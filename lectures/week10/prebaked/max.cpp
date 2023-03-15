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

//
// total_count is a global variable to count how many times mi = i is executed;
// usually we want to avoid global variables, but in this case it's convenient
//
int total_count = 0;

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

    cout << "# times mi = i called: " << mi_assign_i_count << "\n";
    total_count += mi_assign_i_count;
    return mi;
}

void rand_vec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand(); // rand() returns a random int
    }                  // from 0 to RAND_MAX
}

void max_count_test(int n)
{
    srand(time(NULL)); // seed the random number generator
    total_count = 0;   // reset the total count
    vector<int> v(n);
    cout << "n = " << n << "\n";
    for (int i = 0; i < 10; i++)
    {
        rand_vec(v);
        index_of_max_count(v);
    }
    cout << "\naverage count = " << total_count / 10 << "\n";
}

int main(int argc, char *argv[])
{
    // test_max();
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " n\n";
        return 1;
    }

    max_count_test(stoi(argv[1]));
}
