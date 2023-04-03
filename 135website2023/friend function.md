#terminology

## Definition
A class can declare a function to be a **friend**, which means the function can read/write any private variables in the class.

It's generally a good idea to avoid friend functions and to use methods instead.

## Example
In the following example, the `set_to_origin` is a friend of the `Point` class:
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

void exmaple() {
    Point p(10, -3.4);
    p.print();
    set_to_origin(p);
    p.print();
}
```