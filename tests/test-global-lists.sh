#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing support for global list definitions..."
    SOURCE="(define (list . elements) elements)
(define (foldl merge end)
  (fn (list)
      (cond ((pair? list) ((foldl merge (merge (car list) end)) (cdr list)))
            ('t end))))
(define (reverse list) ((foldl cons ()) list))
(define (foldr merge end)
  (fn (list) ((foldl merge end) (reverse list))))
(define (append . args) ((foldr (fn (x xs)
                                    (cond ((null? xs) x)
                                          ('t ((foldr cons xs) x))))
                                '()) args))
(define messages
  (list \"Hello, World!\" \"Goodbye, Cruel World!\"))
(fn args ((foldr (fn (message output) (append message \"\\n\" output)) \"\") messages))"
    echo ${SOURCE} | ./compile.sh - -o bin/test-global-lists
    if [ $? ]; then
	OUTPUT=`./bin/test-global-lists`
	EXPECTED="Hello, World!
Goodbye, Cruel World!"
	if [ "$OUTPUT" = "$EXPECTED" ]; then
	    echo $'\tPassed'
	    return 0
	else
	    echo $'\tFailed'
	    return 1
	fi
	rm bin/test-global-lists
    else
	echo $'\tBuild Failed'
	return 1
    fi
}
run_test