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
      increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    target = (&&function_2);
    goto apply_addr;
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
    val = new_symbol(-37);
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
    val = new_symbol(-38);
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
    val = new_symbol(-41);
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
    val = new_symbol(-42);
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
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
    val = new_symbol(-46);
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
    val = new_symbol(-48);
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
    val = new_symbol(-50);
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
    val = new_symbol(-53);
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
    val = new_symbol(-54);
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
    val = new_symbol(-55);
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
    val = new_symbol(-57);
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
    val = new_symbol(-58);
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
    val = new_symbol(-59);
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
    val = new_symbol(-60);
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
    val = new_symbol(-61);
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
    val = new_symbol(-62);
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
    val = new_symbol(-63);
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
    val = new_symbol(-64);
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
    val = new_symbol(-65);
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
    val = new_symbol(-66);
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
    val = new_symbol(-67);
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
    val = new_symbol(-68);
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
    val = new_symbol(-69);
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
            val = new_symbol(-53);
            goto pop_function;
          } else {
            val = nil();
            goto pop_function;
          }
        } else {
          val = new_symbol(-53);
          goto pop_function;
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
      val = new_symbol(-53);
      goto pop_function;
    }
  } else {
    val = nil();
    goto pop_function;
  }
/* __pair? */
body_4:
  increment_count(env);
  val = wrap_function((&&function_46), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c97c116c111c109;
function_47:
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
      val = new_symbol(-53);
      goto pop_function;
    } else {
      val = nil();
      goto pop_function;
    }
  } else {
    val = new_symbol(-53);
    goto pop_function;
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
    increment_count(val = global_c95c101c113c117c97c108 /* _equal */);
    goto top_level_apply;
  }
function_49:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
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
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    goto top_level_apply;
  }
function_52:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
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
  } else {
    increment_count(val = car(cdr(car(cdr(env)))));
    goto pop_function;
  }
function_56:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
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
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_78), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_75);
  goto apply_addr;
/* _append */
body_21:
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_22;
pointer global_c102c110c95c51;
function_80:
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
function_81:
  increment_count(env);
  val = wrap_function((&&function_80), env);
  goto pop_function;
/* fn_3 */
body_22:
  increment_count(env);
  val = wrap_function((&&function_81), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_23;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_82:
  goto top_level_apply;
function_83:
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
      val = new_number(value(car(args)) / 
                       value(car(cdr(args))));
    }
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_85:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
function_86:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51 /* fn_3 */);
  goto top_level_apply;
function_87:
  increment_count(val = global_c95c105c100 /* _id */);
  goto pop_function;
function_88:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
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
  increment_count(env);
  val = wrap_function((&&function_83), env);
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107 /* _walk */);
  target = (&&function_82);
  goto apply_addr;
/* _build-num-str */
body_23:
  increment_count(env);
  val = wrap_function((&&function_88), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_24;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_89:
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
function_90:
  target = (&&function_89);
  goto apply_addr;
function_91:
  goto top_level_apply;
function_92:
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
      target = (&&function_90);
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
      target = (&&function_91);
      goto apply_addr;
    }
  }
function_93:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_92);
  goto apply_addr;
/* _print-num */
body_24:
  increment_count(env);
  val = wrap_function((&&function_93), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_25;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_94:
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
function_95:
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
      target = (&&function_94);
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
  val = wrap_function((&&function_95), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_26;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_96:
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
function_97:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_96);
  goto apply_addr;
function_98:
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
function_99:
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
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108 /* _print-tail */);
    target = (&&function_97);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109 /* _print-atom */);
    target = (&&function_98);
    goto apply_addr;
  }
function_100:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_99);
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
  val = wrap_function((&&function_100), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_27;
function_101:
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
function_102:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_101);
  goto apply_addr;
function_103:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_104:
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
    increment_count(val = global_c95c112c114c105c110c116c45c116c97c105c108 /* _print-tail */);
    target = (&&function_102);
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
    increment_count(val = global_c95c112c114c105c110c116c45c97c116c111c109 /* _print-atom */);
    target = (&&function_103);
    goto apply_addr;
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
/* _print-with-suffix */
body_27:
  increment_count(env);
  val = wrap_function((&&function_105), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_28;
pointer global_c95c112c114c105c110c116;
function_106:
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
  val = wrap_function((&&function_106), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_29;
pointer global_c95c95c95c95c112c114c105c110c116c45c119c97c114c110c105c110c103c115;
function_107:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_108:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50 /* ___l_2 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49 /* ___l_1 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_107);
  goto apply_addr;
function_109:
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
    target = (&&function_108);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
/* ____print-warnings */
body_29:
  increment_count(env);
  val = wrap_function((&&function_109), env);
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
function_110:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_111:
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
  target = (&&function_110);
  goto apply_addr;
/* ____print-error */
body_32:
  increment_count(env);
  val = wrap_function((&&function_111), env);
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
function_112:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
function_113:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55 /* ___l_7 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_112);
  goto apply_addr;
function_114:
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
  target = (&&function_113);
  goto apply_addr;
/* ____number->symbol */
body_34:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  global_c95c95c95c95c110c117c109c98c101c114c45c62c115c121c109c98c111c108 = val; /* ____number->symbol */
  goto body_35;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_35:
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-36);
  args = cons(val, args);
  val = new_symbol(-40);
  args = cons(val, args);
  val = new_symbol(-43);
  args = cons(val, args);
  val = new_symbol(-52);
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
  val = new_symbol(-49);
  args = cons(val, args);
  val = new_symbol(-42);
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
  val = new_symbol(-48);
  args = cons(val, args);
  val = new_symbol(-46);
  args = cons(val, args);
  val = new_symbol(-47);
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
function_115:
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
function_116:
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
    target = (&&function_115);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_117:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_116);
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
function_118:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_117);
  goto apply_addr;
/* __equal */
body_40:
  increment_count(env);
  val = wrap_function((&&function_118), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_41;
pointer global_c95c109c101c109c98c101c114;
function_119:
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
function_120:
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
    target = (&&function_119);
    goto apply_addr;
  } else {
    val = nil();
    goto pop_function;
  }
function_121:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_120);
  goto apply_addr;
/* _member */
body_41:
  increment_count(env);
  val = wrap_function((&&function_121), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_42;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115;
function_122:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_123:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_122);
  goto apply_addr;
function_124:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
function_125:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48 /* ___l_10 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_124);
  goto apply_addr;
function_126:
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
    target = (&&function_125);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_126);
    goto apply_addr;
  }
function_128:
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
    target = (&&function_127);
    goto apply_addr;
  }
function_129:
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
    target = (&&function_123);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c95c115c112c101c99c105c97c108c45c102c111c114c109c115 /* ____special-forms */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_128);
    goto apply_addr;
  }
function_130:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_129);
  goto apply_addr;
/* ____escape-symbols */
body_42:
  increment_count(env);
  val = wrap_function((&&function_130), env);
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
function_131:
  goto top_level_apply;
function_132:
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
  target = (&&function_131);
  goto apply_addr;
function_133:
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
  target = (&&function_132);
  goto apply_addr;
function_134:
  increment_count(env);
  val = wrap_function((&&function_133), env);
  goto pop_function;
/* fn_7 */
body_46:
global_c102c110c95c54 = nil(); /* fn_6 */
  increment_count(env);
  val = wrap_function((&&function_134), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_47;
pointer global_c102c110c95c53; /* fn_5 */
function_135:
  goto top_level_apply;
function_136:
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
  target = (&&function_135);
  goto apply_addr;
function_137:
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
  target = (&&function_136);
  goto apply_addr;
function_138:
  increment_count(env);
  val = wrap_function((&&function_137), env);
  goto pop_function;
/* fn_6 */
body_47:
global_c102c110c95c53 = nil(); /* fn_5 */
  increment_count(env);
  val = wrap_function((&&function_138), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_48;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108; /* ____transform-tail-call */
pointer global_c102c110c95c52; /* fn_4 */
function_139:
  goto top_level_apply;
function_140:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c52 /* fn_4 */);
  target = (&&function_139);
  goto apply_addr;
function_141:
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
  target = (&&function_140);
  goto apply_addr;
function_142:
  increment_count(env);
  val = wrap_function((&&function_141), env);
  goto pop_function;
/* fn_5 */
body_48:
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = nil(); /* ____transform-tail-call */
global_c102c110c95c52 = nil(); /* fn_4 */
  increment_count(env);
  val = wrap_function((&&function_142), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_49;
function_143:
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
  val = new_symbol(-36);
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
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* fn_4 */
body_49:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_50;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108;
function_145:
  goto top_level_apply;
function_146:
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
  target = (&&function_145);
  goto apply_addr;
function_147:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_146);
  goto apply_addr;
/* ____transform-fn-tail-call */
body_50:
  increment_count(env);
  val = wrap_function((&&function_147), env);
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
function_148:
  goto top_level_apply;
function_149:
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
  target = (&&function_148);
  goto apply_addr;
function_150:
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
  target = (&&function_149);
  goto apply_addr;
function_151:
  increment_count(env);
  val = wrap_function((&&function_150), env);
  goto pop_function;
/* fn_12 */
body_54:
global_c102c110c95c49c49 = nil(); /* fn_11 */
  increment_count(env);
  val = wrap_function((&&function_151), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_55;
pointer global_c102c110c95c49c48; /* fn_10 */
function_152:
  goto top_level_apply;
function_153:
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
  target = (&&function_152);
  goto apply_addr;
function_154:
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
  target = (&&function_153);
  goto apply_addr;
function_155:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  goto pop_function;
/* fn_11 */
body_55:
global_c102c110c95c49c48 = nil(); /* fn_10 */
  increment_count(env);
  val = wrap_function((&&function_155), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_56;
pointer global_c102c110c95c57; /* fn_9 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109; /* ____transform */
function_156:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_157:
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
  target = (&&function_156);
  goto apply_addr;
function_158:
  increment_count(env);
  val = wrap_function((&&function_157), env);
  goto pop_function;
/* fn_10 */
body_56:
global_c102c110c95c57 = nil(); /* fn_9 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = nil(); /* ____transform */
  increment_count(env);
  val = wrap_function((&&function_158), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_57;
pointer global_c102c110c95c56; /* fn_8 */
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115; /* ____transform-args */
function_159:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c51 /* ___l_13 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_160:
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
  target = (&&function_159);
  goto apply_addr;
function_161:
  increment_count(env);
  val = wrap_function((&&function_160), env);
  goto pop_function;
/* fn_9 */
body_57:
global_c102c110c95c56 = nil(); /* fn_8 */
global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = nil(); /* ____transform-args */
  increment_count(env);
  val = wrap_function((&&function_161), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_58;
function_162:
  push_args();
  increment_count(val = car(car(env)));
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  goto top_level_apply;
function_163:
  increment_count(env);
  val = wrap_function((&&function_162), env);
  goto pop_function;
/* fn_8 */
body_58:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_59;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108;
function_164:
  goto top_level_apply;
function_165:
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
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_165);
  goto apply_addr;
/* ____transform-application-tail-call */
body_59:
  increment_count(env);
  val = wrap_function((&&function_166), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-application-tail-call */
  goto body_60;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_60:
  val = nil();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_61;
pointer global_c102c110c95c49c51;
function_167:
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
function_168:
  increment_count(env);
  val = wrap_function((&&function_167), env);
  goto pop_function;
/* fn_13 */
body_61:
  increment_count(env);
  val = wrap_function((&&function_168), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_62;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101c45c116c97c105c108c45c99c97c108c108;
function_169:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54 /* ___l_16 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_170:
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
  target = (&&function_169);
  goto apply_addr;
/* ____transform-primitive-tail-call */
body_62:
  increment_count(env);
  val = wrap_function((&&function_170), env);
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
function_171:
  goto top_level_apply;
function_172:
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
  target = (&&function_171);
  goto apply_addr;
function_173:
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
  target = (&&function_172);
  goto apply_addr;
function_174:
  increment_count(env);
  val = wrap_function((&&function_173), env);
  goto pop_function;
/* fn_19 */
body_66:
global_c102c110c95c49c56 = nil(); /* fn_18 */
  increment_count(env);
  val = wrap_function((&&function_174), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_67;
pointer global_c102c110c95c49c55; /* fn_17 */
function_175:
  goto top_level_apply;
function_176:
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
  target = (&&function_175);
  goto apply_addr;
function_177:
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
  target = (&&function_176);
  goto apply_addr;
function_178:
  increment_count(env);
  val = wrap_function((&&function_177), env);
  goto pop_function;
/* fn_18 */
body_67:
global_c102c110c95c49c55 = nil(); /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_178), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_68;
pointer global_c102c110c95c49c54; /* fn_16 */
function_179:
  goto top_level_apply;
function_180:
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
  target = (&&function_179);
  goto apply_addr;
function_181:
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
  target = (&&function_180);
  goto apply_addr;
function_182:
  increment_count(env);
  val = wrap_function((&&function_181), env);
  goto pop_function;
/* fn_17 */
body_68:
global_c102c110c95c49c54 = nil(); /* fn_16 */
  increment_count(env);
  val = wrap_function((&&function_182), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_69;
pointer global_c102c110c95c49c53; /* fn_15 */
function_183:
  goto top_level_apply;
function_184:
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
  target = (&&function_183);
  goto apply_addr;
function_185:
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
  target = (&&function_184);
  goto apply_addr;
function_186:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  goto pop_function;
/* fn_16 */
body_69:
global_c102c110c95c49c53 = nil(); /* fn_15 */
  increment_count(env);
  val = wrap_function((&&function_186), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_70;
pointer global_c102c110c95c49c52; /* fn_14 */
function_187:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_188:
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
  target = (&&function_187);
  goto apply_addr;
function_189:
  increment_count(env);
  val = wrap_function((&&function_188), env);
  goto pop_function;
/* fn_15 */
body_70:
global_c102c110c95c49c52 = nil(); /* fn_14 */
  increment_count(env);
  val = wrap_function((&&function_189), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_71;
function_190:
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
  val = new_symbol(-43);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_191:
  increment_count(env);
  val = wrap_function((&&function_190), env);
  goto pop_function;
/* fn_14 */
body_71:
  increment_count(env);
  val = wrap_function((&&function_191), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_72;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108;
function_192:
  goto top_level_apply;
function_193:
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
  target = (&&function_192);
  goto apply_addr;
function_194:
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
  target = (&&function_193);
  goto apply_addr;
/* ____transform-if-tail-call */
body_72:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-if-tail-call */
  goto body_73;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_73:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_74;
pointer global_c95c110c111c116;
function_195:
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
/* _not */
body_74:
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_75;
pointer global_c102c110c95c50c48; /* fn_20 */
pointer global_c102c110c95c50c49;
function_196:
  goto top_level_apply;
function_197:
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
  target = (&&function_196);
  goto apply_addr;
function_198:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_197);
  goto apply_addr;
function_199:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c48 /* ___l_20 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_198);
  goto apply_addr;
function_200:
  increment_count(env);
  val = wrap_function((&&function_199), env);
  goto pop_function;
/* fn_21 */
body_75:
global_c102c110c95c50c48 = nil(); /* fn_20 */
  increment_count(env);
  val = wrap_function((&&function_200), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_76;
function_201:
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
  val = new_symbol(-36);
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
function_202:
  increment_count(env);
  val = wrap_function((&&function_201), env);
  goto pop_function;
/* fn_20 */
body_76:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_77;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108;
function_203:
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
function_204:
  goto top_level_apply;
function_205:
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
  target = (&&function_204);
  goto apply_addr;
function_206:
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
    target = (&&function_203);
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
    target = (&&function_205);
    goto apply_addr;
  }
function_207:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_206);
  goto apply_addr;
function_208:
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
      target = (&&function_207);
      goto apply_addr;
    }
  }
/* ____transform-atom-tail-call */
body_77:
  increment_count(env);
  val = wrap_function((&&function_208), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-atom-tail-call */
  goto body_78;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_78:
  val = new_symbol(-36);
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_79;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_79:
  val = new_symbol(-43);
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_80;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_80:
  val = new_symbol(-52);
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_81;
pointer global_c95c99c97c100c114;
function_209:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* _cadr */
body_81:
  increment_count(env);
  val = wrap_function((&&function_209), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_82;
pointer global_c95c99c100c100c114;
function_210:
  increment_count(val = cdr(cdr(car(car(env)))));
  goto pop_function;
/* _cddr */
body_82:
  increment_count(env);
  val = wrap_function((&&function_210), env);
  global_c95c99c100c100c114 = val; /* _cddr */
  goto body_83;
pointer global_c95c99c97c100c100c114;
function_211:
  increment_count(val = car(cdr(cdr(car(car(env))))));
  goto pop_function;
/* _caddr */
body_83:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  global_c95c99c97c100c100c114 = val; /* _caddr */
  goto body_84;
function_212:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110c45c116c97c105c108c45c99c97c108c108 /* ____transform-fn-tail-call */);
  goto top_level_apply;
function_213:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_212);
  goto apply_addr;
function_214:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102c45c116c97c105c108c45c99c97c108c108 /* ____transform-if-tail-call */);
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
  target = (&&function_215);
  goto apply_addr;
function_217:
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
function_219:
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
    target = (&&function_218);
    goto apply_addr;
  }
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
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c100c100c114 /* _cddr */);
    target = (&&function_217);
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
    target = (&&function_219);
    goto apply_addr;
  }
function_221:
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
    target = (&&function_213);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c50c50 /* ___l_22 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
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
    increment_count(val = global_c95c95c95c108c95c50c49 /* ___l_21 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_221);
    goto apply_addr;
  } else {
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
  }
function_223:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_222);
  goto apply_addr;
/* ____transform-tail-call */
body_84:
  increment_count(env);
  val = wrap_function((&&function_223), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c116c97c105c108c45c99c97c108c108 = val; /* ____transform-tail-call */
  goto body_85;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_85:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_86;
pointer global_c102c110c95c50c52; /* fn_24 */
pointer global_c102c110c95c50c53;
function_224:
  goto top_level_apply;
function_225:
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
  target = (&&function_224);
  goto apply_addr;
function_226:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c52 /* ___l_24 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_225);
  goto apply_addr;
function_227:
  increment_count(env);
  val = wrap_function((&&function_226), env);
  goto pop_function;
/* fn_25 */
body_86:
global_c102c110c95c50c52 = nil(); /* fn_24 */
  increment_count(env);
  val = wrap_function((&&function_227), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_87;
pointer global_c102c110c95c50c51; /* fn_23 */
function_228:
  goto top_level_apply;
function_229:
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
  target = (&&function_228);
  goto apply_addr;
function_230:
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
  target = (&&function_229);
  goto apply_addr;
function_231:
  increment_count(env);
  val = wrap_function((&&function_230), env);
  goto pop_function;
/* fn_24 */
body_87:
global_c102c110c95c50c51 = nil(); /* fn_23 */
  increment_count(env);
  val = wrap_function((&&function_231), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_88;
pointer global_c102c110c95c50c50; /* fn_22 */
function_232:
  goto top_level_apply;
function_233:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c50 /* fn_22 */);
  target = (&&function_232);
  goto apply_addr;
function_234:
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
  target = (&&function_233);
  goto apply_addr;
function_235:
  increment_count(env);
  val = wrap_function((&&function_234), env);
  goto pop_function;
/* fn_23 */
body_88:
global_c102c110c95c50c50 = nil(); /* fn_22 */
  increment_count(env);
  val = wrap_function((&&function_235), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_89;
function_236:
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
  val = new_symbol(-36);
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
function_237:
  increment_count(env);
  val = wrap_function((&&function_236), env);
  goto pop_function;
/* fn_22 */
body_89:
  increment_count(env);
  val = wrap_function((&&function_237), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_90;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110;
function_238:
  goto top_level_apply;
function_239:
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
  target = (&&function_238);
  goto apply_addr;
function_240:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_239);
  goto apply_addr;
/* ____transform-fn */
body_90:
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 = val; /* ____transform-fn */
  goto body_91;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_91:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_92;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_92:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
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
pointer global_c95c114c101c118c101c114c115c101;
function_241:
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
body_94:
  increment_count(env);
  val = wrap_function((&&function_241), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_95;
pointer global_c102c110c95c50c56; /* fn_28 */
pointer global_c102c110c95c50c57;
function_242:
  goto top_level_apply;
function_243:
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
  increment_count(val = global_c102c110c95c50c56 /* fn_28 */);
  target = (&&function_242);
  goto apply_addr;
function_244:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c54 /* ___l_26 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_243);
  goto apply_addr;
function_245:
  increment_count(env);
  val = wrap_function((&&function_244), env);
  goto pop_function;
/* fn_29 */
body_95:
global_c102c110c95c50c56 = nil(); /* fn_28 */
  increment_count(env);
  val = wrap_function((&&function_245), env);
  global_c102c110c95c50c57 = val; /* fn_29 */
  goto body_96;
pointer global_c102c110c95c50c55; /* fn_27 */
function_246:
  goto top_level_apply;
function_247:
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
  increment_count(val = global_c102c110c95c50c55 /* fn_27 */);
  target = (&&function_246);
  goto apply_addr;
function_248:
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
  target = (&&function_247);
  goto apply_addr;
function_249:
  increment_count(env);
  val = wrap_function((&&function_248), env);
  goto pop_function;
/* fn_28 */
body_96:
global_c102c110c95c50c55 = nil(); /* fn_27 */
  increment_count(env);
  val = wrap_function((&&function_249), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_97;
pointer global_c102c110c95c50c54; /* fn_26 */
function_250:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_251:
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
  increment_count(val = global_c102c110c95c50c54 /* fn_26 */);
  target = (&&function_250);
  goto apply_addr;
function_252:
  increment_count(env);
  val = wrap_function((&&function_251), env);
  goto pop_function;
/* fn_27 */
body_97:
global_c102c110c95c50c54 = nil(); /* fn_26 */
  increment_count(env);
  val = wrap_function((&&function_252), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_98;
function_253:
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
function_254:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  goto pop_function;
/* fn_26 */
body_98:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_99;
pointer global_c102c110c95c51c49; /* fn_31 */
pointer global_c102c110c95c51c50;
function_255:
  goto top_level_apply;
function_256:
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
  increment_count(val = global_c95c95c95c108c95c50c55 /* ___l_27 */);
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
body_99:
global_c102c110c95c51c49 = nil(); /* fn_31 */
  increment_count(env);
  val = wrap_function((&&function_258), env);
  global_c102c110c95c51c50 = val; /* fn_32 */
  goto body_100;
pointer global_c102c110c95c51c48; /* fn_30 */
function_259:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_260:
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
  increment_count(val = global_c102c110c95c51c48 /* fn_30 */);
  target = (&&function_259);
  goto apply_addr;
function_261:
  increment_count(env);
  val = wrap_function((&&function_260), env);
  goto pop_function;
/* fn_31 */
body_100:
global_c102c110c95c51c48 = nil(); /* fn_30 */
  increment_count(env);
  val = wrap_function((&&function_261), env);
  global_c102c110c95c51c49 = val; /* fn_31 */
  goto body_101;
function_262:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_263:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_262);
  goto apply_addr;
function_264:
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
  target = (&&function_263);
  goto apply_addr;
function_265:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  goto pop_function;
/* fn_30 */
body_101:
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c102c110c95c51c48 = val; /* fn_30 */
  goto body_102;
function_266:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  goto top_level_apply;
function_267:
  goto top_level_apply;
function_268:
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
  increment_count(val = global_c102c110c95c50c57 /* fn_29 */);
  target = (&&function_267);
  goto apply_addr;
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
  increment_count(val = global_c102c110c95c51c50 /* fn_32 */);
  target = (&&function_269);
  goto apply_addr;
function_271:
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
    target = (&&function_268);
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
    target = (&&function_270);
    goto apply_addr;
  }
function_272:
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
    target = (&&function_266);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
    target = (&&function_271);
    goto apply_addr;
  }
/* ____transform-args */
body_102:
  increment_count(env);
  val = wrap_function((&&function_272), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 = val; /* ____transform-args */
  goto body_103;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_103:
  val = nil();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_104;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_104:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_105;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_105:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_106;
pointer global_c102c110c95c51c54; /* fn_36 */
pointer global_c102c110c95c51c55;
function_273:
  goto top_level_apply;
function_274:
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
  target = (&&function_273);
  goto apply_addr;
function_275:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c48 /* ___l_30 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_274);
  goto apply_addr;
function_276:
  increment_count(env);
  val = wrap_function((&&function_275), env);
  goto pop_function;
/* fn_37 */
body_106:
global_c102c110c95c51c54 = nil(); /* fn_36 */
  increment_count(env);
  val = wrap_function((&&function_276), env);
  global_c102c110c95c51c55 = val; /* fn_37 */
  goto body_107;
pointer global_c102c110c95c51c53; /* fn_35 */
function_277:
  goto top_level_apply;
function_278:
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
  target = (&&function_277);
  goto apply_addr;
function_279:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57 /* ___l_29 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_278);
  goto apply_addr;
function_280:
  increment_count(env);
  val = wrap_function((&&function_279), env);
  goto pop_function;
/* fn_36 */
body_107:
global_c102c110c95c51c53 = nil(); /* fn_35 */
  increment_count(env);
  val = wrap_function((&&function_280), env);
  global_c102c110c95c51c54 = val; /* fn_36 */
  goto body_108;
pointer global_c102c110c95c51c52; /* fn_34 */
function_281:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_282:
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
  target = (&&function_281);
  goto apply_addr;
function_283:
  increment_count(env);
  val = wrap_function((&&function_282), env);
  goto pop_function;
/* fn_35 */
body_108:
global_c102c110c95c51c52 = nil(); /* fn_34 */
  increment_count(env);
  val = wrap_function((&&function_283), env);
  global_c102c110c95c51c53 = val; /* fn_35 */
  goto body_109;
pointer global_c102c110c95c51c51; /* fn_33 */
function_284:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56 /* ___l_28 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_285:
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
  target = (&&function_284);
  goto apply_addr;
function_286:
  increment_count(env);
  val = wrap_function((&&function_285), env);
  goto pop_function;
/* fn_34 */
body_109:
global_c102c110c95c51c51 = nil(); /* fn_33 */
  increment_count(env);
  val = wrap_function((&&function_286), env);
  global_c102c110c95c51c52 = val; /* fn_34 */
  goto body_110;
function_287:
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
  val = new_symbol(-36);
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
function_288:
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
  target = (&&function_287);
  goto apply_addr;
function_289:
  increment_count(env);
  val = wrap_function((&&function_288), env);
  goto pop_function;
/* fn_33 */
body_110:
  increment_count(env);
  val = wrap_function((&&function_289), env);
  global_c102c110c95c51c51 = val; /* fn_33 */
  goto body_111;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110;
function_290:
  goto top_level_apply;
function_291:
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
  target = (&&function_290);
  goto apply_addr;
function_292:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_291);
  goto apply_addr;
/* ____transform-application */
body_111:
  increment_count(env);
  val = wrap_function((&&function_292), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c112c112c108c105c99c97c116c105c111c110 = val; /* ____transform-application */
  goto body_112;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_112:
  val = nil();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_113;
pointer global_c102c110c95c51c56;
function_293:
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
function_294:
  increment_count(env);
  val = wrap_function((&&function_293), env);
  goto pop_function;
/* fn_38 */
body_113:
  increment_count(env);
  val = wrap_function((&&function_294), env);
  global_c102c110c95c51c56 = val; /* fn_38 */
  goto body_114;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101;
function_295:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c49 /* ___l_31 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c114c103c115 /* ____transform-args */);
  goto top_level_apply;
function_296:
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
  target = (&&function_295);
  goto apply_addr;
/* ____transform-primitive */
body_114:
  increment_count(env);
  val = wrap_function((&&function_296), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c112c114c105c109c105c116c105c118c101 = val; /* ____transform-primitive */
  goto body_115;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_115:
  val = nil();
  push_args();
  args = val;
  val = new_number(50);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_116;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_116:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_117;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_117:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_118;
pointer global_c102c110c95c52c51; /* fn_43 */
pointer global_c102c110c95c52c52;
function_297:
  goto top_level_apply;
function_298:
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
  target = (&&function_297);
  goto apply_addr;
function_299:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c51 /* ___l_33 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_298);
  goto apply_addr;
function_300:
  increment_count(env);
  val = wrap_function((&&function_299), env);
  goto pop_function;
/* fn_44 */
body_118:
global_c102c110c95c52c51 = nil(); /* fn_43 */
  increment_count(env);
  val = wrap_function((&&function_300), env);
  global_c102c110c95c52c52 = val; /* fn_44 */
  goto body_119;
pointer global_c102c110c95c52c50; /* fn_42 */
function_301:
  goto top_level_apply;
function_302:
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
  target = (&&function_301);
  goto apply_addr;
function_303:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c50 /* ___l_32 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_302);
  goto apply_addr;
function_304:
  increment_count(env);
  val = wrap_function((&&function_303), env);
  goto pop_function;
/* fn_43 */
body_119:
global_c102c110c95c52c50 = nil(); /* fn_42 */
  increment_count(env);
  val = wrap_function((&&function_304), env);
  global_c102c110c95c52c51 = val; /* fn_43 */
  goto body_120;
pointer global_c102c110c95c52c49; /* fn_41 */
function_305:
  goto top_level_apply;
function_306:
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
  target = (&&function_305);
  goto apply_addr;
function_307:
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
  target = (&&function_306);
  goto apply_addr;
function_308:
  increment_count(env);
  val = wrap_function((&&function_307), env);
  goto pop_function;
/* fn_42 */
body_120:
global_c102c110c95c52c49 = nil(); /* fn_41 */
  increment_count(env);
  val = wrap_function((&&function_308), env);
  global_c102c110c95c52c50 = val; /* fn_42 */
  goto body_121;
pointer global_c102c110c95c52c48; /* fn_40 */
function_309:
  goto top_level_apply;
function_310:
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
  target = (&&function_309);
  goto apply_addr;
function_311:
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
  target = (&&function_310);
  goto apply_addr;
function_312:
  increment_count(env);
  val = wrap_function((&&function_311), env);
  goto pop_function;
/* fn_41 */
body_121:
global_c102c110c95c52c48 = nil(); /* fn_40 */
  increment_count(env);
  val = wrap_function((&&function_312), env);
  global_c102c110c95c52c49 = val; /* fn_41 */
  goto body_122;
pointer global_c102c110c95c51c57; /* fn_39 */
function_313:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
function_314:
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
  target = (&&function_313);
  goto apply_addr;
function_315:
  increment_count(env);
  val = wrap_function((&&function_314), env);
  goto pop_function;
/* fn_40 */
body_122:
global_c102c110c95c51c57 = nil(); /* fn_39 */
  increment_count(env);
  val = wrap_function((&&function_315), env);
  global_c102c110c95c52c48 = val; /* fn_40 */
  goto body_123;
function_316:
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
  val = new_symbol(-43);
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_317:
  increment_count(env);
  val = wrap_function((&&function_316), env);
  goto pop_function;
/* fn_39 */
body_123:
  increment_count(env);
  val = wrap_function((&&function_317), env);
  global_c102c110c95c51c57 = val; /* fn_39 */
  goto body_124;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102;
function_318:
  goto top_level_apply;
function_319:
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
  target = (&&function_318);
  goto apply_addr;
function_320:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52 /* ___l_34 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_319);
  goto apply_addr;
/* ____transform-if */
body_124:
  increment_count(env);
  val = wrap_function((&&function_320), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 = val; /* ____transform-if */
  goto body_125;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_125:
  val = nil();
  push_args();
  args = val;
  val = new_number(49);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_126;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_126:
  val = nil();
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_127;
pointer global_c102c110c95c52c55; /* fn_47 */
pointer global_c102c110c95c52c56;
function_321:
  goto top_level_apply;
function_322:
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
  target = (&&function_321);
  goto apply_addr;
function_323:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c53 /* ___l_35 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_322);
  goto apply_addr;
function_324:
  increment_count(env);
  val = wrap_function((&&function_323), env);
  goto pop_function;
/* fn_48 */
body_127:
global_c102c110c95c52c55 = nil(); /* fn_47 */
  increment_count(env);
  val = wrap_function((&&function_324), env);
  global_c102c110c95c52c56 = val; /* fn_48 */
  goto body_128;
pointer global_c102c110c95c52c54; /* fn_46 */
function_325:
  goto top_level_apply;
function_326:
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
  target = (&&function_325);
  goto apply_addr;
function_327:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_326);
  goto apply_addr;
function_328:
  increment_count(env);
  val = wrap_function((&&function_327), env);
  goto pop_function;
/* fn_47 */
body_128:
global_c102c110c95c52c54 = nil(); /* fn_46 */
  increment_count(env);
  val = wrap_function((&&function_328), env);
  global_c102c110c95c52c55 = val; /* fn_47 */
  goto body_129;
pointer global_c102c110c95c52c53; /* fn_45 */
function_329:
  goto top_level_apply;
function_330:
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
  target = (&&function_329);
  goto apply_addr;
function_331:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_330);
  goto apply_addr;
function_332:
  increment_count(env);
  val = wrap_function((&&function_331), env);
  goto pop_function;
/* fn_46 */
body_129:
global_c102c110c95c52c53 = nil(); /* fn_45 */
  increment_count(env);
  val = wrap_function((&&function_332), env);
  global_c102c110c95c52c54 = val; /* fn_46 */
  goto body_130;
function_333:
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
  val = new_symbol(-36);
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
function_334:
  increment_count(env);
  val = wrap_function((&&function_333), env);
  goto pop_function;
/* fn_45 */
body_130:
  increment_count(env);
  val = wrap_function((&&function_334), env);
  global_c102c110c95c52c53 = val; /* fn_45 */
  goto body_131;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109;
function_335:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  goto top_level_apply;
function_336:
  goto top_level_apply;
function_337:
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
  target = (&&function_336);
  goto apply_addr;
function_338:
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
    target = (&&function_335);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c54 /* ___l_36 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    target = (&&function_337);
    goto apply_addr;
  }
function_339:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_338);
  goto apply_addr;
function_340:
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
      target = (&&function_339);
      goto apply_addr;
    }
  }
/* ____transform-atom */
body_131:
  increment_count(env);
  val = wrap_function((&&function_340), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c97c116c111c109 = val; /* ____transform-atom */
  goto body_132;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_132:
  val = new_symbol(-36);
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_133;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_133:
  val = new_symbol(-43);
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_134;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_134:
  val = new_symbol(-52);
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_135;
pointer global_c95c99c97c100c100c100c114;
function_341:
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  goto pop_function;
/* _cadddr */
body_135:
  increment_count(env);
  val = wrap_function((&&function_341), env);
  global_c95c99c97c100c100c100c114 = val; /* _cadddr */
  goto body_136;
function_342:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c102c110 /* ____transform-fn */);
  goto top_level_apply;
function_343:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_342);
  goto apply_addr;
function_344:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c105c102 /* ____transform-if */);
  goto top_level_apply;
function_345:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c114 /* _cadr */);
  target = (&&function_344);
  goto apply_addr;
function_346:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c99c97c100c100c114 /* _caddr */);
  target = (&&function_345);
  goto apply_addr;
function_347:
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
function_348:
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
    target = (&&function_347);
    goto apply_addr;
  }
function_349:
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
    target = (&&function_346);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c57 /* ___l_39 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_348);
    goto apply_addr;
  }
function_350:
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
    target = (&&function_343);
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
    target = (&&function_349);
    goto apply_addr;
  }
function_351:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c55 /* ___l_37 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_350);
    goto apply_addr;
  } else {
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
  }
function_352:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_351);
  goto apply_addr;
/* ____transform */
body_136:
  increment_count(env);
  val = wrap_function((&&function_352), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109 = val; /* ____transform */
  goto body_137;
pointer global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110;
function_353:
  increment_count(val = car(car(env)));
  goto pop_function;
function_354:
  push_args();
  val = nil();
  args = val;
  increment_count(env);
  val = wrap_function((&&function_353), env);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c105c110c105c116c105c97c108c45c115c121c109c98c111c108c45c110c97c109c101 /* ____initial-symbol-name */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109 /* ____transform */);
  goto top_level_apply;
/* ____cps-transformation */
body_137:
  increment_count(env);
  val = wrap_function((&&function_354), env);
  global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 = val; /* ____cps-transformation */
  goto body_138;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_138:
  val = new_symbol(-40);
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_139;
pointer global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116;
function_355:
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
  goto pop_function;
function_356:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_355);
  goto apply_addr;
function_357:
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
  target = (&&function_356);
  goto apply_addr;
function_358:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c112c115c45c116c114c97c110c115c102c111c114c109c97c116c105c111c110 /* ____cps-transformation */);
  target = (&&function_357);
  goto apply_addr;
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
    target = (&&function_358);
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
    target = (&&function_359);
    goto apply_addr;
  }
function_361:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c48 /* ___l_40 */);
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_360);
  goto apply_addr;
/* ____transform-statement */
body_139:
  increment_count(env);
  val = wrap_function((&&function_361), env);
  global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 = val; /* ____transform-statement */
  goto body_140;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_140:
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
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_141;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_141:
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
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_142;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_142:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_143;
pointer global_c95c111c114;
function_362:
  goto top_level_apply;
function_363:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_364:
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
  val = wrap_function((&&function_363), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_362);
  goto apply_addr;
/* _or */
body_143:
  increment_count(env);
  val = wrap_function((&&function_364), env);
  global_c95c111c114 = val; /* _or */
  goto body_144;
pointer global_c95c97c110c100;
function_365:
  goto top_level_apply;
function_366:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_367:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_symbol(-53);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_366), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_365);
  goto apply_addr;
/* _and */
body_144:
  increment_count(env);
  val = wrap_function((&&function_367), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_145;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_368:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_369:
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
    target = (&&function_368);
    goto apply_addr;
  }
function_370:
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
    target = (&&function_369);
    goto apply_addr;
  }
function_371:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_370);
  goto apply_addr;
/* _escape-char */
body_145:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_146;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* _parse-escaped-string */
pointer global_c102c110c95c52c57;
function_372:
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
function_373:
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
    target = (&&function_372);
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
    target = (&&function_372);
    goto apply_addr;
  }
function_374:
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
    target = (&&function_374);
    goto apply_addr;
  }
function_376:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_375);
  goto apply_addr;
function_377:
  increment_count(env);
  val = wrap_function((&&function_376), env);
  goto pop_function;
/* fn_49 */
body_146:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* _parse-string */
global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* _parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_377), env);
  global_c102c110c95c52c57 = val; /* fn_49 */
  goto body_147;
function_378:
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
body_147:
  increment_count(env);
  val = wrap_function((&&function_378), env);
  global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* _parse-escaped-string */
  goto body_148;
pointer global_c102c110c95c53c48;
function_379:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_380:
  args = cons(val, args);
  val = new_symbol(-52);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
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
function_382:
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
    target = (&&function_381);
    goto apply_addr;
  }
function_383:
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
    target = (&&function_380);
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
    target = (&&function_384);
    goto apply_addr;
  }
function_386:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_385);
  goto apply_addr;
function_387:
  increment_count(env);
  val = wrap_function((&&function_386), env);
  goto pop_function;
/* fn_50 */
body_148:
  increment_count(env);
  val = wrap_function((&&function_387), env);
  global_c102c110c95c53c48 = val; /* fn_50 */
  goto body_149;
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
  increment_count(val = global_c102c110c95c53c48 /* fn_50 */);
  goto top_level_apply;
/* _parse-string */
body_149:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_150;
pointer global_c95c115c107c105c112c45c108c105c110c101; /* _skip-line */
pointer global_c102c110c95c53c49;
function_389:
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
function_390:
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
    target = (&&function_389);
    goto apply_addr;
  }
function_391:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_390);
  goto apply_addr;
function_392:
  increment_count(env);
  val = wrap_function((&&function_391), env);
  goto pop_function;
/* fn_51 */
body_150:
global_c95c115c107c105c112c45c108c105c110c101 = nil(); /* _skip-line */
  increment_count(env);
  val = wrap_function((&&function_392), env);
  global_c102c110c95c53c49 = val; /* fn_51 */
  goto body_151;
function_393:
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
body_151:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  global_c95c115c107c105c112c45c108c105c110c101 = val; /* _skip-line */
  goto body_152;
pointer global_c95c112c97c114c115c101c45c110c117c109c98c101c114; /* _parse-number */
pointer global_c102c110c95c53c50;
function_394:
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
function_395:
  goto top_level_apply;
function_396:
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
    target = (&&function_395);
    goto apply_addr;
  }
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
      target = (&&function_394);
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
      target = (&&function_396);
      goto apply_addr;
    }
  }
function_398:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_397);
  goto apply_addr;
function_399:
  increment_count(env);
  val = wrap_function((&&function_398), env);
  goto pop_function;
/* fn_52 */
body_152:
global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* _parse-number */
  increment_count(env);
  val = wrap_function((&&function_399), env);
  global_c102c110c95c53c50 = val; /* fn_52 */
  goto body_153;
function_400:
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
body_153:
  increment_count(env);
  val = wrap_function((&&function_400), env);
  global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* _parse-number */
  goto body_154;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c53c51;
function_401:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_402:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_401);
  goto apply_addr;
function_403:
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
    target = (&&function_402);
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
    target = (&&function_402);
    goto apply_addr;
  }
function_404:
  goto top_level_apply;
function_405:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_404);
  goto apply_addr;
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
    target = (&&function_406);
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
function_408:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_407);
  goto apply_addr;
function_409:
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
  target = (&&function_408);
  goto apply_addr;
function_410:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_409);
  goto apply_addr;
function_411:
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
      target = (&&function_403);
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
      target = (&&function_410);
      goto apply_addr;
    }
  }
function_412:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_411);
  goto apply_addr;
function_413:
  increment_count(env);
  val = wrap_function((&&function_412), env);
  goto pop_function;
/* fn_53 */
body_154:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_413), env);
  global_c102c110c95c53c51 = val; /* fn_53 */
  goto body_155;
function_414:
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
body_155:
  increment_count(env);
  val = wrap_function((&&function_414), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_156;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c53c52;
function_415:
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
function_416:
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
    target = (&&function_415);
    goto apply_addr;
  }
function_417:
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
    target = (&&function_416);
    goto apply_addr;
  }
function_418:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_417);
  goto apply_addr;
function_419:
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
    target = (&&function_419);
    goto apply_addr;
  }
function_421:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_420);
  goto apply_addr;
function_422:
  increment_count(env);
  val = wrap_function((&&function_421), env);
  goto pop_function;
/* fn_54 */
body_156:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_422), env);
  global_c102c110c95c53c52 = val; /* fn_54 */
  goto body_157;
function_423:
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
body_157:
  increment_count(env);
  val = wrap_function((&&function_423), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_158;
pointer global_c102c110c95c53c53; /* fn_55 */
pointer global_c95c112c97c114c115c101c45c116c97c105c108; /* _parse-tail */
pointer global_c102c110c95c53c54;
function_424:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
  goto top_level_apply;
function_425:
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
  target = (&&function_424);
  goto apply_addr;
function_426:
  increment_count(env);
  val = wrap_function((&&function_425), env);
  goto pop_function;
/* fn_56 */
body_158:
global_c102c110c95c53c53 = nil(); /* fn_55 */
global_c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* _parse-tail */
  increment_count(env);
  val = wrap_function((&&function_426), env);
  global_c102c110c95c53c54 = val; /* fn_56 */
  goto body_159;
function_427:
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
function_428:
  increment_count(env);
  val = wrap_function((&&function_427), env);
  goto pop_function;
/* fn_55 */
body_159:
  increment_count(env);
  val = wrap_function((&&function_428), env);
  global_c102c110c95c53c53 = val; /* fn_55 */
  goto body_160;
pointer global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_429:
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
body_160:
  increment_count(env);
  val = wrap_function((&&function_429), env);
  global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* _parse-tail-cont */
  goto body_161;
pointer global_c102c110c95c53c56; /* fn_58 */
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c102c110c95c53c57;
function_430:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_431:
  goto top_level_apply;
function_432:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_431);
  goto apply_addr;
function_433:
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
    target = (&&function_430);
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
    target = (&&function_435);
    goto apply_addr;
  }
function_437:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_436);
  goto apply_addr;
function_438:
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
    target = (&&function_438);
    goto apply_addr;
  }
function_440:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_439);
  goto apply_addr;
function_441:
  increment_count(env);
  val = wrap_function((&&function_440), env);
  goto pop_function;
/* fn_59 */
body_161:
global_c102c110c95c53c56 = nil(); /* fn_58 */
global_c95c112c97c114c115c101c45c101c120c112c114 = nil(); /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_441), env);
  global_c102c110c95c53c57 = val; /* fn_59 */
  goto body_162;
pointer global_c102c110c95c53c55; /* fn_57 */
function_442:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
  goto top_level_apply;
function_443:
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
  target = (&&function_442);
  goto apply_addr;
function_444:
  increment_count(env);
  val = wrap_function((&&function_443), env);
  goto pop_function;
/* fn_58 */
body_162:
global_c102c110c95c53c55 = nil(); /* fn_57 */
  increment_count(env);
  val = wrap_function((&&function_444), env);
  global_c102c110c95c53c56 = val; /* fn_58 */
  goto body_163;
function_445:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_446:
  increment_count(env);
  val = wrap_function((&&function_445), env);
  goto pop_function;
/* fn_57 */
body_163:
  increment_count(env);
  val = wrap_function((&&function_446), env);
  global_c102c110c95c53c55 = val; /* fn_57 */
  goto body_164;
function_447:
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
body_164:
  increment_count(env);
  val = wrap_function((&&function_447), env);
  global_c95c112c97c114c115c101c45c116c97c105c108 = val; /* _parse-tail */
  goto body_165;
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c54c48;
function_448:
  goto top_level_apply;
function_449:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_448);
  goto apply_addr;
function_450:
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
    target = (&&function_449);
    goto apply_addr;
  }
function_451:
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
    target = (&&function_451);
    goto apply_addr;
  }
function_453:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_452);
  goto apply_addr;
function_454:
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
    target = (&&function_454);
    goto apply_addr;
  }
function_456:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_455);
  goto apply_addr;
function_457:
  increment_count(env);
  val = wrap_function((&&function_456), env);
  goto pop_function;
/* fn_60 */
body_165:
global_c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_457), env);
  global_c102c110c95c54c48 = val; /* fn_60 */
  goto body_166;
function_458:
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
body_166:
  increment_count(env);
  val = wrap_function((&&function_458), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_167;
pointer global_c102c110c95c54c51; /* fn_63 */
pointer global_c102c110c95c54c50; /* fn_62 */
pointer global_c102c110c95c54c49; /* fn_61 */
pointer global_c102c110c95c54c52;
function_459:
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
function_460:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
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
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
  goto top_level_apply;
function_464:
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
    increment_count(val = global_c102c110c95c54c51 /* fn_63 */);
    target = (&&function_462);
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
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c54c50 /* fn_62 */);
    target = (&&function_461);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c54c49 /* fn_61 */);
    target = (&&function_460);
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
    target = (&&function_471);
    goto apply_addr;
  }
function_473:
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
    target = (&&function_459);
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
    target = (&&function_472);
    goto apply_addr;
  }
function_474:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_473);
  goto apply_addr;
function_475:
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
    target = (&&function_474);
    goto apply_addr;
  }
function_476:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_475);
  goto apply_addr;
function_477:
  increment_count(env);
  val = wrap_function((&&function_476), env);
  goto pop_function;
/* fn_64 */
body_167:
global_c102c110c95c54c51 = nil(); /* fn_63 */
global_c102c110c95c54c50 = nil(); /* fn_62 */
global_c102c110c95c54c49 = nil(); /* fn_61 */
  increment_count(env);
  val = wrap_function((&&function_477), env);
  global_c102c110c95c54c52 = val; /* fn_64 */
  goto body_168;
function_478:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_479:
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
  val = new_symbol(-52);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_478);
  goto apply_addr;
function_480:
  increment_count(env);
  val = wrap_function((&&function_479), env);
  goto pop_function;
/* fn_61 */
body_168:
  increment_count(env);
  val = wrap_function((&&function_480), env);
  global_c102c110c95c54c49 = val; /* fn_61 */
  goto body_169;
function_481:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_482:
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
  target = (&&function_481);
  goto apply_addr;
function_483:
  increment_count(env);
  val = wrap_function((&&function_482), env);
  goto pop_function;
/* fn_62 */
body_169:
  increment_count(env);
  val = wrap_function((&&function_483), env);
  global_c102c110c95c54c50 = val; /* fn_62 */
  goto body_170;
function_484:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_485:
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
  target = (&&function_484);
  goto apply_addr;
function_486:
  increment_count(env);
  val = wrap_function((&&function_485), env);
  goto pop_function;
/* fn_63 */
body_170:
  increment_count(env);
  val = wrap_function((&&function_486), env);
  global_c102c110c95c54c51 = val; /* fn_63 */
  goto body_171;
function_487:
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
body_171:
  increment_count(env);
  val = wrap_function((&&function_487), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_172;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_488:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
  goto top_level_apply;
function_489:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c49 /* ___l_41 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_488);
  goto apply_addr;
function_490:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c51 /* ___l_43 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c50 /* ___l_42 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_489);
  goto apply_addr;
function_491:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_490), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
/* ____read-expr */
body_172:
  increment_count(env);
  val = wrap_function((&&function_491), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_173;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_173:
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
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_174;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_174:
  val = new_symbol(-40);
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_175;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_175:
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
  val = new_symbol(-37);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-41);
  push_args();
  args = val;
  val = new_symbol(-39);
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-41);
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-37);
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
  val = new_symbol(-44);
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
  val = nil();
  push_args();
  args = val;
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-45);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-37);
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
  val = new_symbol(-44);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-45);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-37);
  args = cons(val, args);
  val = new_symbol(-48);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-37);
  args = cons(val, args);
  val = new_symbol(-49);
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
  val = new_symbol(-44);
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  val = new_symbol(-40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_176;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_176:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_177;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_177:
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
  val = new_symbol(-35);
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-35);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  val = new_symbol(-38);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = nil();
  push_args();
  args = val;
  val = new_symbol(-37);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-36);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  args = cons(val, args);
  val = new_symbol(-39);
  args = cons(val, args);
  val = new_symbol(-40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_178;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_178:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
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
pointer global_c95c99c97c97c100c114;
function_492:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* _caadr */
body_182:
  increment_count(env);
  val = wrap_function((&&function_492), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_183;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101;
function_493:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_494:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c55 /* ___l_47 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c54 /* ___l_46 */);
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_493);
  goto apply_addr;
function_495:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c57 /* ___l_49 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c52c56 /* ___l_48 */);
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_494);
  goto apply_addr;
function_496:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_495);
  goto apply_addr;
function_497:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_498:
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
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c116c114c97c110c115c102c111c114c109c45c115c116c97c116c101c109c101c110c116 /* ____transform-statement */);
  target = (&&function_498);
  goto apply_addr;
function_500:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  target = (&&function_499);
  goto apply_addr;
function_501:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c49 /* ___l_51 */);
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
    target = (&&function_500);
    goto apply_addr;
  }
function_502:
  args = cons(val, args);
  increment_count(val = global_c95c97c110c100 /* _and */);
  target = (&&function_501);
  goto apply_addr;
function_503:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_502);
  goto apply_addr;
function_504:
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
  target = (&&function_503);
  goto apply_addr;
function_505:
  args = cons(val, args);
  increment_count(val = global_c95c95c112c97c105c114c63 /* __pair? */);
  target = (&&function_504);
  goto apply_addr;
function_506:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c53c48 /* ___l_50 */);
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
    target = (&&function_496);
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c99c97c97c100c114 /* _caadr */);
    target = (&&function_505);
    goto apply_addr;
  }
function_507:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_506);
  goto apply_addr;
function_508:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c52 /* ___l_44 */);
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
    increment_count(val = global_c95c95c95c108c95c52c53 /* ___l_45 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_507);
    goto apply_addr;
  }
function_509:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_508);
  goto apply_addr;
function_510:
  increment_count(env);
  val = wrap_function((&&function_509), env);
  goto pop_function;
/* ____compile-source */
body_183:
  increment_count(env);
  val = wrap_function((&&function_510), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
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
function_511:
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
function_512:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_513:
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
  target = (&&function_512);
  goto apply_addr;
body_184:
  increment_count(env);
  val = wrap_function((&&function_513), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_511), nil()), call_stack);
  goto body_0;
}
