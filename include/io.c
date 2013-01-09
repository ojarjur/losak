/* io.c: Input/Output methods. */
/* Copyright (c) 2004 - 2012 by Omar Jarjur

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
#include <unistd.h>
#include <sys/select.h>
#endif

#include "io.h"

#ifdef BARE_HARDWARE
#include "console.h"
#endif

pointer msg_buffer, last_msg;

void buffer_msg(pointer msg) {
  if (is_nil(msg_buffer)) {
    last_msg = msg_buffer = cons(msg, nil());
  } else {
    last_msg = setCdr(last_msg, cons(msg, nil()));
  }
}

void init_io() {
#ifdef BARE_HARDWARE
  init_console();
#endif
  msg_buffer = last_msg = nil();
}

#ifdef BARE_HARDWARE
unsigned char inb(short port) {
  unsigned char val;
  asm volatile("inb %1, %0\n" : "=a"(val) : "Nd"(port));
  return val;
}

short inw(short port) {
  short val;
  asm volatile("inw %1, %0\n" : "=a"(val) : "Nd"(port));
  return val;
}

int inl(short port) {
  int val;
  asm volatile("inl %1, %0\n" : "=a"(val) : "Nd"(port));
  return val;
}

void outb(short port, unsigned char val) {
  asm volatile("outb %0, %1\n" : : "a"(val), "Nd"(port));
}

void outw(short port, short val) {
  asm volatile("outw %0, %1\n" : : "a"(val), "Nd"(port));
}

void outl(short port, int val) {
  asm volatile("outl %0, %1\n" : : "a"(val), "Nd"(port));
}

void halt() {
  // FIX ME: Shutdown instead of rebooting
  reboot();
}

void reboot() {
  outb(0x64,0xFE);
}
#endif

/**
 * Read in input.
 */
pointer get_input() {
  pointer result = nil(), input, t;
  if (! is_nil(msg_buffer)) {
    increment_count(input = car(msg_buffer));
    increment_count(t = cdr(msg_buffer));
    decrement_count(msg_buffer);
    msg_buffer = t;
    result = cons(input, result);
  } else {
#ifdef BARE_HARDWARE
    short stat;
    if ((inb(0x64)) & 1) {
      stat = inb(0x61);
      input = new_number((pointer)inb(0x60));
      outb(0x61, (stat | 0x80));
      outb(0x61, (stat & 0x7f));
      result = cons(input, result);
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
        input = new_number(0);
        result = cons(input, result);
      } else if (read_count == 1) {
        input = new_number(char_buffer[0]);
        result = cons(input, result);
      }
    }
#endif
  }
  return result;
}

#ifdef BARE_HARDWARE
pointer read_from_port(short port, long int size) {
  if (size < 2) {
    return new_number(inb(port));
  } else if (size < 4) {
    return new_number(inw(port));
  } else {
    return new_number(inl(port));
  }
}

void write_to_port(short port, pointer bytes) {
  char char_val = (char)value(car(bytes));
  if (is_nil(cdr(bytes))) {
    // Write a single byte
    outb(port, char_val);
  } else {
    short short_val = char_val;
    short_val <<= 8;
    short_val |= (char)value(car(cdr(bytes)));
    if (is_nil(cdr(cdr(bytes)))) {
      // Write 2 bytes
      outw(port, short_val);
    } else {
      // Write 4 bytes
      int int_val = short_val;
      int_val <<= 8;
      int_val |= (char)value(car(cdr(cdr(bytes))));
      int_val <<= 8;
      int_val |= (char)value(car(cdr(cdr(cdr(bytes)))));
      outl(port, int_val);
    }
  }
}
#else
pointer string_to_pointer(char* str) {
  int string_length = strlen(str);
  pointer ptr = nil();
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

pointer read_from_file(long int handle, int read_count) {
  pointer result;
  char* input = (char*)malloc(sizeof(char)*(read_count+1));
  fgets(input, read_count, get_handle_stream(handle));
  result = string_to_pointer(input);
  free(input);
  return result;
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
#endif

/**
 * Execute a command as specified by an s-expression.
 */
void execute(pointer msg) {
  pointer output;
  if (is_atom(msg)) {
    output = msg;
  } else {
    output = car(msg);
  }
  if (is_atom(output)) {
    if (is_number(output)) {
      /** Write an ascii character to the screen/stdout */
#ifdef BARE_HARDWARE
      print((char)value(output));
#else
      int val = value(output);
      printf("%c", val);
      fflush(stdout);
#endif
    }
  } else {
    if (is_number(car(output))) {
      long int location = value(car(output));
      if (is_nil(cdr(output))) {
#ifdef BARE_HARDWARE
        if ((location >= 0) && (location < 0x100000)) {
          /* Read from memory */
          char* memory_loc = (char*)location;
          (*memory_loc) = (char)value(car(cdr(output)));
          buffer_msg(new_number(*memory_loc));
        }
#else
        // close file handle
        close_file(location);
#endif
      } else if (is_number(cdr(output))) {
#ifdef BARE_HARDWARE
        if ((location >= 0) && (location < 0x100000)) {
          /* Write directly to memory */
          char* memory_loc = (char*)location;
          (*memory_loc) = (char)value(cdr(output));
        }
#else
        // write a char to the file handle
        long int val = value(cdr(output));
        write(location, &val, 1);
#endif
      } else if (is_number(car(cdr(output)))) {
#ifdef BARE_HARDWARE
        /** Poll an IO Port */
        buffer_msg(read_from_port((short)location, value(car(cdr(output)))));
#else
        // read from the file handle
        buffer_msg(read_from_file(location, value(car(cdr(output)))));
#endif
      }
      else {
#ifdef BARE_HARDWARE
        /* Write to an IO Port */
        write_to_port((short)location, car(cdr(output)));
#else
        // write a string to the file handle
        write_to_file(location, car(cdr(output)));
#endif
      }
#ifndef BARE_HARDWARE
    } else { // open file handle
      pointer name = car(output);
      pointer mode = car(cdr(output));
      open_file(name, mode);
#endif
    }
  }
}

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
