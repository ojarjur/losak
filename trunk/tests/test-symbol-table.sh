#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing the symbol-table support..."
PROGRAM="(define (rreverse list result return)
  (cond ((atom list) (return result))
        ('t (rreverse (cdr list) (cons (car list) result) return))))
(define (reverse list) (rreverse list '() (fn (x) x)))
(define (foldl merge end)
  (fn (list)
      (cond ((atom list) end)
            ('t ((foldl merge (merge (car list) end)) (cdr list))))))
(define (foldr merge end)
  (fn (list) (rreverse list '() (foldl merge end))))
(define (append . args) ((foldr (fn (x xs)
                                    (cond ((= xs '()) x)
                                          ('t ((foldr cons xs) x))))
                                '()) args))
(fn args (append (symbol->string 'Hello,)
                 \" \"
                 (symbol->string (string->symbol \"World!\"))))"
echo ${PROGRAM} | ./bin/symbol-table | ./bin/desugar | ./bin/compiler > main.c
gcc *.c -o bin/test-symbol-table
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
