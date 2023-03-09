// fib.cpp

#include <iostream>
#include <vector>

using namespace std;

// Returns the nth Fibonacci number (assuming n > 0). Uses recursion.
// Simple, but sloooooow because of all the repeated calls to fib.
long fib(long n)
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
long fib2(long n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        long a = 1;
        long b = 1;
        long c = 0;
        for (long i = 2; i < n; ++i)
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
    for (int n = 1; n <= 50; ++n)
    {
        // flush makes the output appear immediately
        cout << "non-recursive f(" << n << ") = " << flush 
             << fib2(n) << "\n";          
        cout << "    recursive f(" << n << ") = " << flush
             << fib(n) << "\n";
    }
}
