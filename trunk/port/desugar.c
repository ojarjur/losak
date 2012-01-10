#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#include "io.h"
#include "mem.h"
#include "eval.h"
pointer arguments = NIL;
int return_value = 0;
function_addr target, return_location;
pointer val, args, stack, call_stack, env, temp, true;
int sign_mask;
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
int build_sign_mask() {
  int sign_mask;
  int t = sign_mask = -1;
  while (t < 0) {
    sign_mask = t;
    t = t << 1;
  }
  return sign_mask;
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
pointer wrap_function(void* ptr, pointer env) {
  return cons(FUN, cons(new_number((pointer)ptr),
                        env));
}
void* function_target(pointer ptr, void* end_addr) {
  return is_function(ptr)?
      (void*)value(head(tail(ptr))):end_addr;
}
pointer function_environment(pointer ptr) {
  return tail(tail(ptr));
}
#ifdef BARE_HARDWARE
void main(unsigned long magic,
          multiboot_data* boot_data) {
#else
int main(int argc, char** argv) {
#endif
  target = &&end_function_addr;
  sign_mask = build_sign_mask();
  val = args = stack = call_stack = env = temp = NIL;
#ifdef BARE_HARDWARE
  int i = 0;
  if ((magic != BOOT_MAGIC) ||
      !getFlag(boot_data->flags, 0)) {
    error(ERR_BAD_BOOT);
    return;
  }
  init_mem((void*)0x500000,
           ((boot_data->mem_upper*1024) - 0x400000));
  init_io();
  arguments = get_cmd(
      boot_data->flags,
      (char*)(boot_data->cmd_line));
#else
  pointer memory_limit = 64 * 1024 * 1024;
  void* memory = malloc(memory_limit);
  init_mem(memory, memory_limit);
  init_io();
  arguments = NIL;
  int i;
  for (i = argc - 1; i >= 0; i--) {
    arguments = cons(make_string(argv[i]),
                     arguments);
  }
#endif
  goto start_addr;
pointer global_c95c101c113c117c97c108; /* _equal */
pointer global_c102c110c95c48;
function_0:
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
    goto top_level_apply;
  } else {
    val = NIL;
    goto pop_function;
  }
function_1:
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
    goto pop_function;
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
      goto pop_function;
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
      target = (&&function_0);
      goto apply_addr;
    }
  }
function_2:
  increment_count(env);
  val = wrap_function((&&function_1), env);
  goto pop_function;
/* fn_0 */
body_0:
global_c95c101c113c117c97c108 = NIL; /* _equal */
  increment_count(env);
  val = wrap_function((&&function_2), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_1;
function_3:
  global_c95c101c113c117c97c108 = val; /* _equal */
  goto body_2;
/* _equal */
body_1:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c48); /* fn_0 */
  target = (&&function_3);
  goto apply_addr;
pointer global_c102c110c95c49;
function_4:
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
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_5:
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
      goto pop_function;
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
        goto pop_function;
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
          goto pop_function;
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
            goto pop_function;
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
              goto pop_function;
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
                goto pop_function;
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
                  goto pop_function;
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
                    goto pop_function;
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
                      goto pop_function;
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
                        goto pop_function;
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
                          goto pop_function;
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
                            goto pop_function;
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
                              goto pop_function;
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
                                goto pop_function;
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
                                  goto pop_function;
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
                                    goto pop_function;
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
                                      goto pop_function;
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
                                        goto pop_function;
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
                                          goto pop_function;
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
                                            goto pop_function;
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
                                              goto pop_function;
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
                                                goto pop_function;
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
                                                  goto pop_function;
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
                                                    goto pop_function;
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
                                                      goto pop_function;
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
                                                        goto pop_function;
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
                                                          goto pop_function;
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
                                                            goto pop_function;
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
                                                              goto pop_function;
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
                                                                goto pop_function;
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
                                                                  goto pop_function;
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
                                                                    goto pop_function;
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
                                                                      goto pop_function;
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
                                                                        goto pop_function;
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
                                                                          goto pop_function;
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
                                                                            goto pop_function;
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
                                                                              goto pop_function;
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
                                                                                goto pop_function;
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
                                                                                  goto pop_function;
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
                                                                                    goto pop_function;
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
                                                                                      goto pop_function;
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
                                                                                        goto pop_function;
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
                                                                                          goto pop_function;
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
                                                                                            goto pop_function;
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
                                                                                              goto pop_function;
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
                                                                                                goto pop_function;
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
                                                                                                  goto pop_function;
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
                                                                                                    goto pop_function;
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
                                                                                                      goto pop_function;
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
                                                                                                        goto pop_function;
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
                                                                                                          goto pop_function;
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
                                                                                                            goto pop_function;
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
                                                                                                              goto pop_function;
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
                                                                                                                goto pop_function;
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
                                                                                                                  goto pop_function;
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
                                                                                                                    goto pop_function;
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
                                                                                                                      goto pop_function;
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
                                                                                                                        goto pop_function;
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
                                                                                                                          goto pop_function;
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
                                                                                                                            goto pop_function;
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
                                                                                                                              goto pop_function;
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
                                                                                                                                goto pop_function;
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
                                                                                                                                  goto pop_function;
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
                                                                                                                                    goto pop_function;
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
                                                                                                                                      goto pop_function;
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
                                                                                                                                        goto pop_function;
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
                                                                                                                                          goto pop_function;
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
                                                                                                                                            goto pop_function;
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
                                                                                                                                              goto pop_function;
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
                                                                                                                                                goto pop_function;
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
                                                                                                                                                  goto pop_function;
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
                                                                                                                                                    goto pop_function;
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
                                                                                                                                                      goto pop_function;
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
                                                                                                                                                        goto pop_function;
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
                                                                                                                                                          goto pop_function;
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
                                                                                                                                                            goto pop_function;
                                                                                                                                                          } else {
                                                                                                                                                            val = NIL;
                                                                                                                                                            goto pop_function;
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
    val = -89;
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
    target = (&&function_4);
    goto apply_addr;
  }
function_6:
  increment_count(env);
  val = wrap_function((&&function_5), env);
  goto pop_function;
/* fn_1 */
body_2:
  increment_count(env);
  val = wrap_function((&&function_6), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_3;
pointer global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
function_7:
  global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* _symbol->string */
  goto body_4;
/* _symbol->string */
body_3:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49); /* fn_1 */
  target = (&&function_7);
  goto apply_addr;
pointer global_c102c110c95c50;
function_8:
  if (val != NIL) {
    decrement_count(val);
    val = -34;
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = -89;
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    goto pop_function;
  }
function_9:
  if (val != NIL) {
    decrement_count(val);
    val = -35;
    goto pop_function;
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
    target = (&&function_8);
    goto apply_addr;
  }
function_10:
  if (val != NIL) {
    decrement_count(val);
    val = -36;
    goto pop_function;
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
    target = (&&function_9);
    goto apply_addr;
  }
function_11:
  if (val != NIL) {
    decrement_count(val);
    val = -37;
    goto pop_function;
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
    target = (&&function_10);
    goto apply_addr;
  }
function_12:
  if (val != NIL) {
    decrement_count(val);
    val = -38;
    goto pop_function;
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
    target = (&&function_11);
    goto apply_addr;
  }
function_13:
  if (val != NIL) {
    decrement_count(val);
    val = -39;
    goto pop_function;
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
    target = (&&function_12);
    goto apply_addr;
  }
function_14:
  if (val != NIL) {
    decrement_count(val);
    val = -40;
    goto pop_function;
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
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
  if (val != NIL) {
    decrement_count(val);
    val = -41;
    goto pop_function;
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
    target = (&&function_14);
    goto apply_addr;
  }
function_16:
  if (val != NIL) {
    decrement_count(val);
    val = -42;
    goto pop_function;
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
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
  if (val != NIL) {
    decrement_count(val);
    val = CONS;
    goto pop_function;
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
    target = (&&function_16);
    goto apply_addr;
  }
function_18:
  if (val != NIL) {
    decrement_count(val);
    val = -43;
    goto pop_function;
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
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
  if (val != NIL) {
    decrement_count(val);
    val = -44;
    goto pop_function;
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
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
  if (val != NIL) {
    decrement_count(val);
    val = -45;
    goto pop_function;
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
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
  if (val != NIL) {
    decrement_count(val);
    val = -46;
    goto pop_function;
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
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
  if (val != NIL) {
    decrement_count(val);
    val = -47;
    goto pop_function;
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
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
  if (val != NIL) {
    decrement_count(val);
    val = -48;
    goto pop_function;
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
    target = (&&function_22);
    goto apply_addr;
  }
function_24:
  if (val != NIL) {
    decrement_count(val);
    val = -49;
    goto pop_function;
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
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
  if (val != NIL) {
    decrement_count(val);
    val = -50;
    goto pop_function;
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
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
  if (val != NIL) {
    decrement_count(val);
    val = -51;
    goto pop_function;
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
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
  if (val != NIL) {
    decrement_count(val);
    val = -52;
    goto pop_function;
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
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
  if (val != NIL) {
    decrement_count(val);
    val = -53;
    goto pop_function;
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
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
  if (val != NIL) {
    decrement_count(val);
    val = -54;
    goto pop_function;
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
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
  if (val != NIL) {
    decrement_count(val);
    val = -55;
    goto pop_function;
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
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
  if (val != NIL) {
    decrement_count(val);
    val = -56;
    goto pop_function;
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
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
  if (val != NIL) {
    decrement_count(val);
    val = -57;
    goto pop_function;
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
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
  if (val != NIL) {
    decrement_count(val);
    val = -58;
    goto pop_function;
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
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
  if (val != NIL) {
    decrement_count(val);
    val = -59;
    goto pop_function;
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
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
  if (val != NIL) {
    decrement_count(val);
    val = -60;
    goto pop_function;
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
    target = (&&function_34);
    goto apply_addr;
  }
function_36:
  if (val != NIL) {
    decrement_count(val);
    val = -61;
    goto pop_function;
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
    target = (&&function_35);
    goto apply_addr;
  }
function_37:
  if (val != NIL) {
    decrement_count(val);
    val = -62;
    goto pop_function;
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
    target = (&&function_36);
    goto apply_addr;
  }
function_38:
  if (val != NIL) {
    decrement_count(val);
    val = -63;
    goto pop_function;
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
    target = (&&function_37);
    goto apply_addr;
  }
function_39:
  if (val != NIL) {
    decrement_count(val);
    val = -64;
    goto pop_function;
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
    target = (&&function_38);
    goto apply_addr;
  }
function_40:
  if (val != NIL) {
    decrement_count(val);
    val = -65;
    goto pop_function;
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
    target = (&&function_39);
    goto apply_addr;
  }
function_41:
  if (val != NIL) {
    decrement_count(val);
    val = -66;
    goto pop_function;
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
    target = (&&function_40);
    goto apply_addr;
  }
function_42:
  if (val != NIL) {
    decrement_count(val);
    val = -67;
    goto pop_function;
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
    target = (&&function_41);
    goto apply_addr;
  }
function_43:
  if (val != NIL) {
    decrement_count(val);
    val = -68;
    goto pop_function;
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
    target = (&&function_42);
    goto apply_addr;
  }
function_44:
  if (val != NIL) {
    decrement_count(val);
    val = -69;
    goto pop_function;
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
    target = (&&function_43);
    goto apply_addr;
  }
function_45:
  if (val != NIL) {
    decrement_count(val);
    val = -70;
    goto pop_function;
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
    target = (&&function_44);
    goto apply_addr;
  }
function_46:
  if (val != NIL) {
    decrement_count(val);
    val = -71;
    goto pop_function;
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
    target = (&&function_45);
    goto apply_addr;
  }
function_47:
  if (val != NIL) {
    decrement_count(val);
    val = -72;
    goto pop_function;
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
    target = (&&function_46);
    goto apply_addr;
  }
function_48:
  if (val != NIL) {
    decrement_count(val);
    val = -73;
    goto pop_function;
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
    target = (&&function_47);
    goto apply_addr;
  }
function_49:
  if (val != NIL) {
    decrement_count(val);
    val = -74;
    goto pop_function;
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
    target = (&&function_48);
    goto apply_addr;
  }
function_50:
  if (val != NIL) {
    decrement_count(val);
    val = -75;
    goto pop_function;
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
    target = (&&function_49);
    goto apply_addr;
  }
function_51:
  if (val != NIL) {
    decrement_count(val);
    val = -76;
    goto pop_function;
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
    target = (&&function_50);
    goto apply_addr;
  }
function_52:
  if (val != NIL) {
    decrement_count(val);
    val = -77;
    goto pop_function;
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
    target = (&&function_51);
    goto apply_addr;
  }
function_53:
  if (val != NIL) {
    decrement_count(val);
    val = -78;
    goto pop_function;
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
    target = (&&function_52);
    goto apply_addr;
  }
function_54:
  if (val != NIL) {
    decrement_count(val);
    val = -79;
    goto pop_function;
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
    target = (&&function_53);
    goto apply_addr;
  }
function_55:
  if (val != NIL) {
    decrement_count(val);
    val = -80;
    goto pop_function;
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
    target = (&&function_54);
    goto apply_addr;
  }
function_56:
  if (val != NIL) {
    decrement_count(val);
    val = -81;
    goto pop_function;
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
    target = (&&function_55);
    goto apply_addr;
  }
function_57:
  if (val != NIL) {
    decrement_count(val);
    val = -82;
    goto pop_function;
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
    target = (&&function_56);
    goto apply_addr;
  }
function_58:
  if (val != NIL) {
    decrement_count(val);
    val = -83;
    goto pop_function;
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
    target = (&&function_57);
    goto apply_addr;
  }
function_59:
  if (val != NIL) {
    decrement_count(val);
    val = -84;
    goto pop_function;
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
    target = (&&function_58);
    goto apply_addr;
  }
function_60:
  if (val != NIL) {
    decrement_count(val);
    val = -85;
    goto pop_function;
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
    target = (&&function_59);
    goto apply_addr;
  }
function_61:
  if (val != NIL) {
    decrement_count(val);
    val = -86;
    goto pop_function;
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
    target = (&&function_60);
    goto apply_addr;
  }
function_62:
  if (val != NIL) {
    decrement_count(val);
    val = -87;
    goto pop_function;
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
    target = (&&function_61);
    goto apply_addr;
  }
function_63:
  if (val != NIL) {
    decrement_count(val);
    val = -88;
    goto pop_function;
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
    target = (&&function_62);
    goto apply_addr;
  }
function_64:
  if (val != NIL) {
    decrement_count(val);
    val = LSHIFT;
    goto pop_function;
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
    target = (&&function_63);
    goto apply_addr;
  }
function_65:
  if (val != NIL) {
    decrement_count(val);
    val = URSHIFT;
    goto pop_function;
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
    target = (&&function_64);
    goto apply_addr;
  }
function_66:
  if (val != NIL) {
    decrement_count(val);
    val = SRSHIFT;
    goto pop_function;
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
    target = (&&function_65);
    goto apply_addr;
  }
function_67:
  if (val != NIL) {
    decrement_count(val);
    val = BXOR;
    goto pop_function;
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
    target = (&&function_66);
    goto apply_addr;
  }
function_68:
  if (val != NIL) {
    decrement_count(val);
    val = BOR;
    goto pop_function;
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
    target = (&&function_67);
    goto apply_addr;
  }
function_69:
  if (val != NIL) {
    decrement_count(val);
    val = BAND;
    goto pop_function;
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
    target = (&&function_68);
    goto apply_addr;
  }
function_70:
  if (val != NIL) {
    decrement_count(val);
    val = BNEG;
    goto pop_function;
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
    target = (&&function_69);
    goto apply_addr;
  }
function_71:
  if (val != NIL) {
    decrement_count(val);
    val = MOD;
    goto pop_function;
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
    target = (&&function_70);
    goto apply_addr;
  }
function_72:
  if (val != NIL) {
    decrement_count(val);
    val = DIV;
    goto pop_function;
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
    target = (&&function_71);
    goto apply_addr;
  }
function_73:
  if (val != NIL) {
    decrement_count(val);
    val = MULT;
    goto pop_function;
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
    target = (&&function_72);
    goto apply_addr;
  }
function_74:
  if (val != NIL) {
    decrement_count(val);
    val = MINUS;
    goto pop_function;
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
    target = (&&function_73);
    goto apply_addr;
  }
function_75:
  if (val != NIL) {
    decrement_count(val);
    val = PLUS;
    goto pop_function;
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
    target = (&&function_74);
    goto apply_addr;
  }
function_76:
  if (val != NIL) {
    decrement_count(val);
    val = GT;
    goto pop_function;
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
    target = (&&function_75);
    goto apply_addr;
  }
function_77:
  if (val != NIL) {
    decrement_count(val);
    val = LT;
    goto pop_function;
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
    target = (&&function_76);
    goto apply_addr;
  }
function_78:
  if (val != NIL) {
    decrement_count(val);
    val = EQ;
    goto pop_function;
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
    target = (&&function_77);
    goto apply_addr;
  }
function_79:
  if (val != NIL) {
    decrement_count(val);
    val = FUNCTION;
    goto pop_function;
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
    target = (&&function_78);
    goto apply_addr;
  }
function_80:
  if (val != NIL) {
    decrement_count(val);
    val = NUMBER;
    goto pop_function;
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
    target = (&&function_79);
    goto apply_addr;
  }
function_81:
  if (val != NIL) {
    decrement_count(val);
    val = ATOM;
    goto pop_function;
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
    target = (&&function_80);
    goto apply_addr;
  }
function_82:
  if (val != NIL) {
    decrement_count(val);
    val = CDR;
    goto pop_function;
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
    target = (&&function_81);
    goto apply_addr;
  }
function_83:
  if (val != NIL) {
    decrement_count(val);
    val = CAR;
    goto pop_function;
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
    target = (&&function_82);
    goto apply_addr;
  }
function_84:
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
  target = (&&function_83);
  goto apply_addr;
function_85:
  increment_count(env);
  val = wrap_function((&&function_84), env);
  goto pop_function;
/* fn_2 */
body_4:
  increment_count(env);
  val = wrap_function((&&function_85), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_5;
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_86:
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_6;
/* _string->symbol */
body_5:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  target = (&&function_86);
  goto apply_addr;
pointer global_c102c110c95c51;
function_87:
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
    goto pop_function;
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
      goto pop_function;
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
        goto pop_function;
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
          goto pop_function;
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -89;
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
            goto pop_function;
          } else {
            val = NIL;
            goto pop_function;
          }
        }
      }
    }
  }
function_88:
  increment_count(env);
  val = wrap_function((&&function_87), env);
  goto pop_function;
/* fn_3 */
body_6:
  increment_count(env);
  val = wrap_function((&&function_88), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_7;
pointer global_c95c115c121c109c98c111c108c63;
function_89:
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  goto body_8;
/* _symbol? */
body_7:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  target = (&&function_89);
  goto apply_addr;
pointer global_c102c110c95c52;
function_90:
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
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -89;
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
      goto pop_function;
    } else {
      val = NIL;
      goto pop_function;
    }
  }
function_91:
  increment_count(env);
  val = wrap_function((&&function_90), env);
  goto pop_function;
/* fn_4 */
body_8:
  increment_count(env);
  val = wrap_function((&&function_91), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_9;
pointer global_c95c95c97c116c111c109;
function_92:
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_10;
/* __atom */
body_9:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  target = (&&function_92);
  goto apply_addr;
pointer global_c102c110c95c53;
function_93:
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
    goto top_level_apply;
  } else {
    val = NIL;
    goto pop_function;
  }
function_94:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_93);
  goto apply_addr;
function_95:
  increment_count(env);
  val = wrap_function((&&function_94), env);
  goto pop_function;
/* fn_5 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_95), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_11;
pointer global_c95c95c61;
function_96:
  global_c95c95c61 = val; /* __= */
  goto body_12;
/* __= */
body_11:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  target = (&&function_96);
  goto apply_addr;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_12:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_13;
pointer global_c102c110c95c54;
function_97:
  increment_count(val = car(car(env)));
  goto pop_function;
function_98:
  increment_count(env);
  val = wrap_function((&&function_97), env);
  goto pop_function;
/* fn_6 */
body_13:
  increment_count(env);
  val = wrap_function((&&function_98), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_14;
pointer global_c95c105c100;
function_99:
  global_c95c105c100 = val; /* _id */
  goto body_15;
/* _id */
body_14:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  target = (&&function_99);
  goto apply_addr;
pointer global_c102c110c95c55; /* fn_7 */
pointer global_c102c110c95c56;
function_100:
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
  goto top_level_apply;
function_101:
  increment_count(env);
  val = wrap_function((&&function_100), env);
  goto pop_function;
/* fn_8 */
body_15:
global_c102c110c95c55 = NIL; /* fn_7 */
  increment_count(env);
  val = wrap_function((&&function_101), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_16;
pointer global_c95c119c97c108c107; /* _walk */
function_102:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_103:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_102);
  goto apply_addr;
function_104:
  target = (&&function_103);
  goto apply_addr;
function_105:
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
  target = (&&function_104);
  goto apply_addr;
function_106:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    goto top_level_apply;
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
    target = (&&function_105);
    goto apply_addr;
  }
function_107:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_106);
  goto apply_addr;
function_108:
  increment_count(env);
  val = wrap_function((&&function_107), env);
  goto pop_function;
/* fn_7 */
body_16:
global_c95c119c97c108c107 = NIL; /* _walk */
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_17;
function_109:
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_18;
/* _walk */
body_17:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  target = (&&function_109);
  goto apply_addr;
pointer global_c95c114c114c101c118c101c114c115c101; /* _rreverse */
pointer global_c102c110c95c57;
function_110:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
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
    goto top_level_apply;
  }
function_111:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_110);
  goto apply_addr;
function_112:
  increment_count(env);
  val = wrap_function((&&function_111), env);
  goto pop_function;
/* fn_9 */
body_18:
global_c95c114c114c101c118c101c114c115c101 = NIL; /* _rreverse */
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_19;
function_113:
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_20;
/* _rreverse */
body_19:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  target = (&&function_113);
  goto apply_addr;
pointer global_c102c110c95c49c48; /* fn_10 */
pointer global_c102c110c95c49c49;
function_114:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  goto top_level_apply;
function_115:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  goto pop_function;
/* fn_11 */
body_20:
global_c102c110c95c49c48 = NIL; /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_115), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_21;
pointer global_c95c102c111c108c100c108; /* _foldl */
function_116:
  goto top_level_apply;
function_117:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_116);
  goto apply_addr;
function_118:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
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
    target = (&&function_117);
    goto apply_addr;
  }
function_119:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_118);
  goto apply_addr;
function_120:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  goto pop_function;
/* fn_10 */
body_21:
global_c95c102c111c108c100c108 = NIL; /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_120), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_22;
function_121:
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_23;
/* _foldl */
body_22:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  target = (&&function_121);
  goto apply_addr;
pointer global_c102c110c95c49c50; /* fn_12 */
pointer global_c102c110c95c49c51;
function_122:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  goto top_level_apply;
function_123:
  increment_count(env);
  val = wrap_function((&&function_122), env);
  goto pop_function;
/* fn_13 */
body_23:
global_c102c110c95c49c50 = NIL; /* fn_12 */
  increment_count(env);
  val = wrap_function((&&function_123), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_24;
function_124:
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  goto top_level_apply;
function_125:
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
  target = (&&function_124);
  goto apply_addr;
function_126:
  increment_count(env);
  val = wrap_function((&&function_125), env);
  goto pop_function;
/* fn_12 */
body_24:
  increment_count(env);
  val = wrap_function((&&function_126), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_25;
pointer global_c95c102c111c108c100c114;
function_127:
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_26;
/* _foldr */
body_25:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  target = (&&function_127);
  goto apply_addr;
pointer global_c102c110c95c49c52; /* fn_14 */
pointer global_c102c110c95c49c53;
function_128:
  goto top_level_apply;
function_129:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_128);
  goto apply_addr;
function_130:
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
  target = (&&function_129);
  goto apply_addr;
function_131:
  increment_count(env);
  val = wrap_function((&&function_130), env);
  goto pop_function;
/* fn_15 */
body_26:
global_c102c110c95c49c52 = NIL; /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_131), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_27;
pointer global_c99c111c110c115; /* cons */
function_132:
  goto top_level_apply;
function_133:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
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
    target = (&&function_132);
    goto apply_addr;
  }
function_134:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_133);
  goto apply_addr;
function_135:
  increment_count(env);
  val = wrap_function((&&function_134), env);
  goto pop_function;
/* fn_14 */
body_27:
global_c99c111c110c115 = CONS; /* cons */
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_28;
pointer global_c95c97c112c112c101c110c100;
function_136:
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_29;
/* _append */
body_28:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  target = (&&function_136);
  goto apply_addr;
pointer global_c102c110c95c50c49; /* fn_21 */
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c102c110c95c49c55; /* fn_17 */
pointer global_c102c110c95c49c54; /* fn_16 */
pointer global_c102c110c95c50c50;
function_137:
  goto top_level_apply;
function_138:
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  target = (&&function_137);
  goto apply_addr;
function_139:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  target = (&&function_138);
  goto apply_addr;
function_140:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  target = (&&function_139);
  goto apply_addr;
function_141:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  target = (&&function_140);
  goto apply_addr;
function_142:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  target = (&&function_141);
  goto apply_addr;
function_143:
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
  target = (&&function_142);
  goto apply_addr;
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* fn_22 */
body_29:
global_c102c110c95c50c49 = NIL; /* fn_21 */
global_c102c110c95c50c48 = NIL; /* fn_20 */
global_c102c110c95c49c56 = NIL; /* fn_18 */
global_c102c110c95c49c55 = NIL; /* fn_17 */
global_c102c110c95c49c54 = NIL; /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_30;
function_145:
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
  goto pop_function;
function_146:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  goto pop_function;
/* fn_16 */
body_30:
  increment_count(env);
  val = wrap_function((&&function_146), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_31;
function_147:
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
  goto pop_function;
function_148:
  increment_count(env);
  val = wrap_function((&&function_147), env);
  goto pop_function;
/* fn_17 */
body_31:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_32;
function_149:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_150:
  increment_count(env);
  val = wrap_function((&&function_149), env);
  goto pop_function;
/* fn_18 */
body_32:
  increment_count(env);
  val = wrap_function((&&function_150), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_33;
pointer global_c102c110c95c49c57; /* fn_19 */
function_151:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  goto top_level_apply;
function_152:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  goto pop_function;
/* fn_20 */
body_33:
global_c102c110c95c49c57 = NIL; /* fn_19 */
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_34;
function_153:
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
  goto top_level_apply;
function_154:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  goto pop_function;
/* fn_19 */
body_34:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_35;
function_155:
  increment_count(val = global_c95c105c100); /* _id */
  goto pop_function;
function_156:
  increment_count(env);
  val = wrap_function((&&function_155), env);
  goto pop_function;
/* fn_21 */
body_35:
  increment_count(env);
  val = wrap_function((&&function_156), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_36;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_157:
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_37;
/* _build-num-str */
body_36:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  target = (&&function_157);
  goto apply_addr;
pointer global_c102c110c95c50c51;
function_158:
  args = cons(val, args);
  val = new_number(45);
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_159:
  target = (&&function_158);
  goto apply_addr;
function_160:
  goto top_level_apply;
function_161:
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
    goto pop_function;
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
      target = (&&function_159);
      goto apply_addr;
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
      target = (&&function_160);
      goto apply_addr;
    }
  }
function_162:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_161);
  goto apply_addr;
function_163:
  increment_count(env);
  val = wrap_function((&&function_162), env);
  goto pop_function;
/* fn_23 */
body_37:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_38;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_164:
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_39;
/* _print-num */
body_38:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  target = (&&function_164);
  goto apply_addr;
pointer global_c102c110c95c50c52;
function_165:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    goto top_level_apply;
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
      push_args();
      args = val;
      val = new_number(62);
      args = cons(val, args);
      val = new_number(78);
      args = cons(val, args);
      val = new_number(79);
      args = cons(val, args);
      val = new_number(73);
      args = cons(val, args);
      val = new_number(84);
      args = cons(val, args);
      val = new_number(67);
      args = cons(val, args);
      val = new_number(78);
      args = cons(val, args);
      val = new_number(85);
      args = cons(val, args);
      val = new_number(70);
      args = cons(val, args);
      val = new_number(60);
      args = cons(val, args);
      val = args;
      args = NIL;
      pop_args();
      goto pop_function;
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
      goto pop_function;
    }
  }
function_166:
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
      goto top_level_apply;
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
      target = (&&function_165);
      goto apply_addr;
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
    goto pop_function;
  }
function_167:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  goto pop_function;
/* fn_24 */
body_39:
  increment_count(env);
  val = wrap_function((&&function_167), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_40;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_168:
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_41;
/* _print-atom */
body_40:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  target = (&&function_168);
  goto apply_addr;
pointer global_c95c112c114c105c110c116c45c116c97c105c108; /* _print-tail */
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c102c110c95c50c53;
function_169:
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
  goto top_level_apply;
function_170:
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
  goto top_level_apply;
function_171:
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
  target = (&&function_170);
  goto apply_addr;
function_172:
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
    target = (&&function_169);
    goto apply_addr;
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
    target = (&&function_171);
    goto apply_addr;
  }
function_173:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_172);
    goto apply_addr;
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
    goto top_level_apply;
  }
function_174:
  increment_count(env);
  val = wrap_function((&&function_173), env);
  goto pop_function;
/* fn_25 */
body_41:
global_c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* _print-tail */
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_174), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_42;
function_175:
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_43;
/* _print-tail */
body_42:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  target = (&&function_175);
  goto apply_addr;
pointer global_c102c110c95c50c54;
function_176:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_177:
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
  goto top_level_apply;
function_178:
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
  target = (&&function_177);
  goto apply_addr;
function_179:
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
    target = (&&function_176);
    goto apply_addr;
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
    target = (&&function_178);
    goto apply_addr;
  }
function_180:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_179);
  goto apply_addr;
function_181:
  increment_count(env);
  val = wrap_function((&&function_180), env);
  goto pop_function;
/* fn_26 */
body_43:
  increment_count(env);
  val = wrap_function((&&function_181), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_44;
function_182:
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_45;
/* _print-with-suffix */
body_44:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  target = (&&function_182);
  goto apply_addr;
pointer global_c102c110c95c50c55;
function_183:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  goto top_level_apply;
function_184:
  increment_count(env);
  val = wrap_function((&&function_183), env);
  goto pop_function;
/* fn_27 */
body_45:
  increment_count(env);
  val = wrap_function((&&function_184), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_46;
pointer global_c95c112c114c105c110c116;
function_185:
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_47;
/* _print */
body_46:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  target = (&&function_185);
  goto apply_addr;
pointer global_c102c110c95c50c56;
function_186:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_187:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_186);
  goto apply_addr;
function_188:
  increment_count(env);
  val = wrap_function((&&function_187), env);
  goto pop_function;
/* fn_28 */
body_47:
  increment_count(env);
  val = wrap_function((&&function_188), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_48;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
function_189:
  global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* ____print-with-newline */
  goto body_49;
/* ____print-with-newline */
body_48:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  target = (&&function_189);
  goto apply_addr;
pointer global_c102c110c95c50c57;
function_190:
  increment_count(val = car(env));
  goto pop_function;
function_191:
  increment_count(env);
  val = wrap_function((&&function_190), env);
  goto pop_function;
/* fn_29 */
body_49:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_50;
pointer global_c95c108c105c115c116;
function_192:
  global_c95c108c105c115c116 = val; /* _list */
  goto body_51;
/* _list */
body_50:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  target = (&&function_192);
  goto apply_addr;
pointer global_c102c110c95c51c48;
function_193:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_194:
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
  target = (&&function_193);
  goto apply_addr;
function_195:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  goto pop_function;
/* fn_30 */
body_51:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_52;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_196:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_53;
function_197:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_196);
  goto apply_addr;
/* ____map-to-stderr */
body_52:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  target = (&&function_197);
  goto apply_addr;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_53:
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
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  goto body_54;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_54:
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
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_55;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_55:
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
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_56;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_56:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_57;
pointer global_c102c110c95c51c49;
function_198:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_199:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52); /* ___l_4 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51); /* ___l_3 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_198);
  goto apply_addr;
function_200:
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54); /* ___l_6 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53); /* ___l_5 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_199);
    goto apply_addr;
  } else {
    val = NIL;
    goto pop_function;
  }
function_201:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  goto pop_function;
/* fn_31 */
body_57:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_58;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_202:
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_59;
/* ____print-warnings */
body_58:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  target = (&&function_202);
  goto apply_addr;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_59:
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
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_60;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_60:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_61;
pointer global_c102c110c95c51c50;
function_203:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_204:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_203);
  goto apply_addr;
function_205:
  increment_count(env);
  val = wrap_function((&&function_204), env);
  goto pop_function;
/* fn_32 */
body_61:
  increment_count(env);
  val = wrap_function((&&function_205), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_62;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_206:
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_63;
/* ____print-error */
body_62:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  target = (&&function_206);
  goto apply_addr;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_63:
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
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_64;
pointer global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ____special-forms */
body_64:
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ____special-forms */
  goto body_65;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_65:
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
  val = EQ;
  args = cons(val, args);
  val = FUNCTION;
  args = cons(val, args);
  val = NUMBER;
  args = cons(val, args);
  val = ATOM;
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
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_66;
pointer global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* ____supported-builtins */
body_66:
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* ____supported-builtins */
  goto body_67;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_67:
  val = NIL;
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_68;
pointer global_c95c95c95c95c102c108c97c116c116c101c110; /* ____flatten */
pointer global_c102c110c95c51c51;
function_207:
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
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110); /* ____flatten */
  goto top_level_apply;
function_208:
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
    goto pop_function;
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
    increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110); /* ____flatten */
    target = (&&function_207);
    goto apply_addr;
  }
function_209:
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
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_208);
    goto apply_addr;
  }
function_210:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    target = (&&function_209);
    goto apply_addr;
  }
function_211:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_210);
  goto apply_addr;
function_212:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  goto pop_function;
/* fn_33 */
body_68:
global_c95c95c95c95c102c108c97c116c116c101c110 = NIL; /* ____flatten */
  increment_count(env);
  val = wrap_function((&&function_212), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_69;
function_213:
  global_c95c95c95c95c102c108c97c116c116c101c110 = val; /* ____flatten */
  goto body_70;
/* ____flatten */
body_69:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  target = (&&function_213);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_70:
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
  val = -82;
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
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_71;
pointer global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115;
/* ____supported-library-procedures */
body_71:
  increment_count(val = global_c95c95c95c108c95c49c50); /* ___l_12 */
  global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 = val; /* ____supported-library-procedures */
  goto body_72;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_72:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_73;
pointer global_c95c95c101c113c117c97c108; /* __equal */
pointer global_c102c110c95c51c52;
function_214:
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
    goto top_level_apply;
  } else {
    val = NIL;
    goto pop_function;
  }
function_215:
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
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
    target = (&&function_214);
    goto apply_addr;
  }
function_216:
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
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_215);
    goto apply_addr;
  }
function_217:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_216);
  goto apply_addr;
function_218:
  increment_count(env);
  val = wrap_function((&&function_217), env);
  goto pop_function;
/* fn_34 */
body_73:
global_c95c95c101c113c117c97c108 = NIL; /* __equal */
  increment_count(env);
  val = wrap_function((&&function_218), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_74;
function_219:
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_75;
/* __equal */
body_74:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  target = (&&function_219);
  goto apply_addr;
pointer global_c95c109c101c109c98c101c114; /* _member */
pointer global_c102c110c95c51c53;
function_220:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
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
    goto top_level_apply;
  }
function_221:
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
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
    target = (&&function_220);
    goto apply_addr;
  }
function_222:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_221);
  goto apply_addr;
function_223:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  goto pop_function;
/* fn_35 */
body_75:
global_c95c109c101c109c98c101c114 = NIL; /* _member */
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_76;
function_224:
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_77;
/* _member */
body_76:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  target = (&&function_224);
  goto apply_addr;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115; /* ____escape-symbols */
pointer global_c102c110c95c51c54;
function_225:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_226:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_225);
  goto apply_addr;
function_227:
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
    target = (&&function_226);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_228:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    target = (&&function_227);
    goto apply_addr;
  }
function_229:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115); /* ____supported-library-procedures */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_228);
    goto apply_addr;
  }
function_230:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115); /* ____supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_229);
    goto apply_addr;
  }
function_231:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_232:
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
  target = (&&function_231);
  goto apply_addr;
function_233:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115); /* ____special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_230);
    goto apply_addr;
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
    target = (&&function_232);
    goto apply_addr;
  }
function_234:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_233);
  goto apply_addr;
function_235:
  increment_count(env);
  val = wrap_function((&&function_234), env);
  goto pop_function;
/* fn_36 */
body_77:
global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ____escape-symbols */
  increment_count(env);
  val = wrap_function((&&function_235), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_78;
function_236:
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_79;
/* ____escape-symbols */
body_78:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  target = (&&function_236);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_79:
  val = NIL;
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_80;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_80:
  val = NIL;
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_81;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_81:
  val = NIL;
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_82;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_82:
  val = NIL;
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_83;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_83:
  val = NIL;
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_84;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_84:
  val = NIL;
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_85;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_85:
  val = NIL;
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_86;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_86:
  val = NIL;
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_87;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_87:
  val = NIL;
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_88;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_88:
  val = NIL;
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_89;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_89:
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
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_90;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_90:
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
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_91;
pointer global_c102c110c95c51c55;
function_237:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c52); /* ___l_14 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_238:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51); /* ___l_23 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50); /* ___l_22 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_239:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_238);
  goto apply_addr;
function_240:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c49); /* ___l_21 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    target = (&&function_239);
    goto apply_addr;
  }
function_241:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56); /* ___l_18 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115); /* ____special-forms */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_240);
    goto apply_addr;
  }
function_242:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c55); /* ___l_17 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115); /* ____supported-library-procedures */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_241);
    goto apply_addr;
  }
function_243:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c53); /* ___l_15 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
    target = (&&function_237);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115); /* ____supported-builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_242);
    goto apply_addr;
  }
function_244:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_243);
  goto apply_addr;
function_245:
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
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110); /* ____flatten */
  target = (&&function_244);
  goto apply_addr;
function_246:
  increment_count(env);
  val = wrap_function((&&function_245), env);
  goto pop_function;
/* fn_37 */
body_91:
  increment_count(env);
  val = wrap_function((&&function_246), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_92;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100;
function_247:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* ____compile-find */
  goto body_93;
/* ____compile-find */
body_92:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  target = (&&function_247);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_93:
  val = NIL;
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_94;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_94:
  val = -37;
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_95;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_95:
  val = CONS;
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_96;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101; /* ____rewrite-quote */
pointer global_c102c110c95c51c56;
function_248:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56); /* ___l_28 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_249:
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101); /* ____rewrite-quote */
  target = (&&function_248);
  goto apply_addr;
function_250:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c55); /* ___l_27 */
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    goto top_level_apply;
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
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101); /* ____rewrite-quote */
    target = (&&function_249);
    goto apply_addr;
  }
function_251:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
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
      goto pop_function;
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c97c116c111c109); /* __atom */
      target = (&&function_250);
      goto apply_addr;
    }
  }
function_252:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_251);
  goto apply_addr;
function_253:
  increment_count(env);
  val = wrap_function((&&function_252), env);
  goto pop_function;
/* fn_38 */
body_96:
global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = NIL; /* ____rewrite-quote */
  increment_count(env);
  val = wrap_function((&&function_253), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_97;
function_254:
  global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* ____rewrite-quote */
  goto body_98;
/* ____rewrite-quote */
body_97:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  target = (&&function_254);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_98:
  val = NIL;
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_99;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_99:
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
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_100;
pointer global_c102c110c95c51c57; /* fn_39 */
pointer global_c102c110c95c52c48;
function_255:
  goto top_level_apply;
function_256:
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
  target = (&&function_255);
  goto apply_addr;
function_257:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_256);
  goto apply_addr;
function_258:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_257);
  goto apply_addr;
function_259:
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
  target = (&&function_258);
  goto apply_addr;
function_260:
  increment_count(env);
  val = wrap_function((&&function_259), env);
  goto pop_function;
/* fn_40 */
body_100:
global_c102c110c95c51c57 = NIL; /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_260), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_101;
function_261:
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
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
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
  goto top_level_apply;
function_262:
  increment_count(env);
  val = wrap_function((&&function_261), env);
  goto pop_function;
/* fn_39 */
body_101:
  increment_count(env);
  val = wrap_function((&&function_262), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_102;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101;
function_263:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* ____compile-quote */
  goto body_103;
/* ____compile-quote */
body_102:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  target = (&&function_263);
  goto apply_addr;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_103:
  val = NIL;
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_104;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_104:
  val = NIL;
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_105;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_105:
  val = NIL;
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_106;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_106:
  val = -37;
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_107;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_107:
  val = NIL;
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_108;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_108:
  val = -35;
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_109;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_109:
  val = -35;
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_110;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_110:
  val = -36;
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_111;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_111:
  val = -36;
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_112;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_112:
  val = CONS;
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_113;
pointer global_c102c110c95c52c49;
function_264:
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
  goto pop_function;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* fn_41 */
body_113:
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_114;
pointer global_c95c99c97c100c114;
function_266:
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_115;
/* _cadr */
body_114:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  target = (&&function_266);
  goto apply_addr;
pointer global_c102c110c95c52c53; /* fn_45 */
pointer global_c102c110c95c52c51; /* fn_43 */
pointer global_c102c110c95c52c50; /* fn_42 */
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101; /* ____rewrite-quasiquote */
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114; /* ____compile-expr */
pointer global_c102c110c95c52c54;
function_267:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  goto top_level_apply;
function_268:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_269:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ____rewrite-quasiquote */
  goto top_level_apply;
function_270:
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
  target = (&&function_269);
  goto apply_addr;
function_271:
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
    target = (&&function_268);
    goto apply_addr;
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
    target = (&&function_270);
    goto apply_addr;
  }
function_272:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ____rewrite-quasiquote */
  goto top_level_apply;
function_273:
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
  target = (&&function_272);
  goto apply_addr;
function_274:
  goto top_level_apply;
function_275:
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
  target = (&&function_274);
  goto apply_addr;
function_276:
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
    target = (&&function_273);
    goto apply_addr;
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
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ____rewrite-quasiquote */
    target = (&&function_275);
    goto apply_addr;
  }
function_277:
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
    target = (&&function_271);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c56); /* ___l_38 */
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
    target = (&&function_276);
    goto apply_addr;
  }
function_278:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c53); /* ___l_35 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c52); /* ___l_34 */
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    target = (&&function_267);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c54); /* ___l_36 */
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
    target = (&&function_277);
    goto apply_addr;
  }
function_279:
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
    increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_278);
    goto apply_addr;
  }
function_280:
  increment_count(env);
  val = wrap_function((&&function_279), env);
  goto pop_function;
/* fn_46 */
body_115:
global_c102c110c95c52c53 = NIL; /* fn_45 */
global_c102c110c95c52c51 = NIL; /* fn_43 */
global_c102c110c95c52c50 = NIL; /* fn_42 */
global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = NIL; /* ____rewrite-quasiquote */
global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = NIL; /* ____compile-expr */
  increment_count(env);
  val = wrap_function((&&function_280), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_116;
function_281:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_282:
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
  increment_count(val = global_c95c95c95c108c95c51c55); /* ___l_37 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_281);
  goto apply_addr;
function_283:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  goto pop_function;
/* fn_42 */
body_116:
  increment_count(env);
  val = wrap_function((&&function_283), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_117;
function_284:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_285:
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
  increment_count(val = global_c95c95c95c108c95c51c57); /* ___l_39 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_284);
  goto apply_addr;
function_286:
  increment_count(env);
  val = wrap_function((&&function_285), env);
  goto pop_function;
/* fn_43 */
body_117:
  increment_count(env);
  val = wrap_function((&&function_286), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_118;
pointer global_c102c110c95c52c52; /* fn_44 */
function_287:
  goto top_level_apply;
function_288:
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
  target = (&&function_287);
  goto apply_addr;
function_289:
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ____rewrite-quasiquote */
  target = (&&function_288);
  goto apply_addr;
function_290:
  increment_count(env);
  val = wrap_function((&&function_289), env);
  goto pop_function;
/* fn_45 */
body_118:
global_c102c110c95c52c52 = NIL; /* fn_44 */
  increment_count(env);
  val = wrap_function((&&function_290), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_119;
function_291:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_292:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_291);
  goto apply_addr;
function_293:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c48); /* ___l_40 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_292);
  goto apply_addr;
function_294:
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
  target = (&&function_293);
  goto apply_addr;
function_295:
  increment_count(env);
  val = wrap_function((&&function_294), env);
  goto pop_function;
/* fn_44 */
body_119:
  increment_count(env);
  val = wrap_function((&&function_295), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_120;
function_296:
  global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* ____rewrite-quasiquote */
  goto body_121;
/* ____rewrite-quasiquote */
body_120:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  target = (&&function_296);
  goto apply_addr;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_121:
  val = NIL;
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_122;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_122:
  val = -37;
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_123;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_123:
  val = NIL;
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_124;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_124:
  val = NIL;
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_125;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_125:
  val = NIL;
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_126;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_126:
  val = -38;
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_127;
pointer global_c102c110c95c52c55;
function_297:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
  } else {
    val = -38;
    goto pop_function;
  }
function_298:
  increment_count(env);
  val = wrap_function((&&function_297), env);
  goto pop_function;
/* fn_47 */
body_127:
  increment_count(env);
  val = wrap_function((&&function_298), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_128;
pointer global_c95c110c111c116;
function_299:
  global_c95c110c111c116 = val; /* _not */
  goto body_129;
/* _not */
body_128:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  target = (&&function_299);
  goto apply_addr;
pointer global_c102c110c95c52c56;
function_300:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c53); /* ___l_45 */
    goto pop_function;
  } else {
    increment_count(val = global_c95c95c95c108c95c52c54); /* ___l_46 */
    goto pop_function;
  }
function_301:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c51); /* ___l_43 */
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c52); /* ___l_44 */
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
    target = (&&function_300);
    goto apply_addr;
  }
function_302:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_301);
  goto apply_addr;
function_303:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c50); /* ___l_42 */
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
    target = (&&function_302);
    goto apply_addr;
  }
function_304:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c49); /* ___l_41 */
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_303);
    goto apply_addr;
  }
function_305:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  target = (&&function_304);
  goto apply_addr;
function_306:
  increment_count(env);
  val = wrap_function((&&function_305), env);
  goto pop_function;
/* fn_48 */
body_129:
  increment_count(env);
  val = wrap_function((&&function_306), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_130;
pointer global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101;
function_307:
  global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101 = val; /* ____always-true */
  goto body_131;
/* ____always-true */
body_130:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  target = (&&function_307);
  goto apply_addr;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_131:
  val = NIL;
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_132;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_132:
  val = NIL;
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_133;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_133:
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
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_134;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_134:
  val = -42;
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_135;
pointer global_c102c110c95c52c57;
function_308:
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
  goto pop_function;
function_309:
  increment_count(env);
  val = wrap_function((&&function_308), env);
  goto pop_function;
/* fn_49 */
body_135:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_136;
pointer global_c95c99c97c97c114;
function_310:
  global_c95c99c97c97c114 = val; /* _caar */
  goto body_137;
/* _caar */
body_136:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  target = (&&function_310);
  goto apply_addr;
pointer global_c102c110c95c53c48;
function_311:
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
  goto pop_function;
function_312:
  increment_count(env);
  val = wrap_function((&&function_311), env);
  goto pop_function;
/* fn_50 */
body_137:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_138;
pointer global_c95c99c97c100c97c114;
function_313:
  global_c95c99c97c100c97c114 = val; /* _cadar */
  goto body_139;
/* _cadar */
body_138:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  target = (&&function_313);
  goto apply_addr;
pointer global_c102c110c95c53c51; /* fn_53 */
pointer global_c102c110c95c53c52;
function_314:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_315:
  goto top_level_apply;
function_316:
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
  target = (&&function_315);
  goto apply_addr;
function_317:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  target = (&&function_316);
  goto apply_addr;
function_318:
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
    target = (&&function_314);
    goto apply_addr;
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
    target = (&&function_317);
    goto apply_addr;
  }
function_319:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101); /* ____always-true */
  target = (&&function_318);
  goto apply_addr;
function_320:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c57); /* ___l_49 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c56); /* ___l_48 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c55); /* ___l_47 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
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
    target = (&&function_319);
    goto apply_addr;
  }
function_321:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_320);
  goto apply_addr;
function_322:
  increment_count(env);
  val = wrap_function((&&function_321), env);
  goto pop_function;
/* fn_54 */
body_139:
global_c102c110c95c53c51 = NIL; /* fn_53 */
  increment_count(env);
  val = wrap_function((&&function_322), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_140;
pointer global_c102c110c95c53c50; /* fn_52 */
function_323:
  goto top_level_apply;
function_324:
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
  target = (&&function_323);
  goto apply_addr;
function_325:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  target = (&&function_324);
  goto apply_addr;
function_326:
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
  target = (&&function_325);
  goto apply_addr;
function_327:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  goto pop_function;
/* fn_53 */
body_140:
global_c102c110c95c53c50 = NIL; /* fn_52 */
  increment_count(env);
  val = wrap_function((&&function_327), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_141;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100; /* ____rewrite-cond */
pointer global_c102c110c95c53c49; /* fn_51 */
function_328:
  goto top_level_apply;
function_329:
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
  target = (&&function_328);
  goto apply_addr;
function_330:
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100); /* ____rewrite-cond */
  target = (&&function_329);
  goto apply_addr;
function_331:
  increment_count(env);
  val = wrap_function((&&function_330), env);
  goto pop_function;
/* fn_52 */
body_141:
global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = NIL; /* ____rewrite-cond */
global_c102c110c95c53c49 = NIL; /* fn_51 */
  increment_count(env);
  val = wrap_function((&&function_331), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_142;
function_332:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_333:
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
  target = (&&function_332);
  goto apply_addr;
function_334:
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
  increment_count(val = global_c95c95c95c108c95c53c48); /* ___l_50 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_333);
  goto apply_addr;
function_335:
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
  target = (&&function_334);
  goto apply_addr;
function_336:
  increment_count(env);
  val = wrap_function((&&function_335), env);
  goto pop_function;
/* fn_51 */
body_142:
  increment_count(env);
  val = wrap_function((&&function_336), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_143;
function_337:
  global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* ____rewrite-cond */
  goto body_144;
/* ____rewrite-cond */
body_143:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  target = (&&function_337);
  goto apply_addr;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_144:
  val = -39;
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_145;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116; /* ____rewrite-let */
pointer global_c102c110c95c53c53;
function_338:
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_339:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c49); /* ___l_51 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_338);
  goto apply_addr;
function_340:
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_339);
  goto apply_addr;
function_341:
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
  target = (&&function_340);
  goto apply_addr;
function_342:
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116); /* ____rewrite-let */
  target = (&&function_341);
  goto apply_addr;
function_343:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
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
    target = (&&function_342);
    goto apply_addr;
  }
function_344:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_343);
  goto apply_addr;
function_345:
  increment_count(env);
  val = wrap_function((&&function_344), env);
  goto pop_function;
/* fn_55 */
body_145:
global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = NIL; /* ____rewrite-let */
  increment_count(env);
  val = wrap_function((&&function_345), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_146;
function_346:
  global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = val; /* ____rewrite-let */
  goto body_147;
/* ____rewrite-let */
body_146:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  target = (&&function_346);
  goto apply_addr;
pointer global_c102c110c95c53c55; /* fn_57 */
pointer global_c102c110c95c53c56;
function_347:
  goto top_level_apply;
function_348:
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
  target = (&&function_347);
  goto apply_addr;
function_349:
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
    goto top_level_apply;
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
    target = (&&function_348);
    goto apply_addr;
  }
function_350:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_349);
  goto apply_addr;
function_351:
  increment_count(env);
  val = wrap_function((&&function_350), env);
  goto pop_function;
/* fn_58 */
body_147:
global_c102c110c95c53c55 = NIL; /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_351), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_148;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115; /* ____compile-args */
pointer global_c102c110c95c53c54; /* fn_56 */
function_352:
  goto top_level_apply;
function_353:
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
  target = (&&function_352);
  goto apply_addr;
function_354:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115); /* ____compile-args */
  target = (&&function_353);
  goto apply_addr;
function_355:
  increment_count(env);
  val = wrap_function((&&function_354), env);
  goto pop_function;
/* fn_57 */
body_148:
global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = NIL; /* ____compile-args */
global_c102c110c95c53c54 = NIL; /* fn_56 */
  increment_count(env);
  val = wrap_function((&&function_355), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_149;
function_356:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_357:
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
  target = (&&function_356);
  goto apply_addr;
function_358:
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
  target = (&&function_357);
  goto apply_addr;
function_359:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  goto pop_function;
/* fn_56 */
body_149:
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_150;
function_360:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* ____compile-args */
  goto body_151;
/* ____compile-args */
body_150:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  target = (&&function_360);
  goto apply_addr;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_151:
  val = NIL;
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_152;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_152:
  val = NIL;
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_153;
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
body_153:
  val = -37;
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  goto body_154;
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
body_154:
  val = -36;
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  goto body_155;
pointer global_c95c95c95c108c95c53c54;
/* ___l_56 */
body_155:
  val = -35;
  global_c95c95c95c108c95c53c54 = val; /* ___l_56 */
  goto body_156;
pointer global_c95c95c95c108c95c53c55;
/* ___l_57 */
body_156:
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
  global_c95c95c95c108c95c53c55 = val; /* ___l_57 */
  goto body_157;
pointer global_c95c95c95c108c95c53c56;
/* ___l_58 */
body_157:
  val = -41;
  global_c95c95c95c108c95c53c56 = val; /* ___l_58 */
  goto body_158;
pointer global_c95c95c95c108c95c53c57;
/* ___l_59 */
body_158:
  val = -40;
  global_c95c95c95c108c95c53c57 = val; /* ___l_59 */
  goto body_159;
pointer global_c95c95c95c108c95c54c48;
/* ___l_60 */
body_159:
  val = -39;
  global_c95c95c95c108c95c54c48 = val; /* ___l_60 */
  goto body_160;
pointer global_c95c95c95c108c95c54c49;
/* ___l_61 */
body_160:
  val = -39;
  global_c95c95c95c108c95c54c49 = val; /* ___l_61 */
  goto body_161;
pointer global_c102c110c95c53c57;
function_361:
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
  goto pop_function;
function_362:
  increment_count(env);
  val = wrap_function((&&function_361), env);
  goto pop_function;
/* fn_59 */
body_161:
  increment_count(env);
  val = wrap_function((&&function_362), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_162;
pointer global_c95c99c97c100c100c114;
function_363:
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_163;
/* _caddr */
body_162:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  target = (&&function_363);
  goto apply_addr;
pointer global_c102c110c95c54c49; /* fn_61 */
pointer global_c102c110c95c54c48; /* fn_60 */
pointer global_c102c110c95c54c50;
function_364:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101); /* ____rewrite-quasiquote */
  goto top_level_apply;
function_365:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_366:
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
  target = (&&function_365);
  goto apply_addr;
function_367:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_368:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116); /* ____rewrite-let */
  target = (&&function_367);
  goto apply_addr;
function_369:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_368);
  goto apply_addr;
function_370:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_371:
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
  target = (&&function_370);
  goto apply_addr;
function_372:
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
  target = (&&function_371);
  goto apply_addr;
function_373:
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
    target = (&&function_372);
    goto apply_addr;
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115); /* ____compile-args */
    goto top_level_apply;
  }
function_374:
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
    target = (&&function_369);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c48); /* ___l_60 */
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
    target = (&&function_373);
    goto apply_addr;
  }
function_375:
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
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100); /* ____rewrite-cond */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c57); /* ___l_59 */
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
    target = (&&function_374);
    goto apply_addr;
  }
function_376:
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
    target = (&&function_366);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c56); /* ___l_58 */
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
    target = (&&function_375);
    goto apply_addr;
  }
function_377:
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
    target = (&&function_364);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c54); /* ___l_56 */
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
    target = (&&function_376);
    goto apply_addr;
  }
function_378:
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101); /* ____compile-quote */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c53); /* ___l_55 */
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
    target = (&&function_377);
    goto apply_addr;
  }
function_379:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c51); /* ___l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c50); /* ___l_52 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c52); /* ___l_54 */
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
    target = (&&function_378);
    goto apply_addr;
  }
function_380:
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100); /* ____compile-find */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_379);
    goto apply_addr;
  }
function_381:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  target = (&&function_380);
  goto apply_addr;
function_382:
  increment_count(env);
  val = wrap_function((&&function_381), env);
  goto pop_function;
/* fn_62 */
body_163:
global_c102c110c95c54c49 = NIL; /* fn_61 */
global_c102c110c95c54c48 = NIL; /* fn_60 */
  increment_count(env);
  val = wrap_function((&&function_382), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_164;
function_383:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_384:
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
  increment_count(val = global_c95c95c95c108c95c53c55); /* ___l_57 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_383);
  goto apply_addr;
function_385:
  increment_count(env);
  val = wrap_function((&&function_384), env);
  goto pop_function;
/* fn_60 */
body_164:
  increment_count(env);
  val = wrap_function((&&function_385), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_165;
function_386:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_387:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c49); /* ___l_61 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  target = (&&function_386);
  goto apply_addr;
function_388:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_387);
  goto apply_addr;
function_389:
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
  target = (&&function_388);
  goto apply_addr;
function_390:
  increment_count(env);
  val = wrap_function((&&function_389), env);
  goto pop_function;
/* fn_61 */
body_165:
  increment_count(env);
  val = wrap_function((&&function_390), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  goto body_166;
function_391:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* ____compile-expr */
  goto body_167;
/* ____compile-expr */
body_166:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  target = (&&function_391);
  goto apply_addr;
pointer global_c102c110c95c54c51;
function_392:
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
  goto pop_function;
function_393:
  increment_count(env);
  val = wrap_function((&&function_392), env);
  goto pop_function;
/* fn_63 */
body_167:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_168;
pointer global_c95c99c97c97c100c114;
function_394:
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_169;
/* _caadr */
body_168:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  target = (&&function_394);
  goto apply_addr;
pointer global_c102c110c95c54c52;
function_395:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c100c114); /* _caadr */
    goto top_level_apply;
  }
function_396:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_395);
  goto apply_addr;
function_397:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_396);
  goto apply_addr;
function_398:
  increment_count(env);
  val = wrap_function((&&function_397), env);
  goto pop_function;
/* fn_64 */
body_169:
  increment_count(env);
  val = wrap_function((&&function_398), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  goto body_170;
pointer global_c95c95c95c95c103c101c116c45c110c97c109c101;
function_399:
  global_c95c95c95c95c103c101c116c45c110c97c109c101 = val; /* ____get-name */
  goto body_171;
/* ____get-name */
body_170:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  target = (&&function_399);
  goto apply_addr;
pointer global_c95c95c95c108c95c54c50;
/* ___l_62 */
body_171:
  val = -39;
  global_c95c95c95c108c95c54c50 = val; /* ___l_62 */
  goto body_172;
pointer global_c102c110c95c54c53;
function_400:
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c50); /* ___l_62 */
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_401:
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
  target = (&&function_400);
  goto apply_addr;
function_402:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    goto top_level_apply;
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
    target = (&&function_401);
    goto apply_addr;
  }
function_403:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_402);
  goto apply_addr;
function_404:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_403);
  goto apply_addr;
function_405:
  increment_count(env);
  val = wrap_function((&&function_404), env);
  goto pop_function;
/* fn_65 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_405), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  goto body_173;
pointer global_c95c95c95c95c103c101c116c45c98c111c100c121;
function_406:
  global_c95c95c95c95c103c101c116c45c98c111c100c121 = val; /* ____get-body */
  goto body_174;
/* ____get-body */
body_173:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  target = (&&function_406);
  goto apply_addr;
pointer global_c95c95c95c108c95c54c51;
/* ___l_63 */
body_174:
  val = NIL;
  global_c95c95c95c108c95c54c51 = val; /* ___l_63 */
  goto body_175;
pointer global_c102c110c95c54c54;
function_407:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_408:
  increment_count(env);
  val = wrap_function((&&function_407), env);
  goto pop_function;
/* fn_66 */
body_175:
  increment_count(env);
  val = wrap_function((&&function_408), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  goto body_176;
pointer global_c95c97c112c112c108c121;
function_409:
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_177;
/* _apply */
body_176:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  target = (&&function_409);
  goto apply_addr;
pointer global_c102c110c95c54c55; /* fn_67 */
pointer global_c102c110c95c54c56;
function_410:
  goto top_level_apply;
function_411:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_410);
  goto apply_addr;
function_412:
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
  target = (&&function_411);
  goto apply_addr;
function_413:
  increment_count(env);
  val = wrap_function((&&function_412), env);
  goto pop_function;
/* fn_68 */
body_177:
global_c102c110c95c54c55 = NIL; /* fn_67 */
  increment_count(env);
  val = wrap_function((&&function_413), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  goto body_178;
function_414:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_415:
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
  target = (&&function_414);
  goto apply_addr;
function_416:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  goto pop_function;
/* fn_67 */
body_178:
  increment_count(env);
  val = wrap_function((&&function_416), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  goto body_179;
pointer global_c95c109c97c112;
function_417:
  global_c95c109c97c112 = val; /* _map */
  goto body_180;
/* _map */
body_179:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  target = (&&function_417);
  goto apply_addr;
pointer global_c102c110c95c55c50; /* fn_72 */
pointer global_c102c110c95c55c51;
function_418:
  goto top_level_apply;
function_419:
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
  target = (&&function_418);
  goto apply_addr;
function_420:
  increment_count(env);
  val = wrap_function((&&function_419), env);
  goto pop_function;
/* fn_73 */
body_180:
global_c102c110c95c55c50 = NIL; /* fn_72 */
  increment_count(env);
  val = wrap_function((&&function_420), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  goto body_181;
pointer global_c102c110c95c55c49; /* fn_71 */
function_421:
  goto top_level_apply;
function_422:
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
  target = (&&function_421);
  goto apply_addr;
function_423:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c110c97c109c101); /* ____get-name */
  target = (&&function_422);
  goto apply_addr;
function_424:
  increment_count(env);
  val = wrap_function((&&function_423), env);
  goto pop_function;
/* fn_72 */
body_181:
global_c102c110c95c55c49 = NIL; /* fn_71 */
  increment_count(env);
  val = wrap_function((&&function_424), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  goto body_182;
pointer global_c102c110c95c55c48; /* fn_70 */
function_425:
  goto top_level_apply;
function_426:
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
  target = (&&function_425);
  goto apply_addr;
function_427:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c98c111c100c121); /* ____get-body */
  target = (&&function_426);
  goto apply_addr;
function_428:
  increment_count(env);
  val = wrap_function((&&function_427), env);
  goto pop_function;
/* fn_71 */
body_182:
global_c102c110c95c55c48 = NIL; /* fn_70 */
  increment_count(env);
  val = wrap_function((&&function_428), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  goto body_183;
pointer global_c102c110c95c54c57; /* fn_69 */
function_429:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c51); /* ___l_63 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  goto top_level_apply;
function_430:
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
  target = (&&function_429);
  goto apply_addr;
function_431:
  increment_count(env);
  val = wrap_function((&&function_430), env);
  goto pop_function;
/* fn_70 */
body_183:
global_c102c110c95c54c57 = NIL; /* fn_69 */
  increment_count(env);
  val = wrap_function((&&function_431), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  goto body_184;
function_432:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_433:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ____print-warnings */
  target = (&&function_432);
  goto apply_addr;
function_434:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  target = (&&function_433);
  goto apply_addr;
function_435:
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
  target = (&&function_434);
  goto apply_addr;
function_436:
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
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  target = (&&function_435);
  goto apply_addr;
function_437:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_436);
  goto apply_addr;
function_438:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_437);
  goto apply_addr;
function_439:
  increment_count(env);
  val = wrap_function((&&function_438), env);
  goto pop_function;
/* fn_69 */
body_184:
  increment_count(env);
  val = wrap_function((&&function_439), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  goto body_185;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
function_440:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* ____compile-definition */
  goto body_186;
/* ____compile-definition */
body_185:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  target = (&&function_440);
  goto apply_addr;
pointer global_c102c110c95c55c52; /* fn_74 */
pointer global_c102c110c95c55c53;
function_441:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110); /* ____compile-definition */
  goto top_level_apply;
function_442:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    goto top_level_apply;
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
    target = (&&function_441);
    goto apply_addr;
  }
function_443:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_442);
  goto apply_addr;
function_444:
  increment_count(env);
  val = wrap_function((&&function_443), env);
  goto pop_function;
/* fn_75 */
body_186:
global_c102c110c95c55c52 = NIL; /* fn_74 */
  increment_count(env);
  val = wrap_function((&&function_444), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  goto body_187;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115; /* ____compile-definitions */
function_445:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115); /* ____compile-definitions */
  goto top_level_apply;
function_446:
  increment_count(env);
  val = wrap_function((&&function_445), env);
  goto pop_function;
/* fn_74 */
body_187:
global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ____compile-definitions */
  increment_count(env);
  val = wrap_function((&&function_446), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  goto body_188;
function_447:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ____compile-definitions */
  goto body_189;
/* ____compile-definitions */
body_188:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  target = (&&function_447);
  goto apply_addr;
pointer global_c95c95c95c108c95c54c52;
/* ___l_64 */
body_189:
  val = NIL;
  global_c95c95c95c108c95c54c52 = val; /* ___l_64 */
  goto body_190;
pointer global_c102c110c95c55c56; /* fn_78 */
pointer global_c102c110c95c55c57;
function_448:
  goto top_level_apply;
function_449:
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
  target = (&&function_448);
  goto apply_addr;
function_450:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c110c97c109c101); /* ____get-name */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  target = (&&function_449);
  goto apply_addr;
function_451:
  increment_count(env);
  val = wrap_function((&&function_450), env);
  goto pop_function;
/* fn_79 */
body_190:
global_c102c110c95c55c56 = NIL; /* fn_78 */
  increment_count(env);
  val = wrap_function((&&function_451), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  goto body_191;
pointer global_c102c110c95c55c55; /* fn_77 */
function_452:
  goto top_level_apply;
function_453:
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
  target = (&&function_452);
  goto apply_addr;
function_454:
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
  increment_count(val = global_c95c95c95c108c95c54c52); /* ___l_64 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114); /* ____compile-expr */
  target = (&&function_453);
  goto apply_addr;
function_455:
  increment_count(env);
  val = wrap_function((&&function_454), env);
  goto pop_function;
/* fn_78 */
body_191:
global_c102c110c95c55c55 = NIL; /* fn_77 */
  increment_count(env);
  val = wrap_function((&&function_455), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  goto body_192;
pointer global_c102c110c95c55c54; /* fn_76 */
function_456:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115); /* ____compile-definitions */
  goto top_level_apply;
function_457:
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
  target = (&&function_456);
  goto apply_addr;
function_458:
  increment_count(env);
  val = wrap_function((&&function_457), env);
  goto pop_function;
/* fn_77 */
body_192:
global_c102c110c95c55c54 = NIL; /* fn_76 */
  increment_count(env);
  val = wrap_function((&&function_458), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  goto body_193;
function_459:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_460:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115); /* ____print-warnings */
  target = (&&function_459);
  goto apply_addr;
function_461:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  target = (&&function_460);
  goto apply_addr;
function_462:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  target = (&&function_461);
  goto apply_addr;
function_463:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101); /* ____print-with-newline */
  target = (&&function_462);
  goto apply_addr;
function_464:
  increment_count(env);
  val = wrap_function((&&function_463), env);
  goto pop_function;
/* fn_76 */
body_193:
  increment_count(env);
  val = wrap_function((&&function_464), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  goto body_194;
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
function_465:
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  goto body_195;
/* ____compile */
body_194:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  target = (&&function_465);
  goto apply_addr;
pointer global_c95c95c95c108c95c54c53;
/* ___l_65 */
body_195:
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
  global_c95c95c95c108c95c54c53 = val; /* ___l_65 */
  goto body_196;
pointer global_c95c95c95c108c95c54c54;
/* ___l_66 */
body_196:
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
  global_c95c95c95c108c95c54c54 = val; /* ___l_66 */
  goto body_197;
pointer global_c95c95c95c108c95c54c55;
/* ___l_67 */
body_197:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c55 = val; /* ___l_67 */
  goto body_198;
pointer global_c102c110c95c56c48; /* fn_80 */
pointer global_c102c110c95c56c49;
function_466:
  goto top_level_apply;
function_467:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_466);
  goto apply_addr;
function_468:
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
  target = (&&function_467);
  goto apply_addr;
function_469:
  increment_count(env);
  val = wrap_function((&&function_468), env);
  goto pop_function;
/* fn_81 */
body_198:
global_c102c110c95c56c48 = NIL; /* fn_80 */
  increment_count(env);
  val = wrap_function((&&function_469), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  goto body_199;
function_470:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_471:
  increment_count(env);
  val = wrap_function((&&function_470), env);
  goto pop_function;
/* fn_80 */
body_199:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  goto body_200;
pointer global_c95c97c110c100;
function_472:
  global_c95c97c110c100 = val; /* _and */
  goto body_201;
/* _and */
body_200:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  target = (&&function_472);
  goto apply_addr;
pointer global_c102c110c95c56c50;
function_473:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_474:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(13);
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(110);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    target = (&&function_473);
    goto apply_addr;
  }
function_475:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(9);
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(114);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    target = (&&function_474);
    goto apply_addr;
  }
function_476:
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_475);
  goto apply_addr;
function_477:
  increment_count(env);
  val = wrap_function((&&function_476), env);
  goto pop_function;
/* fn_82 */
body_201:
  increment_count(env);
  val = wrap_function((&&function_477), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  goto body_202;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_478:
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_203;
/* _escape-char */
body_202:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  target = (&&function_478);
  goto apply_addr;
pointer global_c102c110c95c56c51; /* fn_83 */
pointer global_c102c110c95c56c52;
function_479:
  goto top_level_apply;
function_480:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_479);
  goto apply_addr;
function_481:
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
  target = (&&function_480);
  goto apply_addr;
function_482:
  increment_count(env);
  val = wrap_function((&&function_481), env);
  goto pop_function;
/* fn_84 */
body_203:
global_c102c110c95c56c51 = NIL; /* fn_83 */
  increment_count(env);
  val = wrap_function((&&function_482), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  goto body_204;
function_483:
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
  goto pop_function;
function_484:
  increment_count(env);
  val = wrap_function((&&function_483), env);
  goto pop_function;
/* fn_83 */
body_204:
  increment_count(env);
  val = wrap_function((&&function_484), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  goto body_205;
pointer global_c95c98c117c105c108c100c45c110c117c109;
function_485:
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  goto body_206;
/* _build-num */
body_205:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  target = (&&function_485);
  goto apply_addr;
pointer global_c102c110c95c56c53;
function_486:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_487:
  increment_count(env);
  val = wrap_function((&&function_486), env);
  goto pop_function;
/* fn_85 */
body_206:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  goto body_207;
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
function_488:
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  goto body_208;
/* _quote-value */
body_207:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  target = (&&function_488);
  goto apply_addr;
pointer global_c102c110c95c56c54;
function_489:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_490:
  increment_count(env);
  val = wrap_function((&&function_489), env);
  goto pop_function;
/* fn_86 */
body_208:
  increment_count(env);
  val = wrap_function((&&function_490), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  goto body_209;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
function_491:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  goto body_210;
/* _quasiquote-value */
body_209:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  target = (&&function_491);
  goto apply_addr;
pointer global_c102c110c95c56c55;
function_492:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -35;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_493:
  increment_count(env);
  val = wrap_function((&&function_492), env);
  goto pop_function;
/* fn_87 */
body_210:
  increment_count(env);
  val = wrap_function((&&function_493), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  goto body_211;
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
function_494:
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  goto body_212;
/* _unquote-value */
body_211:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  target = (&&function_494);
  goto apply_addr;
pointer global_c102c110c95c56c56; /* fn_88 */
pointer global_c102c110c95c56c57;
function_495:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  goto top_level_apply;
function_496:
  increment_count(env);
  val = wrap_function((&&function_495), env);
  goto pop_function;
/* fn_89 */
body_212:
global_c102c110c95c56c56 = NIL; /* fn_88 */
  increment_count(env);
  val = wrap_function((&&function_496), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  goto body_213;
function_497:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  goto top_level_apply;
function_498:
  increment_count(env);
  val = wrap_function((&&function_497), env);
  goto pop_function;
/* fn_88 */
body_213:
  increment_count(env);
  val = wrap_function((&&function_498), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  goto body_214;
pointer global_c95c102c97c105c108;
function_499:
  global_c95c102c97c105c108 = val; /* _fail */
  goto body_215;
/* _fail */
body_214:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  target = (&&function_499);
  goto apply_addr;
pointer global_c102c110c95c57c48;
function_500:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_501:
  increment_count(env);
  val = wrap_function((&&function_500), env);
  goto pop_function;
/* fn_90 */
body_215:
  increment_count(env);
  val = wrap_function((&&function_501), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  goto body_216;
pointer global_c95c100c111c110c101;
function_502:
  global_c95c100c111c110c101 = val; /* _done */
  goto body_217;
/* _done */
body_216:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  target = (&&function_502);
  goto apply_addr;
pointer global_c102c110c95c57c49; /* fn_91 */
pointer global_c102c110c95c57c50;
function_503:
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
  goto top_level_apply;
function_504:
  increment_count(env);
  val = wrap_function((&&function_503), env);
  goto pop_function;
/* fn_92 */
body_217:
global_c102c110c95c57c49 = NIL; /* fn_91 */
  increment_count(env);
  val = wrap_function((&&function_504), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  goto body_218;
pointer global_c95c112c111c112; /* _pop */
function_505:
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
    goto top_level_apply;
  } else {
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    goto top_level_apply;
  }
function_506:
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
      target = (&&function_505);
      goto apply_addr;
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(cdr(car(cdr(env))))));
      args = cons(val, args);
      val = NIL;
      push_args();
      args = val;
      val = new_number(116);
      args = cons(val, args);
      val = new_number(117);
      args = cons(val, args);
      val = new_number(112);
      args = cons(val, args);
      val = new_number(110);
      args = cons(val, args);
      val = new_number(105);
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
      val = args;
      args = NIL;
      pop_args();
      args = cons(val, args);
      increment_count(val = car(cdr(car(cdr(env)))));
      goto top_level_apply;
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
    goto top_level_apply;
  }
function_507:
  increment_count(env);
  val = wrap_function((&&function_506), env);
  goto pop_function;
/* fn_91 */
body_218:
global_c95c112c111c112 = NIL; /* _pop */
  increment_count(env);
  val = wrap_function((&&function_507), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  goto body_219;
function_508:
  global_c95c112c111c112 = val; /* _pop */
  goto body_220;
/* _pop */
body_219:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  target = (&&function_508);
  goto apply_addr;
pointer global_c102c110c95c57c52; /* fn_94 */
pointer global_c102c110c95c57c53;
function_509:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  goto top_level_apply;
function_510:
  increment_count(env);
  val = wrap_function((&&function_509), env);
  goto pop_function;
/* fn_95 */
body_220:
global_c102c110c95c57c52 = NIL; /* fn_94 */
  increment_count(env);
  val = wrap_function((&&function_510), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  goto body_221;
pointer global_c102c110c95c57c51; /* fn_93 */
function_511:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  goto top_level_apply;
function_512:
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
  target = (&&function_511);
  goto apply_addr;
function_513:
  increment_count(env);
  val = wrap_function((&&function_512), env);
  goto pop_function;
/* fn_94 */
body_221:
global_c102c110c95c57c51 = NIL; /* fn_93 */
  increment_count(env);
  val = wrap_function((&&function_513), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  goto body_222;
function_514:
  goto top_level_apply;
function_515:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_514);
  goto apply_addr;
function_516:
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(117);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(118);
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
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_515);
  goto apply_addr;
function_517:
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
    goto top_level_apply;
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_516);
    goto apply_addr;
  }
function_518:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_517);
  goto apply_addr;
function_519:
  increment_count(env);
  val = wrap_function((&&function_518), env);
  goto pop_function;
/* fn_93 */
body_222:
  increment_count(env);
  val = wrap_function((&&function_519), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  goto body_223;
pointer global_c95c99c104c101c99c107;
function_520:
  global_c95c99c104c101c99c107 = val; /* _check */
  goto body_224;
/* _check */
body_223:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  target = (&&function_520);
  goto apply_addr;
pointer global_c102c110c95c57c54; /* fn_96 */
pointer global_c102c110c95c57c55;
function_521:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_522:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  target = (&&function_521);
  goto apply_addr;
function_523:
  increment_count(env);
  val = wrap_function((&&function_522), env);
  goto pop_function;
/* fn_97 */
body_224:
global_c102c110c95c57c54 = NIL; /* fn_96 */
  increment_count(env);
  val = wrap_function((&&function_523), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  goto body_225;
function_524:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_525:
  increment_count(env);
  val = wrap_function((&&function_524), env);
  goto pop_function;
/* fn_96 */
body_225:
  increment_count(env);
  val = wrap_function((&&function_525), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  goto body_226;
pointer global_c95c109c97c116c99c104;
function_526:
  global_c95c109c97c116c99c104 = val; /* _match */
  goto body_227;
/* _match */
body_226:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  target = (&&function_526);
  goto apply_addr;
pointer global_c102c110c95c57c56; /* fn_98 */
pointer global_c102c110c95c57c57;
function_527:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  goto top_level_apply;
function_528:
  increment_count(env);
  val = wrap_function((&&function_527), env);
  goto pop_function;
/* fn_99 */
body_227:
global_c102c110c95c57c56 = NIL; /* fn_98 */
  increment_count(env);
  val = wrap_function((&&function_528), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  goto body_228;
function_529:
  increment_count(val = car(car(cdr(env))));
  goto pop_function;
function_530:
  increment_count(env);
  val = wrap_function((&&function_529), env);
  goto pop_function;
/* fn_98 */
body_228:
  increment_count(env);
  val = wrap_function((&&function_530), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  goto body_229;
pointer global_c95c100c101c102c97c117c108c116;
function_531:
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  goto body_230;
/* _default */
body_229:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  target = (&&function_531);
  goto apply_addr;
pointer global_c102c110c95c49c48c51; /* fn_103 */
pointer global_c102c110c95c49c48c52;
function_532:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  goto top_level_apply;
function_533:
  increment_count(env);
  val = wrap_function((&&function_532), env);
  goto pop_function;
/* fn_104 */
body_230:
global_c102c110c95c49c48c51 = NIL; /* fn_103 */
  increment_count(env);
  val = wrap_function((&&function_533), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  goto body_231;
pointer global_c102c110c95c49c48c50; /* fn_102 */
function_534:
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
  goto top_level_apply;
function_535:
  increment_count(env);
  val = wrap_function((&&function_534), env);
  goto pop_function;
/* fn_103 */
body_231:
global_c102c110c95c49c48c50 = NIL; /* fn_102 */
  increment_count(env);
  val = wrap_function((&&function_535), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  goto body_232;
pointer global_c102c110c95c49c48c49; /* fn_101 */
pointer global_c102c110c95c49c48c48; /* fn_100 */
function_536:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_537:
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
  target = (&&function_536);
  goto apply_addr;
function_538:
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
  target = (&&function_537);
  goto apply_addr;
function_539:
  increment_count(env);
  val = wrap_function((&&function_538), env);
  goto pop_function;
/* fn_102 */
body_232:
global_c102c110c95c49c48c49 = NIL; /* fn_101 */
global_c102c110c95c49c48c48 = NIL; /* fn_100 */
  increment_count(env);
  val = wrap_function((&&function_539), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  goto body_233;
function_540:
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
  goto top_level_apply;
function_541:
  increment_count(env);
  val = wrap_function((&&function_540), env);
  goto pop_function;
/* fn_100 */
body_233:
  increment_count(env);
  val = wrap_function((&&function_541), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  goto body_234;
function_542:
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
  goto top_level_apply;
function_543:
  increment_count(env);
  val = wrap_function((&&function_542), env);
  goto pop_function;
/* fn_101 */
body_234:
  increment_count(env);
  val = wrap_function((&&function_543), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  goto body_235;
pointer global_c95c99c97c115c101;
function_544:
  global_c95c99c97c115c101 = val; /* _case */
  goto body_236;
/* _case */
body_235:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  target = (&&function_544);
  goto apply_addr;
pointer global_c102c110c95c49c48c53; /* fn_105 */
pointer global_c102c110c95c49c48c54;
function_545:
  goto top_level_apply;
function_546:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_545);
  goto apply_addr;
function_547:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  target = (&&function_546);
  goto apply_addr;
function_548:
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
  target = (&&function_547);
  goto apply_addr;
function_549:
  increment_count(env);
  val = wrap_function((&&function_548), env);
  goto pop_function;
/* fn_106 */
body_236:
global_c102c110c95c49c48c53 = NIL; /* fn_105 */
  increment_count(env);
  val = wrap_function((&&function_549), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  goto body_237;
function_550:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_551:
  increment_count(env);
  val = wrap_function((&&function_550), env);
  goto pop_function;
/* fn_105 */
body_237:
  increment_count(env);
  val = wrap_function((&&function_551), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  goto body_238;
pointer global_c95c99c104c111c105c99c101;
function_552:
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  goto body_239;
/* _choice */
body_238:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  target = (&&function_552);
  goto apply_addr;
pointer global_c102c110c95c49c48c56; /* fn_108 */
pointer global_c102c110c95c49c48c57;
function_553:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  goto top_level_apply;
function_554:
  increment_count(env);
  val = wrap_function((&&function_553), env);
  goto pop_function;
/* fn_109 */
body_239:
global_c102c110c95c49c48c56 = NIL; /* fn_108 */
  increment_count(env);
  val = wrap_function((&&function_554), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  goto body_240;
pointer global_c102c110c95c49c48c55; /* fn_107 */
function_555:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_556:
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
  target = (&&function_555);
  goto apply_addr;
function_557:
  increment_count(env);
  val = wrap_function((&&function_556), env);
  goto pop_function;
/* fn_108 */
body_240:
global_c102c110c95c49c48c55 = NIL; /* fn_107 */
  increment_count(env);
  val = wrap_function((&&function_557), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  goto body_241;
function_558:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_559:
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
  target = (&&function_558);
  goto apply_addr;
function_560:
  increment_count(env);
  val = wrap_function((&&function_559), env);
  goto pop_function;
/* fn_107 */
body_241:
  increment_count(env);
  val = wrap_function((&&function_560), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  goto body_242;
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
function_561:
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  goto body_243;
/* _post-process */
body_242:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  target = (&&function_561);
  goto apply_addr;
pointer global_c102c110c95c49c49c50; /* fn_112 */
pointer global_c102c110c95c49c49c51;
function_562:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  goto top_level_apply;
function_563:
  increment_count(env);
  val = wrap_function((&&function_562), env);
  goto pop_function;
/* fn_113 */
body_243:
global_c102c110c95c49c49c50 = NIL; /* fn_112 */
  increment_count(env);
  val = wrap_function((&&function_563), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  goto body_244;
pointer global_c102c110c95c49c49c49; /* fn_111 */
function_564:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_565:
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
  target = (&&function_564);
  goto apply_addr;
function_566:
  increment_count(env);
  val = wrap_function((&&function_565), env);
  goto pop_function;
/* fn_112 */
body_244:
global_c102c110c95c49c49c49 = NIL; /* fn_111 */
  increment_count(env);
  val = wrap_function((&&function_566), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  goto body_245;
pointer global_c102c110c95c49c49c48; /* fn_110 */
function_567:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_568:
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
  target = (&&function_567);
  goto apply_addr;
function_569:
  increment_count(env);
  val = wrap_function((&&function_568), env);
  goto pop_function;
/* fn_111 */
body_245:
global_c102c110c95c49c49c48 = NIL; /* fn_110 */
  increment_count(env);
  val = wrap_function((&&function_569), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  goto body_246;
function_570:
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
  goto top_level_apply;
function_571:
  increment_count(env);
  val = wrap_function((&&function_570), env);
  goto pop_function;
/* fn_110 */
body_246:
  increment_count(env);
  val = wrap_function((&&function_571), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  goto body_247;
pointer global_c95c115c101c113;
function_572:
  global_c95c115c101c113 = val; /* _seq */
  goto body_248;
/* _seq */
body_247:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  target = (&&function_572);
  goto apply_addr;
pointer global_c102c110c95c49c49c52;
function_573:
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_574:
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
  target = (&&function_573);
  goto apply_addr;
function_575:
  increment_count(env);
  val = wrap_function((&&function_574), env);
  goto pop_function;
/* fn_114 */
body_248:
  increment_count(env);
  val = wrap_function((&&function_575), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  goto body_249;
pointer global_c95c101c115c99c97c112c101;
function_576:
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  goto body_250;
/* _escape */
body_249:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  target = (&&function_576);
  goto apply_addr;
pointer global_c102c110c95c49c49c53;
function_577:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_578:
  increment_count(env);
  val = wrap_function((&&function_577), env);
  goto pop_function;
/* fn_115 */
body_250:
  increment_count(env);
  val = wrap_function((&&function_578), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  goto body_251;
pointer global_c95c117c115c101;
function_579:
  global_c95c117c115c101 = val; /* _use */
  goto body_252;
/* _use */
body_251:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  target = (&&function_579);
  goto apply_addr;
pointer global_c102c110c95c49c49c55; /* fn_117 */
pointer global_c102c110c95c49c49c56;
function_580:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  goto top_level_apply;
function_581:
  increment_count(env);
  val = wrap_function((&&function_580), env);
  goto pop_function;
/* fn_118 */
body_252:
global_c102c110c95c49c49c55 = NIL; /* fn_117 */
  increment_count(env);
  val = wrap_function((&&function_581), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  goto body_253;
pointer global_c102c110c95c49c49c54; /* fn_116 */
function_582:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_583:
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
  target = (&&function_582);
  goto apply_addr;
function_584:
  increment_count(env);
  val = wrap_function((&&function_583), env);
  goto pop_function;
/* fn_117 */
body_253:
global_c102c110c95c49c49c54 = NIL; /* fn_116 */
  increment_count(env);
  val = wrap_function((&&function_584), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  goto body_254;
function_585:
  goto top_level_apply;
function_586:
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
  target = (&&function_585);
  goto apply_addr;
function_587:
  increment_count(env);
  val = wrap_function((&&function_586), env);
  goto pop_function;
/* fn_116 */
body_254:
  increment_count(env);
  val = wrap_function((&&function_587), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  goto body_255;
pointer global_c95c112c101c101c107;
function_588:
  global_c95c112c101c101c107 = val; /* _peek */
  goto body_256;
/* _peek */
body_255:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  target = (&&function_588);
  goto apply_addr;
pointer global_c102c110c95c49c49c57; /* fn_119 */
pointer global_c102c110c95c49c50c48;
function_589:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_590:
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
  target = (&&function_589);
  goto apply_addr;
function_591:
  increment_count(env);
  val = wrap_function((&&function_590), env);
  goto pop_function;
/* fn_120 */
body_256:
global_c102c110c95c49c49c57 = NIL; /* fn_119 */
  increment_count(env);
  val = wrap_function((&&function_591), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  goto body_257;
function_592:
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
  goto top_level_apply;
function_593:
  increment_count(env);
  val = wrap_function((&&function_592), env);
  goto pop_function;
/* fn_119 */
body_257:
  increment_count(env);
  val = wrap_function((&&function_593), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  goto body_258;
pointer global_c95c105c110c116c101c114c118c97c108;
function_594:
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  goto body_259;
/* _interval */
body_258:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  target = (&&function_594);
  goto apply_addr;
pointer global_c99c100c114; /* cdr */
pointer global_c102c110c95c49c50c49;
function_595:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_596:
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
  target = (&&function_595);
  goto apply_addr;
function_597:
  increment_count(env);
  val = wrap_function((&&function_596), env);
  goto pop_function;
/* fn_121 */
body_259:
global_c99c100c114 = CDR; /* cdr */
  increment_count(env);
  val = wrap_function((&&function_597), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  goto body_260;
pointer global_c95c115c107c105c112;
function_598:
  global_c95c115c107c105c112 = val; /* _skip */
  goto body_261;
/* _skip */
body_260:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  target = (&&function_598);
  goto apply_addr;
pointer global_c99c97c114; /* car */
pointer global_c102c110c95c49c50c50;
function_599:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_600:
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
  target = (&&function_599);
  goto apply_addr;
function_601:
  increment_count(env);
  val = wrap_function((&&function_600), env);
  goto pop_function;
/* fn_122 */
body_261:
global_c99c97c114 = CAR; /* car */
  increment_count(env);
  val = wrap_function((&&function_601), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  goto body_262;
pointer global_c95c102c105c114c115c116;
function_602:
  global_c95c102c105c114c115c116 = val; /* _first */
  goto body_263;
/* _first */
body_262:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  target = (&&function_602);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c110c117c109; /* _parse-num */
pointer global_c102c110c95c49c50c51;
function_603:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_604:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_603);
  goto apply_addr;
function_605:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_604);
  goto apply_addr;
function_606:
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
  target = (&&function_605);
  goto apply_addr;
function_607:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_606);
  goto apply_addr;
function_608:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_607);
  goto apply_addr;
function_609:
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
  target = (&&function_608);
  goto apply_addr;
function_610:
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
  target = (&&function_609);
  goto apply_addr;
function_611:
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
  target = (&&function_610);
  goto apply_addr;
function_612:
  increment_count(env);
  val = wrap_function((&&function_611), env);
  goto pop_function;
/* fn_123 */
body_263:
global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
  increment_count(env);
  val = wrap_function((&&function_612), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  goto body_264;
function_613:
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  goto body_265;
/* _parse-num */
body_264:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  target = (&&function_613);
  goto apply_addr;
pointer global_c102c110c95c49c50c52;
function_614:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_615:
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
  target = (&&function_614);
  goto apply_addr;
function_616:
  increment_count(env);
  val = wrap_function((&&function_615), env);
  goto pop_function;
/* fn_124 */
body_265:
  increment_count(env);
  val = wrap_function((&&function_616), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  goto body_266;
pointer global_c95c114c101c97c100c45c110c117c109;
function_617:
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  goto body_267;
/* _read-num */
body_266:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  target = (&&function_617);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c49c50c53;
function_618:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_619:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_618);
  goto apply_addr;
function_620:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_619);
  goto apply_addr;
function_621:
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
  target = (&&function_620);
  goto apply_addr;
function_622:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_621);
  goto apply_addr;
function_623:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_622);
  goto apply_addr;
function_624:
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
  target = (&&function_623);
  goto apply_addr;
function_625:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_624);
  goto apply_addr;
function_626:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_625);
  goto apply_addr;
function_627:
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
  target = (&&function_626);
  goto apply_addr;
function_628:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_627);
  goto apply_addr;
function_629:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_628);
  goto apply_addr;
function_630:
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
  target = (&&function_629);
  goto apply_addr;
function_631:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_630);
  goto apply_addr;
function_632:
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
  target = (&&function_631);
  goto apply_addr;
function_633:
  increment_count(env);
  val = wrap_function((&&function_632), env);
  goto pop_function;
/* fn_125 */
body_267:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_633), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  goto body_268;
function_634:
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_269;
/* _parse-symbol */
body_268:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  target = (&&function_634);
  goto apply_addr;
pointer global_c102c110c95c49c50c54;
function_635:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_636:
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
  target = (&&function_635);
  goto apply_addr;
function_637:
  increment_count(env);
  val = wrap_function((&&function_636), env);
  goto pop_function;
/* fn_126 */
body_269:
  increment_count(env);
  val = wrap_function((&&function_637), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  goto body_270;
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
function_638:
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  goto body_271;
/* _read-symbol */
body_270:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  target = (&&function_638);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c102c110c95c49c50c55;
function_639:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_640:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_639);
  goto apply_addr;
function_641:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_640);
  goto apply_addr;
function_642:
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
  target = (&&function_641);
  goto apply_addr;
function_643:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_642);
  goto apply_addr;
function_644:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_643);
  goto apply_addr;
function_645:
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
  target = (&&function_644);
  goto apply_addr;
function_646:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_645);
  goto apply_addr;
function_647:
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
  target = (&&function_646);
  goto apply_addr;
function_648:
  increment_count(env);
  val = wrap_function((&&function_647), env);
  goto pop_function;
/* fn_127 */
body_271:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
  increment_count(env);
  val = wrap_function((&&function_648), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  goto body_272;
function_649:
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_273;
/* _parse-string */
body_272:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  target = (&&function_649);
  goto apply_addr;
pointer global_c102c110c95c49c50c56;
function_650:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c111c116c101c45c118c97c108c117c101); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_651:
  increment_count(env);
  val = wrap_function((&&function_650), env);
  goto pop_function;
/* fn_128 */
body_273:
  increment_count(env);
  val = wrap_function((&&function_651), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  goto body_274;
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
function_652:
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  goto body_275;
/* _quote-parser */
body_274:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  target = (&&function_652);
  goto apply_addr;
pointer global_c102c110c95c49c50c57;
function_653:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_654:
  increment_count(env);
  val = wrap_function((&&function_653), env);
  goto pop_function;
/* fn_129 */
body_275:
  increment_count(env);
  val = wrap_function((&&function_654), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  goto body_276;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
function_655:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  goto body_277;
/* _quasiquote-parser */
body_276:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  target = (&&function_655);
  goto apply_addr;
pointer global_c102c110c95c49c51c48;
function_656:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_657:
  increment_count(env);
  val = wrap_function((&&function_656), env);
  goto pop_function;
/* fn_130 */
body_277:
  increment_count(env);
  val = wrap_function((&&function_657), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  goto body_278;
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
function_658:
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  goto body_279;
/* _unquote-parser */
body_278:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  target = (&&function_658);
  goto apply_addr;
pointer global_c102c110c95c49c51c49; /* fn_131 */
pointer global_c102c110c95c49c51c50;
function_659:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  goto top_level_apply;
function_660:
  increment_count(env);
  val = wrap_function((&&function_659), env);
  goto pop_function;
/* fn_132 */
body_279:
global_c102c110c95c49c51c49 = NIL; /* fn_131 */
  increment_count(env);
  val = wrap_function((&&function_660), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  goto body_280;
pointer global_c95c99c111c109c109c101c110c116; /* _comment */
function_661:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_662:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_661);
  goto apply_addr;
function_663:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_662);
  goto apply_addr;
function_664:
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
  target = (&&function_663);
  goto apply_addr;
function_665:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_664);
  goto apply_addr;
function_666:
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
  target = (&&function_665);
  goto apply_addr;
function_667:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_666);
  goto apply_addr;
function_668:
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  target = (&&function_667);
  goto apply_addr;
function_669:
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
  target = (&&function_668);
  goto apply_addr;
function_670:
  increment_count(env);
  val = wrap_function((&&function_669), env);
  goto pop_function;
/* fn_131 */
body_280:
global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
  increment_count(env);
  val = wrap_function((&&function_670), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  goto body_281;
function_671:
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  goto body_282;
/* _comment */
body_281:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  target = (&&function_671);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c49c51c51;
function_672:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_673:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_672);
  goto apply_addr;
function_674:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_673);
  goto apply_addr;
function_675:
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
  target = (&&function_674);
  goto apply_addr;
function_676:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_675);
  goto apply_addr;
function_677:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_676);
  goto apply_addr;
function_678:
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
  target = (&&function_677);
  goto apply_addr;
function_679:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_678);
  goto apply_addr;
function_680:
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
  target = (&&function_679);
  goto apply_addr;
function_681:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_680);
  goto apply_addr;
function_682:
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
  val = new_number(115);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c102c97c105c108); /* _fail */
  target = (&&function_681);
  goto apply_addr;
function_683:
  increment_count(env);
  val = wrap_function((&&function_682), env);
  goto pop_function;
/* fn_133 */
body_282:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_683), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  goto body_283;
function_684:
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_284;
/* _parse-paren */
body_283:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  target = (&&function_684);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c49c51c52;
function_685:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_686:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_685);
  goto apply_addr;
function_687:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_686);
  goto apply_addr;
function_688:
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
  target = (&&function_687);
  goto apply_addr;
function_689:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_688);
  goto apply_addr;
function_690:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_689);
  goto apply_addr;
function_691:
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
  target = (&&function_690);
  goto apply_addr;
function_692:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_691);
  goto apply_addr;
function_693:
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
  target = (&&function_692);
  goto apply_addr;
function_694:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_693);
  goto apply_addr;
function_695:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_694);
  goto apply_addr;
function_696:
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
  target = (&&function_695);
  goto apply_addr;
function_697:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_696);
  goto apply_addr;
function_698:
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
  target = (&&function_697);
  goto apply_addr;
function_699:
  increment_count(env);
  val = wrap_function((&&function_698), env);
  goto pop_function;
/* fn_134 */
body_284:
global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_699), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  goto body_285;
function_700:
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_286;
/* _parse-pair */
body_285:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  target = (&&function_700);
  goto apply_addr;
pointer global_c102c110c95c49c51c53;
function_701:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_702:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_701);
  goto apply_addr;
function_703:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_702);
  goto apply_addr;
function_704:
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
  target = (&&function_703);
  goto apply_addr;
function_705:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_704);
  goto apply_addr;
function_706:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_705);
  goto apply_addr;
function_707:
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
  target = (&&function_706);
  goto apply_addr;
function_708:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_707);
  goto apply_addr;
function_709:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_708);
  goto apply_addr;
function_710:
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
  target = (&&function_709);
  goto apply_addr;
function_711:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_710);
  goto apply_addr;
function_712:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_711);
  goto apply_addr;
function_713:
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
  target = (&&function_712);
  goto apply_addr;
function_714:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_713);
  goto apply_addr;
function_715:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_714);
  goto apply_addr;
function_716:
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
  target = (&&function_715);
  goto apply_addr;
function_717:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_716);
  goto apply_addr;
function_718:
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
  target = (&&function_717);
  goto apply_addr;
function_719:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_718);
  goto apply_addr;
function_720:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_719);
  goto apply_addr;
function_721:
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
  target = (&&function_720);
  goto apply_addr;
function_722:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_721);
  goto apply_addr;
function_723:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_722);
  goto apply_addr;
function_724:
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
  target = (&&function_723);
  goto apply_addr;
function_725:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_724);
  goto apply_addr;
function_726:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_725);
  goto apply_addr;
function_727:
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
  target = (&&function_726);
  goto apply_addr;
function_728:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_727);
  goto apply_addr;
function_729:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_728);
  goto apply_addr;
function_730:
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
  target = (&&function_729);
  goto apply_addr;
function_731:
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
  target = (&&function_730);
  goto apply_addr;
function_732:
  increment_count(env);
  val = wrap_function((&&function_731), env);
  goto pop_function;
/* fn_135 */
body_286:
  increment_count(env);
  val = wrap_function((&&function_732), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  goto body_287;
function_733:
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_288;
/* _parse-expr */
body_287:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  target = (&&function_733);
  goto apply_addr;
pointer global_c102c110c95c49c51c54; /* fn_136 */
pointer global_c102c110c95c49c51c55;
function_734:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  goto top_level_apply;
function_735:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  target = (&&function_734);
  goto apply_addr;
function_736:
  increment_count(env);
  val = wrap_function((&&function_735), env);
  goto pop_function;
/* fn_137 */
body_288:
global_c102c110c95c49c51c54 = NIL; /* fn_136 */
  increment_count(env);
  val = wrap_function((&&function_736), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  goto body_289;
function_737:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  goto top_level_apply;
function_738:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c53); /* ___l_65 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_737);
  goto apply_addr;
function_739:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c54c55); /* ___l_67 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c54); /* ___l_66 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_738);
  goto apply_addr;
function_740:
  increment_count(env);
  val = wrap_function((&&function_739), env);
  goto pop_function;
/* fn_136 */
body_289:
  increment_count(env);
  val = wrap_function((&&function_740), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  goto body_290;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_741:
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_291;
/* ____read-expr */
body_290:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  target = (&&function_741);
  goto apply_addr;
pointer global_c95c95c95c108c95c54c56;
/* ___l_68 */
body_291:
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
  global_c95c95c95c108c95c54c56 = val; /* ___l_68 */
  goto body_292;
pointer global_c95c95c95c108c95c54c57;
/* ___l_69 */
body_292:
  val = -34;
  global_c95c95c95c108c95c54c57 = val; /* ___l_69 */
  goto body_293;
pointer global_c95c95c95c108c95c55c48;
/* ___l_70 */
body_293:
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
  global_c95c95c95c108c95c55c48 = val; /* ___l_70 */
  goto body_294;
pointer global_c102c110c95c49c51c56;
function_742:
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
  goto top_level_apply;
function_743:
  increment_count(env);
  val = wrap_function((&&function_742), env);
  goto pop_function;
/* fn_138 */
body_294:
  increment_count(env);
  val = wrap_function((&&function_743), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  goto body_295;
pointer global_c95c114c101c118c101c114c115c101;
function_744:
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_296;
/* _reverse */
body_295:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  target = (&&function_744);
  goto apply_addr;
pointer global_c102c110c95c49c51c57; /* fn_139 */
pointer global_c102c110c95c49c52c48;
function_745:
  goto top_level_apply;
function_746:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_745);
  goto apply_addr;
function_747:
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
  target = (&&function_746);
  goto apply_addr;
function_748:
  increment_count(env);
  val = wrap_function((&&function_747), env);
  goto pop_function;
/* fn_140 */
body_296:
global_c102c110c95c49c51c57 = NIL; /* fn_139 */
  increment_count(env);
  val = wrap_function((&&function_748), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  goto body_297;
function_749:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_750:
  increment_count(env);
  val = wrap_function((&&function_749), env);
  goto pop_function;
/* fn_139 */
body_297:
  increment_count(env);
  val = wrap_function((&&function_750), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  goto body_298;
pointer global_c95c111c114;
function_751:
  global_c95c111c114 = val; /* _or */
  goto body_299;
/* _or */
body_298:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
  target = (&&function_751);
  goto apply_addr;
pointer global_c102c110c95c49c52c49; /* fn_141 */
pointer global_c102c110c95c49c52c50;
function_752:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
  goto top_level_apply;
function_753:
  increment_count(env);
  val = wrap_function((&&function_752), env);
  goto pop_function;
/* fn_142 */
body_299:
global_c102c110c95c49c52c49 = NIL; /* fn_141 */
  increment_count(env);
  val = wrap_function((&&function_753), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  goto body_300;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
function_754:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101); /* ____compile */
  goto top_level_apply;
function_755:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_756:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c48); /* ___l_70 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
    goto top_level_apply;
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
    target = (&&function_755);
    goto apply_addr;
  }
function_757:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_756);
  goto apply_addr;
function_758:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_757);
  goto apply_addr;
function_759:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_758);
  goto apply_addr;
function_760:
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
  target = (&&function_759);
  goto apply_addr;
function_761:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_760);
  goto apply_addr;
function_762:
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
    target = (&&function_754);
    goto apply_addr;
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
    target = (&&function_761);
    goto apply_addr;
  }
function_763:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_762);
  goto apply_addr;
function_764:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c56); /* ___l_68 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c57); /* ___l_69 */
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
    target = (&&function_763);
    goto apply_addr;
  }
function_765:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_764);
  goto apply_addr;
function_766:
  increment_count(env);
  val = wrap_function((&&function_765), env);
  goto pop_function;
/* fn_141 */
body_300:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_766), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  goto body_301;
function_767:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_302;
/* ____compile-source */
body_301:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  target = (&&function_767);
  goto apply_addr;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_302:
  val = NIL;
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_303;
pointer global_c102c110c95c49c52c51;
function_768:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_769:
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
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_768);
  goto apply_addr;
function_770:
  increment_count(env);
  val = wrap_function((&&function_769), env);
  goto pop_function;
/* fn_143 */
body_303:
  increment_count(env);
  val = wrap_function((&&function_770), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  goto body_304;
top_level_addr:
  while (! is_atom(val)) {
    execute(car(val));
    increment_count(temp = cdr(val));
    decrement_count(val);
    val = temp;
  }
  if (is_function(val)) {
    pointer input = get_input();
    target = function_target(val, &&end_function_addr);
    increment_count(env = function_environment(val));
    decrement_count(val);
    if (input != NIL) {
      env = cons(cons(input, NIL), env);
    } else {
      env = cons(NIL, env);
    }
    call_stack = cons(wrap_function(&&top_level_addr,
                                    NIL),
                     call_stack);
  } else {
    target = &&end_function_addr;
  }
  goto *target;
end_function_addr:
#ifndef BARE_HARDWARE
  end_io();
#endif
  if (is_number(val)) {
#ifdef BARE_HARDWARE
    if (cdr(val) == 0) {
      halt();
    } else if (cdr(val) == 1) {
      reboot();
    }
  }
  decrement_count(val);
#else
    return_value = value(val);
  } else {
    return_value = 0;
  }
  decrement_count(val);
  return return_value;
#endif
pop_function:
  decrement_count(env);
  temp = car(call_stack);
  if (is_function(temp)) {
    env = function_environment(temp);
    increment_count(env);
    target = function_target(temp, &&end_function_addr);
  } else {
    error(ERR_INTERNAL);
    env = NIL;
    target = (&&end_function_addr);
  }
  increment_count(temp = cdr(call_stack));
  decrement_count(call_stack);
  call_stack = temp;
  goto *target;
top_level_apply:
  if (is_function(val)) {
    decrement_count(env);
    target = function_target(val, &&end_function_addr);
    increment_count(env = function_environment(val));
    decrement_count(val);
    increment_count(args);
    env = cons(args, env);
    pop_args();
    goto *target;
  } else {
    if (is_primitive(val)) {
      val = eval_primitive(val, args);
    } else {
      decrement_count(val);
      val = NIL;
    }
    pop_args();
    goto pop_function;
  }
apply_addr:
  if (is_function(val)) {
    call_stack = cons(wrap_function(target, env),
                      call_stack);
    target = function_target(val, &&end_function_addr);
    increment_count(env = function_environment(val));
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
  }
  pop_args();
  goto *target;
function_771:
  if (is_function(val)) {
    increment_count(env=function_environment(val));
    env = cons(cons(free_memory_size(),
                   cons(arguments,NIL)),
               env);
    target = function_target(val, &&end_function_addr);
    decrement_count(val);
  } else {
    error(ERR_NO_OS);
    env = NIL;
    target = &&end_function_addr;
  }
  goto *target;
body_304:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  goto top_level_apply;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), NIL), call_stack);
  call_stack = cons(wrap_function((&&function_771), NIL), call_stack);
  goto body_0;
}
