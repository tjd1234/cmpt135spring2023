```cpp
// sort_example.cpp

#include "cmpt_error.h"
#include <iostream>
#include <algorithm>

using namespace std;

struct str_array {
    string* arr;
    int sz;
    int cap;
};

void sort(str_array a) {
    sort(a.arr, a.arr + a.sz);
} 

int main() {
    // create an array of 10 strings
    string* arr = new string[10];

    // the str_array is of size 3, so it has 3 strings and 7 unused entries
    str_array a{arr, 3, 10};

    // add some strings
    a.arr[0] = "mouse";
    a.arr[1] = "cheese";
    a.arr[2] = "cat";

    // print the str_array
    for(int i = 0; i < a.sz; i++) {
        cout << "\"" << a.arr[i] << "\" ";
    }
    cout << "\n";

    sort(a);

    // print the str_array
    for(int i = 0; i < a.sz; i++) {
        cout << "\"" << a.arr[i] << "\" ";
    }
    cout << "\n";

    // de-allocate the underlying array to avoid a memory leak
    delete[] a.arr;
}
```