// recursion.cpp

#include <iostream>

using namespace std;

// Question 1
//
// Without using any loops, write a function that prints
// "Hello!" forever.

// n is the number of times hello! is printed
void a(int n) {
    if (n <= 0) return;
    a(n-1);
    a(n-1);
    cout << n << ": Hello!\n";
}

// say("apple", 5)
void say(const string& s, int n) {
    if (n <= 0) return;
    cout << s << "\n";
    say(s, n-1);
}

int main()
{
    a(7);
}










// Question 2
//
// Without using any loops, write a function that prints
// "Hello!" forever, and each hello starts with its count:
//
// 1: Hello!
// 2: Hello!
// 3: Hello!
// ...


// Question 3
//
// Without using any loops, write a function that prints "hello!" at most 10
// times. Use a passed-in int parameter to keep track of how many times it is
// called.

// Question 4
//
// Without using any loops, write a function that prints "hello!" n times. Pass in
// n as a parameter.

// Question 5
//
// Without using any loops, write a function say(s, n) that prints the string s
// n times. 

