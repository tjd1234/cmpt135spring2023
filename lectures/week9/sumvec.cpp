// sumvec.cpp

#include <iostream>
#include <vector>

using namespace std;

//
// Recursion on vectors
//

// returns the sum of v[begin], v[begin+1], ... , v[n - 1]
// n is the size of v
int sum(const vector<int> &v, int begin)
{
    if (begin == v.size())
    {
        return 0;
    }
    else
    {
        return v[begin] + sum(v, begin + 1);
    }
}

// returns the sum of v[0], v[1], ... , v[n - 1]
// n is the size of v
int sum(const vector<int> &v)
{
    return sum(v, 0);
}

int main()
{
    vector<int> v = {2, 1, 6, 4, 3};
    cout << "sum(v) = " << sum(v) << "\n";
}
