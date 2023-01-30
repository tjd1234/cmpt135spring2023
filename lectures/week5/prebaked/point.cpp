// point.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>

using namespace std;

struct Point {
    double x = 0;  // member initialization
    double y = 0;  // i.e. x and y are set to 0 by default

    // default constructor
    Point() // x and y are initialized above
    { }

    Point(double a, double b)
    : x(a), y(b)               // initializer list
    { }

    // copy constructor
    Point(const Point& other)
    : Point(other.x, other.y)  // constructor delegation
    { }

    string to_string() const {
        return "(" + std::to_string(this->x) + ", "   // this pointer
                   + std::to_string(this->y) + ")";
    }

    // assignment operator: assign a new Point p to this object; returns a
    // reference to this object, as is standard in C++ for assignment operators
    Point& operator=(const Point& p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
    }
}; // struct Point

// overload the << operator for Point; makes printing
// more consistent
ostream& operator<<(ostream& out, const Point& p) {
    out << p.to_string();
    return out;
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}


int main() {
    Point p(-32.5, 4.8);
    Point q; // default constructor called

    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";

    if (p == q) {
        cout << "p and q are the same\n";
    } else {
        cout << "p and q are different\n";
    }

} // main
