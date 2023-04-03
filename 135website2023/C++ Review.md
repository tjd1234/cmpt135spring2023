## Overview

The C++ programming language was born in the late 1970s and early 1980s. [Bjarne Stroustrup](https://en.wikipedia.org/wiki/Bjarne_Stroustrup) is the original designer and implementer:

![[Pasted image 20230103144839.png]]

He wanted a language that was as efficient as [C](https://en.wikipedia.org/wiki/C_(programming_language)), but with better features for designing big programs. While C is great for low-level programming tasks, such as interfacing directly with hardware, it can be difficult to use for higher-level applications. Similarly, while high-level languages like [Python](https://www.python.org/) or [JavaScript](https://en.wikipedia.org/wiki/JavaScript) are programmer-friendly when creating many kinds of high-level applications, they're too inefficient for programs where performance is paramount (like operating systems, or graphics rendering engines). 

So, C++ is [Stroustrup's](https://en.wikipedia.org/wiki/Bjarne_Stroustrup) attempt at creating a language that is as efficient as C, but can also be used for high-level programs. Essentially, he borrowed the idea of classes and objects from the [Simula programming language](https://en.wikipedia.org/wiki/Simula) and added them to C. Classes let you create customized data types specific to the problem you're solving.
 
C++ has been a very successful language. It has been under constant development since the early 1980s, with new features still being added. It is a huge and complex language, and its not possible to understand *every* detail of it in a single course. We'll focus on a small but useful subset.

One final note. While C++ supports programming that is higher-level than C, C++ still tends to be best used for programs that need low-level access to computer hardware, or where speed or memory-efficiency is important. It's generally **not so good** for writing user-oriented apps that, say, appear on a phone, or for scripting the levels of a game. Many kinds of high-level programs are more easily written in languages such as [Java](https://en.wikipedia.org/wiki/Java_(programming_language)) or [C#](https://en.wikipedia.org/wiki/C_Sharp_(programming_language)) or [Python](https://www.python.org/).

## C++ Review
This course assumes you've already learned the basics of programming C or C++, and so we give whirlwind review of the basics.

## Types, Variables, and Values
C++ is, for the most part, a [[statically typed language]]. That means that the type of values and functions is *known at compile-time*, and so the compiler can notify you of many type-related errors.

Most of the time we will explicitly list the types of variables and values when they are declared. For example:

```cpp
int    a = 5;      // the types of
double x = 6.22;   // a, x, and c
char   c = 'm';    // are explicitly given
cout << a << ' ' 
     << x << ' '
     << c << ' '
     << "\n";
```

`a`, `x`, and `c` are all variables. The code explicitly declares `a` to be of type `int`, `x` to be of  type `double`, and `c` to be of type `char`. 

Since C++11, the `auto` keyword can be used to infer types in some situations. For example:

```cpp
auto a = 5;       // auto uses type inference
auto x = 6.22;    // to determine the types
auto c = 'm';     // of a (and int), x (a double), and c (a char)
cout << a << ' ' 
     << x << ' '
     << c << ' '
     << "\n";
```

C++ infers that `a` is of type `int` because the literal value 5 is of type `int`. Similarly, it knows `x` is a `double` because the literal value 6.22 is of type `double` 

C++ has a large selection of standard low-level types for integers, characters, and floating point types.

## Control Structures: Loops, If-statements, and Switches
### If-statements
Here's the general form of a C++ if-statement:

```cpp
if (cond_1) {
	body_1;
} else if (cond_2) {
	body_2;
} else if (cond_3) {
	body_3
} 
.
.
.
} else if (cond_n) {
	body_n;
} else {
	body_else;
}
```

Each of `cond_1` to `cond_n` are *conditions*, i.e. boolean expressions that evaluate to either `true` or `false`.

The `else` parts are all optional.

### Switch Statements
Switch statements make decisions using basic integral types like `char`s and `int`s, e.g.:

```cpp
char sep = ',';
switch (sep) {
	case ' ':
	case ',':
	   cout << "definitely a separator";
	   break;
	case '-':
	   cout << "maybe a separator" 
	   break;
	default:
	   cout << "not a separator";
}
```

The code under the cases is executed when the value matches the case. Notice that `break` *must* be used to stop the program from "falling through" to the next case.

Each case in a `switch` statement is one value of the variable being switched on. If you want to check for a range of cases, then you must list each value explicitly with its own `case`.

`default:` is the catch-all case. The code after it will be run if none of the cases above it are matched.

Switch statements do **not** work with strings, or arrays, or other complex data types.

### While Loops
A C++ while-loop has this general form:

```cpp
before_code
while (cond) {
	body_code
}
after_code
```

The condition `cond` is a boolean expression that evaluates to either `true` or `false`. If `cond` is true, then `body_code` is executed. After that finishes, `cond` is checked again, and, if it is `true`, `body_code` is executed again. If `cond` evaluates to `false`, then `body_code` is *not* executed, and the programs jumps to `after_code`.

### Do-while Loops
C++ do-while loops have this general form:

```cpp
before_code
do {
	body_code
} while (cond);  // note the semi-colon here!
after_code
```

It is essentially the same as a while-loop, but the condition `cond` is check *after* `body` is executed. This means the body of a do-while loop is always executed at least once.

> We will rarely, if ever, use do-while loops in this course. For most purposes, while-loops and for-loops are all we need.

### C-Style For-loop
A C-style for-loop has this general form:

```cpp
before_code
for(init; cond; incr) {
	body_code
}
after_code
```

 When the for-loop is executed, the first thing it does is run `init`. Then it checks to see if `cond` is `true`; if it's not, it immediately skips to `after_code`. But if `cond` is `true`, then it executes `body_code`, and then after that executes `incr` and checks the condition again.

`init` and `incr` are often used with an index variable. For example, this prints the numbers from 1 to 100:

```cpp
for(int i = 0; i < 100; i++) {
	cout << i + 1;
}
```

### For-each Style Loop
Since C++11, there is also a **for-each** style loop in C++ that directly loops through the elements of a vector or array without the need for an index variable. 

For example, this prints all the values of `nums`:

```cpp
vector<int> nums = {5, 6, 3, -2, 0, 5};
for(int n : nums) {
	cout << n << "\n";
}
```

The `:` is read as "in", and so the loop is saying "for each of the `int`s `n` in `nums`, do the following ...".

In general, it's usually a good idea to use for-each loops when you can. They are usually easier to read than equivalent for-loops or while-loops.

## Functions
The C++ functions we'll mostly use have this general form:

```cpp
T fun_name(T1 param_1, T2 param_2, ..., Tn param_n) {
	// ... C++ code ...
	
	// ... return statement that returns a value of type T ...
}
```

This function is called `fun_name`, and it takes `n` input parameters of types `T1`, `T2`, ..., `Tn`. It returns one value of type `T`, and the function must end with a return statement of the form `return expr`. `expr` evaluates to a value of type `T`. 

The details of [[Calling a function|calling a function]] are useful to know. For instance, they help us better understand [[recursion]].

### Passing Parameters to Functions
We will consider two types of parameter passing in this course: [[pass by value]], and [[pass by reference]]. When parameters are **passed by value**, a *copy* of them is passed to the function, e.g.:

```cpp
int f(int n) {  // n is passed by value: a copy is made
	n++;
	return n + 2;
}

int main() {
	int a = 5;
	cout << f(a) << "\n"; // prints 7
	cout << a << "\n";    // prints 5 (a is NOT changed)
}
```

Note that the variable `a` is *not* changed in this example.

**Pass by reference** passes the actual variable to the function *without* making a copy. There are two main reasons to use pass by reference:
1. **Pass by reference can save memory**. For example, if you pass a string to a function using pass by value, then the string will be copied. If the string is big, making the copy could take a significant time and memory. With pass by reference, no copy would be made of the string.
2. **Pass by reference lets you modify the value of the passed-in variable**.

Compare this example to the one above:

```cpp
int f(int& n) {  // n is passed by reference: note the &
	n++;
	return n + 2;
}

int main() {
	int a = 5;
	cout << f(a) << "\n"; // prints 7
	cout << a << "\n";    // prints 6 (a is changed)
}
```

An important variation of [[pass by reference]] is [[pass by constant reference]]. [[Pass by constant reference]] passes a parameter by reference, but does *not* allow the function to modify it any way. In many cases, [[pass by constant reference]] is the best way to pass parameters because it is efficient and avoids the problem of functions unexpectedly changing variables. For example, string `s` is passed by conference reference:

```cpp
int count_spaces(const string& s) {
	int num_spaces = 0;
	for(char c : s) {
		if (c == ' ') num_spaces++;
	}
	return num_spaces;
}
```

### void Functions
If a function doesn't return a value, then its return type can be `void`:

```cpp
void fun_name(T1 param_1, T2 param_2, ..., Tn param_n) {
	// ... C++ code ...
}
```

`return` statements are optional in `void` functions. It's okay to put  `return;` (with no value returned) statement in a `void` function to make the function immediately end. If a `void` function doesn't have a return, then it will end when the code ends.

### Local Variables
A variable defined inside a function is called a [[local variable]]. For example, `num_spaces` is a local variable in the `count_spaces` function:

```cpp
int count_spaces(const string& s) {
	int num_spaces = 0;  // local variable
	for(char c : s) {
		if (c == ' ') num_spaces++;
	}
	return num_spaces;
}
```

The passed-in parameter `s` is treated as if it were local to `spaces` as well, and so we will say that `s`, `num_spaces`, and `c` are the local variables in `spaces`.

Local variables are created when their function is called, and then they are automatically deleted when their function ends. Code outside of the function cannot read or write the values of local variables.


## Includes and the Standard Namespace
C++ has a very large standard library of useful functions and classes. They are in a [[namespaces]] called `std` (short for "standard"), and are spread across a series of header file that you must include. For example:

```cpp
#include <iostream>

int main() {
	std::cout << "Hello, world!\n";   // std:: is required!
}
```

`cout` is a standard value, and because it's in the `std` namespace we must access it using the prefix `std::`.

To avoid writing `std::` all the time, we'll often use a `using` statement like this:

```cpp
#include <iostream>

using namespace std;

int main() {
	cout << "Hello, world!\n";   // std:: no longer required
}
```

`using` tells C++ to check the `std` namespace if it runs into a name that it doesn't know about. This lets write `cout` instead of `std::cout`.

We should point out that the way `#include` actually includes declarations of functions is relatively simple, i.e. it does plain textual inclusion.  While this is simple, it causes some problems. For example, compile-times of large C++ program can be in the *hours*, in part due to the `#include` statement being so inefficient. C++20 has added *modules* to C++ which solve many of the problems of `#include`. If modules catch on, then `#include` statements may eventually be phased out of C++ programs entirely.

## Practice Questions
1. What's the name of the original inventor and implementer of C++?
2. What programming language did C++ get the idea of objects and classes from?
3. Name two kinds of programs that C++ would probably be **good** for writing. Name two kinds of programs that C++ would probably **not be good** for writing. Justify your answers.
4. What does it mean when we say that C++ is a [[statically typed language]]?
5. Explain what the `auto` keyword does in C++. Give an example of how to use it.
6. What types of variables can a `switch` statement switch on?
7. In a `switch` statement, what happens if you don't end a case with a `break`?
8. In a `switch` statement, what is the label for the "catch-all" case?
9. In your own words, describe how **while-loops** and **do-while loops** work, and how they differ.
10. What is the general form of a **C-style** for-loop?
11. Give an example of how to use a **for-each** style loop.
12. How many different values can a C++ function return?
13. In your own words, explain how **pass by reference** parameter passing works, and also how **pass by value** parameter passing works. When would you use each?
14. In your own words, explain [[pass by constant reference]] parameter passing. Give an example of where it could be used.
15. What is a **namespace**? What namespace is `cout` in?