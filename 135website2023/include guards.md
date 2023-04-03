#terminology

## Definition
A trick using the C++ [[pre-processor]] that prevents the same function/variable/method definitions from being compiled more than once.

## Example
```cpp
//////////////////////////////////////////////////////////////

// int_vec.cpp

#ifndef INT_VEC_H
#define INT_VEC_H

#include "int_vec.h"
#include "cmpt_error.h"
#include <iostream>
// ...

// ... all definitions of functions and methods of int_vec go here ...

#endif
```

Notice that `int_vec.h` begins with these two lines:
```cpp
#ifndef INT_VEC_H
#define INT_VEC_H
```
And ends with this line:
```cpp
#endif
```

In C++, commands that start with `#` are  [[pre-processor|pre-processor directives]], i.e. commands to the  [[pre-processor]] that scans the code before the main C++ compiler sees it.

The directive `#ifndef INT_VEC_H` tests if `INT_VEC_H` has been
defined before (by a `#define` statement). If so, then everything
after `#ifndef INT_VEC_H` is skipped and not seen by the compiler.
But if `INT_VEC_H` is not defined, then it is immediately defined in
the next line, and the rest of the file is compiled as usual. The
`#endif` at the end of the file matches the `#ifndef` at the top.

The reason for doing this is to prevent multiple inclusion of
`int_vec.h`. In large programs, it is common to unintentionally
include a file like `int_vec.h` twice or more in the same file,
which will cause the compile to complain that `int_vec` is being
defined multiple times (a class must be defined exactly once in C++).
The `#ifndef` acts as a guard to make sure that at most one instance
of `int_vec.h` gets compiled.
