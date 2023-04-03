---
aliases: [copy constructors]
---

#terminology

## Definition
A [[constructor]] that takes another object of the same class/struct as input, and creates a copy of it.

If a class does not define its own copy constructor, then C++ *may* create an implicit copy constructor that copies all the member variables of the object.

## Example
```cpp
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

    // ...

}; // struct Point
```
