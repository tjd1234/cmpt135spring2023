// count_chars2.cpp

//
// Based on count_chars1. Removes global variables and uses a struct instead.
//

#include <iostream>

using namespace std;

struct Count {
    int num_chars = 0;
    int num_lines = 0;
    int num_tabs  = 0;
    int num_words = 0;
}; // Count


int main() {
    // Creates a Count object. All the counts are initialized to 0 as in the
    // struct above.
    Count count;

    bool first_whitespace = true;
    char c;
    while (cin.get(c)) {
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
