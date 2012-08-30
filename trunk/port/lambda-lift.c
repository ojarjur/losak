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
  long int memory_limit = 64 * 1024 * 1024;
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
    val = new_number(94);
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
    val = new_number(124);
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
    val = new_number(38);
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
    val = new_number(126);
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
    val = new_number(37);
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
    val = new_number(47);
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
    val = new_number(42);
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
    val = new_number(45);
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
    val = new_number(43);
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
    val = new_number(62);
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
    val = new_number(60);
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
    val = new_number(61);
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
  target = (&&function_33);
  goto apply_addr;
/* string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_34), env);
  global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_35:
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
  val = wrap_function((&&function_35), env);
  global_c95c95c115c121c109c98c111c108c63 = val; /* __symbol? */
  goto body_4;
pointer global_c95c95c112c97c105c114c63;
function_36:
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
  val = wrap_function((&&function_36), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c61;
function_37:
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
function_38:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_37);
  goto apply_addr;
/* __= */
body_5:
  increment_count(env);
  val = wrap_function((&&function_38), env);
  global_c95c95c61 = val; /* __= */
  goto body_6;
pointer global_c108c105c115c116;
function_39:
  increment_count(val = car(env));
  goto pop_function;
/* list */
body_6:
  increment_count(env);
  val = wrap_function((&&function_39), env);
  global_c108c105c115c116 = val; /* list */
  goto body_7;
pointer global_c95c95c95c114c114c101c118c101c114c115c101;
function_40:
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
function_41:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_40);
  goto apply_addr;
/* ___rreverse */
body_7:
  increment_count(env);
  val = wrap_function((&&function_41), env);
  global_c95c95c95c114c114c101c118c101c114c115c101 = val; /* ___rreverse */
  goto body_8;
pointer global_c102c111c108c100c108; /* foldl */
pointer global_c95c102c110c48;
function_42:
  goto top_level_apply;
function_43:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c108 /* foldl */);
  target = (&&function_42);
  goto apply_addr;
function_44:
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
    target = (&&function_43);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
  }
function_45:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_44);
  goto apply_addr;
function_46:
  increment_count(env);
  val = wrap_function((&&function_45), env);
  goto pop_function;
/* _fn0 */
body_8:
global_c102c111c108c100c108 = nil(); /* foldl */
  increment_count(env);
  val = wrap_function((&&function_46), env);
  global_c95c102c110c48 = val; /* _fn0 */
  goto body_9;
function_47:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c48 /* _fn0 */);
  goto top_level_apply;
/* foldl */
body_9:
  increment_count(env);
  val = wrap_function((&&function_47), env);
  global_c102c111c108c100c108 = val; /* foldl */
  goto body_10;
pointer global_c95c102c110c49;
function_48:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c114c114c101c118c101c114c115c101 /* ___rreverse */);
  goto top_level_apply;
function_49:
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
  target = (&&function_48);
  goto apply_addr;
function_50:
  increment_count(env);
  val = wrap_function((&&function_49), env);
  goto pop_function;
/* _fn1 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  global_c95c102c110c49 = val; /* _fn1 */
  goto body_11;
pointer global_c102c111c108c100c114;
function_51:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49 /* _fn1 */);
  goto top_level_apply;
/* foldr */
body_11:
  increment_count(env);
  val = wrap_function((&&function_51), env);
  global_c102c111c108c100c114 = val; /* foldr */
  goto body_12;
pointer global_c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_52:
  global_c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* map-to-stderr */
  goto body_13;
function_53:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_54:
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
  target = (&&function_53);
  goto apply_addr;
/* map-to-stderr */
body_12:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_54), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_52);
  goto apply_addr;
pointer global_c95c95c95c95c108c49;
/* ____l1 */
body_13:
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
  global_c95c95c95c95c108c49 = val; /* ____l1 */
  goto body_14;
pointer global_c95c95c95c95c108c50;
/* ____l2 */
body_14:
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
  global_c95c95c95c95c108c50 = val; /* ____l2 */
  goto body_15;
pointer global_c95c95c95c95c108c51;
/* ____l3 */
body_15:
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
  global_c95c95c95c95c108c51 = val; /* ____l3 */
  goto body_16;
pointer global_c95c95c95c95c108c52;
/* ____l4 */
body_16:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c52 = val; /* ____l4 */
  goto body_17;
pointer global_c105c100;
function_55:
  increment_count(val = car(car(env)));
  goto pop_function;
/* id */
body_17:
  increment_count(env);
  val = wrap_function((&&function_55), env);
  global_c105c100 = val; /* id */
  goto body_18;
pointer global_c95c95c95c119c97c108c107; /* ___walk */
pointer global_c95c102c110c50;
function_56:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_57:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_56);
  goto apply_addr;
function_58:
  target = (&&function_57);
  goto apply_addr;
function_59:
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
  target = (&&function_58);
  goto apply_addr;
function_60:
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
    target = (&&function_59);
    goto apply_addr;
  }
function_61:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_60);
  goto apply_addr;
function_62:
  increment_count(env);
  val = wrap_function((&&function_61), env);
  goto pop_function;
/* _fn2 */
body_18:
global_c95c95c95c119c97c108c107 = nil(); /* ___walk */
  increment_count(env);
  val = wrap_function((&&function_62), env);
  global_c95c102c110c50 = val; /* _fn2 */
  goto body_19;
function_63:
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
  increment_count(val = global_c95c102c110c50 /* _fn2 */);
  goto top_level_apply;
/* ___walk */
body_19:
  increment_count(env);
  val = wrap_function((&&function_63), env);
  global_c95c95c95c119c97c108c107 = val; /* ___walk */
  goto body_20;
pointer global_c97c112c112c101c110c100;
function_64:
  goto top_level_apply;
function_65:
  goto top_level_apply;
function_66:
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
function_67:
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
    val = wrap_function((&&function_66), env);
    args = cons(val, args);
    increment_count(val = global_c102c111c108c100c114 /* foldr */);
    target = (&&function_65);
    goto apply_addr;
  }
function_68:
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
  increment_count(env);
  val = wrap_function((&&function_67), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_64);
  goto apply_addr;
/* append */
body_20:
  increment_count(env);
  val = wrap_function((&&function_68), env);
  global_c97c112c112c101c110c100 = val; /* append */
  goto body_21;
pointer global_c95c102c110c51;
function_69:
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
function_70:
  increment_count(env);
  val = wrap_function((&&function_69), env);
  goto pop_function;
/* _fn3 */
body_21:
  increment_count(env);
  val = wrap_function((&&function_70), env);
  global_c95c102c110c51 = val; /* _fn3 */
  goto body_22;
pointer global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_71:
  goto top_level_apply;
function_72:
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
function_73:
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
function_74:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
function_75:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51 /* _fn3 */);
  goto top_level_apply;
function_76:
  increment_count(val = global_c105c100 /* id */);
  goto pop_function;
function_77:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(env);
  val = wrap_function((&&function_76), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_75), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_74), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_73), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_72), env);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c119c97c108c107 /* ___walk */);
  target = (&&function_71);
  goto apply_addr;
/* ___build-num-str */
body_22:
  increment_count(env);
  val = wrap_function((&&function_77), env);
  global_c95c95c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* ___build-num-str */
  goto body_23;
pointer global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103;
function_78:
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
function_79:
  target = (&&function_78);
  goto apply_addr;
function_80:
  goto top_level_apply;
function_81:
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
      target = (&&function_79);
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
      target = (&&function_80);
      goto apply_addr;
    }
  }
function_82:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_81);
  goto apply_addr;
/* number->string */
body_23:
  increment_count(env);
  val = wrap_function((&&function_82), env);
  global_c110c117c109c98c101c114c45c62c115c116c114c105c110c103 = val; /* number->string */
  goto body_24;
pointer global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* ___print-with-suffix */
pointer global_c95c95c95c112c114c105c110c116c45c116c97c105c108;
function_83:
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
function_84:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_83);
  goto apply_addr;
function_85:
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
function_86:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_85);
  goto apply_addr;
function_87:
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
    target = (&&function_84);
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
    target = (&&function_86);
    goto apply_addr;
  }
function_88:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_87);
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
body_24:
global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = nil(); /* ___print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_88), env);
  global_c95c95c95c112c114c105c110c116c45c116c97c105c108 = val; /* ___print-tail */
  goto body_25;
pointer global_c112c114c105c110c116; /* print */
function_89:
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
function_90:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* ___print-with-suffix */);
  target = (&&function_89);
  goto apply_addr;
function_91:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_92:
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
    target = (&&function_90);
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
    target = (&&function_91);
    goto apply_addr;
  }
function_93:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_92);
  goto apply_addr;
/* ___print-with-suffix */
body_25:
global_c112c114c105c110c116 = nil(); /* print */
  increment_count(env);
  val = wrap_function((&&function_93), env);
  global_c95c95c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* ___print-with-suffix */
  goto body_26;
function_94:
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
function_95:
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
    target = (&&function_94);
    goto apply_addr;
  }
function_96:
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
      target = (&&function_95);
      goto apply_addr;
    }
  }
/* print */
body_26:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  global_c112c114c105c110c116 = val; /* print */
  goto body_27;
pointer global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_97:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_98:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50 /* ____l2 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c49 /* ____l1 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_97);
  goto apply_addr;
function_99:
  increment_count(val = car(cdr(car(env))));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c52 /* ____l4 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c51 /* ____l3 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_98);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
/* print-warnings */
body_27:
  increment_count(env);
  val = wrap_function((&&function_99), env);
  global_c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* print-warnings */
  goto body_28;
pointer global_c95c95c95c95c108c53;
/* ____l5 */
body_28:
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
  global_c95c95c95c95c108c53 = val; /* ____l5 */
  goto body_29;
pointer global_c95c95c95c95c108c54;
/* ____l6 */
body_29:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c54 = val; /* ____l6 */
  goto body_30;
pointer global_c112c114c105c110c116c45c101c114c114c111c114;
function_100:
  args = cons(val, args);
  increment_count(val = global_c109c97c112c45c116c111c45c115c116c100c101c114c114 /* map-to-stderr */);
  goto top_level_apply;
function_101:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c54 /* ____l6 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c53 /* ____l5 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_100);
  goto apply_addr;
/* print-error */
body_30:
  increment_count(env);
  val = wrap_function((&&function_101), env);
  global_c112c114c105c110c116c45c101c114c114c111c114 = val; /* print-error */
  goto body_31;
pointer global_c95c95c95c95c108c55;
/* ____l7 */
body_31:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-42);
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = new_symbol(-44);
  args = cons(val, args);
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
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c55 = val; /* ____l7 */
  goto body_32;
pointer global_c98c117c105c108c116c105c110c115;
/* builtins */
body_32:
  increment_count(val = global_c95c95c95c95c108c55 /* ____l7 */);
  global_c98c117c105c108c116c105c110c115 = val; /* builtins */
  goto body_33;
pointer global_c95c95c101c113c117c97c108;
function_102:
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
function_103:
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
    target = (&&function_102);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_104:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_103);
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
function_105:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_104);
  goto apply_addr;
/* __equal */
body_33:
  increment_count(env);
  val = wrap_function((&&function_105), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_34;
pointer global_c109c101c109c98c101c114;
function_106:
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
function_107:
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
    target = (&&function_106);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_108:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_107);
  goto apply_addr;
/* member */
body_34:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c109c101c109c98c101c114 = val; /* member */
  goto body_35;
pointer global_c95c102c110c52;
function_109:
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
function_110:
  push_args();
  val = nil();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_109);
  goto apply_addr;
function_111:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  goto pop_function;
/* _fn4 */
body_35:
  increment_count(env);
  val = wrap_function((&&function_111), env);
  global_c95c102c110c52 = val; /* _fn4 */
  goto body_36;
pointer global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_112:
  goto top_level_apply;
function_113:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c52 /* _fn4 */);
  target = (&&function_112);
  goto apply_addr;
function_114:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_115:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_114);
  goto apply_addr;
function_116:
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
    target = (&&function_115);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_117:
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
    target = (&&function_113);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_116);
    goto apply_addr;
  }
function_118:
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
    target = (&&function_117);
    goto apply_addr;
  }
function_119:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c98c117c105c108c116c105c110c115 /* builtins */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_118);
  goto apply_addr;
/* escape-symbols */
body_36:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* escape-symbols */
  goto body_37;
pointer global_c102c108c97c116c116c101c110;
function_120:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  goto top_level_apply;
function_121:
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
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
    target = (&&function_120);
    goto apply_addr;
  } else {
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
  }
function_122:
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
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_121);
    goto apply_addr;
  }
/* flatten */
body_37:
  increment_count(env);
  val = wrap_function((&&function_122), env);
  global_c102c108c97c116c116c101c110 = val; /* flatten */
  goto body_38;
pointer global_c109c101c114c103c101;
function_123:
  goto top_level_apply;
function_124:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
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
  }
function_125:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_124);
  goto apply_addr;
function_126:
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
  val = wrap_function((&&function_125), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_123);
  goto apply_addr;
/* merge */
body_38:
  increment_count(env);
  val = wrap_function((&&function_126), env);
  global_c109c101c114c103c101 = val; /* merge */
  goto body_39;
pointer global_c95c95c95c95c108c56;
/* ____l8 */
body_39:
  val = nil();
  global_c95c95c95c95c108c56 = val; /* ____l8 */
  goto body_40;
pointer global_c95c102c110c53;
function_127:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
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
  }
function_128:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c109c101c109c98c101c114 /* member */);
  target = (&&function_127);
  goto apply_addr;
function_129:
  increment_count(env);
  val = wrap_function((&&function_128), env);
  goto pop_function;
/* _fn5 */
body_40:
  increment_count(env);
  val = wrap_function((&&function_129), env);
  global_c95c102c110c53 = val; /* _fn5 */
  goto body_41;
pointer global_c115c117c98c116c114c97c99c116c45c108c105c115c116;
function_130:
  goto top_level_apply;
function_131:
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_130);
  goto apply_addr;
function_132:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c56 /* ____l8 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c53 /* _fn5 */);
  target = (&&function_131);
  goto apply_addr;
/* subtract-list */
body_41:
  increment_count(env);
  val = wrap_function((&&function_132), env);
  global_c115c117c98c116c114c97c99c116c45c108c105c115c116 = val; /* subtract-list */
  goto body_42;
pointer global_c95c102c110c54;
function_133:
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
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_134:
  push_args();
  val = nil();
  args = val;
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
  push_args();
  val = nil();
  args = val;
  val = nil();
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_133);
  goto apply_addr;
function_135:
  increment_count(env);
  val = wrap_function((&&function_134), env);
  goto pop_function;
/* _fn6 */
body_42:
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c95c102c110c54 = val; /* _fn6 */
  goto body_43;
pointer global_c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110;
function_136:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c54 /* _fn6 */);
  goto top_level_apply;
/* definition-return */
body_43:
  increment_count(env);
  val = wrap_function((&&function_136), env);
  global_c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110 = val; /* definition-return */
  goto body_44;
pointer global_c95c95c95c95c108c57;
/* ____l9 */
body_44:
  val = nil();
  push_args();
  args = val;
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c57 = val; /* ____l9 */
  goto body_45;
pointer global_c95c95c95c95c108c49c48;
/* ____l10 */
body_45:
  val = nil();
  global_c95c95c95c95c108c49c48 = val; /* ____l10 */
  goto body_46;
pointer global_c95c95c95c95c108c49c49;
/* ____l11 */
body_46:
  val = nil();
  global_c95c95c95c95c108c49c49 = val; /* ____l11 */
  goto body_47;
pointer global_c95c102c110c49c48; /* _fn10 */
pointer global_c95c102c110c49c49;
function_137:
  goto top_level_apply;
function_138:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c48 /* _fn10 */);
  target = (&&function_137);
  goto apply_addr;
function_139:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c49c49 /* ____l11 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  target = (&&function_138);
  goto apply_addr;
function_140:
  increment_count(env);
  val = wrap_function((&&function_139), env);
  goto pop_function;
/* _fn11 */
body_47:
global_c95c102c110c49c48 = nil(); /* _fn10 */
  increment_count(env);
  val = wrap_function((&&function_140), env);
  global_c95c102c110c49c49 = val; /* _fn11 */
  goto body_48;
pointer global_c95c102c110c57; /* _fn9 */
function_141:
  goto top_level_apply;
function_142:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c57 /* _fn9 */);
  target = (&&function_141);
  goto apply_addr;
function_143:
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
  increment_count(val = global_c115c117c98c116c114c97c99c116c45c108c105c115c116 /* subtract-list */);
  target = (&&function_142);
  goto apply_addr;
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* _fn10 */
body_48:
global_c95c102c110c57 = nil(); /* _fn9 */
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c95c102c110c49c48 = val; /* _fn10 */
  goto body_49;
pointer global_c95c102c110c56; /* _fn8 */
function_145:
  goto top_level_apply;
function_146:
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
  increment_count(val = global_c95c102c110c56 /* _fn8 */);
  target = (&&function_145);
  goto apply_addr;
function_147:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c57 /* ____l9 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_146);
  goto apply_addr;
function_148:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-41);
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
function_149:
  increment_count(val = car(car(env)));
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
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    args = cons(val, args);
    increment_count(val = global_c112c114c105c110c116 /* print */);
    target = (&&function_147);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c48 /* ____l10 */);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
    target = (&&function_148);
    goto apply_addr;
  }
function_150:
  increment_count(env);
  val = wrap_function((&&function_149), env);
  goto pop_function;
/* _fn9 */
body_49:
global_c95c102c110c56 = nil(); /* _fn8 */
  increment_count(env);
  val = wrap_function((&&function_150), env);
  global_c95c102c110c57 = val; /* _fn9 */
  goto body_50;
pointer global_c95c102c110c55; /* _fn7 */
function_151:
  goto top_level_apply;
function_152:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c55 /* _fn7 */);
  target = (&&function_151);
  goto apply_addr;
function_153:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_152);
  goto apply_addr;
function_154:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  goto pop_function;
/* _fn8 */
body_50:
global_c95c102c110c55 = nil(); /* _fn7 */
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c95c102c110c56 = val; /* _fn8 */
  goto body_51;
function_155:
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
  goto top_level_apply;
function_156:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-41);
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_155);
  goto apply_addr;
function_157:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-41);
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_156);
  goto apply_addr;
function_158:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
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
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
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
  target = (&&function_157);
  goto apply_addr;
function_159:
  increment_count(env);
  val = wrap_function((&&function_158), env);
  goto pop_function;
/* _fn7 */
body_51:
  increment_count(env);
  val = wrap_function((&&function_159), env);
  global_c95c102c110c55 = val; /* _fn7 */
  goto body_52;
pointer global_c102c110c45c114c101c116c117c114c110;
function_160:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c49 /* _fn11 */);
  goto top_level_apply;
/* fn-return */
body_52:
  increment_count(env);
  val = wrap_function((&&function_160), env);
  global_c102c110c45c114c101c116c117c114c110 = val; /* fn-return */
  goto body_53;
pointer global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115; /* extract-definitions */
pointer global_c95c102c110c49c50;
function_161:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  goto top_level_apply;
function_162:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c45c114c101c116c117c114c110 /* fn-return */);
  target = (&&function_161);
  goto apply_addr;
function_163:
  increment_count(env);
  val = wrap_function((&&function_162), env);
  goto pop_function;
/* _fn12 */
body_53:
global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* extract-definitions */
  increment_count(env);
  val = wrap_function((&&function_163), env);
  global_c95c102c110c49c50 = val; /* _fn12 */
  goto body_54;
pointer global_c102c110c45c100c101c102c105c110c116c105c111c110c115;
function_164:
  goto top_level_apply;
function_165:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c50 /* _fn12 */);
  target = (&&function_164);
  goto apply_addr;
function_166:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c108c97c116c116c101c110 /* flatten */);
  target = (&&function_165);
  goto apply_addr;
/* fn-defintions */
body_54:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  global_c102c110c45c100c101c102c105c110c116c105c111c110c115 = val; /* fn-defintions */
  goto body_55;
pointer global_c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115; /* args-definitions */
pointer global_c95c102c110c49c51; /* _fn13 */
pointer global_c95c102c110c49c52;
function_167:
  goto top_level_apply;
function_168:
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
  increment_count(val = global_c95c102c110c49c51 /* _fn13 */);
  target = (&&function_167);
  goto apply_addr;
function_169:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 /* args-definitions */);
  target = (&&function_168);
  goto apply_addr;
function_170:
  increment_count(env);
  val = wrap_function((&&function_169), env);
  goto pop_function;
/* _fn14 */
body_55:
global_c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* args-definitions */
global_c95c102c110c49c51 = nil(); /* _fn13 */
  increment_count(env);
  val = wrap_function((&&function_170), env);
  global_c95c102c110c49c52 = val; /* _fn14 */
  goto body_56;
function_171:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
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
function_172:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c109c101c114c103c101 /* merge */);
  target = (&&function_171);
  goto apply_addr;
function_173:
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
  target = (&&function_172);
  goto apply_addr;
function_174:
  increment_count(env);
  val = wrap_function((&&function_173), env);
  goto pop_function;
/* _fn13 */
body_56:
  increment_count(env);
  val = wrap_function((&&function_174), env);
  global_c95c102c110c49c51 = val; /* _fn13 */
  goto body_57;
function_175:
  goto top_level_apply;
function_176:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c52 /* _fn14 */);
  target = (&&function_175);
  goto apply_addr;
function_177:
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
    target = (&&function_176);
    goto apply_addr;
  } else {
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
    increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
    goto top_level_apply;
  }
function_178:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_177);
  goto apply_addr;
/* args-definitions */
body_57:
  increment_count(env);
  val = wrap_function((&&function_178), env);
  global_c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* args-definitions */
  goto body_58;
pointer global_c95c95c95c95c108c49c50;
/* ____l12 */
body_58:
  val = nil();
  global_c95c95c95c95c108c49c50 = val; /* ____l12 */
  goto body_59;
pointer global_c95c95c95c95c108c49c51;
/* ____l13 */
body_59:
  val = nil();
  global_c95c95c95c95c108c49c51 = val; /* ____l13 */
  goto body_60;
pointer global_c95c95c95c95c108c49c52;
/* ____l14 */
body_60:
  val = nil();
  global_c95c95c95c95c108c49c52 = val; /* ____l14 */
  goto body_61;
pointer global_c95c95c95c95c108c49c53;
/* ____l15 */
body_61:
  val = nil();
  global_c95c95c95c95c108c49c53 = val; /* ____l15 */
  goto body_62;
pointer global_c95c95c95c95c108c49c54;
/* ____l16 */
body_62:
  val = nil();
  global_c95c95c95c95c108c49c54 = val; /* ____l16 */
  goto body_63;
pointer global_c95c95c95c95c108c49c55;
/* ____l17 */
body_63:
  val = nil();
  global_c95c95c95c95c108c49c55 = val; /* ____l17 */
  goto body_64;
pointer global_c95c95c95c95c108c49c56;
/* ____l18 */
body_64:
  val = new_symbol(-38);
  global_c95c95c95c95c108c49c56 = val; /* ____l18 */
  goto body_65;
pointer global_c95c95c95c95c108c49c57;
/* ____l19 */
body_65:
  val = nil();
  global_c95c95c95c95c108c49c57 = val; /* ____l19 */
  goto body_66;
pointer global_c95c95c95c95c108c50c48;
/* ____l20 */
body_66:
  val = nil();
  global_c95c95c95c95c108c50c48 = val; /* ____l20 */
  goto body_67;
pointer global_c95c95c95c95c108c50c49;
/* ____l21 */
body_67:
  val = new_symbol(-35);
  global_c95c95c95c95c108c50c49 = val; /* ____l21 */
  goto body_68;
pointer global_c95c95c95c95c108c50c50;
/* ____l22 */
body_68:
  val = new_symbol(-41);
  global_c95c95c95c95c108c50c50 = val; /* ____l22 */
  goto body_69;
pointer global_c95c95c95c95c108c50c51;
/* ____l23 */
body_69:
  val = new_symbol(-40);
  global_c95c95c95c95c108c50c51 = val; /* ____l23 */
  goto body_70;
pointer global_c99c97c100c114;
function_179:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* cadr */
body_70:
  increment_count(env);
  val = wrap_function((&&function_179), env);
  global_c99c97c100c114 = val; /* cadr */
  goto body_71;
pointer global_c99c100c100c114;
function_180:
  increment_count(val = cdr(cdr(car(car(env)))));
  goto pop_function;
/* cddr */
body_71:
  increment_count(env);
  val = wrap_function((&&function_180), env);
  global_c99c100c100c114 = val; /* cddr */
  goto body_72;
pointer global_c99c97c100c100c114;
function_181:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* caddr */
body_72:
  increment_count(env);
  val = wrap_function((&&function_181), env);
  global_c99c97c100c100c114 = val; /* caddr */
  goto body_73;
pointer global_c95c102c110c49c54; /* _fn16 */
pointer global_c95c102c110c49c55;
function_182:
  goto top_level_apply;
function_183:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c102c110c49c54 /* _fn16 */);
  target = (&&function_182);
  goto apply_addr;
function_184:
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  target = (&&function_183);
  goto apply_addr;
function_185:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c100c114 /* caddr */);
  target = (&&function_184);
  goto apply_addr;
function_186:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  goto pop_function;
/* _fn17 */
body_73:
global_c95c102c110c49c54 = nil(); /* _fn16 */
  increment_count(env);
  val = wrap_function((&&function_186), env);
  global_c95c102c110c49c55 = val; /* _fn17 */
  goto body_74;
pointer global_c95c102c110c49c53; /* _fn15 */
function_187:
  goto top_level_apply;
function_188:
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
  increment_count(val = global_c95c102c110c49c53 /* _fn15 */);
  target = (&&function_187);
  goto apply_addr;
function_189:
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  target = (&&function_188);
  goto apply_addr;
function_190:
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_189);
  goto apply_addr;
function_191:
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
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c99c100c100c114 /* cddr */);
  target = (&&function_190);
  goto apply_addr;
function_192:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  goto pop_function;
/* _fn16 */
body_74:
global_c95c102c110c49c53 = nil(); /* _fn15 */
  increment_count(env);
  val = wrap_function((&&function_192), env);
  global_c95c102c110c49c54 = val; /* _fn16 */
  goto body_75;
function_193:
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
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
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
  val = new_symbol(-40);
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
function_194:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c109c101c114c103c101 /* merge */);
  target = (&&function_193);
  goto apply_addr;
function_195:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c109c101c114c103c101 /* merge */);
  target = (&&function_194);
  goto apply_addr;
function_196:
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
  target = (&&function_195);
  goto apply_addr;
function_197:
  increment_count(env);
  val = wrap_function((&&function_196), env);
  goto pop_function;
/* _fn15 */
body_75:
  increment_count(env);
  val = wrap_function((&&function_197), env);
  global_c95c102c110c49c53 = val; /* _fn15 */
  goto body_76;
function_198:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_199:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
  target = (&&function_198);
  goto apply_addr;
function_200:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c108c105c115c116 /* list */);
    target = (&&function_199);
    goto apply_addr;
  } else {
    increment_count(val = global_c95c95c95c95c108c49c50 /* ____l12 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* escape-symbols */);
    target = (&&function_198);
    goto apply_addr;
  }
function_201:
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  goto top_level_apply;
function_202:
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
  increment_count(val = global_c99c97c100c100c114 /* caddr */);
  target = (&&function_201);
  goto apply_addr;
function_203:
  args = cons(val, args);
  increment_count(val = global_c100c101c102c105c110c105c116c105c111c110c45c114c101c116c117c114c110 /* definition-return */);
  target = (&&function_202);
  goto apply_addr;
function_204:
  args = cons(val, args);
  increment_count(val = global_c102c110c45c100c101c102c105c110c116c105c111c110c115 /* fn-defintions */);
  goto top_level_apply;
function_205:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c97c100c114 /* cadr */);
  target = (&&function_204);
  goto apply_addr;
function_206:
  goto top_level_apply;
function_207:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c55 /* _fn17 */);
  target = (&&function_206);
  goto apply_addr;
function_208:
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  target = (&&function_207);
  goto apply_addr;
function_209:
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
    target = (&&function_208);
    goto apply_addr;
  } else {
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
    increment_count(val = global_c97c114c103c115c45c100c101c102c105c110c105c116c105c111c110c115 /* args-definitions */);
    goto top_level_apply;
  }
function_210:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
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
    increment_count(val = global_c99c97c100c100c114 /* caddr */);
    target = (&&function_205);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c50c51 /* ____l23 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c97c100c114 /* cadr */);
    target = (&&function_203);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c50c50 /* ____l22 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c50c48 /* ____l20 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c57 /* ____l19 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c50c49 /* ____l21 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c49c51 /* ____l13 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c109c101c109c98c101c114 /* member */);
    target = (&&function_200);
    goto apply_addr;
  } else {
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
      increment_count(val = car(cdr(cdr(car(env)))));
      args = cons(val, args);
      increment_count(val = global_c95c95c95c95c108c49c53 /* ____l15 */);
      args = cons(val, args);
      increment_count(val = global_c95c95c95c95c108c49c52 /* ____l14 */);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(cdr(car(env))))));
      goto top_level_apply;
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
        increment_count(val = car(cdr(cdr(car(env)))));
        args = cons(val, args);
        increment_count(val = global_c95c95c95c95c108c49c55 /* ____l17 */);
        args = cons(val, args);
        increment_count(val = global_c95c95c95c95c108c49c54 /* ____l16 */);
        args = cons(val, args);
        increment_count(val = car(car(env)));
        args = cons(val, args);
        increment_count(val = car(cdr(cdr(cdr(car(env))))));
        goto top_level_apply;
      } else {
        push_args();
        val = nil();
        args = val;
        increment_count(val = global_c95c95c95c95c108c49c56 /* ____l18 */);
        args = cons(val, args);
        increment_count(val = car(car(car(env))));
        args = cons(val, args);
        increment_count(val = global_c95c95c61 /* __= */);
        target = (&&function_212);
        goto apply_addr;
      }
    }
  }
function_214:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_213);
  goto apply_addr;
/* extract-definitions */
body_76:
  increment_count(env);
  val = wrap_function((&&function_214), env);
  global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* extract-definitions */
  goto body_77;
pointer global_c95c95c95c95c108c50c52;
/* ____l24 */
body_77:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c50c52 = val; /* ____l24 */
  goto body_78;
pointer global_c95c95c95c95c108c50c53;
/* ____l25 */
body_78:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c50c53 = val; /* ____l25 */
  goto body_79;
pointer global_c95c102c110c49c56;
function_215:
  goto top_level_apply;
function_216:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  goto top_level_apply;
function_217:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c52 /* ____l24 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_216);
  goto apply_addr;
function_218:
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_217), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_215);
  goto apply_addr;
function_219:
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_218);
  goto apply_addr;
function_220:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c53 /* ____l25 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_219);
  goto apply_addr;
function_221:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
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
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_220);
  goto apply_addr;
function_222:
  increment_count(env);
  val = wrap_function((&&function_221), env);
  goto pop_function;
/* _fn18 */
body_79:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  global_c95c102c110c49c56 = val; /* _fn18 */
  goto body_80;
pointer global_c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110;
function_223:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c49c56 /* _fn18 */);
  goto top_level_apply;
/* statement-return */
body_80:
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110 = val; /* statement-return */
  goto body_81;
pointer global_c95c95c95c95c108c50c54;
/* ____l26 */
body_81:
  val = nil();
  global_c95c95c95c95c108c50c54 = val; /* ____l26 */
  goto body_82;
pointer global_c99c111c109c112c105c108c101;
function_224:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c54 /* ____l26 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c101c120c116c114c97c99c116c45c100c101c102c105c110c105c116c105c111c110c115 /* extract-definitions */);
  goto top_level_apply;
function_225:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c115c116c97c116c101c109c101c110c116c45c114c101c116c117c114c110 /* statement-return */);
  target = (&&function_224);
  goto apply_addr;
/* compile */
body_82:
  increment_count(env);
  val = wrap_function((&&function_225), env);
  global_c99c111c109c112c105c108c101 = val; /* compile */
  goto body_83;
pointer global_c95c95c95c95c108c50c55;
/* ____l27 */
body_83:
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
  global_c95c95c95c95c108c50c55 = val; /* ____l27 */
  goto body_84;
pointer global_c95c95c95c95c108c50c56;
/* ____l28 */
body_84:
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
  global_c95c95c95c95c108c50c56 = val; /* ____l28 */
  goto body_85;
pointer global_c95c95c95c95c108c50c57;
/* ____l29 */
body_85:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c50c57 = val; /* ____l29 */
  goto body_86;
pointer global_c114c101c118c101c114c115c101;
function_226:
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
body_86:
  increment_count(env);
  val = wrap_function((&&function_226), env);
  global_c114c101c118c101c114c115c101 = val; /* reverse */
  goto body_87;
pointer global_c111c114;
function_227:
  goto top_level_apply;
function_228:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_229:
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
  increment_count(env);
  val = wrap_function((&&function_228), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_227);
  goto apply_addr;
/* or */
body_87:
  increment_count(env);
  val = wrap_function((&&function_229), env);
  global_c111c114 = val; /* or */
  goto body_88;
pointer global_c97c110c100;
function_230:
  goto top_level_apply;
function_231:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_232:
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
  increment_count(env);
  val = wrap_function((&&function_231), env);
  args = cons(val, args);
  increment_count(val = global_c102c111c108c100c114 /* foldr */);
  target = (&&function_230);
  goto apply_addr;
/* and */
body_88:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c97c110c100 = val; /* and */
  goto body_89;
pointer global_c110c111c116;
function_233:
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
body_89:
  increment_count(env);
  val = wrap_function((&&function_233), env);
  global_c110c111c116 = val; /* not */
  goto body_90;
pointer global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114;
function_234:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_235:
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
    target = (&&function_234);
    goto apply_addr;
  }
function_236:
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
    target = (&&function_235);
    goto apply_addr;
  }
function_237:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_236);
  goto apply_addr;
/* ___escape-char */
body_90:
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c95c95c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* ___escape-char */
  goto body_91;
pointer global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103; /* ___parse-string */
pointer global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* ___parse-escaped-string */
pointer global_c95c102c110c49c57;
function_238:
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
function_239:
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
    target = (&&function_238);
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
    target = (&&function_238);
    goto apply_addr;
  }
function_240:
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
    target = (&&function_239);
    goto apply_addr;
  }
function_241:
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
    target = (&&function_240);
    goto apply_addr;
  }
function_242:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_241);
  goto apply_addr;
function_243:
  increment_count(env);
  val = wrap_function((&&function_242), env);
  goto pop_function;
/* _fn19 */
body_91:
global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* ___parse-string */
global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* ___parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_243), env);
  global_c95c102c110c49c57 = val; /* _fn19 */
  goto body_92;
function_244:
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
  increment_count(val = global_c95c102c110c49c57 /* _fn19 */);
  goto top_level_apply;
/* ___parse-escaped-string */
body_92:
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c95c95c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* ___parse-escaped-string */
  goto body_93;
pointer global_c95c102c110c50c48;
function_245:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_246:
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  increment_count(val = global_c108c105c115c116 /* list */);
  target = (&&function_245);
  goto apply_addr;
function_247:
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
function_248:
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
    target = (&&function_247);
    goto apply_addr;
  }
function_249:
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
    target = (&&function_246);
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
    target = (&&function_248);
    goto apply_addr;
  }
function_250:
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
    target = (&&function_249);
    goto apply_addr;
  }
function_251:
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
    target = (&&function_250);
    goto apply_addr;
  }
function_252:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_251);
  goto apply_addr;
function_253:
  increment_count(env);
  val = wrap_function((&&function_252), env);
  goto pop_function;
/* _fn20 */
body_93:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  global_c95c102c110c50c48 = val; /* _fn20 */
  goto body_94;
function_254:
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
  increment_count(val = global_c95c102c110c50c48 /* _fn20 */);
  goto top_level_apply;
/* ___parse-string */
body_94:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c95c95c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* ___parse-string */
  goto body_95;
pointer global_c95c95c95c115c107c105c112c45c108c105c110c101; /* ___skip-line */
pointer global_c95c102c110c50c49;
function_255:
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
function_256:
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
    target = (&&function_255);
    goto apply_addr;
  }
function_257:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_256);
  goto apply_addr;
function_258:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  goto pop_function;
/* _fn21 */
body_95:
global_c95c95c95c115c107c105c112c45c108c105c110c101 = nil(); /* ___skip-line */
  increment_count(env);
  val = wrap_function((&&function_258), env);
  global_c95c102c110c50c49 = val; /* _fn21 */
  goto body_96;
function_259:
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
  increment_count(val = global_c95c102c110c50c49 /* _fn21 */);
  goto top_level_apply;
/* ___skip-line */
body_96:
  increment_count(env);
  val = wrap_function((&&function_259), env);
  global_c95c95c95c115c107c105c112c45c108c105c110c101 = val; /* ___skip-line */
  goto body_97;
pointer global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114; /* ___parse-number */
pointer global_c95c102c110c50c50;
function_260:
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
function_261:
  goto top_level_apply;
function_262:
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
    target = (&&function_261);
    goto apply_addr;
  }
function_263:
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
      target = (&&function_260);
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
      target = (&&function_262);
      goto apply_addr;
    }
  }
function_264:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_263);
  goto apply_addr;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* _fn22 */
body_97:
global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* ___parse-number */
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c95c102c110c50c50 = val; /* _fn22 */
  goto body_98;
function_266:
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
  increment_count(val = global_c95c102c110c50c50 /* _fn22 */);
  goto top_level_apply;
/* ___parse-number */
body_98:
  increment_count(env);
  val = wrap_function((&&function_266), env);
  global_c95c95c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* ___parse-number */
  goto body_99;
pointer global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108; /* ___parse-symbol */
pointer global_c95c102c110c50c51;
function_267:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_268:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_267);
  goto apply_addr;
function_269:
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
    target = (&&function_268);
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
    target = (&&function_268);
    goto apply_addr;
  }
function_270:
  goto top_level_apply;
function_271:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_270);
  goto apply_addr;
function_272:
  args = cons(val, args);
  increment_count(val = global_c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* string->symbol */);
  target = (&&function_271);
  goto apply_addr;
function_273:
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
    target = (&&function_272);
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
function_274:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_273);
  goto apply_addr;
function_275:
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
  target = (&&function_274);
  goto apply_addr;
function_276:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_275);
  goto apply_addr;
function_277:
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
      target = (&&function_269);
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
      target = (&&function_276);
      goto apply_addr;
    }
  }
function_278:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_277);
  goto apply_addr;
function_279:
  increment_count(env);
  val = wrap_function((&&function_278), env);
  goto pop_function;
/* _fn23 */
body_99:
global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* ___parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_279), env);
  global_c95c102c110c50c51 = val; /* _fn23 */
  goto body_100;
function_280:
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
  increment_count(val = global_c95c102c110c50c51 /* _fn23 */);
  goto top_level_apply;
/* ___parse-symbol */
body_100:
  increment_count(env);
  val = wrap_function((&&function_280), env);
  global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* ___parse-symbol */
  goto body_101;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110; /* ___parse-paren */
pointer global_c95c102c110c50c52;
function_281:
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
function_282:
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
    target = (&&function_281);
    goto apply_addr;
  }
function_283:
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
    target = (&&function_282);
    goto apply_addr;
  }
function_284:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_283);
  goto apply_addr;
function_285:
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
    target = (&&function_284);
    goto apply_addr;
  }
function_286:
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
    target = (&&function_285);
    goto apply_addr;
  }
function_287:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_286);
  goto apply_addr;
function_288:
  increment_count(env);
  val = wrap_function((&&function_287), env);
  goto pop_function;
/* _fn24 */
body_101:
global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* ___parse-paren */
  increment_count(env);
  val = wrap_function((&&function_288), env);
  global_c95c102c110c50c52 = val; /* _fn24 */
  goto body_102;
function_289:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c52 /* _fn24 */);
  goto top_level_apply;
/* ___parse-paren */
body_102:
  increment_count(env);
  val = wrap_function((&&function_289), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* ___parse-paren */
  goto body_103;
pointer global_c95c102c110c50c53; /* _fn25 */
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108; /* ___parse-tail */
pointer global_c95c102c110c50c54;
function_290:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c116c97c105c108 /* ___parse-tail */);
  goto top_level_apply;
function_291:
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
  increment_count(val = global_c95c102c110c50c53 /* _fn25 */);
  target = (&&function_290);
  goto apply_addr;
function_292:
  increment_count(env);
  val = wrap_function((&&function_291), env);
  goto pop_function;
/* _fn26 */
body_103:
global_c95c102c110c50c53 = nil(); /* _fn25 */
global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* ___parse-tail */
  increment_count(env);
  val = wrap_function((&&function_292), env);
  global_c95c102c110c50c54 = val; /* _fn26 */
  goto body_104;
function_293:
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
function_294:
  increment_count(env);
  val = wrap_function((&&function_293), env);
  goto pop_function;
/* _fn25 */
body_104:
  increment_count(env);
  val = wrap_function((&&function_294), env);
  global_c95c102c110c50c53 = val; /* _fn25 */
  goto body_105;
pointer global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_295:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c50c54 /* _fn26 */);
  goto top_level_apply;
/* ___parse-tail-cont */
body_105:
  increment_count(env);
  val = wrap_function((&&function_295), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* ___parse-tail-cont */
  goto body_106;
pointer global_c95c102c110c50c56; /* _fn28 */
pointer global_c112c97c114c115c101c45c101c120c112c114; /* parse-expr */
pointer global_c95c102c110c50c57;
function_296:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_297:
  goto top_level_apply;
function_298:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_297);
  goto apply_addr;
function_299:
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
    target = (&&function_298);
    goto apply_addr;
  }
function_300:
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
    increment_count(val = global_c95c102c110c50c56 /* _fn28 */);
    target = (&&function_296);
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
    target = (&&function_299);
    goto apply_addr;
  }
function_301:
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
    target = (&&function_300);
    goto apply_addr;
  }
function_302:
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
    target = (&&function_301);
    goto apply_addr;
  }
function_303:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_302);
  goto apply_addr;
function_304:
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
    target = (&&function_303);
    goto apply_addr;
  }
function_305:
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
    target = (&&function_304);
    goto apply_addr;
  }
function_306:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_305);
  goto apply_addr;
function_307:
  increment_count(env);
  val = wrap_function((&&function_306), env);
  goto pop_function;
/* _fn29 */
body_106:
global_c95c102c110c50c56 = nil(); /* _fn28 */
global_c112c97c114c115c101c45c101c120c112c114 = nil(); /* parse-expr */
  increment_count(env);
  val = wrap_function((&&function_307), env);
  global_c95c102c110c50c57 = val; /* _fn29 */
  goto body_107;
pointer global_c95c102c110c50c55; /* _fn27 */
function_308:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c112c97c114c101c110 /* ___parse-paren */);
  goto top_level_apply;
function_309:
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
  increment_count(val = global_c95c102c110c50c55 /* _fn27 */);
  target = (&&function_308);
  goto apply_addr;
function_310:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  goto pop_function;
/* _fn28 */
body_107:
global_c95c102c110c50c55 = nil(); /* _fn27 */
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c95c102c110c50c56 = val; /* _fn28 */
  goto body_108;
function_311:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_312:
  increment_count(env);
  val = wrap_function((&&function_311), env);
  goto pop_function;
/* _fn27 */
body_108:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  global_c95c102c110c50c55 = val; /* _fn27 */
  goto body_109;
function_313:
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
/* ___parse-tail */
body_109:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c95c95c95c112c97c114c115c101c45c116c97c105c108 = val; /* ___parse-tail */
  goto body_110;
pointer global_c95c95c95c112c97c114c115c101c45c112c97c105c114; /* ___parse-pair */
pointer global_c95c102c110c51c48;
function_314:
  goto top_level_apply;
function_315:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  target = (&&function_314);
  goto apply_addr;
function_316:
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
    target = (&&function_315);
    goto apply_addr;
  }
function_317:
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
    target = (&&function_316);
    goto apply_addr;
  }
function_318:
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
    target = (&&function_317);
    goto apply_addr;
  }
function_319:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_318);
  goto apply_addr;
function_320:
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
    target = (&&function_319);
    goto apply_addr;
  }
function_321:
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
    target = (&&function_320);
    goto apply_addr;
  }
function_322:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  increment_count(env);
  val = wrap_function((&&function_322), env);
  goto pop_function;
/* _fn30 */
body_110:
global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* ___parse-pair */
  increment_count(env);
  val = wrap_function((&&function_323), env);
  global_c95c102c110c51c48 = val; /* _fn30 */
  goto body_111;
function_324:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c48 /* _fn30 */);
  goto top_level_apply;
/* ___parse-pair */
body_111:
  increment_count(env);
  val = wrap_function((&&function_324), env);
  global_c95c95c95c112c97c114c115c101c45c112c97c105c114 = val; /* ___parse-pair */
  goto body_112;
pointer global_c95c102c110c51c51; /* _fn33 */
pointer global_c95c102c110c51c50; /* _fn32 */
pointer global_c95c102c110c51c49; /* _fn31 */
pointer global_c95c102c110c51c52;
function_325:
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
function_326:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_327:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_328:
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
function_329:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c112c97c114c115c101c45c115c121c109c98c111c108 /* ___parse-symbol */);
  goto top_level_apply;
function_330:
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
    target = (&&function_329);
    goto apply_addr;
  }
function_331:
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
    target = (&&function_330);
    goto apply_addr;
  }
function_332:
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
    increment_count(val = global_c95c102c110c51c51 /* _fn33 */);
    target = (&&function_328);
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
    target = (&&function_331);
    goto apply_addr;
  }
function_333:
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
    target = (&&function_332);
    goto apply_addr;
  }
function_334:
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
    increment_count(val = global_c95c102c110c51c50 /* _fn32 */);
    target = (&&function_327);
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
    target = (&&function_333);
    goto apply_addr;
  }
function_335:
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
    target = (&&function_334);
    goto apply_addr;
  }
function_336:
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
    target = (&&function_335);
    goto apply_addr;
  }
function_337:
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
    target = (&&function_326);
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
    target = (&&function_336);
    goto apply_addr;
  }
function_338:
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
    target = (&&function_337);
    goto apply_addr;
  }
function_339:
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
    target = (&&function_325);
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
    target = (&&function_338);
    goto apply_addr;
  }
function_340:
  args = cons(val, args);
  increment_count(val = global_c111c114 /* or */);
  target = (&&function_339);
  goto apply_addr;
function_341:
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
    target = (&&function_340);
    goto apply_addr;
  }
function_342:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_341);
  goto apply_addr;
function_343:
  increment_count(env);
  val = wrap_function((&&function_342), env);
  goto pop_function;
/* _fn34 */
body_112:
global_c95c102c110c51c51 = nil(); /* _fn33 */
global_c95c102c110c51c50 = nil(); /* _fn32 */
global_c95c102c110c51c49 = nil(); /* _fn31 */
  increment_count(env);
  val = wrap_function((&&function_343), env);
  global_c95c102c110c51c52 = val; /* _fn34 */
  goto body_113;
function_344:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_345:
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
  target = (&&function_344);
  goto apply_addr;
function_346:
  increment_count(env);
  val = wrap_function((&&function_345), env);
  goto pop_function;
/* _fn31 */
body_113:
  increment_count(env);
  val = wrap_function((&&function_346), env);
  global_c95c102c110c51c49 = val; /* _fn31 */
  goto body_114;
function_347:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_348:
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
  target = (&&function_347);
  goto apply_addr;
function_349:
  increment_count(env);
  val = wrap_function((&&function_348), env);
  goto pop_function;
/* _fn32 */
body_114:
  increment_count(env);
  val = wrap_function((&&function_349), env);
  global_c95c102c110c51c50 = val; /* _fn32 */
  goto body_115;
function_350:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_351:
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
  target = (&&function_350);
  goto apply_addr;
function_352:
  increment_count(env);
  val = wrap_function((&&function_351), env);
  goto pop_function;
/* _fn33 */
body_115:
  increment_count(env);
  val = wrap_function((&&function_352), env);
  global_c95c102c110c51c51 = val; /* _fn33 */
  goto body_116;
function_353:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c52 /* _fn34 */);
  goto top_level_apply;
/* parse-expr */
body_116:
  increment_count(env);
  val = wrap_function((&&function_353), env);
  global_c112c97c114c115c101c45c101c120c112c114 = val; /* parse-expr */
  goto body_117;
pointer global_c114c101c97c100c45c101c120c112c114;
function_354:
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116c45c101c114c114c111c114 /* print-error */);
  goto top_level_apply;
function_355:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c55 /* ____l27 */);
  args = cons(val, args);
  increment_count(val = global_c97c112c112c101c110c100 /* append */);
  target = (&&function_354);
  goto apply_addr;
function_356:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c95c108c50c57 /* ____l29 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c50c56 /* ____l28 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c112c114c105c110c116 /* print */);
  target = (&&function_355);
  goto apply_addr;
function_357:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_356), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c112c97c114c115c101c45c101c120c112c114 /* parse-expr */);
  goto top_level_apply;
/* read-expr */
body_117:
  increment_count(env);
  val = wrap_function((&&function_357), env);
  global_c114c101c97c100c45c101c120c112c114 = val; /* read-expr */
  goto body_118;
pointer global_c95c95c95c95c108c51c48;
/* ____l30 */
body_118:
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
  global_c95c95c95c95c108c51c48 = val; /* ____l30 */
  goto body_119;
pointer global_c95c95c95c95c108c51c49;
/* ____l31 */
body_119:
  val = new_symbol(-35);
  global_c95c95c95c95c108c51c49 = val; /* ____l31 */
  goto body_120;
pointer global_c95c95c95c95c108c51c50;
/* ____l32 */
body_120:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c95c108c51c50 = val; /* ____l32 */
  goto body_121;
pointer global_c95c95c95c95c108c51c51;
/* ____l33 */
body_121:
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
  global_c95c95c95c95c108c51c51 = val; /* ____l33 */
  goto body_122;
pointer global_c99c97c97c100c114;
function_358:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* caadr */
body_122:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  global_c99c97c97c100c114 = val; /* caadr */
  goto body_123;
pointer global_c95c102c110c51c53; /* _fn35 */
pointer global_c95c102c110c51c54;
function_359:
  increment_count(val = global_c95c95c95c95c108c51c50 /* ____l32 */);
  goto pop_function;
function_360:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101 /* compile */);
  goto top_level_apply;
function_361:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c51c51 /* ____l33 */);
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c102c110c51c53 /* _fn35 */);
    target = (&&function_360);
    goto apply_addr;
  }
function_362:
  args = cons(val, args);
  increment_count(val = global_c97c110c100 /* and */);
  target = (&&function_361);
  goto apply_addr;
function_363:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_362);
  goto apply_addr;
function_364:
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
  target = (&&function_363);
  goto apply_addr;
function_365:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_364);
  goto apply_addr;
function_366:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(env);
    val = wrap_function((&&function_359), env);
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c99c111c109c112c105c108c101 /* compile */);
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
    increment_count(val = global_c99c97c97c100c114 /* caadr */);
    target = (&&function_365);
    goto apply_addr;
  }
function_367:
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_366);
  goto apply_addr;
function_368:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c108c51c48 /* ____l30 */);
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
    increment_count(val = global_c95c95c95c95c108c51c49 /* ____l31 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_367);
    goto apply_addr;
  }
function_369:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c110c111c116 /* not */);
  target = (&&function_368);
  goto apply_addr;
function_370:
  increment_count(env);
  val = wrap_function((&&function_369), env);
  goto pop_function;
/* _fn36 */
body_123:
global_c95c102c110c51c53 = nil(); /* _fn35 */
  increment_count(env);
  val = wrap_function((&&function_370), env);
  global_c95c102c110c51c54 = val; /* _fn36 */
  goto body_124;
pointer global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* compile-source */
function_371:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_372:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_371);
  goto apply_addr;
function_373:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  goto pop_function;
/* _fn35 */
body_124:
global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = nil(); /* compile-source */
  increment_count(env);
  val = wrap_function((&&function_373), env);
  global_c95c102c110c51c53 = val; /* _fn35 */
  goto body_125;
function_374:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c110c51c54 /* _fn36 */);
  goto top_level_apply;
/* compile-source */
body_125:
  increment_count(env);
  val = wrap_function((&&function_374), env);
  global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* compile-source */
  goto body_126;
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
function_375:
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
function_376:
  args = cons(val, args);
  increment_count(val = global_c114c101c97c100c45c101c120c112c114 /* read-expr */);
  goto top_level_apply;
function_377:
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* compile-source */);
  target = (&&function_376);
  goto apply_addr;
body_126:
  increment_count(env);
  val = wrap_function((&&function_377), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_375), nil()), call_stack);
  goto body_0;
}
