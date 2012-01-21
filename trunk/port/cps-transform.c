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
                                                        val = new_number(115);
                                                        args = cons(val, args);
                                                        val = new_number(103);
                                                        args = cons(val, args);
                                                        val = new_number(114);
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
                                                              val = new_number(114);
                                                              args = cons(val, args);
                                                              val = new_number(117);
                                                              args = cons(val, args);
                                                              val = new_number(116);
                                                              args = cons(val, args);
                                                              val = new_number(101);
                                                              args = cons(val, args);
                                                              val = new_number(114);
                                                              args = cons(val, args);
                                                              val = new_number(45);
                                                              args = cons(val, args);
                                                              val = new_number(108);
                                                              args = cons(val, args);
                                                              val = new_number(101);
                                                              args = cons(val, args);
                                                              val = new_number(118);
                                                              args = cons(val, args);
                                                              val = new_number(101);
                                                              args = cons(val, args);
                                                              val = new_number(108);
                                                              args = cons(val, args);
                                                              val = new_number(45);
                                                              args = cons(val, args);
                                                              val = new_number(112);
                                                              args = cons(val, args);
                                                              val = new_number(111);
                                                              args = cons(val, args);
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
                                                                  val = new_number(114);
                                                                  args = cons(val, args);
                                                                  val = new_number(112);
                                                                  args = cons(val, args);
                                                                  val = new_number(120);
                                                                  args = cons(val, args);
                                                                  val = new_number(101);
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
    val = -44;
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
    val = CDR;
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
    val = -35;
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
    target = (&&function_9);
    goto apply_addr;
  }
function_11:
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
    val = new_number(110);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(118);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(116);
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
    val = CONS;
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
    val = new_number(99);
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
    val = -36;
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
    target = (&&function_12);
    goto apply_addr;
  }
function_14:
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
    val = new_number(115);
    args = cons(val, args);
    val = new_number(103);
    args = cons(val, args);
    val = new_number(114);
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
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
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
    target = (&&function_14);
    goto apply_addr;
  }
function_16:
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
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
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
    val = -39;
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
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
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
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
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
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
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
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
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
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
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
    val = new_number(116);
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
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
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
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
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
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
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
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
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
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
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
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
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
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
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
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
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
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
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
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
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
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
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
    target = (&&function_34);
    goto apply_addr;
  }
function_36:
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
    target = (&&function_35);
    goto apply_addr;
  }
function_37:
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
    target = (&&function_36);
    goto apply_addr;
  }
function_38:
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
    val = new_number(61);
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
  target = (&&function_38);
  goto apply_addr;
function_40:
  increment_count(env);
  val = wrap_function((&&function_39), env);
  goto pop_function;
/* fn_2 */
body_4:
  increment_count(env);
  val = wrap_function((&&function_40), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_5;
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_41:
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_6;
/* _string->symbol */
body_5:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  target = (&&function_41);
  goto apply_addr;
pointer global_c102c110c95c51;
function_42:
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
          val = -43;
          goto pop_function;
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
            val = -43;
            goto pop_function;
          } else {
            val = NIL;
            goto pop_function;
          }
        }
      }
    }
  }
function_43:
  increment_count(env);
  val = wrap_function((&&function_42), env);
  goto pop_function;
/* fn_3 */
body_6:
  increment_count(env);
  val = wrap_function((&&function_43), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_7;
pointer global_c95c115c121c109c98c111c108c63;
function_44:
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  goto body_8;
/* _symbol? */
body_7:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  target = (&&function_44);
  goto apply_addr;
pointer global_c102c110c95c52;
function_45:
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
    goto pop_function;
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
      val = -43;
      goto pop_function;
    } else {
      val = NIL;
      goto pop_function;
    }
  }
function_46:
  increment_count(env);
  val = wrap_function((&&function_45), env);
  goto pop_function;
/* fn_4 */
body_8:
  increment_count(env);
  val = wrap_function((&&function_46), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_9;
pointer global_c95c95c97c116c111c109;
function_47:
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_10;
/* __atom */
body_9:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  target = (&&function_47);
  goto apply_addr;
pointer global_c102c110c95c53;
function_48:
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
function_49:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_48);
  goto apply_addr;
function_50:
  increment_count(env);
  val = wrap_function((&&function_49), env);
  goto pop_function;
/* fn_5 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_11;
pointer global_c95c95c61;
function_51:
  global_c95c95c61 = val; /* __= */
  goto body_12;
/* __= */
body_11:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  target = (&&function_51);
  goto apply_addr;
pointer global_c102c110c95c54;
function_52:
  increment_count(val = car(env));
  goto pop_function;
function_53:
  increment_count(env);
  val = wrap_function((&&function_52), env);
  goto pop_function;
/* fn_6 */
body_12:
  increment_count(env);
  val = wrap_function((&&function_53), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_13;
pointer global_c95c108c105c115c116;
function_54:
  global_c95c108c105c115c116 = val; /* _list */
  goto body_14;
/* _list */
body_13:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  target = (&&function_54);
  goto apply_addr;
pointer global_c95c114c114c101c118c101c114c115c101; /* _rreverse */
pointer global_c102c110c95c55;
function_55:
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
function_56:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_55);
  goto apply_addr;
function_57:
  increment_count(env);
  val = wrap_function((&&function_56), env);
  goto pop_function;
/* fn_7 */
body_14:
global_c95c114c114c101c118c101c114c115c101 = NIL; /* _rreverse */
  increment_count(env);
  val = wrap_function((&&function_57), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_15;
function_58:
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_16;
/* _rreverse */
body_15:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  target = (&&function_58);
  goto apply_addr;
pointer global_c102c110c95c56; /* fn_8 */
pointer global_c102c110c95c57;
function_59:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  goto top_level_apply;
function_60:
  increment_count(env);
  val = wrap_function((&&function_59), env);
  goto pop_function;
/* fn_9 */
body_16:
global_c102c110c95c56 = NIL; /* fn_8 */
  increment_count(env);
  val = wrap_function((&&function_60), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_17;
pointer global_c95c102c111c108c100c108; /* _foldl */
function_61:
  goto top_level_apply;
function_62:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_61);
  goto apply_addr;
function_63:
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
    target = (&&function_62);
    goto apply_addr;
  }
function_64:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_63);
  goto apply_addr;
function_65:
  increment_count(env);
  val = wrap_function((&&function_64), env);
  goto pop_function;
/* fn_8 */
body_17:
global_c95c102c111c108c100c108 = NIL; /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_65), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_18;
function_66:
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_19;
/* _foldl */
body_18:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  target = (&&function_66);
  goto apply_addr;
pointer global_c102c110c95c49c48; /* fn_10 */
pointer global_c102c110c95c49c49;
function_67:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  goto top_level_apply;
function_68:
  increment_count(env);
  val = wrap_function((&&function_67), env);
  goto pop_function;
/* fn_11 */
body_19:
global_c102c110c95c49c48 = NIL; /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_68), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_20;
function_69:
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  goto top_level_apply;
function_70:
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
  target = (&&function_69);
  goto apply_addr;
function_71:
  increment_count(env);
  val = wrap_function((&&function_70), env);
  goto pop_function;
/* fn_10 */
body_20:
  increment_count(env);
  val = wrap_function((&&function_71), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_21;
pointer global_c95c102c111c108c100c114;
function_72:
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_22;
/* _foldr */
body_21:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  target = (&&function_72);
  goto apply_addr;
pointer global_c102c110c95c49c50;
function_73:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_74:
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
  target = (&&function_73);
  goto apply_addr;
function_75:
  increment_count(env);
  val = wrap_function((&&function_74), env);
  goto pop_function;
/* fn_12 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_75), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_23;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_76:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_24;
function_77:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_76);
  goto apply_addr;
/* ____map-to-stderr */
body_23:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  target = (&&function_77);
  goto apply_addr;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_24:
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
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_25;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_25:
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
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_26;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_26:
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
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  goto body_27;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_27:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_28;
pointer global_c102c110c95c49c51;
function_78:
  increment_count(val = car(car(env)));
  goto pop_function;
function_79:
  increment_count(env);
  val = wrap_function((&&function_78), env);
  goto pop_function;
/* fn_13 */
body_28:
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_29;
pointer global_c95c105c100;
function_80:
  global_c95c105c100 = val; /* _id */
  goto body_30;
/* _id */
body_29:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  target = (&&function_80);
  goto apply_addr;
pointer global_c102c110c95c49c52; /* fn_14 */
pointer global_c102c110c95c49c53;
function_81:
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
  goto top_level_apply;
function_82:
  increment_count(env);
  val = wrap_function((&&function_81), env);
  goto pop_function;
/* fn_15 */
body_30:
global_c102c110c95c49c52 = NIL; /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_82), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_31;
pointer global_c95c119c97c108c107; /* _walk */
function_83:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_84:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_83);
  goto apply_addr;
function_85:
  target = (&&function_84);
  goto apply_addr;
function_86:
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
  target = (&&function_85);
  goto apply_addr;
function_87:
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
    target = (&&function_86);
    goto apply_addr;
  }
function_88:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_87);
  goto apply_addr;
function_89:
  increment_count(env);
  val = wrap_function((&&function_88), env);
  goto pop_function;
/* fn_14 */
body_31:
global_c95c119c97c108c107 = NIL; /* _walk */
  increment_count(env);
  val = wrap_function((&&function_89), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_32;
function_90:
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_33;
/* _walk */
body_32:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  target = (&&function_90);
  goto apply_addr;
pointer global_c102c110c95c49c54; /* fn_16 */
pointer global_c102c110c95c49c55;
function_91:
  goto top_level_apply;
function_92:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_91);
  goto apply_addr;
function_93:
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
  target = (&&function_92);
  goto apply_addr;
function_94:
  increment_count(env);
  val = wrap_function((&&function_93), env);
  goto pop_function;
/* fn_17 */
body_33:
global_c102c110c95c49c54 = NIL; /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_94), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_34;
pointer global_c99c111c110c115; /* cons */
function_95:
  goto top_level_apply;
function_96:
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
    target = (&&function_95);
    goto apply_addr;
  }
function_97:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_96);
  goto apply_addr;
function_98:
  increment_count(env);
  val = wrap_function((&&function_97), env);
  goto pop_function;
/* fn_16 */
body_34:
global_c99c111c110c115 = CONS; /* cons */
  increment_count(env);
  val = wrap_function((&&function_98), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_35;
pointer global_c95c97c112c112c101c110c100;
function_99:
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_36;
/* _append */
body_35:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  target = (&&function_99);
  goto apply_addr;
pointer global_c102c110c95c50c51; /* fn_23 */
pointer global_c102c110c95c50c50; /* fn_22 */
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c49c57; /* fn_19 */
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c102c110c95c50c52;
function_100:
  goto top_level_apply;
function_101:
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  target = (&&function_100);
  goto apply_addr;
function_102:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  target = (&&function_101);
  goto apply_addr;
function_103:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  target = (&&function_102);
  goto apply_addr;
function_104:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  target = (&&function_103);
  goto apply_addr;
function_105:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  target = (&&function_104);
  goto apply_addr;
function_106:
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
  target = (&&function_105);
  goto apply_addr;
function_107:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  goto pop_function;
/* fn_24 */
body_36:
global_c102c110c95c50c51 = NIL; /* fn_23 */
global_c102c110c95c50c50 = NIL; /* fn_22 */
global_c102c110c95c50c48 = NIL; /* fn_20 */
global_c102c110c95c49c57 = NIL; /* fn_19 */
global_c102c110c95c49c56 = NIL; /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_107), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_37;
function_108:
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
function_109:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  goto pop_function;
/* fn_18 */
body_37:
  increment_count(env);
  val = wrap_function((&&function_109), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_38;
function_110:
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
function_111:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  goto pop_function;
/* fn_19 */
body_38:
  increment_count(env);
  val = wrap_function((&&function_111), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_39;
function_112:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_113:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  goto pop_function;
/* fn_20 */
body_39:
  increment_count(env);
  val = wrap_function((&&function_113), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_40;
pointer global_c102c110c95c50c49; /* fn_21 */
function_114:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  goto top_level_apply;
function_115:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  goto pop_function;
/* fn_22 */
body_40:
global_c102c110c95c50c49 = NIL; /* fn_21 */
  increment_count(env);
  val = wrap_function((&&function_115), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_41;
function_116:
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
function_117:
  increment_count(env);
  val = wrap_function((&&function_116), env);
  goto pop_function;
/* fn_21 */
body_41:
  increment_count(env);
  val = wrap_function((&&function_117), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_42;
function_118:
  increment_count(val = global_c95c105c100); /* _id */
  goto pop_function;
function_119:
  increment_count(env);
  val = wrap_function((&&function_118), env);
  goto pop_function;
/* fn_23 */
body_42:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_43;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_120:
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_44;
/* _build-num-str */
body_43:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  target = (&&function_120);
  goto apply_addr;
pointer global_c102c110c95c50c53;
function_121:
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
function_122:
  target = (&&function_121);
  goto apply_addr;
function_123:
  goto top_level_apply;
function_124:
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
      target = (&&function_122);
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
      target = (&&function_123);
      goto apply_addr;
    }
  }
function_125:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_124);
  goto apply_addr;
function_126:
  increment_count(env);
  val = wrap_function((&&function_125), env);
  goto pop_function;
/* fn_25 */
body_44:
  increment_count(env);
  val = wrap_function((&&function_126), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_45;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_127:
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_46;
/* _print-num */
body_45:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  target = (&&function_127);
  goto apply_addr;
pointer global_c102c110c95c50c54;
function_128:
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
function_129:
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
      target = (&&function_128);
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
function_130:
  increment_count(env);
  val = wrap_function((&&function_129), env);
  goto pop_function;
/* fn_26 */
body_46:
  increment_count(env);
  val = wrap_function((&&function_130), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_47;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_131:
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_48;
/* _print-atom */
body_47:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  target = (&&function_131);
  goto apply_addr;
pointer global_c95c112c114c105c110c116c45c116c97c105c108; /* _print-tail */
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c102c110c95c50c55;
function_132:
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
function_133:
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
function_134:
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
  target = (&&function_133);
  goto apply_addr;
function_135:
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
    target = (&&function_132);
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
    target = (&&function_134);
    goto apply_addr;
  }
function_136:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_135);
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
function_137:
  increment_count(env);
  val = wrap_function((&&function_136), env);
  goto pop_function;
/* fn_27 */
body_48:
global_c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* _print-tail */
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_137), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_49;
function_138:
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_50;
/* _print-tail */
body_49:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  target = (&&function_138);
  goto apply_addr;
pointer global_c102c110c95c50c56;
function_139:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_140:
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
function_141:
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
  target = (&&function_140);
  goto apply_addr;
function_142:
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
    target = (&&function_139);
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
    target = (&&function_141);
    goto apply_addr;
  }
function_143:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_142);
  goto apply_addr;
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* fn_28 */
body_50:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_51;
function_145:
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_52;
/* _print-with-suffix */
body_51:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  target = (&&function_145);
  goto apply_addr;
pointer global_c102c110c95c50c57;
function_146:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  goto top_level_apply;
function_147:
  increment_count(env);
  val = wrap_function((&&function_146), env);
  goto pop_function;
/* fn_29 */
body_52:
  increment_count(env);
  val = wrap_function((&&function_147), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_53;
pointer global_c95c112c114c105c110c116;
function_148:
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_54;
/* _print */
body_53:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  target = (&&function_148);
  goto apply_addr;
pointer global_c102c110c95c51c48;
function_149:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_150:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_149);
  goto apply_addr;
function_151:
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52); /* ___l_4 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51); /* ___l_3 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_150);
    goto apply_addr;
  } else {
    val = NIL;
    goto pop_function;
  }
function_152:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  goto pop_function;
/* fn_30 */
body_54:
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_55;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_153:
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_56;
/* ____print-warnings */
body_55:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  target = (&&function_153);
  goto apply_addr;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_56:
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
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_57;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_57:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_58;
pointer global_c102c110c95c51c49;
function_154:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_155:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c54); /* ___l_6 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53); /* ___l_5 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_154);
  goto apply_addr;
function_156:
  increment_count(env);
  val = wrap_function((&&function_155), env);
  goto pop_function;
/* fn_31 */
body_58:
  increment_count(env);
  val = wrap_function((&&function_156), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_59;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_157:
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_60;
/* ____print-error */
body_59:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  target = (&&function_157);
  goto apply_addr;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_60:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_61;
pointer global_c102c110c95c51c50;
function_158:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_159:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_158);
  goto apply_addr;
function_160:
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
  target = (&&function_159);
  goto apply_addr;
function_161:
  increment_count(env);
  val = wrap_function((&&function_160), env);
  goto pop_function;
/* fn_32 */
body_61:
  increment_count(env);
  val = wrap_function((&&function_161), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_62;
pointer global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
function_162:
  global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ____number->symbol */
  goto body_63;
/* ____number->symbol */
body_62:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  target = (&&function_162);
  goto apply_addr;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_63:
  val = NIL;
  push_args();
  args = val;
  val = -37;
  args = cons(val, args);
  val = -39;
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  val = -42;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_64;
pointer global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ____special-forms */
body_64:
  increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
  global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ____special-forms */
  goto body_65;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_65:
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
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_66;
pointer global_c95c95c95c95c98c117c105c108c116c105c110c115;
/* ____builtins */
body_66:
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  global_c95c95c95c95c98c117c105c108c116c105c110c115 = val; /* ____builtins */
  goto body_67;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_67:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_68;
pointer global_c95c95c101c113c117c97c108; /* __equal */
pointer global_c102c110c95c51c51;
function_163:
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
function_164:
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
    target = (&&function_163);
    goto apply_addr;
  }
function_165:
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
    target = (&&function_164);
    goto apply_addr;
  }
function_166:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_165);
  goto apply_addr;
function_167:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  goto pop_function;
/* fn_33 */
body_68:
global_c95c95c101c113c117c97c108 = NIL; /* __equal */
  increment_count(env);
  val = wrap_function((&&function_167), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_69;
function_168:
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_70;
/* __equal */
body_69:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  target = (&&function_168);
  goto apply_addr;
pointer global_c95c109c101c109c98c101c114; /* _member */
pointer global_c102c110c95c51c52;
function_169:
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
function_170:
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
    target = (&&function_169);
    goto apply_addr;
  }
function_171:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_170);
  goto apply_addr;
function_172:
  increment_count(env);
  val = wrap_function((&&function_171), env);
  goto pop_function;
/* fn_34 */
body_70:
global_c95c109c101c109c98c101c114 = NIL; /* _member */
  increment_count(env);
  val = wrap_function((&&function_172), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_71;
function_173:
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_72;
/* _member */
body_71:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  target = (&&function_173);
  goto apply_addr;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115; /* ____escape-symbols */
pointer global_c102c110c95c51c53;
function_174:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_175:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_174);
  goto apply_addr;
function_176:
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
    target = (&&function_175);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_177:
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
    target = (&&function_176);
    goto apply_addr;
  }
function_178:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115); /* ____builtins */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_177);
    goto apply_addr;
  }
function_179:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_180:
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
  target = (&&function_179);
  goto apply_addr;
function_181:
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
    target = (&&function_178);
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
    target = (&&function_180);
    goto apply_addr;
  }
function_182:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_181);
  goto apply_addr;
function_183:
  increment_count(env);
  val = wrap_function((&&function_182), env);
  goto pop_function;
/* fn_35 */
body_72:
global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ____escape-symbols */
  increment_count(env);
  val = wrap_function((&&function_183), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_73;
function_184:
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_74;
/* ____escape-symbols */
body_73:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  target = (&&function_184);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_74:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_75;
pointer global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101;
/* ____initial-symbol-name */
body_75:
  increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
  global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____initial-symbol-name */
  goto body_76;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_76:
  val = NIL;
  push_args();
  args = val;
  val = new_number(121);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(98);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_77;
pointer global_c102c110c95c51c57; /* fn_39 */
pointer global_c102c110c95c52c48;
function_185:
  goto top_level_apply;
function_186:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  target = (&&function_185);
  goto apply_addr;
function_187:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_186);
  goto apply_addr;
function_188:
  increment_count(env);
  val = wrap_function((&&function_187), env);
  goto pop_function;
/* fn_40 */
body_77:
global_c102c110c95c51c57 = NIL; /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_188), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_78;
pointer global_c102c110c95c51c56; /* fn_38 */
function_189:
  goto top_level_apply;
function_190:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  target = (&&function_189);
  goto apply_addr;
function_191:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50); /* ___l_12 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_190);
  goto apply_addr;
function_192:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  goto pop_function;
/* fn_39 */
body_78:
global_c102c110c95c51c56 = NIL; /* fn_38 */
  increment_count(env);
  val = wrap_function((&&function_192), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_79;
pointer global_c102c110c95c51c55; /* fn_37 */
function_193:
  goto top_level_apply;
function_194:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  target = (&&function_193);
  goto apply_addr;
function_195:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_194);
  goto apply_addr;
function_196:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  goto pop_function;
/* fn_38 */
body_79:
global_c102c110c95c51c55 = NIL; /* fn_37 */
  increment_count(env);
  val = wrap_function((&&function_196), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_80;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108; /* ____transform-tail-call */
pointer global_c102c110c95c51c54; /* fn_36 */
function_197:
  goto top_level_apply;
function_198:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  target = (&&function_197);
  goto apply_addr;
function_199:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-tail-call */
  target = (&&function_198);
  goto apply_addr;
function_200:
  increment_count(env);
  val = wrap_function((&&function_199), env);
  goto pop_function;
/* fn_37 */
body_80:
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = NIL; /* ____transform-tail-call */
global_c102c110c95c51c54 = NIL; /* fn_36 */
  increment_count(env);
  val = wrap_function((&&function_200), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_81;
function_201:
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
  increment_count(val = car(car(env)));
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
  val = -37;
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
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_202:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  goto pop_function;
/* fn_36 */
body_81:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_82;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108;
function_203:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-fn-tail-call */
  goto body_83;
/* ____transform-fn-tail-call */
body_82:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  target = (&&function_203);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_83:
  val = NIL;
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_84;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_84:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_85;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_85:
  val = NIL;
  push_args();
  args = val;
  val = new_number(112);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_86;
pointer global_c102c110c95c52c53; /* fn_45 */
pointer global_c102c110c95c52c54;
function_204:
  goto top_level_apply;
function_205:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  target = (&&function_204);
  goto apply_addr;
function_206:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_205);
  goto apply_addr;
function_207:
  increment_count(env);
  val = wrap_function((&&function_206), env);
  goto pop_function;
/* fn_46 */
body_86:
global_c102c110c95c52c53 = NIL; /* fn_45 */
  increment_count(env);
  val = wrap_function((&&function_207), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_87;
pointer global_c102c110c95c52c52; /* fn_44 */
function_208:
  goto top_level_apply;
function_209:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  target = (&&function_208);
  goto apply_addr;
function_210:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c53); /* ___l_15 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_209);
  goto apply_addr;
function_211:
  increment_count(env);
  val = wrap_function((&&function_210), env);
  goto pop_function;
/* fn_45 */
body_87:
global_c102c110c95c52c52 = NIL; /* fn_44 */
  increment_count(env);
  val = wrap_function((&&function_211), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_88;
pointer global_c102c110c95c52c51; /* fn_43 */
function_212:
  goto top_level_apply;
function_213:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  target = (&&function_212);
  goto apply_addr;
function_214:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c52); /* ___l_14 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_213);
  goto apply_addr;
function_215:
  increment_count(env);
  val = wrap_function((&&function_214), env);
  goto pop_function;
/* fn_44 */
body_88:
global_c102c110c95c52c51 = NIL; /* fn_43 */
  increment_count(env);
  val = wrap_function((&&function_215), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_89;
pointer global_c102c110c95c52c50; /* fn_42 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109; /* ____transform */
function_216:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_217:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  target = (&&function_216);
  goto apply_addr;
function_218:
  increment_count(env);
  val = wrap_function((&&function_217), env);
  goto pop_function;
/* fn_43 */
body_89:
global_c102c110c95c52c50 = NIL; /* fn_42 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = NIL; /* ____transform */
  increment_count(env);
  val = wrap_function((&&function_218), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_90;
pointer global_c102c110c95c52c49; /* fn_41 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115; /* ____transform-args */
function_219:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_220:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  target = (&&function_219);
  goto apply_addr;
function_221:
  increment_count(env);
  val = wrap_function((&&function_220), env);
  goto pop_function;
/* fn_42 */
body_90:
global_c102c110c95c52c49 = NIL; /* fn_41 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = NIL; /* ____transform-args */
  increment_count(env);
  val = wrap_function((&&function_221), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_91;
function_222:
  push_args();
  increment_count(val = car(car(env)));
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_223:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  goto pop_function;
/* fn_41 */
body_91:
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_92;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108;
function_224:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-application-tail-call */
  goto body_93;
/* ____transform-application-tail-call */
body_92:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  target = (&&function_224);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_93:
  val = NIL;
  push_args();
  args = val;
  val = new_number(101);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_94;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_94:
  val = NIL;
  push_args();
  args = val;
  val = new_number(110);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_95;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_95:
  val = NIL;
  push_args();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_96;
pointer global_c102c110c95c53c51; /* fn_53 */
pointer global_c102c110c95c53c52;
function_225:
  goto top_level_apply;
function_226:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  target = (&&function_225);
  goto apply_addr;
function_227:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_226);
  goto apply_addr;
function_228:
  increment_count(env);
  val = wrap_function((&&function_227), env);
  goto pop_function;
/* fn_54 */
body_96:
global_c102c110c95c53c51 = NIL; /* fn_53 */
  increment_count(env);
  val = wrap_function((&&function_228), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_97;
pointer global_c102c110c95c53c50; /* fn_52 */
function_229:
  goto top_level_apply;
function_230:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  target = (&&function_229);
  goto apply_addr;
function_231:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56); /* ___l_18 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_230);
  goto apply_addr;
function_232:
  increment_count(env);
  val = wrap_function((&&function_231), env);
  goto pop_function;
/* fn_53 */
body_97:
global_c102c110c95c53c50 = NIL; /* fn_52 */
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_98;
pointer global_c102c110c95c53c49; /* fn_51 */
function_233:
  goto top_level_apply;
function_234:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  target = (&&function_233);
  goto apply_addr;
function_235:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55); /* ___l_17 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_234);
  goto apply_addr;
function_236:
  increment_count(env);
  val = wrap_function((&&function_235), env);
  goto pop_function;
/* fn_52 */
body_98:
global_c102c110c95c53c49 = NIL; /* fn_51 */
  increment_count(env);
  val = wrap_function((&&function_236), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_99;
pointer global_c102c110c95c53c48; /* fn_50 */
function_237:
  goto top_level_apply;
function_238:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
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
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  target = (&&function_237);
  goto apply_addr;
function_239:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_238);
  goto apply_addr;
function_240:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  goto pop_function;
/* fn_51 */
body_99:
global_c102c110c95c53c48 = NIL; /* fn_50 */
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_100;
pointer global_c102c110c95c52c57; /* fn_49 */
function_241:
  goto top_level_apply;
function_242:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  target = (&&function_241);
  goto apply_addr;
function_243:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-tail-call */
  target = (&&function_242);
  goto apply_addr;
function_244:
  increment_count(env);
  val = wrap_function((&&function_243), env);
  goto pop_function;
/* fn_50 */
body_100:
global_c102c110c95c52c57 = NIL; /* fn_49 */
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_101;
pointer global_c102c110c95c52c56; /* fn_48 */
function_245:
  goto top_level_apply;
function_246:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  target = (&&function_245);
  goto apply_addr;
function_247:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-tail-call */
  target = (&&function_246);
  goto apply_addr;
function_248:
  increment_count(env);
  val = wrap_function((&&function_247), env);
  goto pop_function;
/* fn_49 */
body_101:
global_c102c110c95c52c56 = NIL; /* fn_48 */
  increment_count(env);
  val = wrap_function((&&function_248), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_102;
pointer global_c102c110c95c52c55; /* fn_47 */
function_249:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_250:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  target = (&&function_249);
  goto apply_addr;
function_251:
  increment_count(env);
  val = wrap_function((&&function_250), env);
  goto pop_function;
/* fn_48 */
body_102:
global_c102c110c95c52c55 = NIL; /* fn_47 */
  increment_count(env);
  val = wrap_function((&&function_251), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_103;
function_252:
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
  push_args();
  val = NIL;
  args = val;
  val = NIL;
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -38;
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
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -37;
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
  goto pop_function;
function_253:
  increment_count(env);
  val = wrap_function((&&function_252), env);
  goto pop_function;
/* fn_47 */
body_103:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_104;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108;
function_254:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-if-tail-call */
  goto body_105;
/* ____transform-if-tail-call */
body_104:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  target = (&&function_254);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_105:
  val = NIL;
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_106;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_106:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_107;
pointer global_c102c110c95c53c53;
function_255:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
  } else {
    val = -43;
    goto pop_function;
  }
function_256:
  increment_count(env);
  val = wrap_function((&&function_255), env);
  goto pop_function;
/* fn_55 */
body_107:
  increment_count(env);
  val = wrap_function((&&function_256), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_108;
pointer global_c95c110c111c116;
function_257:
  global_c95c110c111c116 = val; /* _not */
  goto body_109;
/* _not */
body_108:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  target = (&&function_257);
  goto apply_addr;
pointer global_c102c110c95c53c55; /* fn_57 */
pointer global_c102c110c95c53c56;
function_258:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_259:
  goto top_level_apply;
function_260:
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
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  target = (&&function_259);
  goto apply_addr;
function_261:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
    target = (&&function_258);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
    target = (&&function_260);
    goto apply_addr;
  }
function_262:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_261);
  goto apply_addr;
function_263:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
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
      increment_count(val = car(cdr(cdr(car(env)))));
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
      increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115); /* ____builtins */
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
      target = (&&function_262);
      goto apply_addr;
    }
  }
function_264:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_263);
  goto apply_addr;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* fn_58 */
body_109:
global_c102c110c95c53c55 = NIL; /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_110;
pointer global_c102c110c95c53c54; /* fn_56 */
function_266:
  goto top_level_apply;
function_267:
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
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  target = (&&function_266);
  goto apply_addr;
function_268:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_267);
  goto apply_addr;
function_269:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_268);
  goto apply_addr;
function_270:
  increment_count(env);
  val = wrap_function((&&function_269), env);
  goto pop_function;
/* fn_57 */
body_110:
global_c102c110c95c53c54 = NIL; /* fn_56 */
  increment_count(env);
  val = wrap_function((&&function_270), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_111;
function_271:
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
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
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
  val = -37;
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
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_272:
  increment_count(env);
  val = wrap_function((&&function_271), env);
  goto pop_function;
/* fn_56 */
body_111:
  increment_count(env);
  val = wrap_function((&&function_272), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_112;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108;
function_273:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-atom-tail-call */
  goto body_113;
/* ____transform-atom-tail-call */
body_112:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  target = (&&function_273);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_113:
  val = -37;
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_114;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_114:
  val = -38;
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_115;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_115:
  val = -42;
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_116;
pointer global_c102c110c95c53c57;
function_274:
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
function_275:
  increment_count(env);
  val = wrap_function((&&function_274), env);
  goto pop_function;
/* fn_59 */
body_116:
  increment_count(env);
  val = wrap_function((&&function_275), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_117;
pointer global_c95c99c97c100c114;
function_276:
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_118;
/* _cadr */
body_117:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  target = (&&function_276);
  goto apply_addr;
pointer global_c102c110c95c54c48;
function_277:
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
  goto pop_function;
function_278:
  increment_count(env);
  val = wrap_function((&&function_277), env);
  goto pop_function;
/* fn_60 */
body_118:
  increment_count(env);
  val = wrap_function((&&function_278), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_119;
pointer global_c95c99c100c100c114;
function_279:
  global_c95c99c100c100c114 = val; /* _cddr */
  goto body_120;
/* _cddr */
body_119:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  target = (&&function_279);
  goto apply_addr;
pointer global_c102c110c95c54c49;
function_280:
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
function_281:
  increment_count(env);
  val = wrap_function((&&function_280), env);
  goto pop_function;
/* fn_61 */
body_120:
  increment_count(env);
  val = wrap_function((&&function_281), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  goto body_121;
pointer global_c95c99c97c100c100c114;
function_282:
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_122;
/* _caddr */
body_121:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  target = (&&function_282);
  goto apply_addr;
pointer global_c102c110c95c54c50;
function_283:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108); /* ____transform-fn-tail-call */
  goto top_level_apply;
function_284:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_283);
  goto apply_addr;
function_285:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108); /* ____transform-if-tail-call */
  goto top_level_apply;
function_286:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_285);
  goto apply_addr;
function_287:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  target = (&&function_286);
  goto apply_addr;
function_288:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_287);
  goto apply_addr;
function_289:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108); /* ____transform-application-tail-call */
    goto top_level_apply;
  }
function_290:
  if (val != NIL) {
    decrement_count(val);
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c100c100c114); /* _cddr */
    target = (&&function_288);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c51); /* ___l_23 */
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
    target = (&&function_289);
    goto apply_addr;
  }
function_291:
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    target = (&&function_284);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c50); /* ___l_22 */
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
    target = (&&function_290);
    goto apply_addr;
  }
function_292:
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-atom-tail-call */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c49); /* ___l_21 */
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
    target = (&&function_291);
    goto apply_addr;
  }
function_293:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_292);
  goto apply_addr;
function_294:
  increment_count(env);
  val = wrap_function((&&function_293), env);
  goto pop_function;
/* fn_62 */
body_122:
  increment_count(env);
  val = wrap_function((&&function_294), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_123;
function_295:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-tail-call */
  goto body_124;
/* ____transform-tail-call */
body_123:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  target = (&&function_295);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_124:
  val = NIL;
  push_args();
  args = val;
  val = new_number(121);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(98);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_125;
pointer global_c102c110c95c54c54; /* fn_66 */
pointer global_c102c110c95c54c55;
function_296:
  goto top_level_apply;
function_297:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  target = (&&function_296);
  goto apply_addr;
function_298:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_297);
  goto apply_addr;
function_299:
  increment_count(env);
  val = wrap_function((&&function_298), env);
  goto pop_function;
/* fn_67 */
body_125:
global_c102c110c95c54c54 = NIL; /* fn_66 */
  increment_count(env);
  val = wrap_function((&&function_299), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  goto body_126;
pointer global_c102c110c95c54c53; /* fn_65 */
function_300:
  goto top_level_apply;
function_301:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  target = (&&function_300);
  goto apply_addr;
function_302:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_301);
  goto apply_addr;
function_303:
  increment_count(env);
  val = wrap_function((&&function_302), env);
  goto pop_function;
/* fn_66 */
body_126:
global_c102c110c95c54c53 = NIL; /* fn_65 */
  increment_count(env);
  val = wrap_function((&&function_303), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  goto body_127;
pointer global_c102c110c95c54c52; /* fn_64 */
function_304:
  goto top_level_apply;
function_305:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  target = (&&function_304);
  goto apply_addr;
function_306:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_305);
  goto apply_addr;
function_307:
  increment_count(env);
  val = wrap_function((&&function_306), env);
  goto pop_function;
/* fn_65 */
body_127:
global_c102c110c95c54c52 = NIL; /* fn_64 */
  increment_count(env);
  val = wrap_function((&&function_307), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  goto body_128;
pointer global_c102c110c95c54c51; /* fn_63 */
function_308:
  goto top_level_apply;
function_309:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  target = (&&function_308);
  goto apply_addr;
function_310:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-tail-call */
  target = (&&function_309);
  goto apply_addr;
function_311:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  goto pop_function;
/* fn_64 */
body_128:
global_c102c110c95c54c51 = NIL; /* fn_63 */
  increment_count(env);
  val = wrap_function((&&function_311), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  goto body_129;
function_312:
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
  increment_count(val = car(car(env)));
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
  val = -37;
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
function_313:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  goto pop_function;
/* fn_63 */
body_129:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_130;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110;
function_314:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 = val; /* ____transform-fn */
  goto body_131;
/* ____transform-fn */
body_130:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  target = (&&function_314);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_131:
  val = NIL;
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_132;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_132:
  val = NIL;
  push_args();
  args = val;
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_133;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_133:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_134;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_134:
  val = NIL;
  push_args();
  args = val;
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_135;
pointer global_c102c110c95c54c56;
function_315:
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
function_316:
  increment_count(env);
  val = wrap_function((&&function_315), env);
  goto pop_function;
/* fn_68 */
body_135:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  goto body_136;
pointer global_c95c114c101c118c101c114c115c101;
function_317:
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_137;
/* _reverse */
body_136:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  target = (&&function_317);
  goto apply_addr;
pointer global_c102c110c95c55c53; /* fn_75 */
pointer global_c102c110c95c55c49; /* fn_71 */
pointer global_c102c110c95c55c54;
function_318:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_319:
  goto top_level_apply;
function_320:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  target = (&&function_319);
  goto apply_addr;
function_321:
  goto top_level_apply;
function_322:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  target = (&&function_321);
  goto apply_addr;
function_323:
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
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
    target = (&&function_320);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
    target = (&&function_322);
    goto apply_addr;
  }
function_324:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101); /* _reverse */
    target = (&&function_318);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_323);
    goto apply_addr;
  }
function_325:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_324);
  goto apply_addr;
function_326:
  increment_count(env);
  val = wrap_function((&&function_325), env);
  goto pop_function;
/* fn_76 */
body_137:
global_c102c110c95c55c53 = NIL; /* fn_75 */
global_c102c110c95c55c49 = NIL; /* fn_71 */
  increment_count(env);
  val = wrap_function((&&function_326), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  goto body_138;
pointer global_c102c110c95c55c48; /* fn_70 */
function_327:
  goto top_level_apply;
function_328:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  target = (&&function_327);
  goto apply_addr;
function_329:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_328);
  goto apply_addr;
function_330:
  increment_count(env);
  val = wrap_function((&&function_329), env);
  goto pop_function;
/* fn_71 */
body_138:
global_c102c110c95c55c48 = NIL; /* fn_70 */
  increment_count(env);
  val = wrap_function((&&function_330), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  goto body_139;
pointer global_c102c110c95c54c57; /* fn_69 */
function_331:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_332:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c57); /* fn_69 */
  target = (&&function_331);
  goto apply_addr;
function_333:
  increment_count(env);
  val = wrap_function((&&function_332), env);
  goto pop_function;
/* fn_70 */
body_139:
global_c102c110c95c54c57 = NIL; /* fn_69 */
  increment_count(env);
  val = wrap_function((&&function_333), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  goto body_140;
function_334:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_335:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_334);
  goto apply_addr;
function_336:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c114c101c118c101c114c115c101); /* _reverse */
  target = (&&function_335);
  goto apply_addr;
function_337:
  increment_count(env);
  val = wrap_function((&&function_336), env);
  goto pop_function;
/* fn_69 */
body_140:
  increment_count(env);
  val = wrap_function((&&function_337), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  goto body_141;
pointer global_c102c110c95c55c52; /* fn_74 */
function_338:
  goto top_level_apply;
function_339:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  target = (&&function_338);
  goto apply_addr;
function_340:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c56); /* ___l_28 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_339);
  goto apply_addr;
function_341:
  increment_count(env);
  val = wrap_function((&&function_340), env);
  goto pop_function;
/* fn_75 */
body_141:
global_c102c110c95c55c52 = NIL; /* fn_74 */
  increment_count(env);
  val = wrap_function((&&function_341), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  goto body_142;
pointer global_c102c110c95c55c51; /* fn_73 */
function_342:
  goto top_level_apply;
function_343:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  target = (&&function_342);
  goto apply_addr;
function_344:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c55); /* ___l_27 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_343);
  goto apply_addr;
function_345:
  increment_count(env);
  val = wrap_function((&&function_344), env);
  goto pop_function;
/* fn_74 */
body_142:
global_c102c110c95c55c51 = NIL; /* fn_73 */
  increment_count(env);
  val = wrap_function((&&function_345), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  goto body_143;
pointer global_c102c110c95c55c50; /* fn_72 */
function_346:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_347:
  push_args();
  val = NIL;
  args = val;
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
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  target = (&&function_346);
  goto apply_addr;
function_348:
  increment_count(env);
  val = wrap_function((&&function_347), env);
  goto pop_function;
/* fn_73 */
body_143:
global_c102c110c95c55c50 = NIL; /* fn_72 */
  increment_count(env);
  val = wrap_function((&&function_348), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  goto body_144;
function_349:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_350:
  increment_count(env);
  val = wrap_function((&&function_349), env);
  goto pop_function;
/* fn_72 */
body_144:
  increment_count(env);
  val = wrap_function((&&function_350), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  goto body_145;
function_351:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = val; /* ____transform-args */
  goto body_146;
/* ____transform-args */
body_145:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  target = (&&function_351);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_146:
  val = NIL;
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_147;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_147:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_148;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_148:
  val = NIL;
  push_args();
  args = val;
  val = new_number(112);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_149;
pointer global_c102c110c95c56c49; /* fn_81 */
pointer global_c102c110c95c56c50;
function_352:
  goto top_level_apply;
function_353:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  target = (&&function_352);
  goto apply_addr;
function_354:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_353);
  goto apply_addr;
function_355:
  increment_count(env);
  val = wrap_function((&&function_354), env);
  goto pop_function;
/* fn_82 */
body_149:
global_c102c110c95c56c49 = NIL; /* fn_81 */
  increment_count(env);
  val = wrap_function((&&function_355), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  goto body_150;
pointer global_c102c110c95c56c48; /* fn_80 */
function_356:
  goto top_level_apply;
function_357:
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
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  target = (&&function_356);
  goto apply_addr;
function_358:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
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
/* fn_81 */
body_150:
global_c102c110c95c56c48 = NIL; /* fn_80 */
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  goto body_151;
pointer global_c102c110c95c55c57; /* fn_79 */
function_360:
  goto top_level_apply;
function_361:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c57); /* fn_79 */
  target = (&&function_360);
  goto apply_addr;
function_362:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_361);
  goto apply_addr;
function_363:
  increment_count(env);
  val = wrap_function((&&function_362), env);
  goto pop_function;
/* fn_80 */
body_151:
global_c102c110c95c55c57 = NIL; /* fn_79 */
  increment_count(env);
  val = wrap_function((&&function_363), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  goto body_152;
pointer global_c102c110c95c55c56; /* fn_78 */
function_364:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_365:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  target = (&&function_364);
  goto apply_addr;
function_366:
  increment_count(env);
  val = wrap_function((&&function_365), env);
  goto pop_function;
/* fn_79 */
body_152:
global_c102c110c95c55c56 = NIL; /* fn_78 */
  increment_count(env);
  val = wrap_function((&&function_366), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  goto body_153;
pointer global_c102c110c95c55c55; /* fn_77 */
function_367:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_368:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c55); /* fn_77 */
  target = (&&function_367);
  goto apply_addr;
function_369:
  increment_count(env);
  val = wrap_function((&&function_368), env);
  goto pop_function;
/* fn_78 */
body_153:
global_c102c110c95c55c55 = NIL; /* fn_77 */
  increment_count(env);
  val = wrap_function((&&function_369), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  goto body_154;
function_370:
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
  val = NIL;
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
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_371:
  push_args();
  increment_count(val = car(car(env)));
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_370);
  goto apply_addr;
function_372:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  goto pop_function;
/* fn_77 */
body_154:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  goto body_155;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110;
function_373:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110 = val; /* ____transform-application */
  goto body_156;
/* ____transform-application */
body_155:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  target = (&&function_373);
  goto apply_addr;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_156:
  val = NIL;
  push_args();
  args = val;
  val = new_number(101);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_157;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_157:
  val = NIL;
  push_args();
  args = val;
  val = new_number(110);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_158;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_158:
  val = NIL;
  push_args();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_159;
pointer global_c102c110c95c56c57; /* fn_89 */
pointer global_c102c110c95c57c48;
function_374:
  goto top_level_apply;
function_375:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  target = (&&function_374);
  goto apply_addr;
function_376:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_375);
  goto apply_addr;
function_377:
  increment_count(env);
  val = wrap_function((&&function_376), env);
  goto pop_function;
/* fn_90 */
body_159:
global_c102c110c95c56c57 = NIL; /* fn_89 */
  increment_count(env);
  val = wrap_function((&&function_377), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  goto body_160;
pointer global_c102c110c95c56c56; /* fn_88 */
function_378:
  goto top_level_apply;
function_379:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c56); /* fn_88 */
  target = (&&function_378);
  goto apply_addr;
function_380:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52); /* ___l_34 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_379);
  goto apply_addr;
function_381:
  increment_count(env);
  val = wrap_function((&&function_380), env);
  goto pop_function;
/* fn_89 */
body_160:
global_c102c110c95c56c56 = NIL; /* fn_88 */
  increment_count(env);
  val = wrap_function((&&function_381), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  goto body_161;
pointer global_c102c110c95c56c55; /* fn_87 */
function_382:
  goto top_level_apply;
function_383:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c55); /* fn_87 */
  target = (&&function_382);
  goto apply_addr;
function_384:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_383);
  goto apply_addr;
function_385:
  increment_count(env);
  val = wrap_function((&&function_384), env);
  goto pop_function;
/* fn_88 */
body_161:
global_c102c110c95c56c55 = NIL; /* fn_87 */
  increment_count(env);
  val = wrap_function((&&function_385), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  goto body_162;
pointer global_c102c110c95c56c54; /* fn_86 */
function_386:
  goto top_level_apply;
function_387:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
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
  increment_count(val = global_c102c110c95c56c54); /* fn_86 */
  target = (&&function_386);
  goto apply_addr;
function_388:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_387);
  goto apply_addr;
function_389:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  goto pop_function;
/* fn_87 */
body_162:
global_c102c110c95c56c54 = NIL; /* fn_86 */
  increment_count(env);
  val = wrap_function((&&function_389), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  goto body_163;
pointer global_c102c110c95c56c53; /* fn_85 */
function_390:
  goto top_level_apply;
function_391:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  target = (&&function_390);
  goto apply_addr;
function_392:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  target = (&&function_391);
  goto apply_addr;
function_393:
  increment_count(env);
  val = wrap_function((&&function_392), env);
  goto pop_function;
/* fn_86 */
body_163:
global_c102c110c95c56c53 = NIL; /* fn_85 */
  increment_count(env);
  val = wrap_function((&&function_393), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  goto body_164;
pointer global_c102c110c95c56c52; /* fn_84 */
function_394:
  goto top_level_apply;
function_395:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  target = (&&function_394);
  goto apply_addr;
function_396:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  target = (&&function_395);
  goto apply_addr;
function_397:
  increment_count(env);
  val = wrap_function((&&function_396), env);
  goto pop_function;
/* fn_85 */
body_164:
global_c102c110c95c56c52 = NIL; /* fn_84 */
  increment_count(env);
  val = wrap_function((&&function_397), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  goto body_165;
pointer global_c102c110c95c56c51; /* fn_83 */
function_398:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_399:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  target = (&&function_398);
  goto apply_addr;
function_400:
  increment_count(env);
  val = wrap_function((&&function_399), env);
  goto pop_function;
/* fn_84 */
body_165:
global_c102c110c95c56c51 = NIL; /* fn_83 */
  increment_count(env);
  val = wrap_function((&&function_400), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  goto body_166;
function_401:
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
  push_args();
  val = NIL;
  args = val;
  val = NIL;
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -38;
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
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = -37;
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
  goto pop_function;
function_402:
  increment_count(env);
  val = wrap_function((&&function_401), env);
  goto pop_function;
/* fn_83 */
body_166:
  increment_count(env);
  val = wrap_function((&&function_402), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  goto body_167;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102;
function_403:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 = val; /* ____transform-if */
  goto body_168;
/* ____transform-if */
body_167:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  target = (&&function_403);
  goto apply_addr;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_168:
  val = NIL;
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_169;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_169:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = new_number(103);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_170;
pointer global_c102c110c95c57c50; /* fn_92 */
pointer global_c102c110c95c57c51;
function_404:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  goto top_level_apply;
function_405:
  goto top_level_apply;
function_406:
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
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  target = (&&function_405);
  goto apply_addr;
function_407:
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
    target = (&&function_404);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
    target = (&&function_406);
    goto apply_addr;
  }
function_408:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_407);
  goto apply_addr;
function_409:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
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
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(car(env)))));
      goto top_level_apply;
    } else {
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115); /* ____builtins */
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
      target = (&&function_408);
      goto apply_addr;
    }
  }
function_410:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c53); /* ___l_35 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_409);
  goto apply_addr;
function_411:
  increment_count(env);
  val = wrap_function((&&function_410), env);
  goto pop_function;
/* fn_93 */
body_170:
global_c102c110c95c57c50 = NIL; /* fn_92 */
  increment_count(env);
  val = wrap_function((&&function_411), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  goto body_171;
pointer global_c102c110c95c57c49; /* fn_91 */
function_412:
  goto top_level_apply;
function_413:
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
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  target = (&&function_412);
  goto apply_addr;
function_414:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_413);
  goto apply_addr;
function_415:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c54); /* ___l_36 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_414);
  goto apply_addr;
function_416:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  goto pop_function;
/* fn_92 */
body_171:
global_c102c110c95c57c49 = NIL; /* fn_91 */
  increment_count(env);
  val = wrap_function((&&function_416), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  goto body_172;
function_417:
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
  increment_count(val = car(car(env)));
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
  val = -37;
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
function_418:
  increment_count(env);
  val = wrap_function((&&function_417), env);
  goto pop_function;
/* fn_91 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_418), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  goto body_173;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109;
function_419:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109 = val; /* ____transform-atom */
  goto body_174;
/* ____transform-atom */
body_173:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c51); /* fn_93 */
  target = (&&function_419);
  goto apply_addr;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_174:
  val = -37;
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_175;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_175:
  val = -38;
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_176;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_176:
  val = -42;
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_177;
pointer global_c102c110c95c57c52;
function_420:
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
function_421:
  increment_count(env);
  val = wrap_function((&&function_420), env);
  goto pop_function;
/* fn_94 */
body_177:
  increment_count(env);
  val = wrap_function((&&function_421), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  goto body_178;
pointer global_c95c99c97c100c100c100c114;
function_422:
  global_c95c99c97c100c100c100c114 = val; /* _cadddr */
  goto body_179;
/* _cadddr */
body_178:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  target = (&&function_422);
  goto apply_addr;
pointer global_c102c110c95c57c53;
function_423:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110); /* ____transform-fn */
  goto top_level_apply;
function_424:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_423);
  goto apply_addr;
function_425:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102); /* ____transform-if */
  goto top_level_apply;
function_426:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_425);
  goto apply_addr;
function_427:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  target = (&&function_426);
  goto apply_addr;
function_428:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110); /* ____transform-application */
    goto top_level_apply;
  }
function_429:
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c97c100c100c100c114); /* _cadddr */
    target = (&&function_427);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c57); /* ___l_39 */
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
    target = (&&function_428);
    goto apply_addr;
  }
function_430:
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    target = (&&function_424);
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
    target = (&&function_429);
    goto apply_addr;
  }
function_431:
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109); /* ____transform-atom */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c55); /* ___l_37 */
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
    target = (&&function_430);
    goto apply_addr;
  }
function_432:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_431);
  goto apply_addr;
function_433:
  increment_count(env);
  val = wrap_function((&&function_432), env);
  goto pop_function;
/* fn_95 */
body_179:
  increment_count(env);
  val = wrap_function((&&function_433), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  goto body_180;
function_434:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = val; /* ____transform */
  goto body_181;
/* ____transform */
body_180:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  target = (&&function_434);
  goto apply_addr;
pointer global_c102c110c95c57c54; /* fn_96 */
pointer global_c102c110c95c57c55;
function_435:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101); /* ____initial-symbol-name */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_436:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c54); /* fn_96 */
  target = (&&function_435);
  goto apply_addr;
function_437:
  increment_count(env);
  val = wrap_function((&&function_436), env);
  goto pop_function;
/* fn_97 */
body_181:
global_c102c110c95c57c54 = NIL; /* fn_96 */
  increment_count(env);
  val = wrap_function((&&function_437), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  goto body_182;
function_438:
  increment_count(val = car(car(env)));
  goto pop_function;
function_439:
  increment_count(env);
  val = wrap_function((&&function_438), env);
  goto pop_function;
/* fn_96 */
body_182:
  increment_count(env);
  val = wrap_function((&&function_439), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  goto body_183;
pointer global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110;
function_440:
  global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 = val; /* ____cps-transformation */
  goto body_184;
/* ____cps-transformation */
body_183:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c55); /* fn_97 */
  target = (&&function_440);
  goto apply_addr;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_184:
  val = -39;
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_185;
pointer global_c102c110c95c57c56;
function_441:
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
  goto pop_function;
function_442:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_441);
  goto apply_addr;
function_443:
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_442);
  goto apply_addr;
function_444:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110); /* ____cps-transformation */
  target = (&&function_443);
  goto apply_addr;
function_445:
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
  goto pop_function;
function_446:
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
    increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
    target = (&&function_444);
    goto apply_addr;
  } else {
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110); /* ____cps-transformation */
    target = (&&function_445);
    goto apply_addr;
  }
function_447:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c48); /* ___l_40 */
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
  target = (&&function_446);
  goto apply_addr;
function_448:
  increment_count(env);
  val = wrap_function((&&function_447), env);
  goto pop_function;
/* fn_98 */
body_185:
  increment_count(env);
  val = wrap_function((&&function_448), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  goto body_186;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116;
function_449:
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 = val; /* ____transform-statement */
  goto body_187;
/* ____transform-statement */
body_186:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  target = (&&function_449);
  goto apply_addr;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_187:
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
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_188;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_188:
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
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_189;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_189:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_190;
pointer global_c102c110c95c57c57;
function_450:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_451:
  increment_count(env);
  val = wrap_function((&&function_450), env);
  goto pop_function;
/* fn_99 */
body_190:
  increment_count(env);
  val = wrap_function((&&function_451), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  goto body_191;
pointer global_c95c97c112c112c108c121;
function_452:
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_192;
/* _apply */
body_191:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  target = (&&function_452);
  goto apply_addr;
pointer global_c102c110c95c49c48c48; /* fn_100 */
pointer global_c102c110c95c49c48c49;
function_453:
  goto top_level_apply;
function_454:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_453);
  goto apply_addr;
function_455:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = -43;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  target = (&&function_454);
  goto apply_addr;
function_456:
  increment_count(env);
  val = wrap_function((&&function_455), env);
  goto pop_function;
/* fn_101 */
body_192:
global_c102c110c95c49c48c48 = NIL; /* fn_100 */
  increment_count(env);
  val = wrap_function((&&function_456), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  goto body_193;
function_457:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_458:
  increment_count(env);
  val = wrap_function((&&function_457), env);
  goto pop_function;
/* fn_100 */
body_193:
  increment_count(env);
  val = wrap_function((&&function_458), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  goto body_194;
pointer global_c95c97c110c100;
function_459:
  global_c95c97c110c100 = val; /* _and */
  goto body_195;
/* _and */
body_194:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  target = (&&function_459);
  goto apply_addr;
pointer global_c102c110c95c49c48c50;
function_460:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_461:
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
    target = (&&function_460);
    goto apply_addr;
  }
function_462:
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
    target = (&&function_461);
    goto apply_addr;
  }
function_463:
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_462);
  goto apply_addr;
function_464:
  increment_count(env);
  val = wrap_function((&&function_463), env);
  goto pop_function;
/* fn_102 */
body_195:
  increment_count(env);
  val = wrap_function((&&function_464), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  goto body_196;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_465:
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_197;
/* _escape-char */
body_196:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c50); /* fn_102 */
  target = (&&function_465);
  goto apply_addr;
pointer global_c102c110c95c49c48c51; /* fn_103 */
pointer global_c102c110c95c49c48c52;
function_466:
  goto top_level_apply;
function_467:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_466);
  goto apply_addr;
function_468:
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
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  target = (&&function_467);
  goto apply_addr;
function_469:
  increment_count(env);
  val = wrap_function((&&function_468), env);
  goto pop_function;
/* fn_104 */
body_197:
global_c102c110c95c49c48c51 = NIL; /* fn_103 */
  increment_count(env);
  val = wrap_function((&&function_469), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  goto body_198;
function_470:
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
function_471:
  increment_count(env);
  val = wrap_function((&&function_470), env);
  goto pop_function;
/* fn_103 */
body_198:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  goto body_199;
pointer global_c95c98c117c105c108c100c45c110c117c109;
function_472:
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  goto body_200;
/* _build-num */
body_199:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  target = (&&function_472);
  goto apply_addr;
pointer global_c102c110c95c49c48c53;
function_473:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -42;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_474:
  increment_count(env);
  val = wrap_function((&&function_473), env);
  goto pop_function;
/* fn_105 */
body_200:
  increment_count(env);
  val = wrap_function((&&function_474), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  goto body_201;
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
function_475:
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  goto body_202;
/* _quote-value */
body_201:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c53); /* fn_105 */
  target = (&&function_475);
  goto apply_addr;
pointer global_c102c110c95c49c48c54;
function_476:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_477:
  increment_count(env);
  val = wrap_function((&&function_476), env);
  goto pop_function;
/* fn_106 */
body_202:
  increment_count(env);
  val = wrap_function((&&function_477), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  goto body_203;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
function_478:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  goto body_204;
/* _quasiquote-value */
body_203:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  target = (&&function_478);
  goto apply_addr;
pointer global_c102c110c95c49c48c55;
function_479:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -40;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_480:
  increment_count(env);
  val = wrap_function((&&function_479), env);
  goto pop_function;
/* fn_107 */
body_204:
  increment_count(env);
  val = wrap_function((&&function_480), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  goto body_205;
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
function_481:
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  goto body_206;
/* _unquote-value */
body_205:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  target = (&&function_481);
  goto apply_addr;
pointer global_c102c110c95c49c48c56; /* fn_108 */
pointer global_c102c110c95c49c48c57;
function_482:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  goto top_level_apply;
function_483:
  increment_count(env);
  val = wrap_function((&&function_482), env);
  goto pop_function;
/* fn_109 */
body_206:
global_c102c110c95c49c48c56 = NIL; /* fn_108 */
  increment_count(env);
  val = wrap_function((&&function_483), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  goto body_207;
function_484:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  goto top_level_apply;
function_485:
  increment_count(env);
  val = wrap_function((&&function_484), env);
  goto pop_function;
/* fn_108 */
body_207:
  increment_count(env);
  val = wrap_function((&&function_485), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  goto body_208;
pointer global_c95c102c97c105c108;
function_486:
  global_c95c102c97c105c108 = val; /* _fail */
  goto body_209;
/* _fail */
body_208:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  target = (&&function_486);
  goto apply_addr;
pointer global_c102c110c95c49c49c48;
function_487:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_488:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  goto pop_function;
/* fn_110 */
body_209:
  increment_count(env);
  val = wrap_function((&&function_488), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  goto body_210;
pointer global_c95c100c111c110c101;
function_489:
  global_c95c100c111c110c101 = val; /* _done */
  goto body_211;
/* _done */
body_210:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  target = (&&function_489);
  goto apply_addr;
pointer global_c102c110c95c49c49c49; /* fn_111 */
pointer global_c102c110c95c49c49c50;
function_490:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  goto top_level_apply;
function_491:
  increment_count(env);
  val = wrap_function((&&function_490), env);
  goto pop_function;
/* fn_112 */
body_211:
global_c102c110c95c49c49c49 = NIL; /* fn_111 */
  increment_count(env);
  val = wrap_function((&&function_491), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  goto body_212;
pointer global_c95c112c111c112; /* _pop */
function_492:
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
function_493:
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
      target = (&&function_492);
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
function_494:
  increment_count(env);
  val = wrap_function((&&function_493), env);
  goto pop_function;
/* fn_111 */
body_212:
global_c95c112c111c112 = NIL; /* _pop */
  increment_count(env);
  val = wrap_function((&&function_494), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  goto body_213;
function_495:
  global_c95c112c111c112 = val; /* _pop */
  goto body_214;
/* _pop */
body_213:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  target = (&&function_495);
  goto apply_addr;
pointer global_c102c110c95c49c49c52; /* fn_114 */
pointer global_c102c110c95c49c49c53;
function_496:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  goto top_level_apply;
function_497:
  increment_count(env);
  val = wrap_function((&&function_496), env);
  goto pop_function;
/* fn_115 */
body_214:
global_c102c110c95c49c49c52 = NIL; /* fn_114 */
  increment_count(env);
  val = wrap_function((&&function_497), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  goto body_215;
pointer global_c102c110c95c49c49c51; /* fn_113 */
function_498:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  goto top_level_apply;
function_499:
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
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  target = (&&function_498);
  goto apply_addr;
function_500:
  increment_count(env);
  val = wrap_function((&&function_499), env);
  goto pop_function;
/* fn_114 */
body_215:
global_c102c110c95c49c49c51 = NIL; /* fn_113 */
  increment_count(env);
  val = wrap_function((&&function_500), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  goto body_216;
function_501:
  goto top_level_apply;
function_502:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_501);
  goto apply_addr;
function_503:
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
  target = (&&function_502);
  goto apply_addr;
function_504:
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
    target = (&&function_503);
    goto apply_addr;
  }
function_505:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_504);
  goto apply_addr;
function_506:
  increment_count(env);
  val = wrap_function((&&function_505), env);
  goto pop_function;
/* fn_113 */
body_216:
  increment_count(env);
  val = wrap_function((&&function_506), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  goto body_217;
pointer global_c95c99c104c101c99c107;
function_507:
  global_c95c99c104c101c99c107 = val; /* _check */
  goto body_218;
/* _check */
body_217:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  target = (&&function_507);
  goto apply_addr;
pointer global_c102c110c95c49c49c54; /* fn_116 */
pointer global_c102c110c95c49c49c55;
function_508:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_509:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  target = (&&function_508);
  goto apply_addr;
function_510:
  increment_count(env);
  val = wrap_function((&&function_509), env);
  goto pop_function;
/* fn_117 */
body_218:
global_c102c110c95c49c49c54 = NIL; /* fn_116 */
  increment_count(env);
  val = wrap_function((&&function_510), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  goto body_219;
function_511:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_512:
  increment_count(env);
  val = wrap_function((&&function_511), env);
  goto pop_function;
/* fn_116 */
body_219:
  increment_count(env);
  val = wrap_function((&&function_512), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  goto body_220;
pointer global_c95c109c97c116c99c104;
function_513:
  global_c95c109c97c116c99c104 = val; /* _match */
  goto body_221;
/* _match */
body_220:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  target = (&&function_513);
  goto apply_addr;
pointer global_c102c110c95c49c49c56; /* fn_118 */
pointer global_c102c110c95c49c49c57;
function_514:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  goto top_level_apply;
function_515:
  increment_count(env);
  val = wrap_function((&&function_514), env);
  goto pop_function;
/* fn_119 */
body_221:
global_c102c110c95c49c49c56 = NIL; /* fn_118 */
  increment_count(env);
  val = wrap_function((&&function_515), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  goto body_222;
function_516:
  increment_count(val = car(car(cdr(env))));
  goto pop_function;
function_517:
  increment_count(env);
  val = wrap_function((&&function_516), env);
  goto pop_function;
/* fn_118 */
body_222:
  increment_count(env);
  val = wrap_function((&&function_517), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  goto body_223;
pointer global_c95c100c101c102c97c117c108c116;
function_518:
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  goto body_224;
/* _default */
body_223:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  target = (&&function_518);
  goto apply_addr;
pointer global_c102c110c95c49c50c51; /* fn_123 */
pointer global_c102c110c95c49c50c52;
function_519:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  goto top_level_apply;
function_520:
  increment_count(env);
  val = wrap_function((&&function_519), env);
  goto pop_function;
/* fn_124 */
body_224:
global_c102c110c95c49c50c51 = NIL; /* fn_123 */
  increment_count(env);
  val = wrap_function((&&function_520), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  goto body_225;
pointer global_c102c110c95c49c50c50; /* fn_122 */
function_521:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  goto top_level_apply;
function_522:
  increment_count(env);
  val = wrap_function((&&function_521), env);
  goto pop_function;
/* fn_123 */
body_225:
global_c102c110c95c49c50c50 = NIL; /* fn_122 */
  increment_count(env);
  val = wrap_function((&&function_522), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  goto body_226;
pointer global_c102c110c95c49c50c49; /* fn_121 */
pointer global_c102c110c95c49c50c48; /* fn_120 */
function_523:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_524:
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
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  target = (&&function_523);
  goto apply_addr;
function_525:
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
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  target = (&&function_524);
  goto apply_addr;
function_526:
  increment_count(env);
  val = wrap_function((&&function_525), env);
  goto pop_function;
/* fn_122 */
body_226:
global_c102c110c95c49c50c49 = NIL; /* fn_121 */
global_c102c110c95c49c50c48 = NIL; /* fn_120 */
  increment_count(env);
  val = wrap_function((&&function_526), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  goto body_227;
function_527:
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
function_528:
  increment_count(env);
  val = wrap_function((&&function_527), env);
  goto pop_function;
/* fn_120 */
body_227:
  increment_count(env);
  val = wrap_function((&&function_528), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  goto body_228;
function_529:
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
function_530:
  increment_count(env);
  val = wrap_function((&&function_529), env);
  goto pop_function;
/* fn_121 */
body_228:
  increment_count(env);
  val = wrap_function((&&function_530), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  goto body_229;
pointer global_c95c99c97c115c101;
function_531:
  global_c95c99c97c115c101 = val; /* _case */
  goto body_230;
/* _case */
body_229:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  target = (&&function_531);
  goto apply_addr;
pointer global_c102c110c95c49c50c53; /* fn_125 */
pointer global_c102c110c95c49c50c54;
function_532:
  goto top_level_apply;
function_533:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_532);
  goto apply_addr;
function_534:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c53); /* fn_125 */
  target = (&&function_533);
  goto apply_addr;
function_535:
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
  target = (&&function_534);
  goto apply_addr;
function_536:
  increment_count(env);
  val = wrap_function((&&function_535), env);
  goto pop_function;
/* fn_126 */
body_230:
global_c102c110c95c49c50c53 = NIL; /* fn_125 */
  increment_count(env);
  val = wrap_function((&&function_536), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  goto body_231;
function_537:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_538:
  increment_count(env);
  val = wrap_function((&&function_537), env);
  goto pop_function;
/* fn_125 */
body_231:
  increment_count(env);
  val = wrap_function((&&function_538), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  goto body_232;
pointer global_c95c99c104c111c105c99c101;
function_539:
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  goto body_233;
/* _choice */
body_232:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  target = (&&function_539);
  goto apply_addr;
pointer global_c102c110c95c49c50c56; /* fn_128 */
pointer global_c102c110c95c49c50c57;
function_540:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
  goto top_level_apply;
function_541:
  increment_count(env);
  val = wrap_function((&&function_540), env);
  goto pop_function;
/* fn_129 */
body_233:
global_c102c110c95c49c50c56 = NIL; /* fn_128 */
  increment_count(env);
  val = wrap_function((&&function_541), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  goto body_234;
pointer global_c102c110c95c49c50c55; /* fn_127 */
function_542:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_543:
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
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  target = (&&function_542);
  goto apply_addr;
function_544:
  increment_count(env);
  val = wrap_function((&&function_543), env);
  goto pop_function;
/* fn_128 */
body_234:
global_c102c110c95c49c50c55 = NIL; /* fn_127 */
  increment_count(env);
  val = wrap_function((&&function_544), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  goto body_235;
function_545:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_546:
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
  target = (&&function_545);
  goto apply_addr;
function_547:
  increment_count(env);
  val = wrap_function((&&function_546), env);
  goto pop_function;
/* fn_127 */
body_235:
  increment_count(env);
  val = wrap_function((&&function_547), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  goto body_236;
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
function_548:
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  goto body_237;
/* _post-process */
body_236:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
  target = (&&function_548);
  goto apply_addr;
pointer global_c102c110c95c49c51c50; /* fn_132 */
pointer global_c102c110c95c49c51c51;
function_549:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  goto top_level_apply;
function_550:
  increment_count(env);
  val = wrap_function((&&function_549), env);
  goto pop_function;
/* fn_133 */
body_237:
global_c102c110c95c49c51c50 = NIL; /* fn_132 */
  increment_count(env);
  val = wrap_function((&&function_550), env);
  global_c102c110c95c49c51c51 = val; /* fn_133 */
  goto body_238;
pointer global_c102c110c95c49c51c49; /* fn_131 */
function_551:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_552:
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
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  target = (&&function_551);
  goto apply_addr;
function_553:
  increment_count(env);
  val = wrap_function((&&function_552), env);
  goto pop_function;
/* fn_132 */
body_238:
global_c102c110c95c49c51c49 = NIL; /* fn_131 */
  increment_count(env);
  val = wrap_function((&&function_553), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  goto body_239;
pointer global_c102c110c95c49c51c48; /* fn_130 */
function_554:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_555:
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
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  target = (&&function_554);
  goto apply_addr;
function_556:
  increment_count(env);
  val = wrap_function((&&function_555), env);
  goto pop_function;
/* fn_131 */
body_239:
global_c102c110c95c49c51c48 = NIL; /* fn_130 */
  increment_count(env);
  val = wrap_function((&&function_556), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  goto body_240;
function_557:
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
function_558:
  increment_count(env);
  val = wrap_function((&&function_557), env);
  goto pop_function;
/* fn_130 */
body_240:
  increment_count(env);
  val = wrap_function((&&function_558), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  goto body_241;
pointer global_c95c115c101c113;
function_559:
  global_c95c115c101c113 = val; /* _seq */
  goto body_242;
/* _seq */
body_241:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c51); /* fn_133 */
  target = (&&function_559);
  goto apply_addr;
pointer global_c102c110c95c49c51c52;
function_560:
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_561:
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
  target = (&&function_560);
  goto apply_addr;
function_562:
  increment_count(env);
  val = wrap_function((&&function_561), env);
  goto pop_function;
/* fn_134 */
body_242:
  increment_count(env);
  val = wrap_function((&&function_562), env);
  global_c102c110c95c49c51c52 = val; /* fn_134 */
  goto body_243;
pointer global_c95c101c115c99c97c112c101;
function_563:
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  goto body_244;
/* _escape */
body_243:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c52); /* fn_134 */
  target = (&&function_563);
  goto apply_addr;
pointer global_c102c110c95c49c51c53;
function_564:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_565:
  increment_count(env);
  val = wrap_function((&&function_564), env);
  goto pop_function;
/* fn_135 */
body_244:
  increment_count(env);
  val = wrap_function((&&function_565), env);
  global_c102c110c95c49c51c53 = val; /* fn_135 */
  goto body_245;
pointer global_c95c117c115c101;
function_566:
  global_c95c117c115c101 = val; /* _use */
  goto body_246;
/* _use */
body_245:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c53); /* fn_135 */
  target = (&&function_566);
  goto apply_addr;
pointer global_c102c110c95c49c51c55; /* fn_137 */
pointer global_c102c110c95c49c51c56;
function_567:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c55); /* fn_137 */
  goto top_level_apply;
function_568:
  increment_count(env);
  val = wrap_function((&&function_567), env);
  goto pop_function;
/* fn_138 */
body_246:
global_c102c110c95c49c51c55 = NIL; /* fn_137 */
  increment_count(env);
  val = wrap_function((&&function_568), env);
  global_c102c110c95c49c51c56 = val; /* fn_138 */
  goto body_247;
pointer global_c102c110c95c49c51c54; /* fn_136 */
function_569:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_570:
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
  increment_count(val = global_c102c110c95c49c51c54); /* fn_136 */
  target = (&&function_569);
  goto apply_addr;
function_571:
  increment_count(env);
  val = wrap_function((&&function_570), env);
  goto pop_function;
/* fn_137 */
body_247:
global_c102c110c95c49c51c54 = NIL; /* fn_136 */
  increment_count(env);
  val = wrap_function((&&function_571), env);
  global_c102c110c95c49c51c55 = val; /* fn_137 */
  goto body_248;
function_572:
  goto top_level_apply;
function_573:
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
  target = (&&function_572);
  goto apply_addr;
function_574:
  increment_count(env);
  val = wrap_function((&&function_573), env);
  goto pop_function;
/* fn_136 */
body_248:
  increment_count(env);
  val = wrap_function((&&function_574), env);
  global_c102c110c95c49c51c54 = val; /* fn_136 */
  goto body_249;
pointer global_c95c112c101c101c107;
function_575:
  global_c95c112c101c101c107 = val; /* _peek */
  goto body_250;
/* _peek */
body_249:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c56); /* fn_138 */
  target = (&&function_575);
  goto apply_addr;
pointer global_c102c110c95c49c51c57; /* fn_139 */
pointer global_c102c110c95c49c52c48;
function_576:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_577:
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
  increment_count(val = global_c102c110c95c49c51c57); /* fn_139 */
  target = (&&function_576);
  goto apply_addr;
function_578:
  increment_count(env);
  val = wrap_function((&&function_577), env);
  goto pop_function;
/* fn_140 */
body_250:
global_c102c110c95c49c51c57 = NIL; /* fn_139 */
  increment_count(env);
  val = wrap_function((&&function_578), env);
  global_c102c110c95c49c52c48 = val; /* fn_140 */
  goto body_251;
function_579:
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
function_580:
  increment_count(env);
  val = wrap_function((&&function_579), env);
  goto pop_function;
/* fn_139 */
body_251:
  increment_count(env);
  val = wrap_function((&&function_580), env);
  global_c102c110c95c49c51c57 = val; /* fn_139 */
  goto body_252;
pointer global_c95c105c110c116c101c114c118c97c108;
function_581:
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  goto body_253;
/* _interval */
body_252:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c48); /* fn_140 */
  target = (&&function_581);
  goto apply_addr;
pointer global_c99c100c114; /* cdr */
pointer global_c102c110c95c49c52c49;
function_582:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_583:
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
  target = (&&function_582);
  goto apply_addr;
function_584:
  increment_count(env);
  val = wrap_function((&&function_583), env);
  goto pop_function;
/* fn_141 */
body_253:
global_c99c100c114 = CDR; /* cdr */
  increment_count(env);
  val = wrap_function((&&function_584), env);
  global_c102c110c95c49c52c49 = val; /* fn_141 */
  goto body_254;
pointer global_c95c115c107c105c112;
function_585:
  global_c95c115c107c105c112 = val; /* _skip */
  goto body_255;
/* _skip */
body_254:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c49); /* fn_141 */
  target = (&&function_585);
  goto apply_addr;
pointer global_c99c97c114; /* car */
pointer global_c102c110c95c49c52c50;
function_586:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_587:
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
  target = (&&function_586);
  goto apply_addr;
function_588:
  increment_count(env);
  val = wrap_function((&&function_587), env);
  goto pop_function;
/* fn_142 */
body_255:
global_c99c97c114 = CAR; /* car */
  increment_count(env);
  val = wrap_function((&&function_588), env);
  global_c102c110c95c49c52c50 = val; /* fn_142 */
  goto body_256;
pointer global_c95c102c105c114c115c116;
function_589:
  global_c95c102c105c114c115c116 = val; /* _first */
  goto body_257;
/* _first */
body_256:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c50); /* fn_142 */
  target = (&&function_589);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c110c117c109; /* _parse-num */
pointer global_c102c110c95c49c52c51;
function_590:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_591:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_590);
  goto apply_addr;
function_592:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_591);
  goto apply_addr;
function_593:
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
  target = (&&function_592);
  goto apply_addr;
function_594:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_593);
  goto apply_addr;
function_595:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_594);
  goto apply_addr;
function_596:
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
  target = (&&function_595);
  goto apply_addr;
function_597:
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
  target = (&&function_596);
  goto apply_addr;
function_598:
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
  target = (&&function_597);
  goto apply_addr;
function_599:
  increment_count(env);
  val = wrap_function((&&function_598), env);
  goto pop_function;
/* fn_143 */
body_257:
global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
  increment_count(env);
  val = wrap_function((&&function_599), env);
  global_c102c110c95c49c52c51 = val; /* fn_143 */
  goto body_258;
function_600:
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  goto body_259;
/* _parse-num */
body_258:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c51); /* fn_143 */
  target = (&&function_600);
  goto apply_addr;
pointer global_c102c110c95c49c52c52;
function_601:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_602:
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
  target = (&&function_601);
  goto apply_addr;
function_603:
  increment_count(env);
  val = wrap_function((&&function_602), env);
  goto pop_function;
/* fn_144 */
body_259:
  increment_count(env);
  val = wrap_function((&&function_603), env);
  global_c102c110c95c49c52c52 = val; /* fn_144 */
  goto body_260;
pointer global_c95c114c101c97c100c45c110c117c109;
function_604:
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  goto body_261;
/* _read-num */
body_260:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c52); /* fn_144 */
  target = (&&function_604);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c49c52c53;
function_605:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_606:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_605);
  goto apply_addr;
function_607:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_606);
  goto apply_addr;
function_608:
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
  target = (&&function_607);
  goto apply_addr;
function_609:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_608);
  goto apply_addr;
function_610:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_609);
  goto apply_addr;
function_611:
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
  target = (&&function_610);
  goto apply_addr;
function_612:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_611);
  goto apply_addr;
function_613:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_612);
  goto apply_addr;
function_614:
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
  target = (&&function_613);
  goto apply_addr;
function_615:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_614);
  goto apply_addr;
function_616:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_615);
  goto apply_addr;
function_617:
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
  target = (&&function_616);
  goto apply_addr;
function_618:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_617);
  goto apply_addr;
function_619:
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
  target = (&&function_618);
  goto apply_addr;
function_620:
  increment_count(env);
  val = wrap_function((&&function_619), env);
  goto pop_function;
/* fn_145 */
body_261:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_620), env);
  global_c102c110c95c49c52c53 = val; /* fn_145 */
  goto body_262;
function_621:
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_263;
/* _parse-symbol */
body_262:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c53); /* fn_145 */
  target = (&&function_621);
  goto apply_addr;
pointer global_c102c110c95c49c52c54;
function_622:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_623:
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
  target = (&&function_622);
  goto apply_addr;
function_624:
  increment_count(env);
  val = wrap_function((&&function_623), env);
  goto pop_function;
/* fn_146 */
body_263:
  increment_count(env);
  val = wrap_function((&&function_624), env);
  global_c102c110c95c49c52c54 = val; /* fn_146 */
  goto body_264;
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
function_625:
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  goto body_265;
/* _read-symbol */
body_264:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c54); /* fn_146 */
  target = (&&function_625);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c102c110c95c49c52c55;
function_626:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_627:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_626);
  goto apply_addr;
function_628:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_627);
  goto apply_addr;
function_629:
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
  target = (&&function_628);
  goto apply_addr;
function_630:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_629);
  goto apply_addr;
function_631:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_630);
  goto apply_addr;
function_632:
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
  target = (&&function_631);
  goto apply_addr;
function_633:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_632);
  goto apply_addr;
function_634:
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
  target = (&&function_633);
  goto apply_addr;
function_635:
  increment_count(env);
  val = wrap_function((&&function_634), env);
  goto pop_function;
/* fn_147 */
body_265:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
  increment_count(env);
  val = wrap_function((&&function_635), env);
  global_c102c110c95c49c52c55 = val; /* fn_147 */
  goto body_266;
function_636:
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_267;
/* _parse-string */
body_266:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c55); /* fn_147 */
  target = (&&function_636);
  goto apply_addr;
pointer global_c102c110c95c49c52c56;
function_637:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c111c116c101c45c118c97c108c117c101); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_638:
  increment_count(env);
  val = wrap_function((&&function_637), env);
  goto pop_function;
/* fn_148 */
body_267:
  increment_count(env);
  val = wrap_function((&&function_638), env);
  global_c102c110c95c49c52c56 = val; /* fn_148 */
  goto body_268;
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
function_639:
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  goto body_269;
/* _quote-parser */
body_268:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c56); /* fn_148 */
  target = (&&function_639);
  goto apply_addr;
pointer global_c102c110c95c49c52c57;
function_640:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_641:
  increment_count(env);
  val = wrap_function((&&function_640), env);
  goto pop_function;
/* fn_149 */
body_269:
  increment_count(env);
  val = wrap_function((&&function_641), env);
  global_c102c110c95c49c52c57 = val; /* fn_149 */
  goto body_270;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
function_642:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  goto body_271;
/* _quasiquote-parser */
body_270:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c52c57); /* fn_149 */
  target = (&&function_642);
  goto apply_addr;
pointer global_c102c110c95c49c53c48;
function_643:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_644:
  increment_count(env);
  val = wrap_function((&&function_643), env);
  goto pop_function;
/* fn_150 */
body_271:
  increment_count(env);
  val = wrap_function((&&function_644), env);
  global_c102c110c95c49c53c48 = val; /* fn_150 */
  goto body_272;
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
function_645:
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  goto body_273;
/* _unquote-parser */
body_272:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c48); /* fn_150 */
  target = (&&function_645);
  goto apply_addr;
pointer global_c102c110c95c49c53c49; /* fn_151 */
pointer global_c102c110c95c49c53c50;
function_646:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c53c49); /* fn_151 */
  goto top_level_apply;
function_647:
  increment_count(env);
  val = wrap_function((&&function_646), env);
  goto pop_function;
/* fn_152 */
body_273:
global_c102c110c95c49c53c49 = NIL; /* fn_151 */
  increment_count(env);
  val = wrap_function((&&function_647), env);
  global_c102c110c95c49c53c50 = val; /* fn_152 */
  goto body_274;
pointer global_c95c99c111c109c109c101c110c116; /* _comment */
function_648:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_649:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_648);
  goto apply_addr;
function_650:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_649);
  goto apply_addr;
function_651:
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
  target = (&&function_650);
  goto apply_addr;
function_652:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_651);
  goto apply_addr;
function_653:
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
  target = (&&function_652);
  goto apply_addr;
function_654:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_653);
  goto apply_addr;
function_655:
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  target = (&&function_654);
  goto apply_addr;
function_656:
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
  target = (&&function_655);
  goto apply_addr;
function_657:
  increment_count(env);
  val = wrap_function((&&function_656), env);
  goto pop_function;
/* fn_151 */
body_274:
global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
  increment_count(env);
  val = wrap_function((&&function_657), env);
  global_c102c110c95c49c53c49 = val; /* fn_151 */
  goto body_275;
function_658:
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  goto body_276;
/* _comment */
body_275:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c50); /* fn_152 */
  target = (&&function_658);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c49c53c51;
function_659:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_660:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_659);
  goto apply_addr;
function_661:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_660);
  goto apply_addr;
function_662:
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
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_663);
  goto apply_addr;
function_665:
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
  target = (&&function_664);
  goto apply_addr;
function_666:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_665);
  goto apply_addr;
function_667:
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
  target = (&&function_666);
  goto apply_addr;
function_668:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
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
  target = (&&function_668);
  goto apply_addr;
function_670:
  increment_count(env);
  val = wrap_function((&&function_669), env);
  goto pop_function;
/* fn_153 */
body_276:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_670), env);
  global_c102c110c95c49c53c51 = val; /* fn_153 */
  goto body_277;
function_671:
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_278;
/* _parse-paren */
body_277:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c51); /* fn_153 */
  target = (&&function_671);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c49c53c52;
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
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114); /* _parse-pair */
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
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_680);
  goto apply_addr;
function_682:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_681);
  goto apply_addr;
function_683:
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
  target = (&&function_682);
  goto apply_addr;
function_684:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_683);
  goto apply_addr;
function_685:
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
  target = (&&function_684);
  goto apply_addr;
function_686:
  increment_count(env);
  val = wrap_function((&&function_685), env);
  goto pop_function;
/* fn_154 */
body_278:
global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_686), env);
  global_c102c110c95c49c53c52 = val; /* fn_154 */
  goto body_279;
function_687:
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_280;
/* _parse-pair */
body_279:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c52); /* fn_154 */
  target = (&&function_687);
  goto apply_addr;
pointer global_c102c110c95c49c53c53;
function_688:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_689:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_688);
  goto apply_addr;
function_690:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_689);
  goto apply_addr;
function_691:
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
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_692);
  goto apply_addr;
function_694:
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
  target = (&&function_693);
  goto apply_addr;
function_695:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_694);
  goto apply_addr;
function_696:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_695);
  goto apply_addr;
function_697:
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
  target = (&&function_696);
  goto apply_addr;
function_698:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_697);
  goto apply_addr;
function_699:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_698);
  goto apply_addr;
function_700:
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
  target = (&&function_699);
  goto apply_addr;
function_701:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_700);
  goto apply_addr;
function_702:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_701);
  goto apply_addr;
function_703:
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
  target = (&&function_702);
  goto apply_addr;
function_704:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_703);
  goto apply_addr;
function_705:
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
  target = (&&function_704);
  goto apply_addr;
function_706:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_705);
  goto apply_addr;
function_707:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_706);
  goto apply_addr;
function_708:
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
  target = (&&function_707);
  goto apply_addr;
function_709:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_708);
  goto apply_addr;
function_710:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_709);
  goto apply_addr;
function_711:
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
  target = (&&function_710);
  goto apply_addr;
function_712:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_711);
  goto apply_addr;
function_713:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_712);
  goto apply_addr;
function_714:
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
  target = (&&function_713);
  goto apply_addr;
function_715:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_714);
  goto apply_addr;
function_716:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_715);
  goto apply_addr;
function_717:
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
  target = (&&function_716);
  goto apply_addr;
function_718:
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
  target = (&&function_717);
  goto apply_addr;
function_719:
  increment_count(env);
  val = wrap_function((&&function_718), env);
  goto pop_function;
/* fn_155 */
body_280:
  increment_count(env);
  val = wrap_function((&&function_719), env);
  global_c102c110c95c49c53c53 = val; /* fn_155 */
  goto body_281;
function_720:
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_282;
/* _parse-expr */
body_281:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c53); /* fn_155 */
  target = (&&function_720);
  goto apply_addr;
pointer global_c102c110c95c49c53c54; /* fn_156 */
pointer global_c102c110c95c49c53c55;
function_721:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  goto top_level_apply;
function_722:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c54); /* fn_156 */
  target = (&&function_721);
  goto apply_addr;
function_723:
  increment_count(env);
  val = wrap_function((&&function_722), env);
  goto pop_function;
/* fn_157 */
body_282:
global_c102c110c95c49c53c54 = NIL; /* fn_156 */
  increment_count(env);
  val = wrap_function((&&function_723), env);
  global_c102c110c95c49c53c55 = val; /* fn_157 */
  goto body_283;
function_724:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  goto top_level_apply;
function_725:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c49); /* ___l_41 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_724);
  goto apply_addr;
function_726:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c51); /* ___l_43 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c50); /* ___l_42 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_725);
  goto apply_addr;
function_727:
  increment_count(env);
  val = wrap_function((&&function_726), env);
  goto pop_function;
/* fn_156 */
body_283:
  increment_count(env);
  val = wrap_function((&&function_727), env);
  global_c102c110c95c49c53c54 = val; /* fn_156 */
  goto body_284;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_728:
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_285;
/* ____read-expr */
body_284:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c55); /* fn_157 */
  target = (&&function_728);
  goto apply_addr;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_285:
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
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_286;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_286:
  val = -39;
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_287;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_287:
  val = NIL;
  push_args();
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = CDR;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -35;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = CAR;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = CONS;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -36;
  push_args();
  args = val;
  val = -35;
  args = cons(val, args);
  val = -34;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = FUNCTION;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = ATOM;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = NIL;
  push_args();
  args = val;
  val = -34;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  val = -35;
  args = cons(val, args);
  val = -39;
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_288;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_288:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_289;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_289:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_290;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_290:
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
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_291;
pointer global_c102c110c95c49c53c56;
function_729:
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
function_730:
  increment_count(env);
  val = wrap_function((&&function_729), env);
  goto pop_function;
/* fn_158 */
body_291:
  increment_count(env);
  val = wrap_function((&&function_730), env);
  global_c102c110c95c49c53c56 = val; /* fn_158 */
  goto body_292;
pointer global_c95c99c97c97c100c114;
function_731:
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_293;
/* _caadr */
body_292:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53c56); /* fn_158 */
  target = (&&function_731);
  goto apply_addr;
pointer global_c102c110c95c49c53c57; /* fn_159 */
pointer global_c102c110c95c49c54c48;
function_732:
  goto top_level_apply;
function_733:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_732);
  goto apply_addr;
function_734:
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
  increment_count(val = global_c102c110c95c49c53c57); /* fn_159 */
  target = (&&function_733);
  goto apply_addr;
function_735:
  increment_count(env);
  val = wrap_function((&&function_734), env);
  goto pop_function;
/* fn_160 */
body_293:
global_c102c110c95c49c53c57 = NIL; /* fn_159 */
  increment_count(env);
  val = wrap_function((&&function_735), env);
  global_c102c110c95c49c54c48 = val; /* fn_160 */
  goto body_294;
function_736:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_737:
  increment_count(env);
  val = wrap_function((&&function_736), env);
  goto pop_function;
/* fn_159 */
body_294:
  increment_count(env);
  val = wrap_function((&&function_737), env);
  global_c102c110c95c49c53c57 = val; /* fn_159 */
  goto body_295;
pointer global_c95c111c114;
function_738:
  global_c95c111c114 = val; /* _or */
  goto body_296;
/* _or */
body_295:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c48); /* fn_160 */
  target = (&&function_738);
  goto apply_addr;
pointer global_c102c110c95c49c54c49; /* fn_161 */
pointer global_c102c110c95c49c54c50;
function_739:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c49); /* fn_161 */
  goto top_level_apply;
function_740:
  increment_count(env);
  val = wrap_function((&&function_739), env);
  goto pop_function;
/* fn_162 */
body_296:
global_c102c110c95c49c54c49 = NIL; /* fn_161 */
  increment_count(env);
  val = wrap_function((&&function_740), env);
  global_c102c110c95c49c54c50 = val; /* fn_162 */
  goto body_297;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
function_741:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_742:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c55); /* ___l_47 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c54); /* ___l_46 */
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_741);
  goto apply_addr;
function_743:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_742);
  goto apply_addr;
function_744:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_745:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_744);
  goto apply_addr;
function_746:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116); /* ____transform-statement */
  target = (&&function_745);
  goto apply_addr;
function_747:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  target = (&&function_746);
  goto apply_addr;
function_748:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c57); /* ___l_49 */
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
    target = (&&function_747);
    goto apply_addr;
  }
function_749:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_748);
  goto apply_addr;
function_750:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_749);
  goto apply_addr;
function_751:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_750);
  goto apply_addr;
function_752:
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
  target = (&&function_751);
  goto apply_addr;
function_753:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_752);
  goto apply_addr;
function_754:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c56); /* ___l_48 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116); /* ____transform-statement */
    target = (&&function_743);
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
    target = (&&function_753);
    goto apply_addr;
  }
function_755:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_754);
  goto apply_addr;
function_756:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c52); /* ___l_44 */
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
    increment_count(val = global_c95c95c95c108c95c52c53); /* ___l_45 */
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
    target = (&&function_755);
    goto apply_addr;
  }
function_757:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_756);
  goto apply_addr;
function_758:
  increment_count(env);
  val = wrap_function((&&function_757), env);
  goto pop_function;
/* fn_161 */
body_297:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_758), env);
  global_c102c110c95c49c54c49 = val; /* fn_161 */
  goto body_298;
function_759:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_299;
/* ____compile-source */
body_298:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c50); /* fn_162 */
  target = (&&function_759);
  goto apply_addr;
pointer global_c102c110c95c49c54c51;
function_760:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_761:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_760);
  goto apply_addr;
function_762:
  increment_count(env);
  val = wrap_function((&&function_761), env);
  goto pop_function;
/* fn_163 */
body_299:
  increment_count(env);
  val = wrap_function((&&function_762), env);
  global_c102c110c95c49c54c51 = val; /* fn_163 */
  goto body_300;
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
function_763:
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
body_300:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c54c51); /* fn_163 */
  goto top_level_apply;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), NIL), call_stack);
  call_stack = cons(wrap_function((&&function_763), NIL), call_stack);
  goto body_0;
}
