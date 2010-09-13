#!/bin/sh
SOURCE=$1
shift 1
ARGS=$@
./bin/desugar < ${SOURCE} > bin/temp
./bin/compiler < bin/temp > main.c
rm bin/temp
#gcc *.c -DNCURSES_CONSOLE -lncurses ${ARGS}
gcc *.c ${ARGS}
