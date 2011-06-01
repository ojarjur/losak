/* io.c: Input/Output methods. */
/* Copyright (c) 2004 - 2008 by Omar Jarjur

This program is free software; you can redistribute it and/or
modify it under the terms of version 2 of the GNU General
Public License as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef BARE_HARDWARE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef NCURSES_CONSOLE
#include <ncurses.h>
#else
#include <unistd.h>
#include <sys/select.h>
#endif
#endif

#include "io.h"

#ifdef BARE_HARDWARE
#include "console.h"
#endif

pointer msg_buffer, last_msg;

void buffer_msg(pointer msg) {
  if (msg_buffer == NIL) {
    last_msg = msg_buffer = cons(msg, NIL);
  } else {
    last_msg = setCdr(last_msg, cons(msg, NIL));
  }
}

void init_io() {
#ifdef NCURSES_CONSOLE
  initscr();
  cbreak();
  noecho();
  nonl();
  scrollok(stdscr, TRUE);
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
#else
#ifdef BARE_HARDWARE
  init_console();
#endif
#endif
  msg_buffer = last_msg = NIL;
}

#ifdef BARE_HARDWARE
void halt() {
  // FIX ME: Shutdown instead of rebooting
  reboot();
}

void reboot() {
  out(0x64,0xFE);
}

short in(short port) {
  short val;
  asm volatile("inb %1, %0\n" : "=a"(val) : "Nd"(port));
  return val;
}

void out(short port, short val) {
  asm volatile("outb %0, %1\n" : : "a"(val), "Nd"(port));
}

/**
 * Execute a command as specified by an s-expression.
 */
void execute(pointer msg) {
  short port, output_value;
  char* memory_loc;
  pointer val, result;
  if (is_atom(msg)) {
    val = msg;
  } else {
    val = car(msg);
  }
  if (is_atom(val)) {
    if (is_number(val)) { /** Write an ascii character to the screen */
      print((char)cdr(val));
    } 
  } else if (is_number(car(val)) &&
             (cdr(val) == NIL)) { /** Poll an IO Port */
    increment_count(car(val));
    result = cons(car(val), cons(NUM, in((short)cdr(car(val)))));
    buffer_msg(result);
  } else if (is_number(car(val)) && is_number(cdr(val))) { /* Write to */
    port = (short)cdr(car(val));                           /* an IO Port */
    output_value = (short)cdr(cdr(val));
    out(port, output_value);
  } else if (is_number(car(val)) &&
             is_number(car(cdr(val))) &&
             (cdr(cdr(val)) == NIL) &&
             (value(car(val)) >= 0) &&
             (value(car(val)) < 0x100000)) {
    /* Write directly to memory */
    memory_loc = (char*)cdr(car(val));
    (*memory_loc) = (char)cdr(car(cdr(val)));
  }
}

#else
void end_io() {
#ifdef NCURSES_CONSOLE
  endwin();
#endif
}
#endif

/**
 * Read in input.
 */
pointer get_input() {
  pointer result = NIL, t;
#ifdef BARE_HARDWARE
  short stat;
  if ((in(0x64)) & 1) {
    stat = in(0x61);
    result = new_number((pointer)in(0x60));
    out(0x61, (stat | 0x80));
    out(0x61, (stat & 0x7f));
  }
#else
#ifdef NCURSES_CONSOLE
  int c = getch();
  if (c != ERR) {
    if (c == KEY_ENTER) {
      c = 10;
    } else if (c == KEY_BACKSPACE) {
      c = 8;
    }
    result = new_number(c);
  }
#else
  fd_set in_set;
  struct timeval timeout;
  ssize_t read_count;
  char char_buffer[1];

  FD_ZERO(&in_set);
  FD_SET(0, &in_set);
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  if (select(1, &in_set, NULL, NULL, &timeout)) {
    read_count = read(0, char_buffer, 1);
    if (read_count == 0) {
      result = new_number(0);
    } else if (read_count == 1) {
      result = new_number(char_buffer[0]);
    }
  }
#endif
#endif
  if (msg_buffer != NIL) {
    if (result != NIL) {
      buffer_msg(result);
    }
    increment_count(result = car(msg_buffer));
    increment_count(t = cdr(msg_buffer));
    decrement_count(msg_buffer);
    msg_buffer = t;
  }
  return result;
}

#ifndef BARE_HARDWARE
pointer string_to_pointer(char* str) {
  int string_length = strlen(str);
  pointer ptr = NIL;
  int char_index;
  for (char_index = string_length-1; char_index >= 0; char_index--) {
    ptr = cons(new_number(str[char_index]), ptr);
  }
  return ptr;
}

char* pointer_to_string(pointer ptr) {
  int string_length = length(ptr);
  char* str = (char*)malloc(sizeof(char) * (string_length+1));
  int char_index;
  if (str == NULL) {
    error(ERR_MEM_LIMIT);
  } else {
    for (char_index = 0; char_index < string_length; char_index++) {
      str[char_index] = (char)value(car(ptr));
      ptr = cdr(ptr);
    }
    str[string_length] = '\0';
  }
  return str;
}

FILE* get_handle_stream(long int handle) {
  return (FILE*)handle;
}

long int get_stream_handle(FILE* stream) {
  return (long int)stream;
}

void read_from_file(long int handle, int read_count) {
  char* input = (char*)malloc(sizeof(char)*(read_count+1));
  fgets(input, read_count, get_handle_stream(handle));
  buffer_msg(string_to_pointer(input));
  free(input);
}

void close_file(long int handle) {
  fclose(get_handle_stream(handle));
}

void write_to_file(long int handle, pointer output) {
  char* output_str = pointer_to_string(output);
  fputs(output_str, get_handle_stream(handle));
  free(output_str);
}

void open_file(pointer name, pointer mode) {
  char* name_str = pointer_to_string(name);
  char* mode_str = pointer_to_string(mode);
  FILE* file = fopen(name_str, mode_str);
  free(name_str);
  free(mode_str);
  buffer_msg(new_number(get_stream_handle(file)));
}

void execute(pointer msg) {
  int val, x, y;
  pointer output;
  if (is_atom(msg)) {
    output = msg;
  } else {
    output = car(msg);
  }
  if (is_atom(output)) {
    if (is_number(output)) {
      val = value(output);
#ifdef NCURSES_CONSOLE
      if (val == 8) {
        // backspace.
        getyx(stdscr, y, x);
        move(y, x-1);
        delch();
      } else if ((val > 31) || (val == 10) || (val == 13)) {
        printw("%c", val);
        if (getcury(stdscr) == getmaxy(stdscr)) {
          scrl(1);
        }
      }
      refresh();
#else
      printf("%c", val);
      fflush(stdout);
#endif
    }
  } else { // File I/O
    if (is_number(car(output))) { // Operation on a file handle
      long int id = value(car(output));
      if (cdr(output) == NIL) { // close file handle
        close_file(id);
      } else if (is_number(cdr(output))) { // write a char to the file handle
        long int val = value(cdr(output));
        write(id, &val, 1);
      } else if (is_number(car(cdr(output)))) { // read from the file handle
        read_from_file(id, value(car(cdr(output))));
      } else { // write a string to the file handle
        write_to_file(id, car(cdr(output)));
      }
    } else { // open file handle
      pointer name = car(output);
      pointer mode = car(cdr(output));
      open_file(name, mode);
    }
  }
}
#endif

void error(int type) {
  if (type == ERR_NO_OS) {
    printf("ERROR: No operating system code loaded.\n");
  } else if (type == ERR_BAD_BOOT) {
    printf("ERROR: Not loaded by a multiboot compliant boot loader.\n");
  } else if (type == ERR_MEM_LIMIT) {
    printf("ERROR: Insufficient memory.\n");
  } else {
    printf("ERROR: An unknown error occured.\n");
  }
#ifdef BARE_HARDWARE
  halt();
#else
  exit(1);
#endif
}
