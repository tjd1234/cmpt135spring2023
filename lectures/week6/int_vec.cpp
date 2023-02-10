// int_vec.cpp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class int_vec : public vector<int>
{
    string name;

public:
    // constructor
    int_vec(const string &n)
        : vector<int>(), name(n)
    {
    }

    // default constructor
    int_vec()
        : vector<int>(), name("<no name>")
    {
    }

    string get_name() const { return name; }

    int sum1() const
    {
        int result = 0;
        for (int i = 0; i < size(); i++)
        {
            result += (*this)[i]; // at(i)
        }
        return result;
    }

    int sum2() const
    {
        int result = 0;
        for (int n : *this)
            result += n;
        return result;
    }

    int sum3() const
    {
        return accumulate(begin(), end(), 0);
    }

    void sort_ascending()
    {
        sort(begin(), end());
    }

    void sort_descending()
    {
        sort_ascending();
        reverse(begin(), end());
    }
}; // int_vec

void summarize(const vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    cout << "size: " << v.size() << "\n";
}

void fancy_summarize(const int_vec &v)
{
    cout << v.get_name() << ":\n";
    for (int n : v)
        cout << "   " << n << "\n";
    cout << "sum = " << v.sum1() << "\n";
}

int main()
{
    int_vec v("Table 1");
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);

    v.sort_ascending();
    cout << v.get_name() << "\n";
    cout << string(7, '-') << "\n";
    fancy_summarize(v);
    // for(int n : v) {
    //     cout << n << " ";
    // }
    // cout << "size: " << v.size() << "\n";
    // cout << "sum1: " << v.sum1() << "\n";
    // cout << "sum2: " << v.sum2() << "\n";
    // cout << "sum3: " << v.sum3() << "\n";

    vector<int> w;
    w.push_back(5);
    w.push_back(6);
    w.push_back(4);
    summarize(w);
} // main
