Managing memory is one most important parts of C++ programming. C++ gives a lot of flexibility in how to do it, but it comes at the cost of complexity. 

A running C++ program has a relatively simple model of memory. You can think of C++ memory as one long array of [[bytes]]:

![[memoryArray.png]]

Here, `N` is the amount of memory (in [[bytes]]) available to your C++ program. Every value in a C++ program is at some address, e.g. the character `a` is at address 3.

You can get the address of a variable like this:

```cpp
char x = 'a';
cout << x;  // prints 'a'
cout << &x; // prints the address of 'a' 
            // (in this case 3)
```

`&` is the [[address-of operator]], and returns the memory address of a variable. In general, we don't know at what address a C++ value will be stored at until the program runs. There's also no guarantee that the same address location will be used in different runs of the program. So in general, programs should *not* depend upon values being at a specific address value.

In C++, address values are called [[pointer|pointers]]. For example, the address of a `char` is of type `char*`, and `char*` is the type "pointer to a `char`".

We can write code like this:

```cpp
char x   = 'a';
char* px = &x;  
// px stores the address of x
// i.e. px points to x
```

In memory, it might look like this:

![[memoryArrayPointer.png]]

`x` has address 408, i.e. `&x == 408` in this example (in general, we won't know the exact address).

`px` has address 951, i.e. `&px = 951` in this example (in general, we won't know the exact address). The value in `px` is the address of `x`, so we say `px` **points to** `x`.

Since `px` stores the address of `x`, we can access the value it points to using the [[dereferencing operator]], `*`. C++ uses the notation `*px` to access the value at `x`.

So in this example, address 408 has two names: `x` and `*px`, and you can read/write the value there using either name, e.g.:

```cpp
char x   = 'a';
char* px = &x;

x = 'b';
cout << *px; // prints b

*px = 'c';
cout << x;  // prints c
```

## The Three Memory Regions of a Running C++ Program
As mentioned above, the memory of a running C++ program can be thought of as one long array of bytes. That array is divided into three main [[C++ memory regions|memory regions]]:

![[threeMemoryRegions.png]]
[[Static memory]] has a fixed size (that is known at compile-time) that never gets bigger or smaller. Global variables and constants are stored in static memory.

[[Stack memory]] is where local variables and function parameters are stored. Stack memory is *automatically* allocated and de-allocated as needed. When a function is called, the parameters and local variables of the function are put onto stack memory, and when the function ends its parameters and variables are automatically removed (see [[calling a function]]).

[[Free store memory|Free store (heap) memory]] is all the other memory.  In contrast to [[stack memory]] it is *not* automatically managed in C++ (although many other programming languages do manage it automatically using a [[garbage collection|garbage collector]]). Instead, a C++ programmer must manually allocate memory on the free store using `new`, and de-allocate it using `delete`/`delete[]`.


## The Free Store
Free store memory is accessed through pointers:

```cpp
double* y_addr = new double(6.4);
// returns a pointer to a newly allocated
// double on the free store
```

`new` always returns a pointer. `*` is used to [[dereferencing operator|dereference a pointer]], i.e. to access the value it points to:

```cpp
cout << *y_addr << "\n";  // prints 6.4
*y_addr += 2;
cout << *y_addr << "\n";  // prints 8.4
```

`*` is called the [[dereferencing operator]], or [[dereferencing operator|indirection operator]].

## De-allocating Free Store Memory
When you, the programmer, are finished using memory that's on the free store, you must remember to de-allocate it using `delete`:

```cpp
delete y_addr;
```

If you forget to do this, your program has a [[memory leak]].

For long-running programs (such as an operating system, a web server, a web browser, a text editor, etc.), [[memory leak|memory leaks]] will eventually eat up all the available memory. A call to `new` might fail because there is not enough memory left.

Experience shows that finding and fixing memory leaks is *very* difficult in general. It is tricky to be 100% sure that you are not de-allocating memory that you still need.

Many other programming languages use a de-allocation technique known as [[garbage collection]] to *automatically* de-allocate free store memory. But C++ does **not** use garbage collection because [[garbage collection]] has a cost in terms of time and extra memory usage. When a garbage collector runs, it slows the program down (or even causes it to briefly stop) while memory is being cleaned-up. This might be a problem in some applications. For example, real-time flight control software might not be able to tolerate any amount of slow-down --- a pilot does not want controls to lock-up for even a brief moment.

C++ aims for efficiency and flexibility, and so it does **not** provide a garbage collector. Instead, it is up to the programmer to carefully manage all the free store memory they use. C++ does provide some help, such as [[destructor|destructors]] (which we will see when we get to classes), and also [[smart pointer|smart pointers]].

## Example: vectors of pointers
The following gives practice using pointers. Create the program that is described step-by-step.

> Importantly, use [[valgrind]] to verify that the programs have no memory leaks. [[Valgrind]] will notice and report any memory leak (and other memory errors) it sees in a running C or C++ program. Any time you use `new` or `delete` you should test your program with [[valgrind]].

### Example 1
- Create an empty `vector` of `int*` pointers named `pv`.
- Allocate three new `int`s on the free store, and store pointers to them in `pv`.
- Print the `int`s `pv` points to.
- Print the sum of the `int`s `pv` points to.
- De-allocate the `int`s `pv` points to so there's no memory leak.

See [[vector pointer sample solutions]] for a sample solution.

### Example 2
- Create an empty vector of `int*` pointers named `pv`.
- Create a single new `int` on the free store, and add three pointers to `pv` that each point to it.
- Print the `int`s `pv` points to.
- Print the sum of the `int`s `pv` points to.
- De-allocate the `int`s `pv` points to so there's no memory leak. **Careful**: it's an error to call delete more than once on the same pointer!

See [[vector pointer sample solutions]] for a sample solution.

### Example 3
- Create a pointer to a `vector<int*>` named `pv`.
- Make `pv` point to an empty `vector<int*>` allocated on the free store.
- Create three new `int`s on the free store, and store pointers to them in
  `pv`.
- Print the `int`s `pv` points to.
- Print the sum of the `int`s `pv` points to.
- De-allocate the `int`s `pv` points to so there's no memory leak.
- De-allocate the `vector<int*>` `pv` points to so there's no memory leak.

See [[vector pointer sample solutions]] for a sample solution.


## Arrays on the Free Store
`new` and `delete[]` allocate and de-allocate *arrays* on the free store:
        
```cpp
int* arr = new int[5]; 
// arr points to a newly allocated array of
// 5 ints on the free store; the value of 
// the ints is unknown
```

The `[]`-brackets in `new int[5]` are essential: that's how C++ knows you want to allocate an entire array instead of a single `int` initialized to 5. If you wrote `new int(5)`, C++ would assume you're allocating a single `int` with an initial value of 5.

`arr` points to the first value of the array, and so we can use [[pointer arithmetic]] to access its individual elements:

```cpp
*(arr + 0) = 1;
*(arr + 1) = 2;
*(arr + 2) = 3;
*(arr + 3) = 4;
*(arr + 4) = 5;
```

You can also use `[]`-bracket notation: `arr[i]` is shorthand for `*(arr + i)`:

```cpp
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;
arr[3] = 4;
arr[4] = 5;
```

You can imagine the array in memory like this:

![[array1to5.png]]
Of course, we don't know the exact address values on the top, so we've just made them up for this example.

Since `arr` is an `int*` (i.e. a pointer to an `int`), for an array it points to the *first* element of the array, i.e. it contains the address of the first element (219 in this case). Then:

- `arr + 1` is 220, the second element of the array
- `arr + 2` is 221, the third element of the array
- `arr + 3` is 220, the fourth element of the array
- etc.

Unfortunately, C++ arrays **don't** stop you from accessing elements *before* or *after* the array. For example, `arr - 1` is address 218, which is `int`-sized chunk of memory that appears just before the start of the array. In general, you have no idea what memory value might be before the array, or even if you are allowed to access it. Similarly, `arr + 5` is address 224, which is the `int`-size chunk of memory immediately after the last element of the array.

C++ lets you do [[pointer arithmetic]], i.e. you can add and subtract values to pointers. While [[pointer arithmetic]] is useful for accessing array values, it is extremely powerful: from a single pointer you can potentially read/write *any* memory location on your computer, which can lead to both errors and security risks (an unethical/careless programmer could use pointers to access regions of memory they shouldn't be able to access).

As another example of using pointers, here are three different ways to print the contents of `arr`:

```cpp
// *(arr + i) style
for(int i = 0; i < 5; ++i) {
    cout << *(arr + i) << "\n";
}

// arr[i] style
for(int i = 0; i < 5; ++i) {           
    cout << arr[i] << "\n";
}

// direct pointer style
for(int* p = arr; p < arr + 5; p++) {  
    cout << *p << "\n";
}
```

The last for-loop directly increments a pointer to print each element, and no `i` index variable is needed. C++ knows that `p++` increments the address in `p` by the length of 1 `int` since it knows that `p` is an `int*` pointer.

Note that in all three loops we need to keep track of the size of the array ourselves since C++ arrays don't store their size.

## Null Pointers
Any pointer variable can be assigned the special value `nullptr`, e.g.:

```cpp
string* a = nullptr;
char*   b = nullptr;
double* c = nullptr;
```

Intuitively, a pointer with the value `nullptr` points nowhere, i.e. it doesn't point to a valid memory address. You should *never* de-reference a [[null pointer]], i.e. `*a` is an error if `a == nullptr`.

Because of this, you always need to be certain that a pointers value is *not* `nullptr` before you de-reference it:

```cpp
if (a == nullptr) {
    cmpt::error("error: null pointer");
} else {
    cout << *a << "\n";
}
```

Note that C++ *references* can never have a null value. For example, if variable `x` has type `int&` (reference to `int`), then `x` is guaranteed to contain an `int`.

> **Note** `nullptr` only exists in C++11 onward. Previous to C++11, the value 0 was used to indicate a null pointer.

## Pointers to Struct and Class Values
It's often useful to allocate struct/class values on the free store. For example, suppose we define a struct for (x, y) points:

```cpp
struct Point {
    double x;
    double y;
};
```

We can allocate and de-allocate `Point` objects on the free store using `new` and `delete`:

```cpp
Point* p = new Point{3, 4};

// ...

delete p;
```

You can use regular pointer notation to read and write the `x` and `y` values of `p`:

```cpp
// plain pointer notation
(*p).x = 5;
(*p).y = 7;
cout << (*p).x << " " << (*p).y << "\n";
```

The brackets are necessary because C++ evaluates `.` before `*`, and so `*p.x` is evaluated as if it were `*(p.x)`. 

Many programmers find expressions like `(*p).x` unpleasant to type and read. And so there is another notation used with pointers to objects:

```cpp
// arrow notation
p->x = 9;
p->y = 1;
cout << p->x << " " << p->y << "\n";
```

Many programmers find the `->`-notation easier to read and write, and so it appears quite often in practice.

## Example: Sorting a `str_array`
Suppose `str_array` is defined like this:

```cpp
struct str_array {
    string* arr;
    int n;
    int cap;
}
```

`str_array` represents a *dynamic array* where:
- `arr` points to the first `string` in the array
- `n` is the number of strings in the array from the point of view of the programmer using it
- `cap` is the size of the underlying array

Here's a diagram:
![[dynamicArray.png]]

`arr[0]` to `arr[n-1]` are the first `n` elements of the array, and they are the elements the programmer knows about.

`arr[n]` to `arr[cap-1]` are the *unused* array entries. They are there to make it fast to expand the size of the array.

If there aren't any unused entries, then to increase the size of the dynamic array you must make a new (bigger) array, copy the old array into it, and then delete the old array. Keeping some extra entries means often you won't have to do this relatively expensive array copying all the time.

Now suppose we want to sort the elements of a `str_array`, i.e. we want to re-arrange the strings in the underlying array so they are in alphabetical order. We a `sort` function that works like this:

```cpp
// words is a str_array that has already been created
sort(words);
```

After calling `sort`, the strings in `words` will be in alphabetical order.

Here is a function that works:

```cpp
#include <algorithm>

void sort(str_array a) {
    std::sort(a.arr, a.arr + a.size);
} 
```

To sort a `str_array` named `a`, we have to sort all the elements in `a.arr` from `a.arr[0]` to `a.arr[a.size-1]`. Fortunately, the C++ standard library has a sorting function called `std::sort(begin, end)` that lets us sort any sub-array in an array.

We need to give `std::sort` two input pointers: one that points to the first element of the array (`a.arr`), and one that points to *one past* the last element of the array (`a.arr + a.size`).

Note that `std::sort(a.arr, a.arr + a.size - 1)` would be wrong: it misses the last element of the array, i.e. the element at `a.arr[a.size - 1]`.

See [[sort_example_cpp]]  for some code showing everything working together.

## Practice Questions
1. What is the [[address-of operator]] and the [[dereferencing operator]]? In your own words, describe what they do, and given an example of how they can be used.
2. What is the type of a pointer to a `double`? What is the type of a pointer to a `char*`?
3. In your own words, describe the three main [[C++ memory regions||memory regions]] of a running C++ program, and what they store.
4. Write a fragment of code that creates a new `string` variable on the free store with the value `"orange"`. Show how to print the string to `cout`.
5. In your own words, explain the difference between `new int(5)` and `new int[5]`.
6. In your own words, explain the difference between `delete` and `delete[]`. 
7. In your own words, explain what a [[memory leak]] is and how it  might cause a program to crash.
8. What is a [[garbage collection|garbage collector]]? Why doesn't C++ use one?
9. What is a [[null pointer]]? What is its purpose? What happens if a program tries to de-reference a null pointer?
10. Write a fragment of code that swaps the value of `x` and `y` in a `Point` object. Suppose you only have a pointer `p` to the object. Show how to swap the values using both regular pointer notation and arrow notation. Which notation do you find more readable?
11. Suppose `arr` is an array of `n` `double`s. Write a statement that sorts the values of `arr` in order from smallest to biggest using the standard C++ sorting function (`sort`).
