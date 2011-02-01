#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing bootstrapping the compiler..."
./bootstrap.sh
./compile.sh compiler.lsk -o bin/compiler
EXPECTED_COMPILER_SOURCE=`cat main.c`
./compile.sh desugar.lsk -o bin/desugar
EXPECTED_DESUGAR_SOURCE=`cat main.c`
./compile.sh compiler.lsk -o bin/compiler
if [ "$EXPECTED_COMPILER_SOURCE" = "$(cat main.c)" ]; then
    ./compile.sh desugar.lsk -o bin/desugar
    if [ "$EXPECTED_DESUGAR_SOURCE" = "$(cat main.c)" ]; then
        echo "\tPassed"
        return 0
    else
        echo "\tFailed: Desugar match failed."
        return 1
    fi
else
    echo "\tFailed: Compiler match failed."
    return 1
fi
