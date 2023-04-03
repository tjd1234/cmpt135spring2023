```cpp
// double_list.cpp

#include <iostream>
#include <cassert>
#include "cmpt_error.h"
#include <algorithm>

using namespace std;

struct double_list {
    double* arr;    // pointer to the underlying array
    int capacity;   // length of underlying array
    int size;       // # of elements from user's perspective
};


// Returns a new double_list of size 0 and capacity 10.
double_list make_empty_double_list() {
    double_list result;
    result.capacity = 10;
    result.arr = new double[result.capacity];
    result.size = 0;
    return result;
}

// prints lst to cout
void print(double_list lst) {
    cout << "\n";
    cout << "lst.capacity = " << lst.capacity << ", "
         << "lst.size = "     << lst.size     << "\n";
    for (int i = 0; i < lst.size; i++) {
        cout << "   lst.arr[" << i << "] = " << lst.arr[i] << "\n";
    }
}

// De-allocate the underlying array of lst.
void deallocate(double_list lst) {
    delete[] lst.arr;
}

// Appends the number x to the right end of the array, increasing 
// it's size by 1. If necessary, it will also double the capacity.
//
// IMPORTANT: lst must be passed by reference since lst.size (and 
// maybe also lst.capacity) is changed. 
//
// IMPORTANT: The line delete[] lst.arr fails if lst.capacity is 0. 
// To prevent this, the make_double_empty_list must always sets the 
// capacity to a value greater than 0.
void append_right(double_list& lst, double x) {
    //
    // double capacity of array, if needed
    //
    if (lst.size >= lst.capacity) {
        //
        // make a new array twice the size of the current one
        //
        lst.capacity = 2 * lst.capacity;
        double* arr_new = new double[lst.capacity]; 

        for(int i = 0; i < lst.size; i++) {  // copy the elements from 
            arr_new[i] = lst.arr[i];         // the old array into the 
        }                                    // new one
       
        delete[] lst.arr;   // de-allocate the old array
        lst.arr = arr_new;  // make lst.arr point to the new array
    }
    
    lst.arr[lst.size] = x;
    lst.size++;
}

// returns the sum of all elements in lst
double sum(double_list lst) {
    double result = 0;
    for(int i = 0; i < lst.size; i++) {
        result += lst.arr[i];
    }
    return result;
}

// Set all elements of lst to fill_value.
void fill(double_list lst, int fill_value) {
    for(int i = 0; i < lst.size; i++) {
        lst.arr[i] = fill_value;
    }
}

// std::sort is C++'s standard sorting function from the 
// <algorithm> include. The input to std::sort is a pointer 
// to the first element of the underlying array, and a 
// pointer to one past the last element.
void sort_ascending(double_list lst) {
    std::sort(lst.arr, lst.arr + lst.size);
}

int main() {
    double_list lst = make_empty_double_list();
    
    // append some numbers to the end of lst
    append_right(lst, 0);
    append_right(lst, 6);
    append_right(lst, 2.5);
    
    // print the sum and average
    cout << "sum = " << sum(lst) << "\n";
    
    // print lst, one number per line
    print(lst);
    sort_ascending(lst);
    print(lst);

    fill(lst, 5);
    print(lst);

    for(int i = 0; i < 100; i++) {
        append_right(lst, i);
    }
    print(lst);

    deallocate(lst);
}
```