#!/bin/bash
# This is meant to be run from the root of the losak source directory.
function run_test() {
    echo "Testing the symbol-table support..."
    PROGRAM="
(fn args (if (and (symbol? (string->symbol \"foo\"))
                  (symbol? 'bar)
                  (not (= 'pair? '_pair?))
                  (not (= '= '_=))
                  (not (= 'equal '_equal))
                  (= 'abc (string->symbol \"abc\"))
                  (= (string->symbol \"abc\") 'abc)
                  (= (string->symbol \"def\") (string->symbol \"def\"))
                  (equal \"pair?\" (symbol->string 'pair?))
                  (equal \"_pair?\" (symbol->string '_pair?)))
             (append (symbol->string 'Hello,)
                     \" \"
                     (symbol->string (string->symbol \"World!\")))
             \"No\"))"
    echo ${PROGRAM} | ./compile.sh - -o bin/test-symbol-table
    if [ $? ]; then
	EXPECTED="Hello, World!"
	ACTUAL=$(./bin/test-symbol-table)
	if [ "$ACTUAL" = "$EXPECTED" ]; then
	    echo $'\tPassed'
	    return 0
	else
	    echo $'\tFailed'
	    return 1
	fi
	rm bin/test-symbol-table
    else
	echo $'\tBuild Failed'
	return 1
    fi
}
run_test
