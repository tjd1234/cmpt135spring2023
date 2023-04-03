
C++ pointers are a powerful feature, but C++ has no built-in safety features and it is easy to make mistakes. In what follows we discuss some common pointer problems that all programmers need to be on the lookout for.

## Pointer Addresses are Unpredictable
Your program should never assume that the value of a pointer is the same from run to run, or even within the same program. For example:

```cpp
void f(const string& msg) {
    int n = 25;
    int* p = &n;   // p points to n, i.e. p stores the address
                   // of n

    cout <<  p     // Careful! This prints unpredictable values
         << msg    // because there is no guarantee where in
         >> "\n";  // memory n is stored.
}

void different_address_demo2() {
    f(" (third call))");
    f(" (fourth call)");
}

void different_address_demo() {
    cout << "different_address_demo ...\n";

    //
    // There is no guarantee what the calls to f print. The address of n
    // inside f may be different on different runs.
    //
    // The first two calls print the same thing on my machine, 
    // but that is not guaranteed.
    //

    // The third and fourth calls (called within 
    // different_address_demo2) print the same thing, but the address 
    // is different than the first two calls.

    f(" (first call))");
    f(" (second call)");

    different_address_demo2();
}
```

> **Rule of Thumb** Never assume assume a pointer has a particular value.

## Dangling Pointers 1
A pointer should always point to a valid memory location. If not, we say it is a [[dangling pointer]]. For example:

```cpp
void dangling_pointer_demo1() {
    cout << "dangling_pointer_demo1 ...\n";
    
    int* p = new int(25);  // p points to a new int on the free store
    
    // ... do things with p ...

    delete p;              // Okay: we're done with p so we de-allocate
                           // the memory it points to.
                           // But: p is now a dangling pointer, i.e. the
                           // memory it points to is de-allocated and
                           // should not be used in any way

  

    *p = 42;               // ERROR! The memory p points to is not
                           // allocated, so this is not allowed. While it
                           // *may* appear to work correctly (the next
                           // cout line may print 42), it writes to memory
                           // we are not allowed to write to.

  

    cout << "*p: " << *p   // ERROR! Prints 42 for me. But that doesn't
         << "\n";          // mean it's correct! The memory p points to 
                           // is not allocated, and so there is no
                           // guarantee what is there. It may be 42, but
                           // it may be something else.
						   //
                           // valgrind catches this error, calling it an
                           // "invalid write".
}
```

  
The [[valgrind]] tool can help you find dangling pointers, but it can't find all such errors. In C++, it's ultimately up to the programmer to make sure they never use dangling pointers.

We will see an interesting solution to the problem later in the course: objects with constructors and destructors can automatically allocate and de-allocate memory at the right time, avoid dangling pointers.

> **Rule of Thumb** Never read or write through a pointer if it is de-allocated.


## Dangling Pointers 2
Here is another example of a dangling pointer. The `exclaim_with_a_bug` function is meant to return a pointer to a copy of `s` with an `'!'` on the end, but it has a serious bug:

```cpp
string* exclaim_with_a_bug(const string& s) {
    string result = s + "!";
    return &result;    // ERROR! Should never return a pointer to a local
                       // variable. The memory it points to is 
                       // de-allocated when the function ends, and so the
                       // returned pointer is a dangling pointer.
}
  
void dangling_pointer_demo2() {
    string* p = exclaim_with_a_bug("hello");  // ERROR! p is a 
                                              // dangling pointer
                                              
    cout << *p << "\n";                       // ERROR!
}
```

Fortunately, this example does *not* compile if you use the course makefile. The course makefile turns on options that  will catch this error at compile-time.

> **Rule of Thumb** Never return a pointer to a local variable.

## Memory Leaks
A **memory leak** occurs when a program allocates memory on the free store, but then never de-allocates it. For example:

```cpp
void memory_leak_demo() {
    int* p = new int(25);  // p points to a new int on the free store

    // okay to use p ...
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

}  // Error! We didn't de-allocate the memory p points to.
   // Running this with valgrind will catch the memory leak.
```

When the function ends, the local variable `p` disappears (it is popped from the [[stack memory|call stack]]), but the value it points to on the free store is still there. This is a [[memory leak]], i.e. the free store memory will stay allocated until the program ends.

[[Memory leaks]] waste memory. Wasted memory might not be a problem in short-running programs, or if only a little bit of memory is wasted, but in long-running programs, like an operating system or web browser, even a small memory leak can eventually cause the program to slow down, or even crash.

[[valgrind]] can catch memory leaks in a running C++ program with nearly perfect accuracy. It is up to the programmer, though, to determine the root cause of the leak, and how best to fix it.

> **Rule of Thumb** Always de-allocate memory you have allocated. 

## Double Deletion 1
Double deletion is a kind of [[dangling pointer]] problem. When you de-allocate memory on the free store with `delete`/`delete[]`, you should de-allocate it exactly *once*. It's an error if you de-allocate it twice or more. For example:

```cpp
void double_deletion_demo1() {
    int* p = new int(25);  // ok: p points to a new int on the free store

    // okay, use p ...
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    delete p;  // ok: we're done with p, de-allocate it

    // At this point p is a dangling pointer, i.e. it is pointing to
    // de-allocated memory. We should not use it in any way for anything, 

    delete p; // ERROR! Deleting p again is a double deletion, and is not
              // allowed. It could corrupt the entire free store memory
              // system.

    // Running without valgrind crashes for me, saying a "double free" was
    // detected. That's good that it caught the problem and gave an
    // understandable error message, but programs should never crash. We
    // should catch such errors at compile-time (or earlier!).
}

```

> **Rule of Thumb** Always de-allocate memory you have allocated exactly one time.


## Double Deletion 2
Double deletion can be hard to catch when you have multiple pointers to the same memory. For example:

```cpp
void double_deletion_demo2() {
    int* p = new int(25);  // p points to a new int on the free store
    int* q = p;            // q points to the same thing as p

    // use p and q, no problems
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    cout << " q: " << q << "\n";
    cout << "*q: " << *q << "\n";

    delete p;  // ok: we're done with p, so de-allocate it

    // At this point p and q are both dangling pointers, i.e. they are
    // pointing to de-allocated memory. We should not use them in any way
    // for anything,

    delete q; // ERROR! q points to the same thing as p, so deleting q 
              // is a double deletion!

    // Running without valgrind crashes for me, saying a "double free" was
    // detected. That's good that it caught the problem and gave an
    // understandable error message, but programs should never crash. We
    // should catch such errors at compile-time (or earlier!).
}
```

In C++, it is the *programmers responsibility* to be sure that they are properly de-allocating memory. Tools like [[valgrind]] make it easier to catch such errors, but it can't always tell you the root cause, or how to fix it.

## Passing Pointers by Value
In C++, you can pass variables to functions using either [[pass by value]] or [[pass by reference]]. For example:

```cpp
double g(double a);  // a passed by value
                     // g gets a copy of the value in a

  

double h(double& b); // b passed by reference
                     // h gets a reference to b, not a copy;
                     // h can change the value of b
```

  

Pass by reference can also be simulated with pointers. For example, suppose we want to write a function that swaps the values of two integers. Pass by value doesn't work:  

```cpp
// a and b are passed by value
void swap1_bad(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap1_bad_demo() {
    int x = 5;
    int y = 10;

    cout << x << "\n";  // 5
    cout << y << "\n";  // 10

    swap1_bad(x, y);

    cout << x << "\n";  // 5
    cout << y << "\n";  // 10

    // x and y are not swapped! That's because they are passed by value to
    // swap1_bad, i.e. a copy of their values is passed, and those copies
    // are swapped. The original x and y values are not changed.
}
```

We can get around this problem by passing *pointers* to the variables we want to swap:

```cpp
// a and b are passed by value, but they are pointers to ints and so the
// pointer values are copied, but the values they point to are not copied
void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2_demo() {
    int x = 5;
    int y = 10;

    cout << x << "\n";  // 5
    cout << y << "\n";  // 10

    swap2(&x, &y);  // note the &: we must pass the addresses of x and y

    cout << x << "\n";  // 10
    cout << y << "\n";  // 5
}
```

This works, and it is how the C language handles cases where you want to do pass by reference. But there are a couple of problems:

- We must write `swap2(&x, &y)`, i.e. we have to remember to add the `&`.
- The body of `swap2` is a little more complicated because it uses pointers.

C++ has references to make this easier. We can write `swap3` like this:

```cpp
// a and b are passed by reference; we treat a and b as if they were
// regular ints
void swap3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap3_demo() {
    int x = 5;
    int y = 10;

    cout << x << "\n";  // 5
    cout << y << "\n";  // 10

    swap3(x, y);  // no & needed: pass by reference lets us
                  // pass x and y directly

    cout << x << "\n";  // 10
    cout << y << "\n";  // 5
}
```

**Rule of Thumb**: Use pass-by-reference instead of pointers whenever possible.

## Practice Questions
1. Why do the values of pointers usually change from run to run of a program?
2. In your own words, describe a [[dangling pointer]].
3. If `p` is a pointer pointing to valid value, is it always the case that `p` is a [[dangling pointer]] right after calling `delete p`?
4. Explain why it is an error to return a pointer to a local variable.
5. In your own words, describe a [[memory leak]].
6. What is an example of when a [[memory leak]] might be tolerable?
7. What tool can you use to detect a [[memory leak]] in a running C++ program?
8. In your own words, describe **double deletion**.
9. Explain how **double deletion** is a kind of [[dangling pointer]] problem.
10. What is the default way that C++ passes values to functions?
11. Explain the difference between [[pass by value]] and [[pass by reference]].
12. Explain how [[pass by reference]] can be simulated using pointers and [[pass by value]].
13. In C++, why is [[pass by reference]] generally preferred over passing by pointers?

