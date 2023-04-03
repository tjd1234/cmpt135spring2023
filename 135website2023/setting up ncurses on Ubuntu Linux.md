**Ncurses** is a library that you can use in C++ to get more precise control over the cursor on the screen.

To install and use ncurses on Ubuntu Linux, follow these steps:

**Step 1**: Install the ncurses library by typing this at the terminal command line:
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

**Step 2**: Import `ncurses.h` into the file where you want to use curses, e.g.:

```cpp
#include <ncurses.h>
#include <string>

using namespace std;

int main() {
    // initialize the screen
    initscr();

    // print to screen
    printw("Hello World!");

    // move the cursor to row 2, column 20
    move(5, 14);
    printw("Whoosh!");

    // print some numbers in a pattern
    int c = 0;
    for (int r = 0; r < 10; r++) {
        move(r+2, c);
        // printw takes a C-string (i.e. a const char*)
        // as input; if s is a std::string, then
        // s.c_str() is C-string version of it.
        printw(to_string(r).c_str());
        c += r;
    }

    move(2, 10);
    printw("Press any key to end.");

    // redraw the screen
    refresh();

    // read a character to pause the program
    getch();

    // deallocate memory and ends ncurses
    endwin();
}
```

**Step 3**: When compiling with g++, you must include the parameter `-lncurses`. For example:

```bash
g++ ncurses_demo.cpp $(CPPFLAGS) -lncurses -o ncurses_demo
```

To compile and run an ncurses program with the usual course options, type this in the command-line:

```bash
$ g++ ncurses_demo.cpp -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g -lncurses -o ncurses_demo

$ ./ncurses_demo
```

Ncurses has many functions, and if you search for "ncurses tutorial" online you'll find more examples of what it can do.
