// loops.cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // C-style for-loop
    int total1 = 0;
    for(int i = 0; i < 100; i++) {
        total1 += i;
    }
    cout << "total1 = " << total1 << "\n";

    // while loop
    int total2 = 0;
    int i = 0;
    while (i < 100) {
        total2 += i;
        i++;
    }
    cout << "total2 = " << total2 << "\n";

    // a vector of the numbers 0 to 99
    vector<int> v;
    for(int i = 0; i < 100; i++) {
        v.push_back(i);
    }

    // C++ style for-loop
    int total3 = 0;
    for(int i = 0; i < v.size(); i++) {
        total3 += v[i];
    }
    cout << "total3 = " << total3 << "\n";

    // C++ range-based for-loop
    int total4 = 0;
    for(int i : v) total4 += i;
    cout << "total4 = " << total4 << "\n";
} // main
