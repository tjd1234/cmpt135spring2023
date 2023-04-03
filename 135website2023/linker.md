#terminology

## Definition
A software tool that combines one or more [[object code]] files into an executable. With `g++`, the command `g++ -o` will link object files.

## Example
```bash
$ g++ -c a.cpp     # creates a.o
$ g++ -c b.cpp     # creates b.o
$ g++ -o a.o b.o   # links a.o and b.o into an executable file
```
