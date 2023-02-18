// exception_destructor.cpp

#include <iostream>

using namespace std;

void error(const string& message)
{
    throw std::runtime_error(message);
    cout << "This line is never executed!\n";
}

class Thing {
    int* arr;
public:
    Thing() 
    : arr(new int[10])
    { }

    ~Thing() {
        delete[] arr;
        cout << "... Thing destructor called\n";
    }
}; // class Thing

void error_test() {
    Thing x;

    error("testing 1, 2, 3");

    cout << "goodbye!\n";
    // Is the array x.arr deleted when an
    // exception thrown? Or is there a memory leak?
}

int main() {
    try {
        error_test();
    } catch (...) {
        cout << "caught an exception\n";
    }
    
    cout << "all done\n";
}
