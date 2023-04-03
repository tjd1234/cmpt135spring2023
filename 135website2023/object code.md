#terminology

## Definition
The code output by a compiler. Multiple object files can be *linked* together to form an executable file.

The `g++` compiler can combine both compiling and linking in a single step. When doing [[Separate compilation]], it is useful to separate compiling and linking.

## Example
This creates an object file called `prog.o`:
```bash
$ g++ -c prog.cpp   # compiles to prog.o
```