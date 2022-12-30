// int_vec_test.cpp

#include "int_vec.h"
#include <iostream>

using namespace std;

int main() {
    int_vec a;
    for(int i = 0; i < 10; ++i) {
        a.append(i);
    }

    cout << "a = " << a << "\n";

    clear(a);

    cout << "a = " << a << "\n";
}
