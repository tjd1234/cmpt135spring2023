#terminology

## Definition
A method that, when called, might modify its object. In contrast, see [[const method]].

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

    // const method
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