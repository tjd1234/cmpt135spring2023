// double_list.cpp

#include <iostream>
#include <cassert>
#include "cmpt_error.h"
#include <algorithm>

using namespace std;

class double_list {
private:
    double* arr;    // pointer to the underlying array
    int capacity;   // length of underlying array
    int size;       // # of elements from user's perspective
public:
    // default constructor
    double_list()
    : arr(new double[10]), capacity(10), size(0)  // initializer list
    { }

    // copy constructor
    double_list(const double_list& lst)
    : arr(new double[lst.capacity]), capacity(lst.capacity), size(lst.size)
    {
        for(int i = 0; i < size; i++) {
            arr[i] = lst.arr[i];
        }
    }

    ~double_list() {
        delete[] arr;
        cout << "double_list destructor called\n";
    }

    // getters
    int get_capacity() const { return capacity; }
    int get_size()     const { return size;     }
    int get(int i) const {
        assert(i >= 0 && i < size); // bounds checking
        return arr[i];
    }

    // setters
    void set(int i, double x) {
        assert(i >= 0 && i < size); // bounds checking
        arr[i] = x;
    }

    // prints lst to cout
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << "   arr[" << i << "] = " << arr[i] << "\n";
        }
        cout << "capacity = " << capacity << ", "
             << "size = "     << size     << "\n\n";
    }

    // Appends the number x to the right end of the array, increasing it's size by
    // 1. If necessary, it will also double the capacity.
    //
    // IMPORTANT: lst must be passed by reference since lst.size (and maybe also
    // lst.capacity) is changed. 
    //
    // IMPORTANT: The line delete[] lst.arr fails if lst.capacity is 0. To prevent
    // this, the make_double_empty_list must always sets the capacity to a value
    // greater than 0.
    void append_right(double x) {
        // double the capacity of array, if necessary
        if (size >= capacity) { 
            capacity = 2 * capacity;                // make a new array 
            double* arr_new = new double[capacity]; // twice the size 
            
            for(int i = 0; i < size; i++) {  // copy elements 
                arr_new[i] = arr[i];         // into new one
            }
        
            delete[] arr;   // de-allocate the old array
            arr = arr_new;  // point to the new array
            cout << "doubled capacity to " << capacity << "\n";
        }
        arr[size] = x;
        size++;
    }

    // returns the sum of all elements in lst
    double sum() const {
        double result = 0;
        for(int i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    // std::sort is C++'s standard sorting function from the <algorithm> include.
    // The input to std::sort is a pointer to the first element of the underlying
    // array, and a pointer to one past the last element.
    void sort_ascending() {
        std::sort(arr, arr + size);
    }

    void sort_descending() {
        sort_ascending();
        reverse();
    }

    void reverse() {
        std::reverse(arr, arr + size);
    }
}; // class double_list

void outside_print(double_list lst) {
    for (int i = 0; i < lst.get_size(); i++) {
        cout << "   arr[" << i << "] = " << lst.get(i) << "\n";
    }
    cout << "capacity = " << lst.get_capacity() << ", "
            << "size = "  << lst.get_size()     << "\n\n";
}

/*

// set all elements of lst to fill_value
void fill(double_list lst, int fill_value) {
    for(int i = 0; i < lst.size; i++) {
        lst.arr[i] = fill_value;
    }
}


int main() {
    double_list lst = make_empty_double_list();
    
    // add some numbers
    append_right(lst, 6);
    append_right(lst, -1);
    append_right(lst, 2);
    
    // print their sum 
    cout << "sum = " << sum(lst) << "\n";
    
    // sort from smallest to biggest
    print(lst);
    sort_ascending(lst);
    print(lst);

    // fill with 5's
    fill(lst, 5);
    print(lst);

    // add 100 more numbers
    for(int i = 0; i < 100; i++) {
        append_right(lst, i);
    }
    print(lst);

    // de-allocate the underlying array to avoid a memory leak
    deallocate(lst);

    cout << "double_list.cpp: done\n";
} // main
*/

int main() {
    double_list lst;
    lst.print();
    for(int i = 0; i < 100; i++) {
        lst.append_right(i);
    }
    lst.print();
    cout << "sum = " << lst.sum() << "\n";

    double_list lst2;
    lst2.append_right(5);
    lst2.append_right(3);
    lst2.append_right(7);
    lst2.set(1, 4);
    lst2.sort_ascending();
    lst2.print();

    double_list lst3(lst2);
    lst2.print();
    outside_print(lst2);
}
