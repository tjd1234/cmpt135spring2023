---
aliases: [default constructors]
---

#terminology

## Definition
A [[constructor]] that takes no inputs.

If a class does not define its own default constructor, then C++ may create an implicit default constructor (that does nothing).

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