#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing support for multiple definitions..."
SOURCE="(define message \"Goodbye, Cruel World!\")
(define message \"Hello, World!\")
(fn args message)"
echo ${SOURCE} | ./bin/symbol-table | ./bin/desugar | ./bin/compiler > main.c
gcc *.c -o bin/test-duplicate-defines
if [ $? ]; then
  OUTPUT=`./bin/test-duplicate-defines`
  EXPECTED='Hello, World!'
  if [ "$OUTPUT" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed"
    return 1
  fi
  rm bin/test-duplicate-defines
else
  echo "\tBuild Failed"
  return 1
fi