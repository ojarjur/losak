#!/bin/sh
SOURCE=$1
shift 1
ARGS=$@
./bin/compiler < ${SOURCE} > main.c
#gcc *.c -DNCURSES_CONSOLE -lncurses ${ARGS}
gcc *.c ${ARGS}
