// linear_search.cpp

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Pre-condition:
//    none
// Post-condition:
//    Returns the smallest i >= 0 such that v[i] == x; or, if
//    x is not anywhere in v, then -1 is returned
int linear_search1(const vector<int> &v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (x == v[i])
            return i;
    }
    return -1;
}

// test linear_search1 using asserts
void test_linear_search1()
{
    cout << "Calling test_linear_search1 ...\n";
    vector<int> v = {5, 2, 1, 3, 4};
    assert(linear_search1(v, 1) == 2);
    assert(linear_search1(v, 2) == 1);
    assert(linear_search1(v, 3) == 3);
    assert(linear_search1(v, 4) == 4);
    assert(linear_search1(v, 5) == 0);
    assert(linear_search1(v, 6) == -1);

    v = {};
    assert(linear_search1(v, 1) == -1);

    v = {1};
    assert(linear_search1(v, 1) == 0);
    assert(linear_search1(v, -2) == -1);
    assert(linear_search1(v, 2) == -1);

    cout << " ... test_linear_search1 done: all tests passed\n";
}

// Pre-condition:
//    none
// Post-condition:
//    Returns the smallest i >= 0 such that s[i] == c; or, if
//    c is not anywhere in s, then -1 is returned
int linear_search1a(const string &s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (c == s[i])
            return i;
    }
    return -1;
}

void test_linear_search1a()
{
    cout << "Calling test_linear_search1a ...\n";
    string s = "hello";
    assert(linear_search1a(s, 'h') == 0);
    assert(linear_search1a(s, 'e') == 1);
    assert(linear_search1a(s, 'l') == 2);
    assert(linear_search1a(s, 'o') == 4);
    assert(linear_search1a(s, 'x') == -1);

    s = "";
    assert(linear_search1a(s, 'x') == -1);

    s = "x";
    assert(linear_search1a(s, 'x') == 0);
    assert(linear_search1a(s, 'y') == -1);

    cout << " ... test_linear_search1a done: all tests passed\n";
}

// linear search in reverse order, i.e. it searches for x start at the end of v
// and then moves to the beginning
int reverse_linear_search(const vector<int> &v, int x)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (x == v[i])
            return i;
    }
    return -1;
}

void test_reverse_linear_search()
{
    cout << "Calling test_reverse_linear_search ...\n";
    vector<int> v = {5, 2, 1, 3, 4};
    assert(reverse_linear_search(v, 1) == 2);
    assert(reverse_linear_search(v, 2) == 1);
    assert(reverse_linear_search(v, 3) == 3);
    assert(reverse_linear_search(v, 4) == 4);
    assert(reverse_linear_search(v, 5) == 0);
    assert(reverse_linear_search(v, 6) == -1);

    v = {};
    assert(reverse_linear_search(v, 1) == -1);

    v = {1};
    assert(reverse_linear_search(v, 1) == 0);
    assert(reverse_linear_search(v, -2) == -1);
    assert(reverse_linear_search(v, 2) == -1);

    cout << " ... test_reverse_linear_search done: all tests passed\n";
}

// Pre-condition:
//    x is in v (i.e. there exists some i such that v[i] == x)
// Post-condition:
//    returns the smallest i >= 0 such that v[i] == x
int location_of(const vector<int> &v, int x)
{
    int i = 0;
    while (v[i] != x)
        i++;
    return i;
}

// v is *cannot* be const because the end value is temporarily modified by the
// algorithm.
int linear_search2(vector<int> &v, int x)
{
    int n = v.size();
    if (n == 0)
        return -1;
    if (n == 1)
    {
        if (v[0] == x)
            return 0;
        else
            return -1;
    }

    // n >= 2 at this point

    // first check if x is the last element
    if (v[n - 1] == x)
        return n - 1;

    // at this point we know v[n-1] != x
    int last = v[n - 1];       // save the last element
    v[n - 1] = x;              // set the last element to x
                               
    int i = location_of(v, x); // search for x
                               
    v[n - 1] = last;           // put the last element back
    if (i == n - 1)            // check which x was found
        return -1; // x is not in v
    else
        return i; 
}

void test_linear_search2()
{
    cout << "Calling test_linear_search2 ...\n";
    vector<int> v = {5, 2, 1, 3, 4};
    assert(linear_search2(v, 1) == 2);
    assert(linear_search2(v, 2) == 1);
    assert(linear_search2(v, 3) == 3);
    assert(linear_search2(v, 4) == 4);
    assert(linear_search2(v, 5) == 0);
    assert(linear_search2(v, 6) == -1);

    v = {};
    assert(linear_search2(v, 1) == -1);

    v = {1};
    assert(linear_search2(v, 1) == 0);
    assert(linear_search2(v, -2) == -1);
    assert(linear_search2(v, 2) == -1);

    cout << " ... test_linear_search2 done: all tests passed\n";
}

// Linear search on the range [begin, end). Lets you search any part of a
// vector.
int linear_search3(const vector<int> &v, int x, int begin, int end)
{
    for (int i = begin; i < end; ++i)
    {
        if (x == v[i])
            return i;
    }
    return -1;
}

void test_linear_search3()
{
    cout << "Calling test_linear_search3 ...\n";
    vector<int> v = {5, 2, 1, 3, 4};
    assert(linear_search3(v, 1, 0, v.size() - 1) == 2);
    assert(linear_search3(v, 2, 1, v.size() - 2) == 1);
    assert(linear_search3(v, 3, 2, v.size()) == 3);
    assert(linear_search3(v, 4, 4, v.size()) == 4);
    assert(linear_search3(v, 5, 0, v.size()) == 0);
    assert(linear_search3(v, 6, 0, v.size()) == -1);

    v = {};
    assert(linear_search3(v, 1, 0, v.size()) == -1);

    v = {1};
    assert(linear_search3(v, 1, 0, v.size()) == 0);
    assert(linear_search3(v, -2, 0, v.size()) == -1);
    assert(linear_search3(v, 2, 0, v.size()) == -1);

    cout << " ... test_linear_search3 done: all tests passed\n";
}

// recursive linear search on a range
int linear_search4(const vector<int> &v, int x, int begin, int end)
{
    if (begin >= end)
    {
        return -1;
    }
    else if (v[begin] == x)
    {
        return begin;
    }
    else
    {
        // note that it's begin + 1
        return linear_search4(v, x, begin + 1, end);
    }
}

int linear_search4(const vector<int> &v, int x)
{
    return linear_search4(v, x, 0, v.size());
}

void test_linear_search4()
{
    cout << "Calling test_linear_search4 ...\n";
    vector<int> v = {5, 2, 1, 3, 4};
    assert(linear_search4(v, 1) == 2);
    assert(linear_search4(v, 2) == 1);
    assert(linear_search4(v, 3) == 3);
    assert(linear_search4(v, 4) == 4);
    assert(linear_search4(v, 5) == 0);
    assert(linear_search4(v, 6) == -1);

    v = {};
    assert(linear_search4(v, 1) == -1);

    v = {1};
    assert(linear_search4(v, 1) == 0);
    assert(linear_search4(v, -2) == -1);
    assert(linear_search4(v, 2) == -1);

    cout << " ... test_linear_search4 done: all tests passed\n";
}

int main()
{
    test_linear_search1();
    test_linear_search1a();
    test_reverse_linear_search();
    test_linear_search2();
    test_linear_search3();
    test_linear_search3();
    test_linear_search4();
}
