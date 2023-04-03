#terminology

## Definition
A program that scans a C++ program *before* the compiler. The pre-processor is controlled through **pre-processor directives**, which are commands that start with a `#` symbol.

For example, `#include` is a pre-processor directive that copies another file into the current file.

The pre-processor is quite powerful: it can be used to re-define almost any aspect of a C++ program. In practice this power can be useful and dangerous. In this course we'll use the pre-processor in only two cases: including header files, and setting up [[include guards]]. Don't use the pre-processor for anything else in this course!

## Example
This code demonstrates the use of the pre-processor for including files, and implementing [[include guards]]:

```cpp
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
