#!/bin/sh
cp port/desugar.c main.c
gcc *.c -o bin/desugar
cp port/compiler.c main.c
gcc *.c -o bin/compiler
./compile.sh compiler.lsk -o bin/compile
./compile.sh desugar.lsk -o bin/desugar
