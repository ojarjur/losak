#!/bin/sh
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the stderr sample..."
    ./compile.sh samples/stderr.lsk -o bin/stderr
    if [ $? ]; then
	OUTPUT1=`./bin/stderr 2> /dev/null`
	EXPECTED1='Hello, World!'
	OUTPUT2=`./bin/stderr 2>&1`
	EXPECTED2='Hello, World!Error: Goodbye, cruel World!'
	if [ "${OUTPUT1}" = "${EXPECTED1}" ]; then
	    if [ "${OUTPUT2}" = "${EXPECTED2}" ]; then
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