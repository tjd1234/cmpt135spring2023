// pointer_example2.cpp

#include <iostream>
#include <string>

using namespace std;


/*

// In this comment is another example of a dangling pointer. Fortunately, the
// compiler flags we are using catch this error at compile-time.

// This function has a serious bug: it returns a pointer to a local variable.
// When the function ends, the local variable is de-allocated, and the pointer
// is now a dangling pointer. 

string* exclaim(const string& s) {
    string result = s + "!";
    return &result;
}

void exclaim_demo() {
    string* p = exclaim("hello");
    cout << *p << "\n"; // hello!
}
*/

void demo2() {
    cout << "demo2 ...\n";
    int* p = new int(25);  // p points to a new int on the free store
    int* q = p;            // q points to the same thing as p

    // use p and q, no problems
    cout << " p: " << p  << "\n";
    cout << "*p: " << *p << "\n";

    cout << " q: " << q  << "\n";
    cout << "*q: " << *q << "\n";


    delete p;  // de-allocate p, good

    // At this point p is a dangling pointer, i.e. it is pointing to
    // de-allocated memory. We should not use it in any way for anything,

    // Error! q points to the same thing as p, so deleting q is a double
    // deletion!
    delete q;

    // Running without valgrind crashes for me, saying a "double free" was
    // detected. That's good that it caught the problem with an error message,
    // but programs should never crash. Better is to catch the error at
    // compile-time (or earlier!).
}

//
// passing a pointer as a parameter
//

void swap1_bad(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap1_bad_demo() {
    cout << "swap1_bad_demo ...\n";
    int x = 5;
    int y = 10;
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    swap1_bad(x, y);
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";

    // x and y are not swapped! That's because they are passed by value to
    // swap1_bad, i.e. a copy of their values is passed. The original x and y
    // values are not changed.
}

void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2_demo() {
    cout << "swap2_demo ...\n";
    int x = 5;
    int y = 10;
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    
    swap2(&x, &y);  // note the &: we must pass the addresses of x and y

    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";

    // x and y are swapped! We passed their addresses, not their values, and so
    // swap2 can actually change the values of x and y.
}

void swap3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap3_demo() {
    cout << "swap3_demo ...\n";
    int x = 5;
    int y = 10;
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    
    swap3(x, y);  // no & needed: pass by reference lets us 
                  // pass x and y directly

    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";

    // x and y are swapped!
}

int main() {
    demo2();
    // swap1_bad_demo();
    // swap2_demo();
    // swap3_demo();
}
