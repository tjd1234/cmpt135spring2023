// date_struct.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;

struct Date {
    int day;   // 1 to 31
    int month; // 1 to 12
    int year;  // e.g. 2017
};

// is_valid checks if a Date object is valid. It doesn't catch all
// problems, e.g. it says {31, 1, 2020} (January 31st, 2020) is 
// valid, but there is no January 31st
bool is_valid(const Date& d) {
    return 1 <= d.day   && d.day   <= 31
        && 1 <= d.month && d.month <= 12
        && 0 <= d.year;
}

void print(const Date& d) {
    cout << "("  << d.day
         << ", " << d.month
         << ", " << d.year
         << ")";
}

void println(const Date& d) {
    print(d);
    cout << "\n";
}

//
// An alternative to writing a print and println function is 
// to overload the operator<<.
//
ostream& operator<<(ostream& out, const Date& d) {
    out << "("  << d.day       // note use of out, not cout!
        << ", " << d.month
        << ", " << d.year
        << ")";
    return out;
}

void check_validity(const Date& d) {
    if (is_valid(d)) {
        cout << d << " is valid\n";
    } else {
        cout << d << " is NOT valid\n";
    }
}

void test_date() {
    cout << "\ntest_date():\n";
    Date d{1, 11, 2000}; // November 1, 2000
    cout << "d = " << d << "\n";
    check_validity(d);
    d.day = 14;
    cout << "d = " << d << "\n";
    check_validity(d);    
    d.year = -343;       // nothing to stop nonsensical data!
    check_validity(d);
    cout << "d = " << d << "\n";
}

// Same as test_date(), but using dynamic memory instead.
void test_date_ptr() {
    cout << "\ntest_date_ptr():\n";
    Date* d = new Date{1, 11, 2000}; // November 1, 2000
    cout << "*d = " << *d << "\n";
    check_validity(*d);
    d->day = 14;
    cout << "*d = " << *d << "\n";
    check_validity(*d);
    d->year = -343;                  // nothing to stop nonsensical data!
    check_validity(*d);
    cout << "*d = " << *d << "\n";

    delete d;                        // remember to de-allocate dynamic 
}                                    // memory

int main() {
    test_date();
    test_date_ptr();
} // main
