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
      val = -45;
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
        val = new_number(95);
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
          val = -44;
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
            val = new_number(95);
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
  } else {
    push_args();
    val = NIL;
    args = val;
    val = -46;
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
    val = -46;
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
    target = (&&function_4);
    goto apply_addr;
  }
function_6:
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
    target = (&&function_5);
    goto apply_addr;
  }
function_7:
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
    target = (&&function_6);
    goto apply_addr;
  }
function_8:
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
    target = (&&function_7);
    goto apply_addr;
  }
function_9:
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
    target = (&&function_8);
    goto apply_addr;
  }
function_10:
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
    val = -41;
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
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
    val = -42;
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
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
    val = -43;
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
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
    val = -44;
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
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
    val = EQ;
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
    val = new_number(95);
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
    val = -45;
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
/* _string->symbol */
body_2:
  increment_count(env);
  val = wrap_function((&&function_18), env);
  global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* _string->symbol */
  goto body_3;
pointer global_c95c115c121c109c98c111c108c63;
function_19:
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
          val = -46;
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
/* _symbol? */
body_3:
  increment_count(env);
  val = wrap_function((&&function_19), env);
  global_c95c115c121c109c98c111c108c63 = val; /* _symbol? */
  goto body_4;
pointer global_c95c95c97c116c111c109;
function_20:
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
    val = -46;
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
/* __atom */
body_4:
  increment_count(env);
  val = wrap_function((&&function_20), env);
  global_c95c95c97c116c111c109 = val; /* __atom */
  goto body_5;
pointer global_c95c95c61;
function_21:
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
function_22:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_21);
  goto apply_addr;
/* __= */
body_5:
  increment_count(env);
  val = wrap_function((&&function_22), env);
  global_c95c95c61 = val; /* __= */
  goto body_6;
pointer global_c95c108c105c115c116;
function_23:
  increment_count(val = car(env));
  goto pop_function;
/* _list */
body_6:
  increment_count(env);
  val = wrap_function((&&function_23), env);
  global_c95c108c105c115c116 = val; /* _list */
  goto body_7;
pointer global_c95c114c114c101c118c101c114c115c101;
function_24:
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
function_25:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_24);
  goto apply_addr;
/* _rreverse */
body_7:
  increment_count(env);
  val = wrap_function((&&function_25), env);
  global_c95c114c114c101c118c101c114c115c101 = val; /* _rreverse */
  goto body_8;
pointer global_c95c102c111c108c100c108; /* _foldl */
pointer global_c102c110c95c48;
function_26:
  goto top_level_apply;
function_27:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_26);
  goto apply_addr;
function_28:
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
    target = (&&function_27);
    goto apply_addr;
  }
function_29:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_28);
  goto apply_addr;
function_30:
  increment_count(env);
  val = wrap_function((&&function_29), env);
  goto pop_function;
/* fn_0 */
body_8:
global_c95c102c111c108c100c108 = NIL; /* _foldl */
  increment_count(env);
  val = wrap_function((&&function_30), env);
  global_c102c110c95c48 = val; /* fn_0 */
  goto body_9;
function_31:
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
  val = wrap_function((&&function_31), env);
  global_c95c102c111c108c100c108 = val; /* _foldl */
  goto body_10;
pointer global_c102c110c95c49;
function_32:
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c114c114c101c118c101c114c115c101); /* _rreverse */
  goto top_level_apply;
function_33:
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
  target = (&&function_32);
  goto apply_addr;
function_34:
  increment_count(env);
  val = wrap_function((&&function_33), env);
  goto pop_function;
/* fn_1 */
body_10:
  increment_count(env);
  val = wrap_function((&&function_34), env);
  global_c102c110c95c49 = val; /* fn_1 */
  goto body_11;
pointer global_c95c102c111c108c100c114;
function_35:
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
  val = wrap_function((&&function_35), env);
  global_c95c102c111c108c100c114 = val; /* _foldr */
  goto body_12;
pointer global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114;
function_36:
  global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114 = val; /* ____map-to-stderr */
  goto body_13;
function_37:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_38:
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
  target = (&&function_37);
  goto apply_addr;
/* ____map-to-stderr */
body_12:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_38), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_36);
  goto apply_addr;
pointer global_c95c95c95c108c95c52;
/* ___l_4 */
body_13:
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
  global_c95c95c95c108c95c52 = val; /* ___l_4 */
  goto body_14;
pointer global_c95c95c95c108c95c53;
/* ___l_5 */
body_14:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53 = val; /* ___l_5 */
  goto body_15;
pointer global_c99c111c110c115; /* cons */
pointer global_c95c97c112c112c101c110c100;
function_39:
  goto top_level_apply;
function_40:
  goto top_level_apply;
function_41:
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
    target = (&&function_40);
    goto apply_addr;
  }
function_42:
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_41);
  goto apply_addr;
function_43:
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
  val = wrap_function((&&function_42), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_39);
  goto apply_addr;
/* _append */
body_15:
global_c99c111c110c115 = CONS; /* cons */
  increment_count(env);
  val = wrap_function((&&function_43), env);
  global_c95c97c112c112c101c110c100 = val; /* _append */
  goto body_16;
pointer global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114;
function_44:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c109c97c112c45c116c111c45c115c116c100c101c114c114); /* ____map-to-stderr */
  goto top_level_apply;
function_45:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c53); /* ___l_5 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52); /* ___l_4 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_44);
  goto apply_addr;
/* ____print-error */
body_16:
  increment_count(env);
  val = wrap_function((&&function_45), env);
  global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114 = val; /* ____print-error */
  goto body_17;
pointer global_c95c95c95c108c95c54;
/* ___l_6 */
body_17:
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54 = val; /* ___l_6 */
  goto body_18;
pointer global_c95c95c101c113c117c97c108;
function_46:
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
function_47:
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
    target = (&&function_46);
    goto apply_addr;
  }
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
    increment_count(val = global_c95c95c61); /* __= */
    goto top_level_apply;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_47);
    goto apply_addr;
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
/* __equal */
body_18:
  increment_count(env);
  val = wrap_function((&&function_49), env);
  global_c95c95c101c113c117c97c108 = val; /* __equal */
  goto body_19;
pointer global_c95c109c101c109c98c101c114;
function_50:
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
function_51:
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
    target = (&&function_50);
    goto apply_addr;
  }
function_52:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_51);
  goto apply_addr;
/* _member */
body_19:
  increment_count(env);
  val = wrap_function((&&function_52), env);
  global_c95c109c101c109c98c101c114 = val; /* _member */
  goto body_20;
pointer global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101;
function_53:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101); /* ____generate-unused-symbol-name */
  goto top_level_apply;
function_54:
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
    increment_count(val = global_c95c95c95c108c95c54); /* ___l_6 */
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
    target = (&&function_53);
    goto apply_addr;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_55:
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_54);
  goto apply_addr;
function_56:
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
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  target = (&&function_55);
  goto apply_addr;
/* ____generate-unused-symbol-name */
body_20:
  increment_count(env);
  val = wrap_function((&&function_56), env);
  global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101 = val; /* ____generate-unused-symbol-name */
  goto body_21;
pointer global_c95c95c95c108c95c55;
/* ___l_7 */
body_21:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55 = val; /* ___l_7 */
  goto body_22;
pointer global_c95c95c95c108c95c56;
/* ___l_8 */
body_22:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56 = val; /* ___l_8 */
  goto body_23;
pointer global_c95c95c95c108c95c57;
/* ___l_9 */
body_23:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c57 = val; /* ___l_9 */
  goto body_24;
pointer global_c95c95c95c108c95c49c48;
/* ___l_10 */
body_24:
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c48 = val; /* ___l_10 */
  goto body_25;
pointer global_c95c95c95c108c95c49c49;
/* ___l_11 */
body_25:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c49 = val; /* ___l_11 */
  goto body_26;
pointer global_c95c95c95c108c95c49c50;
/* ___l_12 */
body_26:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c50 = val; /* ___l_12 */
  goto body_27;
pointer global_c95c95c95c108c95c49c51;
/* ___l_13 */
body_27:
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c51 = val; /* ___l_13 */
  goto body_28;
pointer global_c95c105c100;
function_57:
  increment_count(val = car(car(env)));
  goto pop_function;
/* _id */
body_28:
  increment_count(env);
  val = wrap_function((&&function_57), env);
  global_c95c105c100 = val; /* _id */
  goto body_29;
pointer global_c95c119c97c108c107; /* _walk */
pointer global_c102c110c95c50;
function_58:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  goto top_level_apply;
function_59:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_58);
  goto apply_addr;
function_60:
  target = (&&function_59);
  goto apply_addr;
function_61:
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
  target = (&&function_60);
  goto apply_addr;
function_62:
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
    target = (&&function_61);
    goto apply_addr;
  }
function_63:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  target = (&&function_62);
  goto apply_addr;
function_64:
  increment_count(env);
  val = wrap_function((&&function_63), env);
  goto pop_function;
/* fn_2 */
body_29:
global_c95c119c97c108c107 = NIL; /* _walk */
  increment_count(env);
  val = wrap_function((&&function_64), env);
  global_c102c110c95c50 = val; /* fn_2 */
  goto body_30;
function_65:
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
body_30:
  increment_count(env);
  val = wrap_function((&&function_65), env);
  global_c95c119c97c108c107 = val; /* _walk */
  goto body_31;
pointer global_c102c110c95c51;
function_66:
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
function_67:
  increment_count(env);
  val = wrap_function((&&function_66), env);
  goto pop_function;
/* fn_3 */
body_31:
  increment_count(env);
  val = wrap_function((&&function_67), env);
  global_c102c110c95c51 = val; /* fn_3 */
  goto body_32;
pointer global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114;
function_68:
  goto top_level_apply;
function_69:
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
function_70:
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
function_71:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_72:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c51); /* fn_3 */
  goto top_level_apply;
function_73:
  increment_count(val = global_c95c105c100); /* _id */
  goto pop_function;
function_74:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = wrap_function((&&function_73), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_72), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_71), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_70), env);
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_69), env);
  args = cons(val, args);
  increment_count(val = global_c95c119c97c108c107); /* _walk */
  target = (&&function_68);
  goto apply_addr;
/* _build-num-str */
body_32:
  increment_count(env);
  val = wrap_function((&&function_74), env);
  global_c95c98c117c105c108c100c45c110c117c109c45c115c116c114 = val; /* _build-num-str */
  goto body_33;
pointer global_c95c112c114c105c110c116c45c110c117c109;
function_75:
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
function_76:
  target = (&&function_75);
  goto apply_addr;
function_77:
  goto top_level_apply;
function_78:
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
      target = (&&function_76);
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
      target = (&&function_77);
      goto apply_addr;
    }
  }
function_79:
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_78);
  goto apply_addr;
/* _print-num */
body_33:
  increment_count(env);
  val = wrap_function((&&function_79), env);
  global_c95c112c114c105c110c116c45c110c117c109 = val; /* _print-num */
  goto body_34;
pointer global_c95c112c114c105c110c116c45c97c116c111c109;
function_80:
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
function_81:
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
      target = (&&function_80);
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
body_34:
  increment_count(env);
  val = wrap_function((&&function_81), env);
  global_c95c112c114c105c110c116c45c97c116c111c109 = val; /* _print-atom */
  goto body_35;
pointer global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120; /* _print-with-suffix */
pointer global_c95c112c114c105c110c116c45c116c97c105c108;
function_82:
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
function_83:
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
function_84:
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
  target = (&&function_83);
  goto apply_addr;
function_85:
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
    target = (&&function_82);
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
    target = (&&function_84);
    goto apply_addr;
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
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_85);
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
body_35:
global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = NIL; /* _print-with-suffix */
  increment_count(env);
  val = wrap_function((&&function_86), env);
  global_c95c112c114c105c110c116c45c116c97c105c108 = val; /* _print-tail */
  goto body_36;
function_87:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_88:
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_90);
  goto apply_addr;
/* _print-with-suffix */
body_36:
  increment_count(env);
  val = wrap_function((&&function_91), env);
  global_c95c112c114c105c110c116c45c119c105c116c104c45c115c117c102c102c105c120 = val; /* _print-with-suffix */
  goto body_37;
pointer global_c95c112c114c105c110c116;
function_92:
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
body_37:
  increment_count(env);
  val = wrap_function((&&function_92), env);
  global_c95c112c114c105c110c116 = val; /* _print */
  goto body_38;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115; /* ____build-string->symbol-cases */
pointer global_c102c110c95c52;
function_93:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c49); /* ___l_11 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c48); /* ___l_10 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c57); /* ___l_9 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_94:
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115); /* ____build-string->symbol-cases */
  target = (&&function_93);
  goto apply_addr;
function_95:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c50); /* ___l_12 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_94);
  goto apply_addr;
function_96:
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
  increment_count(val = global_c95c95c95c108c95c49c51); /* ___l_13 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_95);
  goto apply_addr;
function_97:
  increment_count(env);
  val = wrap_function((&&function_96), env);
  goto pop_function;
/* fn_4 */
body_38:
global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = NIL; /* ____build-string->symbol-cases */
  increment_count(env);
  val = wrap_function((&&function_97), env);
  global_c102c110c95c52 = val; /* fn_4 */
  goto body_39;
function_98:
  goto top_level_apply;
function_99:
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c52); /* fn_4 */
  target = (&&function_98);
  goto apply_addr;
function_100:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c56); /* ___l_8 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c55); /* ___l_7 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
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
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_99);
    goto apply_addr;
  }
function_101:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_100);
  goto apply_addr;
/* ____build-string->symbol-cases */
body_39:
  increment_count(env);
  val = wrap_function((&&function_101), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115 = val; /* ____build-string->symbol-cases */
  goto body_40;
pointer global_c95c95c95c108c95c49c52;
/* ___l_14 */
body_40:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c52 = val; /* ___l_14 */
  goto body_41;
pointer global_c95c95c95c108c95c49c53;
/* ___l_15 */
body_41:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c53 = val; /* ___l_15 */
  goto body_42;
pointer global_c95c95c95c108c95c49c54;
/* ___l_16 */
body_42:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c54 = val; /* ___l_16 */
  goto body_43;
pointer global_c95c95c95c108c95c49c55;
/* ___l_17 */
body_43:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c55 = val; /* ___l_17 */
  goto body_44;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108;
function_102:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c53); /* ___l_15 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c52); /* ___l_14 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_103:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c49c55); /* ___l_17 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c54); /* ___l_16 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108c45c99c97c115c101c115); /* ____build-string->symbol-cases */
  target = (&&function_102);
  goto apply_addr;
/* ____build-string->symbol */
body_44:
  increment_count(env);
  val = wrap_function((&&function_103), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108 = val; /* ____build-string->symbol */
  goto body_45;
pointer global_c95c95c95c108c95c49c56;
/* ___l_18 */
body_45:
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c56 = val; /* ___l_18 */
  goto body_46;
pointer global_c95c95c95c108c95c49c57;
/* ___l_19 */
body_46:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c49c57 = val; /* ___l_19 */
  goto body_47;
pointer global_c95c95c95c108c95c50c48;
/* ___l_20 */
body_47:
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c48 = val; /* ___l_20 */
  goto body_48;
pointer global_c95c95c95c108c95c50c49;
/* ___l_21 */
body_48:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c49 = val; /* ___l_21 */
  goto body_49;
pointer global_c95c95c95c108c95c50c50;
/* ___l_22 */
body_49:
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c50 = val; /* ___l_22 */
  goto body_50;
pointer global_c95c95c95c108c95c50c51;
/* ___l_23 */
body_50:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c51 = val; /* ___l_23 */
  goto body_51;
pointer global_c95c95c95c108c95c50c52;
/* ___l_24 */
body_51:
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c52 = val; /* ___l_24 */
  goto body_52;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115; /* ____build-symbol->string-cases */
pointer global_c102c110c95c53;
function_104:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c50); /* ___l_22 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c49); /* ___l_21 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c48); /* ___l_20 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49c57); /* ___l_19 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_105:
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
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115); /* ____build-symbol->string-cases */
  target = (&&function_104);
  goto apply_addr;
function_106:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c51); /* ___l_23 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_105);
  goto apply_addr;
function_107:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c52); /* ___l_24 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_106);
  goto apply_addr;
function_108:
  increment_count(env);
  val = wrap_function((&&function_107), env);
  goto pop_function;
/* fn_5 */
body_52:
global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = NIL; /* ____build-symbol->string-cases */
  increment_count(env);
  val = wrap_function((&&function_108), env);
  global_c102c110c95c53 = val; /* fn_5 */
  goto body_53;
function_109:
  goto top_level_apply;
function_110:
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
  increment_count(val = global_c102c110c95c53); /* fn_5 */
  target = (&&function_109);
  goto apply_addr;
function_111:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c108c95c49c56); /* ___l_18 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
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
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_110);
    goto apply_addr;
  }
function_112:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_111);
  goto apply_addr;
/* ____build-symbol->string-cases */
body_53:
  increment_count(env);
  val = wrap_function((&&function_112), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115 = val; /* ____build-symbol->string-cases */
  goto body_54;
pointer global_c95c95c95c108c95c50c53;
/* ___l_25 */
body_54:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c53 = val; /* ___l_25 */
  goto body_55;
pointer global_c95c95c95c108c95c50c54;
/* ___l_26 */
body_55:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c54 = val; /* ___l_26 */
  goto body_56;
pointer global_c95c95c95c108c95c50c55;
/* ___l_27 */
body_56:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c55 = val; /* ___l_27 */
  goto body_57;
pointer global_c95c95c95c108c95c50c56;
/* ___l_28 */
body_57:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c56 = val; /* ___l_28 */
  goto body_58;
pointer global_c95c95c95c108c95c50c57;
/* ___l_29 */
body_58:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c50c57 = val; /* ___l_29 */
  goto body_59;
pointer global_c95c95c95c108c95c51c48;
/* ___l_30 */
body_59:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c48 = val; /* ___l_30 */
  goto body_60;
pointer global_c95c95c95c108c95c51c49;
/* ___l_31 */
body_60:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c49 = val; /* ___l_31 */
  goto body_61;
pointer global_c95c95c95c108c95c51c50;
/* ___l_32 */
body_61:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c50 = val; /* ___l_32 */
  goto body_62;
pointer global_c95c95c95c108c95c51c51;
/* ___l_33 */
body_62:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c51c51 = val; /* ___l_33 */
  goto body_63;
pointer global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103;
function_113:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c55); /* ___l_27 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c54); /* ___l_26 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c53); /* ___l_25 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_114:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c51); /* ___l_33 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c50); /* ___l_32 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c49); /* ___l_31 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51c48); /* ___l_30 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50c57); /* ___l_29 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c50c56); /* ___l_28 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103c45c99c97c115c101c115); /* ____build-symbol->string-cases */
  target = (&&function_113);
  goto apply_addr;
/* ____build-symbol->string */
body_63:
  increment_count(env);
  val = wrap_function((&&function_114), env);
  global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103 = val; /* ____build-symbol->string */
  goto body_64;
pointer global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115; /* ____escape-symbols */
pointer global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115;
function_115:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_116:
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
  target = (&&function_115);
  goto apply_addr;
function_117:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
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
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115); /* ____escape-args */
    target = (&&function_116);
    goto apply_addr;
  }
function_118:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_117);
  goto apply_addr;
/* ____escape-args */
body_64:
global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = NIL; /* ____escape-symbols */
  increment_count(env);
  val = wrap_function((&&function_118), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115 = val; /* ____escape-args */
  goto body_65;
pointer global_c95c95c95c108c95c51c52;
/* ___l_34 */
body_65:
  val = ATOM;
  global_c95c95c95c108c95c51c52 = val; /* ___l_34 */
  goto body_66;
pointer global_c95c95c95c108c95c51c53;
/* ___l_35 */
body_66:
  val = -45;
  global_c95c95c95c108c95c51c53 = val; /* ___l_35 */
  goto body_67;
pointer global_c95c95c95c108c95c51c54;
/* ___l_36 */
body_67:
  val = EQ;
  global_c95c95c95c108c95c51c54 = val; /* ___l_36 */
  goto body_68;
pointer global_c95c95c95c108c95c51c55;
/* ___l_37 */
body_68:
  val = -44;
  global_c95c95c95c108c95c51c55 = val; /* ___l_37 */
  goto body_69;
pointer global_c95c95c95c108c95c51c56;
/* ___l_38 */
body_69:
  val = -43;
  global_c95c95c95c108c95c51c56 = val; /* ___l_38 */
  goto body_70;
pointer global_c95c95c95c108c95c51c57;
/* ___l_39 */
body_70:
  val = -42;
  global_c95c95c95c108c95c51c57 = val; /* ___l_39 */
  goto body_71;
pointer global_c95c95c95c108c95c52c48;
/* ___l_40 */
body_71:
  val = -38;
  global_c95c95c95c108c95c52c48 = val; /* ___l_40 */
  goto body_72;
function_119:
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* _string->symbol */
  goto top_level_apply;
function_120:
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
    target = (&&function_119);
    goto apply_addr;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_121:
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_120);
  goto apply_addr;
function_122:
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
    increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c97c114c103c115); /* ____escape-args */
    goto top_level_apply;
  }
function_123:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
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
    target = (&&function_122);
    goto apply_addr;
  }
function_124:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    val = new_number(95);
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* _symbol->string */
    target = (&&function_121);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_123);
    goto apply_addr;
  }
function_125:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c57); /* ___l_39 */
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
    target = (&&function_124);
    goto apply_addr;
  }
function_126:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c55); /* ___l_37 */
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c56); /* ___l_38 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    target = (&&function_125);
    goto apply_addr;
  }
function_127:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_c95c95c95c108c95c51c53); /* ___l_35 */
    goto pop_function;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c51c54); /* ___l_36 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c61); /* __= */
    target = (&&function_126);
    goto apply_addr;
  }
function_128:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c51c52); /* ___l_34 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_127);
  goto apply_addr;
/* ____escape-symbols */
body_72:
  increment_count(env);
  val = wrap_function((&&function_128), env);
  global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115 = val; /* ____escape-symbols */
  goto body_73;
pointer global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115;
function_129:
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
function_130:
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
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
  goto top_level_apply;
function_131:
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
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
    target = (&&function_130);
    goto apply_addr;
  }
function_132:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
    target = (&&function_129);
    goto apply_addr;
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c97c116c111c109); /* __atom */
    target = (&&function_131);
    goto apply_addr;
  }
function_133:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c115c121c109c98c111c108c63); /* _symbol? */
  target = (&&function_132);
  goto apply_addr;
/* ____list-symbols */
body_73:
  increment_count(env);
  val = wrap_function((&&function_133), env);
  global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115 = val; /* ____list-symbols */
  goto body_74;
pointer global_c95c95c95c108c95c52c49;
/* ___l_41 */
body_74:
  val = -38;
  global_c95c95c95c108c95c52c49 = val; /* ___l_41 */
  goto body_75;
pointer global_c95c99c97c100c114;
function_134:
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
body_75:
  increment_count(env);
  val = wrap_function((&&function_134), env);
  global_c95c99c97c100c114 = val; /* _cadr */
  goto body_76;
pointer global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115;
function_135:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
  goto top_level_apply;
function_136:
  goto top_level_apply;
function_137:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115); /* ____find-quoted-symbols */
  goto top_level_apply;
function_138:
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
    increment_count(val = global_c95c99c97c100c114); /* _cadr */
    target = (&&function_135);
    goto apply_addr;
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
    val = wrap_function((&&function_137), env);
    args = cons(val, args);
    increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
    target = (&&function_136);
    goto apply_addr;
  }
function_139:
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
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
/* ____find-quoted-symbols */
body_76:
  increment_count(env);
  val = wrap_function((&&function_140), env);
  global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115 = val; /* ____find-quoted-symbols */
  goto body_77;
pointer global_c95c95c95c108c95c52c50;
/* ___l_42 */
body_77:
  val = -41;
  global_c95c95c95c108c95c52c50 = val; /* ___l_42 */
  goto body_78;
pointer global_c95c95c95c108c95c52c51;
/* ___l_43 */
body_78:
  val = -40;
  global_c95c95c95c108c95c52c51 = val; /* ___l_43 */
  goto body_79;
pointer global_c95c95c95c108c95c52c52;
/* ___l_44 */
body_79:
  val = -39;
  global_c95c95c95c108c95c52c52 = val; /* ___l_44 */
  goto body_80;
pointer global_c95c95c95c108c95c52c53;
/* ___l_45 */
body_80:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c53 = val; /* ___l_45 */
  goto body_81;
pointer global_c95c95c95c108c95c52c54;
/* ___l_46 */
body_81:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c54 = val; /* ___l_46 */
  goto body_82;
pointer global_c95c95c95c108c95c52c55;
/* ___l_47 */
body_82:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c55 = val; /* ___l_47 */
  goto body_83;
pointer global_c95c95c95c108c95c52c56;
/* ___l_48 */
body_83:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c56 = val; /* ___l_48 */
  goto body_84;
pointer global_c95c95c95c108c95c52c57;
/* ___l_49 */
body_84:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c52c57 = val; /* ___l_49 */
  goto body_85;
pointer global_c95c95c95c108c95c53c48;
/* ___l_50 */
body_85:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c48 = val; /* ___l_50 */
  goto body_86;
pointer global_c95c95c95c108c95c53c49;
/* ___l_51 */
body_86:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c49 = val; /* ___l_51 */
  goto body_87;
pointer global_c95c95c95c108c95c53c50;
/* ___l_52 */
body_87:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c50 = val; /* ___l_52 */
  goto body_88;
pointer global_c95c95c95c108c95c53c51;
/* ___l_53 */
body_88:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c51 = val; /* ___l_53 */
  goto body_89;
pointer global_c95c95c95c108c95c53c52;
/* ___l_54 */
body_89:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c52 = val; /* ___l_54 */
  goto body_90;
pointer global_c95c95c95c108c95c53c53;
/* ___l_55 */
body_90:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c53 = val; /* ___l_55 */
  goto body_91;
pointer global_c95c95c95c108c95c53c54;
/* ___l_56 */
body_91:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c54 = val; /* ___l_56 */
  goto body_92;
pointer global_c95c95c95c108c95c53c55;
/* ___l_57 */
body_92:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c55 = val; /* ___l_57 */
  goto body_93;
pointer global_c95c95c95c108c95c53c56;
/* ___l_58 */
body_93:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c56 = val; /* ___l_58 */
  goto body_94;
pointer global_c95c95c95c108c95c53c57;
/* ___l_59 */
body_94:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c53c57 = val; /* ___l_59 */
  goto body_95;
pointer global_c95c95c95c108c95c54c48;
/* ___l_60 */
body_95:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c48 = val; /* ___l_60 */
  goto body_96;
pointer global_c95c95c95c108c95c54c49;
/* ___l_61 */
body_96:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c49 = val; /* ___l_61 */
  goto body_97;
pointer global_c95c95c95c108c95c54c50;
/* ___l_62 */
body_97:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c50 = val; /* ___l_62 */
  goto body_98;
pointer global_c95c95c95c108c95c54c51;
/* ___l_63 */
body_98:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c51 = val; /* ___l_63 */
  goto body_99;
pointer global_c95c95c95c108c95c54c52;
/* ___l_64 */
body_99:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c52 = val; /* ___l_64 */
  goto body_100;
pointer global_c95c95c95c108c95c54c53;
/* ___l_65 */
body_100:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c53 = val; /* ___l_65 */
  goto body_101;
pointer global_c95c95c95c108c95c54c54;
/* ___l_66 */
body_101:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c54 = val; /* ___l_66 */
  goto body_102;
pointer global_c95c95c95c108c95c54c55;
/* ___l_67 */
body_102:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c55 = val; /* ___l_67 */
  goto body_103;
pointer global_c95c95c95c108c95c54c56;
/* ___l_68 */
body_103:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c56 = val; /* ___l_68 */
  goto body_104;
pointer global_c95c95c95c108c95c54c57;
/* ___l_69 */
body_104:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c54c57 = val; /* ___l_69 */
  goto body_105;
pointer global_c95c95c95c108c95c55c48;
/* ___l_70 */
body_105:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c48 = val; /* ___l_70 */
  goto body_106;
pointer global_c95c95c95c108c95c55c49;
/* ___l_71 */
body_106:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c49 = val; /* ___l_71 */
  goto body_107;
pointer global_c95c95c95c108c95c55c50;
/* ___l_72 */
body_107:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c50 = val; /* ___l_72 */
  goto body_108;
pointer global_c95c95c95c108c95c55c51;
/* ___l_73 */
body_108:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c51 = val; /* ___l_73 */
  goto body_109;
pointer global_c95c95c95c108c95c55c52;
/* ___l_74 */
body_109:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c52 = val; /* ___l_74 */
  goto body_110;
pointer global_c95c95c95c108c95c55c53;
/* ___l_75 */
body_110:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c53 = val; /* ___l_75 */
  goto body_111;
pointer global_c95c95c95c108c95c55c54;
/* ___l_76 */
body_111:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c54 = val; /* ___l_76 */
  goto body_112;
pointer global_c95c95c95c108c95c55c55;
/* ___l_77 */
body_112:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c55 = val; /* ___l_77 */
  goto body_113;
pointer global_c95c95c95c108c95c55c56;
/* ___l_78 */
body_113:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c56 = val; /* ___l_78 */
  goto body_114;
pointer global_c95c95c95c108c95c55c57;
/* ___l_79 */
body_114:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c55c57 = val; /* ___l_79 */
  goto body_115;
pointer global_c95c95c95c108c95c56c48;
/* ___l_80 */
body_115:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c48 = val; /* ___l_80 */
  goto body_116;
pointer global_c95c95c95c108c95c56c49;
/* ___l_81 */
body_116:
  val = NIL;
  global_c95c95c95c108c95c56c49 = val; /* ___l_81 */
  goto body_117;
pointer global_c95c95c95c108c95c56c50;
/* ___l_82 */
body_117:
  val = NIL;
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
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c50 = val; /* ___l_82 */
  goto body_118;
pointer global_c95c97c112c112c108c121;
function_141:
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  goto top_level_apply;
/* _apply */
body_118:
  increment_count(env);
  val = wrap_function((&&function_141), env);
  global_c95c97c112c112c108c121 = val; /* _apply */
  goto body_119;
pointer global_c102c110c95c54;
function_142:
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  goto pop_function;
function_143:
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
  increment_count(val = car(car(cdr(env))));
  target = (&&function_142);
  goto apply_addr;
function_144:
  increment_count(env);
  val = wrap_function((&&function_143), env);
  goto pop_function;
/* fn_6 */
body_119:
  increment_count(env);
  val = wrap_function((&&function_144), env);
  global_c102c110c95c54 = val; /* fn_6 */
  goto body_120;
pointer global_c95c109c97c112;
function_145:
  goto top_level_apply;
function_146:
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_145);
  goto apply_addr;
function_147:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
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
  increment_count(val = global_c102c110c95c54); /* fn_6 */
  target = (&&function_146);
  goto apply_addr;
/* _map */
body_120:
  increment_count(env);
  val = wrap_function((&&function_147), env);
  global_c95c109c97c112 = val; /* _map */
  goto body_121;
pointer global_c95c111c114;
function_148:
  goto top_level_apply;
function_149:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    goto pop_function;
  } else {
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  }
function_150:
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
  val = wrap_function((&&function_149), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_148);
  goto apply_addr;
/* _or */
body_121:
  increment_count(env);
  val = wrap_function((&&function_150), env);
  global_c95c111c114 = val; /* _or */
  goto body_122;
pointer global_c102c110c95c55; /* fn_7 */
pointer global_c102c110c95c56;
function_151:
  goto top_level_apply;
function_152:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c55); /* fn_7 */
  target = (&&function_151);
  goto apply_addr;
function_153:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c56c49); /* ___l_81 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_c95c95c95c95c102c105c110c100c45c113c117c111c116c101c100c45c115c121c109c98c111c108c115); /* ____find-quoted-symbols */
  target = (&&function_152);
  goto apply_addr;
function_154:
  increment_count(env);
  val = wrap_function((&&function_153), env);
  goto pop_function;
/* fn_8 */
body_122:
global_c102c110c95c55 = NIL; /* fn_7 */
  increment_count(env);
  val = wrap_function((&&function_154), env);
  global_c102c110c95c56 = val; /* fn_8 */
  goto body_123;
function_155:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c51); /* ___l_53 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c50); /* ___l_52 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c49); /* ___l_51 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c48); /* ___l_50 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c57); /* ___l_49 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c56); /* ___l_48 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c55); /* ___l_47 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c54); /* ___l_46 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c53); /* ___l_45 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_156:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c121c109c98c111c108c45c62c115c116c114c105c110c103); /* ____build-symbol->string */
  target = (&&function_155);
  goto apply_addr;
function_157:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c48); /* ___l_80 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c57); /* ___l_79 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c56); /* ___l_78 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c55); /* ___l_77 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c54); /* ___l_76 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c53); /* ___l_75 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c52); /* ___l_74 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c51); /* ___l_73 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c50); /* ___l_72 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c49); /* ___l_71 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c55c48); /* ___l_70 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c57); /* ___l_69 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c56); /* ___l_68 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c55); /* ___l_67 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c54); /* ___l_66 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c53); /* ___l_65 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c52); /* ___l_64 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c51); /* ___l_63 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c50); /* ___l_62 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c49); /* ___l_61 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c54c48); /* ___l_60 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c57); /* ___l_59 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c56); /* ___l_58 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c55); /* ___l_57 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c54); /* ___l_56 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c53); /* ___l_55 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c53c52); /* ___l_54 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c98c117c105c108c100c45c115c116c114c105c110c103c45c62c115c121c109c98c111c108); /* ____build-string->symbol */
  target = (&&function_156);
  goto apply_addr;
function_158:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  target = (&&function_157);
  goto apply_addr;
function_159:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  target = (&&function_158);
  goto apply_addr;
function_160:
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
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  target = (&&function_159);
  goto apply_addr;
function_161:
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_160);
  goto apply_addr;
function_162:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c101c115c99c97c112c101c45c115c121c109c98c111c108c115); /* ____escape-symbols */
  target = (&&function_161);
  goto apply_addr;
function_163:
  increment_count(env);
  val = wrap_function((&&function_162), env);
  goto pop_function;
/* fn_7 */
body_123:
  increment_count(env);
  val = wrap_function((&&function_163), env);
  global_c102c110c95c55 = val; /* fn_7 */
  goto body_124;
pointer global_c95c95c95c95c99c111c109c112c105c108c101;
function_164:
  goto top_level_apply;
function_165:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c56); /* fn_8 */
  target = (&&function_164);
  goto apply_addr;
function_166:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  goto top_level_apply;
function_167:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  target = (&&function_166);
  goto apply_addr;
function_168:
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
  args = cons(val, args);
  increment_count(val = global_c95c109c97c112); /* _map */
  target = (&&function_167);
  goto apply_addr;
function_169:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c50); /* ___l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c103c101c110c101c114c97c116c101c45c117c110c117c115c101c100c45c115c121c109c98c111c108c45c110c97c109c101); /* ____generate-unused-symbol-name */
    target = (&&function_165);
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
    increment_count(val = global_c95c112c114c105c110c116); /* _print */
    target = (&&function_168);
    goto apply_addr;
  }
function_170:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_169);
  goto apply_addr;
function_171:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c50); /* ___l_42 */
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_170);
  goto apply_addr;
function_172:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c51); /* ___l_43 */
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_171);
  goto apply_addr;
function_173:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c52c52); /* ___l_44 */
  args = cons(val, args);
  increment_count(val = global_c95c109c101c109c98c101c114); /* _member */
  target = (&&function_172);
  goto apply_addr;
/* ____compile */
body_124:
  increment_count(env);
  val = wrap_function((&&function_173), env);
  global_c95c95c95c95c99c111c109c112c105c108c101 = val; /* ____compile */
  goto body_125;
pointer global_c95c95c95c108c95c56c51;
/* ___l_83 */
body_125:
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
  global_c95c95c95c108c95c56c51 = val; /* ___l_83 */
  goto body_126;
pointer global_c95c95c95c108c95c56c52;
/* ___l_84 */
body_126:
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
  global_c95c95c95c108c95c56c52 = val; /* ___l_84 */
  goto body_127;
pointer global_c95c95c95c108c95c56c53;
/* ___l_85 */
body_127:
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_c95c95c95c108c95c56c53 = val; /* ___l_85 */
  goto body_128;
pointer global_c95c97c110c100;
function_174:
  goto top_level_apply;
function_175:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    goto pop_function;
  } else {
    val = NIL;
    goto pop_function;
  }
function_176:
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
  increment_count(env);
  val = wrap_function((&&function_175), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_174);
  goto apply_addr;
/* _and */
body_128:
  increment_count(env);
  val = wrap_function((&&function_176), env);
  global_c95c97c110c100 = val; /* _and */
  goto body_129;
pointer global_c95c101c115c99c97c112c101c45c99c104c97c114;
function_177:
  if (val != NIL) {
    decrement_count(val);
    val = new_number(10);
    goto pop_function;
  } else {
    increment_count(val = car(car(env)));
    goto pop_function;
  }
function_178:
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
    target = (&&function_177);
    goto apply_addr;
  }
function_179:
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
    target = (&&function_178);
    goto apply_addr;
  }
function_180:
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  target = (&&function_179);
  goto apply_addr;
/* _escape-char */
body_129:
  increment_count(env);
  val = wrap_function((&&function_180), env);
  global_c95c101c115c99c97c112c101c45c99c104c97c114 = val; /* _escape-char */
  goto body_130;
pointer global_c95c98c117c105c108c100c45c110c117c109;
function_181:
  goto top_level_apply;
function_182:
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
function_183:
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
  val = wrap_function((&&function_182), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c108); /* _foldl */
  target = (&&function_181);
  goto apply_addr;
/* _build-num */
body_130:
  increment_count(env);
  val = wrap_function((&&function_183), env);
  global_c95c98c117c105c108c100c45c110c117c109 = val; /* _build-num */
  goto body_131;
pointer global_c95c113c117c111c116c101c45c118c97c108c117c101;
function_184:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -38;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _quote-value */
body_131:
  increment_count(env);
  val = wrap_function((&&function_184), env);
  global_c95c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quote-value */
  goto body_132;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101;
function_185:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -37;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _quasiquote-value */
body_132:
  increment_count(env);
  val = wrap_function((&&function_185), env);
  global_c95c113c117c97c115c105c113c117c111c116c101c45c118c97c108c117c101 = val; /* _quasiquote-value */
  goto body_133;
pointer global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101;
function_186:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = -36;
  args = cons(val, args);
  increment_count(val = global_c95c108c105c115c116); /* _list */
  goto top_level_apply;
/* _unquote-value */
body_133:
  increment_count(env);
  val = wrap_function((&&function_186), env);
  global_c95c117c110c113c117c111c116c101c45c118c97c108c117c101 = val; /* _unquote-value */
  goto body_134;
pointer global_c102c110c95c57;
function_187:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  goto top_level_apply;
function_188:
  increment_count(env);
  val = wrap_function((&&function_187), env);
  goto pop_function;
/* fn_9 */
body_134:
  increment_count(env);
  val = wrap_function((&&function_188), env);
  global_c102c110c95c57 = val; /* fn_9 */
  goto body_135;
pointer global_c95c102c97c105c108;
function_189:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c57); /* fn_9 */
  goto top_level_apply;
/* _fail */
body_135:
  increment_count(env);
  val = wrap_function((&&function_189), env);
  global_c95c102c97c105c108 = val; /* _fail */
  goto body_136;
pointer global_c95c100c111c110c101;
function_190:
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
body_136:
  increment_count(env);
  val = wrap_function((&&function_190), env);
  global_c95c100c111c110c101 = val; /* _done */
  goto body_137;
pointer global_c95c112c111c112; /* _pop */
pointer global_c102c110c95c49c48;
function_191:
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
function_192:
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
      target = (&&function_191);
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
function_193:
  increment_count(env);
  val = wrap_function((&&function_192), env);
  goto pop_function;
/* fn_10 */
body_137:
global_c95c112c111c112 = NIL; /* _pop */
  increment_count(env);
  val = wrap_function((&&function_193), env);
  global_c102c110c95c49c48 = val; /* fn_10 */
  goto body_138;
function_194:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c48); /* fn_10 */
  goto top_level_apply;
/* _pop */
body_138:
  increment_count(env);
  val = wrap_function((&&function_194), env);
  global_c95c112c111c112 = val; /* _pop */
  goto body_139;
pointer global_c102c110c95c49c49; /* fn_11 */
pointer global_c102c110c95c49c50;
function_195:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c112); /* _pop */
  goto top_level_apply;
function_196:
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
  increment_count(val = global_c102c110c95c49c49); /* fn_11 */
  target = (&&function_195);
  goto apply_addr;
function_197:
  increment_count(env);
  val = wrap_function((&&function_196), env);
  goto pop_function;
/* fn_12 */
body_139:
global_c102c110c95c49c49 = NIL; /* fn_11 */
  increment_count(env);
  val = wrap_function((&&function_197), env);
  global_c102c110c95c49c50 = val; /* fn_12 */
  goto body_140;
function_198:
  goto top_level_apply;
function_199:
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  target = (&&function_198);
  goto apply_addr;
function_200:
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
  target = (&&function_199);
  goto apply_addr;
function_201:
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
    target = (&&function_200);
    goto apply_addr;
  }
function_202:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  target = (&&function_201);
  goto apply_addr;
function_203:
  increment_count(env);
  val = wrap_function((&&function_202), env);
  goto pop_function;
/* fn_11 */
body_140:
  increment_count(env);
  val = wrap_function((&&function_203), env);
  global_c102c110c95c49c49 = val; /* fn_11 */
  goto body_141;
pointer global_c95c99c104c101c99c107;
function_204:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c50); /* fn_12 */
  goto top_level_apply;
/* _check */
body_141:
  increment_count(env);
  val = wrap_function((&&function_204), env);
  global_c95c99c104c101c99c107 = val; /* _check */
  goto body_142;
pointer global_c102c110c95c49c51;
function_205:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c61); /* __= */
  goto top_level_apply;
function_206:
  increment_count(env);
  val = wrap_function((&&function_205), env);
  goto pop_function;
/* fn_13 */
body_142:
  increment_count(env);
  val = wrap_function((&&function_206), env);
  global_c102c110c95c49c51 = val; /* fn_13 */
  goto body_143;
pointer global_c95c109c97c116c99c104;
function_207:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_208:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c51); /* fn_13 */
  target = (&&function_207);
  goto apply_addr;
/* _match */
body_143:
  increment_count(env);
  val = wrap_function((&&function_208), env);
  global_c95c109c97c116c99c104 = val; /* _match */
  goto body_144;
pointer global_c102c110c95c49c52;
function_209:
  increment_count(val = car(car(cdr(env))));
  goto pop_function;
function_210:
  increment_count(env);
  val = wrap_function((&&function_209), env);
  goto pop_function;
/* fn_14 */
body_144:
  increment_count(env);
  val = wrap_function((&&function_210), env);
  global_c102c110c95c49c52 = val; /* fn_14 */
  goto body_145;
pointer global_c95c100c101c102c97c117c108c116;
function_211:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c52); /* fn_14 */
  goto top_level_apply;
/* _default */
body_145:
  increment_count(env);
  val = wrap_function((&&function_211), env);
  global_c95c100c101c102c97c117c108c116 = val; /* _default */
  goto body_146;
pointer global_c102c110c95c49c55; /* fn_17 */
pointer global_c102c110c95c49c56;
function_212:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c55); /* fn_17 */
  goto top_level_apply;
function_213:
  increment_count(env);
  val = wrap_function((&&function_212), env);
  goto pop_function;
/* fn_18 */
body_146:
global_c102c110c95c49c55 = NIL; /* fn_17 */
  increment_count(env);
  val = wrap_function((&&function_213), env);
  global_c102c110c95c49c56 = val; /* fn_18 */
  goto body_147;
pointer global_c102c110c95c49c54; /* fn_16 */
pointer global_c102c110c95c49c53; /* fn_15 */
function_214:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_215:
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
  increment_count(val = global_c102c110c95c49c53); /* fn_15 */
  target = (&&function_214);
  goto apply_addr;
function_216:
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
  increment_count(val = global_c102c110c95c49c54); /* fn_16 */
  target = (&&function_215);
  goto apply_addr;
function_217:
  increment_count(env);
  val = wrap_function((&&function_216), env);
  goto pop_function;
/* fn_17 */
body_147:
global_c102c110c95c49c54 = NIL; /* fn_16 */
global_c102c110c95c49c53 = NIL; /* fn_15 */
  increment_count(env);
  val = wrap_function((&&function_217), env);
  global_c102c110c95c49c55 = val; /* fn_17 */
  goto body_148;
function_218:
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
function_219:
  increment_count(env);
  val = wrap_function((&&function_218), env);
  goto pop_function;
/* fn_15 */
body_148:
  increment_count(env);
  val = wrap_function((&&function_219), env);
  global_c102c110c95c49c53 = val; /* fn_15 */
  goto body_149;
function_220:
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
function_221:
  increment_count(env);
  val = wrap_function((&&function_220), env);
  goto pop_function;
/* fn_16 */
body_149:
  increment_count(env);
  val = wrap_function((&&function_221), env);
  global_c102c110c95c49c54 = val; /* fn_16 */
  goto body_150;
pointer global_c95c99c97c115c101;
function_222:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c49c56); /* fn_18 */
  goto top_level_apply;
/* _case */
body_150:
  increment_count(env);
  val = wrap_function((&&function_222), env);
  global_c95c99c97c115c101 = val; /* _case */
  goto body_151;
pointer global_c95c99c104c111c105c99c101;
function_223:
  goto top_level_apply;
function_224:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  goto top_level_apply;
function_225:
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_224), env);
  args = cons(val, args);
  increment_count(val = global_c95c102c111c108c100c114); /* _foldr */
  target = (&&function_223);
  goto apply_addr;
function_226:
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
  target = (&&function_225);
  goto apply_addr;
/* _choice */
body_151:
  increment_count(env);
  val = wrap_function((&&function_226), env);
  global_c95c99c104c111c105c99c101 = val; /* _choice */
  goto body_152;
pointer global_c102c110c95c49c57; /* fn_19 */
pointer global_c102c110c95c50c48;
function_227:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_228:
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
  increment_count(val = global_c102c110c95c49c57); /* fn_19 */
  target = (&&function_227);
  goto apply_addr;
function_229:
  increment_count(env);
  val = wrap_function((&&function_228), env);
  goto pop_function;
/* fn_20 */
body_152:
global_c102c110c95c49c57 = NIL; /* fn_19 */
  increment_count(env);
  val = wrap_function((&&function_229), env);
  global_c102c110c95c50c48 = val; /* fn_20 */
  goto body_153;
function_230:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_231:
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
  target = (&&function_230);
  goto apply_addr;
function_232:
  increment_count(env);
  val = wrap_function((&&function_231), env);
  goto pop_function;
/* fn_19 */
body_153:
  increment_count(env);
  val = wrap_function((&&function_232), env);
  global_c102c110c95c49c57 = val; /* fn_19 */
  goto body_154;
pointer global_c95c112c111c115c116c45c112c114c111c99c101c115c115;
function_233:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c48); /* fn_20 */
  goto top_level_apply;
/* _post-process */
body_154:
  increment_count(env);
  val = wrap_function((&&function_233), env);
  global_c95c112c111c115c116c45c112c114c111c99c101c115c115 = val; /* _post-process */
  goto body_155;
pointer global_c102c110c95c50c50; /* fn_22 */
pointer global_c102c110c95c50c51;
function_234:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_235:
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
  increment_count(val = global_c102c110c95c50c50); /* fn_22 */
  target = (&&function_234);
  goto apply_addr;
function_236:
  increment_count(env);
  val = wrap_function((&&function_235), env);
  goto pop_function;
/* fn_23 */
body_155:
global_c102c110c95c50c50 = NIL; /* fn_22 */
  increment_count(env);
  val = wrap_function((&&function_236), env);
  global_c102c110c95c50c51 = val; /* fn_23 */
  goto body_156;
pointer global_c102c110c95c50c49; /* fn_21 */
function_237:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_238:
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
  increment_count(val = global_c102c110c95c50c49); /* fn_21 */
  target = (&&function_237);
  goto apply_addr;
function_239:
  increment_count(env);
  val = wrap_function((&&function_238), env);
  goto pop_function;
/* fn_22 */
body_156:
global_c102c110c95c50c49 = NIL; /* fn_21 */
  increment_count(env);
  val = wrap_function((&&function_239), env);
  global_c102c110c95c50c50 = val; /* fn_22 */
  goto body_157;
function_240:
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
function_241:
  increment_count(env);
  val = wrap_function((&&function_240), env);
  goto pop_function;
/* fn_21 */
body_157:
  increment_count(env);
  val = wrap_function((&&function_241), env);
  global_c102c110c95c50c49 = val; /* fn_21 */
  goto body_158;
pointer global_c95c115c101c113;
function_242:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c51); /* fn_23 */
  goto top_level_apply;
/* _seq */
body_158:
  increment_count(env);
  val = wrap_function((&&function_242), env);
  global_c95c115c101c113 = val; /* _seq */
  goto body_159;
pointer global_c95c101c115c99c97c112c101;
function_243:
  args = cons(val, args);
  increment_count(val = global_c95c115c101c113); /* _seq */
  goto top_level_apply;
function_244:
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
  target = (&&function_243);
  goto apply_addr;
/* _escape */
body_159:
  increment_count(env);
  val = wrap_function((&&function_244), env);
  global_c95c101c115c99c97c112c101 = val; /* _escape */
  goto body_160;
pointer global_c95c117c115c101;
function_245:
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
body_160:
  increment_count(env);
  val = wrap_function((&&function_245), env);
  global_c95c117c115c101 = val; /* _use */
  goto body_161;
pointer global_c102c110c95c50c52; /* fn_24 */
pointer global_c102c110c95c50c53;
function_246:
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  goto top_level_apply;
function_247:
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
  increment_count(val = global_c102c110c95c50c52); /* fn_24 */
  target = (&&function_246);
  goto apply_addr;
function_248:
  increment_count(env);
  val = wrap_function((&&function_247), env);
  goto pop_function;
/* fn_25 */
body_161:
global_c102c110c95c50c52 = NIL; /* fn_24 */
  increment_count(env);
  val = wrap_function((&&function_248), env);
  global_c102c110c95c50c53 = val; /* fn_25 */
  goto body_162;
function_249:
  goto top_level_apply;
function_250:
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
  target = (&&function_249);
  goto apply_addr;
function_251:
  increment_count(env);
  val = wrap_function((&&function_250), env);
  goto pop_function;
/* fn_24 */
body_162:
  increment_count(env);
  val = wrap_function((&&function_251), env);
  global_c102c110c95c50c52 = val; /* fn_24 */
  goto body_163;
pointer global_c95c112c101c101c107;
function_252:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c53); /* fn_25 */
  goto top_level_apply;
/* _peek */
body_163:
  increment_count(env);
  val = wrap_function((&&function_252), env);
  global_c95c112c101c101c107 = val; /* _peek */
  goto body_164;
pointer global_c102c110c95c50c54;
function_253:
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
function_254:
  increment_count(env);
  val = wrap_function((&&function_253), env);
  goto pop_function;
/* fn_26 */
body_164:
  increment_count(env);
  val = wrap_function((&&function_254), env);
  global_c102c110c95c50c54 = val; /* fn_26 */
  goto body_165;
pointer global_c95c105c110c116c101c114c118c97c108;
function_255:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c101c99c107); /* _check */
  goto top_level_apply;
function_256:
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
  increment_count(val = global_c102c110c95c50c54); /* fn_26 */
  target = (&&function_255);
  goto apply_addr;
/* _interval */
body_165:
  increment_count(env);
  val = wrap_function((&&function_256), env);
  global_c95c105c110c116c101c114c118c97c108 = val; /* _interval */
  goto body_166;
pointer global_c99c100c114; /* cdr */
pointer global_c95c115c107c105c112;
function_257:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_258:
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
  target = (&&function_257);
  goto apply_addr;
/* _skip */
body_166:
global_c99c100c114 = CDR; /* cdr */
  increment_count(env);
  val = wrap_function((&&function_258), env);
  global_c95c115c107c105c112 = val; /* _skip */
  goto body_167;
pointer global_c99c97c114; /* car */
pointer global_c95c102c105c114c115c116;
function_259:
  args = cons(val, args);
  increment_count(val = global_c95c112c111c115c116c45c112c114c111c99c101c115c115); /* _post-process */
  goto top_level_apply;
function_260:
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
  target = (&&function_259);
  goto apply_addr;
/* _first */
body_167:
global_c99c97c114 = CAR; /* car */
  increment_count(env);
  val = wrap_function((&&function_260), env);
  global_c95c102c105c114c115c116 = val; /* _first */
  goto body_168;
pointer global_c95c112c97c114c115c101c45c110c117c109;
function_261:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_262:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_261);
  goto apply_addr;
function_263:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_262);
  goto apply_addr;
function_264:
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
  target = (&&function_263);
  goto apply_addr;
function_265:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_264);
  goto apply_addr;
function_266:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_265);
  goto apply_addr;
function_267:
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
  target = (&&function_266);
  goto apply_addr;
function_268:
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
  target = (&&function_267);
  goto apply_addr;
function_269:
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
  target = (&&function_268);
  goto apply_addr;
/* _parse-num */
body_168:
  increment_count(env);
  val = wrap_function((&&function_269), env);
  global_c95c112c97c114c115c101c45c110c117c109 = val; /* _parse-num */
  goto body_169;
pointer global_c95c114c101c97c100c45c110c117c109;
function_270:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_271:
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
  target = (&&function_270);
  goto apply_addr;
/* _read-num */
body_169:
  increment_count(env);
  val = wrap_function((&&function_271), env);
  global_c95c114c101c97c100c45c110c117c109 = val; /* _read-num */
  goto body_170;
pointer global_c95c112c97c114c115c101c45c115c121c109c98c111c108;
function_272:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_273:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_272);
  goto apply_addr;
function_274:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_273);
  goto apply_addr;
function_275:
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
  target = (&&function_274);
  goto apply_addr;
function_276:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_275);
  goto apply_addr;
function_277:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_276);
  goto apply_addr;
function_278:
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
  target = (&&function_277);
  goto apply_addr;
function_279:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_278);
  goto apply_addr;
function_280:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_279);
  goto apply_addr;
function_281:
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
  target = (&&function_280);
  goto apply_addr;
function_282:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_281);
  goto apply_addr;
function_283:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_282);
  goto apply_addr;
function_284:
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
  target = (&&function_283);
  goto apply_addr;
function_285:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_284);
  goto apply_addr;
function_286:
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
  target = (&&function_285);
  goto apply_addr;
/* _parse-symbol */
body_170:
  increment_count(env);
  val = wrap_function((&&function_286), env);
  global_c95c112c97c114c115c101c45c115c121c109c98c111c108 = val; /* _parse-symbol */
  goto body_171;
pointer global_c95c114c101c97c100c45c115c121c109c98c111c108;
function_287:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_288:
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
  target = (&&function_287);
  goto apply_addr;
/* _read-symbol */
body_171:
  increment_count(env);
  val = wrap_function((&&function_288), env);
  global_c95c114c101c97c100c45c115c121c109c98c111c108 = val; /* _read-symbol */
  goto body_172;
pointer global_c95c112c97c114c115c101c45c115c116c114c105c110c103;
function_289:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_290:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_289);
  goto apply_addr;
function_291:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_290);
  goto apply_addr;
function_292:
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
  target = (&&function_291);
  goto apply_addr;
function_293:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_292);
  goto apply_addr;
function_294:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_293);
  goto apply_addr;
function_295:
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
  target = (&&function_294);
  goto apply_addr;
function_296:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_295);
  goto apply_addr;
function_297:
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
  target = (&&function_296);
  goto apply_addr;
/* _parse-string */
body_172:
  increment_count(env);
  val = wrap_function((&&function_297), env);
  global_c95c112c97c114c115c101c45c115c116c114c105c110c103 = val; /* _parse-string */
  goto body_173;
pointer global_c95c113c117c111c116c101c45c112c97c114c115c101c114;
function_298:
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
body_173:
  increment_count(env);
  val = wrap_function((&&function_298), env);
  global_c95c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quote-parser */
  goto body_174;
pointer global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114;
function_299:
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
body_174:
  increment_count(env);
  val = wrap_function((&&function_299), env);
  global_c95c113c117c97c115c105c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _quasiquote-parser */
  goto body_175;
pointer global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114;
function_300:
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
body_175:
  increment_count(env);
  val = wrap_function((&&function_300), env);
  global_c95c117c110c113c117c111c116c101c45c112c97c114c115c101c114 = val; /* _unquote-parser */
  goto body_176;
pointer global_c95c99c111c109c109c101c110c116; /* _comment */
pointer global_c102c110c95c50c55;
function_301:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_302:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_301);
  goto apply_addr;
function_303:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_302);
  goto apply_addr;
function_304:
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
  target = (&&function_303);
  goto apply_addr;
function_305:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_304);
  goto apply_addr;
function_306:
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
  target = (&&function_305);
  goto apply_addr;
function_307:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_306);
  goto apply_addr;
function_308:
  args = cons(val, args);
  increment_count(val = global_c95c115c107c105c112); /* _skip */
  target = (&&function_307);
  goto apply_addr;
function_309:
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
  target = (&&function_308);
  goto apply_addr;
function_310:
  increment_count(env);
  val = wrap_function((&&function_309), env);
  goto pop_function;
/* fn_27 */
body_176:
global_c95c99c111c109c109c101c110c116 = NIL; /* _comment */
  increment_count(env);
  val = wrap_function((&&function_310), env);
  global_c102c110c95c50c55 = val; /* fn_27 */
  goto body_177;
function_311:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c55); /* fn_27 */
  goto top_level_apply;
/* _comment */
body_177:
  increment_count(env);
  val = wrap_function((&&function_311), env);
  global_c95c99c111c109c109c101c110c116 = val; /* _comment */
  goto body_178;
pointer global_c95c112c97c114c115c101c45c112c97c114c101c110;
function_312:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_313:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_312);
  goto apply_addr;
function_314:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_313);
  goto apply_addr;
function_315:
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
  target = (&&function_314);
  goto apply_addr;
function_316:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_315);
  goto apply_addr;
function_317:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_316);
  goto apply_addr;
function_318:
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
  target = (&&function_317);
  goto apply_addr;
function_319:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_318);
  goto apply_addr;
function_320:
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
  target = (&&function_319);
  goto apply_addr;
function_321:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_320);
  goto apply_addr;
function_322:
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
  target = (&&function_321);
  goto apply_addr;
/* _parse-paren */
body_178:
  increment_count(env);
  val = wrap_function((&&function_322), env);
  global_c95c112c97c114c115c101c45c112c97c114c101c110 = val; /* _parse-paren */
  goto body_179;
pointer global_c95c112c97c114c115c101c45c101c120c112c114; /* _parse-expr */
pointer global_c95c112c97c114c115c101c45c112c97c105c114;
function_323:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_324:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_323);
  goto apply_addr;
function_325:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_324);
  goto apply_addr;
function_326:
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
  target = (&&function_325);
  goto apply_addr;
function_327:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_326);
  goto apply_addr;
function_328:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_327);
  goto apply_addr;
function_329:
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
  target = (&&function_328);
  goto apply_addr;
function_330:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_329);
  goto apply_addr;
function_331:
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
  target = (&&function_330);
  goto apply_addr;
function_332:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_331);
  goto apply_addr;
function_333:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_332);
  goto apply_addr;
function_334:
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
  target = (&&function_333);
  goto apply_addr;
function_335:
  args = cons(val, args);
  increment_count(val = global_c95c100c101c102c97c117c108c116); /* _default */
  target = (&&function_334);
  goto apply_addr;
function_336:
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
  target = (&&function_335);
  goto apply_addr;
/* _parse-pair */
body_179:
global_c95c112c97c114c115c101c45c101c120c112c114 = NIL; /* _parse-expr */
  increment_count(env);
  val = wrap_function((&&function_336), env);
  global_c95c112c97c114c115c101c45c112c97c105c114 = val; /* _parse-pair */
  goto body_180;
function_337:
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c108c121); /* _apply */
  goto top_level_apply;
function_338:
  args = cons(val, args);
  increment_count(val = global_c95c99c104c111c105c99c101); /* _choice */
  target = (&&function_337);
  goto apply_addr;
function_339:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_338);
  goto apply_addr;
function_340:
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
  target = (&&function_339);
  goto apply_addr;
function_341:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_340);
  goto apply_addr;
function_342:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_341);
  goto apply_addr;
function_343:
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
  target = (&&function_342);
  goto apply_addr;
function_344:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_343);
  goto apply_addr;
function_345:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_344);
  goto apply_addr;
function_346:
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
  target = (&&function_345);
  goto apply_addr;
function_347:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_346);
  goto apply_addr;
function_348:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_347);
  goto apply_addr;
function_349:
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
  target = (&&function_348);
  goto apply_addr;
function_350:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_349);
  goto apply_addr;
function_351:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_350);
  goto apply_addr;
function_352:
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
  target = (&&function_351);
  goto apply_addr;
function_353:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_352);
  goto apply_addr;
function_354:
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
  target = (&&function_353);
  goto apply_addr;
function_355:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_354);
  goto apply_addr;
function_356:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_355);
  goto apply_addr;
function_357:
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
  target = (&&function_356);
  goto apply_addr;
function_358:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_357);
  goto apply_addr;
function_359:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_358);
  goto apply_addr;
function_360:
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
  target = (&&function_359);
  goto apply_addr;
function_361:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_360);
  goto apply_addr;
function_362:
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_c95c109c97c116c99c104); /* _match */
  target = (&&function_361);
  goto apply_addr;
function_363:
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
  target = (&&function_362);
  goto apply_addr;
function_364:
  args = cons(val, args);
  increment_count(val = global_c95c99c97c115c101); /* _case */
  target = (&&function_363);
  goto apply_addr;
function_365:
  args = cons(val, args);
  increment_count(val = global_c95c112c101c101c107); /* _peek */
  target = (&&function_364);
  goto apply_addr;
function_366:
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
  target = (&&function_365);
  goto apply_addr;
function_367:
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
  target = (&&function_366);
  goto apply_addr;
/* _parse-expr */
body_180:
  increment_count(env);
  val = wrap_function((&&function_367), env);
  global_c95c112c97c114c115c101c45c101c120c112c114 = val; /* _parse-expr */
  goto body_181;
pointer global_c95c95c95c95c114c101c97c100c45c101c120c112c114;
function_368:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
  goto top_level_apply;
function_369:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c51); /* ___l_83 */
  args = cons(val, args);
  increment_count(val = global_c95c97c112c112c101c110c100); /* _append */
  target = (&&function_368);
  goto apply_addr;
function_370:
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c56c53); /* ___l_85 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c56c52); /* ___l_84 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_c95c112c114c105c110c116); /* _print */
  target = (&&function_369);
  goto apply_addr;
function_371:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = wrap_function((&&function_370), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c112c97c114c115c101c45c101c120c112c114); /* _parse-expr */
  goto top_level_apply;
/* ____read-expr */
body_181:
  increment_count(env);
  val = wrap_function((&&function_371), env);
  global_c95c95c95c95c114c101c97c100c45c101c120c112c114 = val; /* ____read-expr */
  goto body_182;
pointer global_c95c95c95c108c95c56c54;
/* ___l_86 */
body_182:
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
  global_c95c95c95c108c95c56c54 = val; /* ___l_86 */
  goto body_183;
pointer global_c95c95c95c108c95c56c55;
/* ___l_87 */
body_183:
  val = -35;
  global_c95c95c95c108c95c56c55 = val; /* ___l_87 */
  goto body_184;
pointer global_c95c95c95c108c95c56c56;
/* ___l_88 */
body_184:
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
  global_c95c95c95c108c95c56c56 = val; /* ___l_88 */
  goto body_185;
pointer global_c95c99c97c97c100c114;
function_372:
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
body_185:
  increment_count(env);
  val = wrap_function((&&function_372), env);
  global_c95c99c97c97c100c114 = val; /* _caadr */
  goto body_186;
pointer global_c95c114c101c118c101c114c115c101;
function_373:
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
body_186:
  increment_count(env);
  val = wrap_function((&&function_373), env);
  global_c95c114c101c118c101c114c115c101 = val; /* _reverse */
  goto body_187;
pointer global_c95c110c111c116;
function_374:
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    goto pop_function;
  } else {
    val = -34;
    goto pop_function;
  }
/* _not */
body_187:
  increment_count(env);
  val = wrap_function((&&function_374), env);
  global_c95c110c111c116 = val; /* _not */
  goto body_188;
pointer global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101; /* ____compile-source */
pointer global_c102c110c95c50c56;
function_375:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101); /* ____compile */
  goto top_level_apply;
function_376:
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_c95c114c101c118c101c114c115c101); /* _reverse */
  target = (&&function_375);
  goto apply_addr;
function_377:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_378:
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
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
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_377);
  goto apply_addr;
function_379:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c56); /* ___l_88 */
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c112c114c105c110c116c45c101c114c114c111c114); /* ____print-error */
    goto top_level_apply;
  } else {
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
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
    target = (&&function_378);
    goto apply_addr;
  }
function_380:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_379);
  goto apply_addr;
function_381:
  args = cons(val, args);
  increment_count(val = global_c95c111c114); /* _or */
  target = (&&function_380);
  goto apply_addr;
function_382:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_381);
  goto apply_addr;
function_383:
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
  target = (&&function_382);
  goto apply_addr;
function_384:
  args = cons(val, args);
  increment_count(val = global_c95c95c97c116c111c109); /* __atom */
  target = (&&function_383);
  goto apply_addr;
function_385:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_c95c95c95c95c108c105c115c116c45c115c121c109c98c111c108c115); /* ____list-symbols */
    target = (&&function_376);
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
    target = (&&function_384);
    goto apply_addr;
  }
function_386:
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_385);
  goto apply_addr;
function_387:
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_c95c95c95c108c95c56c54); /* ___l_86 */
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
    increment_count(val = global_c95c95c95c108c95c56c55); /* ___l_87 */
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
    target = (&&function_386);
    goto apply_addr;
  }
function_388:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c95c110c111c116); /* _not */
  target = (&&function_387);
  goto apply_addr;
function_389:
  increment_count(env);
  val = wrap_function((&&function_388), env);
  goto pop_function;
/* fn_28 */
body_188:
global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = NIL; /* ____compile-source */
  increment_count(env);
  val = wrap_function((&&function_389), env);
  global_c102c110c95c50c56 = val; /* fn_28 */
  goto body_189;
function_390:
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_c102c110c95c50c56); /* fn_28 */
  goto top_level_apply;
/* ____compile-source */
body_189:
  increment_count(env);
  val = wrap_function((&&function_390), env);
  global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101 = val; /* ____compile-source */
  goto body_190;
pointer global_c95c95c95c108c95c49;
/* ___l_1 */
body_190:
  val = NIL;
  global_c95c95c95c108c95c49 = val; /* ___l_1 */
  goto body_191;
pointer global_c95c95c95c108c95c50;
/* ___l_2 */
body_191:
  val = NIL;
  global_c95c95c95c108c95c50 = val; /* ___l_2 */
  goto body_192;
pointer global_c95c95c95c108c95c51;
/* ___l_3 */
body_192:
  val = NIL;
  global_c95c95c95c108c95c51 = val; /* ___l_3 */
  goto body_193;
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
function_391:
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
function_392:
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c114c101c97c100c45c101c120c112c114); /* ____read-expr */
  goto top_level_apply;
function_393:
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c51); /* ___l_3 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_c95c95c95c108c95c50); /* ___l_2 */
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_c95c95c95c108c95c49); /* ___l_1 */
  args = cons(val, args);
  increment_count(val = global_c95c95c95c95c99c111c109c112c105c108c101c45c115c111c117c114c99c101); /* ____compile-source */
  target = (&&function_392);
  goto apply_addr;
body_193:
  increment_count(env);
  val = wrap_function((&&function_393), env);
  goto pop_function;
start_addr:
  true = new_number(1);
  call_stack = cons(wrap_function((&&top_level_addr), NIL), call_stack);
  call_stack = cons(wrap_function((&&function_391), NIL), call_stack);
  goto body_0;
}
