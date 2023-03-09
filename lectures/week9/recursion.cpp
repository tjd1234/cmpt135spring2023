// recursion.cpp

#include <iostream>

using namespace std;

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

void f(int n) {
    if (n <= 0) return;
    a(n-1);
    a(n-1);
    cout << n << ": Hello!\n";
}

int main()
{
    say("dog", 3);
}
