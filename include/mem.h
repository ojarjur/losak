/* mem.h: Memory management functions.
 *        Cons cell allocation and garbage collection. */
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

#ifndef MEM_H
#define MEM_H

enum type {
  UNALLOCATED,
  EMPTY_LIST,
  NUMBER,
  SYMBOL,
  FUNCTION,
  PAIR
};
struct expression;
typedef struct expression* pointer;
typedef void* function_addr;
struct pair_data {
  pointer ar;
  pointer dr;
};
struct closure_data {
  void* address;
  pointer env;
};
union expression_data {
  struct pair_data pair;
  struct closure_data closure;
  long int number;
};
typedef struct expression {
  enum type tag;
  long int count;
  int serialized_size;
  union expression_data data;
} expression;

void init_mem(void* my_memory, long int mem_limit);
pointer free_memory_size();
void flush_mem();

inline int is_primitive(pointer e);
inline int is_nil(pointer e);
inline int is_number(pointer e);
inline int is_function(pointer e);
inline int is_symbol(pointer e);
inline int is_pair(pointer e);
inline int is_atom(pointer e);
inline int eq(pointer e1, pointer e2);

inline void increment_count(pointer e);
inline void decrement_count(pointer e);
inline pointer car(pointer e);
inline pointer cdr(pointer e);
inline pointer cons(pointer ar, pointer dr);
inline int length(pointer list);
inline int serialized_size(pointer expr);

inline pointer nil();
inline pointer new_number(long int value);
inline pointer new_symbol(long int value);
inline long int value(pointer n);
inline long int symbol_id(pointer n);
pointer wrap_function(function_addr ptr, pointer env);
function_addr function_target(pointer ptr, function_addr end_addr);
pointer function_environment(pointer ptr);

pointer setCdr(pointer e, pointer dr);

#endif
