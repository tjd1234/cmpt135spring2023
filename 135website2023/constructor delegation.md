#terminology

## Definition
When one [[constructor]] calls another constructor.

## Example
In this class, the default constructor uses constructor delegation to initialize `x` and `y` to 0 and 0:

```cpp
class Point {
	double x;
	double y;
public:
	Point(double a, double b)
	: x(a), y(b)
	{ }
	
	// default constructor
	Point()
	: Point(0, 0)   // constructor delegation
	{ }
};
```
