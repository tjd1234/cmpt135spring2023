// pointer_example.cpp

//
// ❯ make hello_world
// g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   hello_world.cpp   -o hello_world
//
// ❯ ./hello_world
// Hello World!
//

#include <iostream>

using namespace std;

void demo() {
    double* p = new double(10.1);
    cout << *p << endl;
    *p = 42.0;
    cout << *p << endl;
    delete p;
}

int main() {
    demo();
}
