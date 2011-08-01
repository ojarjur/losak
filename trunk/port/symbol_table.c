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
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -47;
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
    val = -47;
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
    val = EQ;
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
    apply((&function_10));
  }
}
void function_12() {
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
    val = new_number(61);
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
    val = BNEG;
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
    apply((&function_12));
  }
}
void function_14() {
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
    val = new_number(126);
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
    apply((&function_14));
  }
}
void function_16() {
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
    apply((&function_15));
  }
}
void function_17() {
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
    val = new_number(38);
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
    apply((&function_17));
  }
}
void function_19() {
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
    apply((&function_18));
  }
}
void function_20() {
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
    apply((&function_19));
  }
}
void function_21() {
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
    apply((&function_20));
  }
}
void function_22() {
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
    apply((&function_21));
  }
}
void function_23() {
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
    apply((&function_22));
  }
}
void function_24() {
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
    val = new_number(60);
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
    val = SRSHIFT;
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
    apply((&function_24));
  }
}
void function_26() {
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
    apply((&function_25));
  }
}
void function_27() {
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
    apply((&function_26));
  }
}
void function_28() {
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
    apply((&function_27));
  }
}
void function_29() {
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
    apply((&function_28));
  }
}
void function_30() {
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
    apply((&function_29));
  }
}
void function_31() {
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
    increment_count(val = global_c95c101c113c117c97c108); /* _equal */
    apply((&function_32));
  }
}
void function_34() {
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
    apply((&function_33));
  }
}
void function_35() {
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
    apply((&function_37));
  }
}
void function_39() {
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
    val = new_number(116);
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
    val = -45;
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
    apply((&function_39));
  }
}
void function_41() {
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
    val = new_number(61);
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
  apply((&function_41));
}
void function_43() {
  increment_count(env);
  val = new_function((&function_42), env);
  pop_function();
}
/* fn_2 */
void body_4() {
  increment_count(env);
  val = new_function((&function_43), env);
  global_c102c110c95c50 = val; /* fn_2 */
  return_location = (&body_5);
}
void body_6();
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
void function_44() {
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  return_location = (&body_6);
}
/* _string->symbol */
void body_5() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  apply((&function_44));
}
void body_7();
pointer global_c102c110c95c51;
void function_45() {
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
          val = -43;
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -47;
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
            val = -43;
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
void function_46() {
  increment_count(env);
  val = new_function((&function_45), env);
  pop_function();
}
/* fn_3 */
void body_6() {
  increment_count(env);
  val = new_function((&function_46), env);
  global_c102c110c95c51 = val; /* fn_3 */
  return_location = (&body_7);
}
void body_8();
pointer global_c95c115c121c109c98c111c108c63;
void function_47() {
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  return_location = (&body_8);
}
/* _symbol? */
void body_7() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  apply((&function_47));
}
void body_9();
pointer global_c102c110c95c52;
void function_48() {
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
    val = -43;
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -47;
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
      val = -43;
      pop_function();
    } else {
      val = NIL;
      pop_function();
    }
  }
}
void function_49() {
  increment_count(env);
  val = new_function((&function_48), env);
  pop_function();
}
/* fn_4 */
void body_8() {
  increment_count(env);
  val = new_function((&function_49), env);
  global_c102c110c95c52 = val; /* fn_4 */
  return_location = (&body_9);
}
void body_10();
pointer global_c95c95c97c116c111c109;
void function_50() {
  global_c95c95c97c116c111c109 = val; /* __atom */
  return_location = (&body_10);
}
/* __atom */
void body_9() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  apply((&function_50));
}
void body_11();
pointer global_c102c110c95c53;
void function_51() {
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
void function_52() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_51));
}
void function_53() {
  increment_count(env);
  val = new_function((&function_52), env);
  pop_function();
}
/* fn_5 */
void body_10() {
  increment_count(env);
  val = new_function((&function_53), env);
  global_c102c110c95c53 = val; /* fn_5 */
  return_location = (&body_11);
}
void body_12();
pointer global_c95c95c61;
void function_54() {
  global_c95c95c61 = val; /* __= */
  return_location = (&body_12);
}
/* __= */
void body_11() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  apply((&function_54));
}
void body_13();
pointer global_c102c110c95c54;
void function_55() {
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
void function_56() {
  increment_count(env);
  val = new_function((&function_55), env);
  pop_function();
}
/* fn_6 */
void body_12() {
  increment_count(env);
  val = new_function((&function_56), env);
  global_c102c110c95c54 = val; /* fn_6 */
  return_location = (&body_13);
}
void body_14();
pointer global_c95c99c97c97c114;
void function_57() {
  global_c95c99c97c97c114 = val; /* _caar */
  return_location = (&body_14);
}
/* _caar */
void body_13() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  apply((&function_57));
}
void body_15();
pointer global_c102c110c95c55;
void function_58() {
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
void function_59() {
  increment_count(env);
  val = new_function((&function_58), env);
  pop_function();
}
/* fn_7 */
void body_14() {
  increment_count(env);
  val = new_function((&function_59), env);
  global_c102c110c95c55 = val; /* fn_7 */
  return_location = (&body_15);
}
void body_16();
pointer global_c95c99c100c97c114;
void function_60() {
  global_c95c99c100c97c114 = val; /* _cdar */
  return_location = (&body_16);
}
/* _cdar */
void body_15() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  apply((&function_60));
}
void body_17();
pointer global_c102c110c95c56;
void function_61() {
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
void function_62() {
  increment_count(env);
  val = new_function((&function_61), env);
  pop_function();
}
/* fn_8 */
void body_16() {
  increment_count(env);
  val = new_function((&function_62), env);
  global_c102c110c95c56 = val; /* fn_8 */
  return_location = (&body_17);
}
void body_18();
pointer global_c95c99c97c100c114;
void function_63() {
  global_c95c99c97c100c114 = val; /* _cadr */
  return_location = (&body_18);
}
/* _cadr */
void body_17() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  apply((&function_63));
}
void body_19();
pointer global_c102c110c95c57;
void function_64() {
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
void function_65() {
  increment_count(env);
  val = new_function((&function_64), env);
  pop_function();
}
/* fn_9 */
void body_18() {
  increment_count(env);
  val = new_function((&function_65), env);
  global_c102c110c95c57 = val; /* fn_9 */
  return_location = (&body_19);
}
void body_20();
pointer global_c95c99c100c100c114;
void function_66() {
  global_c95c99c100c100c114 = val; /* _cddr */
  return_location = (&body_20);
}
/* _cddr */
void body_19() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  apply((&function_66));
}
void body_21();
pointer global_c102c110c95c49c48;
void function_67() {
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
void function_68() {
  increment_count(env);
  val = new_function((&function_67), env);
  pop_function();
}
/* fn_10 */
void body_20() {
  increment_count(env);
  val = new_function((&function_68), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  return_location = (&body_21);
}
void body_22();
pointer global_c95c99c97c97c97c114;
void function_69() {
  global_c95c99c97c97c97c114 = val; /* _caaar */
  return_location = (&body_22);
}
/* _caaar */
void body_21() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  apply((&function_69));
}
void body_23();
pointer global_c102c110c95c49c49;
void function_70() {
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
void function_71() {
  increment_count(env);
  val = new_function((&function_70), env);
  pop_function();
}
/* fn_11 */
void body_22() {
  increment_count(env);
  val = new_function((&function_71), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  return_location = (&body_23);
}
void body_24();
pointer global_c95c99c97c97c100c114;
void function_72() {
  global_c95c99c97c97c100c114 = val; /* _caadr */
  return_location = (&body_24);
}
/* _caadr */
void body_23() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  apply((&function_72));
}
void body_25();
pointer global_c102c110c95c49c50;
void function_73() {
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
void function_74() {
  increment_count(env);
  val = new_function((&function_73), env);
  pop_function();
}
/* fn_12 */
void body_24() {
  increment_count(env);
  val = new_function((&function_74), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  return_location = (&body_25);
}
void body_26();
pointer global_c95c99c97c100c97c114;
void function_75() {
  global_c95c99c97c100c97c114 = val; /* _cadar */
  return_location = (&body_26);
}
/* _cadar */
void body_25() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  apply((&function_75));
}
void body_27();
pointer global_c102c110c95c49c51;
void function_76() {
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
void function_77() {
  increment_count(env);
  val = new_function((&function_76), env);
  pop_function();
}
/* fn_13 */
void body_26() {
  increment_count(env);
  val = new_function((&function_77), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  return_location = (&body_27);
}
void body_28();
pointer global_c95c99c97c100c100c114;
void function_78() {
  global_c95c99c97c100c100c114 = val; /* _caddr */
  return_location = (&body_28);
}
/* _caddr */
void body_27() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  apply((&function_78));
}
void body_29();
pointer global_c102c110c95c49c52;
void function_79() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_80() {
  increment_count(env);
  val = new_function((&function_79), env);
  pop_function();
}
/* fn_14 */
void body_28() {
  increment_count(env);
  val = new_function((&function_80), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  return_location = (&body_29);
}
void body_30();
pointer global_c95c105c100;
void function_81() {
  global_c95c105c100 = val; /* _id */
  return_location = (&body_30);
}
/* _id */
void body_29() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  apply((&function_81));
}
void body_31();
pointer global_c102c110c95c49c53;
void function_82() {
  increment_count(val = car(env));
  pop_function();
}
void function_83() {
  increment_count(env);
  val = new_function((&function_82), env);
  pop_function();
}
/* fn_15 */
void body_30() {
  increment_count(env);
  val = new_function((&function_83), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  return_location = (&body_31);
}
void body_32();
pointer global_c95c108c105c115c116;
void function_84() {
  global_c95c108c105c115c116 = val; /* _list */
  return_location = (&body_32);
}
/* _list */
void body_31() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  apply((&function_84));
}
void body_33();
pointer global_c102c110c95c49c54;
void function_85() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_86() {
  increment_count(env);
  val = new_function((&function_85), env);
  pop_function();
}
/* fn_16 */
void body_32() {
  increment_count(env);
  val = new_function((&function_86), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  return_location = (&body_33);
}
void body_34();
pointer global_c95c97c112c112c108c121;
void function_87() {
  global_c95c97c112c112c108c121 = val; /* _apply */
  return_location = (&body_34);
}
/* _apply */
void body_33() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  apply((&function_87));
}
void body_35();
pointer global_c102c110c95c50c48 = NIL; /* fn_20 */
pointer global_c102c110c95c49c56 = NIL; /* fn_18 */
pointer global_c102c110c95c50c49;
void function_88() {
  top_level_apply();
}
void function_89() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  apply((&function_88));
}
void function_90() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  apply((&function_89));
}
void function_91() {
  increment_count(env);
  val = new_function((&function_90), env);
  pop_function();
}
/* fn_21 */
void body_34() {
  increment_count(env);
  val = new_function((&function_91), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  return_location = (&body_35);
}
void body_36();
pointer global_c102c110c95c49c55 = NIL; /* fn_17 */
void function_92() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_93() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  apply((&function_92));
}
void function_94() {
  increment_count(env);
  val = new_function((&function_93), env);
  pop_function();
}
/* fn_18 */
void body_35() {
  increment_count(env);
  val = new_function((&function_94), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  return_location = (&body_36);
}
void body_37();
void function_95() {
  top_level_apply();
}
void function_96() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_95));
}
void function_97() {
  increment_count(env);
  val = new_function((&function_96), env);
  pop_function();
}
/* fn_17 */
void body_36() {
  increment_count(env);
  val = new_function((&function_97), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  return_location = (&body_37);
}
void body_38();
pointer global_c102c110c95c49c57 = NIL; /* fn_19 */
void function_98() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_99() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  apply((&function_98));
}
void function_100() {
  increment_count(env);
  val = new_function((&function_99), env);
  pop_function();
}
/* fn_20 */
void body_37() {
  increment_count(env);
  val = new_function((&function_100), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  return_location = (&body_38);
}
void body_39();
void function_101() {
  top_level_apply();
}
void function_102() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_101));
}
void function_103() {
  increment_count(env);
  val = new_function((&function_102), env);
  pop_function();
}
/* fn_19 */
void body_38() {
  increment_count(env);
  val = new_function((&function_103), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  return_location = (&body_39);
}
void body_40();
pointer global_c95c95c95c95c114c101c99c117c114c115c101;
void function_104() {
  global_c95c95c95c95c114c101c99c117c114c115c101 = val; /* ____recurse */
  return_location = (&body_40);
}
/* ____recurse */
void body_39() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  apply((&function_104));
}
void body_41();
pointer global_c102c110c95c50c50 = NIL; /* fn_22 */
pointer global_c102c110c95c50c51;
void function_105() {
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
void function_106() {
  increment_count(env);
  val = new_function((&function_105), env);
  pop_function();
}
/* fn_23 */
void body_40() {
  increment_count(env);
  val = new_function((&function_106), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  return_location = (&body_41);
}
void body_42();
pointer global_c95c95c95c95c119c97c108c107 = NIL; /* ____walk */
void function_107() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_108() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_107));
}
void function_109() {
  apply((&function_108));
}
void function_110() {
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
  increment_count(val = global_c95c95c95c95c119c97c108c107); /* ____walk */
  apply((&function_109));
}
void function_111() {
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
    apply((&function_110));
  }
}
void function_112() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_111));
}
void function_113() {
  increment_count(env);
  val = new_function((&function_112), env);
  pop_function();
}
/* fn_22 */
void body_41() {
  increment_count(env);
  val = new_function((&function_113), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  return_location = (&body_42);
}
void body_43();
void function_114() {
  global_c95c95c95c95c119c97c108c107 = val; /* ____walk */
  return_location = (&body_43);
}
/* ____walk */
void body_42() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  apply((&function_114));
}
void body_44();
pointer global_c95c95c95c95c114c114c101c118c101c114c115c101 = NIL; /* ____rreverse */
pointer global_c102c110c95c50c52;
void function_115() {
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
    increment_count(val = global_c95c95c95c95c114c114c101c118c101c114c115c101); /* ____rreverse */
    top_level_apply();
  }
}
void function_116() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_115));
}
void function_117() {
  increment_count(env);
  val = new_function((&function_116), env);
  pop_function();
}
/* fn_24 */
void body_43() {
  increment_count(env);
  val = new_function((&function_117), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  return_location = (&body_44);
}
void body_45();
void function_118() {
  global_c95c95c95c95c114c114c101c118c101c114c115c101 = val; /* ____rreverse */
  return_location = (&body_45);
}
/* ____rreverse */
void body_44() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  apply((&function_118));
}
void body_46();
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
void body_45() {
  val = NIL;
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  return_location = (&body_46);
}
void body_47();
pointer global_c102c110c95c50c53;
void function_119() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c105c100); /* _id */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51); /* ___l_3 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c114c101c118c101c114c115c101); /* ____rreverse */
  top_level_apply();
}
void function_120() {
  increment_count(env);
  val = new_function((&function_119), env);
  pop_function();
}
/* fn_25 */
void body_46() {
  increment_count(env);
  val = new_function((&function_120), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  return_location = (&body_47);
}
void body_48();
pointer global_c95c114c101c118c101c114c115c101;
void function_121() {
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  return_location = (&body_48);
}
/* _reverse */
void body_47() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  apply((&function_121));
}
void body_49();
pointer global_c102c110c95c50c54 = NIL; /* fn_26 */
pointer global_c102c110c95c50c55;
void function_122() {
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
void function_123() {
  increment_count(env);
  val = new_function((&function_122), env);
  pop_function();
}
/* fn_27 */
void body_48() {
  increment_count(env);
  val = new_function((&function_123), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  return_location = (&body_49);
}
void body_50();
pointer global_c95c102c111c108c100c108 = NIL; /* _foldl */
void function_124() {
  top_level_apply();
}
void function_125() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_124));
}
void function_126() {
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
    apply((&function_125));
  }
}
void function_127() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_126));
}
void function_128() {
  increment_count(env);
  val = new_function((&function_127), env);
  pop_function();
}
/* fn_26 */
void body_49() {
  increment_count(env);
  val = new_function((&function_128), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  return_location = (&body_50);
}
void body_51();
void function_129() {
  global_c95c102c111c108c100c108 = val; /* _foldl */
  return_location = (&body_51);
}
/* _foldl */
void body_50() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  apply((&function_129));
}
void body_52();
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
void body_51() {
  val = NIL;
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  return_location = (&body_52);
}
void body_53();
pointer global_c102c110c95c50c56 = NIL; /* fn_28 */
pointer global_c102c110c95c50c57;
void function_130() {
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
void function_131() {
  increment_count(env);
  val = new_function((&function_130), env);
  pop_function();
}
/* fn_29 */
void body_52() {
  increment_count(env);
  val = new_function((&function_131), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  return_location = (&body_53);
}
void body_54();
void function_132() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52); /* ___l_4 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c114c101c118c101c114c115c101); /* ____rreverse */
  top_level_apply();
}
void function_133() {
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
  apply((&function_132));
}
void function_134() {
  increment_count(env);
  val = new_function((&function_133), env);
  pop_function();
}
/* fn_28 */
void body_53() {
  increment_count(env);
  val = new_function((&function_134), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  return_location = (&body_54);
}
void body_55();
pointer global_c95c102c111c108c100c114;
void function_135() {
  global_c95c102c111c108c100c114 = val; /* _foldr */
  return_location = (&body_55);
}
/* _foldr */
void body_54() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  apply((&function_135));
}
void body_56();
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
void body_55() {
  val = NIL;
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  return_location = (&body_56);
}
void body_57();
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
void body_56() {
  val = NIL;
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  return_location = (&body_57);
}
void body_58();
pointer global_c102c110c95c51c48 = NIL; /* fn_30 */
pointer global_c102c110c95c51c49;
void function_136() {
  top_level_apply();
}
void function_137() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_136));
}
void function_138() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c54); /* ___l_6 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  apply((&function_137));
}
void function_139() {
  increment_count(env);
  val = new_function((&function_138), env);
  pop_function();
}
/* fn_31 */
void body_57() {
  increment_count(env);
  val = new_function((&function_139), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  return_location = (&body_58);
}
void body_59();
pointer global_c99c111c110c115 = CONS; /* cons */
void function_140() {
  top_level_apply();
}
void function_141() {
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
    apply((&function_140));
  }
}
void function_142() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c53); /* ___l_5 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_141));
}
void function_143() {
  increment_count(env);
  val = new_function((&function_142), env);
  pop_function();
}
/* fn_30 */
void body_58() {
  increment_count(env);
  val = new_function((&function_143), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  return_location = (&body_59);
}
void body_60();
pointer global_c95c97c112c112c101c110c100;
void function_144() {
  global_c95c97c112c112c101c110c100 = val; /* _append */
  return_location = (&body_60);
}
/* _append */
void body_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  apply((&function_144));
}
void body_61();
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
void body_60() {
  val = NIL;
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  return_location = (&body_61);
}
void body_62();
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
void body_61() {
  val = NIL;
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  return_location = (&body_62);
}
void body_63();
pointer global_c95c95c101c113c117c97c108 = NIL; /* __equal */
pointer global_c102c110c95c51c50;
void function_145() {
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
    increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
    pop_function();
  }
}
void function_146() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
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
    apply((&function_145));
  }
}
void function_147() {
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
    apply((&function_146));
  }
}
void function_148() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_147));
}
void function_149() {
  increment_count(env);
  val = new_function((&function_148), env);
  pop_function();
}
/* fn_32 */
void body_62() {
  increment_count(env);
  val = new_function((&function_149), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  return_location = (&body_63);
}
void body_64();
void function_150() {
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  return_location = (&body_64);
}
/* __equal */
void body_63() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  apply((&function_150));
}
void body_65();
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
void body_64() {
  val = NIL;
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  return_location = (&body_65);
}
void body_66();
pointer global_c102c110c95c51c51 = NIL; /* fn_33 */
pointer global_c102c110c95c51c52;
void function_151() {
  top_level_apply();
}
void function_152() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_151));
}
void function_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  apply((&function_152));
}
void function_154() {
  increment_count(env);
  val = new_function((&function_153), env);
  pop_function();
}
/* fn_34 */
void body_65() {
  increment_count(env);
  val = new_function((&function_154), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  return_location = (&body_66);
}
void body_67();
void function_155() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_156() {
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
  apply((&function_155));
}
void function_157() {
  increment_count(env);
  val = new_function((&function_156), env);
  pop_function();
}
/* fn_33 */
void body_66() {
  increment_count(env);
  val = new_function((&function_157), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  return_location = (&body_67);
}
void body_68();
pointer global_c95c109c97c112;
void function_158() {
  global_c95c109c97c112 = val; /* _map */
  return_location = (&body_68);
}
/* _map */
void body_67() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  apply((&function_158));
}
void body_69();
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
void body_68() {
  val = NIL;
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  return_location = (&body_69);
}
void body_70();
pointer global_c102c110c95c51c53 = NIL; /* fn_35 */
pointer global_c102c110c95c51c54;
void function_159() {
  top_level_apply();
}
void function_160() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_159));
}
void function_161() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  apply((&function_160));
}
void function_162() {
  increment_count(env);
  val = new_function((&function_161), env);
  pop_function();
}
/* fn_36 */
void body_69() {
  increment_count(env);
  val = new_function((&function_162), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  return_location = (&body_70);
}
void body_71();
void function_163() {
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
void function_164() {
  increment_count(env);
  val = new_function((&function_163), env);
  pop_function();
}
/* fn_35 */
void body_70() {
  increment_count(env);
  val = new_function((&function_164), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  return_location = (&body_71);
}
void body_72();
pointer global_c95c111c114;
void function_165() {
  global_c95c111c114 = val; /* _or */
  return_location = (&body_72);
}
/* _or */
void body_71() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  apply((&function_165));
}
void body_73();
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
void body_72() {
  val = NIL;
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  return_location = (&body_73);
}
void body_74();
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
void body_73() {
  val = -43;
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  return_location = (&body_74);
}
void body_75();
pointer global_c102c110c95c51c55 = NIL; /* fn_37 */
pointer global_c102c110c95c51c56;
void function_166() {
  top_level_apply();
}
void function_167() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_166));
}
void function_168() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50); /* ___l_12 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  apply((&function_167));
}
void function_169() {
  increment_count(env);
  val = new_function((&function_168), env);
  pop_function();
}
/* fn_38 */
void body_74() {
  increment_count(env);
  val = new_function((&function_169), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  return_location = (&body_75);
}
void body_76();
void function_170() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
    pop_function();
  }
}
void function_171() {
  increment_count(env);
  val = new_function((&function_170), env);
  pop_function();
}
/* fn_37 */
void body_75() {
  increment_count(env);
  val = new_function((&function_171), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  return_location = (&body_76);
}
void body_77();
pointer global_c95c97c110c100;
void function_172() {
  global_c95c97c110c100 = val; /* _and */
  return_location = (&body_77);
}
/* _and */
void body_76() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  apply((&function_172));
}
void body_78();
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
void body_77() {
  val = NIL;
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  return_location = (&body_78);
}
void body_79();
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
void body_78() {
  val = -43;
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  return_location = (&body_79);
}
void body_80();
pointer global_c102c110c95c51c57;
void function_173() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
    pop_function();
  } else {
    increment_count(val = global_c95c95c95c108c95c49c52); /* ___l_14 */
    pop_function();
  }
}
void function_174() {
  increment_count(env);
  val = new_function((&function_173), env);
  pop_function();
}
/* fn_39 */
void body_79() {
  increment_count(env);
  val = new_function((&function_174), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  return_location = (&body_80);
}
void body_81();
pointer global_c95c110c111c116;
void function_175() {
  global_c95c110c111c116 = val; /* _not */
  return_location = (&body_81);
}
/* _not */
void body_80() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  apply((&function_175));
}
void body_82();
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
void body_81() {
  val = -43;
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  return_location = (&body_82);
}
void body_83();
pointer global_c102c110c95c52c48 = NIL; /* fn_40 */
pointer global_c102c110c95c52c49;
void function_176() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  top_level_apply();
}
void function_177() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  apply((&function_176));
}
void function_178() {
  increment_count(env);
  val = new_function((&function_177), env);
  pop_function();
}
/* fn_41 */
void body_82() {
  increment_count(env);
  val = new_function((&function_178), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  return_location = (&body_83);
}
void body_84();
void function_179() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53); /* ___l_15 */
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_180() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_179));
}
void function_181() {
  increment_count(env);
  val = new_function((&function_180), env);
  pop_function();
}
/* fn_40 */
void body_83() {
  increment_count(env);
  val = new_function((&function_181), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  return_location = (&body_84);
}
void body_85();
pointer global_c95c95c95c95c99c111c110c116c97c105c110c115;
void function_182() {
  global_c95c95c95c95c99c111c110c116c97c105c110c115 = val; /* ____contains */
  return_location = (&body_85);
}
/* ____contains */
void body_84() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  apply((&function_182));
}
void body_86();
pointer global_c102c110c95c52c50;
void function_183() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_184() {
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
  apply((&function_183));
}
void function_185() {
  increment_count(env);
  val = new_function((&function_184), env);
  pop_function();
}
/* fn_42 */
void body_85() {
  increment_count(env);
  val = new_function((&function_185), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  return_location = (&body_86);
}
void body_87();
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
void function_186() {
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  return_location = (&body_87);
}
void function_187() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_186));
}
/* ____map-to-stderr */
void body_86() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  apply((&function_187));
}
void body_88();
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
void body_87() {
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
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  return_location = (&body_88);
}
void body_89();
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
void body_88() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  return_location = (&body_89);
}
void body_90();
pointer global_c102c110c95c52c51;
void function_188() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  top_level_apply();
}
void function_189() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55); /* ___l_17 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_188));
}
void function_190() {
  increment_count(env);
  val = new_function((&function_189), env);
  pop_function();
}
/* fn_43 */
void body_89() {
  increment_count(env);
  val = new_function((&function_190), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  return_location = (&body_90);
}
void body_91();
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
void function_191() {
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  return_location = (&body_91);
}
/* ____print-error */
void body_90() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  apply((&function_191));
}
void body_92();
pointer global_c102c110c95c52c52 = NIL; /* fn_44 */
pointer global_c102c110c95c52c53;
void function_192() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  top_level_apply();
}
void function_193() {
  increment_count(env);
  val = new_function((&function_192), env);
  pop_function();
}
/* fn_45 */
void body_91() {
  increment_count(env);
  val = new_function((&function_193), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  return_location = (&body_92);
}
void body_93();
void function_194() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_195() {
  increment_count(env);
  val = new_function((&function_194), env);
  pop_function();
}
/* fn_44 */
void body_92() {
  increment_count(env);
  val = new_function((&function_195), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  return_location = (&body_93);
}
void body_94();
pointer global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108;
void function_196() {
  global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108 = val; /* ____make-symbol */
  return_location = (&body_94);
}
/* ____make-symbol */
void body_93() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  apply((&function_196));
}
void body_95();
pointer global_c102c110c95c52c54 = NIL; /* fn_46 */
pointer global_c102c110c95c52c55;
void function_197() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_198() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  apply((&function_197));
}
void function_199() {
  increment_count(env);
  val = new_function((&function_198), env);
  pop_function();
}
/* fn_47 */
void body_94() {
  increment_count(env);
  val = new_function((&function_199), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  return_location = (&body_95);
}
void body_96();
void function_200() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_201() {
  increment_count(env);
  val = new_function((&function_200), env);
  pop_function();
}
/* fn_46 */
void body_95() {
  increment_count(env);
  val = new_function((&function_201), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  return_location = (&body_96);
}
void body_97();
pointer global_c95c95c95c95c115c121c109c98c111c108c45c62c105c100;
void function_202() {
  global_c95c95c95c95c115c121c109c98c111c108c45c62c105c100 = val; /* ____symbol->id */
  return_location = (&body_97);
}
/* ____symbol->id */
void body_96() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  apply((&function_202));
}
void body_98();
pointer global_c102c110c95c52c56;
void function_203() {
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  top_level_apply();
}
void function_204() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c62c105c100); /* ____symbol->id */
  apply((&function_203));
}
void function_205() {
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
    increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c62c105c100); /* ____symbol->id */
    apply((&function_204));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    top_level_apply();
  }
}
void function_206() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_function(car(args))) {
      increment_count(val = true);
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
    if (is_function(car(args))) {
      increment_count(val = true);
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c110c100); /* _and */
  apply((&function_205));
}
void function_207() {
  increment_count(env);
  val = new_function((&function_206), env);
  pop_function();
}
/* fn_48 */
void body_97() {
  increment_count(env);
  val = new_function((&function_207), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  return_location = (&body_98);
}
void body_99();
pointer global_c95c95c95c95c115c121c109c98c111c108c45c101c113;
void function_208() {
  global_c95c95c95c95c115c121c109c98c111c108c45c101c113 = val; /* ____symbol-eq */
  return_location = (&body_99);
}
/* ____symbol-eq */
void body_98() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  apply((&function_208));
}
void body_100();
pointer global_c102c110c95c52c57 = NIL; /* fn_49 */
pointer global_c102c110c95c53c48;
void function_209() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_210() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  apply((&function_209));
}
void function_211() {
  increment_count(env);
  val = new_function((&function_210), env);
  pop_function();
}
/* fn_50 */
void body_99() {
  increment_count(env);
  val = new_function((&function_211), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  return_location = (&body_100);
}
void body_101();
void function_212() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_213() {
  increment_count(env);
  val = new_function((&function_212), env);
  pop_function();
}
/* fn_49 */
void body_100() {
  increment_count(env);
  val = new_function((&function_213), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  return_location = (&body_101);
}
void body_102();
void function_214() {
  global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* _symbol->string */
  return_location = (&body_102);
}
/* _symbol->string */
void body_101() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  apply((&function_214));
}
void body_103();
pointer global_c95c95c95c95c108c111c111c107c117c112 = NIL; /* ____lookup */
pointer global_c102c110c95c53c49;
void function_215() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_216() {
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c100c97c114); /* _cdar */
    apply((&function_215));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_number(car(args))) &&
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
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
    increment_count(val = global_c95c95c95c95c108c111c111c107c117c112); /* ____lookup */
    top_level_apply();
  }
}
void function_217() {
  args = cons(val, args);
  increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
  apply((&function_216));
}
void function_218() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
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
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
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
    increment_count(val = global_c95c99c97c97c114); /* _caar */
    apply((&function_217));
  }
}
void function_219() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_218));
}
void function_220() {
  increment_count(env);
  val = new_function((&function_219), env);
  pop_function();
}
/* fn_51 */
void body_102() {
  increment_count(env);
  val = new_function((&function_220), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  return_location = (&body_103);
}
void body_104();
void function_221() {
  global_c95c95c95c95c108c111c111c107c117c112 = val; /* ____lookup */
  return_location = (&body_104);
}
/* ____lookup */
void body_103() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  apply((&function_221));
}
void body_105();
pointer global_c102c110c95c53c50 = NIL; /* fn_52 */
pointer global_c102c110c95c53c51;
void function_222() {
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c111c111c107c117c112); /* ____lookup */
  top_level_apply();
}
void function_223() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  apply((&function_222));
}
void function_224() {
  increment_count(env);
  val = new_function((&function_223), env);
  pop_function();
}
/* fn_53 */
void body_104() {
  increment_count(env);
  val = new_function((&function_224), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  return_location = (&body_105);
}
void body_106();
void function_225() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_226() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108); /* ____make-symbol */
  apply((&function_225));
}
void function_227() {
  increment_count(env);
  val = new_function((&function_226), env);
  pop_function();
}
/* fn_52 */
void body_105() {
  increment_count(env);
  val = new_function((&function_227), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  return_location = (&body_106);
}
void body_107();
pointer global_c95c95c95c95c103c101c116c45c115c121c109c98c111c108;
void function_228() {
  global_c95c95c95c95c103c101c116c45c115c121c109c98c111c108 = val; /* ____get-symbol */
  return_location = (&body_107);
}
/* ____get-symbol */
void body_106() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  apply((&function_228));
}
void body_108();
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
void body_107() {
  val = NIL;
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  return_location = (&body_108);
}
void body_109();
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
void body_108() {
  val = -43;
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  return_location = (&body_109);
}
void body_110();
pointer global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63 = NIL; /* ____symbol-present? */
pointer global_c102c110c95c53c52;
void function_229() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
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
    increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63); /* ____symbol-present? */
    top_level_apply();
  }
}
void function_230() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
  apply((&function_229));
}
void function_231() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c56); /* ___l_18 */
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
    increment_count(val = global_c95c99c97c97c114); /* _caar */
    apply((&function_230));
  }
}
void function_232() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_231));
}
void function_233() {
  increment_count(env);
  val = new_function((&function_232), env);
  pop_function();
}
/* fn_54 */
void body_109() {
  increment_count(env);
  val = new_function((&function_233), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  return_location = (&body_110);
}
void body_111();
void function_234() {
  global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63 = val; /* ____symbol-present? */
  return_location = (&body_111);
}
/* ____symbol-present? */
void body_110() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  apply((&function_234));
}
void body_112();
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
void body_111() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  return_location = (&body_112);
}
void body_113();
pointer global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 = NIL; /* ____generate-unused-symbol-name */
pointer global_c102c110c95c53c53;
void function_235() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101); /* ____generate-unused-symbol-name */
  top_level_apply();
}
void function_236() {
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
    increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    apply((&function_235));
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_237() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63); /* ____symbol-present? */
  apply((&function_236));
}
void function_238() {
  increment_count(env);
  val = new_function((&function_237), env);
  pop_function();
}
/* fn_55 */
void body_112() {
  increment_count(env);
  val = new_function((&function_238), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  return_location = (&body_113);
}
void body_114();
void function_239() {
  global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____generate-unused-symbol-name */
  return_location = (&body_114);
}
/* ____generate-unused-symbol-name */
void body_113() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  apply((&function_239));
}
void body_115();
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
void body_114() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  return_location = (&body_115);
}
void body_116();
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
void body_115() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  return_location = (&body_116);
}
void body_117();
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
void body_116() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  return_location = (&body_117);
}
void body_118();
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
void body_117() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  return_location = (&body_118);
}
void body_119();
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
void body_118() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  return_location = (&body_119);
}
void body_120();
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
void body_119() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  return_location = (&body_120);
}
void body_121();
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
void body_120() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  return_location = (&body_121);
}
void body_122();
pointer global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109 = NIL; /* ____print-atom */
pointer global_c102c110c95c53c54 = NIL; /* fn_56 */
pointer global_c102c110c95c53c55;
void function_240() {
  top_level_apply();
}
void function_241() {
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
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  apply((&function_240));
}
void function_242() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c50); /* ___l_22 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c49); /* ___l_21 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
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
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ____print-atom */
    apply((&function_241));
  }
}
void function_243() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_242));
}
void function_244() {
  increment_count(env);
  val = new_function((&function_243), env);
  pop_function();
}
/* fn_57 */
void body_121() {
  increment_count(env);
  val = new_function((&function_244), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  return_location = (&body_122);
}
void body_123();
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = NIL; /* ____build-string->symbol-cases */
void function_245() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51); /* ___l_23 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_246() {
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
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115); /* ____build-string->symbol-cases */
  apply((&function_245));
}
void function_247() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_246));
}
void function_248() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c55); /* ___l_27 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_247));
}
void function_249() {
  increment_count(env);
  val = new_function((&function_248), env);
  pop_function();
}
/* fn_56 */
void body_122() {
  increment_count(env);
  val = new_function((&function_249), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  return_location = (&body_123);
}
void body_124();
void function_250() {
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = val; /* ____build-string->symbol-cases */
  return_location = (&body_124);
}
/* ____build-string->symbol-cases */
void body_123() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  apply((&function_250));
}
void body_125();
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
void body_124() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  return_location = (&body_125);
}
void body_126();
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
void body_125() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  return_location = (&body_126);
}
void body_127();
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
void body_126() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  return_location = (&body_127);
}
void body_128();
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
void body_127() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  return_location = (&body_128);
}
void body_129();
pointer global_c102c110c95c53c56;
void function_251() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56); /* ___l_28 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_252() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115); /* ____build-string->symbol-cases */
  apply((&function_251));
}
void function_253() {
  increment_count(env);
  val = new_function((&function_252), env);
  pop_function();
}
/* fn_58 */
void body_128() {
  increment_count(env);
  val = new_function((&function_253), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  return_location = (&body_129);
}
void body_130();
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
void function_254() {
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* ____build-string->symbol */
  return_location = (&body_130);
}
/* ____build-string->symbol */
void body_129() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  apply((&function_254));
}
void body_131();
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
void body_130() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  return_location = (&body_131);
}
void body_132();
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
void body_131() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  return_location = (&body_132);
}
void body_133();
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
void body_132() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  return_location = (&body_133);
}
void body_134();
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
void body_133() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  return_location = (&body_134);
}
void body_135();
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
void body_134() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  return_location = (&body_135);
}
void body_136();
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
void body_135() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  return_location = (&body_136);
}
void body_137();
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
void body_136() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  return_location = (&body_137);
}
void body_138();
pointer global_c102c110c95c53c57 = NIL; /* fn_59 */
pointer global_c102c110c95c54c48;
void function_255() {
  top_level_apply();
}
void function_256() {
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
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  apply((&function_255));
}
void function_257() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
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
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ____print-atom */
    apply((&function_256));
  }
}
void function_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_257));
}
void function_259() {
  increment_count(env);
  val = new_function((&function_258), env);
  pop_function();
}
/* fn_60 */
void body_137() {
  increment_count(env);
  val = new_function((&function_259), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  return_location = (&body_138);
}
void body_139();
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = NIL; /* ____build-symbol->string-cases */
void function_260() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c54); /* ___l_36 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c53); /* ___l_35 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c52); /* ___l_34 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_261() {
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
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115); /* ____build-symbol->string-cases */
  apply((&function_260));
}
void function_262() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c55); /* ___l_37 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_261));
}
void function_263() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c56); /* ___l_38 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_262));
}
void function_264() {
  increment_count(env);
  val = new_function((&function_263), env);
  pop_function();
}
/* fn_59 */
void body_138() {
  increment_count(env);
  val = new_function((&function_264), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  return_location = (&body_139);
}
void body_140();
void function_265() {
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = val; /* ____build-symbol->string-cases */
  return_location = (&body_140);
}
/* ____build-symbol->string-cases */
void body_139() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  apply((&function_265));
}
void body_141();
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
void body_140() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  return_location = (&body_141);
}
void body_142();
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
void body_141() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  return_location = (&body_142);
}
void body_143();
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
void body_142() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  return_location = (&body_143);
}
void body_144();
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
void body_143() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  return_location = (&body_144);
}
void body_145();
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
void body_144() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  return_location = (&body_145);
}
void body_146();
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
void body_145() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  return_location = (&body_146);
}
void body_147();
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
void body_146() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  return_location = (&body_147);
}
void body_148();
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
void body_147() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  return_location = (&body_148);
}
void body_149();
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
void body_148() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  return_location = (&body_149);
}
void body_150();
pointer global_c102c110c95c54c49;
void function_266() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c49); /* ___l_41 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c48); /* ___l_40 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c57); /* ___l_39 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_267() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c55); /* ___l_47 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c54); /* ___l_46 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c53); /* ___l_45 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c52); /* ___l_44 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c51); /* ___l_43 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c50); /* ___l_42 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115); /* ____build-symbol->string-cases */
  apply((&function_266));
}
void function_268() {
  increment_count(env);
  val = new_function((&function_267), env);
  pop_function();
}
/* fn_61 */
void body_149() {
  increment_count(env);
  val = new_function((&function_268), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  return_location = (&body_150);
}
void body_151();
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
void function_269() {
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* ____build-symbol->string */
  return_location = (&body_151);
}
/* ____build-symbol->string */
void body_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  apply((&function_269));
}
void body_152();
pointer global_c102c110c95c54c50;
void function_270() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  }
}
void function_271() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(13);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(110);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_270));
  }
}
void function_272() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(9);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(114);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_271));
  }
}
void function_273() {
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
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_272));
}
void function_274() {
  increment_count(env);
  val = new_function((&function_273), env);
  pop_function();
}
/* fn_62 */
void body_151() {
  increment_count(env);
  val = new_function((&function_274), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  return_location = (&body_152);
}
void body_153();
pointer global_c95c95c95c95c101c115c99c97c112c101c45c99c104c97c114;
void function_275() {
  global_c95c95c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* ____escape-char */
  return_location = (&body_153);
}
/* ____escape-char */
void body_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  apply((&function_275));
}
void body_154();
pointer global_c102c110c95c54c51 = NIL; /* fn_63 */
pointer global_c102c110c95c54c52;
void function_276() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_277() {
  apply((&function_276));
}
void function_278() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_277));
}
void function_279() {
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
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  apply((&function_278));
}
void function_280() {
  increment_count(env);
  val = new_function((&function_279), env);
  pop_function();
}
/* fn_64 */
void body_153() {
  increment_count(env);
  val = new_function((&function_280), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  return_location = (&body_154);
}
void body_155();
void function_281() {
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
void function_282() {
  increment_count(env);
  val = new_function((&function_281), env);
  pop_function();
}
/* fn_63 */
void body_154() {
  increment_count(env);
  val = new_function((&function_282), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  return_location = (&body_155);
}
void body_156();
pointer global_c95c95c95c95c98c117c105c108c100c45c110c117c109;
void function_283() {
  global_c95c95c95c95c98c117c105c108c100c45c110c117c109 = val; /* ____build-num */
  return_location = (&body_156);
}
/* ____build-num */
void body_155() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  apply((&function_283));
}
void body_157();
pointer global_c102c110c95c54c53;
void function_284() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_285() {
  increment_count(env);
  val = new_function((&function_284), env);
  pop_function();
}
/* fn_65 */
void body_156() {
  increment_count(env);
  val = new_function((&function_285), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  return_location = (&body_157);
}
void body_158();
pointer global_c95c95c95c95c100c114c111c112c45c102c105c114c115c116;
void function_286() {
  global_c95c95c95c95c100c114c111c112c45c102c105c114c115c116 = val; /* ____drop-first */
  return_location = (&body_158);
}
/* ____drop-first */
void body_157() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  apply((&function_286));
}
void body_159();
pointer global_c102c110c95c54c54;
void function_287() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_288() {
  increment_count(env);
  val = new_function((&function_287), env);
  pop_function();
}
/* fn_66 */
void body_158() {
  increment_count(env);
  val = new_function((&function_288), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  return_location = (&body_159);
}
void body_160();
pointer global_c95c95c95c95c100c114c111c112c45c115c101c99c111c110c100;
void function_289() {
  global_c95c95c95c95c100c114c111c112c45c115c101c99c111c110c100 = val; /* ____drop-second */
  return_location = (&body_160);
}
/* ____drop-second */
void body_159() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  apply((&function_289));
}
void body_161();
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
void body_160() {
  val = -35;
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  return_location = (&body_161);
}
void body_162();
pointer global_c102c110c95c54c55;
void function_290() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_291() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c56); /* ___l_48 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_290));
}
void function_292() {
  increment_count(env);
  val = new_function((&function_291), env);
  pop_function();
}
/* fn_67 */
void body_161() {
  increment_count(env);
  val = new_function((&function_292), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  return_location = (&body_162);
}
void body_163();
pointer global_c95c95c95c95c113c117c111c116c101c45c118c97c108c117c101;
void function_293() {
  global_c95c95c95c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* ____quote-value */
  return_location = (&body_163);
}
/* ____quote-value */
void body_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  apply((&function_293));
}
void body_164();
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
void body_163() {
  val = -42;
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  return_location = (&body_164);
}
void body_165();
pointer global_c102c110c95c54c56;
void function_294() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_295() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c57); /* ___l_49 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_294));
}
void function_296() {
  increment_count(env);
  val = new_function((&function_295), env);
  pop_function();
}
/* fn_68 */
void body_164() {
  increment_count(env);
  val = new_function((&function_296), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  return_location = (&body_165);
}
void body_166();
pointer global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_297() {
  global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* ____quasiquote-value */
  return_location = (&body_166);
}
/* ____quasiquote-value */
void body_165() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  apply((&function_297));
}
void body_167();
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
void body_166() {
  val = -41;
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  return_location = (&body_167);
}
void body_168();
pointer global_c102c110c95c54c57;
void function_298() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_299() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c48); /* ___l_50 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  apply((&function_298));
}
void function_300() {
  increment_count(env);
  val = new_function((&function_299), env);
  pop_function();
}
/* fn_69 */
void body_167() {
  increment_count(env);
  val = new_function((&function_300), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  return_location = (&body_168);
}
void body_169();
pointer global_c95c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_301() {
  global_c95c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* ____unquote-value */
  return_location = (&body_169);
}
/* ____unquote-value */
void body_168() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  apply((&function_301));
}
void body_170();
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
void body_169() {
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
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  return_location = (&body_170);
}
void body_171();
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
void body_170() {
  val = -36;
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  return_location = (&body_171);
}
void body_172();
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
void body_171() {
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
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  return_location = (&body_172);
}
void body_173();
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
void body_172() {
  val = -40;
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  return_location = (&body_173);
}
void body_174();
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
void body_173() {
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
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  return_location = (&body_174);
}
void body_175();
pointer global_c95c95c95c108c95c53c54;
/* ___l_56 */
void body_174() {
  val = -39;
  global_c95c95c95c108c95c53c54 = val; /* ___l_56 */
  return_location = (&body_175);
}
void body_176();
pointer global_c95c95c95c108c95c53c55;
/* ___l_57 */
void body_175() {
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
  global_c95c95c95c108c95c53c55 = val; /* ___l_57 */
  return_location = (&body_176);
}
void body_177();
pointer global_c95c95c95c108c95c53c56;
/* ___l_58 */
void body_176() {
  val = -38;
  global_c95c95c95c108c95c53c56 = val; /* ___l_58 */
  return_location = (&body_177);
}
void body_178();
pointer global_c95c95c95c108c95c53c57;
/* ___l_59 */
void body_177() {
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
  global_c95c95c95c108c95c53c57 = val; /* ___l_59 */
  return_location = (&body_178);
}
void body_179();
pointer global_c95c95c95c108c95c54c48;
/* ___l_60 */
void body_178() {
  val = -37;
  global_c95c95c95c108c95c54c48 = val; /* ___l_60 */
  return_location = (&body_179);
}
void body_180();
pointer global_c95c95c95c108c95c54c49;
/* ___l_61 */
void body_179() {
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
  global_c95c95c95c108c95c54c49 = val; /* ___l_61 */
  return_location = (&body_180);
}
void body_181();
pointer global_c95c95c95c108c95c54c50;
/* ___l_62 */
void body_180() {
  val = -35;
  global_c95c95c95c108c95c54c50 = val; /* ___l_62 */
  return_location = (&body_181);
}
void body_182();
pointer global_c95c95c95c108c95c54c51;
/* ___l_63 */
void body_181() {
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
  global_c95c95c95c108c95c54c51 = val; /* ___l_63 */
  return_location = (&body_182);
}
void body_183();
pointer global_c95c95c95c108c95c54c52;
/* ___l_64 */
void body_182() {
  val = -42;
  global_c95c95c95c108c95c54c52 = val; /* ___l_64 */
  return_location = (&body_183);
}
void body_184();
pointer global_c95c95c95c108c95c54c53;
/* ___l_65 */
void body_183() {
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
  global_c95c95c95c108c95c54c53 = val; /* ___l_65 */
  return_location = (&body_184);
}
void body_185();
pointer global_c95c95c95c108c95c54c54;
/* ___l_66 */
void body_184() {
  val = -41;
  global_c95c95c95c108c95c54c54 = val; /* ___l_66 */
  return_location = (&body_185);
}
void body_186();
pointer global_c95c95c95c108c95c54c55;
/* ___l_67 */
void body_185() {
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
  global_c95c95c95c108c95c54c55 = val; /* ___l_67 */
  return_location = (&body_186);
}
void body_187();
pointer global_c95c95c95c108c95c54c56;
/* ___l_68 */
void body_186() {
  val = CONS;
  global_c95c95c95c108c95c54c56 = val; /* ___l_68 */
  return_location = (&body_187);
}
void body_188();
pointer global_c95c95c95c108c95c54c57;
/* ___l_69 */
void body_187() {
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
  global_c95c95c95c108c95c54c57 = val; /* ___l_69 */
  return_location = (&body_188);
}
void body_189();
pointer global_c95c95c95c108c95c55c48;
/* ___l_70 */
void body_188() {
  val = CAR;
  global_c95c95c95c108c95c55c48 = val; /* ___l_70 */
  return_location = (&body_189);
}
void body_190();
pointer global_c95c95c95c108c95c55c49;
/* ___l_71 */
void body_189() {
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
  global_c95c95c95c108c95c55c49 = val; /* ___l_71 */
  return_location = (&body_190);
}
void body_191();
pointer global_c95c95c95c108c95c55c50;
/* ___l_72 */
void body_190() {
  val = CDR;
  global_c95c95c95c108c95c55c50 = val; /* ___l_72 */
  return_location = (&body_191);
}
void body_192();
pointer global_c95c95c95c108c95c55c51;
/* ___l_73 */
void body_191() {
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
  global_c95c95c95c108c95c55c51 = val; /* ___l_73 */
  return_location = (&body_192);
}
void body_193();
pointer global_c95c95c95c108c95c55c52;
/* ___l_74 */
void body_192() {
  val = ATOM;
  global_c95c95c95c108c95c55c52 = val; /* ___l_74 */
  return_location = (&body_193);
}
void body_194();
pointer global_c95c95c95c108c95c55c53;
/* ___l_75 */
void body_193() {
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
  global_c95c95c95c108c95c55c53 = val; /* ___l_75 */
  return_location = (&body_194);
}
void body_195();
pointer global_c95c95c95c108c95c55c54;
/* ___l_76 */
void body_194() {
  val = NUMBER;
  global_c95c95c95c108c95c55c54 = val; /* ___l_76 */
  return_location = (&body_195);
}
void body_196();
pointer global_c95c95c95c108c95c55c55;
/* ___l_77 */
void body_195() {
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
  global_c95c95c95c108c95c55c55 = val; /* ___l_77 */
  return_location = (&body_196);
}
void body_197();
pointer global_c95c95c95c108c95c55c56;
/* ___l_78 */
void body_196() {
  val = FUNCTION;
  global_c95c95c95c108c95c55c56 = val; /* ___l_78 */
  return_location = (&body_197);
}
void body_198();
pointer global_c95c95c95c108c95c55c57;
/* ___l_79 */
void body_197() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c57 = val; /* ___l_79 */
  return_location = (&body_198);
}
void body_199();
pointer global_c95c95c95c108c95c56c48;
/* ___l_80 */
void body_198() {
  val = EQ;
  global_c95c95c95c108c95c56c48 = val; /* ___l_80 */
  return_location = (&body_199);
}
void body_200();
pointer global_c95c95c95c108c95c56c49;
/* ___l_81 */
void body_199() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c49 = val; /* ___l_81 */
  return_location = (&body_200);
}
void body_201();
pointer global_c95c95c95c108c95c56c50;
/* ___l_82 */
void body_200() {
  val = LT;
  global_c95c95c95c108c95c56c50 = val; /* ___l_82 */
  return_location = (&body_201);
}
void body_202();
pointer global_c95c95c95c108c95c56c51;
/* ___l_83 */
void body_201() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c51 = val; /* ___l_83 */
  return_location = (&body_202);
}
void body_203();
pointer global_c95c95c95c108c95c56c52;
/* ___l_84 */
void body_202() {
  val = GT;
  global_c95c95c95c108c95c56c52 = val; /* ___l_84 */
  return_location = (&body_203);
}
void body_204();
pointer global_c95c95c95c108c95c56c53;
/* ___l_85 */
void body_203() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c53 = val; /* ___l_85 */
  return_location = (&body_204);
}
void body_205();
pointer global_c95c95c95c108c95c56c54;
/* ___l_86 */
void body_204() {
  val = PLUS;
  global_c95c95c95c108c95c56c54 = val; /* ___l_86 */
  return_location = (&body_205);
}
void body_206();
pointer global_c95c95c95c108c95c56c55;
/* ___l_87 */
void body_205() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c55 = val; /* ___l_87 */
  return_location = (&body_206);
}
void body_207();
pointer global_c95c95c95c108c95c56c56;
/* ___l_88 */
void body_206() {
  val = MINUS;
  global_c95c95c95c108c95c56c56 = val; /* ___l_88 */
  return_location = (&body_207);
}
void body_208();
pointer global_c95c95c95c108c95c56c57;
/* ___l_89 */
void body_207() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c57 = val; /* ___l_89 */
  return_location = (&body_208);
}
void body_209();
pointer global_c95c95c95c108c95c57c48;
/* ___l_90 */
void body_208() {
  val = MULT;
  global_c95c95c95c108c95c57c48 = val; /* ___l_90 */
  return_location = (&body_209);
}
void body_210();
pointer global_c95c95c95c108c95c57c49;
/* ___l_91 */
void body_209() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57c49 = val; /* ___l_91 */
  return_location = (&body_210);
}
void body_211();
pointer global_c95c95c95c108c95c57c50;
/* ___l_92 */
void body_210() {
  val = DIV;
  global_c95c95c95c108c95c57c50 = val; /* ___l_92 */
  return_location = (&body_211);
}
void body_212();
pointer global_c95c95c95c108c95c57c51;
/* ___l_93 */
void body_211() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57c51 = val; /* ___l_93 */
  return_location = (&body_212);
}
void body_213();
pointer global_c95c95c95c108c95c57c52;
/* ___l_94 */
void body_212() {
  val = MOD;
  global_c95c95c95c108c95c57c52 = val; /* ___l_94 */
  return_location = (&body_213);
}
void body_214();
pointer global_c95c95c95c108c95c57c53;
/* ___l_95 */
void body_213() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57c53 = val; /* ___l_95 */
  return_location = (&body_214);
}
void body_215();
pointer global_c95c95c95c108c95c57c54;
/* ___l_96 */
void body_214() {
  val = BNEG;
  global_c95c95c95c108c95c57c54 = val; /* ___l_96 */
  return_location = (&body_215);
}
void body_216();
pointer global_c95c95c95c108c95c57c55;
/* ___l_97 */
void body_215() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57c55 = val; /* ___l_97 */
  return_location = (&body_216);
}
void body_217();
pointer global_c95c95c95c108c95c57c56;
/* ___l_98 */
void body_216() {
  val = BAND;
  global_c95c95c95c108c95c57c56 = val; /* ___l_98 */
  return_location = (&body_217);
}
void body_218();
pointer global_c95c95c95c108c95c57c57;
/* ___l_99 */
void body_217() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57c57 = val; /* ___l_99 */
  return_location = (&body_218);
}
void body_219();
pointer global_c95c95c95c108c95c49c48c48;
/* ___l_100 */
void body_218() {
  val = BOR;
  global_c95c95c95c108c95c49c48c48 = val; /* ___l_100 */
  return_location = (&body_219);
}
void body_220();
pointer global_c95c95c95c108c95c49c48c49;
/* ___l_101 */
void body_219() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c48c49 = val; /* ___l_101 */
  return_location = (&body_220);
}
void body_221();
pointer global_c95c95c95c108c95c49c48c50;
/* ___l_102 */
void body_220() {
  val = BXOR;
  global_c95c95c95c108c95c49c48c50 = val; /* ___l_102 */
  return_location = (&body_221);
}
void body_222();
pointer global_c95c95c95c108c95c49c48c51;
/* ___l_103 */
void body_221() {
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
  global_c95c95c95c108c95c49c48c51 = val; /* ___l_103 */
  return_location = (&body_222);
}
void body_223();
pointer global_c95c95c95c108c95c49c48c52;
/* ___l_104 */
void body_222() {
  val = SRSHIFT;
  global_c95c95c95c108c95c49c48c52 = val; /* ___l_104 */
  return_location = (&body_223);
}
void body_224();
pointer global_c95c95c95c108c95c49c48c53;
/* ___l_105 */
void body_223() {
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
  global_c95c95c95c108c95c49c48c53 = val; /* ___l_105 */
  return_location = (&body_224);
}
void body_225();
pointer global_c95c95c95c108c95c49c48c54;
/* ___l_106 */
void body_224() {
  val = URSHIFT;
  global_c95c95c95c108c95c49c48c54 = val; /* ___l_106 */
  return_location = (&body_225);
}
void body_226();
pointer global_c95c95c95c108c95c49c48c55;
/* ___l_107 */
void body_225() {
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
  global_c95c95c95c108c95c49c48c55 = val; /* ___l_107 */
  return_location = (&body_226);
}
void body_227();
pointer global_c95c95c95c108c95c49c48c56;
/* ___l_108 */
void body_226() {
  val = LSHIFT;
  global_c95c95c95c108c95c49c48c56 = val; /* ___l_108 */
  return_location = (&body_227);
}
void body_228();
pointer global_c95c95c95c108c95c49c48c57;
/* ___l_109 */
void body_227() {
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
  global_c95c95c95c108c95c49c48c57 = val; /* ___l_109 */
  return_location = (&body_228);
}
void body_229();
pointer global_c95c95c95c108c95c49c49c48;
/* ___l_110 */
void body_228() {
  val = -34;
  global_c95c95c95c108c95c49c49c48 = val; /* ___l_110 */
  return_location = (&body_229);
}
void body_230();
pointer global_c102c110c95c55c48 = NIL; /* fn_70 */
pointer global_c102c110c95c55c49;
void function_302() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c115c121c109c98c111c108); /* ____get-symbol */
  top_level_apply();
}
void function_303() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c49c48); /* ___l_110 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
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
    increment_count(val = global_c102c110c95c55c48); /* fn_70 */
    apply((&function_302));
  }
}
void function_304() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c48c56); /* ___l_108 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c57); /* ___l_109 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_303));
  }
}
void function_305() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c48c54); /* ___l_106 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c55); /* ___l_107 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_304));
  }
}
void function_306() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c48c52); /* ___l_104 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c53); /* ___l_105 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_305));
  }
}
void function_307() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c48c50); /* ___l_102 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c51); /* ___l_103 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_306));
  }
}
void function_308() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c48c48); /* ___l_100 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c49); /* ___l_101 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_307));
  }
}
void function_309() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c57c56); /* ___l_98 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c57); /* ___l_99 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_308));
  }
}
void function_310() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c57c54); /* ___l_96 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c55); /* ___l_97 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_309));
  }
}
void function_311() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c57c52); /* ___l_94 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c53); /* ___l_95 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_310));
  }
}
void function_312() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c57c50); /* ___l_92 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c51); /* ___l_93 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_311));
  }
}
void function_313() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c57c48); /* ___l_90 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c49); /* ___l_91 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_312));
  }
}
void function_314() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56c56); /* ___l_88 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c57); /* ___l_89 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_313));
  }
}
void function_315() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56c54); /* ___l_86 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c55); /* ___l_87 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_314));
  }
}
void function_316() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56c52); /* ___l_84 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c53); /* ___l_85 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_315));
  }
}
void function_317() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56c50); /* ___l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c51); /* ___l_83 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_316));
  }
}
void function_318() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56c48); /* ___l_80 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c49); /* ___l_81 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55c56); /* ___l_78 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c57); /* ___l_79 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55c54); /* ___l_76 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c55); /* ___l_77 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_319));
  }
}
void function_321() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55c52); /* ___l_74 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c53); /* ___l_75 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_320));
  }
}
void function_322() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55c50); /* ___l_72 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c51); /* ___l_73 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_321));
  }
}
void function_323() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55c48); /* ___l_70 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c49); /* ___l_71 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_322));
  }
}
void function_324() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c54c56); /* ___l_68 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c57); /* ___l_69 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_323));
  }
}
void function_325() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c54c54); /* ___l_66 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c55); /* ___l_67 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_324));
  }
}
void function_326() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c54c52); /* ___l_64 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c53); /* ___l_65 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_325));
  }
}
void function_327() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c54c50); /* ___l_62 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c51); /* ___l_63 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_326));
  }
}
void function_328() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c54c48); /* ___l_60 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c49); /* ___l_61 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_327));
  }
}
void function_329() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c56); /* ___l_58 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c57); /* ___l_59 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_328));
  }
}
void function_330() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c54); /* ___l_56 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c55); /* ___l_57 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_329));
  }
}
void function_331() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c52); /* ___l_54 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c53); /* ___l_55 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_330));
  }
}
void function_332() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c50); /* ___l_52 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c51); /* ___l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
    apply((&function_331));
  }
}
void function_333() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c53c49); /* ___l_51 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c113c117c97c108); /* __equal */
  apply((&function_332));
}
void function_334() {
  increment_count(env);
  val = new_function((&function_333), env);
  pop_function();
}
/* fn_71 */
void body_229() {
  increment_count(env);
  val = new_function((&function_334), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  return_location = (&body_230);
}
void body_231();
void function_335() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_336() {
  increment_count(env);
  val = new_function((&function_335), env);
  pop_function();
}
/* fn_70 */
void body_230() {
  increment_count(env);
  val = new_function((&function_336), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  return_location = (&body_231);
}
void body_232();
pointer global_c95c95c95c95c108c111c111c107c117c112c45c115c121c109c98c111c108;
void function_337() {
  global_c95c95c95c95c108c111c111c107c117c112c45c115c121c109c98c111c108 = val; /* ____lookup-symbol */
  return_location = (&body_232);
}
/* ____lookup-symbol */
void body_231() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  apply((&function_337));
}
void body_233();
pointer global_c102c110c95c55c50;
void function_338() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_339() {
  increment_count(env);
  val = new_function((&function_338), env);
  pop_function();
}
/* fn_72 */
void body_232() {
  increment_count(env);
  val = new_function((&function_339), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  return_location = (&body_233);
}
void body_234();
pointer global_c95c95c95c95c102c97c105c108;
void function_340() {
  global_c95c95c95c95c102c97c105c108 = val; /* ____fail */
  return_location = (&body_234);
}
/* ____fail */
void body_233() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  apply((&function_340));
}
void body_235();
pointer global_c102c110c95c55c51;
void function_341() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_342() {
  increment_count(env);
  val = new_function((&function_341), env);
  pop_function();
}
/* fn_73 */
void body_234() {
  increment_count(env);
  val = new_function((&function_342), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  return_location = (&body_235);
}
void body_236();
pointer global_c95c95c95c95c100c111c110c101;
void function_343() {
  global_c95c95c95c95c100c111c110c101 = val; /* ____done */
  return_location = (&body_236);
}
/* ____done */
void body_235() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  apply((&function_343));
}
void body_237();
pointer global_c95c95c95c108c95c49c49c49;
/* ___l_111 */
void body_236() {
  val = NIL;
  global_c95c95c95c108c95c49c49c49 = val; /* ___l_111 */
  return_location = (&body_237);
}
void body_238();
pointer global_c102c110c95c55c52 = NIL; /* fn_74 */
pointer global_c102c110c95c55c53;
void function_344() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  top_level_apply();
}
void function_345() {
  increment_count(env);
  val = new_function((&function_344), env);
  pop_function();
}
/* fn_75 */
void body_237() {
  increment_count(env);
  val = new_function((&function_345), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  return_location = (&body_238);
}
void body_239();
pointer global_c95c95c95c95c112c111c112 = NIL; /* ____pop */
void function_346() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
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
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  } else {
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
    top_level_apply();
  }
}
void function_347() {
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
    apply((&function_346));
  }
}
void function_348() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c111c112); /* ____pop */
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
    apply((&function_347));
  }
}
void function_349() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c49c49); /* ___l_111 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_348));
}
void function_350() {
  increment_count(env);
  val = new_function((&function_349), env);
  pop_function();
}
/* fn_74 */
void body_238() {
  increment_count(env);
  val = new_function((&function_350), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  return_location = (&body_239);
}
void body_240();
void function_351() {
  global_c95c95c95c95c112c111c112 = val; /* ____pop */
  return_location = (&body_240);
}
/* ____pop */
void body_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  apply((&function_351));
}
void body_241();
pointer global_c102c110c95c55c55 = NIL; /* fn_77 */
pointer global_c102c110c95c55c56;
void function_352() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  top_level_apply();
}
void function_353() {
  increment_count(env);
  val = new_function((&function_352), env);
  pop_function();
}
/* fn_78 */
void body_240() {
  increment_count(env);
  val = new_function((&function_353), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  return_location = (&body_241);
}
void body_242();
pointer global_c102c110c95c55c54 = NIL; /* fn_76 */
void function_354() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c112); /* ____pop */
  top_level_apply();
}
void function_355() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  apply((&function_354));
}
void function_356() {
  increment_count(env);
  val = new_function((&function_355), env);
  pop_function();
}
/* fn_77 */
void body_241() {
  increment_count(env);
  val = new_function((&function_356), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  return_location = (&body_242);
}
void body_243();
void function_357() {
  top_level_apply();
}
void function_358() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
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
    apply((&function_357));
  }
}
void function_359() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_358));
}
void function_360() {
  increment_count(env);
  val = new_function((&function_359), env);
  pop_function();
}
/* fn_76 */
void body_242() {
  increment_count(env);
  val = new_function((&function_360), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  return_location = (&body_243);
}
void body_244();
pointer global_c95c95c95c95c99c104c101c99c107;
void function_361() {
  global_c95c95c95c95c99c104c101c99c107 = val; /* ____check */
  return_location = (&body_244);
}
/* ____check */
void body_243() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  apply((&function_361));
}
void body_245();
pointer global_c102c110c95c55c57 = NIL; /* fn_79 */
pointer global_c102c110c95c56c48;
void function_362() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c101c99c107); /* ____check */
  top_level_apply();
}
void function_363() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  apply((&function_362));
}
void function_364() {
  increment_count(env);
  val = new_function((&function_363), env);
  pop_function();
}
/* fn_80 */
void body_244() {
  increment_count(env);
  val = new_function((&function_364), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  return_location = (&body_245);
}
void body_246();
void function_365() {
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
void function_366() {
  increment_count(env);
  val = new_function((&function_365), env);
  pop_function();
}
/* fn_79 */
void body_245() {
  increment_count(env);
  val = new_function((&function_366), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  return_location = (&body_246);
}
void body_247();
pointer global_c95c95c95c95c109c97c116c99c104;
void function_367() {
  global_c95c95c95c95c109c97c116c99c104 = val; /* ____match */
  return_location = (&body_247);
}
/* ____match */
void body_246() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  apply((&function_367));
}
void body_248();
pointer global_c102c110c95c56c49 = NIL; /* fn_81 */
pointer global_c102c110c95c56c50;
void function_368() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  top_level_apply();
}
void function_369() {
  increment_count(env);
  val = new_function((&function_368), env);
  pop_function();
}
/* fn_82 */
void body_247() {
  increment_count(env);
  val = new_function((&function_369), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  return_location = (&body_248);
}
void body_249();
void function_370() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_371() {
  increment_count(env);
  val = new_function((&function_370), env);
  pop_function();
}
/* fn_81 */
void body_248() {
  increment_count(env);
  val = new_function((&function_371), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  return_location = (&body_249);
}
void body_250();
pointer global_c95c95c95c95c100c101c102c97c117c108c116;
void function_372() {
  global_c95c95c95c95c100c101c102c97c117c108c116 = val; /* ____default */
  return_location = (&body_250);
}
/* ____default */
void body_249() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  apply((&function_372));
}
void body_251();
pointer global_c102c110c95c56c54 = NIL; /* fn_86 */
pointer global_c102c110c95c56c55;
void function_373() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  top_level_apply();
}
void function_374() {
  increment_count(env);
  val = new_function((&function_373), env);
  pop_function();
}
/* fn_87 */
void body_250() {
  increment_count(env);
  val = new_function((&function_374), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  return_location = (&body_251);
}
void body_252();
pointer global_c102c110c95c56c53 = NIL; /* fn_85 */
void function_375() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  top_level_apply();
}
void function_376() {
  increment_count(env);
  val = new_function((&function_375), env);
  pop_function();
}
/* fn_86 */
void body_251() {
  increment_count(env);
  val = new_function((&function_376), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  return_location = (&body_252);
}
void body_253();
pointer global_c102c110c95c56c52 = NIL; /* fn_84 */
pointer global_c102c110c95c56c51 = NIL; /* fn_83 */
void function_377() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_378() {
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
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  apply((&function_377));
}
void function_379() {
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
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  apply((&function_378));
}
void function_380() {
  increment_count(env);
  val = new_function((&function_379), env);
  pop_function();
}
/* fn_85 */
void body_252() {
  increment_count(env);
  val = new_function((&function_380), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  return_location = (&body_253);
}
void body_254();
void function_381() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_382() {
  increment_count(env);
  val = new_function((&function_381), env);
  pop_function();
}
/* fn_83 */
void body_253() {
  increment_count(env);
  val = new_function((&function_382), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  return_location = (&body_254);
}
void body_255();
void function_383() {
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
  top_level_apply();
}
void function_384() {
  increment_count(env);
  val = new_function((&function_383), env);
  pop_function();
}
/* fn_84 */
void body_254() {
  increment_count(env);
  val = new_function((&function_384), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  return_location = (&body_255);
}
void body_256();
pointer global_c95c95c95c95c99c97c115c101;
void function_385() {
  global_c95c95c95c95c99c97c115c101 = val; /* ____case */
  return_location = (&body_256);
}
/* ____case */
void body_255() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  apply((&function_385));
}
void body_257();
pointer global_c102c110c95c56c56 = NIL; /* fn_88 */
pointer global_c102c110c95c56c57;
void function_386() {
  top_level_apply();
}
void function_387() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_386));
}
void function_388() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c102c97c105c108); /* ____fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  apply((&function_387));
}
void function_389() {
  increment_count(env);
  val = new_function((&function_388), env);
  pop_function();
}
/* fn_89 */
void body_256() {
  increment_count(env);
  val = new_function((&function_389), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  return_location = (&body_257);
}
void body_258();
void function_390() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_391() {
  increment_count(env);
  val = new_function((&function_390), env);
  pop_function();
}
/* fn_88 */
void body_257() {
  increment_count(env);
  val = new_function((&function_391), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  return_location = (&body_258);
}
void body_259();
pointer global_c95c95c95c95c99c104c111c105c99c101;
void function_392() {
  global_c95c95c95c95c99c104c111c105c99c101 = val; /* ____choice */
  return_location = (&body_259);
}
/* ____choice */
void body_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  apply((&function_392));
}
void body_260();
pointer global_c102c110c95c57c49 = NIL; /* fn_91 */
pointer global_c102c110c95c57c50;
void function_393() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  top_level_apply();
}
void function_394() {
  increment_count(env);
  val = new_function((&function_393), env);
  pop_function();
}
/* fn_92 */
void body_259() {
  increment_count(env);
  val = new_function((&function_394), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  return_location = (&body_260);
}
void body_261();
pointer global_c102c110c95c57c48 = NIL; /* fn_90 */
void function_395() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_396() {
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  apply((&function_395));
}
void function_397() {
  increment_count(env);
  val = new_function((&function_396), env);
  pop_function();
}
/* fn_91 */
void body_260() {
  increment_count(env);
  val = new_function((&function_397), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  return_location = (&body_261);
}
void body_262();
void function_398() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_399() {
  increment_count(env);
  val = new_function((&function_398), env);
  pop_function();
}
/* fn_90 */
void body_261() {
  increment_count(env);
  val = new_function((&function_399), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  return_location = (&body_262);
}
void body_263();
pointer global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_400() {
  global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* ____post-process */
  return_location = (&body_263);
}
/* ____post-process */
void body_262() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  apply((&function_400));
}
void body_264();
pointer global_c102c110c95c57c53 = NIL; /* fn_95 */
pointer global_c102c110c95c57c54;
void function_401() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  top_level_apply();
}
void function_402() {
  increment_count(env);
  val = new_function((&function_401), env);
  pop_function();
}
/* fn_96 */
void body_263() {
  increment_count(env);
  val = new_function((&function_402), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  return_location = (&body_264);
}
void body_265();
pointer global_c102c110c95c57c52 = NIL; /* fn_94 */
void function_403() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_404() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  apply((&function_403));
}
void function_405() {
  increment_count(env);
  val = new_function((&function_404), env);
  pop_function();
}
/* fn_95 */
void body_264() {
  increment_count(env);
  val = new_function((&function_405), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  return_location = (&body_265);
}
void body_266();
pointer global_c102c110c95c57c51 = NIL; /* fn_93 */
void function_406() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_407() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  apply((&function_406));
}
void function_408() {
  increment_count(env);
  val = new_function((&function_407), env);
  pop_function();
}
/* fn_94 */
void body_265() {
  increment_count(env);
  val = new_function((&function_408), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  return_location = (&body_266);
}
void body_267();
void function_409() {
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
void function_410() {
  increment_count(env);
  val = new_function((&function_409), env);
  pop_function();
}
/* fn_93 */
void body_266() {
  increment_count(env);
  val = new_function((&function_410), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  return_location = (&body_267);
}
void body_268();
pointer global_c95c95c95c95c115c101c113;
void function_411() {
  global_c95c95c95c95c115c101c113 = val; /* ____seq */
  return_location = (&body_268);
}
/* ____seq */
void body_267() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  apply((&function_411));
}
void body_269();
pointer global_c102c110c95c57c55;
void function_412() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c101c113); /* ____seq */
  top_level_apply();
}
void function_413() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c99c104c97c114); /* ____escape-char */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c112); /* ____pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  apply((&function_412));
}
void function_414() {
  increment_count(env);
  val = new_function((&function_413), env);
  pop_function();
}
/* fn_97 */
void body_268() {
  increment_count(env);
  val = new_function((&function_414), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  return_location = (&body_269);
}
void body_270();
pointer global_c95c95c95c95c101c115c99c97c112c101;
void function_415() {
  global_c95c95c95c95c101c115c99c97c112c101 = val; /* ____escape */
  return_location = (&body_270);
}
/* ____escape */
void body_269() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  apply((&function_415));
}
void body_271();
pointer global_c102c110c95c57c56;
void function_416() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c112); /* ____pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c101c113); /* ____seq */
  top_level_apply();
}
void function_417() {
  increment_count(env);
  val = new_function((&function_416), env);
  pop_function();
}
/* fn_98 */
void body_270() {
  increment_count(env);
  val = new_function((&function_417), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  return_location = (&body_271);
}
void body_272();
pointer global_c95c95c95c95c117c115c101;
void function_418() {
  global_c95c95c95c95c117c115c101 = val; /* ____use */
  return_location = (&body_272);
}
/* ____use */
void body_271() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  apply((&function_418));
}
void body_273();
pointer global_c102c110c95c49c48c48 = NIL; /* fn_100 */
pointer global_c102c110c95c49c48c49;
void function_419() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  top_level_apply();
}
void function_420() {
  increment_count(env);
  val = new_function((&function_419), env);
  pop_function();
}
/* fn_101 */
void body_272() {
  increment_count(env);
  val = new_function((&function_420), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  return_location = (&body_273);
}
void body_274();
pointer global_c102c110c95c57c57 = NIL; /* fn_99 */
void function_421() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_422() {
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
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  apply((&function_421));
}
void function_423() {
  increment_count(env);
  val = new_function((&function_422), env);
  pop_function();
}
/* fn_100 */
void body_273() {
  increment_count(env);
  val = new_function((&function_423), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  return_location = (&body_274);
}
void body_275();
void function_424() {
  top_level_apply();
}
void function_425() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_424));
}
void function_426() {
  increment_count(env);
  val = new_function((&function_425), env);
  pop_function();
}
/* fn_99 */
void body_274() {
  increment_count(env);
  val = new_function((&function_426), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  return_location = (&body_275);
}
void body_276();
pointer global_c95c95c95c95c112c101c101c107;
void function_427() {
  global_c95c95c95c95c112c101c101c107 = val; /* ____peek */
  return_location = (&body_276);
}
/* ____peek */
void body_275() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  apply((&function_427));
}
void body_277();
pointer global_c102c110c95c49c48c50 = NIL; /* fn_102 */
pointer global_c102c110c95c49c48c51;
void function_428() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c101c99c107); /* ____check */
  top_level_apply();
}
void function_429() {
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
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  apply((&function_428));
}
void function_430() {
  increment_count(env);
  val = new_function((&function_429), env);
  pop_function();
}
/* fn_103 */
void body_276() {
  increment_count(env);
  val = new_function((&function_430), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  return_location = (&body_277);
}
void body_278();
void function_431() {
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
void function_432() {
  increment_count(env);
  val = new_function((&function_431), env);
  pop_function();
}
/* fn_102 */
void body_277() {
  increment_count(env);
  val = new_function((&function_432), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  return_location = (&body_278);
}
void body_279();
pointer global_c95c95c95c95c105c110c116c101c114c118c97c108;
void function_433() {
  global_c95c95c95c95c105c110c116c101c114c118c97c108 = val; /* ____interval */
  return_location = (&body_279);
}
/* ____interval */
void body_278() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  apply((&function_433));
}
void body_280();
pointer global_c102c110c95c49c48c52;
void function_434() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  top_level_apply();
}
void function_435() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c114c111c112c45c102c105c114c115c116); /* ____drop-first */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c117c115c101); /* ____use */
  apply((&function_434));
}
void function_436() {
  increment_count(env);
  val = new_function((&function_435), env);
  pop_function();
}
/* fn_104 */
void body_279() {
  increment_count(env);
  val = new_function((&function_436), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  return_location = (&body_280);
}
void body_281();
pointer global_c95c95c95c95c115c107c105c112;
void function_437() {
  global_c95c95c95c95c115c107c105c112 = val; /* ____skip */
  return_location = (&body_281);
}
/* ____skip */
void body_280() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  apply((&function_437));
}
void body_282();
pointer global_c102c110c95c49c48c53;
void function_438() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  top_level_apply();
}
void function_439() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c114c111c112c45c115c101c99c111c110c100); /* ____drop-second */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c101c113); /* ____seq */
  apply((&function_438));
}
void function_440() {
  increment_count(env);
  val = new_function((&function_439), env);
  pop_function();
}
/* fn_105 */
void body_281() {
  increment_count(env);
  val = new_function((&function_440), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  return_location = (&body_282);
}
void body_283();
pointer global_c95c95c95c95c102c105c114c115c116;
void function_441() {
  global_c95c95c95c95c102c105c114c115c116 = val; /* ____first */
  return_location = (&body_283);
}
/* ____first */
void body_282() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  apply((&function_441));
}
void body_284();
pointer global_c95c95c95c95c112c97c114c115c101c45c110c117c109 = NIL; /* ____parse-num */
pointer global_c102c110c95c49c48c54;
void function_442() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_443() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_442));
}
void function_444() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_443));
}
void function_445() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c101c101c107); /* ____peek */
  apply((&function_444));
}
void function_446() {
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
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_445));
}
void function_447() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c110c117c109); /* ____parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c117c115c101); /* ____use */
  apply((&function_446));
}
void function_448() {
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
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_447));
}
void function_449() {
  increment_count(env);
  val = new_function((&function_448), env);
  pop_function();
}
/* fn_106 */
void body_283() {
  increment_count(env);
  val = new_function((&function_449), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  return_location = (&body_284);
}
void body_285();
void function_450() {
  global_c95c95c95c95c112c97c114c115c101c45c110c117c109 = val; /* ____parse-num */
  return_location = (&body_285);
}
/* ____parse-num */
void body_284() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  apply((&function_450));
}
void body_286();
pointer global_c102c110c95c49c48c55;
void function_451() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_452() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c110c117c109); /* ____build-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c110c117c109); /* ____parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  apply((&function_451));
}
void function_453() {
  increment_count(env);
  val = new_function((&function_452), env);
  pop_function();
}
/* fn_107 */
void body_285() {
  increment_count(env);
  val = new_function((&function_453), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  return_location = (&body_286);
}
void body_287();
pointer global_c95c95c95c95c114c101c97c100c45c110c117c109;
void function_454() {
  global_c95c95c95c95c114c101c97c100c45c110c117c109 = val; /* ____read-num */
  return_location = (&body_287);
}
/* ____read-num */
void body_286() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  apply((&function_454));
}
void body_288();
pointer global_c95c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* ____parse-symbol */
pointer global_c102c110c95c49c48c56;
void function_455() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_456() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_455));
}
void function_457() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_456));
}
void function_458() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_457));
}
void function_459() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_458));
}
void function_460() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c101c101c107); /* ____peek */
  apply((&function_459));
}
void function_461() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
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
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_460));
}
void function_462() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_461));
}
void function_463() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c101c101c107); /* ____peek */
  apply((&function_462));
}
void function_464() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_463));
}
void function_465() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_464));
}
void function_466() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c101c101c107); /* ____peek */
  apply((&function_465));
}
void function_467() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_466));
}
void function_468() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_467));
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
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* ____parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c117c115c101); /* ____use */
  apply((&function_468));
}
void function_470() {
  increment_count(env);
  val = new_function((&function_469), env);
  pop_function();
}
/* fn_108 */
void body_287() {
  increment_count(env);
  val = new_function((&function_470), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  return_location = (&body_288);
}
void body_289();
void function_471() {
  global_c95c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* ____parse-symbol */
  return_location = (&body_289);
}
/* ____parse-symbol */
void body_288() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  apply((&function_471));
}
void body_290();
pointer global_c102c110c95c49c48c57;
void function_472() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_473() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c108c111c111c107c117c112c45c115c121c109c98c111c108); /* ____lookup-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* ____parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  apply((&function_472));
}
void function_474() {
  increment_count(env);
  val = new_function((&function_473), env);
  pop_function();
}
/* fn_109 */
void body_289() {
  increment_count(env);
  val = new_function((&function_474), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  return_location = (&body_290);
}
void body_291();
pointer global_c95c95c95c95c114c101c97c100c45c115c121c109c98c111c108;
void function_475() {
  global_c95c95c95c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* ____read-symbol */
  return_location = (&body_291);
}
/* ____read-symbol */
void body_290() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  apply((&function_475));
}
void body_292();
pointer global_c95c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* ____parse-string */
pointer global_c102c110c95c49c49c48;
void function_476() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_477() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_476));
}
void function_478() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_477));
}
void function_479() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_478));
}
void function_480() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_479));
}
void function_481() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_480));
}
void function_482() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ____parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101); /* ____escape */
  apply((&function_481));
}
void function_483() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_482));
}
void function_484() {
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
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ____parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c117c115c101); /* ____use */
  apply((&function_483));
}
void function_485() {
  increment_count(env);
  val = new_function((&function_484), env);
  pop_function();
}
/* fn_110 */
void body_291() {
  increment_count(env);
  val = new_function((&function_485), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  return_location = (&body_292);
}
void body_293();
void function_486() {
  global_c95c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* ____parse-string */
  return_location = (&body_293);
}
/* ____parse-string */
void body_292() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  apply((&function_486));
}
void body_294();
pointer global_c102c110c95c49c49c49;
void function_487() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c113c117c111c116c101c45c118c97c108c117c101); /* ____quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  top_level_apply();
}
void function_488() {
  increment_count(env);
  val = new_function((&function_487), env);
  pop_function();
}
/* fn_111 */
void body_293() {
  increment_count(env);
  val = new_function((&function_488), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  return_location = (&body_294);
}
void body_295();
pointer global_c95c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_489() {
  global_c95c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ____quote-parser */
  return_location = (&body_295);
}
/* ____quote-parser */
void body_294() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  apply((&function_489));
}
void body_296();
pointer global_c102c110c95c49c49c50;
void function_490() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* ____quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  top_level_apply();
}
void function_491() {
  increment_count(env);
  val = new_function((&function_490), env);
  pop_function();
}
/* fn_112 */
void body_295() {
  increment_count(env);
  val = new_function((&function_491), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  return_location = (&body_296);
}
void body_297();
pointer global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_492() {
  global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ____quasiquote-parser */
  return_location = (&body_297);
}
/* ____quasiquote-parser */
void body_296() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  apply((&function_492));
}
void body_298();
pointer global_c102c110c95c49c49c51;
void function_493() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* ____unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* ____post-process */
  top_level_apply();
}
void function_494() {
  increment_count(env);
  val = new_function((&function_493), env);
  pop_function();
}
/* fn_113 */
void body_297() {
  increment_count(env);
  val = new_function((&function_494), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  return_location = (&body_298);
}
void body_299();
pointer global_c95c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_495() {
  global_c95c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* ____unquote-parser */
  return_location = (&body_299);
}
/* ____unquote-parser */
void body_298() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  apply((&function_495));
}
void body_300();
pointer global_c102c110c95c49c49c52 = NIL; /* fn_114 */
pointer global_c102c110c95c49c49c53;
void function_496() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  top_level_apply();
}
void function_497() {
  increment_count(env);
  val = new_function((&function_496), env);
  pop_function();
}
/* fn_115 */
void body_299() {
  increment_count(env);
  val = new_function((&function_497), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  return_location = (&body_300);
}
void body_301();
pointer global_c95c95c95c95c99c111c109c109c101c110c116 = NIL; /* ____comment */
void function_498() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_499() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_498));
}
void function_500() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_499));
}
void function_501() {
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
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_500));
}
void function_502() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_501));
}
void function_503() {
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
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_502));
}
void function_504() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_503));
}
void function_505() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c107c105c112); /* ____skip */
  apply((&function_504));
}
void function_506() {
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
  increment_count(val = global_c95c95c95c95c99c111c109c109c101c110c116); /* ____comment */
  apply((&function_505));
}
void function_507() {
  increment_count(env);
  val = new_function((&function_506), env);
  pop_function();
}
/* fn_114 */
void body_300() {
  increment_count(env);
  val = new_function((&function_507), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  return_location = (&body_301);
}
void body_302();
void function_508() {
  global_c95c95c95c95c99c111c109c109c101c110c116 = val; /* ____comment */
  return_location = (&body_302);
}
/* ____comment */
void body_301() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  apply((&function_508));
}
void body_303();
pointer global_c95c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* ____parse-paren */
pointer global_c102c110c95c49c49c54;
void function_509() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_510() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_509));
}
void function_511() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_510));
}
void function_512() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ____parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_511));
}
void function_513() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_512));
}
void function_514() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_513));
}
void function_515() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ____parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c109c101c110c116); /* ____comment */
  apply((&function_514));
}
void function_516() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_515));
}
void function_517() {
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
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_516));
}
void function_518() {
  increment_count(env);
  val = new_function((&function_517), env);
  pop_function();
}
/* fn_116 */
void body_302() {
  increment_count(env);
  val = new_function((&function_518), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  return_location = (&body_303);
}
void body_304();
void function_519() {
  global_c95c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* ____parse-paren */
  return_location = (&body_304);
}
/* ____parse-paren */
void body_303() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  apply((&function_519));
}
void body_305();
pointer global_c102c110c95c49c49c55;
void function_520() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_521() {
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
    apply((&function_520));
  }
}
void function_522() {
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
    apply((&function_521));
  }
}
void function_523() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_522));
}
void function_524() {
  increment_count(env);
  val = new_function((&function_523), env);
  pop_function();
}
/* fn_117 */
void body_304() {
  increment_count(env);
  val = new_function((&function_524), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  return_location = (&body_305);
}
void body_306();
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
void function_525() {
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  return_location = (&body_306);
}
/* _escape-char */
void body_305() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  apply((&function_525));
}
void body_307();
pointer global_c102c110c95c49c49c56 = NIL; /* fn_118 */
pointer global_c102c110c95c49c49c57;
void function_526() {
  top_level_apply();
}
void function_527() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  apply((&function_526));
}
void function_528() {
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
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  apply((&function_527));
}
void function_529() {
  increment_count(env);
  val = new_function((&function_528), env);
  pop_function();
}
/* fn_119 */
void body_306() {
  increment_count(env);
  val = new_function((&function_529), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  return_location = (&body_307);
}
void body_308();
void function_530() {
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
void function_531() {
  increment_count(env);
  val = new_function((&function_530), env);
  pop_function();
}
/* fn_118 */
void body_307() {
  increment_count(env);
  val = new_function((&function_531), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  return_location = (&body_308);
}
void body_309();
pointer global_c95c98c117c105c108c100c45c110c117c109;
void function_532() {
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  return_location = (&body_309);
}
/* _build-num */
void body_308() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  apply((&function_532));
}
void body_310();
pointer global_c102c110c95c49c50c48;
void function_533() {
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
void function_534() {
  increment_count(env);
  val = new_function((&function_533), env);
  pop_function();
}
/* fn_120 */
void body_309() {
  increment_count(env);
  val = new_function((&function_534), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  return_location = (&body_310);
}
void body_311();
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
void function_535() {
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  return_location = (&body_311);
}
/* _quote-value */
void body_310() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  apply((&function_535));
}
void body_312();
pointer global_c102c110c95c49c50c49;
void function_536() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -42;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_537() {
  increment_count(env);
  val = new_function((&function_536), env);
  pop_function();
}
/* fn_121 */
void body_311() {
  increment_count(env);
  val = new_function((&function_537), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  return_location = (&body_312);
}
void body_313();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_538() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  return_location = (&body_313);
}
/* _quasiquote-value */
void body_312() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  apply((&function_538));
}
void body_314();
pointer global_c102c110c95c49c50c50;
void function_539() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  top_level_apply();
}
void function_540() {
  increment_count(env);
  val = new_function((&function_539), env);
  pop_function();
}
/* fn_122 */
void body_313() {
  increment_count(env);
  val = new_function((&function_540), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  return_location = (&body_314);
}
void body_315();
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_541() {
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  return_location = (&body_315);
}
/* _unquote-value */
void body_314() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  apply((&function_541));
}
void body_316();
pointer global_c102c110c95c49c50c51 = NIL; /* fn_123 */
pointer global_c102c110c95c49c50c52;
void function_542() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  top_level_apply();
}
void function_543() {
  increment_count(env);
  val = new_function((&function_542), env);
  pop_function();
}
/* fn_124 */
void body_315() {
  increment_count(env);
  val = new_function((&function_543), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  return_location = (&body_316);
}
void body_317();
void function_544() {
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
void function_545() {
  increment_count(env);
  val = new_function((&function_544), env);
  pop_function();
}
/* fn_123 */
void body_316() {
  increment_count(env);
  val = new_function((&function_545), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  return_location = (&body_317);
}
void body_318();
pointer global_c95c102c97c105c108;
void function_546() {
  global_c95c102c97c105c108 = val; /* _fail */
  return_location = (&body_318);
}
/* _fail */
void body_317() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  apply((&function_546));
}
void body_319();
pointer global_c102c110c95c49c50c53;
void function_547() {
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
void function_548() {
  increment_count(env);
  val = new_function((&function_547), env);
  pop_function();
}
/* fn_125 */
void body_318() {
  increment_count(env);
  val = new_function((&function_548), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  return_location = (&body_319);
}
void body_320();
pointer global_c95c100c111c110c101;
void function_549() {
  global_c95c100c111c110c101 = val; /* _done */
  return_location = (&body_320);
}
/* _done */
void body_319() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  apply((&function_549));
}
void body_321();
pointer global_c102c110c95c49c50c54 = NIL; /* fn_126 */
pointer global_c102c110c95c49c50c55;
void function_550() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  top_level_apply();
}
void function_551() {
  increment_count(env);
  val = new_function((&function_550), env);
  pop_function();
}
/* fn_127 */
void body_320() {
  increment_count(env);
  val = new_function((&function_551), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  return_location = (&body_321);
}
void body_322();
pointer global_c95c112c111c112 = NIL; /* _pop */
void function_552() {
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
void function_553() {
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
      apply((&function_552));
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
void function_554() {
  increment_count(env);
  val = new_function((&function_553), env);
  pop_function();
}
/* fn_126 */
void body_321() {
  increment_count(env);
  val = new_function((&function_554), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  return_location = (&body_322);
}
void body_323();
void function_555() {
  global_c95c112c111c112 = val; /* _pop */
  return_location = (&body_323);
}
/* _pop */
void body_322() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  apply((&function_555));
}
void body_324();
pointer global_c102c110c95c49c50c57 = NIL; /* fn_129 */
pointer global_c102c110c95c49c51c48;
void function_556() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  top_level_apply();
}
void function_557() {
  increment_count(env);
  val = new_function((&function_556), env);
  pop_function();
}
/* fn_130 */
void body_323() {
  increment_count(env);
  val = new_function((&function_557), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  return_location = (&body_324);
}
void body_325();
pointer global_c102c110c95c49c50c56 = NIL; /* fn_128 */
void function_558() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  top_level_apply();
}
void function_559() {
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
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  apply((&function_558));
}
void function_560() {
  increment_count(env);
  val = new_function((&function_559), env);
  pop_function();
}
/* fn_129 */
void body_324() {
  increment_count(env);
  val = new_function((&function_560), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  return_location = (&body_325);
}
void body_326();
void function_561() {
  top_level_apply();
}
void function_562() {
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
    apply((&function_561));
  }
}
void function_563() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_562));
}
void function_564() {
  increment_count(env);
  val = new_function((&function_563), env);
  pop_function();
}
/* fn_128 */
void body_325() {
  increment_count(env);
  val = new_function((&function_564), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  return_location = (&body_326);
}
void body_327();
pointer global_c95c99c104c101c99c107;
void function_565() {
  global_c95c99c104c101c99c107 = val; /* _check */
  return_location = (&body_327);
}
/* _check */
void body_326() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  apply((&function_565));
}
void body_328();
pointer global_c102c110c95c49c51c49 = NIL; /* fn_131 */
pointer global_c102c110c95c49c51c50;
void function_566() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_567() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  apply((&function_566));
}
void function_568() {
  increment_count(env);
  val = new_function((&function_567), env);
  pop_function();
}
/* fn_132 */
void body_327() {
  increment_count(env);
  val = new_function((&function_568), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  return_location = (&body_328);
}
void body_329();
void function_569() {
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
void function_570() {
  increment_count(env);
  val = new_function((&function_569), env);
  pop_function();
}
/* fn_131 */
void body_328() {
  increment_count(env);
  val = new_function((&function_570), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  return_location = (&body_329);
}
void body_330();
pointer global_c95c109c97c116c99c104;
void function_571() {
  global_c95c109c97c116c99c104 = val; /* _match */
  return_location = (&body_330);
}
/* _match */
void body_329() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  apply((&function_571));
}
void body_331();
pointer global_c102c110c95c49c51c51 = NIL; /* fn_133 */
pointer global_c102c110c95c49c51c52;
void function_572() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  top_level_apply();
}
void function_573() {
  increment_count(env);
  val = new_function((&function_572), env);
  pop_function();
}
/* fn_134 */
void body_330() {
  increment_count(env);
  val = new_function((&function_573), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  return_location = (&body_331);
}
void body_332();
void function_574() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_575() {
  increment_count(env);
  val = new_function((&function_574), env);
  pop_function();
}
/* fn_133 */
void body_331() {
  increment_count(env);
  val = new_function((&function_575), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  return_location = (&body_332);
}
void body_333();
pointer global_c95c100c101c102c97c117c108c116;
void function_576() {
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  return_location = (&body_333);
}
/* _default */
void body_332() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  apply((&function_576));
}
void body_334();
pointer global_c102c110c95c49c51c56 = NIL; /* fn_138 */
pointer global_c102c110c95c49c51c57;
void function_577() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  top_level_apply();
}
void function_578() {
  increment_count(env);
  val = new_function((&function_577), env);
  pop_function();
}
/* fn_139 */
void body_333() {
  increment_count(env);
  val = new_function((&function_578), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  return_location = (&body_334);
}
void body_335();
pointer global_c102c110c95c49c51c55 = NIL; /* fn_137 */
void function_579() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  top_level_apply();
}
void function_580() {
  increment_count(env);
  val = new_function((&function_579), env);
  pop_function();
}
/* fn_138 */
void body_334() {
  increment_count(env);
  val = new_function((&function_580), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  return_location = (&body_335);
}
void body_336();
pointer global_c102c110c95c49c51c54 = NIL; /* fn_136 */
pointer global_c102c110c95c49c51c53 = NIL; /* fn_135 */
void function_581() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_582() {
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
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  apply((&function_581));
}
void function_583() {
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
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  apply((&function_582));
}
void function_584() {
  increment_count(env);
  val = new_function((&function_583), env);
  pop_function();
}
/* fn_137 */
void body_335() {
  increment_count(env);
  val = new_function((&function_584), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  return_location = (&body_336);
}
void body_337();
void function_585() {
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
void function_586() {
  increment_count(env);
  val = new_function((&function_585), env);
  pop_function();
}
/* fn_135 */
void body_336() {
  increment_count(env);
  val = new_function((&function_586), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  return_location = (&body_337);
}
void body_338();
void function_587() {
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
void function_588() {
  increment_count(env);
  val = new_function((&function_587), env);
  pop_function();
}
/* fn_136 */
void body_337() {
  increment_count(env);
  val = new_function((&function_588), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  return_location = (&body_338);
}
void body_339();
pointer global_c95c99c97c115c101;
void function_589() {
  global_c95c99c97c115c101 = val; /* _case */
  return_location = (&body_339);
}
/* _case */
void body_338() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c57); /* fn_139 */
  apply((&function_589));
}
void body_340();
pointer global_c102c110c95c49c52c48 = NIL; /* fn_140 */
pointer global_c102c110c95c49c52c49;
void function_590() {
  top_level_apply();
}
void function_591() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_590));
}
void function_592() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
  apply((&function_591));
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
  apply((&function_592));
}
void function_594() {
  increment_count(env);
  val = new_function((&function_593), env);
  pop_function();
}
/* fn_141 */
void body_339() {
  increment_count(env);
  val = new_function((&function_594), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  return_location = (&body_340);
}
void body_341();
void function_595() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_596() {
  increment_count(env);
  val = new_function((&function_595), env);
  pop_function();
}
/* fn_140 */
void body_340() {
  increment_count(env);
  val = new_function((&function_596), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  return_location = (&body_341);
}
void body_342();
pointer global_c95c99c104c111c105c99c101;
void function_597() {
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  return_location = (&body_342);
}
/* _choice */
void body_341() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
  apply((&function_597));
}
void body_343();
pointer global_c102c110c95c49c52c51 = NIL; /* fn_143 */
pointer global_c102c110c95c49c52c52;
void function_598() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  top_level_apply();
}
void function_599() {
  increment_count(env);
  val = new_function((&function_598), env);
  pop_function();
}
/* fn_144 */
void body_342() {
  increment_count(env);
  val = new_function((&function_599), env);
  global_c102c110c95c49c52c52 = val; /* fn_144 */
  return_location = (&body_343);
}
void body_344();
pointer global_c102c110c95c49c52c50 = NIL; /* fn_142 */
void function_600() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_601() {
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
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  apply((&function_600));
}
void function_602() {
  increment_count(env);
  val = new_function((&function_601), env);
  pop_function();
}
/* fn_143 */
void body_343() {
  increment_count(env);
  val = new_function((&function_602), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  return_location = (&body_344);
}
void body_345();
void function_603() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_604() {
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
  apply((&function_603));
}
void function_605() {
  increment_count(env);
  val = new_function((&function_604), env);
  pop_function();
}
/* fn_142 */
void body_344() {
  increment_count(env);
  val = new_function((&function_605), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  return_location = (&body_345);
}
void body_346();
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_606() {
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  return_location = (&body_346);
}
/* _post-process */
void body_345() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c52); /* fn_144 */
  apply((&function_606));
}
void body_347();
pointer global_c102c110c95c49c52c55 = NIL; /* fn_147 */
pointer global_c102c110c95c49c52c56;
void function_607() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c55); /* fn_147 */
  top_level_apply();
}
void function_608() {
  increment_count(env);
  val = new_function((&function_607), env);
  pop_function();
}
/* fn_148 */
void body_346() {
  increment_count(env);
  val = new_function((&function_608), env);
  global_c102c110c95c49c52c56 = val; /* fn_148 */
  return_location = (&body_347);
}
void body_348();
pointer global_c102c110c95c49c52c54 = NIL; /* fn_146 */
void function_609() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_610() {
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
  increment_count(val = global_c102c110c95c49c52c54); /* fn_146 */
  apply((&function_609));
}
void function_611() {
  increment_count(env);
  val = new_function((&function_610), env);
  pop_function();
}
/* fn_147 */
void body_347() {
  increment_count(env);
  val = new_function((&function_611), env);
  global_c102c110c95c49c52c55 = val; /* fn_147 */
  return_location = (&body_348);
}
void body_349();
pointer global_c102c110c95c49c52c53 = NIL; /* fn_145 */
void function_612() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_613() {
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
  increment_count(val = global_c102c110c95c49c52c53); /* fn_145 */
  apply((&function_612));
}
void function_614() {
  increment_count(env);
  val = new_function((&function_613), env);
  pop_function();
}
/* fn_146 */
void body_348() {
  increment_count(env);
  val = new_function((&function_614), env);
  global_c102c110c95c49c52c54 = val; /* fn_146 */
  return_location = (&body_349);
}
void body_350();
void function_615() {
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
void function_616() {
  increment_count(env);
  val = new_function((&function_615), env);
  pop_function();
}
/* fn_145 */
void body_349() {
  increment_count(env);
  val = new_function((&function_616), env);
  global_c102c110c95c49c52c53 = val; /* fn_145 */
  return_location = (&body_350);
}
void body_351();
pointer global_c95c115c101c113;
void function_617() {
  global_c95c115c101c113 = val; /* _seq */
  return_location = (&body_351);
}
/* _seq */
void body_350() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c56); /* fn_148 */
  apply((&function_617));
}
void body_352();
pointer global_c102c110c95c49c52c57;
void function_618() {
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  top_level_apply();
}
void function_619() {
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
  apply((&function_618));
}
void function_620() {
  increment_count(env);
  val = new_function((&function_619), env);
  pop_function();
}
/* fn_149 */
void body_351() {
  increment_count(env);
  val = new_function((&function_620), env);
  global_c102c110c95c49c52c57 = val; /* fn_149 */
  return_location = (&body_352);
}
void body_353();
pointer global_c95c101c115c99c97c112c101;
void function_621() {
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  return_location = (&body_353);
}
/* _escape */
void body_352() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c57); /* fn_149 */
  apply((&function_621));
}
void body_354();
pointer global_c102c110c95c49c53c48;
void function_622() {
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
void function_623() {
  increment_count(env);
  val = new_function((&function_622), env);
  pop_function();
}
/* fn_150 */
void body_353() {
  increment_count(env);
  val = new_function((&function_623), env);
  global_c102c110c95c49c53c48 = val; /* fn_150 */
  return_location = (&body_354);
}
void body_355();
pointer global_c95c117c115c101;
void function_624() {
  global_c95c117c115c101 = val; /* _use */
  return_location = (&body_355);
}
/* _use */
void body_354() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c48); /* fn_150 */
  apply((&function_624));
}
void body_356();
pointer global_c102c110c95c49c53c50 = NIL; /* fn_152 */
pointer global_c102c110c95c49c53c51;
void function_625() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c53c50); /* fn_152 */
  top_level_apply();
}
void function_626() {
  increment_count(env);
  val = new_function((&function_625), env);
  pop_function();
}
/* fn_153 */
void body_355() {
  increment_count(env);
  val = new_function((&function_626), env);
  global_c102c110c95c49c53c51 = val; /* fn_153 */
  return_location = (&body_356);
}
void body_357();
pointer global_c102c110c95c49c53c49 = NIL; /* fn_151 */
void function_627() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_628() {
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
  increment_count(val = global_c102c110c95c49c53c49); /* fn_151 */
  apply((&function_627));
}
void function_629() {
  increment_count(env);
  val = new_function((&function_628), env);
  pop_function();
}
/* fn_152 */
void body_356() {
  increment_count(env);
  val = new_function((&function_629), env);
  global_c102c110c95c49c53c50 = val; /* fn_152 */
  return_location = (&body_357);
}
void body_358();
void function_630() {
  top_level_apply();
}
void function_631() {
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
  apply((&function_630));
}
void function_632() {
  increment_count(env);
  val = new_function((&function_631), env);
  pop_function();
}
/* fn_151 */
void body_357() {
  increment_count(env);
  val = new_function((&function_632), env);
  global_c102c110c95c49c53c49 = val; /* fn_151 */
  return_location = (&body_358);
}
void body_359();
pointer global_c95c112c101c101c107;
void function_633() {
  global_c95c112c101c101c107 = val; /* _peek */
  return_location = (&body_359);
}
/* _peek */
void body_358() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c51); /* fn_153 */
  apply((&function_633));
}
void body_360();
pointer global_c102c110c95c49c53c52 = NIL; /* fn_154 */
pointer global_c102c110c95c49c53c53;
void function_634() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  top_level_apply();
}
void function_635() {
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
  increment_count(val = global_c102c110c95c49c53c52); /* fn_154 */
  apply((&function_634));
}
void function_636() {
  increment_count(env);
  val = new_function((&function_635), env);
  pop_function();
}
/* fn_155 */
void body_359() {
  increment_count(env);
  val = new_function((&function_636), env);
  global_c102c110c95c49c53c53 = val; /* fn_155 */
  return_location = (&body_360);
}
void body_361();
void function_637() {
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
void function_638() {
  increment_count(env);
  val = new_function((&function_637), env);
  pop_function();
}
/* fn_154 */
void body_360() {
  increment_count(env);
  val = new_function((&function_638), env);
  global_c102c110c95c49c53c52 = val; /* fn_154 */
  return_location = (&body_361);
}
void body_362();
pointer global_c95c105c110c116c101c114c118c97c108;
void function_639() {
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  return_location = (&body_362);
}
/* _interval */
void body_361() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c53); /* fn_155 */
  apply((&function_639));
}
void body_363();
pointer global_c99c100c114 = CDR; /* cdr */
pointer global_c102c110c95c49c53c54;
void function_640() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_641() {
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
  apply((&function_640));
}
void function_642() {
  increment_count(env);
  val = new_function((&function_641), env);
  pop_function();
}
/* fn_156 */
void body_362() {
  increment_count(env);
  val = new_function((&function_642), env);
  global_c102c110c95c49c53c54 = val; /* fn_156 */
  return_location = (&body_363);
}
void body_364();
pointer global_c95c115c107c105c112;
void function_643() {
  global_c95c115c107c105c112 = val; /* _skip */
  return_location = (&body_364);
}
/* _skip */
void body_363() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c54); /* fn_156 */
  apply((&function_643));
}
void body_365();
pointer global_c99c97c114 = CAR; /* car */
pointer global_c102c110c95c49c53c55;
void function_644() {
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  top_level_apply();
}
void function_645() {
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
  apply((&function_644));
}
void function_646() {
  increment_count(env);
  val = new_function((&function_645), env);
  pop_function();
}
/* fn_157 */
void body_364() {
  increment_count(env);
  val = new_function((&function_646), env);
  global_c102c110c95c49c53c55 = val; /* fn_157 */
  return_location = (&body_365);
}
void body_366();
pointer global_c95c102c105c114c115c116;
void function_647() {
  global_c95c102c105c114c115c116 = val; /* _first */
  return_location = (&body_366);
}
/* _first */
void body_365() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c55); /* fn_157 */
  apply((&function_647));
}
void body_367();
pointer global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
pointer global_c102c110c95c49c53c56;
void function_648() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_649() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_648));
}
void function_650() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_649));
}
void function_651() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_650));
}
void function_652() {
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
  apply((&function_651));
}
void function_653() {
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
  apply((&function_652));
}
void function_654() {
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
  apply((&function_653));
}
void function_655() {
  increment_count(env);
  val = new_function((&function_654), env);
  pop_function();
}
/* fn_158 */
void body_366() {
  increment_count(env);
  val = new_function((&function_655), env);
  global_c102c110c95c49c53c56 = val; /* fn_158 */
  return_location = (&body_367);
}
void body_368();
void function_656() {
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  return_location = (&body_368);
}
/* _parse-num */
void body_367() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c56); /* fn_158 */
  apply((&function_656));
}
void body_369();
pointer global_c102c110c95c49c53c57;
void function_657() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_658() {
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
  apply((&function_657));
}
void function_659() {
  increment_count(env);
  val = new_function((&function_658), env);
  pop_function();
}
/* fn_159 */
void body_368() {
  increment_count(env);
  val = new_function((&function_659), env);
  global_c102c110c95c49c53c57 = val; /* fn_159 */
  return_location = (&body_369);
}
void body_370();
pointer global_c95c114c101c97c100c45c110c117c109;
void function_660() {
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  return_location = (&body_370);
}
/* _read-num */
void body_369() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c57); /* fn_159 */
  apply((&function_660));
}
void body_371();
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
pointer global_c102c110c95c49c54c48;
void function_661() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_662() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
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
  apply((&function_663));
}
void function_665() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_664));
}
void function_666() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_665));
}
void function_667() {
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
  apply((&function_666));
}
void function_668() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_667));
}
void function_669() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_668));
}
void function_670() {
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
  apply((&function_669));
}
void function_671() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_670));
}
void function_672() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_671));
}
void function_673() {
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
  apply((&function_672));
}
void function_674() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_673));
}
void function_675() {
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
  apply((&function_674));
}
void function_676() {
  increment_count(env);
  val = new_function((&function_675), env);
  pop_function();
}
/* fn_160 */
void body_370() {
  increment_count(env);
  val = new_function((&function_676), env);
  global_c102c110c95c49c54c48 = val; /* fn_160 */
  return_location = (&body_371);
}
void body_372();
void function_677() {
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  return_location = (&body_372);
}
/* _parse-symbol */
void body_371() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c48); /* fn_160 */
  apply((&function_677));
}
void body_373();
pointer global_c102c110c95c49c54c49;
void function_678() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
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
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  apply((&function_678));
}
void function_680() {
  increment_count(env);
  val = new_function((&function_679), env);
  pop_function();
}
/* fn_161 */
void body_372() {
  increment_count(env);
  val = new_function((&function_680), env);
  global_c102c110c95c49c54c49 = val; /* fn_161 */
  return_location = (&body_373);
}
void body_374();
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
void function_681() {
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  return_location = (&body_374);
}
/* _read-symbol */
void body_373() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c49); /* fn_161 */
  apply((&function_681));
}
void body_375();
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
pointer global_c102c110c95c49c54c50;
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
  increment_count(val = global_c95c100c111c110c101); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
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
  val = new_number(92);
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
  increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c101c115c99c97c112c101); /* _escape */
  apply((&function_687));
}
void function_689() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_688));
}
void function_690() {
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
  apply((&function_689));
}
void function_691() {
  increment_count(env);
  val = new_function((&function_690), env);
  pop_function();
}
/* fn_162 */
void body_374() {
  increment_count(env);
  val = new_function((&function_691), env);
  global_c102c110c95c49c54c50 = val; /* fn_162 */
  return_location = (&body_375);
}
void body_376();
void function_692() {
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  return_location = (&body_376);
}
/* _parse-string */
void body_375() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c50); /* fn_162 */
  apply((&function_692));
}
void body_377();
pointer global_c102c110c95c49c54c51;
void function_693() {
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
void function_694() {
  increment_count(env);
  val = new_function((&function_693), env);
  pop_function();
}
/* fn_163 */
void body_376() {
  increment_count(env);
  val = new_function((&function_694), env);
  global_c102c110c95c49c54c51 = val; /* fn_163 */
  return_location = (&body_377);
}
void body_378();
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_695() {
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  return_location = (&body_378);
}
/* _quote-parser */
void body_377() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c51); /* fn_163 */
  apply((&function_695));
}
void body_379();
pointer global_c102c110c95c49c54c52;
void function_696() {
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
void function_697() {
  increment_count(env);
  val = new_function((&function_696), env);
  pop_function();
}
/* fn_164 */
void body_378() {
  increment_count(env);
  val = new_function((&function_697), env);
  global_c102c110c95c49c54c52 = val; /* fn_164 */
  return_location = (&body_379);
}
void body_380();
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_698() {
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  return_location = (&body_380);
}
/* _quasiquote-parser */
void body_379() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c52); /* fn_164 */
  apply((&function_698));
}
void body_381();
pointer global_c102c110c95c49c54c53;
void function_699() {
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
void function_700() {
  increment_count(env);
  val = new_function((&function_699), env);
  pop_function();
}
/* fn_165 */
void body_380() {
  increment_count(env);
  val = new_function((&function_700), env);
  global_c102c110c95c49c54c53 = val; /* fn_165 */
  return_location = (&body_381);
}
void body_382();
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_701() {
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  return_location = (&body_382);
}
/* _unquote-parser */
void body_381() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c53); /* fn_165 */
  apply((&function_701));
}
void body_383();
pointer global_c102c110c95c49c54c54 = NIL; /* fn_166 */
pointer global_c102c110c95c49c54c55;
void function_702() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c54c54); /* fn_166 */
  top_level_apply();
}
void function_703() {
  increment_count(env);
  val = new_function((&function_702), env);
  pop_function();
}
/* fn_167 */
void body_382() {
  increment_count(env);
  val = new_function((&function_703), env);
  global_c102c110c95c49c54c55 = val; /* fn_167 */
  return_location = (&body_383);
}
void body_384();
pointer global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
void function_704() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_705() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_704));
}
void function_706() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_705));
}
void function_707() {
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(13);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_708));
}
void function_710() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_709));
}
void function_711() {
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  apply((&function_710));
}
void function_712() {
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
  apply((&function_711));
}
void function_713() {
  increment_count(env);
  val = new_function((&function_712), env);
  pop_function();
}
/* fn_166 */
void body_383() {
  increment_count(env);
  val = new_function((&function_713), env);
  global_c102c110c95c49c54c54 = val; /* fn_166 */
  return_location = (&body_384);
}
void body_385();
void function_714() {
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  return_location = (&body_385);
}
/* _comment */
void body_384() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c55); /* fn_167 */
  apply((&function_714));
}
void body_386();
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
pointer global_c102c110c95c49c54c56;
void function_715() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_716() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_715));
}
void function_717() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_716));
}
void function_718() {
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
  val = new_number(59);
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
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c99c111c109c109c101c110c116); /* _comment */
  apply((&function_720));
}
void function_722() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_721));
}
void function_723() {
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
  apply((&function_722));
}
void function_724() {
  increment_count(env);
  val = new_function((&function_723), env);
  pop_function();
}
/* fn_168 */
void body_385() {
  increment_count(env);
  val = new_function((&function_724), env);
  global_c102c110c95c49c54c56 = val; /* fn_168 */
  return_location = (&body_386);
}
void body_387();
void function_725() {
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  return_location = (&body_387);
}
/* _parse-paren */
void body_386() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c56); /* fn_168 */
  apply((&function_725));
}
void body_388();
pointer global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
pointer global_c102c110c95c49c54c57;
void function_726() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_727() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_726));
}
void function_728() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_727));
}
void function_729() {
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
  apply((&function_728));
}
void function_730() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_729));
}
void function_731() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_730));
}
void function_732() {
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
  apply((&function_731));
}
void function_733() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_732));
}
void function_734() {
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
  apply((&function_733));
}
void function_735() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_734));
}
void function_736() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_735));
}
void function_737() {
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
  apply((&function_736));
}
void function_738() {
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  apply((&function_737));
}
void function_739() {
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
  apply((&function_738));
}
void function_740() {
  increment_count(env);
  val = new_function((&function_739), env);
  pop_function();
}
/* fn_169 */
void body_387() {
  increment_count(env);
  val = new_function((&function_740), env);
  global_c102c110c95c49c54c57 = val; /* fn_169 */
  return_location = (&body_388);
}
void body_389();
void function_741() {
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  return_location = (&body_389);
}
/* _parse-pair */
void body_388() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c57); /* fn_169 */
  apply((&function_741));
}
void body_390();
pointer global_c102c110c95c49c55c48;
void function_742() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_743() {
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  apply((&function_742));
}
void function_744() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_743));
}
void function_745() {
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
  apply((&function_744));
}
void function_746() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_745));
}
void function_747() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_746));
}
void function_748() {
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
  apply((&function_747));
}
void function_749() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_748));
}
void function_750() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_749));
}
void function_751() {
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
  apply((&function_750));
}
void function_752() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_751));
}
void function_753() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_752));
}
void function_754() {
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
  apply((&function_753));
}
void function_755() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_754));
}
void function_756() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
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
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114); /* _unquote-parser */
  apply((&function_756));
}
void function_758() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_757));
}
void function_759() {
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
  apply((&function_758));
}
void function_760() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_759));
}
void function_761() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_760));
}
void function_762() {
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
  apply((&function_761));
}
void function_763() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_762));
}
void function_764() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_763));
}
void function_765() {
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
  apply((&function_764));
}
void function_766() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_765));
}
void function_767() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  apply((&function_766));
}
void function_768() {
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
  apply((&function_767));
}
void function_769() {
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  apply((&function_768));
}
void function_770() {
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  apply((&function_769));
}
void function_771() {
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
  apply((&function_770));
}
void function_772() {
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
  apply((&function_771));
}
void function_773() {
  increment_count(env);
  val = new_function((&function_772), env);
  pop_function();
}
/* fn_170 */
void body_389() {
  increment_count(env);
  val = new_function((&function_773), env);
  global_c102c110c95c49c55c48 = val; /* fn_170 */
  return_location = (&body_390);
}
void body_391();
void function_774() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_391);
}
/* _parse-expr */
void body_390() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c48); /* fn_170 */
  apply((&function_774));
}
void body_392();
pointer global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* ____parse-pair */
pointer global_c102c110c95c49c55c49;
void function_775() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_776() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_775));
}
void function_777() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_776));
}
void function_778() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ____parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_777));
}
void function_779() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_778));
}
void function_780() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_779));
}
void function_781() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ____parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c109c101c110c116); /* ____comment */
  apply((&function_780));
}
void function_782() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_781));
}
void function_783() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c100c111c110c101); /* ____done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_782));
}
void function_784() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_783));
}
void function_785() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_784));
}
void function_786() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c114c101c110); /* ____parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c105c114c115c116); /* ____first */
  apply((&function_785));
}
void function_787() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_786));
}
void function_788() {
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
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ____parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c101c113); /* ____seq */
  apply((&function_787));
}
void function_789() {
  increment_count(env);
  val = new_function((&function_788), env);
  pop_function();
}
/* fn_171 */
void body_391() {
  increment_count(env);
  val = new_function((&function_789), env);
  global_c102c110c95c49c55c49 = val; /* fn_171 */
  return_location = (&body_392);
}
void body_393();
void function_790() {
  global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* ____parse-pair */
  return_location = (&body_393);
}
/* ____parse-pair */
void body_392() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c49); /* fn_171 */
  apply((&function_790));
}
void body_394();
pointer global_c102c110c95c49c55c50;
void function_791() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  top_level_apply();
}
void function_792() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c104c111c105c99c101); /* ____choice */
  apply((&function_791));
}
void function_793() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_792));
}
void function_794() {
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
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_793));
}
void function_795() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_794));
}
void function_796() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_795));
}
void function_797() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* ____parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* ____quote-parser */
  apply((&function_796));
}
void function_798() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_797));
}
void function_799() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_798));
}
void function_800() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* ____quote-parser */
  apply((&function_799));
}
void function_801() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_800));
}
void function_802() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_801));
}
void function_803() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114); /* ____quasiquote-parser */
  apply((&function_802));
}
void function_804() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_803));
}
void function_805() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_804));
}
void function_806() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114); /* ____unquote-parser */
  apply((&function_805));
}
void function_807() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_806));
}
void function_808() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c112c97c114c115c101c45c112c97c105c114); /* ____parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_807));
}
void function_809() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_808));
}
void function_810() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c102c97c105c108); /* ____fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_809));
}
void function_811() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_810));
}
void function_812() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c102c97c105c108); /* ____fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_811));
}
void function_813() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_812));
}
void function_814() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c116c99c104); /* ____match */
  apply((&function_813));
}
void function_815() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c109c101c110c116); /* ____comment */
  apply((&function_814));
}
void function_816() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c97c115c101); /* ____case */
  apply((&function_815));
}
void function_817() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c101c101c107); /* ____peek */
  apply((&function_816));
}
void function_818() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c110c117c109); /* ____read-num */
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
  increment_count(val = global_c95c95c95c95c105c110c116c101c114c118c97c108); /* ____interval */
  apply((&function_817));
}
void function_819() {
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
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c115c121c109c98c111c108); /* ____read-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c97c117c108c116); /* ____default */
  apply((&function_818));
}
void function_820() {
  increment_count(env);
  val = new_function((&function_819), env);
  pop_function();
}
/* fn_172 */
void body_393() {
  increment_count(env);
  val = new_function((&function_820), env);
  global_c102c110c95c49c55c50 = val; /* fn_172 */
  return_location = (&body_394);
}
void body_395();
void function_821() {
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  return_location = (&body_395);
}
/* _parse-expr */
void body_394() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c50); /* fn_172 */
  apply((&function_821));
}
void body_396();
pointer global_c95c95c95c108c95c49c49c50;
/* ___l_112 */
void body_395() {
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
  global_c95c95c95c108c95c49c49c50 = val; /* ___l_112 */
  return_location = (&body_396);
}
void body_397();
pointer global_c95c95c95c108c95c49c49c51;
/* ___l_113 */
void body_396() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c49c51 = val; /* ___l_113 */
  return_location = (&body_397);
}
void body_398();
pointer global_c102c110c95c49c55c51 = NIL; /* fn_173 */
pointer global_c102c110c95c49c55c52;
void function_822() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  top_level_apply();
}
void function_823() {
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
  increment_count(val = global_c102c110c95c49c55c51); /* fn_173 */
  apply((&function_822));
}
void function_824() {
  increment_count(env);
  val = new_function((&function_823), env);
  pop_function();
}
/* fn_174 */
void body_397() {
  increment_count(env);
  val = new_function((&function_824), env);
  global_c102c110c95c49c55c52 = val; /* fn_174 */
  return_location = (&body_398);
}
void body_399();
pointer global_c95c95c95c95c112c114c105c110c116c45c110c117c109 = NIL; /* ____print-num */
void function_825() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  top_level_apply();
}
void function_826() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c49c50); /* ___l_112 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  apply((&function_825));
}
void function_827() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c49c51); /* ___l_113 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c110c117c109); /* ____print-num */
  apply((&function_826));
}
void function_828() {
  increment_count(env);
  val = new_function((&function_827), env);
  pop_function();
}
/* fn_173 */
void body_398() {
  increment_count(env);
  val = new_function((&function_828), env);
  global_c102c110c95c49c55c51 = val; /* fn_173 */
  return_location = (&body_399);
}
void body_400();
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
void function_829() {
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  return_location = (&body_400);
}
/* ____read-expr */
void body_399() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c52); /* fn_174 */
  apply((&function_829));
}
void body_401();
pointer global_c102c110c95c49c56c48 = NIL; /* fn_180 */
pointer global_c102c110c95c49c55c57 = NIL; /* fn_179 */
pointer global_c102c110c95c49c55c55 = NIL; /* fn_177 */
pointer global_c102c110c95c49c55c54 = NIL; /* fn_176 */
pointer global_c102c110c95c49c55c53 = NIL; /* fn_175 */
pointer global_c102c110c95c49c56c49;
void function_830() {
  top_level_apply();
}
void function_831() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c119c97c108c107); /* ____walk */
  apply((&function_830));
}
void function_832() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c53); /* fn_175 */
  apply((&function_831));
}
void function_833() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c54); /* fn_176 */
  apply((&function_832));
}
void function_834() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c55); /* fn_177 */
  apply((&function_833));
}
void function_835() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55c57); /* fn_179 */
  apply((&function_834));
}
void function_836() {
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
  increment_count(val = global_c102c110c95c49c56c48); /* fn_180 */
  apply((&function_835));
}
void function_837() {
  increment_count(env);
  val = new_function((&function_836), env);
  pop_function();
}
/* fn_181 */
void body_400() {
  increment_count(env);
  val = new_function((&function_837), env);
  global_c102c110c95c49c56c49 = val; /* fn_181 */
  return_location = (&body_401);
}
void body_402();
void function_838() {
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
void function_839() {
  increment_count(env);
  val = new_function((&function_838), env);
  pop_function();
}
/* fn_175 */
void body_401() {
  increment_count(env);
  val = new_function((&function_839), env);
  global_c102c110c95c49c55c53 = val; /* fn_175 */
  return_location = (&body_402);
}
void body_403();
void function_840() {
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
void function_841() {
  increment_count(env);
  val = new_function((&function_840), env);
  pop_function();
}
/* fn_176 */
void body_402() {
  increment_count(env);
  val = new_function((&function_841), env);
  global_c102c110c95c49c55c54 = val; /* fn_176 */
  return_location = (&body_403);
}
void body_404();
void function_842() {
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
void function_843() {
  increment_count(env);
  val = new_function((&function_842), env);
  pop_function();
}
/* fn_177 */
void body_403() {
  increment_count(env);
  val = new_function((&function_843), env);
  global_c102c110c95c49c55c55 = val; /* fn_177 */
  return_location = (&body_404);
}
void body_405();
pointer global_c102c110c95c49c55c56 = NIL; /* fn_178 */
void function_844() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c55c56); /* fn_178 */
  top_level_apply();
}
void function_845() {
  increment_count(env);
  val = new_function((&function_844), env);
  pop_function();
}
/* fn_179 */
void body_404() {
  increment_count(env);
  val = new_function((&function_845), env);
  global_c102c110c95c49c55c57 = val; /* fn_179 */
  return_location = (&body_405);
}
void body_406();
void function_846() {
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
void function_847() {
  increment_count(env);
  val = new_function((&function_846), env);
  pop_function();
}
/* fn_178 */
void body_405() {
  increment_count(env);
  val = new_function((&function_847), env);
  global_c102c110c95c49c55c56 = val; /* fn_178 */
  return_location = (&body_406);
}
void body_407();
void function_848() {
  increment_count(val = global_c95c105c100); /* _id */
  pop_function();
}
void function_849() {
  increment_count(env);
  val = new_function((&function_848), env);
  pop_function();
}
/* fn_180 */
void body_406() {
  increment_count(env);
  val = new_function((&function_849), env);
  global_c102c110c95c49c56c48 = val; /* fn_180 */
  return_location = (&body_407);
}
void body_408();
pointer global_c95c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
void function_850() {
  global_c95c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* ____build-num-str */
  return_location = (&body_408);
}
/* ____build-num-str */
void body_407() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c49); /* fn_181 */
  apply((&function_850));
}
void body_409();
pointer global_c95c95c95c108c95c49c49c52;
/* ___l_114 */
void body_408() {
  val = NIL;
  global_c95c95c95c108c95c49c49c52 = val; /* ___l_114 */
  return_location = (&body_409);
}
void body_410();
pointer global_c95c95c95c108c95c49c49c53;
/* ___l_115 */
void body_409() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c49c53 = val; /* ___l_115 */
  return_location = (&body_410);
}
void body_411();
pointer global_c95c95c95c108c95c49c49c54;
/* ___l_116 */
void body_410() {
  val = NIL;
  global_c95c95c95c108c95c49c49c54 = val; /* ___l_116 */
  return_location = (&body_411);
}
void body_412();
pointer global_c102c110c95c49c56c50;
void function_851() {
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
void function_852() {
  apply((&function_851));
}
void function_853() {
  top_level_apply();
}
void function_854() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c49c53); /* ___l_115 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c49c54); /* ___l_116 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* ____build-num-str */
    apply((&function_853));
  }
}
void function_855() {
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
    increment_count(val = global_c95c95c95c108c95c49c49c52); /* ___l_114 */
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
    increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* ____build-num-str */
    apply((&function_852));
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_854));
  }
}
void function_856() {
  increment_count(env);
  val = new_function((&function_855), env);
  pop_function();
}
/* fn_182 */
void body_411() {
  increment_count(env);
  val = new_function((&function_856), env);
  global_c102c110c95c49c56c50 = val; /* fn_182 */
  return_location = (&body_412);
}
void body_413();
void function_857() {
  global_c95c95c95c95c112c114c105c110c116c45c110c117c109 = val; /* ____print-num */
  return_location = (&body_413);
}
/* ____print-num */
void body_412() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c50); /* fn_182 */
  apply((&function_857));
}
void body_414();
pointer global_c95c95c95c108c95c49c49c55;
/* ___l_117 */
void body_413() {
  val = -36;
  global_c95c95c95c108c95c49c49c55 = val; /* ___l_117 */
  return_location = (&body_414);
}
void body_415();
pointer global_c95c95c95c108c95c49c49c56;
/* ___l_118 */
void body_414() {
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
  global_c95c95c95c108c95c49c49c56 = val; /* ___l_118 */
  return_location = (&body_415);
}
void body_416();
pointer global_c95c95c95c108c95c49c49c57;
/* ___l_119 */
void body_415() {
  val = -35;
  global_c95c95c95c108c95c49c49c57 = val; /* ___l_119 */
  return_location = (&body_416);
}
void body_417();
pointer global_c95c95c95c108c95c49c50c48;
/* ___l_120 */
void body_416() {
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
  global_c95c95c95c108c95c49c50c48 = val; /* ___l_120 */
  return_location = (&body_417);
}
void body_418();
pointer global_c95c95c95c108c95c49c50c49;
/* ___l_121 */
void body_417() {
  val = -42;
  global_c95c95c95c108c95c49c50c49 = val; /* ___l_121 */
  return_location = (&body_418);
}
void body_419();
pointer global_c95c95c95c108c95c49c50c50;
/* ___l_122 */
void body_418() {
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
  global_c95c95c95c108c95c49c50c50 = val; /* ___l_122 */
  return_location = (&body_419);
}
void body_420();
pointer global_c95c95c95c108c95c49c50c51;
/* ___l_123 */
void body_419() {
  val = -41;
  global_c95c95c95c108c95c49c50c51 = val; /* ___l_123 */
  return_location = (&body_420);
}
void body_421();
pointer global_c95c95c95c108c95c49c50c52;
/* ___l_124 */
void body_420() {
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
  global_c95c95c95c108c95c49c50c52 = val; /* ___l_124 */
  return_location = (&body_421);
}
void body_422();
pointer global_c95c95c95c108c95c49c50c53;
/* ___l_125 */
void body_421() {
  val = CAR;
  global_c95c95c95c108c95c49c50c53 = val; /* ___l_125 */
  return_location = (&body_422);
}
void body_423();
pointer global_c95c95c95c108c95c49c50c54;
/* ___l_126 */
void body_422() {
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
  global_c95c95c95c108c95c49c50c54 = val; /* ___l_126 */
  return_location = (&body_423);
}
void body_424();
pointer global_c95c95c95c108c95c49c50c55;
/* ___l_127 */
void body_423() {
  val = CDR;
  global_c95c95c95c108c95c49c50c55 = val; /* ___l_127 */
  return_location = (&body_424);
}
void body_425();
pointer global_c95c95c95c108c95c49c50c56;
/* ___l_128 */
void body_424() {
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
  global_c95c95c95c108c95c49c50c56 = val; /* ___l_128 */
  return_location = (&body_425);
}
void body_426();
pointer global_c95c95c95c108c95c49c50c57;
/* ___l_129 */
void body_425() {
  val = NUMBER;
  global_c95c95c95c108c95c49c50c57 = val; /* ___l_129 */
  return_location = (&body_426);
}
void body_427();
pointer global_c95c95c95c108c95c49c51c48;
/* ___l_130 */
void body_426() {
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
  global_c95c95c95c108c95c49c51c48 = val; /* ___l_130 */
  return_location = (&body_427);
}
void body_428();
pointer global_c95c95c95c108c95c49c51c49;
/* ___l_131 */
void body_427() {
  val = FUNCTION;
  global_c95c95c95c108c95c49c51c49 = val; /* ___l_131 */
  return_location = (&body_428);
}
void body_429();
pointer global_c95c95c95c108c95c49c51c50;
/* ___l_132 */
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
  global_c95c95c95c108c95c49c51c50 = val; /* ___l_132 */
  return_location = (&body_429);
}
void body_430();
pointer global_c95c95c95c108c95c49c51c51;
/* ___l_133 */
void body_429() {
  val = ATOM;
  global_c95c95c95c108c95c49c51c51 = val; /* ___l_133 */
  return_location = (&body_430);
}
void body_431();
pointer global_c95c95c95c108c95c49c51c52;
/* ___l_134 */
void body_430() {
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
  global_c95c95c95c108c95c49c51c52 = val; /* ___l_134 */
  return_location = (&body_431);
}
void body_432();
pointer global_c95c95c95c108c95c49c51c53;
/* ___l_135 */
void body_431() {
  val = CONS;
  global_c95c95c95c108c95c49c51c53 = val; /* ___l_135 */
  return_location = (&body_432);
}
void body_433();
pointer global_c95c95c95c108c95c49c51c54;
/* ___l_136 */
void body_432() {
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
  global_c95c95c95c108c95c49c51c54 = val; /* ___l_136 */
  return_location = (&body_433);
}
void body_434();
pointer global_c95c95c95c108c95c49c51c55;
/* ___l_137 */
void body_433() {
  val = -40;
  global_c95c95c95c108c95c49c51c55 = val; /* ___l_137 */
  return_location = (&body_434);
}
void body_435();
pointer global_c95c95c95c108c95c49c51c56;
/* ___l_138 */
void body_434() {
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
  global_c95c95c95c108c95c49c51c56 = val; /* ___l_138 */
  return_location = (&body_435);
}
void body_436();
pointer global_c95c95c95c108c95c49c51c57;
/* ___l_139 */
void body_435() {
  val = -39;
  global_c95c95c95c108c95c49c51c57 = val; /* ___l_139 */
  return_location = (&body_436);
}
void body_437();
pointer global_c95c95c95c108c95c49c52c48;
/* ___l_140 */
void body_436() {
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
  global_c95c95c95c108c95c49c52c48 = val; /* ___l_140 */
  return_location = (&body_437);
}
void body_438();
pointer global_c95c95c95c108c95c49c52c49;
/* ___l_141 */
void body_437() {
  val = -38;
  global_c95c95c95c108c95c49c52c49 = val; /* ___l_141 */
  return_location = (&body_438);
}
void body_439();
pointer global_c95c95c95c108c95c49c52c50;
/* ___l_142 */
void body_438() {
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
  global_c95c95c95c108c95c49c52c50 = val; /* ___l_142 */
  return_location = (&body_439);
}
void body_440();
pointer global_c95c95c95c108c95c49c52c51;
/* ___l_143 */
void body_439() {
  val = -37;
  global_c95c95c95c108c95c49c52c51 = val; /* ___l_143 */
  return_location = (&body_440);
}
void body_441();
pointer global_c95c95c95c108c95c49c52c52;
/* ___l_144 */
void body_440() {
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
  global_c95c95c95c108c95c49c52c52 = val; /* ___l_144 */
  return_location = (&body_441);
}
void body_442();
pointer global_c95c95c95c108c95c49c52c53;
/* ___l_145 */
void body_441() {
  val = URSHIFT;
  global_c95c95c95c108c95c49c52c53 = val; /* ___l_145 */
  return_location = (&body_442);
}
void body_443();
pointer global_c95c95c95c108c95c49c52c54;
/* ___l_146 */
void body_442() {
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
  global_c95c95c95c108c95c49c52c54 = val; /* ___l_146 */
  return_location = (&body_443);
}
void body_444();
pointer global_c95c95c95c108c95c49c52c55;
/* ___l_147 */
void body_443() {
  val = SRSHIFT;
  global_c95c95c95c108c95c49c52c55 = val; /* ___l_147 */
  return_location = (&body_444);
}
void body_445();
pointer global_c95c95c95c108c95c49c52c56;
/* ___l_148 */
void body_444() {
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
  global_c95c95c95c108c95c49c52c56 = val; /* ___l_148 */
  return_location = (&body_445);
}
void body_446();
pointer global_c95c95c95c108c95c49c52c57;
/* ___l_149 */
void body_445() {
  val = LSHIFT;
  global_c95c95c95c108c95c49c52c57 = val; /* ___l_149 */
  return_location = (&body_446);
}
void body_447();
pointer global_c95c95c95c108c95c49c53c48;
/* ___l_150 */
void body_446() {
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
  global_c95c95c95c108c95c49c53c48 = val; /* ___l_150 */
  return_location = (&body_447);
}
void body_448();
pointer global_c95c95c95c108c95c49c53c49;
/* ___l_151 */
void body_447() {
  val = LT;
  global_c95c95c95c108c95c49c53c49 = val; /* ___l_151 */
  return_location = (&body_448);
}
void body_449();
pointer global_c95c95c95c108c95c49c53c50;
/* ___l_152 */
void body_448() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53c50 = val; /* ___l_152 */
  return_location = (&body_449);
}
void body_450();
pointer global_c95c95c95c108c95c49c53c51;
/* ___l_153 */
void body_449() {
  val = GT;
  global_c95c95c95c108c95c49c53c51 = val; /* ___l_153 */
  return_location = (&body_450);
}
void body_451();
pointer global_c95c95c95c108c95c49c53c52;
/* ___l_154 */
void body_450() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53c52 = val; /* ___l_154 */
  return_location = (&body_451);
}
void body_452();
pointer global_c95c95c95c108c95c49c53c53;
/* ___l_155 */
void body_451() {
  val = EQ;
  global_c95c95c95c108c95c49c53c53 = val; /* ___l_155 */
  return_location = (&body_452);
}
void body_453();
pointer global_c95c95c95c108c95c49c53c54;
/* ___l_156 */
void body_452() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53c54 = val; /* ___l_156 */
  return_location = (&body_453);
}
void body_454();
pointer global_c95c95c95c108c95c49c53c55;
/* ___l_157 */
void body_453() {
  val = PLUS;
  global_c95c95c95c108c95c49c53c55 = val; /* ___l_157 */
  return_location = (&body_454);
}
void body_455();
pointer global_c95c95c95c108c95c49c53c56;
/* ___l_158 */
void body_454() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53c56 = val; /* ___l_158 */
  return_location = (&body_455);
}
void body_456();
pointer global_c95c95c95c108c95c49c53c57;
/* ___l_159 */
void body_455() {
  val = MINUS;
  global_c95c95c95c108c95c49c53c57 = val; /* ___l_159 */
  return_location = (&body_456);
}
void body_457();
pointer global_c95c95c95c108c95c49c54c48;
/* ___l_160 */
void body_456() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54c48 = val; /* ___l_160 */
  return_location = (&body_457);
}
void body_458();
pointer global_c95c95c95c108c95c49c54c49;
/* ___l_161 */
void body_457() {
  val = MULT;
  global_c95c95c95c108c95c49c54c49 = val; /* ___l_161 */
  return_location = (&body_458);
}
void body_459();
pointer global_c95c95c95c108c95c49c54c50;
/* ___l_162 */
void body_458() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54c50 = val; /* ___l_162 */
  return_location = (&body_459);
}
void body_460();
pointer global_c95c95c95c108c95c49c54c51;
/* ___l_163 */
void body_459() {
  val = DIV;
  global_c95c95c95c108c95c49c54c51 = val; /* ___l_163 */
  return_location = (&body_460);
}
void body_461();
pointer global_c95c95c95c108c95c49c54c52;
/* ___l_164 */
void body_460() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54c52 = val; /* ___l_164 */
  return_location = (&body_461);
}
void body_462();
pointer global_c95c95c95c108c95c49c54c53;
/* ___l_165 */
void body_461() {
  val = MOD;
  global_c95c95c95c108c95c49c54c53 = val; /* ___l_165 */
  return_location = (&body_462);
}
void body_463();
pointer global_c95c95c95c108c95c49c54c54;
/* ___l_166 */
void body_462() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54c54 = val; /* ___l_166 */
  return_location = (&body_463);
}
void body_464();
pointer global_c95c95c95c108c95c49c54c55;
/* ___l_167 */
void body_463() {
  val = BAND;
  global_c95c95c95c108c95c49c54c55 = val; /* ___l_167 */
  return_location = (&body_464);
}
void body_465();
pointer global_c95c95c95c108c95c49c54c56;
/* ___l_168 */
void body_464() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54c56 = val; /* ___l_168 */
  return_location = (&body_465);
}
void body_466();
pointer global_c95c95c95c108c95c49c54c57;
/* ___l_169 */
void body_465() {
  val = BOR;
  global_c95c95c95c108c95c49c54c57 = val; /* ___l_169 */
  return_location = (&body_466);
}
void body_467();
pointer global_c95c95c95c108c95c49c55c48;
/* ___l_170 */
void body_466() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55c48 = val; /* ___l_170 */
  return_location = (&body_467);
}
void body_468();
pointer global_c95c95c95c108c95c49c55c49;
/* ___l_171 */
void body_467() {
  val = BXOR;
  global_c95c95c95c108c95c49c55c49 = val; /* ___l_171 */
  return_location = (&body_468);
}
void body_469();
pointer global_c95c95c95c108c95c49c55c50;
/* ___l_172 */
void body_468() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55c50 = val; /* ___l_172 */
  return_location = (&body_469);
}
void body_470();
pointer global_c95c95c95c108c95c49c55c51;
/* ___l_173 */
void body_469() {
  val = BNEG;
  global_c95c95c95c108c95c49c55c51 = val; /* ___l_173 */
  return_location = (&body_470);
}
void body_471();
pointer global_c95c95c95c108c95c49c55c52;
/* ___l_174 */
void body_470() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55c52 = val; /* ___l_174 */
  return_location = (&body_471);
}
void body_472();
pointer global_c95c95c95c108c95c49c55c53;
/* ___l_175 */
void body_471() {
  val = -34;
  global_c95c95c95c108c95c49c55c53 = val; /* ___l_175 */
  return_location = (&body_472);
}
void body_473();
pointer global_c95c95c95c108c95c49c55c54;
/* ___l_176 */
void body_472() {
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
  global_c95c95c95c108c95c49c55c54 = val; /* ___l_176 */
  return_location = (&body_473);
}
void body_474();
pointer global_c95c95c95c108c95c49c55c55;
/* ___l_177 */
void body_473() {
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
  global_c95c95c95c108c95c49c55c55 = val; /* ___l_177 */
  return_location = (&body_474);
}
void body_475();
pointer global_c102c110c95c49c56c51;
void function_858() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c55c54); /* ___l_176 */
    pop_function();
  } else {
    increment_count(val = global_c95c95c95c108c95c49c55c55); /* ___l_177 */
    pop_function();
  }
}
void function_859() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c55c52); /* ___l_174 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c55c53); /* ___l_175 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_858));
  }
}
void function_860() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c55c50); /* ___l_172 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c55c51); /* ___l_173 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_859));
  }
}
void function_861() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c55c48); /* ___l_170 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c55c49); /* ___l_171 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_860));
  }
}
void function_862() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c54c56); /* ___l_168 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c54c57); /* ___l_169 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_861));
  }
}
void function_863() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c54c54); /* ___l_166 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c54c55); /* ___l_167 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_862));
  }
}
void function_864() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c54c52); /* ___l_164 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c54c53); /* ___l_165 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_863));
  }
}
void function_865() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c54c50); /* ___l_162 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c54c51); /* ___l_163 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_864));
  }
}
void function_866() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c54c48); /* ___l_160 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c54c49); /* ___l_161 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_865));
  }
}
void function_867() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53c56); /* ___l_158 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c53c57); /* ___l_159 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_866));
  }
}
void function_868() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53c54); /* ___l_156 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c53c55); /* ___l_157 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_867));
  }
}
void function_869() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53c52); /* ___l_154 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c53c53); /* ___l_155 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_868));
  }
}
void function_870() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53c50); /* ___l_152 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c53c51); /* ___l_153 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_869));
  }
}
void function_871() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c53c48); /* ___l_150 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c53c49); /* ___l_151 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_870));
  }
}
void function_872() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c52c56); /* ___l_148 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c52c57); /* ___l_149 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_871));
  }
}
void function_873() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c52c54); /* ___l_146 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c52c55); /* ___l_147 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_872));
  }
}
void function_874() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c52c52); /* ___l_144 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c52c53); /* ___l_145 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_873));
  }
}
void function_875() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c52c50); /* ___l_142 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c52c51); /* ___l_143 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_874));
  }
}
void function_876() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c52c48); /* ___l_140 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c52c49); /* ___l_141 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_875));
  }
}
void function_877() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51c56); /* ___l_138 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c51c57); /* ___l_139 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_876));
  }
}
void function_878() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51c54); /* ___l_136 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c51c55); /* ___l_137 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_877));
  }
}
void function_879() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51c52); /* ___l_134 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c51c53); /* ___l_135 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_878));
  }
}
void function_880() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51c50); /* ___l_132 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c51c51); /* ___l_133 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_879));
  }
}
void function_881() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c51c48); /* ___l_130 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c51c49); /* ___l_131 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_880));
  }
}
void function_882() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c50c56); /* ___l_128 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c50c57); /* ___l_129 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_881));
  }
}
void function_883() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c50c54); /* ___l_126 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c50c55); /* ___l_127 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_882));
  }
}
void function_884() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c50c52); /* ___l_124 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c50c53); /* ___l_125 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_883));
  }
}
void function_885() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c50c50); /* ___l_122 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c50c51); /* ___l_123 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_884));
  }
}
void function_886() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c50c48); /* ___l_120 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c50c49); /* ___l_121 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_885));
  }
}
void function_887() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c49c49c56); /* ___l_118 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c49c57); /* ___l_119 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_886));
  }
}
void function_888() {
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
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c110c117c109); /* ____print-num */
    top_level_apply();
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
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_c95c95c95c108c95c49c49c55); /* ___l_117 */
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61); /* __= */
      apply((&function_887));
    }
  }
}
void function_889() {
  increment_count(env);
  val = new_function((&function_888), env);
  pop_function();
}
/* fn_183 */
void body_474() {
  increment_count(env);
  val = new_function((&function_889), env);
  global_c102c110c95c49c56c51 = val; /* fn_183 */
  return_location = (&body_475);
}
void body_476();
void function_890() {
  global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109 = val; /* ____print-atom */
  return_location = (&body_476);
}
/* ____print-atom */
void body_475() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c51); /* fn_183 */
  apply((&function_890));
}
void body_477();
pointer global_c95c95c95c108c95c49c55c56;
/* ___l_178 */
void body_476() {
  val = NIL;
  global_c95c95c95c108c95c49c55c56 = val; /* ___l_178 */
  return_location = (&body_477);
}
void body_478();
pointer global_c95c95c95c108c95c49c55c57;
/* ___l_179 */
void body_477() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55c57 = val; /* ___l_179 */
  return_location = (&body_478);
}
void body_479();
pointer global_c95c95c95c108c95c49c56c48;
/* ___l_180 */
void body_478() {
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
  global_c95c95c95c108c95c49c56c48 = val; /* ___l_180 */
  return_location = (&body_479);
}
void body_480();
pointer global_c95c95c95c108c95c49c56c49;
/* ___l_181 */
void body_479() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56c49 = val; /* ___l_181 */
  return_location = (&body_480);
}
void body_481();
pointer global_c95c95c95c108c95c49c56c50;
/* ___l_182 */
void body_480() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56c50 = val; /* ___l_182 */
  return_location = (&body_481);
}
void body_482();
pointer global_c95c95c95c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* ____print-tail */
pointer global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* ____print-with-suffix */
pointer global_c102c110c95c49c56c52;
void function_891() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c56c48); /* ___l_180 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_892() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c56c50); /* ___l_182 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_893() {
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
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ____print-with-suffix */
  apply((&function_892));
}
void function_894() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56c49); /* ___l_181 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ____print-atom */
    apply((&function_891));
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
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c116c97c105c108); /* ____print-tail */
    apply((&function_893));
  }
}
void function_895() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c55c57); /* ___l_179 */
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
    apply((&function_894));
  }
}
void function_896() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55c56); /* ___l_178 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_895));
}
void function_897() {
  increment_count(env);
  val = new_function((&function_896), env);
  pop_function();
}
/* fn_184 */
void body_481() {
  increment_count(env);
  val = new_function((&function_897), env);
  global_c102c110c95c49c56c52 = val; /* fn_184 */
  return_location = (&body_482);
}
void body_483();
void function_898() {
  global_c95c95c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* ____print-tail */
  return_location = (&body_483);
}
/* ____print-tail */
void body_482() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c52); /* fn_184 */
  apply((&function_898));
}
void body_484();
pointer global_c95c95c95c108c95c49c56c51;
/* ___l_183 */
void body_483() {
  val = NIL;
  global_c95c95c95c108c95c49c56c51 = val; /* ___l_183 */
  return_location = (&body_484);
}
void body_485();
pointer global_c95c95c95c108c95c49c56c52;
/* ___l_184 */
void body_484() {
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
  global_c95c95c95c108c95c49c56c52 = val; /* ___l_184 */
  return_location = (&body_485);
}
void body_486();
pointer global_c95c95c95c108c95c49c56c53;
/* ___l_185 */
void body_485() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56c53 = val; /* ___l_185 */
  return_location = (&body_486);
}
void body_487();
pointer global_c102c110c95c49c56c53;
void function_899() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_900() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c56c53); /* ___l_185 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_901() {
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
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ____print-with-suffix */
  apply((&function_900));
}
void function_902() {
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
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c97c116c111c109); /* ____print-atom */
    apply((&function_899));
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
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c116c97c105c108); /* ____print-tail */
    apply((&function_901));
  }
}
void function_903() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56c52); /* ___l_184 */
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
    apply((&function_902));
  }
}
void function_904() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56c51); /* ___l_183 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_903));
}
void function_905() {
  increment_count(env);
  val = new_function((&function_904), env);
  pop_function();
}
/* fn_185 */
void body_486() {
  increment_count(env);
  val = new_function((&function_905), env);
  global_c102c110c95c49c56c53 = val; /* fn_185 */
  return_location = (&body_487);
}
void body_488();
void function_906() {
  global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* ____print-with-suffix */
  return_location = (&body_488);
}
/* ____print-with-suffix */
void body_487() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c53); /* fn_185 */
  apply((&function_906));
}
void body_489();
pointer global_c95c95c95c108c95c49c56c54;
/* ___l_186 */
void body_488() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56c54 = val; /* ___l_186 */
  return_location = (&body_489);
}
void body_490();
pointer global_c102c110c95c49c56c54;
void function_907() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56c54); /* ___l_186 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ____print-with-suffix */
  top_level_apply();
}
void function_908() {
  increment_count(env);
  val = new_function((&function_907), env);
  pop_function();
}
/* fn_186 */
void body_489() {
  increment_count(env);
  val = new_function((&function_908), env);
  global_c102c110c95c49c56c54 = val; /* fn_186 */
  return_location = (&body_490);
}
void body_491();
pointer global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
void function_909() {
  global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* ____print-with-newline */
  return_location = (&body_491);
}
/* ____print-with-newline */
void body_490() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c54); /* fn_186 */
  apply((&function_909));
}
void body_492();
pointer global_c95c95c95c108c95c49c56c55;
/* ___l_187 */
void body_491() {
  val = NIL;
  global_c95c95c95c108c95c49c56c55 = val; /* ___l_187 */
  return_location = (&body_492);
}
void body_493();
pointer global_c102c110c95c49c56c55;
void function_910() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56c55); /* ___l_187 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* ____print-with-suffix */
  top_level_apply();
}
void function_911() {
  increment_count(env);
  val = new_function((&function_910), env);
  pop_function();
}
/* fn_187 */
void body_492() {
  increment_count(env);
  val = new_function((&function_911), env);
  global_c102c110c95c49c56c55 = val; /* fn_187 */
  return_location = (&body_493);
}
void body_494();
pointer global_c95c112c114c105c110c116;
void function_912() {
  global_c95c112c114c105c110c116 = val; /* _print */
  return_location = (&body_494);
}
/* _print */
void body_493() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c55); /* fn_187 */
  apply((&function_912));
}
void body_495();
pointer global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 = NIL; /* ____escape-args */
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ____escape-symbols */
pointer global_c102c110c95c49c56c56;
void function_913() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_914() {
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  apply((&function_913));
}
void function_915() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115); /* ____escape-args */
    apply((&function_914));
  }
}
void function_916() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_915));
}
void function_917() {
  increment_count(env);
  val = new_function((&function_916), env);
  pop_function();
}
/* fn_188 */
void body_494() {
  increment_count(env);
  val = new_function((&function_917), env);
  global_c102c110c95c49c56c56 = val; /* fn_188 */
  return_location = (&body_495);
}
void body_496();
void function_918() {
  global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 = val; /* ____escape-args */
  return_location = (&body_496);
}
/* ____escape-args */
void body_495() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56c56); /* fn_188 */
  apply((&function_918));
}
void body_497();
pointer global_c95c95c95c108c95c49c56c56;
/* ___l_188 */
void body_496() {
  val = ATOM;
  global_c95c95c95c108c95c49c56c56 = val; /* ___l_188 */
  return_location = (&body_497);
}
void body_498();
pointer global_c95c95c95c108c95c49c56c57;
/* ___l_189 */
void body_497() {
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
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56c57 = val; /* ___l_189 */
  return_location = (&body_498);
}
void body_499();
pointer global_c95c95c95c108c95c49c57c48;
/* ___l_190 */
void body_498() {
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
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57c48 = val; /* ___l_190 */
  return_location = (&body_499);
}
void body_500();
pointer global_c95c95c95c108c95c49c57c49;
/* ___l_191 */
void body_499() {
  val = EQ;
  global_c95c95c95c108c95c49c57c49 = val; /* ___l_191 */
  return_location = (&body_500);
}
void body_501();
pointer global_c95c95c95c108c95c49c57c50;
/* ___l_192 */
void body_500() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57c50 = val; /* ___l_192 */
  return_location = (&body_501);
}
void body_502();
pointer global_c95c95c95c108c95c49c57c51;
/* ___l_193 */
void body_501() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57c51 = val; /* ___l_193 */
  return_location = (&body_502);
}
void body_503();
pointer global_c95c95c95c108c95c49c57c52;
/* ___l_194 */
void body_502() {
  val = -36;
  global_c95c95c95c108c95c49c57c52 = val; /* ___l_194 */
  return_location = (&body_503);
}
void body_504();
pointer global_c95c95c95c108c95c49c57c53;
/* ___l_195 */
void body_503() {
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
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57c53 = val; /* ___l_195 */
  return_location = (&body_504);
}
void body_505();
pointer global_c95c95c95c108c95c49c57c54;
/* ___l_196 */
void body_504() {
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
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57c54 = val; /* ___l_196 */
  return_location = (&body_505);
}
void body_506();
pointer global_c95c95c95c108c95c49c57c55;
/* ___l_197 */
void body_505() {
  val = -35;
  global_c95c95c95c108c95c49c57c55 = val; /* ___l_197 */
  return_location = (&body_506);
}
void body_507();
pointer global_c102c110c95c49c56c57 = NIL; /* fn_189 */
pointer global_c102c110c95c49c57c48;
void function_919() {
  top_level_apply();
}
void function_920() {
  args = cons(val, args);
  val = new_number(95);
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
  increment_count(val = global_c102c110c95c49c56c57); /* fn_189 */
  apply((&function_919));
}
void function_921() {
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
    apply((&function_920));
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_922() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_921));
}
void function_923() {
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115); /* ____escape-args */
    top_level_apply();
  }
}
void function_924() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c55); /* ___l_197 */
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
    apply((&function_923));
  }
}
void function_925() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c54); /* ___l_196 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c57c53); /* ___l_195 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108); /* ____make-symbol */
    top_level_apply();
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
      push_args();
      val = NIL;
      args = val;
      val = new_number(95);
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
      apply((&function_922));
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c97c116c111c109); /* __atom */
      apply((&function_924));
    }
  }
}
void function_926() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c51); /* ___l_193 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c57c50); /* ___l_192 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108); /* ____make-symbol */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c52); /* ___l_194 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_925));
  }
}
void function_927() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c48); /* ___l_190 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56c57); /* ___l_189 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108); /* ____make-symbol */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c49); /* ___l_191 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_926));
  }
}
void function_928() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56c56); /* ___l_188 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_927));
}
void function_929() {
  increment_count(env);
  val = new_function((&function_928), env);
  pop_function();
}
/* fn_190 */
void body_506() {
  increment_count(env);
  val = new_function((&function_929), env);
  global_c102c110c95c49c57c48 = val; /* fn_190 */
  return_location = (&body_507);
}
void body_508();
void function_930() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c107c101c45c115c121c109c98c111c108); /* ____make-symbol */
  top_level_apply();
}
void function_931() {
  increment_count(env);
  val = new_function((&function_930), env);
  pop_function();
}
/* fn_189 */
void body_507() {
  increment_count(env);
  val = new_function((&function_931), env);
  global_c102c110c95c49c56c57 = val; /* fn_189 */
  return_location = (&body_508);
}
void body_509();
void function_932() {
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  return_location = (&body_509);
}
/* ____escape-symbols */
void body_508() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c48); /* fn_190 */
  apply((&function_932));
}
void body_510();
pointer global_c95c95c95c108c95c49c57c56;
/* ___l_198 */
void body_509() {
  val = NIL;
  global_c95c95c95c108c95c49c57c56 = val; /* ___l_198 */
  return_location = (&body_510);
}
void body_511();
pointer global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 = NIL; /* ____list-symbols */
pointer global_c102c110c95c49c57c49;
void function_933() {
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
void function_934() {
  apply((&function_933));
}
void function_935() {
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
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
  top_level_apply();
}
void function_936() {
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
    increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c101c113); /* ____symbol-eq */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c111c110c116c97c105c110c115); /* ____contains */
    apply((&function_934));
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
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
    apply((&function_935));
  }
}
void function_937() {
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
    if (length(args) == 1) {
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
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
      apply((&function_936));
    }
  }
}
void function_938() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c57c56); /* ___l_198 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_937));
}
void function_939() {
  increment_count(env);
  val = new_function((&function_938), env);
  pop_function();
}
/* fn_191 */
void body_510() {
  increment_count(env);
  val = new_function((&function_939), env);
  global_c102c110c95c49c57c49 = val; /* fn_191 */
  return_location = (&body_511);
}
void body_512();
void function_940() {
  global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 = val; /* ____list-symbols */
  return_location = (&body_512);
}
/* ____list-symbols */
void body_511() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c49); /* fn_191 */
  apply((&function_940));
}
void body_513();
pointer global_c95c95c95c108c95c49c57c57;
/* ___l_199 */
void body_512() {
  val = -35;
  global_c95c95c95c108c95c49c57c57 = val; /* ___l_199 */
  return_location = (&body_513);
}
void body_514();
pointer global_c102c110c95c49c57c50 = NIL; /* fn_192 */
pointer global_c102c110c95c49c57c51;
void function_941() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
  top_level_apply();
}
void function_942() {
  top_level_apply();
}
void function_943() {
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  apply((&function_942));
}
void function_944() {
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
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    apply((&function_941));
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c102c110c95c49c57c50); /* fn_192 */
    apply((&function_943));
  }
}
void function_945() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c57c57); /* ___l_199 */
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
    apply((&function_944));
  }
}
void function_946() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_945));
}
void function_947() {
  increment_count(env);
  val = new_function((&function_946), env);
  pop_function();
}
/* fn_193 */
void body_513() {
  increment_count(env);
  val = new_function((&function_947), env);
  global_c102c110c95c49c57c51 = val; /* fn_193 */
  return_location = (&body_514);
}
void body_515();
pointer global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 = NIL; /* ____find-quoted-symbols */
void function_948() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115); /* ____find-quoted-symbols */
  top_level_apply();
}
void function_949() {
  increment_count(env);
  val = new_function((&function_948), env);
  pop_function();
}
/* fn_192 */
void body_514() {
  increment_count(env);
  val = new_function((&function_949), env);
  global_c102c110c95c49c57c50 = val; /* fn_192 */
  return_location = (&body_515);
}
void body_516();
void function_950() {
  global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 = val; /* ____find-quoted-symbols */
  return_location = (&body_516);
}
/* ____find-quoted-symbols */
void body_515() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c51); /* fn_193 */
  apply((&function_950));
}
void body_517();
pointer global_c95c95c95c108c95c50c48c48;
/* ___l_200 */
void body_516() {
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
  global_c95c95c95c108c95c50c48c48 = val; /* ___l_200 */
  return_location = (&body_517);
}
void body_518();
pointer global_c95c95c95c108c95c50c48c49;
/* ___l_201 */
void body_517() {
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
  global_c95c95c95c108c95c50c48c49 = val; /* ___l_201 */
  return_location = (&body_518);
}
void body_519();
pointer global_c95c95c95c108c95c50c48c50;
/* ___l_202 */
void body_518() {
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
  global_c95c95c95c108c95c50c48c50 = val; /* ___l_202 */
  return_location = (&body_519);
}
void body_520();
pointer global_c95c95c95c108c95c50c48c51;
/* ___l_203 */
void body_519() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c51 = val; /* ___l_203 */
  return_location = (&body_520);
}
void body_521();
pointer global_c95c95c95c108c95c50c48c52;
/* ___l_204 */
void body_520() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c52 = val; /* ___l_204 */
  return_location = (&body_521);
}
void body_522();
pointer global_c95c95c95c108c95c50c48c53;
/* ___l_205 */
void body_521() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c53 = val; /* ___l_205 */
  return_location = (&body_522);
}
void body_523();
pointer global_c95c95c95c108c95c50c48c54;
/* ___l_206 */
void body_522() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c54 = val; /* ___l_206 */
  return_location = (&body_523);
}
void body_524();
pointer global_c95c95c95c108c95c50c48c55;
/* ___l_207 */
void body_523() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c55 = val; /* ___l_207 */
  return_location = (&body_524);
}
void body_525();
pointer global_c95c95c95c108c95c50c48c56;
/* ___l_208 */
void body_524() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c56 = val; /* ___l_208 */
  return_location = (&body_525);
}
void body_526();
pointer global_c95c95c95c108c95c50c48c57;
/* ___l_209 */
void body_525() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48c57 = val; /* ___l_209 */
  return_location = (&body_526);
}
void body_527();
pointer global_c95c95c95c108c95c50c49c48;
/* ___l_210 */
void body_526() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c48 = val; /* ___l_210 */
  return_location = (&body_527);
}
void body_528();
pointer global_c95c95c95c108c95c50c49c49;
/* ___l_211 */
void body_527() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c49 = val; /* ___l_211 */
  return_location = (&body_528);
}
void body_529();
pointer global_c95c95c95c108c95c50c49c50;
/* ___l_212 */
void body_528() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c50 = val; /* ___l_212 */
  return_location = (&body_529);
}
void body_530();
pointer global_c95c95c95c108c95c50c49c51;
/* ___l_213 */
void body_529() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c51 = val; /* ___l_213 */
  return_location = (&body_530);
}
void body_531();
pointer global_c95c95c95c108c95c50c49c52;
/* ___l_214 */
void body_530() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
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
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c52 = val; /* ___l_214 */
  return_location = (&body_531);
}
void body_532();
pointer global_c95c95c95c108c95c50c49c53;
/* ___l_215 */
void body_531() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c53 = val; /* ___l_215 */
  return_location = (&body_532);
}
void body_533();
pointer global_c95c95c95c108c95c50c49c54;
/* ___l_216 */
void body_532() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c54 = val; /* ___l_216 */
  return_location = (&body_533);
}
void body_534();
pointer global_c95c95c95c108c95c50c49c55;
/* ___l_217 */
void body_533() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c55 = val; /* ___l_217 */
  return_location = (&body_534);
}
void body_535();
pointer global_c95c95c95c108c95c50c49c56;
/* ___l_218 */
void body_534() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c56 = val; /* ___l_218 */
  return_location = (&body_535);
}
void body_536();
pointer global_c95c95c95c108c95c50c49c57;
/* ___l_219 */
void body_535() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49c57 = val; /* ___l_219 */
  return_location = (&body_536);
}
void body_537();
pointer global_c95c95c95c108c95c50c50c48;
/* ___l_220 */
void body_536() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c48 = val; /* ___l_220 */
  return_location = (&body_537);
}
void body_538();
pointer global_c95c95c95c108c95c50c50c49;
/* ___l_221 */
void body_537() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c49 = val; /* ___l_221 */
  return_location = (&body_538);
}
void body_539();
pointer global_c95c95c95c108c95c50c50c50;
/* ___l_222 */
void body_538() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c50 = val; /* ___l_222 */
  return_location = (&body_539);
}
void body_540();
pointer global_c95c95c95c108c95c50c50c51;
/* ___l_223 */
void body_539() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c51 = val; /* ___l_223 */
  return_location = (&body_540);
}
void body_541();
pointer global_c95c95c95c108c95c50c50c52;
/* ___l_224 */
void body_540() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c52 = val; /* ___l_224 */
  return_location = (&body_541);
}
void body_542();
pointer global_c95c95c95c108c95c50c50c53;
/* ___l_225 */
void body_541() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c53 = val; /* ___l_225 */
  return_location = (&body_542);
}
void body_543();
pointer global_c95c95c95c108c95c50c50c54;
/* ___l_226 */
void body_542() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c54 = val; /* ___l_226 */
  return_location = (&body_543);
}
void body_544();
pointer global_c95c95c95c108c95c50c50c55;
/* ___l_227 */
void body_543() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c55 = val; /* ___l_227 */
  return_location = (&body_544);
}
void body_545();
pointer global_c95c95c95c108c95c50c50c56;
/* ___l_228 */
void body_544() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c56 = val; /* ___l_228 */
  return_location = (&body_545);
}
void body_546();
pointer global_c95c95c95c108c95c50c50c57;
/* ___l_229 */
void body_545() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50c57 = val; /* ___l_229 */
  return_location = (&body_546);
}
void body_547();
pointer global_c95c95c95c108c95c50c51c48;
/* ___l_230 */
void body_546() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c48 = val; /* ___l_230 */
  return_location = (&body_547);
}
void body_548();
pointer global_c95c95c95c108c95c50c51c49;
/* ___l_231 */
void body_547() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c49 = val; /* ___l_231 */
  return_location = (&body_548);
}
void body_549();
pointer global_c95c95c95c108c95c50c51c50;
/* ___l_232 */
void body_548() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c50 = val; /* ___l_232 */
  return_location = (&body_549);
}
void body_550();
pointer global_c95c95c95c108c95c50c51c51;
/* ___l_233 */
void body_549() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c51 = val; /* ___l_233 */
  return_location = (&body_550);
}
void body_551();
pointer global_c95c95c95c108c95c50c51c52;
/* ___l_234 */
void body_550() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c52 = val; /* ___l_234 */
  return_location = (&body_551);
}
void body_552();
pointer global_c95c95c95c108c95c50c51c53;
/* ___l_235 */
void body_551() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c53 = val; /* ___l_235 */
  return_location = (&body_552);
}
void body_553();
pointer global_c95c95c95c108c95c50c51c54;
/* ___l_236 */
void body_552() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c54 = val; /* ___l_236 */
  return_location = (&body_553);
}
void body_554();
pointer global_c95c95c95c108c95c50c51c55;
/* ___l_237 */
void body_553() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c55 = val; /* ___l_237 */
  return_location = (&body_554);
}
void body_555();
pointer global_c95c95c95c108c95c50c51c56;
/* ___l_238 */
void body_554() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51c56 = val; /* ___l_238 */
  return_location = (&body_555);
}
void body_556();
pointer global_c95c95c95c108c95c50c51c57;
/* ___l_239 */
void body_555() {
  val = NIL;
  global_c95c95c95c108c95c50c51c57 = val; /* ___l_239 */
  return_location = (&body_556);
}
void body_557();
pointer global_c95c95c95c108c95c50c52c48;
/* ___l_240 */
void body_556() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(103);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(116);
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
  global_c95c95c95c108c95c50c52c48 = val; /* ___l_240 */
  return_location = (&body_557);
}
void body_558();
pointer global_c102c110c95c49c57c53 = NIL; /* fn_195 */
pointer global_c102c110c95c49c57c54;
void function_951() {
  top_level_apply();
}
void function_952() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57c53); /* fn_195 */
  apply((&function_951));
}
void function_953() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_954() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_953));
}
void function_955() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_954));
}
void function_956() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52c48); /* ___l_240 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101); /* ____generate-unused-symbol-name */
    apply((&function_952));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
    apply((&function_955));
  }
}
void function_957() {
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  apply((&function_956));
}
void function_958() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c48); /* ___l_200 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63); /* ____symbol-present? */
  apply((&function_957));
}
void function_959() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c49); /* ___l_201 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63); /* ____symbol-present? */
  apply((&function_958));
}
void function_960() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c50); /* ___l_202 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c121c109c98c111c108c45c112c114c101c115c101c110c116c63); /* ____symbol-present? */
  apply((&function_959));
}
void function_961() {
  increment_count(env);
  val = new_function((&function_960), env);
  pop_function();
}
/* fn_196 */
void body_557() {
  increment_count(env);
  val = new_function((&function_961), env);
  global_c102c110c95c49c57c54 = val; /* fn_196 */
  return_location = (&body_558);
}
void body_559();
pointer global_c102c110c95c49c57c52 = NIL; /* fn_194 */
void function_962() {
  top_level_apply();
}
void function_963() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57c52); /* fn_194 */
  apply((&function_962));
}
void function_964() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c51c57); /* ___l_239 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115); /* ____find-quoted-symbols */
  apply((&function_963));
}
void function_965() {
  increment_count(env);
  val = new_function((&function_964), env);
  pop_function();
}
/* fn_195 */
void body_558() {
  increment_count(env);
  val = new_function((&function_965), env);
  global_c102c110c95c49c57c53 = val; /* fn_195 */
  return_location = (&body_559);
}
void body_560();
void function_966() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c49); /* ___l_211 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c48); /* ___l_210 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c57); /* ___l_209 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c56); /* ___l_208 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c55); /* ___l_207 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c54); /* ___l_206 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c53); /* ___l_205 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c52); /* ___l_204 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48c51); /* ___l_203 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  top_level_apply();
}
void function_967() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* ____build-symbol->string */
  apply((&function_966));
}
void function_968() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c56); /* ___l_238 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c55); /* ___l_237 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c54); /* ___l_236 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c53); /* ___l_235 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c52); /* ___l_234 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c51); /* ___l_233 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c50); /* ___l_232 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c49); /* ___l_231 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51c48); /* ___l_230 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c57); /* ___l_229 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c56); /* ___l_228 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c55); /* ___l_227 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c54); /* ___l_226 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c53); /* ___l_225 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c52); /* ___l_224 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c51); /* ___l_223 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c50); /* ___l_222 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c49); /* ___l_221 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50c48); /* ___l_220 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c57); /* ___l_219 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c56); /* ___l_218 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c55); /* ___l_217 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c54); /* ___l_216 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c53); /* ___l_215 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c52); /* ___l_214 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c51); /* ___l_213 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49c50); /* ___l_212 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* ____build-string->symbol */
  apply((&function_967));
}
void function_969() {
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  apply((&function_968));
}
void function_970() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_969));
}
void function_971() {
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  apply((&function_970));
}
void function_972() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  apply((&function_971));
}
void function_973() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  apply((&function_972));
}
void function_974() {
  increment_count(env);
  val = new_function((&function_973), env);
  pop_function();
}
/* fn_194 */
void body_559() {
  increment_count(env);
  val = new_function((&function_974), env);
  global_c102c110c95c49c57c52 = val; /* fn_194 */
  return_location = (&body_560);
}
void body_561();
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
void function_975() {
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  return_location = (&body_561);
}
/* ____compile */
void body_560() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c54); /* fn_196 */
  apply((&function_975));
}
void body_562();
pointer global_c95c95c95c108c95c50c52c49;
/* ___l_241 */
void body_561() {
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
  global_c95c95c95c108c95c50c52c49 = val; /* ___l_241 */
  return_location = (&body_562);
}
void body_563();
pointer global_c95c95c95c108c95c50c52c50;
/* ___l_242 */
void body_562() {
  val = -34;
  global_c95c95c95c108c95c50c52c50 = val; /* ___l_242 */
  return_location = (&body_563);
}
void body_564();
pointer global_c95c95c95c108c95c50c52c51;
/* ___l_243 */
void body_563() {
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
  global_c95c95c95c108c95c50c52c51 = val; /* ___l_243 */
  return_location = (&body_564);
}
void body_565();
pointer global_c102c110c95c49c57c55 = NIL; /* fn_197 */
pointer global_c102c110c95c49c57c56;
void function_976() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57c55); /* fn_197 */
  top_level_apply();
}
void function_977() {
  increment_count(env);
  val = new_function((&function_976), env);
  pop_function();
}
/* fn_198 */
void body_564() {
  increment_count(env);
  val = new_function((&function_977), env);
  global_c102c110c95c49c57c56 = val; /* fn_198 */
  return_location = (&body_565);
}
void body_566();
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ____compile-source */
void function_978() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101); /* ____compile */
  top_level_apply();
}
void function_979() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  top_level_apply();
}
void function_980() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52c51); /* ___l_243 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
    top_level_apply();
  } else {
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
    apply((&function_979));
  }
}
void function_981() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_980));
}
void function_982() {
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  apply((&function_981));
}
void function_983() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_982));
}
void function_984() {
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
  apply((&function_983));
}
void function_985() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_984));
}
void function_986() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c114c101c118c101c114c115c101); /* _reverse */
    apply((&function_978));
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
    apply((&function_985));
  }
}
void function_987() {
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_986));
}
void function_988() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52c49); /* ___l_241 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52c50); /* ___l_242 */
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
    apply((&function_987));
  }
}
void function_989() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  apply((&function_988));
}
void function_990() {
  increment_count(env);
  val = new_function((&function_989), env);
  pop_function();
}
/* fn_197 */
void body_565() {
  increment_count(env);
  val = new_function((&function_990), env);
  global_c102c110c95c49c57c55 = val; /* fn_197 */
  return_location = (&body_566);
}
void body_567();
void function_991() {
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  return_location = (&body_567);
}
/* ____compile-source */
void body_566() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c56); /* fn_198 */
  apply((&function_991));
}
void body_568();
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
void body_567() {
  val = NIL;
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  return_location = (&body_568);
}
void body_569();
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
void body_568() {
  val = NIL;
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  return_location = (&body_569);
}
void body_570();
pointer global_c102c110c95c49c57c57;
void function_992() {
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  top_level_apply();
}
void function_993() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  apply((&function_992));
}
void function_994() {
  increment_count(env);
  val = new_function((&function_993), env);
  pop_function();
}
/* fn_199 */
void body_569() {
  increment_count(env);
  val = new_function((&function_994), env);
  global_c102c110c95c49c57c57 = val; /* fn_199 */
  return_location = (&body_570);
}
void function_995() {
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
void body_570() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57c57); /* fn_199 */
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
    call_stack = cons(new_function((&function_995), NIL), call_stack);
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
  call_stack = cons(new_function((&function_995), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
