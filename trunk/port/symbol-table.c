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
        val = new_number(109);
        args = cons(val, args);
        val = new_number(111);
        args = cons(val, args);
        val = new_number(116);
        args = cons(val, args);
        val = new_number(97);
        args = cons(val, args);
        val = new_number(95);
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
            val = new_number(61);
            args = cons(val, args);
            val = new_number(95);
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
                val = new_number(97);
                args = cons(val, args);
                val = new_number(117);
                args = cons(val, args);
                val = new_number(113);
                args = cons(val, args);
                val = new_number(101);
                args = cons(val, args);
                val = new_number(95);
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
                  val = new_number(95);
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
                      val = new_number(114);
                      args = cons(val, args);
                      val = new_number(105);
                      args = cons(val, args);
                      val = new_number(97);
                      args = cons(val, args);
                      val = new_number(112);
                      args = cons(val, args);
                      val = new_number(95);
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
  } else {
    push_args();
    val = nil();
    args = val;
    val = new_symbol(-51);
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
    val = new_symbol(-51);
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
    val = new_number(95);
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
    val = new_number(95);
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
    val = new_number(95);
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
    val = new_number(61);
    args = cons(val, args);
    val = new_number(95);
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
    val = new_number(61);
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
    val = new_number(109);
    args = cons(val, args);
    val = new_number(111);
    args = cons(val, args);
    val = new_number(116);
    args = cons(val, args);
    val = new_number(97);
    args = cons(val, args);
    val = new_number(95);
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
  target = (&&function_20);
  goto apply_addr;
/* _string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_21), env);
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_3;
pointer global_c95c95c115c121c109c98c111c108c63;
function_22:
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
          val = new_symbol(-51);
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
  val = wrap_function((&&function_22), env);
  global_c95c95c115c121c109c98c111c108c63 = val; /* __symbol? */
  goto body_4;
pointer global_c95c95c112c97c105c114c63;
function_23:
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
    val = new_symbol(-51);
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
  val = wrap_function((&&function_23), env);
  global_c95c95c112c97c105c114c63 = val; /* __pair? */
  goto body_5;
pointer global_c95c95c97c116c111c109;
function_24:
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
    val = new_symbol(-51);
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
  val = wrap_function((&&function_24), env);
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_6;
pointer global_c95c95c61;
function_25:
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
function_26:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_25);
  goto apply_addr;
/* __= */
body_6:
  increment_count(env);
  val = wrap_function((&&function_26), env);
  global_c95c95c61 = val; /* __= */
  goto body_7;
pointer global_c95c108c105c115c116;
function_27:
  increment_count(val = car(env));
  goto pop_function;
/* _list */
body_7:
  increment_count(env);
  val = wrap_function((&&function_27), env);
  global_c95c108c105c115c116 = val; /* _list */
  goto body_8;
pointer global_c95c114c114c101c118c101c114c115c101;
function_28:
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
function_29:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_28);
  goto apply_addr;
/* _rreverse */
body_8:
  increment_count(env);
  val = wrap_function((&&function_29), env);
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_9;
pointer global_c95c102c111c108c100c108; /* _foldl */
pointer global_c102c110c95c48;
function_30:
  goto top_level_apply;
function_31:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108 /* _foldl */);
  target = (&&function_30);
  goto apply_addr;
function_32:
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
    target = (&&function_31);
    goto apply_addr;
  }
function_33:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_32);
  goto apply_addr;
function_34:
  increment_count(env);
  val = wrap_function((&&function_33), env);
  goto pop_function;
/* fn_0 */
body_9:
global_c95c102c111c108c100c108 = nil(); /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_34), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_10;
function_35:
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
  val = wrap_function((&&function_35), env);
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_11;
pointer global_c102c110c95c49;
function_36:
  args = cons(val, args);
  val = nil();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101 /* _rreverse */);
  goto top_level_apply;
function_37:
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
  target = (&&function_36);
  goto apply_addr;
function_38:
  increment_count(env);
  val = wrap_function((&&function_37), env);
  goto pop_function;
/* fn_1 */
body_11:
  increment_count(env);
  val = wrap_function((&&function_38), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_12;
pointer global_c95c102c111c108c100c114;
function_39:
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
  val = wrap_function((&&function_39), env);
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_13;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_40:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_14;
function_41:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_42:
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
  target = (&&function_41);
  goto apply_addr;
/* ____map-to-stderr */
body_13:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_42), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_40);
  goto apply_addr;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_14:
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
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_15;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_15:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_16;
pointer global_c95c97c112c112c101c110c100;
function_43:
  goto top_level_apply;
function_44:
  goto top_level_apply;
function_45:
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
function_46:
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
    val = wrap_function((&&function_45), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
    target = (&&function_44);
    goto apply_addr;
  }
function_47:
  push_args();
  val = nil();
  args = val;
  val = nil();
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_46);
  goto apply_addr;
function_48:
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
  val = wrap_function((&&function_47), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_43);
  goto apply_addr;
/* _append */
body_16:
  increment_count(env);
  val = wrap_function((&&function_48), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_17;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_49:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 /* ____map-to-stderr */);
  goto top_level_apply;
function_50:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c53 /* ___l_5 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52 /* ___l_4 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_49);
  goto apply_addr;
/* ____print-error */
body_17:
  increment_count(env);
  val = wrap_function((&&function_50), env);
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_18;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_18:
  val = nil();
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_19;
pointer global_c95c95c101c113c117c97c108;
function_51:
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
function_52:
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
    target = (&&function_51);
    goto apply_addr;
  }
function_53:
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
    target = (&&function_52);
    goto apply_addr;
  }
function_54:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_53);
  goto apply_addr;
/* __equal */
body_19:
  increment_count(env);
  val = wrap_function((&&function_54), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_20;
pointer global_c95c109c101c109c98c101c114;
function_55:
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
function_56:
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
    target = (&&function_55);
    goto apply_addr;
  }
function_57:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_56);
  goto apply_addr;
/* _member */
body_20:
  increment_count(env);
  val = wrap_function((&&function_57), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_21;
pointer global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101;
function_58:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 /* ____generate-unused-symbol-name */);
  goto top_level_apply;
function_59:
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
    increment_count(val = global_c95c95c95c108c95c54 /* ___l_6 */);
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    target = (&&function_58);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_60:
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
  target = (&&function_59);
  goto apply_addr;
function_61:
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
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_60);
  goto apply_addr;
/* ____generate-unused-symbol-name */
body_21:
  increment_count(env);
  val = wrap_function((&&function_61), env);
  global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____generate-unused-symbol-name */
  goto body_22;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_22:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_23;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_23:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_24;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_24:
  val = nil();
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_25;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_25:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_26;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_26:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_27;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_27:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_28;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_28:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_29;
pointer global_c95c105c100;
function_62:
  increment_count(val = car(car(env)));
  goto pop_function;
/* _id */
body_29:
  increment_count(env);
  val = wrap_function((&&function_62), env);
  global_c95c105c100 = val; /* _id */
  goto body_30;
pointer global_c95c119c97c108c107; /* _walk */
pointer global_c102c110c95c50;
function_63:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_64:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_63);
  goto apply_addr;
function_65:
  target = (&&function_64);
  goto apply_addr;
function_66:
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
  target = (&&function_65);
  goto apply_addr;
function_67:
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
    target = (&&function_66);
    goto apply_addr;
  }
function_68:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_67);
  goto apply_addr;
function_69:
  increment_count(env);
  val = wrap_function((&&function_68), env);
  goto pop_function;
/* fn_2 */
body_30:
global_c95c119c97c108c107 = nil(); /* _walk */
  increment_count(env);
  val = wrap_function((&&function_69), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_31;
function_70:
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
body_31:
  increment_count(env);
  val = wrap_function((&&function_70), env);
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_32;
pointer global_c102c110c95c51;
function_71:
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
function_72:
  increment_count(env);
  val = wrap_function((&&function_71), env);
  goto pop_function;
/* fn_3 */
body_32:
  increment_count(env);
  val = wrap_function((&&function_72), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_33;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_73:
  goto top_level_apply;
function_74:
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
function_75:
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
function_76:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  goto top_level_apply;
function_77:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51 /* fn_3 */);
  goto top_level_apply;
function_78:
  increment_count(val = global_c95c105c100 /* _id */);
  goto pop_function;
function_79:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
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
  increment_count(val = global_c95c119c97c108c107 /* _walk */);
  target = (&&function_73);
  goto apply_addr;
/* _build-num-str */
body_33:
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_34;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_80:
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
function_81:
  target = (&&function_80);
  goto apply_addr;
function_82:
  goto top_level_apply;
function_83:
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
      target = (&&function_81);
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
      target = (&&function_82);
      goto apply_addr;
    }
  }
function_84:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_83);
  goto apply_addr;
/* _print-num */
body_34:
  increment_count(env);
  val = wrap_function((&&function_84), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_35;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_85:
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
function_86:
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
      target = (&&function_85);
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
body_35:
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_36;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_87:
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
function_88:
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
function_89:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_88);
  goto apply_addr;
function_90:
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
    target = (&&function_87);
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
    target = (&&function_89);
    goto apply_addr;
  }
function_91:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_90);
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
body_36:
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = nil(); /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_91), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_37;
function_92:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_93:
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
function_94:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 /* _print-with-suffix */);
  target = (&&function_93);
  goto apply_addr;
function_95:
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
    target = (&&function_92);
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
    target = (&&function_94);
    goto apply_addr;
  }
function_96:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_95);
  goto apply_addr;
/* _print-with-suffix */
body_37:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_38;
pointer global_c95c112c114c105c110c116;
function_97:
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
body_38:
  increment_count(env);
  val = wrap_function((&&function_97), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_39;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115; /* ____build-string->symbol-cases */
pointer global_c102c110c95c52;
function_98:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c49 /* ___l_11 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48 /* ___l_10 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57 /* ___l_9 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_99:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = cdr(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 /* ____build-string->symbol-cases */);
  target = (&&function_98);
  goto apply_addr;
function_100:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50 /* ___l_12 */);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_99);
  goto apply_addr;
function_101:
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
  increment_count(val = global_c95c95c95c108c95c49c51 /* ___l_13 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_100);
  goto apply_addr;
function_102:
  increment_count(env);
  val = wrap_function((&&function_101), env);
  goto pop_function;
/* fn_4 */
body_39:
global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = nil(); /* ____build-string->symbol-cases */
  increment_count(env);
  val = wrap_function((&&function_102), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_40;
function_103:
  goto top_level_apply;
function_104:
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
  increment_count(val = global_c102c110c95c52 /* fn_4 */);
  target = (&&function_103);
  goto apply_addr;
function_105:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56 /* ___l_8 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55 /* ___l_7 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116 /* _print */);
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
/* ____build-string->symbol-cases */
body_40:
  increment_count(env);
  val = wrap_function((&&function_106), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = val; /* ____build-string->symbol-cases */
  goto body_41;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_41:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_42;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_42:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(115);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(104);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_43;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_43:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_44;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_44:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_45;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_107:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c53 /* ___l_15 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c52 /* ___l_14 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_108:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55 /* ___l_17 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54 /* ___l_16 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 /* ____build-string->symbol-cases */);
  target = (&&function_107);
  goto apply_addr;
/* ____build-string->symbol */
body_45:
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* ____build-string->symbol */
  goto body_46;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_46:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_47;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_47:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_48;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_48:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_49;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_49:
  val = nil();
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_50;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_50:
  val = nil();
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_51;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_51:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_52;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_52:
  val = nil();
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_53;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115; /* ____build-symbol->string-cases */
pointer global_c102c110c95c53;
function_109:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50 /* ___l_22 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49 /* ___l_21 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48 /* ___l_20 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c57 /* ___l_19 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_110:
  args = cons(val, args);
  increment_count(val = cdr(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 /* ____build-symbol->string-cases */);
  target = (&&function_109);
  goto apply_addr;
function_111:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c51 /* ___l_23 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_110);
  goto apply_addr;
function_112:
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
  increment_count(val = global_c95c95c95c108c95c50c52 /* ___l_24 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_111);
  goto apply_addr;
function_113:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  goto pop_function;
/* fn_5 */
body_53:
global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = nil(); /* ____build-symbol->string-cases */
  increment_count(env);
  val = wrap_function((&&function_113), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_54;
function_114:
  goto top_level_apply;
function_115:
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
  increment_count(val = global_c102c110c95c53 /* fn_5 */);
  target = (&&function_114);
  goto apply_addr;
function_116:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56 /* ___l_18 */);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
    goto top_level_apply;
  } else {
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116 /* _print */);
    target = (&&function_115);
    goto apply_addr;
  }
function_117:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_116);
  goto apply_addr;
/* ____build-symbol->string-cases */
body_54:
  increment_count(env);
  val = wrap_function((&&function_117), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = val; /* ____build-symbol->string-cases */
  goto body_55;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_55:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_56;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_56:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_57;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_57:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_58;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_58:
  val = nil();
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_59;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_59:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_60;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_60:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_61;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_61:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_62;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_62:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_63;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_63:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_64;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
function_118:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c55 /* ___l_27 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c54 /* ___l_26 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c53 /* ___l_25 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_119:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c51 /* ___l_33 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c50 /* ___l_32 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c49 /* ___l_31 */);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48 /* ___l_30 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57 /* ___l_29 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56 /* ___l_28 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 /* ____build-symbol->string-cases */);
  target = (&&function_118);
  goto apply_addr;
/* ____build-symbol->string */
body_64:
  increment_count(env);
  val = wrap_function((&&function_119), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* ____build-symbol->string */
  goto body_65;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115; /* ____escape-symbols */
pointer global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115;
function_120:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_121:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_120);
  goto apply_addr;
function_122:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 /* ____escape-args */);
    target = (&&function_121);
    goto apply_addr;
  }
function_123:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_122);
  goto apply_addr;
/* ____escape-args */
body_65:
global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = nil(); /* ____escape-symbols */
  increment_count(env);
  val = wrap_function((&&function_123), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 = val; /* ____escape-args */
  goto body_66;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_66:
  val = new_symbol(-50);
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_67;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_67:
  val = new_symbol(-49);
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_68;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_68:
  val = new_symbol(-48);
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_69;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_69:
  val = new_symbol(-47);
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_70;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_70:
  val = new_symbol(-46);
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_71;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_71:
  val = new_symbol(-45);
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_72;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_72:
  val = new_symbol(-39);
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_73;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_73:
  val = new_symbol(-44);
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_74;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_74:
  val = new_symbol(-43);
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_75;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_75:
  val = new_symbol(-42);
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_76;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_76:
  val = new_symbol(-37);
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_77;
function_124:
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
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  goto top_level_apply;
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
  args = cons(val, args);
  if (is_unary(args)) {
    if (is_pair(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = nil(); }
  } else { val = nil(); }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_125);
  goto apply_addr;
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 /* ____escape-args */);
    goto top_level_apply;
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
    increment_count(val = global_c95c95c95c108c95c52c52 /* ___l_44 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_127);
    goto apply_addr;
  }
function_129:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    val = new_number(95);
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* _symbol->string */);
    target = (&&function_126);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_128);
    goto apply_addr;
  }
function_130:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c51 /* ___l_43 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
    target = (&&function_129);
    goto apply_addr;
  }
function_131:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c52c49 /* ___l_41 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c50 /* ___l_42 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_130);
    goto apply_addr;
  }
function_132:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c57 /* ___l_39 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c48 /* ___l_40 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_131);
    goto apply_addr;
  }
function_133:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c55 /* ___l_37 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c56 /* ___l_38 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_132);
    goto apply_addr;
  }
function_134:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c53 /* ___l_35 */);
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c54 /* ___l_36 */);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_133);
    goto apply_addr;
  }
function_135:
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52 /* ___l_34 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_134);
  goto apply_addr;
/* ____escape-symbols */
body_77:
  increment_count(env);
  val = wrap_function((&&function_135), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_78;
pointer global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115;
function_136:
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
function_137:
  args = cons(val, args);
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 /* ____list-symbols */);
  goto top_level_apply;
function_138:
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 /* ____list-symbols */);
    target = (&&function_137);
    goto apply_addr;
  }
function_139:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
    target = (&&function_136);
    goto apply_addr;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
    target = (&&function_138);
    goto apply_addr;
  }
function_140:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c115c121c109c98c111c108c63 /* __symbol? */);
  target = (&&function_139);
  goto apply_addr;
/* ____list-symbols */
body_78:
  increment_count(env);
  val = wrap_function((&&function_140), env);
  global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 = val; /* ____list-symbols */
  goto body_79;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_79:
  val = new_symbol(-37);
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_80;
pointer global_c95c99c97c100c114;
function_141:
  increment_count(val = car(cdr(car(car(env)))));
  goto pop_function;
/* _cadr */
body_80:
  increment_count(env);
  val = wrap_function((&&function_141), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_81;
pointer global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115;
function_142:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 /* ____list-symbols */);
  goto top_level_apply;
function_143:
  goto top_level_apply;
function_144:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 /* ____find-quoted-symbols */);
  goto top_level_apply;
function_145:
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
    increment_count(val = global_c95c99c97c100c114 /* _cadr */);
    target = (&&function_142);
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(env);
    val = wrap_function((&&function_144), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
    target = (&&function_143);
    goto apply_addr;
  }
function_146:
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c52c53 /* ___l_45 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_145);
    goto apply_addr;
  }
function_147:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_146);
  goto apply_addr;
/* ____find-quoted-symbols */
body_81:
  increment_count(env);
  val = wrap_function((&&function_147), env);
  global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 = val; /* ____find-quoted-symbols */
  goto body_82;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_82:
  val = new_symbol(-41);
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_83;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_83:
  val = new_symbol(-40);
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_84;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_84:
  val = new_symbol(-39);
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_85;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_85:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_86;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_86:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_87;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_87:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_88;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_88:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_89;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_89:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_90;
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
body_90:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  goto body_91;
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
body_91:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  goto body_92;
pointer global_c95c95c95c108c95c53c54;
/* ___l_56 */
body_92:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c54 = val; /* ___l_56 */
  goto body_93;
pointer global_c95c95c95c108c95c53c55;
/* ___l_57 */
body_93:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c55 = val; /* ___l_57 */
  goto body_94;
pointer global_c95c95c95c108c95c53c56;
/* ___l_58 */
body_94:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
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
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c56 = val; /* ___l_58 */
  goto body_95;
pointer global_c95c95c95c108c95c53c57;
/* ___l_59 */
body_95:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c53c57 = val; /* ___l_59 */
  goto body_96;
pointer global_c95c95c95c108c95c54c48;
/* ___l_60 */
body_96:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
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
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c48 = val; /* ___l_60 */
  goto body_97;
pointer global_c95c95c95c108c95c54c49;
/* ___l_61 */
body_97:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c49 = val; /* ___l_61 */
  goto body_98;
pointer global_c95c95c95c108c95c54c50;
/* ___l_62 */
body_98:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c50 = val; /* ___l_62 */
  goto body_99;
pointer global_c95c95c95c108c95c54c51;
/* ___l_63 */
body_99:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c51 = val; /* ___l_63 */
  goto body_100;
pointer global_c95c95c95c108c95c54c52;
/* ___l_64 */
body_100:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c52 = val; /* ___l_64 */
  goto body_101;
pointer global_c95c95c95c108c95c54c53;
/* ___l_65 */
body_101:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c53 = val; /* ___l_65 */
  goto body_102;
pointer global_c95c95c95c108c95c54c54;
/* ___l_66 */
body_102:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c54 = val; /* ___l_66 */
  goto body_103;
pointer global_c95c95c95c108c95c54c55;
/* ___l_67 */
body_103:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c55 = val; /* ___l_67 */
  goto body_104;
pointer global_c95c95c95c108c95c54c56;
/* ___l_68 */
body_104:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c56 = val; /* ___l_68 */
  goto body_105;
pointer global_c95c95c95c108c95c54c57;
/* ___l_69 */
body_105:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c54c57 = val; /* ___l_69 */
  goto body_106;
pointer global_c95c95c95c108c95c55c48;
/* ___l_70 */
body_106:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c48 = val; /* ___l_70 */
  goto body_107;
pointer global_c95c95c95c108c95c55c49;
/* ___l_71 */
body_107:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c49 = val; /* ___l_71 */
  goto body_108;
pointer global_c95c95c95c108c95c55c50;
/* ___l_72 */
body_108:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
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
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c50 = val; /* ___l_72 */
  goto body_109;
pointer global_c95c95c95c108c95c55c51;
/* ___l_73 */
body_109:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c51 = val; /* ___l_73 */
  goto body_110;
pointer global_c95c95c95c108c95c55c52;
/* ___l_74 */
body_110:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c52 = val; /* ___l_74 */
  goto body_111;
pointer global_c95c95c95c108c95c55c53;
/* ___l_75 */
body_111:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c53 = val; /* ___l_75 */
  goto body_112;
pointer global_c95c95c95c108c95c55c54;
/* ___l_76 */
body_112:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c54 = val; /* ___l_76 */
  goto body_113;
pointer global_c95c95c95c108c95c55c55;
/* ___l_77 */
body_113:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c55 = val; /* ___l_77 */
  goto body_114;
pointer global_c95c95c95c108c95c55c56;
/* ___l_78 */
body_114:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c56 = val; /* ___l_78 */
  goto body_115;
pointer global_c95c95c95c108c95c55c57;
/* ___l_79 */
body_115:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c55c57 = val; /* ___l_79 */
  goto body_116;
pointer global_c95c95c95c108c95c56c48;
/* ___l_80 */
body_116:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c48 = val; /* ___l_80 */
  goto body_117;
pointer global_c95c95c95c108c95c56c49;
/* ___l_81 */
body_117:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(114);
  args = cons(val, args);
  val = new_number(112);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c49 = val; /* ___l_81 */
  goto body_118;
pointer global_c95c95c95c108c95c56c50;
/* ___l_82 */
body_118:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c50 = val; /* ___l_82 */
  goto body_119;
pointer global_c95c95c95c108c95c56c51;
/* ___l_83 */
body_119:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c51 = val; /* ___l_83 */
  goto body_120;
pointer global_c95c95c95c108c95c56c52;
/* ___l_84 */
body_120:
  val = nil();
  push_args();
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(114);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(99);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c52 = val; /* ___l_84 */
  goto body_121;
pointer global_c95c95c95c108c95c56c53;
/* ___l_85 */
body_121:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c53 = val; /* ___l_85 */
  goto body_122;
pointer global_c95c95c95c108c95c56c54;
/* ___l_86 */
body_122:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c54 = val; /* ___l_86 */
  goto body_123;
pointer global_c95c95c95c108c95c56c55;
/* ___l_87 */
body_123:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c55 = val; /* ___l_87 */
  goto body_124;
pointer global_c95c95c95c108c95c56c56;
/* ___l_88 */
body_124:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c56 = val; /* ___l_88 */
  goto body_125;
pointer global_c95c95c95c108c95c56c57;
/* ___l_89 */
body_125:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(110);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c56c57 = val; /* ___l_89 */
  goto body_126;
pointer global_c95c95c95c108c95c57c48;
/* ___l_90 */
body_126:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(102);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57c48 = val; /* ___l_90 */
  goto body_127;
pointer global_c95c95c95c108c95c57c49;
/* ___l_91 */
body_127:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(121);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(120);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57c49 = val; /* ___l_91 */
  goto body_128;
pointer global_c95c95c95c108c95c57c50;
/* ___l_92 */
body_128:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57c50 = val; /* ___l_92 */
  goto body_129;
pointer global_c95c95c95c108c95c57c51;
/* ___l_93 */
body_129:
  val = nil();
  global_c95c95c95c108c95c57c51 = val; /* ___l_93 */
  goto body_130;
pointer global_c95c95c95c108c95c57c52;
/* ___l_94 */
body_130:
  val = nil();
  push_args();
  args = val;
  val = new_number(103);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
  val = new_number(116);
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
  global_c95c95c95c108c95c57c52 = val; /* ___l_94 */
  goto body_131;
pointer global_c95c97c112c112c108c121;
function_148:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* _apply */
body_131:
  increment_count(env);
  val = wrap_function((&&function_148), env);
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_132;
pointer global_c102c110c95c54;
function_149:
  args = cons(val, args);
  if (is_binary(args)) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = nil(); }
  pop_args();
  goto pop_function;
function_150:
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
  target = (&&function_149);
  goto apply_addr;
function_151:
  increment_count(env);
  val = wrap_function((&&function_150), env);
  goto pop_function;
/* fn_6 */
body_132:
  increment_count(env);
  val = wrap_function((&&function_151), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_133;
pointer global_c95c109c97c112;
function_152:
  goto top_level_apply;
function_153:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_152);
  goto apply_addr;
function_154:
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
  increment_count(val = global_c102c110c95c54 /* fn_6 */);
  target = (&&function_153);
  goto apply_addr;
/* _map */
body_133:
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c95c109c97c112 = val; /* _map */
  goto body_134;
pointer global_c95c111c114;
function_155:
  goto top_level_apply;
function_156:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_157:
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
  val = wrap_function((&&function_156), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_155);
  goto apply_addr;
/* _or */
body_134:
  increment_count(env);
  val = wrap_function((&&function_157), env);
  global_c95c111c114 = val; /* _or */
  goto body_135;
pointer global_c102c110c95c55; /* fn_7 */
pointer global_c102c110c95c56;
function_158:
  goto top_level_apply;
function_159:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55 /* fn_7 */);
  target = (&&function_158);
  goto apply_addr;
function_160:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c57c51 /* ___l_93 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 /* ____find-quoted-symbols */);
  target = (&&function_159);
  goto apply_addr;
function_161:
  increment_count(env);
  val = wrap_function((&&function_160), env);
  goto pop_function;
/* fn_8 */
body_135:
global_c102c110c95c55 = nil(); /* fn_7 */
  increment_count(env);
  val = wrap_function((&&function_161), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_136;
function_162:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c55 /* ___l_57 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c54 /* ___l_56 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c53 /* ___l_55 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c52 /* ___l_54 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c51 /* ___l_53 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c50 /* ___l_52 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c49 /* ___l_51 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c48 /* ___l_50 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c57 /* ___l_49 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_163:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103 /* ____build-symbol->string */);
  target = (&&function_162);
  goto apply_addr;
function_164:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57c50 /* ___l_92 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57c49 /* ___l_91 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57c48 /* ___l_90 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c57 /* ___l_89 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c56 /* ___l_88 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c55 /* ___l_87 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c54 /* ___l_86 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c53 /* ___l_85 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c52 /* ___l_84 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c51 /* ___l_83 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c50 /* ___l_82 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c49 /* ___l_81 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c48 /* ___l_80 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c57 /* ___l_79 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c56 /* ___l_78 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c55 /* ___l_77 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c54 /* ___l_76 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c53 /* ___l_75 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c52 /* ___l_74 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c51 /* ___l_73 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c50 /* ___l_72 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c49 /* ___l_71 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c48 /* ___l_70 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c57 /* ___l_69 */);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c56 /* ___l_68 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c55 /* ___l_67 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c54 /* ___l_66 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c53 /* ___l_65 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c52 /* ___l_64 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c51 /* ___l_63 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c50 /* ___l_62 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c49 /* ___l_61 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c48 /* ___l_60 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c57 /* ___l_59 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c56 /* ___l_58 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* ____build-string->symbol */);
  target = (&&function_163);
  goto apply_addr;
function_165:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121 /* _apply */);
  target = (&&function_164);
  goto apply_addr;
function_166:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_165);
  goto apply_addr;
function_167:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_166);
  goto apply_addr;
function_168:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_167);
  goto apply_addr;
function_169:
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
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 /* ____escape-symbols */);
  target = (&&function_168);
  goto apply_addr;
function_170:
  increment_count(env);
  val = wrap_function((&&function_169), env);
  goto pop_function;
/* fn_7 */
body_136:
  increment_count(env);
  val = wrap_function((&&function_170), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_137;
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
function_171:
  goto top_level_apply;
function_172:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56 /* fn_8 */);
  target = (&&function_171);
  goto apply_addr;
function_173:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  goto top_level_apply;
function_174:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121 /* _apply */);
  target = (&&function_173);
  goto apply_addr;
function_175:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112 /* _map */);
  target = (&&function_174);
  goto apply_addr;
function_176:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c52 /* ___l_94 */);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 /* ____generate-unused-symbol-name */);
    target = (&&function_172);
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
    increment_count(val = global_c95c112c114c105c110c116 /* _print */);
    target = (&&function_175);
    goto apply_addr;
  }
function_177:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_176);
  goto apply_addr;
function_178:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c54 /* ___l_46 */);
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
  target = (&&function_177);
  goto apply_addr;
function_179:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c55 /* ___l_47 */);
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
  target = (&&function_178);
  goto apply_addr;
function_180:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c56 /* ___l_48 */);
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114 /* _member */);
  target = (&&function_179);
  goto apply_addr;
/* ____compile */
body_137:
  increment_count(env);
  val = wrap_function((&&function_180), env);
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  goto body_138;
pointer global_c95c95c95c108c95c57c53;
/* ___l_95 */
body_138:
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
  global_c95c95c95c108c95c57c53 = val; /* ___l_95 */
  goto body_139;
pointer global_c95c95c95c108c95c57c54;
/* ___l_96 */
body_139:
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
  global_c95c95c95c108c95c57c54 = val; /* ___l_96 */
  goto body_140;
pointer global_c95c95c95c108c95c57c55;
/* ___l_97 */
body_140:
  val = nil();
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = nil();
  pop_args();
  global_c95c95c95c108c95c57c55 = val; /* ___l_97 */
  goto body_141;
pointer global_c95c114c101c118c101c114c115c101;
function_181:
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
body_141:
  increment_count(env);
  val = wrap_function((&&function_181), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_142;
pointer global_c95c97c110c100;
function_182:
  goto top_level_apply;
function_183:
  increment_count(val = car(car(env)));
  if (! is_nil(val)) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = nil();
    goto pop_function;
  }
function_184:
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
  val = wrap_function((&&function_183), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114 /* _foldr */);
  target = (&&function_182);
  goto apply_addr;
/* _and */
body_142:
  increment_count(env);
  val = wrap_function((&&function_184), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_143;
pointer global_c95c110c111c116;
function_185:
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
body_143:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_144;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_186:
  if (! is_nil(val)) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_187:
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
    target = (&&function_186);
    goto apply_addr;
  }
function_188:
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
    target = (&&function_187);
    goto apply_addr;
  }
function_189:
  push_args();
  val = nil();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_188);
  goto apply_addr;
/* _escape-char */
body_144:
  increment_count(env);
  val = wrap_function((&&function_189), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_145;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103; /* _parse-string */
pointer global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103; /* _parse-escaped-string */
pointer global_c102c110c95c57;
function_190:
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
function_191:
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
    target = (&&function_190);
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
    target = (&&function_190);
    goto apply_addr;
  }
function_192:
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
    target = (&&function_191);
    goto apply_addr;
  }
function_193:
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
    target = (&&function_192);
    goto apply_addr;
  }
function_194:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_193);
  goto apply_addr;
function_195:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  goto pop_function;
/* fn_9 */
body_145:
global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = nil(); /* _parse-string */
global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = nil(); /* _parse-escaped-string */
  increment_count(env);
  val = wrap_function((&&function_195), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_146;
function_196:
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
  increment_count(val = global_c102c110c95c57 /* fn_9 */);
  goto top_level_apply;
/* _parse-escaped-string */
body_146:
  increment_count(env);
  val = wrap_function((&&function_196), env);
  global_c95c112c97c114c115c101c45c101c115c99c97c112c101c100c45c115c116c114c105c110c103 = val; /* _parse-escaped-string */
  goto body_147;
pointer global_c102c110c95c49c48;
function_197:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_198:
  args = cons(val, args);
  val = new_symbol(-37);
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116 /* _list */);
  target = (&&function_197);
  goto apply_addr;
function_199:
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
function_200:
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
    target = (&&function_199);
    goto apply_addr;
  }
function_201:
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
    target = (&&function_198);
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
    target = (&&function_200);
    goto apply_addr;
  }
function_202:
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
    target = (&&function_201);
    goto apply_addr;
  }
function_203:
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
    target = (&&function_202);
    goto apply_addr;
  }
function_204:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_203);
  goto apply_addr;
function_205:
  increment_count(env);
  val = wrap_function((&&function_204), env);
  goto pop_function;
/* fn_10 */
body_147:
  increment_count(env);
  val = wrap_function((&&function_205), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_148;
function_206:
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
  increment_count(val = global_c102c110c95c49c48 /* fn_10 */);
  goto top_level_apply;
/* _parse-string */
body_148:
  increment_count(env);
  val = wrap_function((&&function_206), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_149;
pointer global_c95c115c107c105c112c45c108c105c110c101; /* _skip-line */
pointer global_c102c110c95c49c49;
function_207:
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
function_208:
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
    target = (&&function_207);
    goto apply_addr;
  }
function_209:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_208);
  goto apply_addr;
function_210:
  increment_count(env);
  val = wrap_function((&&function_209), env);
  goto pop_function;
/* fn_11 */
body_149:
global_c95c115c107c105c112c45c108c105c110c101 = nil(); /* _skip-line */
  increment_count(env);
  val = wrap_function((&&function_210), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_150;
function_211:
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
  increment_count(val = global_c102c110c95c49c49 /* fn_11 */);
  goto top_level_apply;
/* _skip-line */
body_150:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  global_c95c115c107c105c112c45c108c105c110c101 = val; /* _skip-line */
  goto body_151;
pointer global_c95c112c97c114c115c101c45c110c117c109c98c101c114; /* _parse-number */
pointer global_c102c110c95c49c50;
function_212:
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
function_213:
  goto top_level_apply;
function_214:
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
    target = (&&function_213);
    goto apply_addr;
  }
function_215:
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
      target = (&&function_212);
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
      target = (&&function_214);
      goto apply_addr;
    }
  }
function_216:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_215);
  goto apply_addr;
function_217:
  increment_count(env);
  val = wrap_function((&&function_216), env);
  goto pop_function;
/* fn_12 */
body_151:
global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = nil(); /* _parse-number */
  increment_count(env);
  val = wrap_function((&&function_217), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_152;
function_218:
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
  increment_count(val = global_c102c110c95c49c50 /* fn_12 */);
  goto top_level_apply;
/* _parse-number */
body_152:
  increment_count(env);
  val = wrap_function((&&function_218), env);
  global_c95c112c97c114c115c101c45c110c117c109c98c101c114 = val; /* _parse-number */
  goto body_153;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108; /* _parse-symbol */
pointer global_c102c110c95c49c51;
function_219:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  goto top_level_apply;
function_220:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_219);
  goto apply_addr;
function_221:
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
    target = (&&function_220);
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
    target = (&&function_220);
    goto apply_addr;
  }
function_222:
  goto top_level_apply;
function_223:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_222);
  goto apply_addr;
function_224:
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 /* _string->symbol */);
  target = (&&function_223);
  goto apply_addr;
function_225:
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
    target = (&&function_224);
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
function_226:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_225);
  goto apply_addr;
function_227:
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
  target = (&&function_226);
  goto apply_addr;
function_228:
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_227);
  goto apply_addr;
function_229:
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
      target = (&&function_221);
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
      target = (&&function_228);
      goto apply_addr;
    }
  }
function_230:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_229);
  goto apply_addr;
function_231:
  increment_count(env);
  val = wrap_function((&&function_230), env);
  goto pop_function;
/* fn_13 */
body_153:
global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = nil(); /* _parse-symbol */
  increment_count(env);
  val = wrap_function((&&function_231), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_154;
function_232:
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
  increment_count(val = global_c102c110c95c49c51 /* fn_13 */);
  goto top_level_apply;
/* _parse-symbol */
body_154:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_155;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110; /* _parse-paren */
pointer global_c102c110c95c49c52;
function_233:
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
function_234:
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
    target = (&&function_233);
    goto apply_addr;
  }
function_235:
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
    target = (&&function_234);
    goto apply_addr;
  }
function_236:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_235);
  goto apply_addr;
function_237:
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
    target = (&&function_236);
    goto apply_addr;
  }
function_238:
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
    target = (&&function_237);
    goto apply_addr;
  }
function_239:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_238);
  goto apply_addr;
function_240:
  increment_count(env);
  val = wrap_function((&&function_239), env);
  goto pop_function;
/* fn_14 */
body_155:
global_c95c112c97c114c115c101c45c112c97c114c101c110 = nil(); /* _parse-paren */
  increment_count(env);
  val = wrap_function((&&function_240), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_156;
function_241:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52 /* fn_14 */);
  goto top_level_apply;
/* _parse-paren */
body_156:
  increment_count(env);
  val = wrap_function((&&function_241), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_157;
pointer global_c102c110c95c49c53; /* fn_15 */
pointer global_c95c112c97c114c115c101c45c116c97c105c108; /* _parse-tail */
pointer global_c102c110c95c49c54;
function_242:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c116c97c105c108 /* _parse-tail */);
  goto top_level_apply;
function_243:
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
  increment_count(val = global_c102c110c95c49c53 /* fn_15 */);
  target = (&&function_242);
  goto apply_addr;
function_244:
  increment_count(env);
  val = wrap_function((&&function_243), env);
  goto pop_function;
/* fn_16 */
body_157:
global_c102c110c95c49c53 = nil(); /* fn_15 */
global_c95c112c97c114c115c101c45c116c97c105c108 = nil(); /* _parse-tail */
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_158;
function_245:
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
function_246:
  increment_count(env);
  val = wrap_function((&&function_245), env);
  goto pop_function;
/* fn_15 */
body_158:
  increment_count(env);
  val = wrap_function((&&function_246), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_159;
pointer global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116;
function_247:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c54 /* fn_16 */);
  goto top_level_apply;
/* _parse-tail-cont */
body_159:
  increment_count(env);
  val = wrap_function((&&function_247), env);
  global_c95c112c97c114c115c101c45c116c97c105c108c45c99c111c110c116 = val; /* _parse-tail-cont */
  goto body_160;
pointer global_c102c110c95c49c56; /* fn_18 */
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c102c110c95c49c57;
function_248:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_249:
  goto top_level_apply;
function_250:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_249);
  goto apply_addr;
function_251:
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
    target = (&&function_250);
    goto apply_addr;
  }
function_252:
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
    increment_count(val = global_c102c110c95c49c56 /* fn_18 */);
    target = (&&function_248);
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
    target = (&&function_251);
    goto apply_addr;
  }
function_253:
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
    target = (&&function_252);
    goto apply_addr;
  }
function_254:
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
    target = (&&function_253);
    goto apply_addr;
  }
function_255:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_254);
  goto apply_addr;
function_256:
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
    target = (&&function_255);
    goto apply_addr;
  }
function_257:
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
    target = (&&function_256);
    goto apply_addr;
  }
function_258:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_257);
  goto apply_addr;
function_259:
  increment_count(env);
  val = wrap_function((&&function_258), env);
  goto pop_function;
/* fn_19 */
body_160:
global_c102c110c95c49c56 = nil(); /* fn_18 */
global_c95c112c97c114c115c101c45c101c120c112c114 = nil(); /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_259), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_161;
pointer global_c102c110c95c49c55; /* fn_17 */
function_260:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c112c97c114c101c110 /* _parse-paren */);
  goto top_level_apply;
function_261:
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
  increment_count(val = global_c102c110c95c49c55 /* fn_17 */);
  target = (&&function_260);
  goto apply_addr;
function_262:
  increment_count(env);
  val = wrap_function((&&function_261), env);
  goto pop_function;
/* fn_18 */
body_161:
global_c102c110c95c49c55 = nil(); /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_262), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_162;
function_263:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_264:
  increment_count(env);
  val = wrap_function((&&function_263), env);
  goto pop_function;
/* fn_17 */
body_162:
  increment_count(env);
  val = wrap_function((&&function_264), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_163;
function_265:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c57 /* fn_19 */);
  goto top_level_apply;
/* _parse-tail */
body_163:
  increment_count(env);
  val = wrap_function((&&function_265), env);
  global_c95c112c97c114c115c101c45c116c97c105c108 = val; /* _parse-tail */
  goto body_164;
pointer global_c95c112c97c114c115c101c45c112c97c105c114; /* _parse-pair */
pointer global_c102c110c95c50c48;
function_266:
  goto top_level_apply;
function_267:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  target = (&&function_266);
  goto apply_addr;
function_268:
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
    target = (&&function_267);
    goto apply_addr;
  }
function_269:
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
    target = (&&function_268);
    goto apply_addr;
  }
function_270:
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
    target = (&&function_269);
    goto apply_addr;
  }
function_271:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
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
    target = (&&function_271);
    goto apply_addr;
  }
function_273:
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
    target = (&&function_272);
    goto apply_addr;
  }
function_274:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_273);
  goto apply_addr;
function_275:
  increment_count(env);
  val = wrap_function((&&function_274), env);
  goto pop_function;
/* fn_20 */
body_164:
global_c95c112c97c114c115c101c45c112c97c105c114 = nil(); /* _parse-pair */
  increment_count(env);
  val = wrap_function((&&function_275), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_165;
function_276:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48 /* fn_20 */);
  goto top_level_apply;
/* _parse-pair */
body_165:
  increment_count(env);
  val = wrap_function((&&function_276), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_166;
pointer global_c102c110c95c50c51; /* fn_23 */
pointer global_c102c110c95c50c50; /* fn_22 */
pointer global_c102c110c95c50c49; /* fn_21 */
pointer global_c102c110c95c50c52;
function_277:
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
function_278:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_279:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_280:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
function_281:
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c115c121c109c98c111c108 /* _parse-symbol */);
  goto top_level_apply;
function_282:
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
    target = (&&function_282);
    goto apply_addr;
  }
function_284:
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
    increment_count(val = global_c102c110c95c50c51 /* fn_23 */);
    target = (&&function_280);
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
    target = (&&function_283);
    goto apply_addr;
  }
function_285:
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
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_c102c110c95c50c50 /* fn_22 */);
    target = (&&function_279);
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
    target = (&&function_285);
    goto apply_addr;
  }
function_287:
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
    target = (&&function_286);
    goto apply_addr;
  }
function_288:
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
    target = (&&function_287);
    goto apply_addr;
  }
function_289:
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
    increment_count(val = global_c102c110c95c50c49 /* fn_21 */);
    target = (&&function_278);
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
    target = (&&function_288);
    goto apply_addr;
  }
function_290:
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
    target = (&&function_289);
    goto apply_addr;
  }
function_291:
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
    target = (&&function_277);
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
    target = (&&function_290);
    goto apply_addr;
  }
function_292:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_291);
  goto apply_addr;
function_293:
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
    target = (&&function_292);
    goto apply_addr;
  }
function_294:
  push_args();
  val = nil();
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61 /* __= */);
  target = (&&function_293);
  goto apply_addr;
function_295:
  increment_count(env);
  val = wrap_function((&&function_294), env);
  goto pop_function;
/* fn_24 */
body_166:
global_c102c110c95c50c51 = nil(); /* fn_23 */
global_c102c110c95c50c50 = nil(); /* fn_22 */
global_c102c110c95c50c49 = nil(); /* fn_21 */
  increment_count(env);
  val = wrap_function((&&function_295), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_167;
function_296:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_297:
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
  target = (&&function_296);
  goto apply_addr;
function_298:
  increment_count(env);
  val = wrap_function((&&function_297), env);
  goto pop_function;
/* fn_21 */
body_167:
  increment_count(env);
  val = wrap_function((&&function_298), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_168;
function_299:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_300:
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
  target = (&&function_299);
  goto apply_addr;
function_301:
  increment_count(env);
  val = wrap_function((&&function_300), env);
  goto pop_function;
/* fn_22 */
body_168:
  increment_count(env);
  val = wrap_function((&&function_301), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_169;
function_302:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_303:
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
  target = (&&function_302);
  goto apply_addr;
function_304:
  increment_count(env);
  val = wrap_function((&&function_303), env);
  goto pop_function;
/* fn_23 */
body_169:
  increment_count(env);
  val = wrap_function((&&function_304), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_170;
function_305:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c52 /* fn_24 */);
  goto top_level_apply;
/* _parse-expr */
body_170:
  increment_count(env);
  val = wrap_function((&&function_305), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_171;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_306:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 /* ____print-error */);
  goto top_level_apply;
function_307:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57c53 /* ___l_95 */);
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100 /* _append */);
  target = (&&function_306);
  goto apply_addr;
function_308:
  push_args();
  val = nil();
  args = val;
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c57c55 /* ___l_97 */);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57c54 /* ___l_96 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116 /* _print */);
  target = (&&function_307);
  goto apply_addr;
function_309:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_308), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114 /* _parse-expr */);
  goto top_level_apply;
/* ____read-expr */
body_171:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_172;
pointer global_c95c95c95c108c95c57c56;
/* ___l_98 */
body_172:
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
  global_c95c95c95c108c95c57c56 = val; /* ___l_98 */
  goto body_173;
pointer global_c95c95c95c108c95c57c57;
/* ___l_99 */
body_173:
  val = new_symbol(-34);
  global_c95c95c95c108c95c57c57 = val; /* ___l_99 */
  goto body_174;
pointer global_c95c95c95c108c95c49c48c48;
/* ___l_100 */
body_174:
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
  global_c95c95c95c108c95c49c48c48 = val; /* ___l_100 */
  goto body_175;
pointer global_c95c99c97c97c100c114;
function_310:
  increment_count(val = car(car(cdr(car(car(env))))));
  goto pop_function;
/* _caadr */
body_175:
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_176;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
pointer global_c102c110c95c50c53;
function_311:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101 /* ____compile */);
  goto top_level_apply;
function_312:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c114c101c118c101c114c115c101 /* _reverse */);
  target = (&&function_311);
  goto apply_addr;
function_313:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_314:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
  target = (&&function_313);
  goto apply_addr;
function_315:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c49c48c48 /* ___l_100 */);
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
    push_args();
    val = nil();
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 /* ____list-symbols */);
    target = (&&function_314);
    goto apply_addr;
  }
function_316:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_315);
  goto apply_addr;
function_317:
  args = cons(val, args);
  increment_count(val = global_c95c111c114 /* _or */);
  target = (&&function_316);
  goto apply_addr;
function_318:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_317);
  goto apply_addr;
function_319:
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
  target = (&&function_318);
  goto apply_addr;
function_320:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109 /* __atom */);
  target = (&&function_319);
  goto apply_addr;
function_321:
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
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 /* ____list-symbols */);
    target = (&&function_312);
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
    target = (&&function_320);
    goto apply_addr;
  }
function_322:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_321);
  goto apply_addr;
function_323:
  if (! is_nil(val)) {
    decrement_count(val);
    push_args();
    val = nil();
    args = val;
    increment_count(val = global_c95c95c95c108c95c57c56 /* ___l_98 */);
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
    increment_count(val = global_c95c95c95c108c95c57c57 /* ___l_99 */);
    args = cons(val, args);
    increment_count(val = car(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c61 /* __= */);
    target = (&&function_322);
    goto apply_addr;
  }
function_324:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116 /* _not */);
  target = (&&function_323);
  goto apply_addr;
function_325:
  increment_count(env);
  val = wrap_function((&&function_324), env);
  goto pop_function;
/* fn_25 */
body_176:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = nil(); /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_325), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_177;
function_326:
  push_args();
  val = nil();
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c53 /* fn_25 */);
  goto top_level_apply;
/* ____compile-source */
body_177:
  increment_count(env);
  val = wrap_function((&&function_326), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_178;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_178:
  val = nil();
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_179;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_179:
  val = nil();
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_180;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_180:
  val = nil();
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
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
function_327:
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
function_328:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114 /* ____read-expr */);
  goto top_level_apply;
function_329:
  push_args();
  val = nil();
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51 /* ___l_3 */);
  args = cons(val, args);
  push_args();
  val = nil();
  args = val;
  increment_count(val = global_c95c95c95c108c95c50 /* ___l_2 */);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49 /* ___l_1 */);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 /* ____compile-source */);
  target = (&&function_328);
  goto apply_addr;
body_181:
  increment_count(env);
  val = wrap_function((&&function_329), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), nil()), call_stack);
  call_stack = cons(wrap_function((&&function_327), nil()), call_stack);
  goto body_0;
}
