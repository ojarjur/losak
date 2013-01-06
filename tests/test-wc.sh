#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the wc sample..."
./compile.sh samples/wc.lsk -o bin/wc
if [ $? ]; then
  OUTPUT=""
  EXPECTED=""
  for NUM in `./bin/wc < samples/wc.lsk`; do
      OUTPUT="${OUTPUT} ${NUM}"
  done
  for NUM in `wc < samples/wc.lsk`; do
      EXPECTED="${EXPECTED} ${NUM}"
  done
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