#!/bin/bash
if [ ! -d 'bin' ]; then mkdir bin; fi
for FILE in `find port -name '*.c'`; do
  SOURCE=$(echo ${FILE} | sed 's/port//' | sed 's/\.c/.lsk/')
  TARGET=$(echo ${FILE} | sed 's/port/bin/' | sed 's/\.c//')
  cp ${FILE} main.c
  gcc *.c -o ${TARGET}
done
for SOURCE in `ls *.lsk`; do
  if [ "${SOURCE}" != "kernel.lsk" ]; then
   TARGET="bin/$(echo ${SOURCE} | sed 's/\.lsk//')"
   ./compile.sh ${SOURCE} -o ${TARGET}
  fi
done
