// switch.cpp

//
// Compile without -Werror flag.
//

#include <iostream>

using namespace std;

int main() {
    char sep = ',';
    switch (sep) {
        case ' ':
        case ',': cout << "A";
        case '-': cout << "B";
        default : cout << "C";
    }
}
