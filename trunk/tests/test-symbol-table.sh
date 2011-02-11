PROGRAM="(define (rreverse list result return)
  (cond ((atom list) (return result))
        ('t (rreverse (cdr list) (cons (car list) result) return))))
(define (reverse list) (rreverse list '() (fn (x) x)))
(define (foldl merge end)
  (fn (list)
      (cond ((atom list) end)
            ('t ((foldl merge (merge (car list) end)) (cdr list))))))
(define (foldr merge end)
  (fn (list) (rreverse list '() (foldl merge end))))
(define (append . args) ((foldr (fn (x xs)
                                    (cond ((= xs '()) x)
                                          ('t ((foldr cons xs) x))))
                                '()) args))
(fn args (append (symbol->string (string->symbol \"Hello,\"))
                 \" \"
                 (symbol->string (string->symbol \"World!\"))))"
#echo ${PROGRAM} | ./bin/symbol-table
echo ${PROGRAM} | ./bin/symbol-table | ./bin/desugar | ./bin/compiler > main.c
gcc *.c -o bin/test-symbol-table
EXPECTED="Hello, World!"
ACTUAL=$(./bin/test-symbol-table)
if [[ ${ACTUAL} == ${EXPECTED} ]]; then
    echo PASSED
else
    echo FAILED ${ACTUAL} ${EXPECTED}
fi
rm bin/test-symbol-table
