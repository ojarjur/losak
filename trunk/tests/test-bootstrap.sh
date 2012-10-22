#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing bootstrapping the compiler..."
./bootstrap.sh
./compile.sh desugar.lsk -g main.c
if [ "$(cat main.c)" = "$(cat port/desugar.c)" ]; then
    ./compile.sh standard-library.lsk -g main.c
    if [ "$(cat main.c)" = "$(cat port/standard-library.c)" ]; then
        ./compile.sh symbol-table.lsk -g main.c
        if [ "$(cat main.c)" = "$(cat port/symbol-table.c)" ]; then
            ./compile.sh lambda-lift.lsk -g main.c
            if [ "$(cat main.c)" = "$(cat port/lambda-lift.c)" ]; then
                ./compile.sh compiler.lsk -g main.c
                if [ "$(cat main.c)" = "$(cat port/compiler.c)" ]; then
                    echo "\tPassed"
                    rm main.c
                    return 0
                else
                    echo "\tFailed: Compiler match failed."
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
        echo "\tFailed: Standard library match failed."
        rm main.c
        return 1
    fi
else
    echo "\tFailed: Desugar match failed."
    rm main.c
    return 1
fi

