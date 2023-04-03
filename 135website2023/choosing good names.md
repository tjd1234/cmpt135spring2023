How should a programmer choose names for variables, functions, classes, files, and so on? One old idea [[Hungarian notation]], which adds the *type* of a variable to its name. However, it is no longer popular. 

In general, choosing good names is tricky. It takes experience to make good choices. 

Here are a few rules of thumb to keep in mind for variables (similar
considerations apply for functions, classes, files, etc.):

- Variable names should be **self-descriptive**, e.g. a programmer who didn't
  write the program should be able to make a reasonable guess about the
  *purpose* of a variable from looking at the name alone.
- Variable name *length* can be tricky:
  - Longer names are good when a variable needs a name that is very
    self-descriptive.
  - Shorter names are good when you must use the same variable many times in
    some code. Longer names can make the code harder to format and read.
    Compare:
    ```cpp
    n*n + 5*n - 1 

    num_opened_files * num_opened_files + 5 * num_opened_files - 1
    ```

    `num_opened_files` is more descriptive than `n`, but it is so long
    that it obscures the structure of the expression.

- Use standard variable names. For example, `i` and `j` are often the
  variables used as a loop index, and `x` and `y` are standard names for
  for 2-dimensional coordinates.
- Use a consistent style for separating the parts of a name. For example, you
  could use `_` characters, e.g. `base_work_rate`. Or instead you could
  use capitalization, e.g. `baseWorkRate`.

  Different programmers have different preferences. It's usually best to be
  consistent: pick one style and stick with it.
- Some programming languages give special meanings to certain kinds of names.
  For example, in the [Go programming
  language](https://en.wikipedia.org/wiki/Go_(programming_language)), a
  capitalized name means the name is public, and can be accessed by code
  outside the current package. In the [Haskell
  language](https://en.wikipedia.org/wiki/Haskell_(programming_language)),
  capitalized names refer to types, while lowercase names refer to
  variables/functions.

  C++ has a few rules for variable names, e.g.:

  - A C++ variable name can't contain certain symbols, such as `' '`,
    `','`, `'.'`, etc.

  - A C++ variable name cannot start with a digit.

  - A C++ variable name can't be the same as a keyword, e.g. you can't use
    `if` or `while` as  variable name.
