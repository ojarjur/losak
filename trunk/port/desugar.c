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
pointer global_404 = NIL;
pointer global_403 = NIL;
pointer global_399 = NIL;
pointer global_398 = NIL;
pointer global_397 = NIL;
pointer global_396 = NIL;
pointer global_393 = NIL;
pointer global_392 = NIL;
pointer global_391 = NIL;
pointer global_388 = NIL;
pointer global_387 = NIL;
pointer global_386 = NIL;
pointer global_385 = NIL;
pointer global_383 = NIL;
pointer global_332 = NIL;
pointer global_382 = NIL;
pointer global_381 = NIL;
pointer global_380 = NIL;
pointer global_379 = NIL;
pointer global_378 = NIL;
pointer global_377 = NIL;
pointer global_376 = NIL;
pointer global_375 = NIL;
pointer global_374 = NIL;
pointer global_373 = NIL;
pointer global_366 = NIL;
pointer global_364 = NIL;
pointer global_363 = NIL;
pointer global_352 = NIL;
pointer global_351 = NIL;
pointer global_350 = NIL;
pointer global_349 = NIL;
pointer global_348 = NIL;
pointer global_347 = NIL;
pointer global_346 = NIL;
pointer global_345 = NIL;
pointer global_344 = NIL;
pointer global_343 = NIL;
pointer global_342 = NIL;
pointer global_341 = NIL;
pointer global_330 = NIL;
pointer global_329 = NIL;
pointer global_328 = NIL;
pointer global_327 = NIL;
pointer global_326 = NIL;
pointer global_325 = NIL;
pointer global_324 = NIL;
pointer global_323 = NIL;
pointer global_322 = NIL;
pointer global_321 = NIL;
pointer global_320 = NIL;
pointer global_318 = NIL;
pointer global_317 = NIL;
pointer global_316 = NIL;
pointer global_314 = NIL;
pointer global_313 = NIL;
pointer global_312 = NIL;
pointer global_311 = NIL;
pointer global_306 = NIL;
pointer global_305 = NIL;
pointer global_304 = NIL;
pointer global_303 = NIL;
pointer global_302 = NIL;
pointer global_301 = NIL;
pointer global_300 = NIL;
pointer global_299 = NIL;
pointer global_298 = NIL;
pointer global_295 = NIL;
pointer global_294 = NIL;
pointer global_72 = NIL;
pointer global_293 = NIL;
pointer global_292 = NIL;
pointer global_291 = NIL;
pointer global_287 = NIL;
pointer global_290 = NIL;
pointer global_289 = NIL;
pointer global_288 = NIL;
pointer global_285 = NIL;
pointer global_284 = NIL;
pointer global_283 = NIL;
pointer global_282 = NIL;
pointer global_281 = NIL;
pointer global_280 = NIL;
pointer global_279 = NIL;
pointer global_278 = NIL;
pointer global_277 = NIL;
pointer global_276 = NIL;
pointer global_275 = NIL;
pointer global_274 = NIL;
pointer global_273 = NIL;
pointer global_272 = NIL;
pointer global_271 = NIL;
pointer global_270 = NIL;
pointer global_269 = NIL;
pointer global_268 = NIL;
pointer global_267 = NIL;
pointer global_266 = NIL;
pointer global_265 = NIL;
pointer global_264 = NIL;
pointer global_263 = NIL;
pointer global_262 = NIL;
pointer global_261 = NIL;
pointer global_260 = NIL;
pointer global_259 = NIL;
pointer global_258 = NIL;
pointer global_257 = NIL;
pointer global_256 = NIL;
pointer global_255 = NIL;
pointer global_254 = NIL;
pointer global_253 = NIL;
pointer global_252 = NIL;
pointer global_251 = NIL;
pointer global_250 = NIL;
pointer global_249 = NIL;
pointer global_248 = NIL;
pointer global_247 = NIL;
pointer global_246 = NIL;
pointer global_245 = NIL;
pointer global_244 = NIL;
pointer global_243 = NIL;
pointer global_242 = NIL;
pointer global_241 = NIL;
pointer global_240 = NIL;
pointer global_239 = NIL;
pointer global_238 = NIL;
pointer global_237 = NIL;
pointer global_236 = NIL;
pointer global_235 = NIL;
pointer global_234 = NIL;
pointer global_233 = NIL;
pointer global_232 = NIL;
pointer global_231 = NIL;
pointer global_230 = NIL;
pointer global_229 = NIL;
pointer global_228 = NIL;
pointer global_227 = NIL;
pointer global_226 = NIL;
pointer global_225 = NIL;
pointer global_224 = NIL;
pointer global_223 = NIL;
pointer global_222 = NIL;
pointer global_221 = NIL;
pointer global_220 = NIL;
pointer global_213 = NIL;
pointer global_219 = NIL;
pointer global_218 = NIL;
pointer global_217 = NIL;
pointer global_214 = NIL;
pointer global_210 = NIL;
pointer global_209 = NIL;
pointer global_208 = NIL;
pointer global_207 = NIL;
pointer global_206 = NIL;
pointer global_205 = NIL;
pointer global_204 = NIL;
pointer global_203 = NIL;
pointer global_202 = NIL;
pointer global_201 = NIL;
pointer global_200 = NIL;
pointer global_199 = NIL;
pointer global_198 = NIL;
pointer global_197 = NIL;
pointer global_196 = NIL;
pointer global_195 = NIL;
pointer global_194 = NIL;
pointer global_192 = NIL;
pointer global_190 = NIL;
pointer global_189 = NIL;
pointer global_188 = NIL;
pointer global_185 = NIL;
pointer global_184 = NIL;
pointer global_182 = NIL;
pointer global_180 = NIL;
pointer global_177 = NIL;
pointer global_176 = NIL;
pointer global_174 = NIL;
pointer global_173 = NIL;
pointer global_172 = NIL;
pointer global_171 = NIL;
pointer global_169 = NIL;
pointer global_167 = NIL;
pointer global_166 = NIL;
pointer global_165 = NIL;
pointer global_164 = NIL;
pointer global_163 = NIL;
pointer global_162 = NIL;
pointer global_161 = NIL;
pointer global_160 = NIL;
pointer global_159 = NIL;
pointer global_158 = NIL;
pointer global_157 = NIL;
pointer global_156 = NIL;
pointer global_155 = NIL;
pointer global_154 = NIL;
pointer global_153 = NIL;
pointer global_152 = NIL;
pointer global_151 = NIL;
pointer global_150 = NIL;
pointer global_149 = NIL;
pointer global_148 = NIL;
pointer global_147 = NIL;
pointer global_146 = NIL;
pointer global_145 = NIL;
pointer global_144 = NIL;
pointer global_143 = NIL;
pointer global_142 = NIL;
pointer global_141 = NIL;
pointer global_140 = NIL;
pointer global_139 = NIL;
pointer global_138 = NIL;
pointer global_137 = NIL;
pointer global_136 = NIL;
pointer global_135 = NIL;
pointer global_134 = NIL;
pointer global_133 = NIL;
pointer global_132 = NIL;
pointer global_131 = NIL;
pointer global_130 = NIL;
pointer global_129 = NIL;
pointer global_128 = NIL;
pointer global_127 = NIL;
pointer global_126 = NIL;
pointer global_125 = NIL;
pointer global_124 = NIL;
pointer global_123 = NIL;
pointer global_122 = NIL;
pointer global_121 = NIL;
pointer global_120 = NIL;
pointer global_119 = NIL;
pointer global_118 = NIL;
pointer global_117 = NIL;
pointer global_116 = NIL;
pointer global_115 = NIL;
pointer global_114 = NIL;
pointer global_113 = NIL;
pointer global_112 = NIL;
pointer global_111 = NIL;
pointer global_110 = NIL;
pointer global_109 = NIL;
pointer global_108 = NIL;
pointer global_107 = NIL;
pointer global_106 = NIL;
pointer global_105 = NIL;
pointer global_103 = NIL;
pointer global_102 = NIL;
pointer global_101 = NIL;
pointer global_99 = NIL;
pointer global_95 = NIL;
pointer global_92 = NIL;
pointer global_90 = NIL;
pointer global_85 = NIL;
pointer global_82 = NIL;
pointer global_81 = NIL;
pointer global_79 = NIL;
pointer global_77 = NIL;
pointer global_75 = NIL;
pointer global_74 = NIL;
pointer global_73 = NIL;
pointer global_69 = NIL;
pointer global_68 = NIL;
pointer global_67 = NIL;
pointer global_66 = NIL;
pointer global_65 = NIL;
pointer global_62 = NIL;
pointer global_58 = NIL;
pointer global_57 = NIL;
pointer global_56 = NIL;
pointer global_55 = NIL;
pointer global_54 = NIL;
pointer global_53 = NIL;
pointer global_51 = NIL;
pointer global_50 = NIL;
pointer global_47 = NIL;
pointer global_46 = NIL;
pointer global_45 = NIL;
pointer global_44 = NIL;
pointer global_42 = NIL;
pointer global_41 = NIL;
pointer global_40 = NIL;
pointer global_38 = NIL;
pointer global_37 = NIL;
pointer global_36 = NIL;
pointer global_35 = NIL;
pointer global_34 = NIL;
pointer global_32 = NIL;
pointer global_31 = NIL;
pointer global_30 = NIL;
pointer global_27 = NIL;
pointer global_20 = NIL;
pointer global_18 = NIL;
pointer global_16 = NIL;
pointer global_14 = NIL;
pointer global_13 = NIL;
pointer global_12 = NIL;
pointer global_11 = NIL;
pointer global_10 = NIL;
pointer global_9 = NIL;
pointer global_8 = NIL;
pointer global_7 = NIL;
pointer global_6 = NIL;
pointer global_4 = NIL;

void function_1() {
  args = cons(val, args);
  increment_count(val = global_210);
  top_level_apply();
}
void function_2() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_404);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_403);
  args = cons(val, args);
  increment_count(val = global_399);
  apply((&function_1));
}
void function_3() {
  args = cons(val, args);
  increment_count(val = global_393);
  top_level_apply();
}
void function_4() {
  args = cons(val, args);
  increment_count(val = global_210);
  top_level_apply();
}
void function_5() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_398);
    args = cons(val, args);
    increment_count(val = global_75);
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
    increment_count(val = global_399);
    apply((&function_4));
  }
}
void function_6() {
  args = cons(val, args);
  increment_count(val = global_56);
  apply((&function_5));
}
void function_7() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (is_atom(car(args))) {
      increment_count(val = true); 
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_47);
  apply((&function_6));
}
void function_8() {
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
  increment_count(val = global_7);
  apply((&function_7));
}
void function_9() {
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
    increment_count(val = global_31);
    apply((&function_3));
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
    increment_count(val = global_10);
    apply((&function_8));
  }
}
void function_10() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_396);
    args = cons(val, args);
    increment_count(val = global_75);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_397);
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
    increment_count(val = global_56);
    apply((&function_9));
  }
}
void function_11() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_56);
  apply((&function_10));
}
void function_12() {
  increment_count(env);
  val = new_function((&function_11), env);
  pop_function();
}
void function_13() {
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_14() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(car(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = global_69);
  apply((&function_13));
}
void function_15() {
  args = cons(val, args);
  increment_count(val = global_38);
  args = cons(val, args);
  increment_count(val = global_16);
  apply((&function_14));
}
void function_16() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_292);
  args = cons(val, args);
  increment_count(val = global_45);
  apply((&function_15));
}
void function_17() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_292);
  apply((&function_16));
}
void function_18() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_17), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(car(env)))))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_391);
  top_level_apply();
}
void function_19() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_18), env);
  top_level_apply();
}
void function_20() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_392);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_332);
  apply((&function_19));
}
void function_21() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_20), env);
  top_level_apply();
}
void function_22() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_383);
  args = cons(val, args);
  increment_count(val = global_45);
  apply((&function_21));
}
void function_23() {
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
  increment_count(val = global_391);
  top_level_apply();
}
void function_24() {
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
    val = new_function((&function_23), env);
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
    increment_count(val = global_388);
    top_level_apply();
  }
}
void function_25() {
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_26() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_69);
  apply((&function_25));
}
void function_27() {
  args = cons(val, args);
  increment_count(val = global_38);
  args = cons(val, args);
  increment_count(val = global_16);
  apply((&function_26));
}
void function_28() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_292);
  args = cons(val, args);
  increment_count(val = global_45);
  apply((&function_27));
}
void function_29() {
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
  increment_count(val = global_292);
  apply((&function_28));
}
void function_30() {
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
  increment_count(val = global_299);
  apply((&function_29));
}
void function_31() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(cdr(cdr(cdr(env))))))))));
  apply((&function_30));
}
void function_32() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_31), env);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(cdr(cdr(env))))))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(cdr(env)))))));
  args = cons(val, args);
  increment_count(val = global_387);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_33() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_32), env);
  top_level_apply();
}
void function_34() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_386);
  apply((&function_33));
}
void function_35() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_34), env);
  top_level_apply();
}
void function_36() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_383);
  apply((&function_35));
}
void function_37() {
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
  val = new_function((&function_36), env);
  top_level_apply();
}
void function_38() {
  args = cons(val, args);
  if (length(args) == 1) {
    if (! is_atom(car(args))) {
    increment_count(val = cdr(car(args)));
    } else { val = NIL; }
  } else { val = NIL; }
  pop_args();
  args = cons(val, args);
  increment_count(val = global_385);
  args = cons(val, args);
  increment_count(val = global_14);
  top_level_apply();
}
void function_39() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7);
  apply((&function_38));
}
void function_40() {
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
    increment_count(val = global_12);
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
    increment_count(val = global_12);
    apply((&function_39));
  }
}
void function_41() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7);
  apply((&function_40));
}
void function_42() {
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
    increment_count(val = global_7);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = cdr(car(car(env))));
    args = cons(val, args);
    increment_count(val = global_10);
    top_level_apply();
  }
}
void function_43() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = cdr(car(car(env))));
  args = cons(val, args);
  increment_count(val = global_7);
  apply((&function_42));
}
void function_44() {
  args = cons(val, args);
  increment_count(val = global_330);
  top_level_apply();
}
void function_45() {
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_46() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_47() {
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
  increment_count(val = global_378);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_46));
}
void function_48() {
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_49() {
  args = cons(val, args);
  increment_count(val = global_364);
  apply((&function_48));
}
void function_50() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_7);
  apply((&function_49));
}
void function_51() {
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_52() {
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
  increment_count(val = global_12);
  apply((&function_51));
}
void function_53() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(env))))))));
  top_level_apply();
}
void function_54() {
  args = cons(val, args);
  increment_count(val = global_382);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_53));
}
void function_55() {
  args = cons(val, args);
  increment_count(val = global_299);
  apply((&function_54));
}
void function_56() {
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
  increment_count(val = global_7);
  apply((&function_55));
}
void function_57() {
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
    increment_count(val = global_306);
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
      increment_count(val = global_374);
      args = cons(val, args);
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_373);
      args = cons(val, args);
      increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_375);
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
        increment_count(val = global_318);
        top_level_apply();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_376);
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
          increment_count(val = global_7);
          apply((&function_44));
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_377);
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
            val = new_function((&function_47), env);
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
            increment_count(val = global_7);
            apply((&function_45));
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_379);
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
              increment_count(val = global_352);
              top_level_apply();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_380);
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
                increment_count(val = global_12);
                apply((&function_50));
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_381);
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
                  val = new_function((&function_56), env);
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
                  increment_count(val = global_7);
                  apply((&function_52));
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
                  increment_count(val = global_366);
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
void function_58() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(env)))))))));
  top_level_apply();
}
void function_59() {
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
  increment_count(val = global_38);
  apply((&function_58));
}
void function_60() {
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
  increment_count(val = global_38);
  apply((&function_59));
}
void function_61() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_60), env);
  top_level_apply();
}
void function_62() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14);
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
  increment_count(val = global_366);
  apply((&function_61));
}
void function_63() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_62), env);
  top_level_apply();
}
void function_64() {
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
    increment_count(val = global_332);
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_14);
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
    increment_count(val = global_332);
    apply((&function_63));
  }
}
void function_65() {
  args = cons(val, args);
  increment_count(val = global_14);
  top_level_apply();
}
void function_66() {
  args = cons(val, args);
  increment_count(val = global_363);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_65));
}
void function_67() {
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_66));
}
void function_68() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_4);
  apply((&function_67));
}
void function_69() {
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
  increment_count(val = global_364);
  apply((&function_68));
}
void function_70() {
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
    increment_count(val = global_11);
    apply((&function_69));
  }
}
void function_71() {
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_72() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(cdr(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_73() {
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
  increment_count(val = global_38);
  apply((&function_72));
}
void function_74() {
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
  increment_count(val = global_351);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_73));
}
void function_75() {
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
  increment_count(val = global_38);
  apply((&function_74));
}
void function_76() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_75), env);
  top_level_apply();
}
void function_77() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14);
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
  increment_count(val = global_352);
  apply((&function_76));
}
void function_78() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_77), env);
  top_level_apply();
}
void function_79() {
  args = cons(val, args);
  increment_count(val = global_332);
  apply((&function_78));
}
void function_80() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14);
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
  increment_count(val = global_11);
  apply((&function_79));
}
void function_81() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_80), env);
  top_level_apply();
}
void function_82() {
  args = cons(val, args);
  increment_count(val = global_332);
  apply((&function_81));
}
void function_83() {
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
    increment_count(val = global_11);
    apply((&function_71));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_14);
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
    increment_count(val = global_4);
    apply((&function_82));
  }
}
void function_84() {
  args = cons(val, args);
  increment_count(val = global_347);
  apply((&function_83));
}
void function_85() {
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
    increment_count(val = global_350);
    args = cons(val, args);
    increment_count(val = global_349);
    args = cons(val, args);
    increment_count(val = global_348);
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
    increment_count(val = global_4);
    apply((&function_84));
  }
}
void function_86() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_343);
    pop_function();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_344);
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
      increment_count(val = global_345);
      pop_function();
    } else {
      increment_count(val = global_346);
      pop_function();
    }
  }
}
void function_87() {
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
    increment_count(val = global_341);
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
      increment_count(val = global_342);
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
      increment_count(val = global_56);
      apply((&function_86));
    }
  }
}
void function_88() {
  args = cons(val, args);
  increment_count(val = global_322);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(env))))))));
  top_level_apply();
}
void function_89() {
  args = cons(val, args);
  increment_count(val = global_332);
  top_level_apply();
}
void function_90() {
  args = cons(val, args);
  increment_count(val = global_330);
  top_level_apply();
}
void function_91() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_92() {
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
  increment_count(val = global_326);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_91));
}
void function_93() {
  args = cons(val, args);
  increment_count(val = global_330);
  top_level_apply();
}
void function_94() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(env)))))))));
  top_level_apply();
}
void function_95() {
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
  increment_count(val = global_328);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_94));
}
void function_96() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(cdr(car(cdr(cdr(env))))))))));
  top_level_apply();
}
void function_97() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_96));
}
void function_98() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_329);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_97));
}
void function_99() {
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
  increment_count(val = global_38);
  apply((&function_98));
}
void function_100() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_99), env);
  top_level_apply();
}
void function_101() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_14);
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
  increment_count(val = global_330);
  apply((&function_100));
}
void function_102() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_101), env);
  top_level_apply();
}
void function_103() {
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
    increment_count(val = global_321);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_320);
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
      increment_count(val = global_324);
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_323);
      args = cons(val, args);
      increment_count(val = global_14);
      apply((&function_88));
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_325);
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
          increment_count(val = global_7);
          apply((&function_89));
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(env);
          val = new_function((&function_92), env);
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
          increment_count(val = global_7);
          apply((&function_90));
        }
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_327);
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
          val = new_function((&function_95), env);
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
          increment_count(val = global_7);
          apply((&function_93));
        } else {
          push_args();
          val = NIL;
          args = val;
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_14);
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
          increment_count(val = global_330);
          apply((&function_102));
        }
      }
    }
  }
}
void function_104() {
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
  increment_count(val = global_316);
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
void function_105() {
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_104), env);
  top_level_apply();
}
void function_106() {
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
  increment_count(val = global_77);
  apply((&function_105));
}
void function_107() {
  args = cons(val, args);
  increment_count(val = global_317);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_106));
}
void function_108() {
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
  increment_count(val = global_72);
  apply((&function_107));
}
void function_109() {
  args = cons(val, args);
  increment_count(val = global_313);
  args = cons(val, args);
  increment_count(val = global_14);
  top_level_apply();
}
void function_110() {
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
  increment_count(val = global_314);
  apply((&function_109));
}
void function_111() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_311);
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
        increment_count(val = global_312);
        args = cons(val, args);
        increment_count(val = global_14);
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
        increment_count(val = global_314);
        apply((&function_110));
      }
    }
  }
}
void function_112() {
  args = cons(val, args);
  increment_count(val = global_300);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_113() {
  args = cons(val, args);
  increment_count(val = global_303);
  args = cons(val, args);
  increment_count(val = global_302);
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_114() {
  args = cons(val, args);
  increment_count(val = global_304);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_113));
}
void function_115() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = global_301);
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_299);
    apply((&function_112));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_305);
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_81);
    apply((&function_114));
  }
}
void function_116() {
  apply((&function_115));
}
void function_117() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_82);
  args = cons(val, args);
  increment_count(val = global_58);
  apply((&function_116));
}
void function_118() {
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
  increment_count(val = global_295);
  apply((&function_117));
}
void function_119() {
  args = cons(val, args);
  increment_count(val = global_77);
  top_level_apply();
}
void function_120() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_79);
  apply((&function_119));
}
void function_121() {
  args = cons(val, args);
  increment_count(val = global_298);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_120));
}
void function_122() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_123() {
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
  increment_count(val = global_299);
  apply((&function_122));
}
void function_124() {
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
    increment_count(val = global_81);
    apply((&function_121));
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
      increment_count(val = global_299);
      apply((&function_123));
    }
  }
}
void function_125() {
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
  increment_count(val = global_295);
  top_level_apply();
}
void function_126() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_294);
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
      increment_count(val = global_295);
      apply((&function_125));
    }
  }
}
void function_127() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_293);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_287);
  top_level_apply();
}
void function_128() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_291);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_287);
  top_level_apply();
}
void function_129() {
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_130() {
  args = cons(val, args);
  increment_count(val = global_290);
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_131() {
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
  increment_count(val = global_287);
  apply((&function_130));
}
void function_132() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_288);
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
    increment_count(val = global_289);
    args = cons(val, args);
    increment_count(val = global_38);
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
      increment_count(val = global_279);
      apply((&function_129));
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
      increment_count(val = global_285);
      apply((&function_131));
    }
  }
}
void function_133() {
  args = cons(val, args);
  increment_count(val = global_282);
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_134() {
  args = cons(val, args);
  increment_count(val = global_284);
  args = cons(val, args);
  increment_count(val = global_38);
  top_level_apply();
}
void function_135() {
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
  increment_count(val = global_287);
  apply((&function_134));
}
void function_136() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_280);
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
    increment_count(val = global_281);
    args = cons(val, args);
    increment_count(val = global_38);
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
      increment_count(val = global_283);
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_279);
      apply((&function_133));
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
      increment_count(val = global_285);
      apply((&function_135));
    }
  }
}
void function_137() {
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
    increment_count(val = global_213);
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
      increment_count(val = global_81);
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_220);
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
        increment_count(val = global_221);
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_222);
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
          increment_count(val = global_223);
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_224);
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
            increment_count(val = global_225);
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_226);
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
              increment_count(val = global_227);
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_228);
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
                increment_count(val = global_229);
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_230);
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
                  increment_count(val = global_231);
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  increment_count(val = global_232);
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
                    increment_count(val = global_233);
                    pop_function();
                  } else {
                    push_args();
                    val = NIL;
                    args = val;
                    increment_count(val = global_234);
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
                      increment_count(val = global_235);
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      increment_count(val = global_236);
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
                        increment_count(val = global_237);
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        increment_count(val = global_238);
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
                          increment_count(val = global_239);
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          increment_count(val = global_240);
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
                            increment_count(val = global_241);
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            increment_count(val = global_242);
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
                              increment_count(val = global_243);
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              increment_count(val = global_244);
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
                                increment_count(val = global_245);
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                increment_count(val = global_246);
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
                                  increment_count(val = global_247);
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  increment_count(val = global_248);
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
                                    increment_count(val = global_249);
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    increment_count(val = global_250);
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
                                      increment_count(val = global_251);
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      increment_count(val = global_252);
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
                                        increment_count(val = global_253);
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        increment_count(val = global_254);
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
                                          increment_count(val = global_255);
                                          pop_function();
                                        } else {
                                          push_args();
                                          val = NIL;
                                          args = val;
                                          increment_count(val = global_256);
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
                                            increment_count(val = global_257);
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            increment_count(val = global_258);
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
                                              increment_count(val = global_259);
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              increment_count(val = global_260);
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
                                                increment_count(val = global_261);
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                increment_count(val = global_262);
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
                                                  increment_count(val = global_263);
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  increment_count(val = global_264);
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
                                                    increment_count(val = global_265);
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    increment_count(val = global_266);
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
                                                      increment_count(val = global_267);
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      increment_count(val = global_268);
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
                                                        increment_count(val = global_269);
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        increment_count(val = global_270);
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
                                                          increment_count(val = global_271);
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          increment_count(val = global_272);
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
                                                            increment_count(val = global_273);
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            increment_count(val = global_274);
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
                                                              increment_count(val = global_275);
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              increment_count(val = global_276);
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
                                                                increment_count(val = global_277);
                                                                pop_function();
                                                              } else {
                                                                increment_count(val = global_278);
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
void function_138() {
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
void function_139() {
  apply((&function_138));
}
void function_140() {
  top_level_apply();
}
void function_141() {
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
    increment_count(val = global_217);
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
    increment_count(val = global_214);
    apply((&function_139));
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
      increment_count(val = global_218);
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_219);
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_214);
      apply((&function_140));
    }
  }
}
void function_142() {
  top_level_apply();
}
void function_143() {
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
void function_144() {
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
void function_145() {
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
void function_146() {
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
void function_147() {
  increment_count(env);
  val = new_function((&function_146), env);
  pop_function();
}
void function_148() {
  increment_count(val = global_13);
  pop_function();
}
void function_149() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_148), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_147), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_145), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_144), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_143), env);
  args = cons(val, args);
  increment_count(val = global_20);
  apply((&function_142));
}
void function_150() {
  args = cons(val, args);
  increment_count(val = global_75);
  top_level_apply();
}
void function_151() {
  args = cons(val, args);
  increment_count(val = global_208);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_150));
}
void function_152() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_209);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_213);
  apply((&function_151));
}
void function_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_152), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_207);
  top_level_apply();
}
void function_154() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_155() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_154));
}
void function_156() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_155));
}
void function_157() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192);
  apply((&function_156));
}
void function_158() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_157));
}
void function_159() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_158));
}
void function_160() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_200);
  args = cons(val, args);
  increment_count(val = global_201);
  apply((&function_159));
}
void function_161() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_160));
}
void function_162() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_161));
}
void function_163() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_201);
  apply((&function_162));
}
void function_164() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_163));
}
void function_165() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_164));
}
void function_166() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_202);
  apply((&function_165));
}
void function_167() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_166));
}
void function_168() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_176);
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
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_203);
  apply((&function_168));
}
void function_170() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_169));
}
void function_171() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_206);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_170));
}
void function_172() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_171));
}
void function_173() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_172));
}
void function_174() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_173));
}
void function_175() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_169);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_174));
}
void function_176() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_175));
}
void function_177() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_176));
}
void function_178() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_204);
  apply((&function_177));
}
void function_179() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_178));
}
void function_180() {
  args = cons(val, args);
  increment_count(val = global_190);
  apply((&function_179));
}
void function_181() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_197);
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
  increment_count(val = global_192);
  apply((&function_180));
}
void function_182() {
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
  increment_count(val = global_199);
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_181));
}
void function_183() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_184() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_183));
}
void function_185() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_184));
}
void function_186() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_206);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192);
  apply((&function_185));
}
void function_187() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_186));
}
void function_188() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176);
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
  increment_count(val = global_206);
  args = cons(val, args);
  increment_count(val = global_204);
  apply((&function_188));
}
void function_190() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_189));
}
void function_191() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_190));
}
void function_192() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_191));
}
void function_193() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_192));
}
void function_194() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205);
  args = cons(val, args);
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_195);
  apply((&function_193));
}
void function_195() {
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_194));
}
void function_196() {
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
  increment_count(val = global_206);
  args = cons(val, args);
  increment_count(val = global_207);
  args = cons(val, args);
  increment_count(val = global_185);
  apply((&function_195));
}
void function_197() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_198() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_197));
}
void function_199() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_198));
}
void function_200() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_192);
  apply((&function_199));
}
void function_201() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_200));
}
void function_202() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_201));
}
void function_203() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_205);
  args = cons(val, args);
  increment_count(val = global_204);
  apply((&function_202));
}
void function_204() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_203));
}
void function_205() {
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
  increment_count(val = global_171);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_204));
}
void function_206() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_207() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_206));
}
void function_208() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_207));
}
void function_209() {
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
  increment_count(val = global_176);
  apply((&function_208));
}
void function_210() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_209));
}
void function_211() {
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
  increment_count(val = global_176);
  apply((&function_210));
}
void function_212() {
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_211));
}
void function_213() {
  args = cons(val, args);
  increment_count(val = global_194);
  apply((&function_212));
}
void function_214() {
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
  increment_count(val = global_204);
  apply((&function_213));
}
void function_215() {
  increment_count(env);
  val = new_function((&function_214), env);
  pop_function();
}
void function_216() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_108);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184);
  top_level_apply();
}
void function_217() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_106);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184);
  top_level_apply();
}
void function_218() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_103);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_184);
  top_level_apply();
}
void function_219() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_220() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_219));
}
void function_221() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_220));
}
void function_222() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_221));
}
void function_223() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_222));
}
void function_224() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_223));
}
void function_225() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_200);
  args = cons(val, args);
  increment_count(val = global_188);
  apply((&function_224));
}
void function_226() {
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_225));
}
void function_227() {
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
  increment_count(val = global_200);
  args = cons(val, args);
  increment_count(val = global_189);
  apply((&function_226));
}
void function_228() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_229() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_167);
  args = cons(val, args);
  increment_count(val = global_198);
  args = cons(val, args);
  increment_count(val = global_184);
  apply((&function_228));
}
void function_230() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_231() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_230));
}
void function_232() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_231));
}
void function_233() {
  args = cons(val, args);
  increment_count(val = global_190);
  apply((&function_232));
}
void function_234() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
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
  increment_count(val = global_192);
  apply((&function_233));
}
void function_235() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_234));
}
void function_236() {
  args = cons(val, args);
  increment_count(val = global_190);
  apply((&function_235));
}
void function_237() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
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
  increment_count(val = global_192);
  apply((&function_236));
}
void function_238() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_237));
}
void function_239() {
  args = cons(val, args);
  increment_count(val = global_190);
  apply((&function_238));
}
void function_240() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_239));
}
void function_241() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_240));
}
void function_242() {
  args = cons(val, args);
  increment_count(val = global_190);
  apply((&function_241));
}
void function_243() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_171);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_176);
  apply((&function_242));
}
void function_244() {
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_243));
}
void function_245() {
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
  increment_count(val = global_198);
  args = cons(val, args);
  increment_count(val = global_189);
  apply((&function_244));
}
void function_246() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_247() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_95);
  args = cons(val, args);
  increment_count(val = global_196);
  args = cons(val, args);
  increment_count(val = global_184);
  apply((&function_246));
}
void function_248() {
  args = cons(val, args);
  increment_count(val = global_16);
  top_level_apply();
}
void function_249() {
  args = cons(val, args);
  increment_count(val = global_182);
  apply((&function_248));
}
void function_250() {
  args = cons(val, args);
  increment_count(val = global_180);
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  increment_count(val = global_190);
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
  val = new_number(57);
  args = cons(val, args);
  val = new_number(48);
  args = cons(val, args);
  increment_count(val = global_192);
  apply((&function_251));
}
void function_253() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_196);
  args = cons(val, args);
  increment_count(val = global_189);
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
  increment_count(val = global_171);
  args = cons(val, args);
  increment_count(val = global_177);
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  increment_count(val = global_184);
  top_level_apply();
}
void function_256() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_101);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_185);
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  increment_count(val = global_184);
  top_level_apply();
}
void function_258() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99);
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_189);
  apply((&function_257));
}
void function_259() {
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
  increment_count(val = global_53);
  top_level_apply();
}
void function_260() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_259), env);
  args = cons(val, args);
  increment_count(val = global_174);
  top_level_apply();
}
void function_261() {
  top_level_apply();
}
void function_262() {
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
  apply((&function_261));
}
void function_263() {
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
  val = new_function((&function_262), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_264() {
  increment_count(env);
  val = new_function((&function_263), env);
  pop_function();
}
void function_265() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_173);
  args = cons(val, args);
  increment_count(val = global_185);
  top_level_apply();
}
void function_266() {
  args = cons(val, args);
  increment_count(val = global_185);
  top_level_apply();
}
void function_267() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_92);
  args = cons(val, args);
  increment_count(val = global_173);
  args = cons(val, args);
  increment_count(val = global_184);
  apply((&function_266));
}
void function_268() {
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
void function_269() {
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
  val = new_function((&function_268), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
}
void function_270() {
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
  val = new_function((&function_269), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_271() {
  increment_count(env);
  val = new_function((&function_270), env);
  pop_function();
}
void function_272() {
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
void function_273() {
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
  val = new_function((&function_272), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_274() {
  increment_count(env);
  val = new_function((&function_273), env);
  pop_function();
}
void function_275() {
  top_level_apply();
}
void function_276() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
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
  increment_count(val = global_169);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_276), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_275));
}
void function_278() {
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
void function_279() {
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
void function_280() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_279), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_278), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_281() {
  increment_count(env);
  val = new_function((&function_280), env);
  pop_function();
}
void function_282() {
  increment_count(env);
  val = new_function((&function_281), env);
  pop_function();
}
void function_283() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_284() {
  increment_count(env);
  val = new_function((&function_283), env);
  pop_function();
}
void function_285() {
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
void function_286() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_285), env);
  args = cons(val, args);
  increment_count(val = global_174);
  top_level_apply();
}
void function_287() {
  top_level_apply();
}
void function_288() {
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
    apply((&function_287));
  }
}
void function_289() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_288));
}
void function_290() {
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
  val = new_function((&function_289), env);
  args = cons(val, args);
  increment_count(val = global_173);
  top_level_apply();
}
void function_291() {
  increment_count(env);
  val = new_function((&function_290), env);
  pop_function();
}
void function_292() {
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
void function_293() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_172);
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
    increment_count(val = global_173);
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
    increment_count(val = global_56);
    apply((&function_292));
  }
}
void function_294() {
  increment_count(env);
  val = new_function((&function_293), env);
  pop_function();
}
void function_295() {
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
void function_296() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_297() {
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
void function_298() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_166);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_297), env);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_90);
    top_level_apply();
  }
}
void function_299() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_164);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_165);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_298));
  }
}
void function_300() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_162);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_163);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_299));
  }
}
void function_301() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_160);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_161);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_300));
  }
}
void function_302() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_158);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_159);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_301));
  }
}
void function_303() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_156);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_157);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_302));
  }
}
void function_304() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_154);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_155);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_303));
  }
}
void function_305() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_152);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_153);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_304));
  }
}
void function_306() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_150);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_151);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_305));
  }
}
void function_307() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_148);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_149);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_306));
  }
}
void function_308() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_146);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_147);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_307));
  }
}
void function_309() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_144);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_145);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_308));
  }
}
void function_310() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_142);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_143);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_309));
  }
}
void function_311() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_140);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_141);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_310));
  }
}
void function_312() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_138);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_139);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_311));
  }
}
void function_313() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_136);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_137);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_312));
  }
}
void function_314() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_134);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_135);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_313));
  }
}
void function_315() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_132);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_133);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_314));
  }
}
void function_316() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_130);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_131);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_315));
  }
}
void function_317() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_128);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_129);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_316));
  }
}
void function_318() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_126);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_127);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_317));
  }
}
void function_319() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_124);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_125);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_318));
  }
}
void function_320() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_122);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_123);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_319));
  }
}
void function_321() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_120);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_121);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_320));
  }
}
void function_322() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_118);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_119);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_321));
  }
}
void function_323() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_116);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_117);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_322));
  }
}
void function_324() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_114);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_115);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_323));
  }
}
void function_325() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_112);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_113);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_324));
  }
}
void function_326() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_110);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_111);
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42);
    apply((&function_325));
  }
}
void function_327() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_109);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42);
  apply((&function_326));
}
void function_328() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_329() {
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
  increment_count(val = global_107);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_328));
}
void function_330() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_331() {
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
  increment_count(val = global_105);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_330));
}
void function_332() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_333() {
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
  increment_count(val = global_102);
  args = cons(val, args);
  increment_count(val = global_14);
  apply((&function_332));
}
void function_334() {
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
void function_335() {
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
void function_336() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_337() {
  apply((&function_336));
}
void function_338() {
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
void function_339() {
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
  val = new_function((&function_338), env);
  args = cons(val, args);
  increment_count(val = global_32);
  apply((&function_337));
}
void function_340() {
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
void function_341() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_342() {
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
  increment_count(val = global_77);
  apply((&function_341));
}
void function_343() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_342), env);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_85);
  top_level_apply();
}
void function_344() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_345() {
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
    increment_count(val = global_6);
    apply((&function_344));
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
    increment_count(val = global_85);
    top_level_apply();
  }
}
void function_346() {
  args = cons(val, args);
  increment_count(val = global_42);
  apply((&function_345));
}
void function_347() {
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
    increment_count(val = global_4);
    apply((&function_346));
  }
}
void function_348() {
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
void function_349() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_79);
  apply((&function_348));
}
void function_350() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_79);
  apply((&function_349));
}
void function_351() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_352() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_351), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_353() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_354() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_353), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_355() {
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
void function_356() {
  increment_count(env);
  val = new_function((&function_355), env);
  pop_function();
}
void function_357() {
  args = cons(val, args);
  increment_count(val = global_62);
  top_level_apply();
}
void function_358() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_74);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_73);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_357));
}
void function_359() {
  args = cons(val, args);
  increment_count(val = global_62);
  top_level_apply();
}
void function_360() {
  args = cons(val, args);
  increment_count(val = global_66);
  args = cons(val, args);
  increment_count(val = global_65);
  args = cons(val, args);
  increment_count(val = global_38);
  apply((&function_359));
}
void function_361() {
  increment_count(val = car(cdr(car(env))));
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_68);
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_67);
    args = cons(val, args);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_72);
    apply((&function_360));
  } else {
    val = NIL;
    pop_function();
  }
}
void function_362() {
  global_62 = val;
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
  global_65 = val;
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
  global_66 = val;
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
  global_67 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_68 = val;
  increment_count(env);
  val = new_function((&function_361), env);
  global_69 = val;
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
  global_73 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_74 = val;
  increment_count(env);
  val = new_function((&function_358), env);
  global_75 = val;
  increment_count(env);
  val = new_function((&function_356), env);
  global_77 = val;
  increment_count(env);
  val = new_function((&function_354), env);
  global_79 = val;
  increment_count(env);
  val = new_function((&function_352), env);
  global_81 = val;
  increment_count(env);
  val = new_function((&function_350), env);
  global_82 = val;
  increment_count(env);
  val = new_function((&function_347), env);
  global_85 = val;
  increment_count(env);
  val = new_function((&function_343), env);
  global_90 = val;
  increment_count(env);
  val = new_function((&function_340), env);
  global_92 = val;
  increment_count(env);
  val = new_function((&function_339), env);
  global_95 = val;
  increment_count(env);
  val = new_function((&function_335), env);
  global_99 = val;
  increment_count(env);
  val = new_function((&function_334), env);
  global_101 = val;
  val = QUOTE;
  global_102 = val;
  increment_count(env);
  val = new_function((&function_333), env);
  global_103 = val;
  val = QUASIQUOTE;
  global_105 = val;
  increment_count(env);
  val = new_function((&function_331), env);
  global_106 = val;
  val = UNQUOTE;
  global_107 = val;
  increment_count(env);
  val = new_function((&function_329), env);
  global_108 = val;
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
  global_109 = val;
  val = COND;
  global_110 = val;
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
  global_111 = val;
  val = IF;
  global_112 = val;
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
  global_113 = val;
  val = LET;
  global_114 = val;
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
  global_115 = val;
  val = FN;
  global_116 = val;
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
  global_117 = val;
  val = QUOTE;
  global_118 = val;
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
  global_119 = val;
  val = QUASIQUOTE;
  global_120 = val;
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
  global_121 = val;
  val = UNQUOTE;
  global_122 = val;
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
  global_123 = val;
  val = CONS;
  global_124 = val;
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
  global_125 = val;
  val = CAR;
  global_126 = val;
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
  global_127 = val;
  val = CDR;
  global_128 = val;
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
  global_129 = val;
  val = ATOM;
  global_130 = val;
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
  global_131 = val;
  val = NUMBER;
  global_132 = val;
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
  global_133 = val;
  val = FUNCTION;
  global_134 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_135 = val;
  val = EQ;
  global_136 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_137 = val;
  val = LT;
  global_138 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_139 = val;
  val = GT;
  global_140 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_141 = val;
  val = PLUS;
  global_142 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_143 = val;
  val = MINUS;
  global_144 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_145 = val;
  val = MULT;
  global_146 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_147 = val;
  val = DIV;
  global_148 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_149 = val;
  val = MOD;
  global_150 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_151 = val;
  val = BNEG;
  global_152 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_153 = val;
  val = BAND;
  global_154 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_155 = val;
  val = BOR;
  global_156 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_157 = val;
  val = BXOR;
  global_158 = val;
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
  global_159 = val;
  val = SRSHIFT;
  global_160 = val;
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
  global_161 = val;
  val = URSHIFT;
  global_162 = val;
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
  global_163 = val;
  val = LSHIFT;
  global_164 = val;
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
  global_165 = val;
  val = DEFINE;
  global_166 = val;
  increment_count(env);
  val = new_function((&function_327), env);
  global_167 = val;
  increment_count(env);
  val = new_function((&function_296), env);
  global_169 = val;
  increment_count(env);
  val = new_function((&function_295), env);
  global_171 = val;
  val = NIL;
  global_172 = val;
  increment_count(env);
  val = new_function((&function_294), env);
  global_173 = val;
  increment_count(env);
  val = new_function((&function_291), env);
  global_174 = val;
  increment_count(env);
  val = new_function((&function_286), env);
  global_176 = val;
  increment_count(env);
  val = new_function((&function_284), env);
  global_177 = val;
  increment_count(env);
  val = new_function((&function_282), env);
  global_180 = val;
  increment_count(env);
  val = new_function((&function_277), env);
  global_182 = val;
  increment_count(env);
  val = new_function((&function_274), env);
  global_184 = val;
  increment_count(env);
  val = new_function((&function_271), env);
  global_185 = val;
  increment_count(env);
  val = new_function((&function_267), env);
  global_188 = val;
  increment_count(env);
  val = new_function((&function_265), env);
  global_189 = val;
  increment_count(env);
  val = new_function((&function_264), env);
  global_190 = val;
  increment_count(env);
  val = new_function((&function_260), env);
  global_192 = val;
  increment_count(env);
  val = new_function((&function_258), env);
  global_194 = val;
  increment_count(env);
  val = new_function((&function_256), env);
  global_195 = val;
  increment_count(env);
  val = new_function((&function_254), env);
  global_196 = val;
  increment_count(env);
  val = new_function((&function_247), env);
  global_197 = val;
  increment_count(env);
  val = new_function((&function_245), env);
  global_198 = val;
  increment_count(env);
  val = new_function((&function_229), env);
  global_199 = val;
  increment_count(env);
  val = new_function((&function_227), env);
  global_200 = val;
  increment_count(env);
  val = new_function((&function_218), env);
  global_201 = val;
  increment_count(env);
  val = new_function((&function_217), env);
  global_202 = val;
  increment_count(env);
  val = new_function((&function_216), env);
  global_203 = val;
  increment_count(env);
  val = new_function((&function_215), env);
  global_204 = val;
  increment_count(env);
  val = new_function((&function_205), env);
  global_205 = val;
  increment_count(env);
  val = new_function((&function_196), env);
  global_206 = val;
  increment_count(env);
  val = new_function((&function_182), env);
  global_207 = val;
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
  global_208 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_209 = val;
  increment_count(env);
  val = new_function((&function_153), env);
  global_210 = val;
  increment_count(env);
  val = new_function((&function_149), env);
  global_214 = val;
  val = NIL;
  global_217 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_218 = val;
  val = NIL;
  global_219 = val;
  increment_count(env);
  val = new_function((&function_141), env);
  global_213 = val;
  val = QUOTE;
  global_220 = val;
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
  global_221 = val;
  val = QUASIQUOTE;
  global_222 = val;
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
  global_223 = val;
  val = UNQUOTE;
  global_224 = val;
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
  global_225 = val;
  val = CAR;
  global_226 = val;
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
  global_227 = val;
  val = CDR;
  global_228 = val;
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
  global_229 = val;
  val = NUMBER;
  global_230 = val;
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
  global_231 = val;
  val = FUNCTION;
  global_232 = val;
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
  global_233 = val;
  val = ATOM;
  global_234 = val;
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
  global_235 = val;
  val = CONS;
  global_236 = val;
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
  global_237 = val;
  val = COND;
  global_238 = val;
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
  global_239 = val;
  val = IF;
  global_240 = val;
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
  global_241 = val;
  val = LET;
  global_242 = val;
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
  global_243 = val;
  val = FN;
  global_244 = val;
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
  global_245 = val;
  val = URSHIFT;
  global_246 = val;
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
  global_247 = val;
  val = SRSHIFT;
  global_248 = val;
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
  global_249 = val;
  val = LSHIFT;
  global_250 = val;
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
  global_251 = val;
  val = LT;
  global_252 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_253 = val;
  val = GT;
  global_254 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_255 = val;
  val = EQ;
  global_256 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_257 = val;
  val = PLUS;
  global_258 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_259 = val;
  val = MINUS;
  global_260 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_261 = val;
  val = MULT;
  global_262 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_263 = val;
  val = DIV;
  global_264 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_265 = val;
  val = MOD;
  global_266 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_267 = val;
  val = BAND;
  global_268 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_269 = val;
  val = BOR;
  global_270 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_271 = val;
  val = BXOR;
  global_272 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_273 = val;
  val = BNEG;
  global_274 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_275 = val;
  val = DEFINE;
  global_276 = val;
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
  global_277 = val;
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
  global_278 = val;
  increment_count(env);
  val = new_function((&function_137), env);
  global_279 = val;
  val = NIL;
  global_280 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_281 = val;
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
  global_282 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_283 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_284 = val;
  increment_count(env);
  val = new_function((&function_136), env);
  global_285 = val;
  val = NIL;
  global_288 = val;
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
  global_289 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_290 = val;
  increment_count(env);
  val = new_function((&function_132), env);
  global_287 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_291 = val;
  increment_count(env);
  val = new_function((&function_128), env);
  global_292 = val;
  val = NIL;
  global_293 = val;
  increment_count(env);
  val = new_function((&function_127), env);
  global_72 = val;
  val = NIL;
  global_294 = val;
  increment_count(env);
  val = new_function((&function_126), env);
  global_295 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_298 = val;
  increment_count(env);
  val = new_function((&function_124), env);
  global_299 = val;
  val = NIL;
  global_300 = val;
  val = NIL;
  global_301 = val;
  val = NIL;
  global_302 = val;
  val = NIL;
  global_303 = val;
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
  global_304 = val;
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
  global_305 = val;
  increment_count(env);
  val = new_function((&function_118), env);
  global_306 = val;
  val = NIL;
  global_311 = val;
  val = QUOTE;
  global_312 = val;
  val = CONS;
  global_313 = val;
  increment_count(env);
  val = new_function((&function_111), env);
  global_314 = val;
  val = NIL;
  global_316 = val;
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
  global_317 = val;
  increment_count(env);
  val = new_function((&function_108), env);
  global_318 = val;
  val = NIL;
  global_320 = val;
  val = NIL;
  global_321 = val;
  val = NIL;
  global_322 = val;
  val = QUOTE;
  global_323 = val;
  val = NIL;
  global_324 = val;
  val = UNQUOTE;
  global_325 = val;
  val = UNQUOTE;
  global_326 = val;
  val = QUASIQUOTE;
  global_327 = val;
  val = QUASIQUOTE;
  global_328 = val;
  val = CONS;
  global_329 = val;
  increment_count(env);
  val = new_function((&function_103), env);
  global_330 = val;
  val = NIL;
  global_341 = val;
  val = QUOTE;
  global_342 = val;
  val = NIL;
  global_343 = val;
  val = NIL;
  global_344 = val;
  val = NIL;
  global_345 = val;
  val = -86;
  global_346 = val;
  increment_count(env);
  val = new_function((&function_87), env);
  global_347 = val;
  val = NIL;
  global_348 = val;
  val = NIL;
  global_349 = val;
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
  global_350 = val;
  val = IF;
  global_351 = val;
  increment_count(env);
  val = new_function((&function_85), env);
  global_352 = val;
  val = FN;
  global_363 = val;
  increment_count(env);
  val = new_function((&function_70), env);
  global_364 = val;
  increment_count(env);
  val = new_function((&function_64), env);
  global_366 = val;
  val = NIL;
  global_373 = val;
  val = NIL;
  global_374 = val;
  val = QUOTE;
  global_375 = val;
  val = QUASIQUOTE;
  global_376 = val;
  val = UNQUOTE;
  global_377 = val;
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
  global_378 = val;
  val = COND;
  global_379 = val;
  val = LET;
  global_380 = val;
  val = FN;
  global_381 = val;
  val = FN;
  global_382 = val;
  increment_count(env);
  val = new_function((&function_57), env);
  global_332 = val;
  increment_count(env);
  val = new_function((&function_43), env);
  global_383 = val;
  val = FN;
  global_385 = val;
  increment_count(env);
  val = new_function((&function_41), env);
  global_386 = val;
  val = NIL;
  global_387 = val;
  increment_count(env);
  val = new_function((&function_37), env);
  global_388 = val;
  increment_count(env);
  val = new_function((&function_24), env);
  global_391 = val;
  val = NIL;
  global_392 = val;
  increment_count(env);
  val = new_function((&function_22), env);
  global_393 = val;
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
  global_396 = val;
  val = DEFINE;
  global_397 = val;
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
  global_398 = val;
  increment_count(env);
  val = new_function((&function_12), env);
  global_399 = val;
  val = NIL;
  global_403 = val;
  val = NIL;
  global_404 = val;
  increment_count(env);
  val = new_function((&function_2), env);
  pop_function();
}
void function_363() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_364() {
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
  increment_count(val = global_14);
  apply((&function_363));
}
void function_365() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_57);
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_366() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_365));
}
void function_367() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_366), env);
  args = cons(val, args);
  increment_count(val = global_35);
  top_level_apply();
}
void function_368() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_54);
    pop_function();
  } else {
    increment_count(val = global_55);
    pop_function();
  }
}
void function_369() {
  top_level_apply();
}
void function_370() {
  increment_count(val = car(car(env)));
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = car(cdr(car(env))));
    pop_function();
  } else {
    increment_count(val = global_50);
    pop_function();
  }
}
void function_371() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_51);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_370), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_369));
}
void function_372() {
  top_level_apply();
}
void function_373() {
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
void function_374() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_46);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_373), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_372));
}
void function_375() {
  top_level_apply();
}
void function_376() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_377() {
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
  apply((&function_376));
}
void function_378() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_44);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_377), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_375));
}
void function_379() {
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
    increment_count(val = global_42);
    top_level_apply();
  } else {
    increment_count(val = global_41);
    pop_function();
  }
}
void function_380() {
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
      increment_count(val = global_40);
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
      increment_count(val = global_42);
      apply((&function_379));
    }
  }
}
void function_381() {
  top_level_apply();
}
void function_382() {
  top_level_apply();
}
void function_383() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_36);
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
    increment_count(val = global_35);
    apply((&function_382));
  }
}
void function_384() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_37);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_383), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_381));
}
void function_385() {
  args = cons(val, args);
  increment_count(val = global_34);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_27);
  top_level_apply();
}
void function_386() {
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
  increment_count(val = global_32);
  apply((&function_385));
}
void function_387() {
  increment_count(env);
  val = new_function((&function_386), env);
  pop_function();
}
void function_388() {
  top_level_apply();
}
void function_389() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_32);
  apply((&function_388));
}
void function_390() {
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
    apply((&function_389));
  }
}
void function_391() {
  increment_count(env);
  val = new_function((&function_390), env);
  pop_function();
}
void function_392() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_13);
  args = cons(val, args);
  increment_count(val = global_30);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_27);
  top_level_apply();
}
void function_393() {
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
    increment_count(val = global_27);
    top_level_apply();
  }
}
void function_394() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_395() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_394));
}
void function_396() {
  apply((&function_395));
}
void function_397() {
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
  increment_count(val = global_20);
  apply((&function_396));
}
void function_398() {
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
    apply((&function_397));
  }
}
void function_399() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_398));
}
void function_400() {
  increment_count(env);
  val = new_function((&function_399), env);
  pop_function();
}
void function_401() {
  top_level_apply();
}
void function_402() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_401));
}
void function_403() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_402), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_404() {
  top_level_apply();
}
void function_405() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_404));
}
void function_406() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_405), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_407() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_406), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_403), env);
  top_level_apply();
}
void function_408() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_409() {
  increment_count(val = car(env));
  pop_function();
}
void function_410() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_411() {
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
void function_412() {
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
void function_413() {
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
void function_414() {
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
void function_415() {
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
void function_416() {
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
void function_417() {
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
void function_418() {
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
void function_419() {
  increment_count(env);
  val = new_function((&function_418), env);
  global_4 = val;
  increment_count(env);
  val = new_function((&function_417), env);
  global_6 = val;
  increment_count(env);
  val = new_function((&function_416), env);
  global_7 = val;
  increment_count(env);
  val = new_function((&function_415), env);
  global_8 = val;
  increment_count(env);
  val = new_function((&function_414), env);
  global_9 = val;
  increment_count(env);
  val = new_function((&function_413), env);
  global_10 = val;
  increment_count(env);
  val = new_function((&function_412), env);
  global_11 = val;
  increment_count(env);
  val = new_function((&function_411), env);
  global_12 = val;
  increment_count(env);
  val = new_function((&function_410), env);
  global_13 = val;
  increment_count(env);
  val = new_function((&function_409), env);
  global_14 = val;
  increment_count(env);
  val = new_function((&function_408), env);
  global_16 = val;
  increment_count(env);
  val = new_function((&function_407), env);
  global_18 = val;
  increment_count(env);
  val = new_function((&function_400), env);
  global_20 = val;
  increment_count(env);
  val = new_function((&function_393), env);
  global_27 = val;
  val = NIL;
  global_30 = val;
  increment_count(env);
  val = new_function((&function_392), env);
  global_31 = val;
  increment_count(env);
  val = new_function((&function_391), env);
  global_32 = val;
  val = NIL;
  global_34 = val;
  increment_count(env);
  val = new_function((&function_387), env);
  global_35 = val;
  val = NIL;
  global_36 = val;
  val = NIL;
  global_37 = val;
  increment_count(env);
  val = new_function((&function_384), env);
  global_38 = val;
  val = NIL;
  global_40 = val;
  val = NIL;
  global_41 = val;
  increment_count(env);
  val = new_function((&function_380), env);
  global_42 = val;
  val = NIL;
  global_44 = val;
  increment_count(env);
  val = new_function((&function_378), env);
  global_45 = val;
  val = NIL;
  global_46 = val;
  increment_count(env);
  val = new_function((&function_374), env);
  global_47 = val;
  val = NIL;
  global_50 = val;
  val = -86;
  global_51 = val;
  increment_count(env);
  val = new_function((&function_371), env);
  global_53 = val;
  val = NIL;
  global_54 = val;
  val = -86;
  global_55 = val;
  increment_count(env);
  val = new_function((&function_368), env);
  global_56 = val;
  val = -86;
  global_57 = val;
  increment_count(env);
  val = new_function((&function_367), env);
  global_58 = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_364), env);
  args = cons(val, args);
  increment_count(val = global_35);
  apply((&function_362));
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
    return_location = (&function_419);
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
  return_location = (&function_419);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
