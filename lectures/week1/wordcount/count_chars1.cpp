// count_chars1.cpp

//
// Counts the number of characters, lines, and words in a file. Similar to the
// standard Linux wc utility program.
//
// The file is read from cin, e.g.:
//
//    > ./count_chars1 < austenPride.txt
//    #chars: 704158
//    #lines: 13427
//    #tabs : 0
//    #words: 124580
//

#include <iostream>

using namespace std;

// global variables to hold the counts
int num_chars = 0;
int num_lines = 0;
int num_tabs  = 0;
int num_words = 0;

int main() {
    //
    // To count the number of words in the file, we use the trick of counting
    // the number of whitespace characters *between* words. The first time we
    // see a whitespace character we increment the word count, and then ignore
    // any subsequent whitespace characters until we see a non-whitespace
    // character.
    //
    // first_whitespace keeps track of when a whitespace character is the first
    // one in a sequence of 1 or more whitespace characters. Essentially, the
    // program ignores all whitespace characters *except* first ones in a
    // sequence.
    //
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
