## Example: Counting Words in a Text File

The `.cpp` files in this directory give a step-by-step transformation of
[count_chars1.cpp](count_chars1.cpp) to a more general-purpose object-oriented
version called [count_chars7.cpp](count_chars7.cpp) counts characters in any
number of files, and still has quite readable source code.

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
