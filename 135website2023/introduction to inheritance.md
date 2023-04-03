Inheritance is a trick for making new classes by extending old classes.

## Example: an int_vec from a vector
The standard `vector<int>` class has many uses, and lets us write code like this:

```cpp
vector<int> v;
v.push_back(4);
v.push_back(5);
v.push_back(1);
for(int n : v) cout << n << "\n";
```

Now suppose we want a new class that is just like ``vector<int>``, but the vector has a few extra features, e.g.:

```cpp
int_vec v("Table 1");    // extra feature: vector has a name
v.push_back(4);
v.push_back(5);
v.push_back(1);

cout << v.get_name() << "\n";        // extra feature: name getter
v.sort_increasing();                 // extra feature: sort the vector
for(int n : v) cout << n << "\n";
cout << "sum = " << v.sum() << "\n"; // extra feature: sum the vector
```

`int_vec` does everything a `vector<int>`, plus a little more. We could create `int_vec` from scratch, but it's much easier is to use inheritance to get all the features of `vector<int>` for free.

### Step 1: Inheriting from a vector
To create `int_vec`, we first start by inheriting from `vector<int>` like this:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class int_vec : public vector<int> {  // int_vec publicly inherits
                                      // from vector<int>
    // nothing yet!
}; // class int_vec

int main() {
    int_vec v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    for(int n : v) cout << n << "\n";
}
```

The line `class int_vec : public vector<int>` tells C++ we want all the members of `vector<int>` to be put into `int_vec`.  Even without adding anything else to `int_vec`, we now have a new class that does everything a `vector<int>` can do.

### A Note on public Inheritance
We are using [[public inheritance]] when we write ``: public vector<int>``

The `public` qualifier means that the `public` members of `vector<int>` remain `public` when inherited, and the `private` members remain `private`. In `public`-style inheritance, the visibility of member variables and methods in the class being inherited stay the same.

C++ also allows `: protected vector<int>`, which inherits all member variables and methods in `vector<int>` so that they are `protected` in `int_vec`. A `protected` member is essentially one that is accessible just in its class and any class that inherits from it.

C++ also allows `: private vector<int>` inheritance, which inherits all member variables or methods in `vector<int>` so that they are `private` in `int_vec`.

**In this course, inheritance will always mean** `public`-style inheritance,
e.g. `: public vector<int>`.


### Step 2: Adding the sum() Method
We can add new methods to `int_vec`, e.g.:

```cpp
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class int_vec : public vector<int> {
public:
    // The begin() and end() methods are inherited from vector<int>, 
    // and so we are free to use them in int_vec methods.
    int sum() const {
        return std::accumulate(begin(), end(), 0);
    }

    // An alternative implementation of sum using a C-style for-loop.
    int sum2() const {
        int result = 0;
        for(int i = 0; i < size(); i++) {
            result += (*this)[i];
        }
        return result;
    }

    // An alternative implementation of sum using a for-each loop.
    int sum3() const {
        int result = 0;
        for(int n : *this) {
            result += n;
        }
        return result;
    }

}; // class int_vec

int main() {
    int_vec v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    for(int n : v) cout << n << "\n";
    cout << " sum = " << v.sum()  << "\n";
    cout << "sum2 = " << v.sum2() << "\n";
    cout << "sum3 = " << v.sum3() << "\n";
}
```

`sum` returns the sum of all the elements in the `int_vec`. `begin()` and `end()` are methods defined in `vector<int>` that return [[iterators]] to the begin and end of the vector. `accumulate` is a standard [[STL]] function that sums elements, and so `std::accumulate(begin(), end(), 0)` returns the sum of all the elements in the vector (the 0 means that the accumulator starts with the value 0).

`sum1` and `sum2` give two other ways of summing the numbers. Both use the `this` pointer to access the class behind inherited from.

### Step 3: Adding a Sorting Method
Here's a helper method for sorting:

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class int_vec : public vector<int> {
public:
    // The begin() and end() methods are inherited from vector<int>, 
    // and so we are free to use them in int_vec methods.
    int sum() const {
        return std::accumulate(begin(), end(), 0);
    }

    // An alternative implementation of sum using a C-style for-loop.
    int sum2() const {
        int result = 0;
        for(int i = 0; i < size(); i++) {
            result += (*this)[i];
        }
        return result;
    }

    // An alternative implementation of sum using a for-each loop.
    int sum3() const {
        int result = 0;
        for(int n : *this) {
            result += n;
        }
        return result;
    }

    // The begin() and end() methods are inherited from vector<int>, 
    // and so we are free to use them in int_vec methods.
    void sort_increasing() {
        std::sort(begin(), end());
    }

}; // class int_vec

int main() {
    int_vec v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    v.sort_increasing();
    for(int n : v) cout << n << "\n";
    cout << " sum = " << v.sum()  << "\n";
    cout << "sum2 = " << v.sum2() << "\n";
    cout << "sum3 = " << v.sum3() << "\n";
}
```

The `int_vec::sort_increasing` method calls the standard [[STL]] sorting function named `std::sort`. 

### Step 4: Adding a Name
Now lets add a string for the name of the `int_vec`. This is a little more involved because we're making the name private, and adding a constructor to initialize it:

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

class int_vec : public vector<int> {
    string name;
public:
    // constructor requires a name
    int_vec(const string& s)
    : vector<int>(),  // call default constructor of vector<int>
      name(s)
    { }

    // name getter
    string get_name() const { return name; }

    int sum() const {
        return std::accumulate(begin(), end(), 0);
    }

    void sort_increasing() {
        std::sort(begin(), end());
    }

}; // class int_vec

int main() {
    int_vec v("Table 1");

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    v.sort_increasing();
    cout << v.get_name() << ":\n";
    for(int n : v) cout << n << "\n";
    cout << "sum = " << v.sum() << "\n";
}
```

First, notice how the constructor calls the [[default constructor]] of `vector<int>()` in its [[initialization list]]. This is important! We must call the constructor for `vector<int>` to ensure that its variables are initialized properly. We don't know what variables a `vector<int>` has, so the only way we can properly initialize them is to call the `vector<int>` constructor.

After the `vector<int>` constructor finishes, we then initialize `name`.

Second, we add a [[getter]] called `get_name` that returns the name of the `int_vec`. In this design, there's no way to change a name after it has been initialized.

Again, the important idea here is that `int_vec` *extends* the functionality of `vector<int>` by adding new methods and member variables. An `int_vec` does *everything* a `vector<int>` does, plus a little more.

### Using an int_vec When a vector is Needed
We can use `int_vec` in any situation that requires a `vector<int>`. Consider this code:

```cpp
// ...

void summarize(const vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    cout << "size: " << v.size() << "\n";
}

int main() {
    int_vec v("Table 1");

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    summarize(v);
}
```

`summarize` takes a `vector<int>` as input, but here we pass it an `int_vec`. This is fine, because we declared `int_vec` by inheriting from `vector<int>`, and so an `int_vec` can do everything a `vector<int>` can do (and more).

Now suppose we add the function `fancy_summarize`, which takes an `int_vec` as input:

```cpp
// ...

void fancy_summarize(const int_vec& v) {
    cout << v.get_name() << ":\n";
    for(int n : v) cout << "   " << n << "\n";
    cout << "sum = " << v.sum() << "\n";
}

int main() {
    int_vec v("Table 1");
    
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    
    summarize(v);
    cout << "\n";
    fancy_summarize(v);
}
```

Since `v` is of type `int_vec`, we can pass it to `fancy_summarize`. However, we *cannot* pass a `vector<int>` to `fancy_summarize`:

```cpp
int main() {
    vector<int> w;

    fancy_summarize(w);  // error: doesn't compile
}
```

This causes a compiler error because `fancy_summarize` needs an `int_vec`. You can see why: `fancy_summarize` calls `v.get_name()` and `v.sum()`, but a `vector<int>` does not have those methods.

## Class Diagrams
[[class diagram|Class diagrams]] are a visual notation for showing how classes relate. In such a diagram, classes are drawn as rectangles, with the name of the class written inside near the top edge. Under the title you write the any important member variables or methods. Arrows are used to indicate inheritance.

For example, this [[class diagram]] shows that the `int_vec` class inherits from the `vector<int>` class:

![[int_vec_ClassDiagram.svg]]

The direction of the arrow is important: it points from the inheriting class (`int_vec`) to the class it inherits from (`vector<int>`). Inside the box we list any important member variables and methods. Even though `vector<int>` has many methods and variables, we only list the ones most relevant to the example code given above.

## Example: Printable Objects
Consider these three classes: `Point`, `Person`, and `Reading` (for temperature readings):

```cpp
#include "cmpt_error.h"
#include <iostream>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // default constructor
    Point() : x(0), y(0) { }

    // copy constructor
    Point(const Point& other) : x(other.x), y(other.y) { }

    Point(double a, double b) : x(a), y(b) { }

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }

    void println() const {
        print();
        cout << "\n";
    }
}; // class Point


class Person {
    string name;
    int age;
public:
    Person(const string& n, int a)
    : name{n}, age{a}
    {
        if (age < 0) cmpt::error("negative age");
    }

    string get_name() const { return name; }
    int get_age() const { return age; }

    void print() const {
        cout << "Name: '" << name << ", Age: " << age;
    }

    void println() const {
        print();
        cout << "\n";
    }
}; // class Person


class Reading {
private:
    string loc;
    double temp;
public:
    Reading(const string& l, double t)
    : loc{l}, temp{t}
    { }

    string get_loc() const { return loc; }
    double get_temp() const { return temp; }

    void print() const {
        cout << temp << " degrees at " << loc;
    }

    void println() const {
        print();
        cout << "\n";
    }
}; // class Reading

int main() {
    Point a{1, 2};
    a.println();

    Person b{"Katja", 22};
    b.println();

    Reading c{"backyard", 2.4};
    c.println();
}
```

Here is a [[class diagram]] for these classes:

![[pointPersonReadingClassDiagram.svg]]

There are no arrows because none of them inherit from the other. Currently they are three unrelated classes.

Each class has a method called `println` with exactly the same definition:

```cpp
void println() const {
    print();
    cout << "\n";
}
```

Repeated methods is a sign that inheritance might help. Instead of writing the same method in each class, maybe we could inherit it from a base class?

So lets create a new class, called `Printable`, that holds the `println` method:

```cpp
class Printable {
public:

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

}; // class Printable
```

Now we can re-write the classes to inherit from `Printable`. Here's how `Point` would be re-written (we do the same for `Person` and `Reading`):

```cpp
class Point : public Printable {
private:
    double x;
    double y;

public:
    // default constructor
    Point() : x(0), y(0) { }

    // copy constructor
    Point(const Point& other) : x(other.x), y(other.y) { }

    Point(double a, double b) : x(a), y(b) { }

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }

}; // class Point
```

Now `Point` inherits from `Printable` thanks to the line `: public Printable`,  and thus we no longer have to write `println` inside `Point`.

But there's a problem: **this example does not compile!**

The error is in `Printable`: it uses, but does not define, the `print()` method:

```cpp
class Printable {
public:
	void println() const {
		print();      // error : print() is not defined
		cout << "\n";
	}

}; // class Printable
```

While `Point` does define a `print()` method, that's not soon enough for `Printable`. So we need to add a `print()` method to `Printable`.

Unlike `println()`, `print()` will be *different* for every class. What should `print()` do inside `Printable`? There's no way to know unless we are given a specific class.

What we need is a way to tell C++ that `print()` will be implemented by a class that inherits from `Printable`. C++ lets us do that like this:

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

}; // class Printable
```

Look at the `print()` method and notice two things:
- It is declared `virtual`. This means that an inheriting class is allowed to supply its own implementation of `print`. Note that `println` is *not* virtual, and so classes that inherit from `Printable` *cannot* change how `println` works.
- It has no implementation. Instead, we write `= 0`, which means no implementation is provided here (the implementation appears in an inheriting class).

With this, the code ... still doesn't compile! At least, it doesn't compile using the course makefile, which compiles files using the option `-Wnon-virtual-dtor`.

So to fix that, we must add a virtual destructor:

```cpp
class Printable {
public:
    // virtual destructor
    virtual ~Printable() { }

    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

}; // class Printable
```

## Inheritance and Destructors
It's not obvious why a virtual destructor is needed, so lets go through an example that explains the problem. For what follows, we assume that the compilers `-Wnon-virtual-dtor` flag has *not* been used.

Lets add a [[destructor]] to `Point`:

```cpp
class Point : public Printable {
private:
    // ... 

public:
    // ...

    ~Point() {
        print();
        cout << " destroyed\n";
    }

    // ...
}; // class Point
```

This code works as expected:

```cpp
Point a(1, 2);
a.println();
```

It prints:

```
(1, 2)
(1, 2) destroyed
```

This code also works as expected:

```cpp
Point* p = new Point(3, 4);
p->println();   // short for: (*p).println()
delete p;
```

it prints:

```
(3, 4)
(3, 4) destroyed
```

But something different happens here:

```cpp
Printable* p = new Point(3, 4);  // notice the difference!
p->println();
delete p;
```

This time, `p` is of type `Printable*`, not `Point*` --- everything else is the same.

This compiles (with warnings!), and it prints this:

```
(3, 4)
```

Apparently the `Point` [[destructor]] is *not being called*!

That's a big problem --- [[destructor|destructors]] are often vital, e.g. think of the `int_vec` class where the [[destructor]] is responsible for deleting the internal array (thus avoiding a [[memory leak]] and a [[dangling pointer]]).

To see what's happening, lets add a [[destructor]] to `Printable`:

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    ~Printable() {
        cout << "Printable destructor called\n";
    }

}; // class Printable
```

Now run this code again:

```cpp
Printable* p = new Point(3, 4);
p->println();
delete p;
```

It prints this:

```
Printable destructor called
(3, 4)
```

So the `Printable` [[destructor]] is called, but the `Print` [[destructor]] is not. And it is pretty weird that the [[destructor]] for `Printable` is called *before* `p->println()`?! The warning message we ignored from above says the we are doing something that will result in undefined behaviour:

```
warning: deleting object of abstract class type ‘Printable’ which has 
    non-virtual destructor will cause undefined behaviour 
    [-Wdelete-non-virtual-dtor]
      delete p;
```

### Virtual Destructors
The solution to these problems is to add a [[virtual destructor]] to `Printable`:

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
```

Declaring a method `virtual` means that any class that inherits from `Printable` can over-ride the inherited implementation of the method with its own implementation. This works with [[destructor|destructors]] as well. The `virtual` in front of `~Printable` means any class that inherits from `Printable` can, if need be, over-ride the inherited [[destructor]] implementation and provide its own.

With the destructor made virtual, this code now compiles:

```cpp
Printable* p = new Point(3, 4);
p->println();
delete p;
```

And prints this:

```
(3, 4)
(3, 4) destroyed
```

Which is exactly what we want!

In this course, we'll always include `virtual` destructors in a [[base class]] so that derived classes can, if they choose to, supply their own destructors.

To help with this in `g++`, we use the `-Wnon-virtual-dtor` option  so that `g++` will warn us when we've forgotten to make a [[destructor]] virtual.

Here is a [[class diagram]] of our final result:

![[printableClassDiagram.svg]]

And here is the complete version of the code:

```cpp
#include "cmpt_error.h"
#include <iostream>

using namespace std;

class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    // A base class should always provide a virtual destructor. 
    // This gives inheriting classes the option of providing their 
    // own destructor and having it called correctly.
    virtual ~Printable() { }
}; // class Printable

class Point : public Printable {
private:
    double x;
    double y;

public:
    // default constructor
    Point() : x(0), y(0) { }

    // copy constructor
    Point(const Point& other) : x(other.x), y(other.y) { }

    Point(double a, double b) : x(a), y(b) { }

    // getters
    double get_x() const { return x; }
    double get_y() const { return y; }

    void print() const {
        cout << '(' << x << ", " << y << ')';
    }
}; // class Point


class Person : public Printable {
    string name;
    int age;
public:
    Person(const string& n, int a)
    : name(n), age(a)
    {
        if (age < 0) cmpt::error("negative age");
    }

    string get_name() const { return name; }
    int get_age() const { return age; }

    void print() const {
        cout << "Name: '" << name << ", Age: " << age;
    }
}; // class Person


class Reading : public Printable {
private:
    string loc;
    double temp;
public:
    Reading(const string& l, double t)
    : loc(l), temp(t)
    { }

    string get_loc() const { return loc; }
    double get_temp() const { return temp; }

    void print() const {
        cout << temp << " degrees at " << loc;
    }
}; // class Reading

int main() {
    Point a(1, 2);
    a.println();

    Person b("Katja", 22);
    b.println();

    Reading c("backyard", 2.4);
    c.println();
}
```

## Some Terminology
Here is the `Printable` class we have settled on:

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
```

`Printable` is an [[abstract class]] because not all of its methods are implemented, i.e. the `print` method has no body. Also:

- `= 0` indicates a method is [[abstract method|abstract]]; such methods are also known as [[abstract method|pure virtual methods]]
- an [[abstract class]] has one, or more, abstract methods
- an [[abstract class]] can have non-abstract methods (as in `Printable`, i.e. `println` is not abstract)

We call `Printable` a [[base class]], because its purpose is to have other classes derive from it. For example, the `Point` class is said to **derive** from `Printable`:

```cpp
class Point : public Printable {
   // ...
};
```

There are many [[synonyms for inheritance]]. We can say that:
- `Point` is **derived** from `Printable`
- or that `Point` **inherits** from `Printable`
- or that `Point` is a **subclass** of `Printable`
- or that `Point` **extends** `Printable`
- or that `Point` is a **child** of `Printable`

We can also say that `Printable` is a **superclass** of `Point`, or that `Printable` is a **parent** class of `Point`.

### A Note on Multiple Inheritance
C++ allows [[multiple inheritance]], where a class can extend more than one class. This turns out to be more complicated and less common than [[single inheritance]] (when a class inherits from at most one other in class).

In practice, many instances of multiple inheritance can be converted into single inheritance, perhaps using an abstract base class.

So in this course we will only deal with [[single inheritance]], where a class has exactly one parent class.

## The Idea of Binding
Consider a regular function that is not inside any class or struct:

```cpp
// function hello is bound to its body 
// at compile-time
void hello() {  
    cout << "Hello!\n";
}
```

When C++ compiles this function, the name `hello` gets **bound to** (associated with) its function body **at compile-time**.

When you call `hello()`, the compiler knows exactly what code will be executed. A name bound at compile time is an example of [[static binding]].

A [[virtual method]], such as `print` in `Printable` is *not* necessarily bound at compile time. It is possible that, at compile-time, there is no way for the compiler to know exactly which `print()` method to call.

For example:

```cpp
Printable* p;
string s;
cout << "Do you prefer points or people? ";
cin >> s;
if (s == "points") {
    p = new Point(2, 3);
} else {
    p = new Person("Jill", 93);
}

p->print();  // Which print is called? 
             // Point's or Person's?
```

In the final line, the compiler doesn't know which `print` is being called  --- it depends on what the user types when the program runs. It is only at run-time when C++ knows which `print()` to call.

Thus, we say that `print` is [[dynamic binding|dynamically bound]], i.e. `print` is associated with its body at run-time instead of compile-time. [[Dynamic binding]] is a key feature of object-oriented programming.

## Pointers to Objects
Since `Printable` is an [[abstract class]], it's impossible to create a `Printable` object:

```cpp
Printable p; // compiler error: print() not implemented
```

However, *pointers* of type `Printable*` can be created:

```cpp
Printable* p1 = new Point{1, 2};
Printable* p2 = new Person{"Max", 2};
Printable* p3 = new Reading{"Black Rock", 41.5};

p1->println(); // (1, 2)
p2->println(); // Name: 'Max, Age: 2
p3->println(); // 41.5 degrees at Black Rock
```

`p1`, `p2`, and `p3` are all pointers of the same type `Printable*`, but the *objects* they point to are all different types.

Suppose `p` is of type `Pointer*` and points to either a `Point`, `Person`, or `Reading` object (we don't know which). What does `p->print()` print? There's no way to know without knowing the type of the object being pointed to. We can't tell from `p->print()` alone what gets printed.

The fact that all the *pointers* are the same type means we can, for example, put them in a `vector`:

```cpp
vector<Printable*> v = { new Point{1, 2},
                         new Person{"Max", 2},
                         new Reading{"Black Rock", 41.5}
                       };
for(Printable* p : v) {
    p->print();
    cout << "\n";
}

// ...
```

Each time `p->println()` is called, a different version of `print()` is called. This works due to a feature called [[dynamic binding]]: C++ knows that it will be able to figure out at run-time which `print()` implementation to call.

In general, if `p` is of type `Printable*` and pointing to an object, we don't know the exact type of the object `p` is pointing to. All we can be sure of is that we can call methods that are declared in `Printable`, i.e. all objects that `p` could point to are guaranteed to have `print()` and `println()`.

So, if `p` is of type `Printable*`, `p->print()` and `p->println()` are the only methods we can be sure can be called through `p`:

```cpp
Reading* r = new Reading{"Black Rock", 41.5};
r->println();           // okay
cout << r->get_temp()   // okay
     << "\n"; 

Printable* p = r;       // okay
p->println();           // okay
cout << p->get_temp();  // compile-time error:
                        //  p is not guaranteed to
                        //  to point to an object
                        //  that has a get_temp
                        //  method
```

## Designing with Inheritance
[[Interface inheritance]] is a style of inheritance where you only inherit [[abstract method|abstract methods]]. This contrasts with [[implementation inheritance]], where you inherit from classes where some methods have a body.

Sometimes large object-oriented programs organize all classes into a [[class hierarchy]]. A [[class diagram]] is a convenient way to visualize such a hierarchy.

It's not always obvious how, or if, two seemingly related classes should inherit from each other. For example, suppose you have a class called `Circle` that represents circles, and a class called `Ellipse` that represents ellipses.

Should `Circle` inherit from `Ellipse`, or should `Ellipse` inherit from `Circle`?

You might say `Circle` should inherit from `Ellipse` because, mathematically, a circle is an ellipse, i.e. the set of circles is a subset of the set of ellipses. But this can lead to serious problems. If `Ellipse` has methods `set_height(h)` and `set_width(w)`, then you can write code like this:

```cpp
Circle c(10);      // a circle of radius 10
     
c.set_width(5);
c.set_height(15);  // ???: a circle's width and 
                   // height can't be different!
```

A circle can't have a different height and width, and so it is not clear what this code should do. It is inconsistent and confusing!

So maybe `Ellipse` should inherit from `Circle`. This seems reasonable because a `Circle` stores one radius, and an `Ellipse` stores two radii, and so `Ellipse` extends `Circle` by adding one more radius. But this can also lead to serious problems. Consider this function:

```cpp
double area(Circle c) {
    return 3.14 * c.radius() * c.radius();
}
```

Since an  `Ellipse` inherits from `Circle`, we can pass an `Ellipse` to `area`:

```cpp
Ellipse e(5, 10);  // an ellipse 5 wide, 10 high
cout << area(e);   // this can't return the correct 
                   // area!
```

`area` only checks one radius, but to correctly calculate the area of an `Ellipse` you need two radii.

So it seems that `Circle` and `Ellipse` have no good way to be related by inheritance at all! Both directions of doing the inheritance can lead to serious problems. [[Interface inheritance]] does not have this particular problem, and so in practice [[interface inheritance]] is usually preferable.

In discussions of object-oriented design, inheritance is often a contentious point. Some people say it's a key feature of object-oriented programming, and classes should be organized into hierarchies based on inheritance. Others say that [[interface inheritance]] is okay, it's useful and easy to understand. But [[implementation inheritance]] is not so good: it's usually more confusing and less flexible. 

[The Liskov substitution principle](https://en.wikipedia.org/wiki/Liskov_substitution_principle) can help you decide if a class should inherit from another. It says this:

> if class B inherits from class A, then objects of type A in a program may be replaced with objects of type B without altering any of the desirable properties of that program

It's wise to keep this principle in mind any time you use inheritance. Violating it can result in serious design problems, like those we saw above with `Circle` and `Ellipse`.

## C++ and OOP
C++ was the first popular mainstream language to support OOP. While earlier languages pioneered it, notably [Simula 67](https://en.wikipedia.org/wiki/Simula) and [SmallTalk](https://en.wikipedia.org/wiki/Smalltalk), they haven't had the widespread influence of C++. Most modern programming languages support OOP in some form, although usually with some different rules. For example:
- [The Java language](https://en.wikipedia.org/wiki/Java_(programming_language)) renames `->` to `.` and directly supports [[interface inheritance]] with is `interface` construct. 
- [The Ruby language](https://en.wikipedia.org/wiki/Ruby_(programming_language)) allows you to add methods to existing classes.
- [The Go language](https://en.wikipedia.org/wiki/Go_(programming_language)) only has [[interface inheritance]], and methods are not defined inside classes.

## Practice Questions
1. Add a `sort_decreasing()` method to `int_vec` that sorts all the elements of an `int_vec` into order from largest to smallest.
2. Add a default method to `int_vec` that initializes the name to `"<no name>"`.
3. In your own words, explain what inheritance is and how it works in C++.
4. In your own words, explain what [[public inheritance]] means in C++. What other kinds of inheritance are there in C++?
5. Suppose class `B` inherits from class `A`, and function `f` takes one object of class `A` as input. Will `f` always work if it's passed an object of class `B`? Justify your answer.
6. Suppose class `B` inherits from class `A`, and function `f` takes one object of class `B` as input. Will `f` always work if it's passed an object of class `A`? Justify your answer.
7. In your own words, describe what it means for a method to be [[virtual method|virtual]]. How does it differ from a non-virtual method?
8. What does  it mean when a method ends with `= 0`? When is such a method useful?
9. Why should destructors always be declared virtual in C++?
10. How can you tell if a class is abstract?
11. Is every base class also an abstract class?
12. In your own words, explain the difference between [[single inheritance]] and [[multiple inheritance]].
13. In your own words, describe the difference between [[static binding]] and [[dynamic binding]].
14. In your own words, describe the difference between [[implementation inheritance]] and [[interface inheritance]].
