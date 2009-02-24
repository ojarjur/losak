#!/bin/sh
SOURCE=$1
shift 1
ARGS=$@
./compiler < ${SOURCE} > main.c
#gcc *.c -lncurses ${ARGS}
gcc *.c ${ARGS}
