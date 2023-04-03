It's useful to understand how **function calls** work in C++. The details are clever and not too complicated, and they give some insight into memory usage. It will also help us understand recursive function calls.

We'll use these functions throughout as standard examples:

```cpp
int f(int a) {
	return a + 1;
}

int g(int a) {
	int n = a + 2;
	return 3*n;
}

int h(int a) {
	int x = f(a);
	int y = g(a);
	return x + y;
}
```


## The Call Stack
When a C++ program runs, it designates a portion of computer memory called the [[stack memory|call stack]]. The [[stack memory|call stack]] stores information related to functions: parameters, local variables, the function return value, and the address of where to return to when the function ends.

The [[stack memory|call stack]] is implemented as a [[stack data structure]].

![[stack data structure]]

Each *call* to a function corresponds to *pushing* that function onto the [[stack memory|call stack]], and each time the function returns corresponds to *popping* it off the [[stack memory|call stack]].

For example, consider calling function `f` (from above):

```cpp
int f(int a) {      // definition of f
	return a + 1;
}

f(3);               // call to f
```

When `f(3)` is called, the following happens:
- `f(3)` is *pushed* onto the top of the [[stack memory|call stack]].
- The program flow of control jumps to the body of `f`.
- The body of `f` is executed. The parameter `a` is stored on the stack along with the function call information, and `a` acts like a [[local variable]] inside of `f`.
- When the `return` statement is executed the functions ends, and `f(3)`, and the variable `a`, is *popped* from the [[stack memory|call stack]]. The value returned by the function is put on the top of the [[stack memory|call stack]].

When a function is pushed onto the [[stack memory|call stack]], a special data structure, called a [[stack frame]], is what actually gets pushed. The [[stack frame]] contains all the information needed to run the function, i.e. the parameters passed to it and where to return to when the function ends.

For example, here is `g` from above:

```cpp
int g(int a) {       // definition of g
	int n = a + 2;
	return 3*n;
}

g(2);
```

When we call `g(2)`, this happens:
- `g(2)` is *pushed* onto the top of the [[stack memory|call stack]].
- The flow of control jumps to the body of `g`.
- The body of `g` is executed; the parameter `a` is stored on the stack with the function call, and `a` acts like a [[local variable]] inside of `g`.
- [[Local variable]] `n` inside of `g` is also stored on the stack with the function call, i.e. it is created when the function is called.
- When the `return` statement is executed the functions ends, and `g(2)` is *popped* from the [[stack memory|call stack]], and the [[local variable]] `n` is removed when this happens. The value returned by the function is put on the top of the [[stack memory|call stack]].

An important property of a [[stack data structure|stack]] is that when items are pushed onto it, any items that are already there are undisturbed. So when a function calls a function, the functions get "stacked up" on the [[stack memory|call stack]]. The functions near the top of the stack are the ones that have been called most recently.

It is useful to sketch the stack as the functions are called to see exactly how it changes.

## Example 1
Here is function `h` from above:

```cpp
int h(int a) {
	int x = f(a);
	int y = g(a);
	return x + y;
}
```

It calls both functions `f` and `g` inside of it. When we call `h(3)`, then `h(3)` gets push onto the stack:

```
|                |
|                |
|                |  
| h(3), x=?, y=? | <-- h(3) is on the top of the stack
|________________|  bottom of the stack
```

When the body of `h(3)` runs, it first reserves memory for the [[local variable|local variables]] `x` and `y`. It initializes`x` by calling `f(3)`, and, as with any function call, `f(3)` is pushed onto the stack:

```
|                |
|                |
| f(3)           | <-- f(3) is on the top of the stack 
| h(3), x=?, y=? | 
|________________|  bottom of the stack
```

`f(3)` evaluates to 4, and so when it's done it's popped from the stack and we can imagine that 4 is on the top of the stack:

```
|                |
|                |
| 4              | <-- 4 (return value of f(3)) is on the top
| h(3), x=?, y=? | 
|________________|  bottom of the stack
```

Now the 4 is removed and assigned to `x`:

```
|                |
|                |
|                | 
| h(3), x=4, y=? | <-- h(3) is on the top of the stack
|________________|  bottom of the stack
```

Next the initial value of `y` is computed by calling `g(3)`:

```
|                |
|                |
| g(3), n=6      | <-- g(3) is on the top of the stack 
| h(3), x=4, y=? | 
|________________|  bottom of the stack
```

Notice that even though `x` is sitting there on the stack, C++ does *not* allow `g` to access local variables of different functions.  When `g(3)` finishes it is popped from the stack and its return value, 15, is left in its place: 

```
|                |
|                |
| 15             | 
| h(3), x=4, y=? | <-- h(3) is on the top of the stack 
|________________|  bottom of the stack
```

Now `y` can be assigned its initial value:

```
|                |
|                |
|                | 
| h(3), x=4, y=15| <-- h(3) is on the top of the stack 
|________________|  bottom of the stack
```

Finally, `h` calculates `x + y`, and is popped from the stack. It's return value, 19, is left on top of the stack so the code that called `h(3)` can access it:

```
|                |
|                |
|                | 
| 19             | <-- 19 is the value returned by h(3) 
|________________|  bottom of the stack
```

Notice that when functions with [[local variable|local variables]] are popped from the [[stack memory|call stack]], their local variables are popped as well. This is very useful: [[local variable|local variables]] are created when the function is called, and then *automatically* de-allocated when the function ends. 

## Example 2
Let's trace the function call `f(f(1))`, where `f` is defined like this:

```cpp
int f(int a) {
	return a + 1;
}
```

First, the inner function call `f(1)` is pushed onto the [[stack memory|call stack]]:

```
|                |
|                |
|                | 
| f(1)           | <-- f(1) is on the top of the stack 
|________________|  bottom of the stack
```

It evaluates to 2:

```
|                |
|                |
|                | 
| 2              | <-- 2 is the value returned by f(1) 
|________________|  bottom of the stack
```

This 2 is the parameter to the outer `f` call, and so now `f(2)` is pushed:

```
|                |
|                |
|                | 
| f(2)           | <-- f(1) is on the top of the stack 
|________________|  bottom of the stack
```

This evaluates to 3:

```
|                |
|                |
|                | 
| 3              | <-- f(1) is on the top of the stack 
|________________|  bottom of the stack
```

The returned 3 is now on the top of the stack so that whatever code called `f(f(1))` can access it.

One final detail: it is possible for there to be so many function calls that the [[stack memory|call stack]] runs out of memory. This is known as a [[stack overflow]], and is an error that is often associated with recursive functions (which quickly stack-up many function calls).

## Practice Questions
1. In your own words, explain the [[stack data structure]], and what pushing and popping mean. Use an example in your explanation.
2. For each of the following function calls, draw a sequence of diagrams that shows how the [[stack memory|call stack]] changes:
	1. `f(2)`
	2. `g(1)`
	3. `h(0)`
	4. `h(h(0))`
3. In your own words, explain how [[local variable|local variables]] are automatically allocated and de-allocated on the [[stack memory|call stack]].
4. In your own words, describe how a [[stack overflow]] error could occur with the [[stack memory|call stack]]. What do you think might happen if a running C++ program has a [[stack memory|call stack]] overflow error?