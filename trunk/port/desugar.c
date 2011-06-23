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
void body_1();
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
/* _caar */
void body_0() {
  increment_count(env);
  val = new_function((&function_0), env);
  global_4 = val; /* _caar */
  return_location = (&body_1);
}
void body_2();
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
/* _cdar */
void body_1() {
  increment_count(env);
  val = new_function((&function_1), env);
  global_6 = val; /* _cdar */
  return_location = (&body_2);
}
void body_3();
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
/* _cadr */
void body_2() {
  increment_count(env);
  val = new_function((&function_2), env);
  global_7 = val; /* _cadr */
  return_location = (&body_3);
}
void body_4();
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
/* _cddr */
void body_3() {
  increment_count(env);
  val = new_function((&function_3), env);
  global_8 = val; /* _cddr */
  return_location = (&body_4);
}
void body_5();
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
/* _caaar */
void body_4() {
  increment_count(env);
  val = new_function((&function_4), env);
  global_9 = val; /* _caaar */
  return_location = (&body_5);
}
void body_6();
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
/* _caadr */
void body_5() {
  increment_count(env);
  val = new_function((&function_5), env);
  global_10 = val; /* _caadr */
  return_location = (&body_6);
}
void body_7();
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
/* _cadar */
void body_6() {
  increment_count(env);
  val = new_function((&function_6), env);
  global_11 = val; /* _cadar */
  return_location = (&body_7);
}
void body_8();
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
/* _caddr */
void body_7() {
  increment_count(env);
  val = new_function((&function_7), env);
  global_12 = val; /* _caddr */
  return_location = (&body_8);
}
void body_9();
pointer global_13;
void function_8() {
  increment_count(val = car(car(env)));
  pop_function();
}
/* _id */
void body_8() {
  increment_count(env);
  val = new_function((&function_8), env);
  global_13 = val; /* _id */
  return_location = (&body_9);
}
void body_10();
pointer global_14;
void function_9() {
  increment_count(val = car(env));
  pop_function();
}
/* _list */
void body_9() {
  increment_count(env);
  val = new_function((&function_9), env);
  global_14 = val; /* _list */
  return_location = (&body_10);
}
void body_11();
pointer global_16;
void function_10() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
/* _apply */
void body_10() {
  increment_count(env);
  val = new_function((&function_10), env);
  global_16 = val; /* _apply */
  return_location = (&body_11);
}
void body_12();
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
/* _recurse */
void body_11() {
  increment_count(env);
  val = new_function((&function_17), env);
  global_18 = val; /* _recurse */
  return_location = (&body_12);
}
void body_13();
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
/* _walk */
void body_12() {
  increment_count(env);
  val = new_function((&function_24), env);
  global_20 = val; /* _walk */
  return_location = (&body_13);
}
void body_14();
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
/* _rreverse */
void body_13() {
  increment_count(env);
  val = new_function((&function_25), env);
  global_27 = val; /* _rreverse */
  return_location = (&body_14);
}
void body_15();
pointer global_30;
/* l_3 */
void body_14() {
  val = NIL;
  global_30 = val; /* l_3 */
  return_location = (&body_15);
}
void body_16();
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
/* _reverse */
void body_15() {
  increment_count(env);
  val = new_function((&function_26), env);
  global_31 = val; /* _reverse */
  return_location = (&body_16);
}
void body_17();
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
/* _foldl */
void body_16() {
  increment_count(env);
  val = new_function((&function_30), env);
  global_32 = val; /* _foldl */
  return_location = (&body_17);
}
void body_18();
pointer global_34;
/* l_4 */
void body_17() {
  val = NIL;
  global_34 = val; /* l_4 */
  return_location = (&body_18);
}
void body_19();
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
/* _foldr */
void body_18() {
  increment_count(env);
  val = new_function((&function_33), env);
  global_35 = val; /* _foldr */
  return_location = (&body_19);
}
void body_20();
pointer global_36;
/* l_5 */
void body_19() {
  val = NIL;
  global_36 = val; /* l_5 */
  return_location = (&body_20);
}
void body_21();
pointer global_37;
/* l_6 */
void body_20() {
  val = NIL;
  global_37 = val; /* l_6 */
  return_location = (&body_21);
}
void body_22();
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
/* _append */
void body_21() {
  increment_count(env);
  val = new_function((&function_37), env);
  global_38 = val; /* _append */
  return_location = (&body_22);
}
void body_23();
pointer global_40;
/* l_7 */
void body_22() {
  val = NIL;
  global_40 = val; /* l_7 */
  return_location = (&body_23);
}
void body_24();
pointer global_41;
/* l_8 */
void body_23() {
  val = NIL;
  global_41 = val; /* l_8 */
  return_location = (&body_24);
}
void body_25();
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
/* _equal */
void body_24() {
  increment_count(env);
  val = new_function((&function_39), env);
  global_42 = val; /* _equal */
  return_location = (&body_25);
}
void body_26();
pointer global_44;
/* l_9 */
void body_25() {
  val = NIL;
  global_44 = val; /* l_9 */
  return_location = (&body_26);
}
void body_27();
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
/* _map */
void body_26() {
  increment_count(env);
  val = new_function((&function_43), env);
  global_45 = val; /* _map */
  return_location = (&body_27);
}
void body_28();
pointer global_46;
/* l_10 */
void body_27() {
  val = NIL;
  global_46 = val; /* l_10 */
  return_location = (&body_28);
}
void body_29();
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
/* _or */
void body_28() {
  increment_count(env);
  val = new_function((&function_46), env);
  global_47 = val; /* _or */
  return_location = (&body_29);
}
void body_30();
pointer global_50;
/* l_11 */
void body_29() {
  val = NIL;
  global_50 = val; /* l_11 */
  return_location = (&body_30);
}
void body_31();
pointer global_51;
/* l_12 */
void body_30() {
  val = -86;
  global_51 = val; /* l_12 */
  return_location = (&body_31);
}
void body_32();
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
/* _and */
void body_31() {
  increment_count(env);
  val = new_function((&function_49), env);
  global_53 = val; /* _and */
  return_location = (&body_32);
}
void body_33();
pointer global_54;
/* l_13 */
void body_32() {
  val = NIL;
  global_54 = val; /* l_13 */
  return_location = (&body_33);
}
void body_34();
pointer global_55;
/* l_14 */
void body_33() {
  val = -86;
  global_55 = val; /* l_14 */
  return_location = (&body_34);
}
void body_35();
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
/* _not */
void body_34() {
  increment_count(env);
  val = new_function((&function_50), env);
  global_56 = val; /* _not */
  return_location = (&body_35);
}
void body_36();
pointer global_57;
/* l_15 */
void body_35() {
  val = -86;
  global_57 = val; /* l_15 */
  return_location = (&body_36);
}
void body_37();
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
/* _contains */
void body_36() {
  increment_count(env);
  val = new_function((&function_53), env);
  global_58 = val; /* _contains */
  return_location = (&body_37);
}
void body_38();
pointer global_62;
void function_54() {
  global_62 = val; /* _map-to-stderr */
  return_location = (&body_38);
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
/* _map-to-stderr */
void body_37() {
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
}
void body_39();
pointer global_65;
/* l_16 */
void body_38() {
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
  global_65 = val; /* l_16 */
  return_location = (&body_39);
}
void body_40();
pointer global_66;
/* l_17 */
void body_39() {
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
  global_66 = val; /* l_17 */
  return_location = (&body_40);
}
void body_41();
pointer global_67;
/* l_18 */
void body_40() {
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
  global_67 = val; /* l_18 */
  return_location = (&body_41);
}
void body_42();
pointer global_68;
/* l_19 */
void body_41() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_68 = val; /* l_19 */
  return_location = (&body_42);
}
void body_43();
pointer global_72 = NIL; /* _print */
pointer global_69;
void function_57() {
  args = cons(val, args);
  increment_count(val = global_62); /* _map-to-stderr */
  top_level_apply();
}
void function_58() {
  args = cons(val, args);
  increment_count(val = global_66); /* l_17 */
  args = cons(val, args);
  increment_count(val = global_65); /* l_16 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_57));
}
void function_59() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_68); /* l_19 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_67); /* l_18 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_72); /* _print */
    apply((&function_58));
  } else {
    val = NIL;
    pop_function();
  }
}
/* _print-warnings */
void body_42() {
  increment_count(env);
  val = new_function((&function_59), env);
  global_69 = val; /* _print-warnings */
  return_location = (&body_43);
}
void body_44();
pointer global_73;
/* l_20 */
void body_43() {
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
  global_73 = val; /* l_20 */
  return_location = (&body_44);
}
void body_45();
pointer global_74;
/* l_21 */
void body_44() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_74 = val; /* l_21 */
  return_location = (&body_45);
}
void body_46();
pointer global_75;
void function_60() {
  args = cons(val, args);
  increment_count(val = global_62); /* _map-to-stderr */
  top_level_apply();
}
void function_61() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_74); /* l_21 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_73); /* l_20 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_60));
}
/* _print-error */
void body_45() {
  increment_count(env);
  val = new_function((&function_61), env);
  global_75 = val; /* _print-error */
  return_location = (&body_46);
}
void body_47();
pointer global_77;
void function_62() {
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
void function_63() {
  increment_count(env);
  val = new_function((&function_62), env);
  pop_function();
}
/* _make-symbol */
void body_46() {
  increment_count(env);
  val = new_function((&function_63), env);
  global_77 = val; /* _make-symbol */
  return_location = (&body_47);
}
void body_48();
pointer global_79;
void function_64() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_65() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_64), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
/* _symbol->id */
void body_47() {
  increment_count(env);
  val = new_function((&function_65), env);
  global_79 = val; /* _symbol->id */
  return_location = (&body_48);
}
void body_49();
pointer global_81;
void function_66() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_67() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_66), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
/* _symbol->string */
void body_48() {
  increment_count(env);
  val = new_function((&function_67), env);
  global_81 = val; /* _symbol->string */
  return_location = (&body_49);
}
void body_50();
pointer global_82;
void function_68() {
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
void function_69() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_79); /* _symbol->id */
  apply((&function_68));
}
void function_70() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_79); /* _symbol->id */
  apply((&function_69));
}
/* _symbol-eq */
void body_49() {
  increment_count(env);
  val = new_function((&function_70), env);
  global_82 = val; /* _symbol-eq */
  return_location = (&body_50);
}
void body_51();
pointer global_85;
void function_71() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_72() {
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
    apply((&function_71));
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
    increment_count(val = global_85); /* _lookup */
    top_level_apply();
  }
}
void function_73() {
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_72));
}
void function_74() {
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
    apply((&function_73));
  }
}
/* _lookup */
void body_50() {
  increment_count(env);
  val = new_function((&function_74), env);
  global_85 = val; /* _lookup */
  return_location = (&body_51);
}
void body_52();
pointer global_90;
void function_75() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_76() {
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
  increment_count(val = global_77); /* _make-symbol */
  apply((&function_75));
}
void function_77() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_76), env);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_85); /* _lookup */
  top_level_apply();
}
/* _get-symbol */
void body_51() {
  increment_count(env);
  val = new_function((&function_77), env);
  global_90 = val; /* _get-symbol */
  return_location = (&body_52);
}
void body_53();
pointer global_92;
void function_78() {
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
/* _escape-char */
void body_52() {
  increment_count(env);
  val = new_function((&function_78), env);
  global_92 = val; /* _escape-char */
  return_location = (&body_53);
}
void body_54();
pointer global_95;
void function_79() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_80() {
  apply((&function_79));
}
void function_81() {
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
void function_82() {
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
  val = new_function((&function_81), env);
  args = cons(val, args);
  increment_count(val = global_32); /* _foldl */
  apply((&function_80));
}
/* _build-num */
void body_53() {
  increment_count(env);
  val = new_function((&function_82), env);
  global_95 = val; /* _build-num */
  return_location = (&body_54);
}
void body_55();
pointer global_99;
void function_83() {
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
/* _drop-first */
void body_54() {
  increment_count(env);
  val = new_function((&function_83), env);
  global_99 = val; /* _drop-first */
  return_location = (&body_55);
}
void body_56();
pointer global_101;
void function_84() {
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
/* _drop-second */
void body_55() {
  increment_count(env);
  val = new_function((&function_84), env);
  global_101 = val; /* _drop-second */
  return_location = (&body_56);
}
void body_57();
pointer global_102;
/* l_22 */
void body_56() {
  val = QUOTE;
  global_102 = val; /* l_22 */
  return_location = (&body_57);
}
void body_58();
pointer global_103;
void function_85() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_86() {
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
  increment_count(val = global_102); /* l_22 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_85));
}
/* _quote-value */
void body_57() {
  increment_count(env);
  val = new_function((&function_86), env);
  global_103 = val; /* _quote-value */
  return_location = (&body_58);
}
void body_59();
pointer global_105;
/* l_23 */
void body_58() {
  val = QUASIQUOTE;
  global_105 = val; /* l_23 */
  return_location = (&body_59);
}
void body_60();
pointer global_106;
void function_87() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_88() {
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
  increment_count(val = global_105); /* l_23 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_87));
}
/* _quasiquote-value */
void body_59() {
  increment_count(env);
  val = new_function((&function_88), env);
  global_106 = val; /* _quasiquote-value */
  return_location = (&body_60);
}
void body_61();
pointer global_107;
/* l_24 */
void body_60() {
  val = UNQUOTE;
  global_107 = val; /* l_24 */
  return_location = (&body_61);
}
void body_62();
pointer global_108;
void function_89() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_90() {
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
  increment_count(val = global_107); /* l_24 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_89));
}
/* _unquote-value */
void body_61() {
  increment_count(env);
  val = new_function((&function_90), env);
  global_108 = val; /* _unquote-value */
  return_location = (&body_62);
}
void body_63();
pointer global_109;
/* l_25 */
void body_62() {
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
  global_109 = val; /* l_25 */
  return_location = (&body_63);
}
void body_64();
pointer global_110;
/* l_26 */
void body_63() {
  val = COND;
  global_110 = val; /* l_26 */
  return_location = (&body_64);
}
void body_65();
pointer global_111;
/* l_27 */
void body_64() {
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
  global_111 = val; /* l_27 */
  return_location = (&body_65);
}
void body_66();
pointer global_112;
/* l_28 */
void body_65() {
  val = IF;
  global_112 = val; /* l_28 */
  return_location = (&body_66);
}
void body_67();
pointer global_113;
/* l_29 */
void body_66() {
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
  global_113 = val; /* l_29 */
  return_location = (&body_67);
}
void body_68();
pointer global_114;
/* l_30 */
void body_67() {
  val = LET;
  global_114 = val; /* l_30 */
  return_location = (&body_68);
}
void body_69();
pointer global_115;
/* l_31 */
void body_68() {
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
  global_115 = val; /* l_31 */
  return_location = (&body_69);
}
void body_70();
pointer global_116;
/* l_32 */
void body_69() {
  val = FN;
  global_116 = val; /* l_32 */
  return_location = (&body_70);
}
void body_71();
pointer global_117;
/* l_33 */
void body_70() {
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
  global_117 = val; /* l_33 */
  return_location = (&body_71);
}
void body_72();
pointer global_118;
/* l_34 */
void body_71() {
  val = QUOTE;
  global_118 = val; /* l_34 */
  return_location = (&body_72);
}
void body_73();
pointer global_119;
/* l_35 */
void body_72() {
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
  global_119 = val; /* l_35 */
  return_location = (&body_73);
}
void body_74();
pointer global_120;
/* l_36 */
void body_73() {
  val = QUASIQUOTE;
  global_120 = val; /* l_36 */
  return_location = (&body_74);
}
void body_75();
pointer global_121;
/* l_37 */
void body_74() {
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
  global_121 = val; /* l_37 */
  return_location = (&body_75);
}
void body_76();
pointer global_122;
/* l_38 */
void body_75() {
  val = UNQUOTE;
  global_122 = val; /* l_38 */
  return_location = (&body_76);
}
void body_77();
pointer global_123;
/* l_39 */
void body_76() {
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
  global_123 = val; /* l_39 */
  return_location = (&body_77);
}
void body_78();
pointer global_124;
/* l_40 */
void body_77() {
  val = CONS;
  global_124 = val; /* l_40 */
  return_location = (&body_78);
}
void body_79();
pointer global_125;
/* l_41 */
void body_78() {
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
  global_125 = val; /* l_41 */
  return_location = (&body_79);
}
void body_80();
pointer global_126;
/* l_42 */
void body_79() {
  val = CAR;
  global_126 = val; /* l_42 */
  return_location = (&body_80);
}
void body_81();
pointer global_127;
/* l_43 */
void body_80() {
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
  global_127 = val; /* l_43 */
  return_location = (&body_81);
}
void body_82();
pointer global_128;
/* l_44 */
void body_81() {
  val = CDR;
  global_128 = val; /* l_44 */
  return_location = (&body_82);
}
void body_83();
pointer global_129;
/* l_45 */
void body_82() {
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
  global_129 = val; /* l_45 */
  return_location = (&body_83);
}
void body_84();
pointer global_130;
/* l_46 */
void body_83() {
  val = ATOM;
  global_130 = val; /* l_46 */
  return_location = (&body_84);
}
void body_85();
pointer global_131;
/* l_47 */
void body_84() {
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
  global_131 = val; /* l_47 */
  return_location = (&body_85);
}
void body_86();
pointer global_132;
/* l_48 */
void body_85() {
  val = NUMBER;
  global_132 = val; /* l_48 */
  return_location = (&body_86);
}
void body_87();
pointer global_133;
/* l_49 */
void body_86() {
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
  global_133 = val; /* l_49 */
  return_location = (&body_87);
}
void body_88();
pointer global_134;
/* l_50 */
void body_87() {
  val = FUNCTION;
  global_134 = val; /* l_50 */
  return_location = (&body_88);
}
void body_89();
pointer global_135;
/* l_51 */
void body_88() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_135 = val; /* l_51 */
  return_location = (&body_89);
}
void body_90();
pointer global_136;
/* l_52 */
void body_89() {
  val = EQ;
  global_136 = val; /* l_52 */
  return_location = (&body_90);
}
void body_91();
pointer global_137;
/* l_53 */
void body_90() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_137 = val; /* l_53 */
  return_location = (&body_91);
}
void body_92();
pointer global_138;
/* l_54 */
void body_91() {
  val = LT;
  global_138 = val; /* l_54 */
  return_location = (&body_92);
}
void body_93();
pointer global_139;
/* l_55 */
void body_92() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_139 = val; /* l_55 */
  return_location = (&body_93);
}
void body_94();
pointer global_140;
/* l_56 */
void body_93() {
  val = GT;
  global_140 = val; /* l_56 */
  return_location = (&body_94);
}
void body_95();
pointer global_141;
/* l_57 */
void body_94() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_141 = val; /* l_57 */
  return_location = (&body_95);
}
void body_96();
pointer global_142;
/* l_58 */
void body_95() {
  val = PLUS;
  global_142 = val; /* l_58 */
  return_location = (&body_96);
}
void body_97();
pointer global_143;
/* l_59 */
void body_96() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_143 = val; /* l_59 */
  return_location = (&body_97);
}
void body_98();
pointer global_144;
/* l_60 */
void body_97() {
  val = MINUS;
  global_144 = val; /* l_60 */
  return_location = (&body_98);
}
void body_99();
pointer global_145;
/* l_61 */
void body_98() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_145 = val; /* l_61 */
  return_location = (&body_99);
}
void body_100();
pointer global_146;
/* l_62 */
void body_99() {
  val = MULT;
  global_146 = val; /* l_62 */
  return_location = (&body_100);
}
void body_101();
pointer global_147;
/* l_63 */
void body_100() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_147 = val; /* l_63 */
  return_location = (&body_101);
}
void body_102();
pointer global_148;
/* l_64 */
void body_101() {
  val = DIV;
  global_148 = val; /* l_64 */
  return_location = (&body_102);
}
void body_103();
pointer global_149;
/* l_65 */
void body_102() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_149 = val; /* l_65 */
  return_location = (&body_103);
}
void body_104();
pointer global_150;
/* l_66 */
void body_103() {
  val = MOD;
  global_150 = val; /* l_66 */
  return_location = (&body_104);
}
void body_105();
pointer global_151;
/* l_67 */
void body_104() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_151 = val; /* l_67 */
  return_location = (&body_105);
}
void body_106();
pointer global_152;
/* l_68 */
void body_105() {
  val = BNEG;
  global_152 = val; /* l_68 */
  return_location = (&body_106);
}
void body_107();
pointer global_153;
/* l_69 */
void body_106() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_153 = val; /* l_69 */
  return_location = (&body_107);
}
void body_108();
pointer global_154;
/* l_70 */
void body_107() {
  val = BAND;
  global_154 = val; /* l_70 */
  return_location = (&body_108);
}
void body_109();
pointer global_155;
/* l_71 */
void body_108() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_155 = val; /* l_71 */
  return_location = (&body_109);
}
void body_110();
pointer global_156;
/* l_72 */
void body_109() {
  val = BOR;
  global_156 = val; /* l_72 */
  return_location = (&body_110);
}
void body_111();
pointer global_157;
/* l_73 */
void body_110() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_157 = val; /* l_73 */
  return_location = (&body_111);
}
void body_112();
pointer global_158;
/* l_74 */
void body_111() {
  val = BXOR;
  global_158 = val; /* l_74 */
  return_location = (&body_112);
}
void body_113();
pointer global_159;
/* l_75 */
void body_112() {
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
  global_159 = val; /* l_75 */
  return_location = (&body_113);
}
void body_114();
pointer global_160;
/* l_76 */
void body_113() {
  val = SRSHIFT;
  global_160 = val; /* l_76 */
  return_location = (&body_114);
}
void body_115();
pointer global_161;
/* l_77 */
void body_114() {
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
  global_161 = val; /* l_77 */
  return_location = (&body_115);
}
void body_116();
pointer global_162;
/* l_78 */
void body_115() {
  val = URSHIFT;
  global_162 = val; /* l_78 */
  return_location = (&body_116);
}
void body_117();
pointer global_163;
/* l_79 */
void body_116() {
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
  global_163 = val; /* l_79 */
  return_location = (&body_117);
}
void body_118();
pointer global_164;
/* l_80 */
void body_117() {
  val = LSHIFT;
  global_164 = val; /* l_80 */
  return_location = (&body_118);
}
void body_119();
pointer global_165;
/* l_81 */
void body_118() {
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
  global_165 = val; /* l_81 */
  return_location = (&body_119);
}
void body_120();
pointer global_166;
/* l_82 */
void body_119() {
  val = DEFINE;
  global_166 = val; /* l_82 */
  return_location = (&body_120);
}
void body_121();
pointer global_167;
void function_91() {
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
void function_92() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_166); /* l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_91), env);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_90); /* _get-symbol */
    top_level_apply();
  }
}
void function_93() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_164); /* l_80 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_165); /* l_81 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_92));
  }
}
void function_94() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_162); /* l_78 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_163); /* l_79 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_93));
  }
}
void function_95() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_160); /* l_76 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_161); /* l_77 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_94));
  }
}
void function_96() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_158); /* l_74 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_159); /* l_75 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_95));
  }
}
void function_97() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_156); /* l_72 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_157); /* l_73 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_96));
  }
}
void function_98() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_154); /* l_70 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_155); /* l_71 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_97));
  }
}
void function_99() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_152); /* l_68 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_153); /* l_69 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_98));
  }
}
void function_100() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_150); /* l_66 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_151); /* l_67 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_99));
  }
}
void function_101() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_148); /* l_64 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_149); /* l_65 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_100));
  }
}
void function_102() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_146); /* l_62 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_147); /* l_63 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_101));
  }
}
void function_103() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_144); /* l_60 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_145); /* l_61 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_102));
  }
}
void function_104() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_142); /* l_58 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_143); /* l_59 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_103));
  }
}
void function_105() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_140); /* l_56 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_141); /* l_57 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_104));
  }
}
void function_106() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_138); /* l_54 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_139); /* l_55 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_105));
  }
}
void function_107() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_136); /* l_52 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_137); /* l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_106));
  }
}
void function_108() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_134); /* l_50 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_135); /* l_51 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_107));
  }
}
void function_109() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_132); /* l_48 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_133); /* l_49 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_108));
  }
}
void function_110() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_130); /* l_46 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_131); /* l_47 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_109));
  }
}
void function_111() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_128); /* l_44 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_129); /* l_45 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_110));
  }
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
    increment_count(val = global_126); /* l_42 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_127); /* l_43 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_111));
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
    increment_count(val = global_124); /* l_40 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_125); /* l_41 */
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
    increment_count(val = global_122); /* l_38 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_123); /* l_39 */
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
    increment_count(val = global_120); /* l_36 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_121); /* l_37 */
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
    increment_count(val = global_118); /* l_34 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_119); /* l_35 */
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
    increment_count(val = global_116); /* l_32 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_117); /* l_33 */
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
    increment_count(val = global_114); /* l_30 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_115); /* l_31 */
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
    increment_count(val = global_112); /* l_28 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_113); /* l_29 */
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
    increment_count(val = global_110); /* l_26 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_111); /* l_27 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_119));
  }
}
void function_121() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_109); /* l_25 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_120));
}
/* _lookup-symbol */
void body_120() {
  increment_count(env);
  val = new_function((&function_121), env);
  global_167 = val; /* _lookup-symbol */
  return_location = (&body_121);
}
void body_122();
pointer global_169;
void function_122() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
/* _fail */
void body_121() {
  increment_count(env);
  val = new_function((&function_122), env);
  global_169 = val; /* _fail */
  return_location = (&body_122);
}
void body_123();
pointer global_171;
void function_123() {
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
/* _done */
void body_122() {
  increment_count(env);
  val = new_function((&function_123), env);
  global_171 = val; /* _done */
  return_location = (&body_123);
}
void body_124();
pointer global_172;
/* l_83 */
void body_123() {
  val = NIL;
  global_172 = val; /* l_83 */
  return_location = (&body_124);
}
void body_125();
pointer global_173;
void function_124() {
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
void function_125() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_172); /* l_83 */
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
    increment_count(val = global_173); /* _pop */
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
    apply((&function_124));
  }
}
void function_126() {
  increment_count(env);
  val = new_function((&function_125), env);
  pop_function();
}
/* _pop */
void body_124() {
  increment_count(env);
  val = new_function((&function_126), env);
  global_173 = val; /* _pop */
  return_location = (&body_125);
}
void body_126();
pointer global_174;
void function_127() {
  top_level_apply();
}
void function_128() {
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
    apply((&function_127));
  }
}
void function_129() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_128));
}
void function_130() {
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
  val = new_function((&function_129), env);
  args = cons(val, args);
  increment_count(val = global_173); /* _pop */
  top_level_apply();
}
void function_131() {
  increment_count(env);
  val = new_function((&function_130), env);
  pop_function();
}
/* _check */
void body_125() {
  increment_count(env);
  val = new_function((&function_131), env);
  global_174 = val; /* _check */
  return_location = (&body_126);
}
void body_127();
pointer global_176;
void function_132() {
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
void function_133() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_132), env);
  args = cons(val, args);
  increment_count(val = global_174); /* _check */
  top_level_apply();
}
/* _match */
void body_126() {
  increment_count(env);
  val = new_function((&function_133), env);
  global_176 = val; /* _match */
  return_location = (&body_127);
}
void body_128();
pointer global_177;
void function_134() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_135() {
  increment_count(env);
  val = new_function((&function_134), env);
  pop_function();
}
/* _default */
void body_127() {
  increment_count(env);
  val = new_function((&function_135), env);
  global_177 = val; /* _default */
  return_location = (&body_128);
}
void body_129();
pointer global_180;
void function_136() {
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
void function_137() {
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
void function_138() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_137), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_136), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_139() {
  increment_count(env);
  val = new_function((&function_138), env);
  pop_function();
}
void function_140() {
  increment_count(env);
  val = new_function((&function_139), env);
  pop_function();
}
/* _case */
void body_128() {
  increment_count(env);
  val = new_function((&function_140), env);
  global_180 = val; /* _case */
  return_location = (&body_129);
}
void body_130();
pointer global_182;
void function_141() {
  top_level_apply();
}
void function_142() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_143() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169); /* _fail */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_142), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_141));
}
/* _choice */
void body_129() {
  increment_count(env);
  val = new_function((&function_143), env);
  global_182 = val; /* _choice */
  return_location = (&body_130);
}
void body_131();
pointer global_184;
void function_144() {
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
void function_145() {
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
  val = new_function((&function_144), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_146() {
  increment_count(env);
  val = new_function((&function_145), env);
  pop_function();
}
/* _post-process */
void body_130() {
  increment_count(env);
  val = new_function((&function_146), env);
  global_184 = val; /* _post-process */
  return_location = (&body_131);
}
void body_132();
pointer global_185;
void function_147() {
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
void function_148() {
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
  val = new_function((&function_147), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_149() {
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
  val = new_function((&function_148), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_150() {
  increment_count(env);
  val = new_function((&function_149), env);
  pop_function();
}
/* _seq */
void body_131() {
  increment_count(env);
  val = new_function((&function_150), env);
  global_185 = val; /* _seq */
  return_location = (&body_132);
}
void body_133();
pointer global_188;
void function_151() {
  args = cons(val, args);
  increment_count(val = global_185); /* _seq */
  top_level_apply();
}
void function_152() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_92); /* _escape-char */
  args = cons(val, args);
  increment_count(val = global_173); /* _pop */
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  apply((&function_151));
}
/* _escape */
void body_132() {
  increment_count(env);
  val = new_function((&function_152), env);
  global_188 = val; /* _escape */
  return_location = (&body_133);
}
void body_134();
pointer global_189;
void function_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_173); /* _pop */
  args = cons(val, args);
  increment_count(val = global_185); /* _seq */
  top_level_apply();
}
/* _use */
void body_133() {
  increment_count(env);
  val = new_function((&function_153), env);
  global_189 = val; /* _use */
  return_location = (&body_134);
}
void body_135();
pointer global_190;
void function_154() {
  top_level_apply();
}
void function_155() {
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
  apply((&function_154));
}
void function_156() {
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
  val = new_function((&function_155), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_157() {
  increment_count(env);
  val = new_function((&function_156), env);
  pop_function();
}
/* _peek */
void body_134() {
  increment_count(env);
  val = new_function((&function_157), env);
  global_190 = val; /* _peek */
  return_location = (&body_135);
}
void body_136();
pointer global_192;
void function_158() {
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
void function_159() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_158), env);
  args = cons(val, args);
  increment_count(val = global_174); /* _check */
  top_level_apply();
}
/* _interval */
void body_135() {
  increment_count(env);
  val = new_function((&function_159), env);
  global_192 = val; /* _interval */
  return_location = (&body_136);
}
void body_137();
pointer global_194;
void function_160() {
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  top_level_apply();
}
void function_161() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99); /* _drop-first */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_189); /* _use */
  apply((&function_160));
}
/* _skip */
void body_136() {
  increment_count(env);
  val = new_function((&function_161), env);
  global_194 = val; /* _skip */
  return_location = (&body_137);
}
void body_138();
pointer global_195;
void function_162() {
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  top_level_apply();
}
void function_163() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_101); /* _drop-second */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_185); /* _seq */
  apply((&function_162));
}
/* _first */
void body_137() {
  increment_count(env);
  val = new_function((&function_163), env);
  global_195 = val; /* _first */
  return_location = (&body_138);
}
void body_139();
pointer global_196;
void function_164() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_165() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_164));
}
void function_166() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_165));
}
void function_167() {
  args = cons(val, args);
  increment_count(val = global_190); /* _peek */
  apply((&function_166));
}
void function_168() {
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
  increment_count(val = global_192); /* _interval */
  apply((&function_167));
}
void function_169() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_196); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_189); /* _use */
  apply((&function_168));
}
void function_170() {
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
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_169));
}
/* _parse-num */
void body_138() {
  increment_count(env);
  val = new_function((&function_170), env);
  global_196 = val; /* _parse-num */
  return_location = (&body_139);
}
void body_140();
pointer global_197;
void function_171() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_172() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_95); /* _build-num */
  args = cons(val, args);
  increment_count(val = global_196); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  apply((&function_171));
}
/* _read-num */
void body_139() {
  increment_count(env);
  val = new_function((&function_172), env);
  global_197 = val; /* _read-num */
  return_location = (&body_140);
}
void body_141();
pointer global_198;
void function_173() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_174() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_173));
}
void function_175() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_174));
}
void function_176() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_192); /* _interval */
  apply((&function_175));
}
void function_177() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_176));
}
void function_178() {
  args = cons(val, args);
  increment_count(val = global_190); /* _peek */
  apply((&function_177));
}
void function_179() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
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
  increment_count(val = global_192); /* _interval */
  apply((&function_178));
}
void function_180() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_179));
}
void function_181() {
  args = cons(val, args);
  increment_count(val = global_190); /* _peek */
  apply((&function_180));
}
void function_182() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_181));
}
void function_183() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_182));
}
void function_184() {
  args = cons(val, args);
  increment_count(val = global_190); /* _peek */
  apply((&function_183));
}
void function_185() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_184));
}
void function_186() {
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_185));
}
void function_187() {
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
  increment_count(val = global_198); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_189); /* _use */
  apply((&function_186));
}
/* _parse-symbol */
void body_140() {
  increment_count(env);
  val = new_function((&function_187), env);
  global_198 = val; /* _parse-symbol */
  return_location = (&body_141);
}
void body_142();
pointer global_199;
void function_188() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_189() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_167); /* _lookup-symbol */
  args = cons(val, args);
  increment_count(val = global_198); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  apply((&function_188));
}
/* _read-symbol */
void body_141() {
  increment_count(env);
  val = new_function((&function_189), env);
  global_199 = val; /* _read-symbol */
  return_location = (&body_142);
}
void body_143();
pointer global_200;
void function_190() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_191() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_190));
}
void function_192() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_191));
}
void function_193() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_192));
}
void function_194() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_193));
}
void function_195() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_194));
}
void function_196() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_200); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_188); /* _escape */
  apply((&function_195));
}
void function_197() {
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_196));
}
void function_198() {
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
  increment_count(val = global_200); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_189); /* _use */
  apply((&function_197));
}
/* _parse-string */
void body_142() {
  increment_count(env);
  val = new_function((&function_198), env);
  global_200 = val; /* _parse-string */
  return_location = (&body_143);
}
void body_144();
pointer global_201;
void function_199() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_103); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  top_level_apply();
}
/* _quote-parser */
void body_143() {
  increment_count(env);
  val = new_function((&function_199), env);
  global_201 = val; /* _quote-parser */
  return_location = (&body_144);
}
void body_145();
pointer global_202;
void function_200() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_106); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  top_level_apply();
}
/* _quasiquote-parser */
void body_144() {
  increment_count(env);
  val = new_function((&function_200), env);
  global_202 = val; /* _quasiquote-parser */
  return_location = (&body_145);
}
void body_146();
pointer global_203;
void function_201() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_108); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184); /* _post-process */
  top_level_apply();
}
/* _unquote-parser */
void body_145() {
  increment_count(env);
  val = new_function((&function_201), env);
  global_203 = val; /* _unquote-parser */
  return_location = (&body_146);
}
void body_147();
pointer global_204;
void function_202() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_203() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_202));
}
void function_204() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_203));
}
void function_205() {
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
  increment_count(val = global_176); /* _match */
  apply((&function_204));
}
void function_206() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_205));
}
void function_207() {
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
  increment_count(val = global_176); /* _match */
  apply((&function_206));
}
void function_208() {
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_207));
}
void function_209() {
  args = cons(val, args);
  increment_count(val = global_194); /* _skip */
  apply((&function_208));
}
void function_210() {
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
  increment_count(val = global_204); /* _comment */
  apply((&function_209));
}
void function_211() {
  increment_count(env);
  val = new_function((&function_210), env);
  pop_function();
}
/* _comment */
void body_146() {
  increment_count(env);
  val = new_function((&function_211), env);
  global_204 = val; /* _comment */
  return_location = (&body_147);
}
void body_148();
pointer global_205;
void function_212() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_213() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_212));
}
void function_214() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_213));
}
void function_215() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205); /* _parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192); /* _interval */
  apply((&function_214));
}
void function_216() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_215));
}
void function_217() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_216));
}
void function_218() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_204); /* _comment */
  apply((&function_217));
}
void function_219() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_218));
}
void function_220() {
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
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_219));
}
/* _parse-paren */
void body_147() {
  increment_count(env);
  val = new_function((&function_220), env);
  global_205 = val; /* _parse-paren */
  return_location = (&body_148);
}
void body_149();
pointer global_207 = NIL; /* _parse-expr */
pointer global_206;
void function_221() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_222() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_221));
}
void function_223() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_222));
}
void function_224() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_206); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192); /* _interval */
  apply((&function_223));
}
void function_225() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_224));
}
void function_226() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_225));
}
void function_227() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_206); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_204); /* _comment */
  apply((&function_226));
}
void function_228() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_227));
}
void function_229() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_228));
}
void function_230() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_229));
}
void function_231() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_230));
}
void function_232() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_195); /* _first */
  apply((&function_231));
}
void function_233() {
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_232));
}
void function_234() {
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
  increment_count(val = global_206); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_185); /* _seq */
  apply((&function_233));
}
/* _parse-pair */
void body_148() {
  increment_count(env);
  val = new_function((&function_234), env);
  global_206 = val; /* _parse-pair */
  return_location = (&body_149);
}
void body_150();
void function_235() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_236() {
  args = cons(val, args);
  increment_count(val = global_182); /* _choice */
  apply((&function_235));
}
void function_237() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_236));
}
void function_238() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192); /* _interval */
  apply((&function_237));
}
void function_239() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_238));
}
void function_240() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_239));
}
void function_241() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_200); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_201); /* _quote-parser */
  apply((&function_240));
}
void function_242() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_241));
}
void function_243() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_242));
}
void function_244() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_201); /* _quote-parser */
  apply((&function_243));
}
void function_245() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_244));
}
void function_246() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
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
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_202); /* _quasiquote-parser */
  apply((&function_246));
}
void function_248() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_247));
}
void function_249() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_248));
}
void function_250() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_203); /* _unquote-parser */
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_250));
}
void function_252() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_206); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_251));
}
void function_253() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_252));
}
void function_254() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_254));
}
void function_256() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_256));
}
void function_258() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176); /* _match */
  apply((&function_257));
}
void function_259() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_204); /* _comment */
  apply((&function_258));
}
void function_260() {
  args = cons(val, args);
  increment_count(val = global_180); /* _case */
  apply((&function_259));
}
void function_261() {
  args = cons(val, args);
  increment_count(val = global_190); /* _peek */
  apply((&function_260));
}
void function_262() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_197); /* _read-num */
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
  increment_count(val = global_192); /* _interval */
  apply((&function_261));
}
void function_263() {
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
  increment_count(val = global_199); /* _read-symbol */
  args = cons(val, args);
  increment_count(val = global_177); /* _default */
  apply((&function_262));
}
/* _parse-expr */
void body_149() {
  increment_count(env);
  val = new_function((&function_263), env);
  global_207 = val; /* _parse-expr */
  return_location = (&body_150);
}
void body_151();
pointer global_208;
/* l_84 */
void body_150() {
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
  global_208 = val; /* l_84 */
  return_location = (&body_151);
}
void body_152();
pointer global_209;
/* l_85 */
void body_151() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_209 = val; /* l_85 */
  return_location = (&body_152);
}
void body_153();
pointer global_213 = NIL; /* _print-num */
pointer global_210;
void function_264() {
  args = cons(val, args);
  increment_count(val = global_75); /* _print-error */
  top_level_apply();
}
void function_265() {
  args = cons(val, args);
  increment_count(val = global_208); /* l_84 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_264));
}
void function_266() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_209); /* l_85 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_213); /* _print-num */
  apply((&function_265));
}
void function_267() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_266), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_207); /* _parse-expr */
  top_level_apply();
}
/* _read-expr */
void body_152() {
  increment_count(env);
  val = new_function((&function_267), env);
  global_210 = val; /* _read-expr */
  return_location = (&body_153);
}
void body_154();
pointer global_214;
void function_268() {
  top_level_apply();
}
void function_269() {
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
void function_270() {
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
void function_271() {
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
void function_272() {
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
void function_273() {
  increment_count(env);
  val = new_function((&function_272), env);
  pop_function();
}
void function_274() {
  increment_count(val = global_13); /* _id */
  pop_function();
}
void function_275() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_274), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_273), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_271), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_270), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_269), env);
  args = cons(val, args);
  increment_count(val = global_20); /* _walk */
  apply((&function_268));
}
/* _build-num-str */
void body_153() {
  increment_count(env);
  val = new_function((&function_275), env);
  global_214 = val; /* _build-num-str */
  return_location = (&body_154);
}
void body_155();
pointer global_217;
/* l_86 */
void body_154() {
  val = NIL;
  global_217 = val; /* l_86 */
  return_location = (&body_155);
}
void body_156();
pointer global_218;
/* l_87 */
void body_155() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_218 = val; /* l_87 */
  return_location = (&body_156);
}
void body_157();
pointer global_219;
/* l_88 */
void body_156() {
  val = NIL;
  global_219 = val; /* l_88 */
  return_location = (&body_157);
}
void body_158();
void function_276() {
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
void function_277() {
  apply((&function_276));
}
void function_278() {
  top_level_apply();
}
void function_279() {
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
    increment_count(val = global_217); /* l_86 */
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
    increment_count(val = global_214); /* _build-num-str */
    apply((&function_277));
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
      increment_count(val = global_218); /* l_87 */
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_219); /* l_88 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_214); /* _build-num-str */
      apply((&function_278));
    }
  }
}
/* _print-num */
void body_157() {
  increment_count(env);
  val = new_function((&function_279), env);
  global_213 = val; /* _print-num */
  return_location = (&body_158);
}
void body_159();
pointer global_220;
/* l_89 */
void body_158() {
  val = QUOTE;
  global_220 = val; /* l_89 */
  return_location = (&body_159);
}
void body_160();
pointer global_221;
/* l_90 */
void body_159() {
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
  global_221 = val; /* l_90 */
  return_location = (&body_160);
}
void body_161();
pointer global_222;
/* l_91 */
void body_160() {
  val = QUASIQUOTE;
  global_222 = val; /* l_91 */
  return_location = (&body_161);
}
void body_162();
pointer global_223;
/* l_92 */
void body_161() {
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
  global_223 = val; /* l_92 */
  return_location = (&body_162);
}
void body_163();
pointer global_224;
/* l_93 */
void body_162() {
  val = UNQUOTE;
  global_224 = val; /* l_93 */
  return_location = (&body_163);
}
void body_164();
pointer global_225;
/* l_94 */
void body_163() {
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
  global_225 = val; /* l_94 */
  return_location = (&body_164);
}
void body_165();
pointer global_226;
/* l_95 */
void body_164() {
  val = CAR;
  global_226 = val; /* l_95 */
  return_location = (&body_165);
}
void body_166();
pointer global_227;
/* l_96 */
void body_165() {
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
  global_227 = val; /* l_96 */
  return_location = (&body_166);
}
void body_167();
pointer global_228;
/* l_97 */
void body_166() {
  val = CDR;
  global_228 = val; /* l_97 */
  return_location = (&body_167);
}
void body_168();
pointer global_229;
/* l_98 */
void body_167() {
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
  global_229 = val; /* l_98 */
  return_location = (&body_168);
}
void body_169();
pointer global_230;
/* l_99 */
void body_168() {
  val = NUMBER;
  global_230 = val; /* l_99 */
  return_location = (&body_169);
}
void body_170();
pointer global_231;
/* l_100 */
void body_169() {
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
  global_231 = val; /* l_100 */
  return_location = (&body_170);
}
void body_171();
pointer global_232;
/* l_101 */
void body_170() {
  val = FUNCTION;
  global_232 = val; /* l_101 */
  return_location = (&body_171);
}
void body_172();
pointer global_233;
/* l_102 */
void body_171() {
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
  global_233 = val; /* l_102 */
  return_location = (&body_172);
}
void body_173();
pointer global_234;
/* l_103 */
void body_172() {
  val = ATOM;
  global_234 = val; /* l_103 */
  return_location = (&body_173);
}
void body_174();
pointer global_235;
/* l_104 */
void body_173() {
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
  global_235 = val; /* l_104 */
  return_location = (&body_174);
}
void body_175();
pointer global_236;
/* l_105 */
void body_174() {
  val = CONS;
  global_236 = val; /* l_105 */
  return_location = (&body_175);
}
void body_176();
pointer global_237;
/* l_106 */
void body_175() {
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
  global_237 = val; /* l_106 */
  return_location = (&body_176);
}
void body_177();
pointer global_238;
/* l_107 */
void body_176() {
  val = COND;
  global_238 = val; /* l_107 */
  return_location = (&body_177);
}
void body_178();
pointer global_239;
/* l_108 */
void body_177() {
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
  global_239 = val; /* l_108 */
  return_location = (&body_178);
}
void body_179();
pointer global_240;
/* l_109 */
void body_178() {
  val = IF;
  global_240 = val; /* l_109 */
  return_location = (&body_179);
}
void body_180();
pointer global_241;
/* l_110 */
void body_179() {
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
  global_241 = val; /* l_110 */
  return_location = (&body_180);
}
void body_181();
pointer global_242;
/* l_111 */
void body_180() {
  val = LET;
  global_242 = val; /* l_111 */
  return_location = (&body_181);
}
void body_182();
pointer global_243;
/* l_112 */
void body_181() {
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
  global_243 = val; /* l_112 */
  return_location = (&body_182);
}
void body_183();
pointer global_244;
/* l_113 */
void body_182() {
  val = FN;
  global_244 = val; /* l_113 */
  return_location = (&body_183);
}
void body_184();
pointer global_245;
/* l_114 */
void body_183() {
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
  global_245 = val; /* l_114 */
  return_location = (&body_184);
}
void body_185();
pointer global_246;
/* l_115 */
void body_184() {
  val = URSHIFT;
  global_246 = val; /* l_115 */
  return_location = (&body_185);
}
void body_186();
pointer global_247;
/* l_116 */
void body_185() {
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
  global_247 = val; /* l_116 */
  return_location = (&body_186);
}
void body_187();
pointer global_248;
/* l_117 */
void body_186() {
  val = SRSHIFT;
  global_248 = val; /* l_117 */
  return_location = (&body_187);
}
void body_188();
pointer global_249;
/* l_118 */
void body_187() {
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
  global_249 = val; /* l_118 */
  return_location = (&body_188);
}
void body_189();
pointer global_250;
/* l_119 */
void body_188() {
  val = LSHIFT;
  global_250 = val; /* l_119 */
  return_location = (&body_189);
}
void body_190();
pointer global_251;
/* l_120 */
void body_189() {
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
  global_251 = val; /* l_120 */
  return_location = (&body_190);
}
void body_191();
pointer global_252;
/* l_121 */
void body_190() {
  val = LT;
  global_252 = val; /* l_121 */
  return_location = (&body_191);
}
void body_192();
pointer global_253;
/* l_122 */
void body_191() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_253 = val; /* l_122 */
  return_location = (&body_192);
}
void body_193();
pointer global_254;
/* l_123 */
void body_192() {
  val = GT;
  global_254 = val; /* l_123 */
  return_location = (&body_193);
}
void body_194();
pointer global_255;
/* l_124 */
void body_193() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_255 = val; /* l_124 */
  return_location = (&body_194);
}
void body_195();
pointer global_256;
/* l_125 */
void body_194() {
  val = EQ;
  global_256 = val; /* l_125 */
  return_location = (&body_195);
}
void body_196();
pointer global_257;
/* l_126 */
void body_195() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_257 = val; /* l_126 */
  return_location = (&body_196);
}
void body_197();
pointer global_258;
/* l_127 */
void body_196() {
  val = PLUS;
  global_258 = val; /* l_127 */
  return_location = (&body_197);
}
void body_198();
pointer global_259;
/* l_128 */
void body_197() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_259 = val; /* l_128 */
  return_location = (&body_198);
}
void body_199();
pointer global_260;
/* l_129 */
void body_198() {
  val = MINUS;
  global_260 = val; /* l_129 */
  return_location = (&body_199);
}
void body_200();
pointer global_261;
/* l_130 */
void body_199() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_261 = val; /* l_130 */
  return_location = (&body_200);
}
void body_201();
pointer global_262;
/* l_131 */
void body_200() {
  val = MULT;
  global_262 = val; /* l_131 */
  return_location = (&body_201);
}
void body_202();
pointer global_263;
/* l_132 */
void body_201() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_263 = val; /* l_132 */
  return_location = (&body_202);
}
void body_203();
pointer global_264;
/* l_133 */
void body_202() {
  val = DIV;
  global_264 = val; /* l_133 */
  return_location = (&body_203);
}
void body_204();
pointer global_265;
/* l_134 */
void body_203() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_265 = val; /* l_134 */
  return_location = (&body_204);
}
void body_205();
pointer global_266;
/* l_135 */
void body_204() {
  val = MOD;
  global_266 = val; /* l_135 */
  return_location = (&body_205);
}
void body_206();
pointer global_267;
/* l_136 */
void body_205() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_267 = val; /* l_136 */
  return_location = (&body_206);
}
void body_207();
pointer global_268;
/* l_137 */
void body_206() {
  val = BAND;
  global_268 = val; /* l_137 */
  return_location = (&body_207);
}
void body_208();
pointer global_269;
/* l_138 */
void body_207() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_269 = val; /* l_138 */
  return_location = (&body_208);
}
void body_209();
pointer global_270;
/* l_139 */
void body_208() {
  val = BOR;
  global_270 = val; /* l_139 */
  return_location = (&body_209);
}
void body_210();
pointer global_271;
/* l_140 */
void body_209() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_271 = val; /* l_140 */
  return_location = (&body_210);
}
void body_211();
pointer global_272;
/* l_141 */
void body_210() {
  val = BXOR;
  global_272 = val; /* l_141 */
  return_location = (&body_211);
}
void body_212();
pointer global_273;
/* l_142 */
void body_211() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_273 = val; /* l_142 */
  return_location = (&body_212);
}
void body_213();
pointer global_274;
/* l_143 */
void body_212() {
  val = BNEG;
  global_274 = val; /* l_143 */
  return_location = (&body_213);
}
void body_214();
pointer global_275;
/* l_144 */
void body_213() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_275 = val; /* l_144 */
  return_location = (&body_214);
}
void body_215();
pointer global_276;
/* l_145 */
void body_214() {
  val = DEFINE;
  global_276 = val; /* l_145 */
  return_location = (&body_215);
}
void body_216();
pointer global_277;
/* l_146 */
void body_215() {
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
  global_277 = val; /* l_146 */
  return_location = (&body_216);
}
void body_217();
pointer global_278;
/* l_147 */
void body_216() {
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
  global_278 = val; /* l_147 */
  return_location = (&body_217);
}
void body_218();
pointer global_279;
void function_280() {
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
    increment_count(val = global_213); /* _print-num */
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
      increment_count(val = global_81); /* _symbol->string */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_220); /* l_89 */
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
        increment_count(val = global_221); /* l_90 */
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_222); /* l_91 */
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
          increment_count(val = global_223); /* l_92 */
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_224); /* l_93 */
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
            increment_count(val = global_225); /* l_94 */
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_226); /* l_95 */
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
              increment_count(val = global_227); /* l_96 */
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_228); /* l_97 */
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
                increment_count(val = global_229); /* l_98 */
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_230); /* l_99 */
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
                  increment_count(val = global_231); /* l_100 */
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  increment_count(val = global_232); /* l_101 */
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
                    increment_count(val = global_233); /* l_102 */
                    pop_function();
                  } else {
                    push_args();
                    val = NIL;
                    args = val;
                    increment_count(val = global_234); /* l_103 */
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
                      increment_count(val = global_235); /* l_104 */
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      increment_count(val = global_236); /* l_105 */
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
                        increment_count(val = global_237); /* l_106 */
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        increment_count(val = global_238); /* l_107 */
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
                          increment_count(val = global_239); /* l_108 */
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          increment_count(val = global_240); /* l_109 */
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
                            increment_count(val = global_241); /* l_110 */
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            increment_count(val = global_242); /* l_111 */
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
                              increment_count(val = global_243); /* l_112 */
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              increment_count(val = global_244); /* l_113 */
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
                                increment_count(val = global_245); /* l_114 */
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                increment_count(val = global_246); /* l_115 */
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
                                  increment_count(val = global_247); /* l_116 */
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  increment_count(val = global_248); /* l_117 */
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
                                    increment_count(val = global_249); /* l_118 */
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    increment_count(val = global_250); /* l_119 */
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
                                      increment_count(val = global_251); /* l_120 */
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      increment_count(val = global_252); /* l_121 */
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
                                        increment_count(val = global_253); /* l_122 */
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        increment_count(val = global_254); /* l_123 */
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
                                          increment_count(val = global_255); /* l_124 */
                                          pop_function();
                                        } else {
                                          push_args();
                                          val = NIL;
                                          args = val;
                                          increment_count(val = global_256); /* l_125 */
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
                                            increment_count(val = global_257); /* l_126 */
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            increment_count(val = global_258); /* l_127 */
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
                                              increment_count(val = global_259); /* l_128 */
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              increment_count(val = global_260); /* l_129 */
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
                                                increment_count(val = global_261); /* l_130 */
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                increment_count(val = global_262); /* l_131 */
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
                                                  increment_count(val = global_263); /* l_132 */
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  increment_count(val = global_264); /* l_133 */
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
                                                    increment_count(val = global_265); /* l_134 */
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    increment_count(val = global_266); /* l_135 */
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
                                                      increment_count(val = global_267); /* l_136 */
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      increment_count(val = global_268); /* l_137 */
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
                                                        increment_count(val = global_269); /* l_138 */
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        increment_count(val = global_270); /* l_139 */
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
                                                          increment_count(val = global_271); /* l_140 */
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          increment_count(val = global_272); /* l_141 */
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
                                                            increment_count(val = global_273); /* l_142 */
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            increment_count(val = global_274); /* l_143 */
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
                                                              increment_count(val = global_275); /* l_144 */
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              increment_count(val = global_276); /* l_145 */
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
                                                                increment_count(val = global_277); /* l_146 */
                                                                pop_function();
                                                              } else {
                                                                increment_count(val = global_278); /* l_147 */
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
/* _print-atom */
void body_217() {
  increment_count(env);
  val = new_function((&function_280), env);
  global_279 = val; /* _print-atom */
  return_location = (&body_218);
}
void body_219();
pointer global_280;
/* l_148 */
void body_218() {
  val = NIL;
  global_280 = val; /* l_148 */
  return_location = (&body_219);
}
void body_220();
pointer global_281;
/* l_149 */
void body_219() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_281 = val; /* l_149 */
  return_location = (&body_220);
}
void body_221();
pointer global_282;
/* l_150 */
void body_220() {
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
  global_282 = val; /* l_150 */
  return_location = (&body_221);
}
void body_222();
pointer global_283;
/* l_151 */
void body_221() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_283 = val; /* l_151 */
  return_location = (&body_222);
}
void body_223();
pointer global_284;
/* l_152 */
void body_222() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_284 = val; /* l_152 */
  return_location = (&body_223);
}
void body_224();
pointer global_287 = NIL; /* _print-with-suffix */
pointer global_285;
void function_281() {
  args = cons(val, args);
  increment_count(val = global_282); /* l_150 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_282() {
  args = cons(val, args);
  increment_count(val = global_284); /* l_152 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_283() {
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
  increment_count(val = global_287); /* _print-with-suffix */
  apply((&function_282));
}
void function_284() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_280); /* l_148 */
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
    increment_count(val = global_281); /* l_149 */
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
      increment_count(val = global_283); /* l_151 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_279); /* _print-atom */
      apply((&function_281));
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
      increment_count(val = global_285); /* _print-tail */
      apply((&function_283));
    }
  }
}
/* _print-tail */
void body_223() {
  increment_count(env);
  val = new_function((&function_284), env);
  global_285 = val; /* _print-tail */
  return_location = (&body_224);
}
void body_225();
pointer global_288;
/* l_153 */
void body_224() {
  val = NIL;
  global_288 = val; /* l_153 */
  return_location = (&body_225);
}
void body_226();
pointer global_289;
/* l_154 */
void body_225() {
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
  global_289 = val; /* l_154 */
  return_location = (&body_226);
}
void body_227();
pointer global_290;
/* l_155 */
void body_226() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_290 = val; /* l_155 */
  return_location = (&body_227);
}
void body_228();
void function_285() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_286() {
  args = cons(val, args);
  increment_count(val = global_290); /* l_155 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_287() {
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
  increment_count(val = global_287); /* _print-with-suffix */
  apply((&function_286));
}
void function_288() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_288); /* l_153 */
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
    increment_count(val = global_289); /* l_154 */
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
      increment_count(val = global_279); /* _print-atom */
      apply((&function_285));
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
      increment_count(val = global_285); /* _print-tail */
      apply((&function_287));
    }
  }
}
/* _print-with-suffix */
void body_227() {
  increment_count(env);
  val = new_function((&function_288), env);
  global_287 = val; /* _print-with-suffix */
  return_location = (&body_228);
}
void body_229();
pointer global_291;
/* l_156 */
void body_228() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_291 = val; /* l_156 */
  return_location = (&body_229);
}
void body_230();
pointer global_292;
void function_289() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_291); /* l_156 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_287); /* _print-with-suffix */
  top_level_apply();
}
/* _print-with-newline */
void body_229() {
  increment_count(env);
  val = new_function((&function_289), env);
  global_292 = val; /* _print-with-newline */
  return_location = (&body_230);
}
void body_231();
pointer global_293;
/* l_157 */
void body_230() {
  val = NIL;
  global_293 = val; /* l_157 */
  return_location = (&body_231);
}
void body_232();
void function_290() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_293); /* l_157 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_287); /* _print-with-suffix */
  top_level_apply();
}
/* _print */
void body_231() {
  increment_count(env);
  val = new_function((&function_290), env);
  global_72 = val; /* _print */
  return_location = (&body_232);
}
void body_233();
pointer global_294;
/* l_158 */
void body_232() {
  val = NIL;
  global_294 = val; /* l_158 */
  return_location = (&body_233);
}
void body_234();
pointer global_295;
void function_291() {
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
  increment_count(val = global_295); /* _flatten */
  top_level_apply();
}
void function_292() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_294); /* l_158 */
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
      if (length(args) == 2) {
        increment_count(car(args));
        increment_count(car(cdr(args)));
        val = cons(car(args), car(cdr(args)));
      } else { val = NIL; }
      pop_args();
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
      increment_count(val = global_295); /* _flatten */
      apply((&function_291));
    }
  }
}
/* _flatten */
void body_233() {
  increment_count(env);
  val = new_function((&function_292), env);
  global_295 = val; /* _flatten */
  return_location = (&body_234);
}
void body_235();
pointer global_298;
/* l_159 */
void body_234() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_298 = val; /* l_159 */
  return_location = (&body_235);
}
void body_236();
pointer global_299;
void function_293() {
  args = cons(val, args);
  increment_count(val = global_77); /* _make-symbol */
  top_level_apply();
}
void function_294() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_79); /* _symbol->id */
  apply((&function_293));
}
void function_295() {
  args = cons(val, args);
  increment_count(val = global_298); /* l_159 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_294));
}
void function_296() {
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
  increment_count(val = global_299); /* _escape-symbols */
  apply((&function_296));
}
void function_298() {
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
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_81); /* _symbol->string */
    apply((&function_295));
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
      increment_count(val = global_299); /* _escape-symbols */
      apply((&function_297));
    }
  }
}
/* _escape-symbols */
void body_235() {
  increment_count(env);
  val = new_function((&function_298), env);
  global_299 = val; /* _escape-symbols */
  return_location = (&body_236);
}
void body_237();
pointer global_300;
/* l_160 */
void body_236() {
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
  global_300 = val; /* l_160 */
  return_location = (&body_237);
}
void body_238();
pointer global_301;
/* l_161 */
void body_237() {
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
  global_301 = val; /* l_161 */
  return_location = (&body_238);
}
void body_239();
pointer global_302;
/* l_162 */
void body_238() {
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
  global_302 = val; /* l_162 */
  return_location = (&body_239);
}
void body_240();
pointer global_303;
void function_299() {
  global_303 = val; /* _supported-builtins */
  return_location = (&body_240);
}
/* _supported-builtins */
void body_239() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_302); /* l_162 */
  args = cons(val, args);
  increment_count(val = global_301); /* l_161 */
  args = cons(val, args);
  increment_count(val = global_300); /* l_160 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_299));
}
void body_241();
pointer global_304;
/* l_163 */
void body_240() {
  val = NIL;
  global_304 = val; /* l_163 */
  return_location = (&body_241);
}
void body_242();
pointer global_305;
/* l_164 */
void body_241() {
  val = NIL;
  global_305 = val; /* l_164 */
  return_location = (&body_242);
}
void body_243();
pointer global_306;
/* l_165 */
void body_242() {
  val = NIL;
  global_306 = val; /* l_165 */
  return_location = (&body_243);
}
void body_244();
pointer global_307;
/* l_166 */
void body_243() {
  val = NIL;
  global_307 = val; /* l_166 */
  return_location = (&body_244);
}
void body_245();
pointer global_308;
/* l_167 */
void body_244() {
  val = NIL;
  global_308 = val; /* l_167 */
  return_location = (&body_245);
}
void body_246();
pointer global_309;
/* l_168 */
void body_245() {
  val = NIL;
  global_309 = val; /* l_168 */
  return_location = (&body_246);
}
void body_247();
pointer global_310;
/* l_169 */
void body_246() {
  val = NIL;
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
  args = NIL;
  pop_args();
  global_310 = val; /* l_169 */
  return_location = (&body_247);
}
void body_248();
pointer global_311;
/* l_170 */
void body_247() {
  val = NIL;
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
  args = NIL;
  pop_args();
  global_311 = val; /* l_170 */
  return_location = (&body_248);
}
void body_249();
pointer global_312;
void function_300() {
  args = cons(val, args);
  increment_count(val = global_304); /* l_163 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_301() {
  args = cons(val, args);
  increment_count(val = global_309); /* l_168 */
  args = cons(val, args);
  increment_count(val = global_308); /* l_167 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_302() {
  args = cons(val, args);
  increment_count(val = global_310); /* l_169 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_301));
}
void function_303() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_307); /* l_166 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_306); /* l_165 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_311); /* l_170 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_81); /* _symbol->string */
    apply((&function_302));
  }
}
void function_304() {
  apply((&function_303));
}
void function_305() {
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  args = cons(val, args);
  increment_count(val = global_58); /* _contains */
  apply((&function_304));
}
void function_306() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_305); /* l_164 */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_299); /* _escape-symbols */
    apply((&function_300));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_303); /* _supported-builtins */
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_81); /* _symbol->string */
    apply((&function_305));
  }
}
void function_307() {
  apply((&function_306));
}
void function_308() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_82); /* _symbol-eq */
  args = cons(val, args);
  increment_count(val = global_58); /* _contains */
  apply((&function_307));
}
void function_309() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_295); /* _flatten */
  apply((&function_308));
}
/* _compile-find */
void body_248() {
  increment_count(env);
  val = new_function((&function_309), env);
  global_312 = val; /* _compile-find */
  return_location = (&body_249);
}
void body_250();
pointer global_317;
/* l_171 */
void body_249() {
  val = NIL;
  global_317 = val; /* l_171 */
  return_location = (&body_250);
}
void body_251();
pointer global_318;
/* l_172 */
void body_250() {
  val = QUOTE;
  global_318 = val; /* l_172 */
  return_location = (&body_251);
}
void body_252();
pointer global_319;
/* l_173 */
void body_251() {
  val = CONS;
  global_319 = val; /* l_173 */
  return_location = (&body_252);
}
void body_253();
pointer global_320;
void function_310() {
  args = cons(val, args);
  increment_count(val = global_319); /* l_173 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  top_level_apply();
}
void function_311() {
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
  increment_count(val = global_320); /* _rewrite-quote */
  apply((&function_310));
}
void function_312() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_317); /* l_171 */
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
    increment_count(val = car(car(env)));
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
      increment_count(val = car(car(env)));
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
        increment_count(val = car(car(env)));
        args = cons(val, args);
        increment_count(val = global_318); /* l_172 */
        args = cons(val, args);
        increment_count(val = global_14); /* _list */
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
          increment_count(val = cdr(car(args)));
          } else { val = NIL; }
        } else { val = NIL; }
        pop_args();
        args = cons(val, args);
        increment_count(val = global_320); /* _rewrite-quote */
        apply((&function_311));
      }
    }
  }
}
/* _rewrite-quote */
void body_252() {
  increment_count(env);
  val = new_function((&function_312), env);
  global_320 = val; /* _rewrite-quote */
  return_location = (&body_253);
}
void body_254();
pointer global_322;
/* l_174 */
void body_253() {
  val = NIL;
  global_322 = val; /* l_174 */
  return_location = (&body_254);
}
void body_255();
pointer global_323;
/* l_175 */
void body_254() {
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = new_number(108);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_323 = val; /* l_175 */
  return_location = (&body_255);
}
void body_256();
pointer global_324;
void function_313() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
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
  increment_count(val = global_322); /* l_174 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
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
  val = DEFINE;
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
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_314() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_313), env);
  top_level_apply();
}
void function_315() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
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
  increment_count(val = global_77); /* _make-symbol */
  apply((&function_314));
}
void function_316() {
  args = cons(val, args);
  increment_count(val = global_323); /* l_175 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_315));
}
void function_317() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_72); /* _print */
  apply((&function_316));
}
/* _compile-quote */
void body_255() {
  increment_count(env);
  val = new_function((&function_317), env);
  global_324 = val; /* _compile-quote */
  return_location = (&body_256);
}
void body_257();
pointer global_326;
/* l_176 */
void body_256() {
  val = NIL;
  global_326 = val; /* l_176 */
  return_location = (&body_257);
}
void body_258();
pointer global_327;
/* l_177 */
void body_257() {
  val = NIL;
  global_327 = val; /* l_177 */
  return_location = (&body_258);
}
void body_259();
pointer global_328;
/* l_178 */
void body_258() {
  val = NIL;
  global_328 = val; /* l_178 */
  return_location = (&body_259);
}
void body_260();
pointer global_329;
/* l_179 */
void body_259() {
  val = QUOTE;
  global_329 = val; /* l_179 */
  return_location = (&body_260);
}
void body_261();
pointer global_330;
/* l_180 */
void body_260() {
  val = NIL;
  global_330 = val; /* l_180 */
  return_location = (&body_261);
}
void body_262();
pointer global_331;
/* l_181 */
void body_261() {
  val = UNQUOTE;
  global_331 = val; /* l_181 */
  return_location = (&body_262);
}
void body_263();
pointer global_332;
/* l_182 */
void body_262() {
  val = UNQUOTE;
  global_332 = val; /* l_182 */
  return_location = (&body_263);
}
void body_264();
pointer global_333;
/* l_183 */
void body_263() {
  val = QUASIQUOTE;
  global_333 = val; /* l_183 */
  return_location = (&body_264);
}
void body_265();
pointer global_334;
/* l_184 */
void body_264() {
  val = QUASIQUOTE;
  global_334 = val; /* l_184 */
  return_location = (&body_265);
}
void body_266();
pointer global_335;
/* l_185 */
void body_265() {
  val = CONS;
  global_335 = val; /* l_185 */
  return_location = (&body_266);
}
void body_267();
pointer global_338 = NIL; /* _compile-expr */
pointer global_336;
void function_318() {
  args = cons(val, args);
  increment_count(val = global_328); /* l_178 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  top_level_apply();
}
void function_319() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_320() {
  args = cons(val, args);
  increment_count(val = global_336); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_321() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_322() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_332); /* l_182 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_321));
}
void function_323() {
  args = cons(val, args);
  increment_count(val = global_336); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_324() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_325() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_334); /* l_184 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_324));
}
void function_326() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_327() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_326));
}
void function_328() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_335); /* l_185 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_327));
}
void function_329() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
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
  increment_count(val = global_14); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
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
  increment_count(val = global_336); /* _rewrite-quasiquote */
  apply((&function_330));
}
void function_332() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_331), env);
  top_level_apply();
}
void function_333() {
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
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
    args = cons(val, args);
    increment_count(val = global_327); /* l_177 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_326); /* l_176 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
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
      increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
      args = cons(val, args);
      increment_count(val = global_330); /* l_180 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_329); /* l_179 */
      args = cons(val, args);
      increment_count(val = global_14); /* _list */
      apply((&function_318));
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_331); /* l_181 */
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
        val = new_number(0);
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
          push_args();
          val = NIL;
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
          val = NIL;
          args = val;
          increment_count(val = car(car(env)));
          args = cons(val, args);
          increment_count(val = global_7); /* _cadr */
          apply((&function_319));
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(env);
          val = new_function((&function_322), env);
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(car(env))))));
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(car(env)))));
          args = cons(val, args);
          push_args();
          val = NIL;
          args = val;
          val = new_number(1);
          args = cons(val, args);
          increment_count(val = car(cdr(car(env))));
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
          increment_count(val = car(car(env)));
          args = cons(val, args);
          increment_count(val = global_7); /* _cadr */
          apply((&function_320));
        }
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_333); /* l_183 */
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
          increment_count(env);
          val = new_function((&function_325), env);
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(car(env))))));
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(car(env)))));
          args = cons(val, args);
          push_args();
          val = NIL;
          args = val;
          val = new_number(1);
          args = cons(val, args);
          increment_count(val = car(cdr(car(env))));
          args = cons(val, args);
          if ((length(args) == 2) &&
              (is_number(car(args))) &&
              (is_number(car(cdr(args))))) {
            val = new_number(value(car(args)) + value(car(cdr(args)))); 
          } else { val = NIL; }
          pop_args();
          args = cons(val, args);
          push_args();
          val = NIL;
          args = val;
          increment_count(val = car(car(env)));
          args = cons(val, args);
          increment_count(val = global_7); /* _cadr */
          apply((&function_323));
        } else {
          push_args();
          val = NIL;
          args = val;
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_14); /* _list */
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
          args = cons(val, args);
          increment_count(val = car(cdr(cdr(cdr(car(env))))));
          args = cons(val, args);
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
            increment_count(val = car(car(args)));
            } else { val = NIL; }
          } else { val = NIL; }
          pop_args();
          args = cons(val, args);
          increment_count(val = global_336); /* _rewrite-quasiquote */
          apply((&function_332));
        }
      }
    }
  }
}
/* _rewrite-quasiquote */
void body_266() {
  increment_count(env);
  val = new_function((&function_333), env);
  global_336 = val; /* _rewrite-quasiquote */
  return_location = (&body_267);
}
void body_268();
pointer global_347;
/* l_186 */
void body_267() {
  val = NIL;
  global_347 = val; /* l_186 */
  return_location = (&body_268);
}
void body_269();
pointer global_348;
/* l_187 */
void body_268() {
  val = QUOTE;
  global_348 = val; /* l_187 */
  return_location = (&body_269);
}
void body_270();
pointer global_349;
/* l_188 */
void body_269() {
  val = NIL;
  global_349 = val; /* l_188 */
  return_location = (&body_270);
}
void body_271();
pointer global_350;
/* l_189 */
void body_270() {
  val = NIL;
  global_350 = val; /* l_189 */
  return_location = (&body_271);
}
void body_272();
pointer global_351;
/* l_190 */
void body_271() {
  val = NIL;
  global_351 = val; /* l_190 */
  return_location = (&body_272);
}
void body_273();
pointer global_352;
/* l_191 */
void body_272() {
  val = -86;
  global_352 = val; /* l_191 */
  return_location = (&body_273);
}
void body_274();
pointer global_353;
void function_334() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_349); /* l_188 */
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_350); /* l_189 */
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
    if ((length(args) == 2) &&
        (is_atom(car(args))) &&
        (is_atom(car(cdr(args)))) &&
        eq(car(args), car(cdr(args)))) {
      increment_count(val = true);
    } else { val = NIL; }
    pop_args();
    if (val != NIL) {
      decrement_count(val);
      increment_count(val = global_351); /* l_190 */
      pop_function();
    } else {
      increment_count(val = global_352); /* l_191 */
      pop_function();
    }
  }
}
void function_335() {
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
    increment_count(val = global_347); /* l_186 */
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
      increment_count(val = car(car(env)));
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_348); /* l_187 */
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
      apply((&function_334));
    }
  }
}
/* _always-true */
void body_273() {
  increment_count(env);
  val = new_function((&function_335), env);
  global_353 = val; /* _always-true */
  return_location = (&body_274);
}
void body_275();
pointer global_354;
/* l_192 */
void body_274() {
  val = NIL;
  global_354 = val; /* l_192 */
  return_location = (&body_275);
}
void body_276();
pointer global_355;
/* l_193 */
void body_275() {
  val = NIL;
  global_355 = val; /* l_193 */
  return_location = (&body_276);
}
void body_277();
pointer global_356;
/* l_194 */
void body_276() {
  val = NIL;
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
  args = NIL;
  pop_args();
  global_356 = val; /* l_194 */
  return_location = (&body_277);
}
void body_278();
pointer global_357;
/* l_195 */
void body_277() {
  val = IF;
  global_357 = val; /* l_195 */
  return_location = (&body_278);
}
void body_279();
pointer global_358;
void function_336() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_337() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_338() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_337));
}
void function_339() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_357); /* l_195 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_338));
}
void function_340() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_339));
}
void function_341() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_340), env);
  top_level_apply();
}
void function_342() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_358); /* _rewrite-cond */
  apply((&function_341));
}
void function_343() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_342), env);
  top_level_apply();
}
void function_344() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  apply((&function_343));
}
void function_345() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_11); /* _cadar */
  apply((&function_344));
}
void function_346() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_345), env);
  top_level_apply();
}
void function_347() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  apply((&function_346));
}
void function_348() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
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
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_11); /* _cadar */
    apply((&function_336));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_14); /* _list */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_4); /* _caar */
    apply((&function_347));
  }
}
void function_349() {
  args = cons(val, args);
  increment_count(val = global_353); /* _always-true */
  apply((&function_348));
}
void function_350() {
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
    increment_count(val = global_356); /* l_194 */
    args = cons(val, args);
    increment_count(val = global_355); /* l_193 */
    args = cons(val, args);
    increment_count(val = global_354); /* l_192 */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
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
    increment_count(val = global_4); /* _caar */
    apply((&function_349));
  }
}
/* _rewrite-cond */
void body_278() {
  increment_count(env);
  val = new_function((&function_350), env);
  global_358 = val; /* _rewrite-cond */
  return_location = (&body_279);
}
void body_280();
pointer global_369;
/* l_196 */
void body_279() {
  val = FN;
  global_369 = val; /* l_196 */
  return_location = (&body_280);
}
void body_281();
pointer global_370;
void function_351() {
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  top_level_apply();
}
void function_352() {
  args = cons(val, args);
  increment_count(val = global_369); /* l_196 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_351));
}
void function_353() {
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_352));
}
void function_354() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_4); /* _caar */
  apply((&function_353));
}
void function_355() {
  args = cons(val, args);
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
  increment_count(val = global_370); /* _rewrite-let */
  apply((&function_354));
}
void function_356() {
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
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_11); /* _cadar */
    apply((&function_355));
  }
}
/* _rewrite-let */
void body_280() {
  increment_count(env);
  val = new_function((&function_356), env);
  global_370 = val; /* _rewrite-let */
  return_location = (&body_281);
}
void body_282();
pointer global_372;
void function_357() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(env)))))))));
  top_level_apply();
}
void function_358() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
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
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_357));
}
void function_359() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_358));
}
void function_360() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_359), env);
  top_level_apply();
}
void function_361() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14); /* _list */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
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
  increment_count(val = global_372); /* _compile-args */
  apply((&function_360));
}
void function_362() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_361), env);
  top_level_apply();
}
void function_363() {
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
    increment_count(val = global_338); /* _compile-expr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_14); /* _list */
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
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
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_338); /* _compile-expr */
    apply((&function_362));
  }
}
/* _compile-args */
void body_281() {
  increment_count(env);
  val = new_function((&function_363), env);
  global_372 = val; /* _compile-args */
  return_location = (&body_282);
}
void body_283();
pointer global_379;
/* l_197 */
void body_282() {
  val = NIL;
  global_379 = val; /* l_197 */
  return_location = (&body_283);
}
void body_284();
pointer global_380;
/* l_198 */
void body_283() {
  val = NIL;
  global_380 = val; /* l_198 */
  return_location = (&body_284);
}
void body_285();
pointer global_381;
/* l_199 */
void body_284() {
  val = QUOTE;
  global_381 = val; /* l_199 */
  return_location = (&body_285);
}
void body_286();
pointer global_382;
/* l_200 */
void body_285() {
  val = QUASIQUOTE;
  global_382 = val; /* l_200 */
  return_location = (&body_286);
}
void body_287();
pointer global_383;
/* l_201 */
void body_286() {
  val = UNQUOTE;
  global_383 = val; /* l_201 */
  return_location = (&body_287);
}
void body_288();
pointer global_384;
/* l_202 */
void body_287() {
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
  args = NIL;
  pop_args();
  global_384 = val; /* l_202 */
  return_location = (&body_288);
}
void body_289();
pointer global_385;
/* l_203 */
void body_288() {
  val = COND;
  global_385 = val; /* l_203 */
  return_location = (&body_289);
}
void body_290();
pointer global_386;
/* l_204 */
void body_289() {
  val = LET;
  global_386 = val; /* l_204 */
  return_location = (&body_290);
}
void body_291();
pointer global_387;
/* l_205 */
void body_290() {
  val = FN;
  global_387 = val; /* l_205 */
  return_location = (&body_291);
}
void body_292();
pointer global_388;
/* l_206 */
void body_291() {
  val = FN;
  global_388 = val; /* l_206 */
  return_location = (&body_292);
}
void body_293();
void function_364() {
  args = cons(val, args);
  increment_count(val = global_336); /* _rewrite-quasiquote */
  top_level_apply();
}
void function_365() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_366() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_367() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_384); /* l_202 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_366));
}
void function_368() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_369() {
  args = cons(val, args);
  increment_count(val = global_370); /* _rewrite-let */
  apply((&function_368));
}
void function_370() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_369));
}
void function_371() {
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_372() {
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
  increment_count(val = global_12); /* _caddr */
  apply((&function_371));
}
void function_373() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_374() {
  args = cons(val, args);
  increment_count(val = global_388); /* l_206 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_373));
}
void function_375() {
  args = cons(val, args);
  increment_count(val = global_299); /* _escape-symbols */
  apply((&function_374));
}
void function_376() {
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
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_375));
}
void function_377() {
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
    increment_count(val = global_312); /* _compile-find */
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
      increment_count(val = car(cdr(cdr(cdr(car(env))))));
      args = cons(val, args);
      increment_count(val = global_380); /* l_198 */
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_379); /* l_197 */
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_381); /* l_199 */
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
        increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
        args = cons(val, args);
        increment_count(val = car(cdr(cdr(cdr(car(env))))));
        args = cons(val, args);
        increment_count(val = car(car(env)));
        args = cons(val, args);
        increment_count(val = global_324); /* _compile-quote */
        top_level_apply();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_382); /* l_200 */
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
          val = NIL;
          args = val;
          increment_count(val = car(car(env)));
          args = cons(val, args);
          increment_count(val = global_7); /* _cadr */
          apply((&function_364));
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_383); /* l_201 */
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
            increment_count(env);
            val = new_function((&function_367), env);
            args = cons(val, args);
            increment_count(val = car(cdr(cdr(cdr(car(env))))));
            args = cons(val, args);
            increment_count(val = car(cdr(cdr(car(env)))));
            args = cons(val, args);
            increment_count(val = car(cdr(car(env))));
            args = cons(val, args);
            push_args();
            val = NIL;
            args = val;
            increment_count(val = car(car(env)));
            args = cons(val, args);
            increment_count(val = global_7); /* _cadr */
            apply((&function_365));
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_385); /* l_203 */
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
              increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
              args = cons(val, args);
              increment_count(val = car(cdr(cdr(cdr(car(env))))));
              args = cons(val, args);
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
              increment_count(val = global_358); /* _rewrite-cond */
              top_level_apply();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_386); /* l_204 */
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
                increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
                args = cons(val, args);
                increment_count(val = car(cdr(cdr(cdr(car(env))))));
                args = cons(val, args);
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
                increment_count(val = global_12); /* _caddr */
                apply((&function_370));
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_387); /* l_205 */
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
                  increment_count(env);
                  val = new_function((&function_376), env);
                  args = cons(val, args);
                  increment_count(val = car(cdr(cdr(cdr(car(env))))));
                  args = cons(val, args);
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
                  increment_count(val = global_7); /* _cadr */
                  apply((&function_372));
                } else {
                  push_args();
                  val = NIL;
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
                  increment_count(val = global_372); /* _compile-args */
                  top_level_apply();
                }
              }
            }
          }
        }
      }
    }
  }
}
/* _compile-expr */
void body_292() {
  increment_count(env);
  val = new_function((&function_377), env);
  global_338 = val; /* _compile-expr */
  return_location = (&body_293);
}
void body_294();
pointer global_389;
void function_378() {
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
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_7); /* _cadr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_10); /* _caadr */
    top_level_apply();
  }
}
void function_379() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_378));
}
/* _get-name */
void body_293() {
  increment_count(env);
  val = new_function((&function_379), env);
  global_389 = val; /* _get-name */
  return_location = (&body_294);
}
void body_295();
pointer global_391;
/* l_207 */
void body_294() {
  val = FN;
  global_391 = val; /* l_207 */
  return_location = (&body_295);
}
void body_296();
pointer global_392;
void function_380() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_391); /* l_207 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  top_level_apply();
}
void function_381() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_380));
}
void function_382() {
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
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_12); /* _caddr */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_12); /* _caddr */
    apply((&function_381));
  }
}
void function_383() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7); /* _cadr */
  apply((&function_382));
}
/* _get-body */
void body_295() {
  increment_count(env);
  val = new_function((&function_383), env);
  global_392 = val; /* _get-body */
  return_location = (&body_296);
}
void body_297();
pointer global_393;
/* l_208 */
void body_296() {
  val = NIL;
  global_393 = val; /* l_208 */
  return_location = (&body_297);
}
void body_298();
pointer global_394;
void function_384() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_385() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_69); /* _print-warnings */
  apply((&function_384));
}
void function_386() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_385));
}
void function_387() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_292); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_386));
}
void function_388() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = DEFINE;
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_292); /* _print-with-newline */
  apply((&function_387));
}
void function_389() {
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
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
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
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_299); /* _escape-symbols */
  apply((&function_388));
}
void function_390() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(cdr(cdr(cdr(env))))))))));
  apply((&function_389));
}
void function_391() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_390), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_393); /* l_208 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  top_level_apply();
}
void function_392() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_391), env);
  top_level_apply();
}
void function_393() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_392); /* _get-body */
  apply((&function_392));
}
void function_394() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_393), env);
  top_level_apply();
}
void function_395() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_389); /* _get-name */
  apply((&function_394));
}
void function_396() {
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
  increment_count(env);
  val = new_function((&function_395), env);
  top_level_apply();
}
/* _compile-definition */
void body_297() {
  increment_count(env);
  val = new_function((&function_396), env);
  global_394 = val; /* _compile-definition */
  return_location = (&body_298);
}
void body_299();
pointer global_397;
void function_397() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
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
  increment_count(val = global_397); /* _compile-definitions */
  top_level_apply();
}
void function_398() {
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
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_397), env);
    args = cons(val, args);
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
      increment_count(val = car(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_394); /* _compile-definition */
    top_level_apply();
  }
}
/* _compile-definitions */
void body_298() {
  increment_count(env);
  val = new_function((&function_398), env);
  global_397 = val; /* _compile-definitions */
  return_location = (&body_299);
}
void body_300();
pointer global_398;
/* l_209 */
void body_299() {
  val = NIL;
  global_398 = val; /* l_209 */
  return_location = (&body_300);
}
void body_301();
pointer global_399;
void function_399() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_400() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_69); /* _print-warnings */
  apply((&function_399));
}
void function_401() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_400));
}
void function_402() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_292); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_401));
}
void function_403() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_292); /* _print-with-newline */
  apply((&function_402));
}
void function_404() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_403), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_397); /* _compile-definitions */
  top_level_apply();
}
void function_405() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_404), env);
  top_level_apply();
}
void function_406() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14); /* _list */
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_398); /* l_209 */
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_338); /* _compile-expr */
  apply((&function_405));
}
void function_407() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_406), env);
  top_level_apply();
}
void function_408() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_389); /* _get-name */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_407));
}
/* _compile */
void body_300() {
  increment_count(env);
  val = new_function((&function_408), env);
  global_399 = val; /* _compile */
  return_location = (&body_301);
}
void body_302();
pointer global_402;
/* l_210 */
void body_301() {
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
  global_402 = val; /* l_210 */
  return_location = (&body_302);
}
void body_303();
pointer global_403;
/* l_211 */
void body_302() {
  val = DEFINE;
  global_403 = val; /* l_211 */
  return_location = (&body_303);
}
void body_304();
pointer global_404;
/* l_212 */
void body_303() {
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
  global_404 = val; /* l_212 */
  return_location = (&body_304);
}
void body_305();
pointer global_405;
void function_409() {
  args = cons(val, args);
  increment_count(val = global_399); /* _compile */
  top_level_apply();
}
void function_410() {
  args = cons(val, args);
  increment_count(val = global_210); /* _read-expr */
  top_level_apply();
}
void function_411() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_404); /* l_212 */
    args = cons(val, args);
    increment_count(val = global_75); /* _print-error */
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
    increment_count(val = global_405); /* _compile-source */
    apply((&function_410));
  }
}
void function_412() {
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
  apply((&function_411));
}
void function_413() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_47); /* _or */
  apply((&function_412));
}
void function_414() {
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
  apply((&function_413));
}
void function_415() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(cdr(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(cdr(env))));
    args = cons(val, args);
    increment_count(val = global_31); /* _reverse */
    apply((&function_409));
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
    apply((&function_414));
  }
}
void function_416() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_402); /* l_210 */
    args = cons(val, args);
    increment_count(val = global_75); /* _print-error */
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_403); /* l_211 */
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
    apply((&function_415));
  }
}
void function_417() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
  apply((&function_416));
}
void function_418() {
  increment_count(env);
  val = new_function((&function_417), env);
  pop_function();
}
/* _compile-source */
void body_304() {
  increment_count(env);
  val = new_function((&function_418), env);
  global_405 = val; /* _compile-source */
  return_location = (&body_305);
}
void body_306();
pointer global_409;
/* l_1 */
void body_305() {
  val = NIL;
  global_409 = val; /* l_1 */
  return_location = (&body_306);
}
void body_307();
pointer global_410;
/* l_2 */
void body_306() {
  val = NIL;
  global_410 = val; /* l_2 */
  return_location = (&body_307);
}
void function_419() {
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
void function_420() {
  args = cons(val, args);
  increment_count(val = global_210); /* _read-expr */
  top_level_apply();
}
void function_421() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_410); /* l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_409); /* l_1 */
  args = cons(val, args);
  increment_count(val = global_405); /* _compile-source */
  apply((&function_420));
}
void body_307() {
  increment_count(env);
  val = new_function((&function_421), env);
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
    call_stack = cons(new_function((&function_419), NIL), call_stack);
    return_location = ;
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
  call_stack = cons(new_function((&top_level), NIL), call_stack);
  call_stack = cons(new_function((&function_419), NIL), call_stack);
  return_location = (&body_0);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
