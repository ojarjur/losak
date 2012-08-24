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
                                                              val = new_number(103);
                                                              args = cons(val, args);
                                                              val = new_number(114);
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
                                                                        val = new_number(108);
                                                                        args = cons(val, args);
                                                                        val = new_number(105);
                                                                        args = cons(val, args);
                                                                        val = new_number(97);
                                                                        args = cons(val, args);
                                                                        val = new_number(116);
                                                                        args = cons(val, args);
                                                                        val = new_number(45);
                                                                        args = cons(val, args);
                                                                        val = new_number(116);
                                                                        args = cons(val, args);
                                                                        val = new_number(117);
                                                                        args = cons(val, args);
                                                                        val = new_number(112);
                                                                        args = cons(val, args);
                                                                        val = new_number(116);
                                                                        args = cons(val, args);
                                                                        val = new_number(117);
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
                                                                              val = new_number(116);
                                                                              args = cons(val, args);
                                                                              val = new_number(117);
                                                                              args = cons(val, args);
                                                                              val = new_number(112);
                                                                              args = cons(val, args);
                                                                              val = new_number(116);
                                                                              args = cons(val, args);
                                                                              val = new_number(117);
                                                                              args = cons(val, args);
                                                                              val = new_number(111);
                                                                              args = cons(val, args);
                                                                              val = new_number(45);
                                                                              args = cons(val, args);
                                                                              val = new_number(112);
                                                                              args = cons(val, args);
                                                                              val = new_number(97);
                                                                              args = cons(val, args);
                                                                              val = new_number(114);
                                                                              args = cons(val, args);
                                                                              val = new_number(119);
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
                                                                                    val = new_number(120);
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
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-74);
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
    val = new_symbol(-74);
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
    val = new_number(120);
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
    val = new_number(116);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(114);
    args = cons(val, args);
    val = new_number(119);
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
    val = new_number(108);
    args = cons(val, args);
    val = new_number(105);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(45);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(117);
    args = cons(val, args);
    val = new_number(112);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(117);
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
    val = new_number(115);
    args = cons(val, args);
    val = new_number(103);
    args = cons(val, args);
    val = new_number(114);
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
    val = new_number(116);
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
    val = new_number(94);
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
    val = new_number(124);
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
    val = new_number(38);
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
    val = new_number(126);
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
    val = new_number(37);
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
    val = new_number(47);
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
    val = new_number(42);
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
    val = new_number(45);
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
    val = new_number(43);
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
    val = new_number(62);
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
    val = new_number(60);
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
    val = new_number(61);
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
    target = (&&function_42);
    goto apply_addr;
  }
function_44:
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
  target = (&&function_43);
  goto apply_addr;
/* _string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_44), env);
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_45:
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
          val = new_symbol(-52);
          goto pop_function;
        } else {
          push_args();
          val = nil();
          args = val;
          val = new_symbol(-74);
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
            val = new_symbol(-52);
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
  val = wrap_function((&&function_45), env);
  global_c95c95c115c121c109c98c111c108c63 = val; /* __symbol? */
  goto body_4;
pointer global_c95c95c112c97c105c114c63;
function_46:
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
    val = new_symbol(-74);
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
      val = new_symbol(-52);
      goto pop_function;
    }
  }
/* __pair? */
body_4:
  increment_count(env);
  val = wrap_function((&&function_46), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c97c116c111c109;
function_47:
  if (is_atom(car(car(env)))) {
    increment_count(val = true);
  } else {
    val = nil();
  }
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_symbol(-52);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-74);
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
      val = new_symbol(-52);
      goto pop_function;
    } else {
      val = nil();
      goto pop_function;
    }
  }
/* __atom */
body_5:
  increment_count(env);
  val = wrap_function((&&function_47), env);
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_6;
pointer global_c95c95c61;
function_48:
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
function_49:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_48);
  goto apply_addr;
/* __= */
body_6:
  increment_count(env);
  val = wrap_function((&&function_49), env);
  global_c95c95c61 = val; /* __= */
  goto body_7;
pointer global_c95c108c105c115c116;
function_50:
  increment_count(val = car(env));
  goto pop_function;
/* _list */
body_7:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  global_c95c108c105c115c116 = val; /* _list */
  goto body_8;
pointer global_c95c114c114c101c118c101c114c115c101;
function_51:
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
function_52:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_51);
  goto apply_addr;
/* _rreverse */
body_8:
  increment_count(env);
  val = wrap_function((&&function_52), env);
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_9;
pointer global_c95c102c111c108c100c108; /* _foldl */
pointer global_c102c110c95c48;
function_53:
  goto top_level_apply;
function_54:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108 /* _foldl */);
  target = (&&function_53);
  goto apply_addr;
function_55:
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
    target = (&&function_54);
    goto apply_addr;
  }
function_56:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_55);
  goto apply_addr;
function_57:
  increment_count(env);
  val = wrap_function((&&function_56), env);
  goto pop_function;
/* fn_0 */
body_9:
global_c95c102c111c108c100c108 = nil(); /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_57), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_10;
function_58:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c48 /* fn_0 */);
  goto top_level_apply;
/* _foldl */
body_10:
  increment_count(env);
  val = wrap_function((&&function_58), env);
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_11;
pointer global_c102c110c95c49;
function_59:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101 /* _rreverse */);
  goto top_level_apply;
function_60:
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
  target = (&&function_59);
  goto apply_addr;
function_61:
  increment_count(env);
  val = wrap_function((&&function_60), env);
  goto pop_function;
/* fn_1 */
body_11:
  increment_count(env);
  val = wrap_function((&&function_61), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_12;
pointer global_c95c102c111c108c100c114;
function_62:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49 /* fn_1 */);
  goto top_level_apply;
/* _foldr */
body_12:
  increment_count(env);
  val = wrap_function((&&function_62), env);
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_13;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_63:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_14;
function_64:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_65:
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
  target = (&&function_64);
  goto apply_addr;
/* ____map-to-stderr */
body_13:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_65), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_63);
  goto apply_addr;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_14:
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
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_15;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_15:
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
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_16;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_16:
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
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  goto body_17;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_17:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_18;
pointer global_c95c105c100;
function_66:
  increment_count(val = car(car(env)));
  goto pop_function;
/* _id */
body_18:
  increment_count(env);
  val = wrap_function((&&function_66), env);
  global_c95c105c100 = val; /* _id */
  goto body_19;
pointer global_c95c119c97c108c107; /* _walk */
pointer global_c102c110c95c50;
function_67:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_68:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_67);
  goto apply_addr;
function_69:
  target = (&&function_68);
  goto apply_addr;
function_70:
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
  target = (&&function_69);
  goto apply_addr;
function_71:
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
    target = (&&function_70);
    goto apply_addr;
  }
function_72:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_71);
  goto apply_addr;
function_73:
  increment_count(env);
  val = wrap_function((&&function_72), env);
  goto pop_function;
/* fn_2 */
body_19:
global_c95c119c97c108c107 = nil(); /* _walk */
  increment_count(env);
  val = wrap_function((&&function_73), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_20;
function_74:
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
  increment_count(val = global_c102c110c95c50 /* fn_2 */);
  goto top_level_apply;
/* _walk */
body_20:
  increment_count(env);
  val = wrap_function((&&function_74), env);
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_21;
pointer global_c95c97c112c112c101c110c100;
function_75:
  goto top_level_apply;
function_76:
  goto top_level_apply;
function_77:
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
function_78:
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
    val = wrap_function((&&function_77), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
    target = (&&function_76);
    goto apply_addr;
  }
function_79:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_78);
  goto apply_addr;
function_80:
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
  val = wrap_function((&&function_79), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_75);
  goto apply_addr;
/* _append */
body_21:
  increment_count(env);
  val = wrap_function((&&function_80), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_22;
pointer global_c102c110c95c51;
function_81:
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
function_82:
  increment_count(env);
  val = wrap_function((&&function_81), env);
  goto pop_function;
/* fn_3 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_82), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_23;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_83:
  goto top_level_apply;
function_84:
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
function_85:
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
function_86:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
function_87:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51 /* fn_3 */);
  goto top_level_apply;
function_88:
  increment_count(val = global_c95c105c100 /* _id */);
  goto pop_function;
function_89:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(env);
  val = wrap_function((&&function_88), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_87), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_86), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_85), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_84), env);
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107 /* _walk */);
  target = (&&function_83);
  goto apply_addr;
/* _build-num-str */
body_23:
  increment_count(env);
  val = wrap_function((&&function_89), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_24;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_90:
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
function_91:
  target = (&&function_90);
  goto apply_addr;
function_92:
  goto top_level_apply;
function_93:
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
      target = (&&function_91);
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
      target = (&&function_92);
      goto apply_addr;
    }
  }
function_94:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_93);
  goto apply_addr;
/* _print-num */
body_24:
  increment_count(env);
  val = wrap_function((&&function_94), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_25;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_95:
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
function_96:
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
      target = (&&function_95);
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
body_25:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_26;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_97:
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
function_98:
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
function_99:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_98);
  goto apply_addr;
function_100:
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
    target = (&&function_97);
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
    target = (&&function_99);
    goto apply_addr;
  }
function_101:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_100);
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
body_26:
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = nil(); /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_101), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_27;
function_102:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_103:
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
function_104:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_103);
  goto apply_addr;
function_105:
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
    target = (&&function_102);
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
    target = (&&function_104);
    goto apply_addr;
  }
function_106:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_105);
  goto apply_addr;
/* _print-with-suffix */
body_27:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_28;
pointer global_c95c112c114c105c110c116;
function_107:
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
body_28:
  increment_count(env);
  val = wrap_function((&&function_107), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_29;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_108:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_109:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50 /* ___l_2 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49 /* ___l_1 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_108);
  goto apply_addr;
function_110:
  increment_count(val = car(cdr(car(env))));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52 /* ___l_4 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c51 /* ___l_3 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116 /* _print */);
    target = (&&function_109);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
/* ____print-warnings */
body_29:
  increment_count(env);
  val = wrap_function((&&function_110), env);
  global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115 = val; /* ____print-warnings */
  goto body_30;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_30:
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
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_31;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_31:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_32;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_111:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_112:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c54 /* ___l_6 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53 /* ___l_5 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_111);
  goto apply_addr;
/* ____print-error */
body_32:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_33;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_33:
  val = nil();
  push_args();
  args = val;
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_34;
pointer global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108;
function_113:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
function_114:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55 /* ___l_7 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_113);
  goto apply_addr;
function_115:
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
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_114);
  goto apply_addr;
/* ____number->symbol */
body_34:
  increment_count(env);
  val = wrap_function((&&function_115), env);
  global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ____number->symbol */
  goto body_35;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_35:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-35);
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  val = new_symbol(-51);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_36;
pointer global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115;
/* ____special-forms */
body_36:
  increment_count(val = global_c95c95c95c108c95c56 /* ___l_8 */);
  global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 = val; /* ____special-forms */
  goto body_37;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_37:
  val = nil();
  push_args();
  args = val;
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
  val = new_symbol(-46);
  args = cons(val, args);
  val = new_symbol(-73);
  args = cons(val, args);
  val = new_symbol(-48);
  args = cons(val, args);
  val = new_symbol(-44);
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_38;
pointer global_c95c95c95c95c98c117c105c108c116c105c110c115;
/* ____builtins */
body_38:
  increment_count(val = global_c95c95c95c108c95c57 /* ___l_9 */);
  global_c95c95c95c95c98c117c105c108c116c105c110c115 = val; /* ____builtins */
  goto body_39;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_39:
  val = nil();
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_40;
pointer global_c95c95c101c113c117c97c108;
function_116:
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
function_117:
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
    target = (&&function_116);
    goto apply_addr;
  }
function_118:
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
    target = (&&function_117);
    goto apply_addr;
  }
function_119:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_118);
  goto apply_addr;
/* __equal */
body_40:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_41;
pointer global_c95c109c101c109c98c101c114;
function_120:
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
function_121:
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
    target = (&&function_120);
    goto apply_addr;
  }
function_122:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_121);
  goto apply_addr;
/* _member */
body_41:
  increment_count(env);
  val = wrap_function((&&function_122), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_42;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_123:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
function_124:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48 /* ___l_10 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_123);
  goto apply_addr;
function_125:
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
    target = (&&function_124);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_126:
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
    target = (&&function_125);
    goto apply_addr;
  }
function_127:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115 /* ____builtins */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_126);
    goto apply_addr;
  }
function_128:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_129:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_128);
  goto apply_addr;
function_130:
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
    target = (&&function_127);
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
    target = (&&function_129);
    goto apply_addr;
  }
function_131:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_130);
  goto apply_addr;
/* ____escape-symbols */
body_42:
  increment_count(env);
  val = wrap_function((&&function_131), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_43;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_43:
  val = nil();
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_44;
pointer global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101;
/* ____initial-symbol-name */
body_44:
  increment_count(val = global_c95c95c95c108c95c49c49 /* ___l_11 */);
  global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____initial-symbol-name */
  goto body_45;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_45:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_46;
pointer global_c102c110c95c54; /* fn_6 */
pointer global_c102c110c95c55;
function_132:
  goto top_level_apply;
function_133:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54 /* fn_6 */);
  target = (&&function_132);
  goto apply_addr;
function_134:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50 /* ___l_12 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_133);
  goto apply_addr;
function_135:
  increment_count(env);
  val = wrap_function((&&function_134), env);
  goto pop_function;
/* fn_7 */
body_46:
global_c102c110c95c54 = nil(); /* fn_6 */
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_47;
pointer global_c102c110c95c53; /* fn_5 */
function_136:
  goto top_level_apply;
function_137:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53 /* fn_5 */);
  target = (&&function_136);
  goto apply_addr;
function_138:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_137);
  goto apply_addr;
function_139:
  increment_count(env);
  val = wrap_function((&&function_138), env);
  goto pop_function;
/* fn_6 */
body_47:
global_c102c110c95c53 = nil(); /* fn_5 */
  increment_count(env);
  val = wrap_function((&&function_139), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_48;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108; /* ____transform-tail-call */
pointer global_c102c110c95c52; /* fn_4 */
function_140:
  goto top_level_apply;
function_141:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52 /* fn_4 */);
  target = (&&function_140);
  goto apply_addr;
function_142:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 /* ____transform-tail-call */);
  target = (&&function_141);
  goto apply_addr;
function_143:
  increment_count(env);
  val = wrap_function((&&function_142), env);
  goto pop_function;
/* fn_5 */
body_48:
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = nil(); /* ____transform-tail-call */
global_c102c110c95c52 = nil(); /* fn_4 */
  increment_count(env);
  val = wrap_function((&&function_143), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_49;
function_144:
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
  increment_count(val = car(car(env)));
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
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_145:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  goto pop_function;
/* fn_4 */
body_49:
  increment_count(env);
  val = wrap_function((&&function_145), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_50;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108;
function_146:
  goto top_level_apply;
function_147:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55 /* fn_7 */);
  target = (&&function_146);
  goto apply_addr;
function_148:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_147);
  goto apply_addr;
/* ____transform-fn-tail-call */
body_50:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-fn-tail-call */
  goto body_51;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_51:
  val = nil();
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_52;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_52:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_53;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_53:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_54;
pointer global_c102c110c95c49c49; /* fn_11 */
pointer global_c102c110c95c49c50;
function_149:
  goto top_level_apply;
function_150:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c49 /* fn_11 */);
  target = (&&function_149);
  goto apply_addr;
function_151:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c53 /* ___l_15 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_150);
  goto apply_addr;
function_152:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  goto pop_function;
/* fn_12 */
body_54:
global_c102c110c95c49c49 = nil(); /* fn_11 */
  increment_count(env);
  val = wrap_function((&&function_152), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_55;
pointer global_c102c110c95c49c48; /* fn_10 */
function_153:
  goto top_level_apply;
function_154:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48 /* fn_10 */);
  target = (&&function_153);
  goto apply_addr;
function_155:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c52 /* ___l_14 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_154);
  goto apply_addr;
function_156:
  increment_count(env);
  val = wrap_function((&&function_155), env);
  goto pop_function;
/* fn_11 */
body_55:
global_c102c110c95c49c48 = nil(); /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_156), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_56;
pointer global_c102c110c95c57; /* fn_9 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109; /* ____transform */
function_157:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_158:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57 /* fn_9 */);
  target = (&&function_157);
  goto apply_addr;
function_159:
  increment_count(env);
  val = wrap_function((&&function_158), env);
  goto pop_function;
/* fn_10 */
body_56:
global_c102c110c95c57 = nil(); /* fn_9 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = nil(); /* ____transform */
  increment_count(env);
  val = wrap_function((&&function_159), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_57;
pointer global_c102c110c95c56; /* fn_8 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115; /* ____transform-args */
function_160:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51 /* ___l_13 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_161:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56 /* fn_8 */);
  target = (&&function_160);
  goto apply_addr;
function_162:
  increment_count(env);
  val = wrap_function((&&function_161), env);
  goto pop_function;
/* fn_9 */
body_57:
global_c102c110c95c56 = nil(); /* fn_8 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = nil(); /* ____transform-args */
  increment_count(env);
  val = wrap_function((&&function_162), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_58;
function_163:
  push_args();
  increment_count(val = car(car(env)));
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_164:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  goto pop_function;
/* fn_8 */
body_58:
  increment_count(env);
  val = wrap_function((&&function_164), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_59;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108;
function_165:
  goto top_level_apply;
function_166:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50 /* fn_12 */);
  target = (&&function_165);
  goto apply_addr;
function_167:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_166);
  goto apply_addr;
/* ____transform-application-tail-call */
body_59:
  increment_count(env);
  val = wrap_function((&&function_167), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-application-tail-call */
  goto body_60;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_60:
  val = nil();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_61;
pointer global_c102c110c95c49c51;
function_168:
  push_args();
  val = nil();
  args = val;
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
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_169:
  increment_count(env);
  val = wrap_function((&&function_168), env);
  goto pop_function;
/* fn_13 */
body_61:
  increment_count(env);
  val = wrap_function((&&function_169), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_62;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108;
function_170:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54 /* ___l_16 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_171:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51 /* fn_13 */);
  target = (&&function_170);
  goto apply_addr;
/* ____transform-primitive-tail-call */
body_62:
  increment_count(env);
  val = wrap_function((&&function_171), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-primitive-tail-call */
  goto body_63;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_63:
  val = nil();
  push_args();
  args = val;
  val = new_number(50);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_64;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_64:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_65;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_65:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_66;
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c102c110c95c49c57;
function_172:
  goto top_level_apply;
function_173:
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
  increment_count(val = global_c102c110c95c49c56 /* fn_18 */);
  target = (&&function_172);
  goto apply_addr;
function_174:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c56 /* ___l_18 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_173);
  goto apply_addr;
function_175:
  increment_count(env);
  val = wrap_function((&&function_174), env);
  goto pop_function;
/* fn_19 */
body_66:
global_c102c110c95c49c56 = nil(); /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_175), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_67;
pointer global_c102c110c95c49c55; /* fn_17 */
function_176:
  goto top_level_apply;
function_177:
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
  increment_count(val = global_c102c110c95c49c55 /* fn_17 */);
  target = (&&function_176);
  goto apply_addr;
function_178:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55 /* ___l_17 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_177);
  goto apply_addr;
function_179:
  increment_count(env);
  val = wrap_function((&&function_178), env);
  goto pop_function;
/* fn_18 */
body_67:
global_c102c110c95c49c55 = nil(); /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_179), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_68;
pointer global_c102c110c95c49c54; /* fn_16 */
function_180:
  goto top_level_apply;
function_181:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c102c110c95c49c54 /* fn_16 */);
  target = (&&function_180);
  goto apply_addr;
function_182:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 /* ____transform-tail-call */);
  target = (&&function_181);
  goto apply_addr;
function_183:
  increment_count(env);
  val = wrap_function((&&function_182), env);
  goto pop_function;
/* fn_17 */
body_68:
global_c102c110c95c49c54 = nil(); /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_183), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_69;
pointer global_c102c110c95c49c53; /* fn_15 */
function_184:
  goto top_level_apply;
function_185:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c53 /* fn_15 */);
  target = (&&function_184);
  goto apply_addr;
function_186:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 /* ____transform-tail-call */);
  target = (&&function_185);
  goto apply_addr;
function_187:
  increment_count(env);
  val = wrap_function((&&function_186), env);
  goto pop_function;
/* fn_16 */
body_69:
global_c102c110c95c49c53 = nil(); /* fn_15 */
  increment_count(env);
  val = wrap_function((&&function_187), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_70;
pointer global_c102c110c95c49c52; /* fn_14 */
function_188:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_189:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52 /* fn_14 */);
  target = (&&function_188);
  goto apply_addr;
function_190:
  increment_count(env);
  val = wrap_function((&&function_189), env);
  goto pop_function;
/* fn_15 */
body_70:
global_c102c110c95c49c52 = nil(); /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_190), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_71;
function_191:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_192:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  goto pop_function;
/* fn_14 */
body_71:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_72;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108;
function_193:
  goto top_level_apply;
function_194:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c102c110c95c49c57 /* fn_19 */);
  target = (&&function_193);
  goto apply_addr;
function_195:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c57 /* ___l_19 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_194);
  goto apply_addr;
/* ____transform-if-tail-call */
body_72:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-if-tail-call */
  goto body_73;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_73:
  val = nil();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_74;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_74:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_75;
pointer global_c95c110c111c116;
function_196:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    val = nil();
    goto pop_function;
  } else {
    val = new_symbol(-52);
    goto pop_function;
  }
/* _not */
body_75:
  increment_count(env);
  val = wrap_function((&&function_196), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_76;
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c50c49;
function_197:
  goto top_level_apply;
function_198:
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
  increment_count(val = global_c102c110c95c50c48 /* fn_20 */);
  target = (&&function_197);
  goto apply_addr;
function_199:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_198);
  goto apply_addr;
function_200:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c49 /* ___l_21 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_199);
  goto apply_addr;
function_201:
  increment_count(env);
  val = wrap_function((&&function_200), env);
  goto pop_function;
/* fn_21 */
body_76:
global_c102c110c95c50c48 = nil(); /* fn_20 */
  increment_count(env);
  val = wrap_function((&&function_201), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_77;
function_202:
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
  val = nil();
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
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
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_203:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  goto pop_function;
/* fn_20 */
body_77:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_78;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108;
function_204:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_205:
  goto top_level_apply;
function_206:
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
  increment_count(val = global_c102c110c95c50c49 /* fn_21 */);
  target = (&&function_205);
  goto apply_addr;
function_207:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
    target = (&&function_204);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
    target = (&&function_206);
    goto apply_addr;
  }
function_208:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
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
    increment_count(val = car(cdr(cdr(car(env)))));
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
      increment_count(val = car(cdr(cdr(car(env)))));
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
      increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115 /* ____builtins */);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
      target = (&&function_208);
      goto apply_addr;
    }
  }
function_210:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c48 /* ___l_20 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_209);
  goto apply_addr;
/* ____transform-atom-tail-call */
body_78:
  increment_count(env);
  val = wrap_function((&&function_210), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-atom-tail-call */
  goto body_79;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_79:
  val = new_symbol(-35);
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_80;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_80:
  val = new_symbol(-47);
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_81;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_81:
  val = new_symbol(-51);
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_82;
pointer global_c95c99c97c100c114;
function_211:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* _cadr */
body_82:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_83;
pointer global_c95c99c100c100c114;
function_212:
  increment_count(val = cdr(cdr(car(car(env)))));
  goto pop_function;
/* _cddr */
body_83:
  increment_count(env);
  val = wrap_function((&&function_212), env);
  global_c95c99c100c100c114 = val; /* _cddr */
  goto body_84;
pointer global_c95c99c97c100c100c114;
function_213:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* _caddr */
body_84:
  increment_count(env);
  val = wrap_function((&&function_213), env);
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_85;
function_214:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108 /* ____transform-fn-tail-call */);
  goto top_level_apply;
function_215:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_214);
  goto apply_addr;
function_216:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 /* ____transform-if-tail-call */);
  goto top_level_apply;
function_217:
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
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
  target = (&&function_217);
  goto apply_addr;
function_219:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_218);
  goto apply_addr;
function_220:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108 /* ____transform-primitive-tail-call */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108 /* ____transform-application-tail-call */);
    goto top_level_apply;
  }
function_221:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    if (is_binary(args)) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = nil(); }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
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
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115 /* ____builtins */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_220);
    goto apply_addr;
  }
function_222:
  if (! is_nil(val)) {
    decrement_count(val);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c100c100c114 /* _cddr */);
    target = (&&function_219);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c52 /* ___l_24 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
    target = (&&function_215);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c51 /* ___l_23 */);
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108 /* ____transform-atom-tail-call */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c50 /* ___l_22 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_223);
    goto apply_addr;
  }
function_225:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_224);
  goto apply_addr;
/* ____transform-tail-call */
body_85:
  increment_count(env);
  val = wrap_function((&&function_225), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-tail-call */
  goto body_86;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_86:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_87;
pointer global_c102c110c95c50c52; /* fn_24 */
pointer global_c102c110c95c50c53;
function_226:
  goto top_level_apply;
function_227:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c52 /* fn_24 */);
  target = (&&function_226);
  goto apply_addr;
function_228:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c53 /* ___l_25 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_227);
  goto apply_addr;
function_229:
  increment_count(env);
  val = wrap_function((&&function_228), env);
  goto pop_function;
/* fn_25 */
body_87:
global_c102c110c95c50c52 = nil(); /* fn_24 */
  increment_count(env);
  val = wrap_function((&&function_229), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_88;
pointer global_c102c110c95c50c51; /* fn_23 */
function_230:
  goto top_level_apply;
function_231:
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c51 /* fn_23 */);
  target = (&&function_230);
  goto apply_addr;
function_232:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_231);
  goto apply_addr;
function_233:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  goto pop_function;
/* fn_24 */
body_88:
global_c102c110c95c50c51 = nil(); /* fn_23 */
  increment_count(env);
  val = wrap_function((&&function_233), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_89;
pointer global_c102c110c95c50c50; /* fn_22 */
function_234:
  goto top_level_apply;
function_235:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c50 /* fn_22 */);
  target = (&&function_234);
  goto apply_addr;
function_236:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 /* ____transform-tail-call */);
  target = (&&function_235);
  goto apply_addr;
function_237:
  increment_count(env);
  val = wrap_function((&&function_236), env);
  goto pop_function;
/* fn_23 */
body_89:
global_c102c110c95c50c50 = nil(); /* fn_22 */
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_90;
function_238:
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
  increment_count(val = car(car(env)));
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
function_239:
  increment_count(env);
  val = wrap_function((&&function_238), env);
  goto pop_function;
/* fn_22 */
body_90:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_91;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110;
function_240:
  goto top_level_apply;
function_241:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c53 /* fn_25 */);
  target = (&&function_240);
  goto apply_addr;
function_242:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_241);
  goto apply_addr;
/* ____transform-fn */
body_91:
  increment_count(env);
  val = wrap_function((&&function_242), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 = val; /* ____transform-fn */
  goto body_92;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_92:
  val = nil();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_93;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_93:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_94;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_94:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_95;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_95:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_96;
pointer global_c95c114c101c118c101c114c115c101;
function_243:
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
body_96:
  increment_count(env);
  val = wrap_function((&&function_243), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_97;
pointer global_c102c110c95c50c55; /* fn_27 */
pointer global_c102c110c95c50c56;
function_244:
  goto top_level_apply;
function_245:
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
  increment_count(val = global_c102c110c95c50c55 /* fn_27 */);
  target = (&&function_244);
  goto apply_addr;
function_246:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c55 /* ___l_27 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_245);
  goto apply_addr;
function_247:
  increment_count(env);
  val = wrap_function((&&function_246), env);
  goto pop_function;
/* fn_28 */
body_97:
global_c102c110c95c50c55 = nil(); /* fn_27 */
  increment_count(env);
  val = wrap_function((&&function_247), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_98;
pointer global_c102c110c95c50c54; /* fn_26 */
function_248:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_249:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c54 /* fn_26 */);
  target = (&&function_248);
  goto apply_addr;
function_250:
  increment_count(env);
  val = wrap_function((&&function_249), env);
  goto pop_function;
/* fn_27 */
body_98:
global_c102c110c95c50c54 = nil(); /* fn_26 */
  increment_count(env);
  val = wrap_function((&&function_250), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_99;
function_251:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_252:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_251);
  goto apply_addr;
function_253:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
  target = (&&function_252);
  goto apply_addr;
function_254:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  goto pop_function;
/* fn_26 */
body_99:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_100;
pointer global_c102c110c95c51c49; /* fn_31 */
pointer global_c102c110c95c51c50;
function_255:
  goto top_level_apply;
function_256:
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c49 /* fn_31 */);
  target = (&&function_255);
  goto apply_addr;
function_257:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57 /* ___l_29 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_256);
  goto apply_addr;
function_258:
  increment_count(env);
  val = wrap_function((&&function_257), env);
  goto pop_function;
/* fn_32 */
body_100:
global_c102c110c95c51c49 = nil(); /* fn_31 */
  increment_count(env);
  val = wrap_function((&&function_258), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_101;
pointer global_c102c110c95c51c48; /* fn_30 */
function_259:
  goto top_level_apply;
function_260:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c48 /* fn_30 */);
  target = (&&function_259);
  goto apply_addr;
function_261:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c56 /* ___l_28 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_260);
  goto apply_addr;
function_262:
  increment_count(env);
  val = wrap_function((&&function_261), env);
  goto pop_function;
/* fn_31 */
body_101:
global_c102c110c95c51c48 = nil(); /* fn_30 */
  increment_count(env);
  val = wrap_function((&&function_262), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_102;
pointer global_c102c110c95c50c57; /* fn_29 */
function_263:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_264:
  push_args();
  val = nil();
  args = val;
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
  increment_count(val = global_c102c110c95c50c57 /* fn_29 */);
  target = (&&function_263);
  goto apply_addr;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* fn_30 */
body_102:
global_c102c110c95c50c57 = nil(); /* fn_29 */
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_103;
function_266:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = cdr(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_267:
  increment_count(env);
  val = wrap_function((&&function_266), env);
  goto pop_function;
/* fn_29 */
body_103:
  increment_count(env);
  val = wrap_function((&&function_267), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_104;
function_268:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_269:
  goto top_level_apply;
function_270:
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c50c56 /* fn_28 */);
  target = (&&function_269);
  goto apply_addr;
function_271:
  goto top_level_apply;
function_272:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c50 /* fn_32 */);
  target = (&&function_271);
  goto apply_addr;
function_273:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
    target = (&&function_270);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
    target = (&&function_272);
    goto apply_addr;
  }
function_274:
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
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_268);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_273);
    goto apply_addr;
  }
function_275:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54 /* ___l_26 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_274);
  goto apply_addr;
/* ____transform-args */
body_104:
  increment_count(env);
  val = wrap_function((&&function_275), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = val; /* ____transform-args */
  goto body_105;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_105:
  val = nil();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_106;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_106:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_107;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_107:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_108;
pointer global_c102c110c95c51c54; /* fn_36 */
pointer global_c102c110c95c51c55;
function_276:
  goto top_level_apply;
function_277:
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
  increment_count(val = global_c102c110c95c51c54 /* fn_36 */);
  target = (&&function_276);
  goto apply_addr;
function_278:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c50 /* ___l_32 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_277);
  goto apply_addr;
function_279:
  increment_count(env);
  val = wrap_function((&&function_278), env);
  goto pop_function;
/* fn_37 */
body_108:
global_c102c110c95c51c54 = nil(); /* fn_36 */
  increment_count(env);
  val = wrap_function((&&function_279), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_109;
pointer global_c102c110c95c51c53; /* fn_35 */
function_280:
  goto top_level_apply;
function_281:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c53 /* fn_35 */);
  target = (&&function_280);
  goto apply_addr;
function_282:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c49 /* ___l_31 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_281);
  goto apply_addr;
function_283:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  goto pop_function;
/* fn_36 */
body_109:
global_c102c110c95c51c53 = nil(); /* fn_35 */
  increment_count(env);
  val = wrap_function((&&function_283), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_110;
pointer global_c102c110c95c51c52; /* fn_34 */
function_284:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_285:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c52 /* fn_34 */);
  target = (&&function_284);
  goto apply_addr;
function_286:
  increment_count(env);
  val = wrap_function((&&function_285), env);
  goto pop_function;
/* fn_35 */
body_110:
global_c102c110c95c51c52 = nil(); /* fn_34 */
  increment_count(env);
  val = wrap_function((&&function_286), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_111;
pointer global_c102c110c95c51c51; /* fn_33 */
function_287:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48 /* ___l_30 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_288:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c51 /* fn_33 */);
  target = (&&function_287);
  goto apply_addr;
function_289:
  increment_count(env);
  val = wrap_function((&&function_288), env);
  goto pop_function;
/* fn_34 */
body_111:
global_c102c110c95c51c51 = nil(); /* fn_33 */
  increment_count(env);
  val = wrap_function((&&function_289), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_112;
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
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_291:
  push_args();
  increment_count(val = car(car(env)));
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_290);
  goto apply_addr;
function_292:
  increment_count(env);
  val = wrap_function((&&function_291), env);
  goto pop_function;
/* fn_33 */
body_112:
  increment_count(env);
  val = wrap_function((&&function_292), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_113;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110;
function_293:
  goto top_level_apply;
function_294:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c55 /* fn_37 */);
  target = (&&function_293);
  goto apply_addr;
function_295:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_294);
  goto apply_addr;
/* ____transform-application */
body_113:
  increment_count(env);
  val = wrap_function((&&function_295), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110 = val; /* ____transform-application */
  goto body_114;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_114:
  val = nil();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_115;
pointer global_c102c110c95c51c56;
function_296:
  push_args();
  val = nil();
  args = val;
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
function_297:
  increment_count(env);
  val = wrap_function((&&function_296), env);
  goto pop_function;
/* fn_38 */
body_115:
  increment_count(env);
  val = wrap_function((&&function_297), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_116;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101;
function_298:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c51 /* ___l_33 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_299:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c56 /* fn_38 */);
  target = (&&function_298);
  goto apply_addr;
/* ____transform-primitive */
body_116:
  increment_count(env);
  val = wrap_function((&&function_299), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101 = val; /* ____transform-primitive */
  goto body_117;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_117:
  val = nil();
  push_args();
  args = val;
  val = new_number(50);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_118;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_118:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_119;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_119:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_120;
pointer global_c102c110c95c52c51; /* fn_43 */
pointer global_c102c110c95c52c52;
function_300:
  goto top_level_apply;
function_301:
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
  increment_count(val = global_c102c110c95c52c51 /* fn_43 */);
  target = (&&function_300);
  goto apply_addr;
function_302:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c53 /* ___l_35 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_301);
  goto apply_addr;
function_303:
  increment_count(env);
  val = wrap_function((&&function_302), env);
  goto pop_function;
/* fn_44 */
body_120:
global_c102c110c95c52c51 = nil(); /* fn_43 */
  increment_count(env);
  val = wrap_function((&&function_303), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_121;
pointer global_c102c110c95c52c50; /* fn_42 */
function_304:
  goto top_level_apply;
function_305:
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
  increment_count(val = global_c102c110c95c52c50 /* fn_42 */);
  target = (&&function_304);
  goto apply_addr;
function_306:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52 /* ___l_34 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_305);
  goto apply_addr;
function_307:
  increment_count(env);
  val = wrap_function((&&function_306), env);
  goto pop_function;
/* fn_43 */
body_121:
global_c102c110c95c52c50 = nil(); /* fn_42 */
  increment_count(env);
  val = wrap_function((&&function_307), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_122;
pointer global_c102c110c95c52c49; /* fn_41 */
function_308:
  goto top_level_apply;
function_309:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c102c110c95c52c49 /* fn_41 */);
  target = (&&function_308);
  goto apply_addr;
function_310:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  target = (&&function_309);
  goto apply_addr;
function_311:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  goto pop_function;
/* fn_42 */
body_122:
global_c102c110c95c52c49 = nil(); /* fn_41 */
  increment_count(env);
  val = wrap_function((&&function_311), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_123;
pointer global_c102c110c95c52c48; /* fn_40 */
function_312:
  goto top_level_apply;
function_313:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c48 /* fn_40 */);
  target = (&&function_312);
  goto apply_addr;
function_314:
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
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  target = (&&function_313);
  goto apply_addr;
function_315:
  increment_count(env);
  val = wrap_function((&&function_314), env);
  goto pop_function;
/* fn_41 */
body_123:
global_c102c110c95c52c48 = nil(); /* fn_40 */
  increment_count(env);
  val = wrap_function((&&function_315), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_124;
pointer global_c102c110c95c51c57; /* fn_39 */
function_316:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_317:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51c57 /* fn_39 */);
  target = (&&function_316);
  goto apply_addr;
function_318:
  increment_count(env);
  val = wrap_function((&&function_317), env);
  goto pop_function;
/* fn_40 */
body_124:
global_c102c110c95c51c57 = nil(); /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_318), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_125;
function_319:
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_320:
  increment_count(env);
  val = wrap_function((&&function_319), env);
  goto pop_function;
/* fn_39 */
body_125:
  increment_count(env);
  val = wrap_function((&&function_320), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_126;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102;
function_321:
  goto top_level_apply;
function_322:
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c102c110c95c52c52 /* fn_44 */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c54 /* ___l_36 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_322);
  goto apply_addr;
/* ____transform-if */
body_126:
  increment_count(env);
  val = wrap_function((&&function_323), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 = val; /* ____transform-if */
  goto body_127;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_127:
  val = nil();
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_128;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_128:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_129;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_129:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_130;
pointer global_c102c110c95c52c55; /* fn_47 */
pointer global_c102c110c95c52c56;
function_324:
  goto top_level_apply;
function_325:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c55 /* fn_47 */);
  target = (&&function_324);
  goto apply_addr;
function_326:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c56 /* ___l_38 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_325);
  goto apply_addr;
function_327:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  goto pop_function;
/* fn_48 */
body_130:
global_c102c110c95c52c55 = nil(); /* fn_47 */
  increment_count(env);
  val = wrap_function((&&function_327), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_131;
pointer global_c102c110c95c52c54; /* fn_46 */
function_328:
  goto top_level_apply;
function_329:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52c54 /* fn_46 */);
  target = (&&function_328);
  goto apply_addr;
function_330:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_329);
  goto apply_addr;
function_331:
  increment_count(env);
  val = wrap_function((&&function_330), env);
  goto pop_function;
/* fn_47 */
body_131:
global_c102c110c95c52c54 = nil(); /* fn_46 */
  increment_count(env);
  val = wrap_function((&&function_331), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_132;
pointer global_c102c110c95c52c53; /* fn_45 */
function_332:
  goto top_level_apply;
function_333:
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
  increment_count(val = global_c102c110c95c52c53 /* fn_45 */);
  target = (&&function_332);
  goto apply_addr;
function_334:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_333);
  goto apply_addr;
function_335:
  increment_count(env);
  val = wrap_function((&&function_334), env);
  goto pop_function;
/* fn_46 */
body_132:
global_c102c110c95c52c53 = nil(); /* fn_45 */
  increment_count(env);
  val = wrap_function((&&function_335), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_133;
function_336:
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
  increment_count(val = car(car(env)));
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
function_337:
  increment_count(env);
  val = wrap_function((&&function_336), env);
  goto pop_function;
/* fn_45 */
body_133:
  increment_count(env);
  val = wrap_function((&&function_337), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_134;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109;
function_338:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  goto top_level_apply;
function_339:
  goto top_level_apply;
function_340:
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
  increment_count(val = global_c102c110c95c52c56 /* fn_48 */);
  target = (&&function_339);
  goto apply_addr;
function_341:
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
    target = (&&function_338);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c57 /* ___l_39 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    target = (&&function_340);
    goto apply_addr;
  }
function_342:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_341);
  goto apply_addr;
function_343:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
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
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(car(env)))));
      goto top_level_apply;
    } else {
      push_args();
      val = nil();
      args = val;
      push_args();
      val = nil();
      args = val;
      increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115 /* ____builtins */);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
      target = (&&function_342);
      goto apply_addr;
    }
  }
function_344:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c55 /* ___l_37 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_343);
  goto apply_addr;
/* ____transform-atom */
body_134:
  increment_count(env);
  val = wrap_function((&&function_344), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109 = val; /* ____transform-atom */
  goto body_135;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_135:
  val = new_symbol(-35);
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_136;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_136:
  val = new_symbol(-47);
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_137;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_137:
  val = new_symbol(-51);
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_138;
pointer global_c95c99c97c100c100c100c114;
function_345:
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* _cadddr */
body_138:
  increment_count(env);
  val = wrap_function((&&function_345), env);
  global_c95c99c97c100c100c100c114 = val; /* _cadddr */
  goto body_139;
function_346:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 /* ____transform-fn */);
  goto top_level_apply;
function_347:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_346);
  goto apply_addr;
function_348:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 /* ____transform-if */);
  goto top_level_apply;
function_349:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_348);
  goto apply_addr;
function_350:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
  target = (&&function_349);
  goto apply_addr;
function_351:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101 /* ____transform-primitive */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110 /* ____transform-application */);
    goto top_level_apply;
  }
function_352:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c98c117c105c108c116c105c110c115 /* ____builtins */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_351);
    goto apply_addr;
  }
function_353:
  if (! is_nil(val)) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c97c100c100c100c114 /* _cadddr */);
    target = (&&function_350);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c50 /* ___l_42 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_352);
    goto apply_addr;
  }
function_354:
  if (! is_nil(val)) {
    decrement_count(val);
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
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
    target = (&&function_347);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c49 /* ___l_41 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_353);
    goto apply_addr;
  }
function_355:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109 /* ____transform-atom */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c48 /* ___l_40 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_354);
    goto apply_addr;
  }
function_356:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_355);
  goto apply_addr;
/* ____transform */
body_139:
  increment_count(env);
  val = wrap_function((&&function_356), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = val; /* ____transform */
  goto body_140;
pointer global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110;
function_357:
  increment_count(val = car(car(env)));
  goto pop_function;
function_358:
  push_args();
  val = nil();
  args = val;
  increment_count(env);
  val = wrap_function((&&function_357), env);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101 /* ____initial-symbol-name */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
/* ____cps-transformation */
body_140:
  increment_count(env);
  val = wrap_function((&&function_358), env);
  global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 = val; /* ____cps-transformation */
  goto body_141;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_141:
  val = new_symbol(-39);
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_142;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116;
function_359:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_360:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_359);
  goto apply_addr;
function_361:
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_360);
  goto apply_addr;
function_362:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 /* ____cps-transformation */);
  target = (&&function_361);
  goto apply_addr;
function_363:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_364:
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
    increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
    target = (&&function_362);
    goto apply_addr;
  } else {
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 /* ____cps-transformation */);
    target = (&&function_363);
    goto apply_addr;
  }
function_365:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c51 /* ___l_43 */);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_364);
  goto apply_addr;
/* ____transform-statement */
body_142:
  increment_count(env);
  val = wrap_function((&&function_365), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 = val; /* ____transform-statement */
  goto body_143;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
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
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_144;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
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
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_145;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_145:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_146;
pointer global_c95c111c114;
function_366:
  goto top_level_apply;
function_367:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
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
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_367), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_366);
  goto apply_addr;
/* _or */
body_146:
  increment_count(env);
  val = wrap_function((&&function_368), env);
  global_c95c111c114 = val; /* _or */
  goto body_147;
pointer global_c95c97c110c100;
function_369:
  goto top_level_apply;
function_370:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_371:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-52);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_370), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_369);
  goto apply_addr;
/* _and */
body_147:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_148;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_372:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_373:
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
    target = (&&function_372);
    goto apply_addr;
  }
function_374:
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
    target = (&&function_373);
    goto apply_addr;
  }
function_375:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_374);
  goto apply_addr;
/* _escape-char */
body_148:
  increment_count(env);
  val = wrap_function((&&function_375), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_149;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* _parse-escaped-string */
pointer global_c102c110c95c52c57;
function_376:
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
function_377:
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
    target = (&&function_376);
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
    target = (&&function_378);
    goto apply_addr;
  }
function_380:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_379);
  goto apply_addr;
function_381:
  increment_count(env);
  val = wrap_function((&&function_380), env);
  goto pop_function;
/* fn_49 */
body_149:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* _parse-string */
global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* _parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_381), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_150;
function_382:
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
  increment_count(val = global_c102c110c95c52c57 /* fn_49 */);
  goto top_level_apply;
/* _parse-escaped-string */
body_150:
  increment_count(env);
  val = wrap_function((&&function_382), env);
  global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* _parse-escaped-string */
  goto body_151;
pointer global_c102c110c95c53c48;
function_383:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_384:
  args = cons(val, args);
  val = new_symbol(-51);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_383);
  goto apply_addr;
function_385:
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
    target = (&&function_385);
    goto apply_addr;
  }
function_387:
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
    target = (&&function_384);
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
    target = (&&function_386);
    goto apply_addr;
  }
function_388:
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
    target = (&&function_387);
    goto apply_addr;
  }
function_389:
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
    target = (&&function_388);
    goto apply_addr;
  }
function_390:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_389);
  goto apply_addr;
function_391:
  increment_count(env);
  val = wrap_function((&&function_390), env);
  goto pop_function;
/* fn_50 */
body_151:
  increment_count(env);
  val = wrap_function((&&function_391), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_152;
function_392:
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
  increment_count(val = global_c102c110c95c53c48 /* fn_50 */);
  goto top_level_apply;
/* _parse-string */
body_152:
  increment_count(env);
  val = wrap_function((&&function_392), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_153;
pointer global_c95c115c107c105c112c45c108c105c110c101; /* _skip-line */
pointer global_c102c110c95c53c49;
function_393:
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
function_394:
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
    target = (&&function_393);
    goto apply_addr;
  }
function_395:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_394);
  goto apply_addr;
function_396:
  increment_count(env);
  val = wrap_function((&&function_395), env);
  goto pop_function;
/* fn_51 */
body_153:
global_c95c115c107c105c112c45c108c105c110c101 = nil(); /* _skip-line */
  increment_count(env);
  val = wrap_function((&&function_396), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_154;
function_397:
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
  increment_count(val = global_c102c110c95c53c49 /* fn_51 */);
  goto top_level_apply;
/* _skip-line */
body_154:
  increment_count(env);
  val = wrap_function((&&function_397), env);
  global_c95c115c107c105c112c45c108c105c110c101 = val; /* _skip-line */
  goto body_155;
pointer global_c95c112c97c114c115c101c45c110c117c109c98c101c114; /* _parse-number */
pointer global_c102c110c95c53c50;
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
function_399:
  goto top_level_apply;
function_400:
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
    target = (&&function_399);
    goto apply_addr;
  }
function_401:
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
      target = (&&function_398);
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
      target = (&&function_400);
      goto apply_addr;
    }
  }
function_402:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_401);
  goto apply_addr;
function_403:
  increment_count(env);
  val = wrap_function((&&function_402), env);
  goto pop_function;
/* fn_52 */
body_155:
global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* _parse-number */
  increment_count(env);
  val = wrap_function((&&function_403), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_156;
function_404:
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
  increment_count(val = global_c102c110c95c53c50 /* fn_52 */);
  goto top_level_apply;
/* _parse-number */
body_156:
  increment_count(env);
  val = wrap_function((&&function_404), env);
  global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* _parse-number */
  goto body_157;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c53c51;
function_405:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_406:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_405);
  goto apply_addr;
function_407:
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
    target = (&&function_406);
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
    target = (&&function_406);
    goto apply_addr;
  }
function_408:
  goto top_level_apply;
function_409:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_408);
  goto apply_addr;
function_410:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_409);
  goto apply_addr;
function_411:
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
    target = (&&function_410);
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
function_412:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_411);
  goto apply_addr;
function_413:
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
  target = (&&function_412);
  goto apply_addr;
function_414:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_413);
  goto apply_addr;
function_415:
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
      target = (&&function_407);
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
      target = (&&function_414);
      goto apply_addr;
    }
  }
function_416:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_415);
  goto apply_addr;
function_417:
  increment_count(env);
  val = wrap_function((&&function_416), env);
  goto pop_function;
/* fn_53 */
body_157:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_417), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_158;
function_418:
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
  increment_count(val = global_c102c110c95c53c51 /* fn_53 */);
  goto top_level_apply;
/* _parse-symbol */
body_158:
  increment_count(env);
  val = wrap_function((&&function_418), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_159;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c53c52;
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
function_420:
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
    target = (&&function_420);
    goto apply_addr;
  }
function_422:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_421);
  goto apply_addr;
function_423:
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
    target = (&&function_422);
    goto apply_addr;
  }
function_424:
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
    target = (&&function_423);
    goto apply_addr;
  }
function_425:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_424);
  goto apply_addr;
function_426:
  increment_count(env);
  val = wrap_function((&&function_425), env);
  goto pop_function;
/* fn_54 */
body_159:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_426), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_160;
function_427:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c52 /* fn_54 */);
  goto top_level_apply;
/* _parse-paren */
body_160:
  increment_count(env);
  val = wrap_function((&&function_427), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_161;
pointer global_c102c110c95c53c53; /* fn_55 */
pointer global_c95c112c97c114c115c101c45c116c97c105c108; /* _parse-tail */
pointer global_c102c110c95c53c54;
function_428:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
  goto top_level_apply;
function_429:
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
  increment_count(val = global_c102c110c95c53c53 /* fn_55 */);
  target = (&&function_428);
  goto apply_addr;
function_430:
  increment_count(env);
  val = wrap_function((&&function_429), env);
  goto pop_function;
/* fn_56 */
body_161:
global_c102c110c95c53c53 = nil(); /* fn_55 */
global_c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* _parse-tail */
  increment_count(env);
  val = wrap_function((&&function_430), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_162;
function_431:
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
function_432:
  increment_count(env);
  val = wrap_function((&&function_431), env);
  goto pop_function;
/* fn_55 */
body_162:
  increment_count(env);
  val = wrap_function((&&function_432), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_163;
pointer global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_433:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c54 /* fn_56 */);
  goto top_level_apply;
/* _parse-tail-cont */
body_163:
  increment_count(env);
  val = wrap_function((&&function_433), env);
  global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* _parse-tail-cont */
  goto body_164;
pointer global_c102c110c95c53c56; /* fn_58 */
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c102c110c95c53c57;
function_434:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_435:
  goto top_level_apply;
function_436:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
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
    target = (&&function_436);
    goto apply_addr;
  }
function_438:
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
    increment_count(val = global_c102c110c95c53c56 /* fn_58 */);
    target = (&&function_434);
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
    target = (&&function_439);
    goto apply_addr;
  }
function_441:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_440);
  goto apply_addr;
function_442:
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
    target = (&&function_441);
    goto apply_addr;
  }
function_443:
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
    target = (&&function_442);
    goto apply_addr;
  }
function_444:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_443);
  goto apply_addr;
function_445:
  increment_count(env);
  val = wrap_function((&&function_444), env);
  goto pop_function;
/* fn_59 */
body_164:
global_c102c110c95c53c56 = nil(); /* fn_58 */
global_c95c112c97c114c115c101c45c101c120c112c114 = nil(); /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_445), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_165;
pointer global_c102c110c95c53c55; /* fn_57 */
function_446:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
  goto top_level_apply;
function_447:
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
  increment_count(val = global_c102c110c95c53c55 /* fn_57 */);
  target = (&&function_446);
  goto apply_addr;
function_448:
  increment_count(env);
  val = wrap_function((&&function_447), env);
  goto pop_function;
/* fn_58 */
body_165:
global_c102c110c95c53c55 = nil(); /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_448), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_166;
function_449:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_450:
  increment_count(env);
  val = wrap_function((&&function_449), env);
  goto pop_function;
/* fn_57 */
body_166:
  increment_count(env);
  val = wrap_function((&&function_450), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_167;
function_451:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c53c57 /* fn_59 */);
  goto top_level_apply;
/* _parse-tail */
body_167:
  increment_count(env);
  val = wrap_function((&&function_451), env);
  global_c95c112c97c114c115c101c45c116c97c105c108 = val; /* _parse-tail */
  goto body_168;
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c54c48;
function_452:
  goto top_level_apply;
function_453:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_452);
  goto apply_addr;
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
    target = (&&function_455);
    goto apply_addr;
  }
function_457:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_456);
  goto apply_addr;
function_458:
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
    target = (&&function_457);
    goto apply_addr;
  }
function_459:
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
    target = (&&function_458);
    goto apply_addr;
  }
function_460:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_459);
  goto apply_addr;
function_461:
  increment_count(env);
  val = wrap_function((&&function_460), env);
  goto pop_function;
/* fn_60 */
body_168:
global_c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_461), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_169;
function_462:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c48 /* fn_60 */);
  goto top_level_apply;
/* _parse-pair */
body_169:
  increment_count(env);
  val = wrap_function((&&function_462), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_170;
pointer global_c102c110c95c54c51; /* fn_63 */
pointer global_c102c110c95c54c50; /* fn_62 */
pointer global_c102c110c95c54c49; /* fn_61 */
pointer global_c102c110c95c54c52;
function_463:
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
function_464:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_465:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_466:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_467:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
  goto top_level_apply;
function_468:
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
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c54c51 /* fn_63 */);
    target = (&&function_466);
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
    increment_count(val = global_c102c110c95c54c50 /* fn_62 */);
    target = (&&function_465);
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
    target = (&&function_472);
    goto apply_addr;
  }
function_474:
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
    target = (&&function_473);
    goto apply_addr;
  }
function_475:
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
    increment_count(val = global_c102c110c95c54c49 /* fn_61 */);
    target = (&&function_464);
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
    target = (&&function_474);
    goto apply_addr;
  }
function_476:
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
    target = (&&function_475);
    goto apply_addr;
  }
function_477:
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
    target = (&&function_463);
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
    target = (&&function_476);
    goto apply_addr;
  }
function_478:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_477);
  goto apply_addr;
function_479:
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
    target = (&&function_478);
    goto apply_addr;
  }
function_480:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_479);
  goto apply_addr;
function_481:
  increment_count(env);
  val = wrap_function((&&function_480), env);
  goto pop_function;
/* fn_64 */
body_170:
global_c102c110c95c54c51 = nil(); /* fn_63 */
global_c102c110c95c54c50 = nil(); /* fn_62 */
global_c102c110c95c54c49 = nil(); /* fn_61 */
  increment_count(env);
  val = wrap_function((&&function_481), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
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
  val = new_symbol(-51);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_482);
  goto apply_addr;
function_484:
  increment_count(env);
  val = wrap_function((&&function_483), env);
  goto pop_function;
/* fn_61 */
body_171:
  increment_count(env);
  val = wrap_function((&&function_484), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
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
  val = new_symbol(-50);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_485);
  goto apply_addr;
function_487:
  increment_count(env);
  val = wrap_function((&&function_486), env);
  goto pop_function;
/* fn_62 */
body_172:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_173;
function_488:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_489:
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
  val = new_symbol(-49);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_488);
  goto apply_addr;
function_490:
  increment_count(env);
  val = wrap_function((&&function_489), env);
  goto pop_function;
/* fn_63 */
body_173:
  increment_count(env);
  val = wrap_function((&&function_490), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_174;
function_491:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c54c52 /* fn_64 */);
  goto top_level_apply;
/* _parse-expr */
body_174:
  increment_count(env);
  val = wrap_function((&&function_491), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_175;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_492:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
  goto top_level_apply;
function_493:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c52 /* ___l_44 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_492);
  goto apply_addr;
function_494:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c54 /* ___l_46 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c53 /* ___l_45 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_493);
  goto apply_addr;
function_495:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_494), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
/* ____read-expr */
body_175:
  increment_count(env);
  val = wrap_function((&&function_495), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_176;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_176:
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
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_177;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_177:
  val = new_symbol(-39);
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_178;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_178:
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-40);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-42);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-44);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-45);
  push_args();
  args = val;
  val = new_symbol(-38);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-45);
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-46);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-47);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-43);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_179;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_179:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_180;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_180:
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-34);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-34);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_181;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_181:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_182;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_182:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_183;
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
body_183:
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
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  goto body_184;
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
body_184:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  goto body_185;
pointer global_c95c99c97c97c100c114;
function_496:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* _caadr */
body_185:
  increment_count(env);
  val = wrap_function((&&function_496), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_186;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101;
function_497:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_498:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c48 /* ___l_50 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c57 /* ___l_49 */);
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_497);
  goto apply_addr;
function_499:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c50 /* ___l_52 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c53c49 /* ___l_51 */);
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_498);
  goto apply_addr;
function_500:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_499);
  goto apply_addr;
function_501:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_502:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_501);
  goto apply_addr;
function_503:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c53 /* ___l_55 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 /* ____transform-statement */);
  target = (&&function_502);
  goto apply_addr;
function_504:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  target = (&&function_503);
  goto apply_addr;
function_505:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c52 /* ___l_54 */);
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
    target = (&&function_504);
    goto apply_addr;
  }
function_506:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_505);
  goto apply_addr;
function_507:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_506);
  goto apply_addr;
function_508:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_507);
  goto apply_addr;
function_509:
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
  target = (&&function_508);
  goto apply_addr;
function_510:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_509);
  goto apply_addr;
function_511:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c51 /* ___l_53 */);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 /* ____transform-statement */);
    target = (&&function_500);
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
    target = (&&function_510);
    goto apply_addr;
  }
function_512:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_511);
  goto apply_addr;
function_513:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c55 /* ___l_47 */);
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
    increment_count(val = global_c95c95c95c108c95c52c56 /* ___l_48 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_512);
    goto apply_addr;
  }
function_514:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_513);
  goto apply_addr;
function_515:
  increment_count(env);
  val = wrap_function((&&function_514), env);
  goto pop_function;
/* ____compile-source */
body_186:
  increment_count(env);
  val = wrap_function((&&function_515), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_187;
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
function_516:
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
function_517:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_518:
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
  target = (&&function_517);
  goto apply_addr;
body_187:
  increment_count(env);
  val = wrap_function((&&function_518), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_516), nil()), call_stack);
  goto body_0;
}
