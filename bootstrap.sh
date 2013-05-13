#!/bin/bash
PORT_FILES='port/compiler.c port/symbol-table.c port/cps-transform.c port/lambda-lift.c port/codegen.c'
SOURCE_FILES='src/symbol-table.lsk src/cps-transform.lsk src/lambda-lift.lsk src/codegen.lsk'
if [ ! -d 'bin' ]; then mkdir bin; fi
for FILE in $(echo ${PORT_FILES}); do
  TARGET=$(echo ${FILE} | sed 's/port/bin/' | sed 's/\.c//')
  gcc -I include include/*.c ${FILE} -o ${TARGET}
done
echo "Compiling main.lsk"
./compile.sh src/main.lsk -o bin/compiler || exit 1
for SOURCE in $(echo ${SOURCE_FILES}); do
  TARGET="bin/$(echo ${SOURCE} | sed 's/\.lsk//')"
  echo "Compiling ${SOURCE}"
  ./compile.sh ${SOURCE} -o ${TARGET} || exit 1
done
