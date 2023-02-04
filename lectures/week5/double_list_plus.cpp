// double_list_plus.cpp

//
// This is the same as double_list.cpp, but with a few more features:
//
// - A to_string() method for nicer and more flexible printing.
// - Overloaded operator<< for easier printing with cout.
// - Overloaded operator[] for getting and setting individual values, e.g. it
//   lets us write a[i] = 5 and cout << a[i]
// - An assignment operator. If a and b are double_lists, then you can assign b
//   to a by writing a = b.
// - operator== for comparing two double_lists, e.g. a == b true just when a and
//   b have the same values.
//

#include "cmpt_error.h"
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

struct double_list {
private:
    double* arr;    // pointer to the underlying array
    int capacity;   // length of underlying array
    int size;       // # of elements from user's perspective

// public members can be accessed by any code.
public:
    // Default constructor: takes no input and makes an array of 
    // size 0
    double_list()
    : double_list(0)  // constructor delegation
    { }

    // constructor to make a double_list of size n, all elements initialized to
    // 0
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

    // copy constructor: make a copy of another double_list
    double_list(const double_list& other) 
    : arr(new double[other.capacity]), 
      capacity(other.capacity), 
      size(other.size)
    {
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // add a new element to the right end of this list, increasing its size by
    // 1; if necessary, also double the capacity of the underlying array
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

    // getters and setters

    int get_size() const { return size; }
    int get_capacity() const { return capacity; }

    // set(i, x) assigns a copy of x to location i of the underlying array of
    // lst.
    void set(int i, double x) {
        if (i < 0 || i >= size) cmpt::error("set: index out of bounds");
        arr[i] = x;
    }

    // get(i) returns the value at index location i of the underlying array.
    double get(int i) const {
        if (i < 0 || i >= size) cmpt::error("get: index out of bounds");
        return arr[i];
    }

    // Overloaded operator[]: lst[i] returns a reference to the value at index
    // location i of the underlying array. It must be a reference to a double to
    // allow the value to be changed. If the return type was a plain double,
    // then it would return a copy of the value, and the value in the array
    // would not be changed.
    double& operator[](int i) {
        if (i < 0 || i >= size) cmpt::error("operator[]: index out of bounds");
        return arr[i];
    }

    // This version of operator[] is const, which allows us to use [] with a
    // constant double list. It returns a double (not a reference to a double),
    // and so doesn't modify the underlying array.
    double operator[](int i) const {
        if (i < 0 || i >= size) cmpt::error("operator[]: index out of bounds");
        return arr[i];
    }
    
    // replace this double_list with a copy of the other one
    void replace_with_copy_of(const double_list& other) {
        // check for self-assignment, e.g. lst = lst
        if (this == &other) return;

        // de-allocate the old array
        delete[] arr;

        // make a new array of the same size as other
        capacity = other.capacity;
        size = other.size;
        arr = new double[capacity];

        // copy the elements from other into the new array
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // assignment operator: makes this double_list a copy of other; this is
    // essentially the same as replace_with_copy_of, but it lets you write a = b
    // instead of a.replace_with_copy_of(b); and it returns a reference to this,
    // which is standard C++ behaviour and allows you to chain assignments, e.g.
    // a = b = c.
    double_list& operator=(const double_list& other) {
        replace_with_copy_of(other);

        // return a reference to this object
        return *this;
    }

    // print the contents of the list to cout
    void print() const {
        cout << "lst capacity = " << capacity << ", "
             << "lst size = "     << size     << "\n";
        for (int i = 0; i < size; i++) {
            cout << "lst.arr[" << i << "] = " << get(i) << "\n";
        }
    }

    // comma-separated list of values as a string, wrapped in curly braces
    string to_string() const {
        string result = "{";
        for (int i = 0; i < size; i++) {
            if (i > 0) result += ", ";
            result += std::to_string(get(i));
        }
        result += "}";
        return result;
    }

    // returns the sum of all elements in this list
    double sum() const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    // sort all elements in this list in ascending order, i.e. smallest to
    // biggest
    void sort_ascending() {
        std::sort(arr, arr + size);
    }

    // destructor
    ~double_list() {
        delete[] arr;
    }
}; // struct double_list

// this lets you use << for printing
ostream& operator<<(ostream& out, const double_list& lst) {
    out << lst.to_string();
    return out;
}

// test if two double_lists have the same elements in the same order
bool operator==(const double_list& a, const double_list& b) {
    if (a.get_size() != b.get_size()) return false;
    for (int i = 0; i < a.get_size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// return the average of all the elements in lst
double average(const double_list& lst) {
    return lst.sum() / lst.get_size();
}

// sort all the elements in lst in descending order, i.e. biggest to smallest
void sort_descending(double_list& lst) {
    lst.sort_ascending();
    // std::reverse(arr, arr + size);
    int a = 0;
    int b = lst.get_size() - 1;
    while (a < b) {
        // double temp = lst.get(a); // temp = a
        // lst.set(a, lst.get(b));   // a = b
        // lst.set(b, temp);         // b = temp
        double temp = lst[a];
        lst[a] = lst[b];
        lst[b] = temp;
        a++;
        b--;
    }
}

int main() {
    // list of size 10, initialized to all 0's
    double_list lst1(10);
    cout << "lst1 = " << lst1  // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
         << "\n";

    // add some numbers
    for(int i = 0; i < 10; i++) {
        lst1[i] = i;  // non-const operator[] used to set the value
    }

    // a constant list (once it's created, it can't be changed)
    const double_list lst2(lst1);
    for(int i = 0; i < lst2.get_size(); i++) {
        cout << lst2[i] << " ";  // const operator[] used to get the value
    }
    cout << "\n";

    // make an empty list
    double_list lst3;
    cout << "lst3 = " << lst3 << "\n"; // {}
    lst3.append_right(6);
    cout << lst3 << "\n"; // {6}
    
    lst3 = lst2;
    assert(lst3 == lst2);
    cout << lst3 << "\n"; // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
} // main
