---
aliases: [getters, getter method]
---

#terminology

## Definition
A [[method]] that returns the value of a property of an object (typically the value of one of its member variables). Getters are usually [[const method]]s as well.

See also [[setter]]s.

## Example
```cpp
struct Point {
private:
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default
public:
    // ...
	
	int get_x() const { return x; } // getter for x
	int get_y() const { return y; } // getter for y

}; // struct Point
```
