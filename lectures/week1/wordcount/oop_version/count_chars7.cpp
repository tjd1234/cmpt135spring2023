// count_chars7.cpp

//
// Based on count_chars6. Re-write of `main` to allow for multiple files to be
// passed as arguments.
//
//   > ./count_chars7 austenPride.txt
//   #chars: 704158
//   #lines: 13427
//   #tabs : 0
//   #words: 124580
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Count {
    fstream infile;

    // Constructor: initializes a Count object.
    Count(const string& fname)
    : infile(fname)  // initializer list
    { }

    int num_chars = 0;
    int num_lines = 0;
    int num_tabs  = 0;
    int num_words = 0;
}; // Count


void process_file(const string& fname) {
    Count count(fname);

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

    cout << "   #chars: " << count.num_chars << "\n";
    cout << "   #lines: " << count.num_lines << "\n";
    cout << "   #tabs : " << count.num_tabs  << "\n";
    cout << "   #words: " << count.num_words << "\n";
} // process_file

int main(int argc, char* argv[]) {
    // check that one or more filename arguments provided
    if (argc < 2) {
      cout << "Wrong number of arguments\n";
      return -1;
    }

    for(int i = 1; i < argc; i++) {
        if (i > 1) cout << "\n";
        cout << argv[i] << ":\n";
        process_file(argv[i]);
    }
}
