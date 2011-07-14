#!/bin/sh
SOURCE=$1
shift 1
ARGS=$@
if [ "$SOURCE" = "-" ]; then
    ./bin/desugar | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > main.c
else
    ./bin/desugar < ${SOURCE} | ./bin/symbol-table | ./bin/lambda-lift | ./bin/compiler > main.c
fi
gcc *.c ${ARGS}
