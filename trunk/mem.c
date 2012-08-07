/* mem.c: Memory management functions.
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

#include "io.h"
#include "mem.h"

long int MEM_LIMIT;
long int FREE_MEM;
expression * memory;
pointer free_list_start;
pointer reclaim_list_start;
int mem_exceeded;

inline pointer unchecked_cons(pointer ar, pointer dr);

void init_mem(void* my_memory, long int memory_limit) {
  FREE_MEM = MEM_LIMIT = (memory_limit)/sizeof(expression);
  memory = (expression*)my_memory;
  memory[0].tag = UNALLOCATED;
  free_list_start = 0;
  reclaim_list_start = MEM_LIMIT;
  mem_exceeded = 0;
}

void flush_mem() {
  while (! is_primitive(reclaim_list_start)) {
    free_list_start = unchecked_cons(free_list_start, NIL);
    FREE_MEM++;
  }
}

pointer free_memory_size() {
  flush_mem();
  return new_number(FREE_MEM);
}

inline int is_primitive(pointer e) { return ((e < 0) || (e >= MEM_LIMIT)); }
inline int is_number(pointer e) {
  return (!is_primitive(e)) && memory[e].tag == NUMBER;
}
inline int is_function(pointer e) {
  return (!is_primitive(e)) && memory[e].tag == FUNCTION;
}
inline int is_atom(pointer e) {
  return (is_primitive(e) || memory[e].tag != PAIR);
}

inline int eq(pointer e1, pointer e2) {
  if (e1 == e2) {
    return 1;
  } else if (is_number(e1) && is_number(e2)) {
    if (value(e1) == value(e2)) { return 1; }
  } else if ((! is_atom(e1)) && (! is_atom(e2))) {
    if (eq(car(e1), car(e2))) {
      return eq(cdr(e1), cdr(e2));
    }
  }
  return 0;
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
  return (is_atom(e))?NIL:memory[e].data.pair.ar;
}

inline pointer cdr(pointer e) {
  return (is_atom(e))?NIL:memory[e].data.pair.dr;
}

inline pointer allocate_pointer() {
  pointer r = NIL;
  if (! is_primitive(reclaim_list_start)) {
    r = reclaim_list_start;
    reclaim_list_start = - (memory[r].count);
    if (memory[r].tag == FUNCTION) {
      decrement_count(memory[r].data.closure.env);
    } else if (memory[r].tag == PAIR) {
      decrement_count(memory[r].data.pair.ar);
      decrement_count(memory[r].data.pair.dr);
    }
  } else if (! is_primitive(free_list_start)) {
    r = free_list_start;
    if (memory[r].tag == UNALLOCATED) {
      free_list_start++;
      if (! is_primitive(free_list_start)) {
        memory[free_list_start].tag = UNALLOCATED;
      }
    } else {
      free_list_start = car(r);
    }
    FREE_MEM--;
  } else if (mem_exceeded == 0) {
    error(ERR_MEM_LIMIT);
    mem_exceeded = 1;
  }
  if (!is_primitive(r)) {
    memory[r].count = 1;
  }
  return r;
}

inline pointer unchecked_cons(pointer ar, pointer dr) {
  pointer r = allocate_pointer();
  if (! is_primitive(r)) {
    memory[r].tag = PAIR;
    memory[r].data.pair.ar = ar;
    memory[r].data.pair.dr = dr;
  }
  return r;
}

inline pointer cons(pointer ar, pointer dr) {
  pointer result = unchecked_cons(ar, dr);
  if (is_primitive(result)) {
    decrement_count(ar);
    decrement_count(dr);
  }
  return result;
}

inline int length(pointer list) {
  int result = 0;
  while (! is_atom(list)) {
    result++;
    list = cdr(list);
  }
  return result;
}

inline pointer new_number(long int value) {
  pointer result = allocate_pointer();
  if (! is_primitive(result)) {
    memory[result].tag = NUMBER;
    memory[result].data.number = value;
  }
  return result;
}

inline long long int value(pointer num) {
  if (is_number(num)) {
    return memory[num].data.number;
  }
  return 0;
}

pointer wrap_function(void* ptr, pointer env) {
  pointer result = allocate_pointer();
  if (! is_primitive(result)) {
    memory[result].tag = FUNCTION;
    memory[result].data.closure.address = ptr;
    memory[result].data.closure.env = env;
  }
  return result;
}

void* function_target(pointer ptr, void* end_addr) {
  return is_function(ptr)?
    memory[ptr].data.closure.address:end_addr;
}

pointer function_environment(pointer ptr) {
  return is_function(ptr)?
    memory[ptr].data.closure.env:NIL;
}

pointer setCdr(pointer e, pointer dr) {
  return (! is_primitive(e))? (memory[e].data.pair.dr = dr) : NIL;
}
