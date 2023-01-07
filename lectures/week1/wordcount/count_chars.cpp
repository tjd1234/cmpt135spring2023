// count_chars.cpp

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

int main() {
    //
    // initialize the count variables
    //
    int num_chars = 0;
    int num_lines = 0;
    int num_tabs  = 0;
    int num_words = 0;

    //
    // To count the number of words in the file, we use the trick of counting
    // the number of whitespace characters *between* words. The first time we
    // see a whitespace character we increment the word count, and then ignore
    // any subsequent whitespace characters until we see a non-whitespace
    // character.
    //
    // first_whitespace keeps track of when a whitespace character is the first
    // one in a sequence of 1 or more whitespace characters.
    //
    // For this program, whitespace characters are: ' ' (space), '\n' (newline),
    // and '\t' (tab).
    //
    bool first_whitespace = true;

    //
    // process the input one character at a time
    //
    char c;
    while (cin.get(c)) {
        num_chars++;
        switch (c) {
            //
            // Every time we see a whitespace character we check if it is the
            // first one in a sequence. If it is, we increment num_words. Then,
            // whether or not num_words was incremented, we set first_whitespace
            // to false to indicate that any immediately following whitespace
            // characters should *not* increment word_count.
            //
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
            //
            // Every time we see a non-whitespace character we set
            // first_whitespace to true, meaning that the next whitespace
            // character we see should cause word_count to be incremented.
            //
            default  : first_whitespace = true;
        } // switch
    } // while

    //
    // print the results
    //
    cout << "#chars: " << num_chars << "\n";
    cout << "#lines: " << num_lines << "\n";
    cout << "#tabs : " << num_tabs  << "\n";
    cout << "#words: " << num_words << "\n";
}
