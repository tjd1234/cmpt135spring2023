---
aliases: [const methods, non-mutating method, non-mutating methods]
---

#terminology

## Definition
A [[method]] that does not modify the object it is part of. To declare a method const, put the `const` keyword immediately after the method header.

Const methods are also know as **non-mutating methods**.

[[getter]]s are almost always const methods since they return the value of a member variable.

A class/struct with only const methods is a common object-oriented design patterns. An object that has only const methods is usually easier to understand than a method that can modify itself. Also, an object with only const methods can be easily used in a [[concurrent program]].

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

	void print() const {
		cout << x << ", " << y << "\n";
	}

	// mutating method
	void move(double dx, double dy) {
		x += dx;
		y += dy;
	}
}; // struct Point

// ...
```

`print()` is an example of a const method. When called, it doesn't modify `x` or `y`.