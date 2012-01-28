#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing bootstrapping the compiler..."
./bootstrap.sh
./compile.sh desugar.lsk -o bin/desugar
if [ "$(cat main.c)" = "$(cat port/desugar.c)" ]; then
    ./compile.sh standard-library.lsk -o bin/standard-library
    if [ "$(cat main.c)" = "$(cat port/standard-library.c)" ]; then
        ./compile.sh symbol-table.lsk -o bin/symbol-table
        if [ "$(cat main.c)" = "$(cat port/symbol-table.c)" ]; then
            ./compile.sh lambda-lift.lsk -o bin/lambda-lift
            if [ "$(cat main.c)" = "$(cat port/lambda-lift.c)" ]; then
                ./compile.sh compiler.lsk -o bin/compiler
                if [ "$(cat main.c)" = "$(cat port/compiler.c)" ]; then
                    echo "\tPassed"
                    return 0
                else
                    echo "\tFailed: Compiler match failed."
                    return 1
                fi
            else
                echo "\tFailed: Lambda-Lift match failed."
                return 1
            fi
        else
            echo "\tFailed: Symbol-Table match failed."
            return 1
        fi
    else
        echo "\tFailed: Standard library match failed."
        return 1
    fi
else
    echo "\tFailed: Desugar match failed."
    return 1
fi
