[[generic function|Template Functions]], also known as [[generic function|generic functions]], are C++ functions where one, or more, of the input or output values have an unspecified type.

## A Generic Swap Function
Here are two implementations of a function for swapping variable values:

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

```

The only difference between them is that the first uses the type `int`, and the second uses the type `string`. Using a templates, we can write a single swap function that works with both `int`s and `string`s:

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

The line `template<typename T>` indicates that the function that follows uses `T` to stand for some type. In this particular example, `T` can be any type that works with `opedrator=`, i.e. the assignment operator is used in the body of the function.

> **Note** You can usually write `template<class T>` instead of `template<typename T>`. 

While we don't know exactly what type `T` is, we do know that `a`, `b`, and `temp` are all of the same type . C++ checks at compile-time that these variables all have the same type.

The exact value of `T` is determined by the compiler at the point `swap` is called. For example:

```cpp
int x = 4;
int y = 7;
swap(x, y);          // line 1

string s = "cow";
string t = "rabbit";
swap(s, t);         // line 2
```

In line 1, `x` and `y` are both of type `int`, and so when the compiler sees the statement `swap(x, y)`, the variable `T` in the definition of `swap` is assigned the value `int`. Similarly, in line 2, `s` and `t` are both of type `string`, and so when the compiler  sees `swap(s, t)` it knows to assign `string` to `T` in the swap function.

Note that `swap(x, t)` would *not* compile. The compiler would catch that error because `x` and `t` are of different types, and `swap` requires that they both be of the same type.

## A Generic Min Function
Here is a template function that returns the smaller of two values:

```cpp
template <typename T>
T min_of(const T& a, const T& b) 
{
    if (a < b) return a;
    return b;
}
```

Notice that the return type is `T`, as well as the input variables `a` and `b`. `T` is any type that has both a copy constructor and `operator<`. So it works with numbers and strings, and any programmer-defined class that has a copy constructor and `operator<`.

Here is a templated function that returns the min value of a vector of a type `T`:

```cpp
template<typename T>
T min_of(const vector<T>& v) {
    assert(v.size() > 0);
    T min = v[0];
    for(int i = 1; i < v.size(); i++) {
        min = min_of(min, v[i]);
    }
    return min;
}
```

The input variable `v` is of type `vector<T>`, i.e. it's a vector of values of type `T`. From looking at the code in the body of `min_of`, we see that `T` must have `operator=`,  `operator<` (because it calls `min_of(a, b)`), and a copy constructor (because it returns a copy of the min).

The exact value of the type `T` isn't known until `min_of` is called. For example:

```cpp
cout << min_of(nums) // -5
     << "\n";

vector<string> words = {"up", "down", "all", "around"};
cout << min_of(nums) // "all"
     << "\n";

vector<vector<int>> vv = {
    {4}, {1, 2, 3}, {5, 6}, {2}};

cout << vv // {{4}, {1, 2, 3}, {5, 6}, {2}}
     << "\n";
cout << min_of(vv) // {1, 2, 3}
     << "\n";
```

When `min_of(nums)` is called, the `T` in `min_of(const vector<T>& v)` is set to `double` because that's the type of the values in `nums`. The `T` in `min_of(const T& a, const T& b)` also has it's `T` set to `double`. The compiler automatically infers the value for `T` and checks that it supports all the necessary operations on it.

Notice that `vv` is a vector of vector. C++ defines a standard `operator<` and `operator=` for vectors, and so we can call `min_of` on a `vector<vector<int>>`.

Finally, for the above code to work we also need to define `operator<<`:

```cpp
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "{";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i < v.size() - 1)
            os << ", ";
    }
    os << "}";
    return os;
}
```

## Class Templates
A common use of templates is to implement **generic containers**. For example, `vector<T>` is a generic container, and all the methods in it work with almost any type `T`. C++ provides many pre-made generic containers, and you can also write your own. For example, here is an implementation of a generic stack:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
class Stack {
    vector<T> v;
public:
    Stack() // default constructor
    : v() 
    { }

    Stack(const Stack<T>& other) // copy constructor
    : v(other.v)
    { }

    bool is_empty() const { return v.size() == 0; }

	// put a copy of x on top of the stack
    void push(const T& x) {
        v.push_back(x);
    }

    // return a constant reference to the top element
    // - reference means it is not copied (so it's efficient)
    // - constant means it cannot be modified (so it's safe)
    const T& peek() const {
        assert(!is_empty());
        return v.back();
    }

    // remove and return the top element
    T pop() {
        T top = peek();
        v.pop_back();
        return top;
    }

    void print() const {
        if (is_empty()) {
            cout << "empty stack";
        } else {
            for(const T& x : v) cout << x << " ";
        }
    }

    void println() {
        print();
        cout << "\n";
    }

}; // class Stack

// This print function is inefficient because it makes a copy of the
// passed-in stack. If the header were instead 
// print(const Stack<T>& s), then the function wouldn't compile 
// because s.pop() modifies s.
//
// The print method in Stack<T> is more efficient because it doesn't 
// need to make a copy of the stack.
template<typename T>
void print(Stack<T> s) {
    if (s.is_empty()) {
        cout << "empty stack";
    } else {
        while (!s.is_empty()) {
            T val = s.pop();
            cout << val << " ";
        }
    }
}

template<typename T>
void println(const Stack<T>& s) {
    print(s);
    cout << "\n";
}

int main() {
  Stack<int> a;
  a.println();
  a.push(5);
  a.push(18);
  a.push(-3);
  a.println();

  Stack<string> b;
  b.println();
  b.push("cat");
  b.push("dog");
  b.push("mouse");
  b.push("parrot");
  b.println();
} // main
```

## Advanced C++ Templates
We've only scratched the surface of templates: they are one of the most-used features of modern C++ libraries. The C++ standard library uses templates throughout, and a number of changes to the base C++ language have been made over the years to better support programming with templates.

While *using* templates is often easy, *implementing* template code requires a lot of care. Writing general-purpose code that works with *any* type of data that makes sense requires good knowledge of the exact rules of C++.

## Practice Questions
1. Here is another way to swap two `int`s:

   ```cpp
   void swap2(int& a, int& b) {
      a = a - b;
      b = a + b;
      a = b - a;
   }
   ```
   
   Convert this into a templated function like `swap` in the notes. Why is this version *not* as general as the one in the notes?
 
2. Implement a templated version of `max_of(a, b)` that returns the bigger of `a` and `b`, and also `max_of(v)` that returns the biggest element in `v` (which has type `vector<T>`).
3. Write a function called `identity(x)` that just returns a copy of `x`. Can you write this function *without* using templates?
4. Using the `Stack` class as defined above, explain why you **can't** create a `Stack<Stack<int>>`. How would you modify `Stack` so that you could create a `Stack<Stack<int>>`?