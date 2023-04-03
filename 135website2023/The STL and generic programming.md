**STL** is short for **standard template library**. The STL is C++'s standard collection of general-purpose classes and functions that implement many basic algorithms and data structures.

Two of the main goals of the STL are *efficiency* and *generality*. All the STL algorithms are implemented as efficiently as possible, and they are well-tested and generally bug-free. They are also implemented in a very general way, so that they typically work with any data structure (i.e. arrays, vectors, strings, lists, files, etc.) that it makes sense for them to work on. Making a library of algorithms that is both efficient and general-purpose is non-trivial: most other languages settle for one or the other.

In this note, we will look at some basic STL algorithms: `find`, `sort`, and `reverse`. We will also introduce **type parameters** and **generic programming**, two ideas the STL uses extensively.


## Linear Search: find
`find` is the STL's version of [[linear search]]. The basic version of `find` has this header:

```cpp
template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
```

Lets look at each part:

- `template<class InputIt, class T>` indicates that `InputIt` and `T` are **type variables**. `T` is a variable representing the type of the value we are looking for, and it can be any type that works with `operator==`.

  `InputIt` is a type variable representing an [[iterators|iterator]] is an object that "points" to another object. 

- `constexpr InputIt` is the type of the value that `find` returns. `constexpr` means that `find` can be called at compile-time inside of a [[constant expression]]. We're not covering `const` expressions in this course, but they let you do computations at compile-time, which can greatly speed up some programs.

  `find` returns an `InputIt`, i.e. `find` returns an [[iterators|iterator]]. An [[iterators|iterator]] points to a another value, and so  the returned [[iterators|iterator]] points to the value. If the value was *not* found, then the returned [[iterators|iterator]] is equal to `last` (i.e. 1 past the last value in the range being searched).

- `find(InputIt first, InputIt last, const T& value)` means that `find`
  takes two [[iterators]], `first` and `last`, and a value to search for called `value`. `first` points to the first element of the range being searched, and `last` points to *one past* the end element of the same range. This asymmetry between `first` and `last` is important: if `find` returns `last`, then that means `value` was not found.

The documentation for C++ gives a suggested implementation of `find`:

```cpp
template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}
```

This is a standard pointer-oriented implementation of linear search. Notice
that `*first` is used when comparing against `value`. `first` is an [[iterators|iterator]], and so `*first` is the value that `first` points to. This is, intentionally, the same way that regular pointers work, and so it's often useful to think of [[iterators]] as pointers.

`find` is very general, and works efficiently with pretty much every type of container where it makes sense to use [[linear search]].

Here are some examples of using `find`:

```cpp
void test1() {
    vector<string> food = {"kale", "lettuce", "onion", 
	                       "carrot", "potato", "tomato"};
    if (find(begin(food), end(food), "carrot") == end(food)) {
        cout << "carrot NOT found\n";
    } else {
        cout << "carrot found\n";
    }

    if (find(begin(food), end(food), "squash") == end(food)) {
        cout << "squash NOT found\n";
    } else {
        cout << "squash found\n";
    }

    double costs[] = {2.00, 3.25, 0.99, 7.40, 2.99};
    if (find(begin(costs), end(costs), 2.99) == end(costs)) {
        cout << "2.99 NOT found\n";
    } else {
        cout << "2.99 found\n";
    }

    if (find(begin(costs), end(costs), 3.99) == end(costs)) {
        cout << "3.99 NOT found\n";
    } else {
        cout << "3.99 found\n";
    }

    string quote = "No matter where you go, there you are.";
    if (find(begin(quote), end(quote), 'e') == end(quote)) {
        cout << "'e' NOT found\n";
    } else {
        cout << "'e' found\n";
    }

    if (find(begin(quote), end(quote), 'q') == end(quote)) {
        cout << "'q' NOT found\n";
    } else {
        cout << "'q' found\n";
    }
}
```

## Generalizing test1 with Templates
`test1()` has a lot of repeated code which makes it hard to read. So here we create a helper function called `test_find` that simplifies things quite a bit. `test_find` is a [[generic function]], or [[generic function|templated function]] because it uses two type variables, `InputIt` and `T`.

The type variables let `test_find` work with *any* data that we can pass to
`find`. This kind of generality is one of the major advantages of the STL, and well-used it can result in code that is both efficient and highly re-usable.

```cpp
template<class InputIt, class T>
void test_find(InputIt first, InputIt last, const T& value) {
    if (find(first, last, value) == last) {
        cout << value << " NOT found\n";
    } else {
        cout << value << " found\n";
    }
}

void test2() {
    vector<string> food = {"kale", "lettuce", "onion", 
	                       "carrot", "potato", "tomato"};
    test_find(begin(food), end(food), "carrot");
    test_find(begin(food), end(food), "squash");
     
    double costs[] = {2.00, 3.25, 0.99, 7.40, 2.99};
    test_find(begin(costs), end(costs), 2.99);
    test_find(begin(costs), end(costs), 3.99);

    string quote = "No matter where you go, there you are.";
    test_find(begin(quote), end(quote), 'e');
    test_find(begin(quote), end(quote), 'q');
}
```

Notice how much simpler and easier to read `test2()` is thanks to `test_find`. Plus the body of `test_find` itself is short and easy to understand.

## Sorting and Reversing
Sorting is one of the most common algorithms in all of programming, and so the STL provides an efficient sorting function called `std::sort`.

`std::sort` is typically implemented using a fast general-purpose sort, such as variations of [[mergesort]] or [[quicksort]]. The C++ documentation doesn't specify exactly how `std:sort` is implemented, it just says it must do no more than $O(n \log n)$ comparisons in the worst case.

The `reverse` function  reverses the elements in a given range. Calling `sort` followed by `reverse` is a common way of putting a range into reverse sorted order.

Here is some sample code:

```cpp
void test3() {
    vector<string> food = {"kale", "lettuce", "onion", 
	                       "carrot", "potato", "tomato"};
    sort(begin(food), end(food));
    for(string s : food) cout << s << " ";
    cout << "\n";
    reverse(begin(food), end(food));
    for(string s : food) cout << s << " ";
    cout << "\n";

    double costs[] = {2.00, 3.25, 0.99, 7.40, 2.99};
    sort(begin(costs), end(costs));
    for(double c : costs) cout << c << " ";
    cout << "\n";
    reverse(begin(costs), end(costs));
    for(double c : costs) cout << c << " ";
    cout << "\n";

    string quote = "No matter where you go, there you are.";
    sort(begin(quote), end(quote));
    cout << quote << "\n";
    reverse(begin(quote), end(quote));
    cout << quote << "\n";
}
```

## Generalizing test3
As we did with `test_find`, lets write a generic `test_sort` function to simplify `test3`. 

Since `test_sort` is only passed [[iterators]] to the first and last items in
the range, we can't print the values in the same way as in `test3`.

So we write `println`, a generic function that prints all the values in the
range specified by the `first` and `last` [[iterators]]. The syntax is almost
the same as what we would write if we were using regular pointers: `p` points to each element in the range in succession, and `*p` is the value that `p` points to:

```cpp
template<class InputIt>
void println(InputIt first, InputIt last) {
    for(InputIt p = first; p != last; p++) {
        cout << *p << " ";
    }
    cout << "\n";
}

template<class InputIt>
void test_sort(InputIt first, InputIt last) {
    sort(first, last);
    println(first, last);
    reverse(first, last);
    println(first, last);
}
```

Unlike `test_find`, `test_sort` has only one type variable, `InputIt`, because it does *not* need a value to search for.

Here is `test4`:

```cpp
void test4() {
    vector<string> food = {"kale", "lettuce", "onion", 
	                       "carrot", "potato", "tomato"};
    test_sort(begin(food), end(food));

    double costs[] = {2.00, 3.25, 0.99, 7.40, 2.99};
    test_sort(begin(costs), end(costs));

    string quote = "No matter where you go, there you are.";
    test_sort(begin(quote), end(quote));
}
```

Again, notice how simple and general-purpose the resulting code is. `test4()` is much easier to read than `test3()`. The essential structure of `test_sort` is quite readable, and works with any type of range that `std::sort` can sort.

See [stl_demo.cpp](https://csil-git1.cs.surrey.sfu.ca/cmpt135/cmpt135_fall2020/cmpt-135-notes/-/tree/master/stl_demonstration) for all the sample source code used in this note.

### Example: Sorting with Different Comparison Functions
The follow code demonstrates how `sort` can be used to sort records by different fields. This is quite useful in practice.

```cpp
// sort_example.cpp

#include "cmpt_error.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    string first_name;
    string last_name;
    int age;
};  

ostream& operator<<(ostream& os, const Person& p) {
    os << "{" << p.first_name << ", " 
              << p.last_name << ", " 
              << p.age
       << "}";
    return os;
}

// Person record could be sorted by first_name, last_name, or age. We make one
// sorting comparison function for each possibility.

bool by_first_name(const Person& a, const Person& b) { 
    return a.first_name <= b.first_name; 
}

bool by_last_name(const Person& a, const Person& b) { 
    return a.last_name <= b.last_name; 
}

bool by_age(const Person& a, const Person& b) { 
    return a.age <= b.age; 
}

// This comparison function is used to sort Person objects first by last name,
// and then by first name.
bool by_last_then_first(const Person& a, const Person& b) {
    if (a.last_name == b.last_name) {
        return by_first_name(a, b);
    } else {
        return by_last_name(a, b);
    }
}

int main() {
    vector<Person> data = {
        {"Sue",     "Zee",      32},
        {"Richard", "Pressman", 40},
        {"Raine",   "Storm",    32},
        {"Carl",    "Storm",    32},
        {"Mimi",    "Yuyu",     44},
        {"Max",     "Power",    40},
        {"Sue",     "Storm",    30}
    };

    cout << "By first_name:\n";
    sort(begin(data), end(data), by_first_name);
    for(const Person& p : data) cout << p << "\n";
    cout << "\n";

    cout << "By first_name, reverse alphabetical:\n";
    sort(begin(data), end(data), by_first_name);
    reverse(begin(data), end(data));
    for(const Person& p : data) cout << p << "\n";
    cout << "\n";

    cout << "By last_name:\n";
    sort(begin(data), end(data), by_last_name);
    for(const Person& p : data) cout << p << "\n";
    cout << "\n";

    cout << "By age, lowest to highest:\n";
    sort(begin(data), end(data), by_age);
    for(const Person& p : data) cout << p << "\n";
    cout << "\n"; 

    cout << "By age, highest to lowest:\n";
    sort(begin(data), end(data), by_age);
    reverse(begin(data), end(data));
    for(const Person& p : data) cout << p << "\n";
    cout << "\n";

    cout << "By last name, then first name:\n";
    sort(begin(data), end(data), by_last_then_first);
    for(const Person& p : data) cout << p << "\n";

} // main

```

## Practice Problems
1. What does STL stand for?
2. What are two of the main design goals of the STL?
3. What is a generic function? How does it differ from a regular function?
4. What are iterators? How do they relate to pointers?
5. In your own words, explain how the standard `find` function works. What does it return if it can't find the value it's looking for?
6. Rewrite the implementation of `find` given in the notes using a while-loop in place of the for-loop.
7. Implement your own function called `reverse_sort` that efficiently sorts any sequence in reverse sorted order. Use the STL `sort` and `reverse` functions.
8. Suppose you have a function called `iter_swap(p, q)` that takes two iterators, `p` and `q`, as input and exchanges the values they point to. Use that function to help implement your own version of the general STL `reverse` function. 