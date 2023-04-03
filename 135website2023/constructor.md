---
aliases: [constructors] 
---

#terminology

## Definition
A special method in a class/struct that is responsible for create a new object for that class/struct. The purpose of a constructor is to initialize the member variables of an object, as well as initialize any other resources the object might need. Constructors and [[destructor]]s often work together manage memory, or other resources.

A method always has the same name as the class, and does not have an explicit return type (not even `void`).

A class/struct can have as many method as it likes, as long as the methods all have different parameter lists.

Constructors often us an [[initialization list]] to initialize the member variables of the class.

A [[default constructor]] is a special constructor that takes no parameters. A [[copy constructor]] is another special constructor that takes another of object of the same struct/class as input, and creates a new copy from it.

## Example
```cpp
struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

    // default constructor
    Point() // x and y are initialized above
    { }

    Point(double a, double b)
    : x(a), y(b)         // initializer list
    { }

    // copy constructor
    Point(const Point& other)
    : Point(other.x, other.y)  // constructor delegation
    { }

    // ...

}; // struct Point