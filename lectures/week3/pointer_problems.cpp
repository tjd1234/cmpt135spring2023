// pointer_problems.cpp

#include <iostream>
#include <string>

using namespace std;

//
// different addresses on different runs
//
void f(const string& msg) {
    int n = 25;
    int* p = &n;   // p points to n, i.e. p stores the address of n

    cout << "p: " << p    // Careful! This prints unpredictable values
         << msg << "\n";  // because there is no guarantee where in
                          // memory n is stored.                                       
}

void different_address_demo2() {
    f(" (third call))");
    f(" (fourth call)");
}

void different_address_demo() {
    cout << "different_address_demo ...\n";
    //
    // There is no guarantee what the calls to f print. The address of n 
    // inside f may be different on different runs.
    //
    // The first two calls print the same thing on my machine, but that is not
    // guaranteed. 
    //
    // The third and fourth calls (called within different_address_demo2 print 
    // the same thing, but the address is different than the first two calls.
    f(" (first call))");
    f(" (second call)");

    different_address_demo2();
}

//
// dangling pointers
//
void dangling_pointer_demo1() {
    cout << "dangling_pointer_demo1 ...\n";
    int* p = new int(25);  // p points to a new int on the free store

    delete p;              // p is now a dangling pointer, i.e. the memory
                           // it points to is de-allocated and should not be
                           // used in any way

    *p = 42;               // Error! The memory p points to is not allocated,
                           // so this is not allowed. While it *may* appear to
                           // work correctly (the next cout line may print 42),
                           // it writes to memory we are not allowed to write
                           // to.

    cout << "*p: " << *p   // Error! Prints 42 for me. But that doesn't mean 
         << "\n";          // it's correct! The memory p points to is not 
                           // allocated, and so there is no guarantee what is
                           // there. It may be 42, but it may be something else.

                           // valgrind catches this error, calling it an
                           // "invalid write".
}

/*

// In this comment is another example of a dangling pointer. Fortunately, the
// compiler flags we are using catch this error at compile-time.

// This function has a serious bug: it returns a pointer to a local variable.
// When the function ends, the local variable is de-allocated, and the pointer
// is now a dangling pointer. 
string* exclaim_with_a_bug(const string& s) {
    string result = s + "!";
    return &result;
}

void dangling_pointer_demo2() {
    cout << "dangling_pointer_demo2 ...\n";
    string *p = exclaim_with_a_bug("hello");
    cout << *p << "\n";
}

*/

//
// memory leaks
//
void memory_leak_demo() {
    cout << "memory_leak_demo ...\n";
    int* p = new int(25);  // p points to a new int on the free store

    // use p, no problems
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    // Error! We didn't de-allocate the memory p points to. When the function
    // ends, the local variable p disappears, but the value on the free store
    // that it points to is still there. This is a memory leak, i.e. the free
    // store memory will stay allocated until the program ends. Memory leaks
    // waste memory, and could slow your program down, or even crash it.
    //
    // Running this with valgrind will catch the memory leak. 
}

//
// double deletion
//
void double_deletion_demo1() {
    cout << "double_deletion_demo1 ...\n";
    int* p = new int(25);  // p points to a new int on the free store

    // use p, no problems
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    delete p;  // de-allocate p, good

    // At this point p is a dangling pointer, i.e. it is pointing to
    // de-allocated memory. We should not use it in any way for anything,

    // Error! Deleting p again is a double deletion, and is not allowed. It
    // could corrupt the entire free store memory system.
    delete p;

    // Running without valgrind crashes for me, saying a "double free" was
    // detected. That's good that it caught the problem with an error message,
    // but crashing is never good for a program. Better would have been to have
    // caught the error at compile-time (or earlier!).
}

void double_deletion_demo2() {
    cout << "double_deletion_demo2 ...\n";
    int* p = new int(25);  // p points to a new int on the free store
    int* q = p;            // q points to the same thing as p

    // use p and q, no problems
    cout << " p: " << p << "\n";
    cout << "*p: " << *p << "\n";

    cout << " q: " << q << "\n";
    cout << "*q: " << *q << "\n";


    delete p;  // de-allocate p, good

    // At this point p is a dangling pointer, i.e. it is pointing to
    // de-allocated memory. We should not use it in any way for anything,

    // Error! q points to the same thing as p, so deleting q is a double
    // deletion!
    delete q;

    // Running without valgrind crashes for me, saying a "double free" was
    // detected. That's good that it caught the problem with an error message,
    // but crashing is never good for a program. Better would have been to have
    // caught the error at compile-time (or earlier!).
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

// - pointing outside of legal memory (e.g. going off the end of an array)

int main() {
    different_address_demo();
    // dangling_pointer_demo1();
    // dangling_pointer_demo2();
    // memory_leak_demo();
    // double_deletion_demo1();
    // double_deletion_demo2();
    // swap1_bad_demo();
    // swap2_demo();
    // swap3_demo();
}
