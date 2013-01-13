#!/bin/sh
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the undefined global warning..."
    COMPILER_OUT=`echo "\
(define (foo x) (cons x bar))\
(fn args (if (cdr (foo 1))\
             \"No\"\
             (if (car (foo 1))\
                 \"Yes\"\
                 \"No\")))\
" | ./compile.sh - -o bin/global-warning 2>&1`
    EXPECTED_COMPILER_OUT="WARNING; In expression beginning on line 1: Unknown var \"bar\" will evaluate to NIL."
    if [ $? ]; then
	OUTPUT=`./bin/global-warning`
	EXPECTED='Yes'
	if [ "${COMPILER_OUT}" = "${EXPECTED_COMPILER_OUT}" ]; then
	    if [ "${OUTPUT}" = "${EXPECTED}" ]; then
		echo "\tPassed"
		return 0
	    else
		echo "\tFailed"
		return 1
	    fi
	else
	    echo "\tFailed"
	    return 1
	fi
    else
	echo "\tBuild Failed"
	return 1
    fi
}
run_test