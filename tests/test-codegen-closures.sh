#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program using anonymous methods...'
    echo '
(define append
  (fn args
    (let ((head (car args))
          (tail (car (cdr args)))
          (callback (car (cdr (cdr args)))))
      (if (pair? head)
          (let ((append-args (cons (cdr head)
                                   (cons tail
                                         (cons (fn args
                                                   (let ((new-tail (car args))
                                                         (callback-args (cons (cons (car head) new-tail) ())))
                                                     (callback . callback-args))))))))
            (append . append-args))
          (let ((callback-args (cons tail ())))
            (callback . callback-args))))))
(fn main-args
  (let ((size (car main-args))
        (args (car (cdr main-args)))
        (append-args (cons "Hello, "
                           (cons "World!\n"
                                 (cons (fn x (car x)) ())))))
    (append . append-args)))
' | ./bin/codegen | gcc -I include include/*.c -o bin/test-codegen-closures -x c -
    if [ $? ]; then
        OUTPUT=`./bin/test-codegen-closures`
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