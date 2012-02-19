#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#include "io.h"
#include "mem.h"
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
pointer global_c95c101c113c117c97c108;
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
/* _equal */
body_0:
  increment_count(env);
  val = wrap_function((&&function_1), env);
  global_c95c101c113c117c97c108 = val; /* _equal */
  goto body_1;
pointer global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
function_2:
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
function_3:
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
    target = (&&function_2);
    goto apply_addr;
  }
/* _symbol->string */
body_1:
  increment_count(env);
  val = wrap_function((&&function_3), env);
  global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* _symbol->string */
  goto body_2;
pointer global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_4:
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
function_5:
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
    target = (&&function_4);
    goto apply_addr;
  }
function_6:
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
    target = (&&function_5);
    goto apply_addr;
  }
function_7:
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
    target = (&&function_6);
    goto apply_addr;
  }
function_8:
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
    target = (&&function_7);
    goto apply_addr;
  }
function_9:
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
    target = (&&function_8);
    goto apply_addr;
  }
function_10:
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
    target = (&&function_9);
    goto apply_addr;
  }
function_11:
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
    target = (&&function_11);
    goto apply_addr;
  }
function_13:
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
    target = (&&function_12);
    goto apply_addr;
  }
function_14:
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
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
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
    target = (&&function_14);
    goto apply_addr;
  }
function_16:
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
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
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
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
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
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
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
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
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
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
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
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
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
    target = (&&function_22);
    goto apply_addr;
  }
function_24:
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
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
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
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
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
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
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
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
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
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
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
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
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
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
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
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
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
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
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
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
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
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
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
  target = (&&function_34);
  goto apply_addr;
/* _string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_35), env);
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_3;
pointer global_c95c115c121c109c98c111c108c63;
function_36:
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
/* _symbol? */
body_3:
  increment_count(env);
  val = wrap_function((&&function_36), env);
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  goto body_4;
pointer global_c95c95c97c116c111c109;
function_37:
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
/* __atom */
body_4:
  increment_count(env);
  val = wrap_function((&&function_37), env);
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_5;
pointer global_c95c95c61;
function_38:
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
function_39:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_38);
  goto apply_addr;
/* __= */
body_5:
  increment_count(env);
  val = wrap_function((&&function_39), env);
  global_c95c95c61 = val; /* __= */
  goto body_6;
pointer global_c95c108c105c115c116;
function_40:
  increment_count(val = car(env));
  goto pop_function;
/* _list */
body_6:
  increment_count(env);
  val = wrap_function((&&function_40), env);
  global_c95c108c105c115c116 = val; /* _list */
  goto body_7;
pointer global_c95c114c114c101c118c101c114c115c101;
function_41:
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
function_42:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_41);
  goto apply_addr;
/* _rreverse */
body_7:
  increment_count(env);
  val = wrap_function((&&function_42), env);
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_8;
pointer global_c95c102c111c108c100c108; /* _foldl */
pointer global_c102c110c95c48;
function_43:
  goto top_level_apply;
function_44:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_43);
  goto apply_addr;
function_45:
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
    target = (&&function_44);
    goto apply_addr;
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
/* fn_0 */
body_8:
global_c95c102c111c108c100c108 = NIL; /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_47), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_9;
function_48:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c48); /* fn_0 */
  goto top_level_apply;
/* _foldl */
body_9:
  increment_count(env);
  val = wrap_function((&&function_48), env);
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_10;
pointer global_c102c110c95c49;
function_49:
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  goto top_level_apply;
function_50:
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
  target = (&&function_49);
  goto apply_addr;
function_51:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  goto pop_function;
/* fn_1 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_51), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_11;
pointer global_c95c102c111c108c100c114;
function_52:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49); /* fn_1 */
  goto top_level_apply;
/* _foldr */
body_11:
  increment_count(env);
  val = wrap_function((&&function_52), env);
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_12;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_53:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_13;
function_54:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_55:
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
  target = (&&function_54);
  goto apply_addr;
/* ____map-to-stderr */
body_12:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_55), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_53);
  goto apply_addr;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_13:
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
  goto body_14;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_14:
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
  goto body_15;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_15:
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
  goto body_16;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_16:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_17;
pointer global_c95c105c100;
function_56:
  increment_count(val = car(car(env)));
  goto pop_function;
/* _id */
body_17:
  increment_count(env);
  val = wrap_function((&&function_56), env);
  global_c95c105c100 = val; /* _id */
  goto body_18;
pointer global_c95c119c97c108c107; /* _walk */
pointer global_c102c110c95c50;
function_57:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_58:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_57);
  goto apply_addr;
function_59:
  target = (&&function_58);
  goto apply_addr;
function_60:
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
  target = (&&function_59);
  goto apply_addr;
function_61:
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
    target = (&&function_60);
    goto apply_addr;
  }
function_62:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_61);
  goto apply_addr;
function_63:
  increment_count(env);
  val = wrap_function((&&function_62), env);
  goto pop_function;
/* fn_2 */
body_18:
global_c95c119c97c108c107 = NIL; /* _walk */
  increment_count(env);
  val = wrap_function((&&function_63), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_19;
function_64:
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
  increment_count(val = global_c102c110c95c50); /* fn_2 */
  goto top_level_apply;
/* _walk */
body_19:
  increment_count(env);
  val = wrap_function((&&function_64), env);
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_20;
pointer global_c95c97c112c112c101c110c100;
function_65:
  goto top_level_apply;
function_66:
  goto top_level_apply;
function_67:
  push_args();
  increment_count(val = car(env));
  args = val;
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_68:
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
    increment_count(env);
    val = wrap_function((&&function_67), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
    target = (&&function_66);
    goto apply_addr;
  }
function_69:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_68);
  goto apply_addr;
function_70:
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
  increment_count(env);
  val = wrap_function((&&function_69), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_65);
  goto apply_addr;
/* _append */
body_20:
  increment_count(env);
  val = wrap_function((&&function_70), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_21;
pointer global_c102c110c95c51;
function_71:
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
function_72:
  increment_count(env);
  val = wrap_function((&&function_71), env);
  goto pop_function;
/* fn_3 */
body_21:
  increment_count(env);
  val = wrap_function((&&function_72), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_22;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_73:
  goto top_level_apply;
function_74:
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
function_75:
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
function_76:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_77:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  goto top_level_apply;
function_78:
  increment_count(val = global_c95c105c100); /* _id */
  goto pop_function;
function_79:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = wrap_function((&&function_78), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_77), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_76), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_75), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_74), env);
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  target = (&&function_73);
  goto apply_addr;
/* _build-num-str */
body_22:
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_23;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_80:
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
function_81:
  target = (&&function_80);
  goto apply_addr;
function_82:
  goto top_level_apply;
function_83:
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
      target = (&&function_81);
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
      target = (&&function_82);
      goto apply_addr;
    }
  }
function_84:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_83);
  goto apply_addr;
/* _print-num */
body_23:
  increment_count(env);
  val = wrap_function((&&function_84), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_24;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_85:
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
function_86:
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
      target = (&&function_85);
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
/* _print-atom */
body_24:
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_25;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_87:
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
function_88:
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
function_89:
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
  target = (&&function_88);
  goto apply_addr;
function_90:
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
    target = (&&function_87);
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
    target = (&&function_89);
    goto apply_addr;
  }
function_91:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_90);
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
/* _print-tail */
body_25:
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_91), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_26;
function_92:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_93:
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
function_94:
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
  target = (&&function_93);
  goto apply_addr;
function_95:
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
    target = (&&function_92);
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
    target = (&&function_94);
    goto apply_addr;
  }
function_96:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_95);
  goto apply_addr;
/* _print-with-suffix */
body_26:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_27;
pointer global_c95c112c114c105c110c116;
function_97:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120); /* _print-with-suffix */
  goto top_level_apply;
/* _print */
body_27:
  increment_count(env);
  val = wrap_function((&&function_97), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_28;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_98:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_99:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_98);
  goto apply_addr;
function_100:
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
    target = (&&function_99);
    goto apply_addr;
  } else {
    val = NIL;
    goto pop_function;
  }
/* ____print-warnings */
body_28:
  increment_count(env);
  val = wrap_function((&&function_100), env);
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_29;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_29:
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
  goto body_30;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_30:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_31;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_101:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_102:
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
  target = (&&function_101);
  goto apply_addr;
/* ____print-error */
body_31:
  increment_count(env);
  val = wrap_function((&&function_102), env);
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_32;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_32:
  val = NIL;
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_33;
pointer global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
function_103:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_104:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_103);
  goto apply_addr;
function_105:
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
  target = (&&function_104);
  goto apply_addr;
/* ____number->symbol */
body_33:
  increment_count(env);
  val = wrap_function((&&function_105), env);
  global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ____number->symbol */
  goto body_34;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_34:
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
  goto body_35;
pointer global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ____special-forms */
body_35:
  increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
  global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ____special-forms */
  goto body_36;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_36:
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
  goto body_37;
pointer global_c95c95c95c95c98c117c105c108c116c105c110c115;
/* ____builtins */
body_37:
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  global_c95c95c95c95c98c117c105c108c116c105c110c115 = val; /* ____builtins */
  goto body_38;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_38:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_39;
pointer global_c95c95c101c113c117c97c108;
function_106:
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
function_107:
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
    target = (&&function_106);
    goto apply_addr;
  }
function_108:
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
    target = (&&function_107);
    goto apply_addr;
  }
function_109:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_108);
  goto apply_addr;
/* __equal */
body_39:
  increment_count(env);
  val = wrap_function((&&function_109), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_40;
pointer global_c95c109c101c109c98c101c114;
function_110:
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
function_111:
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
    target = (&&function_110);
    goto apply_addr;
  }
function_112:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_111);
  goto apply_addr;
/* _member */
body_40:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_41;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_113:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_114:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_113);
  goto apply_addr;
function_115:
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
    target = (&&function_114);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_116:
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
    target = (&&function_115);
    goto apply_addr;
  }
function_117:
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
    target = (&&function_116);
    goto apply_addr;
  }
function_118:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_119:
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
  target = (&&function_118);
  goto apply_addr;
function_120:
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
    target = (&&function_117);
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
    target = (&&function_119);
    goto apply_addr;
  }
function_121:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_120);
  goto apply_addr;
/* ____escape-symbols */
body_41:
  increment_count(env);
  val = wrap_function((&&function_121), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_42;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_42:
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
  goto body_43;
pointer global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101;
/* ____initial-symbol-name */
body_43:
  increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
  global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____initial-symbol-name */
  goto body_44;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_44:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_45;
pointer global_c102c110c95c54; /* fn_6 */
pointer global_c102c110c95c55;
function_122:
  goto top_level_apply;
function_123:
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
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  target = (&&function_122);
  goto apply_addr;
function_124:
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
  target = (&&function_123);
  goto apply_addr;
function_125:
  increment_count(env);
  val = wrap_function((&&function_124), env);
  goto pop_function;
/* fn_7 */
body_45:
global_c102c110c95c54 = NIL; /* fn_6 */
  increment_count(env);
  val = wrap_function((&&function_125), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_46;
pointer global_c102c110c95c53; /* fn_5 */
function_126:
  goto top_level_apply;
function_127:
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
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  target = (&&function_126);
  goto apply_addr;
function_128:
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
  target = (&&function_127);
  goto apply_addr;
function_129:
  increment_count(env);
  val = wrap_function((&&function_128), env);
  goto pop_function;
/* fn_6 */
body_46:
global_c102c110c95c53 = NIL; /* fn_5 */
  increment_count(env);
  val = wrap_function((&&function_129), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_47;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108; /* ____transform-tail-call */
pointer global_c102c110c95c52; /* fn_4 */
function_130:
  goto top_level_apply;
function_131:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  target = (&&function_130);
  goto apply_addr;
function_132:
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
  target = (&&function_131);
  goto apply_addr;
function_133:
  increment_count(env);
  val = wrap_function((&&function_132), env);
  goto pop_function;
/* fn_5 */
body_47:
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = NIL; /* ____transform-tail-call */
global_c102c110c95c52 = NIL; /* fn_4 */
  increment_count(env);
  val = wrap_function((&&function_133), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_48;
function_134:
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
function_135:
  increment_count(env);
  val = wrap_function((&&function_134), env);
  goto pop_function;
/* fn_4 */
body_48:
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_49;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108;
function_136:
  goto top_level_apply;
function_137:
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
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  target = (&&function_136);
  goto apply_addr;
function_138:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_137);
  goto apply_addr;
/* ____transform-fn-tail-call */
body_49:
  increment_count(env);
  val = wrap_function((&&function_138), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-fn-tail-call */
  goto body_50;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_50:
  val = NIL;
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_51;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_51:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_52;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_52:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_53;
pointer global_c102c110c95c49c49; /* fn_11 */
pointer global_c102c110c95c49c50;
function_139:
  goto top_level_apply;
function_140:
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
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  target = (&&function_139);
  goto apply_addr;
function_141:
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
  target = (&&function_140);
  goto apply_addr;
function_142:
  increment_count(env);
  val = wrap_function((&&function_141), env);
  goto pop_function;
/* fn_12 */
body_53:
global_c102c110c95c49c49 = NIL; /* fn_11 */
  increment_count(env);
  val = wrap_function((&&function_142), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_54;
pointer global_c102c110c95c49c48; /* fn_10 */
function_143:
  goto top_level_apply;
function_144:
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
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  target = (&&function_143);
  goto apply_addr;
function_145:
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
  target = (&&function_144);
  goto apply_addr;
function_146:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  goto pop_function;
/* fn_11 */
body_54:
global_c102c110c95c49c48 = NIL; /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_146), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_55;
pointer global_c102c110c95c57; /* fn_9 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109; /* ____transform */
function_147:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_148:
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
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  target = (&&function_147);
  goto apply_addr;
function_149:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  goto pop_function;
/* fn_10 */
body_55:
global_c102c110c95c57 = NIL; /* fn_9 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = NIL; /* ____transform */
  increment_count(env);
  val = wrap_function((&&function_149), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_56;
pointer global_c102c110c95c56; /* fn_8 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115; /* ____transform-args */
function_150:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_151:
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
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  target = (&&function_150);
  goto apply_addr;
function_152:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  goto pop_function;
/* fn_9 */
body_56:
global_c102c110c95c56 = NIL; /* fn_8 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = NIL; /* ____transform-args */
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_57;
function_153:
  push_args();
  increment_count(val = car(car(env)));
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_154:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  goto pop_function;
/* fn_8 */
body_57:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_58;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108;
function_155:
  goto top_level_apply;
function_156:
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
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  target = (&&function_155);
  goto apply_addr;
function_157:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_156);
  goto apply_addr;
/* ____transform-application-tail-call */
body_58:
  increment_count(env);
  val = wrap_function((&&function_157), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-application-tail-call */
  goto body_59;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_59:
  val = NIL;
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_60;
pointer global_c102c110c95c49c51;
function_158:
  push_args();
  val = NIL;
  args = val;
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
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
function_159:
  increment_count(env);
  val = wrap_function((&&function_158), env);
  goto pop_function;
/* fn_13 */
body_60:
  increment_count(env);
  val = wrap_function((&&function_159), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_61;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108;
function_160:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_161:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  target = (&&function_160);
  goto apply_addr;
/* ____transform-primitive-tail-call */
body_61:
  increment_count(env);
  val = wrap_function((&&function_161), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-primitive-tail-call */
  goto body_62;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_62:
  val = NIL;
  push_args();
  args = val;
  val = new_number(50);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_63;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_63:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_64;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_64:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_65;
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c102c110c95c49c57;
function_162:
  goto top_level_apply;
function_163:
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
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  target = (&&function_162);
  goto apply_addr;
function_164:
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
  target = (&&function_163);
  goto apply_addr;
function_165:
  increment_count(env);
  val = wrap_function((&&function_164), env);
  goto pop_function;
/* fn_19 */
body_65:
global_c102c110c95c49c56 = NIL; /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_165), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_66;
pointer global_c102c110c95c49c55; /* fn_17 */
function_166:
  goto top_level_apply;
function_167:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
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
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  target = (&&function_166);
  goto apply_addr;
function_168:
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
  target = (&&function_167);
  goto apply_addr;
function_169:
  increment_count(env);
  val = wrap_function((&&function_168), env);
  goto pop_function;
/* fn_18 */
body_66:
global_c102c110c95c49c55 = NIL; /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_169), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_67;
pointer global_c102c110c95c49c54; /* fn_16 */
function_170:
  goto top_level_apply;
function_171:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  target = (&&function_170);
  goto apply_addr;
function_172:
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
  target = (&&function_171);
  goto apply_addr;
function_173:
  increment_count(env);
  val = wrap_function((&&function_172), env);
  goto pop_function;
/* fn_17 */
body_67:
global_c102c110c95c49c54 = NIL; /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_173), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_68;
pointer global_c102c110c95c49c53; /* fn_15 */
function_174:
  goto top_level_apply;
function_175:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  target = (&&function_174);
  goto apply_addr;
function_176:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108); /* ____transform-tail-call */
  target = (&&function_175);
  goto apply_addr;
function_177:
  increment_count(env);
  val = wrap_function((&&function_176), env);
  goto pop_function;
/* fn_16 */
body_68:
global_c102c110c95c49c53 = NIL; /* fn_15 */
  increment_count(env);
  val = wrap_function((&&function_177), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_69;
pointer global_c102c110c95c49c52; /* fn_14 */
function_178:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_179:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  target = (&&function_178);
  goto apply_addr;
function_180:
  increment_count(env);
  val = wrap_function((&&function_179), env);
  goto pop_function;
/* fn_15 */
body_69:
global_c102c110c95c49c52 = NIL; /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_180), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_70;
function_181:
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
  increment_count(val = car(car(env)));
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
  goto pop_function;
function_182:
  increment_count(env);
  val = wrap_function((&&function_181), env);
  goto pop_function;
/* fn_14 */
body_70:
  increment_count(env);
  val = wrap_function((&&function_182), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_71;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108;
function_183:
  goto top_level_apply;
function_184:
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
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  target = (&&function_183);
  goto apply_addr;
function_185:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_184);
  goto apply_addr;
/* ____transform-if-tail-call */
body_71:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-if-tail-call */
  goto body_72;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_72:
  val = NIL;
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_73;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_73:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_74;
pointer global_c95c110c111c116;
function_186:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
  } else {
    val = -43;
    goto pop_function;
  }
/* _not */
body_74:
  increment_count(env);
  val = wrap_function((&&function_186), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_75;
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c50c49;
function_187:
  goto top_level_apply;
function_188:
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
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  target = (&&function_187);
  goto apply_addr;
function_189:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_188);
  goto apply_addr;
function_190:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c49); /* ___l_21 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_189);
  goto apply_addr;
function_191:
  increment_count(env);
  val = wrap_function((&&function_190), env);
  goto pop_function;
/* fn_21 */
body_75:
global_c102c110c95c50c48 = NIL; /* fn_20 */
  increment_count(env);
  val = wrap_function((&&function_191), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_76;
function_192:
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
function_193:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  goto pop_function;
/* fn_20 */
body_76:
  increment_count(env);
  val = wrap_function((&&function_193), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_77;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108;
function_194:
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
function_195:
  goto top_level_apply;
function_196:
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
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  target = (&&function_195);
  goto apply_addr;
function_197:
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
    target = (&&function_194);
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
    target = (&&function_196);
    goto apply_addr;
  }
function_198:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_197);
  goto apply_addr;
function_199:
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
      target = (&&function_198);
      goto apply_addr;
    }
  }
function_200:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_199);
  goto apply_addr;
/* ____transform-atom-tail-call */
body_77:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-atom-tail-call */
  goto body_78;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_78:
  val = -37;
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_79;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_79:
  val = -38;
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_80;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_80:
  val = -42;
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_81;
pointer global_c95c99c97c100c114;
function_201:
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
/* _cadr */
body_81:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_82;
pointer global_c95c99c100c100c114;
function_202:
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
/* _cddr */
body_82:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  global_c95c99c100c100c114 = val; /* _cddr */
  goto body_83;
pointer global_c95c99c97c100c100c114;
function_203:
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
/* _caddr */
body_83:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_84;
function_204:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108); /* ____transform-fn-tail-call */
  goto top_level_apply;
function_205:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_204);
  goto apply_addr;
function_206:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108); /* ____transform-if-tail-call */
  goto top_level_apply;
function_207:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_206);
  goto apply_addr;
function_208:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  target = (&&function_207);
  goto apply_addr;
function_209:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_208);
  goto apply_addr;
function_210:
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108); /* ____transform-primitive-tail-call */
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108); /* ____transform-application-tail-call */
    goto top_level_apply;
  }
function_211:
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
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115); /* ____builtins */
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
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_210);
    goto apply_addr;
  }
function_212:
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
    target = (&&function_209);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
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
    target = (&&function_211);
    goto apply_addr;
  }
function_213:
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
    target = (&&function_205);
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
    target = (&&function_212);
    goto apply_addr;
  }
function_214:
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
    target = (&&function_213);
    goto apply_addr;
  }
function_215:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_214);
  goto apply_addr;
/* ____transform-tail-call */
body_84:
  increment_count(env);
  val = wrap_function((&&function_215), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-tail-call */
  goto body_85;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_85:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_86;
pointer global_c102c110c95c50c52; /* fn_24 */
pointer global_c102c110c95c50c53;
function_216:
  goto top_level_apply;
function_217:
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
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  target = (&&function_216);
  goto apply_addr;
function_218:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_217);
  goto apply_addr;
function_219:
  increment_count(env);
  val = wrap_function((&&function_218), env);
  goto pop_function;
/* fn_25 */
body_86:
global_c102c110c95c50c52 = NIL; /* fn_24 */
  increment_count(env);
  val = wrap_function((&&function_219), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_87;
pointer global_c102c110c95c50c51; /* fn_23 */
function_220:
  goto top_level_apply;
function_221:
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
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  target = (&&function_220);
  goto apply_addr;
function_222:
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
  target = (&&function_221);
  goto apply_addr;
function_223:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  goto pop_function;
/* fn_24 */
body_87:
global_c102c110c95c50c51 = NIL; /* fn_23 */
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_88;
pointer global_c102c110c95c50c50; /* fn_22 */
function_224:
  goto top_level_apply;
function_225:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  target = (&&function_224);
  goto apply_addr;
function_226:
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
  target = (&&function_225);
  goto apply_addr;
function_227:
  increment_count(env);
  val = wrap_function((&&function_226), env);
  goto pop_function;
/* fn_23 */
body_88:
global_c102c110c95c50c50 = NIL; /* fn_22 */
  increment_count(env);
  val = wrap_function((&&function_227), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_89;
function_228:
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
function_229:
  increment_count(env);
  val = wrap_function((&&function_228), env);
  goto pop_function;
/* fn_22 */
body_89:
  increment_count(env);
  val = wrap_function((&&function_229), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_90;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110;
function_230:
  goto top_level_apply;
function_231:
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
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  target = (&&function_230);
  goto apply_addr;
function_232:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_231);
  goto apply_addr;
/* ____transform-fn */
body_90:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 = val; /* ____transform-fn */
  goto body_91;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_91:
  val = NIL;
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_92;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_92:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_93;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_93:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_94;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_94:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_95;
pointer global_c95c114c101c118c101c114c115c101;
function_233:
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
/* _reverse */
body_95:
  increment_count(env);
  val = wrap_function((&&function_233), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_96;
pointer global_c102c110c95c50c55; /* fn_27 */
pointer global_c102c110c95c50c56;
function_234:
  goto top_level_apply;
function_235:
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
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  target = (&&function_234);
  goto apply_addr;
function_236:
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
  target = (&&function_235);
  goto apply_addr;
function_237:
  increment_count(env);
  val = wrap_function((&&function_236), env);
  goto pop_function;
/* fn_28 */
body_96:
global_c102c110c95c50c55 = NIL; /* fn_27 */
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_97;
pointer global_c102c110c95c50c54; /* fn_26 */
function_238:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_239:
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
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  target = (&&function_238);
  goto apply_addr;
function_240:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  goto pop_function;
/* fn_27 */
body_97:
global_c102c110c95c50c54 = NIL; /* fn_26 */
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_98;
function_241:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_242:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_241);
  goto apply_addr;
function_243:
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
  target = (&&function_242);
  goto apply_addr;
function_244:
  increment_count(env);
  val = wrap_function((&&function_243), env);
  goto pop_function;
/* fn_26 */
body_98:
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_99;
pointer global_c102c110c95c51c49; /* fn_31 */
pointer global_c102c110c95c51c50;
function_245:
  goto top_level_apply;
function_246:
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
  increment_count(val = global_c102c110c95c51c49); /* fn_31 */
  target = (&&function_245);
  goto apply_addr;
function_247:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_246);
  goto apply_addr;
function_248:
  increment_count(env);
  val = wrap_function((&&function_247), env);
  goto pop_function;
/* fn_32 */
body_99:
global_c102c110c95c51c49 = NIL; /* fn_31 */
  increment_count(env);
  val = wrap_function((&&function_248), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_100;
pointer global_c102c110c95c51c48; /* fn_30 */
function_249:
  goto top_level_apply;
function_250:
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
  increment_count(val = global_c102c110c95c51c48); /* fn_30 */
  target = (&&function_249);
  goto apply_addr;
function_251:
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
  target = (&&function_250);
  goto apply_addr;
function_252:
  increment_count(env);
  val = wrap_function((&&function_251), env);
  goto pop_function;
/* fn_31 */
body_100:
global_c102c110c95c51c48 = NIL; /* fn_30 */
  increment_count(env);
  val = wrap_function((&&function_252), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_101;
pointer global_c102c110c95c50c57; /* fn_29 */
function_253:
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
function_254:
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
  increment_count(val = global_c102c110c95c50c57); /* fn_29 */
  target = (&&function_253);
  goto apply_addr;
function_255:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  goto pop_function;
/* fn_30 */
body_101:
global_c102c110c95c50c57 = NIL; /* fn_29 */
  increment_count(env);
  val = wrap_function((&&function_255), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_102;
function_256:
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
function_257:
  increment_count(env);
  val = wrap_function((&&function_256), env);
  goto pop_function;
/* fn_29 */
body_102:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_103;
function_258:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_259:
  goto top_level_apply;
function_260:
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
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  target = (&&function_259);
  goto apply_addr;
function_261:
  goto top_level_apply;
function_262:
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
  increment_count(val = global_c102c110c95c51c50); /* fn_32 */
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
    target = (&&function_260);
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
    target = (&&function_262);
    goto apply_addr;
  }
function_264:
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
    target = (&&function_258);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_263);
    goto apply_addr;
  }
function_265:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_264);
  goto apply_addr;
/* ____transform-args */
body_103:
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = val; /* ____transform-args */
  goto body_104;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_104:
  val = NIL;
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_105;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_105:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_106;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_106:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_107;
pointer global_c102c110c95c51c54; /* fn_36 */
pointer global_c102c110c95c51c55;
function_266:
  goto top_level_apply;
function_267:
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
  increment_count(val = global_c102c110c95c51c54); /* fn_36 */
  target = (&&function_266);
  goto apply_addr;
function_268:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_267);
  goto apply_addr;
function_269:
  increment_count(env);
  val = wrap_function((&&function_268), env);
  goto pop_function;
/* fn_37 */
body_107:
global_c102c110c95c51c54 = NIL; /* fn_36 */
  increment_count(env);
  val = wrap_function((&&function_269), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_108;
pointer global_c102c110c95c51c53; /* fn_35 */
function_270:
  goto top_level_apply;
function_271:
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
  increment_count(val = global_c102c110c95c51c53); /* fn_35 */
  target = (&&function_270);
  goto apply_addr;
function_272:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_271);
  goto apply_addr;
function_273:
  increment_count(env);
  val = wrap_function((&&function_272), env);
  goto pop_function;
/* fn_36 */
body_108:
global_c102c110c95c51c53 = NIL; /* fn_35 */
  increment_count(env);
  val = wrap_function((&&function_273), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_109;
pointer global_c102c110c95c51c52; /* fn_34 */
function_274:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_275:
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
  increment_count(val = global_c102c110c95c51c52); /* fn_34 */
  target = (&&function_274);
  goto apply_addr;
function_276:
  increment_count(env);
  val = wrap_function((&&function_275), env);
  goto pop_function;
/* fn_35 */
body_109:
global_c102c110c95c51c52 = NIL; /* fn_34 */
  increment_count(env);
  val = wrap_function((&&function_276), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_110;
pointer global_c102c110c95c51c51; /* fn_33 */
function_277:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_278:
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
  increment_count(val = global_c102c110c95c51c51); /* fn_33 */
  target = (&&function_277);
  goto apply_addr;
function_279:
  increment_count(env);
  val = wrap_function((&&function_278), env);
  goto pop_function;
/* fn_34 */
body_110:
global_c102c110c95c51c51 = NIL; /* fn_33 */
  increment_count(env);
  val = wrap_function((&&function_279), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_111;
function_280:
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
function_281:
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
  target = (&&function_280);
  goto apply_addr;
function_282:
  increment_count(env);
  val = wrap_function((&&function_281), env);
  goto pop_function;
/* fn_33 */
body_111:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_112;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110;
function_283:
  goto top_level_apply;
function_284:
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
  increment_count(val = global_c102c110c95c51c55); /* fn_37 */
  target = (&&function_283);
  goto apply_addr;
function_285:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_284);
  goto apply_addr;
/* ____transform-application */
body_112:
  increment_count(env);
  val = wrap_function((&&function_285), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110 = val; /* ____transform-application */
  goto body_113;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_113:
  val = NIL;
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_114;
pointer global_c102c110c95c51c56;
function_286:
  push_args();
  val = NIL;
  args = val;
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
function_287:
  increment_count(env);
  val = wrap_function((&&function_286), env);
  goto pop_function;
/* fn_38 */
body_114:
  increment_count(env);
  val = wrap_function((&&function_287), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_115;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101;
function_288:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115); /* ____transform-args */
  goto top_level_apply;
function_289:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c56); /* fn_38 */
  target = (&&function_288);
  goto apply_addr;
/* ____transform-primitive */
body_115:
  increment_count(env);
  val = wrap_function((&&function_289), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101 = val; /* ____transform-primitive */
  goto body_116;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_116:
  val = NIL;
  push_args();
  args = val;
  val = new_number(50);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_117;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_117:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_118;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_118:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_119;
pointer global_c102c110c95c52c51; /* fn_43 */
pointer global_c102c110c95c52c52;
function_290:
  goto top_level_apply;
function_291:
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
  increment_count(val = global_c102c110c95c52c51); /* fn_43 */
  target = (&&function_290);
  goto apply_addr;
function_292:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c53); /* ___l_35 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_291);
  goto apply_addr;
function_293:
  increment_count(env);
  val = wrap_function((&&function_292), env);
  goto pop_function;
/* fn_44 */
body_119:
global_c102c110c95c52c51 = NIL; /* fn_43 */
  increment_count(env);
  val = wrap_function((&&function_293), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_120;
pointer global_c102c110c95c52c50; /* fn_42 */
function_294:
  goto top_level_apply;
function_295:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
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
  increment_count(val = global_c102c110c95c52c50); /* fn_42 */
  target = (&&function_294);
  goto apply_addr;
function_296:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52); /* ___l_34 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_295);
  goto apply_addr;
function_297:
  increment_count(env);
  val = wrap_function((&&function_296), env);
  goto pop_function;
/* fn_43 */
body_120:
global_c102c110c95c52c50 = NIL; /* fn_42 */
  increment_count(env);
  val = wrap_function((&&function_297), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_121;
pointer global_c102c110c95c52c49; /* fn_41 */
function_298:
  goto top_level_apply;
function_299:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c49); /* fn_41 */
  target = (&&function_298);
  goto apply_addr;
function_300:
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
  target = (&&function_299);
  goto apply_addr;
function_301:
  increment_count(env);
  val = wrap_function((&&function_300), env);
  goto pop_function;
/* fn_42 */
body_121:
global_c102c110c95c52c49 = NIL; /* fn_41 */
  increment_count(env);
  val = wrap_function((&&function_301), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_122;
pointer global_c102c110c95c52c48; /* fn_40 */
function_302:
  goto top_level_apply;
function_303:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c48); /* fn_40 */
  target = (&&function_302);
  goto apply_addr;
function_304:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  target = (&&function_303);
  goto apply_addr;
function_305:
  increment_count(env);
  val = wrap_function((&&function_304), env);
  goto pop_function;
/* fn_41 */
body_122:
global_c102c110c95c52c48 = NIL; /* fn_40 */
  increment_count(env);
  val = wrap_function((&&function_305), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_123;
pointer global_c102c110c95c51c57; /* fn_39 */
function_306:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
function_307:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57); /* fn_39 */
  target = (&&function_306);
  goto apply_addr;
function_308:
  increment_count(env);
  val = wrap_function((&&function_307), env);
  goto pop_function;
/* fn_40 */
body_123:
global_c102c110c95c51c57 = NIL; /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_308), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_124;
function_309:
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
  increment_count(val = car(car(env)));
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
  goto pop_function;
function_310:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  goto pop_function;
/* fn_39 */
body_124:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_125;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102;
function_311:
  goto top_level_apply;
function_312:
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
  increment_count(val = global_c102c110c95c52c52); /* fn_44 */
  target = (&&function_311);
  goto apply_addr;
function_313:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c54); /* ___l_36 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_312);
  goto apply_addr;
/* ____transform-if */
body_125:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 = val; /* ____transform-if */
  goto body_126;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_126:
  val = NIL;
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_127;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_127:
  val = NIL;
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_128;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_128:
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_129;
pointer global_c102c110c95c52c55; /* fn_47 */
pointer global_c102c110c95c52c56;
function_314:
  goto top_level_apply;
function_315:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55); /* fn_47 */
  target = (&&function_314);
  goto apply_addr;
function_316:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c56); /* ___l_38 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_315);
  goto apply_addr;
function_317:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  goto pop_function;
/* fn_48 */
body_129:
global_c102c110c95c52c55 = NIL; /* fn_47 */
  increment_count(env);
  val = wrap_function((&&function_317), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_130;
pointer global_c102c110c95c52c54; /* fn_46 */
function_318:
  goto top_level_apply;
function_319:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c54); /* fn_46 */
  target = (&&function_318);
  goto apply_addr;
function_320:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_319);
  goto apply_addr;
function_321:
  increment_count(env);
  val = wrap_function((&&function_320), env);
  goto pop_function;
/* fn_47 */
body_130:
global_c102c110c95c52c54 = NIL; /* fn_46 */
  increment_count(env);
  val = wrap_function((&&function_321), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_131;
pointer global_c102c110c95c52c53; /* fn_45 */
function_322:
  goto top_level_apply;
function_323:
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
  increment_count(val = global_c102c110c95c52c53); /* fn_45 */
  target = (&&function_322);
  goto apply_addr;
function_324:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_323);
  goto apply_addr;
function_325:
  increment_count(env);
  val = wrap_function((&&function_324), env);
  goto pop_function;
/* fn_46 */
body_131:
global_c102c110c95c52c53 = NIL; /* fn_45 */
  increment_count(env);
  val = wrap_function((&&function_325), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_132;
function_326:
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
function_327:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  goto pop_function;
/* fn_45 */
body_132:
  increment_count(env);
  val = wrap_function((&&function_327), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_133;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109;
function_328:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  goto top_level_apply;
function_329:
  goto top_level_apply;
function_330:
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
  increment_count(val = global_c102c110c95c52c56); /* fn_48 */
  target = (&&function_329);
  goto apply_addr;
function_331:
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
    target = (&&function_328);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c57); /* ___l_39 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    target = (&&function_330);
    goto apply_addr;
  }
function_332:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_331);
  goto apply_addr;
function_333:
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
      target = (&&function_332);
      goto apply_addr;
    }
  }
function_334:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c55); /* ___l_37 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_333);
  goto apply_addr;
/* ____transform-atom */
body_133:
  increment_count(env);
  val = wrap_function((&&function_334), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109 = val; /* ____transform-atom */
  goto body_134;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_134:
  val = -37;
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_135;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_135:
  val = -38;
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_136;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_136:
  val = -42;
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_137;
pointer global_c95c99c97c100c100c100c114;
function_335:
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
/* _cadddr */
body_137:
  increment_count(env);
  val = wrap_function((&&function_335), env);
  global_c95c99c97c100c100c100c114 = val; /* _cadddr */
  goto body_138;
function_336:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110); /* ____transform-fn */
  goto top_level_apply;
function_337:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_336);
  goto apply_addr;
function_338:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102); /* ____transform-if */
  goto top_level_apply;
function_339:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114); /* _cadr */
  target = (&&function_338);
  goto apply_addr;
function_340:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114); /* _caddr */
  target = (&&function_339);
  goto apply_addr;
function_341:
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
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101); /* ____transform-primitive */
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
function_342:
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
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115); /* ____builtins */
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
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_341);
    goto apply_addr;
  }
function_343:
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
    target = (&&function_340);
    goto apply_addr;
  } else {
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
    target = (&&function_342);
    goto apply_addr;
  }
function_344:
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
    target = (&&function_337);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c49); /* ___l_41 */
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
    target = (&&function_343);
    goto apply_addr;
  }
function_345:
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
    target = (&&function_344);
    goto apply_addr;
  }
function_346:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_345);
  goto apply_addr;
/* ____transform */
body_138:
  increment_count(env);
  val = wrap_function((&&function_346), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = val; /* ____transform */
  goto body_139;
pointer global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110;
function_347:
  increment_count(val = car(car(env)));
  goto pop_function;
function_348:
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = wrap_function((&&function_347), env);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101); /* ____initial-symbol-name */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109); /* ____transform */
  goto top_level_apply;
/* ____cps-transformation */
body_139:
  increment_count(env);
  val = wrap_function((&&function_348), env);
  global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 = val; /* ____cps-transformation */
  goto body_140;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_140:
  val = -39;
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_141;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116;
function_349:
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
function_350:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_349);
  goto apply_addr;
function_351:
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
  target = (&&function_350);
  goto apply_addr;
function_352:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110); /* ____cps-transformation */
  target = (&&function_351);
  goto apply_addr;
function_353:
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
function_354:
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
    target = (&&function_352);
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
    target = (&&function_353);
    goto apply_addr;
  }
function_355:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c51); /* ___l_43 */
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
  target = (&&function_354);
  goto apply_addr;
/* ____transform-statement */
body_141:
  increment_count(env);
  val = wrap_function((&&function_355), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 = val; /* ____transform-statement */
  goto body_142;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_142:
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
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_143;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_143:
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
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_144;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_144:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_145;
pointer global_c95c97c112c112c108c121;
function_356:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* _apply */
body_145:
  increment_count(env);
  val = wrap_function((&&function_356), env);
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_146;
pointer global_c95c97c110c100;
function_357:
  goto top_level_apply;
function_358:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_359:
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
  increment_count(env);
  val = wrap_function((&&function_358), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_357);
  goto apply_addr;
/* _and */
body_146:
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_147;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_360:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_361:
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
    target = (&&function_360);
    goto apply_addr;
  }
function_362:
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
    target = (&&function_361);
    goto apply_addr;
  }
function_363:
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_362);
  goto apply_addr;
/* _escape-char */
body_147:
  increment_count(env);
  val = wrap_function((&&function_363), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_148;
pointer global_c95c98c117c105c108c100c45c110c117c109;
function_364:
  goto top_level_apply;
function_365:
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
function_366:
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
  val = wrap_function((&&function_365), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_364);
  goto apply_addr;
/* _build-num */
body_148:
  increment_count(env);
  val = wrap_function((&&function_366), env);
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  goto body_149;
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
function_367:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -42;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _quote-value */
body_149:
  increment_count(env);
  val = wrap_function((&&function_367), env);
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  goto body_150;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
function_368:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -41;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _quasiquote-value */
body_150:
  increment_count(env);
  val = wrap_function((&&function_368), env);
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  goto body_151;
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
function_369:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -40;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _unquote-value */
body_151:
  increment_count(env);
  val = wrap_function((&&function_369), env);
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  goto body_152;
pointer global_c102c110c95c52c57;
function_370:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  goto top_level_apply;
function_371:
  increment_count(env);
  val = wrap_function((&&function_370), env);
  goto pop_function;
/* fn_49 */
body_152:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_153;
pointer global_c95c102c97c105c108;
function_372:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c57); /* fn_49 */
  goto top_level_apply;
/* _fail */
body_153:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  global_c95c102c97c105c108 = val; /* _fail */
  goto body_154;
pointer global_c95c100c111c110c101;
function_373:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* _done */
body_154:
  increment_count(env);
  val = wrap_function((&&function_373), env);
  global_c95c100c111c110c101 = val; /* _done */
  goto body_155;
pointer global_c95c112c111c112; /* _pop */
pointer global_c102c110c95c53c48;
function_374:
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
function_375:
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
      target = (&&function_374);
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
function_376:
  increment_count(env);
  val = wrap_function((&&function_375), env);
  goto pop_function;
/* fn_50 */
body_155:
global_c95c112c111c112 = NIL; /* _pop */
  increment_count(env);
  val = wrap_function((&&function_376), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_156;
function_377:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c48); /* fn_50 */
  goto top_level_apply;
/* _pop */
body_156:
  increment_count(env);
  val = wrap_function((&&function_377), env);
  global_c95c112c111c112 = val; /* _pop */
  goto body_157;
pointer global_c102c110c95c53c49; /* fn_51 */
pointer global_c102c110c95c53c50;
function_378:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  goto top_level_apply;
function_379:
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
  increment_count(val = global_c102c110c95c53c49); /* fn_51 */
  target = (&&function_378);
  goto apply_addr;
function_380:
  increment_count(env);
  val = wrap_function((&&function_379), env);
  goto pop_function;
/* fn_52 */
body_157:
global_c102c110c95c53c49 = NIL; /* fn_51 */
  increment_count(env);
  val = wrap_function((&&function_380), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_158;
function_381:
  goto top_level_apply;
function_382:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_381);
  goto apply_addr;
function_383:
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
  target = (&&function_382);
  goto apply_addr;
function_384:
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
    target = (&&function_383);
    goto apply_addr;
  }
function_385:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_384);
  goto apply_addr;
function_386:
  increment_count(env);
  val = wrap_function((&&function_385), env);
  goto pop_function;
/* fn_51 */
body_158:
  increment_count(env);
  val = wrap_function((&&function_386), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_159;
pointer global_c95c99c104c101c99c107;
function_387:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c50); /* fn_52 */
  goto top_level_apply;
/* _check */
body_159:
  increment_count(env);
  val = wrap_function((&&function_387), env);
  global_c95c99c104c101c99c107 = val; /* _check */
  goto body_160;
pointer global_c102c110c95c53c51;
function_388:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_389:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  goto pop_function;
/* fn_53 */
body_160:
  increment_count(env);
  val = wrap_function((&&function_389), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_161;
pointer global_c95c109c97c116c99c104;
function_390:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_391:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c51); /* fn_53 */
  target = (&&function_390);
  goto apply_addr;
/* _match */
body_161:
  increment_count(env);
  val = wrap_function((&&function_391), env);
  global_c95c109c97c116c99c104 = val; /* _match */
  goto body_162;
pointer global_c102c110c95c53c52;
function_392:
  increment_count(val = car(car(cdr(env))));
  goto pop_function;
function_393:
  increment_count(env);
  val = wrap_function((&&function_392), env);
  goto pop_function;
/* fn_54 */
body_162:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_163;
pointer global_c95c100c101c102c97c117c108c116;
function_394:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c52); /* fn_54 */
  goto top_level_apply;
/* _default */
body_163:
  increment_count(env);
  val = wrap_function((&&function_394), env);
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  goto body_164;
pointer global_c102c110c95c53c55; /* fn_57 */
pointer global_c102c110c95c53c56;
function_395:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c55); /* fn_57 */
  goto top_level_apply;
function_396:
  increment_count(env);
  val = wrap_function((&&function_395), env);
  goto pop_function;
/* fn_58 */
body_164:
global_c102c110c95c53c55 = NIL; /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_396), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_165;
pointer global_c102c110c95c53c54; /* fn_56 */
pointer global_c102c110c95c53c53; /* fn_55 */
function_397:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_398:
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
  increment_count(val = global_c102c110c95c53c53); /* fn_55 */
  target = (&&function_397);
  goto apply_addr;
function_399:
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
  increment_count(val = global_c102c110c95c53c54); /* fn_56 */
  target = (&&function_398);
  goto apply_addr;
function_400:
  increment_count(env);
  val = wrap_function((&&function_399), env);
  goto pop_function;
/* fn_57 */
body_165:
global_c102c110c95c53c54 = NIL; /* fn_56 */
global_c102c110c95c53c53 = NIL; /* fn_55 */
  increment_count(env);
  val = wrap_function((&&function_400), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_166;
function_401:
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
function_402:
  increment_count(env);
  val = wrap_function((&&function_401), env);
  goto pop_function;
/* fn_55 */
body_166:
  increment_count(env);
  val = wrap_function((&&function_402), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_167;
function_403:
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
function_404:
  increment_count(env);
  val = wrap_function((&&function_403), env);
  goto pop_function;
/* fn_56 */
body_167:
  increment_count(env);
  val = wrap_function((&&function_404), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_168;
pointer global_c95c99c97c115c101;
function_405:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c56); /* fn_58 */
  goto top_level_apply;
/* _case */
body_168:
  increment_count(env);
  val = wrap_function((&&function_405), env);
  global_c95c99c97c115c101 = val; /* _case */
  goto body_169;
pointer global_c95c99c104c111c105c99c101;
function_406:
  goto top_level_apply;
function_407:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_408:
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_407), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_406);
  goto apply_addr;
function_409:
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
  target = (&&function_408);
  goto apply_addr;
/* _choice */
body_169:
  increment_count(env);
  val = wrap_function((&&function_409), env);
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  goto body_170;
pointer global_c102c110c95c53c57; /* fn_59 */
pointer global_c102c110c95c54c48;
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
  increment_count(val = global_c102c110c95c53c57); /* fn_59 */
  target = (&&function_410);
  goto apply_addr;
function_412:
  increment_count(env);
  val = wrap_function((&&function_411), env);
  goto pop_function;
/* fn_60 */
body_170:
global_c102c110c95c53c57 = NIL; /* fn_59 */
  increment_count(env);
  val = wrap_function((&&function_412), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_171;
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
/* fn_59 */
body_171:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_172;
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
function_416:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c48); /* fn_60 */
  goto top_level_apply;
/* _post-process */
body_172:
  increment_count(env);
  val = wrap_function((&&function_416), env);
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  goto body_173;
pointer global_c102c110c95c54c50; /* fn_62 */
pointer global_c102c110c95c54c51;
function_417:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_418:
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
  increment_count(val = global_c102c110c95c54c50); /* fn_62 */
  target = (&&function_417);
  goto apply_addr;
function_419:
  increment_count(env);
  val = wrap_function((&&function_418), env);
  goto pop_function;
/* fn_63 */
body_173:
global_c102c110c95c54c50 = NIL; /* fn_62 */
  increment_count(env);
  val = wrap_function((&&function_419), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_174;
pointer global_c102c110c95c54c49; /* fn_61 */
function_420:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_421:
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
  increment_count(val = global_c102c110c95c54c49); /* fn_61 */
  target = (&&function_420);
  goto apply_addr;
function_422:
  increment_count(env);
  val = wrap_function((&&function_421), env);
  goto pop_function;
/* fn_62 */
body_174:
global_c102c110c95c54c49 = NIL; /* fn_61 */
  increment_count(env);
  val = wrap_function((&&function_422), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_175;
function_423:
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
function_424:
  increment_count(env);
  val = wrap_function((&&function_423), env);
  goto pop_function;
/* fn_61 */
body_175:
  increment_count(env);
  val = wrap_function((&&function_424), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  goto body_176;
pointer global_c95c115c101c113;
function_425:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c51); /* fn_63 */
  goto top_level_apply;
/* _seq */
body_176:
  increment_count(env);
  val = wrap_function((&&function_425), env);
  global_c95c115c101c113 = val; /* _seq */
  goto body_177;
pointer global_c95c101c115c99c97c112c101;
function_426:
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_427:
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
  target = (&&function_426);
  goto apply_addr;
/* _escape */
body_177:
  increment_count(env);
  val = wrap_function((&&function_427), env);
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  goto body_178;
pointer global_c95c117c115c101;
function_428:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
/* _use */
body_178:
  increment_count(env);
  val = wrap_function((&&function_428), env);
  global_c95c117c115c101 = val; /* _use */
  goto body_179;
pointer global_c102c110c95c54c52; /* fn_64 */
pointer global_c102c110c95c54c53;
function_429:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_430:
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
  increment_count(val = global_c102c110c95c54c52); /* fn_64 */
  target = (&&function_429);
  goto apply_addr;
function_431:
  increment_count(env);
  val = wrap_function((&&function_430), env);
  goto pop_function;
/* fn_65 */
body_179:
global_c102c110c95c54c52 = NIL; /* fn_64 */
  increment_count(env);
  val = wrap_function((&&function_431), env);
  global_c102c110c95c54c53 = val; /* fn_65 */
  goto body_180;
function_432:
  goto top_level_apply;
function_433:
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
  target = (&&function_432);
  goto apply_addr;
function_434:
  increment_count(env);
  val = wrap_function((&&function_433), env);
  goto pop_function;
/* fn_64 */
body_180:
  increment_count(env);
  val = wrap_function((&&function_434), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  goto body_181;
pointer global_c95c112c101c101c107;
function_435:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c53); /* fn_65 */
  goto top_level_apply;
/* _peek */
body_181:
  increment_count(env);
  val = wrap_function((&&function_435), env);
  global_c95c112c101c101c107 = val; /* _peek */
  goto body_182;
pointer global_c102c110c95c54c54;
function_436:
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
function_437:
  increment_count(env);
  val = wrap_function((&&function_436), env);
  goto pop_function;
/* fn_66 */
body_182:
  increment_count(env);
  val = wrap_function((&&function_437), env);
  global_c102c110c95c54c54 = val; /* fn_66 */
  goto body_183;
pointer global_c95c105c110c116c101c114c118c97c108;
function_438:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_439:
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
  increment_count(val = global_c102c110c95c54c54); /* fn_66 */
  target = (&&function_438);
  goto apply_addr;
/* _interval */
body_183:
  increment_count(env);
  val = wrap_function((&&function_439), env);
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  goto body_184;
pointer global_c95c115c107c105c112;
function_440:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_441:
  push_args();
  increment_count(val = car(env));
  args = val;
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_442:
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = wrap_function((&&function_441), env);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c117c115c101); /* _use */
  target = (&&function_440);
  goto apply_addr;
/* _skip */
body_184:
  increment_count(env);
  val = wrap_function((&&function_442), env);
  global_c95c115c107c105c112 = val; /* _skip */
  goto body_185;
pointer global_c95c102c105c114c115c116;
function_443:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_444:
  push_args();
  increment_count(val = car(env));
  args = val;
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_445:
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = wrap_function((&&function_444), env);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  target = (&&function_443);
  goto apply_addr;
/* _first */
body_185:
  increment_count(env);
  val = wrap_function((&&function_445), env);
  global_c95c102c105c114c115c116 = val; /* _first */
  goto body_186;
pointer global_c95c112c97c114c115c101c45c110c117c109;
function_446:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_447:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_446);
  goto apply_addr;
function_448:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_447);
  goto apply_addr;
function_449:
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
  target = (&&function_448);
  goto apply_addr;
function_450:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_449);
  goto apply_addr;
function_451:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_450);
  goto apply_addr;
function_452:
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
  target = (&&function_451);
  goto apply_addr;
function_453:
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
  target = (&&function_452);
  goto apply_addr;
function_454:
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
  target = (&&function_453);
  goto apply_addr;
/* _parse-num */
body_186:
  increment_count(env);
  val = wrap_function((&&function_454), env);
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  goto body_187;
pointer global_c95c114c101c97c100c45c110c117c109;
function_455:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_456:
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
  target = (&&function_455);
  goto apply_addr;
/* _read-num */
body_187:
  increment_count(env);
  val = wrap_function((&&function_456), env);
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  goto body_188;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108;
function_457:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_458:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_457);
  goto apply_addr;
function_459:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_458);
  goto apply_addr;
function_460:
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
  target = (&&function_459);
  goto apply_addr;
function_461:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_460);
  goto apply_addr;
function_462:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_461);
  goto apply_addr;
function_463:
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
  target = (&&function_462);
  goto apply_addr;
function_464:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_463);
  goto apply_addr;
function_465:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_464);
  goto apply_addr;
function_466:
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
  target = (&&function_465);
  goto apply_addr;
function_467:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_466);
  goto apply_addr;
function_468:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_467);
  goto apply_addr;
function_469:
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
  target = (&&function_468);
  goto apply_addr;
function_470:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_469);
  goto apply_addr;
function_471:
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
  target = (&&function_470);
  goto apply_addr;
/* _parse-symbol */
body_188:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_189;
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
function_472:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_473:
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
  target = (&&function_472);
  goto apply_addr;
/* _read-symbol */
body_189:
  increment_count(env);
  val = wrap_function((&&function_473), env);
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  goto body_190;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103;
function_474:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_475:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_474);
  goto apply_addr;
function_476:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_475);
  goto apply_addr;
function_477:
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
  target = (&&function_476);
  goto apply_addr;
function_478:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_477);
  goto apply_addr;
function_479:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_478);
  goto apply_addr;
function_480:
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
  target = (&&function_479);
  goto apply_addr;
function_481:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_480);
  goto apply_addr;
function_482:
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
  target = (&&function_481);
  goto apply_addr;
/* _parse-string */
body_190:
  increment_count(env);
  val = wrap_function((&&function_482), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_191;
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
function_483:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c111c116c101c45c118c97c108c117c101); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
/* _quote-parser */
body_191:
  increment_count(env);
  val = wrap_function((&&function_483), env);
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  goto body_192;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
function_484:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
/* _quasiquote-parser */
body_192:
  increment_count(env);
  val = wrap_function((&&function_484), env);
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  goto body_193;
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
function_485:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
/* _unquote-parser */
body_193:
  increment_count(env);
  val = wrap_function((&&function_485), env);
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  goto body_194;
pointer global_c95c99c111c109c109c101c110c116; /* _comment */
pointer global_c102c110c95c54c55;
function_486:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_487:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_486);
  goto apply_addr;
function_488:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_487);
  goto apply_addr;
function_489:
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
  target = (&&function_488);
  goto apply_addr;
function_490:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_489);
  goto apply_addr;
function_491:
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
  target = (&&function_490);
  goto apply_addr;
function_492:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_491);
  goto apply_addr;
function_493:
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  target = (&&function_492);
  goto apply_addr;
function_494:
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
  target = (&&function_493);
  goto apply_addr;
function_495:
  increment_count(env);
  val = wrap_function((&&function_494), env);
  goto pop_function;
/* fn_67 */
body_194:
global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
  increment_count(env);
  val = wrap_function((&&function_495), env);
  global_c102c110c95c54c55 = val; /* fn_67 */
  goto body_195;
function_496:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c55); /* fn_67 */
  goto top_level_apply;
/* _comment */
body_195:
  increment_count(env);
  val = wrap_function((&&function_496), env);
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  goto body_196;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110;
function_497:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_498:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_497);
  goto apply_addr;
function_499:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_498);
  goto apply_addr;
function_500:
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
  target = (&&function_499);
  goto apply_addr;
function_501:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_500);
  goto apply_addr;
function_502:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_501);
  goto apply_addr;
function_503:
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
  target = (&&function_502);
  goto apply_addr;
function_504:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_503);
  goto apply_addr;
function_505:
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
  target = (&&function_504);
  goto apply_addr;
function_506:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_505);
  goto apply_addr;
function_507:
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
  target = (&&function_506);
  goto apply_addr;
/* _parse-paren */
body_196:
  increment_count(env);
  val = wrap_function((&&function_507), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_197;
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114;
function_508:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_509:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_508);
  goto apply_addr;
function_510:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_509);
  goto apply_addr;
function_511:
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
  target = (&&function_510);
  goto apply_addr;
function_512:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_511);
  goto apply_addr;
function_513:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_512);
  goto apply_addr;
function_514:
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
  target = (&&function_513);
  goto apply_addr;
function_515:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_514);
  goto apply_addr;
function_516:
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
  target = (&&function_515);
  goto apply_addr;
function_517:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_516);
  goto apply_addr;
function_518:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_517);
  goto apply_addr;
function_519:
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
  target = (&&function_518);
  goto apply_addr;
function_520:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_519);
  goto apply_addr;
function_521:
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
  target = (&&function_520);
  goto apply_addr;
/* _parse-pair */
body_197:
global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_521), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_198;
function_522:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_523:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_522);
  goto apply_addr;
function_524:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_523);
  goto apply_addr;
function_525:
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
  target = (&&function_524);
  goto apply_addr;
function_526:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_525);
  goto apply_addr;
function_527:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_526);
  goto apply_addr;
function_528:
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
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_529);
  goto apply_addr;
function_531:
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
  target = (&&function_530);
  goto apply_addr;
function_532:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_531);
  goto apply_addr;
function_533:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_532);
  goto apply_addr;
function_534:
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
  target = (&&function_533);
  goto apply_addr;
function_535:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_534);
  goto apply_addr;
function_536:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_535);
  goto apply_addr;
function_537:
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
  target = (&&function_536);
  goto apply_addr;
function_538:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_537);
  goto apply_addr;
function_539:
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
  target = (&&function_538);
  goto apply_addr;
function_540:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_539);
  goto apply_addr;
function_541:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_540);
  goto apply_addr;
function_542:
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
  target = (&&function_541);
  goto apply_addr;
function_543:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_542);
  goto apply_addr;
function_544:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_543);
  goto apply_addr;
function_545:
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
  target = (&&function_544);
  goto apply_addr;
function_546:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_545);
  goto apply_addr;
function_547:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_546);
  goto apply_addr;
function_548:
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
  target = (&&function_547);
  goto apply_addr;
function_549:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_548);
  goto apply_addr;
function_550:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_549);
  goto apply_addr;
function_551:
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
  target = (&&function_550);
  goto apply_addr;
function_552:
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
  target = (&&function_551);
  goto apply_addr;
/* _parse-expr */
body_198:
  increment_count(env);
  val = wrap_function((&&function_552), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_199;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_553:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  goto top_level_apply;
function_554:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c52); /* ___l_44 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_553);
  goto apply_addr;
function_555:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c54); /* ___l_46 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c53); /* ___l_45 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_554);
  goto apply_addr;
function_556:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_555), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  goto top_level_apply;
/* ____read-expr */
body_199:
  increment_count(env);
  val = wrap_function((&&function_556), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_200;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_200:
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
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_201;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_201:
  val = -39;
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_202;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_202:
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
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_203;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_203:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_204;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_204:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_205;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_205:
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
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_206;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_206:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_207;
pointer global_c95c99c97c97c100c114;
function_557:
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
/* _caadr */
body_207:
  increment_count(env);
  val = wrap_function((&&function_557), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_208;
pointer global_c95c111c114;
function_558:
  goto top_level_apply;
function_559:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_560:
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
  increment_count(env);
  val = wrap_function((&&function_559), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_558);
  goto apply_addr;
/* _or */
body_208:
  increment_count(env);
  val = wrap_function((&&function_560), env);
  global_c95c111c114 = val; /* _or */
  goto body_209;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101;
function_561:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_562:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c48); /* ___l_50 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c57); /* ___l_49 */
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_561);
  goto apply_addr;
function_563:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_562);
  goto apply_addr;
function_564:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_565:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_564);
  goto apply_addr;
function_566:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c51); /* ___l_53 */
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
  target = (&&function_565);
  goto apply_addr;
function_567:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  target = (&&function_566);
  goto apply_addr;
function_568:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c50); /* ___l_52 */
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
    target = (&&function_567);
    goto apply_addr;
  }
function_569:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_568);
  goto apply_addr;
function_570:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_569);
  goto apply_addr;
function_571:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_570);
  goto apply_addr;
function_572:
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
  target = (&&function_571);
  goto apply_addr;
function_573:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_572);
  goto apply_addr;
function_574:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c49); /* ___l_51 */
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
    target = (&&function_563);
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
    target = (&&function_573);
    goto apply_addr;
  }
function_575:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_574);
  goto apply_addr;
function_576:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c55); /* ___l_47 */
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
    increment_count(val = global_c95c95c95c108c95c52c56); /* ___l_48 */
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
    target = (&&function_575);
    goto apply_addr;
  }
function_577:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_576);
  goto apply_addr;
function_578:
  increment_count(env);
  val = wrap_function((&&function_577), env);
  goto pop_function;
/* ____compile-source */
body_209:
  increment_count(env);
  val = wrap_function((&&function_578), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_210;
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
    decrement_count(val);
    val = NIL;
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
    decrement_count(val);
    val = NIL;
  }
  pop_args();
  goto *target;
function_579:
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
function_580:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_581:
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
  target = (&&function_580);
  goto apply_addr;
body_210:
  increment_count(env);
  val = wrap_function((&&function_581), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), NIL), call_stack);
  call_stack = cons(wrap_function((&&function_579), NIL), call_stack);
  goto body_0;
}
