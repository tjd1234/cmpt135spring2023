```cpp
// RGB_color.h

#ifndef RGB_COLOR_H
#define RGB_COLOR_H

#include <iostream>

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
// The following are functions (not methods) defined outside RGB_color.
//

ostream& operator<<(ostream& out, const RGB_color& c);

// returns the distance between two colors
double dist(const RGB_color& a, const RGB_color& b);

#endif
```