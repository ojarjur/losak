;; Compiler from a simple lisp-dialect to C
;;
;; The basis for this compiler is the invariant* that for each type
;; of s-expression, that s-expression is compiled into C code that
;; stores the evaluated result of the s-expression into the C global
;; variable "val", while leaving the variables "args", "stack", and
;; "call_stack" with the same values before and after computation.
;;
;; (*May be violated if the system runs out of free memory)
;;
;; The following C types must be externally defined:
;;   pointer,      //HINT: typedef long int pointer;
;;   function_addr //HINT: typedef void (*function_addr)();
;;
;; The following C globals must be externally defined:
;;   int sign_mask
;;   pointer val, args, stack, call_stack, true
;;
;; The following C functions must be defined in another file:
;;   pointer cons(pointer expr1, pointer expr2)
;;   pointer car(pointer expr)
;;   pointer cdr(pointer expr)
;;
;;   pointer new_number(int value)
;;   int value(pointer n)
;;
;;   pointer new_function(function_addr addr, pointer binding_env)
;;   function_addr addr(pointer func)
;;   pointer binding_env(pointer func)
;;
;;   void increment_count(pointer expr)
;;   void decrement_count(pointer expr)
;;
;;   int eq(pointer expr1, pointer expr2)
;;   int length(pointer expr)
;;   int is_atom(pointer expr)
;;   int is_number(pointer expr)
;;   int is_function(pointer expr)
;;
;;   pointer eval_primitive(pointer op, pointer args)
;;
;;   void end_function()

(require (lib "defmacro.ss"))
(define-macro (fn args body) `(lambda ,args ,body))
(define-macro (let bindings body) `(let* ,bindings ,body))
(define = eq?)
(define number number?)
(define function procedure?)
(define (atom expr) (not (pair? expr)))
(define (id x) x)
(define (list . args) args)
(define (recurse op)
  ((fn (this) (op (fn args (apply (this this) args))))
   (fn (this) (op (fn args (apply (this this) args))))))
(define (walk head tail test merge ret)
  (fn (tree)
      (cond ((test tree) (ret tree))
            ('t (merge (head tree)
                       ((walk head tail test merge ret)
                        (tail tree)))))))
(define (fold merge end)
  (walk car cdr atom merge (fn (val) end)))
(define (foldl merge end)
  (fn (expr)
    (((walk car cdr atom
            (fn (x op) (fn (xs) (op (merge x xs))))
            (fn (x) id))
      expr) end)))
(define (inline op) (fn args (op args)))
(define (append . args) ((fold (fn (x xs)
                                   (cond ((= xs '()) x)
                                         ('t ((fold cons xs) x))))
                               '()) args))
(define (equal x y)
        (cond ((atom x) (= x y))
              ((atom y) #f)
              ((equal (car x) (car y)) (equal (cdr x) (cdr y)))
              ('t #f)))
(define (map op list) ((fold (fn (x xs) (cons (op x) xs)) '()) list))
(define (or . args) ((fold (fn (t ts) (cond (t t) ('t ts))) #f) args))
(define (and . args) ((fold (fn (t ts) (cond (t ts) ('t #f))) 't) args))
(define (not test) (cond (test #f) ('t 't)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functions for maintaining the symbol table ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (make-symbol id str) (fn (op) (op id str)))
(define (symbol->id symbol) (symbol (fn (id str) id)))
(define (symbol->string symbol) (symbol (fn (id str) str)))
(define (lookup string curr table count return)
  (cond ((atom curr) (return count (cons (cons string count) table)))
        ((equal (caar curr) string) (return (cdar curr) table))
        ('t (lookup string (cdr curr) table (+ count 1) return))))
(define (get-symbol string table return)
  (lookup string table table 4 ;; Symbols 0-3 are reserved for the compiler
          (fn (id new-table) (return (make-symbol id string) new-table))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Helper functions for parsing ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (end_of_line chars)
  (or (atom chars)
      (= (car chars) 10)
      (= (car chars) 13)))
(define (discard_line arg) ((walk car cdr end_of_line (fn (c cs) cs) cdr) arg))

(define (escape_char char return rest symbols)
  (return (cond ((= char 116) 9)
                ((= char 114) 13)
                ((= char 110) 10)
                ('t char))
          rest symbols))
(define (build_num chars return rest symbols)
  (return ((foldl (fn (c n) (+ (* 10 n) (- c 48))) 0) chars)
          rest symbols))
(define (drop_first pair return rest symbols)
  (return (cdr pair) rest symbols))
(define (drop_second pair return rest symbols)
  (return (car pair) rest symbols))
(define (quote-value expr return rest symbols)
  (return (list 'quote expr) rest symbols))
(define (char-list-eq chars string)
  (equal? (list->string (map integer->char chars)) string))
(define (make_symbol chars return rest symbols)
  (cond ((char-list-eq chars "cond") (return 'cond rest symbols))
        ((char-list-eq chars "let") (return 'let rest symbols))
        ((char-list-eq chars "fn") (return 'fn rest symbols))
        ((char-list-eq chars "quote") (return 'quote rest symbols))
        ((char-list-eq chars "cons") (return 'cons rest symbols))
        ((char-list-eq chars "car") (return 'car rest symbols))
        ((char-list-eq chars "cdr") (return 'cdr rest symbols))
        ((char-list-eq chars "atom") (return 'atom rest symbols))
        ((char-list-eq chars "number") (return 'number rest symbols))
        ((char-list-eq chars "function") (return 'function rest symbols))
        ((char-list-eq chars "=") (return '= rest symbols))
        ((char-list-eq chars "<") (return '< rest symbols))
        ((char-list-eq chars ">") (return '> rest symbols))
        ((char-list-eq chars "+") (return '+ rest symbols))
        ((char-list-eq chars "-") (return '- rest symbols))
        ((char-list-eq chars "*") (return '* rest symbols))
        ((char-list-eq chars "/") (return '/ rest symbols))
        ((char-list-eq chars "%") (return '% rest symbols))
        ((char-list-eq chars "~") (return '~ rest symbols))
        ((char-list-eq chars "&") (return '& rest symbols))
        ((char-list-eq chars "|") (return (string->symbol "|") rest symbols))
        ((char-list-eq chars "^") (return '^ rest symbols))
        ((char-list-eq chars ">>") (return '>> rest symbols))
        ((char-list-eq chars ">>>") (return '>>> rest symbols))
        ((char-list-eq chars "<<") (return '<< rest symbols))
        ((char-list-eq chars "define") (return 'define rest symbols))
        ('t (get-symbol chars symbols
                        (fn (id new-symbols)
                          (return id rest new-symbols))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Parser combinators that simplify the process of writting an LL(1) ;;
;; grammar.                                                          ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Each parser takes a return continuation, an error continuation,   ;;
;; an input string, and a symbol table. They implement a function    ;;
;; that parses the string, and passes the tree, remaining chars, and ;;
;; new symbol table to the return, or "fails" and passes a message,  ;;
;; the remaining chars, and new symbol table to the error.           ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (fail return error input symbols) (error input symbols))
(define (done return error input symbols) (return () input symbols))
(define (check test)
  (fn (return error input symbols)
    (cond ((atom input) (error input symbols))
          ((test (car input)) (return (car input) (cdr input) symbols))
          ('t (error input symbols)))))
(define (pop return error input symbols)
  (cond ((atom input) (error input symbols))
        ('t (return (car input) (cdr input) symbols))))
(define (match char) (check (fn (val) (= val char))))
(define (default parser) (fn (else) parser))
(define (case test then)
  (fn (else)
    (fn (return error input symbols)
      (test (fn (val rest symbols) (then return error rest symbols))
            (fn (rest symbols) (else return error input symbols))
            input symbols))))
(define (choice . args) ((fold (fn (c cs) (c cs)) fail) args))
(define (post-process parser op)
  (fn (return error input symbols)
    (parser (fn (val rest symbols) (op val return rest symbols))
            error input symbols)))
(define (seq parser1 parser2)
  (fn (return error input symbols)
    (parser1 (fn (head next symbols)
               (parser2 (fn (tail rest symbols)
                          (return (cons head tail) rest symbols))
                        error next symbols))
             error input symbols)))
(define (escape parser) (seq (post-process pop escape_char) parser))
(define (use parser) (seq pop parser))
(define (peek parser)
  (fn (return error input symbols)
    (parser (fn (val rest symbols) (return val input symbols))
            error input symbols)))
(define (interval start end)
  (check (fn (val) (and (> val (- start 1)) (< val (+ end 1))))))
(define (skip parser) (post-process (use parser) drop_first))
(define (first parser1 parser2)
  (post-process (seq parser1 parser2) drop_second))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functions to parse an s-expression ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (parse-num . args)
  (apply (choice (case (peek (interval 48 57)) (use parse-num))
                 (default done))
         args))
(define (read-num . args) (apply (post-process parse-num build_num) args))
(define (parse-symbol . args)
  (apply (choice (case (match ()) done)
                 (case (peek (interval 0 32)) done)
                 (case (peek (interval 39 41)) done)
                 (case (peek (match 46)) done)
                 (case (peek (match 59)) done)
                 (default (use parse-symbol)))
         args))
(define (read-symbol . args)
  (apply (post-process parse-symbol make_symbol) args))
(define (parse-string . args)
  (apply (choice (case (match 34) done)
                 (case (match 92) (escape parse-string))
                 (default (use parse-string)))
         args))
(define (quote-parser parser) (post-process parser quote-value))
(define (comment parser)
  (recurse (fn (this) (choice (case (match 10) parser)
                              (case (match 13) parser)
                              (default (skip this))))))
(define (parse-paren . args)
  (apply (choice (case (interval 0 32) parse-paren)
                 (case (match 59) (comment parse-paren))
                 (case (match 41) done))
         args))
(define (parse-pair parser)
  (recurse (fn (this)
               (choice (case (interval 0 32) this)
                       (case (match 59) (comment this))
                       (case (match 41) done)
                       (case (match 46) (first parser parse-paren))
                       (default (seq parser this))))))
(define (parse-expr . args)
  (apply (choice (case (interval 0 32) parse-expr)
                 (case (match 34) (quote-parser parse-string))
                 (case (match 39) (quote-parser parse-expr))
                 (case (match 40) (parse-pair parse-expr))
                 (case (match 41) fail)
                 (case (match 46) fail)
                 (case (match 59) (comment parse-expr))
                 (case (peek (interval 48 57)) read-num)
                 (default read-symbol))
         args))
(define (read_expr chars cont symbol-table)
  (parse-expr cont
              (fn (rest symbols) (error "Parse error" rest))
              chars symbol-table))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functions for structuring the generated code ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (code_block . lines)
  (fn (prefix postfix)
      ((fold (fn (block postfix)
                 (cond ((function block) (block prefix postfix))
                       ((string? block)
                        (append prefix
                                (map char->integer (string->list block))
                                '(10)
                                postfix))
                       ('t (append prefix block '(10) postfix))))
             postfix)
       lines)))
(define (indent . code)
  (fn (prefix postfix)
      (let ((new-prefix (append '(32 32) prefix)))
        ((fold (fn (block postfix)
                   (cond ((function block) (block new-prefix postfix))
                         ((string? block)
                          (append new-prefix
                                  (map char->integer (string->list block))
                                  '(10)
                                  postfix))
                         ('t (append new-prefix block '(10) postfix))))
               postfix)
         code))))
(define (build_num_str n)
  (((walk (fn (n) (modulo n 10))
          (fn (n) (quotient n 10))
          (fn (n) (= n 0))
          (fn (d op) (fn (str) (op (cons (+ d 48) str))))
          (fn (x) id))
    n)
   ""))
(define (number->string num)
  (list->string (map integer->char
                     (cond ((< num 0) (cons 45 (build_num_str (- num))))
                           ((= num 0) '(48))
                           ('t (build_num_str num))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Variables for maintaining the symbol table ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile_symbol sym)
  (cond ((= sym 'cons) "CONS")
        ((= sym 'car) "CAR")
        ((= sym 'cdr) "CDR")
        ((= sym 'cond) "COND")
        ((= sym 'atom) "ATOM")
        ((= sym 'number) "NUMBER")
        ((= sym 'function) "FUNCTION")
        ((= sym 'quote) "QUOTE")
        ((= sym 'fn) "FN")
        ((= sym 'let) "LET")
        ((= sym '=) "EQ")
        ((= sym '<) "LT")
        ((= sym '>) "GT")
        ((= sym '+) "PLUS")
        ((= sym '-) "MINUS")
        ((= sym '*) "MULT")
        ((= sym '/) "DIV")
        ((= sym '%) "MOD")
        ((= sym '~) "BNEG")
        ((= sym '&) "BAND")
        ((= sym (string->symbol "|")) "BOR")
        ((= sym '^) "BXOR")
        ((= sym '>>) "SRSHIFT")
        ((= sym '>>>) "URSHIFT")
        ((= sym '<<) "LSHIFT")
        ((= sym 'define) "DEFINE")
        ((= sym '()) "NIL")
        ('t "/** Internal Error: unknown symbol */NIL")))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Function to compile compile-time data ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile_structure expr)
  (cond ((number expr)
         (string-append "val = new_number(" (number->string expr) ");"))
        ((function expr)
         (string-append "val = "
                        (number->string (- (- 30) (symbol->id expr)))
                        ";"))
        ((atom expr)
         (string-append "val = " (compile_symbol expr) ";"))
        ('t (code_block "push_args();"
                        (compile_structure (car expr))
                        "args = val;"
                        (compile_structure (cdr expr))
                        "increment_count(args);"
                        "val = cons(args, val);"
                        "pop_args();"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functions for handling primitives ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (is_primitive expr)
  (or (= expr 'car) (= expr 'cdr) (= expr 'cons) (= expr 'atom)
      (= expr 'number) (= expr 'function) (= expr '=) (= expr '<)
      (= expr '>) (= expr '+) (= expr '-) (= expr '*) (= expr '/)
      (= expr '%) (= expr '~) (= expr '&) (= expr (string->symbol "|"))
      (= expr '^) (= expr '>>) (= expr '>>>) (= expr '<<)))
(define (compile_primitive op)
  (cond ((or (= op 'car) (= op 'cdr) (= op 'atom)
             (= op 'number) (= op 'function) (= op '~))
         (code_block
          "if (length(args) == 1) {"
          (indent (cond ((= op 'atom)
                         (code_block
                          "if (is_atom(car(args))) {"
                          (indent "increment_count(val = true); ")
                          "} else { val = NIL; }"))
                        ((= op 'number)
                         (code_block
                          "if (is_number(car(args))) {"
                          (indent "increment_count(val = true);")
                          "} else { val = NIL; }"))
                        ((= op 'function)
                         (code_block
                          "if (is_function(car(args))) {"
                          (indent "increment_count(val = true);")
                          "} else { val = NIL; }"))
                        ((= op '~)
                         (code_block
                          "if (is_number(car(args))) {"
                          (indent "val = new_number(~(value(car(args))));")
                          "} else { val = NIL; }"))
                        ('t (code_block
                             "if (! is_atom(car(args))) {"
                             (cond ((= op 'car)
                                    "increment_count(val = car(car(args)));")
                                   ('t ;; (= op 'cdr)
                                    "increment_count(val = cdr(car(args)));"))
                             "} else { val = NIL; }"))))
          "} else { val = NIL; }"))
        ((or (= op '+) (= op '*) (= op '/) (= op '%)
             (= op '&) (= op (string->symbol "|")) (= op '^) (= op '>>)
             (= op '<<) (= op '>>>) (= op '>) (= op '<))
         (code_block
          "if ((length(args) == 2) &&"
          "    (is_number(car(args))) &&"
          "    (is_number(car(cdr(args))))) {"
          (indent (cond ((= op '+)
                         "val = new_number(value(car(args)) + value(car(cdr(args)))); ")
                        ((= op '*)
                         "val = new_number(value(car(args)) * value(car(cdr(args)))); ")
                        ((= op '/)
                         (code_block
                          "if (value(car(cdr(args))) == 0) {"
                          (indent "val = NIL;")
                          "} else {"
                          (indent "val = new_number(value(car(args)) / "
                                  "                 value(car(cdr(args))));")
                          "}"))
                        ((= op '%)
                         (code_block
                          "if (value(car(cdr(args))) == 0) {"
                          (indent "val = NIL;")
                          "} else {"
                          (indent "val = new_number(value(car(args)) %"
                                  "                 value(car(cdr(args))));")
                          "}"))
                        ((= op '&)
                         "val = new_number(value(car(args)) & value(car(cdr(args)))); ")
                        ((= op (string->symbol "|"))
                         "val = new_number(value(car(args)) | value(car(cdr(args)))); ")
                        ((= op '^)
                         "val = new_number(value(car(args)) ^ value(car(cdr(args)))); ")
                        ((= op '>>)
                         (code_block "val = new_number(value(car(args)) >> "
                                     "                 value(car(cdr(args))));"))
                        ((= op '>>>)
                         (code_block "val = new_number(((sign_mask >> "
                                     "                   value(car(cdr(args))) - 1) ^ -1) & "
                                     "                 (value(car(args)) >> "
                                     "                  value(car(cdr(args))))); "))
                        ((= op '<<)
                         (code_block "val = new_number(value(car(args)) << "
                                     "                 value(car(cdr(args)))); "))
                        ((= op '>)
                         (code_block
                          "if (value(car(args)) > value(car(cdr(args)))) {"
                          (indent "increment_count(val = true);")
                          "} else { val = NIL; }"))
                        ('t ;; (= op '<)
                         (code_block
                          "if (value(car(args)) < value(car(cdr(args)))) {"
                          (indent "increment_count(val = true);")
                          "} else { val = NIL; }"))))
          "} else { val = NIL; }"))
        ((= op '-)
         (code_block "if (is_number(car(args))) {"
                     (indent "if ((length(args) == 2) &&"
                             "    is_number(car(cdr(args)))) {"
                             (indent "val = new_number(value(car(args)) - "
                                     "                 value(car(cdr(args))));")
                             "} else if (length(args) == 1) {"
                             (indent "val = new_number(-value(car(args)));")
                             "} else { val = NIL; }")
                     "} else { val = NIL; }"))
        ((= op '=)
         (code_block "if ((length(args) == 2) &&"
                     "    (is_atom(car(args))) &&"
                     "    (is_atom(car(cdr(args)))) &&"
                     "    eq(car(args), car(cdr(args)))) {"
                     (indent "increment_count(val = true);")
                     "} else { val = NIL; }"))
        ((= op 'cons)
         (code_block "if (length(args) == 2) {"
                     (indent "increment_count(car(args));"
                             "increment_count(car(cdr(args)));"
                             "val = cons(car(args), car(cdr(args)));")
                     "} else { val = NIL; }"))
        ('t "/** Internal Error: unknown primitive */ val = NIL;")))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile a cond expression ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (is_quote expr)
  (cond ((atom expr) #f)
        ((not (= (car expr) 'quote)) #f)
        ((= (cdr expr) '()) #f)
        ('t 't)))
(define (then-else-block then-code else-code)
  (code_block "if (val != NIL) {"
              (indent "decrement_count(val);" then-code)
              "} else {"
              (indent else-code)
              "}"))
(define (compile_cond expr env cont return_cont labels methods return)
  (cond ((atom expr)
         (return (code_block "/** Warning, unhandled cond-default */ val = NIL;"
                             return_cont)
                 labels methods))
        ((atom (car expr))
         (return (code_block "/** Warning, unhandled cond-default */ val = NIL;"
                             return_cont)
                 labels methods))
        ((is_quote (caar expr))
         (compile_expr (cadar expr) env cont labels methods return))
        ('t (compile_expr (cadar expr) env cont labels methods
                          (fn (then-code labels methods)
                            (compile_cond (cdr expr) env cont
                                          return_cont labels methods
                                          (fn (else-code labels methods)
                                            (let ((new_cont (then-else-block then-code else-code)))
                                              (compile_expr (caar expr) env new_cont
                                                            labels methods return)))))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile a let expression ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (convert_let vars expr)
  (cond ((atom vars) expr)
        ((atom (car vars)) (convert_let (cdr vars) expr))
        ('t (list (list 'fn (list (caar vars)) (convert_let (cdr vars) expr))
                  (cadar vars)))))
(define (compile_let vars expr env cont labels methods return)
  (compile_expr (convert_let vars expr) env cont labels methods return))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile a list of arguments ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile_args args env cont labels methods return)
  (cond ((atom args)
         (let ((new_cont (code_block "args = val;" cont)))
           (compile_expr args env new_cont labels methods return)))
        ('t (compile_expr (car args) env
                          (code_block "args = cons(val, args);" cont)
                          labels methods
                          (fn (new_cont labels methods)
                            (compile_args (cdr args) env new_cont
                                          labels methods return))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile a function body ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (add_method_return return)
  (fn (function_name methods labels)
    (return (code_block "increment_count(env);"
                        (string-append "val = new_function("
                                       function_name ", env);"))
            labels
            methods)))
(define (compile_fn body env labels methods return)
  (cond ((or (atom body) (atom (cdr body)))
         (return "/** Warning, malformed function */ val = NIL;"
                 labels methods))
        ('t (let ((local_env (bind (car body) env))
                  (expr (car (cdr body))))
              (compile_expr expr local_env '() labels methods
                            (fn (compiled_body labels methods)
                                (add_function compiled_body labels methods
                                              (add_method_return return))))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile the application of an unknown function to a list of arguments. ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (apply_return op arg_list env top_level return)
  (fn (return_block methods labels)
      (let ((call_function (string-append "return_location = "
                                          return_block ";"))
            (push_function (cond (top_level "decrement_count(env);")
                                 ('t (string-append
                                      "call_stack = cons(new_function("
                                      return_block
                                      ", env), call_stack);"))))
            (call_cont
             (code_block "if (is_function(val)) {"
                         (indent push_function
                                 "return_location = address(val);"
                                 "increment_count(env = environment(val));"
                                 "decrement_count(val);"
                                 "increment_count(args);"
                                 "env = cons(args, env);"
                                 "pop_args();")
                         "} else {"
                         (indent "if (is_primitive(val)) {"
                                 (indent "temp = val;"
                                         "val = eval_primitive(val, args);"
                                         "decrement_count(temp);")
                                 "} else {"
                                 (indent "decrement_count(val);"
                                         "val = NIL;")
                                 "}"
                                 "pop_args();"
                                 call_function)
                         "}")))
        (compile_expr op env call_cont labels methods
                      (fn (call_body labels methods)
                          (compile_args arg_list env call_body labels methods
                                        (fn (apply_body labels methods)
                                            (return (code_block "push_args();"
                                                                apply_body)
                                                    labels
                                                    methods))))))))
(define (compile_apply op args env return_cont top_level labels methods return)
  (add_function return_cont labels methods
                (apply_return op args env top_level return)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile the application of a primitive operation to a list of arguments, ;;
;; when the operation applied is known at compile-time.                     ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile_apply_primitive op args env cont labels methods return)
  (let ((return_body (code_block (compile_primitive op)
                                 "pop_args();"
                                 cont)))
    (compile_args args env return_body labels methods
                  (fn (apply_body labels methods)
                    (return (code_block "push_args();" apply_body)
                            labels
                            methods)))))

;;;;;;;;;;;;;;;;;;;;
;; Compile a pair ;;
;;;;;;;;;;;;;;;;;;;;
(define (compile_pair op expr env cont return_cont labels methods return)
  (cond ((= op 'cond)
         (compile_cond expr env cont return_cont labels methods return))
        ((= op 'let)
         (compile_let (car expr) (cadr expr) env cont labels methods return))
        ((= op 'quote)
         (return (code_block (compile_structure (car expr)) return_cont)
                 labels
                 methods))
        ((= op 'fn)
         (compile_fn expr env labels methods
                     (fn (fn_call labels methods)
                       (return (code_block fn_call return_cont)
                               labels methods))))
        ((= op 'define)
         (error "Illegal, nested define statement" '()))
        ((is_primitive op)
         (compile_apply_primitive op expr env return_cont labels methods return))
        ('t (compile_apply op expr env return_cont (= cont '())
                           labels methods return))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile an expression using a series of global function definitions ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (definition-names definitions)
  ((fold (fn (def names) (cons (cond ((atom (cadr def)) (cadr def))
                                     ('t (caadr def)))
                               names))
         '())
   definitions))
(define (definition-body definition)
  (cond ((atom (cadr definition)) (caddr definition))
        ('t (list 'fn (cdr (cadr definition)) (caddr definition)))))
(define (definition-bodies definitions)
  ((fold (fn (def bodies) (cons (definition-body def) bodies)) '())
   definitions))
(define (add_definitions names labels cont)
  (((fold (fn (name return)
              (fn (labels ids)
                  (add_define name labels
                              (fn (labels id) (return labels (cons id ids))))))
          (fn (labels ids) (cont labels (reverse ids))))
    names)
   labels '()))
(define (build-declarations ids)
  ((fold (fn (id decls) (code_block (string-append "pointer " id " = NIL;") decls))
         '())
   ids))
(define (compile-defs ids bodies labels methods main_block return)
  (cond ((atom ids) (return main_block labels methods))
        ('t (compile_expr (car bodies) '()
                          (code_block (string-append (car ids) " = val;")
                                      main_block)
                          labels methods
                          (fn (code labels methods)
                              (compile-defs (cdr ids) (cdr bodies) labels
                                            methods code return))))))
(define (compile-definitions definitions expr labels methods return)
  (let ((names (definition-names definitions))
        (bodies (definition-bodies definitions)))
    (add_definitions names labels
                     (fn (labels ids)
                         (let ((prefix (build-declarations ids)))
                           (compile_expr expr '() '() labels
                                         (cons prefix methods)
                                         (fn (code labels methods)
                                             (compile-defs ids bodies labels
                                                           methods code
                                                           return))))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compile an s-expression ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile_expr expr env cont labels methods return)
  (let ((return_cont (cond ((= cont '()) "pop_function();")
                           ('t cont))))
    (cond ((function expr)
           (return (code_block (find expr env labels) return_cont)
                   labels methods))
          ((not (atom expr))
           (compile_pair (car expr) (cdr expr) env cont
                         return_cont labels methods return))
          ('t (return (code_block (compile_structure expr) return_cont)
                      labels methods)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Variables for maintaining the list of function headers/bodies ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (empty_labels initial)
  (fn (op) (op initial '())))
(define (get_next_label labels)
  (labels (fn (label-count label-map) label-count)))
(define (get_label_map labels)
  (labels (fn (label-count label-map) label-map)))
(define (add_label labels)
  (let ((label_count (+ (get_next_label labels) 1))
        (label_map (get_label_map labels)))
    (fn (op) (op label_count label_map))))
(define (next_label->string labels)
  (number->string (get_next_label labels)))
(define (add_define name labels return)
  (let ((label_number (get_next_label labels))
        (label_count (+ label_number 1))
        (label_id (string-append "global_" (number->string label_number)))
        (label_map (cons (cons name label_id) (get_label_map labels))))
    (return (fn (op) (op label_count label_map)) label_id)))
(define (add_function body labels methods return)
  (return (string-append "(&function_" (next_label->string labels) ")")
          (cons (code_block (string-append "void function_"
                                           (next_label->string labels)
                                           "() {")
                            (indent body)
                            "}")
                methods)
          (add_label labels)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; The skeleton of the code generation ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (main_body apply_main function_name)
  (code_block "int main(int argc, char** argv) {"
              (indent "pointer memory_limit = 104857600;"
                      "void* memory = malloc(memory_limit);"
                      "init_mem(memory, memory_limit);"
                      "init_io();"
                      "init_eval();"
                      (string-append
                       "call_stack = "
                       "cons(new_function((&top_level), NIL),"
                       " call_stack);")
                      (string-append
                       "call_stack = "
                       "cons(new_function(" apply_main ", NIL),"
                       " call_stack);")
                      (string-append "return_location = "
                                     function_name ";")
                      "while (return_location != (&end_function)) {"
                      (indent "(*return_location)();")
                      "}"
                      "end_function();"
                      "end_io();")
              "}"))
(define (compile_return apply_main)
  (fn (main_expr labels methods)
    (add_function main_expr labels methods
                  (fn (function_name methods labels)
                    (add-code-header (cons (main_body apply_main function_name)
                                           methods))))))
(define (rreverse list result)
  (cond ((atom list) result)
        ('t (rreverse (cdr list) (cons (car list) result)))))
(define (reverse list) (rreverse list '()))
(define (add-code-header methods)
  (cons (code_block "#include <stdlib.h>"
                    "#include \"io.h\""
                    "#include \"mem.h\""
                    "#include \"eval.h\""
                    "pointer arguments = NIL;"
                    "inline void pop_function() {"
                    (indent "decrement_count(env);"
                            "temp = car(call_stack);"
                            "if (is_function(temp)) {"
                            (indent "env = environment(temp);"
                                    "increment_count(env);"
                                    "return_location = address(temp);")
                            "} else {"
                            (indent "error(ERR_INTERNAL);"
                                    "env = NIL;"
                                    "return_location = (&end_function);")
                            "}"
                            "increment_count(temp = cdr(call_stack));"
                            "decrement_count(call_stack);"
                            "call_stack = temp;")
                    "}"
                    "void push_env() {"
                    (indent "stack = cons(env, stack);")
                    "}"
                    "void pop_env() {"
                    (indent "decrement_count(env);"
                            "increment_count(env = car(stack));"
                            "increment_count(temp = cdr(stack));"
                            "decrement_count(stack);"
                            "stack = temp;")
                    "}"
                    "void push_args() {"
                    (indent "stack = cons(args, stack);")
                    "}"
                    "void pop_args() {"
                    (indent "decrement_count(args);"
                            "increment_count(args = car(stack));"
                            "increment_count(temp = cdr(stack));"
                            "decrement_count(stack);"
                            "stack = temp;")
                    "}")
        (reverse methods)))
(define (compile definitions expr)
  (let ((end_cont (code_block "if (is_function(val)) {"
                              (indent "increment_count(env=environment(val));"
                                      "env = cons(cons(free_memory_size(),"
                                      "               cons(arguments,NIL)),"
                                      "           env);"
                                      "return_location = address(val);"
                                      "decrement_count(val);")
                              "} else {"
                              (indent "error(ERR_NO_OS);"
                                      "env = NIL;"
                                      "return_location = (&end_function);")
                              "}"))
        (labels (empty_labels 0)))
    (add_function end_cont labels '()
                  (fn (apply_main methods labels)
                    (cond ((atom definitions)
                           (compile_expr expr '() '() labels methods
                                         (compile_return apply_main)))
                          ('t (compile-definitions definitions expr
                                                   labels methods
                                                   (compile_return apply_main))))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Function for maintaining the binding environment ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (bind args env) (cons args env))
(define (rfind var env expr)
  (cond ((function env)
         (cond ((= (symbol->id var) (symbol->id env)) expr)
               ('t '())))
        ((atom env)
         (cond ((= var env) expr)
               ('t '())))
        ('t (let ((find_var (rfind var (car env)
                                   (string-append "car(" expr ")"))))
              (cond ((= find_var '())
                     (rfind var (cdr env)
                            (string-append "cdr(" expr ")")))
                    ('t find_var))))))
(define (find_global expr label_map)
  (cond ((= label_map '())
         (string-append "/** Warning, expression "
                        (map integer->char (symbol->string expr))
                        " not bound in the environment */"
                        "val = NIL;"))
        ((= (symbol->id (caar label_map)) (symbol->id expr))
         (code_block (string-append "val = " (cdar label_map) ";")
                     "increment_count(val);"))
        ('t (find_global expr (cdr label_map)))))
(define (find expr env labels)
  (let ((expr_str (rfind expr env "env")))
    (cond ((= expr_str '()) (find_global expr (get_label_map labels)))
          ('t (string-append "increment_count(val = " expr_str ");")))))

;;;;;;;;;;;;;;;;;;;;
;; Error handling ;;
;;;;;;;;;;;;;;;;;;;;
(define (error msg rest)
  (append (map char->integer (string->list msg)) rest '(10 13)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Function for printing the generated code ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (printer prefix postfix)
  (fold (fn (block printed-code) (block prefix printed-code)) postfix))

;;;;;;;;;;;;;;;;;;;;;;;
;; Compile the input ;;
;;;;;;;;;;;;;;;;;;;;;;;
(define (input-finished? input-chars)
  (cond ((= input-chars '()) 't)
        ((< (car input-chars) 32) (input-finished? (cdr input-chars)))
        ('t #f)))
(define (compile_source definitions)
  (fn (value remaining_chars symbol-table)
    (cond ((input-finished? remaining_chars)
           ((printer '() '()) (compile definitions value)))
          ((not (= (car value) 'define))
           (error "Remaining input" remaining_chars))
          ((not (or (atom (cadr value)) (atom (caadr value))))
           (error "Malformed define statement" remaining_chars))
          ('t (read_expr remaining_chars
                         (compile_source (cons value definitions))
                         symbol-table)))))
(define (compile-input input-chars)
  (read_expr input-chars (compile_source '()) '()))
(define (build-input-list inputs return)
  (fn (next-input)
    (cond ((= next-input '()) (return (reverse inputs)))
          ('t (build-input-list (cons next-input inputs) return)))))
(define (compiler input)
  ((build-input-list '() (fn (inputs) (compile-input inputs))) input))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main loop which allows us to use CSP-style I/O. This means that we can ;;
;; write the entire rest of the program in a purely functional manner.    ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (compile-stream input-port input-closed? output-port compiler)
  (cond ((pair? compiler)
         (cond ((number? (car compiler))
                (write-char (integer->char (car compiler)) output-port)
                (compile-stream input-port
                                input-closed?
                                output-port
                                (cdr compiler)))
               ('t (display "Error: compiler bug"))))
        ((and (procedure? compiler) input-closed?)
         (display "Error: compiler not handling end-of-file correctly"))
        ((procedure? compiler)
         (let ((next-char (read-char input-port)))
           (cond ((eof-object? next-char)
                  (close-input-port input-port)
                  (compile-stream input-port
                                  't
                                  output-port
                                  (compiler '())))
                 ('t (compile-stream input-port #f output-port
                                     (compiler (char->integer next-char)))))))
        ((null? compiler)
         (cond (input-closed? (close-input-port input-port)
                              (close-output-port output-port))
               ('t (close-output-port output-port))))
        ('t (display "Error: compiler output bug"))))
(define (compile_file input-file-name)
  (let ((input-port (open-input-file input-file-name)))
    (compile-stream input-port #f (current-output-port) compiler)))