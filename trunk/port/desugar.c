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
pointer global_4;
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
    increment_count(val = global_4); /* equal */
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
      increment_count(val = global_4); /* equal */
      apply((&function_0));
    }
  }
}
/* equal */
void body_0() {
  increment_count(env);
  val = new_function((&function_1), env);
  global_4 = val; /* equal */
  return_location = (&body_1);
}
void body_2();
pointer global_7;
void function_2() {
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
void function_3() {
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
                                                            val = IF;
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
                                                              val = QUOTE;
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
                                                                val = QUASIQUOTE;
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
                                                                  val = UNQUOTE;
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
                                                                    val = COND;
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
                                                                      val = LET;
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
                                                                        val = FN;
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
                                                                          val = DEFINE;
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
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -49;
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
    increment_count(val = global_4); /* equal */
    apply((&function_2));
  }
}
/* symbol->string */
void body_1() {
  increment_count(env);
  val = new_function((&function_3), env);
  global_7 = val; /* symbol->string */
  return_location = (&body_2);
}
void body_3();
pointer global_13;
void function_4() {
  if (val != NIL) {
    decrement_count(val);
    val = DEFINE;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = -49;
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
void function_5() {
  if (val != NIL) {
    decrement_count(val);
    val = FN;
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
    increment_count(val = global_4); /* equal */
    apply((&function_4));
  }
}
void function_6() {
  if (val != NIL) {
    decrement_count(val);
    val = LET;
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
    increment_count(val = global_4); /* equal */
    apply((&function_5));
  }
}
void function_7() {
  if (val != NIL) {
    decrement_count(val);
    val = COND;
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
    increment_count(val = global_4); /* equal */
    apply((&function_6));
  }
}
void function_8() {
  if (val != NIL) {
    decrement_count(val);
    val = UNQUOTE;
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
    increment_count(val = global_4); /* equal */
    apply((&function_7));
  }
}
void function_9() {
  if (val != NIL) {
    decrement_count(val);
    val = QUASIQUOTE;
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
    increment_count(val = global_4); /* equal */
    apply((&function_8));
  }
}
void function_10() {
  if (val != NIL) {
    decrement_count(val);
    val = QUOTE;
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
    increment_count(val = global_4); /* equal */
    apply((&function_9));
  }
}
void function_11() {
  if (val != NIL) {
    decrement_count(val);
    val = IF;
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
    increment_count(val = global_4); /* equal */
    apply((&function_10));
  }
}
void function_12() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_11));
  }
}
void function_13() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_12));
  }
}
void function_14() {
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
    increment_count(val = global_4); /* equal */
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
    increment_count(val = global_4); /* equal */
    apply((&function_14));
  }
}
void function_16() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_15));
  }
}
void function_17() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_16));
  }
}
void function_18() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_17));
  }
}
void function_19() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_18));
  }
}
void function_20() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_19));
  }
}
void function_21() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_20));
  }
}
void function_22() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_21));
  }
}
void function_23() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_22));
  }
}
void function_24() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_23));
  }
}
void function_25() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_24));
  }
}
void function_26() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_25));
  }
}
void function_27() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_26));
  }
}
void function_28() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_27));
  }
}
void function_29() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_28));
  }
}
void function_30() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_29));
  }
}
void function_31() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_30));
  }
}
void function_32() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_31));
  }
}
void function_33() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_32));
  }
}
void function_34() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_33));
  }
}
void function_35() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_34));
  }
}
void function_36() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_35));
  }
}
void function_37() {
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_4); /* equal */
    apply((&function_36));
  }
}
void function_38() {
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
    increment_count(val = global_4); /* equal */
    apply((&function_37));
  }
}
void function_39() {
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
    val = new_number(61);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_4); /* equal */
    apply((&function_38));
  }
}
void function_40() {
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
  increment_count(val = global_4); /* equal */
  apply((&function_39));
}
/* string->symbol */
void body_2() {
  increment_count(env);
  val = new_function((&function_40), env);
  global_13 = val; /* string->symbol */
  return_location = (&body_3);
}
void body_4();
pointer global_12;
void function_41() {
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
          val = -48;
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -49;
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
            val = -48;
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
/* symbol? */
void body_3() {
  increment_count(env);
  val = new_function((&function_41), env);
  global_12 = val; /* symbol? */
  return_location = (&body_4);
}
void body_5();
pointer global_9;
void function_42() {
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
    val = -48;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -49;
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
      val = -48;
      pop_function();
    } else {
      val = NIL;
      pop_function();
    }
  }
}
/* _atom */
void body_4() {
  increment_count(env);
  val = new_function((&function_42), env);
  global_9 = val; /* _atom */
  return_location = (&body_5);
}
void body_6();
pointer global_10;
void function_43() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_4); /* equal */
    top_level_apply();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_44() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_43));
}
/* _= */
void body_5() {
  increment_count(env);
  val = new_function((&function_44), env);
  global_10 = val; /* _= */
  return_location = (&body_6);
}
void body_7();
pointer global_18;
void function_45() {
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
/* _caar */
void body_6() {
  increment_count(env);
  val = new_function((&function_45), env);
  global_18 = val; /* _caar */
  return_location = (&body_7);
}
void body_8();
pointer global_20;
void function_46() {
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
/* _cdar */
void body_7() {
  increment_count(env);
  val = new_function((&function_46), env);
  global_20 = val; /* _cdar */
  return_location = (&body_8);
}
void body_9();
pointer global_21;
void function_47() {
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
/* _cadr */
void body_8() {
  increment_count(env);
  val = new_function((&function_47), env);
  global_21 = val; /* _cadr */
  return_location = (&body_9);
}
void body_10();
pointer global_22;
void function_48() {
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
/* _cddr */
void body_9() {
  increment_count(env);
  val = new_function((&function_48), env);
  global_22 = val; /* _cddr */
  return_location = (&body_10);
}
void body_11();
pointer global_23;
void function_49() {
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
/* _caaar */
void body_10() {
  increment_count(env);
  val = new_function((&function_49), env);
  global_23 = val; /* _caaar */
  return_location = (&body_11);
}
void body_12();
pointer global_24;
void function_50() {
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
/* _caadr */
void body_11() {
  increment_count(env);
  val = new_function((&function_50), env);
  global_24 = val; /* _caadr */
  return_location = (&body_12);
}
void body_13();
pointer global_25;
void function_51() {
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
/* _cadar */
void body_12() {
  increment_count(env);
  val = new_function((&function_51), env);
  global_25 = val; /* _cadar */
  return_location = (&body_13);
}
void body_14();
pointer global_26;
void function_52() {
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
/* _caddr */
void body_13() {
  increment_count(env);
  val = new_function((&function_52), env);
  global_26 = val; /* _caddr */
  return_location = (&body_14);
}
void body_15();
pointer global_27;
void function_53() {
  increment_count(val = car(car(env)));
  pop_function();
}
/* _id */
void body_14() {
  increment_count(env);
  val = new_function((&function_53), env);
  global_27 = val; /* _id */
  return_location = (&body_15);
}
void body_16();
pointer global_28;
void function_54() {
  increment_count(val = car(env));
  pop_function();
}
/* _list */
void body_15() {
  increment_count(env);
  val = new_function((&function_54), env);
  global_28 = val; /* _list */
  return_location = (&body_16);
}
void body_17();
pointer global_30;
void function_55() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
/* _apply */
void body_16() {
  increment_count(env);
  val = new_function((&function_55), env);
  global_30 = val; /* _apply */
  return_location = (&body_17);
}
void body_18();
pointer global_32;
void function_56() {
  top_level_apply();
}
void function_57() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_56));
}
void function_58() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_57), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_59() {
  top_level_apply();
}
void function_60() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_59));
}
void function_61() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_60), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_62() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_61), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_58), env);
  top_level_apply();
}
/* _recurse */
void body_17() {
  increment_count(env);
  val = new_function((&function_62), env);
  global_32 = val; /* _recurse */
  return_location = (&body_18);
}
void body_19();
pointer global_34;
void function_63() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_64() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_63));
}
void function_65() {
  apply((&function_64));
}
void function_66() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_34); /* _walk */
  apply((&function_65));
}
void function_67() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
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
    increment_count(val = car(cdr(car(cdr(env)))));
    apply((&function_66));
  }
}
void function_68() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_67));
}
void function_69() {
  increment_count(env);
  val = new_function((&function_68), env);
  pop_function();
}
/* _walk */
void body_18() {
  increment_count(env);
  val = new_function((&function_69), env);
  global_34 = val; /* _walk */
  return_location = (&body_19);
}
void body_20();
pointer global_41;
void function_70() {
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
    increment_count(val = global_41); /* _rreverse */
    top_level_apply();
  }
}
void function_71() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_70));
}
/* _rreverse */
void body_19() {
  increment_count(env);
  val = new_function((&function_71), env);
  global_41 = val; /* _rreverse */
  return_location = (&body_20);
}
void body_21();
pointer global_44;
/* l_2 */
void body_20() {
  val = NIL;
  global_44 = val; /* l_2 */
  return_location = (&body_21);
}
void body_22();
pointer global_45;
void function_72() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_27); /* _id */
  args = cons(val, args);
  increment_count(val = global_44); /* l_2 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_41); /* _rreverse */
  top_level_apply();
}
/* _reverse */
void body_21() {
  increment_count(env);
  val = new_function((&function_72), env);
  global_45 = val; /* _reverse */
  return_location = (&body_22);
}
void body_23();
pointer global_46;
void function_73() {
  top_level_apply();
}
void function_74() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_46); /* _foldl */
  apply((&function_73));
}
void function_75() {
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
    apply((&function_74));
  }
}
void function_76() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_75));
}
void function_77() {
  increment_count(env);
  val = new_function((&function_76), env);
  pop_function();
}
/* _foldl */
void body_22() {
  increment_count(env);
  val = new_function((&function_77), env);
  global_46 = val; /* _foldl */
  return_location = (&body_23);
}
void body_24();
pointer global_48;
/* l_3 */
void body_23() {
  val = NIL;
  global_48 = val; /* l_3 */
  return_location = (&body_24);
}
void body_25();
pointer global_49;
void function_78() {
  args = cons(val, args);
  increment_count(val = global_48); /* l_3 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_41); /* _rreverse */
  top_level_apply();
}
void function_79() {
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
  increment_count(val = global_46); /* _foldl */
  apply((&function_78));
}
void function_80() {
  increment_count(env);
  val = new_function((&function_79), env);
  pop_function();
}
/* _foldr */
void body_24() {
  increment_count(env);
  val = new_function((&function_80), env);
  global_49 = val; /* _foldr */
  return_location = (&body_25);
}
void body_26();
pointer global_50;
/* l_4 */
void body_25() {
  val = NIL;
  global_50 = val; /* l_4 */
  return_location = (&body_26);
}
void body_27();
pointer global_51;
/* l_5 */
void body_26() {
  val = NIL;
  global_51 = val; /* l_5 */
  return_location = (&body_27);
}
void body_28();
pointer global_52;
void function_81() {
  top_level_apply();
}
void function_82() {
  top_level_apply();
}
void function_83() {
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
    val = CONS;
    args = cons(val, args);
    increment_count(val = global_49); /* _foldr */
    apply((&function_82));
  }
}
void function_84() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_50); /* l_4 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_83));
}
void function_85() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_51); /* l_5 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_84), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_81));
}
/* _append */
void body_27() {
  increment_count(env);
  val = new_function((&function_85), env);
  global_52 = val; /* _append */
  return_location = (&body_28);
}
void body_29();
pointer global_54;
/* l_6 */
void body_28() {
  val = NIL;
  global_54 = val; /* l_6 */
  return_location = (&body_29);
}
void body_30();
pointer global_55;
/* l_7 */
void body_29() {
  val = NIL;
  global_55 = val; /* l_7 */
  return_location = (&body_30);
}
void body_31();
pointer global_11;
void function_86() {
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
    increment_count(val = global_11); /* _equal */
    top_level_apply();
  } else {
    increment_count(val = global_55); /* l_7 */
    pop_function();
  }
}
void function_87() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_54); /* l_6 */
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
    increment_count(val = global_11); /* _equal */
    apply((&function_86));
  }
}
void function_88() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_10); /* _= */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_87));
  }
}
void function_89() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_88));
}
/* _equal */
void body_30() {
  increment_count(env);
  val = new_function((&function_89), env);
  global_11 = val; /* _equal */
  return_location = (&body_31);
}
void body_32();
pointer global_57;
/* l_8 */
void body_31() {
  val = NIL;
  global_57 = val; /* l_8 */
  return_location = (&body_32);
}
void body_33();
pointer global_58;
void function_90() {
  top_level_apply();
}
void function_91() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_92() {
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
  apply((&function_91));
}
void function_93() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_57); /* l_8 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_92), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_90));
}
/* _map */
void body_32() {
  increment_count(env);
  val = new_function((&function_93), env);
  global_58 = val; /* _map */
  return_location = (&body_33);
}
void body_34();
pointer global_59;
/* l_9 */
void body_33() {
  val = NIL;
  global_59 = val; /* l_9 */
  return_location = (&body_34);
}
void body_35();
pointer global_60;
void function_94() {
  top_level_apply();
}
void function_95() {
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
void function_96() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_59); /* l_9 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_95), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_94));
}
/* _or */
void body_34() {
  increment_count(env);
  val = new_function((&function_96), env);
  global_60 = val; /* _or */
  return_location = (&body_35);
}
void body_36();
pointer global_63;
/* l_10 */
void body_35() {
  val = NIL;
  global_63 = val; /* l_10 */
  return_location = (&body_36);
}
void body_37();
pointer global_64;
/* l_11 */
void body_36() {
  val = -48;
  global_64 = val; /* l_11 */
  return_location = (&body_37);
}
void body_38();
pointer global_65;
void function_97() {
  top_level_apply();
}
void function_98() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_63); /* l_10 */
    pop_function();
  }
}
void function_99() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_64); /* l_11 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_98), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_97));
}
/* _and */
void body_37() {
  increment_count(env);
  val = new_function((&function_99), env);
  global_65 = val; /* _and */
  return_location = (&body_38);
}
void body_39();
pointer global_66;
/* l_12 */
void body_38() {
  val = NIL;
  global_66 = val; /* l_12 */
  return_location = (&body_39);
}
void body_40();
pointer global_67;
/* l_13 */
void body_39() {
  val = -48;
  global_67 = val; /* l_13 */
  return_location = (&body_40);
}
void body_41();
pointer global_68;
void function_100() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_66); /* l_12 */
    pop_function();
  } else {
    increment_count(val = global_67); /* l_13 */
    pop_function();
  }
}
/* _not */
void body_40() {
  increment_count(env);
  val = new_function((&function_100), env);
  global_68 = val; /* _not */
  return_location = (&body_41);
}
void body_42();
pointer global_69;
/* l_14 */
void body_41() {
  val = NIL;
  global_69 = val; /* l_14 */
  return_location = (&body_42);
}
void body_43();
pointer global_70;
void function_101() {
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
    increment_count(val = global_70); /* _member */
    top_level_apply();
  }
}
void function_102() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_69); /* l_14 */
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
    increment_count(val = global_11); /* _equal */
    apply((&function_101));
  }
}
void function_103() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_102));
}
/* _member */
void body_42() {
  increment_count(env);
  val = new_function((&function_103), env);
  global_70 = val; /* _member */
  return_location = (&body_43);
}
void body_44();
pointer global_72;
void function_104() {
  global_72 = val; /* _map-to-stderr */
  return_location = (&body_44);
}
void function_105() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_106() {
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
  increment_count(val = global_28); /* _list */
  apply((&function_105));
}
/* _map-to-stderr */
void body_43() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_106), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_104));
}
void body_45();
pointer global_75;
/* l_15 */
void body_44() {
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
  global_75 = val; /* l_15 */
  return_location = (&body_45);
}
void body_46();
pointer global_76;
/* l_16 */
void body_45() {
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
  global_76 = val; /* l_16 */
  return_location = (&body_46);
}
void body_47();
pointer global_77;
/* l_17 */
void body_46() {
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
  global_77 = val; /* l_17 */
  return_location = (&body_47);
}
void body_48();
pointer global_78;
/* l_18 */
void body_47() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_78 = val; /* l_18 */
  return_location = (&body_48);
}
void body_49();
pointer global_82 = NIL; /* _print */
pointer global_79;
void function_107() {
  args = cons(val, args);
  increment_count(val = global_72); /* _map-to-stderr */
  top_level_apply();
}
void function_108() {
  args = cons(val, args);
  increment_count(val = global_76); /* l_16 */
  args = cons(val, args);
  increment_count(val = global_75); /* l_15 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_107));
}
void function_109() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_78); /* l_18 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_77); /* l_17 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_82); /* _print */
    apply((&function_108));
  } else {
    val = NIL;
    pop_function();
  }
}
/* _print-warnings */
void body_48() {
  increment_count(env);
  val = new_function((&function_109), env);
  global_79 = val; /* _print-warnings */
  return_location = (&body_49);
}
void body_50();
pointer global_83;
/* l_19 */
void body_49() {
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
  global_83 = val; /* l_19 */
  return_location = (&body_50);
}
void body_51();
pointer global_84;
/* l_20 */
void body_50() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_84 = val; /* l_20 */
  return_location = (&body_51);
}
void body_52();
pointer global_85;
void function_110() {
  args = cons(val, args);
  increment_count(val = global_72); /* _map-to-stderr */
  top_level_apply();
}
void function_111() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_84); /* l_20 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_83); /* l_19 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_110));
}
/* _print-error */
void body_51() {
  increment_count(env);
  val = new_function((&function_111), env);
  global_85 = val; /* _print-error */
  return_location = (&body_52);
}
void body_53();
pointer global_87;
void function_112() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_113() {
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
    increment_count(val = global_10); /* _= */
    apply((&function_112));
  }
}
void function_114() {
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
    increment_count(val = global_10); /* _= */
    apply((&function_113));
  }
}
void function_115() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_114));
}
/* _escape-char */
void body_52() {
  increment_count(env);
  val = new_function((&function_115), env);
  global_87 = val; /* _escape-char */
  return_location = (&body_53);
}
void body_54();
pointer global_88;
void function_116() {
  top_level_apply();
}
void function_117() {
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
void function_118() {
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
  increment_count(env);
  val = new_function((&function_117), env);
  args = cons(val, args);
  increment_count(val = global_46); /* _foldl */
  apply((&function_116));
}
/* _build-num */
void body_53() {
  increment_count(env);
  val = new_function((&function_118), env);
  global_88 = val; /* _build-num */
  return_location = (&body_54);
}
void body_55();
pointer global_92;
/* l_21 */
void body_54() {
  val = QUOTE;
  global_92 = val; /* l_21 */
  return_location = (&body_55);
}
void body_56();
pointer global_93;
void function_119() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_92); /* l_21 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
/* _quote-value */
void body_55() {
  increment_count(env);
  val = new_function((&function_119), env);
  global_93 = val; /* _quote-value */
  return_location = (&body_56);
}
void body_57();
pointer global_95;
/* l_22 */
void body_56() {
  val = QUASIQUOTE;
  global_95 = val; /* l_22 */
  return_location = (&body_57);
}
void body_58();
pointer global_96;
void function_120() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_95); /* l_22 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
/* _quasiquote-value */
void body_57() {
  increment_count(env);
  val = new_function((&function_120), env);
  global_96 = val; /* _quasiquote-value */
  return_location = (&body_58);
}
void body_59();
pointer global_97;
/* l_23 */
void body_58() {
  val = UNQUOTE;
  global_97 = val; /* l_23 */
  return_location = (&body_59);
}
void body_60();
pointer global_98;
void function_121() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_97); /* l_23 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
/* _unquote-value */
void body_59() {
  increment_count(env);
  val = new_function((&function_121), env);
  global_98 = val; /* _unquote-value */
  return_location = (&body_60);
}
void body_61();
pointer global_99;
void function_122() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
/* _fail */
void body_60() {
  increment_count(env);
  val = new_function((&function_122), env);
  global_99 = val; /* _fail */
  return_location = (&body_61);
}
void body_62();
pointer global_102;
void function_123() {
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
/* _done */
void body_61() {
  increment_count(env);
  val = new_function((&function_123), env);
  global_102 = val; /* _done */
  return_location = (&body_62);
}
void body_63();
pointer global_103;
/* l_24 */
void body_62() {
  val = NIL;
  global_103 = val; /* l_24 */
  return_location = (&body_63);
}
void body_64();
pointer global_104;
void function_124() {
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
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
  }
}
void function_125() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_10); /* _= */
    apply((&function_124));
  }
}
void function_126() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_104); /* _pop */
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
    increment_count(val = global_68); /* _not */
    apply((&function_125));
  }
}
void function_127() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_103); /* l_24 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_126));
}
void function_128() {
  increment_count(env);
  val = new_function((&function_127), env);
  pop_function();
}
/* _pop */
void body_63() {
  increment_count(env);
  val = new_function((&function_128), env);
  global_104 = val; /* _pop */
  return_location = (&body_64);
}
void body_65();
pointer global_105;
void function_129() {
  top_level_apply();
}
void function_130() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
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
    increment_count(val = car(cdr(car(cdr(env)))));
    apply((&function_129));
  }
}
void function_131() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_130));
}
void function_132() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_131), env);
  args = cons(val, args);
  increment_count(val = global_104); /* _pop */
  top_level_apply();
}
void function_133() {
  increment_count(env);
  val = new_function((&function_132), env);
  pop_function();
}
/* _check */
void body_64() {
  increment_count(env);
  val = new_function((&function_133), env);
  global_105 = val; /* _check */
  return_location = (&body_65);
}
void body_66();
pointer global_107;
void function_134() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  top_level_apply();
}
void function_135() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_134), env);
  args = cons(val, args);
  increment_count(val = global_105); /* _check */
  top_level_apply();
}
/* _match */
void body_65() {
  increment_count(env);
  val = new_function((&function_135), env);
  global_107 = val; /* _match */
  return_location = (&body_66);
}
void body_67();
pointer global_108;
void function_136() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_137() {
  increment_count(env);
  val = new_function((&function_136), env);
  pop_function();
}
/* _default */
void body_66() {
  increment_count(env);
  val = new_function((&function_137), env);
  global_108 = val; /* _default */
  return_location = (&body_67);
}
void body_68();
pointer global_111;
void function_138() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(cdr(env)))))));
  top_level_apply();
}
void function_139() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_140() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_139), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_138), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_141() {
  increment_count(env);
  val = new_function((&function_140), env);
  pop_function();
}
void function_142() {
  increment_count(env);
  val = new_function((&function_141), env);
  pop_function();
}
/* _case */
void body_67() {
  increment_count(env);
  val = new_function((&function_142), env);
  global_111 = val; /* _case */
  return_location = (&body_68);
}
void body_69();
pointer global_114;
void function_143() {
  top_level_apply();
}
void function_144() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_145() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99); /* _fail */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_144), env);
  args = cons(val, args);
  increment_count(val = global_49); /* _foldr */
  apply((&function_143));
}
/* _choice */
void body_68() {
  increment_count(env);
  val = new_function((&function_145), env);
  global_114 = val; /* _choice */
  return_location = (&body_69);
}
void body_70();
pointer global_116;
void function_146() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_147() {
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
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  apply((&function_146));
}
void function_148() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_147), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_149() {
  increment_count(env);
  val = new_function((&function_148), env);
  pop_function();
}
/* _post-process */
void body_69() {
  increment_count(env);
  val = new_function((&function_149), env);
  global_116 = val; /* _post-process */
  return_location = (&body_70);
}
void body_71();
pointer global_117;
void function_150() {
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
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_151() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_150), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_151), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_153() {
  increment_count(env);
  val = new_function((&function_152), env);
  pop_function();
}
/* _seq */
void body_70() {
  increment_count(env);
  val = new_function((&function_153), env);
  global_117 = val; /* _seq */
  return_location = (&body_71);
}
void body_72();
pointer global_120;
void function_154() {
  args = cons(val, args);
  increment_count(val = global_117); /* _seq */
  top_level_apply();
}
void function_155() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_87); /* _escape-char */
  args = cons(val, args);
  increment_count(val = global_104); /* _pop */
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  apply((&function_154));
}
/* _escape */
void body_71() {
  increment_count(env);
  val = new_function((&function_155), env);
  global_120 = val; /* _escape */
  return_location = (&body_72);
}
void body_73();
pointer global_121;
void function_156() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_104); /* _pop */
  args = cons(val, args);
  increment_count(val = global_117); /* _seq */
  top_level_apply();
}
/* _use */
void body_72() {
  increment_count(env);
  val = new_function((&function_156), env);
  global_121 = val; /* _use */
  return_location = (&body_73);
}
void body_74();
pointer global_122;
void function_157() {
  top_level_apply();
}
void function_158() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_157));
}
void function_159() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_158), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_160() {
  increment_count(env);
  val = new_function((&function_159), env);
  pop_function();
}
/* _peek */
void body_73() {
  increment_count(env);
  val = new_function((&function_160), env);
  global_122 = val; /* _peek */
  return_location = (&body_74);
}
void body_75();
pointer global_124;
void function_161() {
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
  increment_count(val = global_65); /* _and */
  top_level_apply();
}
void function_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_161), env);
  args = cons(val, args);
  increment_count(val = global_105); /* _check */
  top_level_apply();
}
/* _interval */
void body_74() {
  increment_count(env);
  val = new_function((&function_162), env);
  global_124 = val; /* _interval */
  return_location = (&body_75);
}
void body_76();
pointer global_126;
void function_163() {
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  top_level_apply();
}
void function_164() {
  push_args();
  val = NIL;
  args = val;
  val = CDR;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_121); /* _use */
  apply((&function_163));
}
/* _skip */
void body_75() {
  increment_count(env);
  val = new_function((&function_164), env);
  global_126 = val; /* _skip */
  return_location = (&body_76);
}
void body_77();
pointer global_127;
void function_165() {
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  top_level_apply();
}
void function_166() {
  push_args();
  val = NIL;
  args = val;
  val = CAR;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_117); /* _seq */
  apply((&function_165));
}
/* _first */
void body_76() {
  increment_count(env);
  val = new_function((&function_166), env);
  global_127 = val; /* _first */
  return_location = (&body_77);
}
void body_78();
pointer global_128;
void function_167() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_168() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_167));
}
void function_169() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_168));
}
void function_170() {
  args = cons(val, args);
  increment_count(val = global_122); /* _peek */
  apply((&function_169));
}
void function_171() {
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
  increment_count(val = global_124); /* _interval */
  apply((&function_170));
}
void function_172() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_128); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_121); /* _use */
  apply((&function_171));
}
void function_173() {
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
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_172));
}
/* _parse-num */
void body_77() {
  increment_count(env);
  val = new_function((&function_173), env);
  global_128 = val; /* _parse-num */
  return_location = (&body_78);
}
void body_79();
pointer global_129;
void function_174() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_175() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_88); /* _build-num */
  args = cons(val, args);
  increment_count(val = global_128); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  apply((&function_174));
}
/* _read-num */
void body_78() {
  increment_count(env);
  val = new_function((&function_175), env);
  global_129 = val; /* _read-num */
  return_location = (&body_79);
}
void body_80();
pointer global_130;
void function_176() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_177() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_176));
}
void function_178() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_177));
}
void function_179() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_124); /* _interval */
  apply((&function_178));
}
void function_180() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_179));
}
void function_181() {
  args = cons(val, args);
  increment_count(val = global_122); /* _peek */
  apply((&function_180));
}
void function_182() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
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
  increment_count(val = global_124); /* _interval */
  apply((&function_181));
}
void function_183() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_182));
}
void function_184() {
  args = cons(val, args);
  increment_count(val = global_122); /* _peek */
  apply((&function_183));
}
void function_185() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_184));
}
void function_186() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_185));
}
void function_187() {
  args = cons(val, args);
  increment_count(val = global_122); /* _peek */
  apply((&function_186));
}
void function_188() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_187));
}
void function_189() {
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_188));
}
void function_190() {
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
  increment_count(val = global_130); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_121); /* _use */
  apply((&function_189));
}
/* _parse-symbol */
void body_79() {
  increment_count(env);
  val = new_function((&function_190), env);
  global_130 = val; /* _parse-symbol */
  return_location = (&body_80);
}
void body_81();
pointer global_131;
void function_191() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_192() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_13); /* string->symbol */
  args = cons(val, args);
  increment_count(val = global_130); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  apply((&function_191));
}
/* _read-symbol */
void body_80() {
  increment_count(env);
  val = new_function((&function_192), env);
  global_131 = val; /* _read-symbol */
  return_location = (&body_81);
}
void body_82();
pointer global_132;
void function_193() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_194() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_193));
}
void function_195() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_194));
}
void function_196() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_195));
}
void function_197() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_196));
}
void function_198() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_197));
}
void function_199() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_132); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_120); /* _escape */
  apply((&function_198));
}
void function_200() {
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_199));
}
void function_201() {
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
  increment_count(val = global_132); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_121); /* _use */
  apply((&function_200));
}
/* _parse-string */
void body_81() {
  increment_count(env);
  val = new_function((&function_201), env);
  global_132 = val; /* _parse-string */
  return_location = (&body_82);
}
void body_83();
pointer global_133;
void function_202() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_93); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  top_level_apply();
}
/* _quote-parser */
void body_82() {
  increment_count(env);
  val = new_function((&function_202), env);
  global_133 = val; /* _quote-parser */
  return_location = (&body_83);
}
void body_84();
pointer global_134;
void function_203() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_96); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  top_level_apply();
}
/* _quasiquote-parser */
void body_83() {
  increment_count(env);
  val = new_function((&function_203), env);
  global_134 = val; /* _quasiquote-parser */
  return_location = (&body_84);
}
void body_85();
pointer global_135;
void function_204() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_98); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_116); /* _post-process */
  top_level_apply();
}
/* _unquote-parser */
void body_84() {
  increment_count(env);
  val = new_function((&function_204), env);
  global_135 = val; /* _unquote-parser */
  return_location = (&body_85);
}
void body_86();
pointer global_136;
void function_205() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_206() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_205));
}
void function_207() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_206));
}
void function_208() {
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
  increment_count(val = global_107); /* _match */
  apply((&function_207));
}
void function_209() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_208));
}
void function_210() {
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
  increment_count(val = global_107); /* _match */
  apply((&function_209));
}
void function_211() {
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_210));
}
void function_212() {
  args = cons(val, args);
  increment_count(val = global_126); /* _skip */
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
  increment_count(val = global_136); /* _comment */
  apply((&function_212));
}
void function_214() {
  increment_count(env);
  val = new_function((&function_213), env);
  pop_function();
}
/* _comment */
void body_85() {
  increment_count(env);
  val = new_function((&function_214), env);
  global_136 = val; /* _comment */
  return_location = (&body_86);
}
void body_87();
pointer global_137;
void function_215() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_216() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_215));
}
void function_217() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_216));
}
void function_218() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_137); /* _parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_124); /* _interval */
  apply((&function_217));
}
void function_219() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_218));
}
void function_220() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_219));
}
void function_221() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_137); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_136); /* _comment */
  apply((&function_220));
}
void function_222() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_221));
}
void function_223() {
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
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_222));
}
/* _parse-paren */
void body_86() {
  increment_count(env);
  val = new_function((&function_223), env);
  global_137 = val; /* _parse-paren */
  return_location = (&body_87);
}
void body_88();
pointer global_139 = NIL; /* _parse-expr */
pointer global_138;
void function_224() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_225() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_224));
}
void function_226() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_225));
}
void function_227() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_138); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_124); /* _interval */
  apply((&function_226));
}
void function_228() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_227));
}
void function_229() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_228));
}
void function_230() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_138); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_136); /* _comment */
  apply((&function_229));
}
void function_231() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_230));
}
void function_232() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_102); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_231));
}
void function_233() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_232));
}
void function_234() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_233));
}
void function_235() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_137); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_127); /* _first */
  apply((&function_234));
}
void function_236() {
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_235));
}
void function_237() {
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
  increment_count(val = global_138); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_117); /* _seq */
  apply((&function_236));
}
/* _parse-pair */
void body_87() {
  increment_count(env);
  val = new_function((&function_237), env);
  global_138 = val; /* _parse-pair */
  return_location = (&body_88);
}
void body_89();
void function_238() {
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  top_level_apply();
}
void function_239() {
  args = cons(val, args);
  increment_count(val = global_114); /* _choice */
  apply((&function_238));
}
void function_240() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_239));
}
void function_241() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_124); /* _interval */
  apply((&function_240));
}
void function_242() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_241));
}
void function_243() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_242));
}
void function_244() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_132); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_133); /* _quote-parser */
  apply((&function_243));
}
void function_245() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_244));
}
void function_246() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_245));
}
void function_247() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_133); /* _quote-parser */
  apply((&function_246));
}
void function_248() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_247));
}
void function_249() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_248));
}
void function_250() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_134); /* _quasiquote-parser */
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_250));
}
void function_252() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_251));
}
void function_253() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_135); /* _unquote-parser */
  apply((&function_252));
}
void function_254() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_138); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_254));
}
void function_256() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_256));
}
void function_258() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_257));
}
void function_259() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_258));
}
void function_260() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_259));
}
void function_261() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_107); /* _match */
  apply((&function_260));
}
void function_262() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_136); /* _comment */
  apply((&function_261));
}
void function_263() {
  args = cons(val, args);
  increment_count(val = global_111); /* _case */
  apply((&function_262));
}
void function_264() {
  args = cons(val, args);
  increment_count(val = global_122); /* _peek */
  apply((&function_263));
}
void function_265() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_129); /* _read-num */
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
  increment_count(val = global_124); /* _interval */
  apply((&function_264));
}
void function_266() {
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
  increment_count(val = global_131); /* _read-symbol */
  args = cons(val, args);
  increment_count(val = global_108); /* _default */
  apply((&function_265));
}
/* _parse-expr */
void body_88() {
  increment_count(env);
  val = new_function((&function_266), env);
  global_139 = val; /* _parse-expr */
  return_location = (&body_89);
}
void body_90();
pointer global_140;
/* l_25 */
void body_89() {
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
  global_140 = val; /* l_25 */
  return_location = (&body_90);
}
void body_91();
pointer global_141;
/* l_26 */
void body_90() {
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
  val = new_number(62);
  args = cons(val, args);
  val = new_number(45);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_141 = val; /* l_26 */
  return_location = (&body_91);
}
void body_92();
pointer global_142;
/* l_27 */
void body_91() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_142 = val; /* l_27 */
  return_location = (&body_92);
}
void body_93();
pointer global_146 = NIL; /* _print-num */
pointer global_143;
void function_267() {
  args = cons(val, args);
  increment_count(val = global_85); /* _print-error */
  top_level_apply();
}
void function_268() {
  args = cons(val, args);
  increment_count(val = global_140); /* l_25 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_267));
}
void function_269() {
  args = cons(val, args);
  increment_count(val = global_141); /* l_26 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_146); /* _print-num */
  apply((&function_268));
}
void function_270() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_142); /* l_27 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_146); /* _print-num */
  apply((&function_269));
}
void function_271() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_270), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_139); /* _parse-expr */
  top_level_apply();
}
/* _read-expr */
void body_92() {
  increment_count(env);
  val = new_function((&function_271), env);
  global_143 = val; /* _read-expr */
  return_location = (&body_93);
}
void body_94();
pointer global_147;
void function_272() {
  top_level_apply();
}
void function_273() {
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
void function_274() {
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
void function_275() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  top_level_apply();
}
void function_276() {
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
  increment_count(val = car(car(cdr(env))));
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
  increment_count(val = car(cdr(car(cdr(env)))));
  top_level_apply();
}
void function_277() {
  increment_count(env);
  val = new_function((&function_276), env);
  pop_function();
}
void function_278() {
  increment_count(val = global_27); /* _id */
  pop_function();
}
void function_279() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_278), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_277), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_275), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_274), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_273), env);
  args = cons(val, args);
  increment_count(val = global_34); /* _walk */
  apply((&function_272));
}
/* _build-num-str */
void body_93() {
  increment_count(env);
  val = new_function((&function_279), env);
  global_147 = val; /* _build-num-str */
  return_location = (&body_94);
}
void body_95();
pointer global_151;
/* l_28 */
void body_94() {
  val = NIL;
  global_151 = val; /* l_28 */
  return_location = (&body_95);
}
void body_96();
pointer global_152;
/* l_29 */
void body_95() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_152 = val; /* l_29 */
  return_location = (&body_96);
}
void body_97();
pointer global_153;
/* l_30 */
void body_96() {
  val = NIL;
  global_153 = val; /* l_30 */
  return_location = (&body_97);
}
void body_98();
void function_280() {
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
void function_281() {
  apply((&function_280));
}
void function_282() {
  top_level_apply();
}
void function_283() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_152); /* l_29 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_153); /* l_30 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_147); /* _build-num-str */
    apply((&function_282));
  }
}
void function_284() {
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
    increment_count(val = global_151); /* l_28 */
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
    increment_count(val = global_147); /* _build-num-str */
    apply((&function_281));
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_10); /* _= */
    apply((&function_283));
  }
}
/* _print-num */
void body_97() {
  increment_count(env);
  val = new_function((&function_284), env);
  global_146 = val; /* _print-num */
  return_location = (&body_98);
}
void body_99();
pointer global_154;
/* l_31 */
void body_98() {
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
  global_154 = val; /* l_31 */
  return_location = (&body_99);
}
void body_100();
pointer global_155;
void function_285() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_7); /* symbol->string */
    top_level_apply();
  } else {
    increment_count(val = global_154); /* l_31 */
    pop_function();
  }
}
void function_286() {
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
    increment_count(val = global_146); /* _print-num */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_12); /* symbol? */
    apply((&function_285));
  }
}
/* _print-atom */
void body_99() {
  increment_count(env);
  val = new_function((&function_286), env);
  global_155 = val; /* _print-atom */
  return_location = (&body_100);
}
void body_101();
pointer global_156;
/* l_32 */
void body_100() {
  val = NIL;
  global_156 = val; /* l_32 */
  return_location = (&body_101);
}
void body_102();
pointer global_157;
/* l_33 */
void body_101() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_157 = val; /* l_33 */
  return_location = (&body_102);
}
void body_103();
pointer global_158;
/* l_34 */
void body_102() {
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
  global_158 = val; /* l_34 */
  return_location = (&body_103);
}
void body_104();
pointer global_159;
/* l_35 */
void body_103() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_159 = val; /* l_35 */
  return_location = (&body_104);
}
void body_105();
pointer global_160;
/* l_36 */
void body_104() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_160 = val; /* l_36 */
  return_location = (&body_105);
}
void body_106();
pointer global_163 = NIL; /* _print-with-suffix */
pointer global_161;
void function_287() {
  args = cons(val, args);
  increment_count(val = global_158); /* l_34 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_288() {
  args = cons(val, args);
  increment_count(val = global_160); /* l_36 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_289() {
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
  increment_count(val = global_163); /* _print-with-suffix */
  apply((&function_288));
}
void function_290() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_159); /* l_35 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_155); /* _print-atom */
    apply((&function_287));
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
    increment_count(val = global_161); /* _print-tail */
    apply((&function_289));
  }
}
void function_291() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_157); /* l_33 */
    args = cons(val, args);
    increment_count(val = global_52); /* _append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_290));
  }
}
void function_292() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_156); /* l_32 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_291));
}
/* _print-tail */
void body_105() {
  increment_count(env);
  val = new_function((&function_292), env);
  global_161 = val; /* _print-tail */
  return_location = (&body_106);
}
void body_107();
pointer global_164;
/* l_37 */
void body_106() {
  val = NIL;
  global_164 = val; /* l_37 */
  return_location = (&body_107);
}
void body_108();
pointer global_165;
/* l_38 */
void body_107() {
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
  global_165 = val; /* l_38 */
  return_location = (&body_108);
}
void body_109();
pointer global_166;
/* l_39 */
void body_108() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_166 = val; /* l_39 */
  return_location = (&body_109);
}
void body_110();
void function_293() {
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_294() {
  args = cons(val, args);
  increment_count(val = global_166); /* l_39 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_295() {
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
  increment_count(val = global_163); /* _print-with-suffix */
  apply((&function_294));
}
void function_296() {
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
    increment_count(val = global_155); /* _print-atom */
    apply((&function_293));
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
    increment_count(val = global_161); /* _print-tail */
    apply((&function_295));
  }
}
void function_297() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_165); /* l_38 */
    args = cons(val, args);
    increment_count(val = global_52); /* _append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_296));
  }
}
void function_298() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_164); /* l_37 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_297));
}
/* _print-with-suffix */
void body_109() {
  increment_count(env);
  val = new_function((&function_298), env);
  global_163 = val; /* _print-with-suffix */
  return_location = (&body_110);
}
void body_111();
pointer global_167;
/* l_40 */
void body_110() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_167 = val; /* l_40 */
  return_location = (&body_111);
}
void body_112();
pointer global_168;
void function_299() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_167); /* l_40 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_163); /* _print-with-suffix */
  top_level_apply();
}
/* _print-with-newline */
void body_111() {
  increment_count(env);
  val = new_function((&function_299), env);
  global_168 = val; /* _print-with-newline */
  return_location = (&body_112);
}
void body_113();
pointer global_169;
/* l_41 */
void body_112() {
  val = NIL;
  global_169 = val; /* l_41 */
  return_location = (&body_113);
}
void body_114();
void function_300() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169); /* l_41 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_163); /* _print-with-suffix */
  top_level_apply();
}
/* _print */
void body_113() {
  increment_count(env);
  val = new_function((&function_300), env);
  global_82 = val; /* _print */
  return_location = (&body_114);
}
void body_115();
pointer global_170;
/* l_42 */
void body_114() {
  val = NIL;
  push_args();
  args = val;
  val = FN;
  args = cons(val, args);
  val = COND;
  args = cons(val, args);
  val = DEFINE;
  args = cons(val, args);
  val = IF;
  args = cons(val, args);
  val = LET;
  args = cons(val, args);
  val = UNQUOTE;
  args = cons(val, args);
  val = QUASIQUOTE;
  args = cons(val, args);
  val = QUOTE;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_170 = val; /* l_42 */
  return_location = (&body_115);
}
void body_116();
pointer global_171;
/* _special-forms */
void body_115() {
  increment_count(val = global_170); /* l_42 */
  global_171 = val; /* _special-forms */
  return_location = (&body_116);
}
void body_117();
pointer global_172;
/* l_43 */
void body_116() {
  val = NIL;
  push_args();
  args = val;
  val = -47;
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  val = -46;
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
  val = -44;
  args = cons(val, args);
  val = FUNCTION;
  args = cons(val, args);
  val = NUMBER;
  args = cons(val, args);
  val = -43;
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
  global_172 = val; /* l_43 */
  return_location = (&body_117);
}
void body_118();
pointer global_173;
/* _supported-builtins */
void body_117() {
  increment_count(val = global_172); /* l_43 */
  global_173 = val; /* _supported-builtins */
  return_location = (&body_118);
}
void body_119();
pointer global_174;
/* l_44 */
void body_118() {
  val = NIL;
  global_174 = val; /* l_44 */
  return_location = (&body_119);
}
void body_120();
pointer global_175;
void function_301() {
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
  increment_count(val = global_175); /* _flatten */
  top_level_apply();
}
void function_302() {
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
    increment_count(val = global_175); /* _flatten */
    apply((&function_301));
  }
}
void function_303() {
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
    increment_count(val = global_9); /* _atom */
    apply((&function_302));
  }
}
void function_304() {
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
    increment_count(val = global_12); /* symbol? */
    apply((&function_303));
  }
}
void function_305() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_174); /* l_44 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_304));
}
/* _flatten */
void body_119() {
  increment_count(env);
  val = new_function((&function_305), env);
  global_175 = val; /* _flatten */
  return_location = (&body_120);
}
void body_121();
pointer global_178;
/* l_45 */
void body_120() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_178 = val; /* l_45 */
  return_location = (&body_121);
}
void body_122();
pointer global_179;
void function_306() {
  args = cons(val, args);
  increment_count(val = global_13); /* string->symbol */
  top_level_apply();
}
void function_307() {
  args = cons(val, args);
  increment_count(val = global_178); /* l_45 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_306));
}
void function_308() {
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
    increment_count(val = global_7); /* symbol->string */
    apply((&function_307));
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_309() {
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
    increment_count(val = global_12); /* symbol? */
    apply((&function_308));
  }
}
void function_310() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_173); /* _supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_70); /* _member */
    apply((&function_309));
  }
}
void function_311() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_312() {
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
  increment_count(val = global_179); /* _escape-symbols */
  apply((&function_311));
}
void function_313() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_171); /* _special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_70); /* _member */
    apply((&function_310));
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
    increment_count(val = global_179); /* _escape-symbols */
    apply((&function_312));
  }
}
void function_314() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_313));
}
/* _escape-symbols */
void body_121() {
  increment_count(env);
  val = new_function((&function_314), env);
  global_179 = val; /* _escape-symbols */
  return_location = (&body_122);
}
void body_123();
pointer global_180;
/* l_46 */
void body_122() {
  val = NIL;
  global_180 = val; /* l_46 */
  return_location = (&body_123);
}
void body_124();
pointer global_181;
/* l_47 */
void body_123() {
  val = NIL;
  global_181 = val; /* l_47 */
  return_location = (&body_124);
}
void body_125();
pointer global_182;
/* l_48 */
void body_124() {
  val = NIL;
  global_182 = val; /* l_48 */
  return_location = (&body_125);
}
void body_126();
pointer global_183;
/* l_49 */
void body_125() {
  val = NIL;
  global_183 = val; /* l_49 */
  return_location = (&body_126);
}
void body_127();
pointer global_184;
/* l_50 */
void body_126() {
  val = NIL;
  global_184 = val; /* l_50 */
  return_location = (&body_127);
}
void body_128();
pointer global_185;
/* l_51 */
void body_127() {
  val = NIL;
  global_185 = val; /* l_51 */
  return_location = (&body_128);
}
void body_129();
pointer global_186;
/* l_52 */
void body_128() {
  val = NIL;
  global_186 = val; /* l_52 */
  return_location = (&body_129);
}
void body_130();
pointer global_187;
/* l_53 */
void body_129() {
  val = NIL;
  global_187 = val; /* l_53 */
  return_location = (&body_130);
}
void body_131();
pointer global_188;
/* l_54 */
void body_130() {
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
  global_188 = val; /* l_54 */
  return_location = (&body_131);
}
void body_132();
pointer global_189;
/* l_55 */
void body_131() {
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
  global_189 = val; /* l_55 */
  return_location = (&body_132);
}
void body_133();
pointer global_190;
void function_315() {
  args = cons(val, args);
  increment_count(val = global_180); /* l_46 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_316() {
  args = cons(val, args);
  increment_count(val = global_187); /* l_53 */
  args = cons(val, args);
  increment_count(val = global_186); /* l_52 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_317() {
  args = cons(val, args);
  increment_count(val = global_188); /* l_54 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_316));
}
void function_318() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_185); /* l_51 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_184); /* l_50 */
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
    increment_count(val = global_189); /* l_55 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_7); /* symbol->string */
    apply((&function_317));
  }
}
void function_319() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_183); /* l_49 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_182); /* l_48 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_171); /* _special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_70); /* _member */
    apply((&function_318));
  }
}
void function_320() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_181); /* l_47 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_179); /* _escape-symbols */
    apply((&function_315));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_173); /* _supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_70); /* _member */
    apply((&function_319));
  }
}
void function_321() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_70); /* _member */
  apply((&function_320));
}
void function_322() {
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
  increment_count(val = global_175); /* _flatten */
  apply((&function_321));
}
/* _compile-find */
void body_132() {
  increment_count(env);
  val = new_function((&function_322), env);
  global_190 = val; /* _compile-find */
  return_location = (&body_133);
}
void body_134();
pointer global_195;
/* l_56 */
void body_133() {
  val = NIL;
  global_195 = val; /* l_56 */
  return_location = (&body_134);
}
void body_135();
pointer global_196;
/* l_57 */
void body_134() {
  val = QUOTE;
  global_196 = val; /* l_57 */
  return_location = (&body_135);
}
void body_136();
pointer global_197;
/* l_58 */
void body_135() {
  val = CONS;
  global_197 = val; /* l_58 */
  return_location = (&body_136);
}
void body_137();
pointer global_198;
void function_323() {
  args = cons(val, args);
  increment_count(val = global_197); /* l_58 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
void function_324() {
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
  increment_count(val = global_198); /* _rewrite-quote */
  apply((&function_323));
}
void function_325() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_196); /* l_57 */
    args = cons(val, args);
    increment_count(val = global_28); /* _list */
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
    increment_count(val = global_198); /* _rewrite-quote */
    apply((&function_324));
  }
}
void function_326() {
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
      increment_count(val = global_9); /* _atom */
      apply((&function_325));
    }
  }
}
void function_327() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_195); /* l_56 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_10); /* _= */
  apply((&function_326));
}
/* _rewrite-quote */
void body_136() {
  increment_count(env);
  val = new_function((&function_327), env);
  global_198 = val; /* _rewrite-quote */
  return_location = (&body_137);
}
void body_138();
pointer global_200;
/* l_59 */
void body_137() {
  val = NIL;
  global_200 = val; /* l_59 */
  return_location = (&body_138);
}
void body_139();
pointer global_201;
/* l_60 */
void body_138() {
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
  global_201 = val; /* l_60 */
  return_location = (&body_139);
}
void body_140();
pointer global_202;
void function_328() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_200); /* l_59 */
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
  increment_count(val = car(car(cdr(env))));
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
  val = DEFINE;
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_329() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_328), env);
  top_level_apply();
}
void function_330() {
  args = cons(val, args);
  increment_count(val = global_13); /* string->symbol */
  apply((&function_329));
}
void function_331() {
  args = cons(val, args);
  increment_count(val = global_201); /* l_60 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_330));
}
void function_332() {
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
  increment_count(val = global_82); /* _print */
  apply((&function_331));
}
/* _compile-quote */
void body_139() {
  increment_count(env);
  val = new_function((&function_332), env);
  global_202 = val; /* _compile-quote */
  return_location = (&body_140);
}
void body_141();
pointer global_204;
/* l_61 */
void body_140() {
  val = NIL;
  global_204 = val; /* l_61 */
  return_location = (&body_141);
}
void body_142();
pointer global_205;
/* l_62 */
void body_141() {
  val = NIL;
  global_205 = val; /* l_62 */
  return_location = (&body_142);
}
void body_143();
pointer global_206;
/* l_63 */
void body_142() {
  val = NIL;
  global_206 = val; /* l_63 */
  return_location = (&body_143);
}
void body_144();
pointer global_207;
/* l_64 */
void body_143() {
  val = QUOTE;
  global_207 = val; /* l_64 */
  return_location = (&body_144);
}
void body_145();
pointer global_208;
/* l_65 */
void body_144() {
  val = NIL;
  global_208 = val; /* l_65 */
  return_location = (&body_145);
}
void body_146();
pointer global_209;
/* l_66 */
void body_145() {
  val = UNQUOTE;
  global_209 = val; /* l_66 */
  return_location = (&body_146);
}
void body_147();
pointer global_210;
/* l_67 */
void body_146() {
  val = UNQUOTE;
  global_210 = val; /* l_67 */
  return_location = (&body_147);
}
void body_148();
pointer global_211;
/* l_68 */
void body_147() {
  val = QUASIQUOTE;
  global_211 = val; /* l_68 */
  return_location = (&body_148);
}
void body_149();
pointer global_212;
/* l_69 */
void body_148() {
  val = QUASIQUOTE;
  global_212 = val; /* l_69 */
  return_location = (&body_149);
}
void body_150();
pointer global_213;
/* l_70 */
void body_149() {
  val = CONS;
  global_213 = val; /* l_70 */
  return_location = (&body_150);
}
void body_151();
pointer global_216 = NIL; /* _compile-expr */
pointer global_214;
void function_333() {
  args = cons(val, args);
  increment_count(val = global_206); /* l_63 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  top_level_apply();
}
void function_334() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_335() {
  args = cons(val, args);
  increment_count(val = global_214); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_336() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_337() {
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
  increment_count(val = global_210); /* l_67 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_336));
}
void function_338() {
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_334));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_337), env);
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_335));
  }
}
void function_339() {
  args = cons(val, args);
  increment_count(val = global_214); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_340() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_341() {
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
  increment_count(val = global_212); /* l_69 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_340));
}
void function_342() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_343() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_342));
}
void function_344() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_213); /* l_70 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_343));
}
void function_345() {
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
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_344));
}
void function_346() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_345), env);
  top_level_apply();
}
void function_347() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_28); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
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
  increment_count(val = global_214); /* _rewrite-quasiquote */
  apply((&function_346));
}
void function_348() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_347), env);
  top_level_apply();
}
void function_349() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_341), env);
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_339));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_28); /* _list */
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
    increment_count(val = global_214); /* _rewrite-quasiquote */
    apply((&function_348));
  }
}
void function_350() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_10); /* _= */
    apply((&function_338));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_211); /* l_68 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_349));
  }
}
void function_351() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_208); /* l_65 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_207); /* l_64 */
    args = cons(val, args);
    increment_count(val = global_28); /* _list */
    apply((&function_333));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_209); /* l_66 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_350));
  }
}
void function_352() {
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
    increment_count(val = global_205); /* l_62 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_204); /* l_61 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_351));
  }
}
/* _rewrite-quasiquote */
void body_150() {
  increment_count(env);
  val = new_function((&function_352), env);
  global_214 = val; /* _rewrite-quasiquote */
  return_location = (&body_151);
}
void body_152();
pointer global_225;
/* l_71 */
void body_151() {
  val = NIL;
  global_225 = val; /* l_71 */
  return_location = (&body_152);
}
void body_153();
pointer global_226;
/* l_72 */
void body_152() {
  val = QUOTE;
  global_226 = val; /* l_72 */
  return_location = (&body_153);
}
void body_154();
pointer global_227;
/* l_73 */
void body_153() {
  val = NIL;
  global_227 = val; /* l_73 */
  return_location = (&body_154);
}
void body_155();
pointer global_228;
/* l_74 */
void body_154() {
  val = NIL;
  global_228 = val; /* l_74 */
  return_location = (&body_155);
}
void body_156();
pointer global_229;
/* l_75 */
void body_155() {
  val = NIL;
  global_229 = val; /* l_75 */
  return_location = (&body_156);
}
void body_157();
pointer global_230;
/* l_76 */
void body_156() {
  val = -48;
  global_230 = val; /* l_76 */
  return_location = (&body_157);
}
void body_158();
pointer global_231;
void function_353() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_229); /* l_75 */
    pop_function();
  } else {
    increment_count(val = global_230); /* l_76 */
    pop_function();
  }
}
void function_354() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_227); /* l_73 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_228); /* l_74 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_353));
  }
}
void function_355() {
  args = cons(val, args);
  increment_count(val = global_68); /* _not */
  apply((&function_354));
}
void function_356() {
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
    increment_count(val = global_226); /* l_72 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_355));
  }
}
void function_357() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_225); /* l_71 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_356));
  }
}
void function_358() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_12); /* symbol? */
  apply((&function_357));
}
/* _always-true */
void body_157() {
  increment_count(env);
  val = new_function((&function_358), env);
  global_231 = val; /* _always-true */
  return_location = (&body_158);
}
void body_159();
pointer global_232;
/* l_77 */
void body_158() {
  val = NIL;
  global_232 = val; /* l_77 */
  return_location = (&body_159);
}
void body_160();
pointer global_233;
/* l_78 */
void body_159() {
  val = NIL;
  global_233 = val; /* l_78 */
  return_location = (&body_160);
}
void body_161();
pointer global_234;
/* l_79 */
void body_160() {
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
  global_234 = val; /* l_79 */
  return_location = (&body_161);
}
void body_162();
pointer global_235;
/* l_80 */
void body_161() {
  val = IF;
  global_235 = val; /* l_80 */
  return_location = (&body_162);
}
void body_163();
pointer global_236;
void function_359() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_360() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_361() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_360));
}
void function_362() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_235); /* l_80 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_361));
}
void function_363() {
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
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_362));
}
void function_364() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_363), env);
  top_level_apply();
}
void function_365() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_28); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_236); /* _rewrite-cond */
  apply((&function_364));
}
void function_366() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_365), env);
  top_level_apply();
}
void function_367() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  apply((&function_366));
}
void function_368() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_28); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_25); /* _cadar */
  apply((&function_367));
}
void function_369() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_368), env);
  top_level_apply();
}
void function_370() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  apply((&function_369));
}
void function_371() {
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
    increment_count(val = global_25); /* _cadar */
    apply((&function_359));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_28); /* _list */
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
    increment_count(val = global_18); /* _caar */
    apply((&function_370));
  }
}
void function_372() {
  args = cons(val, args);
  increment_count(val = global_231); /* _always-true */
  apply((&function_371));
}
void function_373() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_234); /* l_79 */
    args = cons(val, args);
    increment_count(val = global_233); /* l_78 */
    args = cons(val, args);
    increment_count(val = global_232); /* l_77 */
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
    increment_count(val = global_18); /* _caar */
    apply((&function_372));
  }
}
void function_374() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_373));
}
/* _rewrite-cond */
void body_162() {
  increment_count(env);
  val = new_function((&function_374), env);
  global_236 = val; /* _rewrite-cond */
  return_location = (&body_163);
}
void body_164();
pointer global_247;
/* l_81 */
void body_163() {
  val = FN;
  global_247 = val; /* l_81 */
  return_location = (&body_164);
}
void body_165();
pointer global_248;
void function_375() {
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
void function_376() {
  args = cons(val, args);
  increment_count(val = global_247); /* l_81 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_375));
}
void function_377() {
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_376));
}
void function_378() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_18); /* _caar */
  apply((&function_377));
}
void function_379() {
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
  increment_count(val = global_248); /* _rewrite-let */
  apply((&function_378));
}
void function_380() {
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
    increment_count(val = global_25); /* _cadar */
    apply((&function_379));
  }
}
void function_381() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_380));
}
/* _rewrite-let */
void body_164() {
  increment_count(env);
  val = new_function((&function_381), env);
  global_248 = val; /* _rewrite-let */
  return_location = (&body_165);
}
void body_166();
pointer global_250;
void function_382() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(env)))))))));
  top_level_apply();
}
void function_383() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
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
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_382));
}
void function_384() {
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
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_383));
}
void function_385() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_384), env);
  top_level_apply();
}
void function_386() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_28); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
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
  increment_count(val = global_250); /* _compile-args */
  apply((&function_385));
}
void function_387() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_386), env);
  top_level_apply();
}
void function_388() {
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
    increment_count(val = global_216); /* _compile-expr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_28); /* _list */
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
    increment_count(val = global_216); /* _compile-expr */
    apply((&function_387));
  }
}
void function_389() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_388));
}
/* _compile-args */
void body_165() {
  increment_count(env);
  val = new_function((&function_389), env);
  global_250 = val; /* _compile-args */
  return_location = (&body_166);
}
void body_167();
pointer global_257;
/* l_82 */
void body_166() {
  val = NIL;
  global_257 = val; /* l_82 */
  return_location = (&body_167);
}
void body_168();
pointer global_258;
/* l_83 */
void body_167() {
  val = NIL;
  global_258 = val; /* l_83 */
  return_location = (&body_168);
}
void body_169();
pointer global_259;
/* l_84 */
void body_168() {
  val = QUOTE;
  global_259 = val; /* l_84 */
  return_location = (&body_169);
}
void body_170();
pointer global_260;
/* l_85 */
void body_169() {
  val = QUASIQUOTE;
  global_260 = val; /* l_85 */
  return_location = (&body_170);
}
void body_171();
pointer global_261;
/* l_86 */
void body_170() {
  val = UNQUOTE;
  global_261 = val; /* l_86 */
  return_location = (&body_171);
}
void body_172();
pointer global_262;
/* l_87 */
void body_171() {
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
  global_262 = val; /* l_87 */
  return_location = (&body_172);
}
void body_173();
pointer global_263;
/* l_88 */
void body_172() {
  val = COND;
  global_263 = val; /* l_88 */
  return_location = (&body_173);
}
void body_174();
pointer global_264;
/* l_89 */
void body_173() {
  val = LET;
  global_264 = val; /* l_89 */
  return_location = (&body_174);
}
void body_175();
pointer global_265;
/* l_90 */
void body_174() {
  val = FN;
  global_265 = val; /* l_90 */
  return_location = (&body_175);
}
void body_176();
pointer global_266;
/* l_91 */
void body_175() {
  val = FN;
  global_266 = val; /* l_91 */
  return_location = (&body_176);
}
void body_177();
void function_390() {
  args = cons(val, args);
  increment_count(val = global_214); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_391() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_392() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_393() {
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
  increment_count(val = global_262); /* l_87 */
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  apply((&function_392));
}
void function_394() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_395() {
  args = cons(val, args);
  increment_count(val = global_248); /* _rewrite-let */
  apply((&function_394));
}
void function_396() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_395));
}
void function_397() {
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_398() {
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
  increment_count(val = global_26); /* _caddr */
  apply((&function_397));
}
void function_399() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_400() {
  args = cons(val, args);
  increment_count(val = global_266); /* l_91 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  apply((&function_399));
}
void function_401() {
  args = cons(val, args);
  increment_count(val = global_179); /* _escape-symbols */
  apply((&function_400));
}
void function_402() {
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_401));
}
void function_403() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_402), env);
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_398));
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
    increment_count(val = global_250); /* _compile-args */
    top_level_apply();
  }
}
void function_404() {
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
    increment_count(val = global_26); /* _caddr */
    apply((&function_396));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_265); /* l_90 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_403));
  }
}
void function_405() {
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
    increment_count(val = global_236); /* _rewrite-cond */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_264); /* l_89 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_404));
  }
}
void function_406() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_393), env);
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_391));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_263); /* l_88 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_405));
  }
}
void function_407() {
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
    increment_count(val = global_21); /* _cadr */
    apply((&function_390));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_261); /* l_86 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_406));
  }
}
void function_408() {
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
    increment_count(val = global_202); /* _compile-quote */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_260); /* l_85 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_407));
  }
}
void function_409() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_258); /* l_83 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_257); /* l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_259); /* l_84 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_408));
  }
}
void function_410() {
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
    increment_count(val = global_190); /* _compile-find */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_9); /* _atom */
    apply((&function_409));
  }
}
void function_411() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_12); /* symbol? */
  apply((&function_410));
}
/* _compile-expr */
void body_176() {
  increment_count(env);
  val = new_function((&function_411), env);
  global_216 = val; /* _compile-expr */
  return_location = (&body_177);
}
void body_178();
pointer global_267;
void function_412() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_21); /* _cadr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_24); /* _caadr */
    top_level_apply();
  }
}
void function_413() {
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_412));
}
void function_414() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_413));
}
/* _get-name */
void body_177() {
  increment_count(env);
  val = new_function((&function_414), env);
  global_267 = val; /* _get-name */
  return_location = (&body_178);
}
void body_179();
pointer global_269;
/* l_92 */
void body_178() {
  val = FN;
  global_269 = val; /* l_92 */
  return_location = (&body_179);
}
void body_180();
pointer global_270;
void function_415() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_269); /* l_92 */
  args = cons(val, args);
  increment_count(val = global_28); /* _list */
  top_level_apply();
}
void function_416() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_415));
}
void function_417() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_26); /* _caddr */
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
    increment_count(val = global_26); /* _caddr */
    apply((&function_416));
  }
}
void function_418() {
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_417));
}
void function_419() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_418));
}
/* _get-body */
void body_179() {
  increment_count(env);
  val = new_function((&function_419), env);
  global_270 = val; /* _get-body */
  return_location = (&body_180);
}
void body_181();
pointer global_271;
/* l_93 */
void body_180() {
  val = NIL;
  global_271 = val; /* l_93 */
  return_location = (&body_181);
}
void body_182();
pointer global_272;
void function_420() {
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_421() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_79); /* _print-warnings */
  apply((&function_420));
}
void function_422() {
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  apply((&function_421));
}
void function_423() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_168); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_58); /* _map */
  apply((&function_422));
}
void function_424() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = DEFINE;
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_168); /* _print-with-newline */
  apply((&function_423));
}
void function_425() {
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
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_179); /* _escape-symbols */
  apply((&function_424));
}
void function_426() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(cdr(cdr(cdr(env))))))))));
  apply((&function_425));
}
void function_427() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_426), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_271); /* l_93 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  top_level_apply();
}
void function_428() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_427), env);
  top_level_apply();
}
void function_429() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_270); /* _get-body */
  apply((&function_428));
}
void function_430() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_429), env);
  top_level_apply();
}
void function_431() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_267); /* _get-name */
  apply((&function_430));
}
void function_432() {
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
  increment_count(env);
  val = new_function((&function_431), env);
  top_level_apply();
}
/* _compile-definition */
void body_181() {
  increment_count(env);
  val = new_function((&function_432), env);
  global_272 = val; /* _compile-definition */
  return_location = (&body_182);
}
void body_183();
pointer global_275;
void function_433() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
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
  increment_count(val = global_275); /* _compile-definitions */
  top_level_apply();
}
void function_434() {
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
    increment_count(env);
    val = new_function((&function_433), env);
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
    increment_count(val = global_272); /* _compile-definition */
    top_level_apply();
  }
}
void function_435() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_434));
}
/* _compile-definitions */
void body_182() {
  increment_count(env);
  val = new_function((&function_435), env);
  global_275 = val; /* _compile-definitions */
  return_location = (&body_183);
}
void body_184();
pointer global_276;
/* l_94 */
void body_183() {
  val = NIL;
  global_276 = val; /* l_94 */
  return_location = (&body_184);
}
void body_185();
pointer global_277;
void function_436() {
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  top_level_apply();
}
void function_437() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_79); /* _print-warnings */
  apply((&function_436));
}
void function_438() {
  args = cons(val, args);
  increment_count(val = global_52); /* _append */
  args = cons(val, args);
  increment_count(val = global_30); /* _apply */
  apply((&function_437));
}
void function_439() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_168); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_58); /* _map */
  apply((&function_438));
}
void function_440() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_168); /* _print-with-newline */
  apply((&function_439));
}
void function_441() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_440), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_275); /* _compile-definitions */
  top_level_apply();
}
void function_442() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_441), env);
  top_level_apply();
}
void function_443() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_28); /* _list */
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_276); /* l_94 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_216); /* _compile-expr */
  apply((&function_442));
}
void function_444() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_443), env);
  top_level_apply();
}
void function_445() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_267); /* _get-name */
  args = cons(val, args);
  increment_count(val = global_58); /* _map */
  apply((&function_444));
}
/* _compile */
void body_184() {
  increment_count(env);
  val = new_function((&function_445), env);
  global_277 = val; /* _compile */
  return_location = (&body_185);
}
void body_186();
pointer global_280;
/* l_95 */
void body_185() {
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
  global_280 = val; /* l_95 */
  return_location = (&body_186);
}
void body_187();
pointer global_281;
/* l_96 */
void body_186() {
  val = DEFINE;
  global_281 = val; /* l_96 */
  return_location = (&body_187);
}
void body_188();
pointer global_282;
/* l_97 */
void body_187() {
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
  global_282 = val; /* l_97 */
  return_location = (&body_188);
}
void body_189();
pointer global_283;
void function_446() {
  args = cons(val, args);
  increment_count(val = global_277); /* _compile */
  top_level_apply();
}
void function_447() {
  args = cons(val, args);
  increment_count(val = global_143); /* _read-expr */
  top_level_apply();
}
void function_448() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_282); /* l_97 */
    args = cons(val, args);
    increment_count(val = global_85); /* _print-error */
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
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
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_283); /* _compile-source */
    apply((&function_447));
  }
}
void function_449() {
  args = cons(val, args);
  increment_count(val = global_68); /* _not */
  apply((&function_448));
}
void function_450() {
  args = cons(val, args);
  increment_count(val = global_60); /* _or */
  apply((&function_449));
}
void function_451() {
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_450));
}
void function_452() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_21); /* _cadr */
  apply((&function_451));
}
void function_453() {
  args = cons(val, args);
  increment_count(val = global_9); /* _atom */
  apply((&function_452));
}
void function_454() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_45); /* _reverse */
    apply((&function_446));
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
    increment_count(val = global_24); /* _caadr */
    apply((&function_453));
  }
}
void function_455() {
  args = cons(val, args);
  increment_count(val = global_68); /* _not */
  apply((&function_454));
}
void function_456() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_280); /* l_95 */
    args = cons(val, args);
    increment_count(val = global_85); /* _print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_281); /* l_96 */
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
    increment_count(val = global_10); /* _= */
    apply((&function_455));
  }
}
void function_457() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_68); /* _not */
  apply((&function_456));
}
void function_458() {
  increment_count(env);
  val = new_function((&function_457), env);
  pop_function();
}
/* _compile-source */
void body_188() {
  increment_count(env);
  val = new_function((&function_458), env);
  global_283 = val; /* _compile-source */
  return_location = (&body_189);
}
void body_190();
pointer global_288;
/* l_1 */
void body_189() {
  val = NIL;
  global_288 = val; /* l_1 */
  return_location = (&body_190);
}
void function_459() {
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
void function_460() {
  args = cons(val, args);
  increment_count(val = global_143); /* _read-expr */
  top_level_apply();
}
void function_461() {
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
  increment_count(val = global_288); /* l_1 */
  args = cons(val, args);
  increment_count(val = global_283); /* _compile-source */
  apply((&function_460));
}
void body_190() {
  increment_count(env);
  val = new_function((&function_461), env);
  pop_function();
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
    call_stack = cons(new_function((&function_459), NIL), call_stack);
    return_location = ;
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
  call_stack = cons(new_function((&function_459), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
