// fib.cpp

#include "cmpt_trace.h"
#include <iostream>
#include <string>

using namespace std;

// 1 1 2 3 5 8 13

int fib(int n) {
    cmpt::Trace trace("fib(" + to_string(n) + ")");
    if (n == 0) return 1;       // base case 1
    if (n == 1) return 1;       // base case 2
    return fib(n-1) + fib(n-2); // recursive case
}

int main() {
    cout << fib(10) << "\n";
}