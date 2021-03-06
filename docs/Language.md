# Lisp Operating System, Abstraction Kernel
# Programming Language Description
		
(Copyright (C) 2004 - 2012 by Omar Jarjur)

## Overview

The language implemented by the system is a purely functional 
dialect of Lisp. It uses static scope and an eager evaluation
strategy. It also provides fixed precision integer arithmetic
operations. The mainstream dialect that it most closely resembles is
probably Scheme.

A losak program is repeatedly evaluated with the result being used
for I/O. Specifically, if a program evaluates to a function then the
next input event (or null if no such events are available and the program
was compiled without multitasking support) is passed to this function as a
parameter and evaluation continues. Otherwise, if a program evaluates to a
pair, the head of the pair is executed as an output event, and the tail of
the pair is evaluated as the remainder of the computation.

## Kernel Parameters

Although subsequent stages of the process take a single parameter,
the first value that a program evaluates to is a function that takes two
parameters; one for the number of available cons cells, and the second for
the parameter string. The parameter string is a list of integers, with each
integer representing the ascii value of a character in the string.

## System Input

Each of the system input events have the following form. If it is (), then
no new input is available yet. If it is a number, then it is a keycode
received from the keyboard. Otherwise, it should be a pair of numbers,
where the first number is an I/O port and the second number is the value
in that port.

## Output Events

If an output event is a number, then it is treated as a character to
write to stdout (or the text console in the case of Bare x86). Otherwise,
the car of the output event is treated as a message to the host system. Those
messages are treated by the host system depending on their type according to
the following table (Here, fixed size lists are denoted using parentheses, and
arbitrary sized lists are denoted using square brackets):

                      | Bare x86                 | Hosted on a Unix-like OS        
    -------------------------------------------------------------------------------
    Number            | Write to the screen      | Write to stdout                 
    (Number)          | Read from memory         | Close a file handle             
    (Number . Number) | Write to memory          | Write a char to a file handle   
    (Number Number)   | Read bytes from a port   | Read a string from file handle  
    (Number [Number]) | Write bytes to a port    | Write a string to a file handle 
    ([Number] Number) |                          | Open a file handle              
    -------------------------------------------------------------------------------

## Multitasking

Losak programs can be compiled in multitasking mode by passing the "-m"
parameter to the compiler. This adds the ability to run multiple concurrent
threads in the program.

Child threads are forked by evaluating to a pair of the definition of the
child thread, and the subsequent value of the parent thread. The child thread
is defined using a list of the child thread's ID, the amount of memory
allocated to it, and the child thread's initial value.

A thread can send a message to another thread by evaluating to a pair of
the message and the thread's subsequent value. If the message is a single
element list, then that element is sent to the thread's parent. If the message
is a two element list, then the first element identifies a child thread, and
the second element is a value to be sent to that child thread.

The root thread is considered to have the host system as its parent. Thus,
system input events are sent to the top-level thread, and messages sent by that
thread to its parent are treated as system output events.

## Language Constructs

A program consists of zero or more definitions followed by an expression.
Any malformed expressions evaluate to ().

Each primitive is a function except for define, quote, quasiquote, unquote,
fn, if, cond, and let.

Each parameter to a function is evaluated before that function is applied
to it. Pattern matching is used both in let expressions and in function
application. So, for example "((fn ((a . b) c) (cons a c)) '(1 . 2) 3)"
evaluates to "(1 . 3)".

Syntactic sugar is provided for defining quoted expressions and for quoted
lists of integers. '<X> is equivalent to (quote <X>), `<X> is equivalent to
(quasiquote <X>), ,<X> is equivalent to (unquote <X>), and "<X><Y><Z>" is
equivalent to (quote (<#X> <#Y> <#Z>)) where <#X> is the ascii value of the
character <X>. So "hello" will be parse as (quote (104 101 108 108 111)).

    (define (<NAME> . <ARGS>) <BODY>) : Add a new function with the name
          <NAME>, arg list of <ARGS>, and body of <BODY> to the global
          definitions. This is only allowed at the top level; anywhere else
          it will simply evaluate to ().
    (define <NAME> <EXPR>) : Evaluate <EXPR> and add it to the global
          definitions with the name <NAME>. This is only allowed at the top
          level; anywhere else it will simply evaluate to ().
    (quote <X>) or '<X> : Return <X> without evaluating it.
    (quaisquote <X>) or `<X> : Return <X> without evaluating it, except for
          subexpressions preceeded by a , or unquote.
    (unquote <X>) or ,<X> : Evaluate <X> even if it is inside of a quasiquote.
    (fn <ARGS> <EXPR>) : Return a static scoped function with the argument
          list <ARGS> and the value <EXPR>.
    (if <TEST> <THEN> <ELSE>) : Evaluate <TEST>. If it returned any value
          other than (), then evaluate <THEN> and return its value. Otherwise,
          evaluate <ELSE> and return its value.
    (cond (<T1> <E1>) (<T2> <E2>) ...) : Repeatedly evaluate a <TN> until 
          one of them returns a value other than (). At that 
          point evaluate the corresponding <EN> and return its 
          value. If every <TN> returns (), then return ().
    (let ((<VAR1> <VAL1>) (<VAR2> <VAL2>) ... ) <EXPR>):
         Evaluate each <VALN> and bind its value to the 
         corresponding <VARN>. Then evaluate <EXPR> in the new
         environment and return its value.
    (<FN> . <ARGS>) : If <FN> is a function then evaluate 
         <ARGS> and apply the function to it. Otherwise 
         return ().
    (cons <X> <Y>) : Return the pair (<X> . <Y>)
    (car <X>) : If <X> is a pair return its first element. Otherwise return ().
    (cdr <X>) : If <X> is a pair return its second element. Otherwise return ().
    (null? <X>) : If <X> is null return a non-nil value. Otherwise return ().
    (pair? <X>) : If <X> is a pair return a non-nil value. Otherwise return ().
    (symbol? <X>) : If <X> is a symbol return a non-nil value. Otherwise return ().
    (number? <X>) : If <X> is a number return a non-nil value. Otherwise
          return ().
    (function? <X>) : If <X> is a function return a non-nil value. Otherwise
          return ().
    (= <X> <Y>) : Return a non-nil value if <X> and <Y> are the same number or
          the same symbol. Otherwise return ().
    (< <X> <Y>) : Return a non-nil value if <X> and <Y> are numbers and <X> is
          less than <Y>, or if <X> and <Y> are symbols and <X> 
          alphabetically precedes <Y> (In terms of ASCII characters).
          Otherwise return ().
    (> <X> <Y>) : Return a non-nil value if <X> and <Y> are numbers and <X> is
          greater than <Y>, or if <X> and <Y> are symbols and <X> 
          alphabetically follows <Y> (In terms of ASCII characters).
          Otherwise return ().
    (+ <X> <Y>) : Return the sum of the two numbers <X> and <Y>.
    (- <X>) : Return the negation of <X>.
    (- <X> <Y>) : Return the difference of the two numbers <X> and <Y>.
    (* <X> <Y>) : Return the product of the two numbers <X> and <Y>.
    (/ <X> <Y>) : Return the integer quotient of <X> divided by <Y>.
    (% <X> <Y>) : Return the integer remainder of <X> divided by <Y>.
    (>> <X> <Y>) : Signed right shift of <X> by <Y> places.
    (>>> <X> <Y>) : Unsigned right shift of <X> by <Y> places.
    (<< <X> <Y>) : Left shift of <X> by <Y> places.
    (& <X> <Y>) : Return the bitwise and of <X> and <Y>.
    (| <X> <Y>) : Return the bitwise or of <X> and <Y>.
    (^ <X> <Y>) : Return the bitwise xor of <X> and <Y>.
    (~ <X>) : Return the bitwise negation of <X>.
