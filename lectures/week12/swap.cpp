// swap.cpp

#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

// template <typename T>
// void swap_values(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }

// void swap_demo()
// {
//     int x = 4;
//     int y = 7;

//     cout << "x = " << x << ", y = " << y << "\n";
//     swap_values(x, y); // line 1
//     cout << "x = " << x << ", y = " << y << "\n";

//     cout << "\n";

//     string s = "cow";
//     string t = "rabbit";
//     cout << "s = " << s << ", t = " << t << "\n";
//     swap_values(s, t); // line 2
//     cout << "s = " << s << ", t = " << t << "\n";
// }

int main()
{
    // swap_demo();
}
