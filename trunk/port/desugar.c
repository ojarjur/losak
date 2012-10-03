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
    val = new_number(94);
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
    val = new_number(124);
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
    val = new_number(38);
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
    val = new_number(126);
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
    val = new_number(37);
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
    val = new_number(47);
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
    val = new_number(42);
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
    val = new_number(45);
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
    val = new_number(43);
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
    val = new_number(62);
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
    val = new_number(60);
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
    val = new_number(61);
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
    target = (&&function_82);
    goto apply_addr;
  }
function_84:
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
  target = (&&function_83);
  goto apply_addr;
/* string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_84), env);
  global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_85:
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
            val = new_symbol(-39);
            goto pop_function;
          } else {
            val = nil();
            goto pop_function;
          }
        } else {
          val = new_symbol(-39);
          goto pop_function;
        }
      }
    }
  }
/* __symbol? */
body_3:
  increment_count(env);
  val = wrap_function((&&function_85), env);
  global_c95c95c115c121c109c98c111c108c63 = val; /* __symbol? */
  goto body_4;
pointer global_c95c95c112c97c105c114c63;
function_86:
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
      val = new_symbol(-39);
      goto pop_function;
    }
  } else {
    val = nil();
    goto pop_function;
  }
/* __pair? */
body_4:
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c61;
function_87:
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
function_88:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_87);
  goto apply_addr;
/* __= */
body_5:
  increment_count(env);
  val = wrap_function((&&function_88), env);
  global_c95c95c61 = val; /* __= */
  goto body_6;
pointer global_c95c95c95c95c108c50;
/* ____l2 */
body_6:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c50 = val; /* ____l2 */
  goto body_7;
pointer global_c105c100;
function_89:
  increment_count(val = car(car(env)));
  goto pop_function;
/* id */
body_7:
  increment_count(env);
  val = wrap_function((&&function_89), env);
  global_c105c100 = val; /* id */
  goto body_8;
pointer global_c95c95c95c119c97c108c107; /* ___walk */
pointer global_c95c102c110c48;
function_90:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_91:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_90);
  goto apply_addr;
function_92:
  target = (&&function_91);
  goto apply_addr;
function_93:
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
  target = (&&function_92);
  goto apply_addr;
function_94:
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
    target = (&&function_93);
    goto apply_addr;
  }
function_95:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_94);
  goto apply_addr;
function_96:
  increment_count(env);
  val = wrap_function((&&function_95), env);
  goto pop_function;
/* _fn0 */
body_8:
global_c95c95c95c119c97c108c107 = nil(); /* ___walk */
  increment_count(env);
  val = wrap_function((&&function_96), env);
  global_c95c102c110c48 = val; /* _fn0 */
  goto body_9;
function_97:
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
  val = wrap_function((&&function_97), env);
  global_c95c95c95c119c97c108c107 = val; /* ___walk */
  goto body_10;
pointer global_c95c95c95c114c114c101c118c101c114c115c101;
function_98:
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
function_99:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_98);
  goto apply_addr;
/* ___rreverse */
body_10:
  increment_count(env);
  val = wrap_function((&&function_99), env);
  global_c95c95c95c114c114c101c118c101c114c115c101 = val; /* ___rreverse */
  goto body_11;
pointer global_c102c111c108c100c108; /* foldl */
pointer global_c95c102c110c49;
function_100:
  goto top_level_apply;
function_101:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c108 /* foldl */);
  target = (&&function_100);
  goto apply_addr;
function_102:
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
    target = (&&function_101);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
  }
function_103:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_102);
  goto apply_addr;
function_104:
  increment_count(env);
  val = wrap_function((&&function_103), env);
  goto pop_function;
/* _fn1 */
body_11:
global_c102c111c108c100c108 = nil(); /* foldl */
  increment_count(env);
  val = wrap_function((&&function_104), env);
  global_c95c102c110c49 = val; /* _fn1 */
  goto body_12;
function_105:
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
  val = wrap_function((&&function_105), env);
  global_c102c111c108c100c108 = val; /* foldl */
  goto body_13;
pointer global_c95c102c110c50;
function_106:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101 /* ___rreverse */);
  goto top_level_apply;
function_107:
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
  target = (&&function_106);
  goto apply_addr;
function_108:
  increment_count(env);
  val = wrap_function((&&function_107), env);
  goto pop_function;
/* _fn2 */
body_13:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c95c102c110c50 = val; /* _fn2 */
  goto body_14;
pointer global_c102c111c108c100c114;
function_109:
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
  val = wrap_function((&&function_109), env);
  global_c102c111c108c100c114 = val; /* foldr */
  goto body_15;
pointer global_c95c102c110c51;
function_110:
  goto top_level_apply;
function_111:
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
function_112:
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
    val = wrap_function((&&function_111), env);
    args = cons(val, args);
    increment_count(val = global_c102c111c108c100c114 /* foldr */);
    target = (&&function_110);
    goto apply_addr;
  }
/* _fn3 */
body_15:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c95c102c110c51 = val; /* _fn3 */
  goto body_16;
pointer global_c97c112c112c101c110c100;
function_113:
  goto top_level_apply;
function_114:
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
  target = (&&function_113);
  goto apply_addr;
/* append */
body_16:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  global_c97c112c112c101c110c100 = val; /* append */
  goto body_17;
pointer global_c95c102c110c52;
function_115:
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
  val = wrap_function((&&function_115), env);
  global_c95c102c110c52 = val; /* _fn4 */
  goto body_18;
pointer global_c95c102c110c53;
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
      val = new_number(value(car(args)) / 
                       value(car(cdr(args))));
    }
  } else { val = nil(); }
  pop_args();
  goto pop_function;
/* _fn5 */
body_18:
  increment_count(env);
  val = wrap_function((&&function_116), env);
  global_c95c102c110c53 = val; /* _fn5 */
  goto body_19;
pointer global_c95c102c110c54;
function_117:
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
  val = wrap_function((&&function_117), env);
  global_c95c102c110c54 = val; /* _fn6 */
  goto body_20;
pointer global_c95c102c110c55; /* _fn7 */
pointer global_c95c102c110c56;
function_118:
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
  val = wrap_function((&&function_118), env);
  global_c95c102c110c56 = val; /* _fn8 */
  goto body_21;
function_119:
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
function_120:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  goto pop_function;
/* _fn7 */
body_21:
  increment_count(env);
  val = wrap_function((&&function_120), env);
  global_c95c102c110c55 = val; /* _fn7 */
  goto body_22;
pointer global_c95c102c110c57;
function_121:
  increment_count(val = global_c105c100 /* id */);
  goto pop_function;
/* _fn9 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_121), env);
  global_c95c102c110c57 = val; /* _fn9 */
  goto body_23;
pointer global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_122:
  goto top_level_apply;
function_123:
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
  target = (&&function_122);
  goto apply_addr;
/* ___build-num-str */
body_23:
  increment_count(env);
  val = wrap_function((&&function_123), env);
  global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* ___build-num-str */
  goto body_24;
pointer global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103;
function_124:
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
function_125:
  target = (&&function_124);
  goto apply_addr;
function_126:
  goto top_level_apply;
function_127:
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
      target = (&&function_125);
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
      target = (&&function_126);
      goto apply_addr;
    }
  }
function_128:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_127);
  goto apply_addr;
/* number->string */
body_24:
  increment_count(env);
  val = wrap_function((&&function_128), env);
  global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103 = val; /* number->string */
  goto body_25;
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* ___print-with-suffix */
pointer global_c95c95c95c112c114c105c110c116c45c116c97c105c108;
function_129:
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
function_130:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_129);
  goto apply_addr;
function_131:
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
function_132:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_131);
  goto apply_addr;
function_133:
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
    target = (&&function_130);
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
    target = (&&function_132);
    goto apply_addr;
  }
function_134:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_133);
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
  val = wrap_function((&&function_134), env);
  global_c95c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* ___print-tail */
  goto body_26;
pointer global_c112c114c105c110c116; /* print */
function_135:
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
function_136:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_135);
  goto apply_addr;
function_137:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_138:
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
    target = (&&function_136);
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
    target = (&&function_137);
    goto apply_addr;
  }
function_139:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_138);
  goto apply_addr;
/* ___print-with-suffix */
body_26:
global_c112c114c105c110c116 = nil(); /* print */
  increment_count(env);
  val = wrap_function((&&function_139), env);
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* ___print-with-suffix */
  goto body_27;
function_140:
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
function_141:
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
    target = (&&function_140);
    goto apply_addr;
  }
function_142:
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
      target = (&&function_141);
      goto apply_addr;
    }
  }
/* print */
body_27:
  increment_count(env);
  val = wrap_function((&&function_142), env);
  global_c112c114c105c110c116 = val; /* print */
  goto body_28;
pointer global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
function_143:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_144:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c50 /* ____l2 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_143);
  goto apply_addr;
/* print-with-newline */
body_28:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* print-with-newline */
  goto body_29;
pointer global_c108c105c115c116;
function_145:
  increment_count(val = car(env));
  goto pop_function;
/* list */
body_29:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  global_c108c105c115c116 = val; /* list */
  goto body_30;
pointer global_c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_146:
  global_c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* map-to-stderr */
  goto body_31;
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
  target = (&&function_147);
  goto apply_addr;
/* map-to-stderr */
body_30:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_148), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_146);
  goto apply_addr;
pointer global_c95c95c95c95c108c51;
/* ____l3 */
body_31:
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
  global_c95c95c95c95c108c51 = val; /* ____l3 */
  goto body_32;
pointer global_c95c95c95c95c108c52;
/* ____l4 */
body_32:
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(73);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c52 = val; /* ____l4 */
  goto body_33;
pointer global_c95c95c95c95c108c53;
/* ____l5 */
body_33:
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
  global_c95c95c95c95c108c53 = val; /* ____l5 */
  goto body_34;
pointer global_c95c95c95c95c108c54;
/* ____l6 */
body_34:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c54 = val; /* ____l6 */
  goto body_35;
pointer global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_149:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_150:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52 /* ____l4 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51 /* ____l3 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_149);
  goto apply_addr;
function_151:
  increment_count(val = car(cdr(car(env))));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c54 /* ____l6 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c53 /* ____l5 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_150);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
/* print-warnings */
body_35:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* print-warnings */
  goto body_36;
pointer global_c95c95c95c95c108c55;
/* ____l7 */
body_36:
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
  global_c95c95c95c95c108c55 = val; /* ____l7 */
  goto body_37;
pointer global_c95c95c95c95c108c56;
/* ____l8 */
body_37:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c56 = val; /* ____l8 */
  goto body_38;
pointer global_c112c114c105c110c116c45c101c114c114c111c114;
function_152:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_153:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c56 /* ____l8 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c55 /* ____l7 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_152);
  goto apply_addr;
/* print-error */
body_38:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  global_c112c114c105c110c116c45c101c114c114c111c114 = val; /* print-error */
  goto body_39;
pointer global_c95c95c95c95c108c57;
/* ____l9 */
body_39:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-40);
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c57 = val; /* ____l9 */
  goto body_40;
pointer global_c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* special-forms */
body_40:
  increment_count(val = global_c95c95c95c95c108c57 /* ____l9 */);
  global_c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* special-forms */
  goto body_41;
pointer global_c95c95c95c95c108c49c48;
/* ____l10 */
body_41:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-91);
  args = cons(val, args);
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
  val = new_symbol(-44);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c48 = val; /* ____l10 */
  goto body_42;
pointer global_c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* supported-builtins */
body_42:
  increment_count(val = global_c95c95c95c95c108c49c48 /* ____l10 */);
  global_c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* supported-builtins */
  goto body_43;
pointer global_c102c108c97c116c116c101c110;
function_154:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  goto top_level_apply;
function_155:
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
      target = (&&function_154);
      goto apply_addr;
    }
  }
function_156:
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
    target = (&&function_155);
    goto apply_addr;
  }
/* flatten */
body_43:
  increment_count(env);
  val = wrap_function((&&function_156), env);
  global_c102c108c97c116c116c101c110 = val; /* flatten */
  goto body_44;
pointer global_c95c95c95c95c108c49c49;
/* ____l11 */
body_44:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-45);
  args = cons(val, args);
  val = new_symbol(-46);
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  val = new_symbol(-48);
  args = cons(val, args);
  val = new_symbol(-49);
  args = cons(val, args);
  val = new_symbol(-50);
  args = cons(val, args);
  val = new_symbol(-51);
  args = cons(val, args);
  val = new_symbol(-52);
  args = cons(val, args);
  val = new_symbol(-53);
  args = cons(val, args);
  val = new_symbol(-54);
  args = cons(val, args);
  val = new_symbol(-55);
  args = cons(val, args);
  val = new_symbol(-56);
  args = cons(val, args);
  val = new_symbol(-57);
  args = cons(val, args);
  val = new_symbol(-58);
  args = cons(val, args);
  val = new_symbol(-59);
  args = cons(val, args);
  val = new_symbol(-60);
  args = cons(val, args);
  val = new_symbol(-61);
  args = cons(val, args);
  val = new_symbol(-62);
  args = cons(val, args);
  val = new_symbol(-63);
  args = cons(val, args);
  val = new_symbol(-64);
  args = cons(val, args);
  val = new_symbol(-65);
  args = cons(val, args);
  val = new_symbol(-66);
  args = cons(val, args);
  val = new_symbol(-67);
  args = cons(val, args);
  val = new_symbol(-68);
  args = cons(val, args);
  val = new_symbol(-69);
  args = cons(val, args);
  val = new_symbol(-70);
  args = cons(val, args);
  val = new_symbol(-71);
  args = cons(val, args);
  val = new_symbol(-72);
  args = cons(val, args);
  val = new_symbol(-73);
  args = cons(val, args);
  val = new_symbol(-74);
  args = cons(val, args);
  val = new_symbol(-75);
  args = cons(val, args);
  val = new_symbol(-76);
  args = cons(val, args);
  val = new_symbol(-77);
  args = cons(val, args);
  val = new_symbol(-78);
  args = cons(val, args);
  val = new_symbol(-79);
  args = cons(val, args);
  val = new_symbol(-80);
  args = cons(val, args);
  val = new_symbol(-81);
  args = cons(val, args);
  val = new_symbol(-82);
  args = cons(val, args);
  val = new_symbol(-83);
  args = cons(val, args);
  val = new_symbol(-84);
  args = cons(val, args);
  val = new_symbol(-85);
  args = cons(val, args);
  val = new_symbol(-86);
  args = cons(val, args);
  val = new_symbol(-87);
  args = cons(val, args);
  val = new_symbol(-88);
  args = cons(val, args);
  val = new_symbol(-89);
  args = cons(val, args);
  val = new_symbol(-90);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c49c49 = val; /* ____l11 */
  goto body_45;
pointer global_c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115;
/* supported-library-procedures */
body_45:
  increment_count(val = global_c95c95c95c95c108c49c49 /* ____l11 */);
  global_c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 = val; /* supported-library-procedures */
  goto body_46;
pointer global_c95c102c110c49c48;
function_157:
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
function_158:
  push_args();
  val = nil();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_157);
  goto apply_addr;
function_159:
  increment_count(env);
  val = wrap_function((&&function_158), env);
  goto pop_function;
/* _fn10 */
body_46:
  increment_count(env);
  val = wrap_function((&&function_159), env);
  global_c95c102c110c49c48 = val; /* _fn10 */
  goto body_47;
pointer global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_160:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_161:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_160);
  goto apply_addr;
function_162:
  goto top_level_apply;
function_163:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c48 /* _fn10 */);
  target = (&&function_162);
  goto apply_addr;
function_164:
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
    target = (&&function_163);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_165:
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
    target = (&&function_161);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_164);
    goto apply_addr;
  }
function_166:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_165);
  goto apply_addr;
/* escape-symbols */
body_47:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* escape-symbols */
  goto body_48;
pointer global_c95c95c95c95c108c49c50;
/* ____l12 */
body_48:
  val = nil();
  global_c95c95c95c95c108c49c50 = val; /* ____l12 */
  goto body_49;
pointer global_c95c95c95c95c108c49c51;
/* ____l13 */
body_49:
  val = nil();
  global_c95c95c95c95c108c49c51 = val; /* ____l13 */
  goto body_50;
pointer global_c95c95c95c95c108c49c52;
/* ____l14 */
body_50:
  val = nil();
  global_c95c95c95c95c108c49c52 = val; /* ____l14 */
  goto body_51;
pointer global_c95c95c95c95c108c49c53;
/* ____l15 */
body_51:
  val = nil();
  global_c95c95c95c95c108c49c53 = val; /* ____l15 */
  goto body_52;
pointer global_c95c95c95c95c108c49c54;
/* ____l16 */
body_52:
  val = nil();
  global_c95c95c95c95c108c49c54 = val; /* ____l16 */
  goto body_53;
pointer global_c95c95c95c95c108c49c55;
/* ____l17 */
body_53:
  val = nil();
  global_c95c95c95c95c108c49c55 = val; /* ____l17 */
  goto body_54;
pointer global_c95c95c95c95c108c49c56;
/* ____l18 */
body_54:
  val = nil();
  global_c95c95c95c95c108c49c56 = val; /* ____l18 */
  goto body_55;
pointer global_c95c95c95c95c108c49c57;
/* ____l19 */
body_55:
  val = nil();
  global_c95c95c95c95c108c49c57 = val; /* ____l19 */
  goto body_56;
pointer global_c95c95c95c95c108c50c48;
/* ____l20 */
body_56:
  val = nil();
  global_c95c95c95c95c108c50c48 = val; /* ____l20 */
  goto body_57;
pointer global_c95c95c95c95c108c50c49;
/* ____l21 */
body_57:
  val = nil();
  global_c95c95c95c95c108c50c49 = val; /* ____l21 */
  goto body_58;
pointer global_c95c95c95c95c108c50c50;
/* ____l22 */
body_58:
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
  global_c95c95c95c95c108c50c50 = val; /* ____l22 */
  goto body_59;
pointer global_c95c95c95c95c108c50c51;
/* ____l23 */
body_59:
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
  global_c95c95c95c95c108c50c51 = val; /* ____l23 */
  goto body_60;
pointer global_c95c95c101c113c117c97c108;
function_167:
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
function_168:
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
    target = (&&function_167);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_169:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_168);
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
function_170:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_169);
  goto apply_addr;
/* __equal */
body_60:
  increment_count(env);
  val = wrap_function((&&function_170), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_61;
pointer global_c109c101c109c98c101c114;
function_171:
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
function_172:
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
    target = (&&function_171);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_173:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_172);
  goto apply_addr;
/* member */
body_61:
  increment_count(env);
  val = wrap_function((&&function_173), env);
  global_c109c101c109c98c101c114 = val; /* member */
  goto body_62;
pointer global_c99c111c109c112c105c108c101c45c102c105c110c100;
function_174:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49c50 /* ____l12 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_175:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c49 /* ____l21 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c48 /* ____l20 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_176:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c50 /* ____l22 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_175);
  goto apply_addr;
function_177:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c57 /* ____l19 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c56 /* ____l18 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c50c51 /* ____l23 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* symbol->string */);
    target = (&&function_176);
    goto apply_addr;
  }
function_178:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c55 /* ____l17 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c54 /* ____l16 */);
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
    target = (&&function_177);
    goto apply_addr;
  }
function_179:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c53 /* ____l15 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c52 /* ____l14 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 /* supported-library-procedures */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    target = (&&function_178);
    goto apply_addr;
  }
function_180:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c51 /* ____l13 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
    target = (&&function_174);
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
    target = (&&function_179);
    goto apply_addr;
  }
function_181:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_180);
  goto apply_addr;
function_182:
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
  target = (&&function_181);
  goto apply_addr;
/* compile-find */
body_62:
  increment_count(env);
  val = wrap_function((&&function_182), env);
  global_c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* compile-find */
  goto body_63;
pointer global_c95c95c95c95c108c50c52;
/* ____l24 */
body_63:
  val = new_symbol(-38);
  global_c95c95c95c95c108c50c52 = val; /* ____l24 */
  goto body_64;
pointer global_c95c95c95c95c108c50c53;
/* ____l25 */
body_64:
  val = new_symbol(-44);
  global_c95c95c95c95c108c50c53 = val; /* ____l25 */
  goto body_65;
pointer global_c114c101c119c114c105c116c101c45c113c117c111c116c101;
function_183:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c53 /* ____l25 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_184:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c111c116c101 /* rewrite-quote */);
  target = (&&function_183);
  goto apply_addr;
function_185:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c52 /* ____l24 */);
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
    target = (&&function_184);
    goto apply_addr;
  }
function_186:
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
      target = (&&function_185);
      goto apply_addr;
    }
  }
/* rewrite-quote */
body_65:
  increment_count(env);
  val = wrap_function((&&function_186), env);
  global_c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* rewrite-quote */
  goto body_66;
pointer global_c95c95c95c95c108c50c54;
/* ____l26 */
body_66:
  val = nil();
  global_c95c95c95c95c108c50c54 = val; /* ____l26 */
  goto body_67;
pointer global_c95c95c95c95c108c50c55;
/* ____l27 */
body_67:
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
  global_c95c95c95c95c108c50c55 = val; /* ____l27 */
  goto body_68;
pointer global_c95c102c110c49c49;
function_187:
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
  increment_count(val = global_c95c95c95c95c108c50c54 /* ____l26 */);
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
function_188:
  increment_count(env);
  val = wrap_function((&&function_187), env);
  goto pop_function;
/* _fn11 */
body_68:
  increment_count(env);
  val = wrap_function((&&function_188), env);
  global_c95c102c110c49c49 = val; /* _fn11 */
  goto body_69;
pointer global_c99c111c109c112c105c108c101c45c113c117c111c116c101;
function_189:
  goto top_level_apply;
function_190:
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
  increment_count(val = global_c95c102c110c49c49 /* _fn11 */);
  target = (&&function_189);
  goto apply_addr;
function_191:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_190);
  goto apply_addr;
function_192:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c55 /* ____l27 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_191);
  goto apply_addr;
function_193:
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
  target = (&&function_192);
  goto apply_addr;
/* compile-quote */
body_69:
  increment_count(env);
  val = wrap_function((&&function_193), env);
  global_c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* compile-quote */
  goto body_70;
pointer global_c95c95c95c95c108c50c56;
/* ____l28 */
body_70:
  val = nil();
  global_c95c95c95c95c108c50c56 = val; /* ____l28 */
  goto body_71;
pointer global_c95c95c95c95c108c50c57;
/* ____l29 */
body_71:
  val = nil();
  global_c95c95c95c95c108c50c57 = val; /* ____l29 */
  goto body_72;
pointer global_c95c95c95c95c108c51c48;
/* ____l30 */
body_72:
  val = nil();
  global_c95c95c95c95c108c51c48 = val; /* ____l30 */
  goto body_73;
pointer global_c95c95c95c95c108c51c49;
/* ____l31 */
body_73:
  val = new_symbol(-38);
  global_c95c95c95c95c108c51c49 = val; /* ____l31 */
  goto body_74;
pointer global_c95c95c95c95c108c51c50;
/* ____l32 */
body_74:
  val = nil();
  global_c95c95c95c95c108c51c50 = val; /* ____l32 */
  goto body_75;
pointer global_c95c95c95c95c108c51c51;
/* ____l33 */
body_75:
  val = new_symbol(-37);
  global_c95c95c95c95c108c51c51 = val; /* ____l33 */
  goto body_76;
pointer global_c95c95c95c95c108c51c52;
/* ____l34 */
body_76:
  val = new_symbol(-37);
  global_c95c95c95c95c108c51c52 = val; /* ____l34 */
  goto body_77;
pointer global_c95c95c95c95c108c51c53;
/* ____l35 */
body_77:
  val = new_symbol(-36);
  global_c95c95c95c95c108c51c53 = val; /* ____l35 */
  goto body_78;
pointer global_c95c95c95c95c108c51c54;
/* ____l36 */
body_78:
  val = new_symbol(-36);
  global_c95c95c95c95c108c51c54 = val; /* ____l36 */
  goto body_79;
pointer global_c95c95c95c95c108c51c55;
/* ____l37 */
body_79:
  val = new_symbol(-44);
  global_c95c95c95c95c108c51c55 = val; /* ____l37 */
  goto body_80;
pointer global_c99c97c100c114;
function_194:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* cadr */
body_80:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  global_c99c97c100c114 = val; /* cadr */
  goto body_81;
pointer global_c95c102c110c49c50;
function_195:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
/* _fn12 */
body_81:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c95c102c110c49c50 = val; /* _fn12 */
  goto body_82;
pointer global_c111c114;
function_196:
  goto top_level_apply;
function_197:
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
  increment_count(val = global_c95c102c110c49c50 /* _fn12 */);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_196);
  goto apply_addr;
/* or */
body_82:
  increment_count(env);
  val = wrap_function((&&function_197), env);
  global_c111c114 = val; /* or */
  goto body_83;
pointer global_c95c102c110c49c51;
function_198:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_199:
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
  increment_count(val = global_c95c95c95c95c108c51c52 /* ____l34 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_198);
  goto apply_addr;
function_200:
  increment_count(env);
  val = wrap_function((&&function_199), env);
  goto pop_function;
/* _fn13 */
body_83:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  global_c95c102c110c49c51 = val; /* _fn13 */
  goto body_84;
pointer global_c95c102c110c49c52;
function_201:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_202:
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
  increment_count(val = global_c95c95c95c95c108c51c54 /* ____l36 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_201);
  goto apply_addr;
function_203:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  goto pop_function;
/* _fn14 */
body_84:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  global_c95c102c110c49c52 = val; /* _fn14 */
  goto body_85;
pointer global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101; /* rewrite-quasiquote */
pointer global_c95c102c110c49c53; /* _fn15 */
pointer global_c95c102c110c49c54;
function_204:
  goto top_level_apply;
function_205:
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
  increment_count(val = global_c95c102c110c49c53 /* _fn15 */);
  target = (&&function_204);
  goto apply_addr;
function_206:
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
  target = (&&function_205);
  goto apply_addr;
function_207:
  increment_count(env);
  val = wrap_function((&&function_206), env);
  goto pop_function;
/* _fn16 */
body_85:
global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = nil(); /* rewrite-quasiquote */
global_c95c102c110c49c53 = nil(); /* _fn15 */
  increment_count(env);
  val = wrap_function((&&function_207), env);
  global_c95c102c110c49c54 = val; /* _fn16 */
  goto body_86;
function_208:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_209:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_208);
  goto apply_addr;
function_210:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c55 /* ____l37 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_209);
  goto apply_addr;
function_211:
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
  target = (&&function_210);
  goto apply_addr;
function_212:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  goto pop_function;
/* _fn15 */
body_86:
  increment_count(env);
  val = wrap_function((&&function_212), env);
  global_c95c102c110c49c53 = val; /* _fn15 */
  goto body_87;
pointer global_c99c111c109c112c105c108c101c45c101c120c112c114; /* compile-expr */
function_213:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c51c48 /* ____l30 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  goto top_level_apply;
function_214:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_215:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_216:
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
  target = (&&function_215);
  goto apply_addr;
function_217:
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
    target = (&&function_214);
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
    increment_count(val = global_c95c102c110c49c51 /* _fn13 */);
    target = (&&function_216);
    goto apply_addr;
  }
function_218:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_219:
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
  target = (&&function_218);
  goto apply_addr;
function_220:
  goto top_level_apply;
function_221:
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
  increment_count(val = global_c95c102c110c49c54 /* _fn16 */);
  target = (&&function_220);
  goto apply_addr;
function_222:
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
    increment_count(val = global_c95c102c110c49c52 /* _fn14 */);
    target = (&&function_219);
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
    target = (&&function_221);
    goto apply_addr;
  }
function_223:
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
    target = (&&function_217);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c51c53 /* ____l35 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c50 /* ____l32 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51c49 /* ____l31 */);
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_213);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c51c51 /* ____l33 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_223);
    goto apply_addr;
  }
function_225:
  args = cons(val, args);
  if (is_nil(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_224);
  goto apply_addr;
function_226:
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
    increment_count(val = global_c95c95c95c95c108c50c57 /* ____l29 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c56 /* ____l28 */);
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
    target = (&&function_225);
    goto apply_addr;
  }
/* rewrite-quasiquote */
body_87:
global_c99c111c109c112c105c108c101c45c101c120c112c114 = nil(); /* compile-expr */
  increment_count(env);
  val = wrap_function((&&function_226), env);
  global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* rewrite-quasiquote */
  goto body_88;
pointer global_c95c95c95c95c108c51c56;
/* ____l38 */
body_88:
  val = new_symbol(-39);
  global_c95c95c95c95c108c51c56 = val; /* ____l38 */
  goto body_89;
pointer global_c95c95c95c95c108c51c57;
/* ____l39 */
body_89:
  val = new_symbol(-38);
  global_c95c95c95c95c108c51c57 = val; /* ____l39 */
  goto body_90;
pointer global_c95c95c95c95c108c52c48;
/* ____l40 */
body_90:
  val = nil();
  global_c95c95c95c95c108c52c48 = val; /* ____l40 */
  goto body_91;
pointer global_c95c95c95c95c108c52c49;
/* ____l41 */
body_91:
  val = nil();
  global_c95c95c95c95c108c52c49 = val; /* ____l41 */
  goto body_92;
pointer global_c110c111c116;
function_227:
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
body_92:
  increment_count(env);
  val = wrap_function((&&function_227), env);
  global_c110c111c116 = val; /* not */
  goto body_93;
pointer global_c97c108c119c97c121c115c45c116c114c117c101;
function_228:
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
    increment_count(val = global_c95c95c95c95c108c52c48 /* ____l40 */);
    goto pop_function;
  }
function_229:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c51c57 /* ____l39 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_228);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c95c108c52c49 /* ____l41 */);
    goto pop_function;
  }
function_230:
  if (is_number(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c95c108c51c56 /* ____l38 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_229);
    goto apply_addr;
  }
/* always-true */
body_93:
  increment_count(env);
  val = wrap_function((&&function_230), env);
  global_c97c108c119c97c121c115c45c116c114c117c101 = val; /* always-true */
  goto body_94;
pointer global_c95c95c95c95c108c52c50;
/* ____l42 */
body_94:
  val = new_symbol(-43);
  global_c95c95c95c95c108c52c50 = val; /* ____l42 */
  goto body_95;
pointer global_c95c95c95c95c108c52c51;
/* ____l43 */
body_95:
  val = nil();
  global_c95c95c95c95c108c52c51 = val; /* ____l43 */
  goto body_96;
pointer global_c95c95c95c95c108c52c52;
/* ____l44 */
body_96:
  val = nil();
  global_c95c95c95c95c108c52c52 = val; /* ____l44 */
  goto body_97;
pointer global_c95c95c95c95c108c52c53;
/* ____l45 */
body_97:
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
  global_c95c95c95c95c108c52c53 = val; /* ____l45 */
  goto body_98;
pointer global_c99c97c97c114;
function_231:
  increment_count(val = car(car(car(car(env)))));
  goto pop_function;
/* caar */
body_98:
  increment_count(env);
  val = wrap_function((&&function_231), env);
  global_c99c97c97c114 = val; /* caar */
  goto body_99;
pointer global_c99c97c100c97c114;
function_232:
  increment_count(val = car(cdr(car(car(car(env))))));
  goto pop_function;
/* cadar */
body_99:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c99c97c100c97c114 = val; /* cadar */
  goto body_100;
pointer global_c95c102c110c49c56; /* _fn18 */
pointer global_c95c102c110c49c57;
function_233:
  goto top_level_apply;
function_234:
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
  increment_count(val = global_c95c102c110c49c56 /* _fn18 */);
  target = (&&function_233);
  goto apply_addr;
function_235:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_234);
  goto apply_addr;
function_236:
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
  target = (&&function_235);
  goto apply_addr;
function_237:
  increment_count(env);
  val = wrap_function((&&function_236), env);
  goto pop_function;
/* _fn19 */
body_100:
global_c95c102c110c49c56 = nil(); /* _fn18 */
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c95c102c110c49c57 = val; /* _fn19 */
  goto body_101;
pointer global_c114c101c119c114c105c116c101c45c99c111c110c100; /* rewrite-cond */
pointer global_c95c102c110c49c55; /* _fn17 */
function_238:
  goto top_level_apply;
function_239:
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
  increment_count(val = global_c95c102c110c49c55 /* _fn17 */);
  target = (&&function_238);
  goto apply_addr;
function_240:
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
  target = (&&function_239);
  goto apply_addr;
function_241:
  increment_count(env);
  val = wrap_function((&&function_240), env);
  goto pop_function;
/* _fn18 */
body_101:
global_c114c101c119c114c105c116c101c45c99c111c110c100 = nil(); /* rewrite-cond */
global_c95c102c110c49c55 = nil(); /* _fn17 */
  increment_count(env);
  val = wrap_function((&&function_241), env);
  global_c95c102c110c49c56 = val; /* _fn18 */
  goto body_102;
function_242:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_243:
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
  target = (&&function_242);
  goto apply_addr;
function_244:
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
  increment_count(val = global_c95c95c95c95c108c52c50 /* ____l42 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_243);
  goto apply_addr;
function_245:
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
  target = (&&function_244);
  goto apply_addr;
function_246:
  increment_count(env);
  val = wrap_function((&&function_245), env);
  goto pop_function;
/* _fn17 */
body_102:
  increment_count(env);
  val = wrap_function((&&function_246), env);
  global_c95c102c110c49c55 = val; /* _fn17 */
  goto body_103;
function_247:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_248:
  goto top_level_apply;
function_249:
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
  increment_count(val = global_c95c102c110c49c57 /* _fn19 */);
  target = (&&function_248);
  goto apply_addr;
function_250:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_249);
  goto apply_addr;
function_251:
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
    target = (&&function_250);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52c53 /* ____l45 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52c52 /* ____l44 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52c51 /* ____l43 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  }
function_252:
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
    target = (&&function_247);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_251);
    goto apply_addr;
  }
function_253:
  args = cons(val, args);
  increment_count(val = global_c97c108c119c97c121c115c45c116c114c117c101 /* always-true */);
  target = (&&function_252);
  goto apply_addr;
function_254:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c97c114 /* caar */);
  target = (&&function_253);
  goto apply_addr;
/* rewrite-cond */
body_103:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* rewrite-cond */
  goto body_104;
pointer global_c95c95c95c95c108c52c54;
/* ____l46 */
body_104:
  val = new_symbol(-40);
  global_c95c95c95c95c108c52c54 = val; /* ____l46 */
  goto body_105;
pointer global_c114c101c119c114c105c116c101c45c108c101c116;
function_255:
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_256:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c52c54 /* ____l46 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_255);
  goto apply_addr;
function_257:
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_256);
  goto apply_addr;
function_258:
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
  target = (&&function_257);
  goto apply_addr;
function_259:
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
  target = (&&function_258);
  goto apply_addr;
function_260:
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
    target = (&&function_259);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_261:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_260);
  goto apply_addr;
/* rewrite-let */
body_105:
  increment_count(env);
  val = wrap_function((&&function_261), env);
  global_c114c101c119c114c105c116c101c45c108c101c116 = val; /* rewrite-let */
  goto body_106;
pointer global_c99c111c109c112c105c108c101c45c97c114c103c115; /* compile-args */
pointer global_c95c102c110c50c48; /* _fn20 */
pointer global_c95c102c110c50c49;
function_262:
  goto top_level_apply;
function_263:
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
  increment_count(val = global_c95c102c110c50c48 /* _fn20 */);
  target = (&&function_262);
  goto apply_addr;
function_264:
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
  target = (&&function_263);
  goto apply_addr;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* _fn21 */
body_106:
global_c99c111c109c112c105c108c101c45c97c114c103c115 = nil(); /* compile-args */
global_c95c102c110c50c48 = nil(); /* _fn20 */
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c95c102c110c50c49 = val; /* _fn21 */
  goto body_107;
function_266:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_267:
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
  target = (&&function_266);
  goto apply_addr;
function_268:
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
  target = (&&function_267);
  goto apply_addr;
function_269:
  increment_count(env);
  val = wrap_function((&&function_268), env);
  goto pop_function;
/* _fn20 */
body_107:
  increment_count(env);
  val = wrap_function((&&function_269), env);
  global_c95c102c110c50c48 = val; /* _fn20 */
  goto body_108;
function_270:
  goto top_level_apply;
function_271:
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
  increment_count(val = global_c95c102c110c50c49 /* _fn21 */);
  target = (&&function_270);
  goto apply_addr;
function_272:
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
    target = (&&function_271);
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
function_273:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_272);
  goto apply_addr;
/* compile-args */
body_108:
  increment_count(env);
  val = wrap_function((&&function_273), env);
  global_c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* compile-args */
  goto body_109;
pointer global_c95c95c95c95c108c52c55;
/* ____l47 */
body_109:
  val = nil();
  global_c95c95c95c95c108c52c55 = val; /* ____l47 */
  goto body_110;
pointer global_c95c95c95c95c108c52c56;
/* ____l48 */
body_110:
  val = nil();
  global_c95c95c95c95c108c52c56 = val; /* ____l48 */
  goto body_111;
pointer global_c95c95c95c95c108c52c57;
/* ____l49 */
body_111:
  val = new_symbol(-38);
  global_c95c95c95c95c108c52c57 = val; /* ____l49 */
  goto body_112;
pointer global_c95c95c95c95c108c53c48;
/* ____l50 */
body_112:
  val = new_symbol(-36);
  global_c95c95c95c95c108c53c48 = val; /* ____l50 */
  goto body_113;
pointer global_c95c95c95c95c108c53c49;
/* ____l51 */
body_113:
  val = new_symbol(-37);
  global_c95c95c95c95c108c53c49 = val; /* ____l51 */
  goto body_114;
pointer global_c95c95c95c95c108c53c50;
/* ____l52 */
body_114:
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
  global_c95c95c95c95c108c53c50 = val; /* ____l52 */
  goto body_115;
pointer global_c95c95c95c95c108c53c51;
/* ____l53 */
body_115:
  val = new_symbol(-42);
  global_c95c95c95c95c108c53c51 = val; /* ____l53 */
  goto body_116;
pointer global_c95c95c95c95c108c53c52;
/* ____l54 */
body_116:
  val = new_symbol(-41);
  global_c95c95c95c95c108c53c52 = val; /* ____l54 */
  goto body_117;
pointer global_c95c95c95c95c108c53c53;
/* ____l55 */
body_117:
  val = new_symbol(-40);
  global_c95c95c95c95c108c53c53 = val; /* ____l55 */
  goto body_118;
pointer global_c95c95c95c95c108c53c54;
/* ____l56 */
body_118:
  val = new_symbol(-40);
  global_c95c95c95c95c108c53c54 = val; /* ____l56 */
  goto body_119;
pointer global_c99c97c100c100c114;
function_274:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* caddr */
body_119:
  increment_count(env);
  val = wrap_function((&&function_274), env);
  global_c99c97c100c100c114 = val; /* caddr */
  goto body_120;
pointer global_c95c102c110c50c50;
function_275:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_276:
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
  increment_count(val = global_c95c95c95c95c108c53c50 /* ____l52 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_275);
  goto apply_addr;
function_277:
  increment_count(env);
  val = wrap_function((&&function_276), env);
  goto pop_function;
/* _fn22 */
body_120:
  increment_count(env);
  val = wrap_function((&&function_277), env);
  global_c95c102c110c50c50 = val; /* _fn22 */
  goto body_121;
pointer global_c95c102c110c50c51;
function_278:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_279:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53c54 /* ____l56 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_278);
  goto apply_addr;
function_280:
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_279);
  goto apply_addr;
function_281:
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
  target = (&&function_280);
  goto apply_addr;
function_282:
  increment_count(env);
  val = wrap_function((&&function_281), env);
  goto pop_function;
/* _fn23 */
body_121:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  global_c95c102c110c50c51 = val; /* _fn23 */
  goto body_122;
function_283:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* rewrite-quasiquote */);
  goto top_level_apply;
function_284:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_285:
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
  target = (&&function_284);
  goto apply_addr;
function_286:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_287:
  args = cons(val, args);
  increment_count(val = global_c114c101c119c114c105c116c101c45c108c101c116 /* rewrite-let */);
  target = (&&function_286);
  goto apply_addr;
function_288:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_287);
  goto apply_addr;
function_289:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_290:
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
  target = (&&function_289);
  goto apply_addr;
function_291:
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
  target = (&&function_290);
  goto apply_addr;
function_292:
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
    increment_count(val = global_c95c102c110c50c51 /* _fn23 */);
    target = (&&function_291);
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
function_293:
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
    target = (&&function_288);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c53 /* ____l55 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_292);
    goto apply_addr;
  }
function_294:
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
    increment_count(val = global_c95c95c95c95c108c53c52 /* ____l54 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_293);
    goto apply_addr;
  }
function_295:
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
    increment_count(val = global_c95c102c110c50c50 /* _fn22 */);
    target = (&&function_285);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c51 /* ____l53 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_294);
    goto apply_addr;
  }
function_296:
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
    target = (&&function_283);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c53c49 /* ____l51 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_295);
    goto apply_addr;
  }
function_297:
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
    increment_count(val = global_c95c95c95c95c108c53c48 /* ____l50 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_296);
    goto apply_addr;
  }
function_298:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52c56 /* ____l48 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c52c55 /* ____l47 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c52c57 /* ____l49 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_297);
    goto apply_addr;
  }
function_299:
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
    target = (&&function_298);
    goto apply_addr;
  }
function_300:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_299);
  goto apply_addr;
/* compile-expr */
body_122:
  increment_count(env);
  val = wrap_function((&&function_300), env);
  global_c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* compile-expr */
  goto body_123;
pointer global_c99c97c97c100c114;
function_301:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* caadr */
body_123:
  increment_count(env);
  val = wrap_function((&&function_301), env);
  global_c99c97c97c100c114 = val; /* caadr */
  goto body_124;
pointer global_c103c101c116c45c110c97c109c101;
function_302:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c114 /* cadr */);
    goto top_level_apply;
  }
function_303:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_302);
  goto apply_addr;
function_304:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_303);
  goto apply_addr;
/* get-name */
body_124:
  increment_count(env);
  val = wrap_function((&&function_304), env);
  global_c103c101c116c45c110c97c109c101 = val; /* get-name */
  goto body_125;
pointer global_c95c95c95c95c108c53c55;
/* ____l57 */
body_125:
  val = new_symbol(-40);
  global_c95c95c95c95c108c53c55 = val; /* ____l57 */
  goto body_126;
pointer global_c103c101c116c45c98c111c100c121;
function_305:
  args = cons(val, args);
  if (is_unary(args)) {
    if (is_pair(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53c55 /* ____l57 */);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  goto top_level_apply;
function_306:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_305);
  goto apply_addr;
function_307:
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
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    target = (&&function_306);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    goto top_level_apply;
  }
function_308:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_307);
  goto apply_addr;
function_309:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_308);
  goto apply_addr;
/* get-body */
body_126:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  global_c103c101c116c45c98c111c100c121 = val; /* get-body */
  goto body_127;
pointer global_c95c95c95c95c108c53c56;
/* ____l58 */
body_127:
  val = nil();
  global_c95c95c95c95c108c53c56 = val; /* ____l58 */
  goto body_128;
pointer global_c97c112c112c108c121;
function_310:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* apply */
body_128:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c97c112c112c108c121 = val; /* apply */
  goto body_129;
pointer global_c95c102c110c50c52;
function_311:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_312:
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
  target = (&&function_311);
  goto apply_addr;
function_313:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  goto pop_function;
/* _fn24 */
body_129:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c95c102c110c50c52 = val; /* _fn24 */
  goto body_130;
pointer global_c109c97c112;
function_314:
  goto top_level_apply;
function_315:
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_314);
  goto apply_addr;
function_316:
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
  increment_count(val = global_c95c102c110c50c52 /* _fn24 */);
  target = (&&function_315);
  goto apply_addr;
/* map */
body_130:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  global_c109c97c112 = val; /* map */
  goto body_131;
pointer global_c95c102c110c50c55; /* _fn27 */
pointer global_c95c102c110c50c56;
function_317:
  goto top_level_apply;
function_318:
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
  increment_count(val = global_c95c102c110c50c55 /* _fn27 */);
  target = (&&function_317);
  goto apply_addr;
function_319:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c103c101c116c45c110c97c109c101 /* get-name */);
  target = (&&function_318);
  goto apply_addr;
function_320:
  increment_count(env);
  val = wrap_function((&&function_319), env);
  goto pop_function;
/* _fn28 */
body_131:
global_c95c102c110c50c55 = nil(); /* _fn27 */
  increment_count(env);
  val = wrap_function((&&function_320), env);
  global_c95c102c110c50c56 = val; /* _fn28 */
  goto body_132;
pointer global_c95c102c110c50c54; /* _fn26 */
function_321:
  goto top_level_apply;
function_322:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c50c54 /* _fn26 */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c103c101c116c45c98c111c100c121 /* get-body */);
  target = (&&function_322);
  goto apply_addr;
function_324:
  increment_count(env);
  val = wrap_function((&&function_323), env);
  goto pop_function;
/* _fn27 */
body_132:
global_c95c102c110c50c54 = nil(); /* _fn26 */
  increment_count(env);
  val = wrap_function((&&function_324), env);
  global_c95c102c110c50c55 = val; /* _fn27 */
  goto body_133;
pointer global_c95c102c110c50c53; /* _fn25 */
function_325:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53c56 /* ____l58 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  goto top_level_apply;
function_326:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c53 /* _fn25 */);
  target = (&&function_325);
  goto apply_addr;
function_327:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  goto pop_function;
/* _fn26 */
body_133:
global_c95c102c110c50c53 = nil(); /* _fn25 */
  increment_count(env);
  val = wrap_function((&&function_327), env);
  global_c95c102c110c50c54 = val; /* _fn26 */
  goto body_134;
function_328:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_329:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* print-warnings */);
  target = (&&function_328);
  goto apply_addr;
function_330:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c108c121 /* apply */);
  target = (&&function_329);
  goto apply_addr;
function_331:
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
  target = (&&function_330);
  goto apply_addr;
function_332:
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
  target = (&&function_331);
  goto apply_addr;
function_333:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_332);
  goto apply_addr;
function_334:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_333);
  goto apply_addr;
function_335:
  increment_count(env);
  val = wrap_function((&&function_334), env);
  goto pop_function;
/* _fn25 */
body_134:
  increment_count(env);
  val = wrap_function((&&function_335), env);
  global_c95c102c110c50c53 = val; /* _fn25 */
  goto body_135;
pointer global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
function_336:
  goto top_level_apply;
function_337:
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
  increment_count(val = global_c95c102c110c50c56 /* _fn28 */);
  target = (&&function_336);
  goto apply_addr;
/* compile-definition */
body_135:
  increment_count(env);
  val = wrap_function((&&function_337), env);
  global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* compile-definition */
  goto body_136;
pointer global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115; /* compile-definitions */
pointer global_c95c102c110c50c57;
function_338:
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
function_339:
  increment_count(env);
  val = wrap_function((&&function_338), env);
  goto pop_function;
/* _fn29 */
body_136:
global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* compile-definitions */
  increment_count(env);
  val = wrap_function((&&function_339), env);
  global_c95c102c110c50c57 = val; /* _fn29 */
  goto body_137;
function_340:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 /* compile-definition */);
  goto top_level_apply;
function_341:
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
    increment_count(val = global_c95c102c110c50c57 /* _fn29 */);
    target = (&&function_340);
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
function_342:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_341);
  goto apply_addr;
/* compile-definitions */
body_137:
  increment_count(env);
  val = wrap_function((&&function_342), env);
  global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* compile-definitions */
  goto body_138;
pointer global_c95c95c95c95c108c53c57;
/* ____l59 */
body_138:
  val = nil();
  global_c95c95c95c95c108c53c57 = val; /* ____l59 */
  goto body_139;
pointer global_c95c102c110c51c49; /* _fn31 */
pointer global_c95c102c110c51c50;
function_343:
  goto top_level_apply;
function_344:
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
  increment_count(val = global_c95c102c110c51c49 /* _fn31 */);
  target = (&&function_343);
  goto apply_addr;
function_345:
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
  increment_count(val = global_c95c95c95c95c108c53c57 /* ____l59 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c101c120c112c114 /* compile-expr */);
  target = (&&function_344);
  goto apply_addr;
function_346:
  increment_count(env);
  val = wrap_function((&&function_345), env);
  goto pop_function;
/* _fn32 */
body_139:
global_c95c102c110c51c49 = nil(); /* _fn31 */
  increment_count(env);
  val = wrap_function((&&function_346), env);
  global_c95c102c110c51c50 = val; /* _fn32 */
  goto body_140;
pointer global_c95c102c110c51c48; /* _fn30 */
function_347:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 /* compile-definitions */);
  goto top_level_apply;
function_348:
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
  increment_count(val = global_c95c102c110c51c48 /* _fn30 */);
  target = (&&function_347);
  goto apply_addr;
function_349:
  increment_count(env);
  val = wrap_function((&&function_348), env);
  goto pop_function;
/* _fn31 */
body_140:
global_c95c102c110c51c48 = nil(); /* _fn30 */
  increment_count(env);
  val = wrap_function((&&function_349), env);
  global_c95c102c110c51c49 = val; /* _fn31 */
  goto body_141;
function_350:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_351:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* print-warnings */);
  target = (&&function_350);
  goto apply_addr;
function_352:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c108c121 /* apply */);
  target = (&&function_351);
  goto apply_addr;
function_353:
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
  target = (&&function_352);
  goto apply_addr;
function_354:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* print-with-newline */);
  target = (&&function_353);
  goto apply_addr;
function_355:
  increment_count(env);
  val = wrap_function((&&function_354), env);
  goto pop_function;
/* _fn30 */
body_141:
  increment_count(env);
  val = wrap_function((&&function_355), env);
  global_c95c102c110c51c48 = val; /* _fn30 */
  goto body_142;
pointer global_c99c111c109c112c105c108c101;
function_356:
  goto top_level_apply;
function_357:
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
  increment_count(val = global_c95c102c110c51c50 /* _fn32 */);
  target = (&&function_356);
  goto apply_addr;
function_358:
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
  target = (&&function_357);
  goto apply_addr;
/* compile */
body_142:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  global_c99c111c109c112c105c108c101 = val; /* compile */
  goto body_143;
pointer global_c95c95c95c95c108c54c48;
/* ____l60 */
body_143:
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
  global_c95c95c95c95c108c54c48 = val; /* ____l60 */
  goto body_144;
pointer global_c95c95c95c95c108c54c49;
/* ____l61 */
body_144:
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
  global_c95c95c95c95c108c54c49 = val; /* ____l61 */
  goto body_145;
pointer global_c95c95c95c95c108c54c50;
/* ____l62 */
body_145:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c54c50 = val; /* ____l62 */
  goto body_146;
pointer global_c114c101c118c101c114c115c101;
function_359:
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
body_146:
  increment_count(env);
  val = wrap_function((&&function_359), env);
  global_c114c101c118c101c114c115c101 = val; /* reverse */
  goto body_147;
pointer global_c95c102c110c51c51;
function_360:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
/* _fn33 */
body_147:
  increment_count(env);
  val = wrap_function((&&function_360), env);
  global_c95c102c110c51c51 = val; /* _fn33 */
  goto body_148;
pointer global_c97c110c100;
function_361:
  goto top_level_apply;
function_362:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-39);
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c51 /* _fn33 */);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_361);
  goto apply_addr;
/* and */
body_148:
  increment_count(env);
  val = wrap_function((&&function_362), env);
  global_c97c110c100 = val; /* and */
  goto body_149;
pointer global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114;
function_363:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_364:
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
    target = (&&function_363);
    goto apply_addr;
  }
function_365:
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
    target = (&&function_364);
    goto apply_addr;
  }
function_366:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_365);
  goto apply_addr;
/* ___escape-char */
body_149:
  increment_count(env);
  val = wrap_function((&&function_366), env);
  global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* ___escape-char */
  goto body_150;
pointer global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103; /* ___parse-string */
pointer global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* ___parse-escaped-string */
pointer global_c95c102c110c51c52;
function_367:
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
function_368:
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
    target = (&&function_367);
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
    target = (&&function_367);
    goto apply_addr;
  }
function_369:
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
    target = (&&function_368);
    goto apply_addr;
  }
function_370:
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
    target = (&&function_369);
    goto apply_addr;
  }
function_371:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_370);
  goto apply_addr;
function_372:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  goto pop_function;
/* _fn34 */
body_150:
global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* ___parse-string */
global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* ___parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_372), env);
  global_c95c102c110c51c52 = val; /* _fn34 */
  goto body_151;
function_373:
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
/* ___parse-escaped-string */
body_151:
  increment_count(env);
  val = wrap_function((&&function_373), env);
  global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* ___parse-escaped-string */
  goto body_152;
pointer global_c95c102c110c51c53;
function_374:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_375:
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_374);
  goto apply_addr;
function_376:
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
function_377:
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
    target = (&&function_376);
    goto apply_addr;
  }
function_378:
  if (! is_nil(val)) {
    decrement_count(val);
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
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c114c101c118c101c114c115c101 /* reverse */);
    target = (&&function_375);
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
    target = (&&function_377);
    goto apply_addr;
  }
function_379:
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
    target = (&&function_378);
    goto apply_addr;
  }
function_380:
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
    target = (&&function_379);
    goto apply_addr;
  }
function_381:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_380);
  goto apply_addr;
function_382:
  increment_count(env);
  val = wrap_function((&&function_381), env);
  goto pop_function;
/* _fn35 */
body_152:
  increment_count(env);
  val = wrap_function((&&function_382), env);
  global_c95c102c110c51c53 = val; /* _fn35 */
  goto body_153;
function_383:
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
  increment_count(val = global_c95c102c110c51c53 /* _fn35 */);
  goto top_level_apply;
/* ___parse-string */
body_153:
  increment_count(env);
  val = wrap_function((&&function_383), env);
  global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* ___parse-string */
  goto body_154;
pointer global_c95c95c95c115c107c105c112c45c108c105c110c101; /* ___skip-line */
pointer global_c95c102c110c51c54;
function_384:
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
function_385:
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
    target = (&&function_384);
    goto apply_addr;
  }
function_386:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_385);
  goto apply_addr;
function_387:
  increment_count(env);
  val = wrap_function((&&function_386), env);
  goto pop_function;
/* _fn36 */
body_154:
global_c95c95c95c115c107c105c112c45c108c105c110c101 = nil(); /* ___skip-line */
  increment_count(env);
  val = wrap_function((&&function_387), env);
  global_c95c102c110c51c54 = val; /* _fn36 */
  goto body_155;
function_388:
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
  increment_count(val = global_c95c102c110c51c54 /* _fn36 */);
  goto top_level_apply;
/* ___skip-line */
body_155:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  global_c95c95c95c115c107c105c112c45c108c105c110c101 = val; /* ___skip-line */
  goto body_156;
pointer global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114; /* ___parse-number */
pointer global_c95c102c110c51c55;
function_389:
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
    goto top_level_apply;
  } else {
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto top_level_apply;
  }
function_390:
  goto top_level_apply;
function_391:
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
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 /* ___parse-number */);
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
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    target = (&&function_390);
    goto apply_addr;
  }
function_392:
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
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 /* ___parse-number */);
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
      push_args();
      val = nil();
      args = val;
      val = new_number(10);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61 /* __= */);
      target = (&&function_389);
      goto apply_addr;
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
      target = (&&function_391);
      goto apply_addr;
    }
  }
function_393:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_392);
  goto apply_addr;
function_394:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  goto pop_function;
/* _fn37 */
body_156:
global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* ___parse-number */
  increment_count(env);
  val = wrap_function((&&function_394), env);
  global_c95c102c110c51c55 = val; /* _fn37 */
  goto body_157;
function_395:
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
  increment_count(val = global_c95c102c110c51c55 /* _fn37 */);
  goto top_level_apply;
/* ___parse-number */
body_157:
  increment_count(env);
  val = wrap_function((&&function_395), env);
  global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* ___parse-number */
  goto body_158;
pointer global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108; /* ___parse-symbol */
pointer global_c95c102c110c51c56;
function_396:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_397:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_396);
  goto apply_addr;
function_398:
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
    target = (&&function_397);
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
    target = (&&function_397);
    goto apply_addr;
  }
function_399:
  goto top_level_apply;
function_400:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_399);
  goto apply_addr;
function_401:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_400);
  goto apply_addr;
function_402:
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
    target = (&&function_401);
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
function_403:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_402);
  goto apply_addr;
function_404:
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
  target = (&&function_403);
  goto apply_addr;
function_405:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_404);
  goto apply_addr;
function_406:
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
      push_args();
      val = nil();
      args = val;
      val = new_number(10);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c61 /* __= */);
      target = (&&function_398);
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
      target = (&&function_405);
      goto apply_addr;
    }
  }
function_407:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_406);
  goto apply_addr;
function_408:
  increment_count(env);
  val = wrap_function((&&function_407), env);
  goto pop_function;
/* _fn38 */
body_158:
global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* ___parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_408), env);
  global_c95c102c110c51c56 = val; /* _fn38 */
  goto body_159;
function_409:
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
  increment_count(val = global_c95c102c110c51c56 /* _fn38 */);
  goto top_level_apply;
/* ___parse-symbol */
body_159:
  increment_count(env);
  val = wrap_function((&&function_409), env);
  global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* ___parse-symbol */
  goto body_160;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110; /* ___parse-paren */
pointer global_c95c102c110c51c57;
function_410:
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
function_411:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
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
    target = (&&function_410);
    goto apply_addr;
  }
function_412:
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
    target = (&&function_411);
    goto apply_addr;
  }
function_413:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_412);
  goto apply_addr;
function_414:
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
    target = (&&function_413);
    goto apply_addr;
  }
function_415:
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
    target = (&&function_414);
    goto apply_addr;
  }
function_416:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_415);
  goto apply_addr;
function_417:
  increment_count(env);
  val = wrap_function((&&function_416), env);
  goto pop_function;
/* _fn39 */
body_160:
global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* ___parse-paren */
  increment_count(env);
  val = wrap_function((&&function_417), env);
  global_c95c102c110c51c57 = val; /* _fn39 */
  goto body_161;
function_418:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c57 /* _fn39 */);
  goto top_level_apply;
/* ___parse-paren */
body_161:
  increment_count(env);
  val = wrap_function((&&function_418), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* ___parse-paren */
  goto body_162;
pointer global_c95c102c110c52c48; /* _fn40 */
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108; /* ___parse-tail */
pointer global_c95c102c110c52c49;
function_419:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
  goto top_level_apply;
function_420:
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
  increment_count(val = global_c95c102c110c52c48 /* _fn40 */);
  target = (&&function_419);
  goto apply_addr;
function_421:
  increment_count(env);
  val = wrap_function((&&function_420), env);
  goto pop_function;
/* _fn41 */
body_162:
global_c95c102c110c52c48 = nil(); /* _fn40 */
global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* ___parse-tail */
  increment_count(env);
  val = wrap_function((&&function_421), env);
  global_c95c102c110c52c49 = val; /* _fn41 */
  goto body_163;
function_422:
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
function_423:
  increment_count(env);
  val = wrap_function((&&function_422), env);
  goto pop_function;
/* _fn40 */
body_163:
  increment_count(env);
  val = wrap_function((&&function_423), env);
  global_c95c102c110c52c48 = val; /* _fn40 */
  goto body_164;
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_424:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c49 /* _fn41 */);
  goto top_level_apply;
/* ___parse-tail-cont */
body_164:
  increment_count(env);
  val = wrap_function((&&function_424), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* ___parse-tail-cont */
  goto body_165;
pointer global_c95c102c110c52c51; /* _fn43 */
pointer global_c112c97c114c115c101c45c101c120c112c114; /* parse-expr */
pointer global_c95c102c110c52c52;
function_425:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_426:
  goto top_level_apply;
function_427:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_426);
  goto apply_addr;
function_428:
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
    target = (&&function_427);
    goto apply_addr;
  }
function_429:
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
    increment_count(val = global_c95c102c110c52c51 /* _fn43 */);
    target = (&&function_425);
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
    target = (&&function_428);
    goto apply_addr;
  }
function_430:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
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
    target = (&&function_429);
    goto apply_addr;
  }
function_431:
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
    target = (&&function_430);
    goto apply_addr;
  }
function_432:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_431);
  goto apply_addr;
function_433:
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
    target = (&&function_432);
    goto apply_addr;
  }
function_434:
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
    target = (&&function_433);
    goto apply_addr;
  }
function_435:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_434);
  goto apply_addr;
function_436:
  increment_count(env);
  val = wrap_function((&&function_435), env);
  goto pop_function;
/* _fn44 */
body_165:
global_c95c102c110c52c51 = nil(); /* _fn43 */
global_c112c97c114c115c101c45c101c120c112c114 = nil(); /* parse-expr */
  increment_count(env);
  val = wrap_function((&&function_436), env);
  global_c95c102c110c52c52 = val; /* _fn44 */
  goto body_166;
pointer global_c95c102c110c52c50; /* _fn42 */
function_437:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
  goto top_level_apply;
function_438:
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
  increment_count(val = global_c95c102c110c52c50 /* _fn42 */);
  target = (&&function_437);
  goto apply_addr;
function_439:
  increment_count(env);
  val = wrap_function((&&function_438), env);
  goto pop_function;
/* _fn43 */
body_166:
global_c95c102c110c52c50 = nil(); /* _fn42 */
  increment_count(env);
  val = wrap_function((&&function_439), env);
  global_c95c102c110c52c51 = val; /* _fn43 */
  goto body_167;
function_440:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_441:
  increment_count(env);
  val = wrap_function((&&function_440), env);
  goto pop_function;
/* _fn42 */
body_167:
  increment_count(env);
  val = wrap_function((&&function_441), env);
  global_c95c102c110c52c50 = val; /* _fn42 */
  goto body_168;
function_442:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c52 /* _fn44 */);
  goto top_level_apply;
/* ___parse-tail */
body_168:
  increment_count(env);
  val = wrap_function((&&function_442), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = val; /* ___parse-tail */
  goto body_169;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c105c114; /* ___parse-pair */
pointer global_c95c102c110c52c53;
function_443:
  goto top_level_apply;
function_444:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_443);
  goto apply_addr;
function_445:
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
    target = (&&function_444);
    goto apply_addr;
  }
function_446:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
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
    target = (&&function_445);
    goto apply_addr;
  }
function_447:
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
    target = (&&function_446);
    goto apply_addr;
  }
function_448:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_447);
  goto apply_addr;
function_449:
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
    target = (&&function_448);
    goto apply_addr;
  }
function_450:
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
    target = (&&function_449);
    goto apply_addr;
  }
function_451:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_450);
  goto apply_addr;
function_452:
  increment_count(env);
  val = wrap_function((&&function_451), env);
  goto pop_function;
/* _fn45 */
body_169:
global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* ___parse-pair */
  increment_count(env);
  val = wrap_function((&&function_452), env);
  global_c95c102c110c52c53 = val; /* _fn45 */
  goto body_170;
function_453:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c53 /* _fn45 */);
  goto top_level_apply;
/* ___parse-pair */
body_170:
  increment_count(env);
  val = wrap_function((&&function_453), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* ___parse-pair */
  goto body_171;
pointer global_c95c102c110c52c56; /* _fn48 */
pointer global_c95c102c110c52c55; /* _fn47 */
pointer global_c95c102c110c52c54; /* _fn46 */
pointer global_c95c102c110c52c57;
function_454:
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
function_455:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_456:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_457:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_458:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
  goto top_level_apply;
function_459:
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
    increment_count(val = global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 /* ___parse-number */);
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
    target = (&&function_458);
    goto apply_addr;
  }
function_460:
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
    target = (&&function_459);
    goto apply_addr;
  }
function_461:
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
    increment_count(val = global_c95c102c110c52c56 /* _fn48 */);
    target = (&&function_457);
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
    target = (&&function_460);
    goto apply_addr;
  }
function_462:
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
    target = (&&function_461);
    goto apply_addr;
  }
function_463:
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
    increment_count(val = global_c95c102c110c52c55 /* _fn47 */);
    target = (&&function_456);
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
    target = (&&function_462);
    goto apply_addr;
  }
function_464:
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
    target = (&&function_463);
    goto apply_addr;
  }
function_465:
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
    target = (&&function_464);
    goto apply_addr;
  }
function_466:
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
    increment_count(val = global_c95c102c110c52c54 /* _fn46 */);
    target = (&&function_455);
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
    target = (&&function_465);
    goto apply_addr;
  }
function_467:
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
    target = (&&function_466);
    goto apply_addr;
  }
function_468:
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
    target = (&&function_454);
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
    target = (&&function_467);
    goto apply_addr;
  }
function_469:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_468);
  goto apply_addr;
function_470:
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
    target = (&&function_469);
    goto apply_addr;
  }
function_471:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_470);
  goto apply_addr;
function_472:
  increment_count(env);
  val = wrap_function((&&function_471), env);
  goto pop_function;
/* _fn49 */
body_171:
global_c95c102c110c52c56 = nil(); /* _fn48 */
global_c95c102c110c52c55 = nil(); /* _fn47 */
global_c95c102c110c52c54 = nil(); /* _fn46 */
  increment_count(env);
  val = wrap_function((&&function_472), env);
  global_c95c102c110c52c57 = val; /* _fn49 */
  goto body_172;
function_473:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_474:
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
  val = new_symbol(-38);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_473);
  goto apply_addr;
function_475:
  increment_count(env);
  val = wrap_function((&&function_474), env);
  goto pop_function;
/* _fn46 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_475), env);
  global_c95c102c110c52c54 = val; /* _fn46 */
  goto body_173;
function_476:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_477:
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
  val = new_symbol(-37);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_476);
  goto apply_addr;
function_478:
  increment_count(env);
  val = wrap_function((&&function_477), env);
  goto pop_function;
/* _fn47 */
body_173:
  increment_count(env);
  val = wrap_function((&&function_478), env);
  global_c95c102c110c52c55 = val; /* _fn47 */
  goto body_174;
function_479:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_480:
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
  val = new_symbol(-36);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_479);
  goto apply_addr;
function_481:
  increment_count(env);
  val = wrap_function((&&function_480), env);
  goto pop_function;
/* _fn48 */
body_174:
  increment_count(env);
  val = wrap_function((&&function_481), env);
  global_c95c102c110c52c56 = val; /* _fn48 */
  goto body_175;
function_482:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52c57 /* _fn49 */);
  goto top_level_apply;
/* parse-expr */
body_175:
  increment_count(env);
  val = wrap_function((&&function_482), env);
  global_c112c97c114c115c101c45c101c120c112c114 = val; /* parse-expr */
  goto body_176;
pointer global_c95c102c110c53c48;
function_483:
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
  goto top_level_apply;
function_484:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c48 /* ____l60 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_483);
  goto apply_addr;
function_485:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c54c50 /* ____l62 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c54c49 /* ____l61 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_484);
  goto apply_addr;
/* _fn50 */
body_176:
  increment_count(env);
  val = wrap_function((&&function_485), env);
  global_c95c102c110c53c48 = val; /* _fn50 */
  goto body_177;
pointer global_c114c101c97c100c45c101c120c112c114;
function_486:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c48 /* _fn50 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
/* read-expr */
body_177:
  increment_count(env);
  val = wrap_function((&&function_486), env);
  global_c114c101c97c100c45c101c120c112c114 = val; /* read-expr */
  goto body_178;
pointer global_c95c95c95c95c108c54c51;
/* ____l63 */
body_178:
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
  global_c95c95c95c95c108c54c51 = val; /* ____l63 */
  goto body_179;
pointer global_c95c95c95c95c108c54c52;
/* ____l64 */
body_179:
  val = new_symbol(-35);
  global_c95c95c95c95c108c54c52 = val; /* ____l64 */
  goto body_180;
pointer global_c95c95c95c95c108c54c53;
/* ____l65 */
body_180:
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
  global_c95c95c95c95c108c54c53 = val; /* ____l65 */
  goto body_181;
pointer global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* compile-source */
pointer global_c95c102c110c53c49;
function_487:
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101 /* compile */);
  goto top_level_apply;
function_488:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_489:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c54c53 /* ____l65 */);
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
    increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
    target = (&&function_488);
    goto apply_addr;
  }
function_490:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_489);
  goto apply_addr;
function_491:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_490);
  goto apply_addr;
function_492:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_491);
  goto apply_addr;
function_493:
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
  target = (&&function_492);
  goto apply_addr;
function_494:
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_493);
  goto apply_addr;
function_495:
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
    target = (&&function_487);
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
    target = (&&function_494);
    goto apply_addr;
  }
function_496:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_495);
  goto apply_addr;
function_497:
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
    increment_count(val = global_c95c95c95c95c108c54c51 /* ____l63 */);
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
    increment_count(val = global_c95c95c95c95c108c54c52 /* ____l64 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_496);
    goto apply_addr;
  }
function_498:
  increment_count(env);
  val = wrap_function((&&function_497), env);
  goto pop_function;
/* _fn51 */
body_181:
global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = nil(); /* compile-source */
  increment_count(env);
  val = wrap_function((&&function_498), env);
  global_c95c102c110c53c49 = val; /* _fn51 */
  goto body_182;
function_499:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53c49 /* _fn51 */);
  goto top_level_apply;
/* compile-source */
body_182:
  increment_count(env);
  val = wrap_function((&&function_499), env);
  global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* compile-source */
  goto body_183;
pointer global_c95c95c95c95c108c49;
/* ____l1 */
body_183:
  val = nil();
  global_c95c95c95c95c108c49 = val; /* ____l1 */
  goto body_184;
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
function_500:
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
function_501:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_502:
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
  increment_count(val = global_c95c95c95c95c108c49 /* ____l1 */);
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_501);
  goto apply_addr;
body_184:
  increment_count(env);
  val = wrap_function((&&function_502), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_500), nil()), call_stack);
  goto body_0;
}
