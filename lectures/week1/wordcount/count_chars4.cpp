// count_chars4.cpp

//
// Based on count_chars3. Reads the file name as an argument from the command
// line.
//
//   > ./count_chars4 austenPride.txt
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

int main(int argc, char* argv[]) {
    // check that exactly one filename argument provided
    if (argc != 2) {
      cout << "Wrong number of arguments\n";
      return -1;
    }

    // argv[0] is the name of the program, e.g. "./count_chars5"
    // argv[1] is the first command-line argument, i.e. the name of the file
    fstream infile(argv[1]);

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
