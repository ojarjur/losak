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
    val = new_number(116);
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
          val = -42;
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
            val = -42;
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
    val = -42;
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
      val = -42;
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
pointer global_c102c110c95c54;
void function_100() {
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
void function_101() {
  increment_count(env);
  val = new_function((&function_100), env);
  pop_function();
}
/* fn_6 */
void body_12() {
  increment_count(env);
  val = new_function((&function_101), env);
  global_c102c110c95c54 = val; /* fn_6 */
  return_location = (&body_13);
}
void body_14();
pointer global_c95c99c97c97c114;
void function_102() {
  global_c95c99c97c97c114 = val; /* _caar */
  return_location = (&body_14);
}
/* _caar */
void body_13() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  apply((&function_102));
}
void body_15();
pointer global_c102c110c95c55;
void function_103() {
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
  pop_function();
}
void function_104() {
  increment_count(env);
  val = new_function((&function_103), env);
  pop_function();
}
/* fn_7 */
void body_14() {
  increment_count(env);
  val = new_function((&function_104), env);
  global_c102c110c95c55 = val; /* fn_7 */
  return_location = (&body_15);
}
void body_16();
pointer global_c95c99c100c97c114;
void function_105() {
  global_c95c99c100c97c114 = val; /* _cdar */
  return_location = (&body_16);
}
/* _cdar */
void body_15() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  apply((&function_105));
}
void body_17();
pointer global_c102c110c95c56;
void function_106() {
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
void function_107() {
  increment_count(env);
  val = new_function((&function_106), env);
  pop_function();
}
/* fn_8 */
void body_16() {
  increment_count(env);
  val = new_function((&function_107), env);
  global_c102c110c95c56 = val; /* fn_8 */
  return_location = (&body_17);
}
void body_18();
pointer global_c95c99c97c100c114;
void function_108() {
  global_c95c99c97c100c114 = val; /* _cadr */
  return_location = (&body_18);
}
/* _cadr */
void body_17() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  apply((&function_108));
}
void body_19();
pointer global_c102c110c95c57;
void function_109() {
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
  pop_function();
}
void function_110() {
  increment_count(env);
  val = new_function((&function_109), env);
  pop_function();
}
/* fn_9 */
void body_18() {
  increment_count(env);
  val = new_function((&function_110), env);
  global_c102c110c95c57 = val; /* fn_9 */
  return_location = (&body_19);
}
void body_20();
pointer global_c95c99c100c100c114;
void function_111() {
  global_c95c99c100c100c114 = val; /* _cddr */
  return_location = (&body_20);
}
/* _cddr */
void body_19() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  apply((&function_111));
}
void body_21();
pointer global_c102c110c95c49c48;
void function_112() {
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
void function_113() {
  increment_count(env);
  val = new_function((&function_112), env);
  pop_function();
}
/* fn_10 */
void body_20() {
  increment_count(env);
  val = new_function((&function_113), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  return_location = (&body_21);
}
void body_22();
pointer global_c95c99c97c97c97c114;
void function_114() {
  global_c95c99c97c97c97c114 = val; /* _caaar */
  return_location = (&body_22);
}
/* _caaar */
void body_21() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  apply((&function_114));
}
void body_23();
pointer global_c102c110c95c49c49;
void function_115() {
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
void function_116() {
  increment_count(env);
  val = new_function((&function_115), env);
  pop_function();
}
/* fn_11 */
void body_22() {
  increment_count(env);
  val = new_function((&function_116), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  return_location = (&body_23);
}
void body_24();
pointer global_c95c99c97c97c100c114;
void function_117() {
  global_c95c99c97c97c100c114 = val; /* _caadr */
  return_location = (&body_24);
}
/* _caadr */
void body_23() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  apply((&function_117));
}
void body_25();
pointer global_c102c110c95c49c50;
void function_118() {
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
void function_119() {
  increment_count(env);
  val = new_function((&function_118), env);
  pop_function();
}
/* fn_12 */
void body_24() {
  increment_count(env);
  val = new_function((&function_119), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  return_location = (&body_25);
}
void body_26();
pointer global_c95c99c97c100c97c114;
void function_120() {
  global_c95c99c97c100c97c114 = val; /* _cadar */
  return_location = (&body_26);
}
/* _cadar */
void body_25() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  apply((&function_120));
}
void body_27();
pointer global_c102c110c95c49c51;
void function_121() {
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
void function_122() {
  increment_count(env);
  val = new_function((&function_121), env);
  pop_function();
}
/* fn_13 */
void body_26() {
  increment_count(env);
  val = new_function((&function_122), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  return_location = (&body_27);
}
void body_28();
pointer global_c95c99c97c100c100c114;
void function_123() {
  global_c95c99c97c100c100c114 = val; /* _caddr */
  return_location = (&body_28);
}
/* _caddr */
void body_27() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  apply((&function_123));
}
void body_29();
pointer global_c102c110c95c49c52;
void function_124() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_125() {
  increment_count(env);
  val = new_function((&function_124), env);
  pop_function();
}
/* fn_14 */
void body_28() {
  increment_count(env);
  val = new_function((&function_125), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  return_location = (&body_29);
}
void body_30();
pointer global_c95c105c100;
void function_126() {
  global_c95c105c100 = val; /* _id */
  return_location = (&body_30);
}
/* _id */
void body_29() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  apply((&function_126));
}
void body_31();
pointer global_c102c110c95c49c53;
void function_127() {
  increment_count(val = car(env));
  pop_function();
}
void function_128() {
  increment_count(env);
  val = new_function((&function_127), env);
  pop_function();
}
/* fn_15 */
void body_30() {
  increment_count(env);
  val = new_function((&function_128), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  return_location = (&body_31);
}
void body_32();
pointer global_c95c108c105c115c116;
void function_129() {
  global_c95c108c105c115c116 = val; /* _list */
  return_location = (&body_32);
}
/* _list */
void body_31() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  apply((&function_129));
}
void body_33();
pointer global_c102c110c95c49c54;
void function_130() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_131() {
  increment_count(env);
  val = new_function((&function_130), env);
  pop_function();
}
/* fn_16 */
void body_32() {
  increment_count(env);
  val = new_function((&function_131), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  return_location = (&body_33);
}
void body_34();
pointer global_c95c97c112c112c108c121;
void function_132() {
  global_c95c97c112c112c108c121 = val; /* _apply */
  return_location = (&body_34);
}
/* _apply */
void body_33() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  apply((&function_132));
}
void body_35();
pointer global_c102c110c95c50c48 = NIL; /* fn_20 */
pointer global_c102c110c95c49c56 = NIL; /* fn_18 */
pointer global_c102c110c95c50c49;
void function_133() {
  top_level_apply();
}
void function_134() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  apply((&function_133));
}
void function_135() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  apply((&function_134));
}
void function_136() {
  increment_count(env);
  val = new_function((&function_135), env);
  pop_function();
}
/* fn_21 */
void body_34() {
  increment_count(env);
  val = new_function((&function_136), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  return_location = (&body_35);
}
void body_36();
pointer global_c102c110c95c49c55 = NIL; /* fn_17 */
void function_137() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_138() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  apply((&function_137));
}
void function_139() {
  increment_count(env);
  val = new_function((&function_138), env);
  pop_function();
}
/* fn_18 */
void body_35() {
  increment_count(env);
  val = new_function((&function_139), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  return_location = (&body_36);
}
void body_37();
void function_140() {
  top_level_apply();
}
void function_141() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_140));
}
void function_142() {
  increment_count(env);
  val = new_function((&function_141), env);
  pop_function();
}
/* fn_17 */
void body_36() {
  increment_count(env);
  val = new_function((&function_142), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  return_location = (&body_37);
}
void body_38();
pointer global_c102c110c95c49c57 = NIL; /* fn_19 */
void function_143() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_144() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  apply((&function_143));
}
void function_145() {
  increment_count(env);
  val = new_function((&function_144), env);
  pop_function();
}
/* fn_20 */
void body_37() {
  increment_count(env);
  val = new_function((&function_145), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  return_location = (&body_38);
}
void body_39();
void function_146() {
  top_level_apply();
}
void function_147() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_146));
}
void function_148() {
  increment_count(env);
  val = new_function((&function_147), env);
  pop_function();
}
/* fn_19 */
void body_38() {
  increment_count(env);
  val = new_function((&function_148), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  return_location = (&body_39);
}
void body_40();
pointer global_c95c95c95c114c101c99c117c114c115c101;
void function_149() {
  global_c95c95c95c114c101c99c117c114c115c101 = val; /* ___recurse */
  return_location = (&body_40);
}
/* ___recurse */
void body_39() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  apply((&function_149));
}
void body_41();
pointer global_c102c110c95c50c50 = NIL; /* fn_22 */
pointer global_c102c110c95c50c51;
void function_150() {
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
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  top_level_apply();
}
void function_151() {
  increment_count(env);
  val = new_function((&function_150), env);
  pop_function();
}
/* fn_23 */
void body_40() {
  increment_count(env);
  val = new_function((&function_151), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  return_location = (&body_41);
}
void body_42();
pointer global_c95c95c95c119c97c108c107 = NIL; /* ___walk */
void function_152() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_153() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_152));
}
void function_154() {
  apply((&function_153));
}
void function_155() {
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
  increment_count(val = global_c95c95c95c119c97c108c107); /* ___walk */
  apply((&function_154));
}
void function_156() {
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
    apply((&function_155));
  }
}
void function_157() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_156));
}
void function_158() {
  increment_count(env);
  val = new_function((&function_157), env);
  pop_function();
}
/* fn_22 */
void body_41() {
  increment_count(env);
  val = new_function((&function_158), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  return_location = (&body_42);
}
void body_43();
void function_159() {
  global_c95c95c95c119c97c108c107 = val; /* ___walk */
  return_location = (&body_43);
}
/* ___walk */
void body_42() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  apply((&function_159));
}
void body_44();
pointer global_c95c95c95c114c114c101c118c101c114c115c101 = NIL; /* ___rreverse */
pointer global_c102c110c95c50c52;
void function_160() {
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
    increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101); /* ___rreverse */
    top_level_apply();
  }
}
void function_161() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_160));
}
void function_162() {
  increment_count(env);
  val = new_function((&function_161), env);
  pop_function();
}
/* fn_24 */
void body_43() {
  increment_count(env);
  val = new_function((&function_162), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  return_location = (&body_44);
}
void body_45();
void function_163() {
  global_c95c95c95c114c114c101c118c101c114c115c101 = val; /* ___rreverse */
  return_location = (&body_45);
}
/* ___rreverse */
void body_44() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  apply((&function_163));
}
void body_46();
pointer global_c95c95c108c95c50;
/* __l_2 */
void body_45() {
  val = NIL;
  global_c95c95c108c95c50 = val; /* __l_2 */
  return_location = (&body_46);
}
void body_47();
pointer global_c102c110c95c50c53;
void function_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c105c100); /* _id */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50); /* __l_2 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101); /* ___rreverse */
  top_level_apply();
}
void function_165() {
  increment_count(env);
  val = new_function((&function_164), env);
  pop_function();
}
/* fn_25 */
void body_46() {
  increment_count(env);
  val = new_function((&function_165), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  return_location = (&body_47);
}
void body_48();
pointer global_c95c114c101c118c101c114c115c101;
void function_166() {
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  return_location = (&body_48);
}
/* _reverse */
void body_47() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  apply((&function_166));
}
void body_49();
pointer global_c102c110c95c50c54 = NIL; /* fn_26 */
pointer global_c102c110c95c50c55;
void function_167() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  top_level_apply();
}
void function_168() {
  increment_count(env);
  val = new_function((&function_167), env);
  pop_function();
}
/* fn_27 */
void body_48() {
  increment_count(env);
  val = new_function((&function_168), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  return_location = (&body_49);
}
void body_50();
pointer global_c95c102c111c108c100c108 = NIL; /* _foldl */
void function_169() {
  top_level_apply();
}
void function_170() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_169));
}
void function_171() {
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
    apply((&function_170));
  }
}
void function_172() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_171));
}
void function_173() {
  increment_count(env);
  val = new_function((&function_172), env);
  pop_function();
}
/* fn_26 */
void body_49() {
  increment_count(env);
  val = new_function((&function_173), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  return_location = (&body_50);
}
void body_51();
void function_174() {
  global_c95c102c111c108c100c108 = val; /* _foldl */
  return_location = (&body_51);
}
/* _foldl */
void body_50() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  apply((&function_174));
}
void body_52();
pointer global_c95c95c108c95c51;
/* __l_3 */
void body_51() {
  val = NIL;
  global_c95c95c108c95c51 = val; /* __l_3 */
  return_location = (&body_52);
}
void body_53();
pointer global_c102c110c95c50c56 = NIL; /* fn_28 */
pointer global_c102c110c95c50c57;
void function_175() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  top_level_apply();
}
void function_176() {
  increment_count(env);
  val = new_function((&function_175), env);
  pop_function();
}
/* fn_29 */
void body_52() {
  increment_count(env);
  val = new_function((&function_176), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  return_location = (&body_53);
}
void body_54();
void function_177() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51); /* __l_3 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101); /* ___rreverse */
  top_level_apply();
}
void function_178() {
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
  apply((&function_177));
}
void function_179() {
  increment_count(env);
  val = new_function((&function_178), env);
  pop_function();
}
/* fn_28 */
void body_53() {
  increment_count(env);
  val = new_function((&function_179), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  return_location = (&body_54);
}
void body_55();
pointer global_c95c102c111c108c100c114;
void function_180() {
  global_c95c102c111c108c100c114 = val; /* _foldr */
  return_location = (&body_55);
}
/* _foldr */
void body_54() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  apply((&function_180));
}
void body_56();
pointer global_c95c95c108c95c52;
/* __l_4 */
void body_55() {
  val = NIL;
  global_c95c95c108c95c52 = val; /* __l_4 */
  return_location = (&body_56);
}
void body_57();
pointer global_c95c95c108c95c53;
/* __l_5 */
void body_56() {
  val = NIL;
  global_c95c95c108c95c53 = val; /* __l_5 */
  return_location = (&body_57);
}
void body_58();
pointer global_c102c110c95c51c48 = NIL; /* fn_30 */
pointer global_c102c110c95c51c49;
void function_181() {
  top_level_apply();
}
void function_182() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_181));
}
void function_183() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c53); /* __l_5 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  apply((&function_182));
}
void function_184() {
  increment_count(env);
  val = new_function((&function_183), env);
  pop_function();
}
/* fn_31 */
void body_57() {
  increment_count(env);
  val = new_function((&function_184), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  return_location = (&body_58);
}
void body_59();
pointer global_c99c111c110c115 = CONS; /* cons */
void function_185() {
  top_level_apply();
}
void function_186() {
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
    apply((&function_185));
  }
}
void function_187() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c52); /* __l_4 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_186));
}
void function_188() {
  increment_count(env);
  val = new_function((&function_187), env);
  pop_function();
}
/* fn_30 */
void body_58() {
  increment_count(env);
  val = new_function((&function_188), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  return_location = (&body_59);
}
void body_60();
pointer global_c95c97c112c112c101c110c100;
void function_189() {
  global_c95c97c112c112c101c110c100 = val; /* _append */
  return_location = (&body_60);
}
/* _append */
void body_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  apply((&function_189));
}
void body_61();
pointer global_c95c95c108c95c54;
/* __l_6 */
void body_60() {
  val = NIL;
  global_c95c95c108c95c54 = val; /* __l_6 */
  return_location = (&body_61);
}
void body_62();
pointer global_c95c95c108c95c55;
/* __l_7 */
void body_61() {
  val = NIL;
  global_c95c95c108c95c55 = val; /* __l_7 */
  return_location = (&body_62);
}
void body_63();
pointer global_c95c95c95c101c113c117c97c108 = NIL; /* ___equal */
pointer global_c102c110c95c51c50;
void function_190() {
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
    increment_count(val = global_c95c95c95c101c113c117c97c108); /* ___equal */
    top_level_apply();
  } else {
    increment_count(val = global_c95c95c108c95c55); /* __l_7 */
    pop_function();
  }
}
void function_191() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c54); /* __l_6 */
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
    increment_count(val = global_c95c95c95c101c113c117c97c108); /* ___equal */
    apply((&function_190));
  }
}
void function_192() {
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
    apply((&function_191));
  }
}
void function_193() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_192));
}
void function_194() {
  increment_count(env);
  val = new_function((&function_193), env);
  pop_function();
}
/* fn_32 */
void body_62() {
  increment_count(env);
  val = new_function((&function_194), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  return_location = (&body_63);
}
void body_64();
void function_195() {
  global_c95c95c95c101c113c117c97c108 = val; /* ___equal */
  return_location = (&body_64);
}
/* ___equal */
void body_63() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  apply((&function_195));
}
void body_65();
pointer global_c95c95c108c95c56;
/* __l_8 */
void body_64() {
  val = NIL;
  global_c95c95c108c95c56 = val; /* __l_8 */
  return_location = (&body_65);
}
void body_66();
pointer global_c102c110c95c51c51 = NIL; /* fn_33 */
pointer global_c102c110c95c51c52;
void function_196() {
  top_level_apply();
}
void function_197() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_196));
}
void function_198() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c56); /* __l_8 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  apply((&function_197));
}
void function_199() {
  increment_count(env);
  val = new_function((&function_198), env);
  pop_function();
}
/* fn_34 */
void body_65() {
  increment_count(env);
  val = new_function((&function_199), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  return_location = (&body_66);
}
void body_67();
void function_200() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_201() {
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
  apply((&function_200));
}
void function_202() {
  increment_count(env);
  val = new_function((&function_201), env);
  pop_function();
}
/* fn_33 */
void body_66() {
  increment_count(env);
  val = new_function((&function_202), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  return_location = (&body_67);
}
void body_68();
pointer global_c95c109c97c112;
void function_203() {
  global_c95c109c97c112 = val; /* _map */
  return_location = (&body_68);
}
/* _map */
void body_67() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  apply((&function_203));
}
void body_69();
pointer global_c95c95c108c95c57;
/* __l_9 */
void body_68() {
  val = NIL;
  global_c95c95c108c95c57 = val; /* __l_9 */
  return_location = (&body_69);
}
void body_70();
pointer global_c102c110c95c51c53 = NIL; /* fn_35 */
pointer global_c102c110c95c51c54;
void function_204() {
  top_level_apply();
}
void function_205() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_204));
}
void function_206() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c57); /* __l_9 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  apply((&function_205));
}
void function_207() {
  increment_count(env);
  val = new_function((&function_206), env);
  pop_function();
}
/* fn_36 */
void body_69() {
  increment_count(env);
  val = new_function((&function_207), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  return_location = (&body_70);
}
void body_71();
void function_208() {
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
void function_209() {
  increment_count(env);
  val = new_function((&function_208), env);
  pop_function();
}
/* fn_35 */
void body_70() {
  increment_count(env);
  val = new_function((&function_209), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  return_location = (&body_71);
}
void body_72();
pointer global_c95c111c114;
void function_210() {
  global_c95c111c114 = val; /* _or */
  return_location = (&body_72);
}
/* _or */
void body_71() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  apply((&function_210));
}
void body_73();
pointer global_c95c95c108c95c49c48;
/* __l_10 */
void body_72() {
  val = NIL;
  global_c95c95c108c95c49c48 = val; /* __l_10 */
  return_location = (&body_73);
}
void body_74();
pointer global_c95c95c108c95c49c49;
/* __l_11 */
void body_73() {
  val = -42;
  global_c95c95c108c95c49c49 = val; /* __l_11 */
  return_location = (&body_74);
}
void body_75();
pointer global_c102c110c95c51c55 = NIL; /* fn_37 */
pointer global_c102c110c95c51c56;
void function_211() {
  top_level_apply();
}
void function_212() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_211));
}
void function_213() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c49); /* __l_11 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  apply((&function_212));
}
void function_214() {
  increment_count(env);
  val = new_function((&function_213), env);
  pop_function();
}
/* fn_38 */
void body_74() {
  increment_count(env);
  val = new_function((&function_214), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  return_location = (&body_75);
}
void body_76();
void function_215() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_c95c95c108c95c49c48); /* __l_10 */
    pop_function();
  }
}
void function_216() {
  increment_count(env);
  val = new_function((&function_215), env);
  pop_function();
}
/* fn_37 */
void body_75() {
  increment_count(env);
  val = new_function((&function_216), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  return_location = (&body_76);
}
void body_77();
pointer global_c95c97c110c100;
void function_217() {
  global_c95c97c110c100 = val; /* _and */
  return_location = (&body_77);
}
/* _and */
void body_76() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  apply((&function_217));
}
void body_78();
pointer global_c95c95c108c95c49c50;
/* __l_12 */
void body_77() {
  val = NIL;
  global_c95c95c108c95c49c50 = val; /* __l_12 */
  return_location = (&body_78);
}
void body_79();
pointer global_c95c95c108c95c49c51;
/* __l_13 */
void body_78() {
  val = -42;
  global_c95c95c108c95c49c51 = val; /* __l_13 */
  return_location = (&body_79);
}
void body_80();
pointer global_c102c110c95c51c57;
void function_218() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c49c50); /* __l_12 */
    pop_function();
  } else {
    increment_count(val = global_c95c95c108c95c49c51); /* __l_13 */
    pop_function();
  }
}
void function_219() {
  increment_count(env);
  val = new_function((&function_218), env);
  pop_function();
}
/* fn_39 */
void body_79() {
  increment_count(env);
  val = new_function((&function_219), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  return_location = (&body_80);
}
void body_81();
pointer global_c95c110c111c116;
void function_220() {
  global_c95c110c111c116 = val; /* _not */
  return_location = (&body_81);
}
/* _not */
void body_80() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  apply((&function_220));
}
void body_82();
pointer global_c95c95c108c95c49c52;
/* __l_14 */
void body_81() {
  val = NIL;
  global_c95c95c108c95c49c52 = val; /* __l_14 */
  return_location = (&body_82);
}
void body_83();
pointer global_c95c109c101c109c98c101c114 = NIL; /* _member */
pointer global_c102c110c95c52c48;
void function_221() {
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
void function_222() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c49c52); /* __l_14 */
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
    increment_count(val = global_c95c95c95c101c113c117c97c108); /* ___equal */
    apply((&function_221));
  }
}
void function_223() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_222));
}
void function_224() {
  increment_count(env);
  val = new_function((&function_223), env);
  pop_function();
}
/* fn_40 */
void body_82() {
  increment_count(env);
  val = new_function((&function_224), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  return_location = (&body_83);
}
void body_84();
void function_225() {
  global_c95c109c101c109c98c101c114 = val; /* _member */
  return_location = (&body_84);
}
/* _member */
void body_83() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  apply((&function_225));
}
void body_85();
pointer global_c102c110c95c52c49;
void function_226() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_227() {
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
    apply((&function_226));
  }
}
void function_228() {
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
    apply((&function_227));
  }
}
void function_229() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_228));
}
void function_230() {
  increment_count(env);
  val = new_function((&function_229), env);
  pop_function();
}
/* fn_41 */
void body_84() {
  increment_count(env);
  val = new_function((&function_230), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  return_location = (&body_85);
}
void body_86();
pointer global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114;
void function_231() {
  global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* ___escape-char */
  return_location = (&body_86);
}
/* ___escape-char */
void body_85() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  apply((&function_231));
}
void body_87();
pointer global_c102c110c95c52c50 = NIL; /* fn_42 */
pointer global_c102c110c95c52c51;
void function_232() {
  top_level_apply();
}
void function_233() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_232));
}
void function_234() {
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
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  apply((&function_233));
}
void function_235() {
  increment_count(env);
  val = new_function((&function_234), env);
  pop_function();
}
/* fn_43 */
void body_86() {
  increment_count(env);
  val = new_function((&function_235), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  return_location = (&body_87);
}
void body_88();
void function_236() {
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
void function_237() {
  increment_count(env);
  val = new_function((&function_236), env);
  pop_function();
}
/* fn_42 */
void body_87() {
  increment_count(env);
  val = new_function((&function_237), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  return_location = (&body_88);
}
void body_89();
pointer global_c95c95c95c98c117c105c108c100c45c110c117c109;
void function_238() {
  global_c95c95c95c98c117c105c108c100c45c110c117c109 = val; /* ___build-num */
  return_location = (&body_89);
}
/* ___build-num */
void body_88() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  apply((&function_238));
}
void body_90();
pointer global_c95c95c108c95c49c53;
/* __l_15 */
void body_89() {
  val = -40;
  global_c95c95c108c95c49c53 = val; /* __l_15 */
  return_location = (&body_90);
}
void body_91();
pointer global_c102c110c95c52c52;
void function_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c53); /* __l_15 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_240() {
  increment_count(env);
  val = new_function((&function_239), env);
  pop_function();
}
/* fn_44 */
void body_90() {
  increment_count(env);
  val = new_function((&function_240), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  return_location = (&body_91);
}
void body_92();
pointer global_c95c95c95c113c117c111c116c101c45c118c97c108c117c101;
void function_241() {
  global_c95c95c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* ___quote-value */
  return_location = (&body_92);
}
/* ___quote-value */
void body_91() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  apply((&function_241));
}
void body_93();
pointer global_c95c95c108c95c49c54;
/* __l_16 */
void body_92() {
  val = -39;
  global_c95c95c108c95c49c54 = val; /* __l_16 */
  return_location = (&body_93);
}
void body_94();
pointer global_c102c110c95c52c53;
void function_242() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c54); /* __l_16 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_243() {
  increment_count(env);
  val = new_function((&function_242), env);
  pop_function();
}
/* fn_45 */
void body_93() {
  increment_count(env);
  val = new_function((&function_243), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  return_location = (&body_94);
}
void body_95();
pointer global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_244() {
  global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* ___quasiquote-value */
  return_location = (&body_95);
}
/* ___quasiquote-value */
void body_94() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  apply((&function_244));
}
void body_96();
pointer global_c95c95c108c95c49c55;
/* __l_17 */
void body_95() {
  val = -38;
  global_c95c95c108c95c49c55 = val; /* __l_17 */
  return_location = (&body_96);
}
void body_97();
pointer global_c102c110c95c52c54;
void function_245() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c55); /* __l_17 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_246() {
  increment_count(env);
  val = new_function((&function_245), env);
  pop_function();
}
/* fn_46 */
void body_96() {
  increment_count(env);
  val = new_function((&function_246), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  return_location = (&body_97);
}
void body_98();
pointer global_c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_247() {
  global_c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* ___unquote-value */
  return_location = (&body_98);
}
/* ___unquote-value */
void body_97() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  apply((&function_247));
}
void body_99();
pointer global_c102c110c95c52c55 = NIL; /* fn_47 */
pointer global_c102c110c95c52c56;
void function_248() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  top_level_apply();
}
void function_249() {
  increment_count(env);
  val = new_function((&function_248), env);
  pop_function();
}
/* fn_48 */
void body_98() {
  increment_count(env);
  val = new_function((&function_249), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  return_location = (&body_99);
}
void body_100();
void function_250() {
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
void function_251() {
  increment_count(env);
  val = new_function((&function_250), env);
  pop_function();
}
/* fn_47 */
void body_99() {
  increment_count(env);
  val = new_function((&function_251), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  return_location = (&body_100);
}
void body_101();
pointer global_c95c95c95c102c97c105c108;
void function_252() {
  global_c95c95c95c102c97c105c108 = val; /* ___fail */
  return_location = (&body_101);
}
/* ___fail */
void body_100() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  apply((&function_252));
}
void body_102();
pointer global_c102c110c95c52c57;
void function_253() {
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
void function_254() {
  increment_count(env);
  val = new_function((&function_253), env);
  pop_function();
}
/* fn_49 */
void body_101() {
  increment_count(env);
  val = new_function((&function_254), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  return_location = (&body_102);
}
void body_103();
pointer global_c95c95c95c100c111c110c101;
void function_255() {
  global_c95c95c95c100c111c110c101 = val; /* ___done */
  return_location = (&body_103);
}
/* ___done */
void body_102() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  apply((&function_255));
}
void body_104();
pointer global_c95c95c108c95c49c56;
/* __l_18 */
void body_103() {
  val = NIL;
  global_c95c95c108c95c49c56 = val; /* __l_18 */
  return_location = (&body_104);
}
void body_105();
pointer global_c102c110c95c53c48 = NIL; /* fn_50 */
pointer global_c102c110c95c53c49;
void function_256() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  top_level_apply();
}
void function_257() {
  increment_count(env);
  val = new_function((&function_256), env);
  pop_function();
}
/* fn_51 */
void body_104() {
  increment_count(env);
  val = new_function((&function_257), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  return_location = (&body_105);
}
void body_106();
pointer global_c95c95c95c112c111c112 = NIL; /* ___pop */
void function_258() {
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  }
}
void function_259() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_258));
  }
}
void function_260() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c111c112); /* ___pop */
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
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c110c111c116); /* _not */
    apply((&function_259));
  }
}
void function_261() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c56); /* __l_18 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_260));
}
void function_262() {
  increment_count(env);
  val = new_function((&function_261), env);
  pop_function();
}
/* fn_50 */
void body_105() {
  increment_count(env);
  val = new_function((&function_262), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  return_location = (&body_106);
}
void body_107();
void function_263() {
  global_c95c95c95c112c111c112 = val; /* ___pop */
  return_location = (&body_107);
}
/* ___pop */
void body_106() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  apply((&function_263));
}
void body_108();
pointer global_c102c110c95c53c51 = NIL; /* fn_53 */
pointer global_c102c110c95c53c52;
void function_264() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  top_level_apply();
}
void function_265() {
  increment_count(env);
  val = new_function((&function_264), env);
  pop_function();
}
/* fn_54 */
void body_107() {
  increment_count(env);
  val = new_function((&function_265), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  return_location = (&body_108);
}
void body_109();
pointer global_c102c110c95c53c50 = NIL; /* fn_52 */
void function_266() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c112); /* ___pop */
  top_level_apply();
}
void function_267() {
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
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  apply((&function_266));
}
void function_268() {
  increment_count(env);
  val = new_function((&function_267), env);
  pop_function();
}
/* fn_53 */
void body_108() {
  increment_count(env);
  val = new_function((&function_268), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  return_location = (&body_109);
}
void body_110();
void function_269() {
  top_level_apply();
}
void function_270() {
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
    apply((&function_269));
  }
}
void function_271() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_270));
}
void function_272() {
  increment_count(env);
  val = new_function((&function_271), env);
  pop_function();
}
/* fn_52 */
void body_109() {
  increment_count(env);
  val = new_function((&function_272), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  return_location = (&body_110);
}
void body_111();
pointer global_c95c95c95c99c104c101c99c107;
void function_273() {
  global_c95c95c95c99c104c101c99c107 = val; /* ___check */
  return_location = (&body_111);
}
/* ___check */
void body_110() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  apply((&function_273));
}
void body_112();
pointer global_c102c110c95c53c53 = NIL; /* fn_55 */
pointer global_c102c110c95c53c54;
void function_274() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c101c99c107); /* ___check */
  top_level_apply();
}
void function_275() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  apply((&function_274));
}
void function_276() {
  increment_count(env);
  val = new_function((&function_275), env);
  pop_function();
}
/* fn_56 */
void body_111() {
  increment_count(env);
  val = new_function((&function_276), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  return_location = (&body_112);
}
void body_113();
void function_277() {
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
void function_278() {
  increment_count(env);
  val = new_function((&function_277), env);
  pop_function();
}
/* fn_55 */
void body_112() {
  increment_count(env);
  val = new_function((&function_278), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  return_location = (&body_113);
}
void body_114();
pointer global_c95c95c95c109c97c116c99c104;
void function_279() {
  global_c95c95c95c109c97c116c99c104 = val; /* ___match */
  return_location = (&body_114);
}
/* ___match */
void body_113() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  apply((&function_279));
}
void body_115();
pointer global_c102c110c95c53c55 = NIL; /* fn_57 */
pointer global_c102c110c95c53c56;
void function_280() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  top_level_apply();
}
void function_281() {
  increment_count(env);
  val = new_function((&function_280), env);
  pop_function();
}
/* fn_58 */
void body_114() {
  increment_count(env);
  val = new_function((&function_281), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  return_location = (&body_115);
}
void body_116();
void function_282() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_283() {
  increment_count(env);
  val = new_function((&function_282), env);
  pop_function();
}
/* fn_57 */
void body_115() {
  increment_count(env);
  val = new_function((&function_283), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  return_location = (&body_116);
}
void body_117();
pointer global_c95c95c95c100c101c102c97c117c108c116;
void function_284() {
  global_c95c95c95c100c101c102c97c117c108c116 = val; /* ___default */
  return_location = (&body_117);
}
/* ___default */
void body_116() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  apply((&function_284));
}
void body_118();
pointer global_c102c110c95c54c50 = NIL; /* fn_62 */
pointer global_c102c110c95c54c51;
void function_285() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  top_level_apply();
}
void function_286() {
  increment_count(env);
  val = new_function((&function_285), env);
  pop_function();
}
/* fn_63 */
void body_117() {
  increment_count(env);
  val = new_function((&function_286), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  return_location = (&body_118);
}
void body_119();
pointer global_c102c110c95c54c49 = NIL; /* fn_61 */
void function_287() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  top_level_apply();
}
void function_288() {
  increment_count(env);
  val = new_function((&function_287), env);
  pop_function();
}
/* fn_62 */
void body_118() {
  increment_count(env);
  val = new_function((&function_288), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  return_location = (&body_119);
}
void body_120();
pointer global_c102c110c95c54c48 = NIL; /* fn_60 */
pointer global_c102c110c95c53c57 = NIL; /* fn_59 */
void function_289() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_290() {
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
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  apply((&function_289));
}
void function_291() {
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
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  apply((&function_290));
}
void function_292() {
  increment_count(env);
  val = new_function((&function_291), env);
  pop_function();
}
/* fn_61 */
void body_119() {
  increment_count(env);
  val = new_function((&function_292), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  return_location = (&body_120);
}
void body_121();
void function_293() {
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
void function_294() {
  increment_count(env);
  val = new_function((&function_293), env);
  pop_function();
}
/* fn_59 */
void body_120() {
  increment_count(env);
  val = new_function((&function_294), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  return_location = (&body_121);
}
void body_122();
void function_295() {
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
void function_296() {
  increment_count(env);
  val = new_function((&function_295), env);
  pop_function();
}
/* fn_60 */
void body_121() {
  increment_count(env);
  val = new_function((&function_296), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  return_location = (&body_122);
}
void body_123();
pointer global_c95c95c95c99c97c115c101;
void function_297() {
  global_c95c95c95c99c97c115c101 = val; /* ___case */
  return_location = (&body_123);
}
/* ___case */
void body_122() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  apply((&function_297));
}
void body_124();
pointer global_c95c95c108c95c49c57;
/* __l_19 */
void body_123() {
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
  global_c95c95c108c95c49c57 = val; /* __l_19 */
  return_location = (&body_124);
}
void body_125();
pointer global_c102c110c95c54c52 = NIL; /* fn_64 */
pointer global_c102c110c95c54c53;
void function_298() {
  top_level_apply();
}
void function_299() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_298));
}
void function_300() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  apply((&function_299));
}
void function_301() {
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
  increment_count(val = global_c95c95c108c95c49c57); /* __l_19 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c97c105c108); /* ___fail */
  apply((&function_300));
}
void function_302() {
  increment_count(env);
  val = new_function((&function_301), env);
  pop_function();
}
/* fn_65 */
void body_124() {
  increment_count(env);
  val = new_function((&function_302), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  return_location = (&body_125);
}
void body_126();
void function_303() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_304() {
  increment_count(env);
  val = new_function((&function_303), env);
  pop_function();
}
/* fn_64 */
void body_125() {
  increment_count(env);
  val = new_function((&function_304), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  return_location = (&body_126);
}
void body_127();
pointer global_c95c95c95c99c104c111c105c99c101;
void function_305() {
  global_c95c95c95c99c104c111c105c99c101 = val; /* ___choice */
  return_location = (&body_127);
}
/* ___choice */
void body_126() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  apply((&function_305));
}
void body_128();
pointer global_c102c110c95c54c55 = NIL; /* fn_67 */
pointer global_c102c110c95c54c56;
void function_306() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  top_level_apply();
}
void function_307() {
  increment_count(env);
  val = new_function((&function_306), env);
  pop_function();
}
/* fn_68 */
void body_127() {
  increment_count(env);
  val = new_function((&function_307), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  return_location = (&body_128);
}
void body_129();
pointer global_c102c110c95c54c54 = NIL; /* fn_66 */
void function_308() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_309() {
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
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  apply((&function_308));
}
void function_310() {
  increment_count(env);
  val = new_function((&function_309), env);
  pop_function();
}
/* fn_67 */
void body_128() {
  increment_count(env);
  val = new_function((&function_310), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  return_location = (&body_129);
}
void body_130();
void function_311() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_312() {
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
  apply((&function_311));
}
void function_313() {
  increment_count(env);
  val = new_function((&function_312), env);
  pop_function();
}
/* fn_66 */
void body_129() {
  increment_count(env);
  val = new_function((&function_313), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  return_location = (&body_130);
}
void body_131();
pointer global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_314() {
  global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* ___post-process */
  return_location = (&body_131);
}
/* ___post-process */
void body_130() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  apply((&function_314));
}
void body_132();
pointer global_c102c110c95c55c49 = NIL; /* fn_71 */
pointer global_c102c110c95c55c50;
void function_315() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  top_level_apply();
}
void function_316() {
  increment_count(env);
  val = new_function((&function_315), env);
  pop_function();
}
/* fn_72 */
void body_131() {
  increment_count(env);
  val = new_function((&function_316), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  return_location = (&body_132);
}
void body_133();
pointer global_c102c110c95c55c48 = NIL; /* fn_70 */
void function_317() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_318() {
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
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  apply((&function_317));
}
void function_319() {
  increment_count(env);
  val = new_function((&function_318), env);
  pop_function();
}
/* fn_71 */
void body_132() {
  increment_count(env);
  val = new_function((&function_319), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  return_location = (&body_133);
}
void body_134();
pointer global_c102c110c95c54c57 = NIL; /* fn_69 */
void function_320() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_321() {
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
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  apply((&function_320));
}
void function_322() {
  increment_count(env);
  val = new_function((&function_321), env);
  pop_function();
}
/* fn_70 */
void body_133() {
  increment_count(env);
  val = new_function((&function_322), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  return_location = (&body_134);
}
void body_135();
void function_323() {
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
void function_324() {
  increment_count(env);
  val = new_function((&function_323), env);
  pop_function();
}
/* fn_69 */
void body_134() {
  increment_count(env);
  val = new_function((&function_324), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  return_location = (&body_135);
}
void body_136();
pointer global_c95c95c95c115c101c113;
void function_325() {
  global_c95c95c95c115c101c113 = val; /* ___seq */
  return_location = (&body_136);
}
/* ___seq */
void body_135() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  apply((&function_325));
}
void body_137();
pointer global_c102c110c95c55c51;
void function_326() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c101c113); /* ___seq */
  top_level_apply();
}
void function_327() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114); /* ___escape-char */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c112); /* ___pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  apply((&function_326));
}
void function_328() {
  increment_count(env);
  val = new_function((&function_327), env);
  pop_function();
}
/* fn_73 */
void body_136() {
  increment_count(env);
  val = new_function((&function_328), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  return_location = (&body_137);
}
void body_138();
pointer global_c95c95c95c101c115c99c97c112c101;
void function_329() {
  global_c95c95c95c101c115c99c97c112c101 = val; /* ___escape */
  return_location = (&body_138);
}
/* ___escape */
void body_137() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  apply((&function_329));
}
void body_139();
pointer global_c102c110c95c55c52;
void function_330() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c112); /* ___pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c101c113); /* ___seq */
  top_level_apply();
}
void function_331() {
  increment_count(env);
  val = new_function((&function_330), env);
  pop_function();
}
/* fn_74 */
void body_138() {
  increment_count(env);
  val = new_function((&function_331), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  return_location = (&body_139);
}
void body_140();
pointer global_c95c95c95c117c115c101;
void function_332() {
  global_c95c95c95c117c115c101 = val; /* ___use */
  return_location = (&body_140);
}
/* ___use */
void body_139() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  apply((&function_332));
}
void body_141();
pointer global_c102c110c95c55c54 = NIL; /* fn_76 */
pointer global_c102c110c95c55c55;
void function_333() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  top_level_apply();
}
void function_334() {
  increment_count(env);
  val = new_function((&function_333), env);
  pop_function();
}
/* fn_77 */
void body_140() {
  increment_count(env);
  val = new_function((&function_334), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  return_location = (&body_141);
}
void body_142();
pointer global_c102c110c95c55c53 = NIL; /* fn_75 */
void function_335() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_336() {
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
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  apply((&function_335));
}
void function_337() {
  increment_count(env);
  val = new_function((&function_336), env);
  pop_function();
}
/* fn_76 */
void body_141() {
  increment_count(env);
  val = new_function((&function_337), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  return_location = (&body_142);
}
void body_143();
void function_338() {
  top_level_apply();
}
void function_339() {
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
  apply((&function_338));
}
void function_340() {
  increment_count(env);
  val = new_function((&function_339), env);
  pop_function();
}
/* fn_75 */
void body_142() {
  increment_count(env);
  val = new_function((&function_340), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  return_location = (&body_143);
}
void body_144();
pointer global_c95c95c95c112c101c101c107;
void function_341() {
  global_c95c95c95c112c101c101c107 = val; /* ___peek */
  return_location = (&body_144);
}
/* ___peek */
void body_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  apply((&function_341));
}
void body_145();
pointer global_c102c110c95c55c56 = NIL; /* fn_78 */
pointer global_c102c110c95c55c57;
void function_342() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c101c99c107); /* ___check */
  top_level_apply();
}
void function_343() {
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
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  apply((&function_342));
}
void function_344() {
  increment_count(env);
  val = new_function((&function_343), env);
  pop_function();
}
/* fn_79 */
void body_144() {
  increment_count(env);
  val = new_function((&function_344), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  return_location = (&body_145);
}
void body_146();
void function_345() {
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
void function_346() {
  increment_count(env);
  val = new_function((&function_345), env);
  pop_function();
}
/* fn_78 */
void body_145() {
  increment_count(env);
  val = new_function((&function_346), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  return_location = (&body_146);
}
void body_147();
pointer global_c95c95c95c105c110c116c101c114c118c97c108;
void function_347() {
  global_c95c95c95c105c110c116c101c114c118c97c108 = val; /* ___interval */
  return_location = (&body_147);
}
/* ___interval */
void body_146() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  apply((&function_347));
}
void body_148();
pointer global_c99c100c114 = CDR; /* cdr */
pointer global_c102c110c95c56c48;
void function_348() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  top_level_apply();
}
void function_349() {
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
  increment_count(val = global_c95c95c95c117c115c101); /* ___use */
  apply((&function_348));
}
void function_350() {
  increment_count(env);
  val = new_function((&function_349), env);
  pop_function();
}
/* fn_80 */
void body_147() {
  increment_count(env);
  val = new_function((&function_350), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  return_location = (&body_148);
}
void body_149();
pointer global_c95c95c95c115c107c105c112;
void function_351() {
  global_c95c95c95c115c107c105c112 = val; /* ___skip */
  return_location = (&body_149);
}
/* ___skip */
void body_148() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  apply((&function_351));
}
void body_150();
pointer global_c99c97c114 = CAR; /* car */
pointer global_c102c110c95c56c49;
void function_352() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  top_level_apply();
}
void function_353() {
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
  increment_count(val = global_c95c95c95c115c101c113); /* ___seq */
  apply((&function_352));
}
void function_354() {
  increment_count(env);
  val = new_function((&function_353), env);
  pop_function();
}
/* fn_81 */
void body_149() {
  increment_count(env);
  val = new_function((&function_354), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  return_location = (&body_150);
}
void body_151();
pointer global_c95c95c95c102c105c114c115c116;
void function_355() {
  global_c95c95c95c102c105c114c115c116 = val; /* ___first */
  return_location = (&body_151);
}
/* ___first */
void body_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  apply((&function_355));
}
void body_152();
pointer global_c95c95c95c112c97c114c115c101c45c110c117c109 = NIL; /* ___parse-num */
pointer global_c102c110c95c56c50;
void function_356() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_357() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_356));
}
void function_358() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_357));
}
void function_359() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c101c101c107); /* ___peek */
  apply((&function_358));
}
void function_360() {
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
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_359));
}
void function_361() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109); /* ___parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c117c115c101); /* ___use */
  apply((&function_360));
}
void function_362() {
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
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_361));
}
void function_363() {
  increment_count(env);
  val = new_function((&function_362), env);
  pop_function();
}
/* fn_82 */
void body_151() {
  increment_count(env);
  val = new_function((&function_363), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  return_location = (&body_152);
}
void body_153();
void function_364() {
  global_c95c95c95c112c97c114c115c101c45c110c117c109 = val; /* ___parse-num */
  return_location = (&body_153);
}
/* ___parse-num */
void body_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  apply((&function_364));
}
void body_154();
pointer global_c102c110c95c56c51;
void function_365() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_366() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c98c117c105c108c100c45c110c117c109); /* ___build-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109); /* ___parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  apply((&function_365));
}
void function_367() {
  increment_count(env);
  val = new_function((&function_366), env);
  pop_function();
}
/* fn_83 */
void body_153() {
  increment_count(env);
  val = new_function((&function_367), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  return_location = (&body_154);
}
void body_155();
pointer global_c95c95c95c114c101c97c100c45c110c117c109;
void function_368() {
  global_c95c95c95c114c101c97c100c45c110c117c109 = val; /* ___read-num */
  return_location = (&body_155);
}
/* ___read-num */
void body_154() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  apply((&function_368));
}
void body_156();
pointer global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* ___parse-symbol */
pointer global_c102c110c95c56c52;
void function_369() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_370() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_369));
}
void function_371() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_370));
}
void function_372() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_371));
}
void function_373() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_372));
}
void function_374() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c101c101c107); /* ___peek */
  apply((&function_373));
}
void function_375() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
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
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_374));
}
void function_376() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_375));
}
void function_377() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c101c101c107); /* ___peek */
  apply((&function_376));
}
void function_378() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_377));
}
void function_379() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_378));
}
void function_380() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c101c101c107); /* ___peek */
  apply((&function_379));
}
void function_381() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_380));
}
void function_382() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_381));
}
void function_383() {
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
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* ___parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c117c115c101); /* ___use */
  apply((&function_382));
}
void function_384() {
  increment_count(env);
  val = new_function((&function_383), env);
  pop_function();
}
/* fn_84 */
void body_155() {
  increment_count(env);
  val = new_function((&function_384), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  return_location = (&body_156);
}
void body_157();
void function_385() {
  global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* ___parse-symbol */
  return_location = (&body_157);
}
/* ___parse-symbol */
void body_156() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  apply((&function_385));
}
void body_158();
pointer global_c102c110c95c56c53;
void function_386() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_387() {
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
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* ___parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  apply((&function_386));
}
void function_388() {
  increment_count(env);
  val = new_function((&function_387), env);
  pop_function();
}
/* fn_85 */
void body_157() {
  increment_count(env);
  val = new_function((&function_388), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  return_location = (&body_158);
}
void body_159();
pointer global_c95c95c95c114c101c97c100c45c115c121c109c98c111c108;
void function_389() {
  global_c95c95c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* ___read-symbol */
  return_location = (&body_159);
}
/* ___read-symbol */
void body_158() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  apply((&function_389));
}
void body_160();
pointer global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* ___parse-string */
pointer global_c102c110c95c56c54;
void function_390() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_391() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_390));
}
void function_392() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_391));
}
void function_393() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_392));
}
void function_394() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_393));
}
void function_395() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_394));
}
void function_396() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ___parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101); /* ___escape */
  apply((&function_395));
}
void function_397() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_396));
}
void function_398() {
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
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ___parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c117c115c101); /* ___use */
  apply((&function_397));
}
void function_399() {
  increment_count(env);
  val = new_function((&function_398), env);
  pop_function();
}
/* fn_86 */
void body_159() {
  increment_count(env);
  val = new_function((&function_399), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  return_location = (&body_160);
}
void body_161();
void function_400() {
  global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* ___parse-string */
  return_location = (&body_161);
}
/* ___parse-string */
void body_160() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  apply((&function_400));
}
void body_162();
pointer global_c102c110c95c56c55;
void function_401() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c113c117c111c116c101c45c118c97c108c117c101); /* ___quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  top_level_apply();
}
void function_402() {
  increment_count(env);
  val = new_function((&function_401), env);
  pop_function();
}
/* fn_87 */
void body_161() {
  increment_count(env);
  val = new_function((&function_402), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  return_location = (&body_162);
}
void body_163();
pointer global_c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_403() {
  global_c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ___quote-parser */
  return_location = (&body_163);
}
/* ___quote-parser */
void body_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  apply((&function_403));
}
void body_164();
pointer global_c102c110c95c56c56;
void function_404() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* ___quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  top_level_apply();
}
void function_405() {
  increment_count(env);
  val = new_function((&function_404), env);
  pop_function();
}
/* fn_88 */
void body_163() {
  increment_count(env);
  val = new_function((&function_405), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  return_location = (&body_164);
}
void body_165();
pointer global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_406() {
  global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ___quasiquote-parser */
  return_location = (&body_165);
}
/* ___quasiquote-parser */
void body_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  apply((&function_406));
}
void body_166();
pointer global_c102c110c95c56c57;
void function_407() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* ___unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ___post-process */
  top_level_apply();
}
void function_408() {
  increment_count(env);
  val = new_function((&function_407), env);
  pop_function();
}
/* fn_89 */
void body_165() {
  increment_count(env);
  val = new_function((&function_408), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  return_location = (&body_166);
}
void body_167();
pointer global_c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_409() {
  global_c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ___unquote-parser */
  return_location = (&body_167);
}
/* ___unquote-parser */
void body_166() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  apply((&function_409));
}
void body_168();
pointer global_c102c110c95c57c48 = NIL; /* fn_90 */
pointer global_c102c110c95c57c49;
void function_410() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  top_level_apply();
}
void function_411() {
  increment_count(env);
  val = new_function((&function_410), env);
  pop_function();
}
/* fn_91 */
void body_167() {
  increment_count(env);
  val = new_function((&function_411), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  return_location = (&body_168);
}
void body_169();
pointer global_c95c95c95c99c111c109c109c101c110c116 = NIL; /* ___comment */
void function_412() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_413() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_412));
}
void function_414() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_413));
}
void function_415() {
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
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_414));
}
void function_416() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_415));
}
void function_417() {
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
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_416));
}
void function_418() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_417));
}
void function_419() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c107c105c112); /* ___skip */
  apply((&function_418));
}
void function_420() {
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
  increment_count(val = global_c95c95c95c99c111c109c109c101c110c116); /* ___comment */
  apply((&function_419));
}
void function_421() {
  increment_count(env);
  val = new_function((&function_420), env);
  pop_function();
}
/* fn_90 */
void body_168() {
  increment_count(env);
  val = new_function((&function_421), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  return_location = (&body_169);
}
void body_170();
void function_422() {
  global_c95c95c95c99c111c109c109c101c110c116 = val; /* ___comment */
  return_location = (&body_170);
}
/* ___comment */
void body_169() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  apply((&function_422));
}
void body_171();
pointer global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* ___parse-paren */
pointer global_c102c110c95c57c50;
void function_423() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_424() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_423));
}
void function_425() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_424));
}
void function_426() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ___parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_425));
}
void function_427() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_426));
}
void function_428() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_427));
}
void function_429() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ___parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c109c101c110c116); /* ___comment */
  apply((&function_428));
}
void function_430() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_429));
}
void function_431() {
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
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_430));
}
void function_432() {
  increment_count(env);
  val = new_function((&function_431), env);
  pop_function();
}
/* fn_92 */
void body_170() {
  increment_count(env);
  val = new_function((&function_432), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  return_location = (&body_171);
}
void body_172();
void function_433() {
  global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* ___parse-paren */
  return_location = (&body_172);
}
/* ___parse-paren */
void body_171() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  apply((&function_433));
}
void body_173();
pointer global_c102c110c95c57c51;
void function_434() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_435() {
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
    apply((&function_434));
  }
}
void function_436() {
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
    apply((&function_435));
  }
}
void function_437() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_436));
}
void function_438() {
  increment_count(env);
  val = new_function((&function_437), env);
  pop_function();
}
/* fn_93 */
void body_172() {
  increment_count(env);
  val = new_function((&function_438), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  return_location = (&body_173);
}
void body_174();
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
void function_439() {
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  return_location = (&body_174);
}
/* _escape-char */
void body_173() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  apply((&function_439));
}
void body_175();
pointer global_c102c110c95c57c52 = NIL; /* fn_94 */
pointer global_c102c110c95c57c53;
void function_440() {
  top_level_apply();
}
void function_441() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_440));
}
void function_442() {
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
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  apply((&function_441));
}
void function_443() {
  increment_count(env);
  val = new_function((&function_442), env);
  pop_function();
}
/* fn_95 */
void body_174() {
  increment_count(env);
  val = new_function((&function_443), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  return_location = (&body_175);
}
void body_176();
void function_444() {
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
void function_445() {
  increment_count(env);
  val = new_function((&function_444), env);
  pop_function();
}
/* fn_94 */
void body_175() {
  increment_count(env);
  val = new_function((&function_445), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  return_location = (&body_176);
}
void body_177();
pointer global_c95c98c117c105c108c100c45c110c117c109;
void function_446() {
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  return_location = (&body_177);
}
/* _build-num */
void body_176() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  apply((&function_446));
}
void body_178();
pointer global_c102c110c95c57c54;
void function_447() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -40;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_448() {
  increment_count(env);
  val = new_function((&function_447), env);
  pop_function();
}
/* fn_96 */
void body_177() {
  increment_count(env);
  val = new_function((&function_448), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  return_location = (&body_178);
}
void body_179();
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
void function_449() {
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  return_location = (&body_179);
}
/* _quote-value */
void body_178() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  apply((&function_449));
}
void body_180();
pointer global_c102c110c95c57c55;
void function_450() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -39;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_451() {
  increment_count(env);
  val = new_function((&function_450), env);
  pop_function();
}
/* fn_97 */
void body_179() {
  increment_count(env);
  val = new_function((&function_451), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  return_location = (&body_180);
}
void body_181();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_452() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  return_location = (&body_181);
}
/* _quasiquote-value */
void body_180() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  apply((&function_452));
}
void body_182();
pointer global_c102c110c95c57c56;
void function_453() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_454() {
  increment_count(env);
  val = new_function((&function_453), env);
  pop_function();
}
/* fn_98 */
void body_181() {
  increment_count(env);
  val = new_function((&function_454), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  return_location = (&body_182);
}
void body_183();
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_455() {
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  return_location = (&body_183);
}
/* _unquote-value */
void body_182() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  apply((&function_455));
}
void body_184();
pointer global_c102c110c95c57c57 = NIL; /* fn_99 */
pointer global_c102c110c95c49c48c48;
void function_456() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  top_level_apply();
}
void function_457() {
  increment_count(env);
  val = new_function((&function_456), env);
  pop_function();
}
/* fn_100 */
void body_183() {
  increment_count(env);
  val = new_function((&function_457), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  return_location = (&body_184);
}
void body_185();
void function_458() {
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
void function_459() {
  increment_count(env);
  val = new_function((&function_458), env);
  pop_function();
}
/* fn_99 */
void body_184() {
  increment_count(env);
  val = new_function((&function_459), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  return_location = (&body_185);
}
void body_186();
pointer global_c95c102c97c105c108;
void function_460() {
  global_c95c102c97c105c108 = val; /* _fail */
  return_location = (&body_186);
}
/* _fail */
void body_185() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  apply((&function_460));
}
void body_187();
pointer global_c102c110c95c49c48c49;
void function_461() {
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
void function_462() {
  increment_count(env);
  val = new_function((&function_461), env);
  pop_function();
}
/* fn_101 */
void body_186() {
  increment_count(env);
  val = new_function((&function_462), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  return_location = (&body_187);
}
void body_188();
pointer global_c95c100c111c110c101;
void function_463() {
  global_c95c100c111c110c101 = val; /* _done */
  return_location = (&body_188);
}
/* _done */
void body_187() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  apply((&function_463));
}
void body_189();
pointer global_c102c110c95c49c48c50 = NIL; /* fn_102 */
pointer global_c102c110c95c49c48c51;
void function_464() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  top_level_apply();
}
void function_465() {
  increment_count(env);
  val = new_function((&function_464), env);
  pop_function();
}
/* fn_103 */
void body_188() {
  increment_count(env);
  val = new_function((&function_465), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  return_location = (&body_189);
}
void body_190();
pointer global_c95c112c111c112 = NIL; /* _pop */
void function_466() {
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
void function_467() {
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
      apply((&function_466));
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
void function_468() {
  increment_count(env);
  val = new_function((&function_467), env);
  pop_function();
}
/* fn_102 */
void body_189() {
  increment_count(env);
  val = new_function((&function_468), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  return_location = (&body_190);
}
void body_191();
void function_469() {
  global_c95c112c111c112 = val; /* _pop */
  return_location = (&body_191);
}
/* _pop */
void body_190() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  apply((&function_469));
}
void body_192();
pointer global_c102c110c95c49c48c53 = NIL; /* fn_105 */
pointer global_c102c110c95c49c48c54;
void function_470() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  top_level_apply();
}
void function_471() {
  increment_count(env);
  val = new_function((&function_470), env);
  pop_function();
}
/* fn_106 */
void body_191() {
  increment_count(env);
  val = new_function((&function_471), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  return_location = (&body_192);
}
void body_193();
pointer global_c102c110c95c49c48c52 = NIL; /* fn_104 */
void function_472() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  top_level_apply();
}
void function_473() {
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
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  apply((&function_472));
}
void function_474() {
  increment_count(env);
  val = new_function((&function_473), env);
  pop_function();
}
/* fn_105 */
void body_192() {
  increment_count(env);
  val = new_function((&function_474), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  return_location = (&body_193);
}
void body_194();
void function_475() {
  top_level_apply();
}
void function_476() {
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
    apply((&function_475));
  }
}
void function_477() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_476));
}
void function_478() {
  increment_count(env);
  val = new_function((&function_477), env);
  pop_function();
}
/* fn_104 */
void body_193() {
  increment_count(env);
  val = new_function((&function_478), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  return_location = (&body_194);
}
void body_195();
pointer global_c95c99c104c101c99c107;
void function_479() {
  global_c95c99c104c101c99c107 = val; /* _check */
  return_location = (&body_195);
}
/* _check */
void body_194() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  apply((&function_479));
}
void body_196();
pointer global_c102c110c95c49c48c55 = NIL; /* fn_107 */
pointer global_c102c110c95c49c48c56;
void function_480() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_481() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  apply((&function_480));
}
void function_482() {
  increment_count(env);
  val = new_function((&function_481), env);
  pop_function();
}
/* fn_108 */
void body_195() {
  increment_count(env);
  val = new_function((&function_482), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  return_location = (&body_196);
}
void body_197();
void function_483() {
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
void function_484() {
  increment_count(env);
  val = new_function((&function_483), env);
  pop_function();
}
/* fn_107 */
void body_196() {
  increment_count(env);
  val = new_function((&function_484), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  return_location = (&body_197);
}
void body_198();
pointer global_c95c109c97c116c99c104;
void function_485() {
  global_c95c109c97c116c99c104 = val; /* _match */
  return_location = (&body_198);
}
/* _match */
void body_197() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  apply((&function_485));
}
void body_199();
pointer global_c102c110c95c49c48c57 = NIL; /* fn_109 */
pointer global_c102c110c95c49c49c48;
void function_486() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  top_level_apply();
}
void function_487() {
  increment_count(env);
  val = new_function((&function_486), env);
  pop_function();
}
/* fn_110 */
void body_198() {
  increment_count(env);
  val = new_function((&function_487), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  return_location = (&body_199);
}
void body_200();
void function_488() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_489() {
  increment_count(env);
  val = new_function((&function_488), env);
  pop_function();
}
/* fn_109 */
void body_199() {
  increment_count(env);
  val = new_function((&function_489), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  return_location = (&body_200);
}
void body_201();
pointer global_c95c100c101c102c97c117c108c116;
void function_490() {
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  return_location = (&body_201);
}
/* _default */
void body_200() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  apply((&function_490));
}
void body_202();
pointer global_c102c110c95c49c49c52 = NIL; /* fn_114 */
pointer global_c102c110c95c49c49c53;
void function_491() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  top_level_apply();
}
void function_492() {
  increment_count(env);
  val = new_function((&function_491), env);
  pop_function();
}
/* fn_115 */
void body_201() {
  increment_count(env);
  val = new_function((&function_492), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  return_location = (&body_202);
}
void body_203();
pointer global_c102c110c95c49c49c51 = NIL; /* fn_113 */
void function_493() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  top_level_apply();
}
void function_494() {
  increment_count(env);
  val = new_function((&function_493), env);
  pop_function();
}
/* fn_114 */
void body_202() {
  increment_count(env);
  val = new_function((&function_494), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  return_location = (&body_203);
}
void body_204();
pointer global_c102c110c95c49c49c50 = NIL; /* fn_112 */
pointer global_c102c110c95c49c49c49 = NIL; /* fn_111 */
void function_495() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_496() {
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
  apply((&function_495));
}
void function_497() {
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
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  apply((&function_496));
}
void function_498() {
  increment_count(env);
  val = new_function((&function_497), env);
  pop_function();
}
/* fn_113 */
void body_203() {
  increment_count(env);
  val = new_function((&function_498), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  return_location = (&body_204);
}
void body_205();
void function_499() {
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
void function_500() {
  increment_count(env);
  val = new_function((&function_499), env);
  pop_function();
}
/* fn_111 */
void body_204() {
  increment_count(env);
  val = new_function((&function_500), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  return_location = (&body_205);
}
void body_206();
void function_501() {
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
void function_502() {
  increment_count(env);
  val = new_function((&function_501), env);
  pop_function();
}
/* fn_112 */
void body_205() {
  increment_count(env);
  val = new_function((&function_502), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  return_location = (&body_206);
}
void body_207();
pointer global_c95c99c97c115c101;
void function_503() {
  global_c95c99c97c115c101 = val; /* _case */
  return_location = (&body_207);
}
/* _case */
void body_206() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  apply((&function_503));
}
void body_208();
pointer global_c102c110c95c49c49c54 = NIL; /* fn_116 */
pointer global_c102c110c95c49c49c55;
void function_504() {
  top_level_apply();
}
void function_505() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_504));
}
void function_506() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  apply((&function_505));
}
void function_507() {
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
  apply((&function_506));
}
void function_508() {
  increment_count(env);
  val = new_function((&function_507), env);
  pop_function();
}
/* fn_117 */
void body_207() {
  increment_count(env);
  val = new_function((&function_508), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  return_location = (&body_208);
}
void body_209();
void function_509() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_510() {
  increment_count(env);
  val = new_function((&function_509), env);
  pop_function();
}
/* fn_116 */
void body_208() {
  increment_count(env);
  val = new_function((&function_510), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  return_location = (&body_209);
}
void body_210();
pointer global_c95c99c104c111c105c99c101;
void function_511() {
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  return_location = (&body_210);
}
/* _choice */
void body_209() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  apply((&function_511));
}
void body_211();
pointer global_c102c110c95c49c49c57 = NIL; /* fn_119 */
pointer global_c102c110c95c49c50c48;
void function_512() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  top_level_apply();
}
void function_513() {
  increment_count(env);
  val = new_function((&function_512), env);
  pop_function();
}
/* fn_120 */
void body_210() {
  increment_count(env);
  val = new_function((&function_513), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  return_location = (&body_211);
}
void body_212();
pointer global_c102c110c95c49c49c56 = NIL; /* fn_118 */
void function_514() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  apply((&function_514));
}
void function_516() {
  increment_count(env);
  val = new_function((&function_515), env);
  pop_function();
}
/* fn_119 */
void body_211() {
  increment_count(env);
  val = new_function((&function_516), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  return_location = (&body_212);
}
void body_213();
void function_517() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_518() {
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
  apply((&function_517));
}
void function_519() {
  increment_count(env);
  val = new_function((&function_518), env);
  pop_function();
}
/* fn_118 */
void body_212() {
  increment_count(env);
  val = new_function((&function_519), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  return_location = (&body_213);
}
void body_214();
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_520() {
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  return_location = (&body_214);
}
/* _post-process */
void body_213() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  apply((&function_520));
}
void body_215();
pointer global_c102c110c95c49c50c51 = NIL; /* fn_123 */
pointer global_c102c110c95c49c50c52;
void function_521() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  top_level_apply();
}
void function_522() {
  increment_count(env);
  val = new_function((&function_521), env);
  pop_function();
}
/* fn_124 */
void body_214() {
  increment_count(env);
  val = new_function((&function_522), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  return_location = (&body_215);
}
void body_216();
pointer global_c102c110c95c49c50c50 = NIL; /* fn_122 */
void function_523() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_524() {
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
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  apply((&function_523));
}
void function_525() {
  increment_count(env);
  val = new_function((&function_524), env);
  pop_function();
}
/* fn_123 */
void body_215() {
  increment_count(env);
  val = new_function((&function_525), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  return_location = (&body_216);
}
void body_217();
pointer global_c102c110c95c49c50c49 = NIL; /* fn_121 */
void function_526() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_527() {
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
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  apply((&function_526));
}
void function_528() {
  increment_count(env);
  val = new_function((&function_527), env);
  pop_function();
}
/* fn_122 */
void body_216() {
  increment_count(env);
  val = new_function((&function_528), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  return_location = (&body_217);
}
void body_218();
void function_529() {
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
void function_530() {
  increment_count(env);
  val = new_function((&function_529), env);
  pop_function();
}
/* fn_121 */
void body_217() {
  increment_count(env);
  val = new_function((&function_530), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  return_location = (&body_218);
}
void body_219();
pointer global_c95c115c101c113;
void function_531() {
  global_c95c115c101c113 = val; /* _seq */
  return_location = (&body_219);
}
/* _seq */
void body_218() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  apply((&function_531));
}
void body_220();
pointer global_c102c110c95c49c50c53;
void function_532() {
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  top_level_apply();
}
void function_533() {
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
  apply((&function_532));
}
void function_534() {
  increment_count(env);
  val = new_function((&function_533), env);
  pop_function();
}
/* fn_125 */
void body_219() {
  increment_count(env);
  val = new_function((&function_534), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  return_location = (&body_220);
}
void body_221();
pointer global_c95c101c115c99c97c112c101;
void function_535() {
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  return_location = (&body_221);
}
/* _escape */
void body_220() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  apply((&function_535));
}
void body_222();
pointer global_c102c110c95c49c50c54;
void function_536() {
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
void function_537() {
  increment_count(env);
  val = new_function((&function_536), env);
  pop_function();
}
/* fn_126 */
void body_221() {
  increment_count(env);
  val = new_function((&function_537), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  return_location = (&body_222);
}
void body_223();
pointer global_c95c117c115c101;
void function_538() {
  global_c95c117c115c101 = val; /* _use */
  return_location = (&body_223);
}
/* _use */
void body_222() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  apply((&function_538));
}
void body_224();
pointer global_c102c110c95c49c50c56 = NIL; /* fn_128 */
pointer global_c102c110c95c49c50c57;
void function_539() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  top_level_apply();
}
void function_540() {
  increment_count(env);
  val = new_function((&function_539), env);
  pop_function();
}
/* fn_129 */
void body_223() {
  increment_count(env);
  val = new_function((&function_540), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  return_location = (&body_224);
}
void body_225();
pointer global_c102c110c95c49c50c55 = NIL; /* fn_127 */
void function_541() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_542() {
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
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  apply((&function_541));
}
void function_543() {
  increment_count(env);
  val = new_function((&function_542), env);
  pop_function();
}
/* fn_128 */
void body_224() {
  increment_count(env);
  val = new_function((&function_543), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  return_location = (&body_225);
}
void body_226();
void function_544() {
  top_level_apply();
}
void function_545() {
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
  apply((&function_544));
}
void function_546() {
  increment_count(env);
  val = new_function((&function_545), env);
  pop_function();
}
/* fn_127 */
void body_225() {
  increment_count(env);
  val = new_function((&function_546), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  return_location = (&body_226);
}
void body_227();
pointer global_c95c112c101c101c107;
void function_547() {
  global_c95c112c101c101c107 = val; /* _peek */
  return_location = (&body_227);
}
/* _peek */
void body_226() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  apply((&function_547));
}
void body_228();
pointer global_c102c110c95c49c51c48 = NIL; /* fn_130 */
pointer global_c102c110c95c49c51c49;
void function_548() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_549() {
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
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  apply((&function_548));
}
void function_550() {
  increment_count(env);
  val = new_function((&function_549), env);
  pop_function();
}
/* fn_131 */
void body_227() {
  increment_count(env);
  val = new_function((&function_550), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  return_location = (&body_228);
}
void body_229();
void function_551() {
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
void function_552() {
  increment_count(env);
  val = new_function((&function_551), env);
  pop_function();
}
/* fn_130 */
void body_228() {
  increment_count(env);
  val = new_function((&function_552), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  return_location = (&body_229);
}
void body_230();
pointer global_c95c105c110c116c101c114c118c97c108;
void function_553() {
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  return_location = (&body_230);
}
/* _interval */
void body_229() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  apply((&function_553));
}
void body_231();
pointer global_c102c110c95c49c51c50;
void function_554() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_555() {
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
  apply((&function_554));
}
void function_556() {
  increment_count(env);
  val = new_function((&function_555), env);
  pop_function();
}
/* fn_132 */
void body_230() {
  increment_count(env);
  val = new_function((&function_556), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  return_location = (&body_231);
}
void body_232();
pointer global_c95c115c107c105c112;
void function_557() {
  global_c95c115c107c105c112 = val; /* _skip */
  return_location = (&body_232);
}
/* _skip */
void body_231() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  apply((&function_557));
}
void body_233();
pointer global_c102c110c95c49c51c51;
void function_558() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_559() {
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
  apply((&function_558));
}
void function_560() {
  increment_count(env);
  val = new_function((&function_559), env);
  pop_function();
}
/* fn_133 */
void body_232() {
  increment_count(env);
  val = new_function((&function_560), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  return_location = (&body_233);
}
void body_234();
pointer global_c95c102c105c114c115c116;
void function_561() {
  global_c95c102c105c114c115c116 = val; /* _first */
  return_location = (&body_234);
}
/* _first */
void body_233() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  apply((&function_561));
}
void body_235();
pointer global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
pointer global_c102c110c95c49c51c52;
void function_562() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_563() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_562));
}
void function_564() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_563));
}
void function_565() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_564));
}
void function_566() {
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
  apply((&function_565));
}
void function_567() {
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
  apply((&function_566));
}
void function_568() {
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
  apply((&function_567));
}
void function_569() {
  increment_count(env);
  val = new_function((&function_568), env);
  pop_function();
}
/* fn_134 */
void body_234() {
  increment_count(env);
  val = new_function((&function_569), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  return_location = (&body_235);
}
void body_236();
void function_570() {
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  return_location = (&body_236);
}
/* _parse-num */
void body_235() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  apply((&function_570));
}
void body_237();
pointer global_c102c110c95c49c51c53;
void function_571() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_572() {
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
  apply((&function_571));
}
void function_573() {
  increment_count(env);
  val = new_function((&function_572), env);
  pop_function();
}
/* fn_135 */
void body_236() {
  increment_count(env);
  val = new_function((&function_573), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  return_location = (&body_237);
}
void body_238();
pointer global_c95c114c101c97c100c45c110c117c109;
void function_574() {
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  return_location = (&body_238);
}
/* _read-num */
void body_237() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  apply((&function_574));
}
void body_239();
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
pointer global_c102c110c95c49c51c54;
void function_575() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_576() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_575));
}
void function_577() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_576));
}
void function_578() {
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
  apply((&function_577));
}
void function_579() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_578));
}
void function_580() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_579));
}
void function_581() {
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
  apply((&function_580));
}
void function_582() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_581));
}
void function_583() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_582));
}
void function_584() {
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
  apply((&function_583));
}
void function_585() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_584));
}
void function_586() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_585));
}
void function_587() {
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
  apply((&function_586));
}
void function_588() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_587));
}
void function_589() {
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
  apply((&function_588));
}
void function_590() {
  increment_count(env);
  val = new_function((&function_589), env);
  pop_function();
}
/* fn_136 */
void body_238() {
  increment_count(env);
  val = new_function((&function_590), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  return_location = (&body_239);
}
void body_240();
void function_591() {
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  return_location = (&body_240);
}
/* _parse-symbol */
void body_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  apply((&function_591));
}
void body_241();
pointer global_c102c110c95c49c51c55;
void function_592() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_593() {
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
  apply((&function_592));
}
void function_594() {
  increment_count(env);
  val = new_function((&function_593), env);
  pop_function();
}
/* fn_137 */
void body_240() {
  increment_count(env);
  val = new_function((&function_594), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  return_location = (&body_241);
}
void body_242();
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
void function_595() {
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  return_location = (&body_242);
}
/* _read-symbol */
void body_241() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  apply((&function_595));
}
void body_243();
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
pointer global_c102c110c95c49c51c56;
void function_596() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_597() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_596));
}
void function_598() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_597));
}
void function_599() {
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
  apply((&function_598));
}
void function_600() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_599));
}
void function_601() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_600));
}
void function_602() {
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
  apply((&function_601));
}
void function_603() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_602));
}
void function_604() {
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
  apply((&function_603));
}
void function_605() {
  increment_count(env);
  val = new_function((&function_604), env);
  pop_function();
}
/* fn_138 */
void body_242() {
  increment_count(env);
  val = new_function((&function_605), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  return_location = (&body_243);
}
void body_244();
void function_606() {
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  return_location = (&body_244);
}
/* _parse-string */
void body_243() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  apply((&function_606));
}
void body_245();
pointer global_c102c110c95c49c51c57;
void function_607() {
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
void function_608() {
  increment_count(env);
  val = new_function((&function_607), env);
  pop_function();
}
/* fn_139 */
void body_244() {
  increment_count(env);
  val = new_function((&function_608), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  return_location = (&body_245);
}
void body_246();
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_609() {
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  return_location = (&body_246);
}
/* _quote-parser */
void body_245() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c57); /* fn_139 */
  apply((&function_609));
}
void body_247();
pointer global_c102c110c95c49c52c48;
void function_610() {
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
void function_611() {
  increment_count(env);
  val = new_function((&function_610), env);
  pop_function();
}
/* fn_140 */
void body_246() {
  increment_count(env);
  val = new_function((&function_611), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  return_location = (&body_247);
}
void body_248();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_612() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  return_location = (&body_248);
}
/* _quasiquote-parser */
void body_247() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
  apply((&function_612));
}
void body_249();
pointer global_c102c110c95c49c52c49;
void function_613() {
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
void function_614() {
  increment_count(env);
  val = new_function((&function_613), env);
  pop_function();
}
/* fn_141 */
void body_248() {
  increment_count(env);
  val = new_function((&function_614), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  return_location = (&body_249);
}
void body_250();
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_615() {
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  return_location = (&body_250);
}
/* _unquote-parser */
void body_249() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
  apply((&function_615));
}
void body_251();
pointer global_c102c110c95c49c52c50 = NIL; /* fn_142 */
pointer global_c102c110c95c49c52c51;
void function_616() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  top_level_apply();
}
void function_617() {
  increment_count(env);
  val = new_function((&function_616), env);
  pop_function();
}
/* fn_143 */
void body_250() {
  increment_count(env);
  val = new_function((&function_617), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  return_location = (&body_251);
}
void body_252();
pointer global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
void function_618() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_619() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_618));
}
void function_620() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_619));
}
void function_621() {
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
  apply((&function_620));
}
void function_622() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_621));
}
void function_623() {
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
  apply((&function_622));
}
void function_624() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_623));
}
void function_625() {
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  apply((&function_624));
}
void function_626() {
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
  apply((&function_625));
}
void function_627() {
  increment_count(env);
  val = new_function((&function_626), env);
  pop_function();
}
/* fn_142 */
void body_251() {
  increment_count(env);
  val = new_function((&function_627), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  return_location = (&body_252);
}
void body_253();
void function_628() {
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  return_location = (&body_253);
}
/* _comment */
void body_252() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  apply((&function_628));
}
void body_254();
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
pointer global_c102c110c95c49c52c52;
void function_629() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_630() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_629));
}
void function_631() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_630));
}
void function_632() {
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
  apply((&function_631));
}
void function_633() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_632));
}
void function_634() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_633));
}
void function_635() {
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
  apply((&function_634));
}
void function_636() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_635));
}
void function_637() {
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
  apply((&function_636));
}
void function_638() {
  increment_count(env);
  val = new_function((&function_637), env);
  pop_function();
}
/* fn_144 */
void body_253() {
  increment_count(env);
  val = new_function((&function_638), env);
  global_c102c110c95c49c52c52 = val; /* fn_144 */
  return_location = (&body_254);
}
void body_255();
void function_639() {
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  return_location = (&body_255);
}
/* _parse-paren */
void body_254() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c52); /* fn_144 */
  apply((&function_639));
}
void body_256();
pointer global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
pointer global_c102c110c95c49c52c53;
void function_640() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_641() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
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
  apply((&function_642));
}
void function_644() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_643));
}
void function_645() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_644));
}
void function_646() {
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
  apply((&function_645));
}
void function_647() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_646));
}
void function_648() {
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
  apply((&function_647));
}
void function_649() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_648));
}
void function_650() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_649));
}
void function_651() {
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
  apply((&function_650));
}
void function_652() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_651));
}
void function_653() {
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
  apply((&function_652));
}
void function_654() {
  increment_count(env);
  val = new_function((&function_653), env);
  pop_function();
}
/* fn_145 */
void body_255() {
  increment_count(env);
  val = new_function((&function_654), env);
  global_c102c110c95c49c52c53 = val; /* fn_145 */
  return_location = (&body_256);
}
void body_257();
void function_655() {
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  return_location = (&body_257);
}
/* _parse-pair */
void body_256() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c53); /* fn_145 */
  apply((&function_655));
}
void body_258();
pointer global_c102c110c95c49c52c54;
void function_656() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_657() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_656));
}
void function_658() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_657));
}
void function_659() {
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
  apply((&function_658));
}
void function_660() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_659));
}
void function_661() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_660));
}
void function_662() {
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
  apply((&function_661));
}
void function_663() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_662));
}
void function_664() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_663));
}
void function_665() {
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
  apply((&function_664));
}
void function_666() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_665));
}
void function_667() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_666));
}
void function_668() {
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
  apply((&function_667));
}
void function_669() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_668));
}
void function_670() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_669));
}
void function_671() {
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
  apply((&function_670));
}
void function_672() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_671));
}
void function_673() {
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
  apply((&function_672));
}
void function_674() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_673));
}
void function_675() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_674));
}
void function_676() {
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
  apply((&function_675));
}
void function_677() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_676));
}
void function_678() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_677));
}
void function_679() {
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
  apply((&function_678));
}
void function_680() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_679));
}
void function_681() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_680));
}
void function_682() {
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
  apply((&function_681));
}
void function_683() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_682));
}
void function_684() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_683));
}
void function_685() {
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
  apply((&function_684));
}
void function_686() {
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
  apply((&function_685));
}
void function_687() {
  increment_count(env);
  val = new_function((&function_686), env);
  pop_function();
}
/* fn_146 */
void body_257() {
  increment_count(env);
  val = new_function((&function_687), env);
  global_c102c110c95c49c52c54 = val; /* fn_146 */
  return_location = (&body_258);
}
void body_259();
void function_688() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_259);
}
/* _parse-expr */
void body_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c54); /* fn_146 */
  apply((&function_688));
}
void body_260();
pointer global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* ___parse-pair */
pointer global_c102c110c95c49c52c55;
void function_689() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_690() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_689));
}
void function_691() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_690));
}
void function_692() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ___parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_691));
}
void function_693() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_692));
}
void function_694() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_693));
}
void function_695() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ___parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c109c101c110c116); /* ___comment */
  apply((&function_694));
}
void function_696() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_695));
}
void function_697() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c100c111c110c101); /* ___done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_696));
}
void function_698() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_697));
}
void function_699() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_698));
}
void function_700() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ___parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c105c114c115c116); /* ___first */
  apply((&function_699));
}
void function_701() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_700));
}
void function_702() {
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
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ___parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c101c113); /* ___seq */
  apply((&function_701));
}
void function_703() {
  increment_count(env);
  val = new_function((&function_702), env);
  pop_function();
}
/* fn_147 */
void body_259() {
  increment_count(env);
  val = new_function((&function_703), env);
  global_c102c110c95c49c52c55 = val; /* fn_147 */
  return_location = (&body_260);
}
void body_261();
void function_704() {
  global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* ___parse-pair */
  return_location = (&body_261);
}
/* ___parse-pair */
void body_260() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c55); /* fn_147 */
  apply((&function_704));
}
void body_262();
pointer global_c95c95c108c95c50c48;
/* __l_20 */
void body_261() {
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
  global_c95c95c108c95c50c48 = val; /* __l_20 */
  return_location = (&body_262);
}
void body_263();
pointer global_c95c95c108c95c50c49;
/* __l_21 */
void body_262() {
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
  global_c95c95c108c95c50c49 = val; /* __l_21 */
  return_location = (&body_263);
}
void body_264();
pointer global_c102c110c95c49c52c56;
void function_705() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_706() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c104c111c105c99c101); /* ___choice */
  apply((&function_705));
}
void function_707() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_706));
}
void function_708() {
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
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_707));
}
void function_709() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_708));
}
void function_710() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_709));
}
void function_711() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ___parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* ___quote-parser */
  apply((&function_710));
}
void function_712() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_711));
}
void function_713() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_712));
}
void function_714() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* ___quote-parser */
  apply((&function_713));
}
void function_715() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_714));
}
void function_716() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_715));
}
void function_717() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114); /* ___quasiquote-parser */
  apply((&function_716));
}
void function_718() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_717));
}
void function_719() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_718));
}
void function_720() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114); /* ___unquote-parser */
  apply((&function_719));
}
void function_721() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_720));
}
void function_722() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ___parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_721));
}
void function_723() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_722));
}
void function_724() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_723));
}
void function_725() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50c48); /* __l_20 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c97c105c108); /* ___fail */
  apply((&function_724));
}
void function_726() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_725));
}
void function_727() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_726));
}
void function_728() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50c49); /* __l_21 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c97c105c108); /* ___fail */
  apply((&function_727));
}
void function_729() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_728));
}
void function_730() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c116c99c104); /* ___match */
  apply((&function_729));
}
void function_731() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c109c101c110c116); /* ___comment */
  apply((&function_730));
}
void function_732() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c97c115c101); /* ___case */
  apply((&function_731));
}
void function_733() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c101c101c107); /* ___peek */
  apply((&function_732));
}
void function_734() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c114c101c97c100c45c110c117c109); /* ___read-num */
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
  increment_count(val = global_c95c95c95c105c110c116c101c114c118c97c108); /* ___interval */
  apply((&function_733));
}
void function_735() {
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
  increment_count(val = global_c95c95c95c114c101c97c100c45c115c121c109c98c111c108); /* ___read-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c97c117c108c116); /* ___default */
  apply((&function_734));
}
void function_736() {
  increment_count(env);
  val = new_function((&function_735), env);
  pop_function();
}
/* fn_148 */
void body_263() {
  increment_count(env);
  val = new_function((&function_736), env);
  global_c102c110c95c49c52c56 = val; /* fn_148 */
  return_location = (&body_264);
}
void body_265();
void function_737() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_265);
}
/* _parse-expr */
void body_264() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c56); /* fn_148 */
  apply((&function_737));
}
void body_266();
pointer global_c102c110c95c49c53c52 = NIL; /* fn_154 */
pointer global_c102c110c95c49c53c51 = NIL; /* fn_153 */
pointer global_c102c110c95c49c53c49 = NIL; /* fn_151 */
pointer global_c102c110c95c49c53c48 = NIL; /* fn_150 */
pointer global_c102c110c95c49c52c57 = NIL; /* fn_149 */
pointer global_c102c110c95c49c53c53;
void function_738() {
  top_level_apply();
}
void function_739() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c119c97c108c107); /* ___walk */
  apply((&function_738));
}
void function_740() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c57); /* fn_149 */
  apply((&function_739));
}
void function_741() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c48); /* fn_150 */
  apply((&function_740));
}
void function_742() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c49); /* fn_151 */
  apply((&function_741));
}
void function_743() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c51); /* fn_153 */
  apply((&function_742));
}
void function_744() {
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
  increment_count(val = global_c102c110c95c49c53c52); /* fn_154 */
  apply((&function_743));
}
void function_745() {
  increment_count(env);
  val = new_function((&function_744), env);
  pop_function();
}
/* fn_155 */
void body_265() {
  increment_count(env);
  val = new_function((&function_745), env);
  global_c102c110c95c49c53c53 = val; /* fn_155 */
  return_location = (&body_266);
}
void body_267();
void function_746() {
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
void function_747() {
  increment_count(env);
  val = new_function((&function_746), env);
  pop_function();
}
/* fn_149 */
void body_266() {
  increment_count(env);
  val = new_function((&function_747), env);
  global_c102c110c95c49c52c57 = val; /* fn_149 */
  return_location = (&body_267);
}
void body_268();
void function_748() {
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
void function_749() {
  increment_count(env);
  val = new_function((&function_748), env);
  pop_function();
}
/* fn_150 */
void body_267() {
  increment_count(env);
  val = new_function((&function_749), env);
  global_c102c110c95c49c53c48 = val; /* fn_150 */
  return_location = (&body_268);
}
void body_269();
void function_750() {
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
void function_751() {
  increment_count(env);
  val = new_function((&function_750), env);
  pop_function();
}
/* fn_151 */
void body_268() {
  increment_count(env);
  val = new_function((&function_751), env);
  global_c102c110c95c49c53c49 = val; /* fn_151 */
  return_location = (&body_269);
}
void body_270();
pointer global_c102c110c95c49c53c50 = NIL; /* fn_152 */
void function_752() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c53c50); /* fn_152 */
  top_level_apply();
}
void function_753() {
  increment_count(env);
  val = new_function((&function_752), env);
  pop_function();
}
/* fn_153 */
void body_269() {
  increment_count(env);
  val = new_function((&function_753), env);
  global_c102c110c95c49c53c51 = val; /* fn_153 */
  return_location = (&body_270);
}
void body_271();
void function_754() {
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
void function_755() {
  increment_count(env);
  val = new_function((&function_754), env);
  pop_function();
}
/* fn_152 */
void body_270() {
  increment_count(env);
  val = new_function((&function_755), env);
  global_c102c110c95c49c53c50 = val; /* fn_152 */
  return_location = (&body_271);
}
void body_272();
void function_756() {
  increment_count(val = global_c95c105c100); /* _id */
  pop_function();
}
void function_757() {
  increment_count(env);
  val = new_function((&function_756), env);
  pop_function();
}
/* fn_154 */
void body_271() {
  increment_count(env);
  val = new_function((&function_757), env);
  global_c102c110c95c49c53c52 = val; /* fn_154 */
  return_location = (&body_272);
}
void body_273();
pointer global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
void function_758() {
  global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* ___build-num-str */
  return_location = (&body_273);
}
/* ___build-num-str */
void body_272() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c53); /* fn_155 */
  apply((&function_758));
}
void body_274();
pointer global_c95c95c108c95c50c50;
/* __l_22 */
void body_273() {
  val = NIL;
  global_c95c95c108c95c50c50 = val; /* __l_22 */
  return_location = (&body_274);
}
void body_275();
pointer global_c95c95c108c95c50c51;
/* __l_23 */
void body_274() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c51 = val; /* __l_23 */
  return_location = (&body_275);
}
void body_276();
pointer global_c95c95c108c95c50c52;
/* __l_24 */
void body_275() {
  val = NIL;
  global_c95c95c108c95c50c52 = val; /* __l_24 */
  return_location = (&body_276);
}
void body_277();
pointer global_c102c110c95c49c53c54;
void function_759() {
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
void function_760() {
  apply((&function_759));
}
void function_761() {
  top_level_apply();
}
void function_762() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c50c51); /* __l_23 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c50c52); /* __l_24 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* ___build-num-str */
    apply((&function_761));
  }
}
void function_763() {
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
    increment_count(val = global_c95c95c108c95c50c50); /* __l_22 */
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
    increment_count(val = global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* ___build-num-str */
    apply((&function_760));
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_762));
  }
}
void function_764() {
  increment_count(env);
  val = new_function((&function_763), env);
  pop_function();
}
/* fn_156 */
void body_276() {
  increment_count(env);
  val = new_function((&function_764), env);
  global_c102c110c95c49c53c54 = val; /* fn_156 */
  return_location = (&body_277);
}
void body_278();
pointer global_c95c95c95c112c114c105c110c116c45c110c117c109;
void function_765() {
  global_c95c95c95c112c114c105c110c116c45c110c117c109 = val; /* ___print-num */
  return_location = (&body_278);
}
/* ___print-num */
void body_277() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c54); /* fn_156 */
  apply((&function_765));
}
void body_279();
pointer global_c95c95c108c95c50c53;
/* __l_25 */
void body_278() {
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
  global_c95c95c108c95c50c53 = val; /* __l_25 */
  return_location = (&body_279);
}
void body_280();
pointer global_c102c110c95c49c53c55;
void function_766() {
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
    increment_count(val = global_c95c95c108c95c50c53); /* __l_25 */
    pop_function();
  }
}
void function_767() {
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
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c110c117c109); /* ___print-num */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    apply((&function_766));
  }
}
void function_768() {
  increment_count(env);
  val = new_function((&function_767), env);
  pop_function();
}
/* fn_157 */
void body_279() {
  increment_count(env);
  val = new_function((&function_768), env);
  global_c102c110c95c49c53c55 = val; /* fn_157 */
  return_location = (&body_280);
}
void body_281();
pointer global_c95c95c95c112c114c105c110c116c45c97c116c111c109;
void function_769() {
  global_c95c95c95c112c114c105c110c116c45c97c116c111c109 = val; /* ___print-atom */
  return_location = (&body_281);
}
/* ___print-atom */
void body_280() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c55); /* fn_157 */
  apply((&function_769));
}
void body_282();
pointer global_c95c95c108c95c50c54;
/* __l_26 */
void body_281() {
  val = NIL;
  global_c95c95c108c95c50c54 = val; /* __l_26 */
  return_location = (&body_282);
}
void body_283();
pointer global_c95c95c108c95c50c55;
/* __l_27 */
void body_282() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c55 = val; /* __l_27 */
  return_location = (&body_283);
}
void body_284();
pointer global_c95c95c108c95c50c56;
/* __l_28 */
void body_283() {
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
  global_c95c95c108c95c50c56 = val; /* __l_28 */
  return_location = (&body_284);
}
void body_285();
pointer global_c95c95c108c95c50c57;
/* __l_29 */
void body_284() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c57 = val; /* __l_29 */
  return_location = (&body_285);
}
void body_286();
pointer global_c95c95c108c95c51c48;
/* __l_30 */
void body_285() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c48 = val; /* __l_30 */
  return_location = (&body_286);
}
void body_287();
pointer global_c95c95c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* ___print-tail */
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* ___print-with-suffix */
pointer global_c102c110c95c49c53c56;
void function_770() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c56); /* __l_28 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_771() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c48); /* __l_30 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_772() {
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
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ___print-with-suffix */
  apply((&function_771));
}
void function_773() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c57); /* __l_29 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ___print-atom */
    apply((&function_770));
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
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c116c97c105c108); /* ___print-tail */
    apply((&function_772));
  }
}
void function_774() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c55); /* __l_27 */
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_773));
  }
}
void function_775() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50c54); /* __l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_774));
}
void function_776() {
  increment_count(env);
  val = new_function((&function_775), env);
  pop_function();
}
/* fn_158 */
void body_286() {
  increment_count(env);
  val = new_function((&function_776), env);
  global_c102c110c95c49c53c56 = val; /* fn_158 */
  return_location = (&body_287);
}
void body_288();
void function_777() {
  global_c95c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* ___print-tail */
  return_location = (&body_288);
}
/* ___print-tail */
void body_287() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c56); /* fn_158 */
  apply((&function_777));
}
void body_289();
pointer global_c95c95c108c95c51c49;
/* __l_31 */
void body_288() {
  val = NIL;
  global_c95c95c108c95c51c49 = val; /* __l_31 */
  return_location = (&body_289);
}
void body_290();
pointer global_c95c95c108c95c51c50;
/* __l_32 */
void body_289() {
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
  global_c95c95c108c95c51c50 = val; /* __l_32 */
  return_location = (&body_290);
}
void body_291();
pointer global_c95c95c108c95c51c51;
/* __l_33 */
void body_290() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c51 = val; /* __l_33 */
  return_location = (&body_291);
}
void body_292();
pointer global_c102c110c95c49c53c57;
void function_778() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_779() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c51); /* __l_33 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_780() {
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
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ___print-with-suffix */
  apply((&function_779));
}
void function_781() {
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
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ___print-atom */
    apply((&function_778));
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
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c116c97c105c108); /* ___print-tail */
    apply((&function_780));
  }
}
void function_782() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c50); /* __l_32 */
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_781));
  }
}
void function_783() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c51c49); /* __l_31 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_782));
}
void function_784() {
  increment_count(env);
  val = new_function((&function_783), env);
  pop_function();
}
/* fn_159 */
void body_291() {
  increment_count(env);
  val = new_function((&function_784), env);
  global_c102c110c95c49c53c57 = val; /* fn_159 */
  return_location = (&body_292);
}
void body_293();
void function_785() {
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* ___print-with-suffix */
  return_location = (&body_293);
}
/* ___print-with-suffix */
void body_292() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c57); /* fn_159 */
  apply((&function_785));
}
void body_294();
pointer global_c95c95c108c95c51c52;
/* __l_34 */
void body_293() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c52 = val; /* __l_34 */
  return_location = (&body_294);
}
void body_295();
pointer global_c102c110c95c49c54c48;
void function_786() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c51c52); /* __l_34 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ___print-with-suffix */
  top_level_apply();
}
void function_787() {
  increment_count(env);
  val = new_function((&function_786), env);
  pop_function();
}
/* fn_160 */
void body_294() {
  increment_count(env);
  val = new_function((&function_787), env);
  global_c102c110c95c49c54c48 = val; /* fn_160 */
  return_location = (&body_295);
}
void body_296();
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
void function_788() {
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* ___print-with-newline */
  return_location = (&body_296);
}
/* ___print-with-newline */
void body_295() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c48); /* fn_160 */
  apply((&function_788));
}
void body_297();
pointer global_c95c95c108c95c51c53;
/* __l_35 */
void body_296() {
  val = NIL;
  global_c95c95c108c95c51c53 = val; /* __l_35 */
  return_location = (&body_297);
}
void body_298();
pointer global_c102c110c95c49c54c49;
void function_789() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c51c53); /* __l_35 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ___print-with-suffix */
  top_level_apply();
}
void function_790() {
  increment_count(env);
  val = new_function((&function_789), env);
  pop_function();
}
/* fn_161 */
void body_297() {
  increment_count(env);
  val = new_function((&function_790), env);
  global_c102c110c95c49c54c49 = val; /* fn_161 */
  return_location = (&body_298);
}
void body_299();
pointer global_c95c112c114c105c110c116;
void function_791() {
  global_c95c112c114c105c110c116 = val; /* _print */
  return_location = (&body_299);
}
/* _print */
void body_298() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c49); /* fn_161 */
  apply((&function_791));
}
void body_300();
pointer global_c102c110c95c49c54c50;
void function_792() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_793() {
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
  apply((&function_792));
}
void function_794() {
  increment_count(env);
  val = new_function((&function_793), env);
  pop_function();
}
/* fn_162 */
void body_299() {
  increment_count(env);
  val = new_function((&function_794), env);
  global_c102c110c95c49c54c50 = val; /* fn_162 */
  return_location = (&body_300);
}
void body_301();
pointer global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
void function_795() {
  global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ___map-to-stderr */
  return_location = (&body_301);
}
void function_796() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_795));
}
/* ___map-to-stderr */
void body_300() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c50); /* fn_162 */
  apply((&function_796));
}
void body_302();
pointer global_c95c95c108c95c51c54;
/* __l_36 */
void body_301() {
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
  global_c95c95c108c95c51c54 = val; /* __l_36 */
  return_location = (&body_302);
}
void body_303();
pointer global_c95c95c108c95c51c55;
/* __l_37 */
void body_302() {
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
  global_c95c95c108c95c51c55 = val; /* __l_37 */
  return_location = (&body_303);
}
void body_304();
pointer global_c95c95c108c95c51c56;
/* __l_38 */
void body_303() {
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
  global_c95c95c108c95c51c56 = val; /* __l_38 */
  return_location = (&body_304);
}
void body_305();
pointer global_c95c95c108c95c51c57;
/* __l_39 */
void body_304() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c57 = val; /* __l_39 */
  return_location = (&body_305);
}
void body_306();
pointer global_c102c110c95c49c54c51;
void function_797() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_798() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c55); /* __l_37 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c51c54); /* __l_36 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_797));
}
void function_799() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c51c57); /* __l_39 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51c56); /* __l_38 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    apply((&function_798));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_800() {
  increment_count(env);
  val = new_function((&function_799), env);
  pop_function();
}
/* fn_163 */
void body_305() {
  increment_count(env);
  val = new_function((&function_800), env);
  global_c102c110c95c49c54c51 = val; /* fn_163 */
  return_location = (&body_306);
}
void body_307();
pointer global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
void function_801() {
  global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ___print-warnings */
  return_location = (&body_307);
}
/* ___print-warnings */
void body_306() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c51); /* fn_163 */
  apply((&function_801));
}
void body_308();
pointer global_c95c95c108c95c52c48;
/* __l_40 */
void body_307() {
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
  global_c95c95c108c95c52c48 = val; /* __l_40 */
  return_location = (&body_308);
}
void body_309();
pointer global_c95c95c108c95c52c49;
/* __l_41 */
void body_308() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52c49 = val; /* __l_41 */
  return_location = (&body_309);
}
void body_310();
pointer global_c102c110c95c49c54c52;
void function_802() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_803() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c52c49); /* __l_41 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c52c48); /* __l_40 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_802));
}
void function_804() {
  increment_count(env);
  val = new_function((&function_803), env);
  pop_function();
}
/* fn_164 */
void body_309() {
  increment_count(env);
  val = new_function((&function_804), env);
  global_c102c110c95c49c54c52 = val; /* fn_164 */
  return_location = (&body_310);
}
void body_311();
pointer global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
void function_805() {
  global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ___print-error */
  return_location = (&body_311);
}
/* ___print-error */
void body_310() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c52); /* fn_164 */
  apply((&function_805));
}
void body_312();
pointer global_c95c95c108c95c52c50;
/* __l_42 */
void body_311() {
  val = NIL;
  push_args();
  args = val;
  val = -35;
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  val = -34;
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  val = -39;
  args = cons(val, args);
  val = -40;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52c50 = val; /* __l_42 */
  return_location = (&body_312);
}
void body_313();
pointer global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ___special-forms */
void body_312() {
  increment_count(val = global_c95c95c108c95c52c50); /* __l_42 */
  global_c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ___special-forms */
  return_location = (&body_313);
}
void body_314();
pointer global_c95c95c108c95c52c51;
/* __l_43 */
void body_313() {
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
  global_c95c95c108c95c52c51 = val; /* __l_43 */
  return_location = (&body_314);
}
void body_315();
pointer global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* ___supported-builtins */
void body_314() {
  increment_count(val = global_c95c95c108c95c52c51); /* __l_43 */
  global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* ___supported-builtins */
  return_location = (&body_315);
}
void body_316();
pointer global_c95c95c108c95c52c52;
/* __l_44 */
void body_315() {
  val = NIL;
  global_c95c95c108c95c52c52 = val; /* __l_44 */
  return_location = (&body_316);
}
void body_317();
pointer global_c95c95c95c102c108c97c116c116c101c110 = NIL; /* ___flatten */
pointer global_c102c110c95c49c54c53;
void function_806() {
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
void function_807() {
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
    apply((&function_806));
  }
}
void function_808() {
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
    apply((&function_807));
  }
}
void function_809() {
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
    apply((&function_808));
  }
}
void function_810() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c52c52); /* __l_44 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_809));
}
void function_811() {
  increment_count(env);
  val = new_function((&function_810), env);
  pop_function();
}
/* fn_165 */
void body_316() {
  increment_count(env);
  val = new_function((&function_811), env);
  global_c102c110c95c49c54c53 = val; /* fn_165 */
  return_location = (&body_317);
}
void body_318();
void function_812() {
  global_c95c95c95c102c108c97c116c116c101c110 = val; /* ___flatten */
  return_location = (&body_318);
}
/* ___flatten */
void body_317() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c53); /* fn_165 */
  apply((&function_812));
}
void body_319();
pointer global_c95c95c108c95c52c53;
/* __l_45 */
void body_318() {
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
  global_c95c95c108c95c52c53 = val; /* __l_45 */
  return_location = (&body_319);
}
void body_320();
pointer global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115;
/* ___supported-library-procedures */
void body_319() {
  increment_count(val = global_c95c95c108c95c52c53); /* __l_45 */
  global_c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 = val; /* ___supported-library-procedures */
  return_location = (&body_320);
}
void body_321();
pointer global_c95c95c108c95c52c54;
/* __l_46 */
void body_320() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52c54 = val; /* __l_46 */
  return_location = (&body_321);
}
void body_322();
pointer global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ___escape-symbols */
pointer global_c102c110c95c49c54c54;
void function_813() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_814() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c52c54); /* __l_46 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_813));
}
void function_815() {
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
    apply((&function_814));
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_816() {
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
    apply((&function_815));
  }
}
void function_817() {
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
    apply((&function_816));
  }
}
void function_818() {
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
    apply((&function_817));
  }
}
void function_819() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_820() {
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
  apply((&function_819));
}
void function_821() {
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
    apply((&function_818));
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
    apply((&function_820));
  }
}
void function_822() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_821));
}
void function_823() {
  increment_count(env);
  val = new_function((&function_822), env);
  pop_function();
}
/* fn_166 */
void body_321() {
  increment_count(env);
  val = new_function((&function_823), env);
  global_c102c110c95c49c54c54 = val; /* fn_166 */
  return_location = (&body_322);
}
void body_323();
void function_824() {
  global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ___escape-symbols */
  return_location = (&body_323);
}
/* ___escape-symbols */
void body_322() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c54); /* fn_166 */
  apply((&function_824));
}
void body_324();
pointer global_c95c95c108c95c52c55;
/* __l_47 */
void body_323() {
  val = NIL;
  global_c95c95c108c95c52c55 = val; /* __l_47 */
  return_location = (&body_324);
}
void body_325();
pointer global_c95c95c108c95c52c56;
/* __l_48 */
void body_324() {
  val = NIL;
  global_c95c95c108c95c52c56 = val; /* __l_48 */
  return_location = (&body_325);
}
void body_326();
pointer global_c95c95c108c95c52c57;
/* __l_49 */
void body_325() {
  val = NIL;
  global_c95c95c108c95c52c57 = val; /* __l_49 */
  return_location = (&body_326);
}
void body_327();
pointer global_c95c95c108c95c53c48;
/* __l_50 */
void body_326() {
  val = NIL;
  global_c95c95c108c95c53c48 = val; /* __l_50 */
  return_location = (&body_327);
}
void body_328();
pointer global_c95c95c108c95c53c49;
/* __l_51 */
void body_327() {
  val = NIL;
  global_c95c95c108c95c53c49 = val; /* __l_51 */
  return_location = (&body_328);
}
void body_329();
pointer global_c95c95c108c95c53c50;
/* __l_52 */
void body_328() {
  val = NIL;
  global_c95c95c108c95c53c50 = val; /* __l_52 */
  return_location = (&body_329);
}
void body_330();
pointer global_c95c95c108c95c53c51;
/* __l_53 */
void body_329() {
  val = NIL;
  global_c95c95c108c95c53c51 = val; /* __l_53 */
  return_location = (&body_330);
}
void body_331();
pointer global_c95c95c108c95c53c52;
/* __l_54 */
void body_330() {
  val = NIL;
  global_c95c95c108c95c53c52 = val; /* __l_54 */
  return_location = (&body_331);
}
void body_332();
pointer global_c95c95c108c95c53c53;
/* __l_55 */
void body_331() {
  val = NIL;
  global_c95c95c108c95c53c53 = val; /* __l_55 */
  return_location = (&body_332);
}
void body_333();
pointer global_c95c95c108c95c53c54;
/* __l_56 */
void body_332() {
  val = NIL;
  global_c95c95c108c95c53c54 = val; /* __l_56 */
  return_location = (&body_333);
}
void body_334();
pointer global_c95c95c108c95c53c55;
/* __l_57 */
void body_333() {
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
  global_c95c95c108c95c53c55 = val; /* __l_57 */
  return_location = (&body_334);
}
void body_335();
pointer global_c95c95c108c95c53c56;
/* __l_58 */
void body_334() {
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
  global_c95c95c108c95c53c56 = val; /* __l_58 */
  return_location = (&body_335);
}
void body_336();
pointer global_c102c110c95c49c54c55;
void function_825() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c52c55); /* __l_47 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_826() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c54); /* __l_56 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c53); /* __l_55 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_827() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53c55); /* __l_57 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_826));
}
void function_828() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c52); /* __l_54 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c51); /* __l_53 */
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
    increment_count(val = global_c95c95c108c95c53c56); /* __l_58 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    apply((&function_827));
  }
}
void function_829() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c50); /* __l_52 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c49); /* __l_51 */
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
    apply((&function_828));
  }
}
void function_830() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c53c48); /* __l_50 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c52c57); /* __l_49 */
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
    apply((&function_829));
  }
}
void function_831() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c52c56); /* __l_48 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
    apply((&function_825));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115); /* ___supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_830));
  }
}
void function_832() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  apply((&function_831));
}
void function_833() {
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
  apply((&function_832));
}
void function_834() {
  increment_count(env);
  val = new_function((&function_833), env);
  pop_function();
}
/* fn_167 */
void body_335() {
  increment_count(env);
  val = new_function((&function_834), env);
  global_c102c110c95c49c54c55 = val; /* fn_167 */
  return_location = (&body_336);
}
void body_337();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100;
void function_835() {
  global_c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* ___compile-find */
  return_location = (&body_337);
}
/* ___compile-find */
void body_336() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c55); /* fn_167 */
  apply((&function_835));
}
void body_338();
pointer global_c95c95c108c95c53c57;
/* __l_59 */
void body_337() {
  val = NIL;
  global_c95c95c108c95c53c57 = val; /* __l_59 */
  return_location = (&body_338);
}
void body_339();
pointer global_c95c95c108c95c54c48;
/* __l_60 */
void body_338() {
  val = -40;
  global_c95c95c108c95c54c48 = val; /* __l_60 */
  return_location = (&body_339);
}
void body_340();
pointer global_c95c95c108c95c54c49;
/* __l_61 */
void body_339() {
  val = CONS;
  global_c95c95c108c95c54c49 = val; /* __l_61 */
  return_location = (&body_340);
}
void body_341();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = NIL; /* ___rewrite-quote */
pointer global_c102c110c95c49c54c56;
void function_836() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c49); /* __l_61 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_837() {
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
  apply((&function_836));
}
void function_838() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c54c48); /* __l_60 */
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
    apply((&function_837));
  }
}
void function_839() {
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
      apply((&function_838));
    }
  }
}
void function_840() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c53c57); /* __l_59 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_839));
}
void function_841() {
  increment_count(env);
  val = new_function((&function_840), env);
  pop_function();
}
/* fn_168 */
void body_340() {
  increment_count(env);
  val = new_function((&function_841), env);
  global_c102c110c95c49c54c56 = val; /* fn_168 */
  return_location = (&body_341);
}
void body_342();
void function_842() {
  global_c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* ___rewrite-quote */
  return_location = (&body_342);
}
/* ___rewrite-quote */
void body_341() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c56); /* fn_168 */
  apply((&function_842));
}
void body_343();
pointer global_c95c95c108c95c54c50;
/* __l_62 */
void body_342() {
  val = NIL;
  global_c95c95c108c95c54c50 = val; /* __l_62 */
  return_location = (&body_343);
}
void body_344();
pointer global_c95c95c108c95c54c51;
/* __l_63 */
void body_343() {
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
  global_c95c95c108c95c54c51 = val; /* __l_63 */
  return_location = (&body_344);
}
void body_345();
pointer global_c102c110c95c49c54c57 = NIL; /* fn_169 */
pointer global_c102c110c95c49c55c48;
void function_843() {
  top_level_apply();
}
void function_844() {
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
  increment_count(val = global_c102c110c95c49c54c57); /* fn_169 */
  apply((&function_843));
}
void function_845() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  apply((&function_844));
}
void function_846() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c51); /* __l_63 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_845));
}
void function_847() {
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
  apply((&function_846));
}
void function_848() {
  increment_count(env);
  val = new_function((&function_847), env);
  pop_function();
}
/* fn_170 */
void body_344() {
  increment_count(env);
  val = new_function((&function_848), env);
  global_c102c110c95c49c55c48 = val; /* fn_170 */
  return_location = (&body_345);
}
void body_346();
void function_849() {
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
  increment_count(val = global_c95c95c108c95c54c50); /* __l_62 */
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
void function_850() {
  increment_count(env);
  val = new_function((&function_849), env);
  pop_function();
}
/* fn_169 */
void body_345() {
  increment_count(env);
  val = new_function((&function_850), env);
  global_c102c110c95c49c54c57 = val; /* fn_169 */
  return_location = (&body_346);
}
void body_347();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101;
void function_851() {
  global_c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* ___compile-quote */
  return_location = (&body_347);
}
/* ___compile-quote */
void body_346() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c48); /* fn_170 */
  apply((&function_851));
}
void body_348();
pointer global_c95c95c108c95c54c52;
/* __l_64 */
void body_347() {
  val = NIL;
  global_c95c95c108c95c54c52 = val; /* __l_64 */
  return_location = (&body_348);
}
void body_349();
pointer global_c95c95c108c95c54c53;
/* __l_65 */
void body_348() {
  val = NIL;
  global_c95c95c108c95c54c53 = val; /* __l_65 */
  return_location = (&body_349);
}
void body_350();
pointer global_c95c95c108c95c54c54;
/* __l_66 */
void body_349() {
  val = NIL;
  global_c95c95c108c95c54c54 = val; /* __l_66 */
  return_location = (&body_350);
}
void body_351();
pointer global_c95c95c108c95c54c55;
/* __l_67 */
void body_350() {
  val = -40;
  global_c95c95c108c95c54c55 = val; /* __l_67 */
  return_location = (&body_351);
}
void body_352();
pointer global_c95c95c108c95c54c56;
/* __l_68 */
void body_351() {
  val = NIL;
  global_c95c95c108c95c54c56 = val; /* __l_68 */
  return_location = (&body_352);
}
void body_353();
pointer global_c95c95c108c95c54c57;
/* __l_69 */
void body_352() {
  val = -38;
  global_c95c95c108c95c54c57 = val; /* __l_69 */
  return_location = (&body_353);
}
void body_354();
pointer global_c95c95c108c95c55c48;
/* __l_70 */
void body_353() {
  val = -38;
  global_c95c95c108c95c55c48 = val; /* __l_70 */
  return_location = (&body_354);
}
void body_355();
pointer global_c95c95c108c95c55c49;
/* __l_71 */
void body_354() {
  val = -39;
  global_c95c95c108c95c55c49 = val; /* __l_71 */
  return_location = (&body_355);
}
void body_356();
pointer global_c95c95c108c95c55c50;
/* __l_72 */
void body_355() {
  val = -39;
  global_c95c95c108c95c55c50 = val; /* __l_72 */
  return_location = (&body_356);
}
void body_357();
pointer global_c95c95c108c95c55c51;
/* __l_73 */
void body_356() {
  val = CONS;
  global_c95c95c108c95c55c51 = val; /* __l_73 */
  return_location = (&body_357);
}
void body_358();
pointer global_c102c110c95c49c55c52 = NIL; /* fn_174 */
pointer global_c102c110c95c49c55c50 = NIL; /* fn_172 */
pointer global_c102c110c95c49c55c49 = NIL; /* fn_171 */
pointer global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = NIL; /* ___rewrite-quasiquote */
pointer global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = NIL; /* ___compile-expr */
pointer global_c102c110c95c49c55c53;
void function_852() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c54c54); /* __l_66 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  top_level_apply();
}
void function_853() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_854() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_855() {
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
  apply((&function_854));
}
void function_856() {
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
    apply((&function_853));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c49c55c49); /* fn_171 */
    apply((&function_855));
  }
}
void function_857() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_858() {
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
  apply((&function_857));
}
void function_859() {
  top_level_apply();
}
void function_860() {
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
  increment_count(val = global_c102c110c95c49c55c52); /* fn_174 */
  apply((&function_859));
}
void function_861() {
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
    increment_count(val = global_c102c110c95c49c55c50); /* fn_172 */
    apply((&function_858));
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
    apply((&function_860));
  }
}
void function_862() {
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
    apply((&function_856));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c55c49); /* __l_71 */
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
    apply((&function_861));
  }
}
void function_863() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c54c56); /* __l_68 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c54c55); /* __l_67 */
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    apply((&function_852));
  } else {
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
    apply((&function_862));
  }
}
void function_864() {
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
    increment_count(val = global_c95c95c108c95c54c53); /* __l_65 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c54c52); /* __l_64 */
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
    apply((&function_863));
  }
}
void function_865() {
  increment_count(env);
  val = new_function((&function_864), env);
  pop_function();
}
/* fn_175 */
void body_357() {
  increment_count(env);
  val = new_function((&function_865), env);
  global_c102c110c95c49c55c53 = val; /* fn_175 */
  return_location = (&body_358);
}
void body_359();
void function_866() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_867() {
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
  increment_count(val = global_c95c95c108c95c55c48); /* __l_70 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_866));
}
void function_868() {
  increment_count(env);
  val = new_function((&function_867), env);
  pop_function();
}
/* fn_171 */
void body_358() {
  increment_count(env);
  val = new_function((&function_868), env);
  global_c102c110c95c49c55c49 = val; /* fn_171 */
  return_location = (&body_359);
}
void body_360();
void function_869() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_870() {
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
  increment_count(val = global_c95c95c108c95c55c50); /* __l_72 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_869));
}
void function_871() {
  increment_count(env);
  val = new_function((&function_870), env);
  pop_function();
}
/* fn_172 */
void body_359() {
  increment_count(env);
  val = new_function((&function_871), env);
  global_c102c110c95c49c55c50 = val; /* fn_172 */
  return_location = (&body_360);
}
void body_361();
pointer global_c102c110c95c49c55c51 = NIL; /* fn_173 */
void function_872() {
  top_level_apply();
}
void function_873() {
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
  increment_count(val = global_c102c110c95c49c55c51); /* fn_173 */
  apply((&function_872));
}
void function_874() {
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
  apply((&function_873));
}
void function_875() {
  increment_count(env);
  val = new_function((&function_874), env);
  pop_function();
}
/* fn_174 */
void body_360() {
  increment_count(env);
  val = new_function((&function_875), env);
  global_c102c110c95c49c55c52 = val; /* fn_174 */
  return_location = (&body_361);
}
void body_362();
void function_876() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_877() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_876));
}
void function_878() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c55c51); /* __l_73 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_877));
}
void function_879() {
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
  apply((&function_878));
}
void function_880() {
  increment_count(env);
  val = new_function((&function_879), env);
  pop_function();
}
/* fn_173 */
void body_361() {
  increment_count(env);
  val = new_function((&function_880), env);
  global_c102c110c95c49c55c51 = val; /* fn_173 */
  return_location = (&body_362);
}
void body_363();
void function_881() {
  global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* ___rewrite-quasiquote */
  return_location = (&body_363);
}
/* ___rewrite-quasiquote */
void body_362() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c53); /* fn_175 */
  apply((&function_881));
}
void body_364();
pointer global_c95c95c108c95c55c52;
/* __l_74 */
void body_363() {
  val = NIL;
  global_c95c95c108c95c55c52 = val; /* __l_74 */
  return_location = (&body_364);
}
void body_365();
pointer global_c95c95c108c95c55c53;
/* __l_75 */
void body_364() {
  val = -40;
  global_c95c95c108c95c55c53 = val; /* __l_75 */
  return_location = (&body_365);
}
void body_366();
pointer global_c95c95c108c95c55c54;
/* __l_76 */
void body_365() {
  val = NIL;
  global_c95c95c108c95c55c54 = val; /* __l_76 */
  return_location = (&body_366);
}
void body_367();
pointer global_c95c95c108c95c55c55;
/* __l_77 */
void body_366() {
  val = NIL;
  global_c95c95c108c95c55c55 = val; /* __l_77 */
  return_location = (&body_367);
}
void body_368();
pointer global_c95c95c108c95c55c56;
/* __l_78 */
void body_367() {
  val = NIL;
  global_c95c95c108c95c55c56 = val; /* __l_78 */
  return_location = (&body_368);
}
void body_369();
pointer global_c95c95c108c95c55c57;
/* __l_79 */
void body_368() {
  val = -42;
  global_c95c95c108c95c55c57 = val; /* __l_79 */
  return_location = (&body_369);
}
void body_370();
pointer global_c102c110c95c49c55c54;
void function_882() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c55c56); /* __l_78 */
    pop_function();
  } else {
    increment_count(val = global_c95c95c108c95c55c57); /* __l_79 */
    pop_function();
  }
}
void function_883() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c55c54); /* __l_76 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c55c55); /* __l_77 */
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
    apply((&function_882));
  }
}
void function_884() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_883));
}
void function_885() {
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
    increment_count(val = global_c95c95c108c95c55c53); /* __l_75 */
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
    apply((&function_884));
  }
}
void function_886() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c108c95c55c52); /* __l_74 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_885));
  }
}
void function_887() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_886));
}
void function_888() {
  increment_count(env);
  val = new_function((&function_887), env);
  pop_function();
}
/* fn_176 */
void body_369() {
  increment_count(env);
  val = new_function((&function_888), env);
  global_c102c110c95c49c55c54 = val; /* fn_176 */
  return_location = (&body_370);
}
void body_371();
pointer global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101;
void function_889() {
  global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101 = val; /* ___always-true */
  return_location = (&body_371);
}
/* ___always-true */
void body_370() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c54); /* fn_176 */
  apply((&function_889));
}
void body_372();
pointer global_c95c95c108c95c56c48;
/* __l_80 */
void body_371() {
  val = NIL;
  global_c95c95c108c95c56c48 = val; /* __l_80 */
  return_location = (&body_372);
}
void body_373();
pointer global_c95c95c108c95c56c49;
/* __l_81 */
void body_372() {
  val = NIL;
  global_c95c95c108c95c56c49 = val; /* __l_81 */
  return_location = (&body_373);
}
void body_374();
pointer global_c95c95c108c95c56c50;
/* __l_82 */
void body_373() {
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
  global_c95c95c108c95c56c50 = val; /* __l_82 */
  return_location = (&body_374);
}
void body_375();
pointer global_c95c95c108c95c56c51;
/* __l_83 */
void body_374() {
  val = -41;
  global_c95c95c108c95c56c51 = val; /* __l_83 */
  return_location = (&body_375);
}
void body_376();
pointer global_c102c110c95c49c55c57 = NIL; /* fn_179 */
pointer global_c102c110c95c49c56c48;
void function_890() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_891() {
  top_level_apply();
}
void function_892() {
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
  increment_count(val = global_c102c110c95c49c55c57); /* fn_179 */
  apply((&function_891));
}
void function_893() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_892));
}
void function_894() {
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
    apply((&function_890));
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
    apply((&function_893));
  }
}
void function_895() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c97c108c119c97c121c115c45c116c114c117c101); /* ___always-true */
  apply((&function_894));
}
void function_896() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c56c50); /* __l_82 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c56c49); /* __l_81 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c56c48); /* __l_80 */
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
    apply((&function_895));
  }
}
void function_897() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_896));
}
void function_898() {
  increment_count(env);
  val = new_function((&function_897), env);
  pop_function();
}
/* fn_180 */
void body_375() {
  increment_count(env);
  val = new_function((&function_898), env);
  global_c102c110c95c49c56c48 = val; /* fn_180 */
  return_location = (&body_376);
}
void body_377();
pointer global_c102c110c95c49c55c56 = NIL; /* fn_178 */
void function_899() {
  top_level_apply();
}
void function_900() {
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
  increment_count(val = global_c102c110c95c49c55c56); /* fn_178 */
  apply((&function_899));
}
void function_901() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_900));
}
void function_902() {
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
  apply((&function_901));
}
void function_903() {
  increment_count(env);
  val = new_function((&function_902), env);
  pop_function();
}
/* fn_179 */
void body_376() {
  increment_count(env);
  val = new_function((&function_903), env);
  global_c102c110c95c49c55c57 = val; /* fn_179 */
  return_location = (&body_377);
}
void body_378();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = NIL; /* ___rewrite-cond */
pointer global_c102c110c95c49c55c55 = NIL; /* fn_177 */
void function_904() {
  top_level_apply();
}
void function_905() {
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
  increment_count(val = global_c102c110c95c49c55c55); /* fn_177 */
  apply((&function_904));
}
void function_906() {
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
  apply((&function_905));
}
void function_907() {
  increment_count(env);
  val = new_function((&function_906), env);
  pop_function();
}
/* fn_178 */
void body_377() {
  increment_count(env);
  val = new_function((&function_907), env);
  global_c102c110c95c49c55c56 = val; /* fn_178 */
  return_location = (&body_378);
}
void body_379();
void function_908() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_909() {
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
  apply((&function_908));
}
void function_910() {
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
  increment_count(val = global_c95c95c108c95c56c51); /* __l_83 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_909));
}
void function_911() {
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
  apply((&function_910));
}
void function_912() {
  increment_count(env);
  val = new_function((&function_911), env);
  pop_function();
}
/* fn_177 */
void body_378() {
  increment_count(env);
  val = new_function((&function_912), env);
  global_c102c110c95c49c55c55 = val; /* fn_177 */
  return_location = (&body_379);
}
void body_380();
void function_913() {
  global_c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* ___rewrite-cond */
  return_location = (&body_380);
}
/* ___rewrite-cond */
void body_379() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c48); /* fn_180 */
  apply((&function_913));
}
void body_381();
pointer global_c95c95c108c95c56c52;
/* __l_84 */
void body_380() {
  val = -35;
  global_c95c95c108c95c56c52 = val; /* __l_84 */
  return_location = (&body_381);
}
void body_382();
pointer global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = NIL; /* ___rewrite-let */
pointer global_c102c110c95c49c56c49;
void function_914() {
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_915() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c56c52); /* __l_84 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_914));
}
void function_916() {
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_915));
}
void function_917() {
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
  apply((&function_916));
}
void function_918() {
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
  apply((&function_917));
}
void function_919() {
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
    apply((&function_918));
  }
}
void function_920() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_919));
}
void function_921() {
  increment_count(env);
  val = new_function((&function_920), env);
  pop_function();
}
/* fn_181 */
void body_381() {
  increment_count(env);
  val = new_function((&function_921), env);
  global_c102c110c95c49c56c49 = val; /* fn_181 */
  return_location = (&body_382);
}
void body_383();
void function_922() {
  global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = val; /* ___rewrite-let */
  return_location = (&body_383);
}
/* ___rewrite-let */
void body_382() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c49); /* fn_181 */
  apply((&function_922));
}
void body_384();
pointer global_c102c110c95c49c56c51 = NIL; /* fn_183 */
pointer global_c102c110c95c49c56c52;
void function_923() {
  top_level_apply();
}
void function_924() {
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
  increment_count(val = global_c102c110c95c49c56c51); /* fn_183 */
  apply((&function_923));
}
void function_925() {
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
    apply((&function_924));
  }
}
void function_926() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_925));
}
void function_927() {
  increment_count(env);
  val = new_function((&function_926), env);
  pop_function();
}
/* fn_184 */
void body_383() {
  increment_count(env);
  val = new_function((&function_927), env);
  global_c102c110c95c49c56c52 = val; /* fn_184 */
  return_location = (&body_384);
}
void body_385();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = NIL; /* ___compile-args */
pointer global_c102c110c95c49c56c50 = NIL; /* fn_182 */
void function_928() {
  top_level_apply();
}
void function_929() {
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
  increment_count(val = global_c102c110c95c49c56c50); /* fn_182 */
  apply((&function_928));
}
void function_930() {
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
  apply((&function_929));
}
void function_931() {
  increment_count(env);
  val = new_function((&function_930), env);
  pop_function();
}
/* fn_183 */
void body_384() {
  increment_count(env);
  val = new_function((&function_931), env);
  global_c102c110c95c49c56c51 = val; /* fn_183 */
  return_location = (&body_385);
}
void body_386();
void function_932() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_933() {
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
  apply((&function_932));
}
void function_934() {
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
  apply((&function_933));
}
void function_935() {
  increment_count(env);
  val = new_function((&function_934), env);
  pop_function();
}
/* fn_182 */
void body_385() {
  increment_count(env);
  val = new_function((&function_935), env);
  global_c102c110c95c49c56c50 = val; /* fn_182 */
  return_location = (&body_386);
}
void body_387();
void function_936() {
  global_c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* ___compile-args */
  return_location = (&body_387);
}
/* ___compile-args */
void body_386() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c52); /* fn_184 */
  apply((&function_936));
}
void body_388();
pointer global_c95c95c108c95c56c53;
/* __l_85 */
void body_387() {
  val = NIL;
  global_c95c95c108c95c56c53 = val; /* __l_85 */
  return_location = (&body_388);
}
void body_389();
pointer global_c95c95c108c95c56c54;
/* __l_86 */
void body_388() {
  val = NIL;
  global_c95c95c108c95c56c54 = val; /* __l_86 */
  return_location = (&body_389);
}
void body_390();
pointer global_c95c95c108c95c56c55;
/* __l_87 */
void body_389() {
  val = -40;
  global_c95c95c108c95c56c55 = val; /* __l_87 */
  return_location = (&body_390);
}
void body_391();
pointer global_c95c95c108c95c56c56;
/* __l_88 */
void body_390() {
  val = -39;
  global_c95c95c108c95c56c56 = val; /* __l_88 */
  return_location = (&body_391);
}
void body_392();
pointer global_c95c95c108c95c56c57;
/* __l_89 */
void body_391() {
  val = -38;
  global_c95c95c108c95c56c57 = val; /* __l_89 */
  return_location = (&body_392);
}
void body_393();
pointer global_c95c95c108c95c57c48;
/* __l_90 */
void body_392() {
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
  global_c95c95c108c95c57c48 = val; /* __l_90 */
  return_location = (&body_393);
}
void body_394();
pointer global_c95c95c108c95c57c49;
/* __l_91 */
void body_393() {
  val = -37;
  global_c95c95c108c95c57c49 = val; /* __l_91 */
  return_location = (&body_394);
}
void body_395();
pointer global_c95c95c108c95c57c50;
/* __l_92 */
void body_394() {
  val = -36;
  global_c95c95c108c95c57c50 = val; /* __l_92 */
  return_location = (&body_395);
}
void body_396();
pointer global_c95c95c108c95c57c51;
/* __l_93 */
void body_395() {
  val = -35;
  global_c95c95c108c95c57c51 = val; /* __l_93 */
  return_location = (&body_396);
}
void body_397();
pointer global_c95c95c108c95c57c52;
/* __l_94 */
void body_396() {
  val = -35;
  global_c95c95c108c95c57c52 = val; /* __l_94 */
  return_location = (&body_397);
}
void body_398();
pointer global_c102c110c95c49c56c54 = NIL; /* fn_186 */
pointer global_c102c110c95c49c56c53 = NIL; /* fn_185 */
pointer global_c102c110c95c49c56c55;
void function_937() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ___rewrite-quasiquote */
  top_level_apply();
}
void function_938() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_939() {
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
  apply((&function_938));
}
void function_940() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_941() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c119c114c105c116c101c45c108c101c116); /* ___rewrite-let */
  apply((&function_940));
}
void function_942() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_941));
}
void function_943() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_944() {
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
  apply((&function_943));
}
void function_945() {
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
  apply((&function_944));
}
void function_946() {
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
    increment_count(val = global_c102c110c95c49c56c54); /* fn_186 */
    apply((&function_945));
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
void function_947() {
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
    apply((&function_942));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c57c51); /* __l_93 */
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
    apply((&function_946));
  }
}
void function_948() {
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
    increment_count(val = global_c95c95c108c95c57c50); /* __l_92 */
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
    apply((&function_947));
  }
}
void function_949() {
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
    increment_count(val = global_c102c110c95c49c56c53); /* fn_185 */
    apply((&function_939));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c57c49); /* __l_91 */
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
    apply((&function_948));
  }
}
void function_950() {
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
    apply((&function_937));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c56c57); /* __l_89 */
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
    apply((&function_949));
  }
}
void function_951() {
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
    increment_count(val = global_c95c95c108c95c56c56); /* __l_88 */
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
    apply((&function_950));
  }
}
void function_952() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c56c54); /* __l_86 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c56c53); /* __l_85 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c56c55); /* __l_87 */
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
    apply((&function_951));
  }
}
void function_953() {
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
    apply((&function_952));
  }
}
void function_954() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_953));
}
void function_955() {
  increment_count(env);
  val = new_function((&function_954), env);
  pop_function();
}
/* fn_187 */
void body_397() {
  increment_count(env);
  val = new_function((&function_955), env);
  global_c102c110c95c49c56c55 = val; /* fn_187 */
  return_location = (&body_398);
}
void body_399();
void function_956() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_957() {
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
  increment_count(val = global_c95c95c108c95c57c48); /* __l_90 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_956));
}
void function_958() {
  increment_count(env);
  val = new_function((&function_957), env);
  pop_function();
}
/* fn_185 */
void body_398() {
  increment_count(env);
  val = new_function((&function_958), env);
  global_c102c110c95c49c56c53 = val; /* fn_185 */
  return_location = (&body_399);
}
void body_400();
void function_959() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_960() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57c52); /* __l_94 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_959));
}
void function_961() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_960));
}
void function_962() {
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
  apply((&function_961));
}
void function_963() {
  increment_count(env);
  val = new_function((&function_962), env);
  pop_function();
}
/* fn_186 */
void body_399() {
  increment_count(env);
  val = new_function((&function_963), env);
  global_c102c110c95c49c56c54 = val; /* fn_186 */
  return_location = (&body_400);
}
void body_401();
void function_964() {
  global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* ___compile-expr */
  return_location = (&body_401);
}
/* ___compile-expr */
void body_400() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c55); /* fn_187 */
  apply((&function_964));
}
void body_402();
pointer global_c102c110c95c49c56c56;
void function_965() {
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
void function_966() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_965));
}
void function_967() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_966));
}
void function_968() {
  increment_count(env);
  val = new_function((&function_967), env);
  pop_function();
}
/* fn_188 */
void body_401() {
  increment_count(env);
  val = new_function((&function_968), env);
  global_c102c110c95c49c56c56 = val; /* fn_188 */
  return_location = (&body_402);
}
void body_403();
pointer global_c95c95c95c103c101c116c45c110c97c109c101;
void function_969() {
  global_c95c95c95c103c101c116c45c110c97c109c101 = val; /* ___get-name */
  return_location = (&body_403);
}
/* ___get-name */
void body_402() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c56); /* fn_188 */
  apply((&function_969));
}
void body_404();
pointer global_c95c95c108c95c57c53;
/* __l_95 */
void body_403() {
  val = -35;
  global_c95c95c108c95c57c53 = val; /* __l_95 */
  return_location = (&body_404);
}
void body_405();
pointer global_c102c110c95c49c56c57;
void function_970() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57c53); /* __l_95 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_971() {
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
  apply((&function_970));
}
void function_972() {
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
    apply((&function_971));
  }
}
void function_973() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_972));
}
void function_974() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_973));
}
void function_975() {
  increment_count(env);
  val = new_function((&function_974), env);
  pop_function();
}
/* fn_189 */
void body_404() {
  increment_count(env);
  val = new_function((&function_975), env);
  global_c102c110c95c49c56c57 = val; /* fn_189 */
  return_location = (&body_405);
}
void body_406();
pointer global_c95c95c95c103c101c116c45c98c111c100c121;
void function_976() {
  global_c95c95c95c103c101c116c45c98c111c100c121 = val; /* ___get-body */
  return_location = (&body_406);
}
/* ___get-body */
void body_405() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c57); /* fn_189 */
  apply((&function_976));
}
void body_407();
pointer global_c95c95c108c95c57c54;
/* __l_96 */
void body_406() {
  val = NIL;
  global_c95c95c108c95c57c54 = val; /* __l_96 */
  return_location = (&body_407);
}
void body_408();
pointer global_c102c110c95c49c57c51 = NIL; /* fn_193 */
pointer global_c102c110c95c49c57c52;
void function_977() {
  top_level_apply();
}
void function_978() {
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
  increment_count(val = global_c102c110c95c49c57c51); /* fn_193 */
  apply((&function_977));
}
void function_979() {
  increment_count(env);
  val = new_function((&function_978), env);
  pop_function();
}
/* fn_194 */
void body_407() {
  increment_count(env);
  val = new_function((&function_979), env);
  global_c102c110c95c49c57c52 = val; /* fn_194 */
  return_location = (&body_408);
}
void body_409();
pointer global_c102c110c95c49c57c50 = NIL; /* fn_192 */
void function_980() {
  top_level_apply();
}
void function_981() {
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
  increment_count(val = global_c102c110c95c49c57c50); /* fn_192 */
  apply((&function_980));
}
void function_982() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c103c101c116c45c110c97c109c101); /* ___get-name */
  apply((&function_981));
}
void function_983() {
  increment_count(env);
  val = new_function((&function_982), env);
  pop_function();
}
/* fn_193 */
void body_408() {
  increment_count(env);
  val = new_function((&function_983), env);
  global_c102c110c95c49c57c51 = val; /* fn_193 */
  return_location = (&body_409);
}
void body_410();
pointer global_c102c110c95c49c57c49 = NIL; /* fn_191 */
void function_984() {
  top_level_apply();
}
void function_985() {
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
  increment_count(val = global_c102c110c95c49c57c49); /* fn_191 */
  apply((&function_984));
}
void function_986() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c103c101c116c45c98c111c100c121); /* ___get-body */
  apply((&function_985));
}
void function_987() {
  increment_count(env);
  val = new_function((&function_986), env);
  pop_function();
}
/* fn_192 */
void body_409() {
  increment_count(env);
  val = new_function((&function_987), env);
  global_c102c110c95c49c57c50 = val; /* fn_192 */
  return_location = (&body_410);
}
void body_411();
pointer global_c102c110c95c49c57c48 = NIL; /* fn_190 */
void function_988() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57c54); /* __l_96 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  top_level_apply();
}
void function_989() {
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
  increment_count(val = global_c102c110c95c49c57c48); /* fn_190 */
  apply((&function_988));
}
void function_990() {
  increment_count(env);
  val = new_function((&function_989), env);
  pop_function();
}
/* fn_191 */
void body_410() {
  increment_count(env);
  val = new_function((&function_990), env);
  global_c102c110c95c49c57c49 = val; /* fn_191 */
  return_location = (&body_411);
}
void body_412();
void function_991() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_992() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ___print-warnings */
  apply((&function_991));
}
void function_993() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_992));
}
void function_994() {
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
  apply((&function_993));
}
void function_995() {
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
  apply((&function_994));
}
void function_996() {
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
  apply((&function_995));
}
void function_997() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_996));
}
void function_998() {
  increment_count(env);
  val = new_function((&function_997), env);
  pop_function();
}
/* fn_190 */
void body_411() {
  increment_count(env);
  val = new_function((&function_998), env);
  global_c102c110c95c49c57c48 = val; /* fn_190 */
  return_location = (&body_412);
}
void body_413();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
void function_999() {
  global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* ___compile-definition */
  return_location = (&body_413);
}
/* ___compile-definition */
void body_412() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c52); /* fn_194 */
  apply((&function_999));
}
void body_414();
pointer global_c102c110c95c49c57c53 = NIL; /* fn_195 */
pointer global_c102c110c95c49c57c54;
void function_1000() {
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
void function_1001() {
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
    increment_count(val = global_c102c110c95c49c57c53); /* fn_195 */
    apply((&function_1000));
  }
}
void function_1002() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_1001));
}
void function_1003() {
  increment_count(env);
  val = new_function((&function_1002), env);
  pop_function();
}
/* fn_196 */
void body_413() {
  increment_count(env);
  val = new_function((&function_1003), env);
  global_c102c110c95c49c57c54 = val; /* fn_196 */
  return_location = (&body_414);
}
void body_415();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ___compile-definitions */
void function_1004() {
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
void function_1005() {
  increment_count(env);
  val = new_function((&function_1004), env);
  pop_function();
}
/* fn_195 */
void body_414() {
  increment_count(env);
  val = new_function((&function_1005), env);
  global_c102c110c95c49c57c53 = val; /* fn_195 */
  return_location = (&body_415);
}
void body_416();
void function_1006() {
  global_c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ___compile-definitions */
  return_location = (&body_416);
}
/* ___compile-definitions */
void body_415() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c54); /* fn_196 */
  apply((&function_1006));
}
void body_417();
pointer global_c95c95c108c95c57c55;
/* __l_97 */
void body_416() {
  val = NIL;
  global_c95c95c108c95c57c55 = val; /* __l_97 */
  return_location = (&body_417);
}
void body_418();
pointer global_c102c110c95c49c57c57 = NIL; /* fn_199 */
pointer global_c102c110c95c50c48c48;
void function_1007() {
  top_level_apply();
}
void function_1008() {
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
  increment_count(val = global_c102c110c95c49c57c57); /* fn_199 */
  apply((&function_1007));
}
void function_1009() {
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
  apply((&function_1008));
}
void function_1010() {
  increment_count(env);
  val = new_function((&function_1009), env);
  pop_function();
}
/* fn_200 */
void body_417() {
  increment_count(env);
  val = new_function((&function_1010), env);
  global_c102c110c95c50c48c48 = val; /* fn_200 */
  return_location = (&body_418);
}
void body_419();
pointer global_c102c110c95c49c57c56 = NIL; /* fn_198 */
void function_1011() {
  top_level_apply();
}
void function_1012() {
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
  increment_count(val = global_c102c110c95c49c57c56); /* fn_198 */
  apply((&function_1011));
}
void function_1013() {
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
  increment_count(val = global_c95c95c108c95c57c55); /* __l_97 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ___compile-expr */
  apply((&function_1012));
}
void function_1014() {
  increment_count(env);
  val = new_function((&function_1013), env);
  pop_function();
}
/* fn_199 */
void body_418() {
  increment_count(env);
  val = new_function((&function_1014), env);
  global_c102c110c95c49c57c57 = val; /* fn_199 */
  return_location = (&body_419);
}
void body_420();
pointer global_c102c110c95c49c57c55 = NIL; /* fn_197 */
void function_1015() {
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
void function_1016() {
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
  increment_count(val = global_c102c110c95c49c57c55); /* fn_197 */
  apply((&function_1015));
}
void function_1017() {
  increment_count(env);
  val = new_function((&function_1016), env);
  pop_function();
}
/* fn_198 */
void body_419() {
  increment_count(env);
  val = new_function((&function_1017), env);
  global_c102c110c95c49c57c56 = val; /* fn_198 */
  return_location = (&body_420);
}
void body_421();
void function_1018() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_1019() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ___print-warnings */
  apply((&function_1018));
}
void function_1020() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_1019));
}
void function_1021() {
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
  apply((&function_1020));
}
void function_1022() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ___print-with-newline */
  apply((&function_1021));
}
void function_1023() {
  increment_count(env);
  val = new_function((&function_1022), env);
  pop_function();
}
/* fn_197 */
void body_420() {
  increment_count(env);
  val = new_function((&function_1023), env);
  global_c102c110c95c49c57c55 = val; /* fn_197 */
  return_location = (&body_421);
}
void body_422();
pointer global_c95c95c95c99c111c109c112c105c108c101;
void function_1024() {
  global_c95c95c95c99c111c109c112c105c108c101 = val; /* ___compile */
  return_location = (&body_422);
}
/* ___compile */
void body_421() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48c48); /* fn_200 */
  apply((&function_1024));
}
void body_423();
pointer global_c95c95c108c95c57c56;
/* __l_98 */
void body_422() {
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
  global_c95c95c108c95c57c56 = val; /* __l_98 */
  return_location = (&body_423);
}
void body_424();
pointer global_c95c95c108c95c57c57;
/* __l_99 */
void body_423() {
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
  global_c95c95c108c95c57c57 = val; /* __l_99 */
  return_location = (&body_424);
}
void body_425();
pointer global_c95c95c108c95c49c48c48;
/* __l_100 */
void body_424() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c49c48c48 = val; /* __l_100 */
  return_location = (&body_425);
}
void body_426();
pointer global_c102c110c95c50c48c49 = NIL; /* fn_201 */
pointer global_c102c110c95c50c48c50;
void function_1025() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  top_level_apply();
}
void function_1026() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48c49); /* fn_201 */
  apply((&function_1025));
}
void function_1027() {
  increment_count(env);
  val = new_function((&function_1026), env);
  pop_function();
}
/* fn_202 */
void body_425() {
  increment_count(env);
  val = new_function((&function_1027), env);
  global_c102c110c95c50c48c50 = val; /* fn_202 */
  return_location = (&body_426);
}
void body_427();
void function_1028() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ___print-error */
  top_level_apply();
}
void function_1029() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57c56); /* __l_98 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_1028));
}
void function_1030() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c48c48); /* __l_100 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57c57); /* __l_99 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_1029));
}
void function_1031() {
  increment_count(env);
  val = new_function((&function_1030), env);
  pop_function();
}
/* fn_201 */
void body_426() {
  increment_count(env);
  val = new_function((&function_1031), env);
  global_c102c110c95c50c48c49 = val; /* fn_201 */
  return_location = (&body_427);
}
void body_428();
pointer global_c95c95c95c114c101c97c100c45c101c120c112c114;
void function_1032() {
  global_c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ___read-expr */
  return_location = (&body_428);
}
/* ___read-expr */
void body_427() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48c50); /* fn_202 */
  apply((&function_1032));
}
void body_429();
pointer global_c95c95c108c95c49c48c49;
/* __l_101 */
void body_428() {
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
  global_c95c95c108c95c49c48c49 = val; /* __l_101 */
  return_location = (&body_429);
}
void body_430();
pointer global_c95c95c108c95c49c48c50;
/* __l_102 */
void body_429() {
  val = -34;
  global_c95c95c108c95c49c48c50 = val; /* __l_102 */
  return_location = (&body_430);
}
void body_431();
pointer global_c95c95c108c95c49c48c51;
/* __l_103 */
void body_430() {
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
  global_c95c95c108c95c49c48c51 = val; /* __l_103 */
  return_location = (&body_431);
}
void body_432();
pointer global_c102c110c95c50c48c51 = NIL; /* fn_203 */
pointer global_c102c110c95c50c48c52;
void function_1033() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48c51); /* fn_203 */
  top_level_apply();
}
void function_1034() {
  increment_count(env);
  val = new_function((&function_1033), env);
  pop_function();
}
/* fn_204 */
void body_431() {
  increment_count(env);
  val = new_function((&function_1034), env);
  global_c102c110c95c50c48c52 = val; /* fn_204 */
  return_location = (&body_432);
}
void body_433();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ___compile-source */
void function_1035() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101); /* ___compile */
  top_level_apply();
}
void function_1036() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_1037() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c49c48c51); /* __l_103 */
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
    apply((&function_1036));
  }
}
void function_1038() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_1037));
}
void function_1039() {
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  apply((&function_1038));
}
void function_1040() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_1039));
}
void function_1041() {
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
  apply((&function_1040));
}
void function_1042() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_1041));
}
void function_1043() {
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
    apply((&function_1035));
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
    apply((&function_1042));
  }
}
void function_1044() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_1043));
}
void function_1045() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c49c48c49); /* __l_101 */
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
    increment_count(val = global_c95c95c108c95c49c48c50); /* __l_102 */
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
    apply((&function_1044));
  }
}
void function_1046() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_1045));
}
void function_1047() {
  increment_count(env);
  val = new_function((&function_1046), env);
  pop_function();
}
/* fn_203 */
void body_432() {
  increment_count(env);
  val = new_function((&function_1047), env);
  global_c102c110c95c50c48c51 = val; /* fn_203 */
  return_location = (&body_433);
}
void body_434();
void function_1048() {
  global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ___compile-source */
  return_location = (&body_434);
}
/* ___compile-source */
void body_433() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48c52); /* fn_204 */
  apply((&function_1048));
}
void body_435();
pointer global_c95c95c108c95c49;
/* __l_1 */
void body_434() {
  val = NIL;
  global_c95c95c108c95c49 = val; /* __l_1 */
  return_location = (&body_435);
}
void body_436();
pointer global_c102c110c95c50c48c53;
void function_1049() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_1050() {
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
  apply((&function_1049));
}
void function_1051() {
  increment_count(env);
  val = new_function((&function_1050), env);
  pop_function();
}
/* fn_205 */
void body_435() {
  increment_count(env);
  val = new_function((&function_1051), env);
  global_c102c110c95c50c48c53 = val; /* fn_205 */
  return_location = (&body_436);
}
void function_1052() {
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
void body_436() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48c53); /* fn_205 */
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
    call_stack = cons(new_function((&function_1052), NIL), call_stack);
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
  call_stack = cons(new_function((&function_1052), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
