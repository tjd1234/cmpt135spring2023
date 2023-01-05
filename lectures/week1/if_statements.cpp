// if_statements.cpp

#include <iostream>

using namespace std;

int main() {
    cout << "What is the temperature in Celsius? ";
    double temp = 0.0;
    cin >> temp;
    if (temp < 0.0)       cout << "It is freezing!\n";
    else if (temp < 10.0) cout << "It is cold!\n";
    else if (temp < 20.0) cout << "It is cool!\n";
    else if (temp < 30.0) cout << "It is warm!\n";
    else                  cout << "It is hot!\n";
}
 