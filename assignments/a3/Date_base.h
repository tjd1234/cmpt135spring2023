// Date_base.h

////////////////////////////////////////////////////////////////////////////
//
// Date_base class
//
////////////////////////////////////////////////////////////////////////////

#include <string>

using namespace std;

// tell the compiler that Date is a class
class Date;

class Date_base
{
public:
	//
    // virtual destructor
	//
    virtual ~Date_base() {}

	//
	// getters
	//
	// return the year, month, and day
	virtual int get_year() const = 0;
	virtual int get_month() const = 0;
	virtual int get_day() const = 0;

	//
	// setters
	//
	// set the year, month, and day
	virtual void set_year(int new_year) = 0;
	virtual void set_month(int new_month) = 0;
	virtual void set_day(int new_day) = 0;

	//
	// assignment operator
	//
	// virtual Date &operator=(const Date &other) = 0;

	//
	// printing
	//
	// returns a string representation of the date, as specified in the
	// assignment
	// virtual string to_string() const = 0;
}; // class Date_base

// Date comparison operators
bool operator<(const Date& d1, const Date& d2);
