// sorting.cpp

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// returns true if v is sorted from begin to end (not including end)
bool is_sorted(const vector<int> &v, int begin, int end)
{
    for (int i = begin + 1; i < end; i++)
    {
        if (v[i - 1] > v[i])
        {
            return false;
        }
    }
    return true;
}

// returns true if v is in ascending sorted order,
// and false otherwise
bool is_sorted(const vector<int> &v)
{
    return is_sorted(v, 0, v.size());
}

long insertion_sort_comp_count = 0;

void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {

        // key is the value we are going to insert
        // into the sorted part of v
        int key = v[i];

        // j points to one position before the
        // (possible) insertion point of the key;
        // thus, key will eventually be inserted at
        // v[j + 1]
        int j = i - 1;

        //
        // This loop determines where to insert the key
        // into the sorted part of v. It does this by
        // searching backwards through the  sorted part
        // for the first value that is less than, or equal
        // to, key.
        //
        // This loop combines searching with element
        // moving. Every time an element bigger than the
        // key is found, it is moved up one position.
        //
        // It's possible that there is no value in the
        // sorted part that is smaller than key, in which
        // case key gets inserted at the very start of v.
        // This is a special case that is handled by j >= 0
        // in the loop condition.
        //
        while (j >= 0 && v[j] > key)
        {
            insertion_sort_comp_count++;
            v[j + 1] = v[j];
            --j;
        }
        // After loop ends this is true:
        // (j < 0 || v[j] <= key)

        v[j + 1] = key; // j points to the location
                        // *before* the one where key
                        // will be inserted
    }                   // for

    assert(is_sorted(v));
} // insertion_sort

bool insertion_sort_ok(vector<int> v)
{
    insertion_sort(v);
    return is_sorted(v);
}

void test_insertion_sort()
{
    cout << "Calling test_insertion_sort ...\n";
    vector<int> empty = {};
    vector<int> one = {5};
    vector<int> two_a = {2, 7};
    vector<int> two_b = {4, 1};
    vector<int> two_c = {3, 3};
    vector<int> same = {4, 4, 4, 4, 4, 4};
    vector<int> ordered = {-1, 0, 5, 9, 10};
    vector<int> rev = {8, 7, 3, 1, 0, -5};

    assert(insertion_sort_ok(empty));
    assert(insertion_sort_ok(one));
    assert(insertion_sort_ok(two_a));
    assert(insertion_sort_ok(two_b));
    assert(insertion_sort_ok(two_c));
    assert(insertion_sort_ok(same));
    assert(insertion_sort_ok(ordered));
    assert(insertion_sort_ok(rev));
    cout << " ... test_insertion_sort done: all tests passed\n";
}

//
// Mergesort
//

long mergesort_comp_count = 0;

// Pre-condition:
//    is_sorted(v, begin, mid)
//    is_sorted(v, mid, end)
// Post-condition:
//    is_sorted(begin, end)
void merge(vector<int> &v, int begin, int mid, int end)
{
    int a = begin;
    int b = mid;
    vector<int> result(v);
    for (int i = begin; i < end; i++)
    {
        if (a >= mid)
        {
            mergesort_comp_count += 1;
            result[i] = v[b];
            b++;
        }
        else if (b >= end)
        {
            mergesort_comp_count += 2;
            result[i] = v[a];
            a++;
        }
        else if (v[a] < v[b])
        {
            mergesort_comp_count += 3;
            result[i] = v[a];
            a++;
        }
        else
        {
            result[i] = v[b];
            b++;
        }
    } // for

    v = result;
} // merge

void mergesort(vector<int> &v, int begin, int end)
{
    const int n = end - begin;
    if (n <= 1)
        return; // base case

    int mid = (begin + end) / 2;
    mergesort(v, begin, mid);
    mergesort(v, mid, end);
    merge(v, begin, mid, end);
}

void mergesort(vector<int> &v)
{
    mergesort(v, 0, v.size());
    assert(is_sorted(v));
}

bool mergesort_ok(vector<int> v)
{
    mergesort(v);
    return is_sorted(v);
}

void test_mergesort()
{
    cout << "Calling test_mergesort ...\n";
    vector<int> empty = {};
    vector<int> one = {5};
    vector<int> two_a = {2, 7};
    vector<int> two_b = {4, 1};
    vector<int> two_c = {3, 3};
    vector<int> same = {4, 4, 4, 4, 4, 4};
    vector<int> ordered = {-1, 0, 5, 9, 10};
    vector<int> rev = {8, 7, 3, 1, 0, -5};

    assert(mergesort_ok(empty));
    assert(mergesort_ok(one));
    assert(mergesort_ok(two_a));
    assert(mergesort_ok(two_b));
    assert(mergesort_ok(two_c));
    assert(mergesort_ok(same));
    assert(mergesort_ok(ordered));
    assert(mergesort_ok(rev));
    cout << " ... test_mergesort done: all tests passed\n";
}

// return a vector of n random ints
vector<int> random_vector(int n)
{
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(rand());
    }
    return result;
}

void do_sort_test(int n)
{
    cout << "n = " << n << "\n";
    cout << "# of comparisons\n";
    cout << "Test  Insertion Sort  Mergesort\n";
    long total_insertion_sort_comp_count = 0;
    long total_mergesort_comp_count = 0;
    for (int i = 0; i < 10; i++)
    {
        vector<int> a = random_vector(n);
        vector<int> b = a;

        insertion_sort_comp_count = 0;
        insertion_sort(a);

        mergesort_comp_count = 0;
        mergesort(b);

        int smaller = insertion_sort_comp_count / mergesort_comp_count;
        cout << i << "     "
             << insertion_sort_comp_count << "          "
             << mergesort_comp_count
             << " (" << smaller << " times smaller)\n";

        total_insertion_sort_comp_count += insertion_sort_comp_count;
        total_mergesort_comp_count += mergesort_comp_count;
    } // for

    int insertion_sort_avg = total_insertion_sort_comp_count / 10;
    int mergesort_avg = total_mergesort_comp_count / 10;
    cout << "\nAvg:  "
         << insertion_sort_avg
         << "          "
         << mergesort_avg
         << " (" << insertion_sort_avg / mergesort_avg << " times smaller)\n";
} // do_sort_test

//
// Binary search
//
// Pre-condition:
//   v[begin] to v[end - 1] is in ascending sorted order
// Post-condition:
//   returns an index i such that v[i] == x and
//   begin <= i < end;
//   if x is not found, -1 is returned
int iterative_binary_search(int x, const vector<int> &v,
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
int iterative_binary_search(int x, const vector<int> &v)
{
    return iterative_binary_search(x, v, 0, v.size());
}

void test_iterative_binary_search()
{
    cout << "Calling test_iterative_binary_search ...\n";
    vector<int> empty = {};
    vector<int> one = {5};
    vector<int> two = {2, 7};
    vector<int> three = {2, 5, 7};

    assert(iterative_binary_search(5, empty) == -1);
    assert(iterative_binary_search(5, one) == 0);
    assert(iterative_binary_search(2, one) == -1);

    assert(iterative_binary_search(2, two) == 0);
    assert(iterative_binary_search(7, two) == 1);
    assert(iterative_binary_search(1, two) == -1);
    assert(iterative_binary_search(5, two) == -1);
    assert(iterative_binary_search(10, two) == -1);

    assert(iterative_binary_search(2, three) == 0);
    assert(iterative_binary_search(5, three) == 1);
    assert(iterative_binary_search(7, three) == 2);
    assert(iterative_binary_search(1, three) == -1);
    assert(iterative_binary_search(3, three) == -1);
    assert(iterative_binary_search(6, three) == -1);
    assert(iterative_binary_search(10, three) == -1);

    cout << "... test_iterative_binary_search done: all tests passed\n";
}

int recursive_binary_search(int x, const vector<int> &v,
                            int begin, int end)
{
    const int n = end - begin;

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
        return recursive_binary_search(x, v, begin, mid);
    }
    else
    {
        return recursive_binary_search(x, v, mid + 1, end);
    }
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x;
//    if x is not in v, -1 is returned
int recursive_binary_search(int x, const vector<int> &v)
{
    return recursive_binary_search(x, v, 0, v.size());
}

void test_recursive_binary_search()
{
    cout << "Calling test_recursive_binary_search ...\n";
    vector<int> empty = {};
    vector<int> one = {5};
    vector<int> two = {2, 7};
    vector<int> three = {2, 5, 7};

    assert(recursive_binary_search(5, empty) == -1);
    
    assert(recursive_binary_search(5, one) == 0);
    assert(recursive_binary_search(2, one) == -1);

    assert(recursive_binary_search(2, two) == 0);
    assert(recursive_binary_search(7, two) == 1);
    assert(recursive_binary_search(1, two) == -1);
    assert(recursive_binary_search(5, two) == -1);
    assert(recursive_binary_search(10, two) == -1);

    assert(recursive_binary_search(2, three) == 0);
    assert(recursive_binary_search(5, three) == 1);
    assert(recursive_binary_search(7, three) == 2);
    assert(recursive_binary_search(1, three) == -1);
    assert(recursive_binary_search(3, three) == -1);
    assert(recursive_binary_search(6, three) == -1);
    assert(recursive_binary_search(10, three) == -1);

    cout << "... test_recursive_binary_search done: all tests passed\n";
}

// int main()
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " n\n";
        return 1;
    }

    int n = atoi(argv[1]);
    do_sort_test(n);

    // test_insertion_sort();
    // test_mergesort();
    // test_iterative_binary_search();
    // test_recursive_binary_search();
}
