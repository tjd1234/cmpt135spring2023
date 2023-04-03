#terminology

## Definition
A file that contains instructions for compiling and linking the files in a program. Used with the `make` program.

The `make` program was designed specifically to help compile and link code. Makefiles  have their own special-purpose scripting language for building C/C++ (and other) programs. It is somewhat intelligent, and can avoid unnecessarily compiling programs if it knows that the source code file has not changed.

`make` is an older program and the syntax is a bit quirky, so we
will not go into any more details about it here. But keep in mind that big
programs, or any program that uses [[Separate compilation]], will need to use
`make`, or something like it, to manage the commands and options for
compiling and linking.

## Example
This makefile sets various flags for the C++ compiler:

```make
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g
```

This makefile compiles three different files, and includes a command for cleaning-up the object files and executable:

```make
#
# makefile for int_vec example
#

# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

# type "make" to run these commands
all: 
	g++ -c $(CPPFLAGS) int_vec.cpp
	g++ -c $(CPPFLAGS) int_vec_test.cpp
	g++ -o int_vec_test int_vec.o int_vec_test.o

# type "make clean" to run these commands
clean:
	rm int_vec.o
	rm int_vec_test.o
	rm int_vec_test
```

While not shown here, this makefile can be improved by adding **dependencies** to the commands for making the .o and executable files. Then those files are only re-created when their dependencies have changed, which can greatly speed-up compiling and linking large programs. For example, if you change 1 of 20 files in a large C++ program, a well-designed makefile would only re-compile the one changed file.

