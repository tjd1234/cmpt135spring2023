```cpp
// color_test.cpp

#include "RGB_color.h"
#include <iostream>

using namespace std;

int main() {
    RGB_color bg(200, 100, 255);
    cout << "bg=" << bg << "\n";
    
    RGB_color fill(55, 155, 200);
    cout << "fill=" << fill << "\n";

    double d = dist(bg, fill);
    cout << "d=" << d << "\n";
}
```