// int_vec.cpp

#include "int_vec.h"

void int_vec::resize(int new_cap) {
    if (new_cap < capacity) return;
    capacity = new_cap;

    int* new_arr = new int[capacity];  // create new, bigger array

    for(int i = 0; i < size; ++i) {    // copy elements of arr
        new_arr[i] = arr[i];           // into new_arr
    }

    delete[] arr;                     // delete old arr

    arr = new_arr;                    // assign new_arr
}

int_vec::int_vec() 
: capacity(10), arr(new int[capacity]), size(0)
{ }

int_vec::int_vec(int sz, int fill_value)
: capacity(10), size(sz)
{
    if (size < 0) cmpt::error("can't construct int_vec of negative size");
    if (size > 0) capacity += size;
    arr = new int[capacity];
    for(int i = 0; i < size; ++i) {
        arr[i] = fill_value;
    }
}

int_vec::int_vec(const int_vec& other)
: capacity(other.capacity), arr(new int[capacity]), size(other.size)
{
    cout << "int_vec copy constructor called ...\n";
    for(int i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

int_vec::~int_vec() {
    cout << "... ~int_vec called\n";
    delete[] arr;
}

int int_vec::get_size() const {
    return size;
}

int int_vec::get_capacity() const {
    return capacity;
}

int int_vec::get(int i) const {
    if (i < 0 || i > size) cmpt::error("get: index out of bounds");
    return arr[i];
}

void int_vec::set(int i, int x) {  
    if (i < 0 || i > size) cmpt::error("get: index out of bounds");
    arr[i] = x;
}

int& int_vec::operator[](int i) {
    cout << "(modifying operator[] called)\n";
    return arr[i];
}

int int_vec::operator[](int i) const {
    cout << "(const operator[] called)\n";
    return arr[i];
}

void int_vec::print() const {
    if (size == 0) {
        cout << "{}";
    } else {
        cout << "{";
        cout << arr[0];
        for (int i = 1; i < size; ++i) {  // i starts at 1 (not 0)
            cout << ", " << arr[i];
        }
        cout << "}";
    }
}

void int_vec::println() const {
    print();
    cout << "\n";
}

void int_vec::append(int x) {
   if (size >= capacity) {
        resize(2 * capacity);   // double the capacity
   }
   assert(size < capacity);
   arr[size] = x;
   size++;
}

int_vec& int_vec::operator=(const int_vec& other) {
    // self-assignment is a special case: don't need to do anything
    if (this == &other) {
        return *this;
    } else {
        // re-size this int_vecs underlying array if necessary
        if (capacity < other.size) {
            resize(other.size + 10);     // a little bit of extra capacity
        }                                // to speed up append
        
        size = other.size;           

        for(int i = 0; i < size; ++i) {  // copy other's values
            arr[i] = other.arr[i];       // into this array
        }

        return *this;
    }
}

////////////////////////////////////////////////////////////////////////////////

void clear(int_vec& v) {
    v.size = 0;
}

bool operator==(const int_vec& a, const int_vec& b) {
    if (a.get_size() != b.get_size()) {
        return false;
    } else {
        for(int i = 0; i < a.get_size(); ++i) {
            if (a.get(i) != b.get(i)) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const int_vec& a, const int_vec& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const int_vec& arr) {
    if (arr.get_size() == 0) {
        os << "{}";
    } else {
        os << "{";
        os << arr.get(0);
        for (int i = 1; i < arr.get_size(); ++i) {  // i starts at 1 (not 0)
            os << ", " << arr.get(i);
        }
        os << "}";
    }
    return os;
}
