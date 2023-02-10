// shapes5.cpp

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
    
    virtual double area() const {
        return PI * radius1 * radius2;
    }
    
    virtual ~Ellipse() {}
};

class Circle : public Ellipse {
public:

    Circle(int r) : Ellipse(r, r) {}

    // This can't be right! Why radius1 instead of radius2?
    double area() const {
        return PI * radius1 * radius1;
    }
};

int main() {
    cout << "shapes5 ...\n";
    Circle c{5};
    cout << "circle area: " << c.area() << "\n";
    Ellipse e{5, 10};
    cout << "ellipse area: " << e.area() << "\n";
}
