// int_vec.h

#ifndef INT_VEC_H
#define INT_VEC_H

#include <iostream>
#include "cmpt_error.h"
#include <cassert>

using namespace std;

class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective

    void resize(int new_cap);

public:
    int_vec();
    int_vec(int sz, int fill_value);
    int_vec(const int_vec& other);

    ~int_vec();

    int get_size() const;
    int get_capacity() const;

    int get(int i) const;
    void set(int i, int x);


    int& operator[](int i); 
    int operator[](int i) const;

    void print() const;
    void println() const;

    void append(int x);

    int_vec& operator=(const int_vec& other);

    friend void clear(int_vec& v);
}; // class int_vec

void clear(int_vec& v);

bool operator==(const int_vec& a, const int_vec& b);
bool operator!=(const int_vec& a, const int_vec& b);

ostream& operator<<(ostream& out, const int_vec& arr);

#endif
