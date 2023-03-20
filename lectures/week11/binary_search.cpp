// binary_search.cpp

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Pre-condition:
//   v[begin] to v[end - 1] is in ascending sorted order
// Post-condition:
//   returns an index i such that v[i] == x and
//   begin <= i < end;
//   if x is not found, -1 is returned
int binary_search_loop(int x, const vector<int> &v,
                       int begin, int end)
{
    while (begin < end)
    {
        int mid = (begin + end) / 2;
        if (v[mid] == x)
        { // found x!
            return mid;
        }
        else if (x < v[mid])
        {
            end = mid;
        }
        else // x > v[mid]
        {
            begin = mid + 1;
        }
    }
    return -1; // x not found
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x; if x is
//    not in v, -1 is returned
int binary_search_loop(int x, const vector<int> &v)
{
    return binary_search_loop(x, v, 0, v.size());
}

void test_binary_search_loop()
{
    cout << "calling test_binary_search_loop() ...\n";
    vector<int> v;
    assert(binary_search_loop(0, v) == -1);

    v = {1};
    assert(binary_search_loop(0, v) == -1);
    assert(binary_search_loop(1, v) == 0);
    assert(binary_search_loop(2, v) == -1);

    v = {1, 3};
    assert(binary_search_loop(0, v) == -1);
    assert(binary_search_loop(1, v) == 0);
    assert(binary_search_loop(2, v) == -1);
    assert(binary_search_loop(3, v) == 1);
    assert(binary_search_loop(4, v) == -1);

    v = {1, 3, 5};
    assert(binary_search_loop(0, v) == -1);
    assert(binary_search_loop(1, v) == 0);
    assert(binary_search_loop(2, v) == -1);
    assert(binary_search_loop(3, v) == 1);
    assert(binary_search_loop(4, v) == -1);
    assert(binary_search_loop(5, v) == 2);

    cout << "... test_binary_search_loop() done: all tests passed\n";
}

int binary_search_rec(int x, const vector<int> &v,
                      int begin, int end)
{
    int n = end - begin;

    // if the sub-vector being searched is empty,
    // then x is not in it
    if (n <= 0)
        return -1; // x not found

    int mid = (begin + end) / 2;
    if (x == v[mid])
    {
        return mid;
    }
    else if (x < v[mid])
    {
        return binary_search_rec(x, v, begin, mid);
    }
    else
    {
        return binary_search_rec(x, v, mid + 1, end);
    }
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x;
//    if x is not in v, -1 is returned
int binary_search_rec(int x, const vector<int> &v)
{
    return binary_search_rec(x, v, 0, v.size());
}

void test_binary_search_rec()
{
    cout << "calling test_binary_search_rec() ...\n";
    vector<int> v = {};
    assert(binary_search_rec(0, v) == -1);

    v = {1};
    assert(binary_search_rec(0, v) == -1);
    assert(binary_search_rec(1, v) == 0);
    assert(binary_search_rec(2, v) == -1);

    v = {1, 3};
    assert(binary_search_rec(0, v) == -1);
    assert(binary_search_rec(1, v) == 0);
    assert(binary_search_rec(2, v) == -1);
    assert(binary_search_rec(3, v) == 1);
    assert(binary_search_rec(4, v) == -1);

    v = {1, 3, 5};
    assert(binary_search_rec(0, v) == -1);
    assert(binary_search_rec(1, v) == 0);
    assert(binary_search_rec(2, v) == -1);
    assert(binary_search_rec(3, v) == 1);
    assert(binary_search_rec(4, v) == -1);
    assert(binary_search_rec(5, v) == 2);

    cout << "... test_binary_search_rec() done: all tests passed\n";
}

int main()
{
    test_binary_search_loop();
    test_binary_search_rec();
}
