// min.cpp

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T min_of(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T min_of(const vector<T> &v)
{
    assert(v.size() > 0);
    T min = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        min = min_of(min, v[i]);
    }
    return min;
}

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

void min_of_demo()
{
    vector<double> nums = {1.6, 9.22, -4.2, -5};
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
}

int main()
{
    min_of_demo();
}
