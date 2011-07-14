#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing bootstrapping the compiler..."
./bootstrap.sh
./compile.sh compiler.lsk -o bin/compiler
EXPECTED_COMPILER_SOURCE=`cat main.c`
./compile.sh desugar.lsk -o bin/desugar
EXPECTED_DESUGAR_SOURCE=`cat main.c`
./compile.sh symbol-table.lsk -o bin/symbol-table
EXPECTED_SYMBOL_TABLE_SOURCE=`cat main.c`
./compile.sh lambda-lift.lsk -o bin/lambda-lift
EXPECTED_LAMBDA_LIFT_SOURCE=`cat main.c`
./compile.sh compiler.lsk -o bin/compiler
if [ "$EXPECTED_COMPILER_SOURCE" = "$(cat main.c)" ]; then
    ./compile.sh desugar.lsk -o bin/desugar
    if [ "$EXPECTED_DESUGAR_SOURCE" = "$(cat main.c)" ]; then
        ./compile.sh symbol-table.lsk -o bin/symbol-table
        if [ "$EXPECTED_SYMBOL_TABLE_SOURCE" = "$(cat main.c)" ]; then
            ./compile.sh lambda-lift.lsk -o bin/lambda-lift
            if [ "$EXPECTED_LAMBDA_LIFT_SOURCE" = "$(cat main.c)" ]; then
                echo "\tPassed"
                return 0
            else
                echo "\tFailed: Lambda-Lift match failed."
                return 1
            fi
        else
            echo "\tFailed: Symbol-Table match failed."
            return 1
        fi
    else
        echo "\tFailed: Desugar match failed."
        return 1
    fi
else
    echo "\tFailed: Compiler match failed."
    return 1
fi
