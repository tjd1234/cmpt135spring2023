In this note, we'll see how to break up a big program into smaller pieces that can be compiled independently of each other.

See also [[splitting int_vec]] for another example of separate compilation.

## The General Idea
Suppose you're creating an interactive paint program. It has a class for menus, a class for brushes, a class for colors, and so on. It might have hundreds of classes.

Putting all those classes into a single `.cpp` file is *possible*, but not a good idea. If you change just one line of code then you must re-compile the *entire* program. Compiling a giant file takes substantial time, which slows down development. 

Another issue is projects with multiple programmers. How can multiple programmers edit and compile a single file at the same time? How can they be sure they're not overwriting someone else's code? What happens when two programmers make *different* changes to the same line of code? These are difficult issues that make using a single file practically impossible with multiple programmers.

To solve these problems, we can divide large programs into multiple files. We put groups of related classes and functions into their own files. This lets us compile each `.cpp` file individually, and different programmers can agree to work on different files to help avoid conflicts. 

> **Note** While working on different files certainly helps decrease editing conflicts, it doesn't eliminate them completely. That's where version control tools like [git](https://git-scm.com/) can help. [Git](https://git-scm.com/) keeps track of changes to source code files, and helps prevent and find inconsistencies.

## Definitions and Declarations
To split a C++ program into multiple files, we must distinguish between **definitions** and **declarations**. Variables, functions, methods, classes, structs, etc. can *declared*.

When you *declare* something, you give it a name and associated type information, but you don't give it a value/implementation. When you *define* something, you give a value or implementation.

For example, here is a *declaration* and *definition* of a function that squares a number:

```cpp
double square(double x);    // declaration of square

double square(double x) {   // definition of square
	return x * x;
}
```

Here is an example with a class:

```cpp
class Point;    // declaration of Point

class Point {   // definition of Point
public:
	double x, y;
}
```

It turns out that all definitions are also declarations. But declarations are *not* definitions.

You can *declare* a variable like this:

```cpp
extern int n;  // declaration of n 
```

However, this is fairly rare and we won't declare variables in this course.

### The Single Definition Rule
C++ follows this rule:

> **Single definition rule** 
> Every variable, function, class, struct, etc. must have *exactly one* definition.
>
> A variable, function, class, struct, etc. can be *declared* multiple times.

For example:

```cpp
int a = 2;  // ok: definition of a
int b = 3;  // ok: definition of b
a = 4;      // ok: assigning a value to a
int a = 5;  // error: a is already defined and cannot be 
            //        defined again in the same scope
```

Similarly, functions must be **defined** exactly once:

```cpp
int f(int a, int b) {  // ok: definition of f
	return 2*a + b;
}

int g(int a, int b) {  // ok: definition of g
	return 2*a + b;
}

int f(int a, int b) {  // compiler error: re-definition of f
	return 2*a + b;
}
```

The single definition rule can be hard to follow when using multiple files. You must be careful to ensure that every variable, function, class, etc. is defined exactly once.

To help with this, there is a standard format for splitting C++ file into files. Each file is split into a `.h` [[header file]] containing (mostly) *declarations*, and a `.cpp` implementation file containing the corresponding *definitions*.

For functions, declarations are just the header of the function without a body, e.g.:

```cpp
int f(int a, int b);   // ok: declaration of f

int f(int a, int b) {  // ok: definition of f
	return 2*a + b;
}
```

It's okay for a C++ program to have multiple *declarations* of a variable, function, or a class/struct. They must have:
- **exactly one definition**
- **one, or more, declarations**

> **Fact** In C++, definitions are also declarations. However, declarations are not always definitions.

This is an important distinction! In general, *definitions* go in `.cpp` files, and *declarations* go in `.h` files.

So, for example, this code is allowed in C++:

```cpp
int f(int a, int b);   // ok: declaration of f
int f(int a, int b);   // ok: declaration of f

int f(int a, int b) {  // ok: definition of f
	return 2*a + b;
}

int f(int a, int b);   // ok: declaration of f
```

But code like this is will *not* compile:

```cpp
int f(int a, int b);   // ok: declaration of f

int f(int a, int b) {  // ok: definition of f
	return 2*a + b;
}

int f(int a, int b);   // ok: declaration of f

int f(int a, int b) {  // compiler error: re-definition of f
	return 2*a + b;
}
```

### Classes
The story is similar for classes. For instance, the class `RGB_color` (for storing colors) would be split into the [[header file]] `RGB_color.h` containing a declaration of `RGB_color`, and a corresponding `.cpp` implementation file contains its definition. Other code that wants to use `RGB_color` must include the `.h` header using `#include "RGB_color"`.

For example, here is a *definition* of the `RGB_color` class, and definitions of all the methods in it:

```cpp
class RGB_color {   // definition of RGB_color
	int red   = 0;
	int green = 0; 
	int blue  = 0;
public:
	RGB_color() // default constructor
	{ }  // member initialization is used to set red, green, blue

	RGB_color(int r, int g, int b)
	: red(r), green(g), blue(b)
	{
		if (red < 0 || red > 255) cmpt::error("bad red value");
		if (green < 0 || green > 255) cmpt::error("bad green value");
		if (blue < 0 || blue > 255) cmpt::error("bad blue value");
	}

	RGB_color(const RGB_color& other)
	: RGB_color(other.red, other.green, other.blue)
	{ }

	int get_red()   const { return red; }
	int get_green() const { return green; }
	int get_blue()  const { return blue; }

	void invert() {
		red   = 255 - red;
		green = 255 - green;
		blue  = 255 - blue;
	}
}; // class RGB_color
```

You can tell it's a definition because the methods *inside* the class have bodies. 

In contrast, here is a *definition* of `RGB_color` with its methods *declared* but *not defined*:

```cpp
class RGB_color {   // definition of RGB_color 
	                // (the class, but not the methods)
    int red   = 0;
	int green = 0; 
	int blue  = 0;
public:
	RGB_color();                       // methods of RGB_color
	RGB_color(int r, int g, int b);    // are declared, not defined
	RGB_color(const RGB_color& other); 

	int get_red()   const;
	int get_green() const;
	int get_blue()  const;

	void invert();
}; // class RGB_color
```

None of the methods have bodies, just headers. This is enough to be able to correctly call `RGB_color` objects. Note that the private variables are included inside the class.

You can put the *definitions* the methods of `RGB_color` afterwards like this:

```cpp
class RGB_color {
	// ...
}; 

RGB_color::RGB_color() // default constructor
{ }  // member initialization is used to set red, green, blue

RGB_color::RGB_color(int r, int g, int b)
: red(r), green(g), blue(b)
{
	if (red < 0 || red > 255) cmpt::error("bad red value");
	if (green < 0 || green > 255) cmpt::error("bad green value");
	if (blue < 0 || blue > 255) cmpt::error("bad blue value");
}

RGB_color::RGB_color(const RGB_color& other)
: RGB_color(other.red, other.green, other.blue)
{ }

int RGB_color::get_red()   const { return red;   }
int RGB_color::get_green() const { return green; }
int RGB_color::get_blue()  const { return blue;  }

void RGB_color::invert() {
	red   = 255 - red;
	green = 255 - green;
	blue  = 255 - blue;
}
```

Note that `RGB_color::` is at the front of all the method names: this is how C++ knows they belong to `RGB_color`.

When putting `RGB_color` its own files, you should put *declarations* in `RGB_color.h`, and *definitions* in `RGB_color.cpp`. Code that *uses* `RBG_color` must `#include` the `.h` file, e.g.:

```cpp
#include "RGB_color.h"
#include <iostream>

using namespace std;

int main() {
	RGB_color bg(200, 100, 255);
	cout << "bg=" << bg << "\n";
	
	RGB_color fill(55, 155, 200);
	cout << "fill=" << fill << "\n";

	double d = dist(bg, fill);
	cout << "d=" << d << "\n";
}
```

Compared to most other modern programming languages, this is a lot of work just to get separately compiled files. But it works, and has stood the test of time.

> **Note** C++20  added **modules** to C++, which will hopefully simplify and improve how separate compilation works. However, modules are not yet widely available in C++ compilers.

## Example: Creating a Separately Compiled File
In what follows we show how to convert a file with a class into a separately compileable file. All the code discussed below is in [here](https://github.com/tjd1234/cmpt135spring2023/tree/main/separate_compilation/rgb_color).

### Version 1: All In One File
In [[RGB_color_allInOne.cpp]], everything is in one file. The class and function definitions, as well as the `main()` function appear in the same file. 

To run this code, type this command (make sure the course makefile is in the same folder):

```bash
> make RGB_color_allInOne
```

This creates an executable file named `RGB_color_allInOne` that run like
this:

```bash
> ./RGB_color_allInOne
```

The good thing about this approach is that it is simple. However, it doesn't *scale*: if your program gets bigger, or more programmers get involved, then putting all the code into one file is impractical and inefficient.

### Version 2: All in One File: Methods Outside the Class
[[RGB_color_split.cpp]] stills puts *everything* into a single `.cpp` file, but with one important change: the bodies of the methods in `RGB_color` are defined *outside* the class instead of inside the class. In [[RGB_color_split.cpp]] the `RGB_Color` class looks like this:

```cpp
class RGB_color {
	int red = 0;
	int green = 0; 
	int blue = 0;
public:
	RGB_color();
	RGB_color(int r, int g, int b);
	RGB_color(const RGB_color& other);

	int get_red() const;
	int get_green() const;
	int get_blue() const;

	void invert();
}; // class RGB_color
```

The step is preparation for the step that follows, where we put the class and function headers (declarations) into one file, and their implementations (definitions) into another.

To run this code, type this command:

```bash
> make RGB_color_split
```

This creates an executable file named `RGB_color_allInOne` that run like this:

```bash
> ./RGB_color_split
```

### Version 3: A Header and an Implementation
See [[RGB_color.h]], [[RGB_color.cpp]], and [[color_test.cpp]].

This version re-arranges the contents of [[RGB_color_split.cpp]] into three separate files:
- [[RGB_color.h]] contains the class and functions headers (i.e. the declarations). Notice that [[include guards]] are used to with this file to prevent multiple inclusion.
- [[RGB_color.cpp]] contains the implementations (i.e. the definitions) of the class and functions that appear in [[RGB_color.h]]. Notice that this files includes [[RGB_color.h]]. It does *not* contain a `main()` function.
- [[color_test.cpp]] contains the `main()` function, and includes [[RGB_color.h]].

Now we have two `.cpp` files, and both of them need to be compiled using `g++ -c`:

```bash
> g++ -c RGB_color.cpp
> g++ -c color_test.cpp
```

After these files are compiled, the files `RGB_color.o` and `color_test.o` should exist.

> **Note** The `-c` tells `g++` just to compile the file and create the corresponding `.o` object code file. We should also add the options listed in the course makefile, but omit them here to emphasize the `-c`.

This creates a `.o` object file named `RGB_color.o`. Since there is no `main` function, we can't create an executable file.

Now we can [[linker|link]] them together using `g++ -o` to make the final executable:

```bash
> g++ -o color_test color_test.o RGB_color.o
```

This creates the executable file `color_test` which can be run like this:

```bash
> ./color_test
...
```

In practice, we usually put the compiling and linking commands into a [[makefile]]. For example:

```bash
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

color_test:
    g++ -c $(CPPFLAGS) RGB_color.cpp
    g++ -c $(CPPFLAGS) color_test.cpp
    g++ $(CPPFLAGS) -o color_test color_test.o RGB_color.o
```

`color_test` is an example of a `makefile` rule. The commands underneath it are run when you type `make color_test` in the shell:

```bash
> make color_test
g++ -c -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g RGB_color.cpp
g++ -c -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g color_test.cpp
g++ -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g -o color_test color_test.o RGB_color.o

❯ ./color_test
bg=(200, 100, 55)
fill=(55, 155, 200)
dist((200, 100, 55), (55, 155, 200)) ...
dist((200, 100, 55), (55, 155, 200)) = 212.309
```

> **Note** The `make` command has many more details that we won't go into here. For example, the rules can be set up so that `.cpp` files are only re-compiled if they have changed since their last compilation. This can greatly speed-up compiling and linking large programs.

This diagram shows how all the files relate:

![[RGB_color_compile.svg]]


## Practice Questions
1. In your own words, why is it usually a good idea to split a large C++ program into separately compiled files?
2. What is the single definition rule in C++? What is the difference between a *definition* and a *declaration*?
3. *True* or *false*: every C++ definition is also a declaration.
4. *True* or *false*: every C++ declaration is also a definition.
5. What is the `g++` command for *just* compiling a file?
6. What is the `g++` command for *linking* object files?
