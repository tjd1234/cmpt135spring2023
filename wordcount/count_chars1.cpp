// count_chars1.cpp

//
// Counts the number of characters, lines, and words in a file. Similar to the
// standard Linux wc utility program.
//
// The file is read from cin, e.g.:
//
//    $ ./count_chars1 < austenPandP.txt
//    #chars: 704158
//    #lines: 13427
//    #tabs : 0
//    #words: 124580
//

#include <iostream>

using namespace std;

// These are global variables. Global variables are often a bad idea because
// they could be modified at any time by any part of the program, thus
// potentially causing subtle bugs. But in a small program like this it is safe
// and convenient to use globals variables.
int num_chars = 0;
int num_lines = 0;
int num_tabs  = 0;
int num_words = 0;

int main() {
    // first_whitespace tracks if the whitespace character is the first one in a
    // sequence of 1 or more whitespace characters. Another way of understanding
    // this is that the character immediately before a first whitespace
    // character is *not* whitespace. Thus the number of first whitespace
    // characters is a good approximation of the number of words in a file.
    bool first_whitespace = true;

    char c;
    while (cin.get(c)) {
        num_chars++;
        switch (c) {
            case '\n': num_lines++;
                       if (first_whitespace) num_words++;
                       first_whitespace = false;
                       break;
            case '\t': num_tabs++;
                       if (first_whitespace) num_words++;
                       first_whitespace = false;
                       break;
            case ' ' : if (first_whitespace) num_words++;
                       first_whitespace = false;
                       break;
            default  : first_whitespace = true;
        } // switch
    } // while

    cout << "#chars: " << num_chars << "\n";
    cout << "#lines: " << num_lines << "\n";
    cout << "#tabs : " << num_tabs  << "\n";
    cout << "#words: " << num_words << "\n";
}
