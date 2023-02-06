// printing.cpp

#include "cmpt_error.h"
#include <iostream>
#include <vector>

using namespace std;

class Printable
{
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const
    {
        print();
        cout << "\n";
    }

    // A base class should always provide a virtual destructor. This allows any
    // inheriting classes the option of providing their own destructor and
    // having it called correctly.
    virtual ~Printable() {}
}; // class Printable

class Point : public Printable
{
private:
    double x;
    double y;

public:
    // default constructor
    Point() : x(0), y(0) {}

    // copy constructor
    Point(const Point &other) : x(other.x), y(other.y) {}

    Point(double a, double b) : x(a), y(b) {}

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const
    {
        cout << "Point(" << x << ", " << y << ')';
    }
}; // class Point

class Person : public Printable
{
    string name;
    int age;

public:
    Person(const string &n, int a)
        : name(n), age(a)
    {
        if (age < 0)
            cmpt::error("negative age");
    }

    string get_name() const { return name; }
    int get_age() const { return age; }

    void print() const
    {
        cout << "Name: '" << name << ", Age: " << age;
    }
}; // class Person

class Reading : public Printable
{
private:
    string loc;
    double temp;

public:
    Reading(const string &l, double t)
        : loc(l), temp(t)
    {
    }

    string get_loc() const { return loc; }
    double get_temp() const { return temp; }

    void print() const
    {
        cout << temp << " degrees at " << loc;
    }
}; // class Reading

void polymorphism_example()
{
    Printable *p;
    string s;
    cout << "Do you prefer points or people? ";
    cin >> s;
    if (s == "points")
    {
        p = new Point(2, 3);
    }
    else
    {
        p = new Person("Jill", 93);
    }

    p->print(); // Which print is called?
                // Point's or Person's?
}

void pointer_example1()
{
    Printable *p1 = new Point{1, 2};
    Printable *p2 = new Person{"Max", 2};
    Printable *p3 = new Reading{"Black Rock", 41.5};

    p1->println(); // (1, 2)
    p2->println(); // Name: 'Max, Age: 2
    p3->println(); // 41.5 degrees at Black Rock

    delete p1;
    delete p2;
    delete p3;
}

void pointer_example2()
{
    vector<Printable *> v = {new Point{1, 2},
                             new Person{"Max", 2},
                             new Reading{"Black Rock", 41.5}};
    for (Printable *p : v)
    {
        p->print();
        cout << "\n";
    }

    // de-allocate memory
    for (Printable *p : v)
    {
        delete p;
    }
}

int main()
{
    // Point a(1, 2);
    // a.println();

    // Person b("Katja", 22);
    // b.println();

    // Reading c("backyard", 2.4);
    // c.println();

    // polymorphism_example();
    // pointer_example1();
    pointer_example2();
}
