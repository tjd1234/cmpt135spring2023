// stack.cpp

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
    vector<T> v;

public:
    Stack() // default constructor
        : v()
    {
    }

    Stack(const Stack<T> &other) // copy constructor
        : v(other.v)
    {
    }

    bool is_empty() const { return v.size() == 0; }

    // put a copy of x on top of the stack
    void push(const T &x)
    {
        v.push_back(x);
    }

    // return a constant reference to the top element
    // - reference means it is not copied (so it's efficient)
    // - constant means it cannot be modified (so it's safe)
    const T& peek() const
    {
        assert(!is_empty());
        return v.back();
    }

    // remove and return the top element
    T pop()
    {
        T top = peek();
        v.pop_back();
        return top;
    }

    void print() const
    {
        if (is_empty())
        {
            cout << "empty stack";
        }
        else
        {
            for (const T &x : v)
                cout << x << " ";
        }
    }

    void println()
    {
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
template <typename T>
void print(Stack<T> s)
{
    if (s.is_empty())
    {
        cout << "empty stack";
    }
    else
    {
        while (!s.is_empty())
        {
            T val = s.pop();
            cout << val << " ";
        }
    }
}

template <typename T>
void println(const Stack<T> &s)
{
    print(s);
    cout << "\n";
}

int main()
{
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
