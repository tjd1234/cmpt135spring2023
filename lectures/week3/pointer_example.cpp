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

void demo1() {
    double* p = new double(10.1);
    cout << *p << endl;
    *p = 42.0;
    cout << *p << endl;
    delete p;
}

void print(int* arr, int size) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << "}";
}

void demo2() {
    // get an array of 10 ints
    // []-brackets must be used to allocate an array
    int* arr = new int[10];

    // initialize all locations of arr to 0
    for (int i = 0; i < 10; i++) {
        arr[i] = 0;
    }

    print(arr, 10);

    // must delete using delete[], because arr was allocated using new int[10]
    delete[] arr;
}

int main() {
    // demo1();
    demo2();
}
