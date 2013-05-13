#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing bootstrapping the compiler..."
    ./bootstrap.sh
    ./compile.sh src/main.lsk -g main.c
    if [ "$(cat main.c)" = "$(cat port/compiler.c)" ]; then
        ./compile.sh src/symbol-table.lsk -g main.c
        if [ "$(cat main.c)" = "$(cat port/symbol-table.c)" ]; then
	    ./compile.sh src/lambda-lift.lsk -g main.c
	    if [ "$(cat main.c)" = "$(cat port/lambda-lift.c)" ]; then
                ./compile.sh src/codegen.lsk -g main.c
                if [ "$(cat main.c)" = "$(cat port/codegen.c)" ]; then
		    echo $'\tPassed'
		    rm main.c
		    return 0
                else
		    echo "\tFailed: Codegen match failed."
		    rm main.c
		    return 1
                fi
	    else
                echo "\tFailed: Lambda-Lift match failed."
                rm main.c
                return 1
	    fi
        else
	    echo "\tFailed: Symbol-Table match failed."
	    rm main.c
	    return 1
        fi
    else
	echo "\tFailed: Compiler match failed."
	rm main.c
	return 1
    fi
}
run_test

