;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Losak Major Mode for Emacs                                      ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Copyright (C) 2011 by Omar Jarjur                               ;;
;;                                                                 ;;
;; This program is free software; you can redistribute it and/or   ;;
;; modify it under the terms of version 2 of the GNU General       ;;
;; Public License as published by the Free Software Foundation.    ;;
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

(defvar lsk-mode-syntax-table
  (let ((lsk-mode-syntax-table (make-syntax-table)))
    (modify-syntax-entry ?_ "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?- "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?+ "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?* "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?/ "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?& "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?| "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?^ "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?~ "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?= "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?< "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?> "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?\? "w" lsk-mode-syntax-table)
    (modify-syntax-entry ?\; "<" lsk-mode-syntax-table)
    (modify-syntax-entry ?\n ">" lsk-mode-syntax-table)
    lsk-mode-syntax-table)
  "Syntax mode for Losak programs")
(defconst lsk-font-lock-defaults
;The following regexpr is generated from the following expression:
;(regexp-opt '("cond" "define" "if" "fn" "let" "quote" "quasiquote" "unquote")
;            t)
  (list '("\\<\\(cond\\|define\\|fn\\|if\\|let\\|\\(?:quasi\\|un\\)?quote\\)\\>"
	  .
	  font-lock-keyword-face)
;The following regexpr is generated from the following expression:
;(regexp-opt '("car" "cdr" "cons" "null?" "number?"
;              "symbol?" "pair?" "function?" "=" "<"
;              ">" "+" "-" "*" "/" "%" "~" "|" "&"
;              "^" ">>" ">>>" "<<")
;            t)
        '("\\(<<\\|>>>?\\|c\\(?:ar\\|dr\\|ons\\)\\|\\(?:function\\|nu\\(?:ll\\|mber\\)\\|pair\\|symbol\\)\\?\\|[%&*+/<=>|~^-]\\)"
	  .
	  font-lock-builtin-face)))

(define-derived-mode lsk-mode lisp-mode "Losak"
  "Major mode for editing Losak programs"
  :syntax-table lsk-mode-syntax-table
  (set (make-local-variable 'font-lock-defaults) '(lsk-font-lock-defaults))
  (setq major-mode 'lsk-mode)
  (setq mode-name "Losak")
  (setq-default indent-tabs-mode nil)
  (run-hooks 'lsk-mode-hook))
(add-to-list 'auto-mode-alist '("\\.lsk\\'" . lsk-mode))

(provide 'lsk-mode)