;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Compiler for Mini LOSAK written in Mini LOSAK                   ;;
;; Copyright (C) 2005 by Omar Jarjur                               ;;
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
(let ((and (let ((rand (fn (rand x . args)
			   (cond ((atom args) x)
				 (x (rand rand . args))))))
	     (fn args (rand rand . args))))
      (append
       (let ((rappend (fn (rappend x y)
			  (cond ((atom x) y)
				('t (cons (car x)
					  (rappend rappend (cdr x) y))))))
	     (rseq (fn (rseq arg . args)
                       (cond ((atom args) arg)
			     ('t (rappend rappend arg
					  (rseq rseq . args)))))))
	 (fn args (rseq rseq . args))))
      (eq
       (let ((req (fn (req x y) (cond ((atom x) (= x y))
				      ((atom y) ())
				      ((req req (car x) (car y))
				       (req req (cdr x) (cdr y)))))))
	 (fn args (req req . args))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Function to print a parse error ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (print_error
       (fn (type)
	   (append "Error: "
		   (cond ((= type 'null)
			  "Unexpected end of input\n\r")
			 ((= type 'parenthesis)
			  "Unexpected parenthesis\n\r")
			 ((= type 'period)
			  "Unexpected period\n\r")
			 ((= type 'no_car)
			  "No car value in pair expression\n\r")
			 ((= type 'no_cdr)
			  "No cdr value in pair expression\n\r")
			 ((= type 'extra_cdrs)
			  "Too many cdrs in pair expression\n\r")
			 ((= type 'extra_periods)
			  "Too many periods in pair expression\n\r")
			 ('t "Unknown Error\n\r")))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Function to read an s-expression ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (read
       (let ((discard_line
	      (let ((rline (fn (rline chars)
			       (cond ((atom chars) chars)
				     ((= (car chars) 10) (cdr chars))
				     ((= (car chars) 13) (cdr chars))
				     ('t (rline rline (cdr chars)))))))
		(fn args (rline rline . args))))
	     (error (fn (type chars)
			(cons (cons 'error type) (discard_line chars))))

	     ;;; Read in a string ;;;
	     (read_string
	      (let ((esc_str (fn (esc_str rstring chars)
				 (cond ((atom chars) (cons () chars))
				       ((= (car chars) ())
					(esc_str esc_str rstring (cdr chars)))
				       ('t (let ((first (car chars))
						 (rest (cdr chars))
						 ((str . rest)
						  (rstring rstring rest)))
					     (cond ((= first 110)
						    (cons (cons 10 str) rest))
						   ((= first 114)
						    (cons (cons 13 str) rest))
						   ((= first 58)
						    (cons (cons 59 str) rest))
						   ((= first 116)
						    (cons (cons 9 str) rest))
						   ('t (cons
							(cons first str)
							rest))))))))
		    (rstring (fn (rstring chars)
				 (cond ((atom chars) (cons () chars))
				       ((= (car chars) ())
					(rstring rstring (cdr chars)))
				       ((= (car chars) 34)
					(cons () (cdr chars)))
				       ((= (car chars) 92)
					(esc_str esc_str rstring (cdr chars)))
				       ('t (let ((rest (cdr chars))
						 ((str . rest)
						  (rstring rstring rest)))
					     (cons (cons (car chars) str)
						   rest)))))))
		(fn args
		    (let (((str . rest) (rstring rstring . args)))
		      (cons (cons (cons 'symbol "quote") str)
			    rest)))))

	     ;;; Read in a number ;;;
	     (read_number
	      (let ((rnumber
		     (fn (rnumber chars val)
			 (cond ((atom chars) (cons val chars))
			       ((= (car chars) ())
				(rnumber rnumber (cdr chars) val))
			       ((< (car chars) 48) (cons val chars))
			       ((> (car chars) 57) (cons val chars))
			       ('t (rnumber rnumber (cdr chars)
					    (+ (* val 10)
					       (- (car chars) 48))))))))
		(fn (chars)
		    (cond ((= (car chars) 45)
			   (let (((num . rest)
				  (rnumber rnumber (cdr chars) 0)))
			     (cons (- num) rest)))
			  ('t (rnumber rnumber chars 0))))))

	     ;;; Read in a symbol ;;;
	     (read_symbol
	      (let ((is_special_char
		     (fn (char) (cond ((< char 33) 't)
				      ((= char 34) 't)
				      ((= char 35) 't)
				      ((= char 39) 't)
				      ((= char 40) 't)
				      ((= char 41) 't)
				      ((= char 46) 't)
				      ((= char 59) 't))))
		    (rsymbol
		     (fn (rsymbol chars)
			 (cond ((atom chars) (cons () chars))
			       ((= (car chars) ())
				(rsymbol rsymbol (cdr chars)))
			       ((is_special_char (car chars))
				(cons () chars))
			       ('t (let (((expr . rest)
					  (rsymbol rsymbol (cdr chars))))
				     (cons (cons (car chars) expr) rest)))))))
		(fn (chars)
		    (let (((expr . rest) (rsymbol rsymbol chars)))
		      (cons (cons 'symbol expr) rest)))))

	     ;;; Read in a pair ;;;
	     (read_pair
	      (let ((reverse
		     (let ((rrev (fn (rrev expr val)
				     (cond ((= expr ()) val)
					   ('t (rrev rrev (cdr expr)
						     (cons (car expr)
							   val)))))))
		       (fn (expr) (rrev rrev (cdr expr) (car expr)))))
		    (rpair (fn (rpair rread chars curr dotted)
			       (cond ((atom chars) (error 'null chars))
				     ((= (car chars) ())
				      (rpair rpair rread (cdr chars)
					     curr dotted))
				     ((< (car chars) 33)
				      (rpair rpair rread (cdr chars)
					     curr dotted))
				     ((= (car chars) 41)
				      (cond ((= dotted 1)
					     (error 'no_cdr chars))
					    ((= dotted 0)
					     (cons (reverse (cons () curr))
						   (cdr chars)))
					    ('t (cons (reverse curr)
						      (cdr chars)))))
				     ((= (car chars) 46)
				      (cond ((= curr ()) (error 'no_car chars))
					    ((= dotted 0)
					     (rpair rpair rread
						    (cdr chars) curr 1))
					    ('t (error 'extra_periods chars))))
				     ((= dotted 2) (error 'extra_cdrs chars))
				     ('t (let (((expr . chars)
						(rread rread chars))
					       (dotted (cond ((= dotted 0) 0)
							     ('t 2))))
					   (cond ((= (car expr) 'error)
						  (cons expr chars))
						 ('t (rpair rpair rread chars
							    (cons expr curr)
							    dotted)))))))))
		(fn (rread chars) (rpair rpair rread chars () 0))))

	     ;;; Read in an s-expression ;;;
	     (rread
	      (fn (rread chars)
		  (cond ((atom chars) (error 'null chars))
			((= (car chars) ()) (rread rread (cdr chars)))
			((< (car chars) 33) (rread rread (cdr chars)))
			((= (car chars) 34)
			 (read_string (cdr chars)))
			((= (car chars) 35)
			 (rread rread (discard_line chars)))
			((= (car chars) 39)
			 (let (((expr . rest)
				(rread rread (cdr chars))))
			   (cond ((= (car expr) 'error)
				  (cons expr rest))
				 ('t (cons (cons (cons 'symbol "quote") expr)
					   rest)))))
			((= (car chars) 40)
			 (read_pair rread (cdr chars)))
			((= (car chars) 41)
			 (error 'parenthesis chars))
			((= (car chars) 46)
			 (error 'period chars))
			((= (car chars) 59)
			 (rread rread (discard_line chars)))
			((and (> (car chars) 47)
			      (< (car chars) 58))
			 (read_number chars))
			((and (= (car chars) 45)
			      (> (car (cdr chars)) 47)
			      (< (car (cdr chars)) 58))
			 (read_number chars))
			('t (read_symbol chars))))))
	 (fn args (rread rread . args))))

      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Function to print an s-expression ;;
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (print
       (let ((is_atom (fn (expr) (cond ((atom expr) 't)
				       ((= (car expr) 'symbol) 't))))

	     ;;; Print a number ;;;
	     (print_number
	      (let ((rnumber (fn (rnumber expr chars)
				 (cond ((= expr 0) chars)
				       ('t (rnumber rnumber (/ expr 10)
						    (cons (+ (% expr 10) 48)
							  chars)))))))
		(fn (expr)
		    (cond ((= expr 0) "0")
			  ((< expr 0) (cons 45 (rnumber rnumber (- expr) ())))
			  ('t (rnumber rnumber expr ()))))))

	     ;;; Print a pair ;;;
	     (print_pair
	      (let ((rpair (fn (rpair rprint expr)
			       (cond ((= (cdr expr) ())
				      (append (rprint rprint (car expr))
					      (cons 41 ())))
				     ((is_atom (cdr expr))
				      (append (rprint rprint (car expr))
					      " . "
					      (rprint rprint (cdr expr))
					      (cons 41 ())))
				     ('t (append (rprint rprint (car expr))
						 " "
						 (rpair rpair rprint
							(cdr expr))))))))
		(fn (rprint expr) (cons 40 (rpair rpair rprint expr)))))

	     (print_atom (fn (expr)
			     (cond ((= expr ()) "()")
				   ((number expr) (print_number expr))
				   ((= (car expr) 'symbol) (cdr expr))
				   ('t "Huh...?"))))

	     ;;; Print an s-expression ;;;
	     (rprint (fn (rprint expr)
			 (cond ((is_atom expr) (print_atom expr))
			       ((eq (car expr) (cons 'symbol "quote"))
				(cons 39 (rprint rprint (cdr expr))))
			       ('t (print_pair rprint expr))))))
	 (fn (expr) (rprint rprint expr))))
      (compile
       (let (()
	     )
	 ()))
      (write
       (let (;;; String of C memory management code ;;;
	     (memory_management
	      "typedef int pointer\:
               typedef struct {
                   pointer count\:
                   pointer ar\:
                   pointer dr\:
               } cons_cell\:
               cons_cell[] memory\:
               pointer NIL = -1, NUM = -2,
                       memory_limit,
                       free_list = 0,
                       reclaim_list = NIL\:
               pointer car(pointer expr) {
                   if ((expr < 0) || (expr >= memory_limit)) {
                       return NIL\:
                   } else {
                       return memory[expr].ar\:
                   }
               }
               pointer cdr(pointer expr) {
                   if ((expr < 0) || (expr >= memory_limit)) {
                       return NIL\:
                   } else {
                       return memory[expr].dr\:
                   }
               }
               pointer cons(pointer ar, pointer dr) {
                   pointer result = NIL\:
                   if ((reclaim_list >= 0) &&
                       (reclaim_list < memory_limit)) {
                       if (car(reclaim_list) != NUM) {
                           decrement_count(car(reclaim_list))\:
                           decrement_count(cdr(reclaim_list))\:
                       }
                       result = reclaim_list\:
                       reclaim_list = cdr(reclaim_list)\:
                   } else if (free_list < memory_limit) {
                       result = free_list\:
                       free_list = free_list + 1\:
                   } else { return NIL\: }
                   memory[result].count = 1\:
                   memory[result].ar = ar\:
                   memory[result].dr = dr\:
                   return result\:
               }
               void increment_cound(pointer expr) {
                   if ((expr >= 0) && (expr < memory_limit)) {
                       memory[expr].count++\:
                   }
               }
               void decrement_cound(pointer expr) {
                   if ((expr >= 0) && (expr < memory_limit)) {
                       memory[expr].count--\:
                       if (memory[expr].count < 1) {
                           memory[expr].count = reclaim_list\:
                           reclaim_list = expr\:
                       }
                   }
               }
              ")

	     ;;; String for the C program initialization ;;;
	     (initialization
	      "void initialize_memory(pointer size) {
                   memory = (cons_cell*)malloc(size*sizeof(cons_cell))\:
                   memory_limit = size\:
               }
               void initialize_memory(void* memory_location,
                                      int size_in_bytes) {
                   memory = (cons_cell*)memory_location\:
                   memory_limit = size_in_bytes / sizeof(cons_cell)\:
               }
              ")
	     )
	 ()))
      )
  (let ((eq
	 (let ((req (fn (req x y)
			(cond ((atom x) (= x y))
			      ((atom y) ())
			      ((req req (car x) (car y))
			       (req req (cdr x) (cdr y)))))))
	   (fn (x y) (req req x y))))
	(repl (fn (repl out in)
		  (cond (out (cons (car out)
				   (repl repl (cdr out) in)))
			('t (let (((expr . rest) (read in)))
			      (cond ((= (car expr) 'error)
				     (repl repl 
					   (append (print_error expr)
						   "\n\r> ")
					   rest))
				    ((eq expr (cons 'symbol "exit")) "Bye\n\r")
				    ('t (repl repl
					      (append (print expr)
						      "\n\r> ")
					      rest)))))))))
    (fn input
	(cons 62 (cons 32 (repl repl () (cdr input)))))))
;  (fn (mem . source)
;      (let (((program . rest) (read source)))
;	(cond ((= (car program) 'error)
;	       (print_error program))
;	      ('t (print (compile program)))))))
