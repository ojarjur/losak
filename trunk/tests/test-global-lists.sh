#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing support for multiple definitions..."
SOURCE="(define (foldl merge end)
  (fn (list)
      (cond ((atom list) end)
            ('t ((foldl merge (merge (car list) end)) (cdr list))))))
(define (reverse list) ((foldl cons ()) list))
(define (foldr merge end)
  (fn (list) ((foldl merge end) (reverse list))))
(define (append . args) ((foldr (fn (x xs)
                                    (cond ((= xs '()) x)
                                          ('t ((foldr cons xs) x))))
                                '()) args))
(define messages
  '(\"Hello, World!\" \"Goodbye, Cruel World!\"))
(fn args ((foldr (fn (message output) (append message \"\\n\" output)) \"\") messages))"
echo ${SOURCE} | ./bin/desugar | ./bin/symbol-table | ./bin/compiler > main.c
gcc *.c -o bin/test-global-lists
if [ $? ]; then
  OUTPUT=`./bin/test-global-lists`
  EXPECTED=$'Hello, World!\nGoodbye, Cruel World!'
  if [ "$OUTPUT" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed"
    return 1
  fi
  rm bin/test-global-lists
else
  echo "\tBuild Failed"
  return 1
fi