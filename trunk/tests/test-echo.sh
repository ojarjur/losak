#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the echo sample..."
./compile.sh samples/echo.lsk -o bin/echo
if [ $? ]; then
  OUTPUT=`./bin/echo Hello, World\!`
  EXPECTED='Hello, World!'
  if [ "$OUTPUT" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed"
    return 1
  fi
else
  echo "\tBuild Failed"
  return 1
fi