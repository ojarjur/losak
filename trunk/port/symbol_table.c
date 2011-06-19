#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#include "io.h"
#include "mem.h"
#include "eval.h"
pointer arguments = NIL;
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
#ifdef BARE_HARDWARE
pointer get_cmd(unsigned long flags, char* command) {
  pointer r = NIL;
  if (getFlag(flags,2) != 0) {
    r = make_string(command);
  }
  return r;
}
#endif
inline void pop_function() {
  decrement_count(env);
  temp = car(call_stack);
  if (is_function(temp)) {
    env = environment(temp);
    increment_count(env);
    return_location = address(temp);
  } else {
    error(ERR_INTERNAL);
    env = NIL;
    return_location = (&end_function);
  }
  increment_count(temp = cdr(call_stack));
  decrement_count(call_stack);
  call_stack = temp;
}
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
inline void top_level_apply() {
  if (is_function(val)) {
    decrement_count(env);
    return_location = address(val);
    increment_count(env = environment(val));
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
    pop_function();
  }
  pop_args();
}
inline void apply(function_addr func) {
  if (is_function(val)) {
    call_stack = cons(new_function(func, env), call_stack);
    return_location = address(val);
    increment_count(env = environment(val));
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
    return_location = func;
  }
  pop_args();
}
pointer global_4;
void function_0() {
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
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = car(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
pointer global_6;
void function_1() {
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
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  pop_function();
}
pointer global_7;
void function_2() {
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
  pop_function();
}
pointer global_8;
void function_3() {
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
  pop_function();
}
pointer global_9;
void function_4() {
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
  pop_function();
}
pointer global_10;
void function_5() {
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
  pop_function();
}
pointer global_11;
void function_6() {
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
  pop_function();
}
pointer global_12;
void function_7() {
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
  pop_function();
}
pointer global_13;
void function_8() {
  increment_count(val = car(car(env)));
  pop_function();
}
pointer global_14;
void function_9() {
  increment_count(val = car(env));
  pop_function();
}
pointer global_16;
void function_10() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
pointer global_18;
void function_11() {
  top_level_apply();
}
void function_12() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_11));
}
void function_13() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_12), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_14() {
  top_level_apply();
}
void function_15() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_14));
}
void function_16() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_15), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_17() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_16), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_13), env);
  top_level_apply();
}
pointer global_20;
void function_18() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_19() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_18));
}
void function_20() {
  apply((&function_19));
}
void function_21() {
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_20); /* _walk */
  apply((&function_20));
}
void function_22() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
    top_level_apply();
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
    increment_count(val = car(cdr(car(cdr(env)))));
    apply((&function_21));
  }
}
void function_23() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_22));
}
void function_24() {
  increment_count(env);
  val = new_function((&function_23), env);
  pop_function();
}
pointer global_27;
void function_25() {
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
    increment_count(val = car(cdr(cdr(car(env)))));
    top_level_apply();
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
    increment_count(val = global_27); /* _rreverse */
    top_level_apply();
  }
}
pointer global_30;
pointer global_31;
void function_26() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_13); /* _id */
  args = cons(val, args);
  increment_count(val = global_30); /* l_3 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_27); /* _rreverse */
  top_level_apply();
}
pointer global_32;
void function_27() {
  top_level_apply();
}
void function_28() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_32); /* _foldl */
  apply((&function_27));
}
void function_29() {
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
    increment_count(val = car(cdr(car(cdr(env)))));
    pop_function();
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
    apply((&function_28));
  }
}
void function_30() {
  increment_count(env);
  val = new_function((&function_29), env);
  pop_function();
}
pointer global_34;
pointer global_35;
void function_31() {
  args = cons(val, args);
  increment_count(val = global_34); /* l_4 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_27); /* _rreverse */
  top_level_apply();
}
void function_32() {
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
  increment_count(val = global_32); /* _foldl */
  apply((&function_31));
}
void function_33() {
  increment_count(env);
  val = new_function((&function_32), env);
  pop_function();
}
pointer global_36;
pointer global_37;
pointer global_38;
void function_34() {
  top_level_apply();
}
void function_35() {
  top_level_apply();
}
void function_36() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_36); /* l_5 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
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
    increment_count(val = car(car(env)));
    pop_function();
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
    val = CONS;
    args = cons(val, args);
    increment_count(val = global_35); /* _foldr */
    apply((&function_35));
  }
}
void function_37() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_37); /* l_6 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_36), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_34));
}
pointer global_40;
pointer global_41;
pointer global_42;
void function_38() {
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
    increment_count(val = global_42); /* _equal */
    top_level_apply();
  } else {
    increment_count(val = global_41); /* l_8 */
    pop_function();
  }
}
void function_39() {
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
    pop_function();
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
      increment_count(val = global_40); /* l_7 */
      pop_function();
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
      increment_count(val = global_42); /* _equal */
      apply((&function_38));
    }
  }
}
pointer global_44;
pointer global_45;
void function_40() {
  top_level_apply();
}
void function_41() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_42() {
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
  apply((&function_41));
}
void function_43() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_44); /* l_9 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_42), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_40));
}
pointer global_46;
pointer global_47;
void function_44() {
  top_level_apply();
}
void function_45() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(car(env)));
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_46() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_46); /* l_10 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_45), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_44));
}
pointer global_50;
pointer global_51;
pointer global_53;
void function_47() {
  top_level_apply();
}
void function_48() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_50); /* l_11 */
    pop_function();
  }
}
void function_49() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_51); /* l_12 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_48), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_47));
}
pointer global_54;
pointer global_55;
pointer global_56;
void function_50() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_54); /* l_13 */
    pop_function();
  } else {
    increment_count(val = global_55); /* l_14 */
    pop_function();
  }
}
pointer global_57;
pointer global_58;
void function_51() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_57); /* l_15 */
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_52() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_51));
}
void function_53() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_52), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  top_level_apply();
}
pointer global_62;
void function_54() {
  global_62 = val; /* _map-to-stderr */
}
void function_55() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_56() {
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
  increment_count(val = global_14); /* _list */
  apply((&function_55));
}
pointer global_65;
pointer global_66;
pointer global_67;
void function_57() {
  args = cons(val, args);
  increment_count(val = global_62); /* _map-to-stderr */
  top_level_apply();
}
void function_58() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_66); /* l_17 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_65); /* l_16 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_57));
}
pointer global_69;
void function_59() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_60() {
  increment_count(env);
  val = new_function((&function_59), env);
  pop_function();
}
pointer global_71;
void function_61() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_62() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_61), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
pointer global_73;
void function_63() {
  args = cons(val, args);
  if ((length(args) == 2) &&
      (is_atom(car(args))) &&
      (is_atom(car(cdr(args)))) &&
      eq(car(args), car(cdr(args)))) {
    increment_count(val = true);
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_64() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_71); /* _symbol->id */
  apply((&function_63));
}
void function_65() {
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
    increment_count(val = global_71); /* _symbol->id */
    apply((&function_64));
  } else {
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
    pop_function();
  }
}
void function_66() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_function(car(args))) {
      increment_count(val = true);
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
    if (is_function(car(args))) {
      increment_count(val = true);
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_53); /* _and */
  apply((&function_65));
}
pointer global_76;
void function_67() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_68() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_67), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
pointer global_77;
void function_69() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_70() {
  if (val != NIL) {
    decrement_count(val);
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
    increment_count(val = global_6); /* _cdar */
    apply((&function_69));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    val = new_number(1);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    if ((length(args) == 2) &&
        (is_number(car(args))) &&
        (is_number(car(cdr(args))))) {
      val = new_number(value(car(args)) + value(car(cdr(args)))); 
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
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
    increment_count(val = global_77); /* _lookup */
    top_level_apply();
  }
}
void function_71() {
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_70));
}
void function_72() {
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
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
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
    if (length(args) == 2) {
      increment_count(car(args));
      increment_count(car(cdr(args)));
      val = cons(car(args), car(cdr(args)));
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
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
    increment_count(val = global_4); /* _caar */
    apply((&function_71));
  }
}
pointer global_82;
void function_73() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_74() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_69); /* _make-symbol */
  apply((&function_73));
}
void function_75() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_74), env);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_77); /* _lookup */
  top_level_apply();
}
pointer global_84;
pointer global_85;
pointer global_86;
void function_76() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_85); /* l_19 */
    pop_function();
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
    increment_count(val = global_86); /* _symbol-present? */
    top_level_apply();
  }
}
void function_77() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_76));
}
void function_78() {
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
    increment_count(val = global_84); /* l_18 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_4); /* _caar */
    apply((&function_77));
  }
}
pointer global_89;
pointer global_90;
void function_79() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_90); /* _generate-unused-symbol-name */
  top_level_apply();
}
void function_80() {
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
    increment_count(val = global_89); /* l_20 */
    args = cons(val, args);
    increment_count(val = global_38); /* _append */
    apply((&function_79));
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_81() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_86); /* _symbol-present? */
  apply((&function_80));
}
pointer global_92;
pointer global_93;
pointer global_94;
pointer global_95;
pointer global_96;
pointer global_97;
pointer global_98;
pointer global_105 = NIL; /* _print-atom */
pointer global_99;
void function_82() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_96); /* l_25 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_95); /* l_24 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_94); /* l_23 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_83() {
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
  increment_count(val = global_99); /* _build-string->symbol-cases */
  apply((&function_82));
}
void function_84() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_97); /* l_26 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_83));
}
void function_85() {
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
  increment_count(val = global_98); /* l_27 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_84));
}
void function_86() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_85), env);
  top_level_apply();
}
void function_87() {
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
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_93); /* l_22 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_92); /* l_21 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_38); /* _append */
    top_level_apply();
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
    increment_count(val = global_105); /* _print-atom */
    apply((&function_86));
  }
}
pointer global_106;
pointer global_107;
pointer global_108;
pointer global_109;
pointer global_110;
pointer global_111;
pointer global_112;
pointer global_113;
pointer global_114;
pointer global_115;
pointer global_116;
void function_88() {
  args = cons(val, args);
  increment_count(val = global_113); /* l_35 */
  args = cons(val, args);
  increment_count(val = global_112); /* l_34 */
  args = cons(val, args);
  increment_count(val = global_111); /* l_33 */
  args = cons(val, args);
  increment_count(val = global_110); /* l_32 */
  args = cons(val, args);
  increment_count(val = global_109); /* l_31 */
  args = cons(val, args);
  increment_count(val = global_108); /* l_30 */
  args = cons(val, args);
  increment_count(val = global_107); /* l_29 */
  args = cons(val, args);
  increment_count(val = global_106); /* l_28 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_89() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_115); /* l_37 */
  args = cons(val, args);
  increment_count(val = global_114); /* l_36 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_99); /* _build-string->symbol-cases */
  apply((&function_88));
}
pointer global_117;
pointer global_118;
pointer global_119;
pointer global_120;
pointer global_121;
pointer global_122;
pointer global_123;
pointer global_124;
void function_90() {
  args = cons(val, args);
  increment_count(val = global_121); /* l_42 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_120); /* l_41 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_119); /* l_40 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_118); /* l_39 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_91() {
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
  increment_count(val = global_124); /* _build-symbol->string-cases */
  apply((&function_90));
}
void function_92() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_122); /* l_43 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_91));
}
void function_93() {
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
  increment_count(val = global_123); /* l_44 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_92));
}
void function_94() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_93), env);
  top_level_apply();
}
void function_95() {
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_117); /* l_38 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_38); /* _append */
    top_level_apply();
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
    increment_count(val = global_105); /* _print-atom */
    apply((&function_94));
  }
}
pointer global_125;
pointer global_126;
pointer global_127;
pointer global_128;
pointer global_129;
pointer global_130;
pointer global_131;
pointer global_132;
pointer global_133;
pointer global_134;
pointer global_135;
pointer global_136;
pointer global_137;
pointer global_138;
pointer global_139;
pointer global_140;
void function_96() {
  args = cons(val, args);
  increment_count(val = global_133); /* l_53 */
  args = cons(val, args);
  increment_count(val = global_132); /* l_52 */
  args = cons(val, args);
  increment_count(val = global_131); /* l_51 */
  args = cons(val, args);
  increment_count(val = global_130); /* l_50 */
  args = cons(val, args);
  increment_count(val = global_129); /* l_49 */
  args = cons(val, args);
  increment_count(val = global_128); /* l_48 */
  args = cons(val, args);
  increment_count(val = global_127); /* l_47 */
  args = cons(val, args);
  increment_count(val = global_126); /* l_46 */
  args = cons(val, args);
  increment_count(val = global_125); /* l_45 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_97() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_139); /* l_59 */
  args = cons(val, args);
  increment_count(val = global_138); /* l_58 */
  args = cons(val, args);
  increment_count(val = global_137); /* l_57 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_136); /* l_56 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_135); /* l_55 */
  args = cons(val, args);
  increment_count(val = global_134); /* l_54 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_124); /* _build-symbol->string-cases */
  apply((&function_96));
}
pointer global_141;
void function_98() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(116);
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
    val = new_number(9);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(114);
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
      val = new_number(13);
      args = cons(val, args);
      increment_count(val = car(cdr(car(env))));
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      val = new_number(110);
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
        val = new_number(10);
        args = cons(val, args);
        increment_count(val = car(cdr(car(env))));
        top_level_apply();
      } else {
        increment_count(val = car(car(env)));
        args = cons(val, args);
        increment_count(val = car(cdr(car(env))));
        top_level_apply();
      }
    }
  }
}
pointer global_143;
void function_99() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_100() {
  apply((&function_99));
}
void function_101() {
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
  pop_function();
}
void function_102() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
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
  val = new_function((&function_101), env);
  args = cons(val, args);
  increment_count(val = global_32); /* _foldl */
  apply((&function_100));
}
pointer global_147;
void function_103() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
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
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
pointer global_149;
void function_104() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
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
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
pointer global_150;
pointer global_151;
void function_105() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_106() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_150); /* l_60 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_105));
}
pointer global_153;
pointer global_154;
void function_107() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_108() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_153); /* l_61 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_107));
}
pointer global_155;
pointer global_156;
void function_109() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_110() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_155); /* l_62 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_109));
}
pointer global_157;
pointer global_158;
pointer global_159;
pointer global_160;
pointer global_161;
pointer global_162;
pointer global_163;
pointer global_164;
pointer global_165;
pointer global_166;
pointer global_167;
pointer global_168;
pointer global_169;
pointer global_170;
pointer global_171;
pointer global_172;
pointer global_173;
pointer global_174;
pointer global_175;
pointer global_176;
pointer global_177;
pointer global_178;
pointer global_179;
pointer global_180;
pointer global_181;
pointer global_182;
pointer global_183;
pointer global_184;
pointer global_185;
pointer global_186;
pointer global_187;
pointer global_188;
pointer global_189;
pointer global_190;
pointer global_191;
pointer global_192;
pointer global_193;
pointer global_194;
pointer global_195;
pointer global_196;
pointer global_197;
pointer global_198;
pointer global_199;
pointer global_200;
pointer global_201;
pointer global_202;
pointer global_203;
pointer global_204;
pointer global_205;
pointer global_206;
pointer global_207;
pointer global_208;
pointer global_209;
pointer global_210;
pointer global_211;
pointer global_212;
pointer global_213;
pointer global_214;
pointer global_215;
void function_111() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  top_level_apply();
}
void function_112() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_214); /* l_120 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_111), env);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_82); /* _get-symbol */
    top_level_apply();
  }
}
void function_113() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_212); /* l_118 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_213); /* l_119 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_112));
  }
}
void function_114() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_210); /* l_116 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_211); /* l_117 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_113));
  }
}
void function_115() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_208); /* l_114 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_209); /* l_115 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_114));
  }
}
void function_116() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_206); /* l_112 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_207); /* l_113 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_115));
  }
}
void function_117() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_204); /* l_110 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_205); /* l_111 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_116));
  }
}
void function_118() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_202); /* l_108 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_203); /* l_109 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_117));
  }
}
void function_119() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_200); /* l_106 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_201); /* l_107 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_118));
  }
}
void function_120() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_198); /* l_104 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_199); /* l_105 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_119));
  }
}
void function_121() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_196); /* l_102 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_197); /* l_103 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_120));
  }
}
void function_122() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_194); /* l_100 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_195); /* l_101 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_121));
  }
}
void function_123() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_192); /* l_98 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_193); /* l_99 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_122));
  }
}
void function_124() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_190); /* l_96 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_191); /* l_97 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_123));
  }
}
void function_125() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_188); /* l_94 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_189); /* l_95 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_124));
  }
}
void function_126() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_186); /* l_92 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_187); /* l_93 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_125));
  }
}
void function_127() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_184); /* l_90 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_185); /* l_91 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_126));
  }
}
void function_128() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_182); /* l_88 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_183); /* l_89 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_127));
  }
}
void function_129() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_180); /* l_86 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_181); /* l_87 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_128));
  }
}
void function_130() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_178); /* l_84 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_179); /* l_85 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_129));
  }
}
void function_131() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_176); /* l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_177); /* l_83 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_130));
  }
}
void function_132() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_174); /* l_80 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_175); /* l_81 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_131));
  }
}
void function_133() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_172); /* l_78 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_173); /* l_79 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_132));
  }
}
void function_134() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_170); /* l_76 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_171); /* l_77 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_133));
  }
}
void function_135() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_168); /* l_74 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_169); /* l_75 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_134));
  }
}
void function_136() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_166); /* l_72 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_167); /* l_73 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_135));
  }
}
void function_137() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_164); /* l_70 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_165); /* l_71 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_136));
  }
}
void function_138() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_162); /* l_68 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_163); /* l_69 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_137));
  }
}
void function_139() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_160); /* l_66 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_161); /* l_67 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_138));
  }
}
void function_140() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_158); /* l_64 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_159); /* l_65 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_139));
  }
}
void function_141() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_157); /* l_63 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_140));
}
pointer global_217;
void function_142() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
pointer global_219;
void function_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
pointer global_220;
pointer global_221;
void function_144() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(car(cdr(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(cdr(env)))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(10);
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
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
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
      increment_count(val = car(cdr(cdr(car(cdr(env))))));
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(car(cdr(env))));
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(car(cdr(env))))));
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(car(cdr(env))));
      top_level_apply();
    }
  }
}
void function_145() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_220); /* l_121 */
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
    increment_count(val = global_221); /* _pop */
    top_level_apply();
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
      if (is_number(car(args))) {
        increment_count(val = true);
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_56); /* _not */
    apply((&function_144));
  }
}
void function_146() {
  increment_count(env);
  val = new_function((&function_145), env);
  pop_function();
}
pointer global_222;
void function_147() {
  top_level_apply();
}
void function_148() {
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
    increment_count(val = car(car(cdr(env))));
    top_level_apply();
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
    increment_count(val = car(cdr(car(cdr(env)))));
    apply((&function_147));
  }
}
void function_149() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_148));
}
void function_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_149), env);
  args = cons(val, args);
  increment_count(val = global_221); /* _pop */
  top_level_apply();
}
void function_151() {
  increment_count(env);
  val = new_function((&function_150), env);
  pop_function();
}
pointer global_224;
void function_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
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
  pop_function();
}
void function_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_152), env);
  args = cons(val, args);
  increment_count(val = global_222); /* _check */
  top_level_apply();
}
pointer global_225;
void function_154() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_155() {
  increment_count(env);
  val = new_function((&function_154), env);
  pop_function();
}
pointer global_228;
void function_156() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(cdr(env)))))));
  top_level_apply();
}
void function_157() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_158() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_157), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_156), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_159() {
  increment_count(env);
  val = new_function((&function_158), env);
  pop_function();
}
void function_160() {
  increment_count(env);
  val = new_function((&function_159), env);
  pop_function();
}
pointer global_230;
void function_161() {
  top_level_apply();
}
void function_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_163() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_217); /* _fail */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_162), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_161));
}
pointer global_232;
void function_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_165() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_164), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_166() {
  increment_count(env);
  val = new_function((&function_165), env);
  pop_function();
}
pointer global_233;
void function_167() {
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
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_168() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_167), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_169() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_168), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_170() {
  increment_count(env);
  val = new_function((&function_169), env);
  pop_function();
}
pointer global_236;
void function_171() {
  args = cons(val, args);
  increment_count(val = global_233); /* _seq */
  top_level_apply();
}
void function_172() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_141); /* _escape-char */
  args = cons(val, args);
  increment_count(val = global_221); /* _pop */
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  apply((&function_171));
}
pointer global_237;
void function_173() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_221); /* _pop */
  args = cons(val, args);
  increment_count(val = global_233); /* _seq */
  top_level_apply();
}
pointer global_238;
void function_174() {
  top_level_apply();
}
void function_175() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_174));
}
void function_176() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_175), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_177() {
  increment_count(env);
  val = new_function((&function_176), env);
  pop_function();
}
pointer global_240;
void function_178() {
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
  increment_count(val = global_53); /* _and */
  top_level_apply();
}
void function_179() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_178), env);
  args = cons(val, args);
  increment_count(val = global_222); /* _check */
  top_level_apply();
}
pointer global_242;
void function_180() {
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  top_level_apply();
}
void function_181() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_147); /* _drop-first */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_237); /* _use */
  apply((&function_180));
}
pointer global_243;
void function_182() {
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  top_level_apply();
}
void function_183() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_149); /* _drop-second */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_233); /* _seq */
  apply((&function_182));
}
pointer global_244;
void function_184() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_185() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_184));
}
void function_186() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_185));
}
void function_187() {
  args = cons(val, args);
  increment_count(val = global_238); /* _peek */
  apply((&function_186));
}
void function_188() {
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
  increment_count(val = global_240); /* _interval */
  apply((&function_187));
}
void function_189() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_244); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_237); /* _use */
  apply((&function_188));
}
void function_190() {
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
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_189));
}
pointer global_245;
void function_191() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_192() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_143); /* _build-num */
  args = cons(val, args);
  increment_count(val = global_244); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  apply((&function_191));
}
pointer global_246;
void function_193() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_194() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_193));
}
void function_195() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_194));
}
void function_196() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_240); /* _interval */
  apply((&function_195));
}
void function_197() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_196));
}
void function_198() {
  args = cons(val, args);
  increment_count(val = global_238); /* _peek */
  apply((&function_197));
}
void function_199() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
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
  increment_count(val = global_240); /* _interval */
  apply((&function_198));
}
void function_200() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_199));
}
void function_201() {
  args = cons(val, args);
  increment_count(val = global_238); /* _peek */
  apply((&function_200));
}
void function_202() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_201));
}
void function_203() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_202));
}
void function_204() {
  args = cons(val, args);
  increment_count(val = global_238); /* _peek */
  apply((&function_203));
}
void function_205() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_204));
}
void function_206() {
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_205));
}
void function_207() {
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
  increment_count(val = global_246); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_237); /* _use */
  apply((&function_206));
}
pointer global_247;
void function_208() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_209() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_215); /* _lookup-symbol */
  args = cons(val, args);
  increment_count(val = global_246); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  apply((&function_208));
}
pointer global_248;
void function_210() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_211() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_210));
}
void function_212() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_211));
}
void function_213() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_212));
}
void function_214() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_213));
}
void function_215() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_214));
}
void function_216() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_248); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_236); /* _escape */
  apply((&function_215));
}
void function_217() {
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_216));
}
void function_218() {
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
  increment_count(val = global_248); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_237); /* _use */
  apply((&function_217));
}
pointer global_249;
void function_219() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_151); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  top_level_apply();
}
pointer global_250;
void function_220() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_154); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  top_level_apply();
}
pointer global_251;
void function_221() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_156); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_232); /* _post-process */
  top_level_apply();
}
pointer global_252;
void function_222() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_223() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_222));
}
void function_224() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_223));
}
void function_225() {
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
  increment_count(val = global_224); /* _match */
  apply((&function_224));
}
void function_226() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_225));
}
void function_227() {
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
  increment_count(val = global_224); /* _match */
  apply((&function_226));
}
void function_228() {
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_227));
}
void function_229() {
  args = cons(val, args);
  increment_count(val = global_242); /* _skip */
  apply((&function_228));
}
void function_230() {
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
  increment_count(val = global_252); /* _comment */
  apply((&function_229));
}
void function_231() {
  increment_count(env);
  val = new_function((&function_230), env);
  pop_function();
}
pointer global_253;
void function_232() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_233() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_232));
}
void function_234() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_233));
}
void function_235() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_253); /* _parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_240); /* _interval */
  apply((&function_234));
}
void function_236() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_235));
}
void function_237() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_236));
}
void function_238() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_253); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_252); /* _comment */
  apply((&function_237));
}
void function_239() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_238));
}
void function_240() {
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
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_239));
}
pointer global_255 = NIL; /* _parse-expr */
pointer global_254;
void function_241() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_242() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_241));
}
void function_243() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_242));
}
void function_244() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_254); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_240); /* _interval */
  apply((&function_243));
}
void function_245() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_244));
}
void function_246() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_245));
}
void function_247() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_254); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_252); /* _comment */
  apply((&function_246));
}
void function_248() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_247));
}
void function_249() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_219); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_248));
}
void function_250() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_250));
}
void function_252() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_253); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_243); /* _first */
  apply((&function_251));
}
void function_253() {
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_252));
}
void function_254() {
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
  increment_count(val = global_254); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_233); /* _seq */
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_256() {
  args = cons(val, args);
  increment_count(val = global_230); /* _choice */
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_256));
}
void function_258() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_240); /* _interval */
  apply((&function_257));
}
void function_259() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_258));
}
void function_260() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_259));
}
void function_261() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_248); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_249); /* _quote-parser */
  apply((&function_260));
}
void function_262() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_261));
}
void function_263() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_262));
}
void function_264() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_249); /* _quote-parser */
  apply((&function_263));
}
void function_265() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_264));
}
void function_266() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_265));
}
void function_267() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_250); /* _quasiquote-parser */
  apply((&function_266));
}
void function_268() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_267));
}
void function_269() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_268));
}
void function_270() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_251); /* _unquote-parser */
  apply((&function_269));
}
void function_271() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_270));
}
void function_272() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_254); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_271));
}
void function_273() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_272));
}
void function_274() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_217); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_273));
}
void function_275() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_274));
}
void function_276() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_217); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_275));
}
void function_277() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_276));
}
void function_278() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_224); /* _match */
  apply((&function_277));
}
void function_279() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_255); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_252); /* _comment */
  apply((&function_278));
}
void function_280() {
  args = cons(val, args);
  increment_count(val = global_228); /* _case */
  apply((&function_279));
}
void function_281() {
  args = cons(val, args);
  increment_count(val = global_238); /* _peek */
  apply((&function_280));
}
void function_282() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_245); /* _read-num */
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
  increment_count(val = global_240); /* _interval */
  apply((&function_281));
}
void function_283() {
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
  increment_count(val = global_247); /* _read-symbol */
  args = cons(val, args);
  increment_count(val = global_225); /* _default */
  apply((&function_282));
}
pointer global_256;
pointer global_257;
pointer global_261 = NIL; /* _print-num */
pointer global_258;
void function_284() {
  args = cons(val, args);
  increment_count(val = global_67); /* _print-error */
  top_level_apply();
}
void function_285() {
  args = cons(val, args);
  increment_count(val = global_256); /* l_122 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_284));
}
void function_286() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_257); /* l_123 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_261); /* _print-num */
  apply((&function_285));
}
void function_287() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_286), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_255); /* _parse-expr */
  top_level_apply();
}
pointer global_262;
void function_288() {
  top_level_apply();
}
void function_289() {
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
  pop_function();
}
void function_290() {
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
  pop_function();
}
void function_291() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(0);
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
  pop_function();
}
void function_292() {
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
  increment_count(val = car(car(cdr(env))));
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
  increment_count(val = car(cdr(car(cdr(env)))));
  top_level_apply();
}
void function_293() {
  increment_count(env);
  val = new_function((&function_292), env);
  pop_function();
}
void function_294() {
  increment_count(val = global_13); /* _id */
  pop_function();
}
void function_295() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_294), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_293), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_291), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_290), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_289), env);
  args = cons(val, args);
  increment_count(val = global_20); /* _walk */
  apply((&function_288));
}
pointer global_265;
pointer global_266;
pointer global_267;
void function_296() {
  args = cons(val, args);
  val = new_number(45);
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_297() {
  apply((&function_296));
}
void function_298() {
  top_level_apply();
}
void function_299() {
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
    increment_count(val = global_265); /* l_124 */
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
    increment_count(val = global_262); /* _build-num-str */
    apply((&function_297));
  } else {
    push_args();
    val = NIL;
    args = val;
    val = new_number(0);
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
      increment_count(val = global_266); /* l_125 */
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_267); /* l_126 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_262); /* _build-num-str */
      apply((&function_298));
    }
  }
}
pointer global_268;
pointer global_269;
pointer global_270;
pointer global_271;
pointer global_272;
pointer global_273;
pointer global_274;
pointer global_275;
pointer global_276;
pointer global_277;
pointer global_278;
pointer global_279;
pointer global_280;
pointer global_281;
pointer global_282;
pointer global_283;
pointer global_284;
pointer global_285;
pointer global_286;
pointer global_287;
pointer global_288;
pointer global_289;
pointer global_290;
pointer global_291;
pointer global_292;
pointer global_293;
pointer global_294;
pointer global_295;
pointer global_296;
pointer global_297;
pointer global_298;
pointer global_299;
pointer global_300;
pointer global_301;
pointer global_302;
pointer global_303;
pointer global_304;
pointer global_305;
pointer global_306;
pointer global_307;
pointer global_308;
pointer global_309;
pointer global_310;
pointer global_311;
pointer global_312;
pointer global_313;
pointer global_314;
pointer global_315;
pointer global_316;
pointer global_317;
pointer global_318;
pointer global_319;
pointer global_320;
pointer global_321;
pointer global_322;
pointer global_323;
pointer global_324;
pointer global_325;
pointer global_326;
void function_300() {
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
    increment_count(val = global_261); /* _print-num */
    top_level_apply();
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
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_76); /* _symbol->string */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_268); /* l_127 */
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
        increment_count(val = global_269); /* l_128 */
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_270); /* l_129 */
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
          increment_count(val = global_271); /* l_130 */
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_272); /* l_131 */
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
            increment_count(val = global_273); /* l_132 */
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_274); /* l_133 */
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
              increment_count(val = global_275); /* l_134 */
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_276); /* l_135 */
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
                increment_count(val = global_277); /* l_136 */
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_278); /* l_137 */
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
                  increment_count(val = global_279); /* l_138 */
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  increment_count(val = global_280); /* l_139 */
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
                    increment_count(val = global_281); /* l_140 */
                    pop_function();
                  } else {
                    push_args();
                    val = NIL;
                    args = val;
                    increment_count(val = global_282); /* l_141 */
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
                      increment_count(val = global_283); /* l_142 */
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      increment_count(val = global_284); /* l_143 */
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
                        increment_count(val = global_285); /* l_144 */
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        increment_count(val = global_286); /* l_145 */
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
                          increment_count(val = global_287); /* l_146 */
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          increment_count(val = global_288); /* l_147 */
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
                            increment_count(val = global_289); /* l_148 */
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            increment_count(val = global_290); /* l_149 */
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
                              increment_count(val = global_291); /* l_150 */
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              increment_count(val = global_292); /* l_151 */
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
                                increment_count(val = global_293); /* l_152 */
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                increment_count(val = global_294); /* l_153 */
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
                                  increment_count(val = global_295); /* l_154 */
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  increment_count(val = global_296); /* l_155 */
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
                                    increment_count(val = global_297); /* l_156 */
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    increment_count(val = global_298); /* l_157 */
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
                                      increment_count(val = global_299); /* l_158 */
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      increment_count(val = global_300); /* l_159 */
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
                                        increment_count(val = global_301); /* l_160 */
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        increment_count(val = global_302); /* l_161 */
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
                                          increment_count(val = global_303); /* l_162 */
                                          pop_function();
                                        } else {
                                          push_args();
                                          val = NIL;
                                          args = val;
                                          increment_count(val = global_304); /* l_163 */
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
                                            increment_count(val = global_305); /* l_164 */
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            increment_count(val = global_306); /* l_165 */
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
                                              increment_count(val = global_307); /* l_166 */
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              increment_count(val = global_308); /* l_167 */
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
                                                increment_count(val = global_309); /* l_168 */
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                increment_count(val = global_310); /* l_169 */
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
                                                  increment_count(val = global_311); /* l_170 */
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  increment_count(val = global_312); /* l_171 */
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
                                                    increment_count(val = global_313); /* l_172 */
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    increment_count(val = global_314); /* l_173 */
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
                                                      increment_count(val = global_315); /* l_174 */
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      increment_count(val = global_316); /* l_175 */
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
                                                        increment_count(val = global_317); /* l_176 */
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        increment_count(val = global_318); /* l_177 */
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
                                                          increment_count(val = global_319); /* l_178 */
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          increment_count(val = global_320); /* l_179 */
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
                                                            increment_count(val = global_321); /* l_180 */
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            increment_count(val = global_322); /* l_181 */
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
                                                              increment_count(val = global_323); /* l_182 */
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              increment_count(val = global_324); /* l_183 */
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
                                                                increment_count(val = global_325); /* l_184 */
                                                                pop_function();
                                                              } else {
                                                                increment_count(val = global_326); /* l_185 */
                                                                pop_function();
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
pointer global_327;
pointer global_328;
pointer global_329;
pointer global_330;
pointer global_331;
pointer global_333 = NIL; /* _print-with-suffix */
pointer global_332;
void function_301() {
  args = cons(val, args);
  increment_count(val = global_329); /* l_188 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_302() {
  args = cons(val, args);
  increment_count(val = global_331); /* l_190 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_303() {
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
  increment_count(val = global_333); /* _print-with-suffix */
  apply((&function_302));
}
void function_304() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_327); /* l_186 */
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_328); /* l_187 */
    args = cons(val, args);
    increment_count(val = global_38); /* _append */
    top_level_apply();
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
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(cdr(car(env))));
      args = cons(val, args);
      increment_count(val = global_330); /* l_189 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_105); /* _print-atom */
      apply((&function_301));
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
      increment_count(val = global_332); /* _print-tail */
      apply((&function_303));
    }
  }
}
pointer global_334;
pointer global_335;
pointer global_336;
void function_305() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_306() {
  args = cons(val, args);
  increment_count(val = global_336); /* l_193 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_307() {
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
  increment_count(val = global_333); /* _print-with-suffix */
  apply((&function_306));
}
void function_308() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_334); /* l_191 */
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_335); /* l_192 */
    args = cons(val, args);
    increment_count(val = global_38); /* _append */
    top_level_apply();
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
      increment_count(val = global_105); /* _print-atom */
      apply((&function_305));
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
      increment_count(val = global_332); /* _print-tail */
      apply((&function_307));
    }
  }
}
pointer global_337;
pointer global_338;
void function_309() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_337); /* l_194 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_333); /* _print-with-suffix */
  top_level_apply();
}
pointer global_339;
pointer global_340;
void function_310() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_339); /* l_195 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_333); /* _print-with-suffix */
  top_level_apply();
}
pointer global_341;
pointer global_342;
pointer global_343;
pointer global_344;
pointer global_345;
pointer global_346;
pointer global_347;
void function_311() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_312() {
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
  increment_count(val = global_347); /* _escape-symbols */
  apply((&function_311));
}
void function_313() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_341); /* l_196 */
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_343); /* l_198 */
    args = cons(val, args);
    increment_count(val = global_342); /* l_197 */
    args = cons(val, args);
    increment_count(val = global_69); /* _make-symbol */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_344); /* l_199 */
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
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_346); /* l_201 */
      args = cons(val, args);
      increment_count(val = global_345); /* l_200 */
      args = cons(val, args);
      increment_count(val = global_69); /* _make-symbol */
      top_level_apply();
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
        increment_count(val = car(car(env)));
        pop_function();
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
        increment_count(val = global_347); /* _escape-symbols */
        apply((&function_312));
      }
    }
  }
}
pointer global_348;
pointer global_349;
void function_314() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
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
    pop_function();
  }
}
void function_315() {
  apply((&function_314));
}
void function_316() {
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
  increment_count(val = global_349); /* _list-symbols */
  top_level_apply();
}
void function_317() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_348); /* l_202 */
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
    increment_count(val = car(cdr(car(env))));
    pop_function();
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
      increment_count(val = car(cdr(car(env))));
      pop_function();
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
        increment_count(val = global_73); /* _symbol-eq */
        args = cons(val, args);
        increment_count(val = global_58); /* _contains */
        apply((&function_315));
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
        increment_count(val = global_349); /* _list-symbols */
        apply((&function_316));
      }
    }
  }
}
pointer global_351;
pointer global_352;
void function_318() {
  args = cons(val, args);
  increment_count(val = global_349); /* _list-symbols */
  top_level_apply();
}
void function_319() {
  top_level_apply();
}
void function_320() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_352); /* _find-quoted-symbols */
  top_level_apply();
}
void function_321() {
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
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_351); /* l_203 */
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
      increment_count(val = global_7); /* _cadr */
      apply((&function_318));
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
      val = new_function((&function_320), env);
      args = cons(val, args);
      increment_count(val = global_35); /* _foldr */
      apply((&function_319));
    }
  }
}
pointer global_354;
pointer global_355;
pointer global_356;
pointer global_357;
pointer global_358;
pointer global_359;
pointer global_360;
pointer global_361;
pointer global_362;
pointer global_363;
pointer global_364;
pointer global_365;
pointer global_366;
pointer global_367;
pointer global_368;
pointer global_369;
pointer global_370;
pointer global_371;
pointer global_372;
pointer global_373;
pointer global_374;
pointer global_375;
pointer global_376;
pointer global_377;
pointer global_378;
pointer global_379;
pointer global_380;
pointer global_381;
pointer global_382;
pointer global_383;
pointer global_384;
pointer global_385;
pointer global_386;
pointer global_387;
pointer global_388;
pointer global_389;
pointer global_390;
pointer global_391;
pointer global_392;
pointer global_393;
pointer global_394;
pointer global_395;
void function_322() {
  args = cons(val, args);
  increment_count(val = global_365); /* l_215 */
  args = cons(val, args);
  increment_count(val = global_364); /* l_214 */
  args = cons(val, args);
  increment_count(val = global_363); /* l_213 */
  args = cons(val, args);
  increment_count(val = global_362); /* l_212 */
  args = cons(val, args);
  increment_count(val = global_361); /* l_211 */
  args = cons(val, args);
  increment_count(val = global_360); /* l_210 */
  args = cons(val, args);
  increment_count(val = global_359); /* l_209 */
  args = cons(val, args);
  increment_count(val = global_358); /* l_208 */
  args = cons(val, args);
  increment_count(val = global_357); /* l_207 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_323() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_140); /* _build-symbol->string */
  apply((&function_322));
}
void function_324() {
  args = cons(val, args);
  increment_count(val = global_392); /* l_242 */
  args = cons(val, args);
  increment_count(val = global_391); /* l_241 */
  args = cons(val, args);
  increment_count(val = global_390); /* l_240 */
  args = cons(val, args);
  increment_count(val = global_389); /* l_239 */
  args = cons(val, args);
  increment_count(val = global_388); /* l_238 */
  args = cons(val, args);
  increment_count(val = global_387); /* l_237 */
  args = cons(val, args);
  increment_count(val = global_386); /* l_236 */
  args = cons(val, args);
  increment_count(val = global_385); /* l_235 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_384); /* l_234 */
  args = cons(val, args);
  increment_count(val = global_383); /* l_233 */
  args = cons(val, args);
  increment_count(val = global_382); /* l_232 */
  args = cons(val, args);
  increment_count(val = global_381); /* l_231 */
  args = cons(val, args);
  increment_count(val = global_380); /* l_230 */
  args = cons(val, args);
  increment_count(val = global_379); /* l_229 */
  args = cons(val, args);
  increment_count(val = global_378); /* l_228 */
  args = cons(val, args);
  increment_count(val = global_377); /* l_227 */
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_376); /* l_226 */
  args = cons(val, args);
  increment_count(val = global_375); /* l_225 */
  args = cons(val, args);
  increment_count(val = global_374); /* l_224 */
  args = cons(val, args);
  increment_count(val = global_373); /* l_223 */
  args = cons(val, args);
  increment_count(val = global_372); /* l_222 */
  args = cons(val, args);
  increment_count(val = global_371); /* l_221 */
  args = cons(val, args);
  increment_count(val = global_370); /* l_220 */
  args = cons(val, args);
  increment_count(val = global_369); /* l_219 */
  args = cons(val, args);
  increment_count(val = global_368); /* l_218 */
  args = cons(val, args);
  increment_count(val = global_367); /* l_217 */
  args = cons(val, args);
  increment_count(val = global_366); /* l_216 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_116); /* _build-string->symbol */
  apply((&function_323));
}
void function_325() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_324));
}
void function_326() {
  args = cons(val, args);
  increment_count(val = global_338); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_325));
}
void function_327() {
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
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_347); /* _escape-symbols */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_326));
}
void function_328() {
  args = cons(val, args);
  increment_count(val = global_338); /* _print-with-newline */
  apply((&function_327));
}
void function_329() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_347); /* _escape-symbols */
  apply((&function_328));
}
void function_330() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_329), env);
  top_level_apply();
}
void function_331() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_393); /* l_243 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
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
  increment_count(val = global_352); /* _find-quoted-symbols */
  apply((&function_330));
}
void function_332() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_331), env);
  top_level_apply();
}
void function_333() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_334() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_333));
}
void function_335() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_338); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_334));
}
void function_336() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_394); /* l_244 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_90); /* _generate-unused-symbol-name */
    apply((&function_332));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_338); /* _print-with-newline */
    apply((&function_335));
  }
}
void function_337() {
  args = cons(val, args);
  increment_count(val = global_47); /* _or */
  apply((&function_336));
}
void function_338() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_354); /* l_204 */
  args = cons(val, args);
  increment_count(val = global_86); /* _symbol-present? */
  apply((&function_337));
}
void function_339() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_355); /* l_205 */
  args = cons(val, args);
  increment_count(val = global_86); /* _symbol-present? */
  apply((&function_338));
}
void function_340() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_356); /* l_206 */
  args = cons(val, args);
  increment_count(val = global_86); /* _symbol-present? */
  apply((&function_339));
}
pointer global_398;
pointer global_399;
pointer global_400;
pointer global_401;
void function_341() {
  args = cons(val, args);
  increment_count(val = global_395); /* _compile */
  top_level_apply();
}
void function_342() {
  args = cons(val, args);
  increment_count(val = global_258); /* _read-expr */
  top_level_apply();
}
void function_343() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_400); /* l_247 */
    args = cons(val, args);
    increment_count(val = global_67); /* _print-error */
    top_level_apply();
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
    increment_count(val = car(cdr(cdr(car(env)))));
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
    increment_count(val = global_401); /* _compile-source */
    apply((&function_342));
  }
}
void function_344() {
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
  apply((&function_343));
}
void function_345() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_47); /* _or */
  apply((&function_344));
}
void function_346() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_345));
}
void function_347() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_31); /* _reverse */
    apply((&function_341));
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
    increment_count(val = global_10); /* _caadr */
    apply((&function_346));
  }
}
void function_348() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_398); /* l_245 */
    args = cons(val, args);
    increment_count(val = global_67); /* _print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_399); /* l_246 */
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
    args = cons(val, args);
    increment_count(val = global_56); /* _not */
    apply((&function_347));
  }
}
void function_349() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
  apply((&function_348));
}
void function_350() {
  increment_count(env);
  val = new_function((&function_349), env);
  pop_function();
}
pointer global_405;
pointer global_406;
void function_351() {
  if (is_function(val)) {
    increment_count(env=environment(val));
    env = cons(cons(free_memory_size(),
                   cons(arguments,NIL)),
               env);
    return_location = address(val);
    decrement_count(val);
  } else {
    error(ERR_NO_OS);
    env = NIL;
    return_location = (&end_function);
  }
}
void function_352() {
  args = cons(val, args);
  increment_count(val = global_258); /* _read-expr */
  top_level_apply();
}
void function_353() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_406); /* l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_405); /* l_1 */
  args = cons(val, args);
  increment_count(val = global_401); /* _compile-source */
  apply((&function_352));
}
void function_354() {
  increment_count(env);
  val = new_function((&function_353), env);
  pop_function();
}
#ifdef BARE_HARDWARE
void main (unsigned long magic, multiboot_data* boot_data) {
  int i = 0;
  if ((magic == BOOT_MAGIC) &&
      getFlag(boot_data->flags, 0)) {
    init_mem((void*)0x200000, ((boot_data->mem_upper*1024) - 0x100000));
    init_io();
    init_eval();
    arguments = get_cmd(boot_data->flags, (char*)(boot_data->cmd_line));
    call_stack = cons(new_function((&top_level), NIL), call_stack);
    call_stack = cons(new_function((&function_351), NIL), call_stack);
    return_location = (&function_354);
    while (return_location != (&end_function)) {
      (*return_location)();
    }
    end_function();
  } else {
    error(ERR_BAD_BOOT);
  }
}
#else
int main(int argc, char** argv) {
  pointer memory_limit = 64 * 1024 * 1024;
  void* memory = malloc(memory_limit);
  init_mem(memory, memory_limit);
  init_io();
  init_eval();
  arguments = NIL;
  int i;
  for (i = argc - 1; i >= 0; i--) {
    arguments = cons(make_string(argv[i]), arguments);
  }
  increment_count(env);
  val = new_function((&function_0), env);
  global_4 = val; /* _caar */
  increment_count(env);
  val = new_function((&function_1), env);
  global_6 = val; /* _cdar */
  increment_count(env);
  val = new_function((&function_2), env);
  global_7 = val; /* _cadr */
  increment_count(env);
  val = new_function((&function_3), env);
  global_8 = val; /* _cddr */
  increment_count(env);
  val = new_function((&function_4), env);
  global_9 = val; /* _caaar */
  increment_count(env);
  val = new_function((&function_5), env);
  global_10 = val; /* _caadr */
  increment_count(env);
  val = new_function((&function_6), env);
  global_11 = val; /* _cadar */
  increment_count(env);
  val = new_function((&function_7), env);
  global_12 = val; /* _caddr */
  increment_count(env);
  val = new_function((&function_8), env);
  global_13 = val; /* _id */
  increment_count(env);
  val = new_function((&function_9), env);
  global_14 = val; /* _list */
  increment_count(env);
  val = new_function((&function_10), env);
  global_16 = val; /* _apply */
  increment_count(env);
  val = new_function((&function_17), env);
  global_18 = val; /* _recurse */
  increment_count(env);
  val = new_function((&function_24), env);
  global_20 = val; /* _walk */
  increment_count(env);
  val = new_function((&function_25), env);
  global_27 = val; /* _rreverse */
  val = NIL;
  global_30 = val; /* l_3 */
  increment_count(env);
  val = new_function((&function_26), env);
  global_31 = val; /* _reverse */
  increment_count(env);
  val = new_function((&function_30), env);
  global_32 = val; /* _foldl */
  val = NIL;
  global_34 = val; /* l_4 */
  increment_count(env);
  val = new_function((&function_33), env);
  global_35 = val; /* _foldr */
  val = NIL;
  global_36 = val; /* l_5 */
  val = NIL;
  global_37 = val; /* l_6 */
  increment_count(env);
  val = new_function((&function_37), env);
  global_38 = val; /* _append */
  val = NIL;
  global_40 = val; /* l_7 */
  val = NIL;
  global_41 = val; /* l_8 */
  increment_count(env);
  val = new_function((&function_39), env);
  global_42 = val; /* _equal */
  val = NIL;
  global_44 = val; /* l_9 */
  increment_count(env);
  val = new_function((&function_43), env);
  global_45 = val; /* _map */
  val = NIL;
  global_46 = val; /* l_10 */
  increment_count(env);
  val = new_function((&function_46), env);
  global_47 = val; /* _or */
  val = NIL;
  global_50 = val; /* l_11 */
  val = -86;
  global_51 = val; /* l_12 */
  increment_count(env);
  val = new_function((&function_49), env);
  global_53 = val; /* _and */
  val = NIL;
  global_54 = val; /* l_13 */
  val = -86;
  global_55 = val; /* l_14 */
  increment_count(env);
  val = new_function((&function_50), env);
  global_56 = val; /* _not */
  val = -86;
  global_57 = val; /* l_15 */
  increment_count(env);
  val = new_function((&function_53), env);
  global_58 = val; /* _contains */
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_56), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_54));
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
  global_65 = val; /* l_16 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_66 = val; /* l_17 */
  increment_count(env);
  val = new_function((&function_58), env);
  global_67 = val; /* _print-error */
  increment_count(env);
  val = new_function((&function_60), env);
  global_69 = val; /* _make-symbol */
  increment_count(env);
  val = new_function((&function_62), env);
  global_71 = val; /* _symbol->id */
  increment_count(env);
  val = new_function((&function_66), env);
  global_73 = val; /* _symbol-eq */
  increment_count(env);
  val = new_function((&function_68), env);
  global_76 = val; /* _symbol->string */
  increment_count(env);
  val = new_function((&function_72), env);
  global_77 = val; /* _lookup */
  increment_count(env);
  val = new_function((&function_75), env);
  global_82 = val; /* _get-symbol */
  val = NIL;
  global_84 = val; /* l_18 */
  val = -86;
  global_85 = val; /* l_19 */
  increment_count(env);
  val = new_function((&function_78), env);
  global_86 = val; /* _symbol-present? */
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_89 = val; /* l_20 */
  increment_count(env);
  val = new_function((&function_81), env);
  global_90 = val; /* _generate-unused-symbol-name */
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
  global_92 = val; /* l_21 */
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
  global_93 = val; /* l_22 */
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
  global_94 = val; /* l_23 */
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
  global_95 = val; /* l_24 */
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
  global_96 = val; /* l_25 */
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
  global_97 = val; /* l_26 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_98 = val; /* l_27 */
  increment_count(env);
  val = new_function((&function_87), env);
  global_99 = val; /* _build-string->symbol-cases */
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
  global_106 = val; /* l_28 */
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
  global_107 = val; /* l_29 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
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
  global_108 = val; /* l_30 */
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
  global_109 = val; /* l_31 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_110 = val; /* l_32 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
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
  global_111 = val; /* l_33 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_112 = val; /* l_34 */
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
  global_113 = val; /* l_35 */
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_114 = val; /* l_36 */
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
  val = args;
  args = NIL;
  pop_args();
  global_115 = val; /* l_37 */
  increment_count(env);
  val = new_function((&function_89), env);
  global_116 = val; /* _build-string->symbol */
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
  global_117 = val; /* l_38 */
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
  global_118 = val; /* l_39 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_119 = val; /* l_40 */
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
  global_120 = val; /* l_41 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_121 = val; /* l_42 */
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
  global_122 = val; /* l_43 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_123 = val; /* l_44 */
  increment_count(env);
  val = new_function((&function_95), env);
  global_124 = val; /* _build-symbol->string-cases */
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
  global_125 = val; /* l_45 */
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
  global_126 = val; /* l_46 */
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
  global_127 = val; /* l_47 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_128 = val; /* l_48 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = new_number(109);
  args = cons(val, args);
  val = new_number(111);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(97);
  args = cons(val, args);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_129 = val; /* l_49 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(95);
  args = cons(val, args);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_130 = val; /* l_50 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_131 = val; /* l_51 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(95);
  args = cons(val, args);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_132 = val; /* l_52 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(34);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_133 = val; /* l_53 */
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
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
  global_134 = val; /* l_54 */
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
  val = args;
  args = NIL;
  pop_args();
  global_135 = val; /* l_55 */
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
  global_136 = val; /* l_56 */
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
  global_137 = val; /* l_57 */
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
  global_138 = val; /* l_58 */
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
  global_139 = val; /* l_59 */
  increment_count(env);
  val = new_function((&function_97), env);
  global_140 = val; /* _build-symbol->string */
  increment_count(env);
  val = new_function((&function_98), env);
  global_141 = val; /* _escape-char */
  increment_count(env);
  val = new_function((&function_102), env);
  global_143 = val; /* _build-num */
  increment_count(env);
  val = new_function((&function_103), env);
  global_147 = val; /* _drop-first */
  increment_count(env);
  val = new_function((&function_104), env);
  global_149 = val; /* _drop-second */
  val = QUOTE;
  global_150 = val; /* l_60 */
  increment_count(env);
  val = new_function((&function_106), env);
  global_151 = val; /* _quote-value */
  val = QUASIQUOTE;
  global_153 = val; /* l_61 */
  increment_count(env);
  val = new_function((&function_108), env);
  global_154 = val; /* _quasiquote-value */
  val = UNQUOTE;
  global_155 = val; /* l_62 */
  increment_count(env);
  val = new_function((&function_110), env);
  global_156 = val; /* _unquote-value */
  val = NIL;
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
  args = NIL;
  pop_args();
  global_157 = val; /* l_63 */
  val = COND;
  global_158 = val; /* l_64 */
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
  global_159 = val; /* l_65 */
  val = IF;
  global_160 = val; /* l_66 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_161 = val; /* l_67 */
  val = LET;
  global_162 = val; /* l_68 */
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
  global_163 = val; /* l_69 */
  val = FN;
  global_164 = val; /* l_70 */
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
  global_165 = val; /* l_71 */
  val = QUOTE;
  global_166 = val; /* l_72 */
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
  global_167 = val; /* l_73 */
  val = QUASIQUOTE;
  global_168 = val; /* l_74 */
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
  global_169 = val; /* l_75 */
  val = UNQUOTE;
  global_170 = val; /* l_76 */
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
  global_171 = val; /* l_77 */
  val = CONS;
  global_172 = val; /* l_78 */
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
  global_173 = val; /* l_79 */
  val = CAR;
  global_174 = val; /* l_80 */
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
  global_175 = val; /* l_81 */
  val = CDR;
  global_176 = val; /* l_82 */
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
  global_177 = val; /* l_83 */
  val = ATOM;
  global_178 = val; /* l_84 */
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
  global_179 = val; /* l_85 */
  val = NUMBER;
  global_180 = val; /* l_86 */
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
  global_181 = val; /* l_87 */
  val = FUNCTION;
  global_182 = val; /* l_88 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_183 = val; /* l_89 */
  val = EQ;
  global_184 = val; /* l_90 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_185 = val; /* l_91 */
  val = LT;
  global_186 = val; /* l_92 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_187 = val; /* l_93 */
  val = GT;
  global_188 = val; /* l_94 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_189 = val; /* l_95 */
  val = PLUS;
  global_190 = val; /* l_96 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_191 = val; /* l_97 */
  val = MINUS;
  global_192 = val; /* l_98 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_193 = val; /* l_99 */
  val = MULT;
  global_194 = val; /* l_100 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_195 = val; /* l_101 */
  val = DIV;
  global_196 = val; /* l_102 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_197 = val; /* l_103 */
  val = MOD;
  global_198 = val; /* l_104 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_199 = val; /* l_105 */
  val = BNEG;
  global_200 = val; /* l_106 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_201 = val; /* l_107 */
  val = BAND;
  global_202 = val; /* l_108 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_203 = val; /* l_109 */
  val = BOR;
  global_204 = val; /* l_110 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_205 = val; /* l_111 */
  val = BXOR;
  global_206 = val; /* l_112 */
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
  global_207 = val; /* l_113 */
  val = SRSHIFT;
  global_208 = val; /* l_114 */
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
  global_209 = val; /* l_115 */
  val = URSHIFT;
  global_210 = val; /* l_116 */
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
  global_211 = val; /* l_117 */
  val = LSHIFT;
  global_212 = val; /* l_118 */
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
  global_213 = val; /* l_119 */
  val = DEFINE;
  global_214 = val; /* l_120 */
  increment_count(env);
  val = new_function((&function_141), env);
  global_215 = val; /* _lookup-symbol */
  increment_count(env);
  val = new_function((&function_142), env);
  global_217 = val; /* _fail */
  increment_count(env);
  val = new_function((&function_143), env);
  global_219 = val; /* _done */
  val = NIL;
  global_220 = val; /* l_121 */
  increment_count(env);
  val = new_function((&function_146), env);
  global_221 = val; /* _pop */
  increment_count(env);
  val = new_function((&function_151), env);
  global_222 = val; /* _check */
  increment_count(env);
  val = new_function((&function_153), env);
  global_224 = val; /* _match */
  increment_count(env);
  val = new_function((&function_155), env);
  global_225 = val; /* _default */
  increment_count(env);
  val = new_function((&function_160), env);
  global_228 = val; /* _case */
  increment_count(env);
  val = new_function((&function_163), env);
  global_230 = val; /* _choice */
  increment_count(env);
  val = new_function((&function_166), env);
  global_232 = val; /* _post-process */
  increment_count(env);
  val = new_function((&function_170), env);
  global_233 = val; /* _seq */
  increment_count(env);
  val = new_function((&function_172), env);
  global_236 = val; /* _escape */
  increment_count(env);
  val = new_function((&function_173), env);
  global_237 = val; /* _use */
  increment_count(env);
  val = new_function((&function_177), env);
  global_238 = val; /* _peek */
  increment_count(env);
  val = new_function((&function_179), env);
  global_240 = val; /* _interval */
  increment_count(env);
  val = new_function((&function_181), env);
  global_242 = val; /* _skip */
  increment_count(env);
  val = new_function((&function_183), env);
  global_243 = val; /* _first */
  increment_count(env);
  val = new_function((&function_190), env);
  global_244 = val; /* _parse-num */
  increment_count(env);
  val = new_function((&function_192), env);
  global_245 = val; /* _read-num */
  increment_count(env);
  val = new_function((&function_207), env);
  global_246 = val; /* _parse-symbol */
  increment_count(env);
  val = new_function((&function_209), env);
  global_247 = val; /* _read-symbol */
  increment_count(env);
  val = new_function((&function_218), env);
  global_248 = val; /* _parse-string */
  increment_count(env);
  val = new_function((&function_219), env);
  global_249 = val; /* _quote-parser */
  increment_count(env);
  val = new_function((&function_220), env);
  global_250 = val; /* _quasiquote-parser */
  increment_count(env);
  val = new_function((&function_221), env);
  global_251 = val; /* _unquote-parser */
  increment_count(env);
  val = new_function((&function_231), env);
  global_252 = val; /* _comment */
  increment_count(env);
  val = new_function((&function_240), env);
  global_253 = val; /* _parse-paren */
  increment_count(env);
  val = new_function((&function_254), env);
  global_254 = val; /* _parse-pair */
  increment_count(env);
  val = new_function((&function_283), env);
  global_255 = val; /* _parse-expr */
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
  global_256 = val; /* l_122 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_257 = val; /* l_123 */
  increment_count(env);
  val = new_function((&function_287), env);
  global_258 = val; /* _read-expr */
  increment_count(env);
  val = new_function((&function_295), env);
  global_262 = val; /* _build-num-str */
  val = NIL;
  global_265 = val; /* l_124 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_266 = val; /* l_125 */
  val = NIL;
  global_267 = val; /* l_126 */
  increment_count(env);
  val = new_function((&function_299), env);
  global_261 = val; /* _print-num */
  val = QUOTE;
  global_268 = val; /* l_127 */
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
  global_269 = val; /* l_128 */
  val = QUASIQUOTE;
  global_270 = val; /* l_129 */
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
  global_271 = val; /* l_130 */
  val = UNQUOTE;
  global_272 = val; /* l_131 */
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
  global_273 = val; /* l_132 */
  val = CAR;
  global_274 = val; /* l_133 */
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
  global_275 = val; /* l_134 */
  val = CDR;
  global_276 = val; /* l_135 */
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
  global_277 = val; /* l_136 */
  val = NUMBER;
  global_278 = val; /* l_137 */
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
  global_279 = val; /* l_138 */
  val = FUNCTION;
  global_280 = val; /* l_139 */
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
  global_281 = val; /* l_140 */
  val = ATOM;
  global_282 = val; /* l_141 */
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
  global_283 = val; /* l_142 */
  val = CONS;
  global_284 = val; /* l_143 */
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
  global_285 = val; /* l_144 */
  val = COND;
  global_286 = val; /* l_145 */
  val = NIL;
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
  args = NIL;
  pop_args();
  global_287 = val; /* l_146 */
  val = IF;
  global_288 = val; /* l_147 */
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
  global_289 = val; /* l_148 */
  val = LET;
  global_290 = val; /* l_149 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(116);
  args = cons(val, args);
  val = new_number(101);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_291 = val; /* l_150 */
  val = FN;
  global_292 = val; /* l_151 */
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
  global_293 = val; /* l_152 */
  val = URSHIFT;
  global_294 = val; /* l_153 */
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
  global_295 = val; /* l_154 */
  val = SRSHIFT;
  global_296 = val; /* l_155 */
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
  global_297 = val; /* l_156 */
  val = LSHIFT;
  global_298 = val; /* l_157 */
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
  global_299 = val; /* l_158 */
  val = LT;
  global_300 = val; /* l_159 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_301 = val; /* l_160 */
  val = GT;
  global_302 = val; /* l_161 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_303 = val; /* l_162 */
  val = EQ;
  global_304 = val; /* l_163 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_305 = val; /* l_164 */
  val = PLUS;
  global_306 = val; /* l_165 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_307 = val; /* l_166 */
  val = MINUS;
  global_308 = val; /* l_167 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_309 = val; /* l_168 */
  val = MULT;
  global_310 = val; /* l_169 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_311 = val; /* l_170 */
  val = DIV;
  global_312 = val; /* l_171 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_313 = val; /* l_172 */
  val = MOD;
  global_314 = val; /* l_173 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_315 = val; /* l_174 */
  val = BAND;
  global_316 = val; /* l_175 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_317 = val; /* l_176 */
  val = BOR;
  global_318 = val; /* l_177 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_319 = val; /* l_178 */
  val = BXOR;
  global_320 = val; /* l_179 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_321 = val; /* l_180 */
  val = BNEG;
  global_322 = val; /* l_181 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_323 = val; /* l_182 */
  val = DEFINE;
  global_324 = val; /* l_183 */
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
  global_325 = val; /* l_184 */
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
  global_326 = val; /* l_185 */
  increment_count(env);
  val = new_function((&function_300), env);
  global_105 = val; /* _print-atom */
  val = NIL;
  global_327 = val; /* l_186 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_328 = val; /* l_187 */
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
  global_329 = val; /* l_188 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_330 = val; /* l_189 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_331 = val; /* l_190 */
  increment_count(env);
  val = new_function((&function_304), env);
  global_332 = val; /* _print-tail */
  val = NIL;
  global_334 = val; /* l_191 */
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
  global_335 = val; /* l_192 */
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_336 = val; /* l_193 */
  increment_count(env);
  val = new_function((&function_308), env);
  global_333 = val; /* _print-with-suffix */
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_337 = val; /* l_194 */
  increment_count(env);
  val = new_function((&function_309), env);
  global_338 = val; /* _print-with-newline */
  val = NIL;
  global_339 = val; /* l_195 */
  increment_count(env);
  val = new_function((&function_310), env);
  global_340 = val; /* _print */
  val = ATOM;
  global_341 = val; /* l_196 */
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
  global_342 = val; /* l_197 */
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
  global_343 = val; /* l_198 */
  val = EQ;
  global_344 = val; /* l_199 */
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
  global_345 = val; /* l_200 */
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
  global_346 = val; /* l_201 */
  increment_count(env);
  val = new_function((&function_313), env);
  global_347 = val; /* _escape-symbols */
  val = NIL;
  global_348 = val; /* l_202 */
  increment_count(env);
  val = new_function((&function_317), env);
  global_349 = val; /* _list-symbols */
  val = QUOTE;
  global_351 = val; /* l_203 */
  increment_count(env);
  val = new_function((&function_321), env);
  global_352 = val; /* _find-quoted-symbols */
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
  global_354 = val; /* l_204 */
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
  global_355 = val; /* l_205 */
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
  global_356 = val; /* l_206 */
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
  global_357 = val; /* l_207 */
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
  global_358 = val; /* l_208 */
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
  global_359 = val; /* l_209 */
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
  global_360 = val; /* l_210 */
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
  global_361 = val; /* l_211 */
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
  global_362 = val; /* l_212 */
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
  global_363 = val; /* l_213 */
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
  global_364 = val; /* l_214 */
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
  global_365 = val; /* l_215 */
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
  global_366 = val; /* l_216 */
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
  global_367 = val; /* l_217 */
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
  global_368 = val; /* l_218 */
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
  global_369 = val; /* l_219 */
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
  global_370 = val; /* l_220 */
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
  global_371 = val; /* l_221 */
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
  global_372 = val; /* l_222 */
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
  global_373 = val; /* l_223 */
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
  global_374 = val; /* l_224 */
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
  global_375 = val; /* l_225 */
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
  global_376 = val; /* l_226 */
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
  global_377 = val; /* l_227 */
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
  global_378 = val; /* l_228 */
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
  global_379 = val; /* l_229 */
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
  global_380 = val; /* l_230 */
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
  global_381 = val; /* l_231 */
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
  global_382 = val; /* l_232 */
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
  global_383 = val; /* l_233 */
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
  global_384 = val; /* l_234 */
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
  global_385 = val; /* l_235 */
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
  global_386 = val; /* l_236 */
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
  global_387 = val; /* l_237 */
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
  global_388 = val; /* l_238 */
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
  global_389 = val; /* l_239 */
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
  global_390 = val; /* l_240 */
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
  global_391 = val; /* l_241 */
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
  global_392 = val; /* l_242 */
  val = NIL;
  global_393 = val; /* l_243 */
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
  global_394 = val; /* l_244 */
  increment_count(env);
  val = new_function((&function_340), env);
  global_395 = val; /* _compile */
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
  global_398 = val; /* l_245 */
  val = DEFINE;
  global_399 = val; /* l_246 */
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
  global_400 = val; /* l_247 */
  increment_count(env);
  val = new_function((&function_350), env);
  global_401 = val; /* _compile-source */
  val = NIL;
  global_405 = val; /* l_1 */
  val = NIL;
  global_406 = val; /* l_2 */
  call_stack = cons(new_function((&top_level), NIL), call_stack);
  call_stack = cons(new_function((&function_351), NIL), call_stack);
  return_location = (&function_354);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
