#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the capitalize sample..."
./compile.sh samples/capitalize.lsk -o bin/capitalize
if [ $? ]; then
  OUTPUT=`./bin/capitalize < samples/capitalize.lsk`
  EXPECTED=`tr [a-z] [A-Z] < samples/capitalize.lsk`
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