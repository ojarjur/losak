/* mem.h: Memory management functions.
 *        Cons cell allocation and garbage collection. */
/* Copyright (c) 2004 - 2007 by Omar Jarjur

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

#ifndef MEM_H
#define MEM_H

#define NUM -1
#define FUN -2

#define NIL -3
#define QUOTE -4
#define CAR -5
#define CDR -6
#define COND -7
#define CONS -8
#define ATOM -9
#define NUMBER -10
#define FUNCTION -11
#define EQ -12
#define FN -13
#define LET -14
#define PLUS -15
#define MINUS -16
#define MULT -17
#define DIV -18
#define MOD -19
#define LSHIFT -20
#define SRSHIFT -21
#define URSHIFT -22
#define BAND -23
#define BOR -24
#define BXOR -25
#define BNEG -26
#define LT -27
#define GT -28
#define DEFINE -29

typedef long int pointer;
typedef struct {
  pointer count;
  pointer ar;
  pointer dr;
} expression;
typedef void (*function_addr)();

void init_mem(void* my_memory, pointer mem_limit);
pointer free_memory_size();
void flush_mem();

inline int is_primitive(pointer e);
inline int is_number(pointer e);
inline int is_function(pointer e);
inline int is_atom(pointer e);
inline int eq(pointer e1, pointer e2);

inline void increment_count(pointer e);
inline void decrement_count(pointer e);
inline pointer car(pointer e);
inline pointer cdr(pointer e);
inline pointer cons(pointer ar, pointer dr);

inline pointer new_number(long int value);
inline long int value(pointer n);

inline pointer new_function(function_addr addr, pointer env);
inline function_addr address(pointer function);
inline pointer environment(pointer function);

#ifdef BARE_HARDWARE
pointer setCdr(pointer e, pointer dr);
#endif

#endif
