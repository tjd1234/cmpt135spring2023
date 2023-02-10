// shapes1.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159265358979323846;

class Circle {
public:
    int radius;

    Circle(int r) : radius(r) {}
};

double area(const Circle& c) {
    return PI * c.radius * c.radius;
}

class Ellipse {
public:
    int radius1;
    int radius2;

    Ellipse(int r1, int r2) : radius1(r1), radius2(r2) {}
};

double area(const Ellipse& e) {
    return PI * e.radius1 * e.radius2;
}


int main() {
    cout << "shapes1 ...\n";
    Circle c{5};
    cout << "circle area: " << area(c) << "\n";
    Ellipse e{5, 10};
    cout << "ellipse area: " << area(e) << "\n";
}
