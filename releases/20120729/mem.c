/* mem.c: Memory management functions.
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

#include "io.h"
#include "mem.h"

pointer MEM_LIMIT;
pointer FREE_MEM;
expression * memory;
pointer free_list_start;
pointer reclaim_list_start;
int mem_exceeded;

inline pointer unchecked_cons(pointer ar, pointer dr);

void init_mem(void* my_memory, pointer memory_limit) {
  FREE_MEM = MEM_LIMIT = (memory_limit)/sizeof(expression);
  memory = (expression*)my_memory;
  memory[0].count = memory[0].ar = memory[0].dr = NIL;
  free_list_start = 0;
  reclaim_list_start = MEM_LIMIT;
  mem_exceeded = 0;
}

pointer free_memory_size() {
  return cons(NUM, FREE_MEM);
}

inline int is_primitive(pointer e) { return ((e < 0) || (e >= MEM_LIMIT)); }
inline pointer head(pointer e) {
  return ((! is_primitive(e))?memory[e].ar:NIL);
}
inline pointer tail(pointer e) {
  return ((! is_primitive(e))?memory[e].dr:NIL);
}

inline int is_number(pointer e) { return (head(e) == NUM); }
inline int is_function(pointer e) { return (head(e) == FUN); }
inline int is_atom(pointer e) {
  return ( is_primitive(e) ||
           is_function(e) ||
           is_number(e));
}

inline int eq(pointer e1, pointer e2) {
  if (e1 == e2) {
    return 1;
  } else if (is_number(e1) && is_number(e2)) {
    if (value(e1) == value(e2)) { return 1; }
  } else if ((! is_atom(e1)) && (! is_atom(e2))) {
    if (eq(head(e1), head(e2))) {
      return eq(tail(e1), tail(e2));
    }
  }
  return 0;
}

void flush_mem() {
  while (! is_primitive(reclaim_list_start)) {
    free_list_start = unchecked_cons(free_list_start, NIL);
    FREE_MEM++;
  }
}

inline void increment_count(pointer e) {
  if (is_primitive(e) || (memory[e].count <= 0)) { return; }
  memory[e].count++;
}

inline void decrement_count(pointer e) {
  if (is_primitive(e) || (memory[e].count <= 0)) { return; }
  memory[e].count--;
  if (memory[e].count == 0) {
    memory[e].count = -reclaim_list_start;
    reclaim_list_start = e;
  }
}

inline pointer car(pointer e) {
  return (is_atom(e))?NIL:head(e);
}

inline pointer cdr(pointer e) {
  return (is_atom(e))?NIL:tail(e);
}

inline pointer unchecked_cons(pointer ar, pointer dr) {
  pointer r = NIL;
  if (! is_primitive(reclaim_list_start)) {
    r = reclaim_list_start;
    reclaim_list_start = - (memory[r].count);
    if (! is_number(r)) {
      decrement_count(head(r));
      decrement_count(tail(r));
    }
  } else if (! is_primitive(free_list_start)) {
    r = free_list_start;
    if (head(r) == NIL) {
      free_list_start++;
      if (! is_primitive(free_list_start)) {
        memory[free_list_start].ar = NIL;
      }
    } else {
      free_list_start = head(r);
    }
    FREE_MEM--;
  } else if (mem_exceeded == 0) {
    error(ERR_MEM_LIMIT);
    mem_exceeded = 1;
  }
  if (! is_primitive(r)) {
    memory[r].ar = ar;
    memory[r].dr = dr;
    memory[r].count = 1;
  }
  return r;
}

inline pointer cons(pointer ar, pointer dr) {
  pointer result = unchecked_cons(ar, dr);
  if (is_primitive(result) && (ar != NUM)) {
    decrement_count(ar);
    decrement_count(dr);
  }
  return result;
}

inline int length(pointer list) {
  int result = 0;
  while (! is_atom(list)) {
    result++;
    list = tail(list);
  }
  return result;
}

inline pointer new_number(long int value) {
  return cons(NUM, value);
}

inline long int value(pointer num) {
  if (is_number(num)) {
    return tail(num);
  }
  return 0;
}

pointer setCdr(pointer e, pointer dr) {
  return (! is_primitive(e))? (memory[e].dr = dr) : NIL;
}