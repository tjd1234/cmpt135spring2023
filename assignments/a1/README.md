# Assignment 1: Echo

For this assignment, please download the file [myecho.cpp](myecho.cpp) and put
all your code into that file.

## Part 1

### Question 1

Write a function called `quote(s)` that returns a copy of the string `s`
surrounded by double quotes. If `s` already starts *and* ends with double quotes,
then return an unchanged copy.

For example, this:

```cpp
cout << quote("hello")      << "\n"
     << quote("goodbye")    << "\n"
     << quote("\"Aloha!\"") << "\n"
     << quote("toodles\"")  << "\n"
     << quote("\"")         << "\n" 
     << quote("")           << "\n";
```

Should print this:

```
"hello"
"goodbye"
"Aloha!"
"toodles""
"""
""
```

In addition to implementing `quote`, also write a function called `test_quote()`
that *automatically* tests your `quote` function. Use `assert` or if-statements
to do the testing, and test the above examples, as well as a few other examples
that you make up. Be thorough --- your function should work for all valid
inputs, not just the ones in the examples.

**Note** Due to the confusion caused by earlier incorrect examples for `quote`,
here is a test function you can use in your assignment to check the correctness
of your `quote` function:

```cpp
void quote_test() {
    cout << "testing quote ... ";
    assert(quote("a"      ) == "\"a\""   );
    assert(quote("ab"     ) == "\"ab\""  );
    assert(quote("\"a\""  ) == "\"a\""   );
    assert(quote("\"ab\"" ) == "\"ab\""  );
    assert(quote("a\"b"   ) == "\"a\"b\"");
    assert(quote("\"a"    ) == "\"\"a\"" );
    assert(quote("a\""    ) == "\"a\"\"" );
    assert(quote(""       ) == "\"\""    );
    assert(quote("\""     ) == "\"\"\""  );
    cout << "all tests passed\n";
}
```


### Question 2

When dealing with vectors of strings, it's convenient to print them with the
`<<` operator. For example:

```cpp
vector<string> v = {"art", "booth", "C"};
cout << v << "\n";  // prints: {"art", "booth", "C"}
```

To make that work we must *overload* `operator<<` like this:

```cpp
string to_string(const vector<string>& v) {
  //
  // ... you write the body ...
  //
}

ostream& operator<<(ostream& out, 
                    const vector<string>& v) 
{
    return out << to_string(v);
}
```

Implement the `to_string(v)` function so that `operator<<` works correctly.
`to_string(v)` takes a `vector<string>` as input and returns a nicely formatted
`string` as in the examples. The output of `to_string` should be the same format
as C++ string vectors, so you could cut-and-paste the output directly into a C++
program.

Here are some more examples:

```cpp
cout << vector<string>{}               << "\n"
     << vector<string>{"a"}            << "\n"
     << vector<string>{"a", "b"}       << "\n"
     << vector<string>{"a", "b", "c"}  << "\n";
```

This prints:

```
{}
{"a"}
{"a", "b"}
{"a", "b", "c"}
```

In addition to implementing `to_string`, also write a function called
`test_to_string()` that *automatically* tests your `to_string` function. Use
`assert` or if-statements to do the testing, and test the above examples, as
well as a few other examples that you make up. Be thorough --- your function
should work for all valid inputs, not just the ones in the examples.


## Part 2

The `echo` command is a standard shell command that prints the arguments passed
to it. For example, here is the [Fish shell](https://fishshell.com/) echo
command:

```bash
❯ echo Welcome to Linux!
Welcome to Linux!

❯ echo -s Welcome to Linux!
WelcometoLinux!

❯ echo Welcome to Linux! -s
Welcome to Linux! -s
```

The `-s` flag prints the arguments *without* a space between them. As the
example shows, it must be *first* to have any effect.

In the following questions, your task to implement a customized version of the
`echo` utility. It works similarly, but *not identically*, to the Linux `echo`.

Each question asks you to add a new feature, and you can do this is all in the
same program. 

Please note the following:

- *Case matters* in the input strings, e.g. `-s` and `-S` are treated as
  *different* strings, and so `-S` would be an invalid flag.
- A flag, like `-s`, is only treated as a flag if it is the *first* string
  passed to your `myecho`. Otherwise, if it's not the first string, it's treated
  like a regular word and printed normally.

### Question 3

Implement `myecho` so that when passed 0 or more strings, each separated by at
least once space, those strings are printed on the screen with exactly one space
between them. For example:

  ```bash
  > ./myecho Welcome to Linux!
  Welcome to Linux!

  ❯ ./myecho   Welcome   to       Linux!
  Welcome to Linux!

  ❯ ./myecho


  ```

> The sample output uses the [Fish shell](https://fishshell.com/), and we
> recommend you use that. Otherwise, you might get slightly different-looking
> output. 


### Question 4

To the version of `./myecho` you wrote in the previous question, add support for
a `-h` flag that prints the help message given below and exits (ignoring any
strings that come after the `-h`).

The help message should look like this:

```bash
❯ ./myecho -h
Usage: ./myecho [-runtests|-(hrs)] [string ...]
  -runtests: run the tests
             over-rides single-character flags
         -h: print this help message
             over-rides other single-character flags
         -r: print the strings in reverse order
         -s: no space between arguments
         -q: quote the printed results
   -rs, -sr: no space between arguments, in reverse order

  Repeated single-character flags are allowed (and are ignored).
  Unknown flags cause an error.


Examples:
  ❯ ./myecho -q
  ""
  ❯ ./myecho x y z
  x y z
  ❯ ./myecho -q x y z
  "x y z"
  ❯ ./myecho -sr x y z
  zyx
  ❯ ./myecho -h
```

Please use this particular help message. The other options listed in it will be
implemented in the following questions.


### Question 5

To the version of `./myecho` you wrote in the previous question, add support for
a `-runtests ` flag that calls the `test_quote()` and `test_to_string()`
functions. Any strings after `-runtests` are ignored. 

The tests should print their results, as shown in the examples.

For example:

```bash
❯ ./myecho -runtests
running quote tests ... all passed
running to_string tests ... all passed

❯ ./myecho -runtests one two three
running quote tests ... all passed
running to_string tests ... all passed

❯ ./myecho one two -runtests three
one two -runtests three

❯ ./myecho -runtests -h one two three
running quote tests ... all passed
running to_string tests ... all passed

❯ ./myecho -h -runtests a b
... prints the help message ...
```

As these examples show, `-h` and `-runtests` only have their special meaning if
they appear as the *first* string passed to `myecho`. If they appear later, they
are treated as regular strings.

### Question 6

To the version of `./myecho` you wrote in the previous question, add support for
the `-q` flag that prints a `"` character (double quote) at the begin and end of
the printed result. For example:

```bash
❯ ./myecho -q
""

❯ ./myecho x y z
x y z

❯ ./myecho -q x y z
"x y z"

> ./myecho -qh z y z
... prints the help message ...
```

Notice that in the quoted strings there is *no* space after the last string.

### Question 7

To the version of `./myecho` you wrote in the previous question, add support for
the `-s` flag that prints the strings *without* a space between them. For
example:

```bash
❯ ./myecho -s Welcome to Linux!
WelcometoLinux!

❯ ./myecho   -s   Welcome   to       Linux!
WelcometoLinux!

❯ ./myecho   -qs   Welcome   to       Linux!
"WelcometoLinux!"

> ./myecho -s

> ./myecho -sq
""
```

Note that `-s` is treated as a regular string if it is not the first string:

```bash
> ./myecho Welcome to -s Linux!
Welcome to -s Linux!
```

### Question 8

To the version of `./myecho` you wrote in the previous question, add support for
the `-r` flag that prints the strings in *reverse* order. For example:

```bash
❯ ./myecho -r Welcome to Linux!
Linux! to Welcome

> ./myecho   -r   Welcome   to       Linux!
Linux! to Welcome

> ./myecho   -r   Welcome   to       Linux!
Linux! to Welcome

> ./myecho Welcome to -r Linux!
Welcome to -r Linux!

> ./myecho -r

```

Note that `-r` is treated as a regular string if it is not the first string.


### Question 9

To the version of `./myecho` you wrote in the previous question, add support for
multiple single-character flags. For example:

```bash
> ./myecho -sr a b c
cba

> ./myecho -rqs a b c
"cba"

> ./myecho -sh Welcome to Linux!
... help message printed...

> ./myecho -hq Welcome to Linux!
... help message printed...
```

Note that the help message is *not* printed in quotes because of the `-q` flag.
The `-h` flag takes precedence over all other flags, and so the `-q` flag is
ignored.

The order of multiple single-character flags does not matter. Repeated
single-character flags are allowed, but ignored. For example:

```bash
> ./myecho -qssq Welcome to Linux!
"WelcometoLinux!"

> ./myecho -hhshs Welcome to Linux!
... help message printed ...
```

If `-h` is one of the flags, it *always* takes precedence (and any other
flags/strings are ignored).

If `-runtests` is the *first* string, then the tests are run and any following
flags/strings are ignored. For example:

```bash
❯ ./myecho -runtests -s Welcome to Linux!
running quote tests ... all passed
running to_string tests ... all passed
``` 

Mixing `-runtests` with other single-character flags is not allowed and should
cause an "invalid flag" error, e.g.:

```bash
❯ ./myecho -hruntests
Error, invalid flag: u

... help message printed ...

❯ ./myecho -runtestsh
Error, invalid flag: u

... help message printed ...
```

Also, if an invalid flag is passed, then print an error message, followed by the
help message, and then immediately exit:

```bash
❯ ./myecho -S Welcome to Linux!
Error, unknown flag: -S
... help message printed...

❯ ./myecho -qQs Welcome to Linux!
Error, unknown flag: -Q
... help message printed...
```

## Hints

- Working with a `vector<string>` is easier than working with a C-style array of
  strings, and so a good first step is to convert the `argc` command-line inputs
  into a `vector<string>`. 

- You are not *required* to use `quote` and `<<` in the *implementation* of
  `myecho`, but they can be useful for printing when debugging.

- The logic for handling flags can get tricky, so make it as simple as possible,
  even if you need to sacrifice some efficiency. For this assignment, code that
  is easy to test and easy to read is more important than squeezing out every
  last drop of performance (you can improve the performance later).

- The file [test.sh](test.sh) contains a script that you can run like this:

  ```bash
  > ./test.sh
  ... lots of output ...
  ```

  Sample correct output is in the file [test.out](test.out). You can use this to
  help test your program. For instance in BASH (the default shell on Ubuntu) you
  can type this command to compare the output of your program with the correct

  ```bash
  > ./test.sh > out.txt
  > diff out.txt test.out
  ... no output means your program produced the correct output ...
  ```

## Marking Scheme

Before we give your program any marks, it must meet the following **basic
requirements**:

- It *compiles on Ubuntu Linux* using [the standard course makefile](makefile),
  e.g.:

  ```bash
  $ make myecho 
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   myecho.cpp   -o myecho
  ```

  If your program fails to compile, your mark for this assignment will be 0.

- It has *no memory leaks*, according to `valgrind`, e.g.:

  ```console
  $ valgrind ./myecho one two three
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory leaks if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and
    `possibly lost` are all 0.

  - `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non-zero number of
    bytes.

  If `valgrind` reports any errors for your program, your mark for the
  assignment will be 0.

- **It includes the large comment section with student info, statement of
  originality, and notes to the marker**, completely and correctly filled out.
  If your submitted file does *not* have this, then we will assume your work is
  not original, and your mark for the assignment will be 0.
  
If your program meets all these basic requirements, then it will graded using
this marking scheme.

#### **Overall source code readability: 5 marks**
- All code is sensibly and consistently indented, and all lines are 100
  characters in length, or less.
- Whitespace is used to group related pieces of a code to make it easier for
  humans to read. All whitespace should have a purpose.
- Variable and function names are self-descriptive.
- Appropriate features of C++ are used, as discussed in class and in the notes.
  **Note** If you use a feature that we haven't discussed in class, **you must
  explain it in a comment**, even if you think it's obvious.
- Comments are used when needed to explain chunks of code whose purpose is not
  obvious from the code itself. There should be *no* commented-out code from
  previous versions.

#### **Overall performance and memory usage: 2 marks**
- No unnecessary work is done.
- No unnecessary memory is used.

#### **Source code correctness**
To get full marks, your functions must pass all the test cases for that
question. The marker may use test cases not given in the assignment.

- Question 1: **2 marks**, `quote` and `test_quote`
- Question 2: **2 marks**, `to_string` and `test_to_string`
- Question 3: **2 marks**
- Question 4: **2 marks**
- Question 5: **2 marks**
- Question 6: **2 marks**
- Question 7: **2 marks**
- Question 8: **2 marks**
- Question 9: **3 marks**

#### Deductions
- **-1 mark** (at least) if your file does not have the correct name
- **a score of 0** if you accidentally submit a "wrong" non-working file, and
  then *after the due date* submit the "right" file. If you can provide evidence
  that you finished the assignment on time, then it may be marked (probably with
  a late penalty).


## Submitting Your Assignment

Please submit your assignment on [Canvas](canvas.sfu.ca) when it is done. Submit
just your `myecho.cpp` file. Do **not** zip it, and do not submit any other
files.

You can submit your file as many times as you like before the due date without
penalty. Each re-submitted file gets automatically renamed by
[Canvas](canvas.sfu.ca), e.g. if you submit `myecho.cpp` twice the second one
will be renamed to something like `myecho-2.cpp`.
