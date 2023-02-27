# Assignment 3: To-do Lists

## Getting Started

In this assignment we're going to build a to-do list application using C++
classes. Don't go on to the next step until you've got the current step working
correctly.

## Part 1: The Base Program

### Step 1.1

In [a3.cpp](a3.cpp), write a program that prints "Welcome to assignment 3!". 

It should also #include the following:

```cpp
#include "cmpt_error.h"
#include <iostream>
#include <cassert>
```

[cmpt_error.h](cmpt_error.h) contains the function `cmpt::error(msg)` which,
when called, crashes your programs and prints `msg` on the screen. 

Other #includes will be used later in the assignment. **Only use the #includes
specified in the steps!** Don't include any other files.

All the code you write for this assignment will be in [a3.cpp](a3.cpp).

> **Note** Throughout this assignment, you do *not* need to check for invalid
> data. You can assume that your functions and methods will always be passed
> valid data. This is a simplification that isn't acceptable in real life, but
> we will allow it for his assignment since we want to focus on objects and
> classes instead of error-checking.

## Part 2: The Date Class

### Step 2.1: Create the Date Class

In [a3.cpp](a3.cpp), write a class called `Date` that inherits from the `Date_base`
class in [Date_base.h](Date_base.h):

```cpp
// ...
#include "Date_base.h"

class Date : public Date_base {
private:
  // ...

public:
  // ...
};
```

In the private part of `Date`, add variables for representing a day (1 to 31),
month (1 to 12), and year (0 or higher). Then add all the getters and setters
listed in `Date_base` (they're all `public`).

In the public part of `Date`, add a constructor that takes a day, month, and
year as input, and uses an *initializer list* to initialize the private
variables with the passed-in values.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_2_1_test()
{
    Date xmas(25, 12, 2018);

    cout << xmas.get_day() << " "
         << xmas.get_month() << " "
         << xmas.get_year() << "\n";

    assert(xmas.get_day() == 25);
    assert(xmas.get_month() == 12);
    assert(xmas.get_year() == 2018);

    xmas.set_year(2020);

    assert(xmas.get_day() == 25);
    assert(xmas.get_month() == 12);
    assert(xmas.get_year() == 2020);

    cout << "All step_2_1 tests passed!\n";
}
```

Call it in `main()` and compile and run your program to check the results:

```cpp
// ...

int main()
{
  cout << "Welcome to assignment 3!\n";

  step_2_1_test();
}
```

### Step 2.2: Add an Assignment Operator

**Note** Don't start this step until you've finished the previous one.

Uncomment the `operator=` method in [Date_base.h](Date_base.h). In it's body,
add code to assign the day, month, and year from the `other` object to the
current object. Finally, return the current object using `*this`.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_2_2_test()
{
    Date a(25, 12, 2018);
    Date b = a;

    assert(a.get_day() == 25);
    assert(a.get_month() == 12);
    assert(a.get_year() == 2018);

    assert(a.get_day() == b.get_day());
    assert(a.get_month() == b.get_month());
    assert(a.get_year() == b.get_year());

    b = Date(1, 1, 2019);
    a = b;

    assert(a.get_day() == 1);
    assert(a.get_month() == 1);
    assert(a.get_year() == 2019);

    assert(a.get_day() == b.get_day());
    assert(a.get_month() == b.get_month());
    assert(a.get_year() == b.get_year());

    cout << "All step_2_2 tests passed!\n";
}
```

Call it in `main()` and compile and run your program to check the results:

```cpp
// ...

int main()
{
    cout << "Welcome to assignment 3!\n";

    step_2_1_test();
    step_2_2_test();
}
```

You should still call the previous test function, just in case you made a change
that broke some previous code.

### Step 2.3: Add to_string

**Note** Don't start this step until you've finished the previous one.

Uncomment the `to_string()` method in [Date_base.h](Date_base.h). The string
returned by `to_string` has this *exact* format: "dd/mm/yyyy". For example, if
your date object represents May 19 2001, then `to_string` returns
`"19/05/2001"`. The returned string will always be exactly 10 characters long.
The day and month will always be exactly two digits, and the year will always be
exactly four digits.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_2_3_test()
{
    Date a(25, 12, 2018);
    Date b(4, 19, 1999);
    Date c(1, 1, 0);

    assert(a.to_string() == "25/12/2018");
    assert(b.to_string() == "04/19/1999");
    assert(c.to_string() == "01/01/0000");

    cout << "All step_2_3 tests passed!\n";
}
```

Call it in `main()` and compile and run your program to check the results:

```cpp
int main()
{
    cout << "Welcome to assignment 3!\n";
    step_2_1_test();
    step_2_2_test();
    step_2_3_test();
}
```

### Step 2.4: Add a Constructor from a String

**Note** Don't start this step until you've finished the previous one.

Add another constructor to your `Date` that takes a string as input. The string
is a date that has *exactly* the same format as the output of `to_string`. For
example, `Date("25/12/2018")` creates a date object with day 25, month 12, and
year 2018.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_2_4_test()
{
    Date a("25/12/2018");
    Date b("04/19/1999");
    Date c("01/01/0000");

    assert(a.get_day() == 25);
    assert(a.get_month() == 12);
    assert(a.get_year() == 2018);

    assert(b.get_day() == 4);
    assert(b.get_month() == 19);
    assert(b.get_year() == 1999);

    assert(c.get_day() == 1);
    assert(c.get_month() == 1);
    assert(c.get_year() == 0);

    cout << "All step_2_4 tests passed!\n";
}
```

Call it in `main()` and compile and run your program to check the results:

```cpp
int main()
{
    cout << "Welcome to assignment 3!\n";
    step_2_1_test();
    step_2_2_test();
    step_2_3_test();
    step_2_4_test();
}
```

### Step 2.5: Add a Comparison Operator

**Note** Don't start this step until you've finished the previous one.

Sorting dates from earliest to latest is a useful feature that we want to
support. The standard C++ `sort` function can sort `Date` objects if we
implement `operator<` for `Date`:

```cpp
bool operator<(const Date& a, const Date& b) {
    // ...
}
```

This function should return `true` if the date `a` is earlier than the date `b`,
and `false` otherwise.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_2_5_test()
{
    Date a("01/01/0000");
    Date b("01/01/2018");
    Date c("02/01/2018");
    Date d("01/02/2018");

    assert(a < b);
    assert(a < c);
    assert(a < d);
    assert(b < c);
    assert(b < d);
    assert(c < d);

    assert(!(a < a));
    assert(!(b < a));
    
    cout << "All step_2_5 tests passed!\n";
}
```

Call it in `main()` and compile and run your program to check the results:

```cpp
int main()
{
    cout << "Welcome to assignment 3!\n";
    step_2_1_test();
    step_2_2_test();
    step_2_3_test();
    step_2_4_test();
    step_2_5_test();
}
```


## Part 3: The Todo_item Class

### Step 3.1: Create the Todo_item Class

In [a3.cpp](a3.cpp), underneath the code you wrote for `Date`, write a class
called `Todo_item` that inherits from the `Todo_item_base` class in
[Todo_item_base.h](Todo_item_base.h):

```cpp
// a3.cpp

// ...
#include "Todo_item_base.h"

// ... code for Date ...

class Todo_item : public Todo_item_base {
private:
  // ...

public:
  // ...
};
```

In the private part of `To_do_item`, add the variables for the item's due date
(use the `Date` class you just wrote), a `string` description (such as "study
for midterm"), and whether or not it has been completed (an item is either
completed, or not completed).

In the public part of `To_do_item`, add a constructor that takes a `string`
description and `Date` due date as input. Use those to initialize the variables
in the private part using an *initializer list*. The item should always be
initialized as not done.

Then add all the getters and setters, as listed in `Todo_item_base`.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_3_1_test()
{
    Date xmas(25, 12, 2018);
    Todo_item buy_gifts("Buy gifts", xmas);

    assert(buy_gifts.get_description() == "Buy gifts");
    assert(buy_gifts.get_due_date().get_day() == xmas.get_day());
    assert(buy_gifts.get_due_date().get_month() == xmas.get_month());
    assert(buy_gifts.get_due_date().get_year() == xmas.get_year());
    assert(!buy_gifts.is_done());

    buy_gifts.set_done();
    assert(buy_gifts.is_done());
    buy_gifts.set_not_done();
    assert(!buy_gifts.is_done());

    Date earlier(20, 12, 2018);
    buy_gifts.set_due_date(earlier);
    assert(buy_gifts.get_due_date().get_day() == earlier.get_day());
    assert(buy_gifts.get_due_date().get_month() == earlier.get_month());
    assert(buy_gifts.get_due_date().get_year() == earlier.get_year());

    buy_gifts.set_description("Buy gifts for family");
    assert(buy_gifts.get_description() == "Buy gifts for family");

    cout << "All step_3_1 tests passed!\n";
}
```

Call it in `main()` to check the results. Make sure to also call all previous
tests in `main()`.

### Step 3.2: Add to_string

Uncomment the `to_string` method in [Todo_item_base.h](Todo_item_base.h). In
it's body, add code to that creates and returns a string representation of the
item. It should have this format: "dd/mm/yyyy? description". The first 10
characters are the due date (from `Date::to_string`). The ? is either the
character `@` (meaning the item *is* done), or the character `!` (meaning the
item is *not* done). Then there is one space, followed by a description that
continues to the end of the line.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_3_2_test()
{
    Date xmas(25, 12, 2018);
    Todo_item buy_gifts("Buy gifts", xmas);

    assert(buy_gifts.to_string() == "25/12/2018! Buy gifts");

    buy_gifts.set_done();
    assert(buy_gifts.to_string() == "25/12/2018@ Buy gifts");

    cout << "All step_3_2 tests passed!\n";
}
```

Call it in `main()` to check the results. Make sure to also call all previous
tests in `main()`.

### Step 3.3: Add to_html

Uncomment the `to_html` method in [Todo_item_base.h](Todo_item_base.h). In its
body, write code that creates and returns a string that can be used as an item
in an HTML. The returned string has one of these formats:

- `<li>dd/mm/yyyy description</li>` if the item is not done.

- `<li><del>dd/mm/yyyy description</del></li>` if the item is done.

In both cases, the string is wrapped by `<li>` and `</li>` tags. If the item is
done, use `<del>`/`</del>` tags to draw a line through the text when displayed
in HTML. If the item is not done, then don't use `<del>` tags.

Notice that there is *no* `@` or `!` character after the date in the output
of `to_html`.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_3_3_test()
{
    Date xmas(25, 12, 2018);
    Todo_item buy_gifts("Buy gifts", xmas);

    assert(buy_gifts.to_html_item() == "<li>25/12/2018 Buy gifts</li>");

    buy_gifts.set_done();
    assert(buy_gifts.to_html_item() == "<li><del>25/12/2018 Buy gifts</del></li>");

    Date easter(21, 4, 2019);
    Todo_item weave_basket("Weave basket", easter);

    assert(weave_basket.to_html_item() == "<li>21/04/2019 Weave basket</li>");

    weave_basket.set_done();
    assert(weave_basket.to_html_item() == "<li><del>21/04/2019 Weave basket</del></li>");

    cout << "All step_3_3 tests passed!\n";
}
```

Call it in `main()` to check the results. Make sure to also call all previous
tests in `main()`.

### Step 3.4: Add operator<

Implement `operator<` for `Todo_item`. When comparing two items, only the *due
date* is used in the comparison (the description and completed status are
ignored). So if `a` and `b` are `Todo_item`s, then `a < b` is true if the due
date of `a` is *before* the due date of `b`, and false otherwise.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_3_4_test()
{
    Date halloween(31, 10, 2018);
    Date xmas(25, 12, 2018);
    Date easter(21, 4, 2019);

    Todo_item carve_pumpkin("Carve pumpkin", halloween);
    Todo_item buy_gifts("Buy gifts", xmas);
    Todo_item weave_basket("Weave basket", easter);

    assert(carve_pumpkin < buy_gifts);
    assert(buy_gifts < weave_basket);
    assert(carve_pumpkin < weave_basket);

    assert(!(carve_pumpkin < carve_pumpkin));

    assert(!(buy_gifts < carve_pumpkin));
    assert(!(weave_basket < buy_gifts));
    assert(!(weave_basket < carve_pumpkin));

    cout << "All step_3_4 tests passed!\n";
}
```

Call it in `main()` to check the results. Make sure to also call all previous
tests in `main()`.

### Step 3.5: Add a Constructor from a String

Add another constructor to `Todo_item` that takes a string as input. The string
is formatted *exactly* the same as the output of `Todo_item::to_string`. For
example, `Todo_item("25/12/2018! Buy gifts")` creates a `Todo_item` with the due
date 25/12/2018, the description "Buy gifts", and a completion status of not
done.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_3_5_test()
{
    Todo_item a("01/01/0000@ buy a hamster");
    assert(a.get_description() == "buy a hamster");
    assert(a.get_due_date().get_day() == 1);
    assert(a.get_due_date().get_month() == 1);
    assert(a.get_due_date().get_year() == 0);
    assert(a.is_done());

    Todo_item b("01/01/2018! sell hamster");
    assert(b.get_description() == "sell hamster");
    assert(b.get_due_date().get_day() == 1);
    assert(b.get_due_date().get_month() == 1);
    assert(b.get_due_date().get_year() == 2018);
    assert(!b.is_done());

    assert(a < b);
    assert(!(b < a));

    cout << "All step_3_5 tests passed!\n";
}
```

## Part 4: The Todo_list Class

### Step 4.1: Create the Todo_list Class

In [a3.cpp](a3.cpp), write a class called `Todo_list` that inherits from the
`Todo_list_base` class in [Todo_list_base.h](Todo_list_base.h):

```cpp
// ...
#include "Todo_list_base.h"

class Todo_list : public Todo_list_base {
private:
  // ...

public:
  // ...
};
```

In the private part of `Todo_list`, add variables for storing 0 or more
`Todo_item`s. If you use a `vector` to do this, make sure to add `#include
<vector>` to the list of includes at the top of the file.

In the public part of `Todo_list`, add a *default* constructor that creates a
`Todo_list` with no items (size 0). Also, implement all the getters and setters
listed in `Todo_list_base.h`.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_4_1_test()
{
    Date easter(21, 4, 2018);
    Date halloween(31, 10, 2018);

    Todo_item weave_basket("Weave basket", easter);
    Todo_item carve_pumpkin("Carve pumpkin", halloween);

    Todo_list list;
    assert(list.size() == 0);

    list.add_item(weave_basket);
    assert(list.size() == 1);
    Todo_item item = list.get_item(0);
    Date date = item.get_due_date();
    assert(item.get_description() == weave_basket.get_description());
    assert(date.get_day() == weave_basket.get_due_date().get_day());
    assert(date.get_month() == weave_basket.get_due_date().get_month());
    assert(date.get_year() == weave_basket.get_due_date().get_year());

    list.add_item(carve_pumpkin);
    assert(list.size() == 2);
    list.remove_item(0);
    assert(list.size() == 1);
    item = list.get_item(0);
    date = item.get_due_date();
    assert(item.get_description() == carve_pumpkin.get_description());
    assert(date.get_day() == carve_pumpkin.get_due_date().get_day());
    assert(date.get_month() == carve_pumpkin.get_due_date().get_month());
    assert(date.get_year() == carve_pumpkin.get_due_date().get_year());

    list.remove_item(0);
    assert(list.size() == 0);

    cout << "All step_4_1 tests passed!\n";
}
```

### Step 4.2: Add Reading from a File

Uncomment the `read_from_file` method in [Todo_list_base.h](Todo_list_base.h),
and then implement it in [a3.cpp](a3.cpp). The method reads the contents of
`filename`, adding each item to the list. If the file does not exist, it should
do nothing and no change is made to the list.

Each line of `filename` is formatted exactly the same as the output of
`Todo_item::to_string`. [todo_example.txt](todo_example.txt) is an example of
such a file. It contains 11 `Todo_item`s, and is used in the tests below.

Add `#include <fstream>` to the list of includes at the top of your
[a3.cpp](a3.cpp).

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_4_2_test()
{
    Todo_list list;
    list.read_from_file("todo_example.txt");
    assert(list.size() == 11);

    // 13/02/2023! optometrist in afternoon
    Todo_item eyes("optometrist in afternoon", Date(13, 2, 2023));

    Todo_item item = list.get_item(0);
    Date date = item.get_due_date();
    assert(item.get_description() == eyes.get_description());
    assert(date.get_day() == eyes.get_due_date().get_day());
    assert(date.get_month() == eyes.get_due_date().get_month());
    assert(date.get_year() == eyes.get_due_date().get_year());

    cout << "All step_4_2 tests passed!\n";
}
```

### Step 4.3: Add Writing to a File

Uncomment the `write_to_file(filename)` method in
[Todo_list_base.h](Todo_list_base.h). When called, it should first sort the
items by due date (earliest to latest), and then write each of those due dates
to `filename`. If the file does not exist, it should create it. If the file
already exists, then it will get over-written (be careful!).

The output of `write_to_file` should be formatted in exactly the same style as
[todo_example.txt](todo_example.txt). That way, you can read the file back in
using `read_from_file`.

Similarly, uncomment `write_to_html_file(filename)` in
[Todo_list_base.h](Todo_list_base.h). When called, it first sorts the items by
due date (earliest to latest), and then writes each of them to `filename` using
their `to_html_item`. Also, the first line of the file is the HTML tag `<ul>`,
and the last line is `</ul>`.

Add `#include <algorithm>` to the list of includes at the top of your
[a3.cpp](a3.cpp) so that you can use the standard C++ `sort` function.

Test what you've done by adding this function to [a3.cpp](a3.cpp):

```cpp
void step_4_3_test()
{
    Todo_list list;

    list.add_item(Todo_item("Buy tinsel", Date(20, 12, 2018)));
    list.add_item(Todo_item("21/04/2018@ Weave basket"));
    list.add_item(Todo_item("Carve pumpkin", Date(31, 10, 2018)));

    list.write_to_file("step_4_3_output.txt");
    list.write_to_html_file("step_4_3_output.html");

    // read step_4_3_output.txt back in and compare to list
    Todo_list list2;
    list2.read_from_file("step_4_3_output.txt");
    assert(list2.size() == 3);
    assert(list2.get_item(0).get_description() == "Weave basket");
    assert(list2.get_item(1).get_description() == "Carve pumpkin");
    assert(list2.get_item(2).get_description() == "Buy tinsel");
    
    assert(list2.get_item(0).get_due_date().get_day() == 21);
    assert(list2.get_item(0).get_due_date().get_month() == 4);
    assert(list2.get_item(0).get_due_date().get_year() == 2018);

    assert(list2.get_item(1).get_due_date().get_day() == 31);
    assert(list2.get_item(1).get_due_date().get_month() == 10);
    assert(list2.get_item(1).get_due_date().get_year() == 2018);

    assert(list2.get_item(2).get_due_date().get_day() == 20);
    assert(list2.get_item(2).get_due_date().get_month() == 12);
    assert(list2.get_item(2).get_due_date().get_year() == 2018);

    assert(list2.get_item(0).is_done() == true);
    assert(list2.get_item(1).is_done() == false);
    assert(list2.get_item(2).is_done() == false);

    cout << "All step_4_3 tests run: check the HTML results by hand!\n";
}
```

Here are the output files created by the test: [step_4_3.txt](step_4_3.txt),
[step_4_3.html](step_4_3.html). Make sure to manually check that
[step_4_3.html](step_4_3.html) looks correct.


## Part 5: The Final Program

As a final test of your [a3.cpp](a3.cpp), write and test a `void` function
called `part5()` that reads the file [part5_todos.txt](part5_todos.txt) and then
prints this:

```
done: 476
not done: 524
oldest: 05/01/2018@ freeze-dry magnet-shaped green orange
newest: 28/12/2023@ defrost large yellow cherry
```

Print the output *exactly* in this format.

In addition, make a file called `final_output.txt` created by a call to
`write_to_file`. And make a file called `final_output.html` created by a call to
`write_to_html_file`.

When your `part5()` function is tested, the contents of `part5_todos.txt` will
behave the same format as [todo_example.txt](todo_example.txt), but the content
of the todos, and number of todos, may be different.


## Submit Your Work

Please put all your code into [a3.cpp](a3.cpp), and submit it on Canvas.
Implement **all** the methods and functions exactly as described, otherwise the
marking software will probably give you 0!

The only file you submit is [a3.cpp](a3.cpp): *don't* submit any other files.
The marker will use the standard [makefile](makefile) to compile it, and copies
of [cmpt_error.h](cmpt_error.h) and [Date_base.h](Date_base.h),
[Todo_item_base.h](Todo_item_base.h), and [Todo_list_base.h](Todo_list_base.h)
will be in the same folder as [a3.cpp](a3.cpp) when it's compiled and tested.


## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using the standard course
  [makefile](makefile):

  ```
  $ make a3
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   a3.cpp   -o a3
  ```

  If your program fails to compile, your mark for this assignment will be 0.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as
  [a3.cpp](a3.cpp) when it's compiled, so your program can use `cmpt::error` if
  necessary.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:

  ```
  $ valgrind ./a3

  // ... lots of output ...
  ```

  A program is considered to have no memory error if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non-zero number of
    bytes.

- **You must include the large comment section with student info and the
  statement of originality**. If your submitted file does not have this, then
  we will assume your work is not original and it will not be marked.

If your program meets all these basic requirements, then it will graded using
the marking scheme on Canvas.

## Marking Scheme

### **Overall source code readability: 5 marks**

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

### **Overall source code performance and memory usage: 2 marks**

- No unnecessary work is done.
- No unnecessary memory is used.

### **Source code correctness: 18 marks**

To get full marks, your functions must pass all the test cases the marker uses
for that question. The marker may use test cases not given in the assignment.

- **1 mark** for correct code for each of 2.1, 2.2, 2.3, 2.4, and 2.5
- **1 mark** for correct code for each of 3.1, 3.2, 3.3, 3.4, and 3.5
- **1 mark** for correct code for each of 4.1, 4.2, 4.3
- **5 marks** for part 5, for printing the correct number todos that are done
  and not done, and the oldest and newest todos. Also, both `final_output.txt`
  and `final_output.html` are correctly printed.


### Deductions

- **-1 mark** (at least) if your file does not have the correct name, or you
  submit it in the incorrect format, submit the wrong file, etc.
- up to **-3 marks** if you do not include your full name, email, and SFU ID in
  the header of your file.
- **a score of 0** if you don't include the "statement of originality in the
  header of your file.
- **a score of 0** if you accidentally submit a "wrong" non-working file, and
  then *after the due date* submit the "right" file. If you can provide evidence
  that you finished the assignment on time, then it may be marked (and probably
  with a late penalty).
