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
pointer global_353 = NIL; /* l_2 */
pointer global_352 = NIL; /* l_1 */
pointer global_348 = NIL; /* _compile-source */
pointer global_347 = NIL; /* l_205 */
pointer global_346 = NIL; /* l_204 */
pointer global_345 = NIL; /* l_203 */
pointer global_343 = NIL; /* _compile */
pointer global_342 = NIL; /* l_202 */
pointer global_341 = NIL; /* l_201 */
pointer global_340 = NIL; /* l_200 */
pointer global_339 = NIL; /* l_199 */
pointer global_338 = NIL; /* l_198 */
pointer global_337 = NIL; /* l_197 */
pointer global_336 = NIL; /* l_196 */
pointer global_335 = NIL; /* l_195 */
pointer global_334 = NIL; /* l_194 */
pointer global_333 = NIL; /* l_193 */
pointer global_332 = NIL; /* l_192 */
pointer global_331 = NIL; /* l_191 */
pointer global_330 = NIL; /* l_190 */
pointer global_329 = NIL; /* l_189 */
pointer global_328 = NIL; /* l_188 */
pointer global_327 = NIL; /* l_187 */
pointer global_326 = NIL; /* l_186 */
pointer global_325 = NIL; /* l_185 */
pointer global_324 = NIL; /* l_184 */
pointer global_323 = NIL; /* l_183 */
pointer global_322 = NIL; /* _escape-symbols */
pointer global_321 = NIL; /* l_182 */
pointer global_320 = NIL; /* l_181 */
pointer global_319 = NIL; /* l_180 */
pointer global_318 = NIL; /* l_179 */
pointer global_317 = NIL; /* l_178 */
pointer global_316 = NIL; /* l_177 */
pointer global_315 = NIL; /* l_176 */
pointer global_314 = NIL; /* _print */
pointer global_313 = NIL; /* l_175 */
pointer global_312 = NIL; /* _print-with-newline */
pointer global_311 = NIL; /* l_174 */
pointer global_307 = NIL; /* _print-with-suffix */
pointer global_310 = NIL; /* l_173 */
pointer global_309 = NIL; /* l_172 */
pointer global_308 = NIL; /* l_171 */
pointer global_305 = NIL; /* _print-tail */
pointer global_304 = NIL; /* l_170 */
pointer global_303 = NIL; /* l_169 */
pointer global_302 = NIL; /* l_168 */
pointer global_301 = NIL; /* l_167 */
pointer global_300 = NIL; /* l_166 */
pointer global_299 = NIL; /* _print-atom */
pointer global_298 = NIL; /* l_165 */
pointer global_297 = NIL; /* l_164 */
pointer global_296 = NIL; /* l_163 */
pointer global_295 = NIL; /* l_162 */
pointer global_294 = NIL; /* l_161 */
pointer global_293 = NIL; /* l_160 */
pointer global_292 = NIL; /* l_159 */
pointer global_291 = NIL; /* l_158 */
pointer global_290 = NIL; /* l_157 */
pointer global_289 = NIL; /* l_156 */
pointer global_288 = NIL; /* l_155 */
pointer global_287 = NIL; /* l_154 */
pointer global_286 = NIL; /* l_153 */
pointer global_285 = NIL; /* l_152 */
pointer global_284 = NIL; /* l_151 */
pointer global_283 = NIL; /* l_150 */
pointer global_282 = NIL; /* l_149 */
pointer global_281 = NIL; /* l_148 */
pointer global_280 = NIL; /* l_147 */
pointer global_279 = NIL; /* l_146 */
pointer global_278 = NIL; /* l_145 */
pointer global_277 = NIL; /* l_144 */
pointer global_276 = NIL; /* l_143 */
pointer global_275 = NIL; /* l_142 */
pointer global_274 = NIL; /* l_141 */
pointer global_273 = NIL; /* l_140 */
pointer global_272 = NIL; /* l_139 */
pointer global_271 = NIL; /* l_138 */
pointer global_270 = NIL; /* l_137 */
pointer global_269 = NIL; /* l_136 */
pointer global_268 = NIL; /* l_135 */
pointer global_267 = NIL; /* l_134 */
pointer global_266 = NIL; /* l_133 */
pointer global_265 = NIL; /* l_132 */
pointer global_264 = NIL; /* l_131 */
pointer global_263 = NIL; /* l_130 */
pointer global_262 = NIL; /* l_129 */
pointer global_261 = NIL; /* l_128 */
pointer global_260 = NIL; /* l_127 */
pointer global_259 = NIL; /* l_126 */
pointer global_258 = NIL; /* l_125 */
pointer global_257 = NIL; /* l_124 */
pointer global_256 = NIL; /* l_123 */
pointer global_255 = NIL; /* l_122 */
pointer global_254 = NIL; /* l_121 */
pointer global_253 = NIL; /* l_120 */
pointer global_252 = NIL; /* l_119 */
pointer global_251 = NIL; /* l_118 */
pointer global_250 = NIL; /* l_117 */
pointer global_249 = NIL; /* l_116 */
pointer global_248 = NIL; /* l_115 */
pointer global_247 = NIL; /* l_114 */
pointer global_246 = NIL; /* l_113 */
pointer global_245 = NIL; /* l_112 */
pointer global_244 = NIL; /* l_111 */
pointer global_243 = NIL; /* l_110 */
pointer global_242 = NIL; /* l_109 */
pointer global_241 = NIL; /* l_108 */
pointer global_240 = NIL; /* l_107 */
pointer global_95 = NIL; /* _print-num */
pointer global_239 = NIL; /* l_106 */
pointer global_238 = NIL; /* l_105 */
pointer global_237 = NIL; /* l_104 */
pointer global_234 = NIL; /* _build-num-str */
pointer global_231 = NIL; /* _read-expr */
pointer global_230 = NIL; /* l_103 */
pointer global_229 = NIL; /* l_102 */
pointer global_228 = NIL; /* _parse-expr */
pointer global_227 = NIL; /* _parse-pair */
pointer global_226 = NIL; /* _parse-paren */
pointer global_225 = NIL; /* _comment */
pointer global_224 = NIL; /* _unquote-parser */
pointer global_223 = NIL; /* _quasiquote-parser */
pointer global_222 = NIL; /* _quote-parser */
pointer global_221 = NIL; /* _parse-string */
pointer global_220 = NIL; /* _read-symbol */
pointer global_219 = NIL; /* _parse-symbol */
pointer global_218 = NIL; /* _read-num */
pointer global_217 = NIL; /* _parse-num */
pointer global_216 = NIL; /* _first */
pointer global_215 = NIL; /* _skip */
pointer global_213 = NIL; /* _interval */
pointer global_211 = NIL; /* _peek */
pointer global_210 = NIL; /* _use */
pointer global_209 = NIL; /* _escape */
pointer global_206 = NIL; /* _seq */
pointer global_205 = NIL; /* _post-process */
pointer global_203 = NIL; /* _choice */
pointer global_201 = NIL; /* _case */
pointer global_198 = NIL; /* _default */
pointer global_197 = NIL; /* _match */
pointer global_195 = NIL; /* _check */
pointer global_194 = NIL; /* _pop */
pointer global_193 = NIL; /* l_101 */
pointer global_192 = NIL; /* _done */
pointer global_190 = NIL; /* _fail */
pointer global_188 = NIL; /* _lookup-symbol */
pointer global_187 = NIL; /* l_100 */
pointer global_186 = NIL; /* l_99 */
pointer global_185 = NIL; /* l_98 */
pointer global_184 = NIL; /* l_97 */
pointer global_183 = NIL; /* l_96 */
pointer global_182 = NIL; /* l_95 */
pointer global_181 = NIL; /* l_94 */
pointer global_180 = NIL; /* l_93 */
pointer global_179 = NIL; /* l_92 */
pointer global_178 = NIL; /* l_91 */
pointer global_177 = NIL; /* l_90 */
pointer global_176 = NIL; /* l_89 */
pointer global_175 = NIL; /* l_88 */
pointer global_174 = NIL; /* l_87 */
pointer global_173 = NIL; /* l_86 */
pointer global_172 = NIL; /* l_85 */
pointer global_171 = NIL; /* l_84 */
pointer global_170 = NIL; /* l_83 */
pointer global_169 = NIL; /* l_82 */
pointer global_168 = NIL; /* l_81 */
pointer global_167 = NIL; /* l_80 */
pointer global_166 = NIL; /* l_79 */
pointer global_165 = NIL; /* l_78 */
pointer global_164 = NIL; /* l_77 */
pointer global_163 = NIL; /* l_76 */
pointer global_162 = NIL; /* l_75 */
pointer global_161 = NIL; /* l_74 */
pointer global_160 = NIL; /* l_73 */
pointer global_159 = NIL; /* l_72 */
pointer global_158 = NIL; /* l_71 */
pointer global_157 = NIL; /* l_70 */
pointer global_156 = NIL; /* l_69 */
pointer global_155 = NIL; /* l_68 */
pointer global_154 = NIL; /* l_67 */
pointer global_153 = NIL; /* l_66 */
pointer global_152 = NIL; /* l_65 */
pointer global_151 = NIL; /* l_64 */
pointer global_150 = NIL; /* l_63 */
pointer global_149 = NIL; /* l_62 */
pointer global_148 = NIL; /* l_61 */
pointer global_147 = NIL; /* l_60 */
pointer global_146 = NIL; /* l_59 */
pointer global_145 = NIL; /* l_58 */
pointer global_144 = NIL; /* l_57 */
pointer global_143 = NIL; /* l_56 */
pointer global_142 = NIL; /* l_55 */
pointer global_141 = NIL; /* l_54 */
pointer global_140 = NIL; /* l_53 */
pointer global_139 = NIL; /* l_52 */
pointer global_138 = NIL; /* l_51 */
pointer global_137 = NIL; /* l_50 */
pointer global_136 = NIL; /* l_49 */
pointer global_135 = NIL; /* l_48 */
pointer global_134 = NIL; /* l_47 */
pointer global_133 = NIL; /* l_46 */
pointer global_132 = NIL; /* l_45 */
pointer global_131 = NIL; /* l_44 */
pointer global_130 = NIL; /* l_43 */
pointer global_129 = NIL; /* _unquote-value */
pointer global_128 = NIL; /* l_42 */
pointer global_127 = NIL; /* _quasiquote-value */
pointer global_126 = NIL; /* l_41 */
pointer global_124 = NIL; /* _quote-value */
pointer global_123 = NIL; /* l_40 */
pointer global_122 = NIL; /* _drop-second */
pointer global_120 = NIL; /* _drop-first */
pointer global_116 = NIL; /* _build-num */
pointer global_114 = NIL; /* _escape-char */
pointer global_113 = NIL; /* _build-symbol->string */
pointer global_112 = NIL; /* l_39 */
pointer global_111 = NIL; /* l_38 */
pointer global_110 = NIL; /* l_37 */
pointer global_109 = NIL; /* l_36 */
pointer global_108 = NIL; /* l_35 */
pointer global_107 = NIL; /* l_34 */
pointer global_106 = NIL; /* _build-symbol->string-cases */
pointer global_105 = NIL; /* l_33 */
pointer global_104 = NIL; /* l_32 */
pointer global_103 = NIL; /* l_31 */
pointer global_102 = NIL; /* l_30 */
pointer global_101 = NIL; /* l_29 */
pointer global_100 = NIL; /* _build-string->symbol */
pointer global_99 = NIL; /* l_28 */
pointer global_98 = NIL; /* l_27 */
pointer global_97 = NIL; /* l_26 */
pointer global_96 = NIL; /* l_25 */
pointer global_91 = NIL; /* _build-string->symbol-cases */
pointer global_90 = NIL; /* l_24 */
pointer global_89 = NIL; /* l_23 */
pointer global_88 = NIL; /* l_22 */
pointer global_87 = NIL; /* l_21 */
pointer global_86 = NIL; /* l_20 */
pointer global_83 = NIL; /* _symbol-present? */
pointer global_82 = NIL; /* l_19 */
pointer global_81 = NIL; /* l_18 */
pointer global_79 = NIL; /* _get-symbol */
pointer global_74 = NIL; /* _lookup */
pointer global_73 = NIL; /* _symbol->string */
pointer global_71 = NIL; /* _symbol->id */
pointer global_69 = NIL; /* _make-symbol */
pointer global_67 = NIL; /* _print-error */
pointer global_66 = NIL; /* l_17 */
pointer global_65 = NIL; /* l_16 */
pointer global_62 = NIL; /* _map-to-stderr */
pointer global_58 = NIL; /* _contains */
pointer global_57 = NIL; /* l_15 */
pointer global_56 = NIL; /* _not */
pointer global_55 = NIL; /* l_14 */
pointer global_54 = NIL; /* l_13 */
pointer global_53 = NIL; /* _and */
pointer global_51 = NIL; /* l_12 */
pointer global_50 = NIL; /* l_11 */
pointer global_47 = NIL; /* _or */
pointer global_46 = NIL; /* l_10 */
pointer global_45 = NIL; /* _map */
pointer global_44 = NIL; /* l_9 */
pointer global_42 = NIL; /* _equal */
pointer global_41 = NIL; /* l_8 */
pointer global_40 = NIL; /* l_7 */
pointer global_38 = NIL; /* _append */
pointer global_37 = NIL; /* l_6 */
pointer global_36 = NIL; /* l_5 */
pointer global_35 = NIL; /* _foldr */
pointer global_34 = NIL; /* l_4 */
pointer global_32 = NIL; /* _foldl */
pointer global_31 = NIL; /* _reverse */
pointer global_30 = NIL; /* l_3 */
pointer global_27 = NIL; /* _rreverse */
pointer global_20 = NIL; /* _walk */
pointer global_18 = NIL; /* _recurse */
pointer global_16 = NIL; /* _apply */
pointer global_14 = NIL; /* _list */
pointer global_13 = NIL; /* _id */
pointer global_12 = NIL; /* _caddr */
pointer global_11 = NIL; /* _cadar */
pointer global_10 = NIL; /* _caadr */
pointer global_9 = NIL; /* _caaar */
pointer global_8 = NIL; /* _cddr */
pointer global_7 = NIL; /* _cadr */
pointer global_6 = NIL; /* _cdar */
pointer global_4 = NIL; /* _caar */

void function_1() {
  args = cons(val, args);
  increment_count(val = global_231); /* _read-expr */
  top_level_apply();
}
void function_2() {
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_353); /* l_2 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_352); /* l_1 */
  args = cons(val, args);
  increment_count(val = global_348); /* _compile-source */
  apply((&function_1));
}
void function_3() {
  args = cons(val, args);
  increment_count(val = global_343); /* _compile */
  top_level_apply();
}
void function_4() {
  args = cons(val, args);
  increment_count(val = global_231); /* _read-expr */
  top_level_apply();
}
void function_5() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_347); /* l_205 */
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
    increment_count(val = global_348); /* _compile-source */
    apply((&function_4));
  }
}
void function_6() {
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
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
  increment_count(val = global_47); /* _or */
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
  increment_count(val = global_7); /* _cadr */
  apply((&function_7));
}
void function_9() {
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
    increment_count(val = global_10); /* _caadr */
    apply((&function_8));
  }
}
void function_10() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_345); /* l_203 */
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
    increment_count(val = global_346); /* l_204 */
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
    apply((&function_9));
  }
}
void function_11() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_56); /* _not */
  apply((&function_10));
}
void function_12() {
  increment_count(env);
  val = new_function((&function_11), env);
  pop_function();
}
void function_13() {
  args = cons(val, args);
  increment_count(val = global_331); /* l_191 */
  args = cons(val, args);
  increment_count(val = global_330); /* l_190 */
  args = cons(val, args);
  increment_count(val = global_329); /* l_189 */
  args = cons(val, args);
  increment_count(val = global_328); /* l_188 */
  args = cons(val, args);
  increment_count(val = global_327); /* l_187 */
  args = cons(val, args);
  increment_count(val = global_326); /* l_186 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_14() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_113); /* _build-symbol->string */
  apply((&function_13));
}
void function_15() {
  args = cons(val, args);
  increment_count(val = global_342); /* l_202 */
  args = cons(val, args);
  increment_count(val = global_341); /* l_201 */
  args = cons(val, args);
  increment_count(val = global_340); /* l_200 */
  args = cons(val, args);
  increment_count(val = global_339); /* l_199 */
  args = cons(val, args);
  increment_count(val = global_338); /* l_198 */
  args = cons(val, args);
  increment_count(val = global_337); /* l_197 */
  args = cons(val, args);
  increment_count(val = global_336); /* l_196 */
  args = cons(val, args);
  increment_count(val = global_335); /* l_195 */
  args = cons(val, args);
  increment_count(val = global_334); /* l_194 */
  args = cons(val, args);
  increment_count(val = global_333); /* l_193 */
  args = cons(val, args);
  increment_count(val = global_332); /* l_192 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_100); /* _build-string->symbol */
  apply((&function_14));
}
void function_16() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_15));
}
void function_17() {
  args = cons(val, args);
  increment_count(val = global_312); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_16));
}
void function_18() {
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
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_322); /* _escape-symbols */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_17));
}
void function_19() {
  args = cons(val, args);
  increment_count(val = global_312); /* _print-with-newline */
  apply((&function_18));
}
void function_20() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_21() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  apply((&function_20));
}
void function_22() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_312); /* _print-with-newline */
  args = cons(val, args);
  increment_count(val = global_45); /* _map */
  apply((&function_21));
}
void function_23() {
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
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_322); /* _escape-symbols */
    apply((&function_19));
  } else {
    push_args();
    val = NIL;
    args = val;
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(car(env))));
    args = cons(val, args);
    increment_count(val = global_312); /* _print-with-newline */
    apply((&function_22));
  }
}
void function_24() {
  args = cons(val, args);
  increment_count(val = global_47); /* _or */
  apply((&function_23));
}
void function_25() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_323); /* l_183 */
  args = cons(val, args);
  increment_count(val = global_83); /* _symbol-present? */
  apply((&function_24));
}
void function_26() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_324); /* l_184 */
  args = cons(val, args);
  increment_count(val = global_83); /* _symbol-present? */
  apply((&function_25));
}
void function_27() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_325); /* l_185 */
  args = cons(val, args);
  increment_count(val = global_83); /* _symbol-present? */
  apply((&function_26));
}
void function_28() {
  args = cons(val, args);
  increment_count(val = global_69); /* _make-symbol */
  top_level_apply();
}
void function_29() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_71); /* _symbol->id */
  apply((&function_28));
}
void function_30() {
  args = cons(val, args);
  increment_count(val = global_315); /* l_176 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_29));
}
void function_31() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_32() {
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
  increment_count(val = global_322); /* _escape-symbols */
  apply((&function_31));
}
void function_33() {
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
    increment_count(val = global_73); /* _symbol->string */
    apply((&function_30));
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_316); /* l_177 */
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
      increment_count(val = global_318); /* l_179 */
      args = cons(val, args);
      increment_count(val = global_317); /* l_178 */
      args = cons(val, args);
      increment_count(val = global_69); /* _make-symbol */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_319); /* l_180 */
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
        increment_count(val = global_321); /* l_182 */
        args = cons(val, args);
        increment_count(val = global_320); /* l_181 */
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
          increment_count(val = global_322); /* _escape-symbols */
          apply((&function_32));
        }
      }
    }
  }
}
void function_34() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_313); /* l_175 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_307); /* _print-with-suffix */
  top_level_apply();
}
void function_35() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_311); /* l_174 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_307); /* _print-with-suffix */
  top_level_apply();
}
void function_36() {
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_37() {
  args = cons(val, args);
  increment_count(val = global_310); /* l_173 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_38() {
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
  increment_count(val = global_307); /* _print-with-suffix */
  apply((&function_37));
}
void function_39() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_308); /* l_171 */
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
    increment_count(val = global_309); /* l_172 */
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
      increment_count(val = global_299); /* _print-atom */
      apply((&function_36));
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
      increment_count(val = global_305); /* _print-tail */
      apply((&function_38));
    }
  }
}
void function_40() {
  args = cons(val, args);
  increment_count(val = global_302); /* l_168 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_41() {
  args = cons(val, args);
  increment_count(val = global_304); /* l_170 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_42() {
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
  increment_count(val = global_307); /* _print-with-suffix */
  apply((&function_41));
}
void function_43() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_300); /* l_166 */
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
    increment_count(val = global_301); /* l_167 */
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
      increment_count(val = global_303); /* l_169 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_299); /* _print-atom */
      apply((&function_40));
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
      increment_count(val = global_305); /* _print-tail */
      apply((&function_42));
    }
  }
}
void function_44() {
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
    increment_count(val = global_95); /* _print-num */
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
      increment_count(val = global_73); /* _symbol->string */
      top_level_apply();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_240); /* l_107 */
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
        increment_count(val = global_241); /* l_108 */
        pop_function();
      } else {
        push_args();
        val = NIL;
        args = val;
        increment_count(val = global_242); /* l_109 */
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
          increment_count(val = global_243); /* l_110 */
          pop_function();
        } else {
          push_args();
          val = NIL;
          args = val;
          increment_count(val = global_244); /* l_111 */
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
            increment_count(val = global_245); /* l_112 */
            pop_function();
          } else {
            push_args();
            val = NIL;
            args = val;
            increment_count(val = global_246); /* l_113 */
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
              increment_count(val = global_247); /* l_114 */
              pop_function();
            } else {
              push_args();
              val = NIL;
              args = val;
              increment_count(val = global_248); /* l_115 */
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
                increment_count(val = global_249); /* l_116 */
                pop_function();
              } else {
                push_args();
                val = NIL;
                args = val;
                increment_count(val = global_250); /* l_117 */
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
                  increment_count(val = global_251); /* l_118 */
                  pop_function();
                } else {
                  push_args();
                  val = NIL;
                  args = val;
                  increment_count(val = global_252); /* l_119 */
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
                    increment_count(val = global_253); /* l_120 */
                    pop_function();
                  } else {
                    push_args();
                    val = NIL;
                    args = val;
                    increment_count(val = global_254); /* l_121 */
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
                      increment_count(val = global_255); /* l_122 */
                      pop_function();
                    } else {
                      push_args();
                      val = NIL;
                      args = val;
                      increment_count(val = global_256); /* l_123 */
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
                        increment_count(val = global_257); /* l_124 */
                        pop_function();
                      } else {
                        push_args();
                        val = NIL;
                        args = val;
                        increment_count(val = global_258); /* l_125 */
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
                          increment_count(val = global_259); /* l_126 */
                          pop_function();
                        } else {
                          push_args();
                          val = NIL;
                          args = val;
                          increment_count(val = global_260); /* l_127 */
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
                            increment_count(val = global_261); /* l_128 */
                            pop_function();
                          } else {
                            push_args();
                            val = NIL;
                            args = val;
                            increment_count(val = global_262); /* l_129 */
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
                              increment_count(val = global_263); /* l_130 */
                              pop_function();
                            } else {
                              push_args();
                              val = NIL;
                              args = val;
                              increment_count(val = global_264); /* l_131 */
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
                                increment_count(val = global_265); /* l_132 */
                                pop_function();
                              } else {
                                push_args();
                                val = NIL;
                                args = val;
                                increment_count(val = global_266); /* l_133 */
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
                                  increment_count(val = global_267); /* l_134 */
                                  pop_function();
                                } else {
                                  push_args();
                                  val = NIL;
                                  args = val;
                                  increment_count(val = global_268); /* l_135 */
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
                                    increment_count(val = global_269); /* l_136 */
                                    pop_function();
                                  } else {
                                    push_args();
                                    val = NIL;
                                    args = val;
                                    increment_count(val = global_270); /* l_137 */
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
                                      increment_count(val = global_271); /* l_138 */
                                      pop_function();
                                    } else {
                                      push_args();
                                      val = NIL;
                                      args = val;
                                      increment_count(val = global_272); /* l_139 */
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
                                        increment_count(val = global_273); /* l_140 */
                                        pop_function();
                                      } else {
                                        push_args();
                                        val = NIL;
                                        args = val;
                                        increment_count(val = global_274); /* l_141 */
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
                                          increment_count(val = global_275); /* l_142 */
                                          pop_function();
                                        } else {
                                          push_args();
                                          val = NIL;
                                          args = val;
                                          increment_count(val = global_276); /* l_143 */
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
                                            increment_count(val = global_277); /* l_144 */
                                            pop_function();
                                          } else {
                                            push_args();
                                            val = NIL;
                                            args = val;
                                            increment_count(val = global_278); /* l_145 */
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
                                              increment_count(val = global_279); /* l_146 */
                                              pop_function();
                                            } else {
                                              push_args();
                                              val = NIL;
                                              args = val;
                                              increment_count(val = global_280); /* l_147 */
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
                                                increment_count(val = global_281); /* l_148 */
                                                pop_function();
                                              } else {
                                                push_args();
                                                val = NIL;
                                                args = val;
                                                increment_count(val = global_282); /* l_149 */
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
                                                  increment_count(val = global_283); /* l_150 */
                                                  pop_function();
                                                } else {
                                                  push_args();
                                                  val = NIL;
                                                  args = val;
                                                  increment_count(val = global_284); /* l_151 */
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
                                                    increment_count(val = global_285); /* l_152 */
                                                    pop_function();
                                                  } else {
                                                    push_args();
                                                    val = NIL;
                                                    args = val;
                                                    increment_count(val = global_286); /* l_153 */
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
                                                      increment_count(val = global_287); /* l_154 */
                                                      pop_function();
                                                    } else {
                                                      push_args();
                                                      val = NIL;
                                                      args = val;
                                                      increment_count(val = global_288); /* l_155 */
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
                                                        increment_count(val = global_289); /* l_156 */
                                                        pop_function();
                                                      } else {
                                                        push_args();
                                                        val = NIL;
                                                        args = val;
                                                        increment_count(val = global_290); /* l_157 */
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
                                                          increment_count(val = global_291); /* l_158 */
                                                          pop_function();
                                                        } else {
                                                          push_args();
                                                          val = NIL;
                                                          args = val;
                                                          increment_count(val = global_292); /* l_159 */
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
                                                            increment_count(val = global_293); /* l_160 */
                                                            pop_function();
                                                          } else {
                                                            push_args();
                                                            val = NIL;
                                                            args = val;
                                                            increment_count(val = global_294); /* l_161 */
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
                                                              increment_count(val = global_295); /* l_162 */
                                                              pop_function();
                                                            } else {
                                                              push_args();
                                                              val = NIL;
                                                              args = val;
                                                              increment_count(val = global_296); /* l_163 */
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
                                                                increment_count(val = global_297); /* l_164 */
                                                                pop_function();
                                                              } else {
                                                                increment_count(val = global_298); /* l_165 */
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
void function_45() {
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
void function_46() {
  apply((&function_45));
}
void function_47() {
  top_level_apply();
}
void function_48() {
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
    increment_count(val = global_237); /* l_104 */
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
    increment_count(val = global_234); /* _build-num-str */
    apply((&function_46));
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
      increment_count(val = global_238); /* l_105 */
      pop_function();
    } else {
      push_args();
      val = NIL;
      args = val;
      increment_count(val = global_239); /* l_106 */
      args = cons(val, args);
      push_args();
      val = NIL;
      args = val;
      increment_count(val = car(car(env)));
      args = cons(val, args);
      increment_count(val = global_234); /* _build-num-str */
      apply((&function_47));
    }
  }
}
void function_49() {
  top_level_apply();
}
void function_50() {
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
void function_51() {
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
void function_52() {
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
void function_53() {
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
void function_54() {
  increment_count(env);
  val = new_function((&function_53), env);
  pop_function();
}
void function_55() {
  increment_count(val = global_13); /* _id */
  pop_function();
}
void function_56() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_55), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_54), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_52), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_51), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_50), env);
  args = cons(val, args);
  increment_count(val = global_20); /* _walk */
  apply((&function_49));
}
void function_57() {
  args = cons(val, args);
  increment_count(val = global_67); /* _print-error */
  top_level_apply();
}
void function_58() {
  args = cons(val, args);
  increment_count(val = global_229); /* l_102 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  apply((&function_57));
}
void function_59() {
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_230); /* l_103 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  args = cons(val, args);
  increment_count(val = global_95); /* _print-num */
  apply((&function_58));
}
void function_60() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_59), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_228); /* _parse-expr */
  top_level_apply();
}
void function_61() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_62() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_61));
}
void function_63() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_62));
}
void function_64() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_213); /* _interval */
  apply((&function_63));
}
void function_65() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_64));
}
void function_66() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_65));
}
void function_67() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_221); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_222); /* _quote-parser */
  apply((&function_66));
}
void function_68() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_67));
}
void function_69() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(39);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_68));
}
void function_70() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_222); /* _quote-parser */
  apply((&function_69));
}
void function_71() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_70));
}
void function_72() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(96);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_71));
}
void function_73() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_223); /* _quasiquote-parser */
  apply((&function_72));
}
void function_74() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_73));
}
void function_75() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(44);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_74));
}
void function_76() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_224); /* _unquote-parser */
  apply((&function_75));
}
void function_77() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_76));
}
void function_78() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_227); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(40);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_77));
}
void function_79() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_78));
}
void function_80() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_190); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_79));
}
void function_81() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_80));
}
void function_82() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_190); /* _fail */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_81));
}
void function_83() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_82));
}
void function_84() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_83));
}
void function_85() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_225); /* _comment */
  apply((&function_84));
}
void function_86() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_85));
}
void function_87() {
  args = cons(val, args);
  increment_count(val = global_211); /* _peek */
  apply((&function_86));
}
void function_88() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_218); /* _read-num */
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
  increment_count(val = global_213); /* _interval */
  apply((&function_87));
}
void function_89() {
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
  increment_count(val = global_220); /* _read-symbol */
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_88));
}
void function_90() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_91() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_90));
}
void function_92() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_91));
}
void function_93() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_227); /* _parse-pair */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_213); /* _interval */
  apply((&function_92));
}
void function_94() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_93));
}
void function_95() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_94));
}
void function_96() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_227); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_225); /* _comment */
  apply((&function_95));
}
void function_97() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_96));
}
void function_98() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_97));
}
void function_99() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_98));
}
void function_100() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_99));
}
void function_101() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_226); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_216); /* _first */
  apply((&function_100));
}
void function_102() {
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_101));
}
void function_103() {
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
  increment_count(val = global_227); /* _parse-pair */
  args = cons(val, args);
  increment_count(val = global_228); /* _parse-expr */
  args = cons(val, args);
  increment_count(val = global_206); /* _seq */
  apply((&function_102));
}
void function_104() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_105() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_104));
}
void function_106() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_105));
}
void function_107() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_226); /* _parse-paren */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(1);
  args = cons(val, args);
  increment_count(val = global_213); /* _interval */
  apply((&function_106));
}
void function_108() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_107));
}
void function_109() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_108));
}
void function_110() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_226); /* _parse-paren */
  args = cons(val, args);
  increment_count(val = global_225); /* _comment */
  apply((&function_109));
}
void function_111() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_110));
}
void function_112() {
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
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(41);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_111));
}
void function_113() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_114() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_113));
}
void function_115() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_114));
}
void function_116() {
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
  increment_count(val = global_197); /* _match */
  apply((&function_115));
}
void function_117() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_116));
}
void function_118() {
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
  increment_count(val = global_197); /* _match */
  apply((&function_117));
}
void function_119() {
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_118));
}
void function_120() {
  args = cons(val, args);
  increment_count(val = global_215); /* _skip */
  apply((&function_119));
}
void function_121() {
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
  increment_count(val = global_225); /* _comment */
  apply((&function_120));
}
void function_122() {
  increment_count(env);
  val = new_function((&function_121), env);
  pop_function();
}
void function_123() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_129); /* _unquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  top_level_apply();
}
void function_124() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_127); /* _quasiquote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  top_level_apply();
}
void function_125() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_124); /* _quote-value */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  top_level_apply();
}
void function_126() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_127() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_126));
}
void function_128() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_127));
}
void function_129() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(34);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_128));
}
void function_130() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_129));
}
void function_131() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(92);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_130));
}
void function_132() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_221); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_209); /* _escape */
  apply((&function_131));
}
void function_133() {
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_132));
}
void function_134() {
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
  increment_count(val = global_221); /* _parse-string */
  args = cons(val, args);
  increment_count(val = global_210); /* _use */
  apply((&function_133));
}
void function_135() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_136() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_188); /* _lookup-symbol */
  args = cons(val, args);
  increment_count(val = global_219); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  apply((&function_135));
}
void function_137() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_138() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_137));
}
void function_139() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_138));
}
void function_140() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = global_213); /* _interval */
  apply((&function_139));
}
void function_141() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_140));
}
void function_142() {
  args = cons(val, args);
  increment_count(val = global_211); /* _peek */
  apply((&function_141));
}
void function_143() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
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
  increment_count(val = global_213); /* _interval */
  apply((&function_142));
}
void function_144() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_143));
}
void function_145() {
  args = cons(val, args);
  increment_count(val = global_211); /* _peek */
  apply((&function_144));
}
void function_146() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(46);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_145));
}
void function_147() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_146));
}
void function_148() {
  args = cons(val, args);
  increment_count(val = global_211); /* _peek */
  apply((&function_147));
}
void function_149() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  val = new_number(59);
  args = cons(val, args);
  increment_count(val = global_197); /* _match */
  apply((&function_148));
}
void function_150() {
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_149));
}
void function_151() {
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
  increment_count(val = global_219); /* _parse-symbol */
  args = cons(val, args);
  increment_count(val = global_210); /* _use */
  apply((&function_150));
}
void function_152() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_153() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_116); /* _build-num */
  args = cons(val, args);
  increment_count(val = global_217); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  apply((&function_152));
}
void function_154() {
  args = cons(val, args);
  increment_count(val = global_16); /* _apply */
  top_level_apply();
}
void function_155() {
  args = cons(val, args);
  increment_count(val = global_203); /* _choice */
  apply((&function_154));
}
void function_156() {
  args = cons(val, args);
  increment_count(val = global_201); /* _case */
  apply((&function_155));
}
void function_157() {
  args = cons(val, args);
  increment_count(val = global_211); /* _peek */
  apply((&function_156));
}
void function_158() {
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
  increment_count(val = global_213); /* _interval */
  apply((&function_157));
}
void function_159() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_217); /* _parse-num */
  args = cons(val, args);
  increment_count(val = global_210); /* _use */
  apply((&function_158));
}
void function_160() {
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
  increment_count(val = global_192); /* _done */
  args = cons(val, args);
  increment_count(val = global_198); /* _default */
  apply((&function_159));
}
void function_161() {
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  top_level_apply();
}
void function_162() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_122); /* _drop-second */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_206); /* _seq */
  apply((&function_161));
}
void function_163() {
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  top_level_apply();
}
void function_164() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_120); /* _drop-first */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_210); /* _use */
  apply((&function_163));
}
void function_165() {
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
void function_166() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_165), env);
  args = cons(val, args);
  increment_count(val = global_195); /* _check */
  top_level_apply();
}
void function_167() {
  top_level_apply();
}
void function_168() {
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
  apply((&function_167));
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
void function_171() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_194); /* _pop */
  args = cons(val, args);
  increment_count(val = global_206); /* _seq */
  top_level_apply();
}
void function_172() {
  args = cons(val, args);
  increment_count(val = global_206); /* _seq */
  top_level_apply();
}
void function_173() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_114); /* _escape-char */
  args = cons(val, args);
  increment_count(val = global_194); /* _pop */
  args = cons(val, args);
  increment_count(val = global_205); /* _post-process */
  apply((&function_172));
}
void function_174() {
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
void function_175() {
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
  val = new_function((&function_174), env);
  args = cons(val, args);
  increment_count(val = car(cdr(car(cdr(cdr(env))))));
  top_level_apply();
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
void function_178() {
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
void function_179() {
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
  val = new_function((&function_178), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_180() {
  increment_count(env);
  val = new_function((&function_179), env);
  pop_function();
}
void function_181() {
  top_level_apply();
}
void function_182() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_183() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(env));
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_190); /* _fail */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_182), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_181));
}
void function_184() {
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
void function_185() {
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
void function_186() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(cdr(car(env))))));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_185), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_184), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  top_level_apply();
}
void function_187() {
  increment_count(env);
  val = new_function((&function_186), env);
  pop_function();
}
void function_188() {
  increment_count(env);
  val = new_function((&function_187), env);
  pop_function();
}
void function_189() {
  increment_count(val = car(car(cdr(env))));
  pop_function();
}
void function_190() {
  increment_count(env);
  val = new_function((&function_189), env);
  pop_function();
}
void function_191() {
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
void function_192() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_191), env);
  args = cons(val, args);
  increment_count(val = global_195); /* _check */
  top_level_apply();
}
void function_193() {
  top_level_apply();
}
void function_194() {
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
    apply((&function_193));
  }
}
void function_195() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(cdr(env)))));
  apply((&function_194));
}
void function_196() {
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
  val = new_function((&function_195), env);
  args = cons(val, args);
  increment_count(val = global_194); /* _pop */
  top_level_apply();
}
void function_197() {
  increment_count(env);
  val = new_function((&function_196), env);
  pop_function();
}
void function_198() {
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
void function_199() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_193); /* l_101 */
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
    increment_count(val = global_194); /* _pop */
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
    apply((&function_198));
  }
}
void function_200() {
  increment_count(env);
  val = new_function((&function_199), env);
  pop_function();
}
void function_201() {
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
void function_202() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_203() {
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
void function_204() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_187); /* l_100 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(env);
    val = new_function((&function_203), env);
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_79); /* _get-symbol */
    top_level_apply();
  }
}
void function_205() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_185); /* l_98 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_186); /* l_99 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_204));
  }
}
void function_206() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_183); /* l_96 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_184); /* l_97 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_205));
  }
}
void function_207() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_181); /* l_94 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_182); /* l_95 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_206));
  }
}
void function_208() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_179); /* l_92 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_180); /* l_93 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_207));
  }
}
void function_209() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_177); /* l_90 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_178); /* l_91 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_208));
  }
}
void function_210() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_175); /* l_88 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_176); /* l_89 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_209));
  }
}
void function_211() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_173); /* l_86 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_174); /* l_87 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_210));
  }
}
void function_212() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_171); /* l_84 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_172); /* l_85 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_211));
  }
}
void function_213() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_169); /* l_82 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_170); /* l_83 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_212));
  }
}
void function_214() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_167); /* l_80 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_168); /* l_81 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_213));
  }
}
void function_215() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_165); /* l_78 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_166); /* l_79 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_214));
  }
}
void function_216() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_163); /* l_76 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_164); /* l_77 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_215));
  }
}
void function_217() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_161); /* l_74 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_162); /* l_75 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_216));
  }
}
void function_218() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_159); /* l_72 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_160); /* l_73 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_217));
  }
}
void function_219() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_157); /* l_70 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_158); /* l_71 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_218));
  }
}
void function_220() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_155); /* l_68 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_156); /* l_69 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_219));
  }
}
void function_221() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_153); /* l_66 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_154); /* l_67 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_220));
  }
}
void function_222() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_151); /* l_64 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_152); /* l_65 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_221));
  }
}
void function_223() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_149); /* l_62 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_150); /* l_63 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_222));
  }
}
void function_224() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_147); /* l_60 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_148); /* l_61 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_223));
  }
}
void function_225() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_145); /* l_58 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_146); /* l_59 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_224));
  }
}
void function_226() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_143); /* l_56 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_144); /* l_57 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_225));
  }
}
void function_227() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_141); /* l_54 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_142); /* l_55 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_226));
  }
}
void function_228() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_139); /* l_52 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_140); /* l_53 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_227));
  }
}
void function_229() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_137); /* l_50 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_138); /* l_51 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_228));
  }
}
void function_230() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_135); /* l_48 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_136); /* l_49 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_229));
  }
}
void function_231() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_133); /* l_46 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_134); /* l_47 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_230));
  }
}
void function_232() {
  if (val != NIL) {
    decrement_count(val);
    push_args();
    val = NIL;
    args = val;
    increment_count(val = car(cdr(cdr(cdr(car(env))))));
    args = cons(val, args);
    increment_count(val = car(cdr(cdr(car(env)))));
    args = cons(val, args);
    increment_count(val = global_131); /* l_44 */
    args = cons(val, args);
    increment_count(val = car(cdr(car(env))));
    top_level_apply();
  } else {
    push_args();
    val = NIL;
    args = val;
    increment_count(val = global_132); /* l_45 */
    args = cons(val, args);
    increment_count(val = car(car(env)));
    args = cons(val, args);
    increment_count(val = global_42); /* _equal */
    apply((&function_231));
  }
}
void function_233() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_130); /* l_43 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_232));
}
void function_234() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_235() {
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
  increment_count(val = global_128); /* l_42 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_234));
}
void function_236() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_237() {
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
  increment_count(val = global_126); /* l_41 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_236));
}
void function_238() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_239() {
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
  increment_count(val = global_123); /* l_40 */
  args = cons(val, args);
  increment_count(val = global_14); /* _list */
  apply((&function_238));
}
void function_240() {
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
void function_241() {
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
void function_242() {
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  top_level_apply();
}
void function_243() {
  apply((&function_242));
}
void function_244() {
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
void function_245() {
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
  val = new_function((&function_244), env);
  args = cons(val, args);
  increment_count(val = global_32); /* _foldl */
  apply((&function_243));
}
void function_246() {
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
void function_247() {
  args = cons(val, args);
  increment_count(val = global_109); /* l_36 */
  args = cons(val, args);
  increment_count(val = global_108); /* l_35 */
  args = cons(val, args);
  increment_count(val = global_107); /* l_34 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_248() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_112); /* l_39 */
  args = cons(val, args);
  increment_count(val = global_111); /* l_38 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_110); /* l_37 */
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_106); /* _build-symbol->string-cases */
  apply((&function_247));
}
void function_249() {
  args = cons(val, args);
  increment_count(val = global_102); /* l_30 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_250() {
  args = cons(val, args);
  increment_count(val = global_104); /* l_32 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_103); /* l_31 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_95); /* _print-num */
  apply((&function_249));
}
void function_251() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_105); /* l_33 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_4); /* _caar */
  apply((&function_250));
}
void function_252() {
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
    increment_count(val = global_101); /* l_29 */
    pop_function();
  } else {
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
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_106); /* _build-symbol->string-cases */
    apply((&function_251));
  }
}
void function_253() {
  args = cons(val, args);
  increment_count(val = global_97); /* l_26 */
  args = cons(val, args);
  increment_count(val = global_96); /* l_25 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_254() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_99); /* l_28 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = global_98); /* l_27 */
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_91); /* _build-string->symbol-cases */
  apply((&function_253));
}
void function_255() {
  args = cons(val, args);
  increment_count(val = global_87); /* l_21 */
  args = cons(val, args);
  increment_count(val = global_38); /* _append */
  top_level_apply();
}
void function_256() {
  args = cons(val, args);
  increment_count(val = global_89); /* l_23 */
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_88); /* l_22 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_4); /* _caar */
  apply((&function_255));
}
void function_257() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(env)))));
  args = cons(val, args);
  increment_count(val = global_90); /* l_24 */
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = global_95); /* _print-num */
  apply((&function_256));
}
void function_258() {
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
    increment_count(val = global_86); /* l_20 */
    pop_function();
  } else {
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
    if (length(args) == 1) {
      if (! is_atom(car(args))) {
      increment_count(val = cdr(car(args)));
      } else { val = NIL; }
    } else { val = NIL; }
    pop_args();
    args = cons(val, args);
    increment_count(val = global_91); /* _build-string->symbol-cases */
    apply((&function_257));
  }
}
void function_259() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_82); /* l_19 */
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
    increment_count(val = global_83); /* _symbol-present? */
    top_level_apply();
  }
}
void function_260() {
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_259));
}
void function_261() {
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
    increment_count(val = global_81); /* l_18 */
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
    apply((&function_260));
  }
}
void function_262() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  top_level_apply();
}
void function_263() {
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
  apply((&function_262));
}
void function_264() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_263), env);
  args = cons(val, args);
  val = new_number(0);
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(cdr(car(env))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_74); /* _lookup */
  top_level_apply();
}
void function_265() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(cdr(car(env)))))));
  top_level_apply();
}
void function_266() {
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
    apply((&function_265));
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
    increment_count(val = global_74); /* _lookup */
    top_level_apply();
  }
}
void function_267() {
  args = cons(val, args);
  increment_count(val = global_42); /* _equal */
  apply((&function_266));
}
void function_268() {
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
    apply((&function_267));
  }
}
void function_269() {
  increment_count(val = car(cdr(car(env))));
  pop_function();
}
void function_270() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_269), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_271() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_272() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_271), env);
  args = cons(val, args);
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_273() {
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
void function_274() {
  increment_count(env);
  val = new_function((&function_273), env);
  pop_function();
}
void function_275() {
  args = cons(val, args);
  increment_count(val = global_62); /* _map-to-stderr */
  top_level_apply();
}
void function_276() {
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
  apply((&function_275));
}
void function_277() {
  global_62 = val;
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
  global_65 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_66 = val;
  increment_count(env);
  val = new_function((&function_276), env);
  global_67 = val;
  increment_count(env);
  val = new_function((&function_274), env);
  global_69 = val;
  increment_count(env);
  val = new_function((&function_272), env);
  global_71 = val;
  increment_count(env);
  val = new_function((&function_270), env);
  global_73 = val;
  increment_count(env);
  val = new_function((&function_268), env);
  global_74 = val;
  increment_count(env);
  val = new_function((&function_264), env);
  global_79 = val;
  val = NIL;
  global_81 = val;
  val = -86;
  global_82 = val;
  increment_count(env);
  val = new_function((&function_261), env);
  global_83 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
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
  val = new_number(32);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_86 = val;
  val = NIL;
  push_args();
  args = val;
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_87 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_88 = val;
  val = NIL;
  push_args();
  args = val;
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
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_89 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_90 = val;
  increment_count(env);
  val = new_function((&function_258), env);
  global_91 = val;
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
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
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
  global_96 = val;
  val = NIL;
  push_args();
  args = val;
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_97 = val;
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
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_98 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_99 = val;
  increment_count(env);
  val = new_function((&function_254), env);
  global_100 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(34);
  args = cons(val, args);
  val = new_number(62);
  args = cons(val, args);
  val = new_number(76);
  args = cons(val, args);
  val = new_number(79);
  args = cons(val, args);
  val = new_number(66);
  args = cons(val, args);
  val = new_number(77);
  args = cons(val, args);
  val = new_number(89);
  args = cons(val, args);
  val = new_number(83);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(87);
  args = cons(val, args);
  val = new_number(79);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(75);
  args = cons(val, args);
  val = new_number(78);
  args = cons(val, args);
  val = new_number(85);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(58);
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
  val = new_number(34);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_101 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = new_number(100);
  args = cons(val, args);
  val = new_number(105);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(61);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_102 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_103 = val;
  val = NIL;
  push_args();
  args = val;
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_104 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_105 = val;
  increment_count(env);
  val = new_function((&function_252), env);
  global_106 = val;
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
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
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
  global_107 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_108 = val;
  val = NIL;
  push_args();
  args = val;
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
  val = args;
  args = NIL;
  pop_args();
  global_109 = val;
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
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_110 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_111 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(41);
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
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
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
  val = args;
  args = NIL;
  pop_args();
  global_112 = val;
  increment_count(env);
  val = new_function((&function_248), env);
  global_113 = val;
  increment_count(env);
  val = new_function((&function_246), env);
  global_114 = val;
  increment_count(env);
  val = new_function((&function_245), env);
  global_116 = val;
  increment_count(env);
  val = new_function((&function_241), env);
  global_120 = val;
  increment_count(env);
  val = new_function((&function_240), env);
  global_122 = val;
  val = QUOTE;
  global_123 = val;
  increment_count(env);
  val = new_function((&function_239), env);
  global_124 = val;
  val = QUASIQUOTE;
  global_126 = val;
  increment_count(env);
  val = new_function((&function_237), env);
  global_127 = val;
  val = UNQUOTE;
  global_128 = val;
  increment_count(env);
  val = new_function((&function_235), env);
  global_129 = val;
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
  global_130 = val;
  val = COND;
  global_131 = val;
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
  global_132 = val;
  val = IF;
  global_133 = val;
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
  global_134 = val;
  val = LET;
  global_135 = val;
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
  global_136 = val;
  val = FN;
  global_137 = val;
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
  global_138 = val;
  val = QUOTE;
  global_139 = val;
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
  global_140 = val;
  val = QUASIQUOTE;
  global_141 = val;
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
  global_142 = val;
  val = UNQUOTE;
  global_143 = val;
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
  global_144 = val;
  val = CONS;
  global_145 = val;
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
  global_146 = val;
  val = CAR;
  global_147 = val;
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
  global_148 = val;
  val = CDR;
  global_149 = val;
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
  global_150 = val;
  val = ATOM;
  global_151 = val;
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
  global_152 = val;
  val = NUMBER;
  global_153 = val;
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
  global_154 = val;
  val = FUNCTION;
  global_155 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_156 = val;
  val = EQ;
  global_157 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_158 = val;
  val = LT;
  global_159 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_160 = val;
  val = GT;
  global_161 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_162 = val;
  val = PLUS;
  global_163 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_164 = val;
  val = MINUS;
  global_165 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_166 = val;
  val = MULT;
  global_167 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_168 = val;
  val = DIV;
  global_169 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_170 = val;
  val = MOD;
  global_171 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_172 = val;
  val = BNEG;
  global_173 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_174 = val;
  val = BAND;
  global_175 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_176 = val;
  val = BOR;
  global_177 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_178 = val;
  val = BXOR;
  global_179 = val;
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
  global_180 = val;
  val = SRSHIFT;
  global_181 = val;
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
  global_182 = val;
  val = URSHIFT;
  global_183 = val;
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
  global_184 = val;
  val = LSHIFT;
  global_185 = val;
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
  global_186 = val;
  val = DEFINE;
  global_187 = val;
  increment_count(env);
  val = new_function((&function_233), env);
  global_188 = val;
  increment_count(env);
  val = new_function((&function_202), env);
  global_190 = val;
  increment_count(env);
  val = new_function((&function_201), env);
  global_192 = val;
  val = NIL;
  global_193 = val;
  increment_count(env);
  val = new_function((&function_200), env);
  global_194 = val;
  increment_count(env);
  val = new_function((&function_197), env);
  global_195 = val;
  increment_count(env);
  val = new_function((&function_192), env);
  global_197 = val;
  increment_count(env);
  val = new_function((&function_190), env);
  global_198 = val;
  increment_count(env);
  val = new_function((&function_188), env);
  global_201 = val;
  increment_count(env);
  val = new_function((&function_183), env);
  global_203 = val;
  increment_count(env);
  val = new_function((&function_180), env);
  global_205 = val;
  increment_count(env);
  val = new_function((&function_177), env);
  global_206 = val;
  increment_count(env);
  val = new_function((&function_173), env);
  global_209 = val;
  increment_count(env);
  val = new_function((&function_171), env);
  global_210 = val;
  increment_count(env);
  val = new_function((&function_170), env);
  global_211 = val;
  increment_count(env);
  val = new_function((&function_166), env);
  global_213 = val;
  increment_count(env);
  val = new_function((&function_164), env);
  global_215 = val;
  increment_count(env);
  val = new_function((&function_162), env);
  global_216 = val;
  increment_count(env);
  val = new_function((&function_160), env);
  global_217 = val;
  increment_count(env);
  val = new_function((&function_153), env);
  global_218 = val;
  increment_count(env);
  val = new_function((&function_151), env);
  global_219 = val;
  increment_count(env);
  val = new_function((&function_136), env);
  global_220 = val;
  increment_count(env);
  val = new_function((&function_134), env);
  global_221 = val;
  increment_count(env);
  val = new_function((&function_125), env);
  global_222 = val;
  increment_count(env);
  val = new_function((&function_124), env);
  global_223 = val;
  increment_count(env);
  val = new_function((&function_123), env);
  global_224 = val;
  increment_count(env);
  val = new_function((&function_122), env);
  global_225 = val;
  increment_count(env);
  val = new_function((&function_112), env);
  global_226 = val;
  increment_count(env);
  val = new_function((&function_103), env);
  global_227 = val;
  increment_count(env);
  val = new_function((&function_89), env);
  global_228 = val;
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
  global_229 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_230 = val;
  increment_count(env);
  val = new_function((&function_60), env);
  global_231 = val;
  increment_count(env);
  val = new_function((&function_56), env);
  global_234 = val;
  val = NIL;
  global_237 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(48);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_238 = val;
  val = NIL;
  global_239 = val;
  increment_count(env);
  val = new_function((&function_48), env);
  global_95 = val;
  val = QUOTE;
  global_240 = val;
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
  global_241 = val;
  val = QUASIQUOTE;
  global_242 = val;
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
  global_243 = val;
  val = UNQUOTE;
  global_244 = val;
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
  global_245 = val;
  val = CAR;
  global_246 = val;
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
  global_247 = val;
  val = CDR;
  global_248 = val;
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
  global_249 = val;
  val = NUMBER;
  global_250 = val;
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
  global_251 = val;
  val = FUNCTION;
  global_252 = val;
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
  global_253 = val;
  val = ATOM;
  global_254 = val;
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
  global_255 = val;
  val = CONS;
  global_256 = val;
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
  global_257 = val;
  val = COND;
  global_258 = val;
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
  global_259 = val;
  val = IF;
  global_260 = val;
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
  global_261 = val;
  val = LET;
  global_262 = val;
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
  global_263 = val;
  val = FN;
  global_264 = val;
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
  global_265 = val;
  val = URSHIFT;
  global_266 = val;
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
  global_267 = val;
  val = SRSHIFT;
  global_268 = val;
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
  global_269 = val;
  val = LSHIFT;
  global_270 = val;
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
  global_271 = val;
  val = LT;
  global_272 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(60);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_273 = val;
  val = GT;
  global_274 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(62);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_275 = val;
  val = EQ;
  global_276 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(61);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_277 = val;
  val = PLUS;
  global_278 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(43);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_279 = val;
  val = MINUS;
  global_280 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(45);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_281 = val;
  val = MULT;
  global_282 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(42);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_283 = val;
  val = DIV;
  global_284 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(47);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_285 = val;
  val = MOD;
  global_286 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(37);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_287 = val;
  val = BAND;
  global_288 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(38);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_289 = val;
  val = BOR;
  global_290 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(124);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_291 = val;
  val = BXOR;
  global_292 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(94);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_293 = val;
  val = BNEG;
  global_294 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(126);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_295 = val;
  val = DEFINE;
  global_296 = val;
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
  global_297 = val;
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
  global_298 = val;
  increment_count(env);
  val = new_function((&function_44), env);
  global_299 = val;
  val = NIL;
  global_300 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_301 = val;
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
  global_302 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(41);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_303 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_304 = val;
  increment_count(env);
  val = new_function((&function_43), env);
  global_305 = val;
  val = NIL;
  global_308 = val;
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
  global_309 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(40);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_310 = val;
  increment_count(env);
  val = new_function((&function_39), env);
  global_307 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_311 = val;
  increment_count(env);
  val = new_function((&function_35), env);
  global_312 = val;
  val = NIL;
  global_313 = val;
  increment_count(env);
  val = new_function((&function_34), env);
  global_314 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(95);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_315 = val;
  val = ATOM;
  global_316 = val;
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
  global_317 = val;
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
  global_318 = val;
  val = EQ;
  global_319 = val;
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
  global_320 = val;
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
  global_321 = val;
  increment_count(env);
  val = new_function((&function_33), env);
  global_322 = val;
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
  global_323 = val;
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
  global_324 = val;
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
  global_325 = val;
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
  global_326 = val;
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_327 = val;
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
  global_328 = val;
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
  global_329 = val;
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
  val = args;
  args = NIL;
  pop_args();
  global_330 = val;
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
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
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
  global_331 = val;
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
  val = new_number(40);
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
  global_332 = val;
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_333 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
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
  global_334 = val;
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
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
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
  global_335 = val;
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
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
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
  global_336 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_337 = val;
  val = NIL;
  push_args();
  args = val;
  val = new_number(10);
  args = cons(val, args);
  val = new_number(41);
  args = cons(val, args);
  val = new_number(116);
  args = cons(val, args);
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
  global_338 = val;
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
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
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
  global_339 = val;
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
  val = new_number(95);
  args = cons(val, args);
  val = new_number(40);
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
  global_340 = val;
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
  val = new_number(40);
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
  val = new_number(40);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = new_number(32);
  args = cons(val, args);
  val = args;
  args = NIL;
  pop_args();
  global_341 = val;
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
  val = new_number(116);
  args = cons(val, args);
  val = new_number(39);
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
  global_342 = val;
  increment_count(env);
  val = new_function((&function_27), env);
  global_343 = val;
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
  global_345 = val;
  val = DEFINE;
  global_346 = val;
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
  global_347 = val;
  increment_count(env);
  val = new_function((&function_12), env);
  global_348 = val;
  val = NIL;
  global_352 = val;
  val = NIL;
  global_353 = val;
  increment_count(env);
  val = new_function((&function_2), env);
  pop_function();
}
void function_278() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_279() {
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
  apply((&function_278));
}
void function_280() {
  if (val != NIL) {
    decrement_count(val);
    increment_count(val = global_57); /* l_15 */
    pop_function();
  } else {
    increment_count(val = car(cdr(car(env))));
    pop_function();
  }
}
void function_281() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(cdr(car(cdr(env)))));
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_280));
}
void function_282() {
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_281), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  top_level_apply();
}
void function_283() {
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
void function_284() {
  top_level_apply();
}
void function_285() {
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
void function_286() {
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
  val = new_function((&function_285), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_284));
}
void function_287() {
  top_level_apply();
}
void function_288() {
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
void function_289() {
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
  val = new_function((&function_288), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_287));
}
void function_290() {
  top_level_apply();
}
void function_291() {
  args = cons(val, args);
  if (length(args) == 2) {
    increment_count(car(args));
    increment_count(car(cdr(args)));
    val = cons(car(args), car(cdr(args)));
  } else { val = NIL; }
  pop_args();
  pop_function();
}
void function_292() {
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
  apply((&function_291));
}
void function_293() {
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
  val = new_function((&function_292), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_290));
}
void function_294() {
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
void function_295() {
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
      apply((&function_294));
    }
  }
}
void function_296() {
  top_level_apply();
}
void function_297() {
  top_level_apply();
}
void function_298() {
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
    apply((&function_297));
  }
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
  increment_count(val = global_37); /* l_6 */
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_298), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_296));
}
void function_300() {
  args = cons(val, args);
  increment_count(val = global_34); /* l_4 */
  args = cons(val, args);
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = global_27); /* _rreverse */
  top_level_apply();
}
void function_301() {
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
  apply((&function_300));
}
void function_302() {
  increment_count(env);
  val = new_function((&function_301), env);
  pop_function();
}
void function_303() {
  top_level_apply();
}
void function_304() {
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = global_32); /* _foldl */
  apply((&function_303));
}
void function_305() {
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
    apply((&function_304));
  }
}
void function_306() {
  increment_count(env);
  val = new_function((&function_305), env);
  pop_function();
}
void function_307() {
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
void function_308() {
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
void function_309() {
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(cdr(car(cdr(env)))))));
  top_level_apply();
}
void function_310() {
  args = cons(val, args);
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_309));
}
void function_311() {
  apply((&function_310));
}
void function_312() {
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
  apply((&function_311));
}
void function_313() {
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
    apply((&function_312));
  }
}
void function_314() {
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(env)));
  args = cons(val, args);
  increment_count(val = car(cdr(cdr(car(cdr(env))))));
  apply((&function_313));
}
void function_315() {
  increment_count(env);
  val = new_function((&function_314), env);
  pop_function();
}
void function_316() {
  top_level_apply();
}
void function_317() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_316));
}
void function_318() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_317), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_319() {
  top_level_apply();
}
void function_320() {
  push_args();
  increment_count(val = car(env));
  args = val;
  push_args();
  val = NIL;
  args = val;
  increment_count(val = car(car(cdr(env))));
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  apply((&function_319));
}
void function_321() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_320), env);
  args = cons(val, args);
  increment_count(val = car(car(cdr(env))));
  top_level_apply();
}
void function_322() {
  push_args();
  val = NIL;
  args = val;
  increment_count(env);
  val = new_function((&function_321), env);
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_318), env);
  top_level_apply();
}
void function_323() {
  push_args();
  increment_count(val = car(cdr(car(env))));
  args = val;
  increment_count(val = car(car(env)));
  top_level_apply();
}
void function_324() {
  increment_count(val = car(env));
  pop_function();
}
void function_325() {
  increment_count(val = car(car(env)));
  pop_function();
}
void function_326() {
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
void function_327() {
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
void function_328() {
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
void function_330() {
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
void function_331() {
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
void function_332() {
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
void function_333() {
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
void function_334() {
  increment_count(env);
  val = new_function((&function_333), env);
  global_4 = val;
  increment_count(env);
  val = new_function((&function_332), env);
  global_6 = val;
  increment_count(env);
  val = new_function((&function_331), env);
  global_7 = val;
  increment_count(env);
  val = new_function((&function_330), env);
  global_8 = val;
  increment_count(env);
  val = new_function((&function_329), env);
  global_9 = val;
  increment_count(env);
  val = new_function((&function_328), env);
  global_10 = val;
  increment_count(env);
  val = new_function((&function_327), env);
  global_11 = val;
  increment_count(env);
  val = new_function((&function_326), env);
  global_12 = val;
  increment_count(env);
  val = new_function((&function_325), env);
  global_13 = val;
  increment_count(env);
  val = new_function((&function_324), env);
  global_14 = val;
  increment_count(env);
  val = new_function((&function_323), env);
  global_16 = val;
  increment_count(env);
  val = new_function((&function_322), env);
  global_18 = val;
  increment_count(env);
  val = new_function((&function_315), env);
  global_20 = val;
  increment_count(env);
  val = new_function((&function_308), env);
  global_27 = val;
  val = NIL;
  global_30 = val;
  increment_count(env);
  val = new_function((&function_307), env);
  global_31 = val;
  increment_count(env);
  val = new_function((&function_306), env);
  global_32 = val;
  val = NIL;
  global_34 = val;
  increment_count(env);
  val = new_function((&function_302), env);
  global_35 = val;
  val = NIL;
  global_36 = val;
  val = NIL;
  global_37 = val;
  increment_count(env);
  val = new_function((&function_299), env);
  global_38 = val;
  val = NIL;
  global_40 = val;
  val = NIL;
  global_41 = val;
  increment_count(env);
  val = new_function((&function_295), env);
  global_42 = val;
  val = NIL;
  global_44 = val;
  increment_count(env);
  val = new_function((&function_293), env);
  global_45 = val;
  val = NIL;
  global_46 = val;
  increment_count(env);
  val = new_function((&function_289), env);
  global_47 = val;
  val = NIL;
  global_50 = val;
  val = -86;
  global_51 = val;
  increment_count(env);
  val = new_function((&function_286), env);
  global_53 = val;
  val = NIL;
  global_54 = val;
  val = -86;
  global_55 = val;
  increment_count(env);
  val = new_function((&function_283), env);
  global_56 = val;
  val = -86;
  global_57 = val;
  increment_count(env);
  val = new_function((&function_282), env);
  global_58 = val;
  push_args();
  val = NIL;
  args = val;
  val = NIL;
  args = cons(val, args);
  increment_count(env);
  val = new_function((&function_279), env);
  args = cons(val, args);
  increment_count(val = global_35); /* _foldr */
  apply((&function_277));
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
    return_location = (&function_334);
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
  call_stack = cons(new_function((&function_0), NIL), call_stack);
  return_location = (&function_334);
  while (return_location != (&end_function)) {
    (*return_location)();
  }
  end_function();
  end_io();
}
#endif
