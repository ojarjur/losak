/* eval.c: Eval primitives. */
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
#include "eval.h"
#include "io.h"
#include "mem.h"

void init_eval() {
  pointer t = sign_mask = -1;
  while (t < 0) {
    sign_mask = t;
    t = t << 1;
  }
  val = args = stack = temp = NIL;
  true = new_number(1);
  return_location = (&end_function);
}

void nil_function() {
  val = NIL;
}

pointer eval_primitive(pointer op, pointer params) {
  pointer result = NIL;
  if (length(params) == 1) {
    if (! is_atom(car(params))) {
      if (op == CAR) {
        result = car(car(params));
        increment_count(result);
      } else if (op == CDR) {
        result = cdr(car(params));
        increment_count(result);
      }
    } else if (op == ATOM) {
      increment_count(result = true);
    } else if (op == FUNCTION) {
      if (is_function(car(params))) {
        increment_count(result = true);
      }
    } else if (is_number(car(params))) {
      if (op == NUMBER) {
        increment_count(result = true);
      } else if (op == MINUS) {
        result = new_number(- value(car(params)));
      } else if (op == BNEG) {
        result = new_number(~ value(car(params)));
      }
    }
  } else if (length(params) == 2) {
    if (op == CONS) {
      increment_count(car(params));
      increment_count(car(cdr(params)));
      result = cons(car(params), car(cdr(params)));
    } else if ((op == EQ)&&
               is_atom(car(params))&&
               is_atom(car(cdr(params)))&&
               eq(car(params), car(cdr(params)))) {
      increment_count(result = true);
    } else if ((op == LT) &&
               is_number(car(params))&&
               is_number(car(cdr(params)))&&
               (value(car(params)) < value(car(cdr(params))))) {
      increment_count(result = true);
    } else if ((op == GT) &&
               is_number(car(params))&&
               is_number(car(cdr(params)))&&
               (value(car(params)) > value(car(cdr(params))))) {
      increment_count(result = true);
    } else if (is_number(car(params)) &&
               is_number(car(cdr(params)))) {
      if (op == PLUS) {
        result = new_number(value(car(params)) + value(car(cdr(params))));
      } else if (op == MINUS) {
        result = new_number(value(car(params)) - value(car(cdr(params))));
      } else if (op == MULT) {
        result = new_number(value(car(params)) * value(car(cdr(params))));
      } else if ((op == DIV) && (value(car(cdr(params))) != 0)) {
        result = new_number(value(car(params)) / value(car(cdr(params))));
      } else if ((op == MOD) && (value(car(cdr(params))) != 0)) {
        result = new_number(value(car(params)) % value(car(cdr(params))));
      } else if (op == BAND) {
        result = new_number(value(car(params)) & value(car(cdr(params))));
      } else if (op == BOR) {
        result = new_number(value(car(params)) | value(car(cdr(params))));
      } else if (op == BXOR) {
        result = new_number(value(car(params)) ^ value(car(cdr(params))));
      } else if (op == LSHIFT) {
        result = new_number(value(car(params)) << value(car(cdr(params))));
      } else if (op == SRSHIFT) {
        result = new_number(value(car(params)) >> value(car(cdr(params))));
      } else if (op == URSHIFT) {
        result =
          new_number(((sign_mask >> (value(car(cdr(params))) - 1)) ^ -1) &
                     (value(car(params)) >> value(car(cdr(params)))));
      }
    }
  }
  return result;
}

void top_level() {
  while (! is_atom(val)) {
    execute(car(val));
    increment_count(temp = cdr(val));
    decrement_count(val);
    val = temp;
  }
  if (is_function(val)) {
    pointer input = get_input();
    return_location = address(val);
    increment_count(env = environment(val));
    decrement_count(val);
    if (input != NIL) {
      env = cons(cons(input, NIL), env);
    } else {
      env = cons(NIL, env);
    }
    call_stack = cons(new_function(&top_level, NIL), call_stack);
  } else {
    return_location = &end_function;
  }
}

void end_function() {
  if (is_number(val) && (cdr(val) == 0)) {
#ifdef BARE_HARDWARE
    halt();
#endif
  } else if (is_number(val) && (cdr(val) == 1)) {
#ifdef BARE_HARDWARE
    reboot();
#endif
  }
  decrement_count(val);
}
