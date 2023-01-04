// count_chars5.cpp

//
// Based on count_chars4. Moves the fstream object inside the Count struct.
//
//   $ ./count_chars5 austenPandP.txt
//   #chars: 704158
//   #lines: 13427
//   #tabs : 0
//   #words: 124580
//

#include <iostream>
#include <fstream>

using namespace std;

struct Count {
    fstream infile;

    int num_chars = 0;
    int num_lines = 0;
    int num_tabs  = 0;
    int num_words = 0;
}; // Count


int main(int argc, char* argv[]) {
    // check that exactly one filename argument provided
    if (argc != 2) {
      cout << "Wrong number of arguments\n";
      return -1;
    }

    Count count;
    count.infile = fstream(argv[1]);

    bool first_whitespace = true;
    char c;
    while (count.infile.get(c)) {
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
