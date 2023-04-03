```cpp
// RGB_color.cpp

#include "RGB_color.h"
#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

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
```