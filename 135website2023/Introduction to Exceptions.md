Recognizing and handling errors is an important topic in real-world programming. There are a number of general approaches to error handling, and here we will consider one of them: *exceptions*.

## Throwing Exceptions
In C++, an [[exception]] is an object that represents an error, or something that is significantly unexpected, i.e. something exceptional. There are two main things you can do with exceptions:
1. **Throw them**. When an error occurs your code can *throw* an exception. i.e. cause an exception to occur. As explained below, exceptions follow their own flow-of-control rules.
2. **Catch them**. Your program has the option of *catching* and handling any exception that has been thrown. Uncaught exceptions will cause your program to crash.

`throw` causes an exception. For example:

```cpp
void error(const string& message)
{
    throw std::runtime_error(message);
    cout << "This line is never executed!\n";
}
```

When `error` is called we say it **throws** (or **raises**) a `runtime_error` [[exception]].
`runtime_error` is a standard pre-defined C++ class whose objects are exceptions. The expression `std::runtime_error(message)` creates a new `runtime_error` object, and the flow of control immediately jumps out of the function, skipping any statements that come afterwards. 

Importantly, a function that throws an exception does **not** return.

Suppose we call `error` like this:

```cpp
void error_test1() {
    cout << "About to call error ...\n";
    error("testing 1, 2, 3");
    cout << "... error called!\n";
}
```

This happens when it runs:

```cpp
About to call error ...
terminate called after throwing an instance of 'std::runtime_error'
  what():  testing 1, 2, 3
```

Notice that the `cout` statement in `error` is *not* called, and the `cout` statement in `error_test1` is also *not* called. That's because `throw` breaks the normal sequence of flow in C++, immediately jumping out of the function.

Such jumping can sometimes cause serious problems. For instance:

```cpp
void error_test2() {
    int* arr = new int[10];

    error("testing 1, 2, 3");
    
    delete[] arr;  // oops: memory leak!
}
```

An exception has been thrown before `delete[]` is called, which causes a [[memory leak]]! In practice, it can be difficult to know when exceptions might be thrown, and so this can be a source of subtle errors.

## Catching Exceptions
An uncaught exception will crash your program. Since crashing is never desirable in real-life programs, we need some way to handle exceptions. C++ lets you **catch** exceptions using `try`/`catch` blocks. For example:

```cpp
void error_test3() {
    int* arr = new int[10];

    try {
        error("testing 1, 2, 3");
        delete[] arr;  // not called if there is an exception 
                       // thrown in the previous line
    } catch (const std::runtime_error& e) {
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
        delete[] arr;  // clean up memory
    }
    cout << "error_test3 finished\n";
}
```

In this example, if any statement inside the `try` block throws an exception of type `runtime_error`, the flow of control immediately jumps to the `catch` block and runs its body. The `cout` statement at the end is outside both the `try` part and the `catch` part, and so it will always be executed.

We could have written it like this:

```cpp
void error_test4() {
    int* arr = new int[10];

    try {
        error("testing 1, 2, 3");
    } catch (const std::runtime_error& e) {
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
    }
    
    delete[] arr;  // clean up memory
}
```

Now there is only one call to `delete` which will be called whether or not a `runtime_error` is thrown in the body of `try`.

This `catch` statement only catches exceptions of type `runtime_error`. Determining all possible exceptions a block of code might throw can be extremely difficult, even impossible. 

If you want to catch *all* exceptions of any type, use `catch (...)`:

```cpp
void error_test5() {
    int* arr = new int[10];

    try {
        error("testing 1, 2, 3");
    } catch (...) {  // ... catches all exceptions
        cout << "Caught some exception thrown by error\n";
    }
    
    delete[] arr;  // clean up memory
}
```

`catch (...)` catches *all* exceptions that might thrown in the `try` block, even ones we don't know about ahead of time. 

A `try` block can have multiple `catch` clauses, one for each different type of exception it wants to handle. For example:

```cpp
void error_test6() {
    int* arr = new int[10];

    try {
        error("testing 1, 2, 3");
    } catch (const std::runtime_error& e) {
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
    } catch (...) {
        cout << "Caught some unknown exception thrown by error\n";
    }
    
    delete[] arr;  // clean up memory
}
```

It is still possible for this code could to throw, but not catch, an exception. The problem is with `new`: if there is not enough memory to create the array, then `new` throws `bad_alloc`. So to be completely sure we catch all exceptions, we should put the call to `new` inside the `try`:

```cpp
void error_test7() {
    int* arr = nullptr;

    try {
        arr = new int[10];        
        error("testing 1, 2, 3");
    } catch (const std::runtime_error& e) {
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
    } catch (const std::bad_alloc& e) {
        cout << "bad allocation: " << e.what() << "\n";
    } catch (...) {
        cout << "Caught some other exception\n";
    } 
    
    delete[] arr;  // clean up memory
}
```

Now `delete[]` is the only statement outside of the `try` block. What if *it* throws an exception? Fortunately, it never will: the rules of C++ explicitly promise that `delete` and `delete[]` will *never* throw an exception.

[[smart pointer|Smart pointers]] are another way that C++ can handle issues such as this, but we won't be using them in this course.

## Exceptions and Destructors
In the above examples, we were able to clean up memory because we had access to `arr`. But consider this class:

```cpp
class Thing {
    int* arr;
public:
    Thing() 
    : arr(new int[10])
    { }

    ~Thing() {
        delete[] arr;
        cout << "... Thing destructor called\n";
    }
};
```

The `arr` pointer in `Thing` is private, and so the only way to de-allocate it is to call its destructor.

So what happens in code like this?

```cpp
void error_test8() {
    Thing x;

    error("testing 1, 2, 3");

    cout << "goodbye!\n";
    // Uh oh: Is the array x.arr deleted? Or is there a memory leak
    // when an exception is thrown?
}

int main() {
    try {
        error_test8();
    } catch (...) {
        cout << "caught an exception\n";
    }
    
    cout << "all done\n";
}
```

Happily, this code does *not* have a [[memory leak]]. If an exception is thrown, C++ *guarantees* that `x`'s destructor is properly called, and the array is de-allocated. 

Since it is possible for the `Thing` constructor to throw an [[exception]] (e.g. `bad_alloc` due to running out of memory), it's safer to do this:

```cpp
void error_test9() {
    try {
        Thing x;
        error("testing 1, 2, 3");
    } catch (...) {
        cout << "Caught some exception\n";
    } 
    // x's destructor is guaranteed to be called
}
```

If *any* exception is thrown by *any* statement in the `try` block, it will be caught by `catch (...)`, and so the destructor for `x` is guaranteed to always be properly called. This guarantee is extremely useful in practice.

> **Aside** C++ and C have a standard function called `exit(n)` that, when called, immediately terminates the program and returns error code `n` to the operating system. The problem with `exit` is that it *doesn't* call destructors, and so it doesn't properly clean up any resources that were in use when it was called. For example, if you call `exit` while your program has 10 files open and is connected to a printer, those connections are just suddenly severed and not shut down properly. This can cause problems for other programs that want to access them.


## RAII: Resource Acquisition is Initialization
Using constructors and destructors to manage memory (or other resources) is called [[resource acquisition is initialization]], or [[resource acquisition is initialization|RAII]] for short. The idea is simple and useful:

- put calls to `new` in constructors
- put calls to `delete`/`delete[]` in destructors; indeed, any code that
  *must* be run, even if an exception occurs, can be put in the [[destructor]]

It's worth noting that some languages, such as Java and Python, have try/catch blocks with a third construct typically called a **finally** block. In these languages, you put code that must run, even if an exception occurs, inside the **finally** block. C++ has no **finally** block, and uses [[resource acquisition is initialization|RAII]] instead.

## Exceptions in Constructors and Destructors
[Using exceptions inside constructors and destructors present some issues](https://isocpp.org/wiki/faq/exceptions#ctor-exceptions). The two essential things to remember are:

1. It's **usually okay** for a constructor to throw an exception. 
2. It is **almost always bad** for a [[destructor]] to throw an exception that escapes the destructor. Basically, [[destructor|destructors]] should never throw exceptions.

For more details, see [this discussion](https://isocpp.org/wiki/faq/exceptions#ctor-exceptions).


## Example: Parsing
This function takes a string of the form `"a + b"` as input, and returns the sum of `a` and `b` as an `int`:

```cpp
// Takes a string of the form "a + b", where a and b are ints, 
// and returns their sum. For example, "4 + 10" returns 14.
int eval(const string& s) {
    // find the position of the '+'
    int plus_loc = s.find('+');
    if (plus_loc == string::npos) cmpt::error("eval: + not found");

    // get a and b as their own strings
    string a = s.substr(0, plus_loc);
    string b = s.substr(plus_loc + 1);

    // convert a and b to ints using the standard function stoi
    // (string to int)
    int result = stoi(a) + stoi(b);

    return result;
}
```

> **Aside** `eval` is an example of a [[parser]].

It appears to work fine if you pass it well-formed strings, e.g.:

```cpp
cout << eval("2 + 3");          // 5
cout << eval("25+-3");          // 22  
cout << eval(" 8   +  10   ");  // 18
```

Notice that extra spaces are no problem. The standard `stoi` function ignores spaces at the beginning or end of a string.

But if you pass it a badly-formed string, it crashes, e.g.:

```cpp
cout << eval(" two + 3");

terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
```

This error says that the program stopped unexpectedly due to an `invalid_argument` exception thrown by the `stoi` function. The problem is
that `stoi` can't convert "two" to an `int`.

Here's another example:

```cpp
cout << eval(" 2 + 39043090300473");

terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi
```

The error is different here. The message says that `stoi` threw an exception
because the number is bigger than the biggest possible `int`.

Using `try`/`catch` we can catch these exceptions and print friendlier error messages:

```cpp
void print_safe(const string& s) {
    try {
        int result = eval(s);
        cout << "result = " << result << "\n";
    } catch (std::invalid_argument& e) {
        cout << "error: one, or both, of the operands of \"" 
             << s << "\"\n"
             << "       is not a valid int\n";
    } catch (std::out_of_range& e) {
        cout << "error: one, or both, of the operands of \"" 
             << s << "\"\n"
             << "       are outside the range of an int\n";    
    } catch (...) {
        cout << "error: an unknown error has occurred\n"
             << "       with input \"" << s << "\"\n";
    }
}

void test_safe() {
    print_safe("11  +33");
    print_safe("two + 3");
    print_safe("2 + 39043090300473");
    print_safe("cow");
}
```

An important idea here is that `eval` was initially written *without* worrying about exceptions. Catching the exceptions came later, which lets the programmer separate the code that solves the problem from the error handling code. The error handling code is rather messy, and there is a lot of it. If this had been mixed-in with the main code for `eval`, it would likely have been much less readable.

Notice that the exception thrown by `cmpt::error("eval: + not found")` is not handled properly in `print_safe`. The try/catch block in `print_safe` doesn't explicitly catch the `runtime_error` exception, and so it gets treated as an unknown error.

There is at least one other issue with the code in `eval`: how should examples like `eval("2.9 + 2")` be handled? It turns out that `stoi` *truncates* the 2.9, i.e. 2.9 becomes 2. Some programmers might say that's an error because we said that the `eval` function works with `int`s, and so it should throw an error when given a non-`int`. Other programmers might say that converting it to an `int` in this way is fine because, after all, that's what C++ normally does when converting floating point numbers to `int`s. So, in this case, it's up to you, the programmer, to decide if `eval("2.9 + 2")` ought to be an error. If you do decide it is an error, then you need a new version of `stoi` that throws an exception in that case.

## Exception Propagation
Consider this class, and the three functions that follow it:

```cpp
class Test {
    string name;
public:
    Test(const string& s)
    : name(s)
    { 
        cout << "Test(): " << name << " constructed ...\n";
    }

    ~Test() {
        cout << "... ~Test(): destructor for " << name << " called\n";
    }
};

void c() {
    cout << "c() called ...\n";
    Test c1("c1");
    cmpt::error("aaahhhhhh!!!");
    Test c2("c2");
    cout << "... c() ended normally\n";
}

void b() {
    cout << "b() called ...\n";
    Test b1{"b1"};
    c();
    Test b2{"b2"};
    cout << "... b() ended normally\n";
}

void a() {
    cout << "a() called ...\n";
    Test a1{"a1"};
    b();
    Test a2{"a2"};
    cout << "... a() ended normally\n";
}

int main() {
    try {
        a();
    } catch (...) {
        cout << "caught an exception!\n";
    }
}
```

Calling `a()` prints this:

```cpp
a() called ...
Test(): a1 constructed ...
b() called ...
Test(): b1 constructed ...
c() called ...
Test(): c1 constructed ...
... ~Test(): destructor for c1 called
... ~Test(): destructor for b1 called
... ~Test(): destructor for a1 called
caught an exception!
```

The call to `error` inside `c()` throws an exception that is *not* caught inside `c()`. The exception **propagates** to `b()` (because it was `b()` that called `c()`), giving `b()` the chance to catch it. But it doesn't catch the exception, and so the exception propagates to `a()`, giving it a chance to catch the exception. But it doesn't, and so the error keeps propagating up through all the functions that were called, eventually hitting `main`. Finally, in `main`, the exception is caught by the `try`/`catch`. If `main` didn't have a `try`/`catch` block, then the program would crash.

Every time you call a function C++ records function calls on the [[stack memory|call stack]]. Just before `error` is called in `c()`, the C++ [[stack memory|call stack]] looks like this:

```
|      |
| c    | <--- top (most recently called function)
| b    |
| a    |
| main | <--- bottom
--------
call stack
```

When the most recently called function ends, it is "popped" off the top of the [[stack memory|call stack]], and the program continues executing at the next line in `b()` (in addition to the function name, the location of the statement to execute next is also stored). But if `c()` ends due to an exception being thrown, C++ searches down the [[stack memory|call stack]], starting at `c()`, to find if there is a `try`/`catch` block that handles the exception. As it searches, it pops off the functions, being sure to call the destructors of all local objects in that function.

This process of going down the [[stack memory|call stack]] and calling destructors is called **stack unwinding**. 

Importantly, throwing an exception is **not** the same as returning a value. Returning a value and throwing an exception work very differently.

## Practice Questions
1. What is an exception? When are they used?
2. What does it mean to *throw* an exception? What does it mean to *catch* an exception?
3. *True* or *false*: when a function throws an exception, we can say it has returned the exception.
4. In a try/catch block, how do you catch *any* exception?
5. *True* or *false*: `new` could throw an exception.
6. *True* or *false*: `delete` could throw an exception.
7. In your own words, explain the difference in how a function ends when you call the standard `exit(n)` function versus throwing an exception. Which technique is better?
8. In your own words, explain the idea of [[resource acquisition is initialization]].
9. *True* or *false*: it's usually okay for a [[constructor]] to throw an exception.
10. *True* or *false*: it's usually okay for a [[destructor]] to throw an exception.
11. In your own words, and using an example, explain the idea of exception propagation on the [[stack memory|call stack]].
12. In your own words, and using an example, explain the idea of stack unwinding.