#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program using anonymous methods...'
    echo '
(define closure (fn arg1 (fn arg2 (car arg1))))
(fn args
    (let ((closure-args (cons "Hello, World!\n" ()))
          (callback (closure . closure-args))
          (callback-args (cons "Goodbye, Cruel World!\n" ())))
      (callback . callback-args)))
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