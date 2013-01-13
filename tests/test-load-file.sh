#!/bin/sh
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the sample that loads definitions from another file..."
    ./compile.sh samples/load-sample.lsk -o bin/load-sample
    if [ $? ]; then
	OUTPUT=`./bin/load-sample`
	EXPECTED="Hello, World!
...
Goodbye, Cruel World!"
	if [ "$OUTPUT" = "$EXPECTED" ]; then
	    echo "\tPassed"
	    return 0
	else
	    echo "\tFailed"  $OUTPUT
	    return 1
	fi
    else
	echo "\tBuild Failed"
	return 1
    fi
}
run_test