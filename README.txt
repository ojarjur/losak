Archive of the LOSAK CVS repository.

When the LOSAK project first started, it used a system
called "CVS" for version control.

The project has long since moved to git, so this branch
was created to store an archive of the history from the
old CVS repository.

The history was converted to git commits using the `cvs2git`
command-line tool that is part of the `cvs2svn` project.

This history is being kept for historical purposes, but
no new development happens here.

-----------------------------------------
-- Original README.txt contents follow --
-----------------------------------------
File Extensions:
     .txt   : Plain text files.
     .ml    : Mini LOSAK source files.
     .losak : LOSAK source files.

Directory Contents:
	  losak.ml	 : Implementation of LOSAK written in Mini LOSAK.
	  mix.ml	 : Partial evaluator for Mini LOSAK written in
			   Mini LOSAK.
	  compiler.ml	 : Compiler for Mini LOSAK written in Mini LOSAK
	  cross platform interpreter : Interpreter for Mini LOSAK written
				       in Java
