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
expression* memory;
pointer NIL, MEM_LIMIT, free_list_start, reclaim_list_start;
int mem_exceeded;

type_tag get_type_tag(pointer p) {
  return p & 0x7;
}

expression* memory_address(pointer p) {
  return memory + (p >> 3);
}

void init_mem(void* my_memory, long int memory_limit) {
  long int cell_count = (memory_limit)/sizeof(expression);
  free_memory = cell_count;
  memory = (expression*)my_memory;
  MEM_LIMIT = (cell_count << 3) | UNALLOCATED;
  free_list_start = 0 | UNALLOCATED;
  reclaim_list_start = NIL = EMPTY_LIST;
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

int is_nil(pointer e) {
  return e == NIL;
}
int is_number(pointer e) {
  return (get_type_tag(e) == NUMBER);
}
int is_function(pointer e) {
  return (get_type_tag(e) == FUNCTION);
}
int is_symbol(pointer e) {
  return (get_type_tag(e) == SYMBOL);
}
int is_pair(pointer e) {
  return (get_type_tag(e) == PAIR);
}

int eq(pointer e1, pointer e2) {
  return (e1 == e2);
}

void increment_count(pointer e) {
  if (is_pair(e) || is_function(e)) {
    memory_address(e)->expr.count++;
  }
}

void decrement_count(pointer e) {
  if (is_pair(e) || is_function(e)) {
    memory_address(e)->expr.count--;
    if (memory_address(e)->expr.count == 0) {
      memory_address(e)->expr.count = (long int)reclaim_list_start;
      reclaim_list_start = e;
    }
  }
}

pointer car(pointer e) {
  if (is_pair(e)) {
    return memory_address(e)->expr.data.pair.ar;
  } else {
    return NIL;
  }
}

pointer cdr(pointer e) {
  if (is_pair(e)) {
    return memory_address(e)->expr.data.pair.dr;
  } else {
    return NIL;
  }
}

void free_environment(pointer env) {
  if (get_type_tag(env) == ENVIRONMENT) {
    expression* addr = memory_address(env);
    free_environment(addr->env.a);
    free_environment(addr->env.b);
    free_environment(addr->env.c);
    free_environment(addr->env.d);
    addr->expr.count = (long int)reclaim_list_start;
    reclaim_list_start = env;
  } else {
    decrement_count(env);
  }
}

pointer allocate_pointer(type_tag tag) {
  pointer r = NIL;
  if (reclaim_list_start != NIL) {
    r = reclaim_list_start;
    reclaim_list_start = (pointer)(memory_address(r)->expr.count);
    if (get_type_tag(r) == FUNCTION) {
      free_environment(memory_address(r)->expr.data.closure.env);
    } else if (get_type_tag(r) == PAIR) {
      decrement_count(memory_address(r)->expr.data.pair.ar);
      decrement_count(memory_address(r)->expr.data.pair.dr);
    }
  } else if (free_list_start != MEM_LIMIT) {
    r = free_list_start;
    if (get_type_tag(r) == UNALLOCATED) {
      free_list_start += (1 << 3);
    } else {
      free_list_start = car(r);
    }
    free_memory--;
  } else if (mem_exceeded == 0) {
    error(ERR_MEM_LIMIT);
    mem_exceeded = 1;
  }
  if (r != NIL) {
    r = (r & (~0x7)) | tag;
    if (tag != ENVIRONMENT) {
      memory_address(r)->expr.count = 1;
    }
  }
  return r;
}

pointer cons(pointer ar, pointer dr) {
  pointer result = allocate_pointer(PAIR);
  if (result == NIL) {
    decrement_count(ar);
    decrement_count(dr);
  } else {
    expression* r = memory_address(result);
    r->expr.data.pair.ar = ar;
    r->expr.data.pair.dr = dr;
    r->expr.serialized_size =
      serialized_size(ar) + serialized_size(dr) + 1;
  }
  return result;
}

pointer make_env(pointer a, pointer b, pointer c, pointer d) {
  pointer result = allocate_pointer(ENVIRONMENT);
  if (result == NIL) {
    free_environment(a);
    free_environment(b);
    free_environment(c);
    free_environment(d);
  } else {
    expression* r = memory_address(result);
    r->env.a = a;
    r->env.b = b;
    r->env.c = c;
    r->env.d = d;
  }
  return result;
}

int length(pointer list) {
  int result = 0;
  while (is_pair(list)) {
    result++;
    list = cdr(list);
  }
  return result;
}

int serialized_size(pointer expr) {
  if (is_pair(expr) || is_function(expr)) {
    return memory_address(expr)->expr.serialized_size;
  }
  return 1;
}

pointer nil() {
  return NIL;
}

pointer new_number(long int value) {
  return (value << 3) | NUMBER;
}

pointer new_symbol(long int value) {
  return (value << 3) | SYMBOL;
}

long int value(pointer num) {
  if (is_number(num)) {
    // Divide by 8 instead of bit shifting,
    // so that sign bits are maintained.
    return ((long int)num) / 8;
  } else {
    return 0;
  }
}

long int symbol_id(pointer num) {
  if (is_symbol(num)) {
    return (num >> 3);
  } else {
    return 0;
  }
}

pointer wrap_function(void* ptr, pointer env) {
  pointer result = allocate_pointer(FUNCTION);
  if (result == NIL) {
    decrement_count(env);
  } else {
    expression* r = memory_address(result);
    r->expr.data.closure.address = ptr;
    r->expr.data.closure.env = env;
    r->expr.serialized_size = serialized_size(env) + 1;
  }
  return result;
}

void* function_target(pointer ptr, void* end_addr) {
  if (is_function(ptr)) {
    return memory_address(ptr)->expr.data.closure.address;
  } else {
    return end_addr;
  }
}

pointer function_environment(pointer ptr) {
  if (is_function(ptr)) {
    return memory_address(ptr)->expr.data.closure.env;
  } else {
    return NIL;
  }
}

pointer setCdr(pointer e, pointer dr) {
  return (is_pair(e))? (memory_address(e)->expr.data.pair.dr = dr) : NIL;
}
