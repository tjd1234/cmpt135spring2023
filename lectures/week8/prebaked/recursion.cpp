// recursion.cpp

#include <iostream>

using namespace std;

//
// When compiled with the standard course makefile, calling a() result in a
// crash.
//
// If -O2 is added as a compiler flag, then g++ optimizes the recursion into a
// loop, and the program runs forever without crashing.
//
void a()
{
    cout << "hello!\n";
    a();
}

// This is like function a, but now we pass in a parameter to count how many
// times b is called.
void b(int n)
{
    cout << n << ": hello!\n";
    b(n + 1); // n + 1 here, not n
}

// This is like b, but now we have a "base case" to stop the recursion.
void c(int n)
{
    if (n >= 10) // base case
    {
        // all done: do nothing
    }
    else // recursive case
    {
        cout << n << ": hello!\n";
        c(n + 1);
    }
}

// This is like function c, but now we can pass in n, the number of times we
// want d to print "hello!".
void d(int n)
{
    if (n <= 0)
    { // n is decreasing, so check if it's 0 or lower
      // all done: do nothing
    }
    else
    {
        cout << n << ": hello!\n";
        d(n - 1); // subtract 1 instead of add 1
    }
}

// This function is a variation of d: the if-statement is re-written to avoid
// the do-nothing case.
void say_hello(int n)
{
    if (n > 0)
    {
        cout << n << ": hello!\n";
        say_hello(n - 1);
    }
}

// A more general version of say_hello: we can pass in any string.
void say(const string &msg, int n)
{
    if (n > 0)
    {
        cout << n << ": " << msg << "\n";
        say(msg, n - 1);
    }
}

// prints the numbers from n down to 1
void count_down(int n)
{
    if (n > 0)
    {
        cout << n << "\n";
        count_down(n - 1); // recursive call comes after printing
    }
}

// prints the numbers from 1 up to n
void count_up(int n)
{
    if (n > 0)
    {
        count_up(n - 1); // recursive calls comes before printing
        cout << n << "\n";
    }
}

// returns 1 + 2 + ... + n (assuming n >= 0)
int S(int n)
{
    if (n == 0) // base case
    {
        return 0;
    }
    else // recursive case
    {
        return n + S(n - 1);
    }
}

// Returns the nth Fibonacci number (assuming n > 0). Uses recursion.
// Simple, but sloooooow.
int fib(int n)
{
    if (n == 1) // base case
    {
        return 1;
    }
    else if (n == 2) // base case
    {
        return 1;
    }
    else // recursive case
    {
        return fib(n - 1) + fib(n - 2);
    }
}

// Returns the nth Fibonacci number (assuming n > 0). Doesn't use recursion.
// Much faster, but more complicated.
int fib2(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        int a = 1;
        int b = 1;
        int c = 0;
        for (int i = 2; i < n; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main()
{
    // a();
    b(1);
    // c(0);
    // d(10);
    // say("hiya!", 10);

    // count_down(10);
    // count_up(10);
}
