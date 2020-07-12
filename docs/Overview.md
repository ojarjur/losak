# LOSAK: A Lisp OS kernel as a compiler
## Lisp Operating System, Abstraction Kernel [LOSAK]

LOSAK is a Lisp operating system kernel implemented as a compiler. LOSAK is
also the name of the dialect of Lisp used. This project is comprised of two
parts: the LOSAK language, and an example operating system that is built
on top of LOSAK. The sample OS provides a multitasking read-eval-print loop.
The current release consists of this environment on a bootable CD image, along
with all of the source code used to build the image.

## Status

The LOSAK compiler/kernel is now feature complete, but may still warrant some
performance improvements. It provides pre-emptive multitasking, strict
seperation of processes with per-process memory limits, real-time garbage
collection, and a small standard library.

The example OS built on top of the LOSAK kernel is currently little more than
a proof of concept.

## Getting Started

Download the latest release from the <a href="http://sourceforge.net/projects/losak/">the project page</a>, and extract the iso image. This is a bootable CD image suitable for running under qemu or bochs (Or writing to an actual CD ROM). So, for instance if you have qemu installed on Gnu/Linux, you can cd to the appropriate directory and run this command:

```sh
qemu-system-i386 -m size=10 -cdrom losak.iso
```

This will launch the OS inside an emulator window.

The release branch of the code is included on the CD image under the "src" directory. You can also fetch the code from our source repository:

```sh
git clone git://git.code.sf.net/p/losak/code losak
```

You can then bootstrap the compiler from the source directory using the default target from the Makefile:

```sh
make
```

You can also run the compiler test suite:

```sh
make tests
```

And you can build the sample kernel via:

```sh
make bin/kImage
```

You can then run it inside of QEMU with:

```sh
qemu-system-i386 -m size=10 -kernel bin/kImage
```

## More Information

[Language.md](Language.md): A brief overview of the LOSAK dialect of Lisp.

[SourceForge site](http://sourceforge.net/projects/losak/): Project Summary Page on SourceForge.

Screen shots of the system running under bochs are [here](losak-screenshot-1.jpeg) and [here](losak-screenshot-2.jpeg).

[The initial concept behind the project](Operating System as a Compiler.md)
