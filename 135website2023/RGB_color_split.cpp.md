```cpp
// RGB_color_split.cpp

// This file shows how the implementations of the methods can be written
// outside of the RGB_color class.

#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

class RGB_color {
    int red = 0;
    int green = 0; 
    int blue = 0;
public:
    RGB_color();
    RGB_color(int r, int g, int b);
    RGB_color(const RGB_color& other);

    int get_red() const;
    int get_green() const;
    int get_blue() const;

    void invert();
}; // class RGB_color

//
// The following are methods defined inside the RGB_color class, and so they all
// start with RGB_color::
//

RGB_color::RGB_color() // default constructor
{ }  // member initialization is used to set red, green, blue

RGB_color::RGB_color(int r, int g, int b)
: red(r), green(g), blue(b)
{
    if (red < 0 || red > 255) cmpt::error("bad red value");
    if (green < 0 || green > 255) cmpt::error("bad green value");
    if (blue < 0 || blue > 255) cmpt::error("bad blue value");
}

RGB_color::RGB_color(const RGB_color& other)
: RGB_color(other.red, other.green, other.blue)
{ }

int RGB_color::get_red() const   { return red;   }
int RGB_color::get_green() const { return green; }
int RGB_color::get_blue() const  { return blue;  }

void RGB_color::invert() {
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
}

//
// The following are functions (not methods) defined outside RGB_color.
//

ostream& operator<<(ostream& out, const RGB_color& c) {
    out << "(" << c.get_red() << ", "
               << c.get_green() << ", "
               << c.get_blue()
        << ")";
    return out;
}

// returns the distance between two colors
double dist(const RGB_color& a, const RGB_color& b) {
    cout << "dist(" << a << ", " << b << ") ...\n";
    int dr = a.get_red() - b.get_red();
    int dg = a.get_green() - b.get_green();
    int db = a.get_blue() - b.get_blue();
    return sqrt(dr*dr + dg*dg + db*db);
}

int main() {
    RGB_color bg(200, 100, 55);
    cout << "bg=" << bg << "\n";
    
    RGB_color fill(55, 155, 200);
    cout << "fill=" << fill << "\n";

    double d = dist(bg, fill);
    cout << "d=" << d << "\n";
}
```