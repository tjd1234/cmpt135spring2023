// shapes4.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159265358979323846;

class Circle {
public:
    int radius;

    Circle(int r) : radius(r) {}

    virtual double area() const {
        return PI * radius * radius;
    }

    virtual int get_radius() const {
        return radius;
    }

    virtual ~Circle() {}
};

class Ellipse : public Circle {
public:
    int radius2;

    Ellipse(int r1, int r2) : Circle(r1), radius2(r2) {}

    double area() const override {
        return PI * radius * radius2;
    }

    // This can't be correct! Why not radius from Circle?
    int get_radius() const {
        return radius2; 
    }
}; 


int main() {
    cout << "shapes4 ...\n";
    Circle c{5};
    cout << "circle area: " << c.area() << "\n";
    Ellipse e{5, 10};
    cout << "ellipse area: " << e.area() << "\n";
}
