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

#ifdef NCURSES_CONSOLE
#include <ncurses.h>
#else
#ifndef BARE_HARDWARE
#include <stdio.h>
#include <sys/select.h>
#endif
#endif

#include "io.h"

#ifdef BARE_HARDWARE
#include "console.h"
pointer msg_buffer, last_msg;
#endif

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
  msg_buffer = last_msg = NIL;
#endif
#endif
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

void buffer_msg(pointer msg) {
  if (msg_buffer == NIL) {
    last_msg = msg_buffer = cons(msg, NIL);
  } else {
    last_msg = setCdr(last_msg, cons(msg, NIL));
  }
}

/**
 * Read in input.
 */
pointer get_input() {
  int i = 0;
  pointer result = NIL, t;
  short stat;
  if ((in(0x64)) & 1) {
    stat = in(0x61);
    buffer_msg(new_number((pointer)in(0x60)));
    out(0x61, (stat | 0x80));
    out(0x61, (stat & 0x7f));
  }
  if (msg_buffer != NIL) {
    increment_count(result = car(msg_buffer));
    increment_count(t = cdr(msg_buffer));
    decrement_count(msg_buffer);
    msg_buffer = t;
  }
  return result;
}

/**
 * Execute a command as specified by an s-expression.
 */
void execute(pointer val) {
  short port, value;
  char* memory_loc;
  pointer result;
  if (is_number(val)) { /** Write an ascii character to the screen */
    print((char)cdr(val));
  } else if (is_number(car(val)) &&
             (cdr(val) == NIL)) { /** Poll an IO Port */
    increment_count(car(val));
    result = cons(car(val), cons(NUM, in((short)cdr(car(val)))));
    buffer_msg(result);
  } else if (is_number(car(val)) && is_number(cdr(val))) { /* Write to */
    port = (short)cdr(car(val));                     /* an IO Port */
    value = (short)cdr(cdr(val));
    out(port, value);
  } else if (is_number(car(val)) &&
             is_number(car(cdr(val))) &&
             (cdr(cdr(val)) == NIL) &&
             (cdr(car(val)) >= 0) &&
             (cdr(car(val)) < 0x100000)) { /* Write directly to memory */
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

pointer get_input() {
#ifdef NCURSES_CONSOLE
  int c = getch();
  if (c == ERR) {
    c = 0; // ASCII value NULL
  } else { 
    if (c == KEY_ENTER) {
      c = 10;
    } else if (c == KEY_BACKSPACE) {
      c = 8;
    }
  }
#else
  fd_set in_set;
  struct timeval timeout;
  int c, ready;

  FD_ZERO(&in_set);
  FD_SET(0, &in_set);
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  ready = select(1, &in_set, NULL, NULL, &timeout);
  if (ready) {
    c = getchar();
    if (c == EOF) {
      c = 0; // ASCII value NULL
    }
  } else {
    return NIL;
  }
#endif
  return new_number(c);
}

void execute(pointer output) {
  int val, x, y;
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
#endif
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
}
