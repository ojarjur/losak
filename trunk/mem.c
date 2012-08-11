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
pointer NIL;

void init_mem(void* my_memory, long int memory_limit) {
  MEM_LIMIT = (memory_limit)/sizeof(expression);
  FREE_MEM = MEM_LIMIT - 1;
  memory = (expression*)my_memory;
  NIL = 0;
  memory[NIL].tag = EMPTY_LIST;
  memory[NIL].count = 1;
  memory[1].tag = UNALLOCATED;
  free_list_start = 1;
  reclaim_list_start = NIL;
  mem_exceeded = 0;
}

void flush_mem() {
  while (reclaim_list_start != NIL) {
    free_list_start = cons(free_list_start, NIL);
    FREE_MEM++;
  }
}

pointer free_memory_size() {
  flush_mem();
  return new_number(FREE_MEM);
}

inline int is_nil(pointer e) {
  return e == NIL;
}
inline int is_number(pointer e) {
  return (memory[e].tag == NUMBER);
}
inline int is_function(pointer e) {
  return (memory[e].tag == FUNCTION);
}
inline int is_symbol(pointer e) {
  return (memory[e].tag == SYMBOL);
}
inline int is_atom(pointer e) {
  return (memory[e].tag != PAIR);
}

inline int eq(pointer e1, pointer e2) {
  return (e1 == e2) | (is_nil(e1) & is_nil(e2)) |
    (is_number(e1) & is_number(e2) & (value(e1) == value(e2))) |
    (is_symbol(e1) & is_symbol(e2) & (symbol_id(e1) == symbol_id(e2)));
}

inline void increment_count(pointer e) {
  if (is_nil(e) || (memory[e].count <= 0)) { return; }
  memory[e].count++;
}

inline void decrement_count(pointer e) {
  if (is_nil(e) || (memory[e].count <= 0)) { return; }
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
  if (reclaim_list_start != NIL) {
    r = reclaim_list_start;
    reclaim_list_start = - (memory[r].count);
    if (memory[r].tag == FUNCTION) {
      decrement_count(memory[r].data.closure.env);
    } else if (memory[r].tag == PAIR) {
      decrement_count(memory[r].data.pair.ar);
      decrement_count(memory[r].data.pair.dr);
    }
  } else if (free_list_start < MEM_LIMIT) {
    r = free_list_start;
    if (memory[r].tag == UNALLOCATED) {
      free_list_start++;
      if (free_list_start < MEM_LIMIT) {
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
  if (r != NIL) {
    memory[r].count = 1;
  }
  return r;
}

inline pointer cons(pointer ar, pointer dr) {
  pointer result = allocate_pointer();
  if (result == NIL) {
    decrement_count(ar);
    decrement_count(dr);
  } else {
    memory[result].tag = PAIR;
    memory[result].data.pair.ar = ar;
    memory[result].data.pair.dr = dr;
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

inline pointer nil() {
  return NIL;
}

inline pointer new_number(long int value) {
  pointer result = allocate_pointer();
  if (result != NIL) {
    memory[result].tag = NUMBER;
    memory[result].data.number = value;
  }
  return result;
}

inline pointer new_symbol(long int value) {
  pointer result = allocate_pointer();
  if (result != NIL) {
    memory[result].tag = SYMBOL;
    memory[result].data.number = value;
  }
  return result;
}

inline long long int value(pointer num) {
  return is_number(num)?memory[num].data.number:0;
}

inline long long int symbol_id(pointer num) {
  return is_symbol(num)?memory[num].data.number:0;
}

pointer wrap_function(void* ptr, pointer env) {
  pointer result = allocate_pointer();
  if (result == NIL) {
    decrement_count(env);
  } else {
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
  return (! is_atom(e))? (memory[e].data.pair.dr = dr) : NIL;
}
