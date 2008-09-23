#!/bin/sh
mzscheme -mv -f port/compiler.scm -e "(and (compile_file \"compiler.lsk\") (exit))" > main.c
gcc *.c -o bootstrap.tmp
./bootstrap.tmp < compiler.lsk > main.c
gcc *.c -o compiler
rm bootstrap.tmp
