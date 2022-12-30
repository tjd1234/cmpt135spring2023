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
