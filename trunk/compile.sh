#!/bin/sh
SOURCE=$1
shift 1
ARGS=$@
./bin/desugar < ${SOURCE} | ./bin/compiler > main.c
#./bin/desugar < ${SOURCE} | ./bin/multitask | ./bin/compiler > main.c
#gcc *.c -DNCURSES_CONSOLE -lncurses ${ARGS}
gcc *.c ${ARGS}
