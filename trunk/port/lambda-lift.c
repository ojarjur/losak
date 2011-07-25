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
                                                                  val = new_number(116);
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
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -44;
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
    val = -44;
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
    val = new_number(116);
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
    apply((&function_13));
  }
}
void function_15() {
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
    apply((&function_14));
  }
}
void function_16() {
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
    apply((&function_15));
  }
}
void function_17() {
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
    apply((&function_16));
  }
}
void function_18() {
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
    apply((&function_17));
  }
}
void function_19() {
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
    apply((&function_18));
  }
}
void function_20() {
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
    apply((&function_19));
  }
}
void function_21() {
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
    apply((&function_20));
  }
}
void function_22() {
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
    apply((&function_21));
  }
}
void function_23() {
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
    apply((&function_22));
  }
}
void function_24() {
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
    apply((&function_23));
  }
}
void function_25() {
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
    apply((&function_24));
  }
}
void function_26() {
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
    apply((&function_25));
  }
}
void function_27() {
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
    apply((&function_26));
  }
}
void function_28() {
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
    apply((&function_27));
  }
}
void function_29() {
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
    apply((&function_28));
  }
}
void function_30() {
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
    apply((&function_29));
  }
}
void function_31() {
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
    apply((&function_30));
  }
}
void function_32() {
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
    apply((&function_31));
  }
}
void function_33() {
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
    apply((&function_32));
  }
}
void function_34() {
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
    apply((&function_33));
  }
}
void function_35() {
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
    apply((&function_34));
  }
}
void function_36() {
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
    apply((&function_35));
  }
}
void function_37() {
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
    apply((&function_36));
  }
}
void function_38() {
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
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_37));
  }
}
void function_39() {
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
  apply((&function_38));
}
void function_40() {
  increment_count(env);
  val = new_function((&function_39), env);
  pop_function();
}
/* fn_2 */
void body_4() {
  increment_count(env);
  val = new_function((&function_40), env);
  global_c102c110c95c50 = val; /* fn_2 */
  return_location = (&body_5);
}
void body_6();
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
void function_41() {
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  return_location = (&body_6);
}
/* _string->symbol */
void body_5() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  apply((&function_41));
}
void body_7();
pointer global_c102c110c95c51;
void function_42() {
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
          val = -34;
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -44;
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
            val = -34;
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
void function_43() {
  increment_count(env);
  val = new_function((&function_42), env);
  pop_function();
}
/* fn_3 */
void body_6() {
  increment_count(env);
  val = new_function((&function_43), env);
  global_c102c110c95c51 = val; /* fn_3 */
  return_location = (&body_7);
}
void body_8();
pointer global_c95c115c121c109c98c111c108c63;
void function_44() {
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  return_location = (&body_8);
}
/* _symbol? */
void body_7() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  apply((&function_44));
}
void body_9();
pointer global_c102c110c95c52;
void function_45() {
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
    val = -34;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -44;
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
      val = -34;
      pop_function();
    } else {
      val = NIL;
      pop_function();
    }
  }
}
void function_46() {
  increment_count(env);
  val = new_function((&function_45), env);
  pop_function();
}
/* fn_4 */
void body_8() {
  increment_count(env);
  val = new_function((&function_46), env);
  global_c102c110c95c52 = val; /* fn_4 */
  return_location = (&body_9);
}
void body_10();
pointer global_c95c95c97c116c111c109;
void function_47() {
  global_c95c95c97c116c111c109 = val; /* __atom */
  return_location = (&body_10);
}
/* __atom */
void body_9() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  apply((&function_47));
}
void body_11();
pointer global_c102c110c95c53;
void function_48() {
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
void function_49() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_48));
}
void function_50() {
  increment_count(env);
  val = new_function((&function_49), env);
  pop_function();
}
/* fn_5 */
void body_10() {
  increment_count(env);
  val = new_function((&function_50), env);
  global_c102c110c95c53 = val; /* fn_5 */
  return_location = (&body_11);
}
void body_12();
pointer global_c95c95c61;
void function_51() {
  global_c95c95c61 = val; /* __= */
  return_location = (&body_12);
}
/* __= */
void body_11() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  apply((&function_51));
}
void body_13();
pointer global_c102c110c95c54;
void function_52() {
  increment_count(val = car(env));
  pop_function();
}
void function_53() {
  increment_count(env);
  val = new_function((&function_52), env);
  pop_function();
}
/* fn_6 */
void body_12() {
  increment_count(env);
  val = new_function((&function_53), env);
  global_c102c110c95c54 = val; /* fn_6 */
  return_location = (&body_13);
}
void body_14();
pointer global_c95c108c105c115c116;
void function_54() {
  global_c95c108c105c115c116 = val; /* _list */
  return_location = (&body_14);
}
/* _list */
void body_13() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  apply((&function_54));
}
void body_15();
pointer global_c95c114c114c101c118c101c114c115c101 = NIL; /* _rreverse */
pointer global_c102c110c95c55;
void function_55() {
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
void function_56() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_55));
}
void function_57() {
  increment_count(env);
  val = new_function((&function_56), env);
  pop_function();
}
/* fn_7 */
void body_14() {
  increment_count(env);
  val = new_function((&function_57), env);
  global_c102c110c95c55 = val; /* fn_7 */
  return_location = (&body_15);
}
void body_16();
void function_58() {
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  return_location = (&body_16);
}
/* _rreverse */
void body_15() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  apply((&function_58));
}
void body_17();
pointer global_c102c110c95c56 = NIL; /* fn_8 */
pointer global_c102c110c95c57;
void function_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  top_level_apply();
}
void function_60() {
  increment_count(env);
  val = new_function((&function_59), env);
  pop_function();
}
/* fn_9 */
void body_16() {
  increment_count(env);
  val = new_function((&function_60), env);
  global_c102c110c95c57 = val; /* fn_9 */
  return_location = (&body_17);
}
void body_18();
pointer global_c95c102c111c108c100c108 = NIL; /* _foldl */
void function_61() {
  top_level_apply();
}
void function_62() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_61));
}
void function_63() {
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
    apply((&function_62));
  }
}
void function_64() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_63));
}
void function_65() {
  increment_count(env);
  val = new_function((&function_64), env);
  pop_function();
}
/* fn_8 */
void body_17() {
  increment_count(env);
  val = new_function((&function_65), env);
  global_c102c110c95c56 = val; /* fn_8 */
  return_location = (&body_18);
}
void body_19();
void function_66() {
  global_c95c102c111c108c100c108 = val; /* _foldl */
  return_location = (&body_19);
}
/* _foldl */
void body_18() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  apply((&function_66));
}
void body_20();
pointer global_c102c110c95c49c48 = NIL; /* fn_10 */
pointer global_c102c110c95c49c49;
void function_67() {
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
void function_68() {
  increment_count(env);
  val = new_function((&function_67), env);
  pop_function();
}
/* fn_11 */
void body_19() {
  increment_count(env);
  val = new_function((&function_68), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  return_location = (&body_20);
}
void body_21();
void function_69() {
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  top_level_apply();
}
void function_70() {
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
  apply((&function_69));
}
void function_71() {
  increment_count(env);
  val = new_function((&function_70), env);
  pop_function();
}
/* fn_10 */
void body_20() {
  increment_count(env);
  val = new_function((&function_71), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  return_location = (&body_21);
}
void body_22();
pointer global_c95c102c111c108c100c114;
void function_72() {
  global_c95c102c111c108c100c114 = val; /* _foldr */
  return_location = (&body_22);
}
/* _foldr */
void body_21() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  apply((&function_72));
}
void body_23();
pointer global_c102c110c95c49c50;
void function_73() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_74() {
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
  apply((&function_73));
}
void function_75() {
  increment_count(env);
  val = new_function((&function_74), env);
  pop_function();
}
/* fn_12 */
void body_22() {
  increment_count(env);
  val = new_function((&function_75), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  return_location = (&body_23);
}
void body_24();
pointer global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
void function_76() {
  global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ___map-to-stderr */
  return_location = (&body_24);
}
void function_77() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_76));
}
/* ___map-to-stderr */
void body_23() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  apply((&function_77));
}
void body_25();
pointer global_c95c95c108c95c49;
/* __l_1 */
void body_24() {
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
  global_c95c95c108c95c49 = val; /* __l_1 */
  return_location = (&body_25);
}
void body_26();
pointer global_c95c95c108c95c50;
/* __l_2 */
void body_25() {
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
  global_c95c95c108c95c50 = val; /* __l_2 */
  return_location = (&body_26);
}
void body_27();
pointer global_c95c95c108c95c51;
/* __l_3 */
void body_26() {
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
  global_c95c95c108c95c51 = val; /* __l_3 */
  return_location = (&body_27);
}
void body_28();
pointer global_c95c95c108c95c52;
/* __l_4 */
void body_27() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c52 = val; /* __l_4 */
  return_location = (&body_28);
}
void body_29();
pointer global_c102c110c95c49c51;
void function_78() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_79() {
  increment_count(env);
  val = new_function((&function_78), env);
  pop_function();
}
/* fn_13 */
void body_28() {
  increment_count(env);
  val = new_function((&function_79), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  return_location = (&body_29);
}
void body_30();
pointer global_c95c105c100;
void function_80() {
  global_c95c105c100 = val; /* _id */
  return_location = (&body_30);
}
/* _id */
void body_29() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  apply((&function_80));
}
void body_31();
pointer global_c102c110c95c49c52 = NIL; /* fn_14 */
pointer global_c102c110c95c49c53;
void function_81() {
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
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  top_level_apply();
}
void function_82() {
  increment_count(env);
  val = new_function((&function_81), env);
  pop_function();
}
/* fn_15 */
void body_30() {
  increment_count(env);
  val = new_function((&function_82), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  return_location = (&body_31);
}
void body_32();
pointer global_c95c119c97c108c107 = NIL; /* _walk */
void function_83() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_84() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_83));
}
void function_85() {
  apply((&function_84));
}
void function_86() {
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
  apply((&function_85));
}
void function_87() {
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
    apply((&function_86));
  }
}
void function_88() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_87));
}
void function_89() {
  increment_count(env);
  val = new_function((&function_88), env);
  pop_function();
}
/* fn_14 */
void body_31() {
  increment_count(env);
  val = new_function((&function_89), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  return_location = (&body_32);
}
void body_33();
void function_90() {
  global_c95c119c97c108c107 = val; /* _walk */
  return_location = (&body_33);
}
/* _walk */
void body_32() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  apply((&function_90));
}
void body_34();
pointer global_c102c110c95c49c54 = NIL; /* fn_16 */
pointer global_c102c110c95c49c55;
void function_91() {
  top_level_apply();
}
void function_92() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_91));
}
void function_93() {
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
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  apply((&function_92));
}
void function_94() {
  increment_count(env);
  val = new_function((&function_93), env);
  pop_function();
}
/* fn_17 */
void body_33() {
  increment_count(env);
  val = new_function((&function_94), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  return_location = (&body_34);
}
void body_35();
pointer global_c99c111c110c115 = CONS; /* cons */
void function_95() {
  top_level_apply();
}
void function_96() {
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
    apply((&function_95));
  }
}
void function_97() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_96));
}
void function_98() {
  increment_count(env);
  val = new_function((&function_97), env);
  pop_function();
}
/* fn_16 */
void body_34() {
  increment_count(env);
  val = new_function((&function_98), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  return_location = (&body_35);
}
void body_36();
pointer global_c95c97c112c112c101c110c100;
void function_99() {
  global_c95c97c112c112c101c110c100 = val; /* _append */
  return_location = (&body_36);
}
/* _append */
void body_35() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  apply((&function_99));
}
void body_37();
pointer global_c102c110c95c50c51 = NIL; /* fn_23 */
pointer global_c102c110c95c50c50 = NIL; /* fn_22 */
pointer global_c102c110c95c50c48 = NIL; /* fn_20 */
pointer global_c102c110c95c49c57 = NIL; /* fn_19 */
pointer global_c102c110c95c49c56 = NIL; /* fn_18 */
pointer global_c102c110c95c50c52;
void function_100() {
  top_level_apply();
}
void function_101() {
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  apply((&function_100));
}
void function_102() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  apply((&function_101));
}
void function_103() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  apply((&function_102));
}
void function_104() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  apply((&function_103));
}
void function_105() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  apply((&function_104));
}
void function_106() {
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
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  apply((&function_105));
}
void function_107() {
  increment_count(env);
  val = new_function((&function_106), env);
  pop_function();
}
/* fn_24 */
void body_36() {
  increment_count(env);
  val = new_function((&function_107), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  return_location = (&body_37);
}
void body_38();
void function_108() {
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
void function_109() {
  increment_count(env);
  val = new_function((&function_108), env);
  pop_function();
}
/* fn_18 */
void body_37() {
  increment_count(env);
  val = new_function((&function_109), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  return_location = (&body_38);
}
void body_39();
void function_110() {
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
void function_111() {
  increment_count(env);
  val = new_function((&function_110), env);
  pop_function();
}
/* fn_19 */
void body_38() {
  increment_count(env);
  val = new_function((&function_111), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  return_location = (&body_39);
}
void body_40();
void function_112() {
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
void function_113() {
  increment_count(env);
  val = new_function((&function_112), env);
  pop_function();
}
/* fn_20 */
void body_39() {
  increment_count(env);
  val = new_function((&function_113), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  return_location = (&body_40);
}
void body_41();
pointer global_c102c110c95c50c49 = NIL; /* fn_21 */
void function_114() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  top_level_apply();
}
void function_115() {
  increment_count(env);
  val = new_function((&function_114), env);
  pop_function();
}
/* fn_22 */
void body_40() {
  increment_count(env);
  val = new_function((&function_115), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  return_location = (&body_41);
}
void body_42();
void function_116() {
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
void function_117() {
  increment_count(env);
  val = new_function((&function_116), env);
  pop_function();
}
/* fn_21 */
void body_41() {
  increment_count(env);
  val = new_function((&function_117), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  return_location = (&body_42);
}
void body_43();
void function_118() {
  increment_count(val = global_c95c105c100); /* _id */
  pop_function();
}
void function_119() {
  increment_count(env);
  val = new_function((&function_118), env);
  pop_function();
}
/* fn_23 */
void body_42() {
  increment_count(env);
  val = new_function((&function_119), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  return_location = (&body_43);
}
void body_44();
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
void function_120() {
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  return_location = (&body_44);
}
/* _build-num-str */
void body_43() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  apply((&function_120));
}
void body_45();
pointer global_c102c110c95c50c53;
void function_121() {
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
void function_122() {
  apply((&function_121));
}
void function_123() {
  top_level_apply();
}
void function_124() {
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
      apply((&function_122));
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
      apply((&function_123));
    }
  }
}
void function_125() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_124));
}
void function_126() {
  increment_count(env);
  val = new_function((&function_125), env);
  pop_function();
}
/* fn_25 */
void body_44() {
  increment_count(env);
  val = new_function((&function_126), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  return_location = (&body_45);
}
void body_46();
pointer global_c95c112c114c105c110c116c45c110c117c109;
void function_127() {
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  return_location = (&body_46);
}
/* _print-num */
void body_45() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  apply((&function_127));
}
void body_47();
pointer global_c102c110c95c50c54;
void function_128() {
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
void function_129() {
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
      apply((&function_128));
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
void function_130() {
  increment_count(env);
  val = new_function((&function_129), env);
  pop_function();
}
/* fn_26 */
void body_46() {
  increment_count(env);
  val = new_function((&function_130), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  return_location = (&body_47);
}
void body_48();
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
void function_131() {
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  return_location = (&body_48);
}
/* _print-atom */
void body_47() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  apply((&function_131));
}
void body_49();
pointer global_c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* _print-tail */
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
pointer global_c102c110c95c50c55;
void function_132() {
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
void function_133() {
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
void function_134() {
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
  apply((&function_133));
}
void function_135() {
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
    apply((&function_132));
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
    apply((&function_134));
  }
}
void function_136() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_135));
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
void function_137() {
  increment_count(env);
  val = new_function((&function_136), env);
  pop_function();
}
/* fn_27 */
void body_48() {
  increment_count(env);
  val = new_function((&function_137), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  return_location = (&body_49);
}
void body_50();
void function_138() {
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  return_location = (&body_50);
}
/* _print-tail */
void body_49() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  apply((&function_138));
}
void body_51();
pointer global_c102c110c95c50c56;
void function_139() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_140() {
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
void function_141() {
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
  apply((&function_140));
}
void function_142() {
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
    apply((&function_139));
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
    apply((&function_141));
  }
}
void function_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_142));
}
void function_144() {
  increment_count(env);
  val = new_function((&function_143), env);
  pop_function();
}
/* fn_28 */
void body_50() {
  increment_count(env);
  val = new_function((&function_144), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  return_location = (&body_51);
}
void body_52();
void function_145() {
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  return_location = (&body_52);
}
/* _print-with-suffix */
void body_51() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  apply((&function_145));
}
void body_53();
pointer global_c102c110c95c50c57;
void function_146() {
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
void function_147() {
  increment_count(env);
  val = new_function((&function_146), env);
  pop_function();
}
/* fn_29 */
void body_52() {
  increment_count(env);
  val = new_function((&function_147), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  return_location = (&body_53);
}
void body_54();
pointer global_c95c112c114c105c110c116;
void function_148() {
  global_c95c112c114c105c110c116 = val; /* _print */
  return_location = (&body_54);
}
/* _print */
void body_53() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  apply((&function_148));
}
void body_55();
pointer global_c102c110c95c51c48;
void function_149() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_150() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50); /* __l_2 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49); /* __l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_149));
}
void function_151() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c52); /* __l_4 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c51); /* __l_3 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    apply((&function_150));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_152() {
  increment_count(env);
  val = new_function((&function_151), env);
  pop_function();
}
/* fn_30 */
void body_54() {
  increment_count(env);
  val = new_function((&function_152), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  return_location = (&body_55);
}
void body_56();
pointer global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
void function_153() {
  global_c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ___print-warnings */
  return_location = (&body_56);
}
/* ___print-warnings */
void body_55() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  apply((&function_153));
}
void body_57();
pointer global_c95c95c108c95c53;
/* __l_5 */
void body_56() {
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
  global_c95c95c108c95c53 = val; /* __l_5 */
  return_location = (&body_57);
}
void body_58();
pointer global_c95c95c108c95c54;
/* __l_6 */
void body_57() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c54 = val; /* __l_6 */
  return_location = (&body_58);
}
void body_59();
pointer global_c102c110c95c51c49;
void function_154() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ___map-to-stderr */
  top_level_apply();
}
void function_155() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c54); /* __l_6 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c53); /* __l_5 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_154));
}
void function_156() {
  increment_count(env);
  val = new_function((&function_155), env);
  pop_function();
}
/* fn_31 */
void body_58() {
  increment_count(env);
  val = new_function((&function_156), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  return_location = (&body_59);
}
void body_60();
pointer global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
void function_157() {
  global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ___print-error */
  return_location = (&body_60);
}
/* ___print-error */
void body_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  apply((&function_157));
}
void body_61();
pointer global_c95c95c108c95c55;
/* __l_7 */
void body_60() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c55 = val; /* __l_7 */
  return_location = (&body_61);
}
void body_62();
pointer global_c102c110c95c51c50;
void function_158() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_159() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c55); /* __l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_158));
}
void function_160() {
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
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_159));
}
void function_161() {
  increment_count(env);
  val = new_function((&function_160), env);
  pop_function();
}
/* fn_32 */
void body_61() {
  increment_count(env);
  val = new_function((&function_161), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  return_location = (&body_62);
}
void body_63();
pointer global_c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
void function_162() {
  global_c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ___number->symbol */
  return_location = (&body_63);
}
/* ___number->symbol */
void body_62() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  apply((&function_162));
}
void body_64();
pointer global_c95c95c108c95c56;
/* __l_8 */
void body_63() {
  val = NIL;
  push_args();
  args = val;
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
  val = -42;
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
  global_c95c95c108c95c56 = val; /* __l_8 */
  return_location = (&body_64);
}
void body_65();
pointer global_c95c95c95c98c117c105c108c116c105c110c115;
/* ___builtins */
void body_64() {
  increment_count(val = global_c95c95c108c95c56); /* __l_8 */
  global_c95c95c95c98c117c105c108c116c105c110c115 = val; /* ___builtins */
  return_location = (&body_65);
}
void body_66();
pointer global_c95c95c108c95c57;
/* __l_9 */
void body_65() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c57 = val; /* __l_9 */
  return_location = (&body_66);
}
void body_67();
pointer global_c95c95c101c113c117c97c108 = NIL; /* __equal */
pointer global_c102c110c95c51c51;
void function_163() {
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
void function_164() {
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
    apply((&function_163));
  }
}
void function_165() {
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
    apply((&function_164));
  }
}
void function_166() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_165));
}
void function_167() {
  increment_count(env);
  val = new_function((&function_166), env);
  pop_function();
}
/* fn_33 */
void body_66() {
  increment_count(env);
  val = new_function((&function_167), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  return_location = (&body_67);
}
void body_68();
void function_168() {
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  return_location = (&body_68);
}
/* __equal */
void body_67() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  apply((&function_168));
}
void body_69();
pointer global_c95c109c101c109c98c101c114 = NIL; /* _member */
pointer global_c102c110c95c51c52;
void function_169() {
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
void function_170() {
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
    apply((&function_169));
  }
}
void function_171() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_170));
}
void function_172() {
  increment_count(env);
  val = new_function((&function_171), env);
  pop_function();
}
/* fn_34 */
void body_68() {
  increment_count(env);
  val = new_function((&function_172), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  return_location = (&body_69);
}
void body_70();
void function_173() {
  global_c95c109c101c109c98c101c114 = val; /* _member */
  return_location = (&body_70);
}
/* _member */
void body_69() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  apply((&function_173));
}
void body_71();
pointer global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ___escape-symbols */
pointer global_c102c110c95c51c53;
void function_174() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_175() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c57); /* __l_9 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_174));
}
void function_176() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_177() {
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
  apply((&function_176));
}
void function_178() {
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
    apply((&function_177));
  }
}
void function_179() {
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
    apply((&function_175));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_178));
  }
}
void function_180() {
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
    apply((&function_179));
  }
}
void function_181() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c98c117c105c108c116c105c110c115); /* ___builtins */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  apply((&function_180));
}
void function_182() {
  increment_count(env);
  val = new_function((&function_181), env);
  pop_function();
}
/* fn_35 */
void body_70() {
  increment_count(env);
  val = new_function((&function_182), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  return_location = (&body_71);
}
void body_72();
void function_183() {
  global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ___escape-symbols */
  return_location = (&body_72);
}
/* ___escape-symbols */
void body_71() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  apply((&function_183));
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
pointer global_c95c95c95c102c108c97c116c116c101c110 = NIL; /* ___flatten */
pointer global_c102c110c95c51c54;
void function_184() {
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
void function_185() {
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
    apply((&function_184));
  }
}
void function_186() {
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
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_185));
  }
}
void function_187() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c48); /* __l_10 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_186));
}
void function_188() {
  increment_count(env);
  val = new_function((&function_187), env);
  pop_function();
}
/* fn_36 */
void body_73() {
  increment_count(env);
  val = new_function((&function_188), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  return_location = (&body_74);
}
void body_75();
void function_189() {
  global_c95c95c95c102c108c97c116c116c101c110 = val; /* ___flatten */
  return_location = (&body_75);
}
/* ___flatten */
void body_74() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  apply((&function_189));
}
void body_76();
pointer global_c102c110c95c51c55 = NIL; /* fn_37 */
pointer global_c102c110c95c51c56;
void function_190() {
  top_level_apply();
}
void function_191() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_190));
}
void function_192() {
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  apply((&function_191));
}
void function_193() {
  increment_count(env);
  val = new_function((&function_192), env);
  pop_function();
}
/* fn_38 */
void body_75() {
  increment_count(env);
  val = new_function((&function_193), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  return_location = (&body_76);
}
void body_77();
void function_194() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
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
  }
}
void function_195() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  apply((&function_194));
}
void function_196() {
  increment_count(env);
  val = new_function((&function_195), env);
  pop_function();
}
/* fn_37 */
void body_76() {
  increment_count(env);
  val = new_function((&function_196), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  return_location = (&body_77);
}
void body_78();
pointer global_c95c95c95c109c101c114c103c101;
void function_197() {
  global_c95c95c95c109c101c114c103c101 = val; /* ___merge */
  return_location = (&body_78);
}
/* ___merge */
void body_77() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  apply((&function_197));
}
void body_79();
pointer global_c95c95c108c95c49c49;
/* __l_11 */
void body_78() {
  val = NIL;
  global_c95c95c108c95c49c49 = val; /* __l_11 */
  return_location = (&body_79);
}
void body_80();
pointer global_c102c110c95c51c57 = NIL; /* fn_39 */
pointer global_c102c110c95c52c48;
void function_198() {
  top_level_apply();
}
void function_199() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_198));
}
void function_200() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c49); /* __l_11 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  apply((&function_199));
}
void function_201() {
  increment_count(env);
  val = new_function((&function_200), env);
  pop_function();
}
/* fn_40 */
void body_79() {
  increment_count(env);
  val = new_function((&function_201), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  return_location = (&body_80);
}
void body_81();
void function_202() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
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
  }
}
void function_203() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  apply((&function_202));
}
void function_204() {
  increment_count(env);
  val = new_function((&function_203), env);
  pop_function();
}
/* fn_39 */
void body_80() {
  increment_count(env);
  val = new_function((&function_204), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  return_location = (&body_81);
}
void body_82();
pointer global_c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116;
void function_205() {
  global_c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116 = val; /* ___subtract-list */
  return_location = (&body_82);
}
/* ___subtract-list */
void body_81() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  apply((&function_205));
}
void body_83();
pointer global_c102c110c95c52c49 = NIL; /* fn_41 */
pointer global_c102c110c95c52c50;
void function_206() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  top_level_apply();
}
void function_207() {
  increment_count(env);
  val = new_function((&function_206), env);
  pop_function();
}
/* fn_42 */
void body_82() {
  increment_count(env);
  val = new_function((&function_207), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  return_location = (&body_83);
}
void body_84();
void function_208() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -35;
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
void function_209() {
  push_args();
  val = NIL;
  args = val;
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
  push_args();
  val = NIL;
  args = val;
  val = NIL;
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_208));
}
void function_210() {
  increment_count(env);
  val = new_function((&function_209), env);
  pop_function();
}
/* fn_41 */
void body_83() {
  increment_count(env);
  val = new_function((&function_210), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  return_location = (&body_84);
}
void body_85();
pointer global_c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110;
void function_211() {
  global_c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110 = val; /* ___definition-return */
  return_location = (&body_85);
}
/* ___definition-return */
void body_84() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  apply((&function_211));
}
void body_86();
pointer global_c95c95c108c95c49c50;
/* __l_12 */
void body_85() {
  val = NIL;
  global_c95c95c108c95c49c50 = val; /* __l_12 */
  return_location = (&body_86);
}
void body_87();
pointer global_c95c95c108c95c49c51;
/* __l_13 */
void body_86() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c49c51 = val; /* __l_13 */
  return_location = (&body_87);
}
void body_88();
pointer global_c102c110c95c52c55 = NIL; /* fn_47 */
pointer global_c102c110c95c52c56;
void function_212() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  top_level_apply();
}
void function_213() {
  increment_count(env);
  val = new_function((&function_212), env);
  pop_function();
}
/* fn_48 */
void body_87() {
  increment_count(env);
  val = new_function((&function_213), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  return_location = (&body_88);
}
void body_89();
pointer global_c102c110c95c52c54 = NIL; /* fn_46 */
void function_214() {
  top_level_apply();
}
void function_215() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  apply((&function_214));
}
void function_216() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c49c51); /* __l_13 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_215));
}
void function_217() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_216));
}
void function_218() {
  increment_count(env);
  val = new_function((&function_217), env);
  pop_function();
}
/* fn_47 */
void body_88() {
  increment_count(env);
  val = new_function((&function_218), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  return_location = (&body_89);
}
void body_90();
pointer global_c102c110c95c52c53 = NIL; /* fn_45 */
void function_219() {
  top_level_apply();
}
void function_220() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  apply((&function_219));
}
void function_221() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  apply((&function_220));
}
void function_222() {
  increment_count(env);
  val = new_function((&function_221), env);
  pop_function();
}
/* fn_46 */
void body_89() {
  increment_count(env);
  val = new_function((&function_222), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  return_location = (&body_90);
}
void body_91();
pointer global_c102c110c95c52c52 = NIL; /* fn_44 */
void function_223() {
  top_level_apply();
}
void function_224() {
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
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  apply((&function_223));
}
void function_225() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c49c50); /* __l_12 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c108c97c116c116c101c110); /* ___flatten */
  apply((&function_224));
}
void function_226() {
  increment_count(env);
  val = new_function((&function_225), env);
  pop_function();
}
/* fn_45 */
void body_90() {
  increment_count(env);
  val = new_function((&function_226), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  return_location = (&body_91);
}
void body_92();
pointer global_c102c110c95c52c51 = NIL; /* fn_43 */
void function_227() {
  top_level_apply();
}
void function_228() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  apply((&function_227));
}
void function_229() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116); /* ___subtract-list */
  apply((&function_228));
}
void function_230() {
  increment_count(env);
  val = new_function((&function_229), env);
  pop_function();
}
/* fn_44 */
void body_91() {
  increment_count(env);
  val = new_function((&function_230), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  return_location = (&body_92);
}
void body_93();
void function_231() {
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
void function_232() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -40;
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -35;
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_231));
}
void function_233() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -40;
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_232));
}
void function_234() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
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
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_233));
}
void function_235() {
  increment_count(env);
  val = new_function((&function_234), env);
  pop_function();
}
/* fn_43 */
void body_92() {
  increment_count(env);
  val = new_function((&function_235), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  return_location = (&body_93);
}
void body_94();
pointer global_c95c95c95c102c110c45c114c101c116c117c114c110;
void function_236() {
  global_c95c95c95c102c110c45c114c101c116c117c114c110 = val; /* ___fn-return */
  return_location = (&body_94);
}
/* ___fn-return */
void body_93() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  apply((&function_236));
}
void body_95();
pointer global_c102c110c95c52c57 = NIL; /* fn_49 */
pointer global_c102c110c95c53c48;
void function_237() {
  top_level_apply();
}
void function_238() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  apply((&function_237));
}
void function_239() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c108c97c116c116c101c110); /* ___flatten */
  apply((&function_238));
}
void function_240() {
  increment_count(env);
  val = new_function((&function_239), env);
  pop_function();
}
/* fn_50 */
void body_94() {
  increment_count(env);
  val = new_function((&function_240), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  return_location = (&body_95);
}
void body_96();
pointer global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ___extract-definitions */
void function_241() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
  top_level_apply();
}
void function_242() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c110c45c114c101c116c117c114c110); /* ___fn-return */
  apply((&function_241));
}
void function_243() {
  increment_count(env);
  val = new_function((&function_242), env);
  pop_function();
}
/* fn_49 */
void body_95() {
  increment_count(env);
  val = new_function((&function_243), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  return_location = (&body_96);
}
void body_97();
pointer global_c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115;
void function_244() {
  global_c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115 = val; /* ___fn-defintions */
  return_location = (&body_97);
}
/* ___fn-defintions */
void body_96() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  apply((&function_244));
}
void body_98();
pointer global_c102c110c95c53c50 = NIL; /* fn_52 */
pointer global_c102c110c95c53c51;
void function_245() {
  top_level_apply();
}
void function_246() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  apply((&function_245));
}
void function_247() {
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
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
    increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
    apply((&function_246));
  }
}
void function_248() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_247));
}
void function_249() {
  increment_count(env);
  val = new_function((&function_248), env);
  pop_function();
}
/* fn_53 */
void body_97() {
  increment_count(env);
  val = new_function((&function_249), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  return_location = (&body_98);
}
void body_99();
pointer global_c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ___args-definitions */
pointer global_c102c110c95c53c49 = NIL; /* fn_51 */
void function_250() {
  top_level_apply();
}
void function_251() {
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
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  apply((&function_250));
}
void function_252() {
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
  increment_count(val = global_c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* ___args-definitions */
  apply((&function_251));
}
void function_253() {
  increment_count(env);
  val = new_function((&function_252), env);
  pop_function();
}
/* fn_52 */
void body_98() {
  increment_count(env);
  val = new_function((&function_253), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  return_location = (&body_99);
}
void body_100();
void function_254() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
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
void function_255() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c101c114c103c101); /* ___merge */
  apply((&function_254));
}
void function_256() {
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
  apply((&function_255));
}
void function_257() {
  increment_count(env);
  val = new_function((&function_256), env);
  pop_function();
}
/* fn_51 */
void body_99() {
  increment_count(env);
  val = new_function((&function_257), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  return_location = (&body_100);
}
void body_101();
void function_258() {
  global_c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ___args-definitions */
  return_location = (&body_101);
}
/* ___args-definitions */
void body_100() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  apply((&function_258));
}
void body_102();
pointer global_c95c95c108c95c49c52;
/* __l_14 */
void body_101() {
  val = NIL;
  global_c95c95c108c95c49c52 = val; /* __l_14 */
  return_location = (&body_102);
}
void body_103();
pointer global_c95c95c108c95c49c53;
/* __l_15 */
void body_102() {
  val = NIL;
  global_c95c95c108c95c49c53 = val; /* __l_15 */
  return_location = (&body_103);
}
void body_104();
pointer global_c95c95c108c95c49c54;
/* __l_16 */
void body_103() {
  val = NIL;
  global_c95c95c108c95c49c54 = val; /* __l_16 */
  return_location = (&body_104);
}
void body_105();
pointer global_c95c95c108c95c49c55;
/* __l_17 */
void body_104() {
  val = NIL;
  global_c95c95c108c95c49c55 = val; /* __l_17 */
  return_location = (&body_105);
}
void body_106();
pointer global_c95c95c108c95c49c56;
/* __l_18 */
void body_105() {
  val = -38;
  global_c95c95c108c95c49c56 = val; /* __l_18 */
  return_location = (&body_106);
}
void body_107();
pointer global_c95c95c108c95c49c57;
/* __l_19 */
void body_106() {
  val = NIL;
  global_c95c95c108c95c49c57 = val; /* __l_19 */
  return_location = (&body_107);
}
void body_108();
pointer global_c95c95c108c95c50c48;
/* __l_20 */
void body_107() {
  val = NIL;
  global_c95c95c108c95c50c48 = val; /* __l_20 */
  return_location = (&body_108);
}
void body_109();
pointer global_c95c95c108c95c50c49;
/* __l_21 */
void body_108() {
  val = -35;
  global_c95c95c108c95c50c49 = val; /* __l_21 */
  return_location = (&body_109);
}
void body_110();
pointer global_c95c95c108c95c50c50;
/* __l_22 */
void body_109() {
  val = -40;
  global_c95c95c108c95c50c50 = val; /* __l_22 */
  return_location = (&body_110);
}
void body_111();
pointer global_c95c95c108c95c50c51;
/* __l_23 */
void body_110() {
  val = -39;
  global_c95c95c108c95c50c51 = val; /* __l_23 */
  return_location = (&body_111);
}
void body_112();
pointer global_c102c110c95c53c52;
void function_259() {
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
void function_260() {
  increment_count(env);
  val = new_function((&function_259), env);
  pop_function();
}
/* fn_54 */
void body_111() {
  increment_count(env);
  val = new_function((&function_260), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  return_location = (&body_112);
}
void body_113();
pointer global_c95c99c97c100c114;
void function_261() {
  global_c95c99c97c100c114 = val; /* _cadr */
  return_location = (&body_113);
}
/* _cadr */
void body_112() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  apply((&function_261));
}
void body_114();
pointer global_c102c110c95c53c53;
void function_262() {
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
void function_263() {
  increment_count(env);
  val = new_function((&function_262), env);
  pop_function();
}
/* fn_55 */
void body_113() {
  increment_count(env);
  val = new_function((&function_263), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  return_location = (&body_114);
}
void body_115();
pointer global_c95c99c100c100c114;
void function_264() {
  global_c95c99c100c100c114 = val; /* _cddr */
  return_location = (&body_115);
}
/* _cddr */
void body_114() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  apply((&function_264));
}
void body_116();
pointer global_c102c110c95c53c54;
void function_265() {
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
void function_266() {
  increment_count(env);
  val = new_function((&function_265), env);
  pop_function();
}
/* fn_56 */
void body_115() {
  increment_count(env);
  val = new_function((&function_266), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  return_location = (&body_116);
}
void body_117();
pointer global_c95c99c97c100c100c114;
void function_267() {
  global_c95c99c97c100c100c114 = val; /* _caddr */
  return_location = (&body_117);
}
/* _caddr */
void body_116() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  apply((&function_267));
}
void body_118();
pointer global_c102c110c95c53c57 = NIL; /* fn_59 */
pointer global_c102c110c95c54c48;
void function_268() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  top_level_apply();
}
void function_269() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
  apply((&function_268));
}
void function_270() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    apply((&function_269));
  } else {
    increment_count(val = global_c95c95c108c95c49c52); /* __l_14 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ___escape-symbols */
    apply((&function_268));
  }
}
void function_271() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
  top_level_apply();
}
void function_272() {
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
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  apply((&function_271));
}
void function_273() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110); /* ___definition-return */
  apply((&function_272));
}
void function_274() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115); /* ___fn-defintions */
  top_level_apply();
}
void function_275() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_274));
}
void function_276() {
  top_level_apply();
}
void function_277() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  apply((&function_276));
}
void function_278() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
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
    increment_count(val = global_c95c108c105c115c116); /* _list */
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
    apply((&function_278));
  } else {
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
    increment_count(val = global_c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* ___args-definitions */
    top_level_apply();
  }
}
void function_280() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
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
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    apply((&function_275));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c50c51); /* __l_23 */
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    apply((&function_273));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c50c50); /* __l_22 */
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
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c50c48); /* __l_20 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c57); /* __l_19 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c50c49); /* __l_21 */
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
    apply((&function_281));
  }
}
void function_283() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c55); /* __l_17 */
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c54); /* __l_16 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c49c56); /* __l_18 */
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
    apply((&function_282));
  }
}
void function_284() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c95c49c53); /* __l_15 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    apply((&function_270));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_283));
  }
}
void function_285() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_284));
}
void function_286() {
  increment_count(env);
  val = new_function((&function_285), env);
  pop_function();
}
/* fn_60 */
void body_117() {
  increment_count(env);
  val = new_function((&function_286), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  return_location = (&body_118);
}
void body_119();
pointer global_c102c110c95c53c56 = NIL; /* fn_58 */
void function_287() {
  top_level_apply();
}
void function_288() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
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
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  apply((&function_287));
}
void function_289() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
  apply((&function_288));
}
void function_290() {
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  apply((&function_289));
}
void function_291() {
  increment_count(env);
  val = new_function((&function_290), env);
  pop_function();
}
/* fn_59 */
void body_118() {
  increment_count(env);
  val = new_function((&function_291), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  return_location = (&body_119);
}
void body_120();
pointer global_c102c110c95c53c55 = NIL; /* fn_57 */
void function_292() {
  top_level_apply();
}
void function_293() {
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
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  apply((&function_292));
}
void function_294() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
  apply((&function_293));
}
void function_295() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  apply((&function_294));
}
void function_296() {
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
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c99c100c100c114); /* _cddr */
  apply((&function_295));
}
void function_297() {
  increment_count(env);
  val = new_function((&function_296), env);
  pop_function();
}
/* fn_58 */
void body_119() {
  increment_count(env);
  val = new_function((&function_297), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  return_location = (&body_120);
}
void body_121();
void function_298() {
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
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -39;
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
void function_299() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c101c114c103c101); /* ___merge */
  apply((&function_298));
}
void function_300() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c109c101c114c103c101); /* ___merge */
  apply((&function_299));
}
void function_301() {
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
  apply((&function_300));
}
void function_302() {
  increment_count(env);
  val = new_function((&function_301), env);
  pop_function();
}
/* fn_57 */
void body_120() {
  increment_count(env);
  val = new_function((&function_302), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  return_location = (&body_121);
}
void body_122();
void function_303() {
  global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ___extract-definitions */
  return_location = (&body_122);
}
/* ___extract-definitions */
void body_121() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  apply((&function_303));
}
void body_123();
pointer global_c95c95c108c95c50c52;
/* __l_24 */
void body_122() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c52 = val; /* __l_24 */
  return_location = (&body_123);
}
void body_124();
pointer global_c95c95c108c95c50c53;
/* __l_25 */
void body_123() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c53 = val; /* __l_25 */
  return_location = (&body_124);
}
void body_125();
pointer global_c102c110c95c54c50 = NIL; /* fn_62 */
pointer global_c102c110c95c54c51;
void function_304() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  top_level_apply();
}
void function_305() {
  increment_count(env);
  val = new_function((&function_304), env);
  pop_function();
}
/* fn_63 */
void body_124() {
  increment_count(env);
  val = new_function((&function_305), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  return_location = (&body_125);
}
void body_126();
pointer global_c102c110c95c54c49 = NIL; /* fn_61 */
void function_306() {
  top_level_apply();
}
void function_307() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_306));
}
void function_308() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  apply((&function_307));
}
void function_309() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_308));
}
void function_310() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c53); /* __l_25 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_309));
}
void function_311() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
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
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_310));
}
void function_312() {
  increment_count(env);
  val = new_function((&function_311), env);
  pop_function();
}
/* fn_62 */
void body_125() {
  increment_count(env);
  val = new_function((&function_312), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  return_location = (&body_126);
}
void body_127();
void function_313() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_314() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c52); /* __l_24 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_313));
}
void function_315() {
  increment_count(env);
  val = new_function((&function_314), env);
  pop_function();
}
/* fn_61 */
void body_126() {
  increment_count(env);
  val = new_function((&function_315), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  return_location = (&body_127);
}
void body_128();
pointer global_c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110;
void function_316() {
  global_c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110 = val; /* ___statement-return */
  return_location = (&body_128);
}
/* ___statement-return */
void body_127() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  apply((&function_316));
}
void body_129();
pointer global_c95c95c108c95c50c54;
/* __l_26 */
void body_128() {
  val = NIL;
  global_c95c95c108c95c50c54 = val; /* __l_26 */
  return_location = (&body_129);
}
void body_130();
pointer global_c102c110c95c54c52;
void function_317() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c54); /* __l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ___extract-definitions */
  top_level_apply();
}
void function_318() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110); /* ___statement-return */
  apply((&function_317));
}
void function_319() {
  increment_count(env);
  val = new_function((&function_318), env);
  pop_function();
}
/* fn_64 */
void body_129() {
  increment_count(env);
  val = new_function((&function_319), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  return_location = (&body_130);
}
void body_131();
pointer global_c95c95c95c99c111c109c112c105c108c101;
void function_320() {
  global_c95c95c95c99c111c109c112c105c108c101 = val; /* ___compile */
  return_location = (&body_131);
}
/* ___compile */
void body_130() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  apply((&function_320));
}
void body_132();
pointer global_c95c95c108c95c50c55;
/* __l_27 */
void body_131() {
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
  global_c95c95c108c95c50c55 = val; /* __l_27 */
  return_location = (&body_132);
}
void body_133();
pointer global_c95c95c108c95c50c56;
/* __l_28 */
void body_132() {
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
  global_c95c95c108c95c50c56 = val; /* __l_28 */
  return_location = (&body_133);
}
void body_134();
pointer global_c95c95c108c95c50c57;
/* __l_29 */
void body_133() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c50c57 = val; /* __l_29 */
  return_location = (&body_134);
}
void body_135();
pointer global_c102c110c95c54c53;
void function_321() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_322() {
  increment_count(env);
  val = new_function((&function_321), env);
  pop_function();
}
/* fn_65 */
void body_134() {
  increment_count(env);
  val = new_function((&function_322), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  return_location = (&body_135);
}
void body_136();
pointer global_c95c97c112c112c108c121;
void function_323() {
  global_c95c97c112c112c108c121 = val; /* _apply */
  return_location = (&body_136);
}
/* _apply */
void body_135() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  apply((&function_323));
}
void body_137();
pointer global_c102c110c95c54c54 = NIL; /* fn_66 */
pointer global_c102c110c95c54c55;
void function_324() {
  top_level_apply();
}
void function_325() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_324));
}
void function_326() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = -34;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  apply((&function_325));
}
void function_327() {
  increment_count(env);
  val = new_function((&function_326), env);
  pop_function();
}
/* fn_67 */
void body_136() {
  increment_count(env);
  val = new_function((&function_327), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  return_location = (&body_137);
}
void body_138();
void function_328() {
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
void function_329() {
  increment_count(env);
  val = new_function((&function_328), env);
  pop_function();
}
/* fn_66 */
void body_137() {
  increment_count(env);
  val = new_function((&function_329), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  return_location = (&body_138);
}
void body_139();
pointer global_c95c97c110c100;
void function_330() {
  global_c95c97c110c100 = val; /* _and */
  return_location = (&body_139);
}
/* _and */
void body_138() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  apply((&function_330));
}
void body_140();
pointer global_c102c110c95c54c56;
void function_331() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_332() {
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
    apply((&function_331));
  }
}
void function_333() {
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
    apply((&function_332));
  }
}
void function_334() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_333));
}
void function_335() {
  increment_count(env);
  val = new_function((&function_334), env);
  pop_function();
}
/* fn_68 */
void body_139() {
  increment_count(env);
  val = new_function((&function_335), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  return_location = (&body_140);
}
void body_141();
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
void function_336() {
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  return_location = (&body_141);
}
/* _escape-char */
void body_140() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  apply((&function_336));
}
void body_142();
pointer global_c102c110c95c54c57 = NIL; /* fn_69 */
pointer global_c102c110c95c55c48;
void function_337() {
  top_level_apply();
}
void function_338() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_337));
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
  val = new_number(0);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  apply((&function_338));
}
void function_340() {
  increment_count(env);
  val = new_function((&function_339), env);
  pop_function();
}
/* fn_70 */
void body_141() {
  increment_count(env);
  val = new_function((&function_340), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  return_location = (&body_142);
}
void body_143();
void function_341() {
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
void function_342() {
  increment_count(env);
  val = new_function((&function_341), env);
  pop_function();
}
/* fn_69 */
void body_142() {
  increment_count(env);
  val = new_function((&function_342), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  return_location = (&body_143);
}
void body_144();
pointer global_c95c98c117c105c108c100c45c110c117c109;
void function_343() {
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  return_location = (&body_144);
}
/* _build-num */
void body_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  apply((&function_343));
}
void body_145();
pointer global_c102c110c95c55c49;
void function_344() {
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
void function_345() {
  increment_count(env);
  val = new_function((&function_344), env);
  pop_function();
}
/* fn_71 */
void body_144() {
  increment_count(env);
  val = new_function((&function_345), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  return_location = (&body_145);
}
void body_146();
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
void function_346() {
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  return_location = (&body_146);
}
/* _quote-value */
void body_145() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  apply((&function_346));
}
void body_147();
pointer global_c102c110c95c55c50;
void function_347() {
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
void function_348() {
  increment_count(env);
  val = new_function((&function_347), env);
  pop_function();
}
/* fn_72 */
void body_146() {
  increment_count(env);
  val = new_function((&function_348), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  return_location = (&body_147);
}
void body_148();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_349() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  return_location = (&body_148);
}
/* _quasiquote-value */
void body_147() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  apply((&function_349));
}
void body_149();
pointer global_c102c110c95c55c51;
void function_350() {
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
void function_351() {
  increment_count(env);
  val = new_function((&function_350), env);
  pop_function();
}
/* fn_73 */
void body_148() {
  increment_count(env);
  val = new_function((&function_351), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  return_location = (&body_149);
}
void body_150();
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_352() {
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  return_location = (&body_150);
}
/* _unquote-value */
void body_149() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  apply((&function_352));
}
void body_151();
pointer global_c102c110c95c55c52 = NIL; /* fn_74 */
pointer global_c102c110c95c55c53;
void function_353() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  top_level_apply();
}
void function_354() {
  increment_count(env);
  val = new_function((&function_353), env);
  pop_function();
}
/* fn_75 */
void body_150() {
  increment_count(env);
  val = new_function((&function_354), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  return_location = (&body_151);
}
void body_152();
void function_355() {
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
void function_356() {
  increment_count(env);
  val = new_function((&function_355), env);
  pop_function();
}
/* fn_74 */
void body_151() {
  increment_count(env);
  val = new_function((&function_356), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  return_location = (&body_152);
}
void body_153();
pointer global_c95c102c97c105c108;
void function_357() {
  global_c95c102c97c105c108 = val; /* _fail */
  return_location = (&body_153);
}
/* _fail */
void body_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  apply((&function_357));
}
void body_154();
pointer global_c102c110c95c55c54;
void function_358() {
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
void function_359() {
  increment_count(env);
  val = new_function((&function_358), env);
  pop_function();
}
/* fn_76 */
void body_153() {
  increment_count(env);
  val = new_function((&function_359), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  return_location = (&body_154);
}
void body_155();
pointer global_c95c100c111c110c101;
void function_360() {
  global_c95c100c111c110c101 = val; /* _done */
  return_location = (&body_155);
}
/* _done */
void body_154() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  apply((&function_360));
}
void body_156();
pointer global_c102c110c95c55c55 = NIL; /* fn_77 */
pointer global_c102c110c95c55c56;
void function_361() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  top_level_apply();
}
void function_362() {
  increment_count(env);
  val = new_function((&function_361), env);
  pop_function();
}
/* fn_78 */
void body_155() {
  increment_count(env);
  val = new_function((&function_362), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  return_location = (&body_156);
}
void body_157();
pointer global_c95c112c111c112 = NIL; /* _pop */
void function_363() {
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
void function_364() {
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
      apply((&function_363));
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
void function_365() {
  increment_count(env);
  val = new_function((&function_364), env);
  pop_function();
}
/* fn_77 */
void body_156() {
  increment_count(env);
  val = new_function((&function_365), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  return_location = (&body_157);
}
void body_158();
void function_366() {
  global_c95c112c111c112 = val; /* _pop */
  return_location = (&body_158);
}
/* _pop */
void body_157() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  apply((&function_366));
}
void body_159();
pointer global_c102c110c95c56c48 = NIL; /* fn_80 */
pointer global_c102c110c95c56c49;
void function_367() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  top_level_apply();
}
void function_368() {
  increment_count(env);
  val = new_function((&function_367), env);
  pop_function();
}
/* fn_81 */
void body_158() {
  increment_count(env);
  val = new_function((&function_368), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  return_location = (&body_159);
}
void body_160();
pointer global_c102c110c95c55c57 = NIL; /* fn_79 */
void function_369() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  top_level_apply();
}
void function_370() {
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
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  apply((&function_369));
}
void function_371() {
  increment_count(env);
  val = new_function((&function_370), env);
  pop_function();
}
/* fn_80 */
void body_159() {
  increment_count(env);
  val = new_function((&function_371), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  return_location = (&body_160);
}
void body_161();
void function_372() {
  top_level_apply();
}
void function_373() {
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
    apply((&function_372));
  }
}
void function_374() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_373));
}
void function_375() {
  increment_count(env);
  val = new_function((&function_374), env);
  pop_function();
}
/* fn_79 */
void body_160() {
  increment_count(env);
  val = new_function((&function_375), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  return_location = (&body_161);
}
void body_162();
pointer global_c95c99c104c101c99c107;
void function_376() {
  global_c95c99c104c101c99c107 = val; /* _check */
  return_location = (&body_162);
}
/* _check */
void body_161() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  apply((&function_376));
}
void body_163();
pointer global_c102c110c95c56c50 = NIL; /* fn_82 */
pointer global_c102c110c95c56c51;
void function_377() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_378() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  apply((&function_377));
}
void function_379() {
  increment_count(env);
  val = new_function((&function_378), env);
  pop_function();
}
/* fn_83 */
void body_162() {
  increment_count(env);
  val = new_function((&function_379), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  return_location = (&body_163);
}
void body_164();
void function_380() {
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
void function_381() {
  increment_count(env);
  val = new_function((&function_380), env);
  pop_function();
}
/* fn_82 */
void body_163() {
  increment_count(env);
  val = new_function((&function_381), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  return_location = (&body_164);
}
void body_165();
pointer global_c95c109c97c116c99c104;
void function_382() {
  global_c95c109c97c116c99c104 = val; /* _match */
  return_location = (&body_165);
}
/* _match */
void body_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  apply((&function_382));
}
void body_166();
pointer global_c102c110c95c56c52 = NIL; /* fn_84 */
pointer global_c102c110c95c56c53;
void function_383() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  top_level_apply();
}
void function_384() {
  increment_count(env);
  val = new_function((&function_383), env);
  pop_function();
}
/* fn_85 */
void body_165() {
  increment_count(env);
  val = new_function((&function_384), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  return_location = (&body_166);
}
void body_167();
void function_385() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_386() {
  increment_count(env);
  val = new_function((&function_385), env);
  pop_function();
}
/* fn_84 */
void body_166() {
  increment_count(env);
  val = new_function((&function_386), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  return_location = (&body_167);
}
void body_168();
pointer global_c95c100c101c102c97c117c108c116;
void function_387() {
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  return_location = (&body_168);
}
/* _default */
void body_167() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  apply((&function_387));
}
void body_169();
pointer global_c102c110c95c56c57 = NIL; /* fn_89 */
pointer global_c102c110c95c57c48;
void function_388() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  top_level_apply();
}
void function_389() {
  increment_count(env);
  val = new_function((&function_388), env);
  pop_function();
}
/* fn_90 */
void body_168() {
  increment_count(env);
  val = new_function((&function_389), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  return_location = (&body_169);
}
void body_170();
pointer global_c102c110c95c56c56 = NIL; /* fn_88 */
void function_390() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  top_level_apply();
}
void function_391() {
  increment_count(env);
  val = new_function((&function_390), env);
  pop_function();
}
/* fn_89 */
void body_169() {
  increment_count(env);
  val = new_function((&function_391), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  return_location = (&body_170);
}
void body_171();
pointer global_c102c110c95c56c55 = NIL; /* fn_87 */
pointer global_c102c110c95c56c54 = NIL; /* fn_86 */
void function_392() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_393() {
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
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  apply((&function_392));
}
void function_394() {
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
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  apply((&function_393));
}
void function_395() {
  increment_count(env);
  val = new_function((&function_394), env);
  pop_function();
}
/* fn_88 */
void body_170() {
  increment_count(env);
  val = new_function((&function_395), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  return_location = (&body_171);
}
void body_172();
void function_396() {
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
void function_397() {
  increment_count(env);
  val = new_function((&function_396), env);
  pop_function();
}
/* fn_86 */
void body_171() {
  increment_count(env);
  val = new_function((&function_397), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  return_location = (&body_172);
}
void body_173();
void function_398() {
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
void function_399() {
  increment_count(env);
  val = new_function((&function_398), env);
  pop_function();
}
/* fn_87 */
void body_172() {
  increment_count(env);
  val = new_function((&function_399), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  return_location = (&body_173);
}
void body_174();
pointer global_c95c99c97c115c101;
void function_400() {
  global_c95c99c97c115c101 = val; /* _case */
  return_location = (&body_174);
}
/* _case */
void body_173() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  apply((&function_400));
}
void body_175();
pointer global_c102c110c95c57c49 = NIL; /* fn_91 */
pointer global_c102c110c95c57c50;
void function_401() {
  top_level_apply();
}
void function_402() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_401));
}
void function_403() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  apply((&function_402));
}
void function_404() {
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
  apply((&function_403));
}
void function_405() {
  increment_count(env);
  val = new_function((&function_404), env);
  pop_function();
}
/* fn_92 */
void body_174() {
  increment_count(env);
  val = new_function((&function_405), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  return_location = (&body_175);
}
void body_176();
void function_406() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_407() {
  increment_count(env);
  val = new_function((&function_406), env);
  pop_function();
}
/* fn_91 */
void body_175() {
  increment_count(env);
  val = new_function((&function_407), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  return_location = (&body_176);
}
void body_177();
pointer global_c95c99c104c111c105c99c101;
void function_408() {
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  return_location = (&body_177);
}
/* _choice */
void body_176() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  apply((&function_408));
}
void body_178();
pointer global_c102c110c95c57c52 = NIL; /* fn_94 */
pointer global_c102c110c95c57c53;
void function_409() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  top_level_apply();
}
void function_410() {
  increment_count(env);
  val = new_function((&function_409), env);
  pop_function();
}
/* fn_95 */
void body_177() {
  increment_count(env);
  val = new_function((&function_410), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  return_location = (&body_178);
}
void body_179();
pointer global_c102c110c95c57c51 = NIL; /* fn_93 */
void function_411() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_412() {
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
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  apply((&function_411));
}
void function_413() {
  increment_count(env);
  val = new_function((&function_412), env);
  pop_function();
}
/* fn_94 */
void body_178() {
  increment_count(env);
  val = new_function((&function_413), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  return_location = (&body_179);
}
void body_180();
void function_414() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_414));
}
void function_416() {
  increment_count(env);
  val = new_function((&function_415), env);
  pop_function();
}
/* fn_93 */
void body_179() {
  increment_count(env);
  val = new_function((&function_416), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  return_location = (&body_180);
}
void body_181();
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_417() {
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  return_location = (&body_181);
}
/* _post-process */
void body_180() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  apply((&function_417));
}
void body_182();
pointer global_c102c110c95c57c56 = NIL; /* fn_98 */
pointer global_c102c110c95c57c57;
void function_418() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  top_level_apply();
}
void function_419() {
  increment_count(env);
  val = new_function((&function_418), env);
  pop_function();
}
/* fn_99 */
void body_181() {
  increment_count(env);
  val = new_function((&function_419), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  return_location = (&body_182);
}
void body_183();
pointer global_c102c110c95c57c55 = NIL; /* fn_97 */
void function_420() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_421() {
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
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  apply((&function_420));
}
void function_422() {
  increment_count(env);
  val = new_function((&function_421), env);
  pop_function();
}
/* fn_98 */
void body_182() {
  increment_count(env);
  val = new_function((&function_422), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  return_location = (&body_183);
}
void body_184();
pointer global_c102c110c95c57c54 = NIL; /* fn_96 */
void function_423() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_424() {
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
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  apply((&function_423));
}
void function_425() {
  increment_count(env);
  val = new_function((&function_424), env);
  pop_function();
}
/* fn_97 */
void body_183() {
  increment_count(env);
  val = new_function((&function_425), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  return_location = (&body_184);
}
void body_185();
void function_426() {
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
void function_427() {
  increment_count(env);
  val = new_function((&function_426), env);
  pop_function();
}
/* fn_96 */
void body_184() {
  increment_count(env);
  val = new_function((&function_427), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  return_location = (&body_185);
}
void body_186();
pointer global_c95c115c101c113;
void function_428() {
  global_c95c115c101c113 = val; /* _seq */
  return_location = (&body_186);
}
/* _seq */
void body_185() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  apply((&function_428));
}
void body_187();
pointer global_c102c110c95c49c48c48;
void function_429() {
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  top_level_apply();
}
void function_430() {
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
  apply((&function_429));
}
void function_431() {
  increment_count(env);
  val = new_function((&function_430), env);
  pop_function();
}
/* fn_100 */
void body_186() {
  increment_count(env);
  val = new_function((&function_431), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  return_location = (&body_187);
}
void body_188();
pointer global_c95c101c115c99c97c112c101;
void function_432() {
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  return_location = (&body_188);
}
/* _escape */
void body_187() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  apply((&function_432));
}
void body_189();
pointer global_c102c110c95c49c48c49;
void function_433() {
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
void function_434() {
  increment_count(env);
  val = new_function((&function_433), env);
  pop_function();
}
/* fn_101 */
void body_188() {
  increment_count(env);
  val = new_function((&function_434), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  return_location = (&body_189);
}
void body_190();
pointer global_c95c117c115c101;
void function_435() {
  global_c95c117c115c101 = val; /* _use */
  return_location = (&body_190);
}
/* _use */
void body_189() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  apply((&function_435));
}
void body_191();
pointer global_c102c110c95c49c48c51 = NIL; /* fn_103 */
pointer global_c102c110c95c49c48c52;
void function_436() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  top_level_apply();
}
void function_437() {
  increment_count(env);
  val = new_function((&function_436), env);
  pop_function();
}
/* fn_104 */
void body_190() {
  increment_count(env);
  val = new_function((&function_437), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  return_location = (&body_191);
}
void body_192();
pointer global_c102c110c95c49c48c50 = NIL; /* fn_102 */
void function_438() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_439() {
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
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  apply((&function_438));
}
void function_440() {
  increment_count(env);
  val = new_function((&function_439), env);
  pop_function();
}
/* fn_103 */
void body_191() {
  increment_count(env);
  val = new_function((&function_440), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  return_location = (&body_192);
}
void body_193();
void function_441() {
  top_level_apply();
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_441));
}
void function_443() {
  increment_count(env);
  val = new_function((&function_442), env);
  pop_function();
}
/* fn_102 */
void body_192() {
  increment_count(env);
  val = new_function((&function_443), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  return_location = (&body_193);
}
void body_194();
pointer global_c95c112c101c101c107;
void function_444() {
  global_c95c112c101c101c107 = val; /* _peek */
  return_location = (&body_194);
}
/* _peek */
void body_193() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  apply((&function_444));
}
void body_195();
pointer global_c102c110c95c49c48c53 = NIL; /* fn_105 */
pointer global_c102c110c95c49c48c54;
void function_445() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_446() {
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
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  apply((&function_445));
}
void function_447() {
  increment_count(env);
  val = new_function((&function_446), env);
  pop_function();
}
/* fn_106 */
void body_194() {
  increment_count(env);
  val = new_function((&function_447), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  return_location = (&body_195);
}
void body_196();
void function_448() {
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
void function_449() {
  increment_count(env);
  val = new_function((&function_448), env);
  pop_function();
}
/* fn_105 */
void body_195() {
  increment_count(env);
  val = new_function((&function_449), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  return_location = (&body_196);
}
void body_197();
pointer global_c95c105c110c116c101c114c118c97c108;
void function_450() {
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  return_location = (&body_197);
}
/* _interval */
void body_196() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  apply((&function_450));
}
void body_198();
pointer global_c99c100c114 = CDR; /* cdr */
pointer global_c102c110c95c49c48c55;
void function_451() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_452() {
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
  apply((&function_451));
}
void function_453() {
  increment_count(env);
  val = new_function((&function_452), env);
  pop_function();
}
/* fn_107 */
void body_197() {
  increment_count(env);
  val = new_function((&function_453), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  return_location = (&body_198);
}
void body_199();
pointer global_c95c115c107c105c112;
void function_454() {
  global_c95c115c107c105c112 = val; /* _skip */
  return_location = (&body_199);
}
/* _skip */
void body_198() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  apply((&function_454));
}
void body_200();
pointer global_c99c97c114 = CAR; /* car */
pointer global_c102c110c95c49c48c56;
void function_455() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_456() {
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
  apply((&function_455));
}
void function_457() {
  increment_count(env);
  val = new_function((&function_456), env);
  pop_function();
}
/* fn_108 */
void body_199() {
  increment_count(env);
  val = new_function((&function_457), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  return_location = (&body_200);
}
void body_201();
pointer global_c95c102c105c114c115c116;
void function_458() {
  global_c95c102c105c114c115c116 = val; /* _first */
  return_location = (&body_201);
}
/* _first */
void body_200() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  apply((&function_458));
}
void body_202();
pointer global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
pointer global_c102c110c95c49c48c57;
void function_459() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_460() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_459));
}
void function_461() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_460));
}
void function_462() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_461));
}
void function_463() {
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
  apply((&function_462));
}
void function_464() {
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
  apply((&function_463));
}
void function_465() {
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
  apply((&function_464));
}
void function_466() {
  increment_count(env);
  val = new_function((&function_465), env);
  pop_function();
}
/* fn_109 */
void body_201() {
  increment_count(env);
  val = new_function((&function_466), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  return_location = (&body_202);
}
void body_203();
void function_467() {
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  return_location = (&body_203);
}
/* _parse-num */
void body_202() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  apply((&function_467));
}
void body_204();
pointer global_c102c110c95c49c49c48;
void function_468() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_469() {
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
  apply((&function_468));
}
void function_470() {
  increment_count(env);
  val = new_function((&function_469), env);
  pop_function();
}
/* fn_110 */
void body_203() {
  increment_count(env);
  val = new_function((&function_470), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  return_location = (&body_204);
}
void body_205();
pointer global_c95c114c101c97c100c45c110c117c109;
void function_471() {
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  return_location = (&body_205);
}
/* _read-num */
void body_204() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  apply((&function_471));
}
void body_206();
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
pointer global_c102c110c95c49c49c49;
void function_472() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_473() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_472));
}
void function_474() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_473));
}
void function_475() {
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
  apply((&function_474));
}
void function_476() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_475));
}
void function_477() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_476));
}
void function_478() {
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
  apply((&function_477));
}
void function_479() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_478));
}
void function_480() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_479));
}
void function_481() {
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
  apply((&function_480));
}
void function_482() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_481));
}
void function_483() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_482));
}
void function_484() {
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
  apply((&function_483));
}
void function_485() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_484));
}
void function_486() {
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
  apply((&function_485));
}
void function_487() {
  increment_count(env);
  val = new_function((&function_486), env);
  pop_function();
}
/* fn_111 */
void body_205() {
  increment_count(env);
  val = new_function((&function_487), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  return_location = (&body_206);
}
void body_207();
void function_488() {
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  return_location = (&body_207);
}
/* _parse-symbol */
void body_206() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  apply((&function_488));
}
void body_208();
pointer global_c102c110c95c49c49c50;
void function_489() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_490() {
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
  apply((&function_489));
}
void function_491() {
  increment_count(env);
  val = new_function((&function_490), env);
  pop_function();
}
/* fn_112 */
void body_207() {
  increment_count(env);
  val = new_function((&function_491), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  return_location = (&body_208);
}
void body_209();
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
void function_492() {
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  return_location = (&body_209);
}
/* _read-symbol */
void body_208() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  apply((&function_492));
}
void body_210();
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
pointer global_c102c110c95c49c49c51;
void function_493() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_494() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_493));
}
void function_495() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_494));
}
void function_496() {
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
  apply((&function_495));
}
void function_497() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_496));
}
void function_498() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_497));
}
void function_499() {
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
  apply((&function_498));
}
void function_500() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_499));
}
void function_501() {
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
  apply((&function_500));
}
void function_502() {
  increment_count(env);
  val = new_function((&function_501), env);
  pop_function();
}
/* fn_113 */
void body_209() {
  increment_count(env);
  val = new_function((&function_502), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  return_location = (&body_210);
}
void body_211();
void function_503() {
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  return_location = (&body_211);
}
/* _parse-string */
void body_210() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  apply((&function_503));
}
void body_212();
pointer global_c102c110c95c49c49c52;
void function_504() {
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
void function_505() {
  increment_count(env);
  val = new_function((&function_504), env);
  pop_function();
}
/* fn_114 */
void body_211() {
  increment_count(env);
  val = new_function((&function_505), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  return_location = (&body_212);
}
void body_213();
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_506() {
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  return_location = (&body_213);
}
/* _quote-parser */
void body_212() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  apply((&function_506));
}
void body_214();
pointer global_c102c110c95c49c49c53;
void function_507() {
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
void function_508() {
  increment_count(env);
  val = new_function((&function_507), env);
  pop_function();
}
/* fn_115 */
void body_213() {
  increment_count(env);
  val = new_function((&function_508), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  return_location = (&body_214);
}
void body_215();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_509() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  return_location = (&body_215);
}
/* _quasiquote-parser */
void body_214() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  apply((&function_509));
}
void body_216();
pointer global_c102c110c95c49c49c54;
void function_510() {
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
void function_511() {
  increment_count(env);
  val = new_function((&function_510), env);
  pop_function();
}
/* fn_116 */
void body_215() {
  increment_count(env);
  val = new_function((&function_511), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  return_location = (&body_216);
}
void body_217();
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_512() {
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  return_location = (&body_217);
}
/* _unquote-parser */
void body_216() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  apply((&function_512));
}
void body_218();
pointer global_c102c110c95c49c49c55 = NIL; /* fn_117 */
pointer global_c102c110c95c49c49c56;
void function_513() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  top_level_apply();
}
void function_514() {
  increment_count(env);
  val = new_function((&function_513), env);
  pop_function();
}
/* fn_118 */
void body_217() {
  increment_count(env);
  val = new_function((&function_514), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  return_location = (&body_218);
}
void body_219();
pointer global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
void function_515() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_516() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_515));
}
void function_517() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_516));
}
void function_518() {
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
  apply((&function_517));
}
void function_519() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_518));
}
void function_520() {
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
  apply((&function_519));
}
void function_521() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_520));
}
void function_522() {
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  apply((&function_521));
}
void function_523() {
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
  apply((&function_522));
}
void function_524() {
  increment_count(env);
  val = new_function((&function_523), env);
  pop_function();
}
/* fn_117 */
void body_218() {
  increment_count(env);
  val = new_function((&function_524), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  return_location = (&body_219);
}
void body_220();
void function_525() {
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  return_location = (&body_220);
}
/* _comment */
void body_219() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  apply((&function_525));
}
void body_221();
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
pointer global_c102c110c95c49c49c57;
void function_526() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_527() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_526));
}
void function_528() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_527));
}
void function_529() {
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
  apply((&function_528));
}
void function_530() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_529));
}
void function_531() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_530));
}
void function_532() {
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
  apply((&function_531));
}
void function_533() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_532));
}
void function_534() {
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
  apply((&function_533));
}
void function_535() {
  increment_count(env);
  val = new_function((&function_534), env);
  pop_function();
}
/* fn_119 */
void body_220() {
  increment_count(env);
  val = new_function((&function_535), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  return_location = (&body_221);
}
void body_222();
void function_536() {
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  return_location = (&body_222);
}
/* _parse-paren */
void body_221() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  apply((&function_536));
}
void body_223();
pointer global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
pointer global_c102c110c95c49c50c48;
void function_537() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_538() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_537));
}
void function_539() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_538));
}
void function_540() {
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
  apply((&function_539));
}
void function_541() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_540));
}
void function_542() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_541));
}
void function_543() {
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
  apply((&function_542));
}
void function_544() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_543));
}
void function_545() {
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
  apply((&function_544));
}
void function_546() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_545));
}
void function_547() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_546));
}
void function_548() {
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
  apply((&function_547));
}
void function_549() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_548));
}
void function_550() {
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
  apply((&function_549));
}
void function_551() {
  increment_count(env);
  val = new_function((&function_550), env);
  pop_function();
}
/* fn_120 */
void body_222() {
  increment_count(env);
  val = new_function((&function_551), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  return_location = (&body_223);
}
void body_224();
void function_552() {
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  return_location = (&body_224);
}
/* _parse-pair */
void body_223() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  apply((&function_552));
}
void body_225();
pointer global_c102c110c95c49c50c49;
void function_553() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_554() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_553));
}
void function_555() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_554));
}
void function_556() {
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
  apply((&function_555));
}
void function_557() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_556));
}
void function_558() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_557));
}
void function_559() {
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
  apply((&function_558));
}
void function_560() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_559));
}
void function_561() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_560));
}
void function_562() {
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
  apply((&function_561));
}
void function_563() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_562));
}
void function_564() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_563));
}
void function_565() {
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
  apply((&function_564));
}
void function_566() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_565));
}
void function_567() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_566));
}
void function_568() {
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
  apply((&function_567));
}
void function_569() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_568));
}
void function_570() {
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
  apply((&function_569));
}
void function_571() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_570));
}
void function_572() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_571));
}
void function_573() {
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
  apply((&function_572));
}
void function_574() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_573));
}
void function_575() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_574));
}
void function_576() {
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
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_577));
}
void function_579() {
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
  apply((&function_578));
}
void function_580() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_579));
}
void function_581() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_580));
}
void function_582() {
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
  apply((&function_581));
}
void function_583() {
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
  apply((&function_582));
}
void function_584() {
  increment_count(env);
  val = new_function((&function_583), env);
  pop_function();
}
/* fn_121 */
void body_224() {
  increment_count(env);
  val = new_function((&function_584), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  return_location = (&body_225);
}
void body_226();
void function_585() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_226);
}
/* _parse-expr */
void body_225() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  apply((&function_585));
}
void body_227();
pointer global_c102c110c95c49c50c50 = NIL; /* fn_122 */
pointer global_c102c110c95c49c50c51;
void function_586() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  top_level_apply();
}
void function_587() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  apply((&function_586));
}
void function_588() {
  increment_count(env);
  val = new_function((&function_587), env);
  pop_function();
}
/* fn_123 */
void body_226() {
  increment_count(env);
  val = new_function((&function_588), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  return_location = (&body_227);
}
void body_228();
void function_589() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ___print-error */
  top_level_apply();
}
void function_590() {
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c55); /* __l_27 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_589));
}
void function_591() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c95c50c57); /* __l_29 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c108c95c50c56); /* __l_28 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  apply((&function_590));
}
void function_592() {
  increment_count(env);
  val = new_function((&function_591), env);
  pop_function();
}
/* fn_122 */
void body_227() {
  increment_count(env);
  val = new_function((&function_592), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  return_location = (&body_228);
}
void body_229();
pointer global_c95c95c95c114c101c97c100c45c101c120c112c114;
void function_593() {
  global_c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ___read-expr */
  return_location = (&body_229);
}
/* ___read-expr */
void body_228() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  apply((&function_593));
}
void body_230();
pointer global_c95c95c108c95c51c48;
/* __l_30 */
void body_229() {
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
  global_c95c95c108c95c51c48 = val; /* __l_30 */
  return_location = (&body_230);
}
void body_231();
pointer global_c95c95c108c95c51c49;
/* __l_31 */
void body_230() {
  val = -35;
  global_c95c95c108c95c51c49 = val; /* __l_31 */
  return_location = (&body_231);
}
void body_232();
pointer global_c95c95c108c95c51c50;
/* __l_32 */
void body_231() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c108c95c51c50 = val; /* __l_32 */
  return_location = (&body_232);
}
void body_233();
pointer global_c95c95c108c95c51c51;
/* __l_33 */
void body_232() {
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
  global_c95c95c108c95c51c51 = val; /* __l_33 */
  return_location = (&body_233);
}
void body_234();
pointer global_c102c110c95c49c50c52;
void function_594() {
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
void function_595() {
  increment_count(env);
  val = new_function((&function_594), env);
  pop_function();
}
/* fn_124 */
void body_233() {
  increment_count(env);
  val = new_function((&function_595), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  return_location = (&body_234);
}
void body_235();
pointer global_c95c99c97c97c100c114;
void function_596() {
  global_c95c99c97c97c100c114 = val; /* _caadr */
  return_location = (&body_235);
}
/* _caadr */
void body_234() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  apply((&function_596));
}
void body_236();
pointer global_c102c110c95c49c50c53 = NIL; /* fn_125 */
pointer global_c102c110c95c49c50c54;
void function_597() {
  top_level_apply();
}
void function_598() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_597));
}
void function_599() {
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
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  apply((&function_598));
}
void function_600() {
  increment_count(env);
  val = new_function((&function_599), env);
  pop_function();
}
/* fn_126 */
void body_235() {
  increment_count(env);
  val = new_function((&function_600), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  return_location = (&body_236);
}
void body_237();
void function_601() {
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
void function_602() {
  increment_count(env);
  val = new_function((&function_601), env);
  pop_function();
}
/* fn_125 */
void body_236() {
  increment_count(env);
  val = new_function((&function_602), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  return_location = (&body_237);
}
void body_238();
pointer global_c95c111c114;
void function_603() {
  global_c95c111c114 = val; /* _or */
  return_location = (&body_238);
}
/* _or */
void body_237() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  apply((&function_603));
}
void body_239();
pointer global_c102c110c95c49c50c55;
void function_604() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    val = -34;
    pop_function();
  }
}
void function_605() {
  increment_count(env);
  val = new_function((&function_604), env);
  pop_function();
}
/* fn_127 */
void body_238() {
  increment_count(env);
  val = new_function((&function_605), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  return_location = (&body_239);
}
void body_240();
pointer global_c95c110c111c116;
void function_606() {
  global_c95c110c111c116 = val; /* _not */
  return_location = (&body_240);
}
/* _not */
void body_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  apply((&function_606));
}
void body_241();
pointer global_c102c110c95c49c51c48 = NIL; /* fn_130 */
pointer global_c102c110c95c49c51c49;
void function_607() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  top_level_apply();
}
void function_608() {
  increment_count(env);
  val = new_function((&function_607), env);
  pop_function();
}
/* fn_131 */
void body_240() {
  increment_count(env);
  val = new_function((&function_608), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  return_location = (&body_241);
}
void body_242();
pointer global_c102c110c95c49c50c57 = NIL; /* fn_129 */
pointer global_c102c110c95c49c50c56 = NIL; /* fn_128 */
void function_609() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101); /* ___compile */
  top_level_apply();
}
void function_610() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101); /* ___compile */
  top_level_apply();
}
void function_611() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c51c51); /* __l_33 */
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
    apply((&function_610));
  }
}
void function_612() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_611));
}
void function_613() {
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  apply((&function_612));
}
void function_614() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_613));
}
void function_615() {
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
  apply((&function_614));
}
void function_616() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_615));
}
void function_617() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
    apply((&function_609));
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
    apply((&function_616));
  }
}
void function_618() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_617));
}
void function_619() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c95c51c48); /* __l_30 */
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
    increment_count(val = global_c95c95c108c95c51c49); /* __l_31 */
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
    apply((&function_618));
  }
}
void function_620() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_619));
}
void function_621() {
  increment_count(env);
  val = new_function((&function_620), env);
  pop_function();
}
/* fn_130 */
void body_241() {
  increment_count(env);
  val = new_function((&function_621), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  return_location = (&body_242);
}
void body_243();
void function_622() {
  increment_count(val = global_c95c95c108c95c51c50); /* __l_32 */
  pop_function();
}
void function_623() {
  increment_count(env);
  val = new_function((&function_622), env);
  pop_function();
}
/* fn_128 */
void body_242() {
  increment_count(env);
  val = new_function((&function_623), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  return_location = (&body_243);
}
void body_244();
pointer global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ___compile-source */
void function_624() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_625() {
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ___compile-source */
  apply((&function_624));
}
void function_626() {
  increment_count(env);
  val = new_function((&function_625), env);
  pop_function();
}
/* fn_129 */
void body_243() {
  increment_count(env);
  val = new_function((&function_626), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  return_location = (&body_244);
}
void body_245();
void function_627() {
  global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ___compile-source */
  return_location = (&body_245);
}
/* ___compile-source */
void body_244() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  apply((&function_627));
}
void body_246();
pointer global_c102c110c95c49c51c50;
void function_628() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c101c97c100c45c101c120c112c114); /* ___read-expr */
  top_level_apply();
}
void function_629() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ___compile-source */
  apply((&function_628));
}
void function_630() {
  increment_count(env);
  val = new_function((&function_629), env);
  pop_function();
}
/* fn_132 */
void body_245() {
  increment_count(env);
  val = new_function((&function_630), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  return_location = (&body_246);
}
void function_631() {
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
void body_246() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
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
    call_stack = cons(new_function((&function_631), NIL), call_stack);
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
  call_stack = cons(new_function((&function_631), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
