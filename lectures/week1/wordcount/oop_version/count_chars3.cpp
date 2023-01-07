// count_chars3.cpp

//
// Based on count_chars2. Uses fstream to read the file, and so it no longer
// requires the the < redirection:
//
//   > ./count_chars3 austenPride.txt
//   #chars: 704158
//   #lines: 13427
//   #tabs : 0
//   #words: 124580
//

#include <iostream>
#include <fstream>

using namespace std;

struct Count {
    int num_chars = 0;
    int num_lines = 0;
    int num_tabs  = 0;
    int num_words = 0;
}; // Count


int main() {
    fstream infile("austenPride.txt");

    // Creates a Count object. All the counts are initialized to 0 in the
    // struct above.
    Count count;

    bool first_whitespace = true;
    char c;
    while (infile.get(c)) {
        count.num_chars++;
        switch (c) {
            case '\n': count.num_lines++;
                       if (first_whitespace) count.num_words++;
                       first_whitespace = false;
                       break;
            case '\t': count.num_tabs++;
                       if (first_whitespace) count.num_words++;
                       first_whitespace = false;
                       break;
            case ' ' : if (first_whitespace) count.num_words++;
                       first_whitespace = false;
                       break;
            default  : first_whitespace = true;
        } // switch
    } // while

    cout << "#chars: " << count.num_chars << "\n";
    cout << "#lines: " << count.num_lines << "\n";
    cout << "#tabs : " << count.num_tabs  << "\n";
    cout << "#words: " << count.num_words << "\n";
}
