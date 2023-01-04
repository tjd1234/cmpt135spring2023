## Example: Counting Words

### The Problem

The standard Linux utility `wc` counts characters, lines, and words in a file.
For example:

```
$ wc austenPandP.txt
 13427 124580 704158 austenPandP.txt
```

This tells us that [austenPandP.txt](austenPandP.txt) has 13427 lines, 124580
words, and 704158 characters.

Create your own version of `wc` that does each of these thigns:

1. **Count the number of characters in a file**. To do this, use `cin.get`.
   `cin.get(c)` sets the `char` `c` to the next character from `cin`. After
   calling `cin.get(c)`. If there are no more characters, i.e. an end of file
   (EOF) character is read in, then `cin.get(c)` returns `false`.
    
   You don't need to use any special file processing in your program. Instead,
   use file re-direction in the shell to process a file like this:
  
   ```bash
   $ ./count_chars < austenPandP.txt
   #chars: 704158
   #lines: 13427
   #tabs: 0
   #words: 124580
   ```

2. **Count the number of lines in a file**. For simplicity, a line is an
   occurrence of a `'\n'` (newline) character.

3. **Count the number of `'\t'` (tab) characters in a file**.

4. **Count the number of words in a file**. The precise definition of a word is
   tricky, so instead it is easier to count *non*-words, i.e. sequences of
   whitespace characters that appear between words. Count the number of
   sub-strings consisting of one or more whitespace characters, where whitespace
   characters are: `' '` (space), `'\n'` (newline), and `'\t'` (tab).


### Sample Solutions

The file [count_chars1.cpp](count_chars1.cpp) is a pretty good solution to the
basic problem. To help understand C++ and object-oriented programming, we modify
[count_chars1.cpp](count_chars1.cpp) a step at a time to become more
object-oriented. The final result is [count_chars8.cpp](count_chars8.cpp), which
counts characters in any number of files, and still has quite readable source
code.

[count_chars1.cpp](count_chars1.cpp) to [count_chars7.cpp](count_chars7.cpp)
are a step-by-step conversion of a non-objected oriented program that uses
global variables into an object-oriented one that can process *one or more*
files passed through the command-line. Here are what each file does:

- [count_chars1.cpp](count_chars1.cpp): Non-objected oriented word count
  program.

- [count_chars2.cpp](count_chars2.cpp): Global variables replaced by a `struct`.

- [count_chars3.cpp](count_chars3.cpp): `fstream` used to read file from the
  command-line.

- [count_chars4.cpp](count_chars4.cpp): File name read from command-line using
  `argc` and `argv`.

- [count_chars5.cpp](count_chars5.cpp): `fstream` object moved to inside the
  `struct`.

- [count_chars6.cpp](count_chars6.cpp): Uses a *constructor* to initialize
  `Count` objects.

- [count_chars7.cpp](count_chars7.cpp): Re-write of `main` to allow for multiple
  files to be passed as arguments.


### Discussion

As mentioned, [count_chars1.cpp](count_chars1.cpp) is already pretty good. It's
short, easy to read, and efficient. If it does what you need, then you don't
need to create the later versions.

Counting lines and tabs is just counting `\n` and `\t` characters. But counting
words is trickier, and relies on the observation that counting the chunks of
whitespace between words is the same as counting the words.
