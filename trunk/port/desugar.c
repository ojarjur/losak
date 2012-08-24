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
pointer global_c95c101c113c117c97c108;
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    goto top_level_apply;
  } else {
    val = nil();
    goto pop_function;
  }
function_1:
  if (is_atom(car(car(env)))) {
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
    if ((is_binary(args)) &
        (is_atom(car(args))) &
        (is_atom(car(cdr(args)))) &
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = nil(); }
    pop_args();
    goto pop_function;
  } else {
    if (is_atom(car(cdr(car(env))))) {
      increment_count(val = true);
    } else {
      val = nil();
    }
    if (! is_nil(val)) {
      decrement_count(val);
      val = nil();
      goto pop_function;
    } else {
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(cdr(car(env)))));
      args = cons(val, args);
      increment_count(val = car(car(car(env))));
      args = cons(val, args);
      increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
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
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = cdr(car(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_3:
  if (is_atom(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
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
          val = new_number(109);
          args = cons(val, args);
          val = new_number(111);
          args = cons(val, args);
          val = new_number(116);
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
                                                                                                                                                                  val = new_symbol(-34);
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
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-114);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
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
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-34);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = new_symbol(-114);
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
    val = new_symbol(-35);
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_4);
    goto apply_addr;
  }
function_6:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_5);
    goto apply_addr;
  }
function_7:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_6);
    goto apply_addr;
  }
function_8:
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
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_7);
    goto apply_addr;
  }
function_9:
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
    val = new_number(116);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_8);
    goto apply_addr;
  }
function_10:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_9);
    goto apply_addr;
  }
function_11:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_10);
    goto apply_addr;
  }
function_12:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_11);
    goto apply_addr;
  }
function_13:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_12);
    goto apply_addr;
  }
function_14:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_13);
    goto apply_addr;
  }
function_15:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_14);
    goto apply_addr;
  }
function_16:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_15);
    goto apply_addr;
  }
function_17:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_16);
    goto apply_addr;
  }
function_18:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_17);
    goto apply_addr;
  }
function_19:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_18);
    goto apply_addr;
  }
function_20:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_19);
    goto apply_addr;
  }
function_21:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_20);
    goto apply_addr;
  }
function_22:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_21);
    goto apply_addr;
  }
function_23:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_22);
    goto apply_addr;
  }
function_24:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_23);
    goto apply_addr;
  }
function_25:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_24);
    goto apply_addr;
  }
function_26:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_25);
    goto apply_addr;
  }
function_27:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_26);
    goto apply_addr;
  }
function_28:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_28);
    goto apply_addr;
  }
function_30:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_29);
    goto apply_addr;
  }
function_31:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_30);
    goto apply_addr;
  }
function_32:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_32);
    goto apply_addr;
  }
function_34:
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_33);
    goto apply_addr;
  }
function_35:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_34);
    goto apply_addr;
  }
function_36:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_35);
    goto apply_addr;
  }
function_37:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_36);
    goto apply_addr;
  }
function_38:
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_37);
    goto apply_addr;
  }
function_39:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_38);
    goto apply_addr;
  }
function_40:
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_39);
    goto apply_addr;
  }
function_41:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_40);
    goto apply_addr;
  }
function_42:
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_41);
    goto apply_addr;
  }
function_43:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_42);
    goto apply_addr;
  }
function_44:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_43);
    goto apply_addr;
  }
function_45:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_44);
    goto apply_addr;
  }
function_46:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_45);
    goto apply_addr;
  }
function_47:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_46);
    goto apply_addr;
  }
function_48:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_47);
    goto apply_addr;
  }
function_49:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_48);
    goto apply_addr;
  }
function_50:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_49);
    goto apply_addr;
  }
function_51:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_50);
    goto apply_addr;
  }
function_52:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_51);
    goto apply_addr;
  }
function_53:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_52);
    goto apply_addr;
  }
function_54:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_53);
    goto apply_addr;
  }
function_55:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_54);
    goto apply_addr;
  }
function_56:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_55);
    goto apply_addr;
  }
function_57:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_56);
    goto apply_addr;
  }
function_58:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_57);
    goto apply_addr;
  }
function_59:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_58);
    goto apply_addr;
  }
function_60:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_59);
    goto apply_addr;
  }
function_61:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_60);
    goto apply_addr;
  }
function_62:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_61);
    goto apply_addr;
  }
function_63:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_62);
    goto apply_addr;
  }
function_64:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_63);
    goto apply_addr;
  }
function_65:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_64);
    goto apply_addr;
  }
function_66:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_65);
    goto apply_addr;
  }
function_67:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_66);
    goto apply_addr;
  }
function_68:
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
    val = new_number(94);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_67);
    goto apply_addr;
  }
function_69:
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
    val = new_number(124);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_68);
    goto apply_addr;
  }
function_70:
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
    val = new_number(38);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_69);
    goto apply_addr;
  }
function_71:
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
    val = new_number(126);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_70);
    goto apply_addr;
  }
function_72:
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
    val = new_number(37);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_71);
    goto apply_addr;
  }
function_73:
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
    val = new_number(47);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_72);
    goto apply_addr;
  }
function_74:
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
    val = new_number(42);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_73);
    goto apply_addr;
  }
function_75:
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
    val = new_number(45);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_74);
    goto apply_addr;
  }
function_76:
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
    val = new_number(43);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_75);
    goto apply_addr;
  }
function_77:
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
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_76);
    goto apply_addr;
  }
function_78:
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
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_77);
    goto apply_addr;
  }
function_79:
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
    val = new_number(61);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_78);
    goto apply_addr;
  }
function_80:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_79);
    goto apply_addr;
  }
function_81:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_80);
    goto apply_addr;
  }
function_82:
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
    val = new_number(109);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = args;
    args = nil();
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_81);
    goto apply_addr;
  }
function_83:
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
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
  increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
  target = (&&function_83);
  goto apply_addr;
/* _string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_84), env);
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_85:
  push_args();
  val = nil();
  args = val;
  val = nil();
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
        if (is_atom(car(car(env)))) {
          increment_count(val = true);
        } else {
          val = nil();
        }
        if (! is_nil(val)) {
          decrement_count(val);
          val = new_symbol(-38);
          goto pop_function;
        } else {
          push_args();
          val = nil();
          args = val;
          val = new_symbol(-114);
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
            val = new_symbol(-38);
            goto pop_function;
          } else {
            val = nil();
            goto pop_function;
          }
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
  if (is_atom(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-114);
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
      val = new_symbol(-38);
      goto pop_function;
    }
  }
/* __pair? */
body_4:
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c97c116c111c109;
function_87:
  if (is_atom(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-38);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-114);
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
      val = new_symbol(-38);
      goto pop_function;
    } else {
      val = nil();
      goto pop_function;
    }
  }
/* __atom */
body_5:
  increment_count(env);
  val = wrap_function((&&function_87), env);
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_6;
pointer global_c95c95c61;
function_88:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    goto top_level_apply;
  } else {
    val = nil();
    goto pop_function;
  }
function_89:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_88);
  goto apply_addr;
/* __= */
body_6:
  increment_count(env);
  val = wrap_function((&&function_89), env);
  global_c95c95c61 = val; /* __= */
  goto body_7;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_7:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_8;
pointer global_c95c105c100;
function_90:
  increment_count(val = car(car(env)));
  goto pop_function;
/* _id */
body_8:
  increment_count(env);
  val = wrap_function((&&function_90), env);
  global_c95c105c100 = val; /* _id */
  goto body_9;
pointer global_c95c119c97c108c107; /* _walk */
pointer global_c102c110c95c48;
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
  increment_count(val = global_c95c119c97c108c107 /* _walk */);
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
/* fn_0 */
body_9:
global_c95c119c97c108c107 = nil(); /* _walk */
  increment_count(env);
  val = wrap_function((&&function_97), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_10;
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
  increment_count(val = global_c102c110c95c48 /* fn_0 */);
  goto top_level_apply;
/* _walk */
body_10:
  increment_count(env);
  val = wrap_function((&&function_98), env);
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_11;
pointer global_c95c114c114c101c118c101c114c115c101;
function_99:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
  } else {
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
    increment_count(val = global_c95c114c114c101c118c101c114c115c101 /* _rreverse */);
    goto top_level_apply;
  }
function_100:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_99);
  goto apply_addr;
/* _rreverse */
body_11:
  increment_count(env);
  val = wrap_function((&&function_100), env);
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_12;
pointer global_c95c102c111c108c100c108; /* _foldl */
pointer global_c102c110c95c49;
function_101:
  goto top_level_apply;
function_102:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108 /* _foldl */);
  target = (&&function_101);
  goto apply_addr;
function_103:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
  } else {
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
  }
function_104:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_103);
  goto apply_addr;
function_105:
  increment_count(env);
  val = wrap_function((&&function_104), env);
  goto pop_function;
/* fn_1 */
body_12:
global_c95c102c111c108c100c108 = nil(); /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_105), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_13;
function_106:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49 /* fn_1 */);
  goto top_level_apply;
/* _foldl */
body_13:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_14;
pointer global_c102c110c95c50;
function_107:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101 /* _rreverse */);
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
  increment_count(val = global_c95c102c111c108c100c108 /* _foldl */);
  target = (&&function_107);
  goto apply_addr;
function_109:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  goto pop_function;
/* fn_2 */
body_14:
  increment_count(env);
  val = wrap_function((&&function_109), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_15;
pointer global_c95c102c111c108c100c114;
function_110:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50 /* fn_2 */);
  goto top_level_apply;
/* _foldr */
body_15:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_16;
pointer global_c95c97c112c112c101c110c100;
function_111:
  goto top_level_apply;
function_112:
  goto top_level_apply;
function_113:
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
function_114:
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
    val = wrap_function((&&function_113), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
    target = (&&function_112);
    goto apply_addr;
  }
function_115:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_114);
  goto apply_addr;
function_116:
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
  val = wrap_function((&&function_115), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_111);
  goto apply_addr;
/* _append */
body_16:
  increment_count(env);
  val = wrap_function((&&function_116), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_17;
pointer global_c102c110c95c51;
function_117:
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
function_118:
  increment_count(env);
  val = wrap_function((&&function_117), env);
  goto pop_function;
/* fn_3 */
body_17:
  increment_count(env);
  val = wrap_function((&&function_118), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_18;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_119:
  goto top_level_apply;
function_120:
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
function_121:
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
function_122:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
function_123:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51 /* fn_3 */);
  goto top_level_apply;
function_124:
  increment_count(val = global_c95c105c100 /* _id */);
  goto pop_function;
function_125:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(env);
  val = wrap_function((&&function_124), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_123), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_122), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_121), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_120), env);
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107 /* _walk */);
  target = (&&function_119);
  goto apply_addr;
/* _build-num-str */
body_18:
  increment_count(env);
  val = wrap_function((&&function_125), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_19;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_126:
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
function_127:
  target = (&&function_126);
  goto apply_addr;
function_128:
  goto top_level_apply;
function_129:
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
      increment_count(val = global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 /* _build-num-str */);
      target = (&&function_127);
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
      increment_count(val = global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 /* _build-num-str */);
      target = (&&function_128);
      goto apply_addr;
    }
  }
function_130:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_129);
  goto apply_addr;
/* _print-num */
body_19:
  increment_count(env);
  val = wrap_function((&&function_130), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_20;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_131:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* _symbol->string */);
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
function_132:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
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
      increment_count(val = global_c95c112c114c105c110c116c45c110c117c109 /* _print-num */);
      goto top_level_apply;
    } else {
      push_args();
      val = nil();
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
      target = (&&function_131);
      goto apply_addr;
    }
  } else {
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
  }
/* _print-atom */
body_20:
  increment_count(env);
  val = wrap_function((&&function_132), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_21;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_133:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_134:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_135:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_134);
  goto apply_addr;
function_136:
  if (! is_nil(val)) {
    decrement_count(val);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109 /* _print-atom */);
    target = (&&function_133);
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
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108 /* _print-tail */);
    target = (&&function_135);
    goto apply_addr;
  }
function_137:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_136);
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
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    goto top_level_apply;
  }
/* _print-tail */
body_21:
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = nil(); /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_137), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_22;
function_138:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_139:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_140:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_139);
  goto apply_addr;
function_141:
  if (! is_nil(val)) {
    decrement_count(val);
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
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109 /* _print-atom */);
    target = (&&function_138);
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
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108 /* _print-tail */);
    target = (&&function_140);
    goto apply_addr;
  }
function_142:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_141);
  goto apply_addr;
/* _print-with-suffix */
body_22:
  increment_count(env);
  val = wrap_function((&&function_142), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_23;
pointer global_c95c112c114c105c110c116;
function_143:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  goto top_level_apply;
/* _print */
body_23:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_24;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101;
function_144:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_145:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50 /* ___l_2 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_144);
  goto apply_addr;
/* ____print-with-newline */
body_24:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 = val; /* ____print-with-newline */
  goto body_25;
pointer global_c95c108c105c115c116;
function_146:
  increment_count(val = car(env));
  goto pop_function;
/* _list */
body_25:
  increment_count(env);
  val = wrap_function((&&function_146), env);
  global_c95c108c105c115c116 = val; /* _list */
  goto body_26;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_147:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_27;
function_148:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_149:
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
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_148);
  goto apply_addr;
/* ____map-to-stderr */
body_26:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_149), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_147);
  goto apply_addr;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_27:
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
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  goto body_28;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_28:
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
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_29;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_29:
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
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_30;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_30:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_31;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_150:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_151:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52 /* ___l_4 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51 /* ___l_3 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_150);
  goto apply_addr;
function_152:
  increment_count(val = car(cdr(car(env))));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c54 /* ___l_6 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53 /* ___l_5 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116 /* _print */);
    target = (&&function_151);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
/* ____print-warnings */
body_31:
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_32;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_32:
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
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_33;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_33:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_34;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_153:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_154:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c56 /* ___l_8 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55 /* ___l_7 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_153);
  goto apply_addr;
/* ____print-error */
body_34:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_35;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_35:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-39);
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = new_symbol(-34);
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  val = new_symbol(-40);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_36;
pointer global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ____special-forms */
body_36:
  increment_count(val = global_c95c95c95c108c95c57 /* ___l_9 */);
  global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ____special-forms */
  goto body_37;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_37:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-87);
  args = cons(val, args);
  val = new_symbol(-88);
  args = cons(val, args);
  val = new_symbol(-89);
  args = cons(val, args);
  val = new_symbol(-90);
  args = cons(val, args);
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
  val = new_symbol(-43);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_38;
pointer global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115;
/* ____supported-builtins */
body_38:
  increment_count(val = global_c95c95c95c108c95c49c48 /* ___l_10 */);
  global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 = val; /* ____supported-builtins */
  goto body_39;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_39:
  val = nil();
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_40;
pointer global_c95c95c95c95c102c108c97c116c116c101c110;
function_155:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110 /* ____flatten */);
  goto top_level_apply;
function_156:
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
    increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110 /* ____flatten */);
    target = (&&function_155);
    goto apply_addr;
  }
function_157:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_156);
    goto apply_addr;
  }
function_158:
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
    target = (&&function_157);
    goto apply_addr;
  }
function_159:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c49 /* ___l_11 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_158);
  goto apply_addr;
/* ____flatten */
body_40:
  increment_count(env);
  val = wrap_function((&&function_159), env);
  global_c95c95c95c95c102c108c97c116c116c101c110 = val; /* ____flatten */
  goto body_41;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_41:
  val = nil();
  push_args();
  args = val;
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
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_42;
pointer global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115;
/* ____supported-library-procedures */
body_42:
  increment_count(val = global_c95c95c95c108c95c49c50 /* ___l_12 */);
  global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 = val; /* ____supported-library-procedures */
  goto body_43;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_43:
  val = nil();
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_44;
pointer global_c95c95c101c113c117c97c108;
function_160:
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
function_161:
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    target = (&&function_160);
    goto apply_addr;
  }
function_162:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_161);
    goto apply_addr;
  }
function_163:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_162);
  goto apply_addr;
/* __equal */
body_44:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_45;
pointer global_c95c109c101c109c98c101c114;
function_164:
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
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    goto top_level_apply;
  }
function_165:
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c101c113c117c97c108 /* __equal */);
    target = (&&function_164);
    goto apply_addr;
  }
function_166:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_165);
  goto apply_addr;
/* _member */
body_45:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_46;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_167:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
function_168:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51 /* ___l_13 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_167);
  goto apply_addr;
function_169:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* _symbol->string */);
    target = (&&function_168);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_170:
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
    target = (&&function_169);
    goto apply_addr;
  }
function_171:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 /* ____supported-library-procedures */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_170);
    goto apply_addr;
  }
function_172:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 /* ____supported-builtins */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_171);
    goto apply_addr;
  }
function_173:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_174:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_173);
  goto apply_addr;
function_175:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 /* ____special-forms */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_172);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
    target = (&&function_174);
    goto apply_addr;
  }
function_176:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_175);
  goto apply_addr;
/* ____escape-symbols */
body_46:
  increment_count(env);
  val = wrap_function((&&function_176), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_47;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_47:
  val = nil();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_48;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_48:
  val = nil();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_49;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_49:
  val = nil();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_50;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_50:
  val = nil();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_51;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_51:
  val = nil();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_52;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_52:
  val = nil();
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_53;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_53:
  val = nil();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_54;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_54:
  val = nil();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_55;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_55:
  val = nil();
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_56;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_56:
  val = nil();
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_57;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_57:
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
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_58;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_58:
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
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_59;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100;
function_177:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c52 /* ___l_14 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_178:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c51 /* ___l_23 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50 /* ___l_22 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  goto top_level_apply;
function_179:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c52 /* ___l_24 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_178);
  goto apply_addr;
function_180:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c49 /* ___l_21 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c48 /* ___l_20 */);
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
    increment_count(val = global_c95c95c95c108c95c50c53 /* ___l_25 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* _symbol->string */);
    target = (&&function_179);
    goto apply_addr;
  }
function_181:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c57 /* ___l_19 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56 /* ___l_18 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 /* ____special-forms */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_180);
    goto apply_addr;
  }
function_182:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c55 /* ___l_17 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c54 /* ___l_16 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c108c105c98c114c97c114c121c45c112c114c111c99c101c100c117c114c101c115 /* ____supported-library-procedures */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_181);
    goto apply_addr;
  }
function_183:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c53 /* ___l_15 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
    target = (&&function_177);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c117c112c112c111c114c116c101c100c45c98c117c105c108c116c105c110c115 /* ____supported-builtins */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_182);
    goto apply_addr;
  }
function_184:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
  target = (&&function_183);
  goto apply_addr;
function_185:
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
  increment_count(val = global_c95c95c95c95c102c108c97c116c116c101c110 /* ____flatten */);
  target = (&&function_184);
  goto apply_addr;
/* ____compile-find */
body_59:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100 = val; /* ____compile-find */
  goto body_60;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_60:
  val = nil();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_61;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_61:
  val = new_symbol(-37);
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_62;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_62:
  val = new_symbol(-43);
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_63;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101;
function_186:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56 /* ___l_28 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_187:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 /* ____rewrite-quote */);
  target = (&&function_186);
  goto apply_addr;
function_188:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c50c55 /* ___l_27 */);
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116 /* _list */);
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
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 /* ____rewrite-quote */);
    target = (&&function_187);
    goto apply_addr;
  }
function_189:
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
      increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
      target = (&&function_188);
      goto apply_addr;
    }
  }
function_190:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54 /* ___l_26 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_189);
  goto apply_addr;
/* ____rewrite-quote */
body_63:
  increment_count(env);
  val = wrap_function((&&function_190), env);
  global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c111c116c101 = val; /* ____rewrite-quote */
  goto body_64;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_64:
  val = nil();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_65;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_65:
  val = nil();
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_66;
pointer global_c102c110c95c52;
function_191:
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
  increment_count(val = global_c95c95c95c108c95c50c57 /* ___l_29 */);
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
  val = new_symbol(-34);
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
function_192:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  goto pop_function;
/* fn_4 */
body_66:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_67;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101;
function_193:
  goto top_level_apply;
function_194:
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
  increment_count(val = global_c102c110c95c52 /* fn_4 */);
  target = (&&function_193);
  goto apply_addr;
function_195:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_194);
  goto apply_addr;
function_196:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48 /* ___l_30 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_195);
  goto apply_addr;
function_197:
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
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_196);
  goto apply_addr;
/* ____compile-quote */
body_67:
  increment_count(env);
  val = wrap_function((&&function_197), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101 = val; /* ____compile-quote */
  goto body_68;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_68:
  val = nil();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_69;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_69:
  val = nil();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_70;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_70:
  val = nil();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_71;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_71:
  val = new_symbol(-37);
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_72;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_72:
  val = nil();
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_73;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_73:
  val = new_symbol(-36);
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_74;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_74:
  val = new_symbol(-36);
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_75;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_75:
  val = new_symbol(-35);
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_76;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_76:
  val = new_symbol(-35);
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_77;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_77:
  val = new_symbol(-43);
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_78;
pointer global_c95c99c97c100c114;
function_198:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* _cadr */
body_78:
  increment_count(env);
  val = wrap_function((&&function_198), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_79;
pointer global_c102c110c95c53;
function_199:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_200:
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
  increment_count(val = global_c95c95c95c108c95c51c55 /* ___l_37 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_199);
  goto apply_addr;
function_201:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  goto pop_function;
/* fn_5 */
body_79:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_80;
pointer global_c102c110c95c54;
function_202:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_203:
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
  increment_count(val = global_c95c95c95c108c95c51c57 /* ___l_39 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_202);
  goto apply_addr;
function_204:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  goto pop_function;
/* fn_6 */
body_80:
  increment_count(env);
  val = wrap_function((&&function_204), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_81;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101; /* ____rewrite-quasiquote */
pointer global_c102c110c95c55; /* fn_7 */
pointer global_c102c110c95c56;
function_205:
  goto top_level_apply;
function_206:
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
  increment_count(val = global_c102c110c95c55 /* fn_7 */);
  target = (&&function_205);
  goto apply_addr;
function_207:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c108c105c115c116 /* _list */);
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* ____rewrite-quasiquote */);
  target = (&&function_206);
  goto apply_addr;
function_208:
  increment_count(env);
  val = wrap_function((&&function_207), env);
  goto pop_function;
/* fn_8 */
body_81:
global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = nil(); /* ____rewrite-quasiquote */
global_c102c110c95c55 = nil(); /* fn_7 */
  increment_count(env);
  val = wrap_function((&&function_208), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_82;
function_209:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_210:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_209);
  goto apply_addr;
function_211:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c48 /* ___l_40 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_210);
  goto apply_addr;
function_212:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_211);
  goto apply_addr;
function_213:
  increment_count(env);
  val = wrap_function((&&function_212), env);
  goto pop_function;
/* fn_7 */
body_82:
  increment_count(env);
  val = wrap_function((&&function_213), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_83;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114; /* ____compile-expr */
function_214:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c51 /* ___l_33 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  goto top_level_apply;
function_215:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_216:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* ____rewrite-quasiquote */);
  goto top_level_apply;
function_217:
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
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_216);
  goto apply_addr;
function_218:
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
    increment_count(val = global_c95c99c97c100c114 /* _cadr */);
    target = (&&function_215);
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
    increment_count(val = global_c102c110c95c53 /* fn_5 */);
    target = (&&function_217);
    goto apply_addr;
  }
function_219:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* ____rewrite-quasiquote */);
  goto top_level_apply;
function_220:
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
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_219);
  goto apply_addr;
function_221:
  goto top_level_apply;
function_222:
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
  increment_count(val = global_c102c110c95c56 /* fn_8 */);
  target = (&&function_221);
  goto apply_addr;
function_223:
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
    increment_count(val = global_c102c110c95c54 /* fn_6 */);
    target = (&&function_220);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c108c105c115c116 /* _list */);
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
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* ____rewrite-quasiquote */);
    target = (&&function_222);
    goto apply_addr;
  }
function_224:
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
    target = (&&function_218);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c56 /* ___l_38 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c53 /* ___l_35 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c52 /* ___l_34 */);
    args = cons(val, args);
    increment_count(val = global_c95c108c105c115c116 /* _list */);
    target = (&&function_214);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c54 /* ___l_36 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_224);
    goto apply_addr;
  }
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
    increment_count(val = global_c95c95c95c108c95c51c50 /* ___l_32 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51c49 /* ___l_31 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_225);
    goto apply_addr;
  }
/* ____rewrite-quasiquote */
body_83:
global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = nil(); /* ____compile-expr */
  increment_count(env);
  val = wrap_function((&&function_226), env);
  global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 = val; /* ____rewrite-quasiquote */
  goto body_84;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_84:
  val = nil();
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_85;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_85:
  val = new_symbol(-37);
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_86;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_86:
  val = nil();
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_87;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_87:
  val = nil();
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_88;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_88:
  val = nil();
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_89;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_89:
  val = new_symbol(-38);
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_90;
pointer global_c95c110c111c116;
function_227:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    val = new_symbol(-38);
    goto pop_function;
  }
/* _not */
body_90:
  increment_count(env);
  val = wrap_function((&&function_227), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_91;
pointer global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101;
function_228:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c53 /* ___l_45 */);
    goto pop_function;
  } else {
    increment_count(val = global_c95c95c95c108c95c52c54 /* ___l_46 */);
    goto pop_function;
  }
function_229:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c51 /* ___l_43 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c52 /* ___l_44 */);
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_228);
    goto apply_addr;
  }
function_230:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_229);
  goto apply_addr;
function_231:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c50 /* ___l_42 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_230);
    goto apply_addr;
  }
function_232:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c49 /* ___l_41 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_231);
    goto apply_addr;
  }
function_233:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_232);
  goto apply_addr;
/* ____always-true */
body_91:
  increment_count(env);
  val = wrap_function((&&function_233), env);
  global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101 = val; /* ____always-true */
  goto body_92;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_92:
  val = nil();
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_93;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_93:
  val = nil();
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_94;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_94:
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
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_95;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_95:
  val = new_symbol(-42);
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_96;
pointer global_c95c99c97c97c114;
function_234:
  increment_count(val = car(car(car(car(env)))));
  goto pop_function;
/* _caar */
body_96:
  increment_count(env);
  val = wrap_function((&&function_234), env);
  global_c95c99c97c97c114 = val; /* _caar */
  goto body_97;
pointer global_c95c99c97c100c97c114;
function_235:
  increment_count(val = car(cdr(car(car(car(env))))));
  goto pop_function;
/* _cadar */
body_97:
  increment_count(env);
  val = wrap_function((&&function_235), env);
  global_c95c99c97c100c97c114 = val; /* _cadar */
  goto body_98;
pointer global_c102c110c95c49c48; /* fn_10 */
pointer global_c102c110c95c49c49;
function_236:
  goto top_level_apply;
function_237:
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
  increment_count(val = global_c102c110c95c49c48 /* fn_10 */);
  target = (&&function_236);
  goto apply_addr;
function_238:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  target = (&&function_237);
  goto apply_addr;
function_239:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c108c105c115c116 /* _list */);
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
  increment_count(val = global_c95c99c97c100c97c114 /* _cadar */);
  target = (&&function_238);
  goto apply_addr;
function_240:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  goto pop_function;
/* fn_11 */
body_98:
global_c102c110c95c49c48 = nil(); /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_99;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100; /* ____rewrite-cond */
pointer global_c102c110c95c57; /* fn_9 */
function_241:
  goto top_level_apply;
function_242:
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
  increment_count(val = global_c102c110c95c57 /* fn_9 */);
  target = (&&function_241);
  goto apply_addr;
function_243:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(cdr(car(cdr(env))))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 /* ____rewrite-cond */);
  target = (&&function_242);
  goto apply_addr;
function_244:
  increment_count(env);
  val = wrap_function((&&function_243), env);
  goto pop_function;
/* fn_10 */
body_99:
global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = nil(); /* ____rewrite-cond */
global_c102c110c95c57 = nil(); /* fn_9 */
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_100;
function_245:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_246:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_245);
  goto apply_addr;
function_247:
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
  increment_count(val = global_c95c95c95c108c95c53c48 /* ___l_50 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_246);
  goto apply_addr;
function_248:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_247);
  goto apply_addr;
function_249:
  increment_count(env);
  val = wrap_function((&&function_248), env);
  goto pop_function;
/* fn_9 */
body_100:
  increment_count(env);
  val = wrap_function((&&function_249), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_101;
function_250:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_251:
  goto top_level_apply;
function_252:
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
  increment_count(val = global_c102c110c95c49c49 /* fn_11 */);
  target = (&&function_251);
  goto apply_addr;
function_253:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  target = (&&function_252);
  goto apply_addr;
function_254:
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
    increment_count(val = global_c95c99c97c100c97c114 /* _cadar */);
    target = (&&function_250);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c108c105c115c116 /* _list */);
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
    increment_count(val = global_c95c99c97c97c114 /* _caar */);
    target = (&&function_253);
    goto apply_addr;
  }
function_255:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c97c108c119c97c121c115c45c116c114c117c101 /* ____always-true */);
  target = (&&function_254);
  goto apply_addr;
function_256:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c57 /* ___l_49 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c56 /* ___l_48 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c52c55 /* ___l_47 */);
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c114 /* _caar */);
    target = (&&function_255);
    goto apply_addr;
  }
function_257:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_256);
  goto apply_addr;
/* ____rewrite-cond */
body_101:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 = val; /* ____rewrite-cond */
  goto body_102;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_102:
  val = new_symbol(-39);
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_103;
pointer global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116;
function_258:
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_259:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c49 /* ___l_51 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_258);
  goto apply_addr;
function_260:
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_259);
  goto apply_addr;
function_261:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c97c114 /* _caar */);
  target = (&&function_260);
  goto apply_addr;
function_262:
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
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116 /* ____rewrite-let */);
  target = (&&function_261);
  goto apply_addr;
function_263:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c97c114 /* _cadar */);
    target = (&&function_262);
    goto apply_addr;
  }
function_264:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_263);
  goto apply_addr;
/* ____rewrite-let */
body_103:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116 = val; /* ____rewrite-let */
  goto body_104;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115; /* ____compile-args */
pointer global_c102c110c95c49c50; /* fn_12 */
pointer global_c102c110c95c49c51;
function_265:
  goto top_level_apply;
function_266:
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
  increment_count(val = global_c102c110c95c49c50 /* fn_12 */);
  target = (&&function_265);
  goto apply_addr;
function_267:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = cdr(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 /* ____compile-args */);
  target = (&&function_266);
  goto apply_addr;
function_268:
  increment_count(env);
  val = wrap_function((&&function_267), env);
  goto pop_function;
/* fn_13 */
body_104:
global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = nil(); /* ____compile-args */
global_c102c110c95c49c50 = nil(); /* fn_12 */
  increment_count(env);
  val = wrap_function((&&function_268), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_105;
function_269:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_270:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_269);
  goto apply_addr;
function_271:
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
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_270);
  goto apply_addr;
function_272:
  increment_count(env);
  val = wrap_function((&&function_271), env);
  goto pop_function;
/* fn_12 */
body_105:
  increment_count(env);
  val = wrap_function((&&function_272), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_106;
function_273:
  goto top_level_apply;
function_274:
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
  increment_count(val = global_c102c110c95c49c51 /* fn_13 */);
  target = (&&function_273);
  goto apply_addr;
function_275:
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c108c105c115c116 /* _list */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
    target = (&&function_274);
    goto apply_addr;
  }
function_276:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_275);
  goto apply_addr;
/* ____compile-args */
body_106:
  increment_count(env);
  val = wrap_function((&&function_276), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 = val; /* ____compile-args */
  goto body_107;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_107:
  val = nil();
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_108;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_108:
  val = nil();
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_109;
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
body_109:
  val = new_symbol(-37);
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  goto body_110;
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
body_110:
  val = new_symbol(-35);
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  goto body_111;
pointer global_c95c95c95c108c95c53c54;
/* ___l_56 */
body_111:
  val = new_symbol(-36);
  global_c95c95c95c108c95c53c54 = val; /* ___l_56 */
  goto body_112;
pointer global_c95c95c95c108c95c53c55;
/* ___l_57 */
body_112:
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
  global_c95c95c95c108c95c53c55 = val; /* ___l_57 */
  goto body_113;
pointer global_c95c95c95c108c95c53c56;
/* ___l_58 */
body_113:
  val = new_symbol(-41);
  global_c95c95c95c108c95c53c56 = val; /* ___l_58 */
  goto body_114;
pointer global_c95c95c95c108c95c53c57;
/* ___l_59 */
body_114:
  val = new_symbol(-40);
  global_c95c95c95c108c95c53c57 = val; /* ___l_59 */
  goto body_115;
pointer global_c95c95c95c108c95c54c48;
/* ___l_60 */
body_115:
  val = new_symbol(-39);
  global_c95c95c95c108c95c54c48 = val; /* ___l_60 */
  goto body_116;
pointer global_c95c95c95c108c95c54c49;
/* ___l_61 */
body_116:
  val = new_symbol(-39);
  global_c95c95c95c108c95c54c49 = val; /* ___l_61 */
  goto body_117;
pointer global_c95c99c97c100c100c114;
function_277:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* _caddr */
body_117:
  increment_count(env);
  val = wrap_function((&&function_277), env);
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_118;
pointer global_c102c110c95c49c52;
function_278:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_279:
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
  increment_count(val = global_c95c95c95c108c95c53c55 /* ___l_57 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_278);
  goto apply_addr;
function_280:
  increment_count(env);
  val = wrap_function((&&function_279), env);
  goto pop_function;
/* fn_14 */
body_118:
  increment_count(env);
  val = wrap_function((&&function_280), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_119;
pointer global_c102c110c95c49c53;
function_281:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_282:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c49 /* ___l_61 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_281);
  goto apply_addr;
function_283:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_282);
  goto apply_addr;
function_284:
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
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_283);
  goto apply_addr;
function_285:
  increment_count(env);
  val = wrap_function((&&function_284), env);
  goto pop_function;
/* fn_15 */
body_119:
  increment_count(env);
  val = wrap_function((&&function_285), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_120;
function_286:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c113c117c97c115c105c113c117c111c116c101 /* ____rewrite-quasiquote */);
  goto top_level_apply;
function_287:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_288:
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
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_287);
  goto apply_addr;
function_289:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_290:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c108c101c116 /* ____rewrite-let */);
  target = (&&function_289);
  goto apply_addr;
function_291:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_290);
  goto apply_addr;
function_292:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_293:
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
  increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
  target = (&&function_292);
  goto apply_addr;
function_294:
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
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_293);
  goto apply_addr;
function_295:
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
    increment_count(val = global_c102c110c95c49c53 /* fn_15 */);
    target = (&&function_294);
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c97c114c103c115 /* ____compile-args */);
    goto top_level_apply;
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
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
    target = (&&function_291);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c48 /* ___l_60 */);
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c114c101c119c114c105c116c101c45c99c111c110c100 /* ____rewrite-cond */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c57 /* ___l_59 */);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c49c52 /* fn_14 */);
    target = (&&function_288);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c56 /* ___l_58 */);
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
    val = new_number(0);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114 /* _cadr */);
    target = (&&function_286);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c54 /* ___l_56 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_298);
    goto apply_addr;
  }
function_300:
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c113c117c111c116c101 /* ____compile-quote */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c53 /* ___l_55 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c51 /* ___l_53 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c53c50 /* ___l_52 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c52 /* ___l_54 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c102c105c110c100 /* ____compile-find */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_301);
    goto apply_addr;
  }
function_303:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_302);
  goto apply_addr;
/* ____compile-expr */
body_120:
  increment_count(env);
  val = wrap_function((&&function_303), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 = val; /* ____compile-expr */
  goto body_121;
pointer global_c95c99c97c97c100c114;
function_304:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* _caadr */
body_121:
  increment_count(env);
  val = wrap_function((&&function_304), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_122;
pointer global_c95c95c95c95c103c101c116c45c110c97c109c101;
function_305:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c114 /* _cadr */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c100c114 /* _caadr */);
    goto top_level_apply;
  }
function_306:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_305);
  goto apply_addr;
function_307:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_306);
  goto apply_addr;
/* ____get-name */
body_122:
  increment_count(env);
  val = wrap_function((&&function_307), env);
  global_c95c95c95c95c103c101c116c45c110c97c109c101 = val; /* ____get-name */
  goto body_123;
pointer global_c95c95c95c108c95c54c50;
/* ___l_62 */
body_123:
  val = new_symbol(-39);
  global_c95c95c95c108c95c54c50 = val; /* ___l_62 */
  goto body_124;
pointer global_c95c95c95c95c103c101c116c45c98c111c100c121;
function_308:
  args = cons(val, args);
  if (is_unary(args)) {
    if (is_pair(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c50 /* ___l_62 */);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_309:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_308);
  goto apply_addr;
function_310:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
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
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
    target = (&&function_309);
    goto apply_addr;
  }
function_311:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_310);
  goto apply_addr;
function_312:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_311);
  goto apply_addr;
/* ____get-body */
body_124:
  increment_count(env);
  val = wrap_function((&&function_312), env);
  global_c95c95c95c95c103c101c116c45c98c111c100c121 = val; /* ____get-body */
  goto body_125;
pointer global_c95c95c95c108c95c54c51;
/* ___l_63 */
body_125:
  val = nil();
  global_c95c95c95c108c95c54c51 = val; /* ___l_63 */
  goto body_126;
pointer global_c95c97c112c112c108c121;
function_313:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* _apply */
body_126:
  increment_count(env);
  val = wrap_function((&&function_313), env);
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_127;
pointer global_c102c110c95c49c54;
function_314:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_315:
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
  target = (&&function_314);
  goto apply_addr;
function_316:
  increment_count(env);
  val = wrap_function((&&function_315), env);
  goto pop_function;
/* fn_16 */
body_127:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_128;
pointer global_c95c109c97c112;
function_317:
  goto top_level_apply;
function_318:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_317);
  goto apply_addr;
function_319:
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
  increment_count(val = global_c102c110c95c49c54 /* fn_16 */);
  target = (&&function_318);
  goto apply_addr;
/* _map */
body_128:
  increment_count(env);
  val = wrap_function((&&function_319), env);
  global_c95c109c97c112 = val; /* _map */
  goto body_129;
pointer global_c102c110c95c49c57; /* fn_19 */
pointer global_c102c110c95c50c48;
function_320:
  goto top_level_apply;
function_321:
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
  increment_count(val = global_c102c110c95c49c57 /* fn_19 */);
  target = (&&function_320);
  goto apply_addr;
function_322:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c110c97c109c101 /* ____get-name */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  increment_count(env);
  val = wrap_function((&&function_322), env);
  goto pop_function;
/* fn_20 */
body_129:
global_c102c110c95c49c57 = nil(); /* fn_19 */
  increment_count(env);
  val = wrap_function((&&function_323), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_130;
pointer global_c102c110c95c49c56; /* fn_18 */
function_324:
  goto top_level_apply;
function_325:
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
  increment_count(val = global_c102c110c95c49c56 /* fn_18 */);
  target = (&&function_324);
  goto apply_addr;
function_326:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c98c111c100c121 /* ____get-body */);
  target = (&&function_325);
  goto apply_addr;
function_327:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  goto pop_function;
/* fn_19 */
body_130:
global_c102c110c95c49c56 = nil(); /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_327), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_131;
pointer global_c102c110c95c49c55; /* fn_17 */
function_328:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c51 /* ___l_63 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  goto top_level_apply;
function_329:
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
  increment_count(val = global_c102c110c95c49c55 /* fn_17 */);
  target = (&&function_328);
  goto apply_addr;
function_330:
  increment_count(env);
  val = wrap_function((&&function_329), env);
  goto pop_function;
/* fn_18 */
body_131:
global_c102c110c95c49c55 = nil(); /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_330), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_132;
function_331:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_332:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* ____print-warnings */);
  target = (&&function_331);
  goto apply_addr;
function_333:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121 /* _apply */);
  target = (&&function_332);
  goto apply_addr;
function_334:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* ____print-with-newline */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_333);
  goto apply_addr;
function_335:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-34);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* ____print-with-newline */);
  target = (&&function_334);
  goto apply_addr;
function_336:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_335);
  goto apply_addr;
function_337:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_336);
  goto apply_addr;
function_338:
  increment_count(env);
  val = wrap_function((&&function_337), env);
  goto pop_function;
/* fn_17 */
body_132:
  increment_count(env);
  val = wrap_function((&&function_338), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_133;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110;
function_339:
  goto top_level_apply;
function_340:
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
  increment_count(val = global_c102c110c95c50c48 /* fn_20 */);
  target = (&&function_339);
  goto apply_addr;
/* ____compile-definition */
body_133:
  increment_count(env);
  val = wrap_function((&&function_340), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 = val; /* ____compile-definition */
  goto body_134;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115; /* ____compile-definitions */
pointer global_c102c110c95c50c49;
function_341:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 /* ____compile-definitions */);
  goto top_level_apply;
function_342:
  increment_count(env);
  val = wrap_function((&&function_341), env);
  goto pop_function;
/* fn_21 */
body_134:
global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = nil(); /* ____compile-definitions */
  increment_count(env);
  val = wrap_function((&&function_342), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_135;
function_343:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110 /* ____compile-definition */);
  goto top_level_apply;
function_344:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c50c49 /* fn_21 */);
    target = (&&function_343);
    goto apply_addr;
  }
function_345:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_344);
  goto apply_addr;
/* ____compile-definitions */
body_135:
  increment_count(env);
  val = wrap_function((&&function_345), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 = val; /* ____compile-definitions */
  goto body_136;
pointer global_c95c95c95c108c95c54c52;
/* ___l_64 */
body_136:
  val = nil();
  global_c95c95c95c108c95c54c52 = val; /* ___l_64 */
  goto body_137;
pointer global_c102c110c95c50c51; /* fn_23 */
pointer global_c102c110c95c50c52;
function_346:
  goto top_level_apply;
function_347:
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
  increment_count(val = global_c102c110c95c50c51 /* fn_23 */);
  target = (&&function_346);
  goto apply_addr;
function_348:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c52 /* ___l_64 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c101c120c112c114 /* ____compile-expr */);
  target = (&&function_347);
  goto apply_addr;
function_349:
  increment_count(env);
  val = wrap_function((&&function_348), env);
  goto pop_function;
/* fn_24 */
body_137:
global_c102c110c95c50c51 = nil(); /* fn_23 */
  increment_count(env);
  val = wrap_function((&&function_349), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_138;
pointer global_c102c110c95c50c50; /* fn_22 */
function_350:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c100c101c102c105c110c105c116c105c111c110c115 /* ____compile-definitions */);
  goto top_level_apply;
function_351:
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
  increment_count(val = global_c102c110c95c50c50 /* fn_22 */);
  target = (&&function_350);
  goto apply_addr;
function_352:
  increment_count(env);
  val = wrap_function((&&function_351), env);
  goto pop_function;
/* fn_23 */
body_138:
global_c102c110c95c50c50 = nil(); /* fn_22 */
  increment_count(env);
  val = wrap_function((&&function_352), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_139;
function_353:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_354:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 /* ____print-warnings */);
  target = (&&function_353);
  goto apply_addr;
function_355:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121 /* _apply */);
  target = (&&function_354);
  goto apply_addr;
function_356:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* ____print-with-newline */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_355);
  goto apply_addr;
function_357:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c119c105c116c104c45c110c101c119c108c105c110c101 /* ____print-with-newline */);
  target = (&&function_356);
  goto apply_addr;
function_358:
  increment_count(env);
  val = wrap_function((&&function_357), env);
  goto pop_function;
/* fn_22 */
body_139:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_140;
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
function_359:
  goto top_level_apply;
function_360:
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
  increment_count(val = global_c102c110c95c50c52 /* fn_24 */);
  target = (&&function_359);
  goto apply_addr;
function_361:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c116c45c110c97c109c101 /* ____get-name */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_360);
  goto apply_addr;
/* ____compile */
body_140:
  increment_count(env);
  val = wrap_function((&&function_361), env);
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  goto body_141;
pointer global_c95c95c95c108c95c54c53;
/* ___l_65 */
body_141:
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
  global_c95c95c95c108c95c54c53 = val; /* ___l_65 */
  goto body_142;
pointer global_c95c95c95c108c95c54c54;
/* ___l_66 */
body_142:
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
  global_c95c95c95c108c95c54c54 = val; /* ___l_66 */
  goto body_143;
pointer global_c95c95c95c108c95c54c55;
/* ___l_67 */
body_143:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c55 = val; /* ___l_67 */
  goto body_144;
pointer global_c95c114c101c118c101c114c115c101;
function_362:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c105c100 /* _id */);
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101 /* _rreverse */);
  goto top_level_apply;
/* _reverse */
body_144:
  increment_count(env);
  val = wrap_function((&&function_362), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_145;
pointer global_c95c111c114;
function_363:
  goto top_level_apply;
function_364:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_365:
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
  val = wrap_function((&&function_364), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_363);
  goto apply_addr;
/* _or */
body_145:
  increment_count(env);
  val = wrap_function((&&function_365), env);
  global_c95c111c114 = val; /* _or */
  goto body_146;
pointer global_c95c97c110c100;
function_366:
  goto top_level_apply;
function_367:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_368:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-38);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_367), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_366);
  goto apply_addr;
/* _and */
body_146:
  increment_count(env);
  val = wrap_function((&&function_368), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_147;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_369:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_370:
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
    target = (&&function_369);
    goto apply_addr;
  }
function_371:
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
    target = (&&function_370);
    goto apply_addr;
  }
function_372:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_371);
  goto apply_addr;
/* _escape-char */
body_147:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_148;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* _parse-escaped-string */
pointer global_c102c110c95c50c53;
function_373:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103 /* _parse-string */);
  goto top_level_apply;
function_374:
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
    increment_count(val = global_c95c101c115c99c97c112c101c45c99c104c97c114 /* _escape-char */);
    target = (&&function_373);
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
    increment_count(val = global_c95c101c115c99c97c112c101c45c99c104c97c114 /* _escape-char */);
    target = (&&function_373);
    goto apply_addr;
  }
function_375:
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
    target = (&&function_374);
    goto apply_addr;
  }
function_376:
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
    increment_count(val = global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 /* _parse-escaped-string */);
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
    target = (&&function_375);
    goto apply_addr;
  }
function_377:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_376);
  goto apply_addr;
function_378:
  increment_count(env);
  val = wrap_function((&&function_377), env);
  goto pop_function;
/* fn_25 */
body_148:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* _parse-string */
global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* _parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_378), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_149;
function_379:
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
  increment_count(val = global_c102c110c95c50c53 /* fn_25 */);
  goto top_level_apply;
/* _parse-escaped-string */
body_149:
  increment_count(env);
  val = wrap_function((&&function_379), env);
  global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* _parse-escaped-string */
  goto body_150;
pointer global_c102c110c95c50c54;
function_380:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_381:
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_380);
  goto apply_addr;
function_382:
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103 /* _parse-string */);
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103 /* _parse-string */);
    goto top_level_apply;
  }
function_383:
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
    increment_count(val = global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 /* _parse-escaped-string */);
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
    target = (&&function_382);
    goto apply_addr;
  }
function_384:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_381);
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
    target = (&&function_383);
    goto apply_addr;
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
    val = new_number(34);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_384);
    goto apply_addr;
  }
function_386:
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103 /* _parse-string */);
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
    target = (&&function_385);
    goto apply_addr;
  }
function_387:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_386);
  goto apply_addr;
function_388:
  increment_count(env);
  val = wrap_function((&&function_387), env);
  goto pop_function;
/* fn_26 */
body_150:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_151;
function_389:
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
  increment_count(val = global_c102c110c95c50c54 /* fn_26 */);
  goto top_level_apply;
/* _parse-string */
body_151:
  increment_count(env);
  val = wrap_function((&&function_389), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_152;
pointer global_c95c115c107c105c112c45c108c105c110c101; /* _skip-line */
pointer global_c102c110c95c50c55;
function_390:
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
    increment_count(val = global_c95c115c107c105c112c45c108c105c110c101 /* _skip-line */);
    goto top_level_apply;
  }
function_391:
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
    target = (&&function_390);
    goto apply_addr;
  }
function_392:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_391);
  goto apply_addr;
function_393:
  increment_count(env);
  val = wrap_function((&&function_392), env);
  goto pop_function;
/* fn_27 */
body_152:
global_c95c115c107c105c112c45c108c105c110c101 = nil(); /* _skip-line */
  increment_count(env);
  val = wrap_function((&&function_393), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_153;
function_394:
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
  increment_count(val = global_c102c110c95c50c55 /* fn_27 */);
  goto top_level_apply;
/* _skip-line */
body_153:
  increment_count(env);
  val = wrap_function((&&function_394), env);
  global_c95c115c107c105c112c45c108c105c110c101 = val; /* _skip-line */
  goto body_154;
pointer global_c95c112c97c114c115c101c45c110c117c109c98c101c114; /* _parse-number */
pointer global_c102c110c95c50c56;
function_395:
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
function_396:
  goto top_level_apply;
function_397:
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
    increment_count(val = global_c95c112c97c114c115c101c45c110c117c109c98c101c114 /* _parse-number */);
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
    target = (&&function_396);
    goto apply_addr;
  }
function_398:
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
    increment_count(val = global_c95c112c97c114c115c101c45c110c117c109c98c101c114 /* _parse-number */);
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
      target = (&&function_395);
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
      increment_count(val = global_c95c97c110c100 /* _and */);
      target = (&&function_397);
      goto apply_addr;
    }
  }
function_399:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_398);
  goto apply_addr;
function_400:
  increment_count(env);
  val = wrap_function((&&function_399), env);
  goto pop_function;
/* fn_28 */
body_154:
global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* _parse-number */
  increment_count(env);
  val = wrap_function((&&function_400), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_155;
function_401:
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
  increment_count(val = global_c102c110c95c50c56 /* fn_28 */);
  goto top_level_apply;
/* _parse-number */
body_155:
  increment_count(env);
  val = wrap_function((&&function_401), env);
  global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* _parse-number */
  goto body_156;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c50c57;
function_402:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_403:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_402);
  goto apply_addr;
function_404:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_403);
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_403);
    goto apply_addr;
  }
function_405:
  goto top_level_apply;
function_406:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_405);
  goto apply_addr;
function_407:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_406);
  goto apply_addr;
function_408:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_407);
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
    goto top_level_apply;
  }
function_409:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_408);
  goto apply_addr;
function_410:
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
  increment_count(val = global_c95c97c110c100 /* _and */);
  target = (&&function_409);
  goto apply_addr;
function_411:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_410);
  goto apply_addr;
function_412:
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
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
      target = (&&function_404);
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
      target = (&&function_411);
      goto apply_addr;
    }
  }
function_413:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_412);
  goto apply_addr;
function_414:
  increment_count(env);
  val = wrap_function((&&function_413), env);
  goto pop_function;
/* fn_29 */
body_156:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_414), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_157;
function_415:
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
  increment_count(val = global_c102c110c95c50c57 /* fn_29 */);
  goto top_level_apply;
/* _parse-symbol */
body_157:
  increment_count(env);
  val = wrap_function((&&function_415), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_158;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c51c48;
function_416:
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
    args = cons(val, args);
    increment_count(val = global_c95c115c107c105c112c45c108c105c110c101 /* _skip-line */);
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
function_417:
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
    target = (&&function_416);
    goto apply_addr;
  }
function_418:
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
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
    target = (&&function_417);
    goto apply_addr;
  }
function_419:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_418);
  goto apply_addr;
function_420:
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
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
    increment_count(val = global_c95c110c111c116 /* _not */);
    target = (&&function_419);
    goto apply_addr;
  }
function_421:
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
    target = (&&function_420);
    goto apply_addr;
  }
function_422:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_421);
  goto apply_addr;
function_423:
  increment_count(env);
  val = wrap_function((&&function_422), env);
  goto pop_function;
/* fn_30 */
body_158:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_423), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_159;
function_424:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c48 /* fn_30 */);
  goto top_level_apply;
/* _parse-paren */
body_159:
  increment_count(env);
  val = wrap_function((&&function_424), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_160;
pointer global_c102c110c95c51c49; /* fn_31 */
pointer global_c95c112c97c114c115c101c45c116c97c105c108; /* _parse-tail */
pointer global_c102c110c95c51c50;
function_425:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
  goto top_level_apply;
function_426:
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
  increment_count(val = global_c102c110c95c51c49 /* fn_31 */);
  target = (&&function_425);
  goto apply_addr;
function_427:
  increment_count(env);
  val = wrap_function((&&function_426), env);
  goto pop_function;
/* fn_32 */
body_160:
global_c102c110c95c51c49 = nil(); /* fn_31 */
global_c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* _parse-tail */
  increment_count(env);
  val = wrap_function((&&function_427), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_161;
function_428:
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
function_429:
  increment_count(env);
  val = wrap_function((&&function_428), env);
  goto pop_function;
/* fn_31 */
body_161:
  increment_count(env);
  val = wrap_function((&&function_429), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_162;
pointer global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_430:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c50 /* fn_32 */);
  goto top_level_apply;
/* _parse-tail-cont */
body_162:
  increment_count(env);
  val = wrap_function((&&function_430), env);
  global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* _parse-tail-cont */
  goto body_163;
pointer global_c102c110c95c51c52; /* fn_34 */
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c102c110c95c51c53;
function_431:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_432:
  goto top_level_apply;
function_433:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_432);
  goto apply_addr;
function_434:
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
    increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
    args = cons(val, args);
    increment_count(val = global_c95c115c107c105c112c45c108c105c110c101 /* _skip-line */);
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
    increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 /* _parse-tail-cont */);
    target = (&&function_433);
    goto apply_addr;
  }
function_435:
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
    increment_count(val = global_c102c110c95c51c52 /* fn_34 */);
    target = (&&function_431);
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
    target = (&&function_434);
    goto apply_addr;
  }
function_436:
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
    target = (&&function_435);
    goto apply_addr;
  }
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
    increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
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
    target = (&&function_436);
    goto apply_addr;
  }
function_438:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_437);
  goto apply_addr;
function_439:
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
    increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
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
    increment_count(val = global_c95c110c111c116 /* _not */);
    target = (&&function_438);
    goto apply_addr;
  }
function_440:
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
    target = (&&function_439);
    goto apply_addr;
  }
function_441:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_440);
  goto apply_addr;
function_442:
  increment_count(env);
  val = wrap_function((&&function_441), env);
  goto pop_function;
/* fn_35 */
body_163:
global_c102c110c95c51c52 = nil(); /* fn_34 */
global_c95c112c97c114c115c101c45c101c120c112c114 = nil(); /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_442), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_164;
pointer global_c102c110c95c51c51; /* fn_33 */
function_443:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
  goto top_level_apply;
function_444:
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
  increment_count(val = global_c102c110c95c51c51 /* fn_33 */);
  target = (&&function_443);
  goto apply_addr;
function_445:
  increment_count(env);
  val = wrap_function((&&function_444), env);
  goto pop_function;
/* fn_34 */
body_164:
global_c102c110c95c51c51 = nil(); /* fn_33 */
  increment_count(env);
  val = wrap_function((&&function_445), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_165;
function_446:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_447:
  increment_count(env);
  val = wrap_function((&&function_446), env);
  goto pop_function;
/* fn_33 */
body_165:
  increment_count(env);
  val = wrap_function((&&function_447), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_166;
function_448:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c53 /* fn_35 */);
  goto top_level_apply;
/* _parse-tail */
body_166:
  increment_count(env);
  val = wrap_function((&&function_448), env);
  global_c95c112c97c114c115c101c45c116c97c105c108 = val; /* _parse-tail */
  goto body_167;
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c51c54;
function_449:
  goto top_level_apply;
function_450:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_449);
  goto apply_addr;
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114 /* _parse-pair */);
    args = cons(val, args);
    increment_count(val = global_c95c115c107c105c112c45c108c105c110c101 /* _skip-line */);
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
    increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 /* _parse-tail-cont */);
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
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114 /* _parse-pair */);
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
    target = (&&function_452);
    goto apply_addr;
  }
function_454:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_453);
  goto apply_addr;
function_455:
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114 /* _parse-pair */);
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
    increment_count(val = global_c95c110c111c116 /* _not */);
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
    target = (&&function_455);
    goto apply_addr;
  }
function_457:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_456);
  goto apply_addr;
function_458:
  increment_count(env);
  val = wrap_function((&&function_457), env);
  goto pop_function;
/* fn_36 */
body_167:
global_c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_458), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_168;
function_459:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c54 /* fn_36 */);
  goto top_level_apply;
/* _parse-pair */
body_168:
  increment_count(env);
  val = wrap_function((&&function_459), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_169;
pointer global_c102c110c95c51c57; /* fn_39 */
pointer global_c102c110c95c51c56; /* fn_38 */
pointer global_c102c110c95c51c55; /* fn_37 */
pointer global_c102c110c95c52c48;
function_460:
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
    increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
    goto top_level_apply;
  } else {
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
    goto top_level_apply;
  }
function_461:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_462:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_463:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_464:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
  goto top_level_apply;
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
    increment_count(val = global_c95c112c97c114c115c101c45c110c117c109c98c101c114 /* _parse-number */);
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
    increment_count(val = global_c95c108c105c115c116 /* _list */);
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
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
    args = cons(val, args);
    increment_count(val = global_c95c115c107c105c112c45c108c105c110c101 /* _skip-line */);
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
    increment_count(val = global_c95c97c110c100 /* _and */);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c51c57 /* fn_39 */);
    target = (&&function_463);
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
    target = (&&function_466);
    goto apply_addr;
  }
function_468:
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
    target = (&&function_467);
    goto apply_addr;
  }
function_469:
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
    increment_count(val = global_c102c110c95c51c56 /* fn_38 */);
    target = (&&function_462);
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
    target = (&&function_468);
    goto apply_addr;
  }
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
    target = (&&function_469);
    goto apply_addr;
  }
function_471:
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
    increment_count(val = global_c95c112c97c114c115c101c45c112c97c105c114 /* _parse-pair */);
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
    target = (&&function_470);
    goto apply_addr;
  }
function_472:
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
    increment_count(val = global_c102c110c95c51c55 /* fn_37 */);
    target = (&&function_461);
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
    target = (&&function_471);
    goto apply_addr;
  }
function_473:
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
    increment_count(val = global_c95c112c97c114c115c101c45c115c116c114c105c110c103 /* _parse-string */);
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
    target = (&&function_472);
    goto apply_addr;
  }
function_474:
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
    target = (&&function_460);
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
    target = (&&function_473);
    goto apply_addr;
  }
function_475:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_474);
  goto apply_addr;
function_476:
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
    increment_count(val = global_c95c110c111c116 /* _not */);
    target = (&&function_475);
    goto apply_addr;
  }
function_477:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_476);
  goto apply_addr;
function_478:
  increment_count(env);
  val = wrap_function((&&function_477), env);
  goto pop_function;
/* fn_40 */
body_169:
global_c102c110c95c51c57 = nil(); /* fn_39 */
global_c102c110c95c51c56 = nil(); /* fn_38 */
global_c102c110c95c51c55 = nil(); /* fn_37 */
  increment_count(env);
  val = wrap_function((&&function_478), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_170;
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
  val = new_symbol(-37);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_479);
  goto apply_addr;
function_481:
  increment_count(env);
  val = wrap_function((&&function_480), env);
  goto pop_function;
/* fn_37 */
body_170:
  increment_count(env);
  val = wrap_function((&&function_481), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_171;
function_482:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_483:
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
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_482);
  goto apply_addr;
function_484:
  increment_count(env);
  val = wrap_function((&&function_483), env);
  goto pop_function;
/* fn_38 */
body_171:
  increment_count(env);
  val = wrap_function((&&function_484), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_172;
function_485:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_486:
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
  val = new_symbol(-35);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_485);
  goto apply_addr;
function_487:
  increment_count(env);
  val = wrap_function((&&function_486), env);
  goto pop_function;
/* fn_39 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_173;
function_488:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c48 /* fn_40 */);
  goto top_level_apply;
/* _parse-expr */
body_173:
  increment_count(env);
  val = wrap_function((&&function_488), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_174;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_489:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
  goto top_level_apply;
function_490:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c53 /* ___l_65 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_489);
  goto apply_addr;
function_491:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c54c55 /* ___l_67 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c54 /* ___l_66 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_490);
  goto apply_addr;
function_492:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_491), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
/* ____read-expr */
body_174:
  increment_count(env);
  val = wrap_function((&&function_492), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_175;
pointer global_c95c95c95c108c95c54c56;
/* ___l_68 */
body_175:
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
  global_c95c95c95c108c95c54c56 = val; /* ___l_68 */
  goto body_176;
pointer global_c95c95c95c108c95c54c57;
/* ___l_69 */
body_176:
  val = new_symbol(-34);
  global_c95c95c95c108c95c54c57 = val; /* ___l_69 */
  goto body_177;
pointer global_c95c95c95c108c95c55c48;
/* ___l_70 */
body_177:
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
  global_c95c95c95c108c95c55c48 = val; /* ___l_70 */
  goto body_178;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
pointer global_c102c110c95c52c49;
function_493:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101 /* ____compile */);
  goto top_level_apply;
function_494:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_495:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c55c48 /* ___l_70 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
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
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
    target = (&&function_494);
    goto apply_addr;
  }
function_496:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_495);
  goto apply_addr;
function_497:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_496);
  goto apply_addr;
function_498:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_497);
  goto apply_addr;
function_499:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_498);
  goto apply_addr;
function_500:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_499);
  goto apply_addr;
function_501:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_493);
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
    increment_count(val = global_c95c99c97c97c100c114 /* _caadr */);
    target = (&&function_500);
    goto apply_addr;
  }
function_502:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_501);
  goto apply_addr;
function_503:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c56 /* ___l_68 */);
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c54c57 /* ___l_69 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_502);
    goto apply_addr;
  }
function_504:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_503);
  goto apply_addr;
function_505:
  increment_count(env);
  val = wrap_function((&&function_504), env);
  goto pop_function;
/* fn_41 */
body_178:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = nil(); /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_505), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_179;
function_506:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c49 /* fn_41 */);
  goto top_level_apply;
/* ____compile-source */
body_179:
  increment_count(env);
  val = wrap_function((&&function_506), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_180;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_180:
  val = nil();
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_181;
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
function_507:
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
function_508:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_509:
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
  increment_count(val = global_c95c95c95c108c95c49 /* ___l_1 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
  target = (&&function_508);
  goto apply_addr;
body_181:
  increment_count(env);
  val = wrap_function((&&function_509), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_507), nil()), call_stack);
  goto body_0;
}
