#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program with let expressions ...'
    echo '
(define append
  (fn a1
      (let ((x1 (car a1))
            (x2 (car (cdr a1)))
            (cont (car (cdr (cdr a1)))))
        (if (pair? x1)
            (let ((car_x1 (car x1))
                  (cdr_x1 (cdr x1))
                  (cont (fn a2 (let ((xs (car a2))
                                     (xs2 (cons car_x1 xs))
                                     (cont-args (cons xs2 ())))
                                 (cont . cont-args))))
                  (append_args (cons cdr_x1 (cons x2 (cons cont ())))))
              (append . append_args))
            (let ((cont-args (cons x2 ())))
              (cont . cont-args))))))
(fn args
  (let ((append-args (cons "Hello,"
                           (cons " World!\n"
                                 (cons (fn a2 (car a2)) ())))))
    (append . append-args)))
' | ./bin/codegen | gcc -I include include/*.c -o bin/hello -x c -
    if [ $? ]; then
        OUTPUT=`./bin/hello`
        EXPECTED='Hello, World!'
        if [ "$OUTPUT" = "$EXPECTED" ]; then
            echo $'\tPassed'
            return 0
        else
            echo $'\tFailed; expected' "$EXPECTED" 'but saw' "$OUTPUT" 
            return 1
        fi
    else
        echo $'\tBuild Failed'
        return 1
    fi
}
run_test