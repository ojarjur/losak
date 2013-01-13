#!/bin/sh
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the quine sample..."
    ./compile.sh samples/quine.lsk -o bin/quine
    if [ $? ]; then
	OUTPUT=`./bin/quine`
	EXPECTED=`cat samples/quine.lsk`
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
}
run_test