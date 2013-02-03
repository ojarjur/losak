#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo 'Testing code generation of a program using if statements...'
    echo '
(fn args
    (if (pair? (cons 1 2))
        (if (pair? "")
            "No\n"
            (if (number? 1)
                (if (number? "")
                    "No\n"
                    (if (function? (fn x x))
                        (if (function? "")
                            "No\n"
                            "Yes\n")
                        "No\n"))
                "No\n"))
        "No\n"))' | ./bin/codegen | gcc -I include include/*.c -o bin/test-codegen-if -x c -
    if [ $? ]; then
        OUTPUT=`./bin/test-codegen-if`
        EXPECTED='Yes'
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