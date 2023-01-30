// point.cpp

#include "cmpt_error.h"
#include <iostream>
#include <string>

using namespace std;

struct Point {
    double x = 0;  // member initialization
    double y = 0;

    Point(double a, double b)
    : x{a}, y{b}
    { }

    // default constructor
    Point() { }

    ~Point() {
        cout << "Point destructor called\n";
    }

    string to_string() const {
        return "(" + std::to_string(this->x) + ", "
                   + std::to_string(this->y) + ")";
    }
}; // struct Point

// overload the << operator for Point; makes printing
// more consistent
ostream& operator<<(ostream& out, const Point& p) {
    out << p.to_string();
    return out;
}

bool operator==(const Point& p, const Point& q) {
    return p.x == q.x && p.y == q.y;
}

bool operator!=(const Point& p, const Point& q) {
    return !(p == q);
}

Point operator+(const Point& p, const Point& q) {
    return Point{p.x + q.x, p.y + q.y};
}

int main() {
    Point p;
    Point q{1, 2};

    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "p + q = " << p + q << "\n";

    if (p != q) {
        cout << "different\n";
    } else {
        cout << "same\n";
    }
}
