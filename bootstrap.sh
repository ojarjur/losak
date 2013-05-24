#!/bin/bash
if [ ! -d 'bin' ]; then mkdir bin; fi
PORT_FILES='port/compiler.c port/cps-transform.c port/lambda-lift.c port/codegen.c'
for FILE in $(echo ${PORT_FILES}); do
  TARGET=$(echo ${FILE} | sed 's/port/bin/' | sed 's/\.c//')
  gcc -I include include/*.c ${FILE} -o ${TARGET}
done
echo "Compiling main.lsk"
./compile.sh src/main.lsk -o bin/compiler || exit 1
SOURCE_FILES='src/cps-transform.lsk src/lambda-lift.lsk src/codegen.lsk'
for SOURCE in $(echo ${SOURCE_FILES}); do
  TARGET=$(echo ${SOURCE} | sed -e 's/\.lsk//' -e 's/src\//bin\//g')
  echo "Compiling ${SOURCE} to ${TARGET}"
  ./compile.sh ${SOURCE} -o ${TARGET} || exit 1
done
