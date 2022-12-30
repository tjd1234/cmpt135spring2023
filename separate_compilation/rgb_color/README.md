Code for notes on separate compilation of the `RGB_color` class.

[RGB_color_allInOne.cpp](RGB_color_allInOne.cpp) contains all code in the
`RGB_color` class, along with a `main()` function.

[RGB_color_split.cpp](RGB_color_split.cpp) is a single file with a
*declaration* of `RGB_color`, followed by definitions of its methods. It also
contains a `main()` function.

[RGB_color.h](RGB_color.h), [RGB_color.cpp](RGB_color.cpp), and
[color_test.cpp](color_test.cpp) is the separate compiled version of
`RGB_color`. The `main()` function appears only in `color_test`. Use these
commands to compile and run `color_test`:

```bash
$ g++ -c RGB_color.cpp
$ g++ -c color_test
$ g++ -o color_test color_test.o RGB_color.o
```
