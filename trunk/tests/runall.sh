#!/bin/sh
# Meant to be run from the root of the losak source directory.
PASSED=0
FAILED=0
for FILE in `ls tests/test*.sh`; do
  ${FILE}
  if [ $? ]; then
      PASSED=`expr $PASSED + 1`
  else
      FAILED=`expr $FAILED + 1`
  fi
done
echo "PASSED: ${PASSED}, FAILED: ${FAILED}"
