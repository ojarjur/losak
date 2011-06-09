#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing code generation of a 'Hello, World!' sample..."
    echo "(define (write-chars chars callback . callback-args)
  (if (atom chars)
      (callback . callback-args)
      (write-output (car chars) write-chars (cons (cdr chars) (cons callback callback-args)))))
(write-chars (cons 72 (cons 101 (cons 108 (cons 108 (cons 111 (cons 44 (cons 32 (cons 87 (cons 111 (cons 114 (cons 108 (cons 100 (cons 92 (cons 33 (cons 10 '())))))))))))))))
             exit)
" | ./bin/codegen > main.c && gcc *.c -o bin/hello
    if [ $? ]; then
        OUTPUT=`./bin/hello`
        EXPECTED='Hello, World!'
        if [ "$OUTPUT" = "$EXPECTED" ]; then
            echo $'\tPassed'
            return 0
        else
            echo $'\tFailed'
            return 1
        fi
    else
        echo $'\tBuild Failed'
        return 1
    fi
}
run_test