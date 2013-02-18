#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program with let expressions ...'
    echo '
(fn args
  (let ((newline "\n")
        (s (cons (car "s") newline))
        (es (cons (car "e") s))
        (Yes (cons (car "Y") es)))
    Yes))
' | ./bin/codegen | gcc -I include include/*.c -o bin/test-codegen-let -x c -
    if [ $? ]; then
        OUTPUT=`./bin/test-codegen-let`
        EXPECTED='Yes'
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