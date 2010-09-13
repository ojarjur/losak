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
#define QUASIQUOTE -5
#define UNQUOTE -6
#define CAR -7
#define CDR -8
#define COND -9
#define IF -10
#define ELSE -11
#define CONS -12
#define ATOM -13
#define NUMBER -14
#define FUNCTION -15
#define EQ -16
#define FN -17
#define LET -18
#define PLUS -19
#define MINUS -20
#define MULT -21
#define DIV -22
#define MOD -23
#define LSHIFT -24
#define SRSHIFT -25
#define URSHIFT -26
#define BAND -27
#define BOR -28
#define BXOR -29
#define BNEG -30
#define LT -31
#define GT -32
#define DEFINE -33

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
inline int length(pointer list);

inline pointer new_number(long int value);
inline long int value(pointer n);

inline pointer new_function(function_addr addr, pointer env);
inline function_addr address(pointer function);
inline pointer environment(pointer function);

pointer setCdr(pointer e, pointer dr);

#endif
