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
    apply((&function_10));
  }
}
void function_12() {
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
    apply((&function_12));
  }
}
void function_14() {
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
    apply((&function_13));
  }
}
void function_15() {
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
    apply((&function_14));
  }
}
void function_16() {
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
    apply((&function_15));
  }
}
void function_17() {
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
    apply((&function_16));
  }
}
void function_18() {
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
    apply((&function_17));
  }
}
void function_19() {
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
    apply((&function_18));
  }
}
void function_20() {
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
    apply((&function_19));
  }
}
void function_21() {
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
    apply((&function_20));
  }
}
void function_22() {
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
    apply((&function_21));
  }
}
void function_23() {
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
    apply((&function_22));
  }
}
void function_24() {
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
    apply((&function_23));
  }
}
void function_25() {
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
    apply((&function_24));
  }
}
void function_26() {
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
    apply((&function_25));
  }
}
void function_27() {
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
    apply((&function_26));
  }
}
void function_28() {
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
    apply((&function_27));
  }
}
void function_29() {
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
    apply((&function_28));
  }
}
void function_30() {
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
    apply((&function_29));
  }
}
void function_31() {
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
    apply((&function_30));
  }
}
void function_32() {
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
    apply((&function_31));
  }
}
void function_33() {
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
    apply((&function_32));
  }
}
void function_34() {
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
    apply((&function_33));
  }
}
void function_35() {
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
    val = new_number(116);
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
          val = -40;
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
            val = -40;
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
    val = -40;
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
      val = -40;
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
pointer global_c95c95c99c97c97c114;
void function_54() {
  global_c95c95c99c97c97c114 = val; /* __caar */
  return_location = (&body_14);
}
/* __caar */
void body_13() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  apply((&function_54));
}
void body_15();
pointer global_c102c110c95c55;
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
    increment_count(val = cdr(car(args)));
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
/* fn_7 */
void body_14() {
  increment_count(env);
  val = new_function((&function_56), env);
  global_c102c110c95c55 = val; /* fn_7 */
  return_location = (&body_15);
}
void body_16();
pointer global_c95c95c99c100c97c114;
void function_57() {
  global_c95c95c99c100c97c114 = val; /* __cdar */
  return_location = (&body_16);
}
/* __cdar */
void body_15() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  apply((&function_57));
}
void body_17();
pointer global_c102c110c95c56;
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
void function_59() {
  increment_count(env);
  val = new_function((&function_58), env);
  pop_function();
}
/* fn_8 */
void body_16() {
  increment_count(env);
  val = new_function((&function_59), env);
  global_c102c110c95c56 = val; /* fn_8 */
  return_location = (&body_17);
}
void body_18();
pointer global_c95c95c99c97c100c114;
void function_60() {
  global_c95c95c99c97c100c114 = val; /* __cadr */
  return_location = (&body_18);
}
/* __cadr */
void body_17() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  apply((&function_60));
}
void body_19();
pointer global_c102c110c95c57;
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
    increment_count(val = cdr(car(args)));
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
/* fn_9 */
void body_18() {
  increment_count(env);
  val = new_function((&function_62), env);
  global_c102c110c95c57 = val; /* fn_9 */
  return_location = (&body_19);
}
void body_20();
pointer global_c95c95c99c100c100c114;
void function_63() {
  global_c95c95c99c100c100c114 = val; /* __cddr */
  return_location = (&body_20);
}
/* __cddr */
void body_19() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  apply((&function_63));
}
void body_21();
pointer global_c102c110c95c49c48;
void function_64() {
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
void function_65() {
  increment_count(env);
  val = new_function((&function_64), env);
  pop_function();
}
/* fn_10 */
void body_20() {
  increment_count(env);
  val = new_function((&function_65), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  return_location = (&body_21);
}
void body_22();
pointer global_c95c95c99c97c97c97c114;
void function_66() {
  global_c95c95c99c97c97c97c114 = val; /* __caaar */
  return_location = (&body_22);
}
/* __caaar */
void body_21() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  apply((&function_66));
}
void body_23();
pointer global_c102c110c95c49c49;
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
void function_68() {
  increment_count(env);
  val = new_function((&function_67), env);
  pop_function();
}
/* fn_11 */
void body_22() {
  increment_count(env);
  val = new_function((&function_68), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  return_location = (&body_23);
}
void body_24();
pointer global_c95c95c99c97c97c100c114;
void function_69() {
  global_c95c95c99c97c97c100c114 = val; /* __caadr */
  return_location = (&body_24);
}
/* __caadr */
void body_23() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  apply((&function_69));
}
void body_25();
pointer global_c102c110c95c49c50;
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
void function_71() {
  increment_count(env);
  val = new_function((&function_70), env);
  pop_function();
}
/* fn_12 */
void body_24() {
  increment_count(env);
  val = new_function((&function_71), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  return_location = (&body_25);
}
void body_26();
pointer global_c95c95c99c97c100c97c114;
void function_72() {
  global_c95c95c99c97c100c97c114 = val; /* __cadar */
  return_location = (&body_26);
}
/* __cadar */
void body_25() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  apply((&function_72));
}
void body_27();
pointer global_c102c110c95c49c51;
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
void function_74() {
  increment_count(env);
  val = new_function((&function_73), env);
  pop_function();
}
/* fn_13 */
void body_26() {
  increment_count(env);
  val = new_function((&function_74), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  return_location = (&body_27);
}
void body_28();
pointer global_c95c95c99c97c100c100c114;
void function_75() {
  global_c95c95c99c97c100c100c114 = val; /* __caddr */
  return_location = (&body_28);
}
/* __caddr */
void body_27() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  apply((&function_75));
}
void body_29();
pointer global_c102c110c95c49c52;
void function_76() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_77() {
  increment_count(env);
  val = new_function((&function_76), env);
  pop_function();
}
/* fn_14 */
void body_28() {
  increment_count(env);
  val = new_function((&function_77), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  return_location = (&body_29);
}
void body_30();
pointer global_c95c95c105c100;
void function_78() {
  global_c95c95c105c100 = val; /* __id */
  return_location = (&body_30);
}
/* __id */
void body_29() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  apply((&function_78));
}
void body_31();
pointer global_c102c110c95c49c53;
void function_79() {
  increment_count(val = car(env));
  pop_function();
}
void function_80() {
  increment_count(env);
  val = new_function((&function_79), env);
  pop_function();
}
/* fn_15 */
void body_30() {
  increment_count(env);
  val = new_function((&function_80), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  return_location = (&body_31);
}
void body_32();
pointer global_c95c95c108c105c115c116;
void function_81() {
  global_c95c95c108c105c115c116 = val; /* __list */
  return_location = (&body_32);
}
/* __list */
void body_31() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  apply((&function_81));
}
void body_33();
pointer global_c102c110c95c49c54;
void function_82() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_83() {
  increment_count(env);
  val = new_function((&function_82), env);
  pop_function();
}
/* fn_16 */
void body_32() {
  increment_count(env);
  val = new_function((&function_83), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  return_location = (&body_33);
}
void body_34();
pointer global_c95c95c97c112c112c108c121;
void function_84() {
  global_c95c95c97c112c112c108c121 = val; /* __apply */
  return_location = (&body_34);
}
/* __apply */
void body_33() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  apply((&function_84));
}
void body_35();
pointer global_c102c110c95c50c48 = NIL; /* fn_20 */
pointer global_c102c110c95c49c56 = NIL; /* fn_18 */
pointer global_c102c110c95c50c49;
void function_85() {
  top_level_apply();
}
void function_86() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  apply((&function_85));
}
void function_87() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  apply((&function_86));
}
void function_88() {
  increment_count(env);
  val = new_function((&function_87), env);
  pop_function();
}
/* fn_21 */
void body_34() {
  increment_count(env);
  val = new_function((&function_88), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  return_location = (&body_35);
}
void body_36();
pointer global_c102c110c95c49c55 = NIL; /* fn_17 */
void function_89() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
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
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  apply((&function_89));
}
void function_91() {
  increment_count(env);
  val = new_function((&function_90), env);
  pop_function();
}
/* fn_18 */
void body_35() {
  increment_count(env);
  val = new_function((&function_91), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  return_location = (&body_36);
}
void body_37();
void function_92() {
  top_level_apply();
}
void function_93() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_92));
}
void function_94() {
  increment_count(env);
  val = new_function((&function_93), env);
  pop_function();
}
/* fn_17 */
void body_36() {
  increment_count(env);
  val = new_function((&function_94), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  return_location = (&body_37);
}
void body_38();
pointer global_c102c110c95c49c57 = NIL; /* fn_19 */
void function_95() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_96() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  apply((&function_95));
}
void function_97() {
  increment_count(env);
  val = new_function((&function_96), env);
  pop_function();
}
/* fn_20 */
void body_37() {
  increment_count(env);
  val = new_function((&function_97), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  return_location = (&body_38);
}
void body_39();
void function_98() {
  top_level_apply();
}
void function_99() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_98));
}
void function_100() {
  increment_count(env);
  val = new_function((&function_99), env);
  pop_function();
}
/* fn_19 */
void body_38() {
  increment_count(env);
  val = new_function((&function_100), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  return_location = (&body_39);
}
void body_40();
pointer global_c95c95c114c101c99c117c114c115c101;
void function_101() {
  global_c95c95c114c101c99c117c114c115c101 = val; /* __recurse */
  return_location = (&body_40);
}
/* __recurse */
void body_39() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  apply((&function_101));
}
void body_41();
pointer global_c102c110c95c50c50 = NIL; /* fn_22 */
pointer global_c102c110c95c50c51;
void function_102() {
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
void function_103() {
  increment_count(env);
  val = new_function((&function_102), env);
  pop_function();
}
/* fn_23 */
void body_40() {
  increment_count(env);
  val = new_function((&function_103), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  return_location = (&body_41);
}
void body_42();
pointer global_c95c95c119c97c108c107 = NIL; /* __walk */
void function_104() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_105() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_104));
}
void function_106() {
  apply((&function_105));
}
void function_107() {
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
  increment_count(val = global_c95c95c119c97c108c107); /* __walk */
  apply((&function_106));
}
void function_108() {
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
    apply((&function_107));
  }
}
void function_109() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  apply((&function_108));
}
void function_110() {
  increment_count(env);
  val = new_function((&function_109), env);
  pop_function();
}
/* fn_22 */
void body_41() {
  increment_count(env);
  val = new_function((&function_110), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  return_location = (&body_42);
}
void body_43();
void function_111() {
  global_c95c95c119c97c108c107 = val; /* __walk */
  return_location = (&body_43);
}
/* __walk */
void body_42() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  apply((&function_111));
}
void body_44();
pointer global_c95c95c114c114c101c118c101c114c115c101 = NIL; /* __rreverse */
pointer global_c102c110c95c50c52;
void function_112() {
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
    increment_count(val = global_c95c95c114c114c101c118c101c114c115c101); /* __rreverse */
    top_level_apply();
  }
}
void function_113() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_112));
}
void function_114() {
  increment_count(env);
  val = new_function((&function_113), env);
  pop_function();
}
/* fn_24 */
void body_43() {
  increment_count(env);
  val = new_function((&function_114), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  return_location = (&body_44);
}
void body_45();
void function_115() {
  global_c95c95c114c114c101c118c101c114c115c101 = val; /* __rreverse */
  return_location = (&body_45);
}
/* __rreverse */
void body_44() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  apply((&function_115));
}
void body_46();
pointer global_c95c108c95c49;
/* _l_1 */
void body_45() {
  val = NIL;
  global_c95c108c95c49 = val; /* _l_1 */
  return_location = (&body_46);
}
void body_47();
pointer global_c102c110c95c50c53;
void function_116() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c105c100); /* __id */
  args = cons(val, args);
  increment_count(val = global_c95c108c95c49); /* _l_1 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c114c114c101c118c101c114c115c101); /* __rreverse */
  top_level_apply();
}
void function_117() {
  increment_count(env);
  val = new_function((&function_116), env);
  pop_function();
}
/* fn_25 */
void body_46() {
  increment_count(env);
  val = new_function((&function_117), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  return_location = (&body_47);
}
void body_48();
pointer global_c95c95c114c101c118c101c114c115c101;
void function_118() {
  global_c95c95c114c101c118c101c114c115c101 = val; /* __reverse */
  return_location = (&body_48);
}
/* __reverse */
void body_47() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  apply((&function_118));
}
void body_49();
pointer global_c102c110c95c50c54 = NIL; /* fn_26 */
pointer global_c102c110c95c50c55;
void function_119() {
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
void function_120() {
  increment_count(env);
  val = new_function((&function_119), env);
  pop_function();
}
/* fn_27 */
void body_48() {
  increment_count(env);
  val = new_function((&function_120), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  return_location = (&body_49);
}
void body_50();
pointer global_c95c95c102c111c108c100c108 = NIL; /* __foldl */
void function_121() {
  top_level_apply();
}
void function_122() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c108); /* __foldl */
  apply((&function_121));
}
void function_123() {
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
    apply((&function_122));
  }
}
void function_124() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_123));
}
void function_125() {
  increment_count(env);
  val = new_function((&function_124), env);
  pop_function();
}
/* fn_26 */
void body_49() {
  increment_count(env);
  val = new_function((&function_125), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  return_location = (&body_50);
}
void body_51();
void function_126() {
  global_c95c95c102c111c108c100c108 = val; /* __foldl */
  return_location = (&body_51);
}
/* __foldl */
void body_50() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  apply((&function_126));
}
void body_52();
pointer global_c95c108c95c50;
/* _l_2 */
void body_51() {
  val = NIL;
  global_c95c108c95c50 = val; /* _l_2 */
  return_location = (&body_52);
}
void body_53();
pointer global_c102c110c95c50c56 = NIL; /* fn_28 */
pointer global_c102c110c95c50c57;
void function_127() {
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
void function_128() {
  increment_count(env);
  val = new_function((&function_127), env);
  pop_function();
}
/* fn_29 */
void body_52() {
  increment_count(env);
  val = new_function((&function_128), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  return_location = (&body_53);
}
void body_54();
void function_129() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50); /* _l_2 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c114c114c101c118c101c114c115c101); /* __rreverse */
  top_level_apply();
}
void function_130() {
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
  increment_count(val = global_c95c95c102c111c108c100c108); /* __foldl */
  apply((&function_129));
}
void function_131() {
  increment_count(env);
  val = new_function((&function_130), env);
  pop_function();
}
/* fn_28 */
void body_53() {
  increment_count(env);
  val = new_function((&function_131), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  return_location = (&body_54);
}
void body_55();
pointer global_c95c95c102c111c108c100c114;
void function_132() {
  global_c95c95c102c111c108c100c114 = val; /* __foldr */
  return_location = (&body_55);
}
/* __foldr */
void body_54() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  apply((&function_132));
}
void body_56();
pointer global_c95c108c95c51;
/* _l_3 */
void body_55() {
  val = NIL;
  global_c95c108c95c51 = val; /* _l_3 */
  return_location = (&body_56);
}
void body_57();
pointer global_c95c108c95c52;
/* _l_4 */
void body_56() {
  val = NIL;
  global_c95c108c95c52 = val; /* _l_4 */
  return_location = (&body_57);
}
void body_58();
pointer global_c102c110c95c51c48 = NIL; /* fn_30 */
pointer global_c102c110c95c51c49;
void function_133() {
  top_level_apply();
}
void function_134() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_133));
}
void function_135() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c52); /* _l_4 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  apply((&function_134));
}
void function_136() {
  increment_count(env);
  val = new_function((&function_135), env);
  pop_function();
}
/* fn_31 */
void body_57() {
  increment_count(env);
  val = new_function((&function_136), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  return_location = (&body_58);
}
void body_59();
pointer global_c99c111c110c115 = CONS; /* cons */
void function_137() {
  top_level_apply();
}
void function_138() {
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
    increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
    apply((&function_137));
  }
}
void function_139() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c51); /* _l_3 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_138));
}
void function_140() {
  increment_count(env);
  val = new_function((&function_139), env);
  pop_function();
}
/* fn_30 */
void body_58() {
  increment_count(env);
  val = new_function((&function_140), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  return_location = (&body_59);
}
void body_60();
pointer global_c95c95c97c112c112c101c110c100;
void function_141() {
  global_c95c95c97c112c112c101c110c100 = val; /* __append */
  return_location = (&body_60);
}
/* __append */
void body_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  apply((&function_141));
}
void body_61();
pointer global_c95c108c95c53;
/* _l_5 */
void body_60() {
  val = NIL;
  global_c95c108c95c53 = val; /* _l_5 */
  return_location = (&body_61);
}
void body_62();
pointer global_c95c108c95c54;
/* _l_6 */
void body_61() {
  val = NIL;
  global_c95c108c95c54 = val; /* _l_6 */
  return_location = (&body_62);
}
void body_63();
pointer global_c95c95c101c113c117c97c108 = NIL; /* __equal */
pointer global_c102c110c95c51c50;
void function_142() {
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
    increment_count(val = global_c95c108c95c54); /* _l_6 */
    pop_function();
  }
}
void function_143() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c108c95c53); /* _l_5 */
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
    apply((&function_142));
  }
}
void function_144() {
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
    apply((&function_143));
  }
}
void function_145() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_144));
}
void function_146() {
  increment_count(env);
  val = new_function((&function_145), env);
  pop_function();
}
/* fn_32 */
void body_62() {
  increment_count(env);
  val = new_function((&function_146), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  return_location = (&body_63);
}
void body_64();
void function_147() {
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  return_location = (&body_64);
}
/* __equal */
void body_63() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  apply((&function_147));
}
void body_65();
pointer global_c95c108c95c55;
/* _l_7 */
void body_64() {
  val = NIL;
  global_c95c108c95c55 = val; /* _l_7 */
  return_location = (&body_65);
}
void body_66();
pointer global_c102c110c95c51c51 = NIL; /* fn_33 */
pointer global_c102c110c95c51c52;
void function_148() {
  top_level_apply();
}
void function_149() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_148));
}
void function_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c55); /* _l_7 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  apply((&function_149));
}
void function_151() {
  increment_count(env);
  val = new_function((&function_150), env);
  pop_function();
}
/* fn_34 */
void body_65() {
  increment_count(env);
  val = new_function((&function_151), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  return_location = (&body_66);
}
void body_67();
void function_152() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_152));
}
void function_154() {
  increment_count(env);
  val = new_function((&function_153), env);
  pop_function();
}
/* fn_33 */
void body_66() {
  increment_count(env);
  val = new_function((&function_154), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  return_location = (&body_67);
}
void body_68();
pointer global_c95c95c109c97c112;
void function_155() {
  global_c95c95c109c97c112 = val; /* __map */
  return_location = (&body_68);
}
/* __map */
void body_67() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  apply((&function_155));
}
void body_69();
pointer global_c95c108c95c56;
/* _l_8 */
void body_68() {
  val = NIL;
  global_c95c108c95c56 = val; /* _l_8 */
  return_location = (&body_69);
}
void body_70();
pointer global_c102c110c95c51c53 = NIL; /* fn_35 */
pointer global_c102c110c95c51c54;
void function_156() {
  top_level_apply();
}
void function_157() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_156));
}
void function_158() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c56); /* _l_8 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  apply((&function_157));
}
void function_159() {
  increment_count(env);
  val = new_function((&function_158), env);
  pop_function();
}
/* fn_36 */
void body_69() {
  increment_count(env);
  val = new_function((&function_159), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  return_location = (&body_70);
}
void body_71();
void function_160() {
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
void function_161() {
  increment_count(env);
  val = new_function((&function_160), env);
  pop_function();
}
/* fn_35 */
void body_70() {
  increment_count(env);
  val = new_function((&function_161), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  return_location = (&body_71);
}
void body_72();
pointer global_c95c95c111c114;
void function_162() {
  global_c95c95c111c114 = val; /* __or */
  return_location = (&body_72);
}
/* __or */
void body_71() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  apply((&function_162));
}
void body_73();
pointer global_c95c108c95c57;
/* _l_9 */
void body_72() {
  val = NIL;
  global_c95c108c95c57 = val; /* _l_9 */
  return_location = (&body_73);
}
void body_74();
pointer global_c95c108c95c49c48;
/* _l_10 */
void body_73() {
  val = -40;
  global_c95c108c95c49c48 = val; /* _l_10 */
  return_location = (&body_74);
}
void body_75();
pointer global_c102c110c95c51c55 = NIL; /* fn_37 */
pointer global_c102c110c95c51c56;
void function_163() {
  top_level_apply();
}
void function_164() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_163));
}
void function_165() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c49c48); /* _l_10 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  apply((&function_164));
}
void function_166() {
  increment_count(env);
  val = new_function((&function_165), env);
  pop_function();
}
/* fn_38 */
void body_74() {
  increment_count(env);
  val = new_function((&function_166), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  return_location = (&body_75);
}
void body_76();
void function_167() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_c95c108c95c57); /* _l_9 */
    pop_function();
  }
}
void function_168() {
  increment_count(env);
  val = new_function((&function_167), env);
  pop_function();
}
/* fn_37 */
void body_75() {
  increment_count(env);
  val = new_function((&function_168), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  return_location = (&body_76);
}
void body_77();
pointer global_c95c95c97c110c100;
void function_169() {
  global_c95c95c97c110c100 = val; /* __and */
  return_location = (&body_77);
}
/* __and */
void body_76() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  apply((&function_169));
}
void body_78();
pointer global_c95c108c95c49c49;
/* _l_11 */
void body_77() {
  val = NIL;
  global_c95c108c95c49c49 = val; /* _l_11 */
  return_location = (&body_78);
}
void body_79();
pointer global_c95c108c95c49c50;
/* _l_12 */
void body_78() {
  val = -40;
  global_c95c108c95c49c50 = val; /* _l_12 */
  return_location = (&body_79);
}
void body_80();
pointer global_c102c110c95c51c57;
void function_170() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c108c95c49c49); /* _l_11 */
    pop_function();
  } else {
    increment_count(val = global_c95c108c95c49c50); /* _l_12 */
    pop_function();
  }
}
void function_171() {
  increment_count(env);
  val = new_function((&function_170), env);
  pop_function();
}
/* fn_39 */
void body_79() {
  increment_count(env);
  val = new_function((&function_171), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  return_location = (&body_80);
}
void body_81();
pointer global_c95c95c110c111c116;
void function_172() {
  global_c95c95c110c111c116 = val; /* __not */
  return_location = (&body_81);
}
/* __not */
void body_80() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  apply((&function_172));
}
void body_82();
pointer global_c95c108c95c49c51;
/* _l_13 */
void body_81() {
  val = NIL;
  global_c95c108c95c49c51 = val; /* _l_13 */
  return_location = (&body_82);
}
void body_83();
pointer global_c95c95c109c101c109c98c101c114 = NIL; /* __member */
pointer global_c102c110c95c52c48;
void function_173() {
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
    increment_count(val = global_c95c95c109c101c109c98c101c114); /* __member */
    top_level_apply();
  }
}
void function_174() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c108c95c49c51); /* _l_13 */
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
    apply((&function_173));
  }
}
void function_175() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_174));
}
void function_176() {
  increment_count(env);
  val = new_function((&function_175), env);
  pop_function();
}
/* fn_40 */
void body_82() {
  increment_count(env);
  val = new_function((&function_176), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  return_location = (&body_83);
}
void body_84();
void function_177() {
  global_c95c95c109c101c109c98c101c114 = val; /* __member */
  return_location = (&body_84);
}
/* __member */
void body_83() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  apply((&function_177));
}
void body_85();
pointer global_c102c110c95c52c49;
void function_178() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_179() {
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
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
  apply((&function_178));
}
void function_180() {
  increment_count(env);
  val = new_function((&function_179), env);
  pop_function();
}
/* fn_41 */
void body_84() {
  increment_count(env);
  val = new_function((&function_180), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  return_location = (&body_85);
}
void body_86();
pointer global_c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
void function_181() {
  global_c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* __map-to-stderr */
  return_location = (&body_86);
}
void function_182() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_181));
}
/* __map-to-stderr */
void body_85() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  apply((&function_182));
}
void body_87();
pointer global_c95c108c95c49c52;
/* _l_14 */
void body_86() {
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
  global_c95c108c95c49c52 = val; /* _l_14 */
  return_location = (&body_87);
}
void body_88();
pointer global_c95c108c95c49c53;
/* _l_15 */
void body_87() {
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
  global_c95c108c95c49c53 = val; /* _l_15 */
  return_location = (&body_88);
}
void body_89();
pointer global_c95c108c95c49c54;
/* _l_16 */
void body_88() {
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
  global_c95c108c95c49c54 = val; /* _l_16 */
  return_location = (&body_89);
}
void body_90();
pointer global_c95c108c95c49c55;
/* _l_17 */
void body_89() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c49c55 = val; /* _l_17 */
  return_location = (&body_90);
}
void body_91();
pointer global_c95c95c112c114c105c110c116 = NIL; /* __print */
pointer global_c102c110c95c52c50;
void function_183() {
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* __map-to-stderr */
  top_level_apply();
}
void function_184() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c49c53); /* _l_15 */
  args = cons(val, args);
  increment_count(val = global_c95c108c95c49c52); /* _l_14 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_183));
}
void function_185() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c49c55); /* _l_17 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c49c54); /* _l_16 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c114c105c110c116); /* __print */
    apply((&function_184));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_186() {
  increment_count(env);
  val = new_function((&function_185), env);
  pop_function();
}
/* fn_42 */
void body_90() {
  increment_count(env);
  val = new_function((&function_186), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  return_location = (&body_91);
}
void body_92();
pointer global_c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
void function_187() {
  global_c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* __print-warnings */
  return_location = (&body_92);
}
/* __print-warnings */
void body_91() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  apply((&function_187));
}
void body_93();
pointer global_c95c108c95c49c56;
/* _l_18 */
void body_92() {
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
  global_c95c108c95c49c56 = val; /* _l_18 */
  return_location = (&body_93);
}
void body_94();
pointer global_c95c108c95c49c57;
/* _l_19 */
void body_93() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c49c57 = val; /* _l_19 */
  return_location = (&body_94);
}
void body_95();
pointer global_c102c110c95c52c51;
void function_188() {
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* __map-to-stderr */
  top_level_apply();
}
void function_189() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c49c57); /* _l_19 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c49c56); /* _l_18 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_188));
}
void function_190() {
  increment_count(env);
  val = new_function((&function_189), env);
  pop_function();
}
/* fn_43 */
void body_94() {
  increment_count(env);
  val = new_function((&function_190), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  return_location = (&body_95);
}
void body_96();
pointer global_c95c95c112c114c105c110c116c45c101c114c114c111c114;
void function_191() {
  global_c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* __print-error */
  return_location = (&body_96);
}
/* __print-error */
void body_95() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  apply((&function_191));
}
void body_97();
pointer global_c102c110c95c52c52;
void function_192() {
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    pop_function();
  } else {
    increment_count(val = car(car(env)));
    pop_function();
  }
}
void function_193() {
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
    apply((&function_192));
  }
}
void function_194() {
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
    apply((&function_193));
  }
}
void function_195() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_194));
}
void function_196() {
  increment_count(env);
  val = new_function((&function_195), env);
  pop_function();
}
/* fn_44 */
void body_96() {
  increment_count(env);
  val = new_function((&function_196), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  return_location = (&body_97);
}
void body_98();
pointer global_c95c95c101c115c99c97c112c101c45c99c104c97c114;
void function_197() {
  global_c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* __escape-char */
  return_location = (&body_98);
}
/* __escape-char */
void body_97() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  apply((&function_197));
}
void body_99();
pointer global_c102c110c95c52c53 = NIL; /* fn_45 */
pointer global_c102c110c95c52c54;
void function_198() {
  top_level_apply();
}
void function_199() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c108); /* __foldl */
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
  val = new_number(0);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  apply((&function_199));
}
void function_201() {
  increment_count(env);
  val = new_function((&function_200), env);
  pop_function();
}
/* fn_46 */
void body_98() {
  increment_count(env);
  val = new_function((&function_201), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  return_location = (&body_99);
}
void body_100();
void function_202() {
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
void function_203() {
  increment_count(env);
  val = new_function((&function_202), env);
  pop_function();
}
/* fn_45 */
void body_99() {
  increment_count(env);
  val = new_function((&function_203), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  return_location = (&body_100);
}
void body_101();
pointer global_c95c95c98c117c105c108c100c45c110c117c109;
void function_204() {
  global_c95c95c98c117c105c108c100c45c110c117c109 = val; /* __build-num */
  return_location = (&body_101);
}
/* __build-num */
void body_100() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  apply((&function_204));
}
void body_102();
pointer global_c95c108c95c50c48;
/* _l_20 */
void body_101() {
  val = -37;
  global_c95c108c95c50c48 = val; /* _l_20 */
  return_location = (&body_102);
}
void body_103();
pointer global_c102c110c95c52c55;
void function_205() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50c48); /* _l_20 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
  top_level_apply();
}
void function_206() {
  increment_count(env);
  val = new_function((&function_205), env);
  pop_function();
}
/* fn_47 */
void body_102() {
  increment_count(env);
  val = new_function((&function_206), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  return_location = (&body_103);
}
void body_104();
pointer global_c95c95c113c117c111c116c101c45c118c97c108c117c101;
void function_207() {
  global_c95c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* __quote-value */
  return_location = (&body_104);
}
/* __quote-value */
void body_103() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  apply((&function_207));
}
void body_105();
pointer global_c95c108c95c50c49;
/* _l_21 */
void body_104() {
  val = -39;
  global_c95c108c95c50c49 = val; /* _l_21 */
  return_location = (&body_105);
}
void body_106();
pointer global_c102c110c95c52c56;
void function_208() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50c49); /* _l_21 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
  top_level_apply();
}
void function_209() {
  increment_count(env);
  val = new_function((&function_208), env);
  pop_function();
}
/* fn_48 */
void body_105() {
  increment_count(env);
  val = new_function((&function_209), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  return_location = (&body_106);
}
void body_107();
pointer global_c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
void function_210() {
  global_c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* __quasiquote-value */
  return_location = (&body_107);
}
/* __quasiquote-value */
void body_106() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  apply((&function_210));
}
void body_108();
pointer global_c95c108c95c50c50;
/* _l_22 */
void body_107() {
  val = -38;
  global_c95c108c95c50c50 = val; /* _l_22 */
  return_location = (&body_108);
}
void body_109();
pointer global_c102c110c95c52c57;
void function_211() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50c50); /* _l_22 */
  args = cons(val, args);
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
  top_level_apply();
}
void function_212() {
  increment_count(env);
  val = new_function((&function_211), env);
  pop_function();
}
/* fn_49 */
void body_108() {
  increment_count(env);
  val = new_function((&function_212), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  return_location = (&body_109);
}
void body_110();
pointer global_c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
void function_213() {
  global_c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* __unquote-value */
  return_location = (&body_110);
}
/* __unquote-value */
void body_109() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  apply((&function_213));
}
void body_111();
pointer global_c102c110c95c53c48;
void function_214() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_215() {
  increment_count(env);
  val = new_function((&function_214), env);
  pop_function();
}
/* fn_50 */
void body_110() {
  increment_count(env);
  val = new_function((&function_215), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  return_location = (&body_111);
}
void body_112();
pointer global_c95c95c102c97c105c108;
void function_216() {
  global_c95c95c102c97c105c108 = val; /* __fail */
  return_location = (&body_112);
}
/* __fail */
void body_111() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  apply((&function_216));
}
void body_113();
pointer global_c102c110c95c53c49;
void function_217() {
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
void function_218() {
  increment_count(env);
  val = new_function((&function_217), env);
  pop_function();
}
/* fn_51 */
void body_112() {
  increment_count(env);
  val = new_function((&function_218), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  return_location = (&body_113);
}
void body_114();
pointer global_c95c95c100c111c110c101;
void function_219() {
  global_c95c95c100c111c110c101 = val; /* __done */
  return_location = (&body_114);
}
/* __done */
void body_113() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  apply((&function_219));
}
void body_115();
pointer global_c95c108c95c50c51;
/* _l_23 */
void body_114() {
  val = NIL;
  global_c95c108c95c50c51 = val; /* _l_23 */
  return_location = (&body_115);
}
void body_116();
pointer global_c102c110c95c53c50 = NIL; /* fn_52 */
pointer global_c102c110c95c53c51;
void function_220() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  top_level_apply();
}
void function_221() {
  increment_count(env);
  val = new_function((&function_220), env);
  pop_function();
}
/* fn_53 */
void body_115() {
  increment_count(env);
  val = new_function((&function_221), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  return_location = (&body_116);
}
void body_117();
pointer global_c95c95c112c111c112 = NIL; /* __pop */
void function_222() {
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
void function_223() {
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
    apply((&function_222));
  }
}
void function_224() {
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
    increment_count(val = global_c95c95c112c111c112); /* __pop */
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
    increment_count(val = global_c95c95c110c111c116); /* __not */
    apply((&function_223));
  }
}
void function_225() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c50c51); /* _l_23 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_224));
}
void function_226() {
  increment_count(env);
  val = new_function((&function_225), env);
  pop_function();
}
/* fn_52 */
void body_116() {
  increment_count(env);
  val = new_function((&function_226), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  return_location = (&body_117);
}
void body_118();
void function_227() {
  global_c95c95c112c111c112 = val; /* __pop */
  return_location = (&body_118);
}
/* __pop */
void body_117() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  apply((&function_227));
}
void body_119();
pointer global_c102c110c95c53c53 = NIL; /* fn_55 */
pointer global_c102c110c95c53c54;
void function_228() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  top_level_apply();
}
void function_229() {
  increment_count(env);
  val = new_function((&function_228), env);
  pop_function();
}
/* fn_56 */
void body_118() {
  increment_count(env);
  val = new_function((&function_229), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  return_location = (&body_119);
}
void body_120();
pointer global_c102c110c95c53c52 = NIL; /* fn_54 */
void function_230() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c112); /* __pop */
  top_level_apply();
}
void function_231() {
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
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  apply((&function_230));
}
void function_232() {
  increment_count(env);
  val = new_function((&function_231), env);
  pop_function();
}
/* fn_55 */
void body_119() {
  increment_count(env);
  val = new_function((&function_232), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  return_location = (&body_120);
}
void body_121();
void function_233() {
  top_level_apply();
}
void function_234() {
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
    apply((&function_233));
  }
}
void function_235() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_234));
}
void function_236() {
  increment_count(env);
  val = new_function((&function_235), env);
  pop_function();
}
/* fn_54 */
void body_120() {
  increment_count(env);
  val = new_function((&function_236), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  return_location = (&body_121);
}
void body_122();
pointer global_c95c95c99c104c101c99c107;
void function_237() {
  global_c95c95c99c104c101c99c107 = val; /* __check */
  return_location = (&body_122);
}
/* __check */
void body_121() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  apply((&function_237));
}
void body_123();
pointer global_c102c110c95c53c55 = NIL; /* fn_57 */
pointer global_c102c110c95c53c56;
void function_238() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c101c99c107); /* __check */
  top_level_apply();
}
void function_239() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  apply((&function_238));
}
void function_240() {
  increment_count(env);
  val = new_function((&function_239), env);
  pop_function();
}
/* fn_58 */
void body_122() {
  increment_count(env);
  val = new_function((&function_240), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  return_location = (&body_123);
}
void body_124();
void function_241() {
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
void function_242() {
  increment_count(env);
  val = new_function((&function_241), env);
  pop_function();
}
/* fn_57 */
void body_123() {
  increment_count(env);
  val = new_function((&function_242), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  return_location = (&body_124);
}
void body_125();
pointer global_c95c95c109c97c116c99c104;
void function_243() {
  global_c95c95c109c97c116c99c104 = val; /* __match */
  return_location = (&body_125);
}
/* __match */
void body_124() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  apply((&function_243));
}
void body_126();
pointer global_c102c110c95c53c57 = NIL; /* fn_59 */
pointer global_c102c110c95c54c48;
void function_244() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  top_level_apply();
}
void function_245() {
  increment_count(env);
  val = new_function((&function_244), env);
  pop_function();
}
/* fn_60 */
void body_125() {
  increment_count(env);
  val = new_function((&function_245), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  return_location = (&body_126);
}
void body_127();
void function_246() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_247() {
  increment_count(env);
  val = new_function((&function_246), env);
  pop_function();
}
/* fn_59 */
void body_126() {
  increment_count(env);
  val = new_function((&function_247), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  return_location = (&body_127);
}
void body_128();
pointer global_c95c95c100c101c102c97c117c108c116;
void function_248() {
  global_c95c95c100c101c102c97c117c108c116 = val; /* __default */
  return_location = (&body_128);
}
/* __default */
void body_127() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  apply((&function_248));
}
void body_129();
pointer global_c102c110c95c54c52 = NIL; /* fn_64 */
pointer global_c102c110c95c54c53;
void function_249() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  top_level_apply();
}
void function_250() {
  increment_count(env);
  val = new_function((&function_249), env);
  pop_function();
}
/* fn_65 */
void body_128() {
  increment_count(env);
  val = new_function((&function_250), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  return_location = (&body_129);
}
void body_130();
pointer global_c102c110c95c54c51 = NIL; /* fn_63 */
void function_251() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  top_level_apply();
}
void function_252() {
  increment_count(env);
  val = new_function((&function_251), env);
  pop_function();
}
/* fn_64 */
void body_129() {
  increment_count(env);
  val = new_function((&function_252), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  return_location = (&body_130);
}
void body_131();
pointer global_c102c110c95c54c50 = NIL; /* fn_62 */
pointer global_c102c110c95c54c49 = NIL; /* fn_61 */
void function_253() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_254() {
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
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  apply((&function_253));
}
void function_255() {
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
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  apply((&function_254));
}
void function_256() {
  increment_count(env);
  val = new_function((&function_255), env);
  pop_function();
}
/* fn_63 */
void body_130() {
  increment_count(env);
  val = new_function((&function_256), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  return_location = (&body_131);
}
void body_132();
void function_257() {
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
void function_258() {
  increment_count(env);
  val = new_function((&function_257), env);
  pop_function();
}
/* fn_61 */
void body_131() {
  increment_count(env);
  val = new_function((&function_258), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  return_location = (&body_132);
}
void body_133();
void function_259() {
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
void function_260() {
  increment_count(env);
  val = new_function((&function_259), env);
  pop_function();
}
/* fn_62 */
void body_132() {
  increment_count(env);
  val = new_function((&function_260), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  return_location = (&body_133);
}
void body_134();
pointer global_c95c95c99c97c115c101;
void function_261() {
  global_c95c95c99c97c115c101 = val; /* __case */
  return_location = (&body_134);
}
/* __case */
void body_133() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  apply((&function_261));
}
void body_135();
pointer global_c102c110c95c54c54 = NIL; /* fn_66 */
pointer global_c102c110c95c54c55;
void function_262() {
  top_level_apply();
}
void function_263() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_262));
}
void function_264() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c102c97c105c108); /* __fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  apply((&function_263));
}
void function_265() {
  increment_count(env);
  val = new_function((&function_264), env);
  pop_function();
}
/* fn_67 */
void body_134() {
  increment_count(env);
  val = new_function((&function_265), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  return_location = (&body_135);
}
void body_136();
void function_266() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_267() {
  increment_count(env);
  val = new_function((&function_266), env);
  pop_function();
}
/* fn_66 */
void body_135() {
  increment_count(env);
  val = new_function((&function_267), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  return_location = (&body_136);
}
void body_137();
pointer global_c95c95c99c104c111c105c99c101;
void function_268() {
  global_c95c95c99c104c111c105c99c101 = val; /* __choice */
  return_location = (&body_137);
}
/* __choice */
void body_136() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  apply((&function_268));
}
void body_138();
pointer global_c102c110c95c54c57 = NIL; /* fn_69 */
pointer global_c102c110c95c55c48;
void function_269() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  top_level_apply();
}
void function_270() {
  increment_count(env);
  val = new_function((&function_269), env);
  pop_function();
}
/* fn_70 */
void body_137() {
  increment_count(env);
  val = new_function((&function_270), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  return_location = (&body_138);
}
void body_139();
pointer global_c102c110c95c54c56 = NIL; /* fn_68 */
void function_271() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_272() {
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
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  apply((&function_271));
}
void function_273() {
  increment_count(env);
  val = new_function((&function_272), env);
  pop_function();
}
/* fn_69 */
void body_138() {
  increment_count(env);
  val = new_function((&function_273), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  return_location = (&body_139);
}
void body_140();
void function_274() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_275() {
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
  apply((&function_274));
}
void function_276() {
  increment_count(env);
  val = new_function((&function_275), env);
  pop_function();
}
/* fn_68 */
void body_139() {
  increment_count(env);
  val = new_function((&function_276), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  return_location = (&body_140);
}
void body_141();
pointer global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115;
void function_277() {
  global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* __post-process */
  return_location = (&body_141);
}
/* __post-process */
void body_140() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  apply((&function_277));
}
void body_142();
pointer global_c102c110c95c55c51 = NIL; /* fn_73 */
pointer global_c102c110c95c55c52;
void function_278() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  top_level_apply();
}
void function_279() {
  increment_count(env);
  val = new_function((&function_278), env);
  pop_function();
}
/* fn_74 */
void body_141() {
  increment_count(env);
  val = new_function((&function_279), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  return_location = (&body_142);
}
void body_143();
pointer global_c102c110c95c55c50 = NIL; /* fn_72 */
void function_280() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_281() {
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
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  apply((&function_280));
}
void function_282() {
  increment_count(env);
  val = new_function((&function_281), env);
  pop_function();
}
/* fn_73 */
void body_142() {
  increment_count(env);
  val = new_function((&function_282), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  return_location = (&body_143);
}
void body_144();
pointer global_c102c110c95c55c49 = NIL; /* fn_71 */
void function_283() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_284() {
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
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  apply((&function_283));
}
void function_285() {
  increment_count(env);
  val = new_function((&function_284), env);
  pop_function();
}
/* fn_72 */
void body_143() {
  increment_count(env);
  val = new_function((&function_285), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  return_location = (&body_144);
}
void body_145();
void function_286() {
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
void function_287() {
  increment_count(env);
  val = new_function((&function_286), env);
  pop_function();
}
/* fn_71 */
void body_144() {
  increment_count(env);
  val = new_function((&function_287), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  return_location = (&body_145);
}
void body_146();
pointer global_c95c95c115c101c113;
void function_288() {
  global_c95c95c115c101c113 = val; /* __seq */
  return_location = (&body_146);
}
/* __seq */
void body_145() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  apply((&function_288));
}
void body_147();
pointer global_c102c110c95c55c53;
void function_289() {
  args = cons(val, args);
  increment_count(val = global_c95c95c115c101c113); /* __seq */
  top_level_apply();
}
void function_290() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c99c104c97c114); /* __escape-char */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c112); /* __pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  apply((&function_289));
}
void function_291() {
  increment_count(env);
  val = new_function((&function_290), env);
  pop_function();
}
/* fn_75 */
void body_146() {
  increment_count(env);
  val = new_function((&function_291), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  return_location = (&body_147);
}
void body_148();
pointer global_c95c95c101c115c99c97c112c101;
void function_292() {
  global_c95c95c101c115c99c97c112c101 = val; /* __escape */
  return_location = (&body_148);
}
/* __escape */
void body_147() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  apply((&function_292));
}
void body_149();
pointer global_c102c110c95c55c54;
void function_293() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c112); /* __pop */
  args = cons(val, args);
  increment_count(val = global_c95c95c115c101c113); /* __seq */
  top_level_apply();
}
void function_294() {
  increment_count(env);
  val = new_function((&function_293), env);
  pop_function();
}
/* fn_76 */
void body_148() {
  increment_count(env);
  val = new_function((&function_294), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  return_location = (&body_149);
}
void body_150();
pointer global_c95c95c117c115c101;
void function_295() {
  global_c95c95c117c115c101 = val; /* __use */
  return_location = (&body_150);
}
/* __use */
void body_149() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  apply((&function_295));
}
void body_151();
pointer global_c102c110c95c55c56 = NIL; /* fn_78 */
pointer global_c102c110c95c55c57;
void function_296() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  top_level_apply();
}
void function_297() {
  increment_count(env);
  val = new_function((&function_296), env);
  pop_function();
}
/* fn_79 */
void body_150() {
  increment_count(env);
  val = new_function((&function_297), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  return_location = (&body_151);
}
void body_152();
pointer global_c102c110c95c55c55 = NIL; /* fn_77 */
void function_298() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_299() {
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
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  apply((&function_298));
}
void function_300() {
  increment_count(env);
  val = new_function((&function_299), env);
  pop_function();
}
/* fn_78 */
void body_151() {
  increment_count(env);
  val = new_function((&function_300), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  return_location = (&body_152);
}
void body_153();
void function_301() {
  top_level_apply();
}
void function_302() {
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
  apply((&function_301));
}
void function_303() {
  increment_count(env);
  val = new_function((&function_302), env);
  pop_function();
}
/* fn_77 */
void body_152() {
  increment_count(env);
  val = new_function((&function_303), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  return_location = (&body_153);
}
void body_154();
pointer global_c95c95c112c101c101c107;
void function_304() {
  global_c95c95c112c101c101c107 = val; /* __peek */
  return_location = (&body_154);
}
/* __peek */
void body_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  apply((&function_304));
}
void body_155();
pointer global_c102c110c95c56c48 = NIL; /* fn_80 */
pointer global_c102c110c95c56c49;
void function_305() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c101c99c107); /* __check */
  top_level_apply();
}
void function_306() {
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
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  apply((&function_305));
}
void function_307() {
  increment_count(env);
  val = new_function((&function_306), env);
  pop_function();
}
/* fn_81 */
void body_154() {
  increment_count(env);
  val = new_function((&function_307), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  return_location = (&body_155);
}
void body_156();
void function_308() {
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
  increment_count(val = global_c95c95c97c110c100); /* __and */
  top_level_apply();
}
void function_309() {
  increment_count(env);
  val = new_function((&function_308), env);
  pop_function();
}
/* fn_80 */
void body_155() {
  increment_count(env);
  val = new_function((&function_309), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  return_location = (&body_156);
}
void body_157();
pointer global_c95c95c105c110c116c101c114c118c97c108;
void function_310() {
  global_c95c95c105c110c116c101c114c118c97c108 = val; /* __interval */
  return_location = (&body_157);
}
/* __interval */
void body_156() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  apply((&function_310));
}
void body_158();
pointer global_c99c100c114 = CDR; /* cdr */
pointer global_c102c110c95c56c50;
void function_311() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  top_level_apply();
}
void function_312() {
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
  increment_count(val = global_c95c95c117c115c101); /* __use */
  apply((&function_311));
}
void function_313() {
  increment_count(env);
  val = new_function((&function_312), env);
  pop_function();
}
/* fn_82 */
void body_157() {
  increment_count(env);
  val = new_function((&function_313), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  return_location = (&body_158);
}
void body_159();
pointer global_c95c95c115c107c105c112;
void function_314() {
  global_c95c95c115c107c105c112 = val; /* __skip */
  return_location = (&body_159);
}
/* __skip */
void body_158() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  apply((&function_314));
}
void body_160();
pointer global_c99c97c114 = CAR; /* car */
pointer global_c102c110c95c56c51;
void function_315() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  top_level_apply();
}
void function_316() {
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
  increment_count(val = global_c95c95c115c101c113); /* __seq */
  apply((&function_315));
}
void function_317() {
  increment_count(env);
  val = new_function((&function_316), env);
  pop_function();
}
/* fn_83 */
void body_159() {
  increment_count(env);
  val = new_function((&function_317), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  return_location = (&body_160);
}
void body_161();
pointer global_c95c95c102c105c114c115c116;
void function_318() {
  global_c95c95c102c105c114c115c116 = val; /* __first */
  return_location = (&body_161);
}
/* __first */
void body_160() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  apply((&function_318));
}
void body_162();
pointer global_c95c95c112c97c114c115c101c45c110c117c109 = NIL; /* __parse-num */
pointer global_c102c110c95c56c52;
void function_319() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_320() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_319));
}
void function_321() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_320));
}
void function_322() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c101c101c107); /* __peek */
  apply((&function_321));
}
void function_323() {
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
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_322));
}
void function_324() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c110c117c109); /* __parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c117c115c101); /* __use */
  apply((&function_323));
}
void function_325() {
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
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_324));
}
void function_326() {
  increment_count(env);
  val = new_function((&function_325), env);
  pop_function();
}
/* fn_84 */
void body_161() {
  increment_count(env);
  val = new_function((&function_326), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  return_location = (&body_162);
}
void body_163();
void function_327() {
  global_c95c95c112c97c114c115c101c45c110c117c109 = val; /* __parse-num */
  return_location = (&body_163);
}
/* __parse-num */
void body_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  apply((&function_327));
}
void body_164();
pointer global_c102c110c95c56c53;
void function_328() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_329() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c98c117c105c108c100c45c110c117c109); /* __build-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c114c115c101c45c110c117c109); /* __parse-num */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  apply((&function_328));
}
void function_330() {
  increment_count(env);
  val = new_function((&function_329), env);
  pop_function();
}
/* fn_85 */
void body_163() {
  increment_count(env);
  val = new_function((&function_330), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  return_location = (&body_164);
}
void body_165();
pointer global_c95c95c114c101c97c100c45c110c117c109;
void function_331() {
  global_c95c95c114c101c97c100c45c110c117c109 = val; /* __read-num */
  return_location = (&body_165);
}
/* __read-num */
void body_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  apply((&function_331));
}
void body_166();
pointer global_c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* __parse-symbol */
pointer global_c102c110c95c56c54;
void function_332() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_333() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_332));
}
void function_334() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_333));
}
void function_335() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_334));
}
void function_336() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_335));
}
void function_337() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c101c101c107); /* __peek */
  apply((&function_336));
}
void function_338() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
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
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_337));
}
void function_339() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_338));
}
void function_340() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c101c101c107); /* __peek */
  apply((&function_339));
}
void function_341() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_340));
}
void function_342() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_341));
}
void function_343() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c101c101c107); /* __peek */
  apply((&function_342));
}
void function_344() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_343));
}
void function_345() {
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_344));
}
void function_346() {
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
  increment_count(val = global_c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* __parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c117c115c101); /* __use */
  apply((&function_345));
}
void function_347() {
  increment_count(env);
  val = new_function((&function_346), env);
  pop_function();
}
/* fn_86 */
void body_165() {
  increment_count(env);
  val = new_function((&function_347), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  return_location = (&body_166);
}
void body_167();
void function_348() {
  global_c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* __parse-symbol */
  return_location = (&body_167);
}
/* __parse-symbol */
void body_166() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  apply((&function_348));
}
void body_168();
pointer global_c102c110c95c56c55;
void function_349() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_350() {
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
  increment_count(val = global_c95c95c112c97c114c115c101c45c115c121c109c98c111c108); /* __parse-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  apply((&function_349));
}
void function_351() {
  increment_count(env);
  val = new_function((&function_350), env);
  pop_function();
}
/* fn_87 */
void body_167() {
  increment_count(env);
  val = new_function((&function_351), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  return_location = (&body_168);
}
void body_169();
pointer global_c95c95c114c101c97c100c45c115c121c109c98c111c108;
void function_352() {
  global_c95c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* __read-symbol */
  return_location = (&body_169);
}
/* __read-symbol */
void body_168() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  apply((&function_352));
}
void body_170();
pointer global_c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* __parse-string */
pointer global_c102c110c95c56c56;
void function_353() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_354() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_353));
}
void function_355() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_354));
}
void function_356() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_355));
}
void function_357() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_356));
}
void function_358() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_357));
}
void function_359() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* __parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c101c115c99c97c112c101); /* __escape */
  apply((&function_358));
}
void function_360() {
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_359));
}
void function_361() {
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
  increment_count(val = global_c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* __parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c117c115c101); /* __use */
  apply((&function_360));
}
void function_362() {
  increment_count(env);
  val = new_function((&function_361), env);
  pop_function();
}
/* fn_88 */
void body_169() {
  increment_count(env);
  val = new_function((&function_362), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  return_location = (&body_170);
}
void body_171();
void function_363() {
  global_c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* __parse-string */
  return_location = (&body_171);
}
/* __parse-string */
void body_170() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  apply((&function_363));
}
void body_172();
pointer global_c102c110c95c56c57;
void function_364() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c113c117c111c116c101c45c118c97c108c117c101); /* __quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  top_level_apply();
}
void function_365() {
  increment_count(env);
  val = new_function((&function_364), env);
  pop_function();
}
/* fn_89 */
void body_171() {
  increment_count(env);
  val = new_function((&function_365), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  return_location = (&body_172);
}
void body_173();
pointer global_c95c95c113c117c111c116c101c45c112c97c114c115c101c114;
void function_366() {
  global_c95c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* __quote-parser */
  return_location = (&body_173);
}
/* __quote-parser */
void body_172() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  apply((&function_366));
}
void body_174();
pointer global_c102c110c95c57c48;
void function_367() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* __quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  top_level_apply();
}
void function_368() {
  increment_count(env);
  val = new_function((&function_367), env);
  pop_function();
}
/* fn_90 */
void body_173() {
  increment_count(env);
  val = new_function((&function_368), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  return_location = (&body_174);
}
void body_175();
pointer global_c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
void function_369() {
  global_c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* __quasiquote-parser */
  return_location = (&body_175);
}
/* __quasiquote-parser */
void body_174() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  apply((&function_369));
}
void body_176();
pointer global_c102c110c95c57c49;
void function_370() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* __unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c111c115c116c45c112c114c111c99c101c115c115); /* __post-process */
  top_level_apply();
}
void function_371() {
  increment_count(env);
  val = new_function((&function_370), env);
  pop_function();
}
/* fn_91 */
void body_175() {
  increment_count(env);
  val = new_function((&function_371), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  return_location = (&body_176);
}
void body_177();
pointer global_c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
void function_372() {
  global_c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* __unquote-parser */
  return_location = (&body_177);
}
/* __unquote-parser */
void body_176() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  apply((&function_372));
}
void body_178();
pointer global_c102c110c95c57c50 = NIL; /* fn_92 */
pointer global_c102c110c95c57c51;
void function_373() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  top_level_apply();
}
void function_374() {
  increment_count(env);
  val = new_function((&function_373), env);
  pop_function();
}
/* fn_93 */
void body_177() {
  increment_count(env);
  val = new_function((&function_374), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  return_location = (&body_178);
}
void body_179();
pointer global_c95c95c99c111c109c109c101c110c116 = NIL; /* __comment */
void function_375() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_376() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_375));
}
void function_377() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_376));
}
void function_378() {
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
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_377));
}
void function_379() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_378));
}
void function_380() {
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
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_379));
}
void function_381() {
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_380));
}
void function_382() {
  args = cons(val, args);
  increment_count(val = global_c95c95c115c107c105c112); /* __skip */
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c109c101c110c116); /* __comment */
  apply((&function_382));
}
void function_384() {
  increment_count(env);
  val = new_function((&function_383), env);
  pop_function();
}
/* fn_92 */
void body_178() {
  increment_count(env);
  val = new_function((&function_384), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  return_location = (&body_179);
}
void body_180();
void function_385() {
  global_c95c95c99c111c109c109c101c110c116 = val; /* __comment */
  return_location = (&body_180);
}
/* __comment */
void body_179() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  apply((&function_385));
}
void body_181();
pointer global_c95c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* __parse-paren */
pointer global_c102c110c95c57c52;
void function_386() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_387() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_386));
}
void function_388() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_387));
}
void function_389() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c114c101c110); /* __parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_388));
}
void function_390() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_389));
}
void function_391() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_390));
}
void function_392() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c114c101c110); /* __parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c109c101c110c116); /* __comment */
  apply((&function_391));
}
void function_393() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_392));
}
void function_394() {
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
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_393));
}
void function_395() {
  increment_count(env);
  val = new_function((&function_394), env);
  pop_function();
}
/* fn_94 */
void body_180() {
  increment_count(env);
  val = new_function((&function_395), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  return_location = (&body_181);
}
void body_182();
void function_396() {
  global_c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* __parse-paren */
  return_location = (&body_182);
}
/* __parse-paren */
void body_181() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  apply((&function_396));
}
void body_183();
pointer global_c95c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* __parse-expr */
pointer global_c95c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* __parse-pair */
pointer global_c102c110c95c57c53;
void function_397() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_398() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_397));
}
void function_399() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_398));
}
void function_400() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c105c114); /* __parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_399));
}
void function_401() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_400));
}
void function_402() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_401));
}
void function_403() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c105c114); /* __parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c109c101c110c116); /* __comment */
  apply((&function_402));
}
void function_404() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_403));
}
void function_405() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c100c111c110c101); /* __done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_404));
}
void function_406() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_405));
}
void function_407() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_406));
}
void function_408() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c114c101c110); /* __parse-paren */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c102c105c114c115c116); /* __first */
  apply((&function_407));
}
void function_409() {
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_408));
}
void function_410() {
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
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c105c114); /* __parse-pair */
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c115c101c113); /* __seq */
  apply((&function_409));
}
void function_411() {
  increment_count(env);
  val = new_function((&function_410), env);
  pop_function();
}
/* fn_95 */
void body_182() {
  increment_count(env);
  val = new_function((&function_411), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  return_location = (&body_183);
}
void body_184();
void function_412() {
  global_c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* __parse-pair */
  return_location = (&body_184);
}
/* __parse-pair */
void body_183() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  apply((&function_412));
}
void body_185();
pointer global_c102c110c95c57c54;
void function_413() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c108c121); /* __apply */
  top_level_apply();
}
void function_414() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c104c111c105c99c101); /* __choice */
  apply((&function_413));
}
void function_415() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_414));
}
void function_416() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_415));
}
void function_417() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_416));
}
void function_418() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_417));
}
void function_419() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c115c116c114c105c110c103); /* __parse-string */
  args = cons(val, args);
  increment_count(val = global_c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* __quote-parser */
  apply((&function_418));
}
void function_420() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_419));
}
void function_421() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_420));
}
void function_422() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c113c117c111c116c101c45c112c97c114c115c101c114); /* __quote-parser */
  apply((&function_421));
}
void function_423() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_422));
}
void function_424() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
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
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114); /* __quasiquote-parser */
  apply((&function_424));
}
void function_426() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_425));
}
void function_427() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_426));
}
void function_428() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114); /* __unquote-parser */
  apply((&function_427));
}
void function_429() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_428));
}
void function_430() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c112c97c105c114); /* __parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_429));
}
void function_431() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_430));
}
void function_432() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c102c97c105c108); /* __fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_431));
}
void function_433() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_432));
}
void function_434() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c102c97c105c108); /* __fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_433));
}
void function_435() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_434));
}
void function_436() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c95c109c97c116c99c104); /* __match */
  apply((&function_435));
}
void function_437() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c109c101c110c116); /* __comment */
  apply((&function_436));
}
void function_438() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c115c101); /* __case */
  apply((&function_437));
}
void function_439() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c101c101c107); /* __peek */
  apply((&function_438));
}
void function_440() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c114c101c97c100c45c110c117c109); /* __read-num */
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
  increment_count(val = global_c95c95c105c110c116c101c114c118c97c108); /* __interval */
  apply((&function_439));
}
void function_441() {
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
  increment_count(val = global_c95c95c114c101c97c100c45c115c121c109c98c111c108); /* __read-symbol */
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c97c117c108c116); /* __default */
  apply((&function_440));
}
void function_442() {
  increment_count(env);
  val = new_function((&function_441), env);
  pop_function();
}
/* fn_96 */
void body_184() {
  increment_count(env);
  val = new_function((&function_442), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  return_location = (&body_185);
}
void body_186();
void function_443() {
  global_c95c95c112c97c114c115c101c45c101c120c112c114 = val; /* __parse-expr */
  return_location = (&body_186);
}
/* __parse-expr */
void body_185() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  apply((&function_443));
}
void body_187();
pointer global_c95c108c95c50c52;
/* _l_24 */
void body_186() {
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
  global_c95c108c95c50c52 = val; /* _l_24 */
  return_location = (&body_187);
}
void body_188();
pointer global_c95c108c95c50c53;
/* _l_25 */
void body_187() {
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
  global_c95c108c95c50c53 = val; /* _l_25 */
  return_location = (&body_188);
}
void body_189();
pointer global_c95c108c95c50c54;
/* _l_26 */
void body_188() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c50c54 = val; /* _l_26 */
  return_location = (&body_189);
}
void body_190();
pointer global_c102c110c95c57c55 = NIL; /* fn_97 */
pointer global_c102c110c95c57c56;
void function_444() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c114c115c101c45c101c120c112c114); /* __parse-expr */
  top_level_apply();
}
void function_445() {
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
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  apply((&function_444));
}
void function_446() {
  increment_count(env);
  val = new_function((&function_445), env);
  pop_function();
}
/* fn_98 */
void body_189() {
  increment_count(env);
  val = new_function((&function_446), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  return_location = (&body_190);
}
void body_191();
pointer global_c95c95c112c114c105c110c116c45c110c117c109 = NIL; /* __print-num */
void function_447() {
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c101c114c114c111c114); /* __print-error */
  top_level_apply();
}
void function_448() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50c52); /* _l_24 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_447));
}
void function_449() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c50c53); /* _l_25 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c110c117c109); /* __print-num */
  apply((&function_448));
}
void function_450() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c50c54); /* _l_26 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c110c117c109); /* __print-num */
  apply((&function_449));
}
void function_451() {
  increment_count(env);
  val = new_function((&function_450), env);
  pop_function();
}
/* fn_97 */
void body_190() {
  increment_count(env);
  val = new_function((&function_451), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  return_location = (&body_191);
}
void body_192();
pointer global_c95c95c114c101c97c100c45c101c120c112c114;
void function_452() {
  global_c95c95c114c101c97c100c45c101c120c112c114 = val; /* __read-expr */
  return_location = (&body_192);
}
/* __read-expr */
void body_191() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  apply((&function_452));
}
void body_193();
pointer global_c102c110c95c49c48c52 = NIL; /* fn_104 */
pointer global_c102c110c95c49c48c51 = NIL; /* fn_103 */
pointer global_c102c110c95c49c48c49 = NIL; /* fn_101 */
pointer global_c102c110c95c49c48c48 = NIL; /* fn_100 */
pointer global_c102c110c95c57c57 = NIL; /* fn_99 */
pointer global_c102c110c95c49c48c53;
void function_453() {
  top_level_apply();
}
void function_454() {
  args = cons(val, args);
  increment_count(val = global_c95c95c119c97c108c107); /* __walk */
  apply((&function_453));
}
void function_455() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  apply((&function_454));
}
void function_456() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  apply((&function_455));
}
void function_457() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  apply((&function_456));
}
void function_458() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  apply((&function_457));
}
void function_459() {
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
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  apply((&function_458));
}
void function_460() {
  increment_count(env);
  val = new_function((&function_459), env);
  pop_function();
}
/* fn_105 */
void body_192() {
  increment_count(env);
  val = new_function((&function_460), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  return_location = (&body_193);
}
void body_194();
void function_461() {
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
void function_462() {
  increment_count(env);
  val = new_function((&function_461), env);
  pop_function();
}
/* fn_99 */
void body_193() {
  increment_count(env);
  val = new_function((&function_462), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  return_location = (&body_194);
}
void body_195();
void function_463() {
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
void function_464() {
  increment_count(env);
  val = new_function((&function_463), env);
  pop_function();
}
/* fn_100 */
void body_194() {
  increment_count(env);
  val = new_function((&function_464), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  return_location = (&body_195);
}
void body_196();
void function_465() {
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
void function_466() {
  increment_count(env);
  val = new_function((&function_465), env);
  pop_function();
}
/* fn_101 */
void body_195() {
  increment_count(env);
  val = new_function((&function_466), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  return_location = (&body_196);
}
void body_197();
pointer global_c102c110c95c49c48c50 = NIL; /* fn_102 */
void function_467() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  top_level_apply();
}
void function_468() {
  increment_count(env);
  val = new_function((&function_467), env);
  pop_function();
}
/* fn_103 */
void body_196() {
  increment_count(env);
  val = new_function((&function_468), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  return_location = (&body_197);
}
void body_198();
void function_469() {
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
void function_470() {
  increment_count(env);
  val = new_function((&function_469), env);
  pop_function();
}
/* fn_102 */
void body_197() {
  increment_count(env);
  val = new_function((&function_470), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  return_location = (&body_198);
}
void body_199();
void function_471() {
  increment_count(val = global_c95c95c105c100); /* __id */
  pop_function();
}
void function_472() {
  increment_count(env);
  val = new_function((&function_471), env);
  pop_function();
}
/* fn_104 */
void body_198() {
  increment_count(env);
  val = new_function((&function_472), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  return_location = (&body_199);
}
void body_200();
pointer global_c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
void function_473() {
  global_c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* __build-num-str */
  return_location = (&body_200);
}
/* __build-num-str */
void body_199() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  apply((&function_473));
}
void body_201();
pointer global_c95c108c95c50c55;
/* _l_27 */
void body_200() {
  val = NIL;
  global_c95c108c95c50c55 = val; /* _l_27 */
  return_location = (&body_201);
}
void body_202();
pointer global_c95c108c95c50c56;
/* _l_28 */
void body_201() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c50c56 = val; /* _l_28 */
  return_location = (&body_202);
}
void body_203();
pointer global_c95c108c95c50c57;
/* _l_29 */
void body_202() {
  val = NIL;
  global_c95c108c95c50c57 = val; /* _l_29 */
  return_location = (&body_203);
}
void body_204();
pointer global_c102c110c95c49c48c54;
void function_474() {
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
void function_475() {
  apply((&function_474));
}
void function_476() {
  top_level_apply();
}
void function_477() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c108c95c50c56); /* _l_28 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c50c57); /* _l_29 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* __build-num-str */
    apply((&function_476));
  }
}
void function_478() {
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
    increment_count(val = global_c95c108c95c50c55); /* _l_27 */
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
    increment_count(val = global_c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114); /* __build-num-str */
    apply((&function_475));
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    apply((&function_477));
  }
}
void function_479() {
  increment_count(env);
  val = new_function((&function_478), env);
  pop_function();
}
/* fn_106 */
void body_203() {
  increment_count(env);
  val = new_function((&function_479), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  return_location = (&body_204);
}
void body_205();
void function_480() {
  global_c95c95c112c114c105c110c116c45c110c117c109 = val; /* __print-num */
  return_location = (&body_205);
}
/* __print-num */
void body_204() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  apply((&function_480));
}
void body_206();
pointer global_c95c108c95c51c48;
/* _l_30 */
void body_205() {
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
  global_c95c108c95c51c48 = val; /* _l_30 */
  return_location = (&body_206);
}
void body_207();
pointer global_c102c110c95c49c48c55;
void function_481() {
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
    increment_count(val = global_c95c108c95c51c48); /* _l_30 */
    pop_function();
  }
}
void function_482() {
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
    increment_count(val = global_c95c95c112c114c105c110c116c45c110c117c109); /* __print-num */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    apply((&function_481));
  }
}
void function_483() {
  increment_count(env);
  val = new_function((&function_482), env);
  pop_function();
}
/* fn_107 */
void body_206() {
  increment_count(env);
  val = new_function((&function_483), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  return_location = (&body_207);
}
void body_208();
pointer global_c95c95c112c114c105c110c116c45c97c116c111c109;
void function_484() {
  global_c95c95c112c114c105c110c116c45c97c116c111c109 = val; /* __print-atom */
  return_location = (&body_208);
}
/* __print-atom */
void body_207() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  apply((&function_484));
}
void body_209();
pointer global_c95c108c95c51c49;
/* _l_31 */
void body_208() {
  val = NIL;
  global_c95c108c95c51c49 = val; /* _l_31 */
  return_location = (&body_209);
}
void body_210();
pointer global_c95c108c95c51c50;
/* _l_32 */
void body_209() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c51c50 = val; /* _l_32 */
  return_location = (&body_210);
}
void body_211();
pointer global_c95c108c95c51c51;
/* _l_33 */
void body_210() {
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
  global_c95c108c95c51c51 = val; /* _l_33 */
  return_location = (&body_211);
}
void body_212();
pointer global_c95c108c95c51c52;
/* _l_34 */
void body_211() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c51c52 = val; /* _l_34 */
  return_location = (&body_212);
}
void body_213();
pointer global_c95c108c95c51c53;
/* _l_35 */
void body_212() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c51c53 = val; /* _l_35 */
  return_location = (&body_213);
}
void body_214();
pointer global_c95c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* __print-tail */
pointer global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* __print-with-suffix */
pointer global_c102c110c95c49c48c56;
void function_485() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c51c51); /* _l_33 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  top_level_apply();
}
void function_486() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c51c53); /* _l_35 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  top_level_apply();
}
void function_487() {
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
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  apply((&function_486));
}
void function_488() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c51c52); /* _l_34 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c114c105c110c116c45c97c116c111c109); /* __print-atom */
    apply((&function_485));
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
    increment_count(val = global_c95c95c112c114c105c110c116c45c116c97c105c108); /* __print-tail */
    apply((&function_487));
  }
}
void function_489() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c51c50); /* _l_32 */
    args = cons(val, args);
    increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_488));
  }
}
void function_490() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c51c49); /* _l_31 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_489));
}
void function_491() {
  increment_count(env);
  val = new_function((&function_490), env);
  pop_function();
}
/* fn_108 */
void body_213() {
  increment_count(env);
  val = new_function((&function_491), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  return_location = (&body_214);
}
void body_215();
void function_492() {
  global_c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* __print-tail */
  return_location = (&body_215);
}
/* __print-tail */
void body_214() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  apply((&function_492));
}
void body_216();
pointer global_c95c108c95c51c54;
/* _l_36 */
void body_215() {
  val = NIL;
  global_c95c108c95c51c54 = val; /* _l_36 */
  return_location = (&body_216);
}
void body_217();
pointer global_c95c108c95c51c55;
/* _l_37 */
void body_216() {
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
  global_c95c108c95c51c55 = val; /* _l_37 */
  return_location = (&body_217);
}
void body_218();
pointer global_c95c108c95c51c56;
/* _l_38 */
void body_217() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c51c56 = val; /* _l_38 */
  return_location = (&body_218);
}
void body_219();
pointer global_c102c110c95c49c48c57;
void function_493() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  top_level_apply();
}
void function_494() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c51c56); /* _l_38 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  top_level_apply();
}
void function_495() {
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
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  apply((&function_494));
}
void function_496() {
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
    increment_count(val = global_c95c95c112c114c105c110c116c45c97c116c111c109); /* __print-atom */
    apply((&function_493));
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
    increment_count(val = global_c95c95c112c114c105c110c116c45c116c97c105c108); /* __print-tail */
    apply((&function_495));
  }
}
void function_497() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c51c55); /* _l_37 */
    args = cons(val, args);
    increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_496));
  }
}
void function_498() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c51c54); /* _l_36 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_497));
}
void function_499() {
  increment_count(env);
  val = new_function((&function_498), env);
  pop_function();
}
/* fn_109 */
void body_218() {
  increment_count(env);
  val = new_function((&function_499), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  return_location = (&body_219);
}
void body_220();
void function_500() {
  global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* __print-with-suffix */
  return_location = (&body_220);
}
/* __print-with-suffix */
void body_219() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  apply((&function_500));
}
void body_221();
pointer global_c95c108c95c51c57;
/* _l_39 */
void body_220() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c51c57 = val; /* _l_39 */
  return_location = (&body_221);
}
void body_222();
pointer global_c102c110c95c49c49c48;
void function_501() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c51c57); /* _l_39 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  top_level_apply();
}
void function_502() {
  increment_count(env);
  val = new_function((&function_501), env);
  pop_function();
}
/* fn_110 */
void body_221() {
  increment_count(env);
  val = new_function((&function_502), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  return_location = (&body_222);
}
void body_223();
pointer global_c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
void function_503() {
  global_c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* __print-with-newline */
  return_location = (&body_223);
}
/* __print-with-newline */
void body_222() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  apply((&function_503));
}
void body_224();
pointer global_c95c108c95c52c48;
/* _l_40 */
void body_223() {
  val = NIL;
  global_c95c108c95c52c48 = val; /* _l_40 */
  return_location = (&body_224);
}
void body_225();
pointer global_c102c110c95c49c49c49;
void function_504() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c52c48); /* _l_40 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  top_level_apply();
}
void function_505() {
  increment_count(env);
  val = new_function((&function_504), env);
  pop_function();
}
/* fn_111 */
void body_224() {
  increment_count(env);
  val = new_function((&function_505), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  return_location = (&body_225);
}
void body_226();
void function_506() {
  global_c95c95c112c114c105c110c116 = val; /* __print */
  return_location = (&body_226);
}
/* __print */
void body_225() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  apply((&function_506));
}
void body_227();
pointer global_c95c108c95c52c49;
/* _l_41 */
void body_226() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c52c49 = val; /* _l_41 */
  return_location = (&body_227);
}
void body_228();
pointer global_c102c110c95c49c49c50;
void function_507() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_508() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c52c49); /* _l_41 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_507));
}
void function_509() {
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
  increment_count(val = global_c95c95c112c114c105c110c116c45c110c117c109); /* __print-num */
  apply((&function_508));
}
void function_510() {
  increment_count(env);
  val = new_function((&function_509), env);
  pop_function();
}
/* fn_112 */
void body_227() {
  increment_count(env);
  val = new_function((&function_510), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  return_location = (&body_228);
}
void body_229();
pointer global_c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
void function_511() {
  global_c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* __number->symbol */
  return_location = (&body_229);
}
/* __number->symbol */
void body_228() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  apply((&function_511));
}
void body_230();
pointer global_c95c108c95c52c50;
/* _l_42 */
void body_229() {
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
  global_c95c108c95c52c50 = val; /* _l_42 */
  return_location = (&body_230);
}
void body_231();
pointer global_c95c95c98c117c105c108c116c105c110c115;
/* __builtins */
void body_230() {
  increment_count(val = global_c95c108c95c52c50); /* _l_42 */
  global_c95c95c98c117c105c108c116c105c110c115 = val; /* __builtins */
  return_location = (&body_231);
}
void body_232();
pointer global_c95c108c95c52c51;
/* _l_43 */
void body_231() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c52c51 = val; /* _l_43 */
  return_location = (&body_232);
}
void body_233();
pointer global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* __escape-symbols */
pointer global_c102c110c95c49c49c51;
void function_512() {
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  top_level_apply();
}
void function_513() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c52c51); /* _l_43 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_512));
}
void function_514() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_515() {
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
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_514));
}
void function_516() {
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
    increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
    apply((&function_515));
  }
}
void function_517() {
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
    apply((&function_513));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_516));
  }
}
void function_518() {
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
    apply((&function_517));
  }
}
void function_519() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c98c117c105c108c116c105c110c115); /* __builtins */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c109c101c109c98c101c114); /* __member */
  apply((&function_518));
}
void function_520() {
  increment_count(env);
  val = new_function((&function_519), env);
  pop_function();
}
/* fn_113 */
void body_232() {
  increment_count(env);
  val = new_function((&function_520), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  return_location = (&body_233);
}
void body_234();
void function_521() {
  global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* __escape-symbols */
  return_location = (&body_234);
}
/* __escape-symbols */
void body_233() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  apply((&function_521));
}
void body_235();
pointer global_c95c108c95c52c52;
/* _l_44 */
void body_234() {
  val = NIL;
  global_c95c108c95c52c52 = val; /* _l_44 */
  return_location = (&body_235);
}
void body_236();
pointer global_c95c95c102c108c97c116c116c101c110 = NIL; /* __flatten */
pointer global_c102c110c95c49c49c52;
void function_522() {
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
  increment_count(val = global_c95c95c102c108c97c116c116c101c110); /* __flatten */
  top_level_apply();
}
void function_523() {
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
    increment_count(val = global_c95c95c102c108c97c116c116c101c110); /* __flatten */
    apply((&function_522));
  }
}
void function_524() {
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
    apply((&function_523));
  }
}
void function_525() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c52c52); /* _l_44 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  apply((&function_524));
}
void function_526() {
  increment_count(env);
  val = new_function((&function_525), env);
  pop_function();
}
/* fn_114 */
void body_235() {
  increment_count(env);
  val = new_function((&function_526), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  return_location = (&body_236);
}
void body_237();
void function_527() {
  global_c95c95c102c108c97c116c116c101c110 = val; /* __flatten */
  return_location = (&body_237);
}
/* __flatten */
void body_236() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  apply((&function_527));
}
void body_238();
pointer global_c102c110c95c49c49c53 = NIL; /* fn_115 */
pointer global_c102c110c95c49c49c54;
void function_528() {
  top_level_apply();
}
void function_529() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_528));
}
void function_530() {
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
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  apply((&function_529));
}
void function_531() {
  increment_count(env);
  val = new_function((&function_530), env);
  pop_function();
}
/* fn_116 */
void body_237() {
  increment_count(env);
  val = new_function((&function_531), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  return_location = (&body_238);
}
void body_239();
void function_532() {
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
void function_533() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c109c101c109c98c101c114); /* __member */
  apply((&function_532));
}
void function_534() {
  increment_count(env);
  val = new_function((&function_533), env);
  pop_function();
}
/* fn_115 */
void body_238() {
  increment_count(env);
  val = new_function((&function_534), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  return_location = (&body_239);
}
void body_240();
pointer global_c95c95c109c101c114c103c101;
void function_535() {
  global_c95c95c109c101c114c103c101 = val; /* __merge */
  return_location = (&body_240);
}
/* __merge */
void body_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  apply((&function_535));
}
void body_241();
pointer global_c95c108c95c52c53;
/* _l_45 */
void body_240() {
  val = NIL;
  global_c95c108c95c52c53 = val; /* _l_45 */
  return_location = (&body_241);
}
void body_242();
pointer global_c102c110c95c49c49c55 = NIL; /* fn_117 */
pointer global_c102c110c95c49c49c56;
void function_536() {
  top_level_apply();
}
void function_537() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_536));
}
void function_538() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c52c53); /* _l_45 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  apply((&function_537));
}
void function_539() {
  increment_count(env);
  val = new_function((&function_538), env);
  pop_function();
}
/* fn_118 */
void body_241() {
  increment_count(env);
  val = new_function((&function_539), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  return_location = (&body_242);
}
void body_243();
void function_540() {
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
void function_541() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c109c101c109c98c101c114); /* __member */
  apply((&function_540));
}
void function_542() {
  increment_count(env);
  val = new_function((&function_541), env);
  pop_function();
}
/* fn_117 */
void body_242() {
  increment_count(env);
  val = new_function((&function_542), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  return_location = (&body_243);
}
void body_244();
pointer global_c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116;
void function_543() {
  global_c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116 = val; /* __subtract-list */
  return_location = (&body_244);
}
/* __subtract-list */
void body_243() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  apply((&function_543));
}
void body_245();
pointer global_c102c110c95c49c49c57 = NIL; /* fn_119 */
pointer global_c102c110c95c49c50c48;
void function_544() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  top_level_apply();
}
void function_545() {
  increment_count(env);
  val = new_function((&function_544), env);
  pop_function();
}
/* fn_120 */
void body_244() {
  increment_count(env);
  val = new_function((&function_545), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  return_location = (&body_245);
}
void body_246();
void function_546() {
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
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_547() {
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
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_546));
}
void function_548() {
  increment_count(env);
  val = new_function((&function_547), env);
  pop_function();
}
/* fn_119 */
void body_245() {
  increment_count(env);
  val = new_function((&function_548), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  return_location = (&body_246);
}
void body_247();
pointer global_c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110;
void function_549() {
  global_c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110 = val; /* __definition-return */
  return_location = (&body_247);
}
/* __definition-return */
void body_246() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  apply((&function_549));
}
void body_248();
pointer global_c95c108c95c52c54;
/* _l_46 */
void body_247() {
  val = NIL;
  global_c95c108c95c52c54 = val; /* _l_46 */
  return_location = (&body_248);
}
void body_249();
pointer global_c95c108c95c52c55;
/* _l_47 */
void body_248() {
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
  global_c95c108c95c52c55 = val; /* _l_47 */
  return_location = (&body_249);
}
void body_250();
pointer global_c102c110c95c49c50c53 = NIL; /* fn_125 */
pointer global_c102c110c95c49c50c54;
void function_550() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  top_level_apply();
}
void function_551() {
  increment_count(env);
  val = new_function((&function_550), env);
  pop_function();
}
/* fn_126 */
void body_249() {
  increment_count(env);
  val = new_function((&function_551), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  return_location = (&body_250);
}
void body_251();
pointer global_c102c110c95c49c50c52 = NIL; /* fn_124 */
void function_552() {
  top_level_apply();
}
void function_553() {
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
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  apply((&function_552));
}
void function_554() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c52c55); /* _l_47 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_553));
}
void function_555() {
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
  increment_count(val = global_c95c95c112c114c105c110c116c45c110c117c109); /* __print-num */
  apply((&function_554));
}
void function_556() {
  increment_count(env);
  val = new_function((&function_555), env);
  pop_function();
}
/* fn_125 */
void body_250() {
  increment_count(env);
  val = new_function((&function_556), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  return_location = (&body_251);
}
void body_252();
pointer global_c102c110c95c49c50c51 = NIL; /* fn_123 */
void function_557() {
  top_level_apply();
}
void function_558() {
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
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  apply((&function_557));
}
void function_559() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  apply((&function_558));
}
void function_560() {
  increment_count(env);
  val = new_function((&function_559), env);
  pop_function();
}
/* fn_124 */
void body_251() {
  increment_count(env);
  val = new_function((&function_560), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  return_location = (&body_252);
}
void body_253();
pointer global_c102c110c95c49c50c50 = NIL; /* fn_122 */
void function_561() {
  top_level_apply();
}
void function_562() {
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
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  apply((&function_561));
}
void function_563() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c108c95c52c54); /* _l_46 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c102c108c97c116c116c101c110); /* __flatten */
  apply((&function_562));
}
void function_564() {
  increment_count(env);
  val = new_function((&function_563), env);
  pop_function();
}
/* fn_123 */
void body_252() {
  increment_count(env);
  val = new_function((&function_564), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  return_location = (&body_253);
}
void body_254();
pointer global_c102c110c95c49c50c49 = NIL; /* fn_121 */
void function_565() {
  top_level_apply();
}
void function_566() {
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
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  apply((&function_565));
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
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116); /* __subtract-list */
  apply((&function_566));
}
void function_568() {
  increment_count(env);
  val = new_function((&function_567), env);
  pop_function();
}
/* fn_122 */
void body_253() {
  increment_count(env);
  val = new_function((&function_568), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  return_location = (&body_254);
}
void body_255();
void function_569() {
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
void function_570() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -36;
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
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_569));
}
void function_571() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -36;
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
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_570));
}
void function_572() {
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
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_571));
}
void function_573() {
  increment_count(env);
  val = new_function((&function_572), env);
  pop_function();
}
/* fn_121 */
void body_254() {
  increment_count(env);
  val = new_function((&function_573), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  return_location = (&body_255);
}
void body_256();
pointer global_c95c95c102c110c45c114c101c116c117c114c110;
void function_574() {
  global_c95c95c102c110c45c114c101c116c117c114c110 = val; /* __fn-return */
  return_location = (&body_256);
}
/* __fn-return */
void body_255() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  apply((&function_574));
}
void body_257();
pointer global_c102c110c95c49c50c55 = NIL; /* fn_127 */
pointer global_c102c110c95c49c50c56;
void function_575() {
  top_level_apply();
}
void function_576() {
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
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  apply((&function_575));
}
void function_577() {
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
  increment_count(val = global_c95c95c102c108c97c116c116c101c110); /* __flatten */
  apply((&function_576));
}
void function_578() {
  increment_count(env);
  val = new_function((&function_577), env);
  pop_function();
}
/* fn_128 */
void body_256() {
  increment_count(env);
  val = new_function((&function_578), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  return_location = (&body_257);
}
void body_258();
pointer global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* __extract-definitions */
void function_579() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  top_level_apply();
}
void function_580() {
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
  increment_count(val = global_c95c95c102c110c45c114c101c116c117c114c110); /* __fn-return */
  apply((&function_579));
}
void function_581() {
  increment_count(env);
  val = new_function((&function_580), env);
  pop_function();
}
/* fn_127 */
void body_257() {
  increment_count(env);
  val = new_function((&function_581), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  return_location = (&body_258);
}
void body_259();
pointer global_c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115;
void function_582() {
  global_c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115 = val; /* __fn-defintions */
  return_location = (&body_259);
}
/* __fn-defintions */
void body_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  apply((&function_582));
}
void body_260();
pointer global_c102c110c95c49c51c48 = NIL; /* fn_130 */
pointer global_c102c110c95c49c51c49;
void function_583() {
  top_level_apply();
}
void function_584() {
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
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  apply((&function_583));
}
void function_585() {
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
    increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c105c115c116); /* __list */
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
    increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
    apply((&function_584));
  }
}
void function_586() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_585));
}
void function_587() {
  increment_count(env);
  val = new_function((&function_586), env);
  pop_function();
}
/* fn_131 */
void body_259() {
  increment_count(env);
  val = new_function((&function_587), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  return_location = (&body_260);
}
void body_261();
pointer global_c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* __args-definitions */
pointer global_c102c110c95c49c50c57 = NIL; /* fn_129 */
void function_588() {
  top_level_apply();
}
void function_589() {
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
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  apply((&function_588));
}
void function_590() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
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
  increment_count(val = global_c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* __args-definitions */
  apply((&function_589));
}
void function_591() {
  increment_count(env);
  val = new_function((&function_590), env);
  pop_function();
}
/* fn_130 */
void body_260() {
  increment_count(env);
  val = new_function((&function_591), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  return_location = (&body_261);
}
void body_262();
void function_592() {
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
void function_593() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c109c101c114c103c101); /* __merge */
  apply((&function_592));
}
void function_594() {
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
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_593));
}
void function_595() {
  increment_count(env);
  val = new_function((&function_594), env);
  pop_function();
}
/* fn_129 */
void body_261() {
  increment_count(env);
  val = new_function((&function_595), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  return_location = (&body_262);
}
void body_263();
void function_596() {
  global_c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* __args-definitions */
  return_location = (&body_263);
}
/* __args-definitions */
void body_262() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  apply((&function_596));
}
void body_264();
pointer global_c95c108c95c52c56;
/* _l_48 */
void body_263() {
  val = NIL;
  global_c95c108c95c52c56 = val; /* _l_48 */
  return_location = (&body_264);
}
void body_265();
pointer global_c95c108c95c52c57;
/* _l_49 */
void body_264() {
  val = NIL;
  global_c95c108c95c52c57 = val; /* _l_49 */
  return_location = (&body_265);
}
void body_266();
pointer global_c95c108c95c53c48;
/* _l_50 */
void body_265() {
  val = NIL;
  global_c95c108c95c53c48 = val; /* _l_50 */
  return_location = (&body_266);
}
void body_267();
pointer global_c95c108c95c53c49;
/* _l_51 */
void body_266() {
  val = NIL;
  global_c95c108c95c53c49 = val; /* _l_51 */
  return_location = (&body_267);
}
void body_268();
pointer global_c95c108c95c53c50;
/* _l_52 */
void body_267() {
  val = -37;
  global_c95c108c95c53c50 = val; /* _l_52 */
  return_location = (&body_268);
}
void body_269();
pointer global_c95c108c95c53c51;
/* _l_53 */
void body_268() {
  val = NIL;
  global_c95c108c95c53c51 = val; /* _l_53 */
  return_location = (&body_269);
}
void body_270();
pointer global_c95c108c95c53c52;
/* _l_54 */
void body_269() {
  val = NIL;
  global_c95c108c95c53c52 = val; /* _l_54 */
  return_location = (&body_270);
}
void body_271();
pointer global_c95c108c95c53c53;
/* _l_55 */
void body_270() {
  val = -34;
  global_c95c108c95c53c53 = val; /* _l_55 */
  return_location = (&body_271);
}
void body_272();
pointer global_c95c108c95c53c54;
/* _l_56 */
void body_271() {
  val = -36;
  global_c95c108c95c53c54 = val; /* _l_56 */
  return_location = (&body_272);
}
void body_273();
pointer global_c95c108c95c53c55;
/* _l_57 */
void body_272() {
  val = -35;
  global_c95c108c95c53c55 = val; /* _l_57 */
  return_location = (&body_273);
}
void body_274();
pointer global_c102c110c95c49c51c52 = NIL; /* fn_134 */
pointer global_c102c110c95c49c51c53;
void function_597() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  top_level_apply();
}
void function_598() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
  apply((&function_597));
}
void function_599() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c108c105c115c116); /* __list */
    apply((&function_598));
  } else {
    increment_count(val = global_c95c108c95c52c56); /* _l_48 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* __escape-symbols */
    apply((&function_597));
  }
}
void function_600() {
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  top_level_apply();
}
void function_601() {
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
  increment_count(val = global_c95c95c99c97c100c100c114); /* __caddr */
  apply((&function_600));
}
void function_602() {
  args = cons(val, args);
  increment_count(val = global_c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110); /* __definition-return */
  apply((&function_601));
}
void function_603() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115); /* __fn-defintions */
  top_level_apply();
}
void function_604() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c100c114); /* __cadr */
  apply((&function_603));
}
void function_605() {
  top_level_apply();
}
void function_606() {
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
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  apply((&function_605));
}
void function_607() {
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  apply((&function_606));
}
void function_608() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c108c105c115c116); /* __list */
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
    increment_count(val = global_c95c95c99c97c100c114); /* __cadr */
    apply((&function_607));
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
    increment_count(val = global_c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* __args-definitions */
    top_level_apply();
  }
}
void function_609() {
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
    increment_count(val = global_c95c95c99c97c100c100c114); /* __caddr */
    apply((&function_604));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c53c55); /* _l_57 */
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
    apply((&function_608));
  }
}
void function_610() {
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
    increment_count(val = global_c95c95c99c97c100c114); /* __cadr */
    apply((&function_602));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c53c54); /* _l_56 */
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
    apply((&function_609));
  }
}
void function_611() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c53c52); /* _l_54 */
    args = cons(val, args);
    increment_count(val = global_c95c108c95c53c51); /* _l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c53c53); /* _l_55 */
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
    apply((&function_610));
  }
}
void function_612() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c53c49); /* _l_51 */
    args = cons(val, args);
    increment_count(val = global_c95c108c95c53c48); /* _l_50 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c53c50); /* _l_52 */
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
    apply((&function_611));
  }
}
void function_613() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c108c95c52c57); /* _l_49 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c109c101c109c98c101c114); /* __member */
    apply((&function_599));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    apply((&function_612));
  }
}
void function_614() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  apply((&function_613));
}
void function_615() {
  increment_count(env);
  val = new_function((&function_614), env);
  pop_function();
}
/* fn_135 */
void body_273() {
  increment_count(env);
  val = new_function((&function_615), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  return_location = (&body_274);
}
void body_275();
pointer global_c102c110c95c49c51c51 = NIL; /* fn_133 */
void function_616() {
  top_level_apply();
}
void function_617() {
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
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  apply((&function_616));
}
void function_618() {
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  apply((&function_617));
}
void function_619() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
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
  increment_count(val = global_c95c95c99c97c100c100c114); /* __caddr */
  apply((&function_618));
}
void function_620() {
  increment_count(env);
  val = new_function((&function_619), env);
  pop_function();
}
/* fn_134 */
void body_274() {
  increment_count(env);
  val = new_function((&function_620), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  return_location = (&body_275);
}
void body_276();
pointer global_c102c110c95c49c51c50 = NIL; /* fn_132 */
void function_621() {
  top_level_apply();
}
void function_622() {
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
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  apply((&function_621));
}
void function_623() {
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  apply((&function_622));
}
void function_624() {
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c100c114); /* __cadr */
  apply((&function_623));
}
void function_625() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c108c105c115c116); /* __list */
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
  increment_count(val = global_c95c95c99c100c100c114); /* __cddr */
  apply((&function_624));
}
void function_626() {
  increment_count(env);
  val = new_function((&function_625), env);
  pop_function();
}
/* fn_133 */
void body_275() {
  increment_count(env);
  val = new_function((&function_626), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  return_location = (&body_276);
}
void body_277();
void function_627() {
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
void function_628() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c109c101c114c103c101); /* __merge */
  apply((&function_627));
}
void function_629() {
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
  increment_count(val = global_c95c95c109c101c114c103c101); /* __merge */
  apply((&function_628));
}
void function_630() {
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
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_629));
}
void function_631() {
  increment_count(env);
  val = new_function((&function_630), env);
  pop_function();
}
/* fn_132 */
void body_276() {
  increment_count(env);
  val = new_function((&function_631), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  return_location = (&body_277);
}
void body_278();
void function_632() {
  global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* __extract-definitions */
  return_location = (&body_278);
}
/* __extract-definitions */
void body_277() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  apply((&function_632));
}
void body_279();
pointer global_c95c108c95c53c56;
/* _l_58 */
void body_278() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c53c56 = val; /* _l_58 */
  return_location = (&body_279);
}
void body_280();
pointer global_c95c108c95c53c57;
/* _l_59 */
void body_279() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c53c57 = val; /* _l_59 */
  return_location = (&body_280);
}
void body_281();
pointer global_c102c110c95c49c51c55 = NIL; /* fn_137 */
pointer global_c102c110c95c49c51c56;
void function_633() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  top_level_apply();
}
void function_634() {
  increment_count(env);
  val = new_function((&function_633), env);
  pop_function();
}
/* fn_138 */
void body_280() {
  increment_count(env);
  val = new_function((&function_634), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  return_location = (&body_281);
}
void body_282();
pointer global_c102c110c95c49c51c54 = NIL; /* fn_136 */
void function_635() {
  top_level_apply();
}
void function_636() {
  args = cons(val, args);
  increment_count(val = global_c95c95c102c111c108c100c114); /* __foldr */
  apply((&function_635));
}
void function_637() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  apply((&function_636));
}
void function_638() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  apply((&function_637));
}
void function_639() {
  args = cons(val, args);
  increment_count(val = global_c95c108c95c53c57); /* _l_59 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_638));
}
void function_640() {
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_639));
}
void function_641() {
  increment_count(env);
  val = new_function((&function_640), env);
  pop_function();
}
/* fn_137 */
void body_281() {
  increment_count(env);
  val = new_function((&function_641), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  return_location = (&body_282);
}
void body_283();
void function_642() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* __print-with-suffix */
  top_level_apply();
}
void function_643() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c53c56); /* _l_58 */
  args = cons(val, args);
  increment_count(val = global_c95c95c97c112c112c101c110c100); /* __append */
  apply((&function_642));
}
void function_644() {
  increment_count(env);
  val = new_function((&function_643), env);
  pop_function();
}
/* fn_136 */
void body_282() {
  increment_count(env);
  val = new_function((&function_644), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  return_location = (&body_283);
}
void body_284();
pointer global_c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110;
void function_645() {
  global_c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110 = val; /* __statement-return */
  return_location = (&body_284);
}
/* __statement-return */
void body_283() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  apply((&function_645));
}
void body_285();
pointer global_c95c108c95c54c48;
/* _l_60 */
void body_284() {
  val = NIL;
  global_c95c108c95c54c48 = val; /* _l_60 */
  return_location = (&body_285);
}
void body_286();
pointer global_c102c110c95c49c51c57;
void function_646() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c95c54c48); /* _l_60 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* __extract-definitions */
  top_level_apply();
}
void function_647() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110); /* __statement-return */
  apply((&function_646));
}
void function_648() {
  increment_count(env);
  val = new_function((&function_647), env);
  pop_function();
}
/* fn_139 */
void body_285() {
  increment_count(env);
  val = new_function((&function_648), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  return_location = (&body_286);
}
void body_287();
pointer global_c95c95c99c111c109c112c105c108c101;
void function_649() {
  global_c95c95c99c111c109c112c105c108c101 = val; /* __compile */
  return_location = (&body_287);
}
/* __compile */
void body_286() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c57); /* fn_139 */
  apply((&function_649));
}
void body_288();
pointer global_c95c108c95c54c49;
/* _l_61 */
void body_287() {
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
  global_c95c108c95c54c49 = val; /* _l_61 */
  return_location = (&body_288);
}
void body_289();
pointer global_c95c108c95c54c50;
/* _l_62 */
void body_288() {
  val = -34;
  global_c95c108c95c54c50 = val; /* _l_62 */
  return_location = (&body_289);
}
void body_290();
pointer global_c95c108c95c54c51;
/* _l_63 */
void body_289() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c108c95c54c51 = val; /* _l_63 */
  return_location = (&body_290);
}
void body_291();
pointer global_c95c108c95c54c52;
/* _l_64 */
void body_290() {
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
  global_c95c108c95c54c52 = val; /* _l_64 */
  return_location = (&body_291);
}
void body_292();
pointer global_c102c110c95c49c52c50 = NIL; /* fn_142 */
pointer global_c102c110c95c49c52c51;
void function_650() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  top_level_apply();
}
void function_651() {
  increment_count(env);
  val = new_function((&function_650), env);
  pop_function();
}
/* fn_143 */
void body_291() {
  increment_count(env);
  val = new_function((&function_651), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  return_location = (&body_292);
}
void body_293();
pointer global_c102c110c95c49c52c49 = NIL; /* fn_141 */
pointer global_c102c110c95c49c52c48 = NIL; /* fn_140 */
void function_652() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c112c105c108c101); /* __compile */
  top_level_apply();
}
void function_653() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c99c111c109c112c105c108c101); /* __compile */
  top_level_apply();
}
void function_654() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c54c52); /* _l_64 */
    args = cons(val, args);
    increment_count(val = global_c95c95c112c114c105c110c116c45c101c114c114c111c114); /* __print-error */
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
    increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
    apply((&function_653));
  }
}
void function_655() {
  args = cons(val, args);
  increment_count(val = global_c95c95c110c111c116); /* __not */
  apply((&function_654));
}
void function_656() {
  args = cons(val, args);
  increment_count(val = global_c95c95c111c114); /* __or */
  apply((&function_655));
}
void function_657() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_656));
}
void function_658() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c99c97c100c114); /* __cadr */
  apply((&function_657));
}
void function_659() {
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  apply((&function_658));
}
void function_660() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
    apply((&function_652));
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
    increment_count(val = global_c95c95c99c97c97c100c114); /* __caadr */
    apply((&function_659));
  }
}
void function_661() {
  args = cons(val, args);
  increment_count(val = global_c95c95c110c111c116); /* __not */
  apply((&function_660));
}
void function_662() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c54c49); /* _l_61 */
    args = cons(val, args);
    increment_count(val = global_c95c95c112c114c105c110c116c45c101c114c114c111c114); /* __print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c108c95c54c50); /* _l_62 */
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
    apply((&function_661));
  }
}
void function_663() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c110c111c116); /* __not */
  apply((&function_662));
}
void function_664() {
  increment_count(env);
  val = new_function((&function_663), env);
  pop_function();
}
/* fn_142 */
void body_292() {
  increment_count(env);
  val = new_function((&function_664), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  return_location = (&body_293);
}
void body_294();
void function_665() {
  increment_count(val = global_c95c108c95c54c51); /* _l_63 */
  pop_function();
}
void function_666() {
  increment_count(env);
  val = new_function((&function_665), env);
  pop_function();
}
/* fn_140 */
void body_293() {
  increment_count(env);
  val = new_function((&function_666), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  return_location = (&body_294);
}
void body_295();
pointer global_c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* __compile-source */
void function_667() {
  args = cons(val, args);
  increment_count(val = global_c95c95c114c101c97c100c45c101c120c112c114); /* __read-expr */
  top_level_apply();
}
void function_668() {
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
  increment_count(val = global_c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* __compile-source */
  apply((&function_667));
}
void function_669() {
  increment_count(env);
  val = new_function((&function_668), env);
  pop_function();
}
/* fn_141 */
void body_294() {
  increment_count(env);
  val = new_function((&function_669), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  return_location = (&body_295);
}
void body_296();
void function_670() {
  global_c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* __compile-source */
  return_location = (&body_296);
}
/* __compile-source */
void body_295() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  apply((&function_670));
}
void body_297();
pointer global_c102c110c95c49c52c52;
void function_671() {
  args = cons(val, args);
  increment_count(val = global_c95c95c114c101c97c100c45c101c120c112c114); /* __read-expr */
  top_level_apply();
}
void function_672() {
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
  increment_count(val = global_c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* __compile-source */
  apply((&function_671));
}
void function_673() {
  increment_count(env);
  val = new_function((&function_672), env);
  pop_function();
}
/* fn_144 */
void body_296() {
  increment_count(env);
  val = new_function((&function_673), env);
  global_c102c110c95c49c52c52 = val; /* fn_144 */
  return_location = (&body_297);
}
void function_674() {
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
void body_297() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c52); /* fn_144 */
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
    call_stack = cons(new_function((&function_674), NIL), call_stack);
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
  call_stack = cons(new_function((&function_674), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
