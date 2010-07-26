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

	.....................
	. Losak source code .
	.....................
	kernel.lsk: The lisp portion of the OS
    compiler.lsk: The lisp to C compiler
    samples/* : Sample Losak programs

    .........................
    . Bootstrapping support .
    .........................
    port/compiler.scm: The lisp to C compiler written in Scheme
    bootstrap.sh: Script that bootstraps the compiler, writing the
                  output to the binary file "compiler". This requires
                  having MzScheme and GCC installed

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
