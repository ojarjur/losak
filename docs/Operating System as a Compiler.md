# Background

This is the initial concept behind the LOSAK project. This was
originally posted as a comment on a SlashDot thread
[here](http://slashdot.org/comments.pl?sid=134235&cid=11204417).

# Operating Systems as Compilers

I think of operating systems as being special cases of programming 
languages. The environment that programs run in is the language and the 
operating system that implements that environment is the language 
interpreter.

When you view it from this perspective, Unix (And every single other 
major operating system) is an interpreted language. The obvious 
improvement then would be to create a "compiler" for that language. This 
could be implemented with a partial evaluator. Run the partial evaluator 
on the operating system with the programs that you want compiled in 
passed as parameters, and you get back an operating system that has your 
programs built into it.

Since this doesn't violate the separation between the OS and application 
layers, it SHOULD have the security/stability of a microkernel operating 
system. At the same time, because the applications are compiled into the 
operating system, you should have the performance of a monolithic kernel 
operating system.

The problem with this idea though (when applied to Unix) is that partial 
evaluators for assembly language are hell to write. An operating system 
written in a higher level language (LISP, Haskell, ML, Prolog, etc) 
will have an easier time of providing this.
