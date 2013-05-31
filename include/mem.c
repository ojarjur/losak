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

long int free_memory;
pointer memory, NIL, MEM_LIMIT, free_list_start, reclaim_list_start;
int mem_exceeded;

void init_mem(void* my_memory, long int memory_limit) {
  long int cell_count = (memory_limit)/sizeof(expression);
  free_memory = cell_count - 1;
  NIL = memory = (expression*)my_memory;
  MEM_LIMIT = memory + cell_count;
  free_list_start = memory + 1;
  reclaim_list_start = NIL;

  NIL->tag = EMPTY_LIST;
  NIL->count = 1;
  NIL->serialized_size = 0;
  free_list_start->tag = UNALLOCATED;
  mem_exceeded = 0;
}

void flush_mem() {
  while (reclaim_list_start != NIL) {
    free_list_start = cons(free_list_start, NIL);
    free_memory++;
  }
}

pointer free_memory_size() {
  flush_mem();
  return new_number(free_memory);
}

inline int is_nil(pointer e) {
  return e == NIL;
}
inline int is_number(pointer e) {
  return (e->tag == NUMBER);
}
inline int is_function(pointer e) {
  return (e->tag == FUNCTION);
}
inline int is_symbol(pointer e) {
  return (e->tag == SYMBOL);
}
inline int is_pair(pointer e) {
  return (e->tag == PAIR);
}
inline int is_atom(pointer e) {
  return (e->tag != PAIR);
}

inline int eq(pointer e1, pointer e2) {
  return (e1 == e2) || (is_nil(e1) && is_nil(e2)) ||
    (is_number(e1) && is_number(e2) && (value(e1) == value(e2))) ||
    (is_symbol(e1) && is_symbol(e2) && (symbol_id(e1) == symbol_id(e2)));
}

inline void increment_count(pointer e) {
  e->count++;
}

inline void decrement_count(pointer e) {
  e->count--;
  if ((!is_nil(e)) && (e->count == 0)) {
    e->count = -((long int)reclaim_list_start);
    reclaim_list_start = e;
  }
}

inline pointer car(pointer e) {
  if (is_atom(e)) {
    return NIL;
  } else {
    return e->data.pair.ar;
  }
}

inline pointer cdr(pointer e) {
  if (is_atom(e)) {
    return NIL;
  } else {
    return e->data.pair.dr;
  }
}

inline pointer allocate_pointer() {
  pointer r = NIL;
  if (reclaim_list_start != NIL) {
    r = reclaim_list_start;
    reclaim_list_start = (pointer)(- (r->count));
    if (r->tag == FUNCTION) {
      decrement_count(r->data.closure.env);
    } else if (r->tag == PAIR) {
      decrement_count(r->data.pair.ar);
      decrement_count(r->data.pair.dr);
    }
  } else if (free_list_start != MEM_LIMIT) {
    r = free_list_start;
    if (r->tag == UNALLOCATED) {
      free_list_start++;
      if (free_list_start != MEM_LIMIT) {
        free_list_start->tag = UNALLOCATED;
      }
    } else {
      free_list_start = car(r);
    }
    free_memory--;
  } else if (mem_exceeded == 0) {
    error(ERR_MEM_LIMIT);
    mem_exceeded = 1;
  }
  if (r != NIL) {
    r->count = 1;
  }
  return r;
}

inline pointer cons(pointer ar, pointer dr) {
  pointer result = allocate_pointer();
  if (result == NIL) {
    decrement_count(ar);
    decrement_count(dr);
  } else {
    result->tag = PAIR;
    result->data.pair.ar = ar;
    result->data.pair.dr = dr;
    result->serialized_size =
      serialized_size(ar) + serialized_size(dr) + 1;
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

inline int serialized_size(pointer expr) {
  return expr->serialized_size;
}

inline pointer nil() {
  return NIL;
}

inline pointer new_number(long int value) {
  pointer result = allocate_pointer();
  if (result != NIL) {
    result->tag = NUMBER;
    result->data.number = value;
    result->serialized_size = 1;
  }
  return result;
}

inline pointer new_symbol(long int value) {
  pointer result = allocate_pointer();
  if (result != NIL) {
    result->tag = SYMBOL;
    result->data.number = value;
    result->serialized_size = 1;
  }
  return result;
}

inline long int value(pointer num) {
  if (is_number(num)) {
    return num->data.number;
  } else {
    return 0;
  }
}

inline long int symbol_id(pointer num) {
  if (is_symbol(num)) {
    return num->data.number;
  } else {
    return 0;
  }
}

pointer wrap_function(void* ptr, pointer env) {
  pointer result = allocate_pointer();
  if (result == NIL) {
    decrement_count(env);
  } else {
    result->tag = FUNCTION;
    result->data.closure.address = ptr;
    result->data.closure.env = env;
    result->serialized_size = serialized_size(env) + 1;
  }
  return result;
}

void* function_target(pointer ptr, void* end_addr) {
  if (is_function(ptr)) {
    return ptr->data.closure.address;
  } else {
    return end_addr;
  }
}

pointer function_environment(pointer ptr) {
  if (is_function(ptr)) {
    return ptr->data.closure.env;
  } else {
    return NIL;
  }
}

pointer setCdr(pointer e, pointer dr) {
  return (! is_atom(e))? (e->data.pair.dr = dr) : NIL;
}
