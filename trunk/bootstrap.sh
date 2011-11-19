#!/bin/sh
if [ ! -d 'bin' ]; then mkdir bin; fi
cp port/desugar.c main.c
gcc *.c -o bin/desugar
cp port/standard-library.c main.c
gcc *.c -o bin/standard-library
cp port/symbol_table.c main.c
gcc *.c -o bin/symbol-table
cp port/lambda-lift.c main.c
gcc *.c -o bin/lambda-lift
cp port/compiler.c main.c
gcc *.c -o bin/compiler
./compile.sh desugar.lsk -o bin/desugar
./compile.sh standard-library.lsk -o bin/standard-library
./compile.sh symbol-table.lsk -o bin/symbol-table
./compile.sh lambda-lift.lsk -o bin/lambda-lift
./compile.sh compiler.lsk -o bin/compiler
./compile.sh multitask.lsk -o bin/multitask