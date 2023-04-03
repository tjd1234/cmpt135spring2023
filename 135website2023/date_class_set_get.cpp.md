```cpp
// date_class_private.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;

class Date {
    //
    // By default, members of a class are private, i.e. not 
    // accessible to code outside the class.
    //
    // A common pattern is to make the member variables of a class 
    // private, and then to provide public methods for accessing 
    // variables in a controlled way.
    //
    int day;   // 1 to 31
    int month; // 1 to 12
    int year;  // e.g. 2017

public:
    // constructor: assigns values to member variables
    Date(int d, int m, int y)
    : day(d), month(m), year(y)  // initialization list
    { }

    // is_valid() is a method, i.e. a function in a class, and can 
    // access the  members of the class with needing to be explicitly 
    // passed a variable
    //
    // The keyword "const" after the name and before the body 
    // indicates that this is a non-mutating method, i.e. calling 
    // is_valid will *never* change the variables in a date.
    bool is_valid() const {
        return 1 <= day   && day   <= 31
            && 1 <= month && month <= 12
            && 0 <= year;
    }

    // The keyword "const" after the name and before the body 
    // indicates that this is a non-mutating method, i.e. calling 
    // print will *never* change the variables in a date.
    void print() const {
        cout << "("  << day
             << ", " << month
             << ", " << year
             << ")";
    }

    // The keyword "const" after the name and before the body 
    // indicates that this is a non-mutating method, i.e. calling 
    // print will *never* change the variables in a date.
    void println() const {
        print();
        cout << "\n";
    }

    // Getters: methods that return the value of a variable. Getters 
    // should not modify the object, and so they are declared const.
    int get_day()   const { return day;   }
    int get_month() const { return month; }
    int get_year()  const { return year;  }

    // Setters: methods that change the value of a variable. Setters 
    // are never const because they modify the object.
    void set_day(int d)   { day   = d; }
    void set_month(int m) { month = m; }
    void set_year(int y)  { year  = y; }
}; // class Date

//
// An alternative to writing a print and println function is to 
// overload the operator<<.
//
ostream& operator<<(ostream& out, const Date& d) {
    out << "("  << d.get_day()       // note use of out, not cout!
        << ", " << d.get_month()
        << ", " << d.get_year()
        << ")";
    return out;
}

// check_validity is not a method because it does not appear inside 
// the Date class; so we must pass it a Date object
void check_validity(const Date& d) {
    if (d.is_valid()) {
        cout << d << " is a valid date\n";
    } else {
        cout << d << " is NOT a valid date\n";
    }
}

void test_date() {
    cout << "\ntest_date():\n";
    Date d{1, 11, 2000};    // November 1, 2000
    cout << "d = " << d << "\n";
    check_validity(d);
    d.set_day(14);
    cout << "d = " << d << "\n";
    check_validity(d);    
    d.set_year(-343);       // nothing to stop nonsensical data!
    check_validity(d);
    cout << "d = " << d << "\n";
}

// Same as test_date(), but using dynamic memory instead.
void test_date_ptr() {
    cout << "\ntest_date_ptr():\n";
    Date* d = new Date{1, 11, 2000}; // November 1, 2000
    cout << "*d = " << *d << "\n";
    check_validity(*d);
    d->set_day(14);
    cout << "*d = " << *d << "\n";
    check_validity(*d);
    d->set_year(-343);       // nothing to stop nonsensical data!
    check_validity(*d);
    cout << "*d = " << *d << "\n";

    delete d;                // remember to de-allocate dynamic memory
}

int main() {
    Date xmas{25, 12, 2021};  // Dec 25, 2021
    xmas.println();
    check_validity(xmas);
    cout << "Christmas: " << xmas << "\n";

    test_date();
    test_date_ptr();
} // main
```
