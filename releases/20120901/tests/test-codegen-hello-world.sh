#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a 'Hello, World!' sample...'
    echo '(fn (space args) "Hello, World!\n")' | ./bin/codegen > main.c && gcc *.c -o bin/hello
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