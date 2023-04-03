Here we work through an example of [[Separate compilation]] by splitting an `int_vec` class into a `.h` file and `.cpp` file.  Check out the notes on [[Separate compilation]] for more discussion of the overall idea.

**Sample code**: [This repositiory](https://github.com/tjd1234/cmpt135spring2023/tree/main/separate_compilation/int_vec) has all the code used in the notes below.

## Step 1: Move Methods Out of the Class
Move all the method bodies of `int_vec` to **after** `int_vec`. The `int_vec` class below shows the result of doing this. What remains in the class itself are just the (private) variables, and the headers for all the methods. The method bodies are declared after the `int_vec` class. All the method names start with `int_vec::` because they belong to `int_vec`.

## Step 2: Split the Class and the Implementations
Put the `int_vec` class in a `.h` header file, and put the method implementations in a `.cpp` file. We'll call these files `int_vec.h` and `int_vec.cpp`. 

`int_vec.h` has this structure:

```cpp
// int_vec.h

#ifndef INT_VEC_H
#define INT_VEC_H

class int_vec {
    // ...
};

void clear(int_vec& v);

// ...

#endif
```

`int_vec.cpp` has this structure:

```cpp
//////////////////////////////////////////////////////////////

// int_vec.cpp

#include "int_vec.h"
#include "cmpt_error.h"
#include <iostream>
// ...

// ... all definitions of functions and methods of int_vec go here ...

#endif
```
        
Notice that `int_vec.cpp` includes `int_vec.h`, and `int_vec.h` uses [[include guards]] to prevent multiple inclusion.

Now we can compile `int_vec.cpp` separately, which is a big time-saver for large programs.

## Step 3: Compile the .cpp File(s)
Compile `int_vec.cpp` to create a `.o` object file that can later
 be linked with other `.o` files to create an executable program.

In g++ the `-c` option is used to compile a program:

```bash
$ g++ -c int_vec3.cpp
```

After running this command successfully, the object file `int_vec.o` should be in the folder.

We are using g++ with various options turned on, so the actual g++ command is longer:

```bash
$ g++ -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g -c int_vec.cpp
```

Don't miss the `-c` near the end!

## Step 4: Create a Program with a main() Function
As a test, create a `.cpp` file with a `main` function and some code that uses `int_vec`. Lets call this `int_vec_test.cpp`:

```cpp
// int_vec_test.cpp

#include "int_vec.h"
#include <iostream>

using namespace std;

int main() {
    int_vec a;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
    }

    cout << "a = " << a << "\n";

    clear(a);

    cout << "a = " << a << "\n";
}
```

We compile this into a `.o` object file using g++ and the `-c` option:

```bash
$ g++ -c int_vec_test.cpp
```

Now `int_vec_test.o` should be in the folder.

As before, the actual g++ command has more options and would look like this:

```bash
$ g++ -std=c++11 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g -c int_vec3_test.cpp
```

## Step 4: Link the Object Files to Make an Executable
[[linker|Link]] the `.o` object files together using g++'s `-o` option to make an executable file:
```bash
$ g++ -o int_vec3_test int_vec3.o int_vec3_test.o
```

If all goes well, this creates an executable file named `int_vec_test` in the current directory that you can run like this:

```bash
$ ./int_vec3_test
```

As you can see from all these steps, separate compilation has lots of little details you need to get right. In practice, these steps are usually written down in a `makefile` so that all you need to do is type `make` to create the `int_vec_test` executable. In this course we won't go any further into the details of using `make`, but in real-life programming setting up a makefile is an important part of many programs.

