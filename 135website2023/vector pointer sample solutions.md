```cpp
// pointer_sum.cpp

//
// Practice using pointers.
//
// Gives examples of how to use a vector<int*>.
//

#include <iostream>
#include <vector>

using namespace std;

// - Create an empty vector of int* pointers named pv.
// - Allocate three new ints on the free store, and store pointers to 
//   them in pv.
// - Print the ints pv points to.
// - Print the sum of the ints pv points to.
// - De-allocate the ints pv points to so there's no memory leak.
void vector_example1() {
    cout << "vector_example1 ...\n";

    // Create an empty vector of int* pointers named pv.
    vector<int*> pv;

    // Create three new ints on the free store, and store pointers to 
    // them in in pv.
    pv.push_back(new int(8));
    pv.push_back(new int(4));
    pv.push_back(new int(15));

    // Print the ints pv points to.
    for(int i = 0; i < pv.size(); i++) {
        cout << *pv[i] << "\n";
    }

    // Print the sum of the ints pv points to.
    int total = 0;
    for(int i = 0; i < pv.size(); i++) {
        total += *pv[i];
    }
    cout << "total: " << total << "\n";

    // De-allocate the ints pv points to so there's no memory leak.
    for(int i = 0; i < pv.size(); i++) {
        delete pv[i];
    }
    //
    // DANGER: at this point all the pointers in pv are dangling pointers.
    //
} // vector_example1

// - Create an empty vector of int* pointers named pv.
// - Create a single new int on the free store, and add three pointers 
//   to pv that each point to it.
// - Print the ints pv points to.
// - Print the sum of the ints pv points to.
// - De-allocate the ints pv points to so there's no memory leak.
//   **Careful**: it's an error to call delete more than once on the same
//   pointer!
void vector_example2() {
    cout << "vector_example2 ...\n";

    // Create an empty vector of int* pointers named pv.
    vector<int*> pv;

    // Create a single new int on the free store, and add three pointers
    // to pv that each point to it.
    int* p = new int(4);
    pv.push_back(p);
    pv.push_back(p);
    pv.push_back(p);

    // Print the ints pv points to.
    for(int i = 0; i < pv.size(); i++) {
        cout << *pv[i] << "\n";
    }

    // Print the sum of the ints pv points to.
    int total = 0;
    for(int i = 0; i < pv.size(); i++) {
        total += *pv[i];
    }
    cout << "total: " << total << "\n";

    // De-allocate the ints pv points to so there's no memory leak.
    // Careful: it's an error to call delete more than once on the same
    // pointer!
    delete p;
    //
    // DANGER: at this point p is a dangling pointer.
    //
} // vector_example2


// - Create a pointer to a vector<int*> named pv.
// - Make pv point to an empty vector<int*> allocated on the free store.
// - Create three new ints on the free store, and store pointers to them
//   in pv.
// - Print the ints pv points to.
// - Print the sum of the ints pv points to.
// - De-allocate the ints pv points to so there's no memory leak.
// - De-allocate the vector<int*> pv points to so there's no memory leak.
void vector_example3() {
    cout << "vector_example3 ...\n";

    // Create a pointer to a vector<int*> named pv.
    vector<int*>* pv;

    // Make pv point to an empty vector<int*> allocated on the free store.
    pv = new vector<int*>();

    // Create three new ints on the free store, and store pointers to 
    // them in pv.
    pv->push_back(new int(8));
    pv->push_back(new int(4));
    pv->push_back(new int(15));

    // Print the ints pv points to.
    for(int* p : *pv) {
        cout << *p << "\n";
    }
    // for(int i = 0; i < pv->size(); i++) {
    //     cout << *(*pv)[i] << "\n";
    // }

    // Print the sum of the ints pv points to.
    int total = 0;
    for(int* p : *pv) {
        total += *p;
    }
    // for(int i = 0; i < pv->size(); i++) {
    //     total += *(*pv)[i];
    // }
    cout << "total: " << total << "\n";

    // De-allocate the ints pv points to so there's no memory leak.
    for(int* p : *pv) {
        delete p;
    }
    // for(int i = 0; i < pv->size(); i++) {
    //     delete (*pv)[i];
    // }

    //
    // DANGER: at this point the pointers in pv are dangling pointers.
    //

    // De-allocate the vector<int*> pv points to.
    delete pv;
    //
    // DANGER: At this point pv is a dangling pointer. The pointers in pv
    //         are no longer dangling pointers because the vector that
    //         contains them has been de-allocated.
    //
} // vector_example3

int main() {
    vector_example1();
    // vector_example2();
    // vector_example3();
}
```