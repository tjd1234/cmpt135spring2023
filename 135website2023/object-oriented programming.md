---
aliases: OOP
---
In these notes we will refer to the following programs that implement calendar dates in different ways:

- [[date_struct.cpp]]
- [[date_class.cpp]]
- [[date_class_set_get.cpp]]
- [[date_class_readonly.cpp]]

## Overview of Object-oriented Programming
[[Object-oriented programming]], or [[object-oriented programming|OOP]] for short, is a popular style of programming that encourages programmers to combine data, and operations on that data, together into "objects". For example, computer window system systems are often implemented using object oriented programming. A window is treated as an object that contains data (files and folders), and also operations (like scrolling, moving items, etc.). In the code that makes the windows they are treated as individual values, or objects, that contain both their data and operations.

C++'s approach to object-oriented programming has been quite influential, and could be said to consist of two main concepts:
- **Objects**, which exist at *run time*. Objects contain data and operations on that data. They are used as values that can be passed, returned, modified, copied, and so on.
- **Classes**, which exist at *compile time*. A class is treated as the *type* of the object, and is like a blue print for creating objects. A class tells you what data and operations an object will contain, along with the exact way to create (and destroy) the object. In C++, you must first create a class, and then you can create objects belong to that class.

In C++, objects exist at *run time*. You can think of an object as big value that combines multiple pieces of data, plus the functions that operate on that data.

## Basic Terms: Classes and Structs
`struct`s and `class`-es in C++ are almost the same. Both can contain data, and both can contain operations (called [[method|methods]]) that operate on that data. All of the data and operations are called the [[members]] of the `struct` or `class`.

For example:

```cpp
struct Person {
    string name;
    int age;

    string to_string() const {
        return name + " " + std::to_string(age);
    }
};
```

`Person` is a `struct` with 3 members: `name`, `age`, and `to_string`. `name` and `age` are variables, and `to_string` is a [[method]]. The `const` on the header line of `to_string` means that it will *not* modify a `Person` object when called.

> **Note** We must write `std::to_string`, with `std::` at the front. Otherwise, this would recursively call the `to_string` method, and that would never end.

Here is `Person` written as an equivalent `class`:

```cpp
class Person {
public:
    string name;
    int age;

    string to_string() const {
        return name + " " + std::to_string(age);
    }
};
```

The only difference is that the first line of the `class` is `public:`, which tells the C++ compiler that all the members that follow can read/written by any code that has access to a `Person` object. *By default*, the members of a `struct` are public, while, by default, members of a `class` are private.

If you remove `public:` from the `class` version of `Person`, then all the members will be **private**, which means they  *cannot* be accessed by code outside of the `class`/`struct` (they can only be accessed by other members within that `class`/`struct`).


## Example: Dates
### Date as a Struct
Take a look at [[date_struct.cpp]]. It implements a date as a `struct` containing only variables, and provides a few helper functions.

### Date with Public Member Variables
[[date_class.cpp]] is similar to [[date_struct.cpp]], but uses some object-oriented features. In particular:

- `Date` uses a `class` instead of a `struct`. The first line of `Date` is `public:`, which means that all the code in `Date` can be accessed by *any* code in the program.
- `Date` uses [[method|methods]] instead of functions. A method is essentially a function that is part of a class, and a method can directly access any variables or methods in `Date`. `is_valid()`, `print()`, and `println()` are all methods because they are declared *inside* of `Date`.
- `is_valid()`, `print()`, and `println()` are all [[const method|const methods]], i.e.
  when they are called they *never* modify any variables in their `Date`
  object (they just read them, never write them).

  A method is declared `const` by putting the keyword `const` after the header and before the body.

  In practice, [[const method|const methods]] are very common and useful and make you programs easier to understand. For example, imagine you're writing a [[concurrent program]] where multiple CPUs might be running at the same time. With [[const method|const methods]] you need never worry about two different [[method|methods]] simultaneously assigning the same variable two different values.
  
  Sometimes [[const method|const methods]] are called [[const method|non-mutating methods]]. And a method that is *not* `const`, i.e. a method that when called might modify a value in the object, is called a [[mutating method]].
- `Date` has a [[constructor]], i.e. a special [[method]] whose job is to initialize the `Date` variables:
  
  ```cpp
  // constructor: assigns values to member variables
  Date(int d, int m, int y)
  : day(d), month(m), year(y)  // initializater list
  { }
  ```
  
   Notice that the name of the [[constructor]] is `Date`, which is the same name as the class. [[constructor|Constructors]] *always* have the same name as their class.

   The constructor does *not* have a return type (not even `void`). [[constructor|Constructors]] *never* have an explicitly listed return type: they always construct an object of the type of the class.

   This [[constructor]] uses an [[initialization list|initializer list]] to assign initial values to the members of `Date`. Initialization lists can only be used with constructors. You should always use an [[initialization list|initializer list]] with a constructor if you can: it ensures that the variables of the class/struct are initialized *before* they are used, which can prevent bugs. They also allow you to initialize values that don't work with the [[assignment operator]], `operator=`.

   In this particular example the constructor the body is empty, but in general you can put whatever code you need into a constructor.

### Date with Private Member Variables
A common pattern in object-oriented programming is to make the member variables of a class *private*, and to provide public methods for accessing those variables in a controlled way. A method that *returns* the value of a member variable is called a [[getter]], and a method that *assigns* a value to a member variable is called a [[setter]]. 

[[date_class_set_get.cpp]] adds setters and getters to `Date`. The `Date` class now looks like this:

```cpp
class Date {
    int day;   // 1 to 31
    int month; // 1 to 12
    int year;  // e.g. 2017

public:
    Date(int d, int m, int y)
    : day(d), month(m), year(y)  // initialization list
    { }

    bool is_valid() const {
		// ...
    }

	// ...

    // Getters: methods that return the value of a variable. 
    // Getters should not modify the object, and so they are 
    // declared const.
    int get_day()   const { return day;   }
    int get_month() const { return month; }
    int get_year()  const { return year;  }

    // Setters: methods that change the value of a variable. 
    // Setters are never const because they modify the object.
    void set_day(int d)   { day   = d; }
    void set_month(int m) { month = m; }
    void set_year(int y)  { year  = y; }

}; // class Date
```

In addition to adding getters and setters, we've also made the member variables private: `day`, `month`, and `year` are declared in the private section of the class, and so they can only be accessed by code within `Date`.

To allow code outside of `Date` to access `day`, `month`, and `year`, we add setters and getters. For example, for `month`, we add the [[getter|getter method]] `get_month()` that returns the value of `month`, and the [[setter|setter method]] `set_month(int m)` that assigns `m` to `month`. The *variables* are private, but the methods are *public*, and so we can read/write the variables through the methods.

The way we've written the [[getter|getters]] and [[setter|setters]] gives us *total* access to the member variables, and so it's not much different than if we'd made them public. But an advantage of this approach is that we can make  methods to do whatever we like. For instance, we could add error-checking to `set_month`:

```cpp
void set_month(int m) { 
	if (m < 1 || m > 31) {
		cmpt::error("invalid month");
	}
	month = m; 
}
```

Or we could add a "helper" [[setter]] to make the `Date` class easier to use:

```cpp
void set_month(const string& m) {
	if (m == "JAN") {
		month = 1;
	} else if (m == "FEB") {
		month = 2;
	} 

	// ...

	} else if (m == "DEC") {
		month = 12;
	} else {
		cmpt::error("unknown month");
	}
}
```

### friend Functions
Using the `friend` keyword, you can give functions outside a class permission to access the private members of a class. For example:

```cpp
class Point {
    double x;                  // x and y are private
    double y;
public:
    Point(double a, double b)  // constructor
    : x(a), y(b)
    { }

    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const { cout << x << ", " << y << "\n"; }
    
    friend void set_to_origin(Point& p);
};

void set_to_origin(Point& p) {   // friend function
    p.x = 0.0;
    p.y = 0.0;
}

void point1() {
    Point p(10, -3.4);
    p.print();
    set_to_origin(p);
    p.print();
}
```

The `Point` class declares `set_to_origin` to be a [[friend function]], which means `set_to_origin` is allowed to read/write private variables in its parameter `p`.

Generally, you should avoid `friend` functions, since they allow objects to be changed in more ways, and that can makes your programs harder to understand, which makes it easier for bugs to occur and hide. It's usually better to write a method instead of a `friend`.

### A Read-only Date Class
Another common object-oriented pattern is to *not use [[setter|setters]]*: make the `Date` class *read-only*. This simplifies the `Date` class and makes it easier to use correctly.

Here is an excerpt from [[date_class_readonly.cpp]]:

```cpp
class Date {
    int day;   // 1 to 31
    int month; // 1 to 12
    int year;  // e.g. 2017

public:
    // constructor: assigns values to member variables
    Date(int d, int m, int y)
    : day(d), month(m), year(y)  // initialization list
    { }

    // ...

    // Getters: methods that return the value of a variable. Getters 
    // should not modify the object, and so they are declared const.
    int get_day()   const { return day;   }
    int get_month() const { return month; }
    int get_year()  const { return year;  }

    //
    // No setters or other non-const methods ... Dates are read-only.
    //

    // returns a new Date exactly one year after this one
    Date next_year() const {
        return Date{day, month, year + 1};
    }

}; // class Date
```

Every member of this class is either private or const: once you construct a `Date` object, there's no way to change it. If you want a new date, then you must construct another one using the `Date` [[constructor]], or a helper method such as `next_year()`.


> A major example of this pattern is in languages such as Python and Java, where their string objects have no setters of any kind. In Python and Java, strings are immutable, i.e. once you create a string on those languages you cannot modify them in way. In contrast the C++ `string` *does* allow you to modify strings.

## Other Kinds of Constructors
A `class`/`struct` can have more than one [[constructor]], and some [[constructor|constructors]] have special names. For example, consider this `Point` class:

```cpp
struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

    // default constructor
    Point() // x and y are initialized above
    { }

    Point(double a, double b)
    : x(a), y(b)               // initializer list
    { }

    // copy constructor
    Point(const Point& other)
    : Point(other.x, other.y)  // constructor delegation
    { }

    // ...

}; // struct Point

// ...
```

`Point` has three different [[constructor|constructors]]. In addition to a [[constructor]] that
takes an `x` and `y` value as input, it has a:
- [[Default constructor]], i.e. a constructor that has no input parameters. In this particular example, the default constructor does nothing since the member variables `x` and `y` are initialized using [[member initialization]].
- [[Copy constructor]], i.e. a constructor that takes another `Point` as input and makes a copy of it. Notice that the [[copy constructor]] in this example uses [[constructor delegation]].

[[default constructor|Default constructors]] and [[copy constructor|copy constructors]] follow some special rules in C++. For example:
- If your class doesn't define a [[default constructor]] or [[copy constructor]], then C++ *automatically* creates an *implicit* default constructor that does nothing, and an *implicit* [[copy constructor]] that copies the member variables in the class.
- Many standard functions and containers, such as `vector<T>`, require that the `class`/`struct` `T` has, at least, a [[default constructor]] and a [[copy constructor]].

## Destructors
A [[destructor]] is a special method in a `class`/`struct` that is *automatically* called when its object is de-allocated. A programmer *cannot* call a [[destructor]] manually: [[destructor|destructors]] are always called automatically when an object is de-allocated.

While a class can have as many constructors as it needs, a class has exactly *one* [[destructor]]. The name of a [[destructor]] is *always* the name of the class with a `~` at the start. [[destructor|Destructors]] *never* have input parameters. For example, for a class called `Printer`, it's destructor would be `~Printer()`.

[[destructor|Destructors]] and [[constructor|constructors]] go together: when you create an object you must call a [[constructor]] for it, and when the object is deleted, it's [[destructor]] is automatically called.

Inside a [[destructor]] you put any code you want to run when the object is deleted. Typically, this involves "clean up" code, e.g. code that calls `delete`/`delete[]` on variables that were `new`-ed in the [[constructor]]. Together, [[constructor|constructors]] and [[destructor|destructors]] are a good to manage [[free store memory]]: the [[constructor]] calls `new`, and the [[destructor]] always remembers to call `delete`/`delete[]`.

An important fact about [[destructor]]s is that they *can't* be called explicitly by the programmer. This prevents the programmer from accidentally de-allocating variables in an object before the program is finished using them.

Here's an example of a class with a [[destructor]]:

```cpp
#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

    // default constructor
    Point()                    // x and y are initialized above
    { }

    Point(double a, double b)
    : x(a), y(b)               // initializer list
    { }

    // copy constructor
    Point(const Point& other)
    : Point(other.x, other.y)  // constructor delegation
    { }

    // destructor
    ~Point() {
        cout << "Point destructor called\n";
    }

}; // struct Point
```

The [[destructor]] is called `~Point()`, and all it does is print a message every time a `Point` object is deleted. This could be useful for debugging.

## The this Pointer
For every object, has C++ automatically adds a special pointer called `this` that points to the object. It's a called the object's [[this pointer]].

Here's an example of how you could use `this` in the `Point` class from above: 

```cpp
struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

	// ...

	void print() {
		cout << "(" << this->x << ", "
		            << this->y << ")";
	} 

}; // struct Point
```

The `print` method is accessing `x` and `y` through the `this` pointer using the standard pointer `->` notation. In this particular cases there's no need to use `this` (we could just write `x` and `y`), but later we will see situations where `this` is essential.


## Practice Questions
1. In your own words, explain the difference between a 
   - `struct` and a `class`
   - function and a [[method]]
   - a [[const method]], and a [[mutating method]]
2. In your own words, describe
   - what *public* and *private* mean when used in a `struct`/`class`
   - what a [[constructor]] is, and how to write one and call one
   - what an [[initialization list]] is, and when and why it is used
   - why using [[const method]]s is a good idea
   - what [[getter|getters]] and [[setter|setters]] are
3. As noted in the comments for [[date_struct.cpp]], `is_valid(const Date& d)` sometimes returns the wrong answer. How would you fix so that it works correctly for more (ideally all!) dates?
4. Implement the following for `Date` in [[date_class_readonly.cpp]]. Implement them as *functions* outside the class (and *not* methods inside the class):
   - `operator==(const Date& a, const Date& b)` returns `true` just when `a`
     and `b` are the same date, and `false` otherwise
   - `operator!=(const Date& a, const Date& b)` returns `true` just when `a`
     and `b` are different dates, and `false` when they're the same
   - `operator<(const Date& a, const Date& b)` returns `true` just when `a`
     occurs before `b`, and `false` otherwise
5. In your own words, describe what a [[destructor]] does. When it is called? Why can't a programmer call a [[destructor]] whenever they want?
6. In your own words, describe the `this` pointer.
