#terminology

## Definition
An extreme value test case is a [[test]] where the [[test input]] or test output is in some way *extreme*, e.g. near the end of a numeric range, very large or very small, etc. Extreme values are often good at uncovering subtle bugs.

## Example
Here are a few extreme value that can be used for testing:
- for integer types: -1, 0, 1, max int, min int, ...
- for floating point types: -1.0, 0.0, max float, min float, smallest positive float (sometimes called **machine epsilon**), ...
- for strings: `""` (the empty string), `"a"` (a string with one character), `"       "` (all spaces), a very large string (e.g. 10,000 or more characters), ...

If you happen to know more about what `f` is supposed to do, then there could
be other extreme values. For example, if you are testing `f(int n)` and know
that `n` should be in the range 1 to 100, then some extreme values would be 0,
1, 2, 99, 100, and 101.

If you have a function `g(m, n)` that takes two inputs `m` and `n`, and `m`
has 5 extreme values and `n` has 4 extreme values, then altogether there $`5
\cdot 4 = 20`$ pairs of of extreme values that you can test `g` with.