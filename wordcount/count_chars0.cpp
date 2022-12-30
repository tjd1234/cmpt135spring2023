// count_chars0.cpp

//
// An alternate implementation of count_chars1.cpp that uses a different
// design, i.e. it uses the function skip_whitespace, and is_whitespace
// increments some counts.
//

#include <iostream>

using namespace std;

// These are global variables. Global variables are often a bad idea because
// they could be modified at any time by any part of the program, thus
// potentially causing subtle bugs. But in a small program like this it is
// actually convenient to use globals variables because the skip_whitespace
// function needs to modify multiple variables.
int num_chars = 0;
int num_lines = 0;
int num_tabs  = 0;
int num_words = 0;

// Returns true if c is a whitespace character, and false otherwise.
bool is_whitespace(char c) {
    switch (c) {
        case ' ' : return true;
        case '\n': num_lines++;
                   return true;
        case '\t': num_tabs++;
                   return true;
        default  : return false;
    }
}

// Ignore all whitespace characters.
void skip_whitespace() {
    char c;
    cin.get(c);
    if (cin.eof()) return;
    num_chars++;
    while (is_whitespace(c)) {
        cin.get(c);
        if (cin.eof()) return;
        num_chars++;
    }
}

int main() {
    // This while-loop reads from standard input, cin, one character at a
    // time. If there are no more characters to read then the end-of-file
    // (EOF) character is read, causing cin.get(c) to return false.
    char c;
    while (cin.get(c)) {
        switch (c) {
            case '\n': num_chars++;
                       num_lines++;
                       num_words++;
                       skip_whitespace();
                       break; // fall-through occurs if this break is removed
            case '\t': num_chars++;
                       num_tabs++;
                       skip_whitespace();
                       break; // fall-through occurs if this break is removed
            case ' ' : num_chars++;
                       num_words++;
                       skip_whitespace();
                       break; // fall-through occurs if this break is removed
            default  : num_chars++; // default case catches all other characters
                                    // break is not needed on last case
        } // switch
    } // while
    cout << "#chars: " << num_chars << "\n";
    cout << "#lines: " << num_lines << "\n";
    cout << "#tabs : " << num_tabs  << "\n";
    cout << "#words: " << num_words << "\n";
}
