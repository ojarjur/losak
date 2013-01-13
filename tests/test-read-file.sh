#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the read-file sample..."
    ./compile.sh samples/read-file.lsk -o bin/read-file
    if [ $? ]; then
	OUTPUT=`./bin/read-file samples/read-file.lsk`
	EXPECTED=`cat samples/read-file.lsk`
	if [ "${OUTPUT}" = "${EXPECTED}" ]; then
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