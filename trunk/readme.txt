Project Overview:
    This project aims to write a Lisp operating system to 
run on general purpose hardware.

Directory Contents:
    .................
    . Documentation .
    .................
    language.txt: Specifies the programming language used
    license.txt: GPL
    readme.txt: This file
    lsk-mode.el: Emaacs Lisp script defining a mode for Losak files

    ..................
    . Losak Compiler .
    ..................
    compile.sh: The lisp to C compiler
    compiler.lsk: The compiler backend
    desugar.lsk: The first pass of the compiler, which removes syntactic sugar
    lambda-lift.lsk: Compiler pass that performs lambda lifting
    multitask.lsk: Compiler pass that implements multitasking
    symbol-table.lsk: Compiler pass that adds run time symbol support
    standard-library.lsk: Compiler pass that adds standard library support

    ......................
    . Sample source code .
    ......................
    kernel.lsk: Simple OS written in Losak
    samples/* : Sample Losak programs

    .........................
    . Bootstrapping support .
    .........................
    port/*: Generated C output of compiling the lisp compiler.
    bootstrap.sh: Script that bootstraps the compiler. This requires
                  having GCC installed

    ..................
    . C Source files .
    ..................
    Makefile: Specifies the build process
    boot.S: Assembly language code to boot the OS
    console.*: Provides console I/O
    eval.*: Evaluate s-expressions
    io.*: General purpose I/O
    mem.*: Memory management
    multiboot.h: Access to multiboot data

Building the OS:
    To build the executable:
        make

    To clean build files:
        make clean

    The generated binary for the OS is written to the file kImage
