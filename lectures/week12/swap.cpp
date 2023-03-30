// swap.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// void swap_values(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void swap_values(string &a, string &b)
// {
//     string temp = a;
//     a = b;
//     b = temp;
// }

template <typename T>
void swap_values(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void swap_demo()
{
    int x = 4;
    int y = 7;

    cout << "x = " << x << ", y = " << y << "\n";
    swap_values(x, y); // line 1
    cout << "x = " << x << ", y = " << y << "\n";

    cout << "\n";

    string s = "cow";
    string t = "rabbit";
    cout << "s = " << s << ", t = " << t << "\n";
    swap_values(s, t); // line 2
    cout << "s = " << s << ", t = " << t << "\n";

    vector<int> v1 = {1};
    vector<int> v2 = {4, 5, 6};
    swap_values(v1, v2);
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << "\n";
}

struct Person {
    string name;
    int age;
}; 

void person_swap_demo() {
    Person p1 = {"Alice", 20};
    Person p2 = {"Bob", 21};
    cout << "p1 = " << p1.name << ", p2 = " << p2.name << "\n";
    swap(p1, p2);
    cout << "p1 = " << p1.name << ", p2 = " << p2.name << "\n";
}

int main()
{
    // swap_demo();
    person_swap_demo();
}
