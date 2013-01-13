#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the cat sample..."
    ./compile.sh samples/cat.lsk -o bin/cat
    if [ $? ]; then
	OUTPUT=`./bin/cat < samples/cat.lsk`
	EXPECTED=`cat samples/cat.lsk`
	if [ "$OUTPUT" = "$EXPECTED" ]; then
	    echo $'\tPassed'
	    return 0
	else
	    echo $'\tFailed'
	    return 1
	fi
    else
	echo $'\tBuild Failed'
	return 1
    fi
}
run_test