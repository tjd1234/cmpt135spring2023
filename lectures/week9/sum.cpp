// sum.cpp

#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    cout << S(5000) << "\n";
}
