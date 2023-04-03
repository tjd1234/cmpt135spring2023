The following describes an implementation of a [[dynamic array]] using a class. It covers most of the essential uses of classes in C++.

## Introduction
A [[dynamic array]] is like a regular array, except it can grow in size as more elements are added to it (it might also shrink in size, but we won't do that in this example). In contrast, a regular array in C++ has a fixed size that never changes. You could, for example, use a dynamic array to read all the numbers in a file without needing to know ahead of time how many numbers are in the file.

These notes implement a [[dynamic array]] in an object-oriented way that is similar to the standard C++ `vector`. Our [[dynamic array]] will only store `int`s, and so we'll call it `int_vec`. 

## The Basic Idea
Our essential idea for implementing a dynamic array is to use an array, which we'll call the *underlying array*, and then, when its size needs to increase, we'll create a new array of twice the size.

The `int_vec` itself will be written as this class:

```cpp
class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective
public:
	// nothing here yet
}; 
```

The three variables work as follows:

- `arr` points to the underlying array.
- `capacity` is the size of `arr`.
- `size` is the number of elements in the `int_vec` from the users point of view. It's always the case that `size <= capacity`.

A `class` is essentially the same as a `struct`, except it us the common name used, by default, the items in a `class` are *private*. We've explicitly written `public:` and `private:` labels to make it clear which items and which are private.

In general, *any* code anywhere in a C++ program can read or write *public* items. In contrast, only code in `int_vec` can read or write *private* `int_vec` items. This is useful because it stops other code from accidentally, or on purpose, modifying `int_vec` in way we don't want it to modified. For example, the user of an `int_vec` should not be allowed to change `capacity` directly. They might set it to a negative value, or some value other then the size of `arr`.

## Getters and Setters
We do want to allow *some* access to the variables. It's okay for the user of an `int_vec` to *read* its size or capacity, and so we provide [[method|methods]] that return their values: 

```cpp
class int_vec {
private:
   int capacity; // length of underlying array
   int* arr;     // pointer to the underlying array
   int size;     // # of elements in this int_vec from user's perspective

public:
   int get_size() const {      // getter method
     return size;
   }

   int get_capacity() const {  // getter method
     return capacity;
   }
};
```

`get_size` and `get_capacity` are [[getter|getters]]. They are both public, so any code can call them. All they do is *read* the values of `size` and `capacity`. 

Importantly, we do *not* provide [[setter|setters]] for `size` or `capacity`. We certainly could have provided [[setter|setters]], but that doesn't make sense for this particular class: the user should *not* be able to change the size/capacity whenever they want. Those variables should only be changed by `int_vec` in the appropriate circumstances.

This idea of making data private is called [[information hiding]]. We hide details of the implementation so that the programmer doesn't have to worry about them, and can't accidentally (or intentionally!) mess them up. Experience has shown that [[information hiding]] is a very useful technique for building large and complex programs.

There is no [[getter]] or [[setter]] for `arr`. Instead, we provide a [[getter|getters]] and [[setter|setters]] to access its individual elements:

```cpp
 int get(int i) const {
   if (i < 0 || i > size) cmpt::error("get: index out of bounds");
   return arr[i];
 }

 // Note that set is not a const method because it modifies the underlying
 // array.
 void set(int i, int x) {  
   if (i < 0 || i > size) cmpt::error("get: index out of bounds");
   arr[i] = x;
 }
```

Notice that both `set` and `get` check that the index variable `i` is within the bounds of the array. This is something that C++ arrays and vectors do *not* do, i.e. C++ arrays and vectors let you access elements outside of their bounds. This is always an error, and so our setters will help catch such mistakes.

## Constructors
To create a new `int_vec` we need to give specific values to `capacity`, `arr`, and `size`. The usual way to do this in a class is to create a [[constructor]]. A [[constructor|constructors]] job is to create a new object, properly initializing all its variables.

Importantly, there's no way to create a C++ object *without* calling a constructor, and so immediately after we construct an `int_vec` object it's variables are guaranteed to have sensible values.

```cpp
class int_vec {
private:
   int capacity; // length of underlying array
   int* arr;     // pointer to the underlying array
   int size;     // # of elements in this int_vec from user's perspective
public:

   // Default constructor (takes no parameters).
   int_vec() 
   : capacity(10), arr(new int[capacity]), size(0) // initializer list
   { }

   // ... 

};
```

The constructor use an [[initialization list|initializer list]] to initialize `int_vec`s. [[initialization list|Initializer lists]]  only work with constructors, and their purpose is to give sensible values to variables *before* calling any code on them. This can help prevent errors.

The body of the constructor is empty, but in general you could add any other code to it that you need for properly constructing an object.

This constructor takes no input parameters, and so it's called a [[default constructor]].

Constructors *always* have the same name as the class.

Now we can create a new `int_vec` of size 0:

```cpp
int_vec v;  // default constructor called
```

For convenience, lets add another [[constructor]] that creates a new `int_vec` filled with copies of a given `int`:

```cpp
// "fill" constructor: makes an int_vec of size n, every location
// initialized tp fill_value.
int_vec(int n, int fill_value)
: capacity(10), size(n)  // initializer list
{
    if (size < 0) cmpt::error("int_vec: size can't be negative");
    if (size > capacity) capacity += size;
    arr = new int[capacity];
    for(int i = 0; i < size; ++i) {
        arr[i] = fill_value;
    }
}
```

This constructor is a little more involved than the default constructor, and so it uses both an [[initialization list|initializer list]] and code in its body.

Notice that we check inside the constructor body that `size` is 0 or greater: the user is not allowed to create an `int_vec` with a negative size. This is a nice safety feature that can help catch bugs.

Next, lets add a [[copy constructor]]. A copy constructor makes a copy of another `int_vec`:

```cpp
// Copy constructor: makes a copy of another int_vec.
int_vec(const int_vec& other)
: capacity(other.capacity), arr(new int[capacity]), size(other.size)
{
    for(int i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}
```

This [[copy constructor]] makes a brand new array (in the [[initialization list|initializer list]]) and then copies the elements of `other` into it.

These constructors now let us write code like this:

```cpp
int_vec a;        // empty int_vec (size 0)
int_vec b(5, 0);  // size 5 int_vec initialized to all 0s
int_vec c(b);     // c is a copy of b (using a new underlying array)
```

## Destructors
If you run the current version of `int_vec` with [[valgrind]], it will report that there are [[memory leak|memory leaks]]. That's because the constructors allocate memory using `new`, but that memory not is de-allocated anywhere.

The best place to de-allocate `arr` is in a [[destructor]]. A [[destructor]] is special kind of method that is *automatically* called when the object is de-allocated. There is no way for a programmer to manually call a destructor. This makes it nearly a perfect tool to de-allocate `arr`

Since the [[destructor]] is called just when the `int_vec` is de-allocated, `arr` will be automatically deleted as soon as the `int_vec` is deleted:

```cpp
~int_vec() {  // destructor: always ~ followed by class name
   delete[] arr;
}
```

The addition of this one method gets rid of all the `int_vec` [[memory leak|memory leaks]]! There is no way to *not* have the [[destructor]] called, or to have it called at the wrong time. `delete[]` is guaranteed to be called exactly once on `arr` when it is known that it is no longer needed.

You can put any code you like in a [[destructor]], although usually it contains "clean up" code that de-allocates resources used by the object. For debugging, it can be useful to add a print message to see when `arr` is de-allocated, e.g.:

```cpp
~int_vec() {  // destructor
    delete[] arr;
    cout << "int_vec destructor called\n";
}
```

## Printing and Appending
Now lets add some helper methods to print an `int_vec` and to append a value onto the right end.

Here are a `print` and `println` method. Notice that both are [[const method|const methods]] because they don't modify the object they print:

```cpp
class int_vec {
private:
   // ...
public:
   // ...

   void print() const {
       if (size == 0) {
           cout << "{}";
       } else {
           cout << "{";
           cout << arr[0];
           for (int i = 1; i < size; ++i) {  // i starts at 1 (not 0)
               cout << ", " << arr[i];
           }
           cout << "}";
       }
   }

   void println() const {
       print();
       cout << "\n";
   }

};
```

 `append` adds an element to the end of an `int_vec` (like `push_back` for a `vector`):

```cpp
class int_vec {
private:
   // ...
public:
   // ...

 void append(int x) {
    if (size >= capacity) {
       capacity = 2 * capacity;          // double the capacity
       int* new_arr = new int[capacity]; // make new underlying array 
                                         // twice size of old one
    
       for(int i = 0; i < size; ++i) {   // copy elements of v
          new_arr[i] = arr[i];           // into new_arr
       }
       
       delete[] arr;                     // delete old arr
      
       arr = new_arr;                    // assign new_arr
    }
    assert(size < capacity);
    arr[size] = x;
    size++;
 }

};
```

`append` is a bit subtle. Sometimes when `append` is called it re-sizes the underlying array by making a new array that is twice the size of the old one, and then copying the elements from the old one to the new one. This re-sizing and copying takes extra time and memory, but in practice it doesn't occur too often, and so this is a reasonably efficient strategy that is often used in practice.


## Getting Rid of Magic Values with Static Variables
In the code above, there were a couple of examples of [[magic number|magic numbers]], or more generally [[magic number|magic values]]. For example, 10 is a [[magic number]] in these two constructors:

```cpp
class int_vec {
	// ...	
public:
    int_vec() 
    : capacity(10), arr(new int[capacity]), size(0)
    { }

    int_vec(int n, int fill_value)
    : capacity(10), size(n)
    {
        // ...
    }

    // ...

}; // class int_vec
```

You cannot tell from this code what 10 means. Would it be okay to change it to 9, or 11, or 100? Or -5?

Another problem is that there is no easy way for the user of `int_vec` to know what the default capacity is. It would be helpful if there was a [[getter]] (or equivalent) that returned the default capacity.

A solution to both of these problems is to use a [[static class member]]. For example:

```cpp
class int_vec {
	// ...
public:

	static const int initial_capacity = 10;

    int_vec() 
    : capacity(initial_capacity), arr(new int[capacity]), size(0)
    { }

    int_vec(int sz, int fill_value)
    : capacity(initial_capacity), size(sz)
    {
        // ...
    }

    // ...

}; // class int_vec
```

`initial_capacity` is a `static`, which means there is only a single copy shared by all `int_vec` objects. Individual `int_vec` objects do *not* have their own personal copies of `initial_capacity`.

We've also declared `initial_capacity` to be `const` because we never want a user of `int_vec` to change `initial_capacity`. They can read it, but they can't write it.

You use `::` notation to access static members of a class:

```cpp
int main() {
	cout << "initial capacity of an int_vec: " 
         << int_vec::initial_capacity 
	     << "\n";
	// ...
}
```

Notice that we *don't* need to construct an `int_vec` object to access `initial_capacity`. For [[static class member|static class members]], the `::` notation is used to access them, i.e. `int_vec::initial_capacity`. In C++, the `.`-notation works with objects, and `::` with classes.

`::`-notation is often a good way to talk about methods. For example, suppose we write a class called `Product` and a class called `Truck`, and they both have their own `print()` methods. The expression `Truck::print()` refers to method in `Truck`, and `Product::print()` is the one in `Product`.


## Summing
Finally, summing the numbers in an array is a common operation, so lets make that easy by adding a method that returns the sum of the numbers in an `int_vec`:

```cpp
int_vec v;
v.append(4);
v.append(2);
v.append(3);

cout << v.sum1();  // prints 9
```

Here are three different implementations of `sum`:

```cpp
// ...

#include <numeric>

// ...

class int_vec {
private:
    // ...

public:
    // ...

    int sum1() const {
        int result = 0;
        for(int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    // Using std::accumulate (from <numeric>).
    int sum2() const {
        return accumulate(arr, arr + size, 0);
    }
}; // class int_vec
```

In `sum2()`, `accumulate` is a standard C++ function that, in this case, takes three inputs: a pointer (`arr`) to the start of an array, a pointer (`arr + size`) to *one past* the last element of the array, and finally the initial value of the sum (i.e. 0). The advantage of `sum2` is that it is short, easy to read, most likely error free (functions in the standard library tend to be very extensively tested by C++ users), and very efficient.

## Source Code
```cpp
#include <iostream>
#include "cmpt_error.h"
#include <cassert>
#include <numeric>

using namespace std;

class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective

public:
    static const int initial_capacity = 10;

    // Default constructor (takes no parameters).
    int_vec() 
    : capacity(initial_capacity), arr(new int[capacity]), size(0)
    { }

    // "fill" constructor: makes an int_vec of size n, every location
    // initialized tp fill_value.
    int_vec(int n, int fill_value)
    : capacity(initial_capacity), size(n)
    {
        if (size < 0) cmpt::error("int_vec: size can't be negative");
        if (size > capacity) capacity += size;
        arr = new int[capacity];
        for(int i = 0; i < size; ++i) {
            arr[i] = fill_value;
        }
    }

    // Copy constructor: makes a copy of another int_vec.
    int_vec(const int_vec& other)
    : capacity(other.capacity), arr(new int[capacity]), size(other.size)
    {
        for(int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor: automatically called when this int_vec is de-allocated.
    ~int_vec() {
        delete[] arr;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }

    // Does bounds checking, i.e. throws an error if i is outside the bounds
    // of arr.
    int get(int i) const {
        if (i < 0 || i > size) 
            cmpt::error("get: index out of bounds");
        return arr[i];
    }

    // set is not a const method because it modifies the underlying array.
    void set(int i, int x) {  
        if (i < 0 || i > size) 
            cmpt::error("set: index out of bounds");
        arr[i] = x;
    }

    void print() const {
        if (size == 0) {
            cout << "{}";
        } else {
            cout << "{";
            cout << arr[0];
            for (int i = 1; i < size; ++i) {  // i starts at 1 (not 0)
                cout << ", " << arr[i];
            }
            cout << "}";
        }
    }

    void println() const {
        print();
        cout << "\n";
    }

    // Adds x to the end of this int_vec, increasing the capacity if needed.
    void append(int x) {
        if (size >= capacity) {
            capacity = 2 * capacity;          // double the capacity
            int* new_arr = new int[capacity]; // make new underlying array 
                                              // twice size of old one

            for(int i = 0; i < size; ++i) {   // copy elements of v
                new_arr[i] = arr[i];          // into new_arr
            }

            delete[] arr;      // delete old arr

            arr = new_arr;     // assign new_arr
        }
        assert(size < capacity);
        arr[size] = x;
        size++;
    }

    int sum1() const {
        int result = 0;
        for(int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    // Using std::accumulate (from <numeric>).
    int sum2() const {
        return accumulate(arr, arr + size, 0);
    }
}; // class int_vec

int main() {
    int_vec v;
    cout << "default capacity: " << int_vec::initial_capacity << "\n";
    cout << "        v.size(): " << v.get_size()              << "\n";
    cout << "    v.capacity(): " << v.get_capacity()          << "\n";
    for(int i = 0; i < 25; ++i) {
        v.append(i);
    }
    v.println();
    cout << "sum1: " << v.sum1() << "\n";
    cout << "sum2: " << v.sum2() << "\n";
}
```

## Practice Questions
1. Does this code work? If so, what exactly does it do?
    ```cpp
	int_vec a(a);
	```
2. Supposed you wanted to save memory, and rewrote the  [[copy constructor]] for `int_vec` like this:
   ```cpp
   int_vec(const int_vec& other)
   : capacity(other.capacity), arr(new int[capacity]), size(other.size)
   {
       arr = other.arr
   }
   ```
    Would `int_vec` still work correctly? Explain why, or why not.
3. In your own words, what is a [[magic number]]? Give some examples.
4. In your own words, what is a [[static class member]]? How does it differ from a regular member variable or method?
5. What is the difference between the `.` operator and `::` operator? Give an example of when they are used.
6. In the  `append` method, the capacity of the underlying array is *doubled* if necessary. The 2 used in the doubling calculation is an example of a [[magic number]]. So, replace the 2 in `append` with a suitably named [[static class member|static member variable]] as was done with the initial capacity.
