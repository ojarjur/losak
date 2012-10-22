#!/bin/bash
if [ ! -d 'bin' ]; then mkdir bin; fi
for FILE in `find port -name '*.c'`; do
  SOURCE=$(echo ${FILE} | sed 's/port//' | sed 's/\.c/.lsk/')
  TARGET=$(echo ${FILE} | sed 's/port/bin/' | sed 's/\.c//')
  gcc -I include include/*.c ${FILE} -o ${TARGET}
done
for SOURCE in `ls *.lsk`; do
  if [ "${SOURCE}" != "kernel.lsk" ]; then
   TARGET="bin/$(echo ${SOURCE} | sed 's/\.lsk//')"
   echo "Compiling ${SOURCE}"
   ./compile.sh ${SOURCE} -o ${TARGET} || exit 1
  fi
done
