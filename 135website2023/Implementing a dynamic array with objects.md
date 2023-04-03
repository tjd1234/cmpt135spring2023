A regular array in C++ has a fixed size that never changes. This makes it difficult to use in situations where you don't know how long the array needs to be. 

C++'s `vector<T>` is an example of polished and feature-rich [[dynamic array]] .  In these notes we'll walk through the creation of a simplified version called `double_list` that stores `double`s.


## The Basic Idea
The essential idea for implementing a [[dynamic array]] is to create an object that manages an *underlying array* that is partitioned into two parts: the *used part*, and the *unused part*. The user only "sees" values in the used part, and the unused part is extra space that is used when the the size increases. If there's no space left in the unused part, then the underlying array is re-created at twice the size. Re-creating the entire array is an expensive operation, but if it is done the right way it does not need to happen too often.

Our [[dynamic array]] class will be called `double_list`:

```cpp
class double_list {
private:
    double* arr;  // pointer to the underlying array
    int capacity; // length of underlying array
    int size;     // # of elements from user's perspective
public:
	// nothing here yet
}; 
```

The three variables work as follows:

- `arr` points to the underlying array.
- `capacity` is the size of `arr`.
- `size` is the number of elements in the `double_list` from the users point of view. It's always the case that `size <= capacity`.

A `class` is the same as a `struct`, except the items in it are *private* by default (they're public by default in a `struct`). We've explicitly written `public:` and `private:` labels to make it clear which items are public and which are private.

In general, *any* code anywhere in a C++ program can read or write *public* items. In contrast, only code in `double_list` can read or write *private* `double_list` items. This is useful because it stops other code from accidentally, or on purpose, modifying `double_list` in ways we don't want. For example, the user of a `double_list` should *not* be allowed to change `capacity` directly. They might set it to a negative value, or some value other then the size of `arr`.

## Getters and Setters
We want allow *some* access to the variables. It's okay for the user of a `double_list` to *read* its size, and so we provide a [[method]] that returns the size: 

```cpp
class double_list {
private:
   double* arr;  // pointer to the underlying array
   int capacity; // length of underlying array
   int size;     // # of elements from user's perspective

public:
   int get_size() const {      // getter method
     return size;
   }

};
```

`get_size` is public, so any code can call it. 

Importantly, we do *not* provide a [[setter]] for `size`. A `size` setter doesn't make sense for this particular class: the user should *not* be able to change the size whenever they want. It should only be changed by `double_list` in the appropriate circumstances.

This idea of making data private is called [[information hiding]]. We intentionally hide details of the implementation so that the programmer doesn't have to worry about them, and can't mess them up. Experience has shown that [[information hiding]] is a useful technique for building large and complex programs.

There is no [[getter]] or [[setter]] for `arr`. Instead, we provide [[getter|getters]] and [[setter|setters]] to access its individual elements:

```cpp
int get(int i) const {
   if (i < 0 || i > size) cmpt::error("get: index out of bounds");
   return arr[i];
}

// set is not a const method because it modifies the underlying
// array.
void set(int i, int x) {  
   if (i < 0 || i > size) cmpt::error("get: index out of bounds");
   arr[i] = x;
}
```

Both `set` and `get` do **bounds checking**: they check that the index variable `i` is within the bounds of the array. This is something that C++ arrays (and vectors) do *not* do, i.e. C++ arrays let you access elements outside of their bounds. This is always an error, and so our setters will help catch such mistakes.

> A down side of bounds-checking is that it can noticeably slow your program down if it does a lot of sets/gets.

## Constructors
To create a new `double_list` we need to assign sensible values to `capacity`, `arr`, and `size`. The usual way to do this in a class is inside a [[constructor]]. A [[constructor|constructors]] job is to create a new object with properly initialized variables.

Importantly, there's no way to create a C++ object *without* calling a constructor, and so immediately after we construct an `double_list` object it's variables are guaranteed to have sensible values:

```cpp
class double_list {
private:
   double* arr;  // pointer to the underlying array
   int capacity; // length of underlying array
   int size;     // # of elements from user's perspective
public:

    // A constructor that creates a new double_list of size n
    // with all n values set to 0
    double_list(int n)
    : capacity(2*n + 1), size(n)  // initializer list
    {
        if (n < 0) {
           cmpt::error("double_list(int n): n must be 0 or greater");
        }        
        arr = new double[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

   // ... 

};
```

The constructor uses an [[initialization list|initializer list]] to set the capacity and size. [[initialization list|Initializer lists]] only work with constructors, and their purpose is to give values to member variables *before* calling any code on them. This can help prevent errors.

The body of this particular constructor does three things:
- It checks if `n` is less than 0. If so, it immediately throws an exception using `cmpt::error`.
- It allocates a new array of size `capacity` on the free store. `capacity` was initialized to `2 * n + 1` in the initializer list. This makes the underlying array about twice the size it needs to be, which allows it to grow to twice its size before any re-allocation of the array is need. The `+ 1` is to ensure that `capacity` is not 0 in the case when `n == 0`.
- It sets the elements from index location 0  to `size - 1` to be 0. If we don't do this, then those values are undefined, and could be any `int`s. Setting the array values to a known default value helps prevent and catch errors.

Constructors *always* have the same name as the class, and they *never* have an explicit return type listed (not even `void`).

Next, lets add a [[copy constructor]]. A copy constructor makes new `double_list` by copying an existing `double_list`:

```cpp
// Copy constructor: makes a copy of another double_list. The copy 
// has the same size, capacity and values, but its own underlying 
// array.
double_list(const double_list& other) 
: arr(new double[other.capacity]), 
  capacity(other.capacity), 
  size(other.size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}
```

This [[copy constructor]] makes a brand new array and then copies the elements of `other` into it.

These constructors now let us write code like this:

```cpp
double_list a(5);  // size 5 double_list initialized to all 0s
double_list b(a);  // b is a copy of a (using a new underlying array)
```

Now lets add a [[default constructor]]. A [[default constructor]] is a constructor that takes no parameters:

```cpp
// Default constructor: takes no input and makes an array of 
// size 0
double_list()
: double_list(0)  // constructor delegation
{ }
```

`double_list()` uses a convenient trick called [[constructor delegation]] which lets a constructor call another constructor in its initializer list. So, calling `double_list()` is the same as calling `double_list(0)`.

## Destructors
The current version of `double_list` as a major flaw: it has a [[memory leak]]. That's because the constructors allocate memory using `new`, but that memory isn't de-allocated anywhere.

The best place to de-allocate `arr` is in a [[destructor]]. A [[destructor]] is a special method that is *automatically* called when the object is de-allocated. There is no way for a programmer to manually call a destructor, and so they can *never* forget to call it, *never* call it more than once, or *never* call it at the wrong time. This makes it nearly a perfect way to de-allocate `arr`.

Since the [[destructor]] is called just when the `double_list` is de-allocated, `arr` will be automatically deleted as soon as the `double_list` is deleted:

```cpp
~double_list() {  // destructor: ~ followed by class name
   delete[] arr;
}
```

The addition of this one method fixes `double_list`s [[memory leak]]. 

You can put any code you like in a [[destructor]], although usually it contains "clean up" code that de-allocates resources used by the object. For debugging, it can be useful to add a print message to see when `arr` is de-allocated, e.g.:

```cpp
~double_list() {  // destructor
    delete[] arr;
    cout << "double_list destructor called\n";
}
```

## Printing and Appending
Now lets add some helper methods to print a `double_list` and to append a value onto the right end.

Here is a `print` method that can be useful for debugging: 

```cpp
class double_list {
private:
   // ...
public:
   // ...

   // Notice that get(i) is used in the for-loop, as a demonstration 
   // for how to call it.
   void print() const {
       cout << "lst capacity = " << capacity << ", "
            << "lst size = "     << size     << "\n";
       for (int i = 0; i < size; i++) {
            cout << "lst.arr[" << i << "] = " << arr[i] << "\n";
       }
    }

   // ...
};
```

Notice it's declared to be a [[const method]] because `print` does not change any values in the `double_list`.

`append_right` adds an element to the end of an `double_list` (like `push_back` for a `vector<T>`):

```cpp
class double_list {
private:
   // ...
public:
   // ...

   void append_right(double x) {
      if (size >= capacity) {
         // double the capacity of the array

         // make a new array about twice the size of the current one
         capacity = 2 * capacity;
         double* arr_new = new double[capacity];

         // copy the elements from the old array into the new one
         for(int i = 0; i < size; i++) {
            arr_new[i] = arr[i]; 
         }

         // de-allocate the old array
         delete[] arr;

         // make lst.arr point to the new array
         arr = arr_new;
      }

	  // add x to the first unused location on the right end
      arr[size] = x;
      size++;
   }

};
```

`append_right` first checks if there are any unused locations in the underlying array. If not, it makes a new array that is twice the sizeof the old one, copying the elements from the old array into it. This re-sizing and copying is expensive: it significant extra time and memory. In practice, however, it doesn't occur too often, and it turns out to be a reasonably efficient strategy for most situations.

## Summing and Sorting
Finally, summing the numbers in an array is a common operation, so lets make that easy by adding a method that returns the sum of the numbers in an `double_list`. We want it to work like this:

```cpp
double_list lst;
lst.append_right(4);
lst.append_right(2);
lst.append_right(3);

cout << lst.sum1();  // prints 9
```

So:

```cpp
class double_list {
private:
    // ...

public:
    // ...

    double sum() const {
        double result = 0;
        for(int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

};
```

The `sum()` method is declared `const` because it doesn't modify anything in the `double_list`.

Suppose instead we wanted to add a *function* --- not a method --- to calculate the average of a `double_list`. We could do it like this:
`
```cpp
double average(const double_list& lst) {
    return lst.sum() / lst.get_size();
}
```

Now lets implement a method to sort the items of a `double_list` into ascending order:

```cpp
#include <algorithm>

// ...

class double_list {
private:
    // ...

public:
    // ...

    void sort_ascending() {
        std::sort(arr, arr + size);
    }

    void sort_descending() {
		sort_ascending();
		std::reverse(arr, arr + size);
	}

};
```

`std::sort` is C++'s standard sorting algorithm. It takes two inputs: a pointer to the first element of the array, and a pointer to one past the last element, and then efficiently re-arranges the array items into ascending sorted order.

The `sort_descending` method sorts the items in reverse order, i.e. from biggest to smallest. It first sorts them in ascending order, then uses `std::reverse` to reverse the elements into descending order. Like `std::sort`, `std:reverse` takes a pointer to the first element of the array, and a pointer to one past the last element, and efficiently reverses the elements in that range. 

## Source Code

```cpp
#include <iostream>
#include <cassert>
#include "cmpt_error.h"
#include <algorithm>

using namespace std;

struct double_list {
// private members can only be accessed by could in double_list, and
// cannot be accessed by code outside of double_list.
private:
    double* arr;    // pointer to the underlying array
    int capacity;   // length of underlying array
    int size;       // # of elements from user's perspective

// public members can be accessed by any code.
public:
    // Default constructor: takes no input and makes an array of 
    // size 0
    double_list()
    : double_list(0)  // constructor delegation
    { }

    // double_list has a constructor that must be called whenever 
    // you create a new double_list. It ensures all the variables 
    // are properly initialized.
    double_list(int n)
    : capacity(2*n + 1), size(n)  // initializer list
    {
        if (n < 0) 
           cmpt::error("double_list(int n): n must be 0 or greater");
        arr = new double[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Copy constructor: makes a copy of another double_list. The 
    // copy has the same size, capacity and values, but its own
    // underlying array.
    double_list(const double_list& other) 
    : arr(new double[other.capacity]), 
      capacity(other.capacity), 
      size(other.size)
    {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    void append_right(double x) {
        if (size >= capacity) {
            // double the capacity of the array

            // make a new array about twice the size of the current
            // one
            capacity = 2 * capacity;
            double* arr_new = new double[capacity];

            // copy the elements from the old array into the new one
            for(int i = 0; i < size; i++) {
                arr_new[i] = arr[i]; 
            }

            // de-allocate the old array
            delete[] arr;

            // make lst.arr point to the new array
            arr = arr_new;
        }

        // add x to the first unused location on the right end
        arr[size] = x;
        size++;
    }

    int get_size() const { return size; }

    // A setter: set(i, x) assigns a copy of x to location i of the
    // underlying array of lst.
    void set(int i, double x) {
        if (i < 0 || i >= size) cmpt::error("set: index out of bounds");
        arr[i] = x;
    }

    // A getter: returns the value at index location i of the
    // underlying array.
    double get(int i) const {
        if (i < 0 || i >= size) cmpt::error("get: index out of bounds");
        return arr[i];
    }
    
    // Notice that get(i) is used in the for-loop, as a 
    // demonstration for how to call it.
    void print() const {
        cout << "lst capacity = " << capacity << ", "
             << "lst size = "     << size     << "\n";
        for (int i = 0; i < size; i++) {
            cout << "lst.arr[" << i << "] = " << get(i) << "\n";
        }
    }

    double sum() const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    void sort_ascending() {
        std::sort(arr, arr + size);
    }

    // Destructor. Always called automatically when the object is
    // de-allocated. The programmer cannot call it manually.
    ~double_list() {
        delete[] arr;
    }
}; // struct double_list

double average(const double_list& lst) {
    return lst.sum() / lst.get_size();
}

void sort_descending(double_list& lst) {
    lst.sort_ascending();
    // std::reverse(arr, arr + size);
    int a = 0;
    int b = lst.get_size() - 1;
    while (a < b) {
        double temp = lst.get(a); // temp = a
        lst.set(a, lst.get(b));   // a = b
        lst.set(b, temp);         // b = temp
        a++;
        b--;
    }
}

int main() {
    double_list lst(0);

    // set the first three numbers of lst to be: 0, 6, 2.5
    lst.append_right(0);
    lst.append_right(6);
    lst.append_right(2.6);

    // print lst, one number per line
    lst.print();

    // lst2 is a copy of lst
    double_list lst2(lst);
    lst2.print();

    // print the sum and average
    cout << "    sum = " << lst2.sum()    << "\n";
    cout << "average = " << average(lst2) << "\n";

    lst2.print();
    lst2.sort_ascending();
    lst2.print();
    sort_descending(lst2);
    lst2.print();

    // destructors automatically called
}
```

See [[double_list_plus.cpp]] for a version of this with a few extra C++ features.

## Practice Questions
1. Writer a *setter* called `get_capacity()` that returns the current capacity of a `double_list`.
2. Writer a *method* called `println()` that works just like `print()`, but prints a `'\n'` at afterwards.
3. Add another constructor with the header `double_list(int n, double fill)` that creates a new `double_list` of size `n` with, and with all `n` values initialized to `fill`.
4. Show how to re-write the constructor given in the notes using [[constructor delegation]] that calls the constructor in the previous question.
5. Does this code work? If so, what exactly does it do?
  ```cpp
  double_list a(a);
  ```
6. Supposed you want to save memory, and rewrite the [[copy constructor]] like this:
   ```cpp
    double_list(const double_list& other) 
    : arr(other.arr), 
      capacity(other.capacity), 
      size(other.size)
    { }
   ```
    Will `double_list` still work correctly? Explain why, or why not.
7. Add a method called `reverse()` that reverse the order of the numbers in the array.
8. Add a method called `sort_descending()` that sort the numbers in order from biggest to smallest.
