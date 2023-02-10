// shapes2.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159265358979323846;

class Ellipse {
public:
    int radius1;
    int radius2;

    Ellipse(int r1, int r2) : radius1(r1), radius2(r2) {}
};

class Circle : public Ellipse {
public:
    Circle(int r) : Ellipse(r, -1) {}
};

// double area(const Circle& c) {
//     return PI * c.radius * c.radius;
// }

double area(const Ellipse& e) {
    return PI * e.radius1 * e.radius2;
}

int main() {
    cout << "shapes2 ...\n";
    Circle c{5}; // error: no matching constructor for initialization of 'Circle'
    cout << "circle area: " << area(c) << endl;
    Ellipse e{5, 10};
    cout << "ellipse area: " << area(e) << endl;
}
