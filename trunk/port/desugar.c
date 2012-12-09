#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#define DEFINE_FUNCTION_HELPERS

#include "io.h"
#include "mem.h"
pointer arguments;
int return_value = 0;
function_addr target, return_location;
pointer val, args, stack, call_stack, env, temp, true;
int sign_mask;
inline int is_unary(pointer args) {
  return (is_pair(args)) &
         (is_atom(cdr(args)));
}
inline int is_binary(pointer args) {
  return (is_pair(args)) &
         (is_pair(cdr(args))) &
         (is_atom(cdr(cdr(args))));
}
pointer make_string(char* str) {
  pointer r = nil();
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
  pointer r = nil();
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
#ifdef BARE_HARDWARE
void main(unsigned long magic,
          multiboot_data* boot_data) {
#else
int main(int argc, char** argv) {
#endif
  target = &&end_function_addr;
  sign_mask = build_sign_mask();
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
  long int memory_limit = 128 * 1024 * 1024;
  void* memory = malloc(memory_limit);
  init_mem(memory, memory_limit);
  init_io();
  arguments = nil();
  int i;
  for (i = argc - 1; i >= 0; i--) {
    arguments = cons(make_string(argv[i]),
                     arguments);
  }
#endif
  val = args = stack = call_stack = env = temp = nil();
  goto start_addr;
pointer global_c101c113c117c97c108;
function_0:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    goto top_level_apply;
  } else {
    val = nil();
    goto pop_function;
  }
function_1:
  if (is_pair(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    if (is_pair(car(cdr(car(env))))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(cdr(car(env)))));
      args = cons(val, args);
      increment_count(val = car(car(car(env))));
      args = cons(val, args);
      increment_count(val = global_c101c113c117c97c108 /* equal */);
      target = (&&function_0);
      goto apply_addr;
    } else {
      val = nil();
      goto pop_function;
    }
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_atom(car(args))) &
        (is_atom(car(cdr(args)))) &
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
    pop_args();
    goto pop_function;
  }
/* equal */
body_0:
  increment_count(env);
  val = wrap_function((&&function_1), env);
  global_c101c113c117c97c108 = val; /* equal */
  goto body_1;
pointer global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
function_2:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = cdr(car(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_3:
  if (is_pair(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-34);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_2);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-115);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_atom(car(args))) &
        (is_atom(car(cdr(args)))) &
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
    pop_args();
    if (! is_nil(val)) {
      decrement_count(val);
      val = nil();
      push_args();
      args = val;
      val = new_number(114);
      args = cons(val, args);
      val = new_number(97);
      args = cons(val, args);
      val = new_number(99);
      args = cons(val, args);
      val = args;
      args = nil();
      pop_args();
      goto pop_function;
    } else {
      push_args();
      val = nil();
      args = val;
      val = new_symbol(-114);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if ((is_binary(args)) &
          (is_atom(car(args))) &
          (is_atom(car(cdr(args)))) &
          eq(car(args), car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
      pop_args();
      if (! is_nil(val)) {
        decrement_count(val);
        val = nil();
        push_args();
        args = val;
        val = new_number(114);
        args = cons(val, args);
        val = new_number(100);
        args = cons(val, args);
        val = new_number(99);
        args = cons(val, args);
        val = args;
        args = nil();
        pop_args();
        goto pop_function;
      } else {
        push_args();
        val = nil();
        args = val;
        val = new_symbol(-113);
        args = cons(val, args);
        increment_count(val = car(car(env)));
        args = cons(val, args);
        if ((is_binary(args)) &
            (is_atom(car(args))) &
            (is_atom(car(cdr(args)))) &
            eq(car(args), car(cdr(args)))) {
          increment_count(val = true);
        } else { val = nil(); }
        pop_args();
        if (! is_nil(val)) {
          decrement_count(val);
          val = nil();
          push_args();
          args = val;
          val = new_number(61);
          args = cons(val, args);
          val = args;
          args = nil();
          pop_args();
          goto pop_function;
        } else {
          push_args();
          val = nil();
          args = val;
          val = new_symbol(-112);
          args = cons(val, args);
          increment_count(val = car(car(env)));
          args = cons(val, args);
          if ((is_binary(args)) &
              (is_atom(car(args))) &
              (is_atom(car(cdr(args)))) &
              eq(car(args), car(cdr(args)))) {
            increment_count(val = true);
          } else { val = nil(); }
          pop_args();
          if (! is_nil(val)) {
            decrement_count(val);
            val = nil();
            push_args();
            args = val;
            val = new_number(60);
            args = cons(val, args);
            val = args;
            args = nil();
            pop_args();
            goto pop_function;
          } else {
            push_args();
            val = nil();
            args = val;
            val = new_symbol(-111);
            args = cons(val, args);
            increment_count(val = car(car(env)));
            args = cons(val, args);
            if ((is_binary(args)) &
                (is_atom(car(args))) &
                (is_atom(car(cdr(args)))) &
                eq(car(args), car(cdr(args)))) {
              increment_count(val = true);
            } else { val = nil(); }
            pop_args();
            if (! is_nil(val)) {
              decrement_count(val);
              val = nil();
              push_args();
              args = val;
              val = new_number(62);
              args = cons(val, args);
              val = args;
              args = nil();
              pop_args();
              goto pop_function;
            } else {
              push_args();
              val = nil();
              args = val;
              val = new_symbol(-110);
              args = cons(val, args);
              increment_count(val = car(car(env)));
              args = cons(val, args);
              if ((is_binary(args)) &
                  (is_atom(car(args))) &
                  (is_atom(car(cdr(args)))) &
                  eq(car(args), car(cdr(args)))) {
                increment_count(val = true);
              } else { val = nil(); }
              pop_args();
              if (! is_nil(val)) {
                decrement_count(val);
                val = nil();
                push_args();
                args = val;
                val = new_number(43);
                args = cons(val, args);
                val = args;
                args = nil();
                pop_args();
                goto pop_function;
              } else {
                push_args();
                val = nil();
                args = val;
                val = new_symbol(-109);
                args = cons(val, args);
                increment_count(val = car(car(env)));
                args = cons(val, args);
                if ((is_binary(args)) &
                    (is_atom(car(args))) &
                    (is_atom(car(cdr(args)))) &
                    eq(car(args), car(cdr(args)))) {
                  increment_count(val = true);
                } else { val = nil(); }
                pop_args();
                if (! is_nil(val)) {
                  decrement_count(val);
                  val = nil();
                  push_args();
                  args = val;
                  val = new_number(45);
                  args = cons(val, args);
                  val = args;
                  args = nil();
                  pop_args();
                  goto pop_function;
                } else {
                  push_args();
                  val = nil();
                  args = val;
                  val = new_symbol(-108);
                  args = cons(val, args);
                  increment_count(val = car(car(env)));
                  args = cons(val, args);
                  if ((is_binary(args)) &
                      (is_atom(car(args))) &
                      (is_atom(car(cdr(args)))) &
                      eq(car(args), car(cdr(args)))) {
                    increment_count(val = true);
                  } else { val = nil(); }
                  pop_args();
                  if (! is_nil(val)) {
                    decrement_count(val);
                    val = nil();
                    push_args();
                    args = val;
                    val = new_number(42);
                    args = cons(val, args);
                    val = args;
                    args = nil();
                    pop_args();
                    goto pop_function;
                  } else {
                    push_args();
                    val = nil();
                    args = val;
                    val = new_symbol(-107);
                    args = cons(val, args);
                    increment_count(val = car(car(env)));
                    args = cons(val, args);
                    if ((is_binary(args)) &
                        (is_atom(car(args))) &
                        (is_atom(car(cdr(args)))) &
                        eq(car(args), car(cdr(args)))) {
                      increment_count(val = true);
                    } else { val = nil(); }
                    pop_args();
                    if (! is_nil(val)) {
                      decrement_count(val);
                      val = nil();
                      push_args();
                      args = val;
                      val = new_number(47);
                      args = cons(val, args);
                      val = args;
                      args = nil();
                      pop_args();
                      goto pop_function;
                    } else {
                      push_args();
                      val = nil();
                      args = val;
                      val = new_symbol(-106);
                      args = cons(val, args);
                      increment_count(val = car(car(env)));
                      args = cons(val, args);
                      if ((is_binary(args)) &
                          (is_atom(car(args))) &
                          (is_atom(car(cdr(args)))) &
                          eq(car(args), car(cdr(args)))) {
                        increment_count(val = true);
                      } else { val = nil(); }
                      pop_args();
                      if (! is_nil(val)) {
                        decrement_count(val);
                        val = nil();
                        push_args();
                        args = val;
                        val = new_number(37);
                        args = cons(val, args);
                        val = args;
                        args = nil();
                        pop_args();
                        goto pop_function;
                      } else {
                        push_args();
                        val = nil();
                        args = val;
                        val = new_symbol(-105);
                        args = cons(val, args);
                        increment_count(val = car(car(env)));
                        args = cons(val, args);
                        if ((is_binary(args)) &
                            (is_atom(car(args))) &
                            (is_atom(car(cdr(args)))) &
                            eq(car(args), car(cdr(args)))) {
                          increment_count(val = true);
                        } else { val = nil(); }
                        pop_args();
                        if (! is_nil(val)) {
                          decrement_count(val);
                          val = nil();
                          push_args();
                          args = val;
                          val = new_number(126);
                          args = cons(val, args);
                          val = args;
                          args = nil();
                          pop_args();
                          goto pop_function;
                        } else {
                          push_args();
                          val = nil();
                          args = val;
                          val = new_symbol(-104);
                          args = cons(val, args);
                          increment_count(val = car(car(env)));
                          args = cons(val, args);
                          if ((is_binary(args)) &
                              (is_atom(car(args))) &
                              (is_atom(car(cdr(args)))) &
                              eq(car(args), car(cdr(args)))) {
                            increment_count(val = true);
                          } else { val = nil(); }
                          pop_args();
                          if (! is_nil(val)) {
                            decrement_count(val);
                            val = nil();
                            push_args();
                            args = val;
                            val = new_number(38);
                            args = cons(val, args);
                            val = args;
                            args = nil();
                            pop_args();
                            goto pop_function;
                          } else {
                            push_args();
                            val = nil();
                            args = val;
                            val = new_symbol(-103);
                            args = cons(val, args);
                            increment_count(val = car(car(env)));
                            args = cons(val, args);
                            if ((is_binary(args)) &
                                (is_atom(car(args))) &
                                (is_atom(car(cdr(args)))) &
                                eq(car(args), car(cdr(args)))) {
                              increment_count(val = true);
                            } else { val = nil(); }
                            pop_args();
                            if (! is_nil(val)) {
                              decrement_count(val);
                              val = nil();
                              push_args();
                              args = val;
                              val = new_number(124);
                              args = cons(val, args);
                              val = args;
                              args = nil();
                              pop_args();
                              goto pop_function;
                            } else {
                              push_args();
                              val = nil();
                              args = val;
                              val = new_symbol(-102);
                              args = cons(val, args);
                              increment_count(val = car(car(env)));
                              args = cons(val, args);
                              if ((is_binary(args)) &
                                  (is_atom(car(args))) &
                                  (is_atom(car(cdr(args)))) &
                                  eq(car(args), car(cdr(args)))) {
                                increment_count(val = true);
                              } else { val = nil(); }
                              pop_args();
                              if (! is_nil(val)) {
                                decrement_count(val);
                                val = nil();
                                push_args();
                                args = val;
                                val = new_number(94);
                                args = cons(val, args);
                                val = args;
                                args = nil();
                                pop_args();
                                goto pop_function;
                              } else {
                                push_args();
                                val = nil();
                                args = val;
                                val = new_symbol(-101);
                                args = cons(val, args);
                                increment_count(val = car(car(env)));
                                args = cons(val, args);
                                if ((is_binary(args)) &
                                    (is_atom(car(args))) &
                                    (is_atom(car(cdr(args)))) &
                                    eq(car(args), car(cdr(args)))) {
                                  increment_count(val = true);
                                } else { val = nil(); }
                                pop_args();
                                if (! is_nil(val)) {
                                  decrement_count(val);
                                  val = nil();
                                  push_args();
                                  args = val;
                                  val = new_number(62);
                                  args = cons(val, args);
                                  val = new_number(62);
                                  args = cons(val, args);
                                  val = args;
                                  args = nil();
                                  pop_args();
                                  goto pop_function;
                                } else {
                                  push_args();
                                  val = nil();
                                  args = val;
                                  val = new_symbol(-100);
                                  args = cons(val, args);
                                  increment_count(val = car(car(env)));
                                  args = cons(val, args);
                                  if ((is_binary(args)) &
                                      (is_atom(car(args))) &
                                      (is_atom(car(cdr(args)))) &
                                      eq(car(args), car(cdr(args)))) {
                                    increment_count(val = true);
                                  } else { val = nil(); }
                                  pop_args();
                                  if (! is_nil(val)) {
                                    decrement_count(val);
                                    val = nil();
                                    push_args();
                                    args = val;
                                    val = new_number(62);
                                    args = cons(val, args);
                                    val = new_number(62);
                                    args = cons(val, args);
                                    val = new_number(62);
                                    args = cons(val, args);
                                    val = args;
                                    args = nil();
                                    pop_args();
                                    goto pop_function;
                                  } else {
                                    push_args();
                                    val = nil();
                                    args = val;
                                    val = new_symbol(-99);
                                    args = cons(val, args);
                                    increment_count(val = car(car(env)));
                                    args = cons(val, args);
                                    if ((is_binary(args)) &
                                        (is_atom(car(args))) &
                                        (is_atom(car(cdr(args)))) &
                                        eq(car(args), car(cdr(args)))) {
                                      increment_count(val = true);
                                    } else { val = nil(); }
                                    pop_args();
                                    if (! is_nil(val)) {
                                      decrement_count(val);
                                      val = nil();
                                      push_args();
                                      args = val;
                                      val = new_number(60);
                                      args = cons(val, args);
                                      val = new_number(60);
                                      args = cons(val, args);
                                      val = args;
                                      args = nil();
                                      pop_args();
                                      goto pop_function;
                                    } else {
                                      push_args();
                                      val = nil();
                                      args = val;
                                      val = new_symbol(-98);
                                      args = cons(val, args);
                                      increment_count(val = car(car(env)));
                                      args = cons(val, args);
                                      if ((is_binary(args)) &
                                          (is_atom(car(args))) &
                                          (is_atom(car(cdr(args)))) &
                                          eq(car(args), car(cdr(args)))) {
                                        increment_count(val = true);
                                      } else { val = nil(); }
                                      pop_args();
                                      if (! is_nil(val)) {
                                        decrement_count(val);
                                        val = nil();
                                        push_args();
                                        args = val;
                                        val = new_number(63);
                                        args = cons(val, args);
                                        val = new_number(108);
                                        args = cons(val, args);
                                        val = new_number(108);
                                        args = cons(val, args);
                                        val = new_number(117);
                                        args = cons(val, args);
                                        val = new_number(110);
                                        args = cons(val, args);
                                        val = args;
                                        args = nil();
                                        pop_args();
                                        goto pop_function;
                                      } else {
                                        push_args();
                                        val = nil();
                                        args = val;
                                        val = new_symbol(-97);
                                        args = cons(val, args);
                                        increment_count(val = car(car(env)));
                                        args = cons(val, args);
                                        if ((is_binary(args)) &
                                            (is_atom(car(args))) &
                                            (is_atom(car(cdr(args)))) &
                                            eq(car(args), car(cdr(args)))) {
                                          increment_count(val = true);
                                        } else { val = nil(); }
                                        pop_args();
                                        if (! is_nil(val)) {
                                          decrement_count(val);
                                          val = nil();
                                          push_args();
                                          args = val;
                                          val = new_number(63);
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
                                          val = args;
                                          args = nil();
                                          pop_args();
                                          goto pop_function;
                                        } else {
                                          push_args();
                                          val = nil();
                                          args = val;
                                          val = new_symbol(-96);
                                          args = cons(val, args);
                                          increment_count(val = car(car(env)));
                                          args = cons(val, args);
                                          if ((is_binary(args)) &
                                              (is_atom(car(args))) &
                                              (is_atom(car(cdr(args)))) &
                                              eq(car(args), car(cdr(args)))) {
                                            increment_count(val = true);
                                          } else { val = nil(); }
                                          pop_args();
                                          if (! is_nil(val)) {
                                            decrement_count(val);
                                            val = nil();
                                            push_args();
                                            args = val;
                                            val = new_number(63);
                                            args = cons(val, args);
                                            val = new_number(114);
                                            args = cons(val, args);
                                            val = new_number(105);
                                            args = cons(val, args);
                                            val = new_number(97);
                                            args = cons(val, args);
                                            val = new_number(112);
                                            args = cons(val, args);
                                            val = args;
                                            args = nil();
                                            pop_args();
                                            goto pop_function;
                                          } else {
                                            push_args();
                                            val = nil();
                                            args = val;
                                            val = new_symbol(-95);
                                            args = cons(val, args);
                                            increment_count(val = car(car(env)));
                                            args = cons(val, args);
                                            if ((is_binary(args)) &
                                                (is_atom(car(args))) &
                                                (is_atom(car(cdr(args)))) &
                                                eq(car(args), car(cdr(args)))) {
                                              increment_count(val = true);
                                            } else { val = nil(); }
                                            pop_args();
                                            if (! is_nil(val)) {
                                              decrement_count(val);
                                              val = nil();
                                              push_args();
                                              args = val;
                                              val = new_number(63);
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
                                              val = args;
                                              args = nil();
                                              pop_args();
                                              goto pop_function;
                                            } else {
                                              push_args();
                                              val = nil();
                                              args = val;
                                              val = new_symbol(-94);
                                              args = cons(val, args);
                                              increment_count(val = car(car(env)));
                                              args = cons(val, args);
                                              if ((is_binary(args)) &
                                                  (is_atom(car(args))) &
                                                  (is_atom(car(cdr(args)))) &
                                                  eq(car(args), car(cdr(args)))) {
                                                increment_count(val = true);
                                              } else { val = nil(); }
                                              pop_args();
                                              if (! is_nil(val)) {
                                                decrement_count(val);
                                                val = nil();
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
                                                args = nil();
                                                pop_args();
                                                goto pop_function;
                                              } else {
                                                push_args();
                                                val = nil();
                                                args = val;
                                                val = new_symbol(-93);
                                                args = cons(val, args);
                                                increment_count(val = car(car(env)));
                                                args = cons(val, args);
                                                if ((is_binary(args)) &
                                                    (is_atom(car(args))) &
                                                    (is_atom(car(cdr(args)))) &
                                                    eq(car(args), car(cdr(args)))) {
                                                  increment_count(val = true);
                                                } else { val = nil(); }
                                                pop_args();
                                                if (! is_nil(val)) {
                                                  decrement_count(val);
                                                  val = nil();
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
                                                  args = nil();
                                                  pop_args();
                                                  goto pop_function;
                                                } else {
                                                  push_args();
                                                  val = nil();
                                                  args = val;
                                                  val = new_symbol(-92);
                                                  args = cons(val, args);
                                                  increment_count(val = car(car(env)));
                                                  args = cons(val, args);
                                                  if ((is_binary(args)) &
                                                      (is_atom(car(args))) &
                                                      (is_atom(car(cdr(args)))) &
                                                      eq(car(args), car(cdr(args)))) {
                                                    increment_count(val = true);
                                                  } else { val = nil(); }
                                                  pop_args();
                                                  if (! is_nil(val)) {
                                                    decrement_count(val);
                                                    val = nil();
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
                                                    args = nil();
                                                    pop_args();
                                                    goto pop_function;
                                                  } else {
                                                    push_args();
                                                    val = nil();
                                                    args = val;
                                                    val = new_symbol(-91);
                                                    args = cons(val, args);
                                                    increment_count(val = car(car(env)));
                                                    args = cons(val, args);
                                                    if ((is_binary(args)) &
                                                        (is_atom(car(args))) &
                                                        (is_atom(car(cdr(args)))) &
                                                        eq(car(args), car(cdr(args)))) {
                                                      increment_count(val = true);
                                                    } else { val = nil(); }
                                                    pop_args();
                                                    if (! is_nil(val)) {
                                                      decrement_count(val);
                                                      val = nil();
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
                                                      args = nil();
                                                      pop_args();
                                                      goto pop_function;
                                                    } else {
                                                      push_args();
                                                      val = nil();
                                                      args = val;
                                                      val = new_symbol(-90);
                                                      args = cons(val, args);
                                                      increment_count(val = car(car(env)));
                                                      args = cons(val, args);
                                                      if ((is_binary(args)) &
                                                          (is_atom(car(args))) &
                                                          (is_atom(car(cdr(args)))) &
                                                          eq(car(args), car(cdr(args)))) {
                                                        increment_count(val = true);
                                                      } else { val = nil(); }
                                                      pop_args();
                                                      if (! is_nil(val)) {
                                                        decrement_count(val);
                                                        val = nil();
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
                                                        args = nil();
                                                        pop_args();
                                                        goto pop_function;
                                                      } else {
                                                        push_args();
                                                        val = nil();
                                                        args = val;
                                                        val = new_symbol(-89);
                                                        args = cons(val, args);
                                                        increment_count(val = car(car(env)));
                                                        args = cons(val, args);
                                                        if ((is_binary(args)) &
                                                            (is_atom(car(args))) &
                                                            (is_atom(car(cdr(args)))) &
                                                            eq(car(args), car(cdr(args)))) {
                                                          increment_count(val = true);
                                                        } else { val = nil(); }
                                                        pop_args();
                                                        if (! is_nil(val)) {
                                                          decrement_count(val);
                                                          val = nil();
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
                                                          args = nil();
                                                          pop_args();
                                                          goto pop_function;
                                                        } else {
                                                          push_args();
                                                          val = nil();
                                                          args = val;
                                                          val = new_symbol(-88);
                                                          args = cons(val, args);
                                                          increment_count(val = car(car(env)));
                                                          args = cons(val, args);
                                                          if ((is_binary(args)) &
                                                              (is_atom(car(args))) &
                                                              (is_atom(car(cdr(args)))) &
                                                              eq(car(args), car(cdr(args)))) {
                                                            increment_count(val = true);
                                                          } else { val = nil(); }
                                                          pop_args();
                                                          if (! is_nil(val)) {
                                                            decrement_count(val);
                                                            val = nil();
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
                                                            args = nil();
                                                            pop_args();
                                                            goto pop_function;
                                                          } else {
                                                            push_args();
                                                            val = nil();
                                                            args = val;
                                                            val = new_symbol(-87);
                                                            args = cons(val, args);
                                                            increment_count(val = car(car(env)));
                                                            args = cons(val, args);
                                                            if ((is_binary(args)) &
                                                                (is_atom(car(args))) &
                                                                (is_atom(car(cdr(args)))) &
                                                                eq(car(args), car(cdr(args)))) {
                                                              increment_count(val = true);
                                                            } else { val = nil(); }
                                                            pop_args();
                                                            if (! is_nil(val)) {
                                                              decrement_count(val);
                                                              val = nil();
                                                              push_args();
                                                              args = val;
                                                              val = new_number(116);
                                                              args = cons(val, args);
                                                              val = new_number(111);
                                                              args = cons(val, args);
                                                              val = new_number(110);
                                                              args = cons(val, args);
                                                              val = args;
                                                              args = nil();
                                                              pop_args();
                                                              goto pop_function;
                                                            } else {
                                                              push_args();
                                                              val = nil();
                                                              args = val;
                                                              val = new_symbol(-86);
                                                              args = cons(val, args);
                                                              increment_count(val = car(car(env)));
                                                              args = cons(val, args);
                                                              if ((is_binary(args)) &
                                                                  (is_atom(car(args))) &
                                                                  (is_atom(car(cdr(args)))) &
                                                                  eq(car(args), car(cdr(args)))) {
                                                                increment_count(val = true);
                                                              } else { val = nil(); }
                                                              pop_args();
                                                              if (! is_nil(val)) {
                                                                decrement_count(val);
                                                                val = nil();
                                                                push_args();
                                                                args = val;
                                                                val = new_number(100);
                                                                args = cons(val, args);
                                                                val = new_number(110);
                                                                args = cons(val, args);
                                                                val = new_number(97);
                                                                args = cons(val, args);
                                                                val = args;
                                                                args = nil();
                                                                pop_args();
                                                                goto pop_function;
                                                              } else {
                                                                push_args();
                                                                val = nil();
                                                                args = val;
                                                                val = new_symbol(-85);
                                                                args = cons(val, args);
                                                                increment_count(val = car(car(env)));
                                                                args = cons(val, args);
                                                                if ((is_binary(args)) &
                                                                    (is_atom(car(args))) &
                                                                    (is_atom(car(cdr(args)))) &
                                                                    eq(car(args), car(cdr(args)))) {
                                                                  increment_count(val = true);
                                                                } else { val = nil(); }
                                                                pop_args();
                                                                if (! is_nil(val)) {
                                                                  decrement_count(val);
                                                                  val = nil();
                                                                  push_args();
                                                                  args = val;
                                                                  val = new_number(114);
                                                                  args = cons(val, args);
                                                                  val = new_number(111);
                                                                  args = cons(val, args);
                                                                  val = args;
                                                                  args = nil();
                                                                  pop_args();
                                                                  goto pop_function;
                                                                } else {
                                                                  push_args();
                                                                  val = nil();
                                                                  args = val;
                                                                  val = new_symbol(-84);
                                                                  args = cons(val, args);
                                                                  increment_count(val = car(car(env)));
                                                                  args = cons(val, args);
                                                                  if ((is_binary(args)) &
                                                                      (is_atom(car(args))) &
                                                                      (is_atom(car(cdr(args)))) &
                                                                      eq(car(args), car(cdr(args)))) {
                                                                    increment_count(val = true);
                                                                  } else { val = nil(); }
                                                                  pop_args();
                                                                  if (! is_nil(val)) {
                                                                    decrement_count(val);
                                                                    val = nil();
                                                                    push_args();
                                                                    args = val;
                                                                    val = new_number(112);
                                                                    args = cons(val, args);
                                                                    val = new_number(97);
                                                                    args = cons(val, args);
                                                                    val = new_number(109);
                                                                    args = cons(val, args);
                                                                    val = args;
                                                                    args = nil();
                                                                    pop_args();
                                                                    goto pop_function;
                                                                  } else {
                                                                    push_args();
                                                                    val = nil();
                                                                    args = val;
                                                                    val = new_symbol(-83);
                                                                    args = cons(val, args);
                                                                    increment_count(val = car(car(env)));
                                                                    args = cons(val, args);
                                                                    if ((is_binary(args)) &
                                                                        (is_atom(car(args))) &
                                                                        (is_atom(car(cdr(args)))) &
                                                                        eq(car(args), car(cdr(args)))) {
                                                                      increment_count(val = true);
                                                                    } else { val = nil(); }
                                                                    pop_args();
                                                                    if (! is_nil(val)) {
                                                                      decrement_count(val);
                                                                      val = nil();
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
                                                                      args = nil();
                                                                      pop_args();
                                                                      goto pop_function;
                                                                    } else {
                                                                      push_args();
                                                                      val = nil();
                                                                      args = val;
                                                                      val = new_symbol(-82);
                                                                      args = cons(val, args);
                                                                      increment_count(val = car(car(env)));
                                                                      args = cons(val, args);
                                                                      if ((is_binary(args)) &
                                                                          (is_atom(car(args))) &
                                                                          (is_atom(car(cdr(args)))) &
                                                                          eq(car(args), car(cdr(args)))) {
                                                                        increment_count(val = true);
                                                                      } else { val = nil(); }
                                                                      pop_args();
                                                                      if (! is_nil(val)) {
                                                                        decrement_count(val);
                                                                        val = nil();
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
                                                                        args = nil();
                                                                        pop_args();
                                                                        goto pop_function;
                                                                      } else {
                                                                        push_args();
                                                                        val = nil();
                                                                        args = val;
                                                                        val = new_symbol(-81);
                                                                        args = cons(val, args);
                                                                        increment_count(val = car(car(env)));
                                                                        args = cons(val, args);
                                                                        if ((is_binary(args)) &
                                                                            (is_atom(car(args))) &
                                                                            (is_atom(car(cdr(args)))) &
                                                                            eq(car(args), car(cdr(args)))) {
                                                                          increment_count(val = true);
                                                                        } else { val = nil(); }
                                                                        pop_args();
                                                                        if (! is_nil(val)) {
                                                                          decrement_count(val);
                                                                          val = nil();
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
                                                                          args = nil();
                                                                          pop_args();
                                                                          goto pop_function;
                                                                        } else {
                                                                          push_args();
                                                                          val = nil();
                                                                          args = val;
                                                                          val = new_symbol(-80);
                                                                          args = cons(val, args);
                                                                          increment_count(val = car(car(env)));
                                                                          args = cons(val, args);
                                                                          if ((is_binary(args)) &
                                                                              (is_atom(car(args))) &
                                                                              (is_atom(car(cdr(args)))) &
                                                                              eq(car(args), car(cdr(args)))) {
                                                                            increment_count(val = true);
                                                                          } else { val = nil(); }
                                                                          pop_args();
                                                                          if (! is_nil(val)) {
                                                                            decrement_count(val);
                                                                            val = nil();
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
                                                                            args = nil();
                                                                            pop_args();
                                                                            goto pop_function;
                                                                          } else {
                                                                            push_args();
                                                                            val = nil();
                                                                            args = val;
                                                                            val = new_symbol(-79);
                                                                            args = cons(val, args);
                                                                            increment_count(val = car(car(env)));
                                                                            args = cons(val, args);
                                                                            if ((is_binary(args)) &
                                                                                (is_atom(car(args))) &
                                                                                (is_atom(car(cdr(args)))) &
                                                                                eq(car(args), car(cdr(args)))) {
                                                                              increment_count(val = true);
                                                                            } else { val = nil(); }
                                                                            pop_args();
                                                                            if (! is_nil(val)) {
                                                                              decrement_count(val);
                                                                              val = nil();
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
                                                                              args = nil();
                                                                              pop_args();
                                                                              goto pop_function;
                                                                            } else {
                                                                              push_args();
                                                                              val = nil();
                                                                              args = val;
                                                                              val = new_symbol(-78);
                                                                              args = cons(val, args);
                                                                              increment_count(val = car(car(env)));
                                                                              args = cons(val, args);
                                                                              if ((is_binary(args)) &
                                                                                  (is_atom(car(args))) &
                                                                                  (is_atom(car(cdr(args)))) &
                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                increment_count(val = true);
                                                                              } else { val = nil(); }
                                                                              pop_args();
                                                                              if (! is_nil(val)) {
                                                                                decrement_count(val);
                                                                                val = nil();
                                                                                push_args();
                                                                                args = val;
                                                                                val = new_number(101);
                                                                                args = cons(val, args);
                                                                                val = new_number(115);
                                                                                args = cons(val, args);
                                                                                val = new_number(114);
                                                                                args = cons(val, args);
                                                                                val = new_number(117);
                                                                                args = cons(val, args);
                                                                                val = new_number(99);
                                                                                args = cons(val, args);
                                                                                val = new_number(101);
                                                                                args = cons(val, args);
                                                                                val = new_number(114);
                                                                                args = cons(val, args);
                                                                                val = args;
                                                                                args = nil();
                                                                                pop_args();
                                                                                goto pop_function;
                                                                              } else {
                                                                                push_args();
                                                                                val = nil();
                                                                                args = val;
                                                                                val = new_symbol(-77);
                                                                                args = cons(val, args);
                                                                                increment_count(val = car(car(env)));
                                                                                args = cons(val, args);
                                                                                if ((is_binary(args)) &
                                                                                    (is_atom(car(args))) &
                                                                                    (is_atom(car(cdr(args)))) &
                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                  increment_count(val = true);
                                                                                } else { val = nil(); }
                                                                                pop_args();
                                                                                if (! is_nil(val)) {
                                                                                  decrement_count(val);
                                                                                  val = nil();
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
                                                                                  args = nil();
                                                                                  pop_args();
                                                                                  goto pop_function;
                                                                                } else {
                                                                                  push_args();
                                                                                  val = nil();
                                                                                  args = val;
                                                                                  val = new_symbol(-76);
                                                                                  args = cons(val, args);
                                                                                  increment_count(val = car(car(env)));
                                                                                  args = cons(val, args);
                                                                                  if ((is_binary(args)) &
                                                                                      (is_atom(car(args))) &
                                                                                      (is_atom(car(cdr(args)))) &
                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                    increment_count(val = true);
                                                                                  } else { val = nil(); }
                                                                                  pop_args();
                                                                                  if (! is_nil(val)) {
                                                                                    decrement_count(val);
                                                                                    val = nil();
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
                                                                                    args = nil();
                                                                                    pop_args();
                                                                                    goto pop_function;
                                                                                  } else {
                                                                                    push_args();
                                                                                    val = nil();
                                                                                    args = val;
                                                                                    val = new_symbol(-75);
                                                                                    args = cons(val, args);
                                                                                    increment_count(val = car(car(env)));
                                                                                    args = cons(val, args);
                                                                                    if ((is_binary(args)) &
                                                                                        (is_atom(car(args))) &
                                                                                        (is_atom(car(cdr(args)))) &
                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                      increment_count(val = true);
                                                                                    } else { val = nil(); }
                                                                                    pop_args();
                                                                                    if (! is_nil(val)) {
                                                                                      decrement_count(val);
                                                                                      val = nil();
                                                                                      push_args();
                                                                                      args = val;
                                                                                      val = new_number(100);
                                                                                      args = cons(val, args);
                                                                                      val = new_number(105);
                                                                                      args = cons(val, args);
                                                                                      val = args;
                                                                                      args = nil();
                                                                                      pop_args();
                                                                                      goto pop_function;
                                                                                    } else {
                                                                                      push_args();
                                                                                      val = nil();
                                                                                      args = val;
                                                                                      val = new_symbol(-74);
                                                                                      args = cons(val, args);
                                                                                      increment_count(val = car(car(env)));
                                                                                      args = cons(val, args);
                                                                                      if ((is_binary(args)) &
                                                                                          (is_atom(car(args))) &
                                                                                          (is_atom(car(cdr(args)))) &
                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                        increment_count(val = true);
                                                                                      } else { val = nil(); }
                                                                                      pop_args();
                                                                                      if (! is_nil(val)) {
                                                                                        decrement_count(val);
                                                                                        val = nil();
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
                                                                                        args = nil();
                                                                                        pop_args();
                                                                                        goto pop_function;
                                                                                      } else {
                                                                                        push_args();
                                                                                        val = nil();
                                                                                        args = val;
                                                                                        val = new_symbol(-73);
                                                                                        args = cons(val, args);
                                                                                        increment_count(val = car(car(env)));
                                                                                        args = cons(val, args);
                                                                                        if ((is_binary(args)) &
                                                                                            (is_atom(car(args))) &
                                                                                            (is_atom(car(cdr(args)))) &
                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                          increment_count(val = true);
                                                                                        } else { val = nil(); }
                                                                                        pop_args();
                                                                                        if (! is_nil(val)) {
                                                                                          decrement_count(val);
                                                                                          val = nil();
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
                                                                                          args = nil();
                                                                                          pop_args();
                                                                                          goto pop_function;
                                                                                        } else {
                                                                                          push_args();
                                                                                          val = nil();
                                                                                          args = val;
                                                                                          val = new_symbol(-72);
                                                                                          args = cons(val, args);
                                                                                          increment_count(val = car(car(env)));
                                                                                          args = cons(val, args);
                                                                                          if ((is_binary(args)) &
                                                                                              (is_atom(car(args))) &
                                                                                              (is_atom(car(cdr(args)))) &
                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                            increment_count(val = true);
                                                                                          } else { val = nil(); }
                                                                                          pop_args();
                                                                                          if (! is_nil(val)) {
                                                                                            decrement_count(val);
                                                                                            val = nil();
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
                                                                                            args = nil();
                                                                                            pop_args();
                                                                                            goto pop_function;
                                                                                          } else {
                                                                                            push_args();
                                                                                            val = nil();
                                                                                            args = val;
                                                                                            val = new_symbol(-71);
                                                                                            args = cons(val, args);
                                                                                            increment_count(val = car(car(env)));
                                                                                            args = cons(val, args);
                                                                                            if ((is_binary(args)) &
                                                                                                (is_atom(car(args))) &
                                                                                                (is_atom(car(cdr(args)))) &
                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                              increment_count(val = true);
                                                                                            } else { val = nil(); }
                                                                                            pop_args();
                                                                                            if (! is_nil(val)) {
                                                                                              decrement_count(val);
                                                                                              val = nil();
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
                                                                                              args = nil();
                                                                                              pop_args();
                                                                                              goto pop_function;
                                                                                            } else {
                                                                                              push_args();
                                                                                              val = nil();
                                                                                              args = val;
                                                                                              val = new_symbol(-70);
                                                                                              args = cons(val, args);
                                                                                              increment_count(val = car(car(env)));
                                                                                              args = cons(val, args);
                                                                                              if ((is_binary(args)) &
                                                                                                  (is_atom(car(args))) &
                                                                                                  (is_atom(car(cdr(args)))) &
                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                increment_count(val = true);
                                                                                              } else { val = nil(); }
                                                                                              pop_args();
                                                                                              if (! is_nil(val)) {
                                                                                                decrement_count(val);
                                                                                                val = nil();
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
                                                                                                args = nil();
                                                                                                pop_args();
                                                                                                goto pop_function;
                                                                                              } else {
                                                                                                push_args();
                                                                                                val = nil();
                                                                                                args = val;
                                                                                                val = new_symbol(-69);
                                                                                                args = cons(val, args);
                                                                                                increment_count(val = car(car(env)));
                                                                                                args = cons(val, args);
                                                                                                if ((is_binary(args)) &
                                                                                                    (is_atom(car(args))) &
                                                                                                    (is_atom(car(cdr(args)))) &
                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                  increment_count(val = true);
                                                                                                } else { val = nil(); }
                                                                                                pop_args();
                                                                                                if (! is_nil(val)) {
                                                                                                  decrement_count(val);
                                                                                                  val = nil();
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
                                                                                                  args = nil();
                                                                                                  pop_args();
                                                                                                  goto pop_function;
                                                                                                } else {
                                                                                                  push_args();
                                                                                                  val = nil();
                                                                                                  args = val;
                                                                                                  val = new_symbol(-68);
                                                                                                  args = cons(val, args);
                                                                                                  increment_count(val = car(car(env)));
                                                                                                  args = cons(val, args);
                                                                                                  if ((is_binary(args)) &
                                                                                                      (is_atom(car(args))) &
                                                                                                      (is_atom(car(cdr(args)))) &
                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                    increment_count(val = true);
                                                                                                  } else { val = nil(); }
                                                                                                  pop_args();
                                                                                                  if (! is_nil(val)) {
                                                                                                    decrement_count(val);
                                                                                                    val = nil();
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
                                                                                                    args = nil();
                                                                                                    pop_args();
                                                                                                    goto pop_function;
                                                                                                  } else {
                                                                                                    push_args();
                                                                                                    val = nil();
                                                                                                    args = val;
                                                                                                    val = new_symbol(-67);
                                                                                                    args = cons(val, args);
                                                                                                    increment_count(val = car(car(env)));
                                                                                                    args = cons(val, args);
                                                                                                    if ((is_binary(args)) &
                                                                                                        (is_atom(car(args))) &
                                                                                                        (is_atom(car(cdr(args)))) &
                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                      increment_count(val = true);
                                                                                                    } else { val = nil(); }
                                                                                                    pop_args();
                                                                                                    if (! is_nil(val)) {
                                                                                                      decrement_count(val);
                                                                                                      val = nil();
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
                                                                                                      args = nil();
                                                                                                      pop_args();
                                                                                                      goto pop_function;
                                                                                                    } else {
                                                                                                      push_args();
                                                                                                      val = nil();
                                                                                                      args = val;
                                                                                                      val = new_symbol(-66);
                                                                                                      args = cons(val, args);
                                                                                                      increment_count(val = car(car(env)));
                                                                                                      args = cons(val, args);
                                                                                                      if ((is_binary(args)) &
                                                                                                          (is_atom(car(args))) &
                                                                                                          (is_atom(car(cdr(args)))) &
                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                        increment_count(val = true);
                                                                                                      } else { val = nil(); }
                                                                                                      pop_args();
                                                                                                      if (! is_nil(val)) {
                                                                                                        decrement_count(val);
                                                                                                        val = nil();
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
                                                                                                        args = nil();
                                                                                                        pop_args();
                                                                                                        goto pop_function;
                                                                                                      } else {
                                                                                                        push_args();
                                                                                                        val = nil();
                                                                                                        args = val;
                                                                                                        val = new_symbol(-65);
                                                                                                        args = cons(val, args);
                                                                                                        increment_count(val = car(car(env)));
                                                                                                        args = cons(val, args);
                                                                                                        if ((is_binary(args)) &
                                                                                                            (is_atom(car(args))) &
                                                                                                            (is_atom(car(cdr(args)))) &
                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                          increment_count(val = true);
                                                                                                        } else { val = nil(); }
                                                                                                        pop_args();
                                                                                                        if (! is_nil(val)) {
                                                                                                          decrement_count(val);
                                                                                                          val = nil();
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
                                                                                                          args = nil();
                                                                                                          pop_args();
                                                                                                          goto pop_function;
                                                                                                        } else {
                                                                                                          push_args();
                                                                                                          val = nil();
                                                                                                          args = val;
                                                                                                          val = new_symbol(-64);
                                                                                                          args = cons(val, args);
                                                                                                          increment_count(val = car(car(env)));
                                                                                                          args = cons(val, args);
                                                                                                          if ((is_binary(args)) &
                                                                                                              (is_atom(car(args))) &
                                                                                                              (is_atom(car(cdr(args)))) &
                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                            increment_count(val = true);
                                                                                                          } else { val = nil(); }
                                                                                                          pop_args();
                                                                                                          if (! is_nil(val)) {
                                                                                                            decrement_count(val);
                                                                                                            val = nil();
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
                                                                                                            args = nil();
                                                                                                            pop_args();
                                                                                                            goto pop_function;
                                                                                                          } else {
                                                                                                            push_args();
                                                                                                            val = nil();
                                                                                                            args = val;
                                                                                                            val = new_symbol(-63);
                                                                                                            args = cons(val, args);
                                                                                                            increment_count(val = car(car(env)));
                                                                                                            args = cons(val, args);
                                                                                                            if ((is_binary(args)) &
                                                                                                                (is_atom(car(args))) &
                                                                                                                (is_atom(car(cdr(args)))) &
                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                              increment_count(val = true);
                                                                                                            } else { val = nil(); }
                                                                                                            pop_args();
                                                                                                            if (! is_nil(val)) {
                                                                                                              decrement_count(val);
                                                                                                              val = nil();
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
                                                                                                              args = nil();
                                                                                                              pop_args();
                                                                                                              goto pop_function;
                                                                                                            } else {
                                                                                                              push_args();
                                                                                                              val = nil();
                                                                                                              args = val;
                                                                                                              val = new_symbol(-62);
                                                                                                              args = cons(val, args);
                                                                                                              increment_count(val = car(car(env)));
                                                                                                              args = cons(val, args);
                                                                                                              if ((is_binary(args)) &
                                                                                                                  (is_atom(car(args))) &
                                                                                                                  (is_atom(car(cdr(args)))) &
                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                increment_count(val = true);
                                                                                                              } else { val = nil(); }
                                                                                                              pop_args();
                                                                                                              if (! is_nil(val)) {
                                                                                                                decrement_count(val);
                                                                                                                val = nil();
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
                                                                                                                args = nil();
                                                                                                                pop_args();
                                                                                                                goto pop_function;
                                                                                                              } else {
                                                                                                                push_args();
                                                                                                                val = nil();
                                                                                                                args = val;
                                                                                                                val = new_symbol(-61);
                                                                                                                args = cons(val, args);
                                                                                                                increment_count(val = car(car(env)));
                                                                                                                args = cons(val, args);
                                                                                                                if ((is_binary(args)) &
                                                                                                                    (is_atom(car(args))) &
                                                                                                                    (is_atom(car(cdr(args)))) &
                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                  increment_count(val = true);
                                                                                                                } else { val = nil(); }
                                                                                                                pop_args();
                                                                                                                if (! is_nil(val)) {
                                                                                                                  decrement_count(val);
                                                                                                                  val = nil();
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
                                                                                                                  args = nil();
                                                                                                                  pop_args();
                                                                                                                  goto pop_function;
                                                                                                                } else {
                                                                                                                  push_args();
                                                                                                                  val = nil();
                                                                                                                  args = val;
                                                                                                                  val = new_symbol(-60);
                                                                                                                  args = cons(val, args);
                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                  args = cons(val, args);
                                                                                                                  if ((is_binary(args)) &
                                                                                                                      (is_atom(car(args))) &
                                                                                                                      (is_atom(car(cdr(args)))) &
                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                    increment_count(val = true);
                                                                                                                  } else { val = nil(); }
                                                                                                                  pop_args();
                                                                                                                  if (! is_nil(val)) {
                                                                                                                    decrement_count(val);
                                                                                                                    val = nil();
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
                                                                                                                    args = nil();
                                                                                                                    pop_args();
                                                                                                                    goto pop_function;
                                                                                                                  } else {
                                                                                                                    push_args();
                                                                                                                    val = nil();
                                                                                                                    args = val;
                                                                                                                    val = new_symbol(-59);
                                                                                                                    args = cons(val, args);
                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                    args = cons(val, args);
                                                                                                                    if ((is_binary(args)) &
                                                                                                                        (is_atom(car(args))) &
                                                                                                                        (is_atom(car(cdr(args)))) &
                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                      increment_count(val = true);
                                                                                                                    } else { val = nil(); }
                                                                                                                    pop_args();
                                                                                                                    if (! is_nil(val)) {
                                                                                                                      decrement_count(val);
                                                                                                                      val = nil();
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
                                                                                                                      args = nil();
                                                                                                                      pop_args();
                                                                                                                      goto pop_function;
                                                                                                                    } else {
                                                                                                                      push_args();
                                                                                                                      val = nil();
                                                                                                                      args = val;
                                                                                                                      val = new_symbol(-58);
                                                                                                                      args = cons(val, args);
                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                      args = cons(val, args);
                                                                                                                      if ((is_binary(args)) &
                                                                                                                          (is_atom(car(args))) &
                                                                                                                          (is_atom(car(cdr(args)))) &
                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                        increment_count(val = true);
                                                                                                                      } else { val = nil(); }
                                                                                                                      pop_args();
                                                                                                                      if (! is_nil(val)) {
                                                                                                                        decrement_count(val);
                                                                                                                        val = nil();
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
                                                                                                                        args = nil();
                                                                                                                        pop_args();
                                                                                                                        goto pop_function;
                                                                                                                      } else {
                                                                                                                        push_args();
                                                                                                                        val = nil();
                                                                                                                        args = val;
                                                                                                                        val = new_symbol(-57);
                                                                                                                        args = cons(val, args);
                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                        args = cons(val, args);
                                                                                                                        if ((is_binary(args)) &
                                                                                                                            (is_atom(car(args))) &
                                                                                                                            (is_atom(car(cdr(args)))) &
                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                          increment_count(val = true);
                                                                                                                        } else { val = nil(); }
                                                                                                                        pop_args();
                                                                                                                        if (! is_nil(val)) {
                                                                                                                          decrement_count(val);
                                                                                                                          val = nil();
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
                                                                                                                          args = nil();
                                                                                                                          pop_args();
                                                                                                                          goto pop_function;
                                                                                                                        } else {
                                                                                                                          push_args();
                                                                                                                          val = nil();
                                                                                                                          args = val;
                                                                                                                          val = new_symbol(-56);
                                                                                                                          args = cons(val, args);
                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                          args = cons(val, args);
                                                                                                                          if ((is_binary(args)) &
                                                                                                                              (is_atom(car(args))) &
                                                                                                                              (is_atom(car(cdr(args)))) &
                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                            increment_count(val = true);
                                                                                                                          } else { val = nil(); }
                                                                                                                          pop_args();
                                                                                                                          if (! is_nil(val)) {
                                                                                                                            decrement_count(val);
                                                                                                                            val = nil();
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
                                                                                                                            args = nil();
                                                                                                                            pop_args();
                                                                                                                            goto pop_function;
                                                                                                                          } else {
                                                                                                                            push_args();
                                                                                                                            val = nil();
                                                                                                                            args = val;
                                                                                                                            val = new_symbol(-55);
                                                                                                                            args = cons(val, args);
                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                            args = cons(val, args);
                                                                                                                            if ((is_binary(args)) &
                                                                                                                                (is_atom(car(args))) &
                                                                                                                                (is_atom(car(cdr(args)))) &
                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                              increment_count(val = true);
                                                                                                                            } else { val = nil(); }
                                                                                                                            pop_args();
                                                                                                                            if (! is_nil(val)) {
                                                                                                                              decrement_count(val);
                                                                                                                              val = nil();
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
                                                                                                                              args = nil();
                                                                                                                              pop_args();
                                                                                                                              goto pop_function;
                                                                                                                            } else {
                                                                                                                              push_args();
                                                                                                                              val = nil();
                                                                                                                              args = val;
                                                                                                                              val = new_symbol(-54);
                                                                                                                              args = cons(val, args);
                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                              args = cons(val, args);
                                                                                                                              if ((is_binary(args)) &
                                                                                                                                  (is_atom(car(args))) &
                                                                                                                                  (is_atom(car(cdr(args)))) &
                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                increment_count(val = true);
                                                                                                                              } else { val = nil(); }
                                                                                                                              pop_args();
                                                                                                                              if (! is_nil(val)) {
                                                                                                                                decrement_count(val);
                                                                                                                                val = nil();
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
                                                                                                                                args = nil();
                                                                                                                                pop_args();
                                                                                                                                goto pop_function;
                                                                                                                              } else {
                                                                                                                                push_args();
                                                                                                                                val = nil();
                                                                                                                                args = val;
                                                                                                                                val = new_symbol(-53);
                                                                                                                                args = cons(val, args);
                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                args = cons(val, args);
                                                                                                                                if ((is_binary(args)) &
                                                                                                                                    (is_atom(car(args))) &
                                                                                                                                    (is_atom(car(cdr(args)))) &
                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                  increment_count(val = true);
                                                                                                                                } else { val = nil(); }
                                                                                                                                pop_args();
                                                                                                                                if (! is_nil(val)) {
                                                                                                                                  decrement_count(val);
                                                                                                                                  val = nil();
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
                                                                                                                                  args = nil();
                                                                                                                                  pop_args();
                                                                                                                                  goto pop_function;
                                                                                                                                } else {
                                                                                                                                  push_args();
                                                                                                                                  val = nil();
                                                                                                                                  args = val;
                                                                                                                                  val = new_symbol(-52);
                                                                                                                                  args = cons(val, args);
                                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                                  args = cons(val, args);
                                                                                                                                  if ((is_binary(args)) &
                                                                                                                                      (is_atom(car(args))) &
                                                                                                                                      (is_atom(car(cdr(args)))) &
                                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                                    increment_count(val = true);
                                                                                                                                  } else { val = nil(); }
                                                                                                                                  pop_args();
                                                                                                                                  if (! is_nil(val)) {
                                                                                                                                    decrement_count(val);
                                                                                                                                    val = nil();
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
                                                                                                                                    args = nil();
                                                                                                                                    pop_args();
                                                                                                                                    goto pop_function;
                                                                                                                                  } else {
                                                                                                                                    push_args();
                                                                                                                                    val = nil();
                                                                                                                                    args = val;
                                                                                                                                    val = new_symbol(-51);
                                                                                                                                    args = cons(val, args);
                                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                                    args = cons(val, args);
                                                                                                                                    if ((is_binary(args)) &
                                                                                                                                        (is_atom(car(args))) &
                                                                                                                                        (is_atom(car(cdr(args)))) &
                                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                                      increment_count(val = true);
                                                                                                                                    } else { val = nil(); }
                                                                                                                                    pop_args();
                                                                                                                                    if (! is_nil(val)) {
                                                                                                                                      decrement_count(val);
                                                                                                                                      val = nil();
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
                                                                                                                                      args = nil();
                                                                                                                                      pop_args();
                                                                                                                                      goto pop_function;
                                                                                                                                    } else {
                                                                                                                                      push_args();
                                                                                                                                      val = nil();
                                                                                                                                      args = val;
                                                                                                                                      val = new_symbol(-50);
                                                                                                                                      args = cons(val, args);
                                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                                      args = cons(val, args);
                                                                                                                                      if ((is_binary(args)) &
                                                                                                                                          (is_atom(car(args))) &
                                                                                                                                          (is_atom(car(cdr(args)))) &
                                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                                        increment_count(val = true);
                                                                                                                                      } else { val = nil(); }
                                                                                                                                      pop_args();
                                                                                                                                      if (! is_nil(val)) {
                                                                                                                                        decrement_count(val);
                                                                                                                                        val = nil();
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
                                                                                                                                        args = nil();
                                                                                                                                        pop_args();
                                                                                                                                        goto pop_function;
                                                                                                                                      } else {
                                                                                                                                        push_args();
                                                                                                                                        val = nil();
                                                                                                                                        args = val;
                                                                                                                                        val = new_symbol(-49);
                                                                                                                                        args = cons(val, args);
                                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                                        args = cons(val, args);
                                                                                                                                        if ((is_binary(args)) &
                                                                                                                                            (is_atom(car(args))) &
                                                                                                                                            (is_atom(car(cdr(args)))) &
                                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                                          increment_count(val = true);
                                                                                                                                        } else { val = nil(); }
                                                                                                                                        pop_args();
                                                                                                                                        if (! is_nil(val)) {
                                                                                                                                          decrement_count(val);
                                                                                                                                          val = nil();
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
                                                                                                                                          args = nil();
                                                                                                                                          pop_args();
                                                                                                                                          goto pop_function;
                                                                                                                                        } else {
                                                                                                                                          push_args();
                                                                                                                                          val = nil();
                                                                                                                                          args = val;
                                                                                                                                          val = new_symbol(-48);
                                                                                                                                          args = cons(val, args);
                                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                                          args = cons(val, args);
                                                                                                                                          if ((is_binary(args)) &
                                                                                                                                              (is_atom(car(args))) &
                                                                                                                                              (is_atom(car(cdr(args)))) &
                                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                                            increment_count(val = true);
                                                                                                                                          } else { val = nil(); }
                                                                                                                                          pop_args();
                                                                                                                                          if (! is_nil(val)) {
                                                                                                                                            decrement_count(val);
                                                                                                                                            val = nil();
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
                                                                                                                                            args = nil();
                                                                                                                                            pop_args();
                                                                                                                                            goto pop_function;
                                                                                                                                          } else {
                                                                                                                                            push_args();
                                                                                                                                            val = nil();
                                                                                                                                            args = val;
                                                                                                                                            val = new_symbol(-47);
                                                                                                                                            args = cons(val, args);
                                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                                            args = cons(val, args);
                                                                                                                                            if ((is_binary(args)) &
                                                                                                                                                (is_atom(car(args))) &
                                                                                                                                                (is_atom(car(cdr(args)))) &
                                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                                              increment_count(val = true);
                                                                                                                                            } else { val = nil(); }
                                                                                                                                            pop_args();
                                                                                                                                            if (! is_nil(val)) {
                                                                                                                                              decrement_count(val);
                                                                                                                                              val = nil();
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
                                                                                                                                              args = nil();
                                                                                                                                              pop_args();
                                                                                                                                              goto pop_function;
                                                                                                                                            } else {
                                                                                                                                              push_args();
                                                                                                                                              val = nil();
                                                                                                                                              args = val;
                                                                                                                                              val = new_symbol(-46);
                                                                                                                                              args = cons(val, args);
                                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                                              args = cons(val, args);
                                                                                                                                              if ((is_binary(args)) &
                                                                                                                                                  (is_atom(car(args))) &
                                                                                                                                                  (is_atom(car(cdr(args)))) &
                                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                                increment_count(val = true);
                                                                                                                                              } else { val = nil(); }
                                                                                                                                              pop_args();
                                                                                                                                              if (! is_nil(val)) {
                                                                                                                                                decrement_count(val);
                                                                                                                                                val = nil();
                                                                                                                                                push_args();
                                                                                                                                                args = val;
                                                                                                                                                val = new_number(121);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(114);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(97);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(114);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(98);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(105);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(108);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(45);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(100);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(114);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(97);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(100);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(110);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(97);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(116);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = new_number(115);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                val = args;
                                                                                                                                                args = nil();
                                                                                                                                                pop_args();
                                                                                                                                                goto pop_function;
                                                                                                                                              } else {
                                                                                                                                                push_args();
                                                                                                                                                val = nil();
                                                                                                                                                args = val;
                                                                                                                                                val = new_symbol(-45);
                                                                                                                                                args = cons(val, args);
                                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                                args = cons(val, args);
                                                                                                                                                if ((is_binary(args)) &
                                                                                                                                                    (is_atom(car(args))) &
                                                                                                                                                    (is_atom(car(cdr(args)))) &
                                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                                  increment_count(val = true);
                                                                                                                                                } else { val = nil(); }
                                                                                                                                                pop_args();
                                                                                                                                                if (! is_nil(val)) {
                                                                                                                                                  decrement_count(val);
                                                                                                                                                  val = nil();
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
                                                                                                                                                  args = nil();
                                                                                                                                                  pop_args();
                                                                                                                                                  goto pop_function;
                                                                                                                                                } else {
                                                                                                                                                  push_args();
                                                                                                                                                  val = nil();
                                                                                                                                                  args = val;
                                                                                                                                                  val = new_symbol(-44);
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                                                  args = cons(val, args);
                                                                                                                                                  if ((is_binary(args)) &
                                                                                                                                                      (is_atom(car(args))) &
                                                                                                                                                      (is_atom(car(cdr(args)))) &
                                                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                                                    increment_count(val = true);
                                                                                                                                                  } else { val = nil(); }
                                                                                                                                                  pop_args();
                                                                                                                                                  if (! is_nil(val)) {
                                                                                                                                                    decrement_count(val);
                                                                                                                                                    val = nil();
                                                                                                                                                    push_args();
                                                                                                                                                    args = val;
                                                                                                                                                    val = new_number(116);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    val = args;
                                                                                                                                                    args = nil();
                                                                                                                                                    pop_args();
                                                                                                                                                    goto pop_function;
                                                                                                                                                  } else {
                                                                                                                                                    push_args();
                                                                                                                                                    val = nil();
                                                                                                                                                    args = val;
                                                                                                                                                    val = new_symbol(-43);
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                                                    args = cons(val, args);
                                                                                                                                                    if ((is_binary(args)) &
                                                                                                                                                        (is_atom(car(args))) &
                                                                                                                                                        (is_atom(car(cdr(args)))) &
                                                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                                                      increment_count(val = true);
                                                                                                                                                    } else { val = nil(); }
                                                                                                                                                    pop_args();
                                                                                                                                                    if (! is_nil(val)) {
                                                                                                                                                      decrement_count(val);
                                                                                                                                                      val = nil();
                                                                                                                                                      push_args();
                                                                                                                                                      args = val;
                                                                                                                                                      val = new_number(102);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      val = new_number(105);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      val = args;
                                                                                                                                                      args = nil();
                                                                                                                                                      pop_args();
                                                                                                                                                      goto pop_function;
                                                                                                                                                    } else {
                                                                                                                                                      push_args();
                                                                                                                                                      val = nil();
                                                                                                                                                      args = val;
                                                                                                                                                      val = new_symbol(-42);
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      increment_count(val = car(car(env)));
                                                                                                                                                      args = cons(val, args);
                                                                                                                                                      if ((is_binary(args)) &
                                                                                                                                                          (is_atom(car(args))) &
                                                                                                                                                          (is_atom(car(cdr(args)))) &
                                                                                                                                                          eq(car(args), car(cdr(args)))) {
                                                                                                                                                        increment_count(val = true);
                                                                                                                                                      } else { val = nil(); }
                                                                                                                                                      pop_args();
                                                                                                                                                      if (! is_nil(val)) {
                                                                                                                                                        decrement_count(val);
                                                                                                                                                        val = nil();
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
                                                                                                                                                        args = nil();
                                                                                                                                                        pop_args();
                                                                                                                                                        goto pop_function;
                                                                                                                                                      } else {
                                                                                                                                                        push_args();
                                                                                                                                                        val = nil();
                                                                                                                                                        args = val;
                                                                                                                                                        val = new_symbol(-41);
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        increment_count(val = car(car(env)));
                                                                                                                                                        args = cons(val, args);
                                                                                                                                                        if ((is_binary(args)) &
                                                                                                                                                            (is_atom(car(args))) &
                                                                                                                                                            (is_atom(car(cdr(args)))) &
                                                                                                                                                            eq(car(args), car(cdr(args)))) {
                                                                                                                                                          increment_count(val = true);
                                                                                                                                                        } else { val = nil(); }
                                                                                                                                                        pop_args();
                                                                                                                                                        if (! is_nil(val)) {
                                                                                                                                                          decrement_count(val);
                                                                                                                                                          val = nil();
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
                                                                                                                                                          args = nil();
                                                                                                                                                          pop_args();
                                                                                                                                                          goto pop_function;
                                                                                                                                                        } else {
                                                                                                                                                          push_args();
                                                                                                                                                          val = nil();
                                                                                                                                                          args = val;
                                                                                                                                                          val = new_symbol(-40);
                                                                                                                                                          args = cons(val, args);
                                                                                                                                                          increment_count(val = car(car(env)));
                                                                                                                                                          args = cons(val, args);
                                                                                                                                                          if ((is_binary(args)) &
                                                                                                                                                              (is_atom(car(args))) &
                                                                                                                                                              (is_atom(car(cdr(args)))) &
                                                                                                                                                              eq(car(args), car(cdr(args)))) {
                                                                                                                                                            increment_count(val = true);
                                                                                                                                                          } else { val = nil(); }
                                                                                                                                                          pop_args();
                                                                                                                                                          if (! is_nil(val)) {
                                                                                                                                                            decrement_count(val);
                                                                                                                                                            val = nil();
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
                                                                                                                                                            args = nil();
                                                                                                                                                            pop_args();
                                                                                                                                                            goto pop_function;
                                                                                                                                                          } else {
                                                                                                                                                            push_args();
                                                                                                                                                            val = nil();
                                                                                                                                                            args = val;
                                                                                                                                                            val = new_symbol(-39);
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            increment_count(val = car(car(env)));
                                                                                                                                                            args = cons(val, args);
                                                                                                                                                            if ((is_binary(args)) &
                                                                                                                                                                (is_atom(car(args))) &
                                                                                                                                                                (is_atom(car(cdr(args)))) &
                                                                                                                                                                eq(car(args), car(cdr(args)))) {
                                                                                                                                                              increment_count(val = true);
                                                                                                                                                            } else { val = nil(); }
                                                                                                                                                            pop_args();
                                                                                                                                                            if (! is_nil(val)) {
                                                                                                                                                              decrement_count(val);
                                                                                                                                                              val = nil();
                                                                                                                                                              push_args();
                                                                                                                                                              args = val;
                                                                                                                                                              val = new_number(116);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(101);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = new_number(108);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              val = args;
                                                                                                                                                              args = nil();
                                                                                                                                                              pop_args();
                                                                                                                                                              goto pop_function;
                                                                                                                                                            } else {
                                                                                                                                                              push_args();
                                                                                                                                                              val = nil();
                                                                                                                                                              args = val;
                                                                                                                                                              val = new_symbol(-38);
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              increment_count(val = car(car(env)));
                                                                                                                                                              args = cons(val, args);
                                                                                                                                                              if ((is_binary(args)) &
                                                                                                                                                                  (is_atom(car(args))) &
                                                                                                                                                                  (is_atom(car(cdr(args)))) &
                                                                                                                                                                  eq(car(args), car(cdr(args)))) {
                                                                                                                                                                increment_count(val = true);
                                                                                                                                                              } else { val = nil(); }
                                                                                                                                                              pop_args();
                                                                                                                                                              if (! is_nil(val)) {
                                                                                                                                                                decrement_count(val);
                                                                                                                                                                val = nil();
                                                                                                                                                                push_args();
                                                                                                                                                                args = val;
                                                                                                                                                                val = new_number(110);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = new_number(102);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                val = args;
                                                                                                                                                                args = nil();
                                                                                                                                                                pop_args();
                                                                                                                                                                goto pop_function;
                                                                                                                                                              } else {
                                                                                                                                                                push_args();
                                                                                                                                                                val = nil();
                                                                                                                                                                args = val;
                                                                                                                                                                val = new_symbol(-37);
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                increment_count(val = car(car(env)));
                                                                                                                                                                args = cons(val, args);
                                                                                                                                                                if ((is_binary(args)) &
                                                                                                                                                                    (is_atom(car(args))) &
                                                                                                                                                                    (is_atom(car(cdr(args)))) &
                                                                                                                                                                    eq(car(args), car(cdr(args)))) {
                                                                                                                                                                  increment_count(val = true);
                                                                                                                                                                } else { val = nil(); }
                                                                                                                                                                pop_args();
                                                                                                                                                                if (! is_nil(val)) {
                                                                                                                                                                  decrement_count(val);
                                                                                                                                                                  val = nil();
                                                                                                                                                                  push_args();
                                                                                                                                                                  args = val;
                                                                                                                                                                  val = new_number(100);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(97);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(111);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = new_number(108);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  val = args;
                                                                                                                                                                  args = nil();
                                                                                                                                                                  pop_args();
                                                                                                                                                                  goto pop_function;
                                                                                                                                                                } else {
                                                                                                                                                                  push_args();
                                                                                                                                                                  val = nil();
                                                                                                                                                                  args = val;
                                                                                                                                                                  val = new_symbol(-36);
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  increment_count(val = car(car(env)));
                                                                                                                                                                  args = cons(val, args);
                                                                                                                                                                  if ((is_binary(args)) &
                                                                                                                                                                      (is_atom(car(args))) &
                                                                                                                                                                      (is_atom(car(cdr(args)))) &
                                                                                                                                                                      eq(car(args), car(cdr(args)))) {
                                                                                                                                                                    increment_count(val = true);
                                                                                                                                                                  } else { val = nil(); }
                                                                                                                                                                  pop_args();
                                                                                                                                                                  if (! is_nil(val)) {
                                                                                                                                                                    decrement_count(val);
                                                                                                                                                                    val = nil();
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
                                                                                                                                                                    args = nil();
                                                                                                                                                                    pop_args();
                                                                                                                                                                    goto pop_function;
                                                                                                                                                                  } else {
                                                                                                                                                                    push_args();
                                                                                                                                                                    val = nil();
                                                                                                                                                                    args = val;
                                                                                                                                                                    val = new_symbol(-35);
                                                                                                                                                                    args = cons(val, args);
                                                                                                                                                                    increment_count(val = car(car(env)));
                                                                                                                                                                    args = cons(val, args);
                                                                                                                                                                    if ((is_binary(args)) &
                                                                                                                                                                        (is_atom(car(args))) &
                                                                                                                                                                        (is_atom(car(cdr(args)))) &
                                                                                                                                                                        eq(car(args), car(cdr(args)))) {
                                                                                                                                                                      increment_count(val = true);
                                                                                                                                                                    } else { val = nil(); }
                                                                                                                                                                    pop_args();
                                                                                                                                                                    if (! is_nil(val)) {
                                                                                                                                                                      decrement_count(val);
                                                                                                                                                                      val = nil();
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
                                                                                                                                                                      args = nil();
                                                                                                                                                                      pop_args();
                                                                                                                                                                      goto pop_function;
                                                                                                                                                                    } else {
                                                                                                                                                                      val = nil();
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
            }
          }
        }
      }
    }
  }
/* symbol->string */
body_1:
  increment_count(env);
  val = wrap_function((&&function_3), env);
  global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* symbol->string */
  goto body_2;
pointer global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_4:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-35);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = new_symbol(-34);
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    goto pop_function;
  }
function_5:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-36);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_4);
    goto apply_addr;
  }
function_6:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-37);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_5);
    goto apply_addr;
  }
function_7:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-38);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_6);
    goto apply_addr;
  }
function_8:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-39);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(110);
    args = cons(val, args);
    val = new_number(102);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_7);
    goto apply_addr;
  }
function_9:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-40);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_8);
    goto apply_addr;
  }
function_10:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-41);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_9);
    goto apply_addr;
  }
function_11:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-42);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_10);
    goto apply_addr;
  }
function_12:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-43);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_11);
    goto apply_addr;
  }
function_13:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-44);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(102);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_12);
    goto apply_addr;
  }
function_14:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-45);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-46);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_14);
    goto apply_addr;
  }
function_16:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-47);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(121);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(98);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-48);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_16);
    goto apply_addr;
  }
function_18:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-49);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-50);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-51);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-52);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-53);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-54);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_22);
    goto apply_addr;
  }
function_24:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-55);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-56);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-57);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-58);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-59);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-60);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-61);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-62);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-63);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-64);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-65);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-66);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_34);
    goto apply_addr;
  }
function_36:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-67);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_35);
    goto apply_addr;
  }
function_37:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-68);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_36);
    goto apply_addr;
  }
function_38:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-69);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_37);
    goto apply_addr;
  }
function_39:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-70);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_38);
    goto apply_addr;
  }
function_40:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-71);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_39);
    goto apply_addr;
  }
function_41:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-72);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_40);
    goto apply_addr;
  }
function_42:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-73);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_41);
    goto apply_addr;
  }
function_43:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-74);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_42);
    goto apply_addr;
  }
function_44:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-75);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_43);
    goto apply_addr;
  }
function_45:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-76);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_44);
    goto apply_addr;
  }
function_46:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-77);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_45);
    goto apply_addr;
  }
function_47:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-78);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_46);
    goto apply_addr;
  }
function_48:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-79);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(101);
    args = cons(val, args);
    val = new_number(115);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = new_number(101);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_47);
    goto apply_addr;
  }
function_49:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-80);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_48);
    goto apply_addr;
  }
function_50:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-81);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_49);
    goto apply_addr;
  }
function_51:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-82);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_50);
    goto apply_addr;
  }
function_52:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-83);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_51);
    goto apply_addr;
  }
function_53:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-84);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_52);
    goto apply_addr;
  }
function_54:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-85);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(112);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_53);
    goto apply_addr;
  }
function_55:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-86);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_54);
    goto apply_addr;
  }
function_56:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-87);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_55);
    goto apply_addr;
  }
function_57:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-88);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(116);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_56);
    goto apply_addr;
  }
function_58:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-89);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_57);
    goto apply_addr;
  }
function_59:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-90);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_58);
    goto apply_addr;
  }
function_60:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-91);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_59);
    goto apply_addr;
  }
function_61:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-92);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_60);
    goto apply_addr;
  }
function_62:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-93);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_61);
    goto apply_addr;
  }
function_63:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-94);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_62);
    goto apply_addr;
  }
function_64:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-95);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
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
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_63);
    goto apply_addr;
  }
function_65:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-96);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(63);
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
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_64);
    goto apply_addr;
  }
function_66:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-97);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(63);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_65);
    goto apply_addr;
  }
function_67:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-98);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(63);
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
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_66);
    goto apply_addr;
  }
function_68:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-99);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(63);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(108);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_67);
    goto apply_addr;
  }
function_69:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-100);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(60);
    args = cons(val, args);
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_68);
    goto apply_addr;
  }
function_70:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-101);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_69);
    goto apply_addr;
  }
function_71:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-102);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_70);
    goto apply_addr;
  }
function_72:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-103);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(94);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_71);
    goto apply_addr;
  }
function_73:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-104);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(124);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_72);
    goto apply_addr;
  }
function_74:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-105);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(38);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_73);
    goto apply_addr;
  }
function_75:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-106);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(126);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_74);
    goto apply_addr;
  }
function_76:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-107);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(37);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_75);
    goto apply_addr;
  }
function_77:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-108);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_76);
    goto apply_addr;
  }
function_78:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-109);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(42);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_77);
    goto apply_addr;
  }
function_79:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-110);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(45);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_78);
    goto apply_addr;
  }
function_80:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-111);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(43);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_79);
    goto apply_addr;
  }
function_81:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-112);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_80);
    goto apply_addr;
  }
function_82:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-113);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_81);
    goto apply_addr;
  }
function_83:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-114);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(61);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_82);
    goto apply_addr;
  }
function_84:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-115);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = nil();
    push_args();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    target = (&&function_83);
    goto apply_addr;
  }
function_85:
  push_args();
  val = nil();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c101c113c117c97c108 /* equal */);
  target = (&&function_84);
  goto apply_addr;
/* string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_85), env);
  global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_86:
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    if (is_number(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      val = nil();
      goto pop_function;
    } else {
      if (is_function(car(car(env)))) {
        increment_count(val = true);
      } else {
        val = nil();
      }
      if (! is_nil(val)) {
        decrement_count(val);
        val = nil();
        goto pop_function;
      } else {
        if (is_pair(car(car(env)))) {
          increment_count(val = true);
        } else {
          val = nil();
        }
        if (! is_nil(val)) {
          decrement_count(val);
          push_args();
          val = nil();
          args = val;
          val = new_symbol(-34);
          args = cons(val, args);
          increment_count(val = car(car(car(env))));
          args = cons(val, args);
          if ((is_binary(args)) &
              (is_atom(car(args))) &
              (is_atom(car(cdr(args)))) &
              eq(car(args), car(cdr(args)))) {
            increment_count(val = true);
          } else { val = nil(); }
          pop_args();
          if (! is_nil(val)) {
            decrement_count(val);
            val = new_symbol(-44);
            goto pop_function;
          } else {
            val = nil();
            goto pop_function;
          }
        } else {
          val = new_symbol(-44);
          goto pop_function;
        }
      }
    }
  }
/* __symbol? */
body_3:
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c95c115c121c109c98c111c108c63 = val; /* __symbol? */
  goto body_4;
pointer global_c95c95c112c97c105c114c63;
function_87:
  if (is_pair(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-34);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_atom(car(args))) &
        (is_atom(car(cdr(args)))) &
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
    pop_args();
    if (! is_nil(val)) {
      decrement_count(val);
      val = nil();
      goto pop_function;
    } else {
      val = new_symbol(-44);
      goto pop_function;
    }
  } else {
    val = nil();
    goto pop_function;
  }
/* __pair? */
body_4:
  increment_count(env);
  val = wrap_function((&&function_87), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c61;
function_88:
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c113c117c97c108 /* equal */);
    goto top_level_apply;
  }
function_89:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_88);
  goto apply_addr;
/* __= */
body_5:
  increment_count(env);
  val = wrap_function((&&function_89), env);
  global_c95c95c61 = val; /* __= */
  goto body_6;
pointer global_c95c95c95c95c108c51;
/* ____l3 */
body_6:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c51 = val; /* ____l3 */
  goto body_7;
pointer global_c105c100;
function_90:
  increment_count(val = car(car(env)));
  goto pop_function;
/* id */
body_7:
  increment_count(env);
  val = wrap_function((&&function_90), env);
  global_c105c100 = val; /* id */
  goto body_8;
pointer global_c95c95c95c119c97c108c107; /* ___walk */
pointer global_c95c102c110c48;
function_91:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_92:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_91);
  goto apply_addr;
function_93:
  target = (&&function_92);
  goto apply_addr;
function_94:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c95c95c119c97c108c107 /* ___walk */);
  target = (&&function_93);
  goto apply_addr;
function_95:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    target = (&&function_94);
    goto apply_addr;
  }
function_96:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_95);
  goto apply_addr;
function_97:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  goto pop_function;
/* _fn0 */
body_8:
global_c95c95c95c119c97c108c107 = nil(); /* ___walk */
  increment_count(env);
  val = wrap_function((&&function_97), env);
  global_c95c102c110c48 = val; /* _fn0 */
  goto body_9;
function_98:
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c48 /* _fn0 */);
  goto top_level_apply;
/* ___walk */
body_9:
  increment_count(env);
  val = wrap_function((&&function_98), env);
  global_c95c95c95c119c97c108c107 = val; /* ___walk */
  goto body_10;
pointer global_c95c95c95c114c114c101c118c101c114c115c101;
function_99:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101 /* ___rreverse */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
  }
function_100:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_99);
  goto apply_addr;
/* ___rreverse */
body_10:
  increment_count(env);
  val = wrap_function((&&function_100), env);
  global_c95c95c95c114c114c101c118c101c114c115c101 = val; /* ___rreverse */
  goto body_11;
pointer global_c102c111c108c100c108; /* foldl */
pointer global_c95c102c110c49;
function_101:
  goto top_level_apply;
function_102:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c108 /* foldl */);
  target = (&&function_101);
  goto apply_addr;
function_103:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    target = (&&function_102);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
  }
function_104:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_103);
  goto apply_addr;
function_105:
  increment_count(env);
  val = wrap_function((&&function_104), env);
  goto pop_function;
/* _fn1 */
body_11:
global_c102c111c108c100c108 = nil(); /* foldl */
  increment_count(env);
  val = wrap_function((&&function_105), env);
  global_c95c102c110c49 = val; /* _fn1 */
  goto body_12;
function_106:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49 /* _fn1 */);
  goto top_level_apply;
/* foldl */
body_12:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  global_c102c111c108c100c108 = val; /* foldl */
  goto body_13;
pointer global_c95c102c110c50;
function_107:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101 /* ___rreverse */);
  goto top_level_apply;
function_108:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c108 /* foldl */);
  target = (&&function_107);
  goto apply_addr;
function_109:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  goto pop_function;
/* _fn2 */
body_13:
  increment_count(env);
  val = wrap_function((&&function_109), env);
  global_c95c102c110c50 = val; /* _fn2 */
  goto body_14;
pointer global_c102c111c108c100c114;
function_110:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50 /* _fn2 */);
  goto top_level_apply;
/* foldr */
body_14:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  global_c102c111c108c100c114 = val; /* foldr */
  goto body_15;
pointer global_c95c102c110c51;
function_111:
  goto top_level_apply;
function_112:
  push_args();
  increment_count(val = car(env));
  args = val;
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_113:
  if (is_nil(car(cdr(car(env))))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(env);
    val = wrap_function((&&function_112), env);
    args = cons(val, args);
    increment_count(val = global_c102c111c108c100c114 /* foldr */);
    target = (&&function_111);
    goto apply_addr;
  }
/* _fn3 */
body_15:
  increment_count(env);
  val = wrap_function((&&function_113), env);
  global_c95c102c110c51 = val; /* _fn3 */
  goto body_16;
pointer global_c97c112c112c101c110c100;
function_114:
  goto top_level_apply;
function_115:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51 /* _fn3 */);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_114);
  goto apply_addr;
/* append */
body_16:
  increment_count(env);
  val = wrap_function((&&function_115), env);
  global_c97c112c112c101c110c100 = val; /* append */
  goto body_17;
pointer global_c95c102c110c52;
function_116:
  push_args();
  val = nil();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    if (value(car(cdr(args))) == 0) {
      val = nil();
    } else {
      val = new_number(value(car(args)) %
                       value(car(cdr(args))));
    }
  } else { val = nil(); }
  pop_args();
  goto pop_function;
/* _fn4 */
body_17:
  increment_count(env);
  val = wrap_function((&&function_116), env);
  global_c95c102c110c52 = val; /* _fn4 */
  goto body_18;
pointer global_c95c102c110c53;
function_117:
  push_args();
  val = nil();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    if (value(car(cdr(args))) == 0) {
      val = nil();
    } else {
      val = new_number(value(car(args)) / 
                       value(car(cdr(args))));
    }
  } else { val = nil(); }
  pop_args();
  goto pop_function;
/* _fn5 */
body_18:
  increment_count(env);
  val = wrap_function((&&function_117), env);
  global_c95c102c110c53 = val; /* _fn5 */
  goto body_19;
pointer global_c95c102c110c54;
function_118:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
/* _fn6 */
body_19:
  increment_count(env);
  val = wrap_function((&&function_118), env);
  global_c95c102c110c54 = val; /* _fn6 */
  goto body_20;
pointer global_c95c102c110c55; /* _fn7 */
pointer global_c95c102c110c56;
function_119:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55 /* _fn7 */);
  goto top_level_apply;
/* _fn8 */
body_20:
global_c95c102c110c55 = nil(); /* _fn7 */
  increment_count(env);
  val = wrap_function((&&function_119), env);
  global_c95c102c110c56 = val; /* _fn8 */
  goto body_21;
function_120:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_121:
  increment_count(env);
  val = wrap_function((&&function_120), env);
  goto pop_function;
/* _fn7 */
body_21:
  increment_count(env);
  val = wrap_function((&&function_121), env);
  global_c95c102c110c55 = val; /* _fn7 */
  goto body_22;
pointer global_c95c102c110c57;
function_122:
  increment_count(val = global_c105c100 /* id */);
  goto pop_function;
/* _fn9 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_122), env);
  global_c95c102c110c57 = val; /* _fn9 */
  goto body_23;
pointer global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_123:
  goto top_level_apply;
function_124:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c102c110c57 /* _fn9 */);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c56 /* _fn8 */);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54 /* _fn6 */);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53 /* _fn5 */);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52 /* _fn4 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c119c97c108c107 /* ___walk */);
  target = (&&function_123);
  goto apply_addr;
/* ___build-num-str */
body_23:
  increment_count(env);
  val = wrap_function((&&function_124), env);
  global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* ___build-num-str */
  goto body_24;
pointer global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103;
function_125:
  args = cons(val, args);
  val = new_number(45);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_126:
  target = (&&function_125);
  goto apply_addr;
function_127:
  goto top_level_apply;
function_128:
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    push_args();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    if (! is_nil(val)) {
      decrement_count(val);
      push_args();
      val = nil();
      args = val;
      push_args();
      val = nil();
      args = val;
      val = nil();
      args = cons(val, args);
      push_args();
      val = nil();
      args = val;
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if (is_number(car(args))) {
        if ((is_binary(args)) &
            is_number(car(cdr(args)))) {
          val = new_number(value(car(args)) - 
                           value(car(cdr(args))));
        } else if (is_unary(args) == 1) {
          val = new_number(-value(car(args)));
        } else { val = nil(); }
      } else { val = nil(); }
      pop_args();
      args = cons(val, args);
      increment_count(val = global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 /* ___build-num-str */);
      target = (&&function_126);
      goto apply_addr;
    } else {
      push_args();
      val = nil();
      args = val;
      val = nil();
      args = cons(val, args);
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 /* ___build-num-str */);
      target = (&&function_127);
      goto apply_addr;
    }
  }
function_129:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_128);
  goto apply_addr;
/* number->string */
body_24:
  increment_count(env);
  val = wrap_function((&&function_129), env);
  global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103 = val; /* number->string */
  goto body_25;
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* ___print-with-suffix */
pointer global_c95c95c95c112c114c105c110c116c45c116c97c105c108;
function_130:
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_131:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_130);
  goto apply_addr;
function_132:
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(46);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_133:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_132);
  goto apply_addr;
function_134:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c116c97c105c108 /* ___print-tail */);
    target = (&&function_131);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    val = nil();
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c112c112c101c110c100 /* append */);
    target = (&&function_133);
    goto apply_addr;
  }
function_135:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_134);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    val = nil();
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c112c112c101c110c100 /* append */);
    goto top_level_apply;
  }
/* ___print-tail */
body_25:
global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = nil(); /* ___print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c95c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* ___print-tail */
  goto body_26;
pointer global_c112c114c105c110c116; /* print */
function_136:
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_137:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_136);
  goto apply_addr;
function_138:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_139:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c116c97c105c108 /* ___print-tail */);
    target = (&&function_137);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_138);
    goto apply_addr;
  }
function_140:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_139);
  goto apply_addr;
/* ___print-with-suffix */
body_26:
global_c112c114c105c110c116 = nil(); /* print */
  increment_count(env);
  val = wrap_function((&&function_140), env);
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* ___print-with-suffix */
  goto body_27;
function_141:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
    goto top_level_apply;
  } else {
    if (is_function(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      val = nil();
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
      args = nil();
      pop_args();
      goto pop_function;
    } else {
      val = nil();
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
      args = nil();
      pop_args();
      goto pop_function;
    }
  }
function_142:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* symbol->string */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_141);
    goto apply_addr;
  }
function_143:
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    push_args();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    val = new_number(40);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    goto pop_function;
  } else {
    if (is_number(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103 /* number->string */);
      goto top_level_apply;
    } else {
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
      target = (&&function_142);
      goto apply_addr;
    }
  }
/* print */
body_27:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  global_c112c114c105c110c116 = val; /* print */
  goto body_28;
pointer global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
function_144:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_145:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c51 /* ____l3 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_144);
  goto apply_addr;
/* print-with-newline */
body_28:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* print-with-newline */
  goto body_29;
pointer global_c108c105c115c116;
function_146:
  increment_count(val = car(env));
  goto pop_function;
/* list */
body_29:
  increment_count(env);
  val = wrap_function((&&function_146), env);
  global_c108c105c115c116 = val; /* list */
  goto body_30;
pointer global_c115c101c110c100c45c116c111c45c112c97c114c101c110c116;
function_147:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_148:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_147);
  goto apply_addr;
/* send-to-parent */
body_30:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  global_c115c101c110c100c45c116c111c45c112c97c114c101c110c116 = val; /* send-to-parent */
  goto body_31;
pointer global_c111c112c101c110c45c102c105c108c101;
function_149:
  args = cons(val, args);
  increment_count(val = global_c115c101c110c100c45c116c111c45c112c97c114c101c110c116 /* send-to-parent */);
  goto top_level_apply;
function_150:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_149);
  goto apply_addr;
/* open-file */
body_31:
  increment_count(env);
  val = wrap_function((&&function_150), env);
  global_c111c112c101c110c45c102c105c108c101 = val; /* open-file */
  goto body_32;
pointer global_c114c101c97c100c45c102c114c111c109c45c102c105c108c101;
function_151:
  args = cons(val, args);
  increment_count(val = global_c115c101c110c100c45c116c111c45c112c97c114c101c110c116 /* send-to-parent */);
  goto top_level_apply;
function_152:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(100);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_151);
  goto apply_addr;
/* read-from-file */
body_32:
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c114c101c97c100c45c102c114c111c109c45c102c105c108c101 = val; /* read-from-file */
  goto body_33;
pointer global_c99c108c111c115c101c45c102c105c108c101;
function_153:
  args = cons(val, args);
  increment_count(val = global_c115c101c110c100c45c116c111c45c112c97c114c101c110c116 /* send-to-parent */);
  goto top_level_apply;
function_154:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_153);
  goto apply_addr;
/* close-file */
body_33:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c99c108c111c115c101c45c102c105c108c101 = val; /* close-file */
  goto body_34;
pointer global_c95c95c95c95c108c52;
/* ____l4 */
body_34:
  val = nil();
  push_args();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c52 = val; /* ____l4 */
  goto body_35;
pointer global_c114c101c118c101c114c115c101;
function_155:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c105c100 /* id */);
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101 /* ___rreverse */);
  goto top_level_apply;
/* reverse */
body_35:
  increment_count(env);
  val = wrap_function((&&function_155), env);
  global_c114c101c118c101c114c115c101 = val; /* reverse */
  goto body_36;
pointer global_c95c102c110c49c50; /* _fn12 */
pointer global_c114c101c97c100c45c99c111c110c116c101c110c116c115; /* read-contents */
pointer global_c95c102c110c49c51;
function_156:
  goto top_level_apply;
function_157:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c97c100c45c99c111c110c116c101c110c116c115 /* read-contents */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52 /* ____l4 */);
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c49c50 /* _fn12 */);
    target = (&&function_156);
    goto apply_addr;
  }
function_158:
  increment_count(env);
  val = wrap_function((&&function_157), env);
  goto pop_function;
/* _fn13 */
body_36:
global_c95c102c110c49c50 = nil(); /* _fn12 */
global_c114c101c97c100c45c99c111c110c116c101c110c116c115 = nil(); /* read-contents */
  increment_count(env);
  val = wrap_function((&&function_158), env);
  global_c95c102c110c49c51 = val; /* _fn13 */
  goto body_37;
pointer global_c95c102c110c49c49; /* _fn11 */
function_159:
  goto top_level_apply;
function_160:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c49 /* _fn11 */);
  target = (&&function_159);
  goto apply_addr;
function_161:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
  target = (&&function_160);
  goto apply_addr;
function_162:
  increment_count(env);
  val = wrap_function((&&function_161), env);
  goto pop_function;
/* _fn12 */
body_37:
global_c95c102c110c49c49 = nil(); /* _fn11 */
  increment_count(env);
  val = wrap_function((&&function_162), env);
  global_c95c102c110c49c50 = val; /* _fn12 */
  goto body_38;
pointer global_c95c102c110c49c48; /* _fn10 */
function_163:
  goto top_level_apply;
function_164:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c48 /* _fn10 */);
  target = (&&function_163);
  goto apply_addr;
function_165:
  push_args();
  val = nil();
  args = val;
  push_args();
  increment_count(val = car(car(env)));
  args = val;
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_164);
  goto apply_addr;
function_166:
  increment_count(env);
  val = wrap_function((&&function_165), env);
  goto pop_function;
/* _fn11 */
body_38:
global_c95c102c110c49c48 = nil(); /* _fn10 */
  increment_count(env);
  val = wrap_function((&&function_166), env);
  global_c95c102c110c49c49 = val; /* _fn11 */
  goto body_39;
function_167:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_168:
  increment_count(env);
  val = wrap_function((&&function_167), env);
  goto pop_function;
/* _fn10 */
body_39:
  increment_count(env);
  val = wrap_function((&&function_168), env);
  global_c95c102c110c49c48 = val; /* _fn10 */
  goto body_40;
function_169:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c102c114c111c109c45c102c105c108c101 /* read-from-file */);
  goto top_level_apply;
function_170:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c51 /* _fn13 */);
  target = (&&function_169);
  goto apply_addr;
/* read-contents */
body_40:
  increment_count(env);
  val = wrap_function((&&function_170), env);
  global_c114c101c97c100c45c99c111c110c116c101c110c116c115 = val; /* read-contents */
  goto body_41;
pointer global_c95c95c95c95c108c53;
/* ____l5 */
body_41:
  val = nil();
  push_args();
  args = val;
  val = new_number(114);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c53 = val; /* ____l5 */
  goto body_42;
pointer global_c95c95c95c95c108c54;
/* ____l6 */
body_42:
  val = nil();
  global_c95c95c95c95c108c54 = val; /* ____l6 */
  goto body_43;
pointer global_c95c102c110c49c52; /* _fn14 */
pointer global_c95c102c110c49c53;
function_171:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54 /* ____l6 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c99c111c110c116c101c110c116c115 /* read-contents */);
  goto top_level_apply;
function_172:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c52 /* _fn14 */);
  target = (&&function_171);
  goto apply_addr;
function_173:
  increment_count(env);
  val = wrap_function((&&function_172), env);
  goto pop_function;
/* _fn15 */
body_43:
global_c95c102c110c49c52 = nil(); /* _fn14 */
  increment_count(env);
  val = wrap_function((&&function_173), env);
  global_c95c102c110c49c53 = val; /* _fn15 */
  goto body_44;
function_174:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c99c108c111c115c101c45c102c105c108c101 /* close-file */);
  goto top_level_apply;
function_175:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_174);
  goto apply_addr;
function_176:
  increment_count(env);
  val = wrap_function((&&function_175), env);
  goto pop_function;
/* _fn14 */
body_44:
  increment_count(env);
  val = wrap_function((&&function_176), env);
  global_c95c102c110c49c52 = val; /* _fn14 */
  goto body_45;
pointer global_c119c105c116c104c45c102c105c108c101c45c99c111c110c116c101c110c116c115;
function_177:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_178:
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_177);
  goto apply_addr;
function_179:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c53 /* ____l5 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_178);
  goto apply_addr;
function_180:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c53 /* _fn15 */);
  target = (&&function_179);
  goto apply_addr;
/* with-file-contents */
body_45:
  increment_count(env);
  val = wrap_function((&&function_180), env);
  global_c119c105c116c104c45c102c105c108c101c45c99c111c110c116c101c110c116c115 = val; /* with-file-contents */
  goto body_46;
pointer global_c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_181:
  global_c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* map-to-stderr */
  goto body_47;
function_182:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_183:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_number(2);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_182);
  goto apply_addr;
/* map-to-stderr */
body_46:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_183), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_181);
  goto apply_addr;
pointer global_c95c95c95c95c108c55;
/* ____l7 */
body_47:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55 = val; /* ____l7 */
  goto body_48;
pointer global_c95c95c95c95c108c56;
/* ____l8 */
body_48:
  val = nil();
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56 = val; /* ____l8 */
  goto body_49;
pointer global_c95c95c95c95c108c57;
/* ____l9 */
body_49:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(44);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c57 = val; /* ____l9 */
  goto body_50;
pointer global_c95c95c95c95c108c49c48;
/* ____l10 */
body_50:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(73);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c48 = val; /* ____l10 */
  goto body_51;
pointer global_c95c95c95c95c108c49c49;
/* ____l11 */
body_51:
  val = nil();
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
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c49 = val; /* ____l11 */
  goto body_52;
pointer global_c95c95c95c95c108c49c50;
/* ____l12 */
body_52:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c50 = val; /* ____l12 */
  goto body_53;
pointer global_c95c95c95c95c108c49c51;
/* ____l13 */
body_53:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c51 = val; /* ____l13 */
  goto body_54;
pointer global_c95c95c95c95c108c49c52;
/* ____l14 */
body_54:
  val = nil();
  global_c95c95c95c95c108c49c52 = val; /* ____l14 */
  goto body_55;
pointer global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_184:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_185:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55 /* ____l7 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_184);
  goto apply_addr;
function_186:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49c49 /* ____l11 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c57 /* ____l9 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c56 /* ____l8 */);
    args = cons(val, args);
    increment_count(val = global_c97c112c112c101c110c100 /* append */);
    target = (&&function_185);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c95c108c49c48 /* ____l10 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c55 /* ____l7 */);
    args = cons(val, args);
    increment_count(val = global_c97c112c112c101c110c100 /* append */);
    target = (&&function_184);
    goto apply_addr;
  }
function_187:
  increment_count(val = car(cdr(cdr(car(env)))));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c49c51 /* ____l13 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c50 /* ____l12 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_186);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c95c108c49c52 /* ____l14 */);
    goto pop_function;
  }
/* print-warnings */
body_55:
  increment_count(env);
  val = wrap_function((&&function_187), env);
  global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* print-warnings */
  goto body_56;
pointer global_c95c95c95c95c108c49c53;
/* ____l15 */
body_56:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c53 = val; /* ____l15 */
  goto body_57;
pointer global_c95c95c95c95c108c49c54;
/* ____l16 */
body_57:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c54 = val; /* ____l16 */
  goto body_58;
pointer global_c112c114c105c110c116c45c101c114c114c111c114;
function_188:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_189:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c49c54 /* ____l16 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49c53 /* ____l15 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_188);
  goto apply_addr;
/* print-error */
body_58:
  increment_count(env);
  val = wrap_function((&&function_189), env);
  global_c112c114c105c110c116c45c101c114c114c111c114 = val; /* print-error */
  goto body_59;
pointer global_c95c95c95c95c108c49c55;
/* ____l17 */
body_59:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-38);
  args = cons(val, args);
  val = new_symbol(-40);
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c55 = val; /* ____l17 */
  goto body_60;
pointer global_c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* special-forms */
body_60:
  increment_count(val = global_c95c95c95c95c108c49c55 /* ____l17 */);
  global_c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* special-forms */
  goto body_61;
pointer global_c95c95c95c95c108c49c56;
/* ____l18 */
body_61:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-92);
  args = cons(val, args);
  val = new_symbol(-93);
  args = cons(val, args);
  val = new_symbol(-94);
  args = cons(val, args);
  val = new_symbol(-95);
  args = cons(val, args);
  val = new_symbol(-96);
  args = cons(val, args);
  val = new_symbol(-97);
  args = cons(val, args);
  val = new_symbol(-98);
  args = cons(val, args);
  val = new_symbol(-99);
  args = cons(val, args);
  val = new_symbol(-100);
  args = cons(val, args);
  val = new_symbol(-101);
  args = cons(val, args);
  val = new_symbol(-102);
  args = cons(val, args);
  val = new_symbol(-103);
  args = cons(val, args);
  val = new_symbol(-104);
  args = cons(val, args);
  val = new_symbol(-105);
  args = cons(val, args);
  val = new_symbol(-106);
  args = cons(val, args);
  val = new_symbol(-107);
  args = cons(val, args);
  val = new_symbol(-108);
  args = cons(val, args);
  val = new_symbol(-109);
  args = cons(val, args);
  val = new_symbol(-110);
  args = cons(val, args);
  val = new_symbol(-111);
  args = cons(val, args);
  val = new_symbol(-112);
  args = cons(val, args);
  val = new_symbol(-113);
  args = cons(val, args);
  val = new_symbol(-114);
  args = cons(val, args);
  val = new_symbol(-115);
  args = cons(val, args);
  val = new_symbol(-45);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c56 = val; /* ____l18 */
  goto body_62;
pointer global_c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* supported-builtins */
body_62:
  increment_count(val = global_c95c95c95c95c108c49c56 /* ____l18 */);
  global_c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* supported-builtins */
  goto body_63;
pointer global_c102c108c97c116c116c101c110;
function_190:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  goto top_level_apply;
function_191:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    goto pop_function;
  } else {
    if (is_number(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(cdr(car(env))));
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      if (is_binary(args)) {
        increment_count(car(args));
        increment_count(car(cdr(args)));
        val = cons(car(args), car(cdr(args)));
      } else { val = nil(); }
      pop_args();
      goto pop_function;
    } else {
      push_args();
      val = nil();
      args = val;
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(cdr(car(env))));
      args = cons(val, args);
      increment_count(val = cdr(car(car(env))));
      args = cons(val, args);
      increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
      target = (&&function_190);
      goto apply_addr;
    }
  }
function_192:
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_191);
    goto apply_addr;
  }
/* flatten */
body_63:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  global_c102c108c97c116c116c101c110 = val; /* flatten */
  goto body_64;
pointer global_c95c102c110c49c54;
function_193:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = new_number(95);
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
    goto top_level_apply;
  } else {
    increment_count(val = car(car(cdr(env))));
    goto pop_function;
  }
function_194:
  push_args();
  val = nil();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_193);
  goto apply_addr;
function_195:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  goto pop_function;
/* _fn16 */
body_64:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c95c102c110c49c54 = val; /* _fn16 */
  goto body_65;
pointer global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_196:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_197:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_196);
  goto apply_addr;
function_198:
  goto top_level_apply;
function_199:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c54 /* _fn16 */);
  target = (&&function_198);
  goto apply_addr;
function_200:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* symbol->string */);
    target = (&&function_199);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_201:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
    target = (&&function_197);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_200);
    goto apply_addr;
  }
function_202:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_201);
  goto apply_addr;
/* escape-symbols */
body_65:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* escape-symbols */
  goto body_66;
pointer global_c95c95c95c95c108c49c57;
/* ____l19 */
body_66:
  val = nil();
  global_c95c95c95c95c108c49c57 = val; /* ____l19 */
  goto body_67;
pointer global_c95c95c95c95c108c50c48;
/* ____l20 */
body_67:
  val = nil();
  global_c95c95c95c95c108c50c48 = val; /* ____l20 */
  goto body_68;
pointer global_c95c95c95c95c108c50c49;
/* ____l21 */
body_68:
  val = nil();
  global_c95c95c95c95c108c50c49 = val; /* ____l21 */
  goto body_69;
pointer global_c95c95c95c95c108c50c50;
/* ____l22 */
body_69:
  val = nil();
  global_c95c95c95c95c108c50c50 = val; /* ____l22 */
  goto body_70;
pointer global_c95c95c95c95c108c50c51;
/* ____l23 */
body_70:
  val = nil();
  global_c95c95c95c95c108c50c51 = val; /* ____l23 */
  goto body_71;
pointer global_c95c95c95c95c108c50c52;
/* ____l24 */
body_71:
  val = nil();
  global_c95c95c95c95c108c50c52 = val; /* ____l24 */
  goto body_72;
pointer global_c95c95c95c95c108c50c53;
/* ____l25 */
body_72:
  val = nil();
  global_c95c95c95c95c108c50c53 = val; /* ____l25 */
  goto body_73;
pointer global_c95c95c95c95c108c50c54;
/* ____l26 */
body_73:
  val = nil();
  global_c95c95c95c95c108c50c54 = val; /* ____l26 */
  goto body_74;
pointer global_c95c95c95c95c108c50c55;
/* ____l27 */
body_74:
  val = nil();
  global_c95c95c95c95c108c50c55 = val; /* ____l27 */
  goto body_75;
pointer global_c95c95c95c95c108c50c56;
/* ____l28 */
body_75:
  val = nil();
  global_c95c95c95c95c108c50c56 = val; /* ____l28 */
  goto body_76;
pointer global_c95c95c95c95c108c50c57;
/* ____l29 */
body_76:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c50c57 = val; /* ____l29 */
  goto body_77;
pointer global_c95c95c95c95c108c51c48;
/* ____l30 */
body_77:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c51c48 = val; /* ____l30 */
  goto body_78;
pointer global_c99c97c97c114; /* caar */
pointer global_c99c100c97c114; /* cdar */
pointer global_c99c97c100c114; /* cadr */
pointer global_c99c100c100c114; /* cddr */
pointer global_c99c97c97c97c114; /* caaar */
pointer global_c99c97c97c100c114; /* caadr */
pointer global_c99c97c100c97c114; /* cadar */
pointer global_c99c97c100c100c114; /* caddr */
pointer global_c99c100c97c97c114; /* cdaar */
pointer global_c99c100c97c100c114; /* cdadr */
pointer global_c99c100c100c97c114; /* cddar */
pointer global_c99c100c100c100c114; /* cdddr */
pointer global_c99c97c97c97c97c114; /* caaaar */
pointer global_c99c97c97c97c100c114; /* caaadr */
pointer global_c99c97c97c100c97c114; /* caadar */
pointer global_c99c97c97c100c100c114; /* caaddr */
pointer global_c99c97c100c97c97c114; /* cadaar */
pointer global_c99c97c100c97c100c114; /* cadadr */
pointer global_c99c97c100c100c97c114; /* caddar */
pointer global_c99c97c100c100c100c114; /* cadddr */
pointer global_c99c100c97c97c97c114; /* cdaaar */
pointer global_c99c100c97c97c100c114; /* cdaadr */
pointer global_c99c100c97c100c97c114; /* cdadar */
pointer global_c99c100c97c100c100c114; /* cdaddr */
pointer global_c99c100c100c97c97c114; /* cddaar */
pointer global_c99c100c100c97c100c114; /* cddadr */
pointer global_c99c100c100c100c97c114; /* cdddar */
pointer global_c99c100c100c100c100c114; /* cddddr */
pointer global_c97c112c112c108c121; /* apply */
pointer global_c114c101c99c117c114c115c101; /* recurse */
pointer global_c95c95c101c113c117c97c108; /* __equal */
pointer global_c109c97c112; /* map */
pointer global_c111c114; /* or */
pointer global_c97c110c100; /* and */
pointer global_c110c111c116; /* not */
pointer global_c109c101c109c98c101c114; /* member */
pointer global_c112c97c114c115c101c45c101c120c112c114; /* parse-expr */
pointer global_c115c116c97c110c100c97c114c100c45c108c105c98c114c97c114c121;
function_203:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c115c116c97c110c100c97c114c100c45c108c105c98c114c97c114c121 /* standard-library */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
  }
function_204:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c114 /* caar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-46);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_203);
    goto apply_addr;
  }
function_205:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c114 /* cdar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-47);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_204);
    goto apply_addr;
  }
function_206:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c114 /* cadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_205);
    goto apply_addr;
  }
function_207:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c114 /* cddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-49);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_206);
    goto apply_addr;
  }
function_208:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c97c114 /* caaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-50);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_207);
    goto apply_addr;
  }
function_209:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-51);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_208);
    goto apply_addr;
  }
function_210:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c97c114 /* cadar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-52);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_209);
    goto apply_addr;
  }
function_211:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-53);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_210);
    goto apply_addr;
  }
function_212:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c97c114 /* cdaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-54);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_211);
    goto apply_addr;
  }
function_213:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c100c114 /* cdadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-55);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_212);
    goto apply_addr;
  }
function_214:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c97c114 /* cddar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-56);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_213);
    goto apply_addr;
  }
function_215:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c100c114 /* cdddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-57);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_214);
    goto apply_addr;
  }
function_216:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c97c97c114 /* caaaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-58);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_215);
    goto apply_addr;
  }
function_217:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c97c100c114 /* caaadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-59);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_216);
    goto apply_addr;
  }
function_218:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c100c97c114 /* caadar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-60);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_217);
    goto apply_addr;
  }
function_219:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c97c100c100c114 /* caaddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-61);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_218);
    goto apply_addr;
  }
function_220:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c97c97c114 /* cadaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-62);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_219);
    goto apply_addr;
  }
function_221:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c97c100c114 /* cadadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-63);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_220);
    goto apply_addr;
  }
function_222:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c100c97c114 /* caddar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-64);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_221);
    goto apply_addr;
  }
function_223:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c97c100c100c100c114 /* cadddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-65);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_222);
    goto apply_addr;
  }
function_224:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c97c97c114 /* cdaaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-66);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_223);
    goto apply_addr;
  }
function_225:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c97c100c114 /* cdaadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-67);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_224);
    goto apply_addr;
  }
function_226:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c100c97c114 /* cdadar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-68);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_225);
    goto apply_addr;
  }
function_227:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c97c100c100c114 /* cdaddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-69);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_226);
    goto apply_addr;
  }
function_228:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c97c97c114 /* cddaar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-70);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_227);
    goto apply_addr;
  }
function_229:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c97c100c114 /* cddadr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-71);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_228);
    goto apply_addr;
  }
function_230:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c100c97c114 /* cdddar */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-72);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_229);
    goto apply_addr;
  }
function_231:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c99c100c100c100c100c114 /* cddddr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-73);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_230);
    goto apply_addr;
  }
function_232:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c105c100 /* id */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-74);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_231);
    goto apply_addr;
  }
function_233:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c108c105c115c116 /* list */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-75);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_232);
    goto apply_addr;
  }
function_234:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c97c112c112c108c121 /* apply */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-76);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_233);
    goto apply_addr;
  }
function_235:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c114c101c99c117c114c115c101 /* recurse */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-77);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_234);
    goto apply_addr;
  }
function_236:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-78);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_235);
    goto apply_addr;
  }
function_237:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c102c111c108c100c108 /* foldl */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-79);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_236);
    goto apply_addr;
  }
function_238:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c102c111c108c100c114 /* foldr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-80);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_237);
    goto apply_addr;
  }
function_239:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c97c112c112c101c110c100 /* append */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-81);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_238);
    goto apply_addr;
  }
function_240:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-82);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_239);
    goto apply_addr;
  }
function_241:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c109c97c112 /* map */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-83);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_240);
    goto apply_addr;
  }
function_242:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c111c114 /* or */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-84);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_241);
    goto apply_addr;
  }
function_243:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c97c110c100 /* and */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-85);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_242);
    goto apply_addr;
  }
function_244:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c110c111c116 /* not */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-86);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_243);
    goto apply_addr;
  }
function_245:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-87);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_244);
    goto apply_addr;
  }
function_246:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-88);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_245);
    goto apply_addr;
  }
function_247:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103 /* number->string */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-89);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_246);
    goto apply_addr;
  }
function_248:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c112c114c105c110c116 /* print */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-90);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_247);
    goto apply_addr;
  }
function_249:
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-91);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_248);
  goto apply_addr;
/* standard-library */
body_78:
global_c99c97c97c114 = nil(); /* caar */
global_c99c100c97c114 = nil(); /* cdar */
global_c99c97c100c114 = nil(); /* cadr */
global_c99c100c100c114 = nil(); /* cddr */
global_c99c97c97c97c114 = nil(); /* caaar */
global_c99c97c97c100c114 = nil(); /* caadr */
global_c99c97c100c97c114 = nil(); /* cadar */
global_c99c97c100c100c114 = nil(); /* caddr */
global_c99c100c97c97c114 = nil(); /* cdaar */
global_c99c100c97c100c114 = nil(); /* cdadr */
global_c99c100c100c97c114 = nil(); /* cddar */
global_c99c100c100c100c114 = nil(); /* cdddr */
global_c99c97c97c97c97c114 = nil(); /* caaaar */
global_c99c97c97c97c100c114 = nil(); /* caaadr */
global_c99c97c97c100c97c114 = nil(); /* caadar */
global_c99c97c97c100c100c114 = nil(); /* caaddr */
global_c99c97c100c97c97c114 = nil(); /* cadaar */
global_c99c97c100c97c100c114 = nil(); /* cadadr */
global_c99c97c100c100c97c114 = nil(); /* caddar */
global_c99c97c100c100c100c114 = nil(); /* cadddr */
global_c99c100c97c97c97c114 = nil(); /* cdaaar */
global_c99c100c97c97c100c114 = nil(); /* cdaadr */
global_c99c100c97c100c97c114 = nil(); /* cdadar */
global_c99c100c97c100c100c114 = nil(); /* cdaddr */
global_c99c100c100c97c97c114 = nil(); /* cddaar */
global_c99c100c100c97c100c114 = nil(); /* cddadr */
global_c99c100c100c100c97c114 = nil(); /* cdddar */
global_c99c100c100c100c100c114 = nil(); /* cddddr */
global_c97c112c112c108c121 = nil(); /* apply */
global_c114c101c99c117c114c115c101 = nil(); /* recurse */
global_c95c95c101c113c117c97c108 = nil(); /* __equal */
global_c109c97c112 = nil(); /* map */
global_c111c114 = nil(); /* or */
global_c97c110c100 = nil(); /* and */
global_c110c111c116 = nil(); /* not */
global_c109c101c109c98c101c114 = nil(); /* member */
global_c112c97c114c115c101c45c101c120c112c114 = nil(); /* parse-expr */
  increment_count(env);
  val = wrap_function((&&function_249), env);
  global_c115c116c97c110c100c97c114c100c45c108c105c98c114c97c114c121 = val; /* standard-library */
  goto body_79;
function_250:
  increment_count(val = car(car(car(car(env)))));
  goto pop_function;
/* caar */
body_79:
  increment_count(env);
  val = wrap_function((&&function_250), env);
  global_c99c97c97c114 = val; /* caar */
  goto body_80;
function_251:
  increment_count(val = cdr(car(car(car(env)))));
  goto pop_function;
/* cdar */
body_80:
  increment_count(env);
  val = wrap_function((&&function_251), env);
  global_c99c100c97c114 = val; /* cdar */
  goto body_81;
function_252:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* cadr */
body_81:
  increment_count(env);
  val = wrap_function((&&function_252), env);
  global_c99c97c100c114 = val; /* cadr */
  goto body_82;
function_253:
  increment_count(val = cdr(cdr(car(car(env)))));
  goto pop_function;
/* cddr */
body_82:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  global_c99c100c100c114 = val; /* cddr */
  goto body_83;
function_254:
  increment_count(val = car(car(car(car(car(env))))));
  goto pop_function;
/* caaar */
body_83:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c99c97c97c97c114 = val; /* caaar */
  goto body_84;
function_255:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* caadr */
body_84:
  increment_count(env);
  val = wrap_function((&&function_255), env);
  global_c99c97c97c100c114 = val; /* caadr */
  goto body_85;
function_256:
  increment_count(val = car(cdr(car(car(car(env))))));
  goto pop_function;
/* cadar */
body_85:
  increment_count(env);
  val = wrap_function((&&function_256), env);
  global_c99c97c100c97c114 = val; /* cadar */
  goto body_86;
function_257:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* caddr */
body_86:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  global_c99c97c100c100c114 = val; /* caddr */
  goto body_87;
function_258:
  increment_count(val = cdr(car(car(car(car(env))))));
  goto pop_function;
/* cdaar */
body_87:
  increment_count(env);
  val = wrap_function((&&function_258), env);
  global_c99c100c97c97c114 = val; /* cdaar */
  goto body_88;
function_259:
  increment_count(val = cdr(car(cdr(car(car(env))))));
  goto pop_function;
/* cdadr */
body_88:
  increment_count(env);
  val = wrap_function((&&function_259), env);
  global_c99c100c97c100c114 = val; /* cdadr */
  goto body_89;
function_260:
  increment_count(val = cdr(cdr(car(car(car(env))))));
  goto pop_function;
/* cddar */
body_89:
  increment_count(env);
  val = wrap_function((&&function_260), env);
  global_c99c100c100c97c114 = val; /* cddar */
  goto body_90;
function_261:
  increment_count(val = cdr(cdr(cdr(car(car(env))))));
  goto pop_function;
/* cdddr */
body_90:
  increment_count(env);
  val = wrap_function((&&function_261), env);
  global_c99c100c100c100c114 = val; /* cdddr */
  goto body_91;
function_262:
  increment_count(val = car(car(car(car(car(car(env)))))));
  goto pop_function;
/* caaaar */
body_91:
  increment_count(env);
  val = wrap_function((&&function_262), env);
  global_c99c97c97c97c97c114 = val; /* caaaar */
  goto body_92;
function_263:
  increment_count(val = car(car(car(cdr(car(car(env)))))));
  goto pop_function;
/* caaadr */
body_92:
  increment_count(env);
  val = wrap_function((&&function_263), env);
  global_c99c97c97c97c100c114 = val; /* caaadr */
  goto body_93;
function_264:
  increment_count(val = car(car(cdr(car(car(car(env)))))));
  goto pop_function;
/* caadar */
body_93:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  global_c99c97c97c100c97c114 = val; /* caadar */
  goto body_94;
function_265:
  increment_count(val = car(car(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* caaddr */
body_94:
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c99c97c97c100c100c114 = val; /* caaddr */
  goto body_95;
function_266:
  increment_count(val = car(cdr(car(car(car(car(env)))))));
  goto pop_function;
/* cadaar */
body_95:
  increment_count(env);
  val = wrap_function((&&function_266), env);
  global_c99c97c100c97c97c114 = val; /* cadaar */
  goto body_96;
function_267:
  increment_count(val = car(cdr(car(cdr(car(car(env)))))));
  goto pop_function;
/* cadadr */
body_96:
  increment_count(env);
  val = wrap_function((&&function_267), env);
  global_c99c97c100c97c100c114 = val; /* cadadr */
  goto body_97;
function_268:
  increment_count(val = car(cdr(cdr(car(car(car(env)))))));
  goto pop_function;
/* caddar */
body_97:
  increment_count(env);
  val = wrap_function((&&function_268), env);
  global_c99c97c100c100c97c114 = val; /* caddar */
  goto body_98;
function_269:
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* cadddr */
body_98:
  increment_count(env);
  val = wrap_function((&&function_269), env);
  global_c99c97c100c100c100c114 = val; /* cadddr */
  goto body_99;
function_270:
  increment_count(val = cdr(car(car(car(car(car(env)))))));
  goto pop_function;
/* cdaaar */
body_99:
  increment_count(env);
  val = wrap_function((&&function_270), env);
  global_c99c100c97c97c97c114 = val; /* cdaaar */
  goto body_100;
function_271:
  increment_count(val = cdr(car(car(cdr(car(car(env)))))));
  goto pop_function;
/* cdaadr */
body_100:
  increment_count(env);
  val = wrap_function((&&function_271), env);
  global_c99c100c97c97c100c114 = val; /* cdaadr */
  goto body_101;
function_272:
  increment_count(val = cdr(car(cdr(car(car(car(env)))))));
  goto pop_function;
/* cdadar */
body_101:
  increment_count(env);
  val = wrap_function((&&function_272), env);
  global_c99c100c97c100c97c114 = val; /* cdadar */
  goto body_102;
function_273:
  increment_count(val = cdr(car(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* cdaddr */
body_102:
  increment_count(env);
  val = wrap_function((&&function_273), env);
  global_c99c100c97c100c100c114 = val; /* cdaddr */
  goto body_103;
function_274:
  increment_count(val = cdr(cdr(car(car(car(car(env)))))));
  goto pop_function;
/* cddaar */
body_103:
  increment_count(env);
  val = wrap_function((&&function_274), env);
  global_c99c100c100c97c97c114 = val; /* cddaar */
  goto body_104;
function_275:
  increment_count(val = cdr(cdr(car(cdr(car(car(env)))))));
  goto pop_function;
/* cddadr */
body_104:
  increment_count(env);
  val = wrap_function((&&function_275), env);
  global_c99c100c100c97c100c114 = val; /* cddadr */
  goto body_105;
function_276:
  increment_count(val = cdr(cdr(cdr(car(car(car(env)))))));
  goto pop_function;
/* cdddar */
body_105:
  increment_count(env);
  val = wrap_function((&&function_276), env);
  global_c99c100c100c100c97c114 = val; /* cdddar */
  goto body_106;
function_277:
  increment_count(val = cdr(cdr(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* cddddr */
body_106:
  increment_count(env);
  val = wrap_function((&&function_277), env);
  global_c99c100c100c100c100c114 = val; /* cddddr */
  goto body_107;
function_278:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* apply */
body_107:
  increment_count(env);
  val = wrap_function((&&function_278), env);
  global_c97c112c112c108c121 = val; /* apply */
  goto body_108;
pointer global_c95c102c110c49c55; /* _fn17 */
pointer global_c95c102c110c49c56;
function_279:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_280:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c55 /* _fn17 */);
  target = (&&function_279);
  goto apply_addr;
function_281:
  increment_count(env);
  val = wrap_function((&&function_280), env);
  goto pop_function;
/* _fn18 */
body_108:
global_c95c102c110c49c55 = nil(); /* _fn17 */
  increment_count(env);
  val = wrap_function((&&function_281), env);
  global_c95c102c110c49c56 = val; /* _fn18 */
  goto body_109;
function_282:
  goto top_level_apply;
function_283:
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_282);
  goto apply_addr;
function_284:
  increment_count(env);
  val = wrap_function((&&function_283), env);
  goto pop_function;
/* _fn17 */
body_109:
  increment_count(env);
  val = wrap_function((&&function_284), env);
  global_c95c102c110c49c55 = val; /* _fn17 */
  goto body_110;
pointer global_c95c102c110c49c57; /* _fn19 */
pointer global_c95c102c110c50c48;
function_285:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_286:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c57 /* _fn19 */);
  target = (&&function_285);
  goto apply_addr;
function_287:
  increment_count(env);
  val = wrap_function((&&function_286), env);
  goto pop_function;
/* _fn20 */
body_110:
global_c95c102c110c49c57 = nil(); /* _fn19 */
  increment_count(env);
  val = wrap_function((&&function_287), env);
  global_c95c102c110c50c48 = val; /* _fn20 */
  goto body_111;
function_288:
  goto top_level_apply;
function_289:
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_288);
  goto apply_addr;
function_290:
  increment_count(env);
  val = wrap_function((&&function_289), env);
  goto pop_function;
/* _fn19 */
body_111:
  increment_count(env);
  val = wrap_function((&&function_290), env);
  global_c95c102c110c49c57 = val; /* _fn19 */
  goto body_112;
function_291:
  goto top_level_apply;
function_292:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c56 /* _fn18 */);
  target = (&&function_291);
  goto apply_addr;
function_293:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c48 /* _fn20 */);
  target = (&&function_292);
  goto apply_addr;
/* recurse */
body_112:
  increment_count(env);
  val = wrap_function((&&function_293), env);
  global_c114c101c99c117c114c115c101 = val; /* recurse */
  goto body_113;
function_294:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    goto top_level_apply;
  } else {
    val = nil();
    goto pop_function;
  }
function_295:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    target = (&&function_294);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_296:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_295);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    goto top_level_apply;
  }
function_297:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_296);
  goto apply_addr;
/* __equal */
body_113:
  increment_count(env);
  val = wrap_function((&&function_297), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_114;
pointer global_c95c102c110c50c49;
function_298:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_299:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_298);
  goto apply_addr;
function_300:
  increment_count(env);
  val = wrap_function((&&function_299), env);
  goto pop_function;
/* _fn21 */
body_114:
  increment_count(env);
  val = wrap_function((&&function_300), env);
  global_c95c102c110c50c49 = val; /* _fn21 */
  goto body_115;
function_301:
  goto top_level_apply;
function_302:
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_301);
  goto apply_addr;
function_303:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c49 /* _fn21 */);
  target = (&&function_302);
  goto apply_addr;
/* map */
body_115:
  increment_count(env);
  val = wrap_function((&&function_303), env);
  global_c109c97c112 = val; /* map */
  goto body_116;
pointer global_c95c102c110c50c50;
function_304:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
/* _fn22 */
body_116:
  increment_count(env);
  val = wrap_function((&&function_304), env);
  global_c95c102c110c50c50 = val; /* _fn22 */
  goto body_117;
function_305:
  goto top_level_apply;
function_306:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c50 /* _fn22 */);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_305);
  goto apply_addr;
/* or */
body_117:
  increment_count(env);
  val = wrap_function((&&function_306), env);
  global_c111c114 = val; /* or */
  goto body_118;
pointer global_c95c102c110c50c51;
function_307:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
/* _fn23 */
body_118:
  increment_count(env);
  val = wrap_function((&&function_307), env);
  global_c95c102c110c50c51 = val; /* _fn23 */
  goto body_119;
function_308:
  goto top_level_apply;
function_309:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-44);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c51 /* _fn23 */);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_308);
  goto apply_addr;
/* and */
body_119:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  global_c97c110c100 = val; /* and */
  goto body_120;
function_310:
  push_args();
  increment_count(val = car(env));
  args = val;
  if (is_unary(args)) {
    if (is_nil(car(args))) {
      increment_count(val = true); 
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  goto pop_function;
/* not */
body_120:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c110c111c116 = val; /* not */
  goto body_121;
function_311:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    goto top_level_apply;
  }
function_312:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    target = (&&function_311);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_313:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_312);
  goto apply_addr;
/* member */
body_121:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c109c101c109c98c101c114 = val; /* member */
  goto body_122;
pointer global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114;
function_314:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_315:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(13);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(110);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_314);
    goto apply_addr;
  }
function_316:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(9);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(114);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_315);
    goto apply_addr;
  }
function_317:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_316);
  goto apply_addr;
/* ___escape-char */
body_122:
  increment_count(env);
  val = wrap_function((&&function_317), env);
  global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* ___escape-char */
  goto body_123;
pointer global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103; /* ___parse-string */
pointer global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* ___parse-escaped-string */
pointer global_c95c102c110c50c52;
function_318:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 /* ___parse-string */);
  goto top_level_apply;
function_319:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 /* ___escape-char */);
    target = (&&function_318);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 /* ___escape-char */);
    target = (&&function_318);
    goto apply_addr;
  }
function_320:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_319);
    goto apply_addr;
  }
function_321:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 /* ___parse-escaped-string */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_320);
    goto apply_addr;
  }
function_322:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  increment_count(env);
  val = wrap_function((&&function_322), env);
  goto pop_function;
/* _fn24 */
body_123:
global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* ___parse-string */
global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* ___parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_323), env);
  global_c95c102c110c50c52 = val; /* _fn24 */
  goto body_124;
function_324:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c52 /* _fn24 */);
  goto top_level_apply;
/* ___parse-escaped-string */
body_124:
  increment_count(env);
  val = wrap_function((&&function_324), env);
  global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* ___parse-escaped-string */
  goto body_125;
pointer global_c95c102c110c50c53;
function_325:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_326:
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_325);
  goto apply_addr;
function_327:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 /* ___parse-string */);
    goto top_level_apply;
  } else {
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 /* ___parse-string */);
    goto top_level_apply;
  }
function_328:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 /* ___parse-escaped-string */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_327);
    goto apply_addr;
  }
function_329:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_326);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(92);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_328);
    goto apply_addr;
  }
function_330:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(34);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_329);
    goto apply_addr;
  }
function_331:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 /* ___parse-string */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_330);
    goto apply_addr;
  }
function_332:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_331);
  goto apply_addr;
function_333:
  increment_count(env);
  val = wrap_function((&&function_332), env);
  goto pop_function;
/* _fn25 */
body_125:
  increment_count(env);
  val = wrap_function((&&function_333), env);
  global_c95c102c110c50c53 = val; /* _fn25 */
  goto body_126;
function_334:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c53 /* _fn25 */);
  goto top_level_apply;
/* ___parse-string */
body_126:
  increment_count(env);
  val = wrap_function((&&function_334), env);
  global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* ___parse-string */
  goto body_127;
pointer global_c95c95c95c115c107c105c112c45c108c105c110c101; /* ___skip-line */
pointer global_c95c102c110c50c54;
function_335:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c115c107c105c112c45c108c105c110c101 /* ___skip-line */);
    goto top_level_apply;
  }
function_336:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_335);
    goto apply_addr;
  }
function_337:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_336);
  goto apply_addr;
function_338:
  increment_count(env);
  val = wrap_function((&&function_337), env);
  goto pop_function;
/* _fn26 */
body_127:
global_c95c95c95c115c107c105c112c45c108c105c110c101 = nil(); /* ___skip-line */
  increment_count(env);
  val = wrap_function((&&function_338), env);
  global_c95c102c110c50c54 = val; /* _fn26 */
  goto body_128;
function_339:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c54 /* _fn26 */);
  goto top_level_apply;
/* ___skip-line */
body_128:
  increment_count(env);
  val = wrap_function((&&function_339), env);
  global_c95c95c95c115c107c105c112c45c108c105c110c101 = val; /* ___skip-line */
  goto body_129;
pointer global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108; /* ___parse-octal */
pointer global_c95c102c110c50c55;
function_340:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(8);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) * value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108 /* ___parse-octal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_341:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108 /* ___parse-octal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(56);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_340);
    goto apply_addr;
  }
function_342:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_341);
  goto apply_addr;
function_343:
  increment_count(env);
  val = wrap_function((&&function_342), env);
  goto pop_function;
/* _fn27 */
body_129:
global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108 = nil(); /* ___parse-octal */
  increment_count(env);
  val = wrap_function((&&function_343), env);
  global_c95c102c110c50c55 = val; /* _fn27 */
  goto body_130;
function_344:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c55 /* _fn27 */);
  goto top_level_apply;
/* ___parse-octal */
body_130:
  increment_count(env);
  val = wrap_function((&&function_344), env);
  global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108 = val; /* ___parse-octal */
  goto body_131;
pointer global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108; /* ___parse-hexadecimal */
pointer global_c95c102c110c50c56;
function_345:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(96);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    val = new_number(9);
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(16);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) * value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_346:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(64);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    val = new_number(9);
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(16);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) * value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(103);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(96);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_345);
    goto apply_addr;
  }
function_347:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(16);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) * value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(71);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(64);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_346);
    goto apply_addr;
  }
function_348:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(58);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_347);
    goto apply_addr;
  }
function_349:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_348);
  goto apply_addr;
function_350:
  increment_count(env);
  val = wrap_function((&&function_349), env);
  goto pop_function;
/* _fn28 */
body_131:
global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 = nil(); /* ___parse-hexadecimal */
  increment_count(env);
  val = wrap_function((&&function_350), env);
  global_c95c102c110c50c56 = val; /* _fn28 */
  goto body_132;
function_351:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c56 /* _fn28 */);
  goto top_level_apply;
/* ___parse-hexadecimal */
body_132:
  increment_count(env);
  val = wrap_function((&&function_351), env);
  global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 = val; /* ___parse-hexadecimal */
  goto body_133;
pointer global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108; /* ___parse-octal-or-hexadecimal */
pointer global_c95c102c110c50c57;
function_352:
  goto top_level_apply;
function_353:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108 /* ___parse-octal */);
    target = (&&function_352);
    goto apply_addr;
  }
function_354:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_353);
  goto apply_addr;
function_355:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(88);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_354);
  goto apply_addr;
function_356:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-octal-or-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(120);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_355);
    goto apply_addr;
  }
function_357:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_356);
  goto apply_addr;
function_358:
  increment_count(env);
  val = wrap_function((&&function_357), env);
  goto pop_function;
/* _fn29 */
body_133:
global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108 = nil(); /* ___parse-octal-or-hexadecimal */
  increment_count(env);
  val = wrap_function((&&function_358), env);
  global_c95c102c110c50c57 = val; /* _fn29 */
  goto body_134;
function_359:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c57 /* _fn29 */);
  goto top_level_apply;
/* ___parse-octal-or-hexadecimal */
body_134:
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108 = val; /* ___parse-octal-or-hexadecimal */
  goto body_135;
pointer global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108; /* ___parse-decimal */
pointer global_c95c102c110c51c48;
function_360:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) * value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 /* ___parse-decimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_361:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 /* ___parse-decimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(58);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_360);
    goto apply_addr;
  }
function_362:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_361);
  goto apply_addr;
function_363:
  increment_count(env);
  val = wrap_function((&&function_362), env);
  goto pop_function;
/* _fn30 */
body_135:
global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 = nil(); /* ___parse-decimal */
  increment_count(env);
  val = wrap_function((&&function_363), env);
  global_c95c102c110c51c48 = val; /* _fn30 */
  goto body_136;
function_364:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c48 /* _fn30 */);
  goto top_level_apply;
/* ___parse-decimal */
body_136:
  increment_count(env);
  val = wrap_function((&&function_364), env);
  global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 = val; /* ___parse-decimal */
  goto body_137;
pointer global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108; /* ___parse-symbol */
pointer global_c95c102c110c51c50; /* _fn32 */
pointer global_c95c102c110c51c49; /* _fn31 */
pointer global_c95c95c95c112c97c114c115c101c45c110c101c103c97c116c105c118c101c45c111c114c45c115c121c109c98c111c108; /* ___parse-negative-or-symbol */
pointer global_c95c102c110c51c51;
function_365:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-octal-or-hexadecimal */);
  goto top_level_apply;
function_366:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((is_binary(args)) &
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (is_unary(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 /* ___parse-decimal */);
  goto top_level_apply;
function_367:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c51c49 /* _fn31 */);
    target = (&&function_365);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c51c50 /* _fn32 */);
    target = (&&function_366);
    goto apply_addr;
  }
function_368:
  goto top_level_apply;
function_369:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
  target = (&&function_368);
  goto apply_addr;
function_370:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_367);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(45);
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_369);
    goto apply_addr;
  }
function_371:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c101c103c97c116c105c118c101c45c111c114c45c115c121c109c98c111c108 /* ___parse-negative-or-symbol */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(58);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_370);
    goto apply_addr;
  }
function_372:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_371);
  goto apply_addr;
function_373:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  goto pop_function;
/* _fn33 */
body_137:
global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* ___parse-symbol */
global_c95c102c110c51c50 = nil(); /* _fn32 */
global_c95c102c110c51c49 = nil(); /* _fn31 */
global_c95c95c95c112c97c114c115c101c45c110c101c103c97c116c105c118c101c45c111c114c45c115c121c109c98c111c108 = nil(); /* ___parse-negative-or-symbol */
  increment_count(env);
  val = wrap_function((&&function_373), env);
  global_c95c102c110c51c51 = val; /* _fn33 */
  goto body_138;
function_374:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((is_binary(args)) &
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (is_unary(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_375:
  increment_count(env);
  val = wrap_function((&&function_374), env);
  goto pop_function;
/* _fn31 */
body_138:
  increment_count(env);
  val = wrap_function((&&function_375), env);
  global_c95c102c110c51c49 = val; /* _fn31 */
  goto body_139;
function_376:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((is_binary(args)) &
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (is_unary(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_377:
  increment_count(env);
  val = wrap_function((&&function_376), env);
  goto pop_function;
/* _fn32 */
body_139:
  increment_count(env);
  val = wrap_function((&&function_377), env);
  global_c95c102c110c51c50 = val; /* _fn32 */
  goto body_140;
function_378:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c51 /* _fn33 */);
  goto top_level_apply;
/* ___parse-negative-or-symbol */
body_140:
  increment_count(env);
  val = wrap_function((&&function_378), env);
  global_c95c95c95c112c97c114c115c101c45c110c101c103c97c116c105c118c101c45c111c114c45c115c121c109c98c111c108 = val; /* ___parse-negative-or-symbol */
  goto body_141;
pointer global_c95c102c110c51c52;
function_379:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_380:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_379);
  goto apply_addr;
function_381:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_380);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_380);
    goto apply_addr;
  }
function_382:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_383:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_382);
  goto apply_addr;
function_384:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_383);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
    goto top_level_apply;
  }
function_385:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_384);
  goto apply_addr;
function_386:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    if (value(car(args)) < value(car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    if (value(car(args)) > value(car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c97c110c100 /* and */);
  target = (&&function_385);
  goto apply_addr;
function_387:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_386);
  goto apply_addr;
function_388:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(33);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    if (! is_nil(val)) {
      decrement_count(val);
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      push_args();
      val = nil();
      args = val;
      val = new_number(10);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61 /* __= */);
      target = (&&function_381);
      goto apply_addr;
    } else {
      push_args();
      val = nil();
      args = val;
      push_args();
      val = nil();
      args = val;
      val = new_number(59);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61 /* __= */);
      target = (&&function_387);
      goto apply_addr;
    }
  }
function_389:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_388);
  goto apply_addr;
function_390:
  increment_count(env);
  val = wrap_function((&&function_389), env);
  goto pop_function;
/* _fn34 */
body_141:
  increment_count(env);
  val = wrap_function((&&function_390), env);
  global_c95c102c110c51c52 = val; /* _fn34 */
  goto body_142;
function_391:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c52 /* _fn34 */);
  goto top_level_apply;
/* ___parse-symbol */
body_142:
  increment_count(env);
  val = wrap_function((&&function_391), env);
  global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* ___parse-symbol */
  goto body_143;
pointer global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114c45c111c114c45c115c121c109c98c111c108; /* ___parse-number-or-symbol */
pointer global_c95c102c110c51c53;
function_392:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
  goto top_level_apply;
function_393:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_number(car(args))) {
      if ((is_binary(args)) &
          is_number(car(cdr(args)))) {
        val = new_number(value(car(args)) - 
                         value(car(cdr(args))));
      } else if (is_unary(args) == 1) {
        val = new_number(-value(car(args)));
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c100c101c99c105c109c97c108 /* ___parse-decimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_392);
    goto apply_addr;
  }
function_394:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c111c99c116c97c108c45c111c114c45c104c101c120c97c100c101c99c105c109c97c108 /* ___parse-octal-or-hexadecimal */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(58);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) > value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c97c110c100 /* and */);
    target = (&&function_393);
    goto apply_addr;
  }
function_395:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c101c103c97c116c105c118c101c45c111c114c45c115c121c109c98c111c108 /* ___parse-negative-or-symbol */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(48);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_394);
    goto apply_addr;
  }
function_396:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114c45c111c114c45c115c121c109c98c111c108 /* ___parse-number-or-symbol */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(45);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_395);
    goto apply_addr;
  }
function_397:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_396);
  goto apply_addr;
function_398:
  increment_count(env);
  val = wrap_function((&&function_397), env);
  goto pop_function;
/* _fn35 */
body_143:
global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114c45c111c114c45c115c121c109c98c111c108 = nil(); /* ___parse-number-or-symbol */
  increment_count(env);
  val = wrap_function((&&function_398), env);
  global_c95c102c110c51c53 = val; /* _fn35 */
  goto body_144;
function_399:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c53 /* _fn35 */);
  goto top_level_apply;
/* ___parse-number-or-symbol */
body_144:
  increment_count(env);
  val = wrap_function((&&function_399), env);
  global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114c45c111c114c45c115c121c109c98c111c108 = val; /* ___parse-number-or-symbol */
  goto body_145;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110; /* ___parse-paren */
pointer global_c95c102c110c51c54;
function_400:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c115c107c105c112c45c108c105c110c101 /* ___skip-line */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(108);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(121);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(109);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(84);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_401:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(59);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_400);
    goto apply_addr;
  }
function_402:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_401);
    goto apply_addr;
  }
function_403:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_402);
  goto apply_addr;
function_404:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(33);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c110c111c116 /* not */);
    target = (&&function_403);
    goto apply_addr;
  }
function_405:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_404);
    goto apply_addr;
  }
function_406:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_405);
  goto apply_addr;
function_407:
  increment_count(env);
  val = wrap_function((&&function_406), env);
  goto pop_function;
/* _fn36 */
body_145:
global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* ___parse-paren */
  increment_count(env);
  val = wrap_function((&&function_407), env);
  global_c95c102c110c51c54 = val; /* _fn36 */
  goto body_146;
function_408:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c54 /* _fn36 */);
  goto top_level_apply;
/* ___parse-paren */
body_146:
  increment_count(env);
  val = wrap_function((&&function_408), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* ___parse-paren */
  goto body_147;
pointer global_c95c102c110c51c55; /* _fn37 */
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108; /* ___parse-tail */
pointer global_c95c102c110c51c56;
function_409:
  goto top_level_apply;
function_410:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
  target = (&&function_409);
  goto apply_addr;
function_411:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c55 /* _fn37 */);
  target = (&&function_410);
  goto apply_addr;
function_412:
  increment_count(env);
  val = wrap_function((&&function_411), env);
  goto pop_function;
/* _fn38 */
body_147:
global_c95c102c110c51c55 = nil(); /* _fn37 */
global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* ___parse-tail */
  increment_count(env);
  val = wrap_function((&&function_412), env);
  global_c95c102c110c51c56 = val; /* _fn38 */
  goto body_148;
function_413:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_414:
  increment_count(env);
  val = wrap_function((&&function_413), env);
  goto pop_function;
/* _fn37 */
body_148:
  increment_count(env);
  val = wrap_function((&&function_414), env);
  global_c95c102c110c51c55 = val; /* _fn37 */
  goto body_149;
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_415:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c56 /* _fn38 */);
  goto top_level_apply;
/* ___parse-tail-cont */
body_149:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* ___parse-tail-cont */
  goto body_150;
pointer global_c95c102c110c52c48; /* _fn40 */
pointer global_c95c102c110c52c49;
function_416:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_417:
  goto top_level_apply;
function_418:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_417);
  goto apply_addr;
function_419:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c115c107c105c112c45c108c105c110c101 /* ___skip-line */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 /* ___parse-tail-cont */);
    target = (&&function_418);
    goto apply_addr;
  }
function_420:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c52c48 /* _fn40 */);
    target = (&&function_416);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(59);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_419);
    goto apply_addr;
  }
function_421:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(46);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_420);
    goto apply_addr;
  }
function_422:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_421);
    goto apply_addr;
  }
function_423:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_422);
  goto apply_addr;
function_424:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(33);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c110c111c116 /* not */);
    target = (&&function_423);
    goto apply_addr;
  }
function_425:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_424);
    goto apply_addr;
  }
function_426:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_425);
  goto apply_addr;
function_427:
  increment_count(env);
  val = wrap_function((&&function_426), env);
  goto pop_function;
/* _fn41 */
body_150:
global_c95c102c110c52c48 = nil(); /* _fn40 */
  increment_count(env);
  val = wrap_function((&&function_427), env);
  global_c95c102c110c52c49 = val; /* _fn41 */
  goto body_151;
pointer global_c95c102c110c51c57; /* _fn39 */
function_428:
  goto top_level_apply;
function_429:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
  target = (&&function_428);
  goto apply_addr;
function_430:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c57 /* _fn39 */);
  target = (&&function_429);
  goto apply_addr;
function_431:
  increment_count(env);
  val = wrap_function((&&function_430), env);
  goto pop_function;
/* _fn40 */
body_151:
global_c95c102c110c51c57 = nil(); /* _fn39 */
  increment_count(env);
  val = wrap_function((&&function_431), env);
  global_c95c102c110c52c48 = val; /* _fn40 */
  goto body_152;
function_432:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_433:
  increment_count(env);
  val = wrap_function((&&function_432), env);
  goto pop_function;
/* _fn39 */
body_152:
  increment_count(env);
  val = wrap_function((&&function_433), env);
  global_c95c102c110c51c57 = val; /* _fn39 */
  goto body_153;
function_434:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c49 /* _fn41 */);
  goto top_level_apply;
/* ___parse-tail */
body_153:
  increment_count(env);
  val = wrap_function((&&function_434), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = val; /* ___parse-tail */
  goto body_154;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c105c114; /* ___parse-pair */
pointer global_c95c102c110c52c50;
function_435:
  goto top_level_apply;
function_436:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_435);
  goto apply_addr;
function_437:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114 /* ___parse-pair */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c115c107c105c112c45c108c105c110c101 /* ___skip-line */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 /* ___parse-tail-cont */);
    target = (&&function_436);
    goto apply_addr;
  }
function_438:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(59);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_437);
    goto apply_addr;
  }
function_439:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114 /* ___parse-pair */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_438);
    goto apply_addr;
  }
function_440:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_439);
  goto apply_addr;
function_441:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114 /* ___parse-pair */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(33);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c110c111c116 /* not */);
    target = (&&function_440);
    goto apply_addr;
  }
function_442:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_441);
    goto apply_addr;
  }
function_443:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_442);
  goto apply_addr;
function_444:
  increment_count(env);
  val = wrap_function((&&function_443), env);
  goto pop_function;
/* _fn42 */
body_154:
global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* ___parse-pair */
  increment_count(env);
  val = wrap_function((&&function_444), env);
  global_c95c102c110c52c50 = val; /* _fn42 */
  goto body_155;
function_445:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c50 /* _fn42 */);
  goto top_level_apply;
/* ___parse-pair */
body_155:
  increment_count(env);
  val = wrap_function((&&function_445), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* ___parse-pair */
  goto body_156;
pointer global_c95c102c110c52c53; /* _fn45 */
pointer global_c95c102c110c52c52; /* _fn44 */
pointer global_c95c102c110c52c51; /* _fn43 */
pointer global_c95c102c110c52c54;
function_446:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
    goto top_level_apply;
  } else {
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
    goto top_level_apply;
  }
function_447:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_448:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_449:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_450:
  goto top_level_apply;
function_451:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c115c107c105c112c45c108c105c110c101 /* ___skip-line */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114c45c111c114c45c115c121c109c98c111c108 /* ___parse-number-or-symbol */);
    target = (&&function_450);
    goto apply_addr;
  }
function_452:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c52c53 /* _fn45 */);
    target = (&&function_449);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(59);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_451);
    goto apply_addr;
  }
function_453:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(85);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(96);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_452);
    goto apply_addr;
  }
function_454:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c52c52 /* _fn44 */);
    target = (&&function_448);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(46);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_453);
    goto apply_addr;
  }
function_455:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(85);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(44);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_454);
    goto apply_addr;
  }
function_456:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c105c114 /* ___parse-pair */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(41);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_455);
    goto apply_addr;
  }
function_457:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c52c51 /* _fn43 */);
    target = (&&function_447);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(40);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_456);
    goto apply_addr;
  }
function_458:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    val = nil();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 /* ___parse-string */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(39);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_457);
    goto apply_addr;
  }
function_459:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_446);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_number(34);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_458);
    goto apply_addr;
  }
function_460:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_459);
  goto apply_addr;
function_461:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    val = nil();
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
    val = new_number(102);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(32);
    args = cons(val, args);
    val = new_number(100);
    args = cons(val, args);
    val = new_number(110);
    args = cons(val, args);
    val = new_number(69);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = new_number(33);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if ((is_binary(args)) &
        (is_number(car(args))) &
        (is_number(car(cdr(args))))) {
      if (value(car(args)) < value(car(cdr(args)))) {
        increment_count(val = true);
      } else { val = nil(); }
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c110c111c116 /* not */);
    target = (&&function_460);
    goto apply_addr;
  }
function_462:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_461);
  goto apply_addr;
function_463:
  increment_count(env);
  val = wrap_function((&&function_462), env);
  goto pop_function;
/* _fn46 */
body_156:
global_c95c102c110c52c53 = nil(); /* _fn45 */
global_c95c102c110c52c52 = nil(); /* _fn44 */
global_c95c102c110c52c51 = nil(); /* _fn43 */
  increment_count(env);
  val = wrap_function((&&function_463), env);
  global_c95c102c110c52c54 = val; /* _fn46 */
  goto body_157;
function_464:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_465:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_464);
  goto apply_addr;
function_466:
  increment_count(env);
  val = wrap_function((&&function_465), env);
  goto pop_function;
/* _fn43 */
body_157:
  increment_count(env);
  val = wrap_function((&&function_466), env);
  global_c95c102c110c52c51 = val; /* _fn43 */
  goto body_158;
function_467:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_468:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_467);
  goto apply_addr;
function_469:
  increment_count(env);
  val = wrap_function((&&function_468), env);
  goto pop_function;
/* _fn44 */
body_158:
  increment_count(env);
  val = wrap_function((&&function_469), env);
  global_c95c102c110c52c52 = val; /* _fn44 */
  goto body_159;
function_470:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_471:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_470);
  goto apply_addr;
function_472:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  goto pop_function;
/* _fn45 */
body_159:
  increment_count(env);
  val = wrap_function((&&function_472), env);
  global_c95c102c110c52c53 = val; /* _fn45 */
  goto body_160;
function_473:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c54 /* _fn46 */);
  goto top_level_apply;
/* parse-expr */
body_160:
  increment_count(env);
  val = wrap_function((&&function_473), env);
  global_c112c97c114c115c101c45c101c120c112c114 = val; /* parse-expr */
  goto body_161;
pointer global_c95c102c110c52c55;
function_474:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c54 /* ____l26 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c53 /* ____l25 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_475:
  increment_count(env);
  val = wrap_function((&&function_474), env);
  goto pop_function;
/* _fn47 */
body_161:
  increment_count(env);
  val = wrap_function((&&function_475), env);
  global_c95c102c110c52c55 = val; /* _fn47 */
  goto body_162;
pointer global_c95c102c110c52c56;
function_476:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c56 /* ____l28 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c55 /* ____l27 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_477:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c57 /* ____l29 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_476);
  goto apply_addr;
function_478:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c51c48 /* ____l30 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* symbol->string */);
  target = (&&function_477);
  goto apply_addr;
function_479:
  increment_count(env);
  val = wrap_function((&&function_478), env);
  goto pop_function;
/* _fn48 */
body_162:
  increment_count(env);
  val = wrap_function((&&function_479), env);
  global_c95c102c110c52c56 = val; /* _fn48 */
  goto body_163;
pointer global_c99c111c109c112c105c108c101c45c102c105c110c100;
function_480:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49c57 /* ____l19 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_481:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c115c116c97c110c100c97c114c100c45c108c105c98c114c97c114c121 /* standard-library */);
  goto top_level_apply;
function_482:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c55 /* _fn47 */);
  target = (&&function_481);
  goto apply_addr;
function_483:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c52 /* ____l24 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c51 /* ____l23 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c52c56 /* _fn48 */);
    target = (&&function_482);
    goto apply_addr;
  }
function_484:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c50 /* ____l22 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c49 /* ____l21 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c115c112c101c99c105c97c108c45c102c111c114c109c115 /* special-forms */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    target = (&&function_483);
    goto apply_addr;
  }
function_485:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c48 /* ____l20 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
    target = (&&function_480);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 /* supported-builtins */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    target = (&&function_484);
    goto apply_addr;
  }
function_486:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_485);
  goto apply_addr;
function_487:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  target = (&&function_486);
  goto apply_addr;
/* compile-find */
body_163:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  global_c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* compile-find */
  goto body_164;
pointer global_c95c95c95c95c108c51c49;
/* ____l31 */
body_164:
  val = new_symbol(-36);
  global_c95c95c95c95c108c51c49 = val; /* ____l31 */
  goto body_165;
pointer global_c95c95c95c95c108c51c50;
/* ____l32 */
body_165:
  val = new_symbol(-45);
  global_c95c95c95c95c108c51c50 = val; /* ____l32 */
  goto body_166;
pointer global_c114c101c119c114c105c116c101c45c113c117c111c116c101;
function_488:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c50 /* ____l32 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_489:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c111c116c101 /* rewrite-quote */);
  target = (&&function_488);
  goto apply_addr;
function_490:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c49 /* ____l31 */);
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c111c116c101 /* rewrite-quote */);
    target = (&&function_489);
    goto apply_addr;
  }
function_491:
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    if (is_number(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      increment_count(val = car(car(env)));
      goto pop_function;
    } else {
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
      target = (&&function_490);
      goto apply_addr;
    }
  }
/* rewrite-quote */
body_166:
  increment_count(env);
  val = wrap_function((&&function_491), env);
  global_c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* rewrite-quote */
  goto body_167;
pointer global_c95c95c95c95c108c51c51;
/* ____l33 */
body_167:
  val = nil();
  global_c95c95c95c95c108c51c51 = val; /* ____l33 */
  goto body_168;
pointer global_c95c95c95c95c108c51c52;
/* ____l34 */
body_168:
  val = nil();
  push_args();
  args = val;
  val = new_number(108);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c51c52 = val; /* ____l34 */
  goto body_169;
pointer global_c95c102c110c52c57;
function_492:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c51 /* ____l33 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_493:
  increment_count(env);
  val = wrap_function((&&function_492), env);
  goto pop_function;
/* _fn49 */
body_169:
  increment_count(env);
  val = wrap_function((&&function_493), env);
  global_c95c102c110c52c57 = val; /* _fn49 */
  goto body_170;
pointer global_c99c111c109c112c105c108c101c45c113c117c111c116c101;
function_494:
  goto top_level_apply;
function_495:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c57 /* _fn49 */);
  target = (&&function_494);
  goto apply_addr;
function_496:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_495);
  goto apply_addr;
function_497:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c52 /* ____l34 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_496);
  goto apply_addr;
function_498:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_497);
  goto apply_addr;
/* compile-quote */
body_170:
  increment_count(env);
  val = wrap_function((&&function_498), env);
  global_c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* compile-quote */
  goto body_171;
pointer global_c95c95c95c95c108c51c53;
/* ____l35 */
body_171:
  val = nil();
  global_c95c95c95c95c108c51c53 = val; /* ____l35 */
  goto body_172;
pointer global_c95c95c95c95c108c51c54;
/* ____l36 */
body_172:
  val = nil();
  global_c95c95c95c95c108c51c54 = val; /* ____l36 */
  goto body_173;
pointer global_c95c95c95c95c108c51c55;
/* ____l37 */
body_173:
  val = nil();
  global_c95c95c95c95c108c51c55 = val; /* ____l37 */
  goto body_174;
pointer global_c95c95c95c95c108c51c56;
/* ____l38 */
body_174:
  val = new_symbol(-36);
  global_c95c95c95c95c108c51c56 = val; /* ____l38 */
  goto body_175;
pointer global_c95c95c95c95c108c51c57;
/* ____l39 */
body_175:
  val = nil();
  global_c95c95c95c95c108c51c57 = val; /* ____l39 */
  goto body_176;
pointer global_c95c95c95c95c108c52c48;
/* ____l40 */
body_176:
  val = new_symbol(-41);
  global_c95c95c95c95c108c52c48 = val; /* ____l40 */
  goto body_177;
pointer global_c95c95c95c95c108c52c49;
/* ____l41 */
body_177:
  val = new_symbol(-41);
  global_c95c95c95c95c108c52c49 = val; /* ____l41 */
  goto body_178;
pointer global_c95c95c95c95c108c52c50;
/* ____l42 */
body_178:
  val = new_symbol(-42);
  global_c95c95c95c95c108c52c50 = val; /* ____l42 */
  goto body_179;
pointer global_c95c95c95c95c108c52c51;
/* ____l43 */
body_179:
  val = new_symbol(-42);
  global_c95c95c95c95c108c52c51 = val; /* ____l43 */
  goto body_180;
pointer global_c95c95c95c95c108c52c52;
/* ____l44 */
body_180:
  val = new_symbol(-45);
  global_c95c95c95c95c108c52c52 = val; /* ____l44 */
  goto body_181;
pointer global_c95c102c110c53c48;
function_499:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_500:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52c49 /* ____l41 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_499);
  goto apply_addr;
function_501:
  increment_count(env);
  val = wrap_function((&&function_500), env);
  goto pop_function;
/* _fn50 */
body_181:
  increment_count(env);
  val = wrap_function((&&function_501), env);
  global_c95c102c110c53c48 = val; /* _fn50 */
  goto body_182;
pointer global_c95c102c110c53c49;
function_502:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_503:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52c51 /* ____l43 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_502);
  goto apply_addr;
function_504:
  increment_count(env);
  val = wrap_function((&&function_503), env);
  goto pop_function;
/* _fn51 */
body_182:
  increment_count(env);
  val = wrap_function((&&function_504), env);
  global_c95c102c110c53c49 = val; /* _fn51 */
  goto body_183;
pointer global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101; /* rewrite-quasiquote */
pointer global_c95c102c110c53c50; /* _fn52 */
pointer global_c95c102c110c53c51;
function_505:
  goto top_level_apply;
function_506:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c50 /* _fn52 */);
  target = (&&function_505);
  goto apply_addr;
function_507:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c108c105c115c116 /* list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  target = (&&function_506);
  goto apply_addr;
function_508:
  increment_count(env);
  val = wrap_function((&&function_507), env);
  goto pop_function;
/* _fn53 */
body_183:
global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = nil(); /* rewrite-quasiquote */
global_c95c102c110c53c50 = nil(); /* _fn52 */
  increment_count(env);
  val = wrap_function((&&function_508), env);
  global_c95c102c110c53c51 = val; /* _fn53 */
  goto body_184;
function_509:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_510:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_509);
  goto apply_addr;
function_511:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52c52 /* ____l44 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_510);
  goto apply_addr;
function_512:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_511);
  goto apply_addr;
function_513:
  increment_count(env);
  val = wrap_function((&&function_512), env);
  goto pop_function;
/* _fn52 */
body_184:
  increment_count(env);
  val = wrap_function((&&function_513), env);
  global_c95c102c110c53c50 = val; /* _fn52 */
  goto body_185;
pointer global_c99c111c109c112c105c108c101c45c101c120c112c114; /* compile-expr */
function_514:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c55 /* ____l37 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  goto top_level_apply;
function_515:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_516:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_517:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (is_number(car(args))) {
    if ((is_binary(args)) &
        is_number(car(cdr(args)))) {
      val = new_number(value(car(args)) - 
                       value(car(cdr(args))));
    } else if (is_unary(args) == 1) {
      val = new_number(-value(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_516);
  goto apply_addr;
function_518:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
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
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c114 /* cadr */);
    target = (&&function_515);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c53c48 /* _fn50 */);
    target = (&&function_517);
    goto apply_addr;
  }
function_519:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_520:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if ((is_binary(args)) &
      (is_number(car(args))) &
      (is_number(car(cdr(args))))) {
    val = new_number(value(car(args)) + value(car(cdr(args)))); 
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_519);
  goto apply_addr;
function_521:
  goto top_level_apply;
function_522:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c53c51 /* _fn53 */);
  target = (&&function_521);
  goto apply_addr;
function_523:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c53c49 /* _fn51 */);
    target = (&&function_520);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c108c105c115c116 /* list */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
    target = (&&function_522);
    goto apply_addr;
  }
function_524:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(0);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_518);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c52c50 /* ____l42 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_523);
    goto apply_addr;
  }
function_525:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c57 /* ____l39 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c56 /* ____l38 */);
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_514);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c52c48 /* ____l40 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_524);
    goto apply_addr;
  }
function_526:
  args = cons(val, args);
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_525);
  goto apply_addr;
function_527:
  if (is_number(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c54 /* ____l36 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c53 /* ____l35 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_526);
    goto apply_addr;
  }
/* rewrite-quasiquote */
body_185:
global_c99c111c109c112c105c108c101c45c101c120c112c114 = nil(); /* compile-expr */
  increment_count(env);
  val = wrap_function((&&function_527), env);
  global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* rewrite-quasiquote */
  goto body_186;
pointer global_c95c95c95c95c108c52c53;
/* ____l45 */
body_186:
  val = new_symbol(-44);
  global_c95c95c95c95c108c52c53 = val; /* ____l45 */
  goto body_187;
pointer global_c95c95c95c95c108c52c54;
/* ____l46 */
body_187:
  val = new_symbol(-36);
  global_c95c95c95c95c108c52c54 = val; /* ____l46 */
  goto body_188;
pointer global_c95c95c95c95c108c52c55;
/* ____l47 */
body_188:
  val = nil();
  global_c95c95c95c95c108c52c55 = val; /* ____l47 */
  goto body_189;
pointer global_c95c95c95c95c108c52c56;
/* ____l48 */
body_189:
  val = nil();
  global_c95c95c95c95c108c52c56 = val; /* ____l48 */
  goto body_190;
pointer global_c97c108c119c97c121c115c45c116c114c117c101;
function_528:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    if (is_nil(cdr(car(car(env))))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    args = cons(val, args);
    increment_count(val = global_c110c111c116 /* not */);
    goto top_level_apply;
  } else {
    increment_count(val = global_c95c95c95c95c108c52c55 /* ____l47 */);
    goto pop_function;
  }
function_529:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c52c54 /* ____l46 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_528);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c95c108c52c56 /* ____l48 */);
    goto pop_function;
  }
function_530:
  if (is_number(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c95c108c52c53 /* ____l45 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_529);
    goto apply_addr;
  }
/* always-true */
body_190:
  increment_count(env);
  val = wrap_function((&&function_530), env);
  global_c97c108c119c97c121c115c45c116c114c117c101 = val; /* always-true */
  goto body_191;
pointer global_c95c95c95c95c108c52c57;
/* ____l49 */
body_191:
  val = new_symbol(-43);
  global_c95c95c95c95c108c52c57 = val; /* ____l49 */
  goto body_192;
pointer global_c95c95c95c95c108c53c48;
/* ____l50 */
body_192:
  val = nil();
  global_c95c95c95c95c108c53c48 = val; /* ____l50 */
  goto body_193;
pointer global_c95c95c95c95c108c53c49;
/* ____l51 */
body_193:
  val = nil();
  global_c95c95c95c95c108c53c49 = val; /* ____l51 */
  goto body_194;
pointer global_c95c95c95c95c108c53c50;
/* ____l52 */
body_194:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c53c50 = val; /* ____l52 */
  goto body_195;
pointer global_c95c102c110c53c53; /* _fn55 */
pointer global_c95c102c110c53c54;
function_531:
  goto top_level_apply;
function_532:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c53c53 /* _fn55 */);
  target = (&&function_531);
  goto apply_addr;
function_533:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_532);
  goto apply_addr;
function_534:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c108c105c115c116 /* list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c97c114 /* cadar */);
  target = (&&function_533);
  goto apply_addr;
function_535:
  increment_count(env);
  val = wrap_function((&&function_534), env);
  goto pop_function;
/* _fn56 */
body_195:
global_c95c102c110c53c53 = nil(); /* _fn55 */
  increment_count(env);
  val = wrap_function((&&function_535), env);
  global_c95c102c110c53c54 = val; /* _fn56 */
  goto body_196;
pointer global_c114c101c119c114c105c116c101c45c99c111c110c100; /* rewrite-cond */
pointer global_c95c102c110c53c52; /* _fn54 */
function_536:
  goto top_level_apply;
function_537:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c53c52 /* _fn54 */);
  target = (&&function_536);
  goto apply_addr;
function_538:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c108c105c115c116 /* list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c99c111c110c100 /* rewrite-cond */);
  target = (&&function_537);
  goto apply_addr;
function_539:
  increment_count(env);
  val = wrap_function((&&function_538), env);
  goto pop_function;
/* _fn55 */
body_196:
global_c114c101c119c114c105c116c101c45c99c111c110c100 = nil(); /* rewrite-cond */
global_c95c102c110c53c52 = nil(); /* _fn54 */
  increment_count(env);
  val = wrap_function((&&function_539), env);
  global_c95c102c110c53c53 = val; /* _fn55 */
  goto body_197;
function_540:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_541:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_540);
  goto apply_addr;
function_542:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52c57 /* ____l49 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_541);
  goto apply_addr;
function_543:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_542);
  goto apply_addr;
function_544:
  increment_count(env);
  val = wrap_function((&&function_543), env);
  goto pop_function;
/* _fn54 */
body_197:
  increment_count(env);
  val = wrap_function((&&function_544), env);
  global_c95c102c110c53c52 = val; /* _fn54 */
  goto body_198;
function_545:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_546:
  goto top_level_apply;
function_547:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c54 /* _fn56 */);
  target = (&&function_546);
  goto apply_addr;
function_548:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_547);
  goto apply_addr;
function_549:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c108c105c115c116 /* list */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c114 /* caar */);
    target = (&&function_548);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53c50 /* ____l52 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53c49 /* ____l51 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53c48 /* ____l50 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  }
function_550:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
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
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c97c114 /* cadar */);
    target = (&&function_545);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_549);
    goto apply_addr;
  }
function_551:
  args = cons(val, args);
  increment_count(val = global_c97c108c119c97c121c115c45c116c114c117c101 /* always-true */);
  target = (&&function_550);
  goto apply_addr;
function_552:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c97c114 /* caar */);
  target = (&&function_551);
  goto apply_addr;
/* rewrite-cond */
body_198:
  increment_count(env);
  val = wrap_function((&&function_552), env);
  global_c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* rewrite-cond */
  goto body_199;
pointer global_c95c95c95c95c108c53c51;
/* ____l53 */
body_199:
  val = new_symbol(-38);
  global_c95c95c95c95c108c53c51 = val; /* ____l53 */
  goto body_200;
pointer global_c114c101c119c114c105c116c101c45c108c101c116;
function_553:
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_554:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53c51 /* ____l53 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_553);
  goto apply_addr;
function_555:
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_554);
  goto apply_addr;
function_556:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c97c114 /* caar */);
  target = (&&function_555);
  goto apply_addr;
function_557:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c108c101c116 /* rewrite-let */);
  target = (&&function_556);
  goto apply_addr;
function_558:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c97c114 /* cadar */);
    target = (&&function_557);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_559:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_558);
  goto apply_addr;
/* rewrite-let */
body_200:
  increment_count(env);
  val = wrap_function((&&function_559), env);
  global_c114c101c119c114c105c116c101c45c108c101c116 = val; /* rewrite-let */
  goto body_201;
pointer global_c99c111c109c112c105c108c101c45c97c114c103c115; /* compile-args */
pointer global_c95c102c110c53c55; /* _fn57 */
pointer global_c95c102c110c53c56;
function_560:
  goto top_level_apply;
function_561:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c55 /* _fn57 */);
  target = (&&function_560);
  goto apply_addr;
function_562:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c108c105c115c116 /* list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c97c114c103c115 /* compile-args */);
  target = (&&function_561);
  goto apply_addr;
function_563:
  increment_count(env);
  val = wrap_function((&&function_562), env);
  goto pop_function;
/* _fn58 */
body_201:
global_c99c111c109c112c105c108c101c45c97c114c103c115 = nil(); /* compile-args */
global_c95c102c110c53c55 = nil(); /* _fn57 */
  increment_count(env);
  val = wrap_function((&&function_563), env);
  global_c95c102c110c53c56 = val; /* _fn58 */
  goto body_202;
function_564:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_565:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_564);
  goto apply_addr;
function_566:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_565);
  goto apply_addr;
function_567:
  increment_count(env);
  val = wrap_function((&&function_566), env);
  goto pop_function;
/* _fn57 */
body_202:
  increment_count(env);
  val = wrap_function((&&function_567), env);
  global_c95c102c110c53c55 = val; /* _fn57 */
  goto body_203;
function_568:
  goto top_level_apply;
function_569:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c56 /* _fn58 */);
  target = (&&function_568);
  goto apply_addr;
function_570:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c108c105c115c116 /* list */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
    target = (&&function_569);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
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
    increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
    goto top_level_apply;
  }
function_571:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_570);
  goto apply_addr;
/* compile-args */
body_203:
  increment_count(env);
  val = wrap_function((&&function_571), env);
  global_c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* compile-args */
  goto body_204;
pointer global_c95c95c95c95c108c53c52;
/* ____l54 */
body_204:
  val = nil();
  global_c95c95c95c95c108c53c52 = val; /* ____l54 */
  goto body_205;
pointer global_c95c95c95c95c108c53c53;
/* ____l55 */
body_205:
  val = nil();
  global_c95c95c95c95c108c53c53 = val; /* ____l55 */
  goto body_206;
pointer global_c95c95c95c95c108c53c54;
/* ____l56 */
body_206:
  val = new_symbol(-36);
  global_c95c95c95c95c108c53c54 = val; /* ____l56 */
  goto body_207;
pointer global_c95c95c95c95c108c53c55;
/* ____l57 */
body_207:
  val = new_symbol(-42);
  global_c95c95c95c95c108c53c55 = val; /* ____l57 */
  goto body_208;
pointer global_c95c95c95c95c108c53c56;
/* ____l58 */
body_208:
  val = new_symbol(-41);
  global_c95c95c95c95c108c53c56 = val; /* ____l58 */
  goto body_209;
pointer global_c95c95c95c95c108c53c57;
/* ____l59 */
body_209:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c53c57 = val; /* ____l59 */
  goto body_210;
pointer global_c95c95c95c95c108c54c48;
/* ____l60 */
body_210:
  val = new_symbol(-40);
  global_c95c95c95c95c108c54c48 = val; /* ____l60 */
  goto body_211;
pointer global_c95c95c95c95c108c54c49;
/* ____l61 */
body_211:
  val = new_symbol(-39);
  global_c95c95c95c95c108c54c49 = val; /* ____l61 */
  goto body_212;
pointer global_c95c95c95c95c108c54c50;
/* ____l62 */
body_212:
  val = new_symbol(-38);
  global_c95c95c95c95c108c54c50 = val; /* ____l62 */
  goto body_213;
pointer global_c95c95c95c95c108c54c51;
/* ____l63 */
body_213:
  val = new_symbol(-38);
  global_c95c95c95c95c108c54c51 = val; /* ____l63 */
  goto body_214;
pointer global_c95c102c110c53c57;
function_572:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_573:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53c57 /* ____l59 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_572);
  goto apply_addr;
function_574:
  increment_count(env);
  val = wrap_function((&&function_573), env);
  goto pop_function;
/* _fn59 */
body_214:
  increment_count(env);
  val = wrap_function((&&function_574), env);
  global_c95c102c110c53c57 = val; /* _fn59 */
  goto body_215;
pointer global_c95c102c110c54c48;
function_575:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_576:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c51 /* ____l63 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_575);
  goto apply_addr;
function_577:
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_576);
  goto apply_addr;
function_578:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_577);
  goto apply_addr;
function_579:
  increment_count(env);
  val = wrap_function((&&function_578), env);
  goto pop_function;
/* _fn60 */
body_215:
  increment_count(env);
  val = wrap_function((&&function_579), env);
  global_c95c102c110c54c48 = val; /* _fn60 */
  goto body_216;
function_580:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_581:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_582:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_581);
  goto apply_addr;
function_583:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_584:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c108c101c116 /* rewrite-let */);
  target = (&&function_583);
  goto apply_addr;
function_585:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_584);
  goto apply_addr;
function_586:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_587:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c100c114 /* caddr */);
  target = (&&function_586);
  goto apply_addr;
function_588:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_587);
  goto apply_addr;
function_589:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c54c48 /* _fn60 */);
    target = (&&function_588);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
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
    increment_count(val = global_c99c111c109c112c105c108c101c45c97c114c103c115 /* compile-args */);
    goto top_level_apply;
  }
function_590:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
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
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    target = (&&function_585);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c54c50 /* ____l62 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_589);
    goto apply_addr;
  }
function_591:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c119c114c105c116c101c45c99c111c110c100 /* rewrite-cond */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c54c49 /* ____l61 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_590);
    goto apply_addr;
  }
function_592:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c53c57 /* _fn59 */);
    target = (&&function_582);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c54c48 /* ____l60 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_591);
    goto apply_addr;
  }
function_593:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
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
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c114 /* cadr */);
    target = (&&function_580);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c56 /* ____l58 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_592);
    goto apply_addr;
  }
function_594:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c111c109c112c105c108c101c45c113c117c111c116c101 /* compile-quote */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c55 /* ____l57 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_593);
    goto apply_addr;
  }
function_595:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53c53 /* ____l55 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53c52 /* ____l54 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c54 /* ____l56 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_594);
    goto apply_addr;
  }
function_596:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
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
    increment_count(val = global_c99c111c109c112c105c108c101c45c102c105c110c100 /* compile-find */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    if (is_number(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    args = cons(val, args);
    if (is_nil(car(car(env)))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    args = cons(val, args);
    increment_count(val = global_c111c114 /* or */);
    target = (&&function_595);
    goto apply_addr;
  }
function_597:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_596);
  goto apply_addr;
/* compile-expr */
body_216:
  increment_count(env);
  val = wrap_function((&&function_597), env);
  global_c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* compile-expr */
  goto body_217;
pointer global_c103c101c116c45c110c97c109c101;
function_598:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c114 /* cadr */);
    goto top_level_apply;
  }
function_599:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_598);
  goto apply_addr;
function_600:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_599);
  goto apply_addr;
/* get-name */
body_217:
  increment_count(env);
  val = wrap_function((&&function_600), env);
  global_c103c101c116c45c110c97c109c101 = val; /* get-name */
  goto body_218;
pointer global_c95c95c95c95c108c54c52;
/* ____l64 */
body_218:
  val = new_symbol(-38);
  global_c95c95c95c95c108c54c52 = val; /* ____l64 */
  goto body_219;
pointer global_c103c101c116c45c98c111c100c121;
function_601:
  args = cons(val, args);
  if (is_unary(args)) {
    if (is_pair(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c52 /* ____l64 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_602:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_601);
  goto apply_addr;
function_603:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    target = (&&function_602);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    goto top_level_apply;
  }
function_604:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_603);
  goto apply_addr;
function_605:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_604);
  goto apply_addr;
/* get-body */
body_219:
  increment_count(env);
  val = wrap_function((&&function_605), env);
  global_c103c101c116c45c98c111c100c121 = val; /* get-body */
  goto body_220;
pointer global_c95c95c95c95c108c54c53;
/* ____l65 */
body_220:
  val = nil();
  global_c95c95c95c95c108c54c53 = val; /* ____l65 */
  goto body_221;
pointer global_c95c102c110c54c52; /* _fn64 */
pointer global_c95c102c110c54c53;
function_606:
  goto top_level_apply;
function_607:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c54c52 /* _fn64 */);
  target = (&&function_606);
  goto apply_addr;
function_608:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_607);
  goto apply_addr;
function_609:
  increment_count(env);
  val = wrap_function((&&function_608), env);
  goto pop_function;
/* _fn65 */
body_221:
global_c95c102c110c54c52 = nil(); /* _fn64 */
  increment_count(env);
  val = wrap_function((&&function_609), env);
  global_c95c102c110c54c53 = val; /* _fn65 */
  goto body_222;
pointer global_c95c102c110c54c51; /* _fn63 */
function_610:
  goto top_level_apply;
function_611:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
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
  increment_count(val = global_c95c102c110c54c51 /* _fn63 */);
  target = (&&function_610);
  goto apply_addr;
function_612:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c103c101c116c45c110c97c109c101 /* get-name */);
  target = (&&function_611);
  goto apply_addr;
function_613:
  increment_count(env);
  val = wrap_function((&&function_612), env);
  goto pop_function;
/* _fn64 */
body_222:
global_c95c102c110c54c51 = nil(); /* _fn63 */
  increment_count(env);
  val = wrap_function((&&function_613), env);
  global_c95c102c110c54c52 = val; /* _fn64 */
  goto body_223;
pointer global_c95c102c110c54c50; /* _fn62 */
function_614:
  goto top_level_apply;
function_615:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c54c50 /* _fn62 */);
  target = (&&function_614);
  goto apply_addr;
function_616:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c103c101c116c45c98c111c100c121 /* get-body */);
  target = (&&function_615);
  goto apply_addr;
function_617:
  increment_count(env);
  val = wrap_function((&&function_616), env);
  goto pop_function;
/* _fn63 */
body_223:
global_c95c102c110c54c50 = nil(); /* _fn62 */
  increment_count(env);
  val = wrap_function((&&function_617), env);
  global_c95c102c110c54c51 = val; /* _fn63 */
  goto body_224;
pointer global_c95c102c110c54c49; /* _fn61 */
function_618:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c53 /* ____l65 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_619:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54c49 /* _fn61 */);
  target = (&&function_618);
  goto apply_addr;
function_620:
  increment_count(env);
  val = wrap_function((&&function_619), env);
  goto pop_function;
/* _fn62 */
body_224:
global_c95c102c110c54c49 = nil(); /* _fn61 */
  increment_count(env);
  val = wrap_function((&&function_620), env);
  global_c95c102c110c54c50 = val; /* _fn62 */
  goto body_225;
function_621:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_622:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* print-warnings */);
  target = (&&function_621);
  goto apply_addr;
function_623:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c108c121 /* apply */);
  target = (&&function_622);
  goto apply_addr;
function_624:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* print-with-newline */);
  args = cons(val, args);
  increment_count(val = global_c109c97c112 /* map */);
  target = (&&function_623);
  goto apply_addr;
function_625:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* print-with-newline */);
  target = (&&function_624);
  goto apply_addr;
function_626:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_625);
  goto apply_addr;
function_627:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  target = (&&function_626);
  goto apply_addr;
function_628:
  increment_count(env);
  val = wrap_function((&&function_627), env);
  goto pop_function;
/* _fn61 */
body_225:
  increment_count(env);
  val = wrap_function((&&function_628), env);
  global_c95c102c110c54c49 = val; /* _fn61 */
  goto body_226;
pointer global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
function_629:
  goto top_level_apply;
function_630:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54c53 /* _fn65 */);
  target = (&&function_629);
  goto apply_addr;
/* compile-definition */
body_226:
  increment_count(env);
  val = wrap_function((&&function_630), env);
  global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* compile-definition */
  goto body_227;
pointer global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115; /* compile-definitions */
pointer global_c95c102c110c54c54;
function_631:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = cdr(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 /* compile-definitions */);
  goto top_level_apply;
function_632:
  increment_count(env);
  val = wrap_function((&&function_631), env);
  goto pop_function;
/* _fn66 */
body_227:
global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* compile-definitions */
  increment_count(env);
  val = wrap_function((&&function_632), env);
  global_c95c102c110c54c54 = val; /* _fn66 */
  goto body_228;
function_633:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 /* compile-definition */);
  goto top_level_apply;
function_634:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c54c54 /* _fn66 */);
    target = (&&function_633);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    goto top_level_apply;
  }
function_635:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_634);
  goto apply_addr;
/* compile-definitions */
body_228:
  increment_count(env);
  val = wrap_function((&&function_635), env);
  global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* compile-definitions */
  goto body_229;
pointer global_c95c95c95c95c108c54c54;
/* ____l66 */
body_229:
  val = nil();
  global_c95c95c95c95c108c54c54 = val; /* ____l66 */
  goto body_230;
pointer global_c95c95c95c95c108c54c55;
/* ____l67 */
body_230:
  val = nil();
  global_c95c95c95c95c108c54c55 = val; /* ____l67 */
  goto body_231;
pointer global_c95c102c110c54c56; /* _fn68 */
pointer global_c95c102c110c54c57;
function_636:
  goto top_level_apply;
function_637:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54c56 /* _fn68 */);
  target = (&&function_636);
  goto apply_addr;
function_638:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c108c105c115c116 /* list */);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c55 /* ____l67 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_637);
  goto apply_addr;
function_639:
  increment_count(env);
  val = wrap_function((&&function_638), env);
  goto pop_function;
/* _fn69 */
body_231:
global_c95c102c110c54c56 = nil(); /* _fn68 */
  increment_count(env);
  val = wrap_function((&&function_639), env);
  global_c95c102c110c54c57 = val; /* _fn69 */
  goto body_232;
pointer global_c95c102c110c54c55; /* _fn67 */
function_640:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 /* compile-definitions */);
  goto top_level_apply;
function_641:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54c55 /* _fn67 */);
  target = (&&function_640);
  goto apply_addr;
function_642:
  increment_count(env);
  val = wrap_function((&&function_641), env);
  goto pop_function;
/* _fn68 */
body_232:
global_c95c102c110c54c55 = nil(); /* _fn67 */
  increment_count(env);
  val = wrap_function((&&function_642), env);
  global_c95c102c110c54c56 = val; /* _fn68 */
  goto body_233;
function_643:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_644:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c54 /* ____l66 */);
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* print-warnings */);
  target = (&&function_643);
  goto apply_addr;
function_645:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c108c121 /* apply */);
  target = (&&function_644);
  goto apply_addr;
function_646:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* print-with-newline */);
  args = cons(val, args);
  increment_count(val = global_c109c97c112 /* map */);
  target = (&&function_645);
  goto apply_addr;
function_647:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* print-with-newline */);
  target = (&&function_646);
  goto apply_addr;
function_648:
  increment_count(env);
  val = wrap_function((&&function_647), env);
  goto pop_function;
/* _fn67 */
body_233:
  increment_count(env);
  val = wrap_function((&&function_648), env);
  global_c95c102c110c54c55 = val; /* _fn67 */
  goto body_234;
pointer global_c99c111c109c112c105c108c101;
function_649:
  goto top_level_apply;
function_650:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54c57 /* _fn69 */);
  target = (&&function_649);
  goto apply_addr;
function_651:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c103c101c116c45c110c97c109c101 /* get-name */);
  args = cons(val, args);
  increment_count(val = global_c109c97c112 /* map */);
  target = (&&function_650);
  goto apply_addr;
/* compile */
body_234:
  increment_count(env);
  val = wrap_function((&&function_651), env);
  global_c99c111c109c112c105c108c101 = val; /* compile */
  goto body_235;
pointer global_c114c101c97c100c45c115c116c114c105c110c103;
function_652:
  args = cons(val, args);
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c115c116c114c105c110c103 /* read-string */);
  goto top_level_apply;
function_653:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    target = (&&function_652);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_654:
  args = cons(val, args);
  increment_count(val = global_c97c110c100 /* and */);
  target = (&&function_653);
  goto apply_addr;
function_655:
  push_args();
  val = nil();
  args = val;
  if (is_function(car(cdr(car(env))))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_654);
  goto apply_addr;
/* read-string */
body_235:
  increment_count(env);
  val = wrap_function((&&function_655), env);
  global_c114c101c97c100c45c115c116c114c105c110c103 = val; /* read-string */
  goto body_236;
pointer global_c95c95c95c95c108c54c56;
/* ____l68 */
body_236:
  val = nil();
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
  val = new_number(102);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(69);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c54c56 = val; /* ____l68 */
  goto body_237;
pointer global_c95c95c95c95c108c54c57;
/* ____l69 */
body_237:
  val = nil();
  push_args();
  args = val;
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c54c57 = val; /* ____l69 */
  goto body_238;
pointer global_c95c95c95c95c108c55c48;
/* ____l70 */
body_238:
  val = nil();
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
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c48 = val; /* ____l70 */
  goto body_239;
pointer global_c95c95c95c95c108c55c49;
/* ____l71 */
body_239:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c49 = val; /* ____l71 */
  goto body_240;
pointer global_c95c95c95c95c108c55c50;
/* ____l72 */
body_240:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c50 = val; /* ____l72 */
  goto body_241;
pointer global_c102c105c108c101c45c114c101c97c100c101c114; /* file-reader */
pointer global_c95c102c110c55c48;
function_656:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c105c108c101c45c114c101c97c100c101c114 /* file-reader */);
  goto top_level_apply;
function_657:
  increment_count(env);
  val = wrap_function((&&function_656), env);
  goto pop_function;
/* _fn70 */
body_241:
global_c102c105c108c101c45c114c101c97c100c101c114 = nil(); /* file-reader */
  increment_count(env);
  val = wrap_function((&&function_657), env);
  global_c95c102c110c55c48 = val; /* _fn70 */
  goto body_242;
pointer global_c95c102c110c55c49;
function_658:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_659:
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
  goto top_level_apply;
function_660:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55c48 /* ____l70 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c57 /* ____l69 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_659);
  goto apply_addr;
function_661:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_658);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c55c50 /* ____l72 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c55c49 /* ____l71 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_660);
    goto apply_addr;
  }
function_662:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c54c56 /* ____l68 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
  target = (&&function_661);
  goto apply_addr;
function_663:
  increment_count(env);
  val = wrap_function((&&function_662), env);
  goto pop_function;
/* _fn71 */
body_242:
  increment_count(env);
  val = wrap_function((&&function_663), env);
  global_c95c102c110c55c49 = val; /* _fn71 */
  goto body_243;
function_664:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_665:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c48 /* _fn70 */);
  target = (&&function_664);
  goto apply_addr;
function_666:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c49 /* _fn71 */);
  target = (&&function_665);
  goto apply_addr;
/* file-reader */
body_243:
  increment_count(env);
  val = wrap_function((&&function_666), env);
  global_c102c105c108c101c45c114c101c97c100c101c114 = val; /* file-reader */
  goto body_244;
pointer global_c95c95c95c95c108c55c51;
/* ____l73 */
body_244:
  val = new_symbol(-37);
  global_c95c95c95c95c108c55c51 = val; /* ____l73 */
  goto body_245;
pointer global_c95c95c95c95c108c55c52;
/* ____l74 */
body_245:
  val = new_symbol(-36);
  global_c95c95c95c95c108c55c52 = val; /* ____l74 */
  goto body_246;
pointer global_c95c95c95c95c108c55c53;
/* ____l75 */
body_246:
  val = new_symbol(-35);
  global_c95c95c95c95c108c55c53 = val; /* ____l75 */
  goto body_247;
pointer global_c95c95c95c95c108c55c54;
/* ____l76 */
body_247:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c54 = val; /* ____l76 */
  goto body_248;
pointer global_c95c95c95c95c108c55c55;
/* ____l77 */
body_248:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c55 = val; /* ____l77 */
  goto body_249;
pointer global_c95c102c110c55c53; /* _fn75 */
pointer global_c95c102c110c55c54;
function_667:
  goto top_level_apply;
function_668:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c53 /* _fn75 */);
  target = (&&function_667);
  goto apply_addr;
function_669:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c114 /* caar */);
    target = (&&function_668);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_670:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_669);
  goto apply_addr;
function_671:
  increment_count(env);
  val = wrap_function((&&function_670), env);
  goto pop_function;
/* _fn76 */
body_249:
global_c95c102c110c55c53 = nil(); /* _fn75 */
  increment_count(env);
  val = wrap_function((&&function_671), env);
  global_c95c102c110c55c54 = val; /* _fn76 */
  goto body_250;
pointer global_c95c102c110c55c52; /* _fn74 */
function_672:
  goto top_level_apply;
function_673:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c55c52 /* _fn74 */);
  target = (&&function_672);
  goto apply_addr;
function_674:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c99c100c97c114 /* cdar */);
  target = (&&function_673);
  goto apply_addr;
function_675:
  increment_count(env);
  val = wrap_function((&&function_674), env);
  goto pop_function;
/* _fn75 */
body_250:
global_c95c102c110c55c52 = nil(); /* _fn74 */
  increment_count(env);
  val = wrap_function((&&function_675), env);
  global_c95c102c110c55c53 = val; /* _fn75 */
  goto body_251;
pointer global_c95c102c110c55c51; /* _fn73 */
function_676:
  goto top_level_apply;
function_677:
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
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
  increment_count(val = global_c95c102c110c55c51 /* _fn73 */);
  target = (&&function_676);
  goto apply_addr;
function_678:
  increment_count(env);
  val = wrap_function((&&function_677), env);
  goto pop_function;
/* _fn74 */
body_251:
global_c95c102c110c55c51 = nil(); /* _fn73 */
  increment_count(env);
  val = wrap_function((&&function_678), env);
  global_c95c102c110c55c52 = val; /* _fn74 */
  goto body_252;
pointer global_c108c111c97c100c45c114c101c116c117c114c110; /* load-return */
pointer global_c95c102c110c55c50; /* _fn72 */
pointer global_c108c111c97c100c45c100c101c102c105c110c105c116c105c111c110c115; /* load-definitions */
function_679:
  args = cons(val, args);
  increment_count(val = global_c108c111c97c100c45c100c101c102c105c110c105c116c105c111c110c115 /* load-definitions */);
  goto top_level_apply;
function_680:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c97c100c114 /* cadadr */);
  target = (&&function_679);
  goto apply_addr;
function_681:
  goto top_level_apply;
function_682:
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
  goto top_level_apply;
function_683:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55c54 /* ____l76 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_682);
  goto apply_addr;
function_684:
  goto top_level_apply;
function_685:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c55c55 /* ____l77 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_683);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    val = nil();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c108c111c97c100c45c114c101c116c117c114c110 /* load-return */);
    target = (&&function_684);
    goto apply_addr;
  }
function_686:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_685);
  goto apply_addr;
function_687:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_686);
  goto apply_addr;
function_688:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_687);
  goto apply_addr;
function_689:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_688);
  goto apply_addr;
function_690:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_689);
  goto apply_addr;
function_691:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c108c111c97c100c45c114c101c116c117c114c110 /* load-return */);
    target = (&&function_681);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    target = (&&function_690);
    goto apply_addr;
  }
function_692:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_691);
  goto apply_addr;
function_693:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c55c50 /* _fn72 */);
    target = (&&function_680);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c55c53 /* ____l75 */);
    args = cons(val, args);
    increment_count(val = car(car(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_692);
    goto apply_addr;
  }
function_694:
  args = cons(val, args);
  increment_count(val = global_c97c110c100 /* and */);
  target = (&&function_693);
  goto apply_addr;
function_695:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c55c51 /* ____l73 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_694);
  goto apply_addr;
function_696:
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_695);
  goto apply_addr;
function_697:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c55c52 /* ____l74 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c97c97c100c114 /* caadr */);
  target = (&&function_696);
  goto apply_addr;
function_698:
  increment_count(env);
  val = wrap_function((&&function_697), env);
  goto pop_function;
/* _fn73 */
body_252:
global_c108c111c97c100c45c114c101c116c117c114c110 = nil(); /* load-return */
global_c95c102c110c55c50 = nil(); /* _fn72 */
global_c108c111c97c100c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* load-definitions */
  increment_count(env);
  val = wrap_function((&&function_698), env);
  global_c95c102c110c55c51 = val; /* _fn73 */
  goto body_253;
function_699:
  goto top_level_apply;
function_700:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c108c111c97c100c45c114c101c116c117c114c110 /* load-return */);
  target = (&&function_699);
  goto apply_addr;
function_701:
  increment_count(env);
  val = wrap_function((&&function_700), env);
  goto pop_function;
/* _fn72 */
body_253:
  increment_count(env);
  val = wrap_function((&&function_701), env);
  global_c95c102c110c55c50 = val; /* _fn72 */
  goto body_254;
function_702:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c54 /* _fn76 */);
  goto top_level_apply;
/* load-return */
body_254:
  increment_count(env);
  val = wrap_function((&&function_702), env);
  global_c108c111c97c100c45c114c101c116c117c114c110 = val; /* load-return */
  goto body_255;
pointer global_c95c95c95c95c108c55c56;
/* ____l78 */
body_255:
  val = nil();
  global_c95c95c95c95c108c55c56 = val; /* ____l78 */
  goto body_256;
pointer global_c95c102c110c55c57; /* _fn79 */
pointer global_c95c102c110c56c48;
function_703:
  goto top_level_apply;
function_704:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c57 /* _fn79 */);
  target = (&&function_703);
  goto apply_addr;
function_705:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55c56 /* ____l78 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c105c108c101c45c114c101c97c100c101c114 /* file-reader */);
  target = (&&function_704);
  goto apply_addr;
function_706:
  increment_count(env);
  val = wrap_function((&&function_705), env);
  goto pop_function;
/* _fn80 */
body_256:
global_c95c102c110c55c57 = nil(); /* _fn79 */
  increment_count(env);
  val = wrap_function((&&function_706), env);
  global_c95c102c110c56c48 = val; /* _fn80 */
  goto body_257;
pointer global_c95c102c110c55c56; /* _fn78 */
pointer global_c95c102c110c55c55; /* _fn77 */
function_707:
  goto top_level_apply;
function_708:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c55 /* _fn77 */);
  target = (&&function_707);
  goto apply_addr;
function_709:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55c56 /* _fn78 */);
  target = (&&function_708);
  goto apply_addr;
function_710:
  increment_count(env);
  val = wrap_function((&&function_709), env);
  goto pop_function;
/* _fn79 */
body_257:
global_c95c102c110c55c56 = nil(); /* _fn78 */
global_c95c102c110c55c55 = nil(); /* _fn77 */
  increment_count(env);
  val = wrap_function((&&function_710), env);
  global_c95c102c110c55c57 = val; /* _fn79 */
  goto body_258;
function_711:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c119c105c116c104c45c102c105c108c101c45c99c111c110c116c101c110c116c115 /* with-file-contents */);
  goto top_level_apply;
function_712:
  increment_count(env);
  val = wrap_function((&&function_711), env);
  goto pop_function;
/* _fn77 */
body_258:
  increment_count(env);
  val = wrap_function((&&function_712), env);
  global_c95c102c110c55c55 = val; /* _fn77 */
  goto body_259;
function_713:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c115c116c114c105c110c103 /* read-string */);
  goto top_level_apply;
function_714:
  increment_count(env);
  val = wrap_function((&&function_713), env);
  goto pop_function;
/* _fn78 */
body_259:
  increment_count(env);
  val = wrap_function((&&function_714), env);
  global_c95c102c110c55c56 = val; /* _fn78 */
  goto body_260;
function_715:
  goto top_level_apply;
function_716:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c56c48 /* _fn80 */);
  target = (&&function_715);
  goto apply_addr;
function_717:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c108c111c97c100c45c114c101c116c117c114c110 /* load-return */);
    target = (&&function_716);
    goto apply_addr;
  }
function_718:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_717);
  goto apply_addr;
/* load-definitions */
body_260:
  increment_count(env);
  val = wrap_function((&&function_718), env);
  global_c108c111c97c100c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* load-definitions */
  goto body_261;
pointer global_c95c95c95c95c108c55c57;
/* ____l79 */
body_261:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55c57 = val; /* ____l79 */
  goto body_262;
pointer global_c95c95c95c95c108c56c48;
/* ____l80 */
body_262:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56c48 = val; /* ____l80 */
  goto body_263;
pointer global_c95c95c95c95c108c56c49;
/* ____l81 */
body_263:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56c49 = val; /* ____l81 */
  goto body_264;
pointer global_c95c102c110c56c49;
function_719:
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
  goto top_level_apply;
function_720:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55c57 /* ____l79 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_719);
  goto apply_addr;
function_721:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c56c49 /* ____l81 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c56c48 /* ____l80 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_720);
  goto apply_addr;
/* _fn81 */
body_264:
  increment_count(env);
  val = wrap_function((&&function_721), env);
  global_c95c102c110c56c49 = val; /* _fn81 */
  goto body_265;
pointer global_c114c101c97c100c45c101c120c112c114;
function_722:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c56c49 /* _fn81 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
/* read-expr */
body_265:
  increment_count(env);
  val = wrap_function((&&function_722), env);
  global_c114c101c97c100c45c101c120c112c114 = val; /* read-expr */
  goto body_266;
pointer global_c95c95c95c95c108c56c50;
/* ____l82 */
body_266:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56c50 = val; /* ____l82 */
  goto body_267;
pointer global_c95c95c95c95c108c56c51;
/* ____l83 */
body_267:
  val = new_symbol(-37);
  global_c95c95c95c95c108c56c51 = val; /* ____l83 */
  goto body_268;
pointer global_c95c95c95c95c108c56c52;
/* ____l84 */
body_268:
  val = new_symbol(-36);
  global_c95c95c95c95c108c56c52 = val; /* ____l84 */
  goto body_269;
pointer global_c95c95c95c95c108c56c53;
/* ____l85 */
body_269:
  val = new_symbol(-35);
  global_c95c95c95c95c108c56c53 = val; /* ____l85 */
  goto body_270;
pointer global_c95c95c95c95c108c56c54;
/* ____l86 */
body_270:
  val = nil();
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
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56c54 = val; /* ____l86 */
  goto body_271;
pointer global_c95c95c95c95c108c56c55;
/* ____l87 */
body_271:
  val = nil();
  global_c95c95c95c95c108c56c55 = val; /* ____l87 */
  goto body_272;
pointer global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* compile-source */
pointer global_c95c102c110c56c50; /* _fn82 */
pointer global_c95c102c110c56c51;
function_723:
  args = cons(val, args);
  increment_count(val = global_c108c111c97c100c45c100c101c102c105c110c105c116c105c111c110c115 /* load-definitions */);
  goto top_level_apply;
function_724:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c97c100c114 /* cadadr */);
  target = (&&function_723);
  goto apply_addr;
function_725:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101 /* compile */);
  goto top_level_apply;
function_726:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_727:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_726);
  goto apply_addr;
function_728:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c56c54 /* ____l86 */);
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c56c55 /* ____l87 */);
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_727);
    goto apply_addr;
  }
function_729:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_728);
  goto apply_addr;
function_730:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_729);
  goto apply_addr;
function_731:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_730);
  goto apply_addr;
function_732:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_731);
  goto apply_addr;
function_733:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_732);
  goto apply_addr;
function_734:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_725);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    target = (&&function_733);
    goto apply_addr;
  }
function_735:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_734);
  goto apply_addr;
function_736:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c56c50 /* _fn82 */);
    target = (&&function_724);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c56c53 /* ____l85 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_735);
    goto apply_addr;
  }
function_737:
  args = cons(val, args);
  increment_count(val = global_c97c110c100 /* and */);
  target = (&&function_736);
  goto apply_addr;
function_738:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c56c51 /* ____l83 */);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_737);
  goto apply_addr;
function_739:
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_738);
  goto apply_addr;
function_740:
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c56c50 /* ____l82 */);
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c56c52 /* ____l84 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    target = (&&function_739);
    goto apply_addr;
  }
function_741:
  increment_count(env);
  val = wrap_function((&&function_740), env);
  goto pop_function;
/* _fn83 */
body_272:
global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = nil(); /* compile-source */
global_c95c102c110c56c50 = nil(); /* _fn82 */
  increment_count(env);
  val = wrap_function((&&function_741), env);
  global_c95c102c110c56c51 = val; /* _fn83 */
  goto body_273;
function_742:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_743:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_742);
  goto apply_addr;
function_744:
  increment_count(env);
  val = wrap_function((&&function_743), env);
  goto pop_function;
/* _fn82 */
body_273:
  increment_count(env);
  val = wrap_function((&&function_744), env);
  global_c95c102c110c56c50 = val; /* _fn82 */
  goto body_274;
function_745:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c56c51 /* _fn83 */);
  goto top_level_apply;
/* compile-source */
body_274:
  increment_count(env);
  val = wrap_function((&&function_745), env);
  global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* compile-source */
  goto body_275;
pointer global_c95c95c95c95c108c49;
/* ____l1 */
body_275:
  val = nil();
  global_c95c95c95c95c108c49 = val; /* ____l1 */
  goto body_276;
pointer global_c95c95c95c95c108c50;
/* ____l2 */
body_276:
  val = nil();
  global_c95c95c95c95c108c50 = val; /* ____l2 */
  goto body_277;
top_level_addr:
  while (is_pair(val)) {
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
    if (! is_nil(input)) {
      env = cons(cons(input, nil()), env);
    } else {
      env = cons(nil(), env);
    }
    call_stack = cons(wrap_function(&&top_level_addr,
                                    nil()),
                     call_stack);
  } else {
    target = &&end_function_addr;
  }
  goto *target;
end_function_addr:
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
    env = nil();
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
    val = nil();
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
    val = nil();
  }
  pop_args();
  goto *target;
function_746:
  if (is_function(val)) {
    increment_count(env=function_environment(val));
    env = cons(cons(free_memory_size(),
                   cons(arguments,nil())),
               env);
    target = function_target(val, &&end_function_addr);
    decrement_count(val);
  } else {
    error(ERR_NO_OS);
    env = nil();
    target = &&end_function_addr;
  }
  goto *target;
function_747:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_748:
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50 /* ____l2 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49 /* ____l1 */);
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_747);
  goto apply_addr;
body_277:
  increment_count(env);
  val = wrap_function((&&function_748), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_746), nil()), call_stack);
  goto body_0;
}
