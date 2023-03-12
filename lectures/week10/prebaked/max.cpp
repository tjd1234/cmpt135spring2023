// max.cpp

#include "cmpt_error.h"
#include <cassert>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <iostream>
#include <vector>

using namespace std;

//
// Iterative (loop-based) max
//

// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns an index value mi such that 0 <= mi < v.size()
//    and v[mi] >= v[i] for 0 <= i < v.size().
int index_of_max(const vector<int> &v)
{
    if (v.empty())
        cmpt::error("empty vector");

    int mi = 0;
    // note i starts at 1
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[mi])
        {
            mi = i;
        }
    }
    return mi;
}

// Returns the maximum value in v.
int max_for(const vector<int> &v)
{
    return v[index_of_max(v)];
}

//
// While-based max
//

// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns an index value mi such that 0 <= mi < v.size()
//    and v[mi] >= v[i] for 0 <= i < v.size().
int index_of_max_while(const vector<int> &v)
{
    if (v.empty())
        cmpt::error("empty vector");

    int mi = 0;
    int i = 1;
    while (i < v.size())
    {
        if (v[i] > v[mi])
        {
            mi = i;
        }
        i++;
    }
    return mi;
}

int max_while(const vector<int> &v)
{
    return v[index_of_max_while(v)];
}

//
// Recursive max
//

// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns an index value mi such that begin <= mi < v.size()
//    and v[mi] >= v[i] for begin <= i < v.size().
int index_of_max_rec(const vector<int> &v, int begin)
{
    if (begin >= v.size())
        cmpt::error("empty vector");

    if (begin == v.size() - 1)
    { // only 1 element, so return it
        return begin;
    }
    else
    {
        int mi = index_of_max_rec(v, begin + 1); // recursive call
        if (v[mi] > v[begin])
        {
            return mi;
        }
        else
        {
            return begin;
        }
    }
}

// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns an index value mi such that 0 <= mi < v.size()
//    and v[mi] >= v[i] for 0 <= i < v.size().
int index_of_max_rec(const vector<int> &v)
{
    return index_of_max_rec(v, 0);
}

// Returns the maximum value in v.
int max_rec(const vector<int> &v)
{
    return v[index_of_max_rec(v)];
}

//
// Test code
//
void test_max()
{
    cout << "test_max() called ...\n";
    vector<int> v = {10};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {1, 10};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {10, 1};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {10, 10};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {9, 10, -1};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {10, 9, -1, 0, 10};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    v = {2, 1, 3, 10, 5, 8, 2};
    assert(max_for(v) == 10);
    assert(max_while(v) == 10);
    assert(max_rec(v) == 10);

    cout << "... test_max() done: all tests passed\n";
}

//
// Code for counting mi = i
//

// prints how times mi = i is executed
int index_of_max_count(const vector<int> &v)
{
    if (v.empty())
        cmpt::error("empty vector");

    int mi = 0;
    int i = 1;
    int mi_assign_i_count = 0;
    while (i < v.size())
    {
        if (v[i] > v[mi])
        {
            mi = i;
            mi_assign_i_count++;
        }
        i++;
    }
    cout << "mi_assign_i_count = " << mi_assign_i_count << "\n";
    return mi;
}

// returns a vector of n random ints
vector<int> rand_vec(int n)
{
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = rand(); // rand() returns a random int
    }                       // from 0 to RAND_MAX
    return result;
}

void max_count_test()
{
    srand(time(NULL)); // seed the random number generator
    const int n = 10;
    cout << "n = " << n << "\n";
    for (int i = 0; i < n; i++)
    {
        vector<int> v = rand_vec(n);
        index_of_max_count(v);
    }
}

int main()
{
    test_max();
    // max_count_test();
}
