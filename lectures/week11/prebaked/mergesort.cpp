// mergesort.cpp

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Returns a new vector<string> containing the elements of v from v[begin] to
// v[end - 1].
vector<string> slice(const vector<string> &v, int begin, int end)
{
    vector<string> result(end - begin, "");
    for (int i = begin; i < end; i++)
    {
        result[i - begin] = v[i];
    }
    return result;
}

// Pre-condition:
//    a and b both in ascending sorted order
// Post-condition:
//    result is in ascending sorted order and contains all strings from a and b
vector<string> merge(const vector<string> &v, const vector<string> &w)
{
    vector<string> result(v.size() + w.size(), "");
    int a = 0;
    int b = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (a >= v.size())
        {
            result[i] = w[b];
            b++;
        }
        else if (b >= w.size())
        {
            result[i] = v[a];
            a++;
        }
        else if (v[a] < w[b])
        {
            result[i] = v[a];
            a++;
        }
        else
        {
            result[i] = w[b];
            b++;
        }
    }
    return result;
}

void mergesort(vector<string> &v)
{
    if (v.size() <= 1)
        return; // base case

    int mid = v.size() / 2;
    vector<string> left = slice(v, 0, mid);
    vector<string> right = slice(v, mid, v.size());
    mergesort(left);
    mergesort(right);
    v = merge(left, right);
}

// // Pre-condition:
// //    is_sorted(v, begin, mid)
// //    is_sorted(v, mid, end)
// // Post-condition:
// //    is_sorted(begin, end)
// void merge(vector<string> &v, int begin, int mid, int end)
// {
//     int a = begin;
//     int b = mid;
//     vector<string> result(v);
//     for (int i = begin; i < end; i++)
//     {
//         if (a >= mid)
//         {
//             result[i] = v[b];
//             b++;
//         }
//         else if (b >= end)
//         {
//             result[i] = v[a];
//             a++;
//         }
//         else if (v[a] < v[b])
//         {
//             result[i] = v[a];
//             a++;
//         }
//         else
//         {
//             result[i] = v[b];
//             b++;
//         }
//     } // for

//     v = result;
// } // merge

// void mergesort(vector<string> &v, int begin, int end)
// {
//     if (end - begin <= 1)
//         return; // base case

//     int mid = (begin + end) / 2;
//     mergesort(v, begin, mid);
//     mergesort(v, mid, end);
//     merge(v, begin, mid, end);
// }

// void mergesort(vector<string> &v)
// {
//     mergesort(v, 0, v.size());
// }

int main()
{
    // read in the words from cin
    cout << "Reading words ..." << endl;
    vector<string> words;
    string w;
    while (cin >> w)
    {
        words.push_back(w);
    }

    // randomly re-arrange them
    cout << "Sorting " << words.size() << " words using mergesort ..." << endl;
    mergesort(words);
    cout << "done!\n";

    // write them to cout
    for (string w : words)
    {
        cout << w << "\n";
    }
}
