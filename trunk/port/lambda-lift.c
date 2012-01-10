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
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -41;
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
    val = -41;
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
    val = new_number(116);
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
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
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
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
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
    target = (&&function_16);
    goto apply_addr;
  }
function_18:
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
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
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
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
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
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
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
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
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
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
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
    target = (&&function_22);
    goto apply_addr;
  }
function_24:
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
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
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
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
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
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
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
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
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
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
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
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
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
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
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
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
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
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
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
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
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
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
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
    target = (&&function_34);
    goto apply_addr;
  }
function_36:
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
  target = (&&function_35);
  goto apply_addr;
function_37:
  increment_count(env);
  val = wrap_function((&&function_36), env);
  goto pop_function;
/* fn_2 */
body_4:
  increment_count(env);
  val = wrap_function((&&function_37), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_5;
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_38:
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_6;
/* _string->symbol */
body_5:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  target = (&&function_38);
  goto apply_addr;
pointer global_c102c110c95c51;
function_39:
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
          val = -34;
          goto pop_function;
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -41;
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
            goto pop_function;
          } else {
            val = NIL;
            goto pop_function;
          }
        }
      }
    }
  }
function_40:
  increment_count(env);
  val = wrap_function((&&function_39), env);
  goto pop_function;
/* fn_3 */
body_6:
  increment_count(env);
  val = wrap_function((&&function_40), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_7;
pointer global_c95c115c121c109c98c111c108c63;
function_41:
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  goto body_8;
/* _symbol? */
body_7:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  target = (&&function_41);
  goto apply_addr;
pointer global_c102c110c95c52;
function_42:
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
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -41;
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
      goto pop_function;
    } else {
      val = NIL;
      goto pop_function;
    }
  }
function_43:
  increment_count(env);
  val = wrap_function((&&function_42), env);
  goto pop_function;
/* fn_4 */
body_8:
  increment_count(env);
  val = wrap_function((&&function_43), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_9;
pointer global_c95c95c97c116c111c109;
function_44:
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_10;
/* __atom */
body_9:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  target = (&&function_44);
  goto apply_addr;
pointer global_c102c110c95c53;
function_45:
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
function_46:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_45);
  goto apply_addr;
function_47:
  increment_count(env);
  val = wrap_function((&&function_46), env);
  goto pop_function;
/* fn_5 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_47), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_11;
pointer global_c95c95c61;
function_48:
  global_c95c95c61 = val; /* __= */
  goto body_12;
/* __= */
body_11:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  target = (&&function_48);
  goto apply_addr;
pointer global_c102c110c95c54;
function_49:
  increment_count(val = car(env));
  goto pop_function;
function_50:
  increment_count(env);
  val = wrap_function((&&function_49), env);
  goto pop_function;
/* fn_6 */
body_12:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_13;
pointer global_c95c108c105c115c116;
function_51:
  global_c95c108c105c115c116 = val; /* _list */
  goto body_14;
/* _list */
body_13:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  target = (&&function_51);
  goto apply_addr;
pointer global_c95c114c114c101c118c101c114c115c101; /* _rreverse */
pointer global_c102c110c95c55;
function_52:
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
function_53:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_52);
  goto apply_addr;
function_54:
  increment_count(env);
  val = wrap_function((&&function_53), env);
  goto pop_function;
/* fn_7 */
body_14:
global_c95c114c114c101c118c101c114c115c101 = NIL; /* _rreverse */
  increment_count(env);
  val = wrap_function((&&function_54), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_15;
function_55:
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_16;
/* _rreverse */
body_15:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  target = (&&function_55);
  goto apply_addr;
pointer global_c102c110c95c56; /* fn_8 */
pointer global_c102c110c95c57;
function_56:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  goto top_level_apply;
function_57:
  increment_count(env);
  val = wrap_function((&&function_56), env);
  goto pop_function;
/* fn_9 */
body_16:
global_c102c110c95c56 = NIL; /* fn_8 */
  increment_count(env);
  val = wrap_function((&&function_57), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_17;
pointer global_c95c102c111c108c100c108; /* _foldl */
function_58:
  goto top_level_apply;
function_59:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_58);
  goto apply_addr;
function_60:
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
    target = (&&function_59);
    goto apply_addr;
  }
function_61:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_60);
  goto apply_addr;
function_62:
  increment_count(env);
  val = wrap_function((&&function_61), env);
  goto pop_function;
/* fn_8 */
body_17:
global_c95c102c111c108c100c108 = NIL; /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_62), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_18;
function_63:
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_19;
/* _foldl */
body_18:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  target = (&&function_63);
  goto apply_addr;
pointer global_c102c110c95c49c48; /* fn_10 */
pointer global_c102c110c95c49c49;
function_64:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  goto top_level_apply;
function_65:
  increment_count(env);
  val = wrap_function((&&function_64), env);
  goto pop_function;
/* fn_11 */
body_19:
global_c102c110c95c49c48 = NIL; /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_65), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_20;
function_66:
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  goto top_level_apply;
function_67:
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
  target = (&&function_66);
  goto apply_addr;
function_68:
  increment_count(env);
  val = wrap_function((&&function_67), env);
  goto pop_function;
/* fn_10 */
body_20:
  increment_count(env);
  val = wrap_function((&&function_68), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_21;
pointer global_c95c102c111c108c100c114;
function_69:
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_22;
/* _foldr */
body_21:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  target = (&&function_69);
  goto apply_addr;
pointer global_c102c110c95c49c50;
function_70:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_71:
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
  target = (&&function_70);
  goto apply_addr;
function_72:
  increment_count(env);
  val = wrap_function((&&function_71), env);
  goto pop_function;
/* fn_12 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_72), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_23;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_73:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_24;
function_74:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_73);
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
  target = (&&function_74);
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
function_75:
  increment_count(val = car(car(env)));
  goto pop_function;
function_76:
  increment_count(env);
  val = wrap_function((&&function_75), env);
  goto pop_function;
/* fn_13 */
body_28:
  increment_count(env);
  val = wrap_function((&&function_76), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_29;
pointer global_c95c105c100;
function_77:
  global_c95c105c100 = val; /* _id */
  goto body_30;
/* _id */
body_29:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  target = (&&function_77);
  goto apply_addr;
pointer global_c102c110c95c49c52; /* fn_14 */
pointer global_c102c110c95c49c53;
function_78:
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
function_79:
  increment_count(env);
  val = wrap_function((&&function_78), env);
  goto pop_function;
/* fn_15 */
body_30:
global_c102c110c95c49c52 = NIL; /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_31;
pointer global_c95c119c97c108c107; /* _walk */
function_80:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_81:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_80);
  goto apply_addr;
function_82:
  target = (&&function_81);
  goto apply_addr;
function_83:
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
  target = (&&function_82);
  goto apply_addr;
function_84:
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
    target = (&&function_83);
    goto apply_addr;
  }
function_85:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_84);
  goto apply_addr;
function_86:
  increment_count(env);
  val = wrap_function((&&function_85), env);
  goto pop_function;
/* fn_14 */
body_31:
global_c95c119c97c108c107 = NIL; /* _walk */
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_32;
function_87:
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_33;
/* _walk */
body_32:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  target = (&&function_87);
  goto apply_addr;
pointer global_c102c110c95c49c54; /* fn_16 */
pointer global_c102c110c95c49c55;
function_88:
  goto top_level_apply;
function_89:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_88);
  goto apply_addr;
function_90:
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
  target = (&&function_89);
  goto apply_addr;
function_91:
  increment_count(env);
  val = wrap_function((&&function_90), env);
  goto pop_function;
/* fn_17 */
body_33:
global_c102c110c95c49c54 = NIL; /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_91), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_34;
pointer global_c99c111c110c115; /* cons */
function_92:
  goto top_level_apply;
function_93:
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
    target = (&&function_92);
    goto apply_addr;
  }
function_94:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_93);
  goto apply_addr;
function_95:
  increment_count(env);
  val = wrap_function((&&function_94), env);
  goto pop_function;
/* fn_16 */
body_34:
global_c99c111c110c115 = CONS; /* cons */
  increment_count(env);
  val = wrap_function((&&function_95), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_35;
pointer global_c95c97c112c112c101c110c100;
function_96:
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_36;
/* _append */
body_35:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  target = (&&function_96);
  goto apply_addr;
pointer global_c102c110c95c50c51; /* fn_23 */
pointer global_c102c110c95c50c50; /* fn_22 */
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c49c57; /* fn_19 */
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c102c110c95c50c52;
function_97:
  goto top_level_apply;
function_98:
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  target = (&&function_97);
  goto apply_addr;
function_99:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  target = (&&function_98);
  goto apply_addr;
function_100:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  target = (&&function_99);
  goto apply_addr;
function_101:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  target = (&&function_100);
  goto apply_addr;
function_102:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  target = (&&function_101);
  goto apply_addr;
function_103:
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
  target = (&&function_102);
  goto apply_addr;
function_104:
  increment_count(env);
  val = wrap_function((&&function_103), env);
  goto pop_function;
/* fn_24 */
body_36:
global_c102c110c95c50c51 = NIL; /* fn_23 */
global_c102c110c95c50c50 = NIL; /* fn_22 */
global_c102c110c95c50c48 = NIL; /* fn_20 */
global_c102c110c95c49c57 = NIL; /* fn_19 */
global_c102c110c95c49c56 = NIL; /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_104), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_37;
function_105:
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
function_106:
  increment_count(env);
  val = wrap_function((&&function_105), env);
  goto pop_function;
/* fn_18 */
body_37:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_38;
function_107:
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
function_108:
  increment_count(env);
  val = wrap_function((&&function_107), env);
  goto pop_function;
/* fn_19 */
body_38:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_39;
function_109:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_110:
  increment_count(env);
  val = wrap_function((&&function_109), env);
  goto pop_function;
/* fn_20 */
body_39:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_40;
pointer global_c102c110c95c50c49; /* fn_21 */
function_111:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  goto top_level_apply;
function_112:
  increment_count(env);
  val = wrap_function((&&function_111), env);
  goto pop_function;
/* fn_22 */
body_40:
global_c102c110c95c50c49 = NIL; /* fn_21 */
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_41;
function_113:
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
function_114:
  increment_count(env);
  val = wrap_function((&&function_113), env);
  goto pop_function;
/* fn_21 */
body_41:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_42;
function_115:
  increment_count(val = global_c95c105c100); /* _id */
  goto pop_function;
function_116:
  increment_count(env);
  val = wrap_function((&&function_115), env);
  goto pop_function;
/* fn_23 */
body_42:
  increment_count(env);
  val = wrap_function((&&function_116), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_43;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_117:
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_44;
/* _build-num-str */
body_43:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  target = (&&function_117);
  goto apply_addr;
pointer global_c102c110c95c50c53;
function_118:
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
function_119:
  target = (&&function_118);
  goto apply_addr;
function_120:
  goto top_level_apply;
function_121:
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
      target = (&&function_119);
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
      target = (&&function_120);
      goto apply_addr;
    }
  }
function_122:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_121);
  goto apply_addr;
function_123:
  increment_count(env);
  val = wrap_function((&&function_122), env);
  goto pop_function;
/* fn_25 */
body_44:
  increment_count(env);
  val = wrap_function((&&function_123), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_45;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_124:
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_46;
/* _print-num */
body_45:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  target = (&&function_124);
  goto apply_addr;
pointer global_c102c110c95c50c54;
function_125:
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
function_126:
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
      target = (&&function_125);
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
function_127:
  increment_count(env);
  val = wrap_function((&&function_126), env);
  goto pop_function;
/* fn_26 */
body_46:
  increment_count(env);
  val = wrap_function((&&function_127), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_47;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_128:
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_48;
/* _print-atom */
body_47:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  target = (&&function_128);
  goto apply_addr;
pointer global_c95c112c114c105c110c116c45c116c97c105c108; /* _print-tail */
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c102c110c95c50c55;
function_129:
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
function_130:
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
function_131:
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
  target = (&&function_130);
  goto apply_addr;
function_132:
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
    target = (&&function_129);
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
    target = (&&function_131);
    goto apply_addr;
  }
function_133:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_132);
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
function_134:
  increment_count(env);
  val = wrap_function((&&function_133), env);
  goto pop_function;
/* fn_27 */
body_48:
global_c95c112c114c105c110c116c45c116c97c105c108 = NIL; /* _print-tail */
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_134), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_49;
function_135:
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_50;
/* _print-tail */
body_49:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  target = (&&function_135);
  goto apply_addr;
pointer global_c102c110c95c50c56;
function_136:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_137:
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
function_138:
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
  target = (&&function_137);
  goto apply_addr;
function_139:
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
    target = (&&function_136);
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
    target = (&&function_138);
    goto apply_addr;
  }
function_140:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_139);
  goto apply_addr;
function_141:
  increment_count(env);
  val = wrap_function((&&function_140), env);
  goto pop_function;
/* fn_28 */
body_50:
  increment_count(env);
  val = wrap_function((&&function_141), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_51;
function_142:
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_52;
/* _print-with-suffix */
body_51:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  target = (&&function_142);
  goto apply_addr;
pointer global_c102c110c95c50c57;
function_143:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  goto top_level_apply;
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* fn_29 */
body_52:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_53;
pointer global_c95c112c114c105c110c116;
function_145:
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_54;
/* _print */
body_53:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  target = (&&function_145);
  goto apply_addr;
pointer global_c102c110c95c51c48;
function_146:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_147:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_146);
  goto apply_addr;
function_148:
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
    target = (&&function_147);
    goto apply_addr;
  } else {
    val = NIL;
    goto pop_function;
  }
function_149:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  goto pop_function;
/* fn_30 */
body_54:
  increment_count(env);
  val = wrap_function((&&function_149), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_55;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_150:
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_56;
/* ____print-warnings */
body_55:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  target = (&&function_150);
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
function_151:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_152:
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
  target = (&&function_151);
  goto apply_addr;
function_153:
  increment_count(env);
  val = wrap_function((&&function_152), env);
  goto pop_function;
/* fn_31 */
body_58:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_59;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_154:
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_60;
/* ____print-error */
body_59:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  target = (&&function_154);
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
function_155:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_156:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_155);
  goto apply_addr;
function_157:
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
  target = (&&function_156);
  goto apply_addr;
function_158:
  increment_count(env);
  val = wrap_function((&&function_157), env);
  goto pop_function;
/* fn_32 */
body_61:
  increment_count(env);
  val = wrap_function((&&function_158), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_62;
pointer global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
function_159:
  global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ____number->symbol */
  goto body_63;
/* ____number->symbol */
body_62:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
  target = (&&function_159);
  goto apply_addr;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_63:
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
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_64;
pointer global_c95c95c95c95c98c117c105c108c116c105c110c115;
/* ____builtins */
body_64:
  increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
  global_c95c95c95c95c98c117c105c108c116c105c110c115 = val; /* ____builtins */
  goto body_65;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_65:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_66;
pointer global_c95c95c101c113c117c97c108; /* __equal */
pointer global_c102c110c95c51c51;
function_160:
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
function_161:
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
    target = (&&function_160);
    goto apply_addr;
  }
function_162:
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
    target = (&&function_161);
    goto apply_addr;
  }
function_163:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_162);
  goto apply_addr;
function_164:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  goto pop_function;
/* fn_33 */
body_66:
global_c95c95c101c113c117c97c108 = NIL; /* __equal */
  increment_count(env);
  val = wrap_function((&&function_164), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_67;
function_165:
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_68;
/* __equal */
body_67:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  target = (&&function_165);
  goto apply_addr;
pointer global_c95c109c101c109c98c101c114; /* _member */
pointer global_c102c110c95c51c52;
function_166:
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
function_167:
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
    target = (&&function_166);
    goto apply_addr;
  }
function_168:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_167);
  goto apply_addr;
function_169:
  increment_count(env);
  val = wrap_function((&&function_168), env);
  goto pop_function;
/* fn_34 */
body_68:
global_c95c109c101c109c98c101c114 = NIL; /* _member */
  increment_count(env);
  val = wrap_function((&&function_169), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_69;
function_170:
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_70;
/* _member */
body_69:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  target = (&&function_170);
  goto apply_addr;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115; /* ____escape-symbols */
pointer global_c102c110c95c51c53;
function_171:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_172:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_171);
  goto apply_addr;
function_173:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_174:
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
  target = (&&function_173);
  goto apply_addr;
function_175:
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
    target = (&&function_174);
    goto apply_addr;
  }
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
    target = (&&function_172);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_175);
    goto apply_addr;
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
function_179:
  increment_count(env);
  val = wrap_function((&&function_178), env);
  goto pop_function;
/* fn_35 */
body_70:
global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ____escape-symbols */
  increment_count(env);
  val = wrap_function((&&function_179), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_71;
function_180:
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_72;
/* ____escape-symbols */
body_71:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  target = (&&function_180);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_72:
  val = NIL;
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_73;
pointer global_c95c95c95c95c102c108c97c116c116c101c110; /* ____flatten */
pointer global_c102c110c95c51c54;
function_181:
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
function_182:
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
    target = (&&function_181);
    goto apply_addr;
  }
function_183:
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
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_182);
    goto apply_addr;
  }
function_184:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_183);
  goto apply_addr;
function_185:
  increment_count(env);
  val = wrap_function((&&function_184), env);
  goto pop_function;
/* fn_36 */
body_73:
global_c95c95c95c95c102c108c97c116c116c101c110 = NIL; /* ____flatten */
  increment_count(env);
  val = wrap_function((&&function_185), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_74;
function_186:
  global_c95c95c95c95c102c108c97c116c116c101c110 = val; /* ____flatten */
  goto body_75;
/* ____flatten */
body_74:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  target = (&&function_186);
  goto apply_addr;
pointer global_c102c110c95c51c55; /* fn_37 */
pointer global_c102c110c95c51c56;
function_187:
  goto top_level_apply;
function_188:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_187);
  goto apply_addr;
function_189:
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
  target = (&&function_188);
  goto apply_addr;
function_190:
  increment_count(env);
  val = wrap_function((&&function_189), env);
  goto pop_function;
/* fn_38 */
body_75:
global_c102c110c95c51c55 = NIL; /* fn_37 */
  increment_count(env);
  val = wrap_function((&&function_190), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_76;
function_191:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
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
    goto pop_function;
  }
function_192:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_191);
  goto apply_addr;
function_193:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  goto pop_function;
/* fn_37 */
body_76:
  increment_count(env);
  val = wrap_function((&&function_193), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_77;
pointer global_c95c95c95c95c109c101c114c103c101;
function_194:
  global_c95c95c95c95c109c101c114c103c101 = val; /* ____merge */
  goto body_78;
/* ____merge */
body_77:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  target = (&&function_194);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_78:
  val = NIL;
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_79;
pointer global_c102c110c95c51c57; /* fn_39 */
pointer global_c102c110c95c52c48;
function_195:
  goto top_level_apply;
function_196:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_195);
  goto apply_addr;
function_197:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  target = (&&function_196);
  goto apply_addr;
function_198:
  increment_count(env);
  val = wrap_function((&&function_197), env);
  goto pop_function;
/* fn_40 */
body_79:
global_c102c110c95c51c57 = NIL; /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_198), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_80;
function_199:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
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
    goto pop_function;
  }
function_200:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_199);
  goto apply_addr;
function_201:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  goto pop_function;
/* fn_39 */
body_80:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_81;
pointer global_c95c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116;
function_202:
  global_c95c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116 = val; /* ____subtract-list */
  goto body_82;
/* ____subtract-list */
body_81:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  target = (&&function_202);
  goto apply_addr;
pointer global_c102c110c95c52c49; /* fn_41 */
pointer global_c102c110c95c52c50;
function_203:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  goto top_level_apply;
function_204:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  goto pop_function;
/* fn_42 */
body_82:
global_c102c110c95c52c49 = NIL; /* fn_41 */
  increment_count(env);
  val = wrap_function((&&function_204), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_83;
function_205:
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
  goto top_level_apply;
function_206:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_205);
  goto apply_addr;
function_207:
  increment_count(env);
  val = wrap_function((&&function_206), env);
  goto pop_function;
/* fn_41 */
body_83:
  increment_count(env);
  val = wrap_function((&&function_207), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_84;
pointer global_c95c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110;
function_208:
  global_c95c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110 = val; /* ____definition-return */
  goto body_85;
/* ____definition-return */
body_84:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  target = (&&function_208);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_85:
  val = NIL;
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_86;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_86:
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
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_87;
pointer global_c102c110c95c52c55; /* fn_47 */
pointer global_c102c110c95c52c56;
function_209:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  goto top_level_apply;
function_210:
  increment_count(env);
  val = wrap_function((&&function_209), env);
  goto pop_function;
/* fn_48 */
body_87:
global_c102c110c95c52c55 = NIL; /* fn_47 */
  increment_count(env);
  val = wrap_function((&&function_210), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_88;
pointer global_c102c110c95c52c54; /* fn_46 */
function_211:
  goto top_level_apply;
function_212:
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
  target = (&&function_211);
  goto apply_addr;
function_213:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_212);
  goto apply_addr;
function_214:
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
  target = (&&function_213);
  goto apply_addr;
function_215:
  increment_count(env);
  val = wrap_function((&&function_214), env);
  goto pop_function;
/* fn_47 */
body_88:
global_c102c110c95c52c54 = NIL; /* fn_46 */
  increment_count(env);
  val = wrap_function((&&function_215), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_89;
pointer global_c102c110c95c52c53; /* fn_45 */
function_216:
  goto top_level_apply;
function_217:
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
  target = (&&function_216);
  goto apply_addr;
function_218:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_217);
  goto apply_addr;
function_219:
  increment_count(env);
  val = wrap_function((&&function_218), env);
  goto pop_function;
/* fn_46 */
body_89:
global_c102c110c95c52c53 = NIL; /* fn_45 */
  increment_count(env);
  val = wrap_function((&&function_219), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_90;
pointer global_c102c110c95c52c52; /* fn_44 */
function_220:
  goto top_level_apply;
function_221:
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
  target = (&&function_220);
  goto apply_addr;
function_222:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50); /* ___l_12 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110); /* ____flatten */
  target = (&&function_221);
  goto apply_addr;
function_223:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  goto pop_function;
/* fn_45 */
body_90:
global_c102c110c95c52c52 = NIL; /* fn_44 */
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_91;
pointer global_c102c110c95c52c51; /* fn_43 */
function_224:
  goto top_level_apply;
function_225:
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
  target = (&&function_224);
  goto apply_addr;
function_226:
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
  increment_count(val = global_c95c95c95c95c115c117c98c116c114c97c99c116c45c108c105c115c116); /* ____subtract-list */
  target = (&&function_225);
  goto apply_addr;
function_227:
  increment_count(env);
  val = wrap_function((&&function_226), env);
  goto pop_function;
/* fn_44 */
body_91:
global_c102c110c95c52c51 = NIL; /* fn_43 */
  increment_count(env);
  val = wrap_function((&&function_227), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_92;
function_228:
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
function_229:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_228);
  goto apply_addr;
function_230:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_229);
  goto apply_addr;
function_231:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_230);
  goto apply_addr;
function_232:
  increment_count(env);
  val = wrap_function((&&function_231), env);
  goto pop_function;
/* fn_43 */
body_92:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_93;
pointer global_c95c95c95c95c102c110c45c114c101c116c117c114c110;
function_233:
  global_c95c95c95c95c102c110c45c114c101c116c117c114c110 = val; /* ____fn-return */
  goto body_94;
/* ____fn-return */
body_93:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  target = (&&function_233);
  goto apply_addr;
pointer global_c102c110c95c52c57; /* fn_49 */
pointer global_c102c110c95c53c48;
function_234:
  goto top_level_apply;
function_235:
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
  target = (&&function_234);
  goto apply_addr;
function_236:
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
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110); /* ____flatten */
  target = (&&function_235);
  goto apply_addr;
function_237:
  increment_count(env);
  val = wrap_function((&&function_236), env);
  goto pop_function;
/* fn_50 */
body_94:
global_c102c110c95c52c57 = NIL; /* fn_49 */
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_95;
pointer global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115; /* ____extract-definitions */
function_238:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
  goto top_level_apply;
function_239:
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
  increment_count(val = global_c95c95c95c95c102c110c45c114c101c116c117c114c110); /* ____fn-return */
  target = (&&function_238);
  goto apply_addr;
function_240:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  goto pop_function;
/* fn_49 */
body_95:
global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ____extract-definitions */
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_96;
pointer global_c95c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115;
function_241:
  global_c95c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115 = val; /* ____fn-defintions */
  goto body_97;
/* ____fn-defintions */
body_96:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  target = (&&function_241);
  goto apply_addr;
pointer global_c102c110c95c53c50; /* fn_52 */
pointer global_c102c110c95c53c51;
function_242:
  goto top_level_apply;
function_243:
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
  target = (&&function_242);
  goto apply_addr;
function_244:
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
    increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
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
    increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
    target = (&&function_243);
    goto apply_addr;
  }
function_245:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_244);
  goto apply_addr;
function_246:
  increment_count(env);
  val = wrap_function((&&function_245), env);
  goto pop_function;
/* fn_53 */
body_97:
global_c102c110c95c53c50 = NIL; /* fn_52 */
  increment_count(env);
  val = wrap_function((&&function_246), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_98;
pointer global_c95c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115; /* ____args-definitions */
pointer global_c102c110c95c53c49; /* fn_51 */
function_247:
  goto top_level_apply;
function_248:
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
  target = (&&function_247);
  goto apply_addr;
function_249:
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
  increment_count(val = global_c95c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* ____args-definitions */
  target = (&&function_248);
  goto apply_addr;
function_250:
  increment_count(env);
  val = wrap_function((&&function_249), env);
  goto pop_function;
/* fn_52 */
body_98:
global_c95c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = NIL; /* ____args-definitions */
global_c102c110c95c53c49 = NIL; /* fn_51 */
  increment_count(env);
  val = wrap_function((&&function_250), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_99;
function_251:
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
  goto top_level_apply;
function_252:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c101c114c103c101); /* ____merge */
  target = (&&function_251);
  goto apply_addr;
function_253:
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
  target = (&&function_252);
  goto apply_addr;
function_254:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  goto pop_function;
/* fn_51 */
body_99:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_100;
function_255:
  global_c95c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ____args-definitions */
  goto body_101;
/* ____args-definitions */
body_100:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  target = (&&function_255);
  goto apply_addr;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_101:
  val = NIL;
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_102;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_102:
  val = NIL;
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_103;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_103:
  val = NIL;
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_104;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_104:
  val = NIL;
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_105;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_105:
  val = -38;
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_106;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_106:
  val = NIL;
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_107;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_107:
  val = NIL;
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_108;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_108:
  val = -35;
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_109;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_109:
  val = -40;
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_110;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_110:
  val = -39;
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_111;
pointer global_c102c110c95c53c52;
function_256:
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
function_257:
  increment_count(env);
  val = wrap_function((&&function_256), env);
  goto pop_function;
/* fn_54 */
body_111:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_112;
pointer global_c95c99c97c100c114;
function_258:
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_113;
/* _cadr */
body_112:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  target = (&&function_258);
  goto apply_addr;
pointer global_c102c110c95c53c53;
function_259:
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
function_260:
  increment_count(env);
  val = wrap_function((&&function_259), env);
  goto pop_function;
/* fn_55 */
body_113:
  increment_count(env);
  val = wrap_function((&&function_260), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_114;
pointer global_c95c99c100c100c114;
function_261:
  global_c95c99c100c100c114 = val; /* _cddr */
  goto body_115;
/* _cddr */
body_114:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  target = (&&function_261);
  goto apply_addr;
pointer global_c102c110c95c53c54;
function_262:
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
function_263:
  increment_count(env);
  val = wrap_function((&&function_262), env);
  goto pop_function;
/* fn_56 */
body_115:
  increment_count(env);
  val = wrap_function((&&function_263), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_116;
pointer global_c95c99c97c100c100c114;
function_264:
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_117;
/* _caddr */
body_116:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  target = (&&function_264);
  goto apply_addr;
pointer global_c102c110c95c53c57; /* fn_59 */
pointer global_c102c110c95c54c48;
function_265:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_266:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_265);
  goto apply_addr;
function_267:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116); /* _list */
    target = (&&function_266);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c108c95c49c52); /* ___l_14 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
    target = (&&function_265);
    goto apply_addr;
  }
function_268:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
  goto top_level_apply;
function_269:
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
  target = (&&function_268);
  goto apply_addr;
function_270:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110); /* ____definition-return */
  target = (&&function_269);
  goto apply_addr;
function_271:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c110c45c100c101c102c105c110c116c105c111c110c115); /* ____fn-defintions */
  goto top_level_apply;
function_272:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_271);
  goto apply_addr;
function_273:
  goto top_level_apply;
function_274:
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
  target = (&&function_273);
  goto apply_addr;
function_275:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
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
    target = (&&function_275);
    goto apply_addr;
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
    increment_count(val = global_c95c95c95c95c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115); /* ____args-definitions */
    goto top_level_apply;
  }
function_277:
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
    target = (&&function_272);
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
    target = (&&function_276);
    goto apply_addr;
  }
function_278:
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
    target = (&&function_270);
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
    target = (&&function_277);
    goto apply_addr;
  }
function_279:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
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
    target = (&&function_278);
    goto apply_addr;
  }
function_280:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c55); /* ___l_17 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c56); /* ___l_18 */
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
    target = (&&function_279);
    goto apply_addr;
  }
function_281:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c53); /* ___l_15 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_267);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_280);
    goto apply_addr;
  }
function_282:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  target = (&&function_281);
  goto apply_addr;
function_283:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  goto pop_function;
/* fn_60 */
body_117:
global_c102c110c95c53c57 = NIL; /* fn_59 */
  increment_count(env);
  val = wrap_function((&&function_283), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_118;
pointer global_c102c110c95c53c56; /* fn_58 */
function_284:
  goto top_level_apply;
function_285:
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
  target = (&&function_284);
  goto apply_addr;
function_286:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
  target = (&&function_285);
  goto apply_addr;
function_287:
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
  target = (&&function_286);
  goto apply_addr;
function_288:
  increment_count(env);
  val = wrap_function((&&function_287), env);
  goto pop_function;
/* fn_59 */
body_118:
global_c102c110c95c53c56 = NIL; /* fn_58 */
  increment_count(env);
  val = wrap_function((&&function_288), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_119;
pointer global_c102c110c95c53c55; /* fn_57 */
function_289:
  goto top_level_apply;
function_290:
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
  target = (&&function_289);
  goto apply_addr;
function_291:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
  target = (&&function_290);
  goto apply_addr;
function_292:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_291);
  goto apply_addr;
function_293:
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
  target = (&&function_292);
  goto apply_addr;
function_294:
  increment_count(env);
  val = wrap_function((&&function_293), env);
  goto pop_function;
/* fn_58 */
body_119:
global_c102c110c95c53c55 = NIL; /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_294), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_120;
function_295:
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
  goto top_level_apply;
function_296:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c101c114c103c101); /* ____merge */
  target = (&&function_295);
  goto apply_addr;
function_297:
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
  increment_count(val = global_c95c95c95c95c109c101c114c103c101); /* ____merge */
  target = (&&function_296);
  goto apply_addr;
function_298:
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
  target = (&&function_297);
  goto apply_addr;
function_299:
  increment_count(env);
  val = wrap_function((&&function_298), env);
  goto pop_function;
/* fn_57 */
body_120:
  increment_count(env);
  val = wrap_function((&&function_299), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_121;
function_300:
  global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ____extract-definitions */
  goto body_122;
/* ____extract-definitions */
body_121:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  target = (&&function_300);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_122:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_123;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_123:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_124;
pointer global_c102c110c95c54c50; /* fn_62 */
pointer global_c102c110c95c54c51;
function_301:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  goto top_level_apply;
function_302:
  increment_count(env);
  val = wrap_function((&&function_301), env);
  goto pop_function;
/* fn_63 */
body_124:
global_c102c110c95c54c50 = NIL; /* fn_62 */
  increment_count(env);
  val = wrap_function((&&function_302), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_125;
pointer global_c102c110c95c54c49; /* fn_61 */
function_303:
  goto top_level_apply;
function_304:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_303);
  goto apply_addr;
function_305:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  target = (&&function_304);
  goto apply_addr;
function_306:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_305);
  goto apply_addr;
function_307:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_306);
  goto apply_addr;
function_308:
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
  target = (&&function_307);
  goto apply_addr;
function_309:
  increment_count(env);
  val = wrap_function((&&function_308), env);
  goto pop_function;
/* fn_62 */
body_125:
global_c102c110c95c54c49 = NIL; /* fn_61 */
  increment_count(env);
  val = wrap_function((&&function_309), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_126;
function_310:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_311:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_310);
  goto apply_addr;
function_312:
  increment_count(env);
  val = wrap_function((&&function_311), env);
  goto pop_function;
/* fn_61 */
body_126:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  goto body_127;
pointer global_c95c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110;
function_313:
  global_c95c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110 = val; /* ____statement-return */
  goto body_128;
/* ____statement-return */
body_127:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  target = (&&function_313);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_128:
  val = NIL;
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_129;
pointer global_c102c110c95c54c52;
function_314:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115); /* ____extract-definitions */
  goto top_level_apply;
function_315:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110); /* ____statement-return */
  target = (&&function_314);
  goto apply_addr;
function_316:
  increment_count(env);
  val = wrap_function((&&function_315), env);
  goto pop_function;
/* fn_64 */
body_129:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  goto body_130;
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
function_317:
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  goto body_131;
/* ____compile */
body_130:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  target = (&&function_317);
  goto apply_addr;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_131:
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
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_132;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_132:
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
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_133;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_133:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_134;
pointer global_c102c110c95c54c53;
function_318:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_319:
  increment_count(env);
  val = wrap_function((&&function_318), env);
  goto pop_function;
/* fn_65 */
body_134:
  increment_count(env);
  val = wrap_function((&&function_319), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  goto body_135;
pointer global_c95c97c112c112c108c121;
function_320:
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_136;
/* _apply */
body_135:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  target = (&&function_320);
  goto apply_addr;
pointer global_c102c110c95c54c54; /* fn_66 */
pointer global_c102c110c95c54c55;
function_321:
  goto top_level_apply;
function_322:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_321);
  goto apply_addr;
function_323:
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
  target = (&&function_322);
  goto apply_addr;
function_324:
  increment_count(env);
  val = wrap_function((&&function_323), env);
  goto pop_function;
/* fn_67 */
body_136:
global_c102c110c95c54c54 = NIL; /* fn_66 */
  increment_count(env);
  val = wrap_function((&&function_324), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  goto body_137;
function_325:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_326:
  increment_count(env);
  val = wrap_function((&&function_325), env);
  goto pop_function;
/* fn_66 */
body_137:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  goto body_138;
pointer global_c95c97c110c100;
function_327:
  global_c95c97c110c100 = val; /* _and */
  goto body_139;
/* _and */
body_138:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  target = (&&function_327);
  goto apply_addr;
pointer global_c102c110c95c54c56;
function_328:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_329:
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
    target = (&&function_328);
    goto apply_addr;
  }
function_330:
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
    target = (&&function_329);
    goto apply_addr;
  }
function_331:
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_330);
  goto apply_addr;
function_332:
  increment_count(env);
  val = wrap_function((&&function_331), env);
  goto pop_function;
/* fn_68 */
body_139:
  increment_count(env);
  val = wrap_function((&&function_332), env);
  global_c102c110c95c54c56 = val; /* fn_68 */
  goto body_140;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_333:
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_141;
/* _escape-char */
body_140:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c54c56); /* fn_68 */
  target = (&&function_333);
  goto apply_addr;
pointer global_c102c110c95c54c57; /* fn_69 */
pointer global_c102c110c95c55c48;
function_334:
  goto top_level_apply;
function_335:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_334);
  goto apply_addr;
function_336:
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
  target = (&&function_335);
  goto apply_addr;
function_337:
  increment_count(env);
  val = wrap_function((&&function_336), env);
  goto pop_function;
/* fn_70 */
body_141:
global_c102c110c95c54c57 = NIL; /* fn_69 */
  increment_count(env);
  val = wrap_function((&&function_337), env);
  global_c102c110c95c55c48 = val; /* fn_70 */
  goto body_142;
function_338:
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
function_339:
  increment_count(env);
  val = wrap_function((&&function_338), env);
  goto pop_function;
/* fn_69 */
body_142:
  increment_count(env);
  val = wrap_function((&&function_339), env);
  global_c102c110c95c54c57 = val; /* fn_69 */
  goto body_143;
pointer global_c95c98c117c105c108c100c45c110c117c109;
function_340:
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  goto body_144;
/* _build-num */
body_143:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c48); /* fn_70 */
  target = (&&function_340);
  goto apply_addr;
pointer global_c102c110c95c55c49;
function_341:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_342:
  increment_count(env);
  val = wrap_function((&&function_341), env);
  goto pop_function;
/* fn_71 */
body_144:
  increment_count(env);
  val = wrap_function((&&function_342), env);
  global_c102c110c95c55c49 = val; /* fn_71 */
  goto body_145;
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
function_343:
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  goto body_146;
/* _quote-value */
body_145:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c49); /* fn_71 */
  target = (&&function_343);
  goto apply_addr;
pointer global_c102c110c95c55c50;
function_344:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_345:
  increment_count(env);
  val = wrap_function((&&function_344), env);
  goto pop_function;
/* fn_72 */
body_146:
  increment_count(env);
  val = wrap_function((&&function_345), env);
  global_c102c110c95c55c50 = val; /* fn_72 */
  goto body_147;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
function_346:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  goto body_148;
/* _quasiquote-value */
body_147:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c50); /* fn_72 */
  target = (&&function_346);
  goto apply_addr;
pointer global_c102c110c95c55c51;
function_347:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_348:
  increment_count(env);
  val = wrap_function((&&function_347), env);
  goto pop_function;
/* fn_73 */
body_148:
  increment_count(env);
  val = wrap_function((&&function_348), env);
  global_c102c110c95c55c51 = val; /* fn_73 */
  goto body_149;
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
function_349:
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  goto body_150;
/* _unquote-value */
body_149:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c51); /* fn_73 */
  target = (&&function_349);
  goto apply_addr;
pointer global_c102c110c95c55c52; /* fn_74 */
pointer global_c102c110c95c55c53;
function_350:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55c52); /* fn_74 */
  goto top_level_apply;
function_351:
  increment_count(env);
  val = wrap_function((&&function_350), env);
  goto pop_function;
/* fn_75 */
body_150:
global_c102c110c95c55c52 = NIL; /* fn_74 */
  increment_count(env);
  val = wrap_function((&&function_351), env);
  global_c102c110c95c55c53 = val; /* fn_75 */
  goto body_151;
function_352:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  goto top_level_apply;
function_353:
  increment_count(env);
  val = wrap_function((&&function_352), env);
  goto pop_function;
/* fn_74 */
body_151:
  increment_count(env);
  val = wrap_function((&&function_353), env);
  global_c102c110c95c55c52 = val; /* fn_74 */
  goto body_152;
pointer global_c95c102c97c105c108;
function_354:
  global_c95c102c97c105c108 = val; /* _fail */
  goto body_153;
/* _fail */
body_152:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c53); /* fn_75 */
  target = (&&function_354);
  goto apply_addr;
pointer global_c102c110c95c55c54;
function_355:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_356:
  increment_count(env);
  val = wrap_function((&&function_355), env);
  goto pop_function;
/* fn_76 */
body_153:
  increment_count(env);
  val = wrap_function((&&function_356), env);
  global_c102c110c95c55c54 = val; /* fn_76 */
  goto body_154;
pointer global_c95c100c111c110c101;
function_357:
  global_c95c100c111c110c101 = val; /* _done */
  goto body_155;
/* _done */
body_154:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c54); /* fn_76 */
  target = (&&function_357);
  goto apply_addr;
pointer global_c102c110c95c55c55; /* fn_77 */
pointer global_c102c110c95c55c56;
function_358:
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
  goto top_level_apply;
function_359:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  goto pop_function;
/* fn_78 */
body_155:
global_c102c110c95c55c55 = NIL; /* fn_77 */
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c102c110c95c55c56 = val; /* fn_78 */
  goto body_156;
pointer global_c95c112c111c112; /* _pop */
function_360:
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
function_361:
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
      target = (&&function_360);
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
function_362:
  increment_count(env);
  val = wrap_function((&&function_361), env);
  goto pop_function;
/* fn_77 */
body_156:
global_c95c112c111c112 = NIL; /* _pop */
  increment_count(env);
  val = wrap_function((&&function_362), env);
  global_c102c110c95c55c55 = val; /* fn_77 */
  goto body_157;
function_363:
  global_c95c112c111c112 = val; /* _pop */
  goto body_158;
/* _pop */
body_157:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c55c56); /* fn_78 */
  target = (&&function_363);
  goto apply_addr;
pointer global_c102c110c95c56c48; /* fn_80 */
pointer global_c102c110c95c56c49;
function_364:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c48); /* fn_80 */
  goto top_level_apply;
function_365:
  increment_count(env);
  val = wrap_function((&&function_364), env);
  goto pop_function;
/* fn_81 */
body_158:
global_c102c110c95c56c48 = NIL; /* fn_80 */
  increment_count(env);
  val = wrap_function((&&function_365), env);
  global_c102c110c95c56c49 = val; /* fn_81 */
  goto body_159;
pointer global_c102c110c95c55c57; /* fn_79 */
function_366:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  goto top_level_apply;
function_367:
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
  target = (&&function_366);
  goto apply_addr;
function_368:
  increment_count(env);
  val = wrap_function((&&function_367), env);
  goto pop_function;
/* fn_80 */
body_159:
global_c102c110c95c55c57 = NIL; /* fn_79 */
  increment_count(env);
  val = wrap_function((&&function_368), env);
  global_c102c110c95c56c48 = val; /* fn_80 */
  goto body_160;
function_369:
  goto top_level_apply;
function_370:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_369);
  goto apply_addr;
function_371:
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
  target = (&&function_370);
  goto apply_addr;
function_372:
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
    target = (&&function_371);
    goto apply_addr;
  }
function_373:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_372);
  goto apply_addr;
function_374:
  increment_count(env);
  val = wrap_function((&&function_373), env);
  goto pop_function;
/* fn_79 */
body_160:
  increment_count(env);
  val = wrap_function((&&function_374), env);
  global_c102c110c95c55c57 = val; /* fn_79 */
  goto body_161;
pointer global_c95c99c104c101c99c107;
function_375:
  global_c95c99c104c101c99c107 = val; /* _check */
  goto body_162;
/* _check */
body_161:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c49); /* fn_81 */
  target = (&&function_375);
  goto apply_addr;
pointer global_c102c110c95c56c50; /* fn_82 */
pointer global_c102c110c95c56c51;
function_376:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_377:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c50); /* fn_82 */
  target = (&&function_376);
  goto apply_addr;
function_378:
  increment_count(env);
  val = wrap_function((&&function_377), env);
  goto pop_function;
/* fn_83 */
body_162:
global_c102c110c95c56c50 = NIL; /* fn_82 */
  increment_count(env);
  val = wrap_function((&&function_378), env);
  global_c102c110c95c56c51 = val; /* fn_83 */
  goto body_163;
function_379:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_380:
  increment_count(env);
  val = wrap_function((&&function_379), env);
  goto pop_function;
/* fn_82 */
body_163:
  increment_count(env);
  val = wrap_function((&&function_380), env);
  global_c102c110c95c56c50 = val; /* fn_82 */
  goto body_164;
pointer global_c95c109c97c116c99c104;
function_381:
  global_c95c109c97c116c99c104 = val; /* _match */
  goto body_165;
/* _match */
body_164:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c51); /* fn_83 */
  target = (&&function_381);
  goto apply_addr;
pointer global_c102c110c95c56c52; /* fn_84 */
pointer global_c102c110c95c56c53;
function_382:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c52); /* fn_84 */
  goto top_level_apply;
function_383:
  increment_count(env);
  val = wrap_function((&&function_382), env);
  goto pop_function;
/* fn_85 */
body_165:
global_c102c110c95c56c52 = NIL; /* fn_84 */
  increment_count(env);
  val = wrap_function((&&function_383), env);
  global_c102c110c95c56c53 = val; /* fn_85 */
  goto body_166;
function_384:
  increment_count(val = car(car(cdr(env))));
  goto pop_function;
function_385:
  increment_count(env);
  val = wrap_function((&&function_384), env);
  goto pop_function;
/* fn_84 */
body_166:
  increment_count(env);
  val = wrap_function((&&function_385), env);
  global_c102c110c95c56c52 = val; /* fn_84 */
  goto body_167;
pointer global_c95c100c101c102c97c117c108c116;
function_386:
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  goto body_168;
/* _default */
body_167:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c56c53); /* fn_85 */
  target = (&&function_386);
  goto apply_addr;
pointer global_c102c110c95c56c57; /* fn_89 */
pointer global_c102c110c95c57c48;
function_387:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56c57); /* fn_89 */
  goto top_level_apply;
function_388:
  increment_count(env);
  val = wrap_function((&&function_387), env);
  goto pop_function;
/* fn_90 */
body_168:
global_c102c110c95c56c57 = NIL; /* fn_89 */
  increment_count(env);
  val = wrap_function((&&function_388), env);
  global_c102c110c95c57c48 = val; /* fn_90 */
  goto body_169;
pointer global_c102c110c95c56c56; /* fn_88 */
function_389:
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
  goto top_level_apply;
function_390:
  increment_count(env);
  val = wrap_function((&&function_389), env);
  goto pop_function;
/* fn_89 */
body_169:
global_c102c110c95c56c56 = NIL; /* fn_88 */
  increment_count(env);
  val = wrap_function((&&function_390), env);
  global_c102c110c95c56c57 = val; /* fn_89 */
  goto body_170;
pointer global_c102c110c95c56c55; /* fn_87 */
pointer global_c102c110c95c56c54; /* fn_86 */
function_391:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_392:
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
  target = (&&function_391);
  goto apply_addr;
function_393:
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
  target = (&&function_392);
  goto apply_addr;
function_394:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  goto pop_function;
/* fn_88 */
body_170:
global_c102c110c95c56c55 = NIL; /* fn_87 */
global_c102c110c95c56c54 = NIL; /* fn_86 */
  increment_count(env);
  val = wrap_function((&&function_394), env);
  global_c102c110c95c56c56 = val; /* fn_88 */
  goto body_171;
function_395:
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
function_396:
  increment_count(env);
  val = wrap_function((&&function_395), env);
  goto pop_function;
/* fn_86 */
body_171:
  increment_count(env);
  val = wrap_function((&&function_396), env);
  global_c102c110c95c56c54 = val; /* fn_86 */
  goto body_172;
function_397:
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
function_398:
  increment_count(env);
  val = wrap_function((&&function_397), env);
  goto pop_function;
/* fn_87 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_398), env);
  global_c102c110c95c56c55 = val; /* fn_87 */
  goto body_173;
pointer global_c95c99c97c115c101;
function_399:
  global_c95c99c97c115c101 = val; /* _case */
  goto body_174;
/* _case */
body_173:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c48); /* fn_90 */
  target = (&&function_399);
  goto apply_addr;
pointer global_c102c110c95c57c49; /* fn_91 */
pointer global_c102c110c95c57c50;
function_400:
  goto top_level_apply;
function_401:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_400);
  goto apply_addr;
function_402:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c49); /* fn_91 */
  target = (&&function_401);
  goto apply_addr;
function_403:
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
  target = (&&function_402);
  goto apply_addr;
function_404:
  increment_count(env);
  val = wrap_function((&&function_403), env);
  goto pop_function;
/* fn_92 */
body_174:
global_c102c110c95c57c49 = NIL; /* fn_91 */
  increment_count(env);
  val = wrap_function((&&function_404), env);
  global_c102c110c95c57c50 = val; /* fn_92 */
  goto body_175;
function_405:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_406:
  increment_count(env);
  val = wrap_function((&&function_405), env);
  goto pop_function;
/* fn_91 */
body_175:
  increment_count(env);
  val = wrap_function((&&function_406), env);
  global_c102c110c95c57c49 = val; /* fn_91 */
  goto body_176;
pointer global_c95c99c104c111c105c99c101;
function_407:
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  goto body_177;
/* _choice */
body_176:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c50); /* fn_92 */
  target = (&&function_407);
  goto apply_addr;
pointer global_c102c110c95c57c52; /* fn_94 */
pointer global_c102c110c95c57c53;
function_408:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c52); /* fn_94 */
  goto top_level_apply;
function_409:
  increment_count(env);
  val = wrap_function((&&function_408), env);
  goto pop_function;
/* fn_95 */
body_177:
global_c102c110c95c57c52 = NIL; /* fn_94 */
  increment_count(env);
  val = wrap_function((&&function_409), env);
  global_c102c110c95c57c53 = val; /* fn_95 */
  goto body_178;
pointer global_c102c110c95c57c51; /* fn_93 */
function_410:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_411:
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
  target = (&&function_410);
  goto apply_addr;
function_412:
  increment_count(env);
  val = wrap_function((&&function_411), env);
  goto pop_function;
/* fn_94 */
body_178:
global_c102c110c95c57c51 = NIL; /* fn_93 */
  increment_count(env);
  val = wrap_function((&&function_412), env);
  global_c102c110c95c57c52 = val; /* fn_94 */
  goto body_179;
function_413:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_414:
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
  target = (&&function_413);
  goto apply_addr;
function_415:
  increment_count(env);
  val = wrap_function((&&function_414), env);
  goto pop_function;
/* fn_93 */
body_179:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  global_c102c110c95c57c51 = val; /* fn_93 */
  goto body_180;
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
function_416:
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  goto body_181;
/* _post-process */
body_180:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c53); /* fn_95 */
  target = (&&function_416);
  goto apply_addr;
pointer global_c102c110c95c57c56; /* fn_98 */
pointer global_c102c110c95c57c57;
function_417:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57c56); /* fn_98 */
  goto top_level_apply;
function_418:
  increment_count(env);
  val = wrap_function((&&function_417), env);
  goto pop_function;
/* fn_99 */
body_181:
global_c102c110c95c57c56 = NIL; /* fn_98 */
  increment_count(env);
  val = wrap_function((&&function_418), env);
  global_c102c110c95c57c57 = val; /* fn_99 */
  goto body_182;
pointer global_c102c110c95c57c55; /* fn_97 */
function_419:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_420:
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
  target = (&&function_419);
  goto apply_addr;
function_421:
  increment_count(env);
  val = wrap_function((&&function_420), env);
  goto pop_function;
/* fn_98 */
body_182:
global_c102c110c95c57c55 = NIL; /* fn_97 */
  increment_count(env);
  val = wrap_function((&&function_421), env);
  global_c102c110c95c57c56 = val; /* fn_98 */
  goto body_183;
pointer global_c102c110c95c57c54; /* fn_96 */
function_422:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_423:
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
  target = (&&function_422);
  goto apply_addr;
function_424:
  increment_count(env);
  val = wrap_function((&&function_423), env);
  goto pop_function;
/* fn_97 */
body_183:
global_c102c110c95c57c54 = NIL; /* fn_96 */
  increment_count(env);
  val = wrap_function((&&function_424), env);
  global_c102c110c95c57c55 = val; /* fn_97 */
  goto body_184;
function_425:
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
function_426:
  increment_count(env);
  val = wrap_function((&&function_425), env);
  goto pop_function;
/* fn_96 */
body_184:
  increment_count(env);
  val = wrap_function((&&function_426), env);
  global_c102c110c95c57c54 = val; /* fn_96 */
  goto body_185;
pointer global_c95c115c101c113;
function_427:
  global_c95c115c101c113 = val; /* _seq */
  goto body_186;
/* _seq */
body_185:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c57c57); /* fn_99 */
  target = (&&function_427);
  goto apply_addr;
pointer global_c102c110c95c49c48c48;
function_428:
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_429:
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
  target = (&&function_428);
  goto apply_addr;
function_430:
  increment_count(env);
  val = wrap_function((&&function_429), env);
  goto pop_function;
/* fn_100 */
body_186:
  increment_count(env);
  val = wrap_function((&&function_430), env);
  global_c102c110c95c49c48c48 = val; /* fn_100 */
  goto body_187;
pointer global_c95c101c115c99c97c112c101;
function_431:
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  goto body_188;
/* _escape */
body_187:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c48); /* fn_100 */
  target = (&&function_431);
  goto apply_addr;
pointer global_c102c110c95c49c48c49;
function_432:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_433:
  increment_count(env);
  val = wrap_function((&&function_432), env);
  goto pop_function;
/* fn_101 */
body_188:
  increment_count(env);
  val = wrap_function((&&function_433), env);
  global_c102c110c95c49c48c49 = val; /* fn_101 */
  goto body_189;
pointer global_c95c117c115c101;
function_434:
  global_c95c117c115c101 = val; /* _use */
  goto body_190;
/* _use */
body_189:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c49); /* fn_101 */
  target = (&&function_434);
  goto apply_addr;
pointer global_c102c110c95c49c48c51; /* fn_103 */
pointer global_c102c110c95c49c48c52;
function_435:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48c51); /* fn_103 */
  goto top_level_apply;
function_436:
  increment_count(env);
  val = wrap_function((&&function_435), env);
  goto pop_function;
/* fn_104 */
body_190:
global_c102c110c95c49c48c51 = NIL; /* fn_103 */
  increment_count(env);
  val = wrap_function((&&function_436), env);
  global_c102c110c95c49c48c52 = val; /* fn_104 */
  goto body_191;
pointer global_c102c110c95c49c48c50; /* fn_102 */
function_437:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_438:
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
  target = (&&function_437);
  goto apply_addr;
function_439:
  increment_count(env);
  val = wrap_function((&&function_438), env);
  goto pop_function;
/* fn_103 */
body_191:
global_c102c110c95c49c48c50 = NIL; /* fn_102 */
  increment_count(env);
  val = wrap_function((&&function_439), env);
  global_c102c110c95c49c48c51 = val; /* fn_103 */
  goto body_192;
function_440:
  goto top_level_apply;
function_441:
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
  target = (&&function_440);
  goto apply_addr;
function_442:
  increment_count(env);
  val = wrap_function((&&function_441), env);
  goto pop_function;
/* fn_102 */
body_192:
  increment_count(env);
  val = wrap_function((&&function_442), env);
  global_c102c110c95c49c48c50 = val; /* fn_102 */
  goto body_193;
pointer global_c95c112c101c101c107;
function_443:
  global_c95c112c101c101c107 = val; /* _peek */
  goto body_194;
/* _peek */
body_193:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c52); /* fn_104 */
  target = (&&function_443);
  goto apply_addr;
pointer global_c102c110c95c49c48c53; /* fn_105 */
pointer global_c102c110c95c49c48c54;
function_444:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_445:
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
  target = (&&function_444);
  goto apply_addr;
function_446:
  increment_count(env);
  val = wrap_function((&&function_445), env);
  goto pop_function;
/* fn_106 */
body_194:
global_c102c110c95c49c48c53 = NIL; /* fn_105 */
  increment_count(env);
  val = wrap_function((&&function_446), env);
  global_c102c110c95c49c48c54 = val; /* fn_106 */
  goto body_195;
function_447:
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
function_448:
  increment_count(env);
  val = wrap_function((&&function_447), env);
  goto pop_function;
/* fn_105 */
body_195:
  increment_count(env);
  val = wrap_function((&&function_448), env);
  global_c102c110c95c49c48c53 = val; /* fn_105 */
  goto body_196;
pointer global_c95c105c110c116c101c114c118c97c108;
function_449:
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  goto body_197;
/* _interval */
body_196:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c54); /* fn_106 */
  target = (&&function_449);
  goto apply_addr;
pointer global_c99c100c114; /* cdr */
pointer global_c102c110c95c49c48c55;
function_450:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_451:
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
  target = (&&function_450);
  goto apply_addr;
function_452:
  increment_count(env);
  val = wrap_function((&&function_451), env);
  goto pop_function;
/* fn_107 */
body_197:
global_c99c100c114 = CDR; /* cdr */
  increment_count(env);
  val = wrap_function((&&function_452), env);
  global_c102c110c95c49c48c55 = val; /* fn_107 */
  goto body_198;
pointer global_c95c115c107c105c112;
function_453:
  global_c95c115c107c105c112 = val; /* _skip */
  goto body_199;
/* _skip */
body_198:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c55); /* fn_107 */
  target = (&&function_453);
  goto apply_addr;
pointer global_c99c97c114; /* car */
pointer global_c102c110c95c49c48c56;
function_454:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_455:
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
  target = (&&function_454);
  goto apply_addr;
function_456:
  increment_count(env);
  val = wrap_function((&&function_455), env);
  goto pop_function;
/* fn_108 */
body_199:
global_c99c97c114 = CAR; /* car */
  increment_count(env);
  val = wrap_function((&&function_456), env);
  global_c102c110c95c49c48c56 = val; /* fn_108 */
  goto body_200;
pointer global_c95c102c105c114c115c116;
function_457:
  global_c95c102c105c114c115c116 = val; /* _first */
  goto body_201;
/* _first */
body_200:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c56); /* fn_108 */
  target = (&&function_457);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c110c117c109; /* _parse-num */
pointer global_c102c110c95c49c48c57;
function_458:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_459:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_458);
  goto apply_addr;
function_460:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_459);
  goto apply_addr;
function_461:
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
  target = (&&function_460);
  goto apply_addr;
function_462:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_461);
  goto apply_addr;
function_463:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_462);
  goto apply_addr;
function_464:
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
  target = (&&function_463);
  goto apply_addr;
function_465:
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
  target = (&&function_464);
  goto apply_addr;
function_466:
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
  target = (&&function_465);
  goto apply_addr;
function_467:
  increment_count(env);
  val = wrap_function((&&function_466), env);
  goto pop_function;
/* fn_109 */
body_201:
global_c95c112c97c114c115c101c45c110c117c109 = NIL; /* _parse-num */
  increment_count(env);
  val = wrap_function((&&function_467), env);
  global_c102c110c95c49c48c57 = val; /* fn_109 */
  goto body_202;
function_468:
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  goto body_203;
/* _parse-num */
body_202:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c48c57); /* fn_109 */
  target = (&&function_468);
  goto apply_addr;
pointer global_c102c110c95c49c49c48;
function_469:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_470:
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
  target = (&&function_469);
  goto apply_addr;
function_471:
  increment_count(env);
  val = wrap_function((&&function_470), env);
  goto pop_function;
/* fn_110 */
body_203:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  global_c102c110c95c49c49c48 = val; /* fn_110 */
  goto body_204;
pointer global_c95c114c101c97c100c45c110c117c109;
function_472:
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  goto body_205;
/* _read-num */
body_204:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c48); /* fn_110 */
  target = (&&function_472);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c49c49c49;
function_473:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_474:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_473);
  goto apply_addr;
function_475:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_474);
  goto apply_addr;
function_476:
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
  target = (&&function_475);
  goto apply_addr;
function_477:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_476);
  goto apply_addr;
function_478:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_477);
  goto apply_addr;
function_479:
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
  target = (&&function_478);
  goto apply_addr;
function_480:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_479);
  goto apply_addr;
function_481:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_480);
  goto apply_addr;
function_482:
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
  target = (&&function_481);
  goto apply_addr;
function_483:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_482);
  goto apply_addr;
function_484:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_483);
  goto apply_addr;
function_485:
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
  target = (&&function_484);
  goto apply_addr;
function_486:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_485);
  goto apply_addr;
function_487:
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
  target = (&&function_486);
  goto apply_addr;
function_488:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  goto pop_function;
/* fn_111 */
body_205:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = NIL; /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_488), env);
  global_c102c110c95c49c49c49 = val; /* fn_111 */
  goto body_206;
function_489:
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_207;
/* _parse-symbol */
body_206:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c49); /* fn_111 */
  target = (&&function_489);
  goto apply_addr;
pointer global_c102c110c95c49c49c50;
function_490:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_491:
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
  target = (&&function_490);
  goto apply_addr;
function_492:
  increment_count(env);
  val = wrap_function((&&function_491), env);
  goto pop_function;
/* fn_112 */
body_207:
  increment_count(env);
  val = wrap_function((&&function_492), env);
  global_c102c110c95c49c49c50 = val; /* fn_112 */
  goto body_208;
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
function_493:
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  goto body_209;
/* _read-symbol */
body_208:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c50); /* fn_112 */
  target = (&&function_493);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c102c110c95c49c49c51;
function_494:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_495:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_494);
  goto apply_addr;
function_496:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_495);
  goto apply_addr;
function_497:
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
  target = (&&function_496);
  goto apply_addr;
function_498:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_497);
  goto apply_addr;
function_499:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_498);
  goto apply_addr;
function_500:
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
  target = (&&function_499);
  goto apply_addr;
function_501:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_500);
  goto apply_addr;
function_502:
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
  target = (&&function_501);
  goto apply_addr;
function_503:
  increment_count(env);
  val = wrap_function((&&function_502), env);
  goto pop_function;
/* fn_113 */
body_209:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = NIL; /* _parse-string */
  increment_count(env);
  val = wrap_function((&&function_503), env);
  global_c102c110c95c49c49c51 = val; /* fn_113 */
  goto body_210;
function_504:
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_211;
/* _parse-string */
body_210:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c51); /* fn_113 */
  target = (&&function_504);
  goto apply_addr;
pointer global_c102c110c95c49c49c52;
function_505:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c111c116c101c45c118c97c108c117c101); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_506:
  increment_count(env);
  val = wrap_function((&&function_505), env);
  goto pop_function;
/* fn_114 */
body_211:
  increment_count(env);
  val = wrap_function((&&function_506), env);
  global_c102c110c95c49c49c52 = val; /* fn_114 */
  goto body_212;
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
function_507:
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  goto body_213;
/* _quote-parser */
body_212:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c52); /* fn_114 */
  target = (&&function_507);
  goto apply_addr;
pointer global_c102c110c95c49c49c53;
function_508:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_509:
  increment_count(env);
  val = wrap_function((&&function_508), env);
  goto pop_function;
/* fn_115 */
body_213:
  increment_count(env);
  val = wrap_function((&&function_509), env);
  global_c102c110c95c49c49c53 = val; /* fn_115 */
  goto body_214;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
function_510:
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  goto body_215;
/* _quasiquote-parser */
body_214:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c53); /* fn_115 */
  target = (&&function_510);
  goto apply_addr;
pointer global_c102c110c95c49c49c54;
function_511:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_512:
  increment_count(env);
  val = wrap_function((&&function_511), env);
  goto pop_function;
/* fn_116 */
body_215:
  increment_count(env);
  val = wrap_function((&&function_512), env);
  global_c102c110c95c49c49c54 = val; /* fn_116 */
  goto body_216;
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
function_513:
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  goto body_217;
/* _unquote-parser */
body_216:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c54); /* fn_116 */
  target = (&&function_513);
  goto apply_addr;
pointer global_c102c110c95c49c49c55; /* fn_117 */
pointer global_c102c110c95c49c49c56;
function_514:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49c55); /* fn_117 */
  goto top_level_apply;
function_515:
  increment_count(env);
  val = wrap_function((&&function_514), env);
  goto pop_function;
/* fn_118 */
body_217:
global_c102c110c95c49c49c55 = NIL; /* fn_117 */
  increment_count(env);
  val = wrap_function((&&function_515), env);
  global_c102c110c95c49c49c56 = val; /* fn_118 */
  goto body_218;
pointer global_c95c99c111c109c109c101c110c116; /* _comment */
function_516:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_517:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_516);
  goto apply_addr;
function_518:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_517);
  goto apply_addr;
function_519:
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
  target = (&&function_518);
  goto apply_addr;
function_520:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_519);
  goto apply_addr;
function_521:
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
  target = (&&function_520);
  goto apply_addr;
function_522:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_521);
  goto apply_addr;
function_523:
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  target = (&&function_522);
  goto apply_addr;
function_524:
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
  target = (&&function_523);
  goto apply_addr;
function_525:
  increment_count(env);
  val = wrap_function((&&function_524), env);
  goto pop_function;
/* fn_117 */
body_218:
global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
  increment_count(env);
  val = wrap_function((&&function_525), env);
  global_c102c110c95c49c49c55 = val; /* fn_117 */
  goto body_219;
function_526:
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  goto body_220;
/* _comment */
body_219:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c56); /* fn_118 */
  target = (&&function_526);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c49c49c57;
function_527:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_528:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_527);
  goto apply_addr;
function_529:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_528);
  goto apply_addr;
function_530:
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
  target = (&&function_529);
  goto apply_addr;
function_531:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_530);
  goto apply_addr;
function_532:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_531);
  goto apply_addr;
function_533:
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
  target = (&&function_532);
  goto apply_addr;
function_534:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_533);
  goto apply_addr;
function_535:
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
  target = (&&function_534);
  goto apply_addr;
function_536:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_535);
  goto apply_addr;
function_537:
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
  target = (&&function_536);
  goto apply_addr;
function_538:
  increment_count(env);
  val = wrap_function((&&function_537), env);
  goto pop_function;
/* fn_119 */
body_220:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = NIL; /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_538), env);
  global_c102c110c95c49c49c57 = val; /* fn_119 */
  goto body_221;
function_539:
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_222;
/* _parse-paren */
body_221:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c49c57); /* fn_119 */
  target = (&&function_539);
  goto apply_addr;
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c49c50c48;
function_540:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_541:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_540);
  goto apply_addr;
function_542:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_541);
  goto apply_addr;
function_543:
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
  target = (&&function_542);
  goto apply_addr;
function_544:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_543);
  goto apply_addr;
function_545:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_544);
  goto apply_addr;
function_546:
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
  target = (&&function_545);
  goto apply_addr;
function_547:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_546);
  goto apply_addr;
function_548:
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
  target = (&&function_547);
  goto apply_addr;
function_549:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_548);
  goto apply_addr;
function_550:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_549);
  goto apply_addr;
function_551:
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
  target = (&&function_550);
  goto apply_addr;
function_552:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_551);
  goto apply_addr;
function_553:
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
  target = (&&function_552);
  goto apply_addr;
function_554:
  increment_count(env);
  val = wrap_function((&&function_553), env);
  goto pop_function;
/* fn_120 */
body_222:
global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
global_c95c112c97c114c115c101c45c112c97c105c114 = NIL; /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_554), env);
  global_c102c110c95c49c50c48 = val; /* fn_120 */
  goto body_223;
function_555:
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_224;
/* _parse-pair */
body_223:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c48); /* fn_120 */
  target = (&&function_555);
  goto apply_addr;
pointer global_c102c110c95c49c50c49;
function_556:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_557:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_556);
  goto apply_addr;
function_558:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_557);
  goto apply_addr;
function_559:
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
  target = (&&function_558);
  goto apply_addr;
function_560:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_559);
  goto apply_addr;
function_561:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_560);
  goto apply_addr;
function_562:
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
  target = (&&function_561);
  goto apply_addr;
function_563:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_562);
  goto apply_addr;
function_564:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_563);
  goto apply_addr;
function_565:
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
  target = (&&function_564);
  goto apply_addr;
function_566:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_565);
  goto apply_addr;
function_567:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_566);
  goto apply_addr;
function_568:
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
  target = (&&function_567);
  goto apply_addr;
function_569:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_568);
  goto apply_addr;
function_570:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_569);
  goto apply_addr;
function_571:
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
  target = (&&function_570);
  goto apply_addr;
function_572:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_571);
  goto apply_addr;
function_573:
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
  target = (&&function_572);
  goto apply_addr;
function_574:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_573);
  goto apply_addr;
function_575:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_574);
  goto apply_addr;
function_576:
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
  target = (&&function_575);
  goto apply_addr;
function_577:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_576);
  goto apply_addr;
function_578:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_577);
  goto apply_addr;
function_579:
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
  target = (&&function_578);
  goto apply_addr;
function_580:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_579);
  goto apply_addr;
function_581:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_580);
  goto apply_addr;
function_582:
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
  target = (&&function_581);
  goto apply_addr;
function_583:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_582);
  goto apply_addr;
function_584:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_583);
  goto apply_addr;
function_585:
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
  target = (&&function_584);
  goto apply_addr;
function_586:
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
  target = (&&function_585);
  goto apply_addr;
function_587:
  increment_count(env);
  val = wrap_function((&&function_586), env);
  goto pop_function;
/* fn_121 */
body_224:
  increment_count(env);
  val = wrap_function((&&function_587), env);
  global_c102c110c95c49c50c49 = val; /* fn_121 */
  goto body_225;
function_588:
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_226;
/* _parse-expr */
body_225:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c49); /* fn_121 */
  target = (&&function_588);
  goto apply_addr;
pointer global_c102c110c95c49c50c50; /* fn_122 */
pointer global_c102c110c95c49c50c51;
function_589:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  goto top_level_apply;
function_590:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c50); /* fn_122 */
  target = (&&function_589);
  goto apply_addr;
function_591:
  increment_count(env);
  val = wrap_function((&&function_590), env);
  goto pop_function;
/* fn_123 */
body_226:
global_c102c110c95c49c50c50 = NIL; /* fn_122 */
  increment_count(env);
  val = wrap_function((&&function_591), env);
  global_c102c110c95c49c50c51 = val; /* fn_123 */
  goto body_227;
function_592:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  goto top_level_apply;
function_593:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c55); /* ___l_27 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_592);
  goto apply_addr;
function_594:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56); /* ___l_28 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_593);
  goto apply_addr;
function_595:
  increment_count(env);
  val = wrap_function((&&function_594), env);
  goto pop_function;
/* fn_122 */
body_227:
  increment_count(env);
  val = wrap_function((&&function_595), env);
  global_c102c110c95c49c50c50 = val; /* fn_122 */
  goto body_228;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_596:
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_229;
/* ____read-expr */
body_228:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c51); /* fn_123 */
  target = (&&function_596);
  goto apply_addr;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_229:
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
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_230;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_230:
  val = -35;
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_231;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_231:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_232;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_232:
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
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_233;
pointer global_c102c110c95c49c50c52;
function_597:
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
function_598:
  increment_count(env);
  val = wrap_function((&&function_597), env);
  goto pop_function;
/* fn_124 */
body_233:
  increment_count(env);
  val = wrap_function((&&function_598), env);
  global_c102c110c95c49c50c52 = val; /* fn_124 */
  goto body_234;
pointer global_c95c99c97c97c100c114;
function_599:
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_235;
/* _caadr */
body_234:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c52); /* fn_124 */
  target = (&&function_599);
  goto apply_addr;
pointer global_c102c110c95c49c50c53; /* fn_125 */
pointer global_c102c110c95c49c50c54;
function_600:
  goto top_level_apply;
function_601:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_600);
  goto apply_addr;
function_602:
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
  target = (&&function_601);
  goto apply_addr;
function_603:
  increment_count(env);
  val = wrap_function((&&function_602), env);
  goto pop_function;
/* fn_126 */
body_235:
global_c102c110c95c49c50c53 = NIL; /* fn_125 */
  increment_count(env);
  val = wrap_function((&&function_603), env);
  global_c102c110c95c49c50c54 = val; /* fn_126 */
  goto body_236;
function_604:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_605:
  increment_count(env);
  val = wrap_function((&&function_604), env);
  goto pop_function;
/* fn_125 */
body_236:
  increment_count(env);
  val = wrap_function((&&function_605), env);
  global_c102c110c95c49c50c53 = val; /* fn_125 */
  goto body_237;
pointer global_c95c111c114;
function_606:
  global_c95c111c114 = val; /* _or */
  goto body_238;
/* _or */
body_237:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c54); /* fn_126 */
  target = (&&function_606);
  goto apply_addr;
pointer global_c102c110c95c49c50c55;
function_607:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
  } else {
    val = -34;
    goto pop_function;
  }
function_608:
  increment_count(env);
  val = wrap_function((&&function_607), env);
  goto pop_function;
/* fn_127 */
body_238:
  increment_count(env);
  val = wrap_function((&&function_608), env);
  global_c102c110c95c49c50c55 = val; /* fn_127 */
  goto body_239;
pointer global_c95c110c111c116;
function_609:
  global_c95c110c111c116 = val; /* _not */
  goto body_240;
/* _not */
body_239:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c50c55); /* fn_127 */
  target = (&&function_609);
  goto apply_addr;
pointer global_c102c110c95c49c51c48; /* fn_130 */
pointer global_c102c110c95c49c51c49;
function_610:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51c48); /* fn_130 */
  goto top_level_apply;
function_611:
  increment_count(env);
  val = wrap_function((&&function_610), env);
  goto pop_function;
/* fn_131 */
body_240:
global_c102c110c95c49c51c48 = NIL; /* fn_130 */
  increment_count(env);
  val = wrap_function((&&function_611), env);
  global_c102c110c95c49c51c49 = val; /* fn_131 */
  goto body_241;
pointer global_c102c110c95c49c50c57; /* fn_129 */
pointer global_c102c110c95c49c50c56; /* fn_128 */
function_612:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101); /* ____compile */
  goto top_level_apply;
function_613:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101); /* ____compile */
  goto top_level_apply;
function_614:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
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
    increment_count(val = global_c102c110c95c49c50c57); /* fn_129 */
    target = (&&function_613);
    goto apply_addr;
  }
function_615:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_614);
  goto apply_addr;
function_616:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_615);
  goto apply_addr;
function_617:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_616);
  goto apply_addr;
function_618:
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
  target = (&&function_617);
  goto apply_addr;
function_619:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_618);
  goto apply_addr;
function_620:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c102c110c95c49c50c56); /* fn_128 */
    target = (&&function_612);
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
    target = (&&function_619);
    goto apply_addr;
  }
function_621:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_620);
  goto apply_addr;
function_622:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
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
    increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
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
    target = (&&function_621);
    goto apply_addr;
  }
function_623:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_622);
  goto apply_addr;
function_624:
  increment_count(env);
  val = wrap_function((&&function_623), env);
  goto pop_function;
/* fn_130 */
body_241:
global_c102c110c95c49c50c57 = NIL; /* fn_129 */
global_c102c110c95c49c50c56 = NIL; /* fn_128 */
  increment_count(env);
  val = wrap_function((&&function_624), env);
  global_c102c110c95c49c51c48 = val; /* fn_130 */
  goto body_242;
function_625:
  increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
  goto pop_function;
function_626:
  increment_count(env);
  val = wrap_function((&&function_625), env);
  goto pop_function;
/* fn_128 */
body_242:
  increment_count(env);
  val = wrap_function((&&function_626), env);
  global_c102c110c95c49c50c56 = val; /* fn_128 */
  goto body_243;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
function_627:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_628:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_627);
  goto apply_addr;
function_629:
  increment_count(env);
  val = wrap_function((&&function_628), env);
  goto pop_function;
/* fn_129 */
body_243:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_629), env);
  global_c102c110c95c49c50c57 = val; /* fn_129 */
  goto body_244;
function_630:
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_245;
/* ____compile-source */
body_244:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c49); /* fn_131 */
  target = (&&function_630);
  goto apply_addr;
pointer global_c102c110c95c49c51c50;
function_631:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_632:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_631);
  goto apply_addr;
function_633:
  increment_count(env);
  val = wrap_function((&&function_632), env);
  goto pop_function;
/* fn_132 */
body_245:
  increment_count(env);
  val = wrap_function((&&function_633), env);
  global_c102c110c95c49c51c50 = val; /* fn_132 */
  goto body_246;
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
function_634:
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
body_246:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c102c110c95c49c51c50); /* fn_132 */
  goto top_level_apply;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), NIL), call_stack);
  call_stack = cons(wrap_function((&&function_634), NIL), call_stack);
  goto body_0;
}
