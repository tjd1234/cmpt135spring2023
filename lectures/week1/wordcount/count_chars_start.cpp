// count_chars_start.cpp

//
// A "starter" file for the word count program. It shows how to read characters
// from cin.
//
// For example:
//
//   ❯ ./count_chars_start
//   this is a test
//   this is a test
//
// This "echos" whatever user types, after they press return.
//
// To exit the program, type Ctrl-D (on Linux).
//
// You can pass a file to the program using the < operator, e.g.:
//
//    ❯ ./count_chars_start < poem.txt
//    Computers that are smart?
//    I want no part.
//
//    Computers that are quantum?
//    I want'em!
//
// The < causes to the program to read from the file poem.txt instead of from the 
// keyboard. This is useful trick to remember!
//

#include <iostream>

using namespace std;


int main() {
    char c;
    while (cin.get(c)) {
        cout << c;
    } // while
} // main
