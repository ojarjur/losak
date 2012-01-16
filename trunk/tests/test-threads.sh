#!/bin/sh
# This is meant to be run from the root of the losak source directory.
echo "Testing forking a child thread..."
echo "(define (list . args) args)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Functions for inter-process I/O ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (fork id space child continuation)
  (cons (list id space child) continuation))
(define (send-to-parent msg continuation)
  (cons (list msg) continuation))
(define (send-to-child child-id msg continuation)
  (cons (list child-id msg) continuation))

(define (echo-thread space)
  (fn (message)
      (send-to-parent (append (print space) message) '())))
(define (read-response msg)
  (if (atom msg) read-response msg))
(fn (space args)
    (fork 'child 100 echo-thread
          (send-to-child 'child \"Done\n\" read-response)))
" | ./compile.sh -m -o bin/thread-test -
if [ $? ]; then
  OUTPUT=`./bin/thread-test`
  EXPECTED='100Done'
  if [ "$OUTPUT" = "$EXPECTED" ]; then
    echo "\tPassed"
    return 0
  else
    echo "\tFailed" "${OUTPUT}"
    return 1
  fi
else
  echo "\tBuild Failed"
  return 1
fi