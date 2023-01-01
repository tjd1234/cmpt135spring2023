# Sample Questions

## Recursive Linear Search

Implement a function called `linear_search(x, v)` that searches for the `int`
`x` in the `vector<int>` `v`. If `x` is in `v`, then the index of the left-most
occurrence of `x ` is returned. If `x` is not in `v`, then -1 is returned. For
example:

- `linear_search(7, {2, 7, 4, 7, 1})` returns 1

- `linear_search(3, {2, 7, 4, 7, 1})` returns -1

Use recursion for your implementation. *Don't* use any loops, STL functions, or
C++ tricks not covered in the course. You can use help functions if you like.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.

## Checking if a vector<int> is Sorted

Implement a function called `is_sorted(v)` that returns `true` if `v` is in
ascending sorted order, and `false` otherwise. For example:

- `is_sorted({})` returns `true`

- `is_sorted({9})` returns `true`
- `is_sorted({1, 9})` returns `true`
- `is_sorted({9, 1})` returns `false`
- `is_sorted({9, 9})` returns `true`
- `is_sorted({1, 9, 10, 34, 34, 35})` returns `true` 
- `is_sorted({9, 10, 34, 34, 35, 1})` returns `false`

Implement two different versions of `is_sorted`: one using loops, and one using
recursion.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Checking for Duplicates in a vector<int>

Write a function called `all_diff(v)` that returns `true` if there are no
duplicate elements in `v`, and `false` if there are. For example:

- `all_diff({})` returns `true`
- `all_diff({6})` returns `true`
- `all_diff({9, 1, 3})` returns `true`
- `all_diff({9, 1, 9})` returns `false`

Implement `all_diff` in two different ways:

1. Using a loop within a loop to test all different pairs of `int`s.

2. Sorting a copy of the vector, and then using a variation of linear search on
   this sorted vector to look for adjacent `int`s that are the same. If the
   original vector has any duplicates, then they will end up beside each other
   in the sorted version.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Pluralizing Strings

a) Write a function called `pluralize` that takes a single string `s` as input,
   and returns new `string` that is the *plural* of `s`. Use these rules for
   pluralization:

   1. The plural of the empty string `""` is `""`.
   
   2. If the last character of `s` is `'s'`, then a copy of `s` unchanged is
      returned. For example, `pluralize("dogs")` returns `"dogs"`.

   3. If the last character of `s` is `'y`', then return a copy of `s` but with
      that last `'y'` replaced by the string `"ies"`. For example,
      `pluralize("try")` returns `"tries"`.
   
   4. If the last character of `s` is a letter other than `'s'` or `'y'`, then
      return a copy of `s` with `'s'` added to the end. For example,
      `pluralize("train")` returns `"trains"`.

   For simplicity, assume the passed-in string `s` contains only the lowercase
   letters a to z.

   Also write an automated unit test, using `assert` or if-statements, to test
   that `pluralize` is correct.

b) Write a function called `pluralize_all(v)`, where `v` is a `vector<string>`,
   that returns a copy of `v` with every string pluralized using the `pluralize`
   function from above.

   Also write an automated unit test, using `assert` or if-statements, to test
   that `pluralize_all` is correct.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Joining the Elements of a vector<T>

Write a function called `join(v, sep)`, where `v` is a `vector<T>` and `sep` is
a `string`, that returns a string consisting of all the elements in `v`
separated by the string `sep`. You can assume the type `T` can be passed to the
standard string conversion function `to_string`.

If `v` is empty, join returns the empty string. If `v` has a single element,
join returns just that element (with no separator).

For example:

- `join({}, ", ")` returns `""`

- `join({15}, ", ")` returns `"15"`

- `join({15, -2}, ", ")` returns `"15, -2"`

- `join({15, -2, 6}, "::")` returns `"15::-2::6"`

- `join({"one", "two", "three"}, "...")` returns `"one...two...three"`

For this last example to work you may need to write your own `to_string`
function for strings:

```cpp
string to_string(const string& s) { return s; }
```

Also write an automated unit test, using `assert` or if-statements, to test that
`join` is correct.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Removing All Given Numbers in a vector<int>

Write a function called `remove_all(v, x)` returns a new `vector<int>` that is
the same as `v` except that all occurrences of `x` in `v` have been removed.
*Don't* modify the passed-in vector.

For example:

- `remove_all({3, 9, 0, 3, 2, 2, -3}, 3)` returns `{9, 0, 2, 2, -3}`

- `remove_all({1, 2, 3}, 4)` returns `{1, 2, 3}`

- `remove_all({4, 4}, 4)` returns `{}`

Also write an automated unit test, using `assert` or if-statements, to test that
`remove_all` is correct.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Searching for Vowels

1. Write a function called `is_vowel(c)` that returns `true` when `c` is a
   vowel, and `false` otherwise. A vowel is defined to be any character in the
   string `"aeiouAEIOU"`.

2. Using `is_vowel`, write a function called `has_vowel(s)` that returns true if
   the string `s` contains one, or more, vowels. For example, `has_vowels('Hi!)`
   returns `true`, and `has_vowels("Grrr!")` returns `false`.

3. Using `has_vowels`, write a function called `keep_vowels(v)` that returns a
   new `vector<string>` that is the same as `v`, except any strings with no
   vowels have been removed. For example, `keep_vowels({"apple", "grr", "fly",
   "orange"})` returns the new `vector<string>` `{"apple", "orange"}`.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## The Same Strings in Different vectors

1. Write a function called `contains(v, s)` that returns `true` when `string`
   `s` occurs one, or more, times in the `vector<string>` `v`, and `false`
   otherwise.

2. Write a function called `intersection(v, w)` that returns a new
   `vector<string>` of all the elements that occur in both `v` and `w`. For
   example, `intersection({"up", "down", "left"}, {"right", "down", "a", "up"})`
   returns `{"up", "down"}`.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.


## Equality When Order Doesn't Matter

Two vectors are said to be the *same* if they have the same elements, but not
necessary in the same order. For example, `{3, 4, 1}` and `{4, 3, 1}` are the
same.

1. Write a function called `same1(v, w)` that returns `true` when vectors `v`
   and `w` are the same, and `false` otherwise. Implement it using templates so
   that it works for at least `vector<int>` and `vector<string>`, and implement
   by checking that both of these things are true:
   
   - Every element in `v` also occurs in `w`.
   - Every element in `w` also occurs in `v`. 

2. Re-do the previous questions for a function called `same2(v, w)`, but this
   time do it by sorting copies of `v` and `w` (don't modify the originals!) and
   then checking if the sorted copies are equal.

3. Assuming `v` and `w` both have *n* items, what is the worst-cast O-notation
   expression describing the number of comparisons done by:

   - `same1(v, w)` ?

   - `same2(v, w)` ?
   
   In both cases, give the *tightest* O-notation expression for the worst-case
   number of comparisons.

See [sample_questions.cpp](sample_questions.cpp) for example solutions.
