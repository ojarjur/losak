#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the parse-expr standard library function..."
PROGRAM="
(define initial-reader
  (parse-expr (fn (expression line-number) expression)
              (fn (error-message error-line-number) 'error)
              1))
(define (read string reader)
  (cond ((atom string) reader)
        ((function reader) (read (cdr string) (reader (car string))))
        ('t reader)))
(fn args
  (let ((number-expr (read \"1234\\n\" initial-reader))
        (symbol-expr (read \"abcd\\n\" initial-reader))
        (null-expr (read \"()\" initial-reader))
        (pair-expr (read \"(a b . c)\\n\" initial-reader))
        (unexpected-period (read \".\\n\" initial-reader))
        (missing-tail (read \"(a .)\\n\" initial-reader))
        (too-many-periods (read \"(a . .)\\n\" initial-reader))
        (too-many-tails (read \"(a . b c)\\n\" initial-reader)))
    (if (and (= number-expr 1234)
             (= symbol-expr 'abcd)
             (= null-expr '())
             (equal pair-expr '(a b . c))
             (= unexpected-period 'error)
             (= missing-tail 'error)
             (= too-many-periods 'error))
        \"Yes\"
        \"No\"
        )))"
echo ${PROGRAM} | ./compile.sh - -o bin/test-read-expr
if [ $? ]; then
  EXPECTED="Yes"
  ACTUAL=$(./bin/test-read-expr)
  if [ "$ACTUAL" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed" "$ACTUAL"
    return 1
  fi
  rm bin/test-read-expr
else
  echo "\tBuild Failed"
  return 1
fi

