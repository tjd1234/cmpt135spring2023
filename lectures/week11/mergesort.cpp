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

int main()
{
    // read in the words from cin
    vector<string> words;
    string w;
    while (cin >> w)
    {
        words.push_back(w);
    }

    // randomly re-arrange them
    mergesort(words);

    // write them to cout
    for (string w : words)
    {
        cout << w << "\n";
    }
}
