#!/bin/sh
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the parse-expr standard library function..."
    PROGRAM="
(define initial-reader
  (parse-expr (fn (expression line-number) expression)
              (fn (error-message error-line-number) (fn (char) 'error))
              1))
(define (read string reader)
  (if (and (pair? string) (function? reader))
      (read (cdr string) (reader (car string)))
      reader))
(fn args
  (let ((number-expr (read \"1234\\n\" initial-reader))
        (symbol-expr (read \"abcd\\n\" initial-reader))
        (hex-expr (read \"0x1aF\\n\" initial-reader))
        (negative-expr (read \"-100\\n\" initial-reader))
        (minus-expr (read \"-\\n\" initial-reader))
        (null-expr (read \"()\" initial-reader))
        (pair-expr (read \"(a b . c)\\n\" initial-reader))
        (unexpected-period (read \".\\n\" initial-reader))
        (missing-tail (read \"(a .)\\n\" initial-reader))
        (too-many-periods (read \"(a . .)\\n\" initial-reader))
        (nested-error (read \"(a (b .))\\n\" initial-reader))
        (too-many-tails (read \"(a . b c)\\n\" initial-reader)))
    (if (and (= number-expr 1234)
             (= symbol-expr 'abcd)
             (= hex-expr 431)
             (= negative-expr (- 100))
             (= minus-expr '-)
             (null? null-expr)
             (equal pair-expr '(a b . c))
             (= unexpected-period 'error)
             (= missing-tail 'error)
             (= too-many-periods 'error)
             (= nested-error 'error)
             (= too-many-tails 'error))
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
}
run_test
