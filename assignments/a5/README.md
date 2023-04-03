# Order and Chaos

> Sometimes putting five things in a straight line is the perfect solution, but
> other times, letting them dance to the beat of their own drum can create a
> beautiful chaos that defies all expectation. -- ChatGPT

*Order and Chaos* is a 2-player game played on a 6-by-6 (or bigger) grid of
squares. One player is *Order*, the other is *Chaos*. They take turns placing
either an *X* or an *O* in an empty square (players always have the choice of
placing an *X* or *O*). *Order* wins if they make 5 *X*s or *O*s in a line
(horizontally, vertically, or diagonally), and *Chaos* wins if they can prevent
this.

An unusual feature of this game is that both players can play *X*s and *O*s. On
their turn, a player can choose to play either an *X* or an *O*.

For this assignment, your task is to implement *Order and Chaos* allowing a
human player to play against the computer.

## Working with a Partner

If you like, you can work with a partner on this assignment. To set this up, you
and your partner should join an assignment 5 group on Canvas.

If you do with a partner, keep this in mind:

- Both partners will get the same mark.
- Only one partner needs to submit the assignment on Canvas, as part of the
  team.
- Both partners should do an equal amount of programming work. We may ask
  questions of either partner about how the code works.
- Teams of *more* than 2 are *not* allowed under any circumstances.
- It's fine if you want to work on your own.


## Requirements

### Basic Features: 15 marks
- **1 mark**: Display instructions for the human at the start of the game.
- **1 mark**: The game is played on a 6-by-6 grid of squares. 
- **1 mark**: In addition to a 6x6 grid size, the user can also choose grids of
  size 7x7, 8x8, or 9x9.
- **1 mark**: The human player is randomly assigned to be either *Order* or
  *Chaos*.
- **1 mark**: The human moves first or second at random.
- **1 mark**: The human types there moves in some easy way (e.g. by entering the
  coordinates of the square they want to place their piece in).
- **1 mark**: Moves entered by the user are checked for validity. If a move is
  invalid, then ask the user to re-enter their move. A move is valid if it
  refers to an empty square on the board, and there is not already an *X* or *O*
  there.
- **3 marks** 1 mark if the computer can play any strategy at all. 2 marks if
  the computer can play random moves. 3 marks if the computer can play better
  than random moves, e.g. it blocks the human from making obvious 5-in-a-lines.
  Try to make the computer play as intelligently as possible. The computer
  should *never* resign.
- **3 marks**: Correctly recognizing the game is over when one of these things
  occurs:
  - The human resigns. In this case, the human loses and the computer wins.
  - *Order* makes 5 *X*s or *O*s in a line (horizontally, vertically, or
    diagonally). In this case *Order* wins, and *Chaos* loses.
  - There are no empty squares left on the board, and there is no line of 5 *X*s
    or *O*s. In this case, *Chaos* wins and *Order* loses.
- **1 mark**: When the game is over, display a message indicating who won.
- **1 mark**: After a game ends, the user is asked if they want to play again.
  If they say yes, then start a new game. If they say no, then exit the program.

### Use of Classes: 2 marks
- **1 mark**: A class is used to represent the playing board. A good name for
  this class is `Board`.
- **1 mark**: At least one other class/struct is used in a sensible way. For
  example, you could use a struct to represent a player, storing whether they
  are *Order* or *Chaos*, and whether they are human or computer.

### Interface and Source Code Readability: 8 marks
- **3 marks** Quality of the user interface. It should be both easy to read
  and look nice. 
- **5 marks**: Code readability and style.
  - All code is sensibly and consistently indented, and all lines are 100
    characters in length, or less.
  - Whitespace is used to group related pieces of a code to make it easier for
    humans to read. All whitespace has a purpose.
  - Variable and function names are self-descriptive.
  - Appropriate features of C++ are used, as discussed in class and in the
    notes. **Note** If you use a feature that we haven't discussed in class,
    **you must explain it in a comment**, even if you think it's obvious.
  - Comments are used when needed to explain chunks of code whose purpose is not
    obvious from the code itself. There should be *no* commented-out code from
    previous versions.

### Report: 5 marks
- **5 marks**: The "Assignment 5 Report" at the bottom of [a5.cpp](a5.cpp) is
  filled in with these sections:
  - a list all known bugs/limitations
  - a list of any extra features
  - an explanation, in high-level terms, of the strategy the computer player
    follows
  - acknowledgements of any help you received
  - the report is neatly formatted, uses full sentences, good grammar, and
    correct spelling

### Deductions

- at least **-1 mark** if your file has an incorrect name, or you submit it in
  the incorrect format, etc.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
  the header of your file.
- **a score of 0** if you don't include the "statement of originality.
- **a score of 0** if you accidentally submit a "wrong" non-working file, and
  then *after the due date* submit the "right" file. If you can provide evidence
  that you finished the assignment on time, then it may be marked (and probably
  with a late penalty).


## Constraints

You can #include any standard C++ libraries, i.e. any libraries that come with
every C++17 compiler. Code and files from the web are *not* allowed: all the
code in your program should be written by you.

As always, you must cite all help you get. If a website, book, person, etc.
helps you with this assignment, then cite their help in the report at the end.


## Submitting Your Work

On Canvas, please submit just the file [a5.cpp](a5.cpp) with your answers in
it. Don't submit anything else.

The marker will compile your [a5.cpp](a5.cpp) using 
[the standard course makefile](makefile). 

**No other files will be in the folder your program is compiled in**. In
particular, [cmpt_error.h](cmpt_error.h) and [cmpt_trace.h](cmpt_trace.h) will
*not* be in the folder when your [a5.cpp](a5.cpp) is compiled.

Remember, if you are working with a partner, then only one of you needs to
submit the assignment on Canvas.


## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using the standard course
  [makefile](makefile):
  
  ```
  $ make a5
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   a5.cpp   -o a5
  ```
  
  If your program fails to compile, your mark for this assignment will be 0.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as
  [a5.cpp](a5.cpp) when it's compiled, so your program can use `cmpt::error`
  if necessary.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:

  ```
  $ valgrind ./a5
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory error if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
    lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non- zero number of
    bytes.

- **You must include the large comment section with student info and the
  statement of originality**. If your submitted file does not have this, then
  we will assume your work is not original and it will not be marked.
  
If your program meets all these basic requirements, then it will graded using
the marking scheme on Canvas.


## Hints

You *can*, but are *not required*, to use inheritance, recursion, pointers, etc.
Only use a feature if it makes sense to use it.

A good way to start this program is to create a `Board` class that represents
the board, and has a method to print it out. Also add a method like
`make_user_move()` that, when called, asks the user to enter a move and then
plays it on the board (re-asking if they enter an invalid move). 

Your board could be drawn like this:

```
   1 2 3 4 5 6
 a . . . . . .
 b . . . . . .
 c . . X . . .
 d . . . X . .
 e . . . . X .
 f . . . . . O
```

For instance, the *O* in the bottom-right corner is at position "f6". 

For entering moves, you could, as shown above, label each row of the board with
a letter, and each column with a number. If the user enters "a3x" on the board
above, the board will look like this:

```
   1 2 3 4 5 6
 a . . X . . .
 b . . . . . .
 c . . X . . .
 d . . . X . .
 e . . . . X .
 f . . . . . O
```

If you run into bugs, a simple debugging technique is to add print statements
that print out the values of variables, e.g. `cout << "debug: x=" << x <<
'\n';`. Putting "debug:" at the start makes it easier to find all these lines
and comment them out (e.g. before submitting your finished program).
