#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the symbol-table support..."
PROGRAM="
(fn args (if (and (atom (string->symbol \"foo\"))
                  (atom 'bar)
                  (= 'abc (string->symbol \"abc\"))
                  (= (string->symbol \"abc\") 'abc)
                  (= (string->symbol \"def\") (string->symbol \"def\")))
             (append (symbol->string 'Hello,)
                     \" \"
                     (symbol->string (string->symbol \"World!\")))
             \"No\"))"
echo ${PROGRAM} | ./compile.sh - -o bin/test-symbol-table
if [ $? ]; then
  EXPECTED="Hello, World!"
  ACTUAL=$(./bin/test-symbol-table)
  if [ "$ACTUAL" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed"
    return 1
  fi
  rm bin/test-symbol-table
else
  echo "\tBuild Failed"
  return 1
fi
