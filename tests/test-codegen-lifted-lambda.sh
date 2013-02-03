#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program using anonymous methods...'
    echo '
(define fn_0
  (fn fn_0-args
    (let ((callback (car fn_0-args))
          (head (car (cdr fn_0-args))))
      (fn args
        (let ((new-tail (car args))
              (callback-args (cons (cons (car head) new-tail) ())))
          (callback . callback-args))))))
(define append
  (fn args
    (let ((head (car args))
          (tail (car (cdr args)))
          (callback (car (cdr (cdr args)))))
      (if (pair? head)
          (let ((fn_0-args (cons callback (cons head ())))
                (append-args (cons (cdr head)
                                   (cons tail
                                         (cons (fn_0 . fn_0-args) ())))))
            (append . append-args))
          (let ((callback-args (cons tail ())))
            (callback . callback-args))))))
(fn args
  (let ((append-args (cons "Hello, " (cons "World!\n" (cons (fn x (car x)) ())))))
    (append . append-args)))
' | ./bin/codegen | gcc -I include include/*.c -o bin/test-codegen-lifted-lambda -x c -
    if [ $? ]; then
        OUTPUT=`./bin/test-codegen-lifted-lambda`
        EXPECTED='Hello, World!'
        if [ "$OUTPUT" = "$EXPECTED" ]; then
            echo $'\tPassed'
            return 0
        else
            echo $'\tFailed,' "expected \"${EXPECTED}\", but saw \"${OUTPUT}\""
            return 1
        fi
    else
        echo $'\tBuild Failed'
        return 1
    fi
}
run_test