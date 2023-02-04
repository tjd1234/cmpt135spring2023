// double_list.cpp

#include <iostream>
#include <cassert>
#include "cmpt_error.h"
#include <algorithm>

using namespace std;

struct double_list {
private:
    double* arr;    // pointer to the underlying array
    int capacity;   // length of underlying array
    int size;       // # of elements from user's perspective

public:
    // Default constructor: takes no input and makes an array of 
    // size 0
    double_list()
    : double_list(0)  // constructor delegation
    { }

    // double_list has a constructor that must be called whenever 
    // you create a new double_list. It ensures all the variables 
    // are properly initialized.
    double_list(int n)
    : capacity(2*n + 1), size(n)  // initializer list
    {
        if (n < 0) 
           cmpt::error("double_list(int n): n must be 0 or greater");
        arr = new double[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Copy constructor: makes a copy of another double_list. The 
    // copy has the same size, capacity and values, and its own
    // underlying array.
    double_list(const double_list& other) 
    : arr(new double[other.capacity]), 
      capacity(other.capacity), 
      size(other.size)
    {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    void append_right(double x) {
        if (size >= capacity) {
            // double the capacity of the array

            // make a new array about twice the size of the current
            // one
            capacity = 2 * capacity;
            double* arr_new = new double[capacity];

            // copy the elements from the old array into the new one
            for(int i = 0; i < size; i++) {
                arr_new[i] = arr[i]; 
            }

            // de-allocate the old array
            delete[] arr;

            // make lst.arr point to the new array
            arr = arr_new;
        }

        // add x to the first unused location on the right end
        arr[size] = x;
        size++;
    }

    int get_size() const { return size; }

    // A setter: set(i, x) assigns a copy of x to location i of the
    // underlying array of lst.
    void set(int i, double x) {
        if (i < 0 || i >= size) cmpt::error("set: index out of bounds");
        arr[i] = x;
    }

    // A getter: returns the value at index location i of the
    // underlying array.
    double get(int i) const {
        if (i < 0 || i >= size) cmpt::error("get: index out of bounds");
        return arr[i];
    }
    
    // Notice that get(i) is used in the for-loop, as a 
    // demonstration for how to call it.
    void print() const {
        cout << "lst capacity = " << capacity << ", "
             << "lst size = "     << size     << "\n";
        for (int i = 0; i < size; i++) {
            cout << "lst.arr[" << i << "] = " << get(i) << "\n";
        }
    }

    double sum() const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    void sort_ascending() {
        std::sort(arr, arr + size);
    }

    // Destructor. Always called automatically when the object is
    // de-allocated. The programmer cannot call it manually.
    ~double_list() {
        delete[] arr;
    }
}; // struct double_list

double average(const double_list& lst) {
    return lst.sum() / lst.get_size();
}

void sort_descending(double_list& lst) {
    lst.sort_ascending();
    // std::reverse(arr, arr + size);
    int a = 0;
    int b = lst.get_size() - 1;
    while (a < b) {
        double temp = lst.get(a); // temp = a
        lst.set(a, lst.get(b));   // a = b
        lst.set(b, temp);         // b = temp
        a++;
        b--;
    }
}

int main() {
    double_list lst(0);

    // set the first three numbers of lst to be: 0, 6, 2.5
    lst.append_right(0);
    lst.append_right(6);
    lst.append_right(2.6);

    // print lst, one number per line
    lst.print();

    // lst2 is a copy of lst
    double_list lst2(lst);
    lst2.print();

    // print the sum and average
    cout << "    sum = " << lst2.sum()    << "\n";
    cout << "average = " << average(lst2) << "\n";

    lst2.print();
    lst2.sort_ascending();
    lst2.print();
    sort_descending(lst2);
    lst2.print();

    // destructors automatically called
}