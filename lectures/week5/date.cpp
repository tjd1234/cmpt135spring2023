// date.cpp

#include "cmpt_error.h"
#include <iostream>

using namespace std;

class Date {
private:
    int day;   // 1 to 31
    int month; // 1 to 12
    int year;  // e.g. 2017

public:
    // constructor
    Date(int d, int m, int y)
    : day{d}, month{m}, year{y}  // initializer list
    { }

    // destructor
    ~Date() {
        cout << "Date destructor called\n";
    }

    // getters
    int get_day() const { // const method
        return day;
    }

    int get_month() const { // const method
        return month;
    }

    int get_year() const { // const method
        return year;
    }

    // setters
    bool set_day(int d) {
        if (d >= 1 || d <= 31) {
            day = d;
            return true;
        }
        return false;
    }

    void set_dmy(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void print() const {  // const method
        cout << "(" << day
             << ", " << month
             << ", " << year
             << ")";
    }

    void println() const { // const method
        print();
        cout << "\n";
    }

}; // class Date


void test_date() {
    cout << "\ntest_date():\n";
    Date d{1, 11, 2000}; // November 1, 2000
    cout << "d = ";
    d.println();
}

// Same as test_date(), but using dynamic memory instead.
void test_date_ptr() {
    cout << "\ntest_date_ptr():\n";
    Date* d = new Date{1, 11, 2000}; // November 1, 2000
    cout << "*d = ";
    d->println();

    delete d;
}

int main() {
    test_date();
    test_date_ptr();
} // main
