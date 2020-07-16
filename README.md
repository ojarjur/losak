# LOSAK: Lisp Operating System, Abstraction Kernel

## Overview:

This project is an operating system kernel implemented as the
compiler for a custom dialect of Lisp.

## Building the included, sample OS:

To build the executable:

```sh        
make
```

To clean build files:

```sh
make clean
```

The generated binary for the OS is written to the file bin/kImage.
    
This is a multiboot compatible binary, and can be loaded on via the
grub bootloader, or can be run inside of qemu using the command:

```sh
make bin/kImage
qemu-system-i386 -m size=10 -kernel bin/kImage
```

## Directory Contents:

### Documentation
    
* README.md: This file
* license.txt: GPL
* lsk-mode.el: Emaacs Lisp script defining a mode for Losak files
* docs/Language.md: Specifies the programming language used
* docs/Overview.md: Provides more background on the project
* docs/Operating System as a Compiler.md: Original concept behind the project

### Losak Compiler

* src/compile.sh: The lisp to C compiler
* src/codegen.lsk: The final pass of the compiler, which generates the C code
* src/cps-transform.lsk: Compiler pass that implements a CPS transformation
* src/desugar.lsk: The first pass of the compiler, which removes syntactic sugar
* src/lambda-lift.lsk: Compiler pass that performs lambda lifting
* src/multitask.lsk: Compiler pass that implements multitasking
* src/symbol-table.lsk: Compiler pass that adds run time symbol support
* src/standard-library.lsk: Compiler pass that adds standard library support

### Sample source code

* samples/* : Sample Losak programs
* samples/kernel.lsk: Simple OS written in Losak

### Bootstrapping support

* port/*: Generated C output of compiling the lisp compiler.
* bootstrap.sh: Script that bootstraps the compiler. This requires having GCC installed

### Assorted source files

* Makefile: Specifies the build process
* include/boot.S: Assembly language code to boot the OS
* include/console.*: Provides console I/O
* include/io.*: General purpose I/O
* include/mem.*: Memory management
* include/multiboot.h: Access to multiboot data