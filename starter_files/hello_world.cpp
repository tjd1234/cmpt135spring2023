// hello_world.cpp

/************************************************************************************************

To compile this file, first make sure the standard course makefile is in the
same folder as this file. Then, run the following command (don't type $, which 
is the prompt for your command-line; it may look different on your computer):

    $ make hello_world
    g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare 
    -Wnon-virtual-dtor -g   hello_world.cpp   -o hello_world

The makefile automatically calls the g++ compiler with the standard options. If
the compiling succeeds, it should complete without printing anything else.

To run the program, type this in the command (don't type $):

    $ ./hello_world
    Hello, World!

************************************************************************************************/

#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!\n";
}
