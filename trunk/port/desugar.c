#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#include "io.h"
#include "mem.h"
#include "eval.h"
pointer arguments = NIL;
pointer make_string(char* str) {
  pointer r = NIL;
  int i = 0;
  while ((str > 0) && (str[i] != '\0')) {
    i++;
  }
  while (i > 0) {
    i--;
    r = cons(new_number(str[i]), r);
  }
  return r;
}
#ifdef BARE_HARDWARE
pointer get_cmd(unsigned long flags, char* command) {
  pointer r = NIL;
  if (getFlag(flags,2) != 0) {
    r = make_string(command);
  }
  return r;
}
#endif
inline void pop_function() {
  decrement_count(env);
  temp = car(call_stack);
  if (is_function(temp)) {
    env = environment(temp);
    increment_count(env);
    return_location = address(temp);
  } else {
    error(ERR_INTERNAL);
    env = NIL;
    return_location = (&end_function);
  }
  increment_count(temp = cdr(call_stack));
  decrement_count(call_stack);
  call_stack = temp;
}
inline void push_args() {
  stack = cons(args, stack);
}
inline void pop_args() {
  decrement_count(args);
  increment_count(args = car(stack));
  increment_count(temp = cdr(stack));
  decrement_count(stack);
  stack = temp;
}
inline void top_level_apply() {
  if (is_function(val)) {
    decrement_count(env);
    return_location = address(val);
    increment_count(env = environment(val));
    decrement_count(val);
    increment_count(args);
    env = cons(args, env);
  } else {
    if (is_primitive(val)) {
      val = eval_primitive(val, args);
    } else {
      decrement_count(val);
      val = NIL;
    }
    pop_function();
  }
  pop_args();
}
inline void apply(function_addr func) {
  if (is_function(val)) {
    call_stack = cons(new_function(func, env), call_stack);
    return_location = address(val);
    increment_count(env = environment(val));
    decrement_count(val);
    increment_count(args);
    env = cons(args, env);
  } else {
    if (is_primitive(val)) {
      val = eval_primitive(val, args);
    } else {
      decrement_count(val);
      val = NIL;
    }
    return_location = func;
  }
  pop_args();
}
void body_1();
pointer global_c95c101c113c117c97c108 = NIL; /* _equal */
pointer global_c102c110c95c48;
void function_0() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    top_level_apply();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_1() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_atom(car(args))) &&
        (is_atom(car(cdr(args)))) &&
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
    pop_args();
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (is_atom(car(args))) {
        increment_count(val = true); 
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      val = NIL;
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(car(env))));
      args = cons(val, args);
      if (length(args) == 1) {
        if (! is_atom(car(args))) {
        increment_count(val = car(car(args)));
        } else { val = NIL; }
      } else { val = NIL; }
      pop_args();
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if (length(args) == 1) {
        if (! is_atom(car(args))) {
        increment_count(val = car(car(args)));
        } else { val = NIL; }
      } else { val = NIL; }
      pop_args();
      args = cons(val, args);
      increment_count(val = global_c95c101c113c117c97c108); /* _equal */
      apply((&function_0));
    }
  }
}
void function_2() {
  increment_count(env);
  val = new_function((&function_1), env);
  pop_function();
}
/* fn_0 */
void body_0() {
  increment_count(env);
  val = new_function((&function_2), env);
  global_c102c110c95c48 = val; /* fn_0 */
  return_location = (&body_1);
}
void body_2();
void function_3() {
  global_c95c101c113c117c97c108 = val; /* _equal */
  return_location = (&body_2);
}
/* _equal */
void body_1() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c48); /* fn_0 */
  apply((&function_3));
}
void body_3();
pointer global_c102c110c95c49;
void function_4() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    pop_function();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_5() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    val = -91;
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_atom(car(args))) &&
        (is_atom(car(cdr(args)))) &&
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      val = NIL;
      push_args();
      args = val;
      val = new_number(109);
      args = cons(val, args);
      val = new_number(111);
      args = cons(val, args);
      val = new_number(116);
      args = cons(val, args);
      val = new_number(97);
      args = cons(val, args);
      val = args;
      args = NIL;
      pop_args();
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      val = -90;
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if ((length(args) == 2) &&
          (is_atom(car(args))) &&
          (is_atom(car(cdr(args)))) &&
          eq(car(args), car(cdr(args)))) {
        increment_count(val = true);
      } else { val = NIL; }
      pop_args();
      if (val != NIL) {
        decrement_count(val);
        val = NIL;
        push_args();
        args = val;
        val = new_number(61);
        args = cons(val, args);
        val = args;
        args = NIL;
        pop_args();
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        val = -89;
        args = cons(val, args);
        increment_count(val = car(car(env)));
        args = cons(val, args);
        if ((length(args) == 2) &&
            (is_atom(car(args))) &&
            (is_atom(car(cdr(args)))) &&
            eq(car(args), car(cdr(args)))) {
          increment_count(val = true);
        } else { val = NIL; }
        pop_args();
        if (val != NIL) {
          decrement_count(val);
          val = NIL;
          push_args();
          args = val;
          val = new_number(108);
          args = cons(val, args);
          val = new_number(97);
          args = cons(val, args);
          val = new_number(117);
          args = cons(val, args);
          val = new_number(113);
          args = cons(val, args);
          val = new_number(101);
          args = cons(val, args);
          val = args;
          args = NIL;
          pop_args();
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = CAR;
          args = cons(val, args);
          increment_count(val = car(car(env)));
          args = cons(val, args);
          if ((length(args) == 2) &&
              (is_atom(car(args))) &&
              (is_atom(car(cdr(args)))) &&
              eq(car(args), car(cdr(args)))) {
            increment_count(val = true);
          } else { val = NIL; }
          pop_args();
          if (val != NIL) {
            decrement_count(val);
            val = NIL;
            push_args();
            args = val;
            val = new_number(114);
            args = cons(val, args);
            val = new_number(97);
            args = cons(val, args);
            val = new_number(99);
            args = cons(val, args);
            val = args;
            args = NIL;
            pop_args();
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            val = CDR;
            args = cons(val, args);
            increment_count(val = car(car(env)));
            args = cons(val, args);
            if ((length(args) == 2) &&
                (is_atom(car(args))) &&
                (is_atom(car(cdr(args)))) &&
                eq(car(args), car(cdr(args)))) {
              increment_count(val = true);
            } else { val = NIL; }
            pop_args();
            if (val != NIL) {
              decrement_count(val);
              val = NIL;
              push_args();
              args = val;
              val = new_number(114);
              args = cons(val, args);
              val = new_number(100);
              args = cons(val, args);
              val = new_number(99);
              args = cons(val, args);
              val = args;
              args = NIL;
              pop_args();
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              val = ATOM;
              args = cons(val, args);
              increment_count(val = car(car(env)));
              args = cons(val, args);
              if ((length(args) == 2) &&
                  (is_atom(car(args))) &&
                  (is_atom(car(cdr(args)))) &&
                  eq(car(args), car(cdr(args)))) {
                increment_count(val = true);
              } else { val = NIL; }
              pop_args();
              if (val != NIL) {
                decrement_count(val);
                val = NIL;
                push_args();
                args = val;
                val = new_number(109);
                args = cons(val, args);
                val = new_number(111);
                args = cons(val, args);
                val = new_number(116);
                args = cons(val, args);
                val = new_number(97);
                args = cons(val, args);
                val = args;
                args = NIL;
                pop_args();
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                val = NUMBER;
                args = cons(val, args);
                increment_count(val = car(car(env)));
                args = cons(val, args);
                if ((length(args) == 2) &&
                    (is_atom(car(args))) &&
                    (is_atom(car(cdr(args)))) &&
                    eq(car(args), car(cdr(args)))) {
                  increment_count(val = true);
                } else { val = NIL; }
                pop_args();
                if (val != NIL) {
                  decrement_count(val);
                  val = NIL;
                  push_args();
                  args = val;
                  val = new_number(114);
                  args = cons(val, args);
                  val = new_number(101);
                  args = cons(val, args);
                  val = new_number(98);
                  args = cons(val, args);
                  val = new_number(109);
                  args = cons(val, args);
                  val = new_number(117);
                  args = cons(val, args);
                  val = new_number(110);
                  args = cons(val, args);
                  val = args;
                  args = NIL;
                  pop_args();
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  val = FUNCTION;
                  args = cons(val, args);
                  increment_count(val = car(car(env)));
                  args = cons(val, args);
                  if ((length(args) == 2) &&
                      (is_atom(car(args))) &&
                      (is_atom(car(cdr(args)))) &&
                      eq(car(args), car(cdr(args)))) {
                    increment_count(val = true);
                  } else { val = NIL; }
                  pop_args();
                  if (val != NIL) {
                    decrement_count(val);
                    val = NIL;
                    push_args();
                    args = val;
                    val = new_number(110);
                    args = cons(val, args);
                    val = new_number(111);
                    args = cons(val, args);
                    val = new_number(105);
                    args = cons(val, args);
                    val = new_number(116);
                    args = cons(val, args);
                    val = new_number(99);
                    args = cons(val, args);
                    val = new_number(110);
                    args = cons(val, args);
                    val = new_number(117);
                    args = cons(val, args);
                    val = new_number(102);
                    args = cons(val, args);
                    val = args;
                    args = NIL;
                    pop_args();
                    pop_function();
                  } else {
                    push_args();
                    val = NIL;
                    args = val;
                    val = EQ;
                    args = cons(val, args);
                    increment_count(val = car(car(env)));
                    args = cons(val, args);
                    if ((length(args) == 2) &&
                        (is_atom(car(args))) &&
                        (is_atom(car(cdr(args)))) &&
                        eq(car(args), car(cdr(args)))) {
                      increment_count(val = true);
                    } else { val = NIL; }
                    pop_args();
                    if (val != NIL) {
                      decrement_count(val);
                      val = NIL;
                      push_args();
                      args = val;
                      val = new_number(61);
                      args = cons(val, args);
                      val = args;
                      args = NIL;
                      pop_args();
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      val = LT;
                      args = cons(val, args);
                      increment_count(val = car(car(env)));
                      args = cons(val, args);
                      if ((length(args) == 2) &&
                          (is_atom(car(args))) &&
                          (is_atom(car(cdr(args)))) &&
                          eq(car(args), car(cdr(args)))) {
                        increment_count(val = true);
                      } else { val = NIL; }
                      pop_args();
                      if (val != NIL) {
                        decrement_count(val);
                        val = NIL;
                        push_args();
                        args = val;
                        val = new_number(60);
                        args = cons(val, args);
                        val = args;
                        args = NIL;
                        pop_args();
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        val = GT;
                        args = cons(val, args);
                        increment_count(val = car(car(env)));
                        args = cons(val, args);
                        if ((length(args) == 2) &&
                            (is_atom(car(args))) &&
                            (is_atom(car(cdr(args)))) &&
                            eq(car(args), car(cdr(args)))) {
                          increment_count(val = true);
                        } else { val = NIL; }
                        pop_args();
                        if (val != NIL) {
                          decrement_count(val);
                          val = NIL;
                          push_args();
                          args = val;
                          val = new_number(62);
                          args = cons(val, args);
                          val = args;
                          args = NIL;
                          pop_args();
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          val = PLUS;
                          args = cons(val, args);
                          increment_count(val = car(car(env)));
                          args = cons(val, args);
                          if ((length(args) == 2) &&
                              (is_atom(car(args))) &&
                              (is_atom(car(cdr(args)))) &&
                              eq(car(args), car(cdr(args)))) {
                            increment_count(val = true);
                          } else { val = NIL; }
                          pop_args();
                          if (val != NIL) {
                            decrement_count(val);
                            val = NIL;
                            push_args();
                            args = val;
                            val = new_number(43);
                            args = cons(val, args);
                            val = args;
                            args = NIL;
                            pop_args();
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            val = MINUS;
                            args = cons(val, args);
                            increment_count(val = car(car(env)));
                            args = cons(val, args);
                            if ((length(args) == 2) &&
                                (is_atom(car(args))) &&
                                (is_atom(car(cdr(args)))) &&
                                eq(car(args), car(cdr(args)))) {
                              increment_count(val = true);
                            } else { val = NIL; }
                            pop_args();
                            if (val != NIL) {
                              decrement_count(val);
                              val = NIL;
                              push_args();
                              args = val;
                              val = new_number(45);
                              args = cons(val, args);
                              val = args;
                              args = NIL;
                              pop_args();
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              val = MULT;
                              args = cons(val, args);
                              increment_count(val = car(car(env)));
                              args = cons(val, args);
                              if ((length(args) == 2) &&
                                  (is_atom(car(args))) &&
                                  (is_atom(car(cdr(args)))) &&
                                  eq(car(args), car(cdr(args)))) {
                                increment_count(val = true);
                              } else { val = NIL; }
                              pop_args();
                              if (val != NIL) {
                                decrement_count(val);
                                val = NIL;
                                push_args();
                                args = val;
                                val = new_number(42);
                                args = cons(val, args);
                                val = args;
                                args = NIL;
                                pop_args();
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                val = DIV;
                                args = cons(val, args);
                                increment_count(val = car(car(env)));
                                args = cons(val, args);
                                if ((length(args) == 2) &&
                                    (is_atom(car(args))) &&
                                    (is_atom(car(cdr(args)))) &&
                                    eq(car(args), car(cdr(args)))) {
                                  increment_count(val = true);
                                } else { val = NIL; }
                                pop_args();
                                if (val != NIL) {
                                  decrement_count(val);
                                  val = NIL;
                                  push_args();
                                  args = val;
                                  val = new_number(47);
                                  args = cons(val, args);
                                  val = args;
                                  args = NIL;
                                  pop_args();
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  val = MOD;
                                  args = cons(val, args);
                                  increment_count(val = car(car(env)));
                                  args = cons(val, args);
                                  if ((length(args) == 2) &&
                                      (is_atom(car(args))) &&
                                      (is_atom(car(cdr(args)))) &&
                                      eq(car(args), car(cdr(args)))) {
                                    increment_count(val = true);
                                  } else { val = NIL; }
                                  pop_args();
                                  if (val != NIL) {
                                    decrement_count(val);
                                    val = NIL;
                                    push_args();
                                    args = val;
                                    val = new_number(37);
                                    args = cons(val, args);
                                    val = args;
                                    args = NIL;
                                    pop_args();
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    val = BNEG;
                                    args = cons(val, args);
                                    increment_count(val = car(car(env)));
                                    args = cons(val, args);
                                    if ((length(args) == 2) &&
                                        (is_atom(car(args))) &&
                                        (is_atom(car(cdr(args)))) &&
                                        eq(car(args), car(cdr(args)))) {
                                      increment_count(val = true);
                                    } else { val = NIL; }
                                    pop_args();
                                    if (val != NIL) {
                                      decrement_count(val);
                                      val = NIL;
                                      push_args();
                                      args = val;
                                      val = new_number(126);
                                      args = cons(val, args);
                                      val = args;
                                      args = NIL;
                                      pop_args();
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      val = BAND;
                                      args = cons(val, args);
                                      increment_count(val = car(car(env)));
                                      args = cons(val, args);
                                      if ((length(args) == 2) &&
                                          (is_atom(car(args))) &&
                                          (is_atom(car(cdr(args)))) &&
                                          eq(car(args), car(cdr(args)))) {
                                        increment_count(val = true);
                                      } else { val = NIL; }
                                      pop_args();
                                      if (val != NIL) {
                                        decrement_count(val);
                                        val = NIL;
                                        push_args();
                                        args = val;
                                        val = new_number(38);
                                        args = cons(val, args);
                                        val = args;
                                        args = NIL;
                                        pop_args();
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        val = BOR;
                                        args = cons(val, args);
                                        increment_count(val = car(car(env)));
                                        args = cons(val, args);
                                        if ((length(args) == 2) &&
                                            (is_atom(car(args))) &&
                                            (is_atom(car(cdr(args)))) &&
                                            eq(car(args), car(cdr(args)))) {
                                          increment_count(val = true);
                                        } else { val = NIL; }
                                        pop_args();
                                        if (val != NIL) {
                                          decrement_count(val);
                                          val = NIL;
                                          push_args();
                                          args = val;
                                          val = new_number(124);
                                          args = cons(val, args);
                                          val = args;
                                          args = NIL;
                                          pop_args();
                                          pop_function();
                                        } else {
                                          push_args();
                                          val = NIL;
                                          args = val;
                                          val = BXOR;
                                          args = cons(val, args);
                                          increment_count(val = car(car(env)));
                                          args = cons(val, args);
                                          if ((length(args) == 2) &&
                                              (is_atom(car(args))) &&
                                              (is_atom(car(cdr(args)))) &&
                                              eq(car(args), car(cdr(args)))) {
                                            increment_count(val = true);
                                          } else { val = NIL; }
                                          pop_args();
                                          if (val != NIL) {
                                            decrement_count(val);
                                            val = NIL;
                                            push_args();
                                            args = val;
                                            val = new_number(94);
                                            args = cons(val, args);
                                            val = args;
                                            args = NIL;
                                            pop_args();
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            val = SRSHIFT;
                                            args = cons(val, args);
                                            increment_count(val = car(car(env)));
                                            args = cons(val, args);
                                            if ((length(args) == 2) &&
                                                (is_atom(car(args))) &&
                                                (is_atom(car(cdr(args)))) &&
                                                eq(car(args), car(cdr(args)))) {
                                              increment_count(val = true);
                                            } else { val = NIL; }
                                            pop_args();
                                            if (val != NIL) {
                                              decrement_count(val);
                                              val = NIL;
                                              push_args();
                                              args = val;
                                              val = new_number(62);
                                              args = cons(val, args);
                                              val = new_number(62);
                                              args = cons(val, args);
                                              val = args;
                                              args = NIL;
                                              pop_args();
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              val = URSHIFT;
                                              args = cons(val, args);
                                              increment_count(val = car(car(env)));
                                              args = cons(val, args);
                                              if ((length(args) == 2) &&
                                                  (is_atom(car(args))) &&
                                                  (is_atom(car(cdr(args)))) &&
                                                  eq(car(args), car(cdr(args)))) {
                                                increment_count(val = true);
                                              } else { val = NIL; }
                                              pop_args();
                                              if (val != NIL) {
                                                decrement_count(val);
                                                val = NIL;
                                                push_args();
                                                args = val;
                                                val = new_number(62);
                                                args = cons(val, args);
                                                val = new_number(62);
                                                args = cons(val, args);
                                                val = new_number(62);
                                                args = cons(val, args);
                                                val = args;
                                                args = NIL;
                                                pop_args();
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                val = LSHIFT;
                                                args = cons(val, args);
                                                increment_count(val = car(car(env)));
                                                args = cons(val, args);
                                                if ((length(args) == 2) &&
                                                    (is_atom(car(args))) &&
                                                    (is_atom(car(cdr(args)))) &&
                                                    eq(car(args), car(cdr(args)))) {
                                                  increment_count(val = true);
                                                } else { val = NIL; }
                                                pop_args();
                                                if (val != NIL) {
                                                  decrement_count(val);
                                                  val = NIL;
                                                  push_args();
                                                  args = val;
                                                  val = new_number(60);
                                                  args = cons(val, args);
                                                  val = new_number(60);
                                                  args = cons(val, args);
                                                  val = args;
                                                  args = NIL;
                                                  pop_args();
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  val = -88;
                                                  args = cons(val, args);
                                                  increment_count(val = car(car(env)));
                                                  args = cons(val, args);
                                                  if ((length(args) == 2) &&
                                                      (is_atom(car(args))) &&
                                                      (is_atom(car(cdr(args)))) &&
                                                      eq(car(args), car(cdr(args)))) {
                                                    increment_count(val = true);
                                                  } else { val = NIL; }
                                                  pop_args();
                                                  if (val != NIL) {
                                                    decrement_count(val);
                                                    val = NIL;
                                                    push_args();
                                                    args = val;
                                                    val = new_number(63);
                                                    args = cons(val, args);
                                                    val = new_number(108);
                                                    args = cons(val, args);
                                                    val = new_number(111);
                                                    args = cons(val, args);
                                                    val = new_number(98);
                                                    args = cons(val, args);
                                                    val = new_number(109);
                                                    args = cons(val, args);
                                                    val = new_number(121);
                                                    args = cons(val, args);
                                                    val = new_number(115);
                                                    args = cons(val, args);
                                                    val = args;
                                                    args = NIL;
                                                    pop_args();
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    val = -87;
                                                    args = cons(val, args);
                                                    increment_count(val = car(car(env)));
                                                    args = cons(val, args);
                                                    if ((length(args) == 2) &&
                                                        (is_atom(car(args))) &&
                                                        (is_atom(car(cdr(args)))) &&
                                                        eq(car(args), car(cdr(args)))) {
                                                      increment_count(val = true);
                                                    } else { val = NIL; }
                                                    pop_args();
                                                    if (val != NIL) {
                                                      decrement_count(val);
                                                      val = NIL;
                                                      push_args();
                                                      args = val;
                                                      val = new_number(103);
                                                      args = cons(val, args);
                                                      val = new_number(110);
                                                      args = cons(val, args);
                                                      val = new_number(105);
                                                      args = cons(val, args);
                                                      val = new_number(114);
                                                      args = cons(val, args);
                                                      val = new_number(116);
                                                      args = cons(val, args);
                                                      val = new_number(115);
                                                      args = cons(val, args);
                                                      val = new_number(62);
                                                      args = cons(val, args);
                                                      val = new_number(45);
                                                      args = cons(val, args);
                                                      val = new_number(108);
                                                      args = cons(val, args);
                                                      val = new_number(111);
                                                      args = cons(val, args);
                                                      val = new_number(98);
                                                      args = cons(val, args);
                                                      val = new_number(109);
                                                      args = cons(val, args);
                                                      val = new_number(121);
                                                      args = cons(val, args);
                                                      val = new_number(115);
                                                      args = cons(val, args);
                                                      val = args;
                                                      args = NIL;
                                                      pop_args();
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      val = -86;
                                                      args = cons(val, args);
                                                      increment_count(val = car(car(env)));
                                                      args = cons(val, args);
                                                      if ((length(args) == 2) &&
                                                          (is_atom(car(args))) &&
                                                          (is_atom(car(cdr(args)))) &&
                                                          eq(car(args), car(cdr(args)))) {
                                                        increment_count(val = true);
                                                      } else { val = NIL; }
                                                      pop_args();
                                                      if (val != NIL) {
                                                        decrement_count(val);
                                                        val = NIL;
                                                        push_args();
                                                        args = val;
                                                        val = new_number(108);
                                                        args = cons(val, args);
                                                        val = new_number(111);
                                                        args = cons(val, args);
                                                        val = new_number(98);
                                                        args = cons(val, args);
                                                        val = new_number(109);
                                                        args = cons(val, args);
                                                        val = new_number(121);
                                                        args = cons(val, args);
                                                        val = new_number(115);
                                                        args = cons(val, args);
                                                        val = new_number(62);
                                                        args = cons(val, args);
                                                        val = new_number(45);
                                                        args = cons(val, args);
                                                        val = new_number(103);
                                                        args = cons(val, args);
                                                        val = new_number(110);
                                                        args = cons(val, args);
                                                        val = new_number(105);
                                                        args = cons(val, args);
                                                        val = new_number(114);
                                                        args = cons(val, args);
                                                        val = new_number(116);
                                                        args = cons(val, args);
                                                        val = new_number(115);
                                                        args = cons(val, args);
                                                        val = args;
                                                        args = NIL;
                                                        pop_args();
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        val = -85;
                                                        args = cons(val, args);
                                                        increment_count(val = car(car(env)));
                                                        args = cons(val, args);
                                                        if ((length(args) == 2) &&
                                                            (is_atom(car(args))) &&
                                                            (is_atom(car(cdr(args)))) &&
                                                            eq(car(args), car(cdr(args)))) {
                                                          increment_count(val = true);
                                                        } else { val = NIL; }
                                                        pop_args();
                                                        if (val != NIL) {
                                                          decrement_count(val);
                                                          val = NIL;
                                                          push_args();
                                                          args = val;
                                                          val = new_number(100);
                                                          args = cons(val, args);
                                                          val = new_number(110);
                                                          args = cons(val, args);
                                                          val = new_number(97);
                                                          args = cons(val, args);
                                                          val = args;
                                                          args = NIL;
                                                          pop_args();
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          val = -84;
                                                          args = cons(val, args);
                                                          increment_count(val = car(car(env)));
                                                          args = cons(val, args);
                                                          if ((length(args) == 2) &&
                                                              (is_atom(car(args))) &&
                                                              (is_atom(car(cdr(args)))) &&
                                                              eq(car(args), car(cdr(args)))) {
                                                            increment_count(val = true);
                                                          } else { val = NIL; }
                                                          pop_args();
                                                          if (val != NIL) {
                                                            decrement_count(val);
                                                            val = NIL;
                                                            push_args();
                                                            args = val;
                                                            val = new_number(100);
                                                            args = cons(val, args);
                                                            val = new_number(110);
                                                            args = cons(val, args);
                                                            val = new_number(101);
                                                            args = cons(val, args);
                                                            val = new_number(112);
                                                            args = cons(val, args);
                                                            val = new_number(112);
                                                            args = cons(val, args);
                                                            val = new_number(97);
                                                            args = cons(val, args);
                                                            val = args;
                                                            args = NIL;
                                                            pop_args();
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            val = -83;
                                                            args = cons(val, args);
                                                            increment_count(val = car(car(env)));
                                                            args = cons(val, args);
                                                            if ((length(args) == 2) &&
                                                                (is_atom(car(args))) &&
                                                                (is_atom(car(cdr(args)))) &&
                                                                eq(car(args), car(cdr(args)))) {
                                                              increment_count(val = true);
                                                            } else { val = NIL; }
                                                            pop_args();
                                                            if (val != NIL) {
                                                              decrement_count(val);
                                                              val = NIL;
                                                              push_args();
                                                              args = val;
                                                              val = new_number(121);
                                                              args = cons(val, args);
                                                              val = new_number(108);
                                                              args = cons(val, args);
                                                              val = new_number(112);
                                                              args = cons(val, args);
                                                              val = new_number(112);
                                                              args = cons(val, args);
                                                              val = new_number(97);
                                                              args = cons(val, args);
                                                              val = args;
                                                              args = NIL;
                                                              pop_args();
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              val = -82;
                                                              args = cons(val, args);
                                                              increment_count(val = car(car(env)));
                                                              args = cons(val, args);
                                                              if ((length(args) == 2) &&
                                                                  (is_atom(car(args))) &&
                                                                  (is_atom(car(cdr(args)))) &&
                                                                  eq(car(args), car(cdr(args)))) {
                                                                increment_count(val = true);
                                                              } else { val = NIL; }
                                                              pop_args();
                                                              if (val != NIL) {
                                                                decrement_count(val);
                                                                val = NIL;
                                                                push_args();
                                                                args = val;
                                                                val = new_number(108);
                                                                args = cons(val, args);
                                                                val = new_number(97);
                                                                args = cons(val, args);
                                                                val = new_number(117);
                                                                args = cons(val, args);
                                                                val = new_number(113);
                                                                args = cons(val, args);
                                                                val = new_number(101);
                                                                args = cons(val, args);
                                                                val = args;
                                                                args = NIL;
                                                                pop_args();
                                                                pop_function();
                                                              } else {
                                                                push_args();
                                                                val = NIL;
                                                                args = val;
                                                                val = -81;
                                                                args = cons(val, args);
                                                                increment_count(val = car(car(env)));
                                                                args = cons(val, args);
                                                                if ((length(args) == 2) &&
                                                                    (is_atom(car(args))) &&
                                                                    (is_atom(car(cdr(args)))) &&
                                                                    eq(car(args), car(cdr(args)))) {
                                                                  increment_count(val = true);
                                                                } else { val = NIL; }
                                                                pop_args();
                                                                if (val != NIL) {
                                                                  decrement_count(val);
                                                                  val = NIL;
                                                                  push_args();
                                                                  args = val;
                                                                  val = new_number(108);
                                                                  args = cons(val, args);
                                                                  val = new_number(100);
                                                                  args = cons(val, args);
                                                                  val = new_number(108);
                                                                  args = cons(val, args);
                                                                  val = new_number(111);
                                                                  args = cons(val, args);
                                                                  val = new_number(102);
                                                                  args = cons(val, args);
                                                                  val = args;
                                                                  args = NIL;
                                                                  pop_args();
                                                                  pop_function();
                                                                } else {
                                                                  push_args();
                                                                  val = NIL;
                                                                  args = val;
                                                                  val = -80;
                                                                  args = cons(val, args);
                                                                  increment_count(val = car(car(env)));
                                                                  args = cons(val, args);
                                                                  if ((length(args) == 2) &&
                                                                      (is_atom(car(args))) &&
                                                                      (is_atom(car(cdr(args)))) &&
                                                                      eq(car(args), car(cdr(args)))) {
                                                                    increment_count(val = true);
                                                                  } else { val = NIL; }
                                                                  pop_args();
                                                                  if (val != NIL) {
                                                                    decrement_count(val);
                                                                    val = NIL;
                                                                    push_args();
                                                                    args = val;
                                                                    val = new_number(114);
                                                                    args = cons(val, args);
                                                                    val = new_number(100);
                                                                    args = cons(val, args);
                                                                    val = new_number(108);
                                                                    args = cons(val, args);
                                                                    val = new_number(111);
                                                                    args = cons(val, args);
                                                                    val = new_number(102);
                                                                    args = cons(val, args);
                                                                    val = args;
                                                                    args = NIL;
                                                                    pop_args();
                                                                    pop_function();
                                                                  } else {
                                                                    push_args();
                                                                    val = NIL;
                                                                    args = val;
                                                                    val = -79;
                                                                    args = cons(val, args);
                                                                    increment_count(val = car(car(env)));
                                                                    args = cons(val, args);
                                                                    if ((length(args) == 2) &&
                                                                        (is_atom(car(args))) &&
                                                                        (is_atom(car(cdr(args)))) &&
                                                                        eq(car(args), car(cdr(args)))) {
                                                                      increment_count(val = true);
                                                                    } else { val = NIL; }
                                                                    pop_args();
                                                                    if (val != NIL) {
                                                                      decrement_count(val);
                                                                      val = NIL;
                                                                      push_args();
                                                                      args = val;
                                                                      val = new_number(100);
                                                                      args = cons(val, args);
                                                                      val = new_number(105);
                                                                      args = cons(val, args);
                                                                      val = args;
                                                                      args = NIL;
                                                                      pop_args();
                                                                      pop_function();
                                                                    } else {
                                                                      push_args();
                                                                      val = NIL;
                                                                      args = val;
                                                                      val = -78;
                                                                      args = cons(val, args);
                                                                      increment_count(val = car(car(env)));
                                                                      args = cons(val, args);
                                                                      if ((length(args) == 2) &&
                                                                          (is_atom(car(args))) &&
                                                                          (is_atom(car(cdr(args)))) &&
                                                                          eq(car(args), car(cdr(args)))) {
                                                                        increment_count(val = true);
                                                                      } else { val = NIL; }
                                                                      pop_args();
                                                                      if (val != NIL) {
                                                                        decrement_count(val);
                                                                        val = NIL;
                                                                        push_args();
                                                                        args = val;
                                                                        val = new_number(116);
                                                                        args = cons(val, args);
                                                                        val = new_number(115);
                                                                        args = cons(val, args);
                                                                        val = new_number(105);
                                                                        args = cons(val, args);
                                                                        val = new_number(108);
                                                                        args = cons(val, args);
                                                                        val = args;
                                                                        args = NIL;
                                                                        pop_args();
                                                                        pop_function();
                                                                      } else {
                                                                        push_args();
                                                                        val = NIL;
                                                                        args = val;
                                                                        val = -77;
                                                                        args = cons(val, args);
                                                                        increment_count(val = car(car(env)));
                                                                        args = cons(val, args);
                                                                        if ((length(args) == 2) &&
                                                                            (is_atom(car(args))) &&
                                                                            (is_atom(car(cdr(args)))) &&
                                                                            eq(car(args), car(cdr(args)))) {
                                                                          increment_count(val = true);
                                                                        } else { val = NIL; }
                                                                        pop_args();
                                                                        if (val != NIL) {
                                                                          decrement_count(val);
                                                                          val = NIL;
                                                                          push_args();
                                                                          args = val;
                                                                          val = new_number(112);
                                                                          args = cons(val, args);
                                                                          val = new_number(97);
                                                                          args = cons(val, args);
                                                                          val = new_number(109);
                                                                          args = cons(val, args);
                                                                          val = args;
                                                                          args = NIL;
                                                                          pop_args();
                                                                          pop_function();
                                                                        } else {
                                                                          push_args();
                                                                          val = NIL;
                                                                          args = val;
                                                                          val = -76;
                                                                          args = cons(val, args);
                                                                          increment_count(val = car(car(env)));
                                                                          args = cons(val, args);
                                                                          if ((length(args) == 2) &&
                                                                              (is_atom(car(args))) &&
                                                                              (is_atom(car(cdr(args)))) &&
                                                                              eq(car(args), car(cdr(args)))) {
                                                                            increment_count(val = true);
                                                                          } else { val = NIL; }
                                                                          pop_args();
                                                                          if (val != NIL) {
                                                                            decrement_count(val);
                                                                            val = NIL;
                                                                            push_args();
                                                                            args = val;
                                                                            val = new_number(114);
                                                                            args = cons(val, args);
                                                                            val = new_number(101);
                                                                            args = cons(val, args);
                                                                            val = new_number(98);
                                                                            args = cons(val, args);
                                                                            val = new_number(109);
                                                                            args = cons(val, args);
                                                                            val = new_number(101);
                                                                            args = cons(val, args);
                                                                            val = new_number(109);
                                                                            args = cons(val, args);
                                                                            val = args;
                                                                            args = NIL;
                                                                            pop_args();
                                                                            pop_function();
                                                                          } else {
                                                                            push_args();
                                                                            val = NIL;
                                                                            args = val;
                                                                            val = -75;
                                                                            args = cons(val, args);
                                                                            increment_count(val = car(car(env)));
                                                                            args = cons(val, args);
                                                                            if ((length(args) == 2) &&
                                                                                (is_atom(car(args))) &&
                                                                                (is_atom(car(cdr(args)))) &&
                                                                                eq(car(args), car(cdr(args)))) {
                                                                              increment_count(val = true);
                                                                            } else { val = NIL; }
                                                                            pop_args();
                                                                            if (val != NIL) {
                                                                              decrement_count(val);
                                                                              val = NIL;
                                                                              push_args();
                                                                              args = val;
                                                                              val = new_number(116);
                                                                              args = cons(val, args);
                                                                              val = new_number(111);
                                                                              args = cons(val, args);
                                                                              val = new_number(110);
                                                                              args = cons(val, args);
                                                                              val = args;
                                                                              args = NIL;
                                                                              pop_args();
                                                                              pop_function();
                                                                            } else {
                                                                              push_args();
                                                                              val = NIL;
                                                                              args = val;
                                                                              val = -74;
                                                                              args = cons(val, args);
                                                                              increment_count(val = car(car(env)));
                                                                              args = cons(val, args);
                                                                              if ((length(args) == 2) &&
                                                                                  (is_atom(car(args))) &&
                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                increment_count(val = true);
                                                                              } else { val = NIL; }
                                                                              pop_args();
                                                                              if (val != NIL) {
                                                                                decrement_count(val);
                                                                                val = NIL;
                                                                                push_args();
                                                                                args = val;
                                                                                val = new_number(114);
                                                                                args = cons(val, args);
                                                                                val = new_number(111);
                                                                                args = cons(val, args);
                                                                                val = args;
                                                                                args = NIL;
                                                                                pop_args();
                                                                                pop_function();
                                                                              } else {
                                                                                push_args();
                                                                                val = NIL;
                                                                                args = val;
                                                                                val = -73;
                                                                                args = cons(val, args);
                                                                                increment_count(val = car(car(env)));
                                                                                args = cons(val, args);
                                                                                if ((length(args) == 2) &&
                                                                                    (is_atom(car(args))) &&
                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                  increment_count(val = true);
                                                                                } else { val = NIL; }
                                                                                pop_args();
                                                                                if (val != NIL) {
                                                                                  decrement_count(val);
                                                                                  val = NIL;
                                                                                  push_args();
                                                                                  args = val;
                                                                                  val = new_number(114);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(112);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(120);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(101);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(45);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(101);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(115);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(114);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(97);
                                                                                  args = cons(val, args);
                                                                                  val = new_number(112);
                                                                                  args = cons(val, args);
                                                                                  val = args;
                                                                                  args = NIL;
                                                                                  pop_args();
                                                                                  pop_function();
                                                                                } else {
                                                                                  push_args();
                                                                                  val = NIL;
                                                                                  args = val;
                                                                                  val = -72;
                                                                                  args = cons(val, args);
                                                                                  increment_count(val = car(car(env)));
                                                                                  args = cons(val, args);
                                                                                  if ((length(args) == 2) &&
                                                                                      (is_atom(car(args))) &&
                                                                                      (is_atom(car(cdr(args)))) &&
                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                    increment_count(val = true);
                                                                                  } else { val = NIL; }
                                                                                  pop_args();
                                                                                  if (val != NIL) {
                                                                                    decrement_count(val);
                                                                                    val = NIL;
                                                                                    push_args();
                                                                                    args = val;
                                                                                    val = new_number(116);
                                                                                    args = cons(val, args);
                                                                                    val = new_number(110);
                                                                                    args = cons(val, args);
                                                                                    val = new_number(105);
                                                                                    args = cons(val, args);
                                                                                    val = new_number(114);
                                                                                    args = cons(val, args);
                                                                                    val = new_number(112);
                                                                                    args = cons(val, args);
                                                                                    val = args;
                                                                                    args = NIL;
                                                                                    pop_args();
                                                                                    pop_function();
                                                                                  } else {
                                                                                    push_args();
                                                                                    val = NIL;
                                                                                    args = val;
                                                                                    val = -71;
                                                                                    args = cons(val, args);
                                                                                    increment_count(val = car(car(env)));
                                                                                    args = cons(val, args);
                                                                                    if ((length(args) == 2) &&
                                                                                        (is_atom(car(args))) &&
                                                                                        (is_atom(car(cdr(args)))) &&
                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                      increment_count(val = true);
                                                                                    } else { val = NIL; }
                                                                                    pop_args();
                                                                                    if (val != NIL) {
                                                                                      decrement_count(val);
                                                                                      val = NIL;
                                                                                      push_args();
                                                                                      args = val;
                                                                                      val = new_number(101);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(115);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(114);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(101);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(118);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(101);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(114);
                                                                                      args = cons(val, args);
                                                                                      val = args;
                                                                                      args = NIL;
                                                                                      pop_args();
                                                                                      pop_function();
                                                                                    } else {
                                                                                      push_args();
                                                                                      val = NIL;
                                                                                      args = val;
                                                                                      val = -70;
                                                                                      args = cons(val, args);
                                                                                      increment_count(val = car(car(env)));
                                                                                      args = cons(val, args);
                                                                                      if ((length(args) == 2) &&
                                                                                          (is_atom(car(args))) &&
                                                                                          (is_atom(car(cdr(args)))) &&
                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                        increment_count(val = true);
                                                                                      } else { val = NIL; }
                                                                                      pop_args();
                                                                                      if (val != NIL) {
                                                                                        decrement_count(val);
                                                                                        val = NIL;
                                                                                        push_args();
                                                                                        args = val;
                                                                                        val = new_number(114);
                                                                                        args = cons(val, args);
                                                                                        val = new_number(97);
                                                                                        args = cons(val, args);
                                                                                        val = new_number(97);
                                                                                        args = cons(val, args);
                                                                                        val = new_number(99);
                                                                                        args = cons(val, args);
                                                                                        val = args;
                                                                                        args = NIL;
                                                                                        pop_args();
                                                                                        pop_function();
                                                                                      } else {
                                                                                        push_args();
                                                                                        val = NIL;
                                                                                        args = val;
                                                                                        val = -69;
                                                                                        args = cons(val, args);
                                                                                        increment_count(val = car(car(env)));
                                                                                        args = cons(val, args);
                                                                                        if ((length(args) == 2) &&
                                                                                            (is_atom(car(args))) &&
                                                                                            (is_atom(car(cdr(args)))) &&
                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                          increment_count(val = true);
                                                                                        } else { val = NIL; }
                                                                                        pop_args();
                                                                                        if (val != NIL) {
                                                                                          decrement_count(val);
                                                                                          val = NIL;
                                                                                          push_args();
                                                                                          args = val;
                                                                                          val = new_number(114);
                                                                                          args = cons(val, args);
                                                                                          val = new_number(100);
                                                                                          args = cons(val, args);
                                                                                          val = new_number(97);
                                                                                          args = cons(val, args);
                                                                                          val = new_number(99);
                                                                                          args = cons(val, args);
                                                                                          val = args;
                                                                                          args = NIL;
                                                                                          pop_args();
                                                                                          pop_function();
                                                                                        } else {
                                                                                          push_args();
                                                                                          val = NIL;
                                                                                          args = val;
                                                                                          val = -68;
                                                                                          args = cons(val, args);
                                                                                          increment_count(val = car(car(env)));
                                                                                          args = cons(val, args);
                                                                                          if ((length(args) == 2) &&
                                                                                              (is_atom(car(args))) &&
                                                                                              (is_atom(car(cdr(args)))) &&
                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                            increment_count(val = true);
                                                                                          } else { val = NIL; }
                                                                                          pop_args();
                                                                                          if (val != NIL) {
                                                                                            decrement_count(val);
                                                                                            val = NIL;
                                                                                            push_args();
                                                                                            args = val;
                                                                                            val = new_number(114);
                                                                                            args = cons(val, args);
                                                                                            val = new_number(97);
                                                                                            args = cons(val, args);
                                                                                            val = new_number(100);
                                                                                            args = cons(val, args);
                                                                                            val = new_number(99);
                                                                                            args = cons(val, args);
                                                                                            val = args;
                                                                                            args = NIL;
                                                                                            pop_args();
                                                                                            pop_function();
                                                                                          } else {
                                                                                            push_args();
                                                                                            val = NIL;
                                                                                            args = val;
                                                                                            val = -67;
                                                                                            args = cons(val, args);
                                                                                            increment_count(val = car(car(env)));
                                                                                            args = cons(val, args);
                                                                                            if ((length(args) == 2) &&
                                                                                                (is_atom(car(args))) &&
                                                                                                (is_atom(car(cdr(args)))) &&
                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                              increment_count(val = true);
                                                                                            } else { val = NIL; }
                                                                                            pop_args();
                                                                                            if (val != NIL) {
                                                                                              decrement_count(val);
                                                                                              val = NIL;
                                                                                              push_args();
                                                                                              args = val;
                                                                                              val = new_number(114);
                                                                                              args = cons(val, args);
                                                                                              val = new_number(100);
                                                                                              args = cons(val, args);
                                                                                              val = new_number(100);
                                                                                              args = cons(val, args);
                                                                                              val = new_number(99);
                                                                                              args = cons(val, args);
                                                                                              val = args;
                                                                                              args = NIL;
                                                                                              pop_args();
                                                                                              pop_function();
                                                                                            } else {
                                                                                              push_args();
                                                                                              val = NIL;
                                                                                              args = val;
                                                                                              val = -66;
                                                                                              args = cons(val, args);
                                                                                              increment_count(val = car(car(env)));
                                                                                              args = cons(val, args);
                                                                                              if ((length(args) == 2) &&
                                                                                                  (is_atom(car(args))) &&
                                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                increment_count(val = true);
                                                                                              } else { val = NIL; }
                                                                                              pop_args();
                                                                                              if (val != NIL) {
                                                                                                decrement_count(val);
                                                                                                val = NIL;
                                                                                                push_args();
                                                                                                args = val;
                                                                                                val = new_number(114);
                                                                                                args = cons(val, args);
                                                                                                val = new_number(97);
                                                                                                args = cons(val, args);
                                                                                                val = new_number(97);
                                                                                                args = cons(val, args);
                                                                                                val = new_number(97);
                                                                                                args = cons(val, args);
                                                                                                val = new_number(99);
                                                                                                args = cons(val, args);
                                                                                                val = args;
                                                                                                args = NIL;
                                                                                                pop_args();
                                                                                                pop_function();
                                                                                              } else {
                                                                                                push_args();
                                                                                                val = NIL;
                                                                                                args = val;
                                                                                                val = -65;
                                                                                                args = cons(val, args);
                                                                                                increment_count(val = car(car(env)));
                                                                                                args = cons(val, args);
                                                                                                if ((length(args) == 2) &&
                                                                                                    (is_atom(car(args))) &&
                                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                  increment_count(val = true);
                                                                                                } else { val = NIL; }
                                                                                                pop_args();
                                                                                                if (val != NIL) {
                                                                                                  decrement_count(val);
                                                                                                  val = NIL;
                                                                                                  push_args();
                                                                                                  args = val;
                                                                                                  val = new_number(114);
                                                                                                  args = cons(val, args);
                                                                                                  val = new_number(100);
                                                                                                  args = cons(val, args);
                                                                                                  val = new_number(97);
                                                                                                  args = cons(val, args);
                                                                                                  val = new_number(97);
                                                                                                  args = cons(val, args);
                                                                                                  val = new_number(99);
                                                                                                  args = cons(val, args);
                                                                                                  val = args;
                                                                                                  args = NIL;
                                                                                                  pop_args();
                                                                                                  pop_function();
                                                                                                } else {
                                                                                                  push_args();
                                                                                                  val = NIL;
                                                                                                  args = val;
                                                                                                  val = -64;
                                                                                                  args = cons(val, args);
                                                                                                  increment_count(val = car(car(env)));
                                                                                                  args = cons(val, args);
                                                                                                  if ((length(args) == 2) &&
                                                                                                      (is_atom(car(args))) &&
                                                                                                      (is_atom(car(cdr(args)))) &&
                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                    increment_count(val = true);
                                                                                                  } else { val = NIL; }
                                                                                                  pop_args();
                                                                                                  if (val != NIL) {
                                                                                                    decrement_count(val);
                                                                                                    val = NIL;
                                                                                                    push_args();
                                                                                                    args = val;
                                                                                                    val = new_number(114);
                                                                                                    args = cons(val, args);
                                                                                                    val = new_number(97);
                                                                                                    args = cons(val, args);
                                                                                                    val = new_number(100);
                                                                                                    args = cons(val, args);
                                                                                                    val = new_number(97);
                                                                                                    args = cons(val, args);
                                                                                                    val = new_number(99);
                                                                                                    args = cons(val, args);
                                                                                                    val = args;
                                                                                                    args = NIL;
                                                                                                    pop_args();
                                                                                                    pop_function();
                                                                                                  } else {
                                                                                                    push_args();
                                                                                                    val = NIL;
                                                                                                    args = val;
                                                                                                    val = -63;
                                                                                                    args = cons(val, args);
                                                                                                    increment_count(val = car(car(env)));
                                                                                                    args = cons(val, args);
                                                                                                    if ((length(args) == 2) &&
                                                                                                        (is_atom(car(args))) &&
                                                                                                        (is_atom(car(cdr(args)))) &&
                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                      increment_count(val = true);
                                                                                                    } else { val = NIL; }
                                                                                                    pop_args();
                                                                                                    if (val != NIL) {
                                                                                                      decrement_count(val);
                                                                                                      val = NIL;
                                                                                                      push_args();
                                                                                                      args = val;
                                                                                                      val = new_number(114);
                                                                                                      args = cons(val, args);
                                                                                                      val = new_number(100);
                                                                                                      args = cons(val, args);
                                                                                                      val = new_number(100);
                                                                                                      args = cons(val, args);
                                                                                                      val = new_number(97);
                                                                                                      args = cons(val, args);
                                                                                                      val = new_number(99);
                                                                                                      args = cons(val, args);
                                                                                                      val = args;
                                                                                                      args = NIL;
                                                                                                      pop_args();
                                                                                                      pop_function();
                                                                                                    } else {
                                                                                                      push_args();
                                                                                                      val = NIL;
                                                                                                      args = val;
                                                                                                      val = -62;
                                                                                                      args = cons(val, args);
                                                                                                      increment_count(val = car(car(env)));
                                                                                                      args = cons(val, args);
                                                                                                      if ((length(args) == 2) &&
                                                                                                          (is_atom(car(args))) &&
                                                                                                          (is_atom(car(cdr(args)))) &&
                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                        increment_count(val = true);
                                                                                                      } else { val = NIL; }
                                                                                                      pop_args();
                                                                                                      if (val != NIL) {
                                                                                                        decrement_count(val);
                                                                                                        val = NIL;
                                                                                                        push_args();
                                                                                                        args = val;
                                                                                                        val = new_number(114);
                                                                                                        args = cons(val, args);
                                                                                                        val = new_number(97);
                                                                                                        args = cons(val, args);
                                                                                                        val = new_number(97);
                                                                                                        args = cons(val, args);
                                                                                                        val = new_number(100);
                                                                                                        args = cons(val, args);
                                                                                                        val = new_number(99);
                                                                                                        args = cons(val, args);
                                                                                                        val = args;
                                                                                                        args = NIL;
                                                                                                        pop_args();
                                                                                                        pop_function();
                                                                                                      } else {
                                                                                                        push_args();
                                                                                                        val = NIL;
                                                                                                        args = val;
                                                                                                        val = -61;
                                                                                                        args = cons(val, args);
                                                                                                        increment_count(val = car(car(env)));
                                                                                                        args = cons(val, args);
                                                                                                        if ((length(args) == 2) &&
                                                                                                            (is_atom(car(args))) &&
                                                                                                            (is_atom(car(cdr(args)))) &&
                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                          increment_count(val = true);
                                                                                                        } else { val = NIL; }
                                                                                                        pop_args();
                                                                                                        if (val != NIL) {
                                                                                                          decrement_count(val);
                                                                                                          val = NIL;
                                                                                                          push_args();
                                                                                                          args = val;
                                                                                                          val = new_number(114);
                                                                                                          args = cons(val, args);
                                                                                                          val = new_number(100);
                                                                                                          args = cons(val, args);
                                                                                                          val = new_number(97);
                                                                                                          args = cons(val, args);
                                                                                                          val = new_number(100);
                                                                                                          args = cons(val, args);
                                                                                                          val = new_number(99);
                                                                                                          args = cons(val, args);
                                                                                                          val = args;
                                                                                                          args = NIL;
                                                                                                          pop_args();
                                                                                                          pop_function();
                                                                                                        } else {
                                                                                                          push_args();
                                                                                                          val = NIL;
                                                                                                          args = val;
                                                                                                          val = -60;
                                                                                                          args = cons(val, args);
                                                                                                          increment_count(val = car(car(env)));
                                                                                                          args = cons(val, args);
                                                                                                          if ((length(args) == 2) &&
                                                                                                              (is_atom(car(args))) &&
                                                                                                              (is_atom(car(cdr(args)))) &&
                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                            increment_count(val = true);
                                                                                                          } else { val = NIL; }
                                                                                                          pop_args();
                                                                                                          if (val != NIL) {
                                                                                                            decrement_count(val);
                                                                                                            val = NIL;
                                                                                                            push_args();
                                                                                                            args = val;
                                                                                                            val = new_number(114);
                                                                                                            args = cons(val, args);
                                                                                                            val = new_number(97);
                                                                                                            args = cons(val, args);
                                                                                                            val = new_number(100);
                                                                                                            args = cons(val, args);
                                                                                                            val = new_number(100);
                                                                                                            args = cons(val, args);
                                                                                                            val = new_number(99);
                                                                                                            args = cons(val, args);
                                                                                                            val = args;
                                                                                                            args = NIL;
                                                                                                            pop_args();
                                                                                                            pop_function();
                                                                                                          } else {
                                                                                                            push_args();
                                                                                                            val = NIL;
                                                                                                            args = val;
                                                                                                            val = -59;
                                                                                                            args = cons(val, args);
                                                                                                            increment_count(val = car(car(env)));
                                                                                                            args = cons(val, args);
                                                                                                            if ((length(args) == 2) &&
                                                                                                                (is_atom(car(args))) &&
                                                                                                                (is_atom(car(cdr(args)))) &&
                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                              increment_count(val = true);
                                                                                                            } else { val = NIL; }
                                                                                                            pop_args();
                                                                                                            if (val != NIL) {
                                                                                                              decrement_count(val);
                                                                                                              val = NIL;
                                                                                                              push_args();
                                                                                                              args = val;
                                                                                                              val = new_number(114);
                                                                                                              args = cons(val, args);
                                                                                                              val = new_number(100);
                                                                                                              args = cons(val, args);
                                                                                                              val = new_number(100);
                                                                                                              args = cons(val, args);
                                                                                                              val = new_number(100);
                                                                                                              args = cons(val, args);
                                                                                                              val = new_number(99);
                                                                                                              args = cons(val, args);
                                                                                                              val = args;
                                                                                                              args = NIL;
                                                                                                              pop_args();
                                                                                                              pop_function();
                                                                                                            } else {
                                                                                                              push_args();
                                                                                                              val = NIL;
                                                                                                              args = val;
                                                                                                              val = -58;
                                                                                                              args = cons(val, args);
                                                                                                              increment_count(val = car(car(env)));
                                                                                                              args = cons(val, args);
                                                                                                              if ((length(args) == 2) &&
                                                                                                                  (is_atom(car(args))) &&
                                                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                increment_count(val = true);
                                                                                                              } else { val = NIL; }
                                                                                                              pop_args();
                                                                                                              if (val != NIL) {
                                                                                                                decrement_count(val);
                                                                                                                val = NIL;
                                                                                                                push_args();
                                                                                                                args = val;
                                                                                                                val = new_number(114);
                                                                                                                args = cons(val, args);
                                                                                                                val = new_number(97);
                                                                                                                args = cons(val, args);
                                                                                                                val = new_number(97);
                                                                                                                args = cons(val, args);
                                                                                                                val = new_number(97);
                                                                                                                args = cons(val, args);
                                                                                                                val = new_number(97);
                                                                                                                args = cons(val, args);
                                                                                                                val = new_number(99);
                                                                                                                args = cons(val, args);
                                                                                                                val = args;
                                                                                                                args = NIL;
                                                                                                                pop_args();
                                                                                                                pop_function();
                                                                                                              } else {
                                                                                                                push_args();
                                                                                                                val = NIL;
                                                                                                                args = val;
                                                                                                                val = -57;
                                                                                                                args = cons(val, args);
                                                                                                                increment_count(val = car(car(env)));
                                                                                                                args = cons(val, args);
                                                                                                                if ((length(args) == 2) &&
                                                                                                                    (is_atom(car(args))) &&
                                                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                  increment_count(val = true);
                                                                                                                } else { val = NIL; }
                                                                                                                pop_args();
                                                                                                                if (val != NIL) {
                                                                                                                  decrement_count(val);
                                                                                                                  val = NIL;
                                                                                                                  push_args();
                                                                                                                  args = val;
                                                                                                                  val = new_number(114);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = new_number(100);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = new_number(97);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = new_number(97);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = new_number(97);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = new_number(99);
                                                                                                                  args = cons(val, args);
                                                                                                                  val = args;
                                                                                                                  args = NIL;
                                                                                                                  pop_args();
                                                                                                                  pop_function();
                                                                                                                } else {
                                                                                                                  push_args();
                                                                                                                  val = NIL;
                                                                                                                  args = val;
                                                                                                                  val = -56;
                                                                                                                  args = cons(val, args);
                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                  args = cons(val, args);
                                                                                                                  if ((length(args) == 2) &&
                                                                                                                      (is_atom(car(args))) &&
                                                                                                                      (is_atom(car(cdr(args)))) &&
                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                    increment_count(val = true);
                                                                                                                  } else { val = NIL; }
                                                                                                                  pop_args();
                                                                                                                  if (val != NIL) {
                                                                                                                    decrement_count(val);
                                                                                                                    val = NIL;
                                                                                                                    push_args();
                                                                                                                    args = val;
                                                                                                                    val = new_number(114);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = new_number(97);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = new_number(100);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = new_number(97);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = new_number(97);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = new_number(99);
                                                                                                                    args = cons(val, args);
                                                                                                                    val = args;
                                                                                                                    args = NIL;
                                                                                                                    pop_args();
                                                                                                                    pop_function();
                                                                                                                  } else {
                                                                                                                    push_args();
                                                                                                                    val = NIL;
                                                                                                                    args = val;
                                                                                                                    val = -55;
                                                                                                                    args = cons(val, args);
                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                    args = cons(val, args);
                                                                                                                    if ((length(args) == 2) &&
                                                                                                                        (is_atom(car(args))) &&
                                                                                                                        (is_atom(car(cdr(args)))) &&
                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                      increment_count(val = true);
                                                                                                                    } else { val = NIL; }
                                                                                                                    pop_args();
                                                                                                                    if (val != NIL) {
                                                                                                                      decrement_count(val);
                                                                                                                      val = NIL;
                                                                                                                      push_args();
                                                                                                                      args = val;
                                                                                                                      val = new_number(114);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = new_number(100);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = new_number(100);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = new_number(97);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = new_number(97);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = new_number(99);
                                                                                                                      args = cons(val, args);
                                                                                                                      val = args;
                                                                                                                      args = NIL;
                                                                                                                      pop_args();
                                                                                                                      pop_function();
                                                                                                                    } else {
                                                                                                                      push_args();
                                                                                                                      val = NIL;
                                                                                                                      args = val;
                                                                                                                      val = -54;
                                                                                                                      args = cons(val, args);
                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                      args = cons(val, args);
                                                                                                                      if ((length(args) == 2) &&
                                                                                                                          (is_atom(car(args))) &&
                                                                                                                          (is_atom(car(cdr(args)))) &&
                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                        increment_count(val = true);
                                                                                                                      } else { val = NIL; }
                                                                                                                      pop_args();
                                                                                                                      if (val != NIL) {
                                                                                                                        decrement_count(val);
                                                                                                                        val = NIL;
                                                                                                                        push_args();
                                                                                                                        args = val;
                                                                                                                        val = new_number(114);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = new_number(97);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = new_number(97);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = new_number(100);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = new_number(97);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = new_number(99);
                                                                                                                        args = cons(val, args);
                                                                                                                        val = args;
                                                                                                                        args = NIL;
                                                                                                                        pop_args();
                                                                                                                        pop_function();
                                                                                                                      } else {
                                                                                                                        push_args();
                                                                                                                        val = NIL;
                                                                                                                        args = val;
                                                                                                                        val = -53;
                                                                                                                        args = cons(val, args);
                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                        args = cons(val, args);
                                                                                                                        if ((length(args) == 2) &&
                                                                                                                            (is_atom(car(args))) &&
                                                                                                                            (is_atom(car(cdr(args)))) &&
                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                          increment_count(val = true);
                                                                                                                        } else { val = NIL; }
                                                                                                                        pop_args();
                                                                                                                        if (val != NIL) {
                                                                                                                          decrement_count(val);
                                                                                                                          val = NIL;
                                                                                                                          push_args();
                                                                                                                          args = val;
                                                                                                                          val = new_number(114);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = new_number(100);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = new_number(97);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = new_number(100);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = new_number(97);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = new_number(99);
                                                                                                                          args = cons(val, args);
                                                                                                                          val = args;
                                                                                                                          args = NIL;
                                                                                                                          pop_args();
                                                                                                                          pop_function();
                                                                                                                        } else {
                                                                                                                          push_args();
                                                                                                                          val = NIL;
                                                                                                                          args = val;
                                                                                                                          val = -52;
                                                                                                                          args = cons(val, args);
                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                          args = cons(val, args);
                                                                                                                          if ((length(args) == 2) &&
                                                                                                                              (is_atom(car(args))) &&
                                                                                                                              (is_atom(car(cdr(args)))) &&
                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                            increment_count(val = true);
                                                                                                                          } else { val = NIL; }
                                                                                                                          pop_args();
                                                                                                                          if (val != NIL) {
                                                                                                                            decrement_count(val);
                                                                                                                            val = NIL;
                                                                                                                            push_args();
                                                                                                                            args = val;
                                                                                                                            val = new_number(114);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = new_number(97);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = new_number(100);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = new_number(100);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = new_number(97);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = new_number(99);
                                                                                                                            args = cons(val, args);
                                                                                                                            val = args;
                                                                                                                            args = NIL;
                                                                                                                            pop_args();
                                                                                                                            pop_function();
                                                                                                                          } else {
                                                                                                                            push_args();
                                                                                                                            val = NIL;
                                                                                                                            args = val;
                                                                                                                            val = -51;
                                                                                                                            args = cons(val, args);
                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                            args = cons(val, args);
                                                                                                                            if ((length(args) == 2) &&
                                                                                                                                (is_atom(car(args))) &&
                                                                                                                                (is_atom(car(cdr(args)))) &&
                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                              increment_count(val = true);
                                                                                                                            } else { val = NIL; }
                                                                                                                            pop_args();
                                                                                                                            if (val != NIL) {
                                                                                                                              decrement_count(val);
                                                                                                                              val = NIL;
                                                                                                                              push_args();
                                                                                                                              args = val;
                                                                                                                              val = new_number(114);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = new_number(100);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = new_number(100);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = new_number(100);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = new_number(97);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = new_number(99);
                                                                                                                              args = cons(val, args);
                                                                                                                              val = args;
                                                                                                                              args = NIL;
                                                                                                                              pop_args();
                                                                                                                              pop_function();
                                                                                                                            } else {
                                                                                                                              push_args();
                                                                                                                              val = NIL;
                                                                                                                              args = val;
                                                                                                                              val = -50;
                                                                                                                              args = cons(val, args);
                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                              args = cons(val, args);
                                                                                                                              if ((length(args) == 2) &&
                                                                                                                                  (is_atom(car(args))) &&
                                                                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                increment_count(val = true);
                                                                                                                              } else { val = NIL; }
                                                                                                                              pop_args();
                                                                                                                              if (val != NIL) {
                                                                                                                                decrement_count(val);
                                                                                                                                val = NIL;
                                                                                                                                push_args();
                                                                                                                                args = val;
                                                                                                                                val = new_number(114);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = new_number(97);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = new_number(97);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = new_number(97);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = new_number(100);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = new_number(99);
                                                                                                                                args = cons(val, args);
                                                                                                                                val = args;
                                                                                                                                args = NIL;
                                                                                                                                pop_args();
                                                                                                                                pop_function();
                                                                                                                              } else {
                                                                                                                                push_args();
                                                                                                                                val = NIL;
                                                                                                                                args = val;
                                                                                                                                val = -49;
                                                                                                                                args = cons(val, args);
                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                args = cons(val, args);
                                                                                                                                if ((length(args) == 2) &&
                                                                                                                                    (is_atom(car(args))) &&
                                                                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                  increment_count(val = true);
                                                                                                                                } else { val = NIL; }
                                                                                                                                pop_args();
                                                                                                                                if (val != NIL) {
                                                                                                                                  decrement_count(val);
                                                                                                                                  val = NIL;
                                                                                                                                  push_args();
                                                                                                                                  args = val;
                                                                                                                                  val = new_number(114);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = new_number(100);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = new_number(97);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = new_number(97);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = new_number(100);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = new_number(99);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  val = args;
                                                                                                                                  args = NIL;
                                                                                                                                  pop_args();
                                                                                                                                  pop_function();
                                                                                                                                } else {
                                                                                                                                  push_args();
                                                                                                                                  val = NIL;
                                                                                                                                  args = val;
                                                                                                                                  val = -48;
                                                                                                                                  args = cons(val, args);
                                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                                  args = cons(val, args);
                                                                                                                                  if ((length(args) == 2) &&
                                                                                                                                      (is_atom(car(args))) &&
                                                                                                                                      (is_atom(car(cdr(args)))) &&
                                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                                    increment_count(val = true);
                                                                                                                                  } else { val = NIL; }
                                                                                                                                  pop_args();
                                                                                                                                  if (val != NIL) {
                                                                                                                                    decrement_count(val);
                                                                                                                                    val = NIL;
                                                                                                                                    push_args();
                                                                                                                                    args = val;
                                                                                                                                    val = new_number(114);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = new_number(97);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = new_number(100);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = new_number(97);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = new_number(100);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = new_number(99);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    val = args;
                                                                                                                                    args = NIL;
                                                                                                                                    pop_args();
                                                                                                                                    pop_function();
                                                                                                                                  } else {
                                                                                                                                    push_args();
                                                                                                                                    val = NIL;
                                                                                                                                    args = val;
                                                                                                                                    val = -47;
                                                                                                                                    args = cons(val, args);
                                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                                    args = cons(val, args);
                                                                                                                                    if ((length(args) == 2) &&
                                                                                                                                        (is_atom(car(args))) &&
                                                                                                                                        (is_atom(car(cdr(args)))) &&
                                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                                      increment_count(val = true);
                                                                                                                                    } else { val = NIL; }
                                                                                                                                    pop_args();
                                                                                                                                    if (val != NIL) {
                                                                                                                                      decrement_count(val);
                                                                                                                                      val = NIL;
                                                                                                                                      push_args();
                                                                                                                                      args = val;
                                                                                                                                      val = new_number(114);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = new_number(100);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = new_number(100);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = new_number(97);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = new_number(100);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = new_number(99);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      val = args;
                                                                                                                                      args = NIL;
                                                                                                                                      pop_args();
                                                                                                                                      pop_function();
                                                                                                                                    } else {
                                                                                                                                      push_args();
                                                                                                                                      val = NIL;
                                                                                                                                      args = val;
                                                                                                                                      val = -46;
                                                                                                                                      args = cons(val, args);
                                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                                      args = cons(val, args);
                                                                                                                                      if ((length(args) == 2) &&
                                                                                                                                          (is_atom(car(args))) &&
                                                                                                                                          (is_atom(car(cdr(args)))) &&
                                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                                        increment_count(val = true);
                                                                                                                                      } else { val = NIL; }
                                                                                                                                      pop_args();
                                                                                                                                      if (val != NIL) {
                                                                                                                                        decrement_count(val);
                                                                                                                                        val = NIL;
                                                                                                                                        push_args();
                                                                                                                                        args = val;
                                                                                                                                        val = new_number(114);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = new_number(97);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = new_number(97);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = new_number(100);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = new_number(100);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = new_number(99);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        val = args;
                                                                                                                                        args = NIL;
                                                                                                                                        pop_args();
                                                                                                                                        pop_function();
                                                                                                                                      } else {
                                                                                                                                        push_args();
                                                                                                                                        val = NIL;
                                                                                                                                        args = val;
                                                                                                                                        val = -45;
                                                                                                                                        args = cons(val, args);
                                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                                        args = cons(val, args);
                                                                                                                                        if ((length(args) == 2) &&
                                                                                                                                            (is_atom(car(args))) &&
                                                                                                                                            (is_atom(car(cdr(args)))) &&
                                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                                          increment_count(val = true);
                                                                                                                                        } else { val = NIL; }
                                                                                                                                        pop_args();
                                                                                                                                        if (val != NIL) {
                                                                                                                                          decrement_count(val);
                                                                                                                                          val = NIL;
                                                                                                                                          push_args();
                                                                                                                                          args = val;
                                                                                                                                          val = new_number(114);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = new_number(100);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = new_number(97);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = new_number(100);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = new_number(100);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = new_number(99);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          val = args;
                                                                                                                                          args = NIL;
                                                                                                                                          pop_args();
                                                                                                                                          pop_function();
                                                                                                                                        } else {
                                                                                                                                          push_args();
                                                                                                                                          val = NIL;
                                                                                                                                          args = val;
                                                                                                                                          val = -44;
                                                                                                                                          args = cons(val, args);
                                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                                          args = cons(val, args);
                                                                                                                                          if ((length(args) == 2) &&
                                                                                                                                              (is_atom(car(args))) &&
                                                                                                                                              (is_atom(car(cdr(args)))) &&
                                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                                            increment_count(val = true);
                                                                                                                                          } else { val = NIL; }
                                                                                                                                          pop_args();
                                                                                                                                          if (val != NIL) {
                                                                                                                                            decrement_count(val);
                                                                                                                                            val = NIL;
                                                                                                                                            push_args();
                                                                                                                                            args = val;
                                                                                                                                            val = new_number(114);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = new_number(97);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = new_number(100);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = new_number(100);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = new_number(100);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = new_number(99);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            val = args;
                                                                                                                                            args = NIL;
                                                                                                                                            pop_args();
                                                                                                                                            pop_function();
                                                                                                                                          } else {
                                                                                                                                            push_args();
                                                                                                                                            val = NIL;
                                                                                                                                            args = val;
                                                                                                                                            val = -43;
                                                                                                                                            args = cons(val, args);
                                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                                            args = cons(val, args);
                                                                                                                                            if ((length(args) == 2) &&
                                                                                                                                                (is_atom(car(args))) &&
                                                                                                                                                (is_atom(car(cdr(args)))) &&
                                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                                              increment_count(val = true);
                                                                                                                                            } else { val = NIL; }
                                                                                                                                            pop_args();
                                                                                                                                            if (val != NIL) {
                                                                                                                                              decrement_count(val);
                                                                                                                                              val = NIL;
                                                                                                                                              push_args();
                                                                                                                                              args = val;
                                                                                                                                              val = new_number(114);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = new_number(100);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = new_number(100);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = new_number(100);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = new_number(100);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = new_number(99);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              val = args;
                                                                                                                                              args = NIL;
                                                                                                                                              pop_args();
                                                                                                                                              pop_function();
                                                                                                                                            } else {
                                                                                                                                              push_args();
                                                                                                                                              val = NIL;
                                                                                                                                              args = val;
                                                                                                                                              val = CONS;
                                                                                                                                              args = cons(val, args);
                                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                                              args = cons(val, args);
                                                                                                                                              if ((length(args) == 2) &&
                                                                                                                                                  (is_atom(car(args))) &&
                                                                                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                                increment_count(val = true);
                                                                                                                                              } else { val = NIL; }
                                                                                                                                              pop_args();
                                                                                                                                              if (val != NIL) {
                                                                                                                                                decrement_count(val);
                                                                                                                                                val = NIL;
                                                                                                                                                push_args();
                                                                                                                                                args = val;
                                                                                                                                                val = new_number(115);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(110);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(111);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(99);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = args;
                                                                                                                                                args = NIL;
                                                                                                                                                pop_args();
                                                                                                                                                pop_function();
                                                                                                                                              } else {
                                                                                                                                                push_args();
                                                                                                                                                val = NIL;
                                                                                                                                                args = val;
                                                                                                                                                val = -42;
                                                                                                                                                args = cons(val, args);
                                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                                args = cons(val, args);
                                                                                                                                                if ((length(args) == 2) &&
                                                                                                                                                    (is_atom(car(args))) &&
                                                                                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                                  increment_count(val = true);
                                                                                                                                                } else { val = NIL; }
                                                                                                                                                pop_args();
                                                                                                                                                if (val != NIL) {
                                                                                                                                                  decrement_count(val);
                                                                                                                                                  val = NIL;
                                                                                                                                                  push_args();
                                                                                                                                                  args = val;
                                                                                                                                                  val = new_number(102);
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  val = new_number(105);
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  val = args;
                                                                                                                                                  args = NIL;
                                                                                                                                                  pop_args();
                                                                                                                                                  pop_function();
                                                                                                                                                } else {
                                                                                                                                                  push_args();
                                                                                                                                                  val = NIL;
                                                                                                                                                  args = val;
                                                                                                                                                  val = -41;
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  if ((length(args) == 2) &&
                                                                                                                                                      (is_atom(car(args))) &&
                                                                                                                                                      (is_atom(car(cdr(args)))) &&
                                                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                                                    increment_count(val = true);
                                                                                                                                                  } else { val = NIL; }
                                                                                                                                                  pop_args();
                                                                                                                                                  if (val != NIL) {
                                                                                                                                                    decrement_count(val);
                                                                                                                                                    val = NIL;
                                                                                                                                                    push_args();
                                                                                                                                                    args = val;
                                                                                                                                                    val = new_number(100);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    val = new_number(110);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    val = new_number(111);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    val = new_number(99);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    val = args;
                                                                                                                                                    args = NIL;
                                                                                                                                                    pop_args();
                                                                                                                                                    pop_function();
                                                                                                                                                  } else {
                                                                                                                                                    push_args();
                                                                                                                                                    val = NIL;
                                                                                                                                                    args = val;
                                                                                                                                                    val = -40;
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    if ((length(args) == 2) &&
                                                                                                                                                        (is_atom(car(args))) &&
                                                                                                                                                        (is_atom(car(cdr(args)))) &&
                                                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                                                      increment_count(val = true);
                                                                                                                                                    } else { val = NIL; }
                                                                                                                                                    pop_args();
                                                                                                                                                    if (val != NIL) {
                                                                                                                                                      decrement_count(val);
                                                                                                                                                      val = NIL;
                                                                                                                                                      push_args();
                                                                                                                                                      args = val;
                                                                                                                                                      val = new_number(116);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      val = new_number(101);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      val = new_number(108);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      val = args;
                                                                                                                                                      args = NIL;
                                                                                                                                                      pop_args();
                                                                                                                                                      pop_function();
                                                                                                                                                    } else {
                                                                                                                                                      push_args();
                                                                                                                                                      val = NIL;
                                                                                                                                                      args = val;
                                                                                                                                                      val = -39;
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      if ((length(args) == 2) &&
                                                                                                                                                          (is_atom(car(args))) &&
                                                                                                                                                          (is_atom(car(cdr(args)))) &&
                                                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                                                        increment_count(val = true);
                                                                                                                                                      } else { val = NIL; }
                                                                                                                                                      pop_args();
                                                                                                                                                      if (val != NIL) {
                                                                                                                                                        decrement_count(val);
                                                                                                                                                        val = NIL;
                                                                                                                                                        push_args();
                                                                                                                                                        args = val;
                                                                                                                                                        val = new_number(110);
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        val = new_number(102);
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        val = args;
                                                                                                                                                        args = NIL;
                                                                                                                                                        pop_args();
                                                                                                                                                        pop_function();
                                                                                                                                                      } else {
                                                                                                                                                        push_args();
                                                                                                                                                        val = NIL;
                                                                                                                                                        args = val;
                                                                                                                                                        val = -38;
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        if ((length(args) == 2) &&
                                                                                                                                                            (is_atom(car(args))) &&
                                                                                                                                                            (is_atom(car(cdr(args)))) &&
                                                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                                                          increment_count(val = true);
                                                                                                                                                        } else { val = NIL; }
                                                                                                                                                        pop_args();
                                                                                                                                                        if (val != NIL) {
                                                                                                                                                          decrement_count(val);
                                                                                                                                                          val = NIL;
                                                                                                                                                          push_args();
                                                                                                                                                          args = val;
                                                                                                                                                          val = new_number(116);
                                                                                                                                                          args = cons(val, args);
                                                                                                                                                          val = args;
                                                                                                                                                          args = NIL;
                                                                                                                                                          pop_args();
                                                                                                                                                          pop_function();
                                                                                                                                                        } else {
                                                                                                                                                          push_args();
                                                                                                                                                          val = NIL;
                                                                                                                                                          args = val;
                                                                                                                                                          val = -37;
                                                                                                                                                          args = cons(val, args);
                                                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                                                          args = cons(val, args);
                                                                                                                                                          if ((length(args) == 2) &&
                                                                                                                                                              (is_atom(car(args))) &&
                                                                                                                                                              (is_atom(car(cdr(args)))) &&
                                                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                                                            increment_count(val = true);
                                                                                                                                                          } else { val = NIL; }
                                                                                                                                                          pop_args();
                                                                                                                                                          if (val != NIL) {
                                                                                                                                                            decrement_count(val);
                                                                                                                                                            val = NIL;
                                                                                                                                                            push_args();
                                                                                                                                                            args = val;
                                                                                                                                                            val = new_number(101);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            val = new_number(116);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            val = new_number(111);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            val = new_number(117);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            val = new_number(113);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            val = args;
                                                                                                                                                            args = NIL;
                                                                                                                                                            pop_args();
                                                                                                                                                            pop_function();
                                                                                                                                                          } else {
                                                                                                                                                            push_args();
                                                                                                                                                            val = NIL;
                                                                                                                                                            args = val;
                                                                                                                                                            val = -36;
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            if ((length(args) == 2) &&
                                                                                                                                                                (is_atom(car(args))) &&
                                                                                                                                                                (is_atom(car(cdr(args)))) &&
                                                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                                                              increment_count(val = true);
                                                                                                                                                            } else { val = NIL; }
                                                                                                                                                            pop_args();
                                                                                                                                                            if (val != NIL) {
                                                                                                                                                              decrement_count(val);
                                                                                                                                                              val = NIL;
                                                                                                                                                              push_args();
                                                                                                                                                              args = val;
                                                                                                                                                              val = new_number(101);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(116);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(111);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(117);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(113);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(105);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(115);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(97);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(117);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(113);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = args;
                                                                                                                                                              args = NIL;
                                                                                                                                                              pop_args();
                                                                                                                                                              pop_function();
                                                                                                                                                            } else {
                                                                                                                                                              push_args();
                                                                                                                                                              val = NIL;
                                                                                                                                                              args = val;
                                                                                                                                                              val = -35;
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              if ((length(args) == 2) &&
                                                                                                                                                                  (is_atom(car(args))) &&
                                                                                                                                                                  (is_atom(car(cdr(args)))) &&
                                                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                                                increment_count(val = true);
                                                                                                                                                              } else { val = NIL; }
                                                                                                                                                              pop_args();
                                                                                                                                                              if (val != NIL) {
                                                                                                                                                                decrement_count(val);
                                                                                                                                                                val = NIL;
                                                                                                                                                                push_args();
                                                                                                                                                                args = val;
                                                                                                                                                                val = new_number(101);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(116);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(111);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(117);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(113);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(110);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(117);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = args;
                                                                                                                                                                args = NIL;
                                                                                                                                                                pop_args();
                                                                                                                                                                pop_function();
                                                                                                                                                              } else {
                                                                                                                                                                push_args();
                                                                                                                                                                val = NIL;
                                                                                                                                                                args = val;
                                                                                                                                                                val = -34;
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                if ((length(args) == 2) &&
                                                                                                                                                                    (is_atom(car(args))) &&
                                                                                                                                                                    (is_atom(car(cdr(args)))) &&
                                                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                                                  increment_count(val = true);
                                                                                                                                                                } else { val = NIL; }
                                                                                                                                                                pop_args();
                                                                                                                                                                if (val != NIL) {
                                                                                                                                                                  decrement_count(val);
                                                                                                                                                                  val = NIL;
                                                                                                                                                                  push_args();
                                                                                                                                                                  args = val;
                                                                                                                                                                  val = new_number(101);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(110);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(105);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(102);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(101);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(100);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = args;
                                                                                                                                                                  args = NIL;
                                                                                                                                                                  pop_args();
                                                                                                                                                                  pop_function();
                                                                                                                                                                } else {
                                                                                                                                                                  val = NIL;
                                                                                                                                                                  pop_function();
                                                                                                                                                                }
                                                                                                                                                              }
                                                                                                                                                            }
                                                                                                                                                          }
                                                                                                                                                        }
                                                                                                                                                      }
                                                                                                                                                    }
                                                                                                                                                  }
                                                                                                                                                }
                                                                                                                                              }
                                                                                                                                            }
                                                                                                                                          }
                                                                                                                                        }
                                                                                                                                      }
                                                                                                                                    }
                                                                                                                                  }
                                                                                                                                }
                                                                                                                              }
                                                                                                                            }
                                                                                                                          }
                                                                                                                        }
                                                                                                                      }
                                                                                                                    }
                                                                                                                  }
                                                                                                                }
                                                                                                              }
                                                                                                            }
                                                                                                          }
                                                                                                        }
                                                                                                      }
                                                                                                    }
                                                                                                  }
                                                                                                }
                                                                                              }
                                                                                            }
                                                                                          }
                                                                                        }
                                                                                      }
                                                                                    }
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -92;
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_4));
  }
}
void function_6() {
  increment_count(env);
  val = new_function((&function_5), env);
  pop_function();
}
/* fn_1 */
void body_2() {
  increment_count(env);
  val = new_function((&function_6), env);
  global_c102c110c95c49 = val; /* fn_1 */
  return_location = (&body_3);
}
void body_4();
pointer global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
void function_7() {
  global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* _symbol->string */
  return_location = (&body_4);
}
/* _symbol->string */
void body_3() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49); /* fn_1 */
  apply((&function_7));
}
void body_5();
pointer global_c102c110c95c50;
void function_8() {
  if (val != NIL) {
    decrement_count(val);
    val = -34;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = -92;
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    pop_function();
  }
}
void function_9() {
  if (val != NIL) {
    decrement_count(val);
    val = -35;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_8));
  }
}
void function_10() {
  if (val != NIL) {
    decrement_count(val);
    val = -36;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_9));
  }
}
void function_11() {
  if (val != NIL) {
    decrement_count(val);
    val = -37;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_10));
  }
}
void function_12() {
  if (val != NIL) {
    decrement_count(val);
    val = -38;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_11));
  }
}
void function_13() {
  if (val != NIL) {
    decrement_count(val);
    val = -39;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_12));
  }
}
void function_14() {
  if (val != NIL) {
    decrement_count(val);
    val = -40;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(110);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_13));
  }
}
void function_15() {
  if (val != NIL) {
    decrement_count(val);
    val = -41;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_14));
  }
}
void function_16() {
  if (val != NIL) {
    decrement_count(val);
    val = -42;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_15));
  }
}
void function_17() {
  if (val != NIL) {
    decrement_count(val);
    val = CONS;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(102);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_16));
  }
}
void function_18() {
  if (val != NIL) {
    decrement_count(val);
    val = -43;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(115);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_17));
  }
}
void function_19() {
  if (val != NIL) {
    decrement_count(val);
    val = -44;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_18));
  }
}
void function_20() {
  if (val != NIL) {
    decrement_count(val);
    val = -45;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_19));
  }
}
void function_21() {
  if (val != NIL) {
    decrement_count(val);
    val = -46;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_20));
  }
}
void function_22() {
  if (val != NIL) {
    decrement_count(val);
    val = -47;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_21));
  }
}
void function_23() {
  if (val != NIL) {
    decrement_count(val);
    val = -48;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_22));
  }
}
void function_24() {
  if (val != NIL) {
    decrement_count(val);
    val = -49;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_23));
  }
}
void function_25() {
  if (val != NIL) {
    decrement_count(val);
    val = -50;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_24));
  }
}
void function_26() {
  if (val != NIL) {
    decrement_count(val);
    val = -51;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_25));
  }
}
void function_27() {
  if (val != NIL) {
    decrement_count(val);
    val = -52;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_26));
  }
}
void function_28() {
  if (val != NIL) {
    decrement_count(val);
    val = -53;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_27));
  }
}
void function_29() {
  if (val != NIL) {
    decrement_count(val);
    val = -54;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_28));
  }
}
void function_30() {
  if (val != NIL) {
    decrement_count(val);
    val = -55;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_29));
  }
}
void function_31() {
  if (val != NIL) {
    decrement_count(val);
    val = -56;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_30));
  }
}
void function_32() {
  if (val != NIL) {
    decrement_count(val);
    val = -57;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_31));
  }
}
void function_33() {
  if (val != NIL) {
    decrement_count(val);
    val = -58;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_32));
  }
}
void function_34() {
  if (val != NIL) {
    decrement_count(val);
    val = -59;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_33));
  }
}
void function_35() {
  if (val != NIL) {
    decrement_count(val);
    val = -60;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_34));
  }
}
void function_36() {
  if (val != NIL) {
    decrement_count(val);
    val = -61;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_35));
  }
}
void function_37() {
  if (val != NIL) {
    decrement_count(val);
    val = -62;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_36));
  }
}
void function_38() {
  if (val != NIL) {
    decrement_count(val);
    val = -63;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_37));
  }
}
void function_39() {
  if (val != NIL) {
    decrement_count(val);
    val = -64;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_38));
  }
}
void function_40() {
  if (val != NIL) {
    decrement_count(val);
    val = -65;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_39));
  }
}
void function_41() {
  if (val != NIL) {
    decrement_count(val);
    val = -66;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_40));
  }
}
void function_42() {
  if (val != NIL) {
    decrement_count(val);
    val = -67;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_41));
  }
}
void function_43() {
  if (val != NIL) {
    decrement_count(val);
    val = -68;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_42));
  }
}
void function_44() {
  if (val != NIL) {
    decrement_count(val);
    val = -69;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_43));
  }
}
void function_45() {
  if (val != NIL) {
    decrement_count(val);
    val = -70;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_44));
  }
}
void function_46() {
  if (val != NIL) {
    decrement_count(val);
    val = -71;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_45));
  }
}
void function_47() {
  if (val != NIL) {
    decrement_count(val);
    val = -72;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(118);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_46));
  }
}
void function_48() {
  if (val != NIL) {
    decrement_count(val);
    val = -73;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_47));
  }
}
void function_49() {
  if (val != NIL) {
    decrement_count(val);
    val = -74;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(120);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_48));
  }
}
void function_50() {
  if (val != NIL) {
    decrement_count(val);
    val = -75;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_49));
  }
}
void function_51() {
  if (val != NIL) {
    decrement_count(val);
    val = -76;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_50));
  }
}
void function_52() {
  if (val != NIL) {
    decrement_count(val);
    val = -77;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_51));
  }
}
void function_53() {
  if (val != NIL) {
    decrement_count(val);
    val = -78;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(112);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_52));
  }
}
void function_54() {
  if (val != NIL) {
    decrement_count(val);
    val = -79;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_53));
  }
}
void function_55() {
  if (val != NIL) {
    decrement_count(val);
    val = -80;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_54));
  }
}
void function_56() {
  if (val != NIL) {
    decrement_count(val);
    val = -81;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_55));
  }
}
void function_57() {
  if (val != NIL) {
    decrement_count(val);
    val = -82;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(108);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_56));
  }
}
void function_58() {
  if (val != NIL) {
    decrement_count(val);
    val = -83;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(108);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_57));
  }
}
void function_59() {
  if (val != NIL) {
    decrement_count(val);
    val = -84;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(121);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_58));
  }
}
void function_60() {
  if (val != NIL) {
    decrement_count(val);
    val = -85;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_59));
  }
}
void function_61() {
  if (val != NIL) {
    decrement_count(val);
    val = -86;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_60));
  }
}
void function_62() {
  if (val != NIL) {
    decrement_count(val);
    val = -87;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(108);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(121);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(103);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_61));
  }
}
void function_63() {
  if (val != NIL) {
    decrement_count(val);
    val = -88;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(103);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(121);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_62));
  }
}
void function_64() {
  if (val != NIL) {
    decrement_count(val);
    val = LSHIFT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(63);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(121);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_63));
  }
}
void function_65() {
  if (val != NIL) {
    decrement_count(val);
    val = URSHIFT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(60);
    args = cons(val, args);
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_64));
  }
}
void function_66() {
  if (val != NIL) {
    decrement_count(val);
    val = SRSHIFT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_65));
  }
}
void function_67() {
  if (val != NIL) {
    decrement_count(val);
    val = BXOR;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_66));
  }
}
void function_68() {
  if (val != NIL) {
    decrement_count(val);
    val = BOR;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(94);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_67));
  }
}
void function_69() {
  if (val != NIL) {
    decrement_count(val);
    val = BAND;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(124);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_68));
  }
}
void function_70() {
  if (val != NIL) {
    decrement_count(val);
    val = BNEG;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(38);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_69));
  }
}
void function_71() {
  if (val != NIL) {
    decrement_count(val);
    val = MOD;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(126);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_70));
  }
}
void function_72() {
  if (val != NIL) {
    decrement_count(val);
    val = DIV;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(37);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_71));
  }
}
void function_73() {
  if (val != NIL) {
    decrement_count(val);
    val = MULT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_72));
  }
}
void function_74() {
  if (val != NIL) {
    decrement_count(val);
    val = MINUS;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(42);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_73));
  }
}
void function_75() {
  if (val != NIL) {
    decrement_count(val);
    val = PLUS;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(45);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_74));
  }
}
void function_76() {
  if (val != NIL) {
    decrement_count(val);
    val = GT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(43);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_75));
  }
}
void function_77() {
  if (val != NIL) {
    decrement_count(val);
    val = LT;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_76));
  }
}
void function_78() {
  if (val != NIL) {
    decrement_count(val);
    val = EQ;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_77));
  }
}
void function_79() {
  if (val != NIL) {
    decrement_count(val);
    val = FUNCTION;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(61);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_78));
  }
}
void function_80() {
  if (val != NIL) {
    decrement_count(val);
    val = NUMBER;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(110);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_79));
  }
}
void function_81() {
  if (val != NIL) {
    decrement_count(val);
    val = ATOM;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_80));
  }
}
void function_82() {
  if (val != NIL) {
    decrement_count(val);
    val = CDR;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(109);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_81));
  }
}
void function_83() {
  if (val != NIL) {
    decrement_count(val);
    val = CAR;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_82));
  }
}
void function_84() {
  if (val != NIL) {
    decrement_count(val);
    val = -89;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_83));
  }
}
void function_85() {
  if (val != NIL) {
    decrement_count(val);
    val = -90;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(108);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(113);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_84));
  }
}
void function_86() {
  if (val != NIL) {
    decrement_count(val);
    val = -91;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(61);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_85));
  }
}
void function_87() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c101c113c117c97c108); /* _equal */
  apply((&function_86));
}
void function_88() {
  increment_count(env);
  val = new_function((&function_87), env);
  pop_function();
}
/* fn_2 */
void body_4() {
  increment_count(env);
  val = new_function((&function_88), env);
  global_c102c110c95c50 = val; /* fn_2 */
  return_location = (&body_5);
}
void body_6();
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
void function_89() {
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  return_location = (&body_6);
}
/* _string->symbol */
void body_5() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  apply((&function_89));
}
void body_7();
pointer global_c102c110c95c51;
void function_90() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_atom(car(args))) &&
      (is_atom(car(cdr(args)))) &&
      eq(car(args), car(cdr(args)))) {
    increment_count(val = true);
  } else { val = NIL; }
  pop_args();
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      val = NIL;
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if (length(args) == 1) {
        if (is_function(car(args))) {
          increment_count(val = true);
        } else { val = NIL; }
      } else { val = NIL; }
      pop_args();
      if (val != NIL) {
        decrement_count(val);
        val = NIL;
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = car(car(env)));
        args = cons(val, args);
        if (length(args) == 1) {
          if (is_atom(car(args))) {
            increment_count(val = true); 
          } else { val = NIL; }
        } else { val = NIL; }
        pop_args();
        if (val != NIL) {
          decrement_count(val);
          val = -38;
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -92;
          args = cons(val, args);
          push_args();
          val = NIL;
          args = val;
          increment_count(val = car(car(env)));
          args = cons(val, args);
          if (length(args) == 1) {
            if (! is_atom(car(args))) {
            increment_count(val = car(car(args)));
            } else { val = NIL; }
          } else { val = NIL; }
          pop_args();
          args = cons(val, args);
          if ((length(args) == 2) &&
              (is_atom(car(args))) &&
              (is_atom(car(cdr(args)))) &&
              eq(car(args), car(cdr(args)))) {
            increment_count(val = true);
          } else { val = NIL; }
          pop_args();
          if (val != NIL) {
            decrement_count(val);
            val = -38;
            pop_function();
          } else {
            val = NIL;
            pop_function();
          }
        }
      }
    }
  }
}
void function_91() {
  increment_count(env);
  val = new_function((&function_90), env);
  pop_function();
}
/* fn_3 */
void body_6() {
  increment_count(env);
  val = new_function((&function_91), env);
  global_c102c110c95c51 = val; /* fn_3 */
  return_location = (&body_7);
}
void body_8();
pointer global_c95c115c121c109c98c111c108c63;
void function_92() {
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  return_location = (&body_8);
}
/* _symbol? */
void body_7() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  apply((&function_92));
}
void body_9();
pointer global_c102c110c95c52;
void function_93() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  if (val != NIL) {
    decrement_count(val);
    val = -38;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -92;
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_atom(car(args))) &&
        (is_atom(car(cdr(args)))) &&
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      val = -38;
      pop_function();
    } else {
      val = NIL;
      pop_function();
    }
  }
}
void function_94() {
  increment_count(env);
  val = new_function((&function_93), env);
  pop_function();
}
/* fn_4 */
void body_8() {
  increment_count(env);
  val = new_function((&function_94), env);
  global_c102c110c95c52 = val; /* fn_4 */
  return_location = (&body_9);
}
void body_10();
pointer global_c95c95c97c116c111c109;
void function_95() {
  global_c95c95c97c116c111c109 = val; /* __atom */
  return_location = (&body_10);
}
/* __atom */
void body_9() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  apply((&function_95));
}
void body_11();
pointer global_c102c110c95c53;
void function_96() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    top_level_apply();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_97() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_96));
}
void function_98() {
  increment_count(env);
  val = new_function((&function_97), env);
  pop_function();
}
/* fn_5 */
void body_10() {
  increment_count(env);
  val = new_function((&function_98), env);
  global_c102c110c95c53 = val; /* fn_5 */
  return_location = (&body_11);
}
void body_12();
pointer global_c95c95c61;
void function_99() {
  global_c95c95c61 = val; /* __= */
  return_location = (&body_12);
}
/* __= */
void body_11() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  apply((&function_99));
}
void body_13();
pointer global_c95c95c108c95c50;
/* __l_2 */
void body_12() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50 = val; /* __l_2 */
  return_location = (&body_13);
}
void body_14();
pointer global_c102c110c95c54;
void function_100() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_101() {
  increment_count(env);
  val = new_function((&function_100), env);
  pop_function();
}
/* fn_6 */
void body_13() {
  increment_count(env);
  val = new_function((&function_101), env);
  global_c102c110c95c54 = val; /* fn_6 */
  return_location = (&body_14);
}
void body_15();
pointer global_c95c105c100;
void function_102() {
  global_c95c105c100 = val; /* _id */
  return_location = (&body_15);
}
/* _id */
void body_14() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  apply((&function_102));
}
void body_16();
pointer global_c102c110c95c55 = NIL; /* fn_7 */
pointer global_c102c110c95c56;
void function_103() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  top_level_apply();
}
void function_104() {
  increment_count(env);
  val = new_function((&function_103), env);
  pop_function();
}
/* fn_8 */
void body_15() {
  increment_count(env);
  val = new_function((&function_104), env);
  global_c102c110c95c56 = val; /* fn_8 */
  return_location = (&body_16);
}
void body_17();
pointer global_c95c119c97c108c107 = NIL; /* _walk */
void function_105() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_106() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_105));
}
void function_107() {
  apply((&function_106));
}
void function_108() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  apply((&function_107));
}
void function_109() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    apply((&function_108));
  }
}
void function_110() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_109));
}
void function_111() {
  increment_count(env);
  val = new_function((&function_110), env);
  pop_function();
}
/* fn_7 */
void body_16() {
  increment_count(env);
  val = new_function((&function_111), env);
  global_c102c110c95c55 = val; /* fn_7 */
  return_location = (&body_17);
}
void body_18();
void function_112() {
  global_c95c119c97c108c107 = val; /* _walk */
  return_location = (&body_18);
}
/* _walk */
void body_17() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  apply((&function_112));
}
void body_19();
pointer global_c95c114c114c101c118c101c114c115c101 = NIL; /* _rreverse */
pointer global_c102c110c95c57;
void function_113() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
    top_level_apply();
  }
}
void function_114() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_113));
}
void function_115() {
  increment_count(env);
  val = new_function((&function_114), env);
  pop_function();
}
/* fn_9 */
void body_18() {
  increment_count(env);
  val = new_function((&function_115), env);
  global_c102c110c95c57 = val; /* fn_9 */
  return_location = (&body_19);
}
void body_20();
void function_116() {
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  return_location = (&body_20);
}
/* _rreverse */
void body_19() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  apply((&function_116));
}
void body_21();
pointer global_c102c110c95c49c48 = NIL; /* fn_10 */
pointer global_c102c110c95c49c49;
void function_117() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  top_level_apply();
}
void function_118() {
  increment_count(env);
  val = new_function((&function_117), env);
  pop_function();
}
/* fn_11 */
void body_20() {
  increment_count(env);
  val = new_function((&function_118), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  return_location = (&body_21);
}
void body_22();
pointer global_c95c102c111c108c100c108 = NIL; /* _foldl */
void function_119() {
  top_level_apply();
}
void function_120() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_119));
}
void function_121() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(cdr(env)))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    apply((&function_120));
  }
}
void function_122() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_121));
}
void function_123() {
  increment_count(env);
  val = new_function((&function_122), env);
  pop_function();
}
/* fn_10 */
void body_21() {
  increment_count(env);
  val = new_function((&function_123), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  return_location = (&body_22);
}
void body_23();
void function_124() {
  global_c95c102c111c108c100c108 = val; /* _foldl */
  return_location = (&body_23);
}
/* _foldl */
void body_22() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  apply((&function_124));
}
void body_24();
pointer global_c102c110c95c49c50 = NIL; /* fn_12 */
pointer global_c102c110c95c49c51;
void function_125() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  top_level_apply();
}
void function_126() {
  increment_count(env);
  val = new_function((&function_125), env);
  pop_function();
}
/* fn_13 */
void body_23() {
  increment_count(env);
  val = new_function((&function_126), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  return_location = (&body_24);
}
void body_25();
void function_127() {
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  top_level_apply();
}
void function_128() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_127));
}
void function_129() {
  increment_count(env);
  val = new_function((&function_128), env);
  pop_function();
}
/* fn_12 */
void body_24() {
  increment_count(env);
  val = new_function((&function_129), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  return_location = (&body_25);
}
void body_26();
pointer global_c95c102c111c108c100c114;
void function_130() {
  global_c95c102c111c108c100c114 = val; /* _foldr */
  return_location = (&body_26);
}
/* _foldr */
void body_25() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  apply((&function_130));
}
void body_27();
pointer global_c102c110c95c49c52 = NIL; /* fn_14 */
pointer global_c102c110c95c49c53;
void function_131() {
  top_level_apply();
}
void function_132() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_131));
}
void function_133() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  apply((&function_132));
}
void function_134() {
  increment_count(env);
  val = new_function((&function_133), env);
  pop_function();
}
/* fn_15 */
void body_26() {
  increment_count(env);
  val = new_function((&function_134), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  return_location = (&body_27);
}
void body_28();
pointer global_c99c111c110c115 = CONS; /* cons */
void function_135() {
  top_level_apply();
}
void function_136() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c99c111c110c115); /* cons */
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
    apply((&function_135));
  }
}
void function_137() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_136));
}
void function_138() {
  increment_count(env);
  val = new_function((&function_137), env);
  pop_function();
}
/* fn_14 */
void body_27() {
  increment_count(env);
  val = new_function((&function_138), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  return_location = (&body_28);
}
void body_29();
pointer global_c95c97c112c112c101c110c100;
void function_139() {
  global_c95c97c112c112c101c110c100 = val; /* _append */
  return_location = (&body_29);
}
/* _append */
void body_28() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  apply((&function_139));
}
void body_30();
pointer global_c102c110c95c50c49 = NIL; /* fn_21 */
pointer global_c102c110c95c50c48 = NIL; /* fn_20 */
pointer global_c102c110c95c49c56 = NIL; /* fn_18 */
pointer global_c102c110c95c49c55 = NIL; /* fn_17 */
pointer global_c102c110c95c49c54 = NIL; /* fn_16 */
pointer global_c102c110c95c50c50;
void function_140() {
  top_level_apply();
}
void function_141() {
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  apply((&function_140));
}
void function_142() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  apply((&function_141));
}
void function_143() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  apply((&function_142));
}
void function_144() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  apply((&function_143));
}
void function_145() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  apply((&function_144));
}
void function_146() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  apply((&function_145));
}
void function_147() {
  increment_count(env);
  val = new_function((&function_146), env);
  pop_function();
}
/* fn_22 */
void body_29() {
  increment_count(env);
  val = new_function((&function_147), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  return_location = (&body_30);
}
void body_31();
void function_148() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(10);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    if (value(car(cdr(args))) == 0) {
      val = NIL;
    } else {
      val = new_number(value(car(args)) %
                       value(car(cdr(args))));
    }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_149() {
  increment_count(env);
  val = new_function((&function_148), env);
  pop_function();
}
/* fn_16 */
void body_30() {
  increment_count(env);
  val = new_function((&function_149), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  return_location = (&body_31);
}
void body_32();
void function_150() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(10);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    if (value(car(cdr(args))) == 0) {
      val = NIL;
    } else {
      val = new_number(value(car(args)) / 
                       value(car(cdr(args))));
    }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_151() {
  increment_count(env);
  val = new_function((&function_150), env);
  pop_function();
}
/* fn_17 */
void body_31() {
  increment_count(env);
  val = new_function((&function_151), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  return_location = (&body_32);
}
void body_33();
void function_152() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  top_level_apply();
}
void function_153() {
  increment_count(env);
  val = new_function((&function_152), env);
  pop_function();
}
/* fn_18 */
void body_32() {
  increment_count(env);
  val = new_function((&function_153), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  return_location = (&body_33);
}
void body_34();
pointer global_c102c110c95c49c57 = NIL; /* fn_19 */
void function_154() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  top_level_apply();
}
void function_155() {
  increment_count(env);
  val = new_function((&function_154), env);
  pop_function();
}
/* fn_20 */
void body_33() {
  increment_count(env);
  val = new_function((&function_155), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  return_location = (&body_34);
}
void body_35();
void function_156() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_157() {
  increment_count(env);
  val = new_function((&function_156), env);
  pop_function();
}
/* fn_19 */
void body_34() {
  increment_count(env);
  val = new_function((&function_157), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  return_location = (&body_35);
}
void body_36();
void function_158() {
  increment_count(val = global_c95c105c100); /* _id */
  pop_function();
}
void function_159() {
  increment_count(env);
  val = new_function((&function_158), env);
  pop_function();
}
/* fn_21 */
void body_35() {
  increment_count(env);
  val = new_function((&function_159), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  return_location = (&body_36);
}
void body_37();
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
void function_160() {
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  return_location = (&body_37);
}
/* _build-num-str */
void body_36() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  apply((&function_160));
}
void body_38();
pointer global_c102c110c95c50c51;
void function_161() {
  args = cons(val, args);
  val = new_number(45);
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_162() {
  apply((&function_161));
}
void function_163() {
  top_level_apply();
}
void function_164() {
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    push_args();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_number(car(args))) &&
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      val = NIL;
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if (is_number(car(args))) {
        if ((length(args) == 2) &&
            is_number(car(cdr(args)))) {
          val = new_number(value(car(args)) - 
                           value(car(cdr(args))));
        } else if (length(args) == 1) {
          val = new_number(-value(car(args)));
        } else { val = NIL; }
      } else { val = NIL; }
      pop_args();
      args = cons(val, args);
      increment_count(val = global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* _build-num-str */
      apply((&function_162));
    } else {
      push_args();
      val = NIL;
      args = val;
      val = NIL;
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* _build-num-str */
      apply((&function_163));
    }
  }
}
void function_165() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_164));
}
void function_166() {
  increment_count(env);
  val = new_function((&function_165), env);
  pop_function();
}
/* fn_23 */
void body_37() {
  increment_count(env);
  val = new_function((&function_166), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  return_location = (&body_38);
}
void body_39();
pointer global_c95c112c114c105c110c116c45c110c117c109;
void function_167() {
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  return_location = (&body_39);
}
/* _print-num */
void body_38() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  apply((&function_167));
}
void body_40();
pointer global_c102c110c95c50c52;
void function_168() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    top_level_apply();
  } else {
    val = NIL;
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = new_number(82);
    args = cons(val, args);
    val = new_number(79);
    args = cons(val, args);
    val = new_number(82);
    args = cons(val, args);
    val = new_number(82);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(76);
    args = cons(val, args);
    val = new_number(65);
    args = cons(val, args);
    val = new_number(78);
    args = cons(val, args);
    val = new_number(82);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = new_number(84);
    args = cons(val, args);
    val = new_number(78);
    args = cons(val, args);
    val = new_number(73);
    args = cons(val, args);
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    pop_function();
  }
}
void function_169() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c112c114c105c110c116c45c110c117c109); /* _print-num */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
      apply((&function_168));
    }
  } else {
    val = NIL;
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = new_number(40);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    pop_function();
  }
}
void function_170() {
  increment_count(env);
  val = new_function((&function_169), env);
  pop_function();
}
/* fn_24 */
void body_39() {
  increment_count(env);
  val = new_function((&function_170), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  return_location = (&body_40);
}
void body_41();
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
void function_171() {
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  return_location = (&body_41);
}
/* _print-atom */
void body_40() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  apply((&function_171));
}
void body_42();
pointer global_c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* _print-tail */
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
pointer global_c102c110c95c50c53;
void function_172() {
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(46);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_173() {
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_174() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  apply((&function_173));
}
void function_175() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    val = NIL;
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109); /* _print-atom */
    apply((&function_172));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108); /* _print-tail */
    apply((&function_174));
  }
}
void function_176() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_175));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    val = NIL;
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    top_level_apply();
  }
}
void function_177() {
  increment_count(env);
  val = new_function((&function_176), env);
  pop_function();
}
/* fn_25 */
void body_41() {
  increment_count(env);
  val = new_function((&function_177), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  return_location = (&body_42);
}
void body_43();
void function_178() {
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  return_location = (&body_43);
}
/* _print-tail */
void body_42() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  apply((&function_178));
}
void body_44();
pointer global_c102c110c95c50c54;
void function_179() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_180() {
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_181() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  apply((&function_180));
}
void function_182() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109); /* _print-atom */
    apply((&function_179));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108); /* _print-tail */
    apply((&function_181));
  }
}
void function_183() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_182));
}
void function_184() {
  increment_count(env);
  val = new_function((&function_183), env);
  pop_function();
}
/* fn_26 */
void body_43() {
  increment_count(env);
  val = new_function((&function_184), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  return_location = (&body_44);
}
void body_45();
void function_185() {
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  return_location = (&body_45);
}
/* _print-with-suffix */
void body_44() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  apply((&function_185));
}
void body_46();
pointer global_c102c110c95c50c55;
void function_186() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  top_level_apply();
}
void function_187() {
  increment_count(env);
  val = new_function((&function_186), env);
  pop_function();
}
/* fn_27 */
void body_45() {
  increment_count(env);
  val = new_function((&function_187), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  return_location = (&body_46);
}
void body_47();
pointer global_c95c112c114c105c110c116;
void function_188() {
  global_c95c112c114c105c110c116 = val; /* _print */
  return_location = (&body_47);
}
/* _print */
void body_46() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  apply((&function_188));
}
void body_48();
pointer global_c102c110c95c50c56;
void function_189() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_190() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50); /* __l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_189));
}
void function_191() {
  increment_count(env);
  val = new_function((&function_190), env);
  pop_function();
}
/* fn_28 */
void body_47() {
  increment_count(env);
  val = new_function((&function_191), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  return_location = (&body_48);
}
void body_49();
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
void function_192() {
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* ___print-with-newline */
  return_location = (&body_49);
}
/* ___print-with-newline */
void body_48() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  apply((&function_192));
}
void body_50();
pointer global_c102c110c95c50c57;
void function_193() {
  increment_count(val = car(env));
  pop_function();
}
void function_194() {
  increment_count(env);
  val = new_function((&function_193), env);
  pop_function();
}
/* fn_29 */
void body_49() {
  increment_count(env);
  val = new_function((&function_194), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  return_location = (&body_50);
}
void body_51();
pointer global_c95c108c105c115c116;
void function_195() {
  global_c95c108c105c115c116 = val; /* _list */
  return_location = (&body_51);
}
/* _list */
void body_50() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  apply((&function_195));
}
void body_52();
pointer global_c102c110c95c51c48;
void function_196() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_197() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_number(2);
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_196));
}
void function_198() {
  increment_count(env);
  val = new_function((&function_197), env);
  pop_function();
}
/* fn_30 */
void body_51() {
  increment_count(env);
  val = new_function((&function_198), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  return_location = (&body_52);
}
void body_53();
pointer global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
void function_199() {
  global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ___map-to-stderr */
  return_location = (&body_53);
}
void function_200() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_199));
}
/* ___map-to-stderr */
void body_52() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  apply((&function_200));
}
void body_54();
pointer global_c95c95c108c95c51;
/* __l_3 */
void body_53() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(59);
  args = cons(val, args);
  val = new_number(71);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(73);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(82);
  args = cons(val, args);
  val = new_number(65);
  args = cons(val, args);
  val = new_number(87);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51 = val; /* __l_3 */
  return_location = (&body_54);
}
void body_55();
pointer global_c95c95c108c95c52;
/* __l_4 */
void body_54() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(98);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(73);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52 = val; /* __l_4 */
  return_location = (&body_55);
}
void body_56();
pointer global_c95c95c108c95c53;
/* __l_5 */
void body_55() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c53 = val; /* __l_5 */
  return_location = (&body_56);
}
void body_57();
pointer global_c95c95c108c95c54;
/* __l_6 */
void body_56() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54 = val; /* __l_6 */
  return_location = (&body_57);
}
void body_58();
pointer global_c102c110c95c51c49;
void function_201() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_202() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c52); /* __l_4 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51); /* __l_3 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_201));
}
void function_203() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c54); /* __l_6 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53); /* __l_5 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    apply((&function_202));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_204() {
  increment_count(env);
  val = new_function((&function_203), env);
  pop_function();
}
/* fn_31 */
void body_57() {
  increment_count(env);
  val = new_function((&function_204), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  return_location = (&body_58);
}
void body_59();
pointer global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
void function_205() {
  global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ___print-warnings */
  return_location = (&body_59);
}
/* ___print-warnings */
void body_58() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  apply((&function_205));
}
void body_60();
pointer global_c95c95c108c95c55;
/* __l_7 */
void body_59() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(59);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(69);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c55 = val; /* __l_7 */
  return_location = (&body_60);
}
void body_61();
pointer global_c95c95c108c95c56;
/* __l_8 */
void body_60() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c56 = val; /* __l_8 */
  return_location = (&body_61);
}
void body_62();
pointer global_c102c110c95c51c50;
void function_206() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_207() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c56); /* __l_8 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c55); /* __l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_206));
}
void function_208() {
  increment_count(env);
  val = new_function((&function_207), env);
  pop_function();
}
/* fn_32 */
void body_61() {
  increment_count(env);
  val = new_function((&function_208), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  return_location = (&body_62);
}
void body_63();
pointer global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
void function_209() {
  global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ___print-error */
  return_location = (&body_63);
}
/* ___print-error */
void body_62() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  apply((&function_209));
}
void body_64();
pointer global_c95c95c108c95c57;
/* __l_9 */
void body_63() {
  val = NIL;
  push_args();
  args = val;
  val = -39;
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  val = -34;
  args = cons(val, args);
  val = -42;
  args = cons(val, args);
  val = -40;
  args = cons(val, args);
  val = -35;
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c57 = val; /* __l_9 */
  return_location = (&body_64);
}
void body_65();
pointer global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ___special-forms */
void body_64() {
  increment_count(val = global_c95c95c108c95c57); /* __l_9 */
  global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ___special-forms */
  return_location = (&body_65);
}
void body_66();
pointer global_c95c95c108c95c49c48;
/* __l_10 */
void body_65() {
  val = NIL;
  push_args();
  args = val;
  val = -86;
  args = cons(val, args);
  val = -87;
  args = cons(val, args);
  val = -88;
  args = cons(val, args);
  val = LSHIFT;
  args = cons(val, args);
  val = URSHIFT;
  args = cons(val, args);
  val = SRSHIFT;
  args = cons(val, args);
  val = BXOR;
  args = cons(val, args);
  val = BOR;
  args = cons(val, args);
  val = BAND;
  args = cons(val, args);
  val = BNEG;
  args = cons(val, args);
  val = MOD;
  args = cons(val, args);
  val = DIV;
  args = cons(val, args);
  val = MULT;
  args = cons(val, args);
  val = MINUS;
  args = cons(val, args);
  val = PLUS;
  args = cons(val, args);
  val = GT;
  args = cons(val, args);
  val = LT;
  args = cons(val, args);
  val = -90;
  args = cons(val, args);
  val = FUNCTION;
  args = cons(val, args);
  val = NUMBER;
  args = cons(val, args);
  val = -91;
  args = cons(val, args);
  val = CDR;
  args = cons(val, args);
  val = CAR;
  args = cons(val, args);
  val = CONS;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c49c48 = val; /* __l_10 */
  return_location = (&body_66);
}
void body_67();
pointer global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* ___supported-builtins */
void body_66() {
  increment_count(val = global_c95c95c108c95c49c48); /* __l_10 */
  global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* ___supported-builtins */
  return_location = (&body_67);
}
void body_68();
pointer global_c95c95c108c95c49c49;
/* __l_11 */
void body_67() {
  val = NIL;
  global_c95c95c108c95c49c49 = val; /* __l_11 */
  return_location = (&body_68);
}
void body_69();
pointer global_c95c95c95c102c108c97c116c116c101c110 = NIL; /* ___flatten */
pointer global_c102c110c95c51c51;
void function_210() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c108c97c116c116c101c110); /* ___flatten */
  top_level_apply();
}
void function_211() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c102c108c97c116c116c101c110); /* ___flatten */
    apply((&function_210));
  }
}
void function_212() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_211));
  }
}
void function_213() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    apply((&function_212));
  }
}
void function_214() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c49); /* __l_11 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_213));
}
void function_215() {
  increment_count(env);
  val = new_function((&function_214), env);
  pop_function();
}
/* fn_33 */
void body_68() {
  increment_count(env);
  val = new_function((&function_215), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  return_location = (&body_69);
}
void body_70();
void function_216() {
  global_c95c95c95c102c108c97c116c116c101c110 = val; /* ___flatten */
  return_location = (&body_70);
}
/* ___flatten */
void body_69() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  apply((&function_216));
}
void body_71();
pointer global_c95c95c108c95c49c50;
/* __l_12 */
void body_70() {
  val = NIL;
  push_args();
  args = val;
  val = -43;
  args = cons(val, args);
  val = -44;
  args = cons(val, args);
  val = -45;
  args = cons(val, args);
  val = -46;
  args = cons(val, args);
  val = -47;
  args = cons(val, args);
  val = -48;
  args = cons(val, args);
  val = -49;
  args = cons(val, args);
  val = -50;
  args = cons(val, args);
  val = -51;
  args = cons(val, args);
  val = -52;
  args = cons(val, args);
  val = -53;
  args = cons(val, args);
  val = -54;
  args = cons(val, args);
  val = -55;
  args = cons(val, args);
  val = -56;
  args = cons(val, args);
  val = -57;
  args = cons(val, args);
  val = -58;
  args = cons(val, args);
  val = -59;
  args = cons(val, args);
  val = -60;
  args = cons(val, args);
  val = -61;
  args = cons(val, args);
  val = -62;
  args = cons(val, args);
  val = -63;
  args = cons(val, args);
  val = -64;
  args = cons(val, args);
  val = -65;
  args = cons(val, args);
  val = -66;
  args = cons(val, args);
  val = -67;
  args = cons(val, args);
  val = -68;
  args = cons(val, args);
  val = -69;
  args = cons(val, args);
  val = -70;
  args = cons(val, args);
  val = -71;
  args = cons(val, args);
  val = -72;
  args = cons(val, args);
  val = -73;
  args = cons(val, args);
  val = -74;
  args = cons(val, args);
  val = -75;
  args = cons(val, args);
  val = -76;
  args = cons(val, args);
  val = -77;
  args = cons(val, args);
  val = -78;
  args = cons(val, args);
  val = -79;
  args = cons(val, args);
  val = -80;
  args = cons(val, args);
  val = -81;
  args = cons(val, args);
  val = -89;
  args = cons(val, args);
  val = -83;
  args = cons(val, args);
  val = -84;
  args = cons(val, args);
  val = -85;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c49c50 = val; /* __l_12 */
  return_location = (&body_71);
}
void body_72();
pointer global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115;
/* ___supported-library-procedures */
void body_71() {
  increment_count(val = global_c95c95c108c95c49c50); /* __l_12 */
  global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 = val; /* ___supported-library-procedures */
  return_location = (&body_72);
}
void body_73();
pointer global_c95c95c108c95c49c51;
/* __l_13 */
void body_72() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c49c51 = val; /* __l_13 */
  return_location = (&body_73);
}
void body_74();
pointer global_c95c95c101c113c117c97c108 = NIL; /* __equal */
pointer global_c102c110c95c51c52;
void function_217() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    top_level_apply();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_218() {
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_217));
  }
}
void function_219() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_218));
  }
}
void function_220() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_219));
}
void function_221() {
  increment_count(env);
  val = new_function((&function_220), env);
  pop_function();
}
/* fn_34 */
void body_73() {
  increment_count(env);
  val = new_function((&function_221), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  return_location = (&body_74);
}
void body_75();
void function_222() {
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  return_location = (&body_75);
}
/* __equal */
void body_74() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  apply((&function_222));
}
void body_76();
pointer global_c95c109c101c109c98c101c114 = NIL; /* _member */
pointer global_c102c110c95c51c53;
void function_223() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    top_level_apply();
  }
}
void function_224() {
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_223));
  }
}
void function_225() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_224));
}
void function_226() {
  increment_count(env);
  val = new_function((&function_225), env);
  pop_function();
}
/* fn_35 */
void body_75() {
  increment_count(env);
  val = new_function((&function_226), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  return_location = (&body_76);
}
void body_77();
void function_227() {
  global_c95c109c101c109c98c101c114 = val; /* _member */
  return_location = (&body_77);
}
/* _member */
void body_76() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  apply((&function_227));
}
void body_78();
pointer global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ___escape-symbols */
pointer global_c102c110c95c51c54;
void function_228() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_229() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c51); /* __l_13 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_228));
}
void function_230() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    apply((&function_229));
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_231() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    apply((&function_230));
  }
}
void function_232() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115); /* ___supported-library-procedures */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_231));
  }
}
void function_233() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115); /* ___supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_232));
  }
}
void function_234() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_235() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_234));
}
void function_236() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115); /* ___special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_233));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
    apply((&function_235));
  }
}
void function_237() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_236));
}
void function_238() {
  increment_count(env);
  val = new_function((&function_237), env);
  pop_function();
}
/* fn_36 */
void body_77() {
  increment_count(env);
  val = new_function((&function_238), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  return_location = (&body_78);
}
void body_79();
void function_239() {
  global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ___escape-symbols */
  return_location = (&body_79);
}
/* ___escape-symbols */
void body_78() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  apply((&function_239));
}
void body_80();
pointer global_c95c95c108c95c49c52;
/* __l_14 */
void body_79() {
  val = NIL;
  global_c95c95c108c95c49c52 = val; /* __l_14 */
  return_location = (&body_80);
}
void body_81();
pointer global_c95c95c108c95c49c53;
/* __l_15 */
void body_80() {
  val = NIL;
  global_c95c95c108c95c49c53 = val; /* __l_15 */
  return_location = (&body_81);
}
void body_82();
pointer global_c95c95c108c95c49c54;
/* __l_16 */
void body_81() {
  val = NIL;
  global_c95c95c108c95c49c54 = val; /* __l_16 */
  return_location = (&body_82);
}
void body_83();
pointer global_c95c95c108c95c49c55;
/* __l_17 */
void body_82() {
  val = NIL;
  global_c95c95c108c95c49c55 = val; /* __l_17 */
  return_location = (&body_83);
}
void body_84();
pointer global_c95c95c108c95c49c56;
/* __l_18 */
void body_83() {
  val = NIL;
  global_c95c95c108c95c49c56 = val; /* __l_18 */
  return_location = (&body_84);
}
void body_85();
pointer global_c95c95c108c95c49c57;
/* __l_19 */
void body_84() {
  val = NIL;
  global_c95c95c108c95c49c57 = val; /* __l_19 */
  return_location = (&body_85);
}
void body_86();
pointer global_c95c95c108c95c50c48;
/* __l_20 */
void body_85() {
  val = NIL;
  global_c95c95c108c95c50c48 = val; /* __l_20 */
  return_location = (&body_86);
}
void body_87();
pointer global_c95c95c108c95c50c49;
/* __l_21 */
void body_86() {
  val = NIL;
  global_c95c95c108c95c50c49 = val; /* __l_21 */
  return_location = (&body_87);
}
void body_88();
pointer global_c95c95c108c95c50c50;
/* __l_22 */
void body_87() {
  val = NIL;
  global_c95c95c108c95c50c50 = val; /* __l_22 */
  return_location = (&body_88);
}
void body_89();
pointer global_c95c95c108c95c50c51;
/* __l_23 */
void body_88() {
  val = NIL;
  global_c95c95c108c95c50c51 = val; /* __l_23 */
  return_location = (&body_89);
}
void body_90();
pointer global_c95c95c108c95c50c52;
/* __l_24 */
void body_89() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(118);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(119);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(107);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(85);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c52 = val; /* __l_24 */
  return_location = (&body_90);
}
void body_91();
pointer global_c95c95c108c95c50c53;
/* __l_25 */
void body_90() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  val = new_number(76);
  args = cons(val, args);
  val = new_number(73);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(118);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(119);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c53 = val; /* __l_25 */
  return_location = (&body_91);
}
void body_92();
pointer global_c102c110c95c51c55;
void function_240() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c52); /* __l_14 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_241() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c51); /* __l_23 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c50); /* __l_22 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_242() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c52); /* __l_24 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_241));
}
void function_243() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c49); /* __l_21 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c48); /* __l_20 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c50c53); /* __l_25 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    apply((&function_242));
  }
}
void function_244() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c57); /* __l_19 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c56); /* __l_18 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115); /* ___special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_243));
  }
}
void function_245() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c55); /* __l_17 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c54); /* __l_16 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115); /* ___supported-library-procedures */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_244));
  }
}
void function_246() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c53); /* __l_15 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
    apply((&function_240));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115); /* ___supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_245));
  }
}
void function_247() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  apply((&function_246));
}
void function_248() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c108c97c116c116c101c110); /* ___flatten */
  apply((&function_247));
}
void function_249() {
  increment_count(env);
  val = new_function((&function_248), env);
  pop_function();
}
/* fn_37 */
void body_91() {
  increment_count(env);
  val = new_function((&function_249), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  return_location = (&body_92);
}
void body_93();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100;
void function_250() {
  global_c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* ___compile-find */
  return_location = (&body_93);
}
/* ___compile-find */
void body_92() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  apply((&function_250));
}
void body_94();
pointer global_c95c95c108c95c50c54;
/* __l_26 */
void body_93() {
  val = NIL;
  global_c95c95c108c95c50c54 = val; /* __l_26 */
  return_location = (&body_94);
}
void body_95();
pointer global_c95c95c108c95c50c55;
/* __l_27 */
void body_94() {
  val = -37;
  global_c95c95c108c95c50c55 = val; /* __l_27 */
  return_location = (&body_95);
}
void body_96();
pointer global_c95c95c108c95c50c56;
/* __l_28 */
void body_95() {
  val = CONS;
  global_c95c95c108c95c50c56 = val; /* __l_28 */
  return_location = (&body_96);
}
void body_97();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = NIL; /* ___rewrite-quote */
pointer global_c102c110c95c51c56;
void function_251() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c56); /* __l_28 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_252() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101); /* ___rewrite-quote */
  apply((&function_251));
}
void function_253() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c55); /* __l_27 */
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101); /* ___rewrite-quote */
    apply((&function_252));
  }
}
void function_254() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      increment_count(val = car(car(env)));
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c97c116c111c109); /* __atom */
      apply((&function_253));
    }
  }
}
void function_255() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50c54); /* __l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_254));
}
void function_256() {
  increment_count(env);
  val = new_function((&function_255), env);
  pop_function();
}
/* fn_38 */
void body_96() {
  increment_count(env);
  val = new_function((&function_256), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  return_location = (&body_97);
}
void body_98();
void function_257() {
  global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* ___rewrite-quote */
  return_location = (&body_98);
}
/* ___rewrite-quote */
void body_97() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  apply((&function_257));
}
void body_99();
pointer global_c95c95c108c95c50c57;
/* __l_29 */
void body_98() {
  val = NIL;
  global_c95c95c108c95c50c57 = val; /* __l_29 */
  return_location = (&body_99);
}
void body_100();
pointer global_c95c95c108c95c51c48;
/* __l_30 */
void body_99() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c48 = val; /* __l_30 */
  return_location = (&body_100);
}
void body_101();
pointer global_c102c110c95c51c57 = NIL; /* fn_39 */
pointer global_c102c110c95c52c48;
void function_258() {
  top_level_apply();
}
void function_259() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  apply((&function_258));
}
void function_260() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  apply((&function_259));
}
void function_261() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c48); /* __l_30 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_260));
}
void function_262() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_261));
}
void function_263() {
  increment_count(env);
  val = new_function((&function_262), env);
  pop_function();
}
/* fn_40 */
void body_100() {
  increment_count(env);
  val = new_function((&function_263), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  return_location = (&body_101);
}
void body_102();
void function_264() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c57); /* __l_29 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -34;
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_265() {
  increment_count(env);
  val = new_function((&function_264), env);
  pop_function();
}
/* fn_39 */
void body_101() {
  increment_count(env);
  val = new_function((&function_265), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  return_location = (&body_102);
}
void body_103();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101;
void function_266() {
  global_c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* ___compile-quote */
  return_location = (&body_103);
}
/* ___compile-quote */
void body_102() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  apply((&function_266));
}
void body_104();
pointer global_c95c95c108c95c51c49;
/* __l_31 */
void body_103() {
  val = NIL;
  global_c95c95c108c95c51c49 = val; /* __l_31 */
  return_location = (&body_104);
}
void body_105();
pointer global_c95c95c108c95c51c50;
/* __l_32 */
void body_104() {
  val = NIL;
  global_c95c95c108c95c51c50 = val; /* __l_32 */
  return_location = (&body_105);
}
void body_106();
pointer global_c95c95c108c95c51c51;
/* __l_33 */
void body_105() {
  val = NIL;
  global_c95c95c108c95c51c51 = val; /* __l_33 */
  return_location = (&body_106);
}
void body_107();
pointer global_c95c95c108c95c51c52;
/* __l_34 */
void body_106() {
  val = -37;
  global_c95c95c108c95c51c52 = val; /* __l_34 */
  return_location = (&body_107);
}
void body_108();
pointer global_c95c95c108c95c51c53;
/* __l_35 */
void body_107() {
  val = NIL;
  global_c95c95c108c95c51c53 = val; /* __l_35 */
  return_location = (&body_108);
}
void body_109();
pointer global_c95c95c108c95c51c54;
/* __l_36 */
void body_108() {
  val = -35;
  global_c95c95c108c95c51c54 = val; /* __l_36 */
  return_location = (&body_109);
}
void body_110();
pointer global_c95c95c108c95c51c55;
/* __l_37 */
void body_109() {
  val = -35;
  global_c95c95c108c95c51c55 = val; /* __l_37 */
  return_location = (&body_110);
}
void body_111();
pointer global_c95c95c108c95c51c56;
/* __l_38 */
void body_110() {
  val = -36;
  global_c95c95c108c95c51c56 = val; /* __l_38 */
  return_location = (&body_111);
}
void body_112();
pointer global_c95c95c108c95c51c57;
/* __l_39 */
void body_111() {
  val = -36;
  global_c95c95c108c95c51c57 = val; /* __l_39 */
  return_location = (&body_112);
}
void body_113();
pointer global_c95c95c108c95c52c48;
/* __l_40 */
void body_112() {
  val = CONS;
  global_c95c95c108c95c52c48 = val; /* __l_40 */
  return_location = (&body_113);
}
void body_114();
pointer global_c102c110c95c52c49;
void function_267() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_268() {
  increment_count(env);
  val = new_function((&function_267), env);
  pop_function();
}
/* fn_41 */
void body_113() {
  increment_count(env);
  val = new_function((&function_268), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  return_location = (&body_114);
}
void body_115();
pointer global_c95c99c97c100c114;
void function_269() {
  global_c95c99c97c100c114 = val; /* _cadr */
  return_location = (&body_115);
}
/* _cadr */
void body_114() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  apply((&function_269));
}
void body_116();
pointer global_c102c110c95c52c53 = NIL; /* fn_45 */
pointer global_c102c110c95c52c51 = NIL; /* fn_43 */
pointer global_c102c110c95c52c50 = NIL; /* fn_42 */
pointer global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = NIL; /* ___rewrite-quasiquote */
pointer global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = NIL; /* ___compile-expr */
pointer global_c102c110c95c52c54;
void function_270() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c51); /* __l_33 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  top_level_apply();
}
void function_271() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_272() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_273() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((length(args) == 2) &&
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (length(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_272));
}
void function_274() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    apply((&function_271));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c52c50); /* fn_42 */
    apply((&function_273));
  }
}
void function_275() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_276() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_275));
}
void function_277() {
  top_level_apply();
}
void function_278() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  apply((&function_277));
}
void function_279() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c52c51); /* fn_43 */
    apply((&function_276));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c105c115c116); /* _list */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
    apply((&function_278));
  }
}
void function_280() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_274));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c51c56); /* __l_38 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_279));
  }
}
void function_281() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c53); /* __l_35 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c52); /* __l_34 */
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    apply((&function_270));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c51c54); /* __l_36 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_280));
  }
}
void function_282() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_number(car(args))) {
      increment_count(val = true);
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c50); /* __l_32 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c49); /* __l_31 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_281));
  }
}
void function_283() {
  increment_count(env);
  val = new_function((&function_282), env);
  pop_function();
}
/* fn_46 */
void body_115() {
  increment_count(env);
  val = new_function((&function_283), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  return_location = (&body_116);
}
void body_117();
void function_284() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_285() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c55); /* __l_37 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_284));
}
void function_286() {
  increment_count(env);
  val = new_function((&function_285), env);
  pop_function();
}
/* fn_42 */
void body_116() {
  increment_count(env);
  val = new_function((&function_286), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  return_location = (&body_117);
}
void body_118();
void function_287() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_288() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c57); /* __l_39 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_287));
}
void function_289() {
  increment_count(env);
  val = new_function((&function_288), env);
  pop_function();
}
/* fn_43 */
void body_117() {
  increment_count(env);
  val = new_function((&function_289), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  return_location = (&body_118);
}
void body_119();
pointer global_c102c110c95c52c52 = NIL; /* fn_44 */
void function_290() {
  top_level_apply();
}
void function_291() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  apply((&function_290));
}
void function_292() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c105c115c116); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  apply((&function_291));
}
void function_293() {
  increment_count(env);
  val = new_function((&function_292), env);
  pop_function();
}
/* fn_45 */
void body_118() {
  increment_count(env);
  val = new_function((&function_293), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  return_location = (&body_119);
}
void body_120();
void function_294() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_295() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_294));
}
void function_296() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c52c48); /* __l_40 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_295));
}
void function_297() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_296));
}
void function_298() {
  increment_count(env);
  val = new_function((&function_297), env);
  pop_function();
}
/* fn_44 */
void body_119() {
  increment_count(env);
  val = new_function((&function_298), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  return_location = (&body_120);
}
void body_121();
void function_299() {
  global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* ___rewrite-quasiquote */
  return_location = (&body_121);
}
/* ___rewrite-quasiquote */
void body_120() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  apply((&function_299));
}
void body_122();
pointer global_c95c95c108c95c52c49;
/* __l_41 */
void body_121() {
  val = NIL;
  global_c95c95c108c95c52c49 = val; /* __l_41 */
  return_location = (&body_122);
}
void body_123();
pointer global_c95c95c108c95c52c50;
/* __l_42 */
void body_122() {
  val = -37;
  global_c95c95c108c95c52c50 = val; /* __l_42 */
  return_location = (&body_123);
}
void body_124();
pointer global_c95c95c108c95c52c51;
/* __l_43 */
void body_123() {
  val = NIL;
  global_c95c95c108c95c52c51 = val; /* __l_43 */
  return_location = (&body_124);
}
void body_125();
pointer global_c95c95c108c95c52c52;
/* __l_44 */
void body_124() {
  val = NIL;
  global_c95c95c108c95c52c52 = val; /* __l_44 */
  return_location = (&body_125);
}
void body_126();
pointer global_c95c95c108c95c52c53;
/* __l_45 */
void body_125() {
  val = NIL;
  global_c95c95c108c95c52c53 = val; /* __l_45 */
  return_location = (&body_126);
}
void body_127();
pointer global_c95c95c108c95c52c54;
/* __l_46 */
void body_126() {
  val = -38;
  global_c95c95c108c95c52c54 = val; /* __l_46 */
  return_location = (&body_127);
}
void body_128();
pointer global_c102c110c95c52c55;
void function_300() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    val = -38;
    pop_function();
  }
}
void function_301() {
  increment_count(env);
  val = new_function((&function_300), env);
  pop_function();
}
/* fn_47 */
void body_127() {
  increment_count(env);
  val = new_function((&function_301), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  return_location = (&body_128);
}
void body_129();
pointer global_c95c110c111c116;
void function_302() {
  global_c95c110c111c116 = val; /* _not */
  return_location = (&body_129);
}
/* _not */
void body_128() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  apply((&function_302));
}
void body_130();
pointer global_c102c110c95c52c56;
void function_303() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c52c53); /* __l_45 */
    pop_function();
  } else {
    increment_count(val = global_c95c95c108c95c52c54); /* __l_46 */
    pop_function();
  }
}
void function_304() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c52c51); /* __l_43 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c52c52); /* __l_44 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_303));
  }
}
void function_305() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_304));
}
void function_306() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c52c50); /* __l_42 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_305));
  }
}
void function_307() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c52c49); /* __l_41 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_306));
  }
}
void function_308() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_307));
}
void function_309() {
  increment_count(env);
  val = new_function((&function_308), env);
  pop_function();
}
/* fn_48 */
void body_129() {
  increment_count(env);
  val = new_function((&function_309), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  return_location = (&body_130);
}
void body_131();
pointer global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101;
void function_310() {
  global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101 = val; /* ___always-true */
  return_location = (&body_131);
}
/* ___always-true */
void body_130() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  apply((&function_310));
}
void body_132();
pointer global_c95c95c108c95c52c55;
/* __l_47 */
void body_131() {
  val = NIL;
  global_c95c95c108c95c52c55 = val; /* __l_47 */
  return_location = (&body_132);
}
void body_133();
pointer global_c95c95c108c95c52c56;
/* __l_48 */
void body_132() {
  val = NIL;
  global_c95c95c108c95c52c56 = val; /* __l_48 */
  return_location = (&body_133);
}
void body_134();
pointer global_c95c95c108c95c52c57;
/* __l_49 */
void body_133() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(46);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(85);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52c57 = val; /* __l_49 */
  return_location = (&body_134);
}
void body_135();
pointer global_c95c95c108c95c53c48;
/* __l_50 */
void body_134() {
  val = -42;
  global_c95c95c108c95c53c48 = val; /* __l_50 */
  return_location = (&body_135);
}
void body_136();
pointer global_c102c110c95c52c57;
void function_311() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_312() {
  increment_count(env);
  val = new_function((&function_311), env);
  pop_function();
}
/* fn_49 */
void body_135() {
  increment_count(env);
  val = new_function((&function_312), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  return_location = (&body_136);
}
void body_137();
pointer global_c95c99c97c97c114;
void function_313() {
  global_c95c99c97c97c114 = val; /* _caar */
  return_location = (&body_137);
}
/* _caar */
void body_136() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  apply((&function_313));
}
void body_138();
pointer global_c102c110c95c53c48;
void function_314() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_315() {
  increment_count(env);
  val = new_function((&function_314), env);
  pop_function();
}
/* fn_50 */
void body_137() {
  increment_count(env);
  val = new_function((&function_315), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  return_location = (&body_138);
}
void body_139();
pointer global_c95c99c97c100c97c114;
void function_316() {
  global_c95c99c97c100c97c114 = val; /* _cadar */
  return_location = (&body_139);
}
/* _cadar */
void body_138() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  apply((&function_316));
}
void body_140();
pointer global_c102c110c95c53c51 = NIL; /* fn_53 */
pointer global_c102c110c95c53c52;
void function_317() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_318() {
  top_level_apply();
}
void function_319() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  apply((&function_318));
}
void function_320() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_319));
}
void function_321() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c97c114); /* _cadar */
    apply((&function_317));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c105c115c116); /* _list */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c114); /* _caar */
    apply((&function_320));
  }
}
void function_322() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101); /* ___always-true */
  apply((&function_321));
}
void function_323() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c52c57); /* __l_49 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c52c56); /* __l_48 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c52c55); /* __l_47 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c114); /* _caar */
    apply((&function_322));
  }
}
void function_324() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_323));
}
void function_325() {
  increment_count(env);
  val = new_function((&function_324), env);
  pop_function();
}
/* fn_54 */
void body_139() {
  increment_count(env);
  val = new_function((&function_325), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  return_location = (&body_140);
}
void body_141();
pointer global_c102c110c95c53c50 = NIL; /* fn_52 */
void function_326() {
  top_level_apply();
}
void function_327() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  apply((&function_326));
}
void function_328() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_327));
}
void function_329() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c105c115c116); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c97c114); /* _cadar */
  apply((&function_328));
}
void function_330() {
  increment_count(env);
  val = new_function((&function_329), env);
  pop_function();
}
/* fn_53 */
void body_140() {
  increment_count(env);
  val = new_function((&function_330), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  return_location = (&body_141);
}
void body_142();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = NIL; /* ___rewrite-cond */
pointer global_c102c110c95c53c49 = NIL; /* fn_51 */
void function_331() {
  top_level_apply();
}
void function_332() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  apply((&function_331));
}
void function_333() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c105c115c116); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100); /* ___rewrite-cond */
  apply((&function_332));
}
void function_334() {
  increment_count(env);
  val = new_function((&function_333), env);
  pop_function();
}
/* fn_52 */
void body_141() {
  increment_count(env);
  val = new_function((&function_334), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  return_location = (&body_142);
}
void body_143();
void function_335() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_336() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_335));
}
void function_337() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c48); /* __l_50 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_336));
}
void function_338() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_337));
}
void function_339() {
  increment_count(env);
  val = new_function((&function_338), env);
  pop_function();
}
/* fn_51 */
void body_142() {
  increment_count(env);
  val = new_function((&function_339), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  return_location = (&body_143);
}
void body_144();
void function_340() {
  global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* ___rewrite-cond */
  return_location = (&body_144);
}
/* ___rewrite-cond */
void body_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  apply((&function_340));
}
void body_145();
pointer global_c95c95c108c95c53c49;
/* __l_51 */
void body_144() {
  val = -39;
  global_c95c95c108c95c53c49 = val; /* __l_51 */
  return_location = (&body_145);
}
void body_146();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = NIL; /* ___rewrite-let */
pointer global_c102c110c95c53c53;
void function_341() {
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_342() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c49); /* __l_51 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_341));
}
void function_343() {
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_342));
}
void function_344() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c97c114); /* _caar */
  apply((&function_343));
}
void function_345() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116); /* ___rewrite-let */
  apply((&function_344));
}
void function_346() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c97c114); /* _cadar */
    apply((&function_345));
  }
}
void function_347() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_346));
}
void function_348() {
  increment_count(env);
  val = new_function((&function_347), env);
  pop_function();
}
/* fn_55 */
void body_145() {
  increment_count(env);
  val = new_function((&function_348), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  return_location = (&body_146);
}
void body_147();
void function_349() {
  global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = val; /* ___rewrite-let */
  return_location = (&body_147);
}
/* ___rewrite-let */
void body_146() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  apply((&function_349));
}
void body_148();
pointer global_c102c110c95c53c55 = NIL; /* fn_57 */
pointer global_c102c110c95c53c56;
void function_350() {
  top_level_apply();
}
void function_351() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  apply((&function_350));
}
void function_352() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c105c115c116); /* _list */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
    apply((&function_351));
  }
}
void function_353() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_352));
}
void function_354() {
  increment_count(env);
  val = new_function((&function_353), env);
  pop_function();
}
/* fn_58 */
void body_147() {
  increment_count(env);
  val = new_function((&function_354), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  return_location = (&body_148);
}
void body_149();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = NIL; /* ___compile-args */
pointer global_c102c110c95c53c54 = NIL; /* fn_56 */
void function_355() {
  top_level_apply();
}
void function_356() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  apply((&function_355));
}
void function_357() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c105c115c116); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115); /* ___compile-args */
  apply((&function_356));
}
void function_358() {
  increment_count(env);
  val = new_function((&function_357), env);
  pop_function();
}
/* fn_57 */
void body_148() {
  increment_count(env);
  val = new_function((&function_358), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  return_location = (&body_149);
}
void body_150();
void function_359() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_360() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_359));
}
void function_361() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_360));
}
void function_362() {
  increment_count(env);
  val = new_function((&function_361), env);
  pop_function();
}
/* fn_56 */
void body_149() {
  increment_count(env);
  val = new_function((&function_362), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  return_location = (&body_150);
}
void body_151();
void function_363() {
  global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* ___compile-args */
  return_location = (&body_151);
}
/* ___compile-args */
void body_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  apply((&function_363));
}
void body_152();
pointer global_c95c95c108c95c53c50;
/* __l_52 */
void body_151() {
  val = NIL;
  global_c95c95c108c95c53c50 = val; /* __l_52 */
  return_location = (&body_152);
}
void body_153();
pointer global_c95c95c108c95c53c51;
/* __l_53 */
void body_152() {
  val = NIL;
  global_c95c95c108c95c53c51 = val; /* __l_53 */
  return_location = (&body_153);
}
void body_154();
pointer global_c95c95c108c95c53c52;
/* __l_54 */
void body_153() {
  val = -37;
  global_c95c95c108c95c53c52 = val; /* __l_54 */
  return_location = (&body_154);
}
void body_155();
pointer global_c95c95c108c95c53c53;
/* __l_55 */
void body_154() {
  val = -36;
  global_c95c95c108c95c53c53 = val; /* __l_55 */
  return_location = (&body_155);
}
void body_156();
pointer global_c95c95c108c95c53c54;
/* __l_56 */
void body_155() {
  val = -35;
  global_c95c95c108c95c53c54 = val; /* __l_56 */
  return_location = (&body_156);
}
void body_157();
pointer global_c95c95c108c95c53c55;
/* __l_57 */
void body_156() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(113);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(113);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(113);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(85);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c53c55 = val; /* __l_57 */
  return_location = (&body_157);
}
void body_158();
pointer global_c95c95c108c95c53c56;
/* __l_58 */
void body_157() {
  val = -41;
  global_c95c95c108c95c53c56 = val; /* __l_58 */
  return_location = (&body_158);
}
void body_159();
pointer global_c95c95c108c95c53c57;
/* __l_59 */
void body_158() {
  val = -40;
  global_c95c95c108c95c53c57 = val; /* __l_59 */
  return_location = (&body_159);
}
void body_160();
pointer global_c95c95c108c95c54c48;
/* __l_60 */
void body_159() {
  val = -39;
  global_c95c95c108c95c54c48 = val; /* __l_60 */
  return_location = (&body_160);
}
void body_161();
pointer global_c95c95c108c95c54c49;
/* __l_61 */
void body_160() {
  val = -39;
  global_c95c95c108c95c54c49 = val; /* __l_61 */
  return_location = (&body_161);
}
void body_162();
pointer global_c102c110c95c53c57;
void function_364() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_365() {
  increment_count(env);
  val = new_function((&function_364), env);
  pop_function();
}
/* fn_59 */
void body_161() {
  increment_count(env);
  val = new_function((&function_365), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  return_location = (&body_162);
}
void body_163();
pointer global_c95c99c97c100c100c114;
void function_366() {
  global_c95c99c97c100c100c114 = val; /* _caddr */
  return_location = (&body_163);
}
/* _caddr */
void body_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  apply((&function_366));
}
void body_164();
pointer global_c102c110c95c54c49 = NIL; /* fn_61 */
pointer global_c102c110c95c54c48 = NIL; /* fn_60 */
pointer global_c102c110c95c54c50;
void function_367() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_368() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_369() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_368));
}
void function_370() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_371() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116); /* ___rewrite-let */
  apply((&function_370));
}
void function_372() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_371));
}
void function_373() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_374() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  apply((&function_373));
}
void function_375() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_374));
}
void function_376() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c54c49); /* fn_61 */
    apply((&function_375));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115); /* ___compile-args */
    top_level_apply();
  }
}
void function_377() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    apply((&function_372));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c54c48); /* __l_60 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_376));
  }
}
void function_378() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100); /* ___rewrite-cond */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c53c57); /* __l_59 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_377));
  }
}
void function_379() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c54c48); /* fn_60 */
    apply((&function_369));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c53c56); /* __l_58 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_378));
  }
}
void function_380() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    val = new_number(0);
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    apply((&function_367));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c53c54); /* __l_56 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_379));
  }
}
void function_381() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101); /* ___compile-quote */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c53c53); /* __l_55 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_380));
  }
}
void function_382() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c51); /* __l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c50); /* __l_52 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c53c52); /* __l_54 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_381));
  }
}
void function_383() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100); /* ___compile-find */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_382));
  }
}
void function_384() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_383));
}
void function_385() {
  increment_count(env);
  val = new_function((&function_384), env);
  pop_function();
}
/* fn_62 */
void body_163() {
  increment_count(env);
  val = new_function((&function_385), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  return_location = (&body_164);
}
void body_165();
void function_386() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_387() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c55); /* __l_57 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_386));
}
void function_388() {
  increment_count(env);
  val = new_function((&function_387), env);
  pop_function();
}
/* fn_60 */
void body_164() {
  increment_count(env);
  val = new_function((&function_388), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  return_location = (&body_165);
}
void body_166();
void function_389() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_390() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c49); /* __l_61 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_389));
}
void function_391() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_390));
}
void function_392() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_391));
}
void function_393() {
  increment_count(env);
  val = new_function((&function_392), env);
  pop_function();
}
/* fn_61 */
void body_165() {
  increment_count(env);
  val = new_function((&function_393), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  return_location = (&body_166);
}
void body_167();
void function_394() {
  global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* ___compile-expr */
  return_location = (&body_167);
}
/* ___compile-expr */
void body_166() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  apply((&function_394));
}
void body_168();
pointer global_c102c110c95c54c51;
void function_395() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_396() {
  increment_count(env);
  val = new_function((&function_395), env);
  pop_function();
}
/* fn_63 */
void body_167() {
  increment_count(env);
  val = new_function((&function_396), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  return_location = (&body_168);
}
void body_169();
pointer global_c95c99c97c97c100c114;
void function_397() {
  global_c95c99c97c97c100c114 = val; /* _caadr */
  return_location = (&body_169);
}
/* _caadr */
void body_168() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  apply((&function_397));
}
void body_170();
pointer global_c102c110c95c54c52;
void function_398() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c100c114); /* _caadr */
    top_level_apply();
  }
}
void function_399() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_398));
}
void function_400() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_399));
}
void function_401() {
  increment_count(env);
  val = new_function((&function_400), env);
  pop_function();
}
/* fn_64 */
void body_169() {
  increment_count(env);
  val = new_function((&function_401), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  return_location = (&body_170);
}
void body_171();
pointer global_c95c95c95c103c101c116c45c110c97c109c101;
void function_402() {
  global_c95c95c95c103c101c116c45c110c97c109c101 = val; /* ___get-name */
  return_location = (&body_171);
}
/* ___get-name */
void body_170() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  apply((&function_402));
}
void body_172();
pointer global_c95c95c108c95c54c50;
/* __l_62 */
void body_171() {
  val = -39;
  global_c95c95c108c95c54c50 = val; /* __l_62 */
  return_location = (&body_172);
}
void body_173();
pointer global_c102c110c95c54c53;
void function_403() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c50); /* __l_62 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_404() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_403));
}
void function_405() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    apply((&function_404));
  }
}
void function_406() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_405));
}
void function_407() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_406));
}
void function_408() {
  increment_count(env);
  val = new_function((&function_407), env);
  pop_function();
}
/* fn_65 */
void body_172() {
  increment_count(env);
  val = new_function((&function_408), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  return_location = (&body_173);
}
void body_174();
pointer global_c95c95c95c103c101c116c45c98c111c100c121;
void function_409() {
  global_c95c95c95c103c101c116c45c98c111c100c121 = val; /* ___get-body */
  return_location = (&body_174);
}
/* ___get-body */
void body_173() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  apply((&function_409));
}
void body_175();
pointer global_c95c95c108c95c54c51;
/* __l_63 */
void body_174() {
  val = NIL;
  global_c95c95c108c95c54c51 = val; /* __l_63 */
  return_location = (&body_175);
}
void body_176();
pointer global_c102c110c95c54c54;
void function_410() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_411() {
  increment_count(env);
  val = new_function((&function_410), env);
  pop_function();
}
/* fn_66 */
void body_175() {
  increment_count(env);
  val = new_function((&function_411), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  return_location = (&body_176);
}
void body_177();
pointer global_c95c97c112c112c108c121;
void function_412() {
  global_c95c97c112c112c108c121 = val; /* _apply */
  return_location = (&body_177);
}
/* _apply */
void body_176() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  apply((&function_412));
}
void body_178();
pointer global_c102c110c95c54c55 = NIL; /* fn_67 */
pointer global_c102c110c95c54c56;
void function_413() {
  top_level_apply();
}
void function_414() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_413));
}
void function_415() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  apply((&function_414));
}
void function_416() {
  increment_count(env);
  val = new_function((&function_415), env);
  pop_function();
}
/* fn_68 */
void body_177() {
  increment_count(env);
  val = new_function((&function_416), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  return_location = (&body_178);
}
void body_179();
void function_417() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_418() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_417));
}
void function_419() {
  increment_count(env);
  val = new_function((&function_418), env);
  pop_function();
}
/* fn_67 */
void body_178() {
  increment_count(env);
  val = new_function((&function_419), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  return_location = (&body_179);
}
void body_180();
pointer global_c95c109c97c112;
void function_420() {
  global_c95c109c97c112 = val; /* _map */
  return_location = (&body_180);
}
/* _map */
void body_179() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  apply((&function_420));
}
void body_181();
pointer global_c102c110c95c55c50 = NIL; /* fn_72 */
pointer global_c102c110c95c55c51;
void function_421() {
  top_level_apply();
}
void function_422() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  apply((&function_421));
}
void function_423() {
  increment_count(env);
  val = new_function((&function_422), env);
  pop_function();
}
/* fn_73 */
void body_180() {
  increment_count(env);
  val = new_function((&function_423), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  return_location = (&body_181);
}
void body_182();
pointer global_c102c110c95c55c49 = NIL; /* fn_71 */
void function_424() {
  top_level_apply();
}
void function_425() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  apply((&function_424));
}
void function_426() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c103c101c116c45c110c97c109c101); /* ___get-name */
  apply((&function_425));
}
void function_427() {
  increment_count(env);
  val = new_function((&function_426), env);
  pop_function();
}
/* fn_72 */
void body_181() {
  increment_count(env);
  val = new_function((&function_427), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  return_location = (&body_182);
}
void body_183();
pointer global_c102c110c95c55c48 = NIL; /* fn_70 */
void function_428() {
  top_level_apply();
}
void function_429() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  apply((&function_428));
}
void function_430() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c103c101c116c45c98c111c100c121); /* ___get-body */
  apply((&function_429));
}
void function_431() {
  increment_count(env);
  val = new_function((&function_430), env);
  pop_function();
}
/* fn_71 */
void body_182() {
  increment_count(env);
  val = new_function((&function_431), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  return_location = (&body_183);
}
void body_184();
pointer global_c102c110c95c54c57 = NIL; /* fn_69 */
void function_432() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c51); /* __l_63 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_433() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  apply((&function_432));
}
void function_434() {
  increment_count(env);
  val = new_function((&function_433), env);
  pop_function();
}
/* fn_70 */
void body_183() {
  increment_count(env);
  val = new_function((&function_434), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  return_location = (&body_184);
}
void body_185();
void function_435() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_436() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ___print-warnings */
  apply((&function_435));
}
void function_437() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_436));
}
void function_438() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ___print-with-newline */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_437));
}
void function_439() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -34;
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ___print-with-newline */
  apply((&function_438));
}
void function_440() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_439));
}
void function_441() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_440));
}
void function_442() {
  increment_count(env);
  val = new_function((&function_441), env);
  pop_function();
}
/* fn_69 */
void body_184() {
  increment_count(env);
  val = new_function((&function_442), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  return_location = (&body_185);
}
void body_186();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
void function_443() {
  global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* ___compile-definition */
  return_location = (&body_186);
}
/* ___compile-definition */
void body_185() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  apply((&function_443));
}
void body_187();
pointer global_c102c110c95c55c52 = NIL; /* fn_74 */
pointer global_c102c110c95c55c53;
void function_444() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110); /* ___compile-definition */
  top_level_apply();
}
void function_445() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c55c52); /* fn_74 */
    apply((&function_444));
  }
}
void function_446() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_445));
}
void function_447() {
  increment_count(env);
  val = new_function((&function_446), env);
  pop_function();
}
/* fn_75 */
void body_186() {
  increment_count(env);
  val = new_function((&function_447), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  return_location = (&body_187);
}
void body_188();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ___compile-definitions */
void function_448() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115); /* ___compile-definitions */
  top_level_apply();
}
void function_449() {
  increment_count(env);
  val = new_function((&function_448), env);
  pop_function();
}
/* fn_74 */
void body_187() {
  increment_count(env);
  val = new_function((&function_449), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  return_location = (&body_188);
}
void body_189();
void function_450() {
  global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ___compile-definitions */
  return_location = (&body_189);
}
/* ___compile-definitions */
void body_188() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  apply((&function_450));
}
void body_190();
pointer global_c95c95c108c95c54c52;
/* __l_64 */
void body_189() {
  val = NIL;
  global_c95c95c108c95c54c52 = val; /* __l_64 */
  return_location = (&body_190);
}
void body_191();
pointer global_c102c110c95c55c56 = NIL; /* fn_78 */
pointer global_c102c110c95c55c57;
void function_451() {
  top_level_apply();
}
void function_452() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  apply((&function_451));
}
void function_453() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c103c101c116c45c110c97c109c101); /* ___get-name */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_452));
}
void function_454() {
  increment_count(env);
  val = new_function((&function_453), env);
  pop_function();
}
/* fn_79 */
void body_190() {
  increment_count(env);
  val = new_function((&function_454), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  return_location = (&body_191);
}
void body_192();
pointer global_c102c110c95c55c55 = NIL; /* fn_77 */
void function_455() {
  top_level_apply();
}
void function_456() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  apply((&function_455));
}
void function_457() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c105c115c116); /* _list */
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c52); /* __l_64 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_456));
}
void function_458() {
  increment_count(env);
  val = new_function((&function_457), env);
  pop_function();
}
/* fn_78 */
void body_191() {
  increment_count(env);
  val = new_function((&function_458), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  return_location = (&body_192);
}
void body_193();
pointer global_c102c110c95c55c54 = NIL; /* fn_76 */
void function_459() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115); /* ___compile-definitions */
  top_level_apply();
}
void function_460() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  apply((&function_459));
}
void function_461() {
  increment_count(env);
  val = new_function((&function_460), env);
  pop_function();
}
/* fn_77 */
void body_192() {
  increment_count(env);
  val = new_function((&function_461), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  return_location = (&body_193);
}
void body_194();
void function_462() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_463() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ___print-warnings */
  apply((&function_462));
}
void function_464() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_463));
}
void function_465() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ___print-with-newline */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_464));
}
void function_466() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ___print-with-newline */
  apply((&function_465));
}
void function_467() {
  increment_count(env);
  val = new_function((&function_466), env);
  pop_function();
}
/* fn_76 */
void body_193() {
  increment_count(env);
  val = new_function((&function_467), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  return_location = (&body_194);
}
void body_195();
pointer global_c95c95c95c99c111c109c112c105c108c101;
void function_468() {
  global_c95c95c95c99c111c109c112c105c108c101 = val; /* ___compile */
  return_location = (&body_195);
}
/* ___compile */
void body_194() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  apply((&function_468));
}
void body_196();
pointer global_c95c95c108c95c54c53;
/* __l_65 */
void body_195() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(44);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(80);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54c53 = val; /* __l_65 */
  return_location = (&body_196);
}
void body_197();
pointer global_c95c95c108c95c54c54;
/* __l_66 */
void body_196() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54c54 = val; /* __l_66 */
  return_location = (&body_197);
}
void body_198();
pointer global_c95c95c108c95c54c55;
/* __l_67 */
void body_197() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54c55 = val; /* __l_67 */
  return_location = (&body_198);
}
void body_199();
pointer global_c102c110c95c56c48 = NIL; /* fn_80 */
pointer global_c102c110c95c56c49;
void function_469() {
  top_level_apply();
}
void function_470() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_469));
}
void function_471() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = -38;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  apply((&function_470));
}
void function_472() {
  increment_count(env);
  val = new_function((&function_471), env);
  pop_function();
}
/* fn_81 */
void body_198() {
  increment_count(env);
  val = new_function((&function_472), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  return_location = (&body_199);
}
void body_200();
void function_473() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_474() {
  increment_count(env);
  val = new_function((&function_473), env);
  pop_function();
}
/* fn_80 */
void body_199() {
  increment_count(env);
  val = new_function((&function_474), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  return_location = (&body_200);
}
void body_201();
pointer global_c95c97c110c100;
void function_475() {
  global_c95c97c110c100 = val; /* _and */
  return_location = (&body_201);
}
/* _and */
void body_200() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  apply((&function_475));
}
void body_202();
pointer global_c102c110c95c56c50;
void function_476() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_477() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(13);
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(110);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_476));
  }
}
void function_478() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(9);
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(114);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_477));
  }
}
void function_479() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_478));
}
void function_480() {
  increment_count(env);
  val = new_function((&function_479), env);
  pop_function();
}
/* fn_82 */
void body_201() {
  increment_count(env);
  val = new_function((&function_480), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  return_location = (&body_202);
}
void body_203();
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
void function_481() {
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  return_location = (&body_203);
}
/* _escape-char */
void body_202() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  apply((&function_481));
}
void body_204();
pointer global_c102c110c95c56c51 = NIL; /* fn_83 */
pointer global_c102c110c95c56c52;
void function_482() {
  top_level_apply();
}
void function_483() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_482));
}
void function_484() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  apply((&function_483));
}
void function_485() {
  increment_count(env);
  val = new_function((&function_484), env);
  pop_function();
}
/* fn_84 */
void body_203() {
  increment_count(env);
  val = new_function((&function_485), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  return_location = (&body_204);
}
void body_205();
void function_486() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((length(args) == 2) &&
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (length(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  val = new_number(10);
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) * value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_487() {
  increment_count(env);
  val = new_function((&function_486), env);
  pop_function();
}
/* fn_83 */
void body_204() {
  increment_count(env);
  val = new_function((&function_487), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  return_location = (&body_205);
}
void body_206();
pointer global_c95c98c117c105c108c100c45c110c117c109;
void function_488() {
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  return_location = (&body_206);
}
/* _build-num */
void body_205() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  apply((&function_488));
}
void body_207();
pointer global_c102c110c95c56c53;
void function_489() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_490() {
  increment_count(env);
  val = new_function((&function_489), env);
  pop_function();
}
/* fn_85 */
void body_206() {
  increment_count(env);
  val = new_function((&function_490), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  return_location = (&body_207);
}
void body_208();
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
void function_491() {
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  return_location = (&body_208);
}
/* _quote-value */
void body_207() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  apply((&function_491));
}
void body_209();
pointer global_c102c110c95c56c54;
void function_492() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_493() {
  increment_count(env);
  val = new_function((&function_492), env);
  pop_function();
}
/* fn_86 */
void body_208() {
  increment_count(env);
  val = new_function((&function_493), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  return_location = (&body_209);
}
void body_210();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_494() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  return_location = (&body_210);
}
/* _quasiquote-value */
void body_209() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  apply((&function_494));
}
void body_211();
pointer global_c102c110c95c56c55;
void function_495() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -35;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_496() {
  increment_count(env);
  val = new_function((&function_495), env);
  pop_function();
}
/* fn_87 */
void body_210() {
  increment_count(env);
  val = new_function((&function_496), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  return_location = (&body_211);
}
void body_212();
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_497() {
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  return_location = (&body_212);
}
/* _unquote-value */
void body_211() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  apply((&function_497));
}
void body_213();
pointer global_c102c110c95c56c56 = NIL; /* fn_88 */
pointer global_c102c110c95c56c57;
void function_498() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  top_level_apply();
}
void function_499() {
  increment_count(env);
  val = new_function((&function_498), env);
  pop_function();
}
/* fn_89 */
void body_212() {
  increment_count(env);
  val = new_function((&function_499), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  return_location = (&body_213);
}
void body_214();
void function_500() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_501() {
  increment_count(env);
  val = new_function((&function_500), env);
  pop_function();
}
/* fn_88 */
void body_213() {
  increment_count(env);
  val = new_function((&function_501), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  return_location = (&body_214);
}
void body_215();
pointer global_c95c102c97c105c108;
void function_502() {
  global_c95c102c97c105c108 = val; /* _fail */
  return_location = (&body_215);
}
/* _fail */
void body_214() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  apply((&function_502));
}
void body_216();
pointer global_c102c110c95c57c48;
void function_503() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_504() {
  increment_count(env);
  val = new_function((&function_503), env);
  pop_function();
}
/* fn_90 */
void body_215() {
  increment_count(env);
  val = new_function((&function_504), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  return_location = (&body_216);
}
void body_217();
pointer global_c95c100c111c110c101;
void function_505() {
  global_c95c100c111c110c101 = val; /* _done */
  return_location = (&body_217);
}
/* _done */
void body_216() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  apply((&function_505));
}
void body_218();
pointer global_c102c110c95c57c49 = NIL; /* fn_91 */
pointer global_c102c110c95c57c50;
void function_506() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  top_level_apply();
}
void function_507() {
  increment_count(env);
  val = new_function((&function_506), env);
  pop_function();
}
/* fn_92 */
void body_217() {
  increment_count(env);
  val = new_function((&function_507), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  return_location = (&body_218);
}
void body_219();
pointer global_c95c112c111c112 = NIL; /* _pop */
void function_508() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = new_number(1);
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_number(car(args))) &&
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
  } else {
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
  }
}
void function_509() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      val = new_number(10);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61); /* __= */
      apply((&function_508));
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(cdr(car(cdr(env))))));
      args = cons(val, args);
      increment_count(val = car(cdr(car(cdr(env)))));
      top_level_apply();
    }
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c111c112); /* _pop */
    top_level_apply();
  }
}
void function_510() {
  increment_count(env);
  val = new_function((&function_509), env);
  pop_function();
}
/* fn_91 */
void body_218() {
  increment_count(env);
  val = new_function((&function_510), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  return_location = (&body_219);
}
void body_220();
void function_511() {
  global_c95c112c111c112 = val; /* _pop */
  return_location = (&body_220);
}
/* _pop */
void body_219() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  apply((&function_511));
}
void body_221();
pointer global_c102c110c95c57c52 = NIL; /* fn_94 */
pointer global_c102c110c95c57c53;
void function_512() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  top_level_apply();
}
void function_513() {
  increment_count(env);
  val = new_function((&function_512), env);
  pop_function();
}
/* fn_95 */
void body_220() {
  increment_count(env);
  val = new_function((&function_513), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  return_location = (&body_221);
}
void body_222();
pointer global_c102c110c95c57c51 = NIL; /* fn_93 */
void function_514() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  top_level_apply();
}
void function_515() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  apply((&function_514));
}
void function_516() {
  increment_count(env);
  val = new_function((&function_515), env);
  pop_function();
}
/* fn_94 */
void body_221() {
  increment_count(env);
  val = new_function((&function_516), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  return_location = (&body_222);
}
void body_223();
void function_517() {
  top_level_apply();
}
void function_518() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    apply((&function_517));
  }
}
void function_519() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_518));
}
void function_520() {
  increment_count(env);
  val = new_function((&function_519), env);
  pop_function();
}
/* fn_93 */
void body_222() {
  increment_count(env);
  val = new_function((&function_520), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  return_location = (&body_223);
}
void body_224();
pointer global_c95c99c104c101c99c107;
void function_521() {
  global_c95c99c104c101c99c107 = val; /* _check */
  return_location = (&body_224);
}
/* _check */
void body_223() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  apply((&function_521));
}
void body_225();
pointer global_c102c110c95c57c54 = NIL; /* fn_96 */
pointer global_c102c110c95c57c55;
void function_522() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_523() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  apply((&function_522));
}
void function_524() {
  increment_count(env);
  val = new_function((&function_523), env);
  pop_function();
}
/* fn_97 */
void body_224() {
  increment_count(env);
  val = new_function((&function_524), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  return_location = (&body_225);
}
void body_226();
void function_525() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  top_level_apply();
}
void function_526() {
  increment_count(env);
  val = new_function((&function_525), env);
  pop_function();
}
/* fn_96 */
void body_225() {
  increment_count(env);
  val = new_function((&function_526), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  return_location = (&body_226);
}
void body_227();
pointer global_c95c109c97c116c99c104;
void function_527() {
  global_c95c109c97c116c99c104 = val; /* _match */
  return_location = (&body_227);
}
/* _match */
void body_226() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  apply((&function_527));
}
void body_228();
pointer global_c102c110c95c57c56 = NIL; /* fn_98 */
pointer global_c102c110c95c57c57;
void function_528() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  top_level_apply();
}
void function_529() {
  increment_count(env);
  val = new_function((&function_528), env);
  pop_function();
}
/* fn_99 */
void body_227() {
  increment_count(env);
  val = new_function((&function_529), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  return_location = (&body_228);
}
void body_229();
void function_530() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_531() {
  increment_count(env);
  val = new_function((&function_530), env);
  pop_function();
}
/* fn_98 */
void body_228() {
  increment_count(env);
  val = new_function((&function_531), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  return_location = (&body_229);
}
void body_230();
pointer global_c95c100c101c102c97c117c108c116;
void function_532() {
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  return_location = (&body_230);
}
/* _default */
void body_229() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  apply((&function_532));
}
void body_231();
pointer global_c102c110c95c49c48c51 = NIL; /* fn_103 */
pointer global_c102c110c95c49c48c52;
void function_533() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  top_level_apply();
}
void function_534() {
  increment_count(env);
  val = new_function((&function_533), env);
  pop_function();
}
/* fn_104 */
void body_230() {
  increment_count(env);
  val = new_function((&function_534), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  return_location = (&body_231);
}
void body_232();
pointer global_c102c110c95c49c48c50 = NIL; /* fn_102 */
void function_535() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  top_level_apply();
}
void function_536() {
  increment_count(env);
  val = new_function((&function_535), env);
  pop_function();
}
/* fn_103 */
void body_231() {
  increment_count(env);
  val = new_function((&function_536), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  return_location = (&body_232);
}
void body_233();
pointer global_c102c110c95c49c48c49 = NIL; /* fn_101 */
pointer global_c102c110c95c49c48c48 = NIL; /* fn_100 */
void function_537() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_538() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  apply((&function_537));
}
void function_539() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  apply((&function_538));
}
void function_540() {
  increment_count(env);
  val = new_function((&function_539), env);
  pop_function();
}
/* fn_102 */
void body_232() {
  increment_count(env);
  val = new_function((&function_540), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  return_location = (&body_233);
}
void body_234();
void function_541() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_542() {
  increment_count(env);
  val = new_function((&function_541), env);
  pop_function();
}
/* fn_100 */
void body_233() {
  increment_count(env);
  val = new_function((&function_542), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  return_location = (&body_234);
}
void body_235();
void function_543() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_544() {
  increment_count(env);
  val = new_function((&function_543), env);
  pop_function();
}
/* fn_101 */
void body_234() {
  increment_count(env);
  val = new_function((&function_544), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  return_location = (&body_235);
}
void body_236();
pointer global_c95c99c97c115c101;
void function_545() {
  global_c95c99c97c115c101 = val; /* _case */
  return_location = (&body_236);
}
/* _case */
void body_235() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  apply((&function_545));
}
void body_237();
pointer global_c102c110c95c49c48c53 = NIL; /* fn_105 */
pointer global_c102c110c95c49c48c54;
void function_546() {
  top_level_apply();
}
void function_547() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_546));
}
void function_548() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  apply((&function_547));
}
void function_549() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c102c97c105c108); /* _fail */
  apply((&function_548));
}
void function_550() {
  increment_count(env);
  val = new_function((&function_549), env);
  pop_function();
}
/* fn_106 */
void body_236() {
  increment_count(env);
  val = new_function((&function_550), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  return_location = (&body_237);
}
void body_238();
void function_551() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_552() {
  increment_count(env);
  val = new_function((&function_551), env);
  pop_function();
}
/* fn_105 */
void body_237() {
  increment_count(env);
  val = new_function((&function_552), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  return_location = (&body_238);
}
void body_239();
pointer global_c95c99c104c111c105c99c101;
void function_553() {
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  return_location = (&body_239);
}
/* _choice */
void body_238() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  apply((&function_553));
}
void body_240();
pointer global_c102c110c95c49c48c56 = NIL; /* fn_108 */
pointer global_c102c110c95c49c48c57;
void function_554() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  top_level_apply();
}
void function_555() {
  increment_count(env);
  val = new_function((&function_554), env);
  pop_function();
}
/* fn_109 */
void body_239() {
  increment_count(env);
  val = new_function((&function_555), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  return_location = (&body_240);
}
void body_241();
pointer global_c102c110c95c49c48c55 = NIL; /* fn_107 */
void function_556() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_557() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  apply((&function_556));
}
void function_558() {
  increment_count(env);
  val = new_function((&function_557), env);
  pop_function();
}
/* fn_108 */
void body_240() {
  increment_count(env);
  val = new_function((&function_558), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  return_location = (&body_241);
}
void body_242();
void function_559() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_560() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_559));
}
void function_561() {
  increment_count(env);
  val = new_function((&function_560), env);
  pop_function();
}
/* fn_107 */
void body_241() {
  increment_count(env);
  val = new_function((&function_561), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  return_location = (&body_242);
}
void body_243();
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_562() {
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  return_location = (&body_243);
}
/* _post-process */
void body_242() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  apply((&function_562));
}
void body_244();
pointer global_c102c110c95c49c49c50 = NIL; /* fn_112 */
pointer global_c102c110c95c49c49c51;
void function_563() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  top_level_apply();
}
void function_564() {
  increment_count(env);
  val = new_function((&function_563), env);
  pop_function();
}
/* fn_113 */
void body_243() {
  increment_count(env);
  val = new_function((&function_564), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  return_location = (&body_244);
}
void body_245();
pointer global_c102c110c95c49c49c49 = NIL; /* fn_111 */
void function_565() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_566() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  apply((&function_565));
}
void function_567() {
  increment_count(env);
  val = new_function((&function_566), env);
  pop_function();
}
/* fn_112 */
void body_244() {
  increment_count(env);
  val = new_function((&function_567), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  return_location = (&body_245);
}
void body_246();
pointer global_c102c110c95c49c49c48 = NIL; /* fn_110 */
void function_568() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_569() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  apply((&function_568));
}
void function_570() {
  increment_count(env);
  val = new_function((&function_569), env);
  pop_function();
}
/* fn_111 */
void body_245() {
  increment_count(env);
  val = new_function((&function_570), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  return_location = (&body_246);
}
void body_247();
void function_571() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_572() {
  increment_count(env);
  val = new_function((&function_571), env);
  pop_function();
}
/* fn_110 */
void body_246() {
  increment_count(env);
  val = new_function((&function_572), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  return_location = (&body_247);
}
void body_248();
pointer global_c95c115c101c113;
void function_573() {
  global_c95c115c101c113 = val; /* _seq */
  return_location = (&body_248);
}
/* _seq */
void body_247() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  apply((&function_573));
}
void body_249();
pointer global_c102c110c95c49c49c52;
void function_574() {
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  top_level_apply();
}
void function_575() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c101c115c99c97c112c101c45c99c104c97c114); /* _escape-char */
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  apply((&function_574));
}
void function_576() {
  increment_count(env);
  val = new_function((&function_575), env);
  pop_function();
}
/* fn_114 */
void body_248() {
  increment_count(env);
  val = new_function((&function_576), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  return_location = (&body_249);
}
void body_250();
pointer global_c95c101c115c99c97c112c101;
void function_577() {
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  return_location = (&body_250);
}
/* _escape */
void body_249() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  apply((&function_577));
}
void body_251();
pointer global_c102c110c95c49c49c53;
void function_578() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  top_level_apply();
}
void function_579() {
  increment_count(env);
  val = new_function((&function_578), env);
  pop_function();
}
/* fn_115 */
void body_250() {
  increment_count(env);
  val = new_function((&function_579), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  return_location = (&body_251);
}
void body_252();
pointer global_c95c117c115c101;
void function_580() {
  global_c95c117c115c101 = val; /* _use */
  return_location = (&body_252);
}
/* _use */
void body_251() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  apply((&function_580));
}
void body_253();
pointer global_c102c110c95c49c49c55 = NIL; /* fn_117 */
pointer global_c102c110c95c49c49c56;
void function_581() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  top_level_apply();
}
void function_582() {
  increment_count(env);
  val = new_function((&function_581), env);
  pop_function();
}
/* fn_118 */
void body_252() {
  increment_count(env);
  val = new_function((&function_582), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  return_location = (&body_253);
}
void body_254();
pointer global_c102c110c95c49c49c54 = NIL; /* fn_116 */
void function_583() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_584() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  apply((&function_583));
}
void function_585() {
  increment_count(env);
  val = new_function((&function_584), env);
  pop_function();
}
/* fn_117 */
void body_253() {
  increment_count(env);
  val = new_function((&function_585), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  return_location = (&body_254);
}
void body_255();
void function_586() {
  top_level_apply();
}
void function_587() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_586));
}
void function_588() {
  increment_count(env);
  val = new_function((&function_587), env);
  pop_function();
}
/* fn_116 */
void body_254() {
  increment_count(env);
  val = new_function((&function_588), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  return_location = (&body_255);
}
void body_256();
pointer global_c95c112c101c101c107;
void function_589() {
  global_c95c112c101c101c107 = val; /* _peek */
  return_location = (&body_256);
}
/* _peek */
void body_255() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  apply((&function_589));
}
void body_257();
pointer global_c102c110c95c49c49c57 = NIL; /* fn_119 */
pointer global_c102c110c95c49c50c48;
void function_590() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_591() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  apply((&function_590));
}
void function_592() {
  increment_count(env);
  val = new_function((&function_591), env);
  pop_function();
}
/* fn_120 */
void body_256() {
  increment_count(env);
  val = new_function((&function_592), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  return_location = (&body_257);
}
void body_258();
void function_593() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    if (value(car(args)) < value(car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((length(args) == 2) &&
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (length(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_number(car(args))) &&
      (is_number(car(cdr(args))))) {
    if (value(car(args)) > value(car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c110c100); /* _and */
  top_level_apply();
}
void function_594() {
  increment_count(env);
  val = new_function((&function_593), env);
  pop_function();
}
/* fn_119 */
void body_257() {
  increment_count(env);
  val = new_function((&function_594), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  return_location = (&body_258);
}
void body_259();
pointer global_c95c105c110c116c101c114c118c97c108;
void function_595() {
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  return_location = (&body_259);
}
/* _interval */
void body_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  apply((&function_595));
}
void body_260();
pointer global_c99c100c114 = CDR; /* cdr */
pointer global_c102c110c95c49c50c49;
void function_596() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_597() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c99c100c114); /* cdr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c117c115c101); /* _use */
  apply((&function_596));
}
void function_598() {
  increment_count(env);
  val = new_function((&function_597), env);
  pop_function();
}
/* fn_121 */
void body_259() {
  increment_count(env);
  val = new_function((&function_598), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  return_location = (&body_260);
}
void body_261();
pointer global_c95c115c107c105c112;
void function_599() {
  global_c95c115c107c105c112 = val; /* _skip */
  return_location = (&body_261);
}
/* _skip */
void body_260() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  apply((&function_599));
}
void body_262();
pointer global_c99c97c114 = CAR; /* car */
pointer global_c102c110c95c49c50c50;
void function_600() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_601() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c99c97c114); /* car */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  apply((&function_600));
}
void function_602() {
  increment_count(env);
  val = new_function((&function_601), env);
  pop_function();
}
/* fn_122 */
void body_261() {
  increment_count(env);
  val = new_function((&function_602), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  return_location = (&body_262);
}
void body_263();
pointer global_c95c102c105c114c115c116;
void function_603() {
  global_c95c102c105c114c115c116 = val; /* _first */
  return_location = (&body_263);
}
/* _first */
void body_262() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  apply((&function_603));
}
void body_264();
pointer global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
pointer global_c102c110c95c49c50c51;
void function_604() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_605() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_604));
}
void function_606() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_605));
}
void function_607() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_606));
}
void function_608() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(57);
  args = cons(val, args);
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_607));
}
void function_609() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c110c117c109); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c117c115c101); /* _use */
  apply((&function_608));
}
void function_610() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_609));
}
void function_611() {
  increment_count(env);
  val = new_function((&function_610), env);
  pop_function();
}
/* fn_123 */
void body_263() {
  increment_count(env);
  val = new_function((&function_611), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  return_location = (&body_264);
}
void body_265();
void function_612() {
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  return_location = (&body_265);
}
/* _parse-num */
void body_264() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  apply((&function_612));
}
void body_266();
pointer global_c102c110c95c49c50c52;
void function_613() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_614() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c98c117c105c108c100c45c110c117c109); /* _build-num */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c110c117c109); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  apply((&function_613));
}
void function_615() {
  increment_count(env);
  val = new_function((&function_614), env);
  pop_function();
}
/* fn_124 */
void body_265() {
  increment_count(env);
  val = new_function((&function_615), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  return_location = (&body_266);
}
void body_267();
pointer global_c95c114c101c97c100c45c110c117c109;
void function_616() {
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  return_location = (&body_267);
}
/* _read-num */
void body_266() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  apply((&function_616));
}
void body_268();
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
pointer global_c102c110c95c49c50c53;
void function_617() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_618() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_617));
}
void function_619() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_618));
}
void function_620() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_619));
}
void function_621() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_620));
}
void function_622() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_621));
}
void function_623() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_622));
}
void function_624() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_623));
}
void function_625() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_624));
}
void function_626() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_625));
}
void function_627() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_626));
}
void function_628() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_627));
}
void function_629() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_628));
}
void function_630() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_629));
}
void function_631() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c117c115c101); /* _use */
  apply((&function_630));
}
void function_632() {
  increment_count(env);
  val = new_function((&function_631), env);
  pop_function();
}
/* fn_125 */
void body_267() {
  increment_count(env);
  val = new_function((&function_632), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  return_location = (&body_268);
}
void body_269();
void function_633() {
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  return_location = (&body_269);
}
/* _parse-symbol */
void body_268() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  apply((&function_633));
}
void body_270();
pointer global_c102c110c95c49c50c54;
void function_634() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_635() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  apply((&function_634));
}
void function_636() {
  increment_count(env);
  val = new_function((&function_635), env);
  pop_function();
}
/* fn_126 */
void body_269() {
  increment_count(env);
  val = new_function((&function_636), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  return_location = (&body_270);
}
void body_271();
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
void function_637() {
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  return_location = (&body_271);
}
/* _read-symbol */
void body_270() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  apply((&function_637));
}
void body_272();
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
pointer global_c102c110c95c49c50c55;
void function_638() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_639() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_638));
}
void function_640() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_639));
}
void function_641() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_640));
}
void function_642() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_641));
}
void function_643() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_642));
}
void function_644() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c101c115c99c97c112c101); /* _escape */
  apply((&function_643));
}
void function_645() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_644));
}
void function_646() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c117c115c101); /* _use */
  apply((&function_645));
}
void function_647() {
  increment_count(env);
  val = new_function((&function_646), env);
  pop_function();
}
/* fn_127 */
void body_271() {
  increment_count(env);
  val = new_function((&function_647), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  return_location = (&body_272);
}
void body_273();
void function_648() {
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  return_location = (&body_273);
}
/* _parse-string */
void body_272() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  apply((&function_648));
}
void body_274();
pointer global_c102c110c95c49c50c56;
void function_649() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c111c116c101c45c118c97c108c117c101); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_650() {
  increment_count(env);
  val = new_function((&function_649), env);
  pop_function();
}
/* fn_128 */
void body_273() {
  increment_count(env);
  val = new_function((&function_650), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  return_location = (&body_274);
}
void body_275();
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_651() {
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  return_location = (&body_275);
}
/* _quote-parser */
void body_274() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  apply((&function_651));
}
void body_276();
pointer global_c102c110c95c49c50c57;
void function_652() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_653() {
  increment_count(env);
  val = new_function((&function_652), env);
  pop_function();
}
/* fn_129 */
void body_275() {
  increment_count(env);
  val = new_function((&function_653), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  return_location = (&body_276);
}
void body_277();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_654() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  return_location = (&body_277);
}
/* _quasiquote-parser */
void body_276() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  apply((&function_654));
}
void body_278();
pointer global_c102c110c95c49c51c48;
void function_655() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_656() {
  increment_count(env);
  val = new_function((&function_655), env);
  pop_function();
}
/* fn_130 */
void body_277() {
  increment_count(env);
  val = new_function((&function_656), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  return_location = (&body_278);
}
void body_279();
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_657() {
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  return_location = (&body_279);
}
/* _unquote-parser */
void body_278() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  apply((&function_657));
}
void body_280();
pointer global_c102c110c95c49c51c49 = NIL; /* fn_131 */
pointer global_c102c110c95c49c51c50;
void function_658() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  top_level_apply();
}
void function_659() {
  increment_count(env);
  val = new_function((&function_658), env);
  pop_function();
}
/* fn_132 */
void body_279() {
  increment_count(env);
  val = new_function((&function_659), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  return_location = (&body_280);
}
void body_281();
pointer global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
void function_660() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_661() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_660));
}
void function_662() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_661));
}
void function_663() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(10);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_662));
}
void function_664() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_663));
}
void function_665() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(13);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_664));
}
void function_666() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_665));
}
void function_667() {
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  apply((&function_666));
}
void function_668() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c111c109c109c101c110c116); /* _comment */
  apply((&function_667));
}
void function_669() {
  increment_count(env);
  val = new_function((&function_668), env);
  pop_function();
}
/* fn_131 */
void body_280() {
  increment_count(env);
  val = new_function((&function_669), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  return_location = (&body_281);
}
void body_282();
void function_670() {
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  return_location = (&body_282);
}
/* _comment */
void body_281() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  apply((&function_670));
}
void body_283();
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
pointer global_c102c110c95c49c51c51;
void function_671() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_672() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_671));
}
void function_673() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_672));
}
void function_674() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110); /* _parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_673));
}
void function_675() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_674));
}
void function_676() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_675));
}
void function_677() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c99c111c109c109c101c110c116); /* _comment */
  apply((&function_676));
}
void function_678() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_677));
}
void function_679() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_678));
}
void function_680() {
  increment_count(env);
  val = new_function((&function_679), env);
  pop_function();
}
/* fn_133 */
void body_282() {
  increment_count(env);
  val = new_function((&function_680), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  return_location = (&body_283);
}
void body_284();
void function_681() {
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  return_location = (&body_284);
}
/* _parse-paren */
void body_283() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  apply((&function_681));
}
void body_285();
pointer global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
pointer global_c102c110c95c49c51c52;
void function_682() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_683() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_682));
}
void function_684() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_683));
}
void function_685() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_684));
}
void function_686() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_685));
}
void function_687() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_686));
}
void function_688() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c99c111c109c109c101c110c116); /* _comment */
  apply((&function_687));
}
void function_689() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_688));
}
void function_690() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_689));
}
void function_691() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_690));
}
void function_692() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_691));
}
void function_693() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c102c105c114c115c116); /* _first */
  apply((&function_692));
}
void function_694() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_693));
}
void function_695() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  apply((&function_694));
}
void function_696() {
  increment_count(env);
  val = new_function((&function_695), env);
  pop_function();
}
/* fn_134 */
void body_284() {
  increment_count(env);
  val = new_function((&function_696), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  return_location = (&body_285);
}
void body_286();
void function_697() {
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  return_location = (&body_286);
}
/* _parse-pair */
void body_285() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  apply((&function_697));
}
void body_287();
pointer global_c102c110c95c49c51c53;
void function_698() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_699() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_698));
}
void function_700() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_699));
}
void function_701() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_700));
}
void function_702() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_701));
}
void function_703() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_702));
}
void function_704() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c113c117c111c116c101c45c112c97c114c115c101c114); /* _quote-parser */
  apply((&function_703));
}
void function_705() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_704));
}
void function_706() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_705));
}
void function_707() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c113c117c111c116c101c45c112c97c114c115c101c114); /* _quote-parser */
  apply((&function_706));
}
void function_708() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_707));
}
void function_709() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_708));
}
void function_710() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114); /* _quasiquote-parser */
  apply((&function_709));
}
void function_711() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_710));
}
void function_712() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_711));
}
void function_713() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114); /* _unquote-parser */
  apply((&function_712));
}
void function_714() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_713));
}
void function_715() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_714));
}
void function_716() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_715));
}
void function_717() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_716));
}
void function_718() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c102c97c105c108); /* _fail */
  apply((&function_717));
}
void function_719() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_718));
}
void function_720() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_719));
}
void function_721() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(100);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c102c97c105c108); /* _fail */
  apply((&function_720));
}
void function_722() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_721));
}
void function_723() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_722));
}
void function_724() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c99c111c109c109c101c110c116); /* _comment */
  apply((&function_723));
}
void function_725() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_724));
}
void function_726() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_725));
}
void function_727() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c114c101c97c100c45c110c117c109); /* _read-num */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(57);
  args = cons(val, args);
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = global_c95c105c110c116c101c114c118c97c108); /* _interval */
  apply((&function_726));
}
void function_728() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c114c101c97c100c45c115c121c109c98c111c108); /* _read-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_727));
}
void function_729() {
  increment_count(env);
  val = new_function((&function_728), env);
  pop_function();
}
/* fn_135 */
void body_286() {
  increment_count(env);
  val = new_function((&function_729), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  return_location = (&body_287);
}
void body_288();
void function_730() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_288);
}
/* _parse-expr */
void body_287() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  apply((&function_730));
}
void body_289();
pointer global_c102c110c95c49c51c54 = NIL; /* fn_136 */
pointer global_c102c110c95c49c51c55;
void function_731() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  top_level_apply();
}
void function_732() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  apply((&function_731));
}
void function_733() {
  increment_count(env);
  val = new_function((&function_732), env);
  pop_function();
}
/* fn_137 */
void body_288() {
  increment_count(env);
  val = new_function((&function_733), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  return_location = (&body_289);
}
void body_290();
void function_734() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ___print-error */
  top_level_apply();
}
void function_735() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c53); /* __l_65 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_734));
}
void function_736() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c54c55); /* __l_67 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c54); /* __l_66 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_735));
}
void function_737() {
  increment_count(env);
  val = new_function((&function_736), env);
  pop_function();
}
/* fn_136 */
void body_289() {
  increment_count(env);
  val = new_function((&function_737), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  return_location = (&body_290);
}
void body_291();
pointer global_c95c95c95c114c101c97c100c45c101c120c112c114;
void function_738() {
  global_c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ___read-expr */
  return_location = (&body_291);
}
/* ___read-expr */
void body_290() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  apply((&function_738));
}
void body_292();
pointer global_c95c95c108c95c54c56;
/* __l_68 */
void body_291() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54c56 = val; /* __l_68 */
  return_location = (&body_292);
}
void body_293();
pointer global_c95c95c108c95c54c57;
/* __l_69 */
void body_292() {
  val = -34;
  global_c95c95c108c95c54c57 = val; /* __l_69 */
  return_location = (&body_293);
}
void body_294();
pointer global_c95c95c108c95c55c48;
/* __l_70 */
void body_293() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(77);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c55c48 = val; /* __l_70 */
  return_location = (&body_294);
}
void body_295();
pointer global_c102c110c95c49c51c56;
void function_739() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c105c100); /* _id */
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  top_level_apply();
}
void function_740() {
  increment_count(env);
  val = new_function((&function_739), env);
  pop_function();
}
/* fn_138 */
void body_294() {
  increment_count(env);
  val = new_function((&function_740), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  return_location = (&body_295);
}
void body_296();
pointer global_c95c114c101c118c101c114c115c101;
void function_741() {
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  return_location = (&body_296);
}
/* _reverse */
void body_295() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  apply((&function_741));
}
void body_297();
pointer global_c102c110c95c49c51c57 = NIL; /* fn_139 */
pointer global_c102c110c95c49c52c48;
void function_742() {
  top_level_apply();
}
void function_743() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_742));
}
void function_744() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c57); /* fn_139 */
  apply((&function_743));
}
void function_745() {
  increment_count(env);
  val = new_function((&function_744), env);
  pop_function();
}
/* fn_140 */
void body_296() {
  increment_count(env);
  val = new_function((&function_745), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  return_location = (&body_297);
}
void body_298();
void function_746() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_747() {
  increment_count(env);
  val = new_function((&function_746), env);
  pop_function();
}
/* fn_139 */
void body_297() {
  increment_count(env);
  val = new_function((&function_747), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  return_location = (&body_298);
}
void body_299();
pointer global_c95c111c114;
void function_748() {
  global_c95c111c114 = val; /* _or */
  return_location = (&body_299);
}
/* _or */
void body_298() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
  apply((&function_748));
}
void body_300();
pointer global_c102c110c95c49c52c49 = NIL; /* fn_141 */
pointer global_c102c110c95c49c52c50;
void function_749() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
  top_level_apply();
}
void function_750() {
  increment_count(env);
  val = new_function((&function_749), env);
  pop_function();
}
/* fn_142 */
void body_299() {
  increment_count(env);
  val = new_function((&function_750), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  return_location = (&body_300);
}
void body_301();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ___compile-source */
void function_751() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101); /* ___compile */
  top_level_apply();
}
void function_752() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_753() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c55c48); /* __l_70 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ___print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ___compile-source */
    apply((&function_752));
  }
}
void function_754() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_753));
}
void function_755() {
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  apply((&function_754));
}
void function_756() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_755));
}
void function_757() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_756));
}
void function_758() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_757));
}
void function_759() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c114c101c118c101c114c115c101); /* _reverse */
    apply((&function_751));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c100c114); /* _caadr */
    apply((&function_758));
  }
}
void function_760() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_759));
}
void function_761() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c54c56); /* __l_68 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ___print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c54c57); /* __l_69 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_760));
  }
}
void function_762() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_761));
}
void function_763() {
  increment_count(env);
  val = new_function((&function_762), env);
  pop_function();
}
/* fn_141 */
void body_300() {
  increment_count(env);
  val = new_function((&function_763), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  return_location = (&body_301);
}
void body_302();
void function_764() {
  global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ___compile-source */
  return_location = (&body_302);
}
/* ___compile-source */
void body_301() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  apply((&function_764));
}
void body_303();
pointer global_c95c95c108c95c49;
/* __l_1 */
void body_302() {
  val = NIL;
  global_c95c95c108c95c49 = val; /* __l_1 */
  return_location = (&body_303);
}
void body_304();
pointer global_c102c110c95c49c52c51;
void function_765() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_766() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49); /* __l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ___compile-source */
  apply((&function_765));
}
void function_767() {
  increment_count(env);
  val = new_function((&function_766), env);
  pop_function();
}
/* fn_143 */
void body_303() {
  increment_count(env);
  val = new_function((&function_767), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  return_location = (&body_304);
}
void function_768() {
  if (is_function(val)) {
    increment_count(env=environment(val));
    env = cons(cons(free_memory_size(),
                   cons(arguments,NIL)),
               env);
    return_location = address(val);
    decrement_count(val);
  } else {
    error(ERR_NO_OS);
    env = NIL;
    return_location = (&end_function);
  }
}
void body_304() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  top_level_apply();
}
#ifdef BARE_HARDWARE
void main (unsigned long magic, multiboot_data* boot_data) {
  int i = 0;
  if ((magic == BOOT_MAGIC) &&
      getFlag(boot_data->flags, 0)) {
    init_mem((void*)0x200000, ((boot_data->mem_upper*1024) - 0x100000));
    init_io();
    init_eval();
    arguments = get_cmd(boot_data->flags, (char*)(boot_data->cmd_line));
    call_stack = cons(new_function((&top_level), NIL), call_stack);
    call_stack = cons(new_function((&function_768), NIL), call_stack);
    return_location = (&body_0);
    while (return_location != (&end_function)) {
      (*return_location)();
    }
    end_function();
  } else {
    error(ERR_BAD_BOOT);
  }
}
#else
int main(int argc, char** argv) {
  pointer memory_limit = 64 * 1024 * 1024;
  void* memory = malloc(memory_limit);
  init_mem(memory, memory_limit);
  init_io();
  init_eval();
  arguments = NIL;
  int i;
  for (i = argc - 1; i >= 0; i--) {
    arguments = cons(make_string(argv[i]), arguments);
  }
  call_stack = cons(new_function((&top_level), NIL), call_stack);
  call_stack = cons(new_function((&function_768), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
