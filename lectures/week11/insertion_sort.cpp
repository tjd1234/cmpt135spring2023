// insertion_sort.cpp

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertion_sort(vector<string> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {

        // key is the value we are going to insert
        // into the sorted part of v
        string key = v[i];

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
            v[j + 1] = v[j];
            --j;
        }
        // After loop ends this is true:
        // (j < 0 || v[j] <= key)

        v[j + 1] = key; // j points to the location
                        // *before* the one where key
                        // will be inserted
    }                   // for

} // insertion_sort

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
    insertion_sort(words);

    // write them to cout
    for (string w : words)
    {
        cout << w << "\n";
    }
}
