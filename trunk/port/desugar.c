#ifdef BARE_HARDWARE
#include "multiboot.h"
#else
#include <stdlib.h>
#endif
#include "io.h"
#include "mem.h"
#include "eval.h"
pointer arguments = NIL;
#ifdef BARE_HARDWARE
pointer get_cmd(unsigned long flags, char* command) {
  pointer r = NIL;
  int i = 0;
  if (getFlag(flags,2) != 0) {
    while ((command > 0) && (command[i] != '\0')) {
      i++;
    }
    while (i > 0) {
      i--;
      r = cons(new_number(command[i]), r);
    }
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
void function_0() {
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
pointer global_1 = NIL;
pointer global_2 = NIL;
pointer global_3 = NIL;
pointer global_4 = NIL;
pointer global_5 = NIL;
pointer global_6 = NIL;
pointer global_7 = NIL;
pointer global_8 = NIL;
pointer global_9 = NIL;
pointer global_10 = NIL;
pointer global_11 = NIL;
pointer global_12 = NIL;
pointer global_13 = NIL;
pointer global_14 = NIL;
pointer global_15 = NIL;
pointer global_16 = NIL;
pointer global_17 = NIL;
pointer global_18 = NIL;
pointer global_19 = NIL;
pointer global_20 = NIL;
pointer global_21 = NIL;
pointer global_22 = NIL;
pointer global_23 = NIL;
pointer global_24 = NIL;
pointer global_25 = NIL;
pointer global_26 = NIL;
pointer global_27 = NIL;
pointer global_28 = NIL;
pointer global_29 = NIL;
pointer global_30 = NIL;
pointer global_31 = NIL;
pointer global_32 = NIL;
pointer global_33 = NIL;
pointer global_34 = NIL;
pointer global_35 = NIL;
pointer global_36 = NIL;
pointer global_37 = NIL;
pointer global_38 = NIL;
pointer global_39 = NIL;
pointer global_40 = NIL;
pointer global_41 = NIL;
pointer global_42 = NIL;
pointer global_43 = NIL;
pointer global_44 = NIL;
pointer global_45 = NIL;
pointer global_46 = NIL;
pointer global_47 = NIL;
pointer global_48 = NIL;
pointer global_49 = NIL;
pointer global_50 = NIL;
pointer global_51 = NIL;
pointer global_52 = NIL;
pointer global_53 = NIL;
pointer global_54 = NIL;
pointer global_55 = NIL;
pointer global_56 = NIL;
pointer global_57 = NIL;
pointer global_58 = NIL;
pointer global_59 = NIL;
pointer global_60 = NIL;
pointer global_61 = NIL;
pointer global_62 = NIL;
pointer global_63 = NIL;
pointer global_64 = NIL;
pointer global_65 = NIL;
pointer global_66 = NIL;
pointer global_67 = NIL;
pointer global_68 = NIL;
pointer global_69 = NIL;
pointer global_70 = NIL;
pointer global_71 = NIL;
pointer global_72 = NIL;
pointer global_73 = NIL;
pointer global_74 = NIL;
pointer global_75 = NIL;
pointer global_76 = NIL;
pointer global_77 = NIL;
pointer global_78 = NIL;
pointer global_79 = NIL;
pointer global_80 = NIL;
pointer global_81 = NIL;
pointer global_82 = NIL;
pointer global_83 = NIL;
pointer global_84 = NIL;
pointer global_85 = NIL;
pointer global_86 = NIL;
pointer global_87 = NIL;
pointer global_88 = NIL;
pointer global_89 = NIL;
pointer global_90 = NIL;

void function_91() {
  args = cons(val, args);
  val = global_21;
  increment_count(val);
  top_level_apply();
}
void function_92() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  val = global_1;
  increment_count(val);
  apply((&function_91));
}
void function_93() {
  args = cons(val, args);
  val = global_2;
  increment_count(val);
  top_level_apply();
}
void function_94() {
  args = cons(val, args);
  val = global_21;
  increment_count(val);
  top_level_apply();
}
void function_95() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    val = global_64;
    increment_count(val);
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
    val = global_1;
    increment_count(val);
    apply((&function_94));
  }
}
void function_96() {
  args = cons(val, args);
  val = global_68;
  increment_count(val);
  apply((&function_95));
}
void function_97() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = global_70;
  increment_count(val);
  apply((&function_96));
}
void function_98() {
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
  val = global_88;
  increment_count(val);
  apply((&function_97));
}
void function_99() {
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
    val = global_76;
    increment_count(val);
    apply((&function_93));
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
    val = global_85;
    increment_count(val);
    apply((&function_98));
  }
}
void function_100() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    val = global_64;
    increment_count(val);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    val = DEFINE;
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
    val = global_68;
    increment_count(val);
    apply((&function_99));
  }
}
void function_101() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_68;
  increment_count(val);
  apply((&function_100));
}
void function_102() {
  increment_count(env);
  val = new_function((&function_101), env);
  pop_function();
}
void function_103() {
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_104() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_103));
}
void function_105() {
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
  val = global_81;
  increment_count(val);
  apply((&function_104));
}
void function_106() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_105), env);
  top_level_apply();
}
void function_107() {
  args = cons(val, args);
  val = global_71;
  increment_count(val);
  apply((&function_106));
}
void function_108() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  val = global_3;
  increment_count(val);
  apply((&function_107));
}
void function_109() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_108), env);
  top_level_apply();
}
void function_110() {
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_111() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(env)))))));
  args = cons(val, args);
  val = global_65;
  increment_count(val);
  apply((&function_110));
}
void function_112() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_16;
  increment_count(val);
  apply((&function_111));
}
void function_113() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_112), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  apply((&function_109));
}
void function_114() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_113), env);
  top_level_apply();
}
void function_115() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_5;
  increment_count(val);
  args = cons(val, args);
  val = global_71;
  increment_count(val);
  apply((&function_114));
}
void function_116() {
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_117() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(cdr(env))))));
  args = cons(val, args);
  val = global_65;
  increment_count(val);
  apply((&function_116));
}
void function_118() {
  args = cons(val, args);
  val = global_16;
  increment_count(val);
  apply((&function_117));
}
void function_119() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
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
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  val = DEFINE;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_118));
}
void function_120() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_119), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(cdr(cdr(env)))))));
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_121() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_120), env);
  top_level_apply();
}
void function_122() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  val = global_4;
  increment_count(val);
  apply((&function_121));
}
void function_123() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_122), env);
  top_level_apply();
}
void function_124() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  val = global_5;
  increment_count(val);
  apply((&function_123));
}
void function_125() {
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
  val = new_function((&function_124), env);
  top_level_apply();
}
void function_126() {
  increment_count(env);
  val = new_function((&function_125), env);
  pop_function();
}
void function_127() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  val = FN;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  top_level_apply();
}
void function_128() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  val = global_88;
  increment_count(val);
  apply((&function_127));
}
void function_129() {
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
    val = global_83;
    increment_count(val);
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
    val = global_83;
    increment_count(val);
    apply((&function_128));
  }
}
void function_130() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  val = global_88;
  increment_count(val);
  apply((&function_129));
}
void function_131() {
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
    val = global_88;
    increment_count(val);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    val = global_85;
    increment_count(val);
    top_level_apply();
  }
}
void function_132() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  val = global_88;
  increment_count(val);
  apply((&function_131));
}
void function_133() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  top_level_apply();
}
void function_134() {
  args = cons(val, args);
  val = global_12;
  increment_count(val);
  apply((&function_133));
}
void function_135() {
  args = cons(val, args);
  val = global_11;
  increment_count(val);
  top_level_apply();
}
void function_136() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_137() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_138() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
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
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_137));
}
void function_139() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_140() {
  args = cons(val, args);
  val = global_8;
  increment_count(val);
  apply((&function_139));
}
void function_141() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_88;
  increment_count(val);
  apply((&function_140));
}
void function_142() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_143() {
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
  val = global_83;
  increment_count(val);
  apply((&function_142));
}
void function_144() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_145() {
  args = cons(val, args);
  val = FN;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_144));
}
void function_146() {
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
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  val = global_88;
  increment_count(val);
  apply((&function_145));
}
void function_147() {
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
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_13;
    increment_count(val);
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
      val = NIL;
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(cdr(car(env))))));
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      val = QUOTE;
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
        val = global_88;
        increment_count(val);
        apply((&function_134));
      } else {
        push_args();
        val = NIL;
        args = val;
        val = -115;
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
          val = global_88;
          increment_count(val);
          apply((&function_135));
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -117;
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
            val = new_function((&function_138), env);
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
            val = global_88;
            increment_count(val);
            apply((&function_136));
          } else {
            push_args();
            val = NIL;
            args = val;
            val = COND;
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
              val = global_9;
              increment_count(val);
              top_level_apply();
            } else {
              push_args();
              val = NIL;
              args = val;
              val = LET;
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
                val = global_83;
                increment_count(val);
                apply((&function_141));
              } else {
                push_args();
                val = NIL;
                args = val;
                val = FN;
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
                  val = new_function((&function_146), env);
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
                  val = global_88;
                  increment_count(val);
                  apply((&function_143));
                } else {
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
                  val = global_7;
                  increment_count(val);
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
void function_148() {
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
  increment_count(val = car(cdr(cdr(cdr(car(cdr(cdr(env))))))));
  top_level_apply();
}
void function_149() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_148));
}
void function_150() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_149), env);
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
  val = global_7;
  increment_count(val);
  top_level_apply();
}
void function_151() {
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
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_6;
    increment_count(val);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_150), env);
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
    val = global_6;
    increment_count(val);
    top_level_apply();
  }
}
void function_152() {
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  top_level_apply();
}
void function_153() {
  args = cons(val, args);
  val = FN;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_152));
}
void function_154() {
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_153));
}
void function_155() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_90;
  increment_count(val);
  apply((&function_154));
}
void function_156() {
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
  val = global_8;
  increment_count(val);
  apply((&function_155));
}
void function_157() {
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
    val = global_84;
    increment_count(val);
    apply((&function_156));
  }
}
void function_158() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_159() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(cdr(cdr(env)))))))));
  top_level_apply();
}
void function_160() {
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
  val = -119;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_159));
}
void function_161() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(cdr(env)))))));
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_160));
}
void function_162() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_161), env);
  top_level_apply();
}
void function_163() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_81;
  increment_count(val);
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
  val = global_9;
  increment_count(val);
  apply((&function_162));
}
void function_164() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_163), env);
  top_level_apply();
}
void function_165() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  apply((&function_164));
}
void function_166() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_81;
  increment_count(val);
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
  val = global_84;
  increment_count(val);
  apply((&function_165));
}
void function_167() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_166), env);
  top_level_apply();
}
void function_168() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  apply((&function_167));
}
void function_169() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
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
    val = global_84;
    increment_count(val);
    apply((&function_158));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    val = global_81;
    increment_count(val);
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
    val = global_90;
    increment_count(val);
    apply((&function_168));
  }
}
void function_170() {
  args = cons(val, args);
  val = global_10;
  increment_count(val);
  apply((&function_169));
}
void function_171() {
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
    args = cons(val, args);
    val = NIL;
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
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
    val = global_90;
    increment_count(val);
    apply((&function_170));
  }
}
void function_172() {
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
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
      val = NIL;
      pop_function();
    } else {
      val = -57;
      pop_function();
    }
  }
}
void function_173() {
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
      val = QUOTE;
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
      val = global_68;
      increment_count(val);
      apply((&function_172));
    }
  }
}
void function_174() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_175() {
  args = cons(val, args);
  val = global_6;
  increment_count(val);
  top_level_apply();
}
void function_176() {
  args = cons(val, args);
  val = global_11;
  increment_count(val);
  top_level_apply();
}
void function_177() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_178() {
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
  val = -117;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_177));
}
void function_179() {
  args = cons(val, args);
  val = global_11;
  increment_count(val);
  top_level_apply();
}
void function_180() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_181() {
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
  val = -115;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_180));
}
void function_182() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(env)))))))));
  top_level_apply();
}
void function_183() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  val = CONS;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_182));
}
void function_184() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_183));
}
void function_185() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_184), env);
  top_level_apply();
}
void function_186() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_81;
  increment_count(val);
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
  val = global_11;
  increment_count(val);
  apply((&function_185));
}
void function_187() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_186), env);
  top_level_apply();
}
void function_188() {
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
    val = NIL;
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
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
      val = NIL;
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      val = QUOTE;
      args = cons(val, args);
      val = global_81;
      increment_count(val);
      apply((&function_174));
    } else {
      push_args();
      val = NIL;
      args = val;
      val = -117;
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
          val = global_88;
          increment_count(val);
          apply((&function_175));
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(env);
          val = new_function((&function_178), env);
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
          val = global_88;
          increment_count(val);
          apply((&function_176));
        }
      } else {
        push_args();
        val = NIL;
        args = val;
        val = -115;
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
          val = new_function((&function_181), env);
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
          val = global_88;
          increment_count(val);
          apply((&function_179));
        } else {
          push_args();
          val = NIL;
          args = val;
          push_args();
          val = NIL;
          args = val;
          val = global_81;
          increment_count(val);
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
          val = global_11;
          increment_count(val);
          apply((&function_187));
        }
      }
    }
  }
}
void function_189() {
  args = cons(val, args);
  val = CONS;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  top_level_apply();
}
void function_190() {
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
  val = global_12;
  increment_count(val);
  apply((&function_189));
}
void function_191() {
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
      val = QUOTE;
      args = cons(val, args);
      val = global_81;
      increment_count(val);
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
      val = global_12;
      increment_count(val);
      apply((&function_190));
    }
  }
}
void function_192() {
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  top_level_apply();
}
void function_193() {
  args = cons(val, args);
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
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_192));
}
void function_194() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(32);
    args = cons(val, args);
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
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_61;
    increment_count(val);
    apply((&function_193));
  }
}
void function_195() {
  apply((&function_194));
}
void function_196() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_60;
  increment_count(val);
  args = cons(val, args);
  val = global_67;
  increment_count(val);
  apply((&function_195));
}
void function_197() {
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
  val = global_14;
  increment_count(val);
  apply((&function_196));
}
void function_198() {
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
  val = global_14;
  increment_count(val);
  top_level_apply();
}
void function_199() {
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
      val = global_14;
      increment_count(val);
      apply((&function_198));
    }
  }
}
void function_200() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_16;
  increment_count(val);
  top_level_apply();
}
void function_201() {
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_202() {
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
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_203() {
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
  val = global_16;
  increment_count(val);
  apply((&function_202));
}
void function_204() {
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
    val = new_number(40);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    val = global_73;
    increment_count(val);
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
      val = global_18;
      increment_count(val);
      apply((&function_201));
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
      val = global_17;
      increment_count(val);
      apply((&function_203));
    }
  }
}
void function_205() {
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
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_206() {
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
  val = global_73;
  increment_count(val);
  top_level_apply();
}
void function_207() {
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
  val = global_16;
  increment_count(val);
  apply((&function_206));
}
void function_208() {
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
    val = global_73;
    increment_count(val);
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
      val = global_18;
      increment_count(val);
      apply((&function_205));
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
      val = global_17;
      increment_count(val);
      apply((&function_207));
    }
  }
}
void function_209() {
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
    val = global_19;
    increment_count(val);
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
      val = global_61;
      increment_count(val);
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      val = QUOTE;
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
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        val = -115;
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
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          val = -117;
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
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            val = CAR;
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
              val = new_number(114);
              args = cons(val, args);
              val = new_number(97);
              args = cons(val, args);
              val = new_number(99);
              args = cons(val, args);
              val = args;
              args = NIL;
              pop_args();
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              val = CDR;
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
                val = new_number(114);
                args = cons(val, args);
                val = new_number(100);
                args = cons(val, args);
                val = new_number(99);
                args = cons(val, args);
                val = args;
                args = NIL;
                pop_args();
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                val = NUMBER;
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
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  val = FUNCTION;
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
                    pop_function();
                  } else {
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
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      val = CONS;
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
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        val = COND;
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
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          val = -119;
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
                            val = new_number(102);
                            args = cons(val, args);
                            val = new_number(105);
                            args = cons(val, args);
                            val = args;
                            args = NIL;
                            pop_args();
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            val = LET;
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
                              val = new_number(101);
                              args = cons(val, args);
                              val = new_number(108);
                              args = cons(val, args);
                              val = args;
                              args = NIL;
                              pop_args();
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              val = FN;
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
                                val = new_number(110);
                                args = cons(val, args);
                                val = new_number(102);
                                args = cons(val, args);
                                val = args;
                                args = NIL;
                                pop_args();
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                val = URSHIFT;
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
                                  val = new_number(62);
                                  args = cons(val, args);
                                  val = new_number(62);
                                  args = cons(val, args);
                                  val = new_number(62);
                                  args = cons(val, args);
                                  val = args;
                                  args = NIL;
                                  pop_args();
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  val = SRSHIFT;
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
                                    val = new_number(62);
                                    args = cons(val, args);
                                    val = new_number(62);
                                    args = cons(val, args);
                                    val = args;
                                    args = NIL;
                                    pop_args();
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    val = LSHIFT;
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
                                      val = new_number(60);
                                      args = cons(val, args);
                                      val = new_number(60);
                                      args = cons(val, args);
                                      val = args;
                                      args = NIL;
                                      pop_args();
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      val = LT;
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
                                        val = new_number(60);
                                        args = cons(val, args);
                                        val = args;
                                        args = NIL;
                                        pop_args();
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        val = GT;
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
                                          val = new_number(62);
                                          args = cons(val, args);
                                          val = args;
                                          args = NIL;
                                          pop_args();
                                          pop_function();
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
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            val = PLUS;
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
                                              val = new_number(43);
                                              args = cons(val, args);
                                              val = args;
                                              args = NIL;
                                              pop_args();
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              val = MINUS;
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
                                                val = new_number(45);
                                                args = cons(val, args);
                                                val = args;
                                                args = NIL;
                                                pop_args();
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                val = MULT;
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
                                                  val = new_number(42);
                                                  args = cons(val, args);
                                                  val = args;
                                                  args = NIL;
                                                  pop_args();
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  val = DIV;
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
                                                    val = new_number(47);
                                                    args = cons(val, args);
                                                    val = args;
                                                    args = NIL;
                                                    pop_args();
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    val = MOD;
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
                                                      val = new_number(37);
                                                      args = cons(val, args);
                                                      val = args;
                                                      args = NIL;
                                                      pop_args();
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      val = BAND;
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
                                                        val = new_number(38);
                                                        args = cons(val, args);
                                                        val = args;
                                                        args = NIL;
                                                        pop_args();
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        val = BOR;
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
                                                          val = new_number(124);
                                                          args = cons(val, args);
                                                          val = args;
                                                          args = NIL;
                                                          pop_args();
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          val = BXOR;
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
                                                            val = new_number(94);
                                                            args = cons(val, args);
                                                            val = args;
                                                            args = NIL;
                                                            pop_args();
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            val = BNEG;
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
                                                              val = new_number(126);
                                                              args = cons(val, args);
                                                              val = args;
                                                              args = NIL;
                                                              pop_args();
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              val = DEFINE;
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
                                                                pop_function();
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
void function_210() {
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
void function_211() {
  apply((&function_210));
}
void function_212() {
  top_level_apply();
}
void function_213() {
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
    val = global_20;
    increment_count(val);
    apply((&function_211));
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
      val = NIL;
      push_args();
      args = val;
      val = new_number(48);
      args = cons(val, args);
      val = args;
      args = NIL;
      pop_args();
      pop_function();
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
      val = global_20;
      increment_count(val);
      apply((&function_212));
    }
  }
}
void function_214() {
  top_level_apply();
}
void function_215() {
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
void function_216() {
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
void function_217() {
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
void function_218() {
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
void function_219() {
  increment_count(env);
  val = new_function((&function_218), env);
  pop_function();
}
void function_220() {
  val = global_82;
  increment_count(val);
  pop_function();
}
void function_221() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_220), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_219), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_217), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_216), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_215), env);
  args = cons(val, args);
  val = global_78;
  increment_count(val);
  apply((&function_214));
}
void function_222() {
  args = cons(val, args);
  val = global_64;
  increment_count(val);
  top_level_apply();
}
void function_223() {
  args = cons(val, args);
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
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_222));
}
void function_224() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  val = global_19;
  increment_count(val);
  apply((&function_223));
}
void function_225() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_224), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_22;
  increment_count(val);
  top_level_apply();
}
void function_226() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_227() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_226));
}
void function_228() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_227));
}
void function_229() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  val = global_36;
  increment_count(val);
  apply((&function_228));
}
void function_230() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_229));
}
void function_231() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
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
  val = global_29;
  increment_count(val);
  args = cons(val, args);
  val = global_28;
  increment_count(val);
  apply((&function_231));
}
void function_233() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_232));
}
void function_234() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_233));
}
void function_235() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_28;
  increment_count(val);
  apply((&function_234));
}
void function_236() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_235));
}
void function_237() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
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
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_27;
  increment_count(val);
  apply((&function_237));
}
void function_239() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_238));
}
void function_240() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
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
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_26;
  increment_count(val);
  apply((&function_240));
}
void function_242() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_241));
}
void function_243() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_23;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_242));
}
void function_244() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_243));
}
void function_245() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_49;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_244));
}
void function_246() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_245));
}
void function_247() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_49;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_246));
}
void function_248() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_247));
}
void function_249() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
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
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_25;
  increment_count(val);
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_250));
}
void function_252() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_251));
}
void function_253() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_32;
  increment_count(val);
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
  val = global_36;
  increment_count(val);
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
  val = global_30;
  increment_count(val);
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_256() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_256));
}
void function_258() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_23;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  val = global_36;
  increment_count(val);
  apply((&function_257));
}
void function_259() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_258));
}
void function_260() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
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
  val = global_23;
  increment_count(val);
  args = cons(val, args);
  val = global_25;
  increment_count(val);
  apply((&function_260));
}
void function_262() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_261));
}
void function_263() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_262));
}
void function_264() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_263));
}
void function_265() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_264));
}
void function_266() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_24;
  increment_count(val);
  args = cons(val, args);
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_34;
  increment_count(val);
  apply((&function_265));
}
void function_267() {
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_266));
}
void function_268() {
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
  val = global_23;
  increment_count(val);
  args = cons(val, args);
  val = global_22;
  increment_count(val);
  args = cons(val, args);
  val = global_40;
  increment_count(val);
  apply((&function_267));
}
void function_269() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_270() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_269));
}
void function_271() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_270));
}
void function_272() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_24;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  val = global_36;
  increment_count(val);
  apply((&function_271));
}
void function_273() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_272));
}
void function_274() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_273));
}
void function_275() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_24;
  increment_count(val);
  args = cons(val, args);
  val = global_25;
  increment_count(val);
  apply((&function_274));
}
void function_276() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_275));
}
void function_277() {
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
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_276));
}
void function_278() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_279() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_278));
}
void function_280() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_279));
}
void function_281() {
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
  val = global_45;
  increment_count(val);
  apply((&function_280));
}
void function_282() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_281));
}
void function_283() {
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
  val = global_45;
  increment_count(val);
  apply((&function_282));
}
void function_284() {
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_283));
}
void function_285() {
  args = cons(val, args);
  val = global_35;
  increment_count(val);
  apply((&function_284));
}
void function_286() {
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
  val = global_25;
  increment_count(val);
  apply((&function_285));
}
void function_287() {
  increment_count(env);
  val = new_function((&function_286), env);
  pop_function();
}
void function_288() {
  push_args();
  val = NIL;
  args = val;
  val = global_51;
  increment_count(val);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  top_level_apply();
}
void function_289() {
  push_args();
  val = NIL;
  args = val;
  val = global_52;
  increment_count(val);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  top_level_apply();
}
void function_290() {
  push_args();
  val = NIL;
  args = val;
  val = global_53;
  increment_count(val);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  top_level_apply();
}
void function_291() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_292() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_291));
}
void function_293() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_292));
}
void function_294() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_293));
}
void function_295() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_294));
}
void function_296() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_295));
}
void function_297() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_29;
  increment_count(val);
  args = cons(val, args);
  val = global_39;
  increment_count(val);
  apply((&function_296));
}
void function_298() {
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_297));
}
void function_299() {
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
  val = global_29;
  increment_count(val);
  args = cons(val, args);
  val = global_38;
  increment_count(val);
  apply((&function_298));
}
void function_300() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_301() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_50;
  increment_count(val);
  args = cons(val, args);
  val = global_31;
  increment_count(val);
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  apply((&function_300));
}
void function_302() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_303() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_302));
}
void function_304() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_303));
}
void function_305() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_304));
}
void function_306() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  val = global_36;
  increment_count(val);
  apply((&function_305));
}
void function_307() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_306));
}
void function_308() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_307));
}
void function_309() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
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
  val = global_36;
  increment_count(val);
  apply((&function_308));
}
void function_310() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_309));
}
void function_311() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_310));
}
void function_312() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_311));
}
void function_313() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_312));
}
void function_314() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_313));
}
void function_315() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  val = global_45;
  increment_count(val);
  apply((&function_314));
}
void function_316() {
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_315));
}
void function_317() {
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
  val = global_31;
  increment_count(val);
  args = cons(val, args);
  val = global_38;
  increment_count(val);
  apply((&function_316));
}
void function_318() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_319() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_56;
  increment_count(val);
  args = cons(val, args);
  val = global_33;
  increment_count(val);
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  apply((&function_318));
}
void function_320() {
  args = cons(val, args);
  val = global_80;
  increment_count(val);
  top_level_apply();
}
void function_321() {
  args = cons(val, args);
  val = global_42;
  increment_count(val);
  apply((&function_320));
}
void function_322() {
  args = cons(val, args);
  val = global_43;
  increment_count(val);
  apply((&function_321));
}
void function_323() {
  args = cons(val, args);
  val = global_37;
  increment_count(val);
  apply((&function_322));
}
void function_324() {
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
  val = global_36;
  increment_count(val);
  apply((&function_323));
}
void function_325() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = global_33;
  increment_count(val);
  args = cons(val, args);
  val = global_38;
  increment_count(val);
  apply((&function_324));
}
void function_326() {
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
  val = global_48;
  increment_count(val);
  args = cons(val, args);
  val = global_44;
  increment_count(val);
  apply((&function_325));
}
void function_327() {
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  top_level_apply();
}
void function_328() {
  push_args();
  val = NIL;
  args = val;
  val = global_54;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_40;
  increment_count(val);
  apply((&function_327));
}
void function_329() {
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  top_level_apply();
}
void function_330() {
  push_args();
  val = NIL;
  args = val;
  val = global_55;
  increment_count(val);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_38;
  increment_count(val);
  apply((&function_329));
}
void function_331() {
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
  val = global_69;
  increment_count(val);
  top_level_apply();
}
void function_332() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_331), env);
  args = cons(val, args);
  val = global_46;
  increment_count(val);
  top_level_apply();
}
void function_333() {
  top_level_apply();
}
void function_334() {
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
  apply((&function_333));
}
void function_335() {
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
  val = new_function((&function_334), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_336() {
  increment_count(env);
  val = new_function((&function_335), env);
  pop_function();
}
void function_337() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_47;
  increment_count(val);
  args = cons(val, args);
  val = global_40;
  increment_count(val);
  top_level_apply();
}
void function_338() {
  args = cons(val, args);
  val = global_40;
  increment_count(val);
  top_level_apply();
}
void function_339() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_57;
  increment_count(val);
  args = cons(val, args);
  val = global_47;
  increment_count(val);
  args = cons(val, args);
  val = global_41;
  increment_count(val);
  apply((&function_338));
}
void function_340() {
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
void function_341() {
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
  val = new_function((&function_340), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_342() {
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
  val = new_function((&function_341), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_343() {
  increment_count(env);
  val = new_function((&function_342), env);
  pop_function();
}
void function_344() {
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
void function_345() {
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
  val = new_function((&function_344), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_346() {
  increment_count(env);
  val = new_function((&function_345), env);
  pop_function();
}
void function_347() {
  top_level_apply();
}
void function_348() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_349() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = global_49;
  increment_count(val);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_348), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_347));
}
void function_350() {
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
void function_351() {
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
void function_352() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_351), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_350), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_353() {
  increment_count(env);
  val = new_function((&function_352), env);
  pop_function();
}
void function_354() {
  increment_count(env);
  val = new_function((&function_353), env);
  pop_function();
}
void function_355() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_356() {
  increment_count(env);
  val = new_function((&function_355), env);
  pop_function();
}
void function_357() {
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
void function_358() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_357), env);
  args = cons(val, args);
  val = global_46;
  increment_count(val);
  top_level_apply();
}
void function_359() {
  top_level_apply();
}
void function_360() {
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
    apply((&function_359));
  }
}
void function_361() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_360));
}
void function_362() {
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
  val = new_function((&function_361), env);
  args = cons(val, args);
  val = global_47;
  increment_count(val);
  top_level_apply();
}
void function_363() {
  increment_count(env);
  val = new_function((&function_362), env);
  pop_function();
}
void function_364() {
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
void function_365() {
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
    val = global_47;
    increment_count(val);
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
    val = global_68;
    increment_count(val);
    apply((&function_364));
  }
}
void function_366() {
  increment_count(env);
  val = new_function((&function_365), env);
  pop_function();
}
void function_367() {
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
void function_368() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_369() {
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
void function_370() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = DEFINE;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_369), env);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_58;
    increment_count(val);
    top_level_apply();
  }
}
void function_371() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = LSHIFT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = global_72;
    increment_count(val);
    apply((&function_370));
  }
}
void function_372() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = URSHIFT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_371));
  }
}
void function_373() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = SRSHIFT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_372));
  }
}
void function_374() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = BXOR;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_373));
  }
}
void function_375() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = BOR;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(94);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_374));
  }
}
void function_376() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = BAND;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(124);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_375));
  }
}
void function_377() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = BNEG;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(38);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_376));
  }
}
void function_378() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = MOD;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(126);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_377));
  }
}
void function_379() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = DIV;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(37);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_378));
  }
}
void function_380() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = MULT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(47);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_379));
  }
}
void function_381() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = MINUS;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(42);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_380));
  }
}
void function_382() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = PLUS;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(45);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_381));
  }
}
void function_383() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = GT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(43);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_382));
  }
}
void function_384() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = LT;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(62);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_383));
  }
}
void function_385() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = EQ;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(60);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_384));
  }
}
void function_386() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = FUNCTION;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = global_72;
    increment_count(val);
    apply((&function_385));
  }
}
void function_387() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = NUMBER;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_386));
  }
}
void function_388() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = ATOM;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_387));
  }
}
void function_389() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = CDR;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_388));
  }
}
void function_390() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = CAR;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_389));
  }
}
void function_391() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = CONS;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_390));
  }
}
void function_392() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = -117;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
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
    val = new_number(99);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_391));
  }
}
void function_393() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = -115;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = global_72;
    increment_count(val);
    apply((&function_392));
  }
}
void function_394() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = QUOTE;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = global_72;
    increment_count(val);
    apply((&function_393));
  }
}
void function_395() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = FN;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
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
    val = global_72;
    increment_count(val);
    apply((&function_394));
  }
}
void function_396() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = LET;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_395));
  }
}
void function_397() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = -119;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_396));
  }
}
void function_398() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    val = COND;
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
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
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_72;
    increment_count(val);
    apply((&function_397));
  }
}
void function_399() {
  push_args();
  val = NIL;
  args = val;
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
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_72;
  increment_count(val);
  apply((&function_398));
}
void function_400() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_401() {
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
  val = -117;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_400));
}
void function_402() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_403() {
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
  val = -115;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_402));
}
void function_404() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_405() {
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
  val = QUOTE;
  args = cons(val, args);
  val = global_81;
  increment_count(val);
  apply((&function_404));
}
void function_406() {
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
void function_407() {
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
void function_408() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_409() {
  apply((&function_408));
}
void function_410() {
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
void function_411() {
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
  val = new_function((&function_410), env);
  args = cons(val, args);
  val = global_75;
  increment_count(val);
  apply((&function_409));
}
void function_412() {
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
void function_413() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_414() {
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
  val = global_63;
  increment_count(val);
  apply((&function_413));
}
void function_415() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_414), env);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_59;
  increment_count(val);
  top_level_apply();
}
void function_416() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_417() {
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
    val = global_89;
    increment_count(val);
    apply((&function_416));
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
    val = global_59;
    increment_count(val);
    top_level_apply();
  }
}
void function_418() {
  args = cons(val, args);
  val = global_72;
  increment_count(val);
  apply((&function_417));
}
void function_419() {
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
    val = global_90;
    increment_count(val);
    apply((&function_418));
  }
}
void function_420() {
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
void function_421() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_62;
  increment_count(val);
  apply((&function_420));
}
void function_422() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  val = global_62;
  increment_count(val);
  apply((&function_421));
}
void function_423() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_424() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_423), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_425() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_426() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_425), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_427() {
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
void function_428() {
  increment_count(env);
  val = new_function((&function_427), env);
  pop_function();
}
void function_429() {
  args = cons(val, args);
  val = global_66;
  increment_count(val);
  top_level_apply();
}
void function_430() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
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
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_429));
}
void function_431() {
  args = cons(val, args);
  val = global_66;
  increment_count(val);
  top_level_apply();
}
void function_432() {
  args = cons(val, args);
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
  args = cons(val, args);
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
  args = cons(val, args);
  val = global_73;
  increment_count(val);
  apply((&function_431));
}
void function_433() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    val = NIL;
    push_args();
    args = val;
    val = new_number(10);
    args = cons(val, args);
    val = args;
    args = NIL;
    pop_args();
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
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
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    val = global_15;
    increment_count(val);
    apply((&function_432));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_434() {
  global_66 = val;
  increment_count(env);
  val = new_function((&function_433), env);
  global_65 = val;
  increment_count(env);
  val = new_function((&function_430), env);
  global_64 = val;
  increment_count(env);
  val = new_function((&function_428), env);
  global_63 = val;
  increment_count(env);
  val = new_function((&function_426), env);
  global_62 = val;
  increment_count(env);
  val = new_function((&function_424), env);
  global_61 = val;
  increment_count(env);
  val = new_function((&function_422), env);
  global_60 = val;
  increment_count(env);
  val = new_function((&function_419), env);
  global_59 = val;
  increment_count(env);
  val = new_function((&function_415), env);
  global_58 = val;
  increment_count(env);
  val = new_function((&function_412), env);
  global_57 = val;
  increment_count(env);
  val = new_function((&function_411), env);
  global_56 = val;
  increment_count(env);
  val = new_function((&function_407), env);
  global_55 = val;
  increment_count(env);
  val = new_function((&function_406), env);
  global_54 = val;
  increment_count(env);
  val = new_function((&function_405), env);
  global_53 = val;
  increment_count(env);
  val = new_function((&function_403), env);
  global_52 = val;
  increment_count(env);
  val = new_function((&function_401), env);
  global_51 = val;
  increment_count(env);
  val = new_function((&function_399), env);
  global_50 = val;
  increment_count(env);
  val = new_function((&function_368), env);
  global_49 = val;
  increment_count(env);
  val = new_function((&function_367), env);
  global_48 = val;
  increment_count(env);
  val = new_function((&function_366), env);
  global_47 = val;
  increment_count(env);
  val = new_function((&function_363), env);
  global_46 = val;
  increment_count(env);
  val = new_function((&function_358), env);
  global_45 = val;
  increment_count(env);
  val = new_function((&function_356), env);
  global_44 = val;
  increment_count(env);
  val = new_function((&function_354), env);
  global_43 = val;
  increment_count(env);
  val = new_function((&function_349), env);
  global_42 = val;
  increment_count(env);
  val = new_function((&function_346), env);
  global_41 = val;
  increment_count(env);
  val = new_function((&function_343), env);
  global_40 = val;
  increment_count(env);
  val = new_function((&function_339), env);
  global_39 = val;
  increment_count(env);
  val = new_function((&function_337), env);
  global_38 = val;
  increment_count(env);
  val = new_function((&function_336), env);
  global_37 = val;
  increment_count(env);
  val = new_function((&function_332), env);
  global_36 = val;
  increment_count(env);
  val = new_function((&function_330), env);
  global_35 = val;
  increment_count(env);
  val = new_function((&function_328), env);
  global_34 = val;
  increment_count(env);
  val = new_function((&function_326), env);
  global_33 = val;
  increment_count(env);
  val = new_function((&function_319), env);
  global_32 = val;
  increment_count(env);
  val = new_function((&function_317), env);
  global_31 = val;
  increment_count(env);
  val = new_function((&function_301), env);
  global_30 = val;
  increment_count(env);
  val = new_function((&function_299), env);
  global_29 = val;
  increment_count(env);
  val = new_function((&function_290), env);
  global_28 = val;
  increment_count(env);
  val = new_function((&function_289), env);
  global_27 = val;
  increment_count(env);
  val = new_function((&function_288), env);
  global_26 = val;
  increment_count(env);
  val = new_function((&function_287), env);
  global_25 = val;
  increment_count(env);
  val = new_function((&function_277), env);
  global_24 = val;
  increment_count(env);
  val = new_function((&function_268), env);
  global_23 = val;
  increment_count(env);
  val = new_function((&function_254), env);
  global_22 = val;
  increment_count(env);
  val = new_function((&function_225), env);
  global_21 = val;
  increment_count(env);
  val = new_function((&function_221), env);
  global_20 = val;
  increment_count(env);
  val = new_function((&function_213), env);
  global_19 = val;
  increment_count(env);
  val = new_function((&function_209), env);
  global_18 = val;
  increment_count(env);
  val = new_function((&function_208), env);
  global_17 = val;
  increment_count(env);
  val = new_function((&function_204), env);
  global_16 = val;
  increment_count(env);
  val = new_function((&function_200), env);
  global_15 = val;
  increment_count(env);
  val = new_function((&function_199), env);
  global_14 = val;
  increment_count(env);
  val = new_function((&function_197), env);
  global_13 = val;
  increment_count(env);
  val = new_function((&function_191), env);
  global_12 = val;
  increment_count(env);
  val = new_function((&function_188), env);
  global_11 = val;
  increment_count(env);
  val = new_function((&function_173), env);
  global_10 = val;
  increment_count(env);
  val = new_function((&function_171), env);
  global_9 = val;
  increment_count(env);
  val = new_function((&function_157), env);
  global_8 = val;
  increment_count(env);
  val = new_function((&function_151), env);
  global_7 = val;
  increment_count(env);
  val = new_function((&function_147), env);
  global_6 = val;
  increment_count(env);
  val = new_function((&function_132), env);
  global_5 = val;
  increment_count(env);
  val = new_function((&function_130), env);
  global_4 = val;
  increment_count(env);
  val = new_function((&function_126), env);
  global_3 = val;
  increment_count(env);
  val = new_function((&function_115), env);
  global_2 = val;
  increment_count(env);
  val = new_function((&function_102), env);
  global_1 = val;
  increment_count(env);
  val = new_function((&function_92), env);
  pop_function();
}
void function_435() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_436() {
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
  val = global_81;
  increment_count(val);
  apply((&function_435));
}
void function_437() {
  if (val != NIL) {
    decrement_count(val);
    val = -57;
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_438() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_437));
}
void function_439() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_438), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  top_level_apply();
}
void function_440() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    val = NIL;
    pop_function();
  } else {
    val = -57;
    pop_function();
  }
}
void function_441() {
  top_level_apply();
}
void function_442() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_443() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = -57;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_442), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_441));
}
void function_444() {
  top_level_apply();
}
void function_445() {
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
void function_446() {
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
  val = new_function((&function_445), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_444));
}
void function_447() {
  top_level_apply();
}
void function_448() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_449() {
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
  apply((&function_448));
}
void function_450() {
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
  increment_count(env);
  val = new_function((&function_449), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_447));
}
void function_451() {
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
    val = global_72;
    increment_count(val);
    top_level_apply();
  } else {
    val = NIL;
    pop_function();
  }
}
void function_452() {
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
      val = NIL;
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
      val = global_72;
      increment_count(val);
      apply((&function_451));
    }
  }
}
void function_453() {
  top_level_apply();
}
void function_454() {
  top_level_apply();
}
void function_455() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
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
    val = global_74;
    increment_count(val);
    apply((&function_454));
  }
}
void function_456() {
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
  val = new_function((&function_455), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_453));
}
void function_457() {
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_77;
  increment_count(val);
  top_level_apply();
}
void function_458() {
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
  val = global_75;
  increment_count(val);
  apply((&function_457));
}
void function_459() {
  increment_count(env);
  val = new_function((&function_458), env);
  pop_function();
}
void function_460() {
  top_level_apply();
}
void function_461() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  val = global_75;
  increment_count(val);
  apply((&function_460));
}
void function_462() {
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
    apply((&function_461));
  }
}
void function_463() {
  increment_count(env);
  val = new_function((&function_462), env);
  pop_function();
}
void function_464() {
  push_args();
  val = NIL;
  args = val;
  val = global_82;
  increment_count(val);
  args = cons(val, args);
  val = NIL;
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  val = global_77;
  increment_count(val);
  top_level_apply();
}
void function_465() {
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
    val = global_77;
    increment_count(val);
    top_level_apply();
  }
}
void function_466() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_467() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_466));
}
void function_468() {
  apply((&function_467));
}
void function_469() {
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
  val = global_78;
  increment_count(val);
  apply((&function_468));
}
void function_470() {
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
    apply((&function_469));
  }
}
void function_471() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_470));
}
void function_472() {
  increment_count(env);
  val = new_function((&function_471), env);
  pop_function();
}
void function_473() {
  top_level_apply();
}
void function_474() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_473));
}
void function_475() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_474), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_476() {
  top_level_apply();
}
void function_477() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_476));
}
void function_478() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_477), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_479() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_478), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_475), env);
  top_level_apply();
}
void function_480() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_481() {
  increment_count(val = car(env));
  pop_function();
}
void function_482() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_483() {
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
void function_484() {
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
void function_485() {
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
void function_486() {
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
void function_487() {
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
void function_488() {
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
void function_489() {
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
void function_490() {
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
void function_491() {
  increment_count(env);
  val = new_function((&function_490), env);
  global_90 = val;
  increment_count(env);
  val = new_function((&function_489), env);
  global_89 = val;
  increment_count(env);
  val = new_function((&function_488), env);
  global_88 = val;
  increment_count(env);
  val = new_function((&function_487), env);
  global_87 = val;
  increment_count(env);
  val = new_function((&function_486), env);
  global_86 = val;
  increment_count(env);
  val = new_function((&function_485), env);
  global_85 = val;
  increment_count(env);
  val = new_function((&function_484), env);
  global_84 = val;
  increment_count(env);
  val = new_function((&function_483), env);
  global_83 = val;
  increment_count(env);
  val = new_function((&function_482), env);
  global_82 = val;
  increment_count(env);
  val = new_function((&function_481), env);
  global_81 = val;
  increment_count(env);
  val = new_function((&function_480), env);
  global_80 = val;
  increment_count(env);
  val = new_function((&function_479), env);
  global_79 = val;
  increment_count(env);
  val = new_function((&function_472), env);
  global_78 = val;
  increment_count(env);
  val = new_function((&function_465), env);
  global_77 = val;
  increment_count(env);
  val = new_function((&function_464), env);
  global_76 = val;
  increment_count(env);
  val = new_function((&function_463), env);
  global_75 = val;
  increment_count(env);
  val = new_function((&function_459), env);
  global_74 = val;
  increment_count(env);
  val = new_function((&function_456), env);
  global_73 = val;
  increment_count(env);
  val = new_function((&function_452), env);
  global_72 = val;
  increment_count(env);
  val = new_function((&function_450), env);
  global_71 = val;
  increment_count(env);
  val = new_function((&function_446), env);
  global_70 = val;
  increment_count(env);
  val = new_function((&function_443), env);
  global_69 = val;
  increment_count(env);
  val = new_function((&function_440), env);
  global_68 = val;
  increment_count(env);
  val = new_function((&function_439), env);
  global_67 = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_436), env);
  args = cons(val, args);
  val = global_74;
  increment_count(val);
  apply((&function_434));
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
    call_stack = cons(new_function((&function_0), NIL), call_stack);
    return_location = (&function_491);
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
  call_stack = cons(new_function((&top_level), NIL), call_stack);
  call_stack = cons(new_function((&function_0), NIL), call_stack);
  return_location = (&function_491);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
