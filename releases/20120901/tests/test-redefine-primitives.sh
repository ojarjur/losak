#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing the ability to redefine primitive functions...'
    echo '
(define (cons x y) (+ x y))
(fn (size args) (list (cons 97 0) (cons 97 1) (cons 97 2) (cons 97 3) 10))
' | ./compile.sh - -o bin/test-redefine-primitives
    if [ $? ]; then
        OUTPUT=`./bin/test-redefine-primitives`
        EXPECTED='abcd'
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