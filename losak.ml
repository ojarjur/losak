;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; LOSAK.el                                                        ;;
;; Interpreter for LOSAK, written in mini LOSAK                    ;;
;; Copyright (C) 2004, 2005 by Omar Jarjur                         ;;
;;                                                                 ;;
;; This program is free software; you can redistribute it and/or   ;;
;; modify it under the terms of the GNU General Public License     ;;
;; as published by the Free Software Foundation; either version 2  ;;
;; of the License, or (at your option) any later version.          ;;
;;                                                                 ;;
;; This program is distributed in the hope that it will be useful, ;;
;; but WITHOUT ANY WARRANTY; without even the implied warranty of  ;;
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the   ;;
;; GNU General Public License for more details.                    ;;
;;                                                                 ;;
;; You should have received a copy of the GNU General Public       ;;
;; License along with this program; if not, write to the Free      ;;
;; Software Foundation, Inc.,                                      ;;
;; 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.       ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(let ((caar (fn (x) (car (car x))))
      (cadr (fn (x) (car (cdr x))))
      (cdar (fn (x) (cdr (car x))))
      (cddr (fn (x) (cdr (cdr x))))
      (caaar (fn (x) (car (caar x))))
      (caadr (fn (x) (car (cadr x))))
      (cadar (fn (x) (car (cdar x))))
      (caddr (fn (x) (car (cddr x))))
      (cdaar (fn (x) (cdr (caar x))))
      (cdadr (fn (x) (cdr (cadr x))))
      (cddar (fn (x) (cdr (cdar x))))
      (cdddr (fn (x) (cdr (cddr x))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Assorted helper functions ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (list (fn x x))
      (rand (fn (rand x xs) (cond ((atom xs) x)
				  (x (rand rand (car xs) (cdr xs))))))
      (and (fn args (rand rand (car args) (cdr args))))
      (ror (fn (ror x xs) (cond ((atom xs) x) (x 't)
				('t (ror ror (car xs) (cdr xs))))))
      (or (fn args (ror ror (car args) (cdr args))))
      (not (fn (x) (cond (x ()) ('t 't))))
      (req (fn (req x y) (cond ((atom x) (= x y))
			       ((req req (car x) (car y))
				(req req (cdr x) (cdr y))))))
      (eq (fn (x y) (req req x y)))
      (rreverse (fn (rreverse x result)
		    (cond ((atom x) result)
			  ('t (rreverse rreverse (cdr x)
					(cons (car x) result))))))
      (reverse (fn (x) (cond ((atom x) x)
			     ('t (rreverse rreverse (cdr x) (car x))))))
      (rappend (fn (rappend x y)
		   (cond ((atom x) y)
			 ('t (cons (car x)
				   (rappend rappend (cdr x) y))))))
      (append (fn (x y) (rappend rappend x y)))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Functions for error handling ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (rdiscard (fn (rdiscard str)
		    (cond ((atom str) ())
			  ((or (= (car str) 13) (= (car str) 10)) (cdr str))
			  ('t (rdiscard rdiscard (cdr str))))))
      (discard_line (fn (str) (rdiscard rdiscard str)))
      (is_error (fn (expr) (= (car expr) 'error)))
      (error (fn (type chars)
		 (cons (cons 'error type) (discard_line chars))))
      (print_error (fn ((head . type))
		       (append "Error in program source code: "
			       (cond ((not (= head 'error)) ())
				     ((= type 'period) "Unexpected period")
				     ((= type 'parenthesis)
				      "Unexpected closing parenthesis")
				     ((= type 'no_car)
				      "No car in pair expression")
				     ((= type 'no_cdr)
				      "No cdr in pair expression")
				     ((= type 'extra_cdrs)
				      "Too many cdrs in pair expression")
				     ((= type 'extra_dots)
				      "Too many periods in pair expression")
				     ('t "Unknown error")))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Functions to parse an s-expression ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (rread_symbol (fn (rread_symbol str)
			(cond ((atom str) (cons () ()))
			      ((= (car str) ())
			       (rread_symbol rread_symbol (cdr str)))
			      ((< (car str) 33) (cons () str))
			      ((and (> (car str) 38) (< (car str) 42))
			       (cons () str))
			      ((= (car str) 34) (cons () str))
			      ((= (car str) 35) (cons () str))
			      ((= (car str) 46) (cons () str))
			      ((= (car str) 59) (cons () str))
			      ('t (let (((expr . rest)
					 (rread_symbol rread_symbol
						       (cdr str))))
				    (cons (cons (car str) expr) rest))))))
      (read_symbol (fn (str) (let (((expr . chars)
				    (rread_symbol rread_symbol str)))
			       (cons (cons 'symb expr) chars))))
      (rread_number (fn (rread_number str val)
			(cond ((= (car str) ())
			       (rread_number rread_number (cdr str) val))
			      ((and (> (car str) 47) (< (car str) 58))
			       (rread_number rread_number (cdr str)
					     (+ (* val 10) (- (car str) 48))))
			      ('t (cons val str)))))
      (read_number (fn (str) (rread_number rread_number str 0)))
      (read_estr (fn (read_estr rread_string chars)
                     (cond ((atom chars) (cons () chars))
                           ((= (car chars) ())
                            (read_estr read_estr rread_string (cdr chars)))
                           ('t (let (((str . rest)
                                      (rread_string rread_string (cdr chars))))
                                 (cond ((= (car chars) 34)
                                        (cons (cons 34 str) rest))
                                       ((= (car chars) 92)
                                        (cons (cons 92 str) rest))
                                       ((= seq 116)
                                        (cons (cons 9 string) chars))
                                       ((= seq 110)
                                        (cons (cons 10 string) chars))
                                       ((= seq 114)
                                        (cons (cons 13 string) chars))
                                       ((= seq 58)
                                        (cons (cons 59 string) chars))
                                       ('t (cons (cons (car chars) str)
                                                 rest))))))))
      (rread_str (fn (rread_str chars)
		     (cond ((atom chars) (cons () chars))
			   ((= (car chars) ())
			    (rread_str rread_str (cdr chars)))
			   ((= (car chars) 34) (cons () (cdr chars)))
			   ((= (car chars) 92)
			    (read_estr read_estr rread_str (cdr chars)))
			   ('t (let (((str . rest)
				      (rread_str rread_str
						 (cdr chars))))
				 (cons (cons (car chars) str) rest))))))
      (read_str (fn (str) (let (((str . chars)
				 (rread_str rread_str str)))
			    (cons (cons (cons 'symb "quote") str) chars))))
      (rread_pair (fn (rread_pair rread str curr dotted)
		      (cond ((or (< (car str) 33) (= (car str) ()))
			     (rread_pair rread_pair rread
					 (cdr str) curr dotted))
			    ((or (atom str) (= (car str) 41))
			     (cond ((= dotted 1) (error 'no_cdr str))
				   ((= dotted 0)
				    (cons (reverse (cons () curr)) (cdr str)))
				   ('t (cons (reverse curr) (cdr str)))))
			    ((= (car str) 46)
			     (cond ((= curr ()) (error 'no_car str))
				   ((= dotted 0)
				    (rread_pair rread_pair rread (cdr str)
						curr 1))
				   ('t (error 'extra_dots str))))
			    ((= dotted 2) (error 'extra_cdrs str))
			    ('t (let (((expr . chars) (rread rread str))
				      (dotted (cond ((= dotted 0) 0) ('t 2))))
				  (cond ((is_error expr) (cons expr chars))
					('t (rread_pair rread_pair rread chars
							(cons expr curr)
							dotted))))))))
      (read_pair (fn (rread str)
		     (rread_pair rread_pair rread str () 0)))
      (rread (fn (rread str)
		 (cond ((atom str) ())
		       ((or (= (car str) ()) (< (car str) 33))
			(rread rread (cdr str)))
		       ((or (= (car str) 35) (= (car str) 59))
			(rread rread (discard_line str)))
		       ((= (car str) 41) (error 'parenthesis str))
		       ((= (car str) 46) (error 'period str))
		       ((= (car str) 40) (read_pair rread (cdr str)))
		       ((= (car str) 34) (read_str (cdr str)))
		       ((= (car str) 39)
			(let ((result (rread rread (cdr str)))
			      (expr (car result))
			      (rest (cdr result)))
			  (cond ((is_error expr) result)
				('t (cons (cons (cons 'symb "quote") expr)
					  rest)))))
		       ((and (> (car str) 47) (< (car str) 58))
			(read_number str))
		       ('t (read_symbol str)))))
      (read (fn (str) (rread rread str)))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Functions for handling atoms ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (is_atom (fn (x) (or (atom x) (= (car x) 'symb))))
      (ccar (fn (x) (cond ((is_atom x) ()) ('t (car x)))))
      (ccdr (fn (x) (cond ((is_atom x) ()) ('t (cdr x)))))
      (is_symbol (fn (x) (= (car x) 'symb)))
      (ris_cxr (fn (ris_cxr op)
		   (cond ((and (= (car op) 114) (atom (cdr op))) 't)
			 ((or (= (car op) 97) (= (car op) 100))
			  (ris_cxr ris_cxr (cdr op))))))
      (is_cxr (fn (x)
		  (cond ((= (car x) 'symb)
			 (cond ((= (cadr x) 99)
				(cond ((= (caddr x) 114) ())
				      ('t (ris_cxr ris_cxr (cddr x))))))))))
      (is_sf (fn (x)
		 (cond ((eq x (cons 'symb "quote")) 't)
		       ((eq x (cons 'symb "cond")) 't)
		       ((eq x (cons 'symb "let")) 't)
		       ((eq x (cons 'symb "fn")) 't)
		       ((eq x (cons 'symb "sf")) 't)
		       ((eq x (cons 'symb "lambda")) 't)
		       ((eq x (cons 'symb "macro")) 't))))
      (is_primitive (fn (x)
			(cond ((is_sf x) 't)
			      ((is_cxr x) 't)
			      ((eq x (cons 'symb "cons")) 't)
			      ((eq x (cons 'symb "atom")) 't)
			      ((eq x (cons 'symb "number")) 't)
			      ((eq x (cons 'symb "symbol")) 't)
			      ((eq x (cons 'symb "hd")) 't)
			      ((eq x (cons 'symb "tl")) 't)
			      ((eq x (cons 'symb "symb")) 't)
			      ((eq x (cons 'symb "+")) 't)
			      ((eq x (cons 'symb "-")) 't)
			      ((eq x (cons 'symb "*")) 't)
			      ((eq x (cons 'symb "/")) 't)
			      ((eq x (cons 'symb "%")) 't)
			      ((eq x (cons 'symb ">>>")) 't)
			      ((eq x (cons 'symb ">>")) 't)
			      ((eq x (cons 'symb "<<")) 't)
			      ((eq x (cons 'symb "=")) 't)
			      ((eq x (cons 'symb "<")) 't)
			      ((eq x (cons 'symb ">")) 't)
			      ((eq x (cons 'symb "~")) 't)
			      ((eq x (cons 'symb "&")) 't)
			      ((eq x (cons 'symb "|")) 't)
			      ((eq x (cons 'symb "^")) 't))))
      (rapply_cxr (fn (rapply_cxr op arg)
		      (cond ((= (car op) 114) arg) ;;r
			    ((is_atom arg) ())
			    ((= (car op) 97) ;;a
			     (rapply_cxr rapply_cxr (cdr op) (car arg)))
			    ((= (car op) 100) ;;d
			     (rapply_cxr rapply_cxr (cdr op) (cdr arg))))))
      (apply_cxr (fn (op args) (rapply_cxr rapply_cxr (cddr op) (ccar args))))
      (apply_primitive (fn (op args)
			   (cond ((is_cxr op) (apply_cxr op args))
				 ((eq op (cons 'symb "atom"))
				  (cond ((is_atom (ccar args))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb "number"))
				  (cond ((number (ccar args))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb "symbol"))
				  (cond ((is_symbol (ccar args))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb "hd"))
				  (cond ((is_symbol (ccar args))
					 (cadar args))))
				 ((eq op (cons 'symb "tl"))
				  (cond ((is_symbol (ccar args))
					 (cond ((atom (cddar args)) ())
					       ('t (cons 'symb
							 (cddar args)))))))
				 ((eq op (cons 'symb "~"))
				  (~ (ccar args)))
				 ((eq op (cons 'symb "cons"))
				  (cons (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "symb"))
				  (let ((arg1 (ccar args))
					(arg2 (ccar (ccdr args))))
				    (cond ((and (or (= arg2 ())
						    (is_symbol arg2))
						(number arg1))
					   (cons 'symb (cons arg1
							     (cdr arg2)))))))
				 ((eq op (cons 'symb "="))
				  (cond ((and (is_atom (ccar args))
					      (eq (ccar args)
						  (ccar (ccdr args))))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb "<"))
				  (cond ((< (ccar args) (ccar (ccdr args)))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb ">"))
				  (cond ((> (ccar args) (ccar (ccdr args)))
					 (cons 'symb "t"))))
				 ((eq op (cons 'symb ">>>"))
				  (>>> (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb ">>"))
				  (>> (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "<<"))
				  (<< (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "+"))
				  (+ (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "*"))
				  (* (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "/"))
				  (/ (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "%"))
				  (% (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "&"))
				  (& (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "|"))
				  (| (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "^"))
				  (^ (ccar args) (ccar (ccdr args))))
				 ((eq op (cons 'symb "-"))
				  (cond ((is_atom (ccdr args))
					 (- (ccar args)))
					('t (- (ccar args)
					       (ccar (ccdr args)))))))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Functions for handling variable bindings ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (rbind (fn (rbind var val env)
		 (cond ((is_symbol var) (cons (cons var val) env))
		       ((is_atom var) env)
		       ('t (rbind rbind (car var) (ccar val)
				  (rbind rbind (cdr var) (ccdr val) env))))))
      (bind (fn (var val env) (rbind rbind var val env)))
      (rfind (fn (rfind var env)
		 (cond ((is_atom env) ())
		       ((eq (caar env) var) (cdar env))
		       ('t (rfind rfind var (cdr env))))))
      (find (fn (var env) (rfind rfind var env)))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Functions for handling special forms ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (rcond (fn (rcond reval cases env)
		 (cond ((is_atom cases)
			(reval reval cases env))
		       ((reval reval (ccar (car cases)) env)
			(reval reval (ccar (ccdr (car cases))) env))
		       ('t (rcond rcond reval (cdr cases) env)))))
      (eval_cond (fn (reval cases env) (rcond rcond reval cases env)))
      (rlet (fn (rlet reval vars expr env)
		(cond ((is_atom vars) (reval reval expr env))
		      ('t (let ((val (reval reval (ccar (ccdr (car vars)))
					    env))
				(env (bind (ccar (car vars)) val env)))
			    (rlet rlet reval (cdr vars) expr env))))))
      (eval_let (fn (reval vars expr env) (rlet rlet reval vars expr env)))
      (eval_sf (fn (reval op expr env)
		   (cond ((eq op (cons 'symb "quote")) expr)
			 ((eq op (cons 'symb "cond"))
			  (eval_cond reval expr env))
			 ((eq op (cons 'symb "let"))
			  (eval_let reval (ccar expr) (ccar (ccdr expr)) env))
			 ((or (eq op (cons 'symb "lambda"))
			      (eq op (cons 'symb "macro")))
			  (cons op expr))
			 ((eq op (cons 'symb "fn"))
			  (cons (cons 'symb "lambda")
				(cons expr env)))
			 ((eq op (cons 'symb "sf"))
			  (cons (cons 'symb "macro")
				(cons expr env))))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Helper functions for evaluating an expression ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (rlist (fn (rlist reval args env)
		 (cond ((is_atom args) (reval reval args env))
		       ('t (cons (reval reval (car args) env)
				 (rlist rlist reval (cdr args) env))))))
      (apply (fn (reval op args)
		 (cond ((is_primitive op)
			(apply_primitive op args))
		       ((or (eq (car op) (cons 'symb "macro"))
			    (eq (car op) (cons 'symb "lambda")))
			(reval reval (ccar (ccdr (ccar (ccdr op))))
			       (bind (ccar (ccar (ccdr op))) args
				     (ccdr (ccdr op))))))))
      (eval_pair (fn (reval op expr env)
		     (cond ((is_sf op) (eval_sf reval op expr env))
			   ((eq (car op) (cons 'symb "sf"))
			    (reval reval (cons op expr) env))
			   ((eq (car op) (cons 'symb "fn"))
			    (reval reval (cons op expr) env))
			   ((eq (car op) (cons 'symb "macro"))
			    (apply reval op expr))
			   ('t (let ((args (rlist rlist reval expr env)))
				 (apply reval op args))))))
      (reval (fn (reval expr env)
		 (cond ((is_primitive expr) expr)
		       ((is_symbol expr) (find expr env))
		       ((is_atom expr) expr)
		       ('t (let ((op (reval reval (car expr) env)))
			     (eval_pair reval op (cdr expr) env))))))
      (eval (fn (expr env) (reval reval expr env))))
  (fn (source_code)
      (let (((program . extra) (read source_code)))
	(cond ((is_error program) (print_error program))
	      ('t (fn input (eval (cons program input) ())))))))