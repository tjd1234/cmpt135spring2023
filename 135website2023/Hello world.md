# Hello, world!
#terminology

## Definition
A program that prints the string "Hello, world!" on the screen. It's a classic first program in C and C++, and other languages.

A hello world program can also be a program that is a small running program that could be used as the start of a bigger program.

## Example
A basic hello world program in C++:

```cpp
// hello_world1.cpp

#include <iostream>

int main() {
    std::cout << "Hello! How old are you? ";
}
```

A slightly more advanced hello world program, showing off a few more features:

```cpp
// hello_world2.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello! How old are you? ";
    int age = 0;

    cin >> age;

    if (age <= 0) {
        cmpt::error("invalid age");
    }

    cout << "That is pretty old!\n";
}
```
