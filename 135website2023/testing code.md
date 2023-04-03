## Introduction
How do you know if a function works correctly? In practice, the most common way of doing this is to give the function an input and then to verify that it returns the correct output for that input. We call this **testing**.

For example, the `quote(s)` function returns a copy of `s` in ""-marks:

```cpp
string quote(const string& s) {
	return "\"" + s + "\"";
}
```

We can see that this function is obviously correct by looking at it, but let's see how we could test it.

To test `quote`, we need to think of input values and the corresponding correct output values. For example, here are three tests for `quote`:

- `quote("cat")` returns `"\"cat\""`
- `quote("hot soup")` returns `"\"hot soup\""`
- `quote("")` returns `"\"\""`

## If-style tests
One way to *automatically* test `quote` is with a series of if-statements like this:

```cpp
void test_quote_if_style() {
	if (quote("cat") != "\"cat\"") cout << "test failed";
	if (quote("hot soup") != "\"hot soup\"") cout << "test failed";
	if (quote("") != "\"\"") cout << "test failed"; 
}
```

A feature of this kind of testing is that it's flexible. In our example we print a message, but you could print a more detailed message, or save the results in a file, or do anything else you like.

## Assert-style Tests
Another way is like this:

```cpp
#include <cassert>     // assert is from here

void test_quote_assert_style() {
    assert(quote("\"cat\"") == "\"cat\"");
    assert(quote("hot soup") == "\"hot soup\"");
    assert(quote("") == "\"\"");
    cout << "all quote tests passed\n";
}
```

`assert(bool_expr)` is a standard C++ *macro* that works as follows:
- if `bool_expr` evaluates to `false`, then we say the assert *failed*. When an assert fails the program immediately crashes with a message saying the line number of the failed assert.
- If `bool_expr` evaluates to `true`, then we say the assert *succeeded*, and *nothing* is done.

Since a failed assert will crash the program, the "all quote tests passed" message at the end of the function will only be printed when, in fact, all the asserts succeeded.

The assert-style testing is clearly shorter than the if-style tests, and so it is preferred by many programmers. One advantage of if-style tests is that you can make more elaborate failure methods, or even print messages upon success.

> **Note** `assert` is a [[macro]], *not* a function. In C++, when you call a function it first evaluates the arguments given to the function, and then passes those values to the function body. A macro passes the argument to the function *unevaluated*, and this is why `assert` is able to show the exact input in its print-out when it fails. If `assert` were a function, it would only be able to print `false`.
>
> In general, you should avoid macros in C++ since they don't follow the same rules as functions (e.g. they can't do type-checking on the arguments) and can have subtle bugs. `assert` is a special case because we want to see the exact expression when the assertion fails. 

## Table-style Testing
Another way to test `quote` is like this:

```cpp
struct Test {
	string input;
	string expected_output;
};

void test_quote_table_style() {
	vector<Testcase> all_tests = {
		Testcase{"cat", "\"cat\""},
		Testcase{"hot soup", "\"hot soup\""},
		Testcase{"", "\"\""},
	};

	for(Testcase tc : all_tests) {
		string actual = quote(tc.input);
		if (actual != expected) {
			cout << "test failed\n";
		}
	}
}
```

Table-style testing is a little more work to set-up than the other kinds of testing we've seen, but an advantage is that it is easy to add new tests cases.

## Testing Terminology

[[Unit testing]] is testing done to a single function (or some other small "unit" of code) independent of the program it is part of. [[System testing]] is when you test an entire program. One of the difficulties with [[system testing]] is that it can't be done until the system is finished, or at least in a usable state. 

In practice, it is common for programmers to do [[unit testing]] at the same time as they write their program. You mix writing code with testing: you write some code, test it, write some more code, test it, and so on. By the time you've written the function, you have also tested it, giving more confidence in its correctness. Mixing testing and writing code is known as [[test-driven development]].

There are two basic ways of coming up with test cases. If you create a test case for a function by considering just its header and purpose (and ignoring its implementation), that's called [[blackbox testing]]. For example, consider this function:

```cpp
// returns a copy of with leading and trailing
// space characters removed
string trim(const string& s) {
	// ...
}
```

Without seeing the body of the function, we can come up with some tests cases:

- `trim("  hello ")` returns `"hello"`
- `trim("nail")` returns `"nail"`
- `trim("   ")` returns `""`
- `trim("")` returns `""`

This shows it's possible to write tests *before* implementing a function. An advantage of this approach is that it can help you better understand how the function works, making it a little easier to implement.

[[Whitebox testing]] is when you create test cases by looking at functions header, purpose, *and* implementation. This way you can pick test cases that cause every line of the function to be executed at least once. For example:

```cpp
// returns a message describing temperature t
string describe_temp(double t) {
	if (t < 0.0) cout << "very cold";
	else if (t == 0.0) cout << "water freezes";
	else if (t < 10.0) cout << "not too cold";
	else if (t == 100.0) cout << "water boils";
	else cout << "hot"; 
}
```
Using [[whitebox testing]], we come up with test cases that execute each branch of the if-statement:
- `describe_temp(-1.0)` returns `"very cold"`
- `describe_temp(0.0)` returns `"water freezes"`
- `describe_temp(5.0)` returns `"not too cold"`
- `describe_temp(100.0)` returns `"water boils"`
- `describe_temp(11.0)` returns `"hot"`

In general, [[blackbox testing]] tends to be preferable to [[whitebox testing]] because blackbox test cases will still work even if you change the implementation of the function. The [[whitebox testing]] test cases might be less useful with different implementations.

Another useful distinction is [[automated testing]] versus [[manual testing]]. In [[manual testing]] you test your function by hand, and visually verify that the output is correct. While this is fine for a  few test cases, or visual output (like graphics), in practice it quickly becomes tedious and programmers start to cut corners, make mistakes, or just not do it.

In contrast, [[automated testing]] is when you write a test function to automatically call the function being tested and to automatically check that its output is correct. No human intervention is needed other than to run the test functions, and do something if any tests fail.

In general, [[automated testing]] is much preferred to [[manual testing]]. It is more work, but overall it can save time by decreasing the amount of time you spend debugging.

## How Many Test Cases is Enough?
Good question!

Generally, you want to **do the least amount of testing necessary to make you confident that your function works correctly in all important cases**.

For some functions, it might be possible to do [[exhaustive testing]] (aka [[exhaustive testing|brute force testing]]), i.e. test *all* possible inputs and outputs, e.g.:

```cpp
// if a and b are different, then true is returned; 
// otherwise, false is returned
bool exclusive_or(bool a, bool b);
```

`exclusive_or` only has 4 possible different inputs, so we can easily test them all.

But more typically, functions have far more input values than could ever be practically tested. For example:

```cpp
// if a and b are different, then true is returned; 
// otherwise, false is returned
int sum(const vector<int>& v);
```

Assuming an `int` is 32 bits, and that, say, `v` could have as many as 2 billion elements, then there are $32 \cdot 2 \;\textrm{billion} = 64$ billion *bits* of input to `sum`, which means there are $2^{64}$ billion possible input vectors. This is an astronomical amount --- there's no way to test that many different cases!

This example shows that **testing doesn't catch all bugs**. Just because a function passes all tests doesn't mean it is correct in every case --- it's always possible that a case you didn't test for has a bug.

## Bugs that Testing has a Hard Time Catching
An important aspect of testing is that we can only test a function when we *know what it is supposed to do*. For example, consider this function:

```cpp
int f(int n) {
	return n + 1;
}
```

Does `f` have a bug? It's impossible to know, since we don't know what `f` is *supposed* to do. If `f` is *supposed* to return `n+1`, then it's correct. But if it is *supposed* to return `n+5`, then it has a bug. We can't test `f` because we don't know what the correct output of it is.

Here's another unusual function:

```cpp
// meant to always return 3, but has a bug
int three() {
  if (rand() == 0) {
    return 2;
  } else {
    return 3;
  }
}
```

`three()` *almost always* returns 3, as expected.

But every once in a (usually) long while, it returns 2 --- which is incorrect. For 32 bit `int`s, you'd expect about 1 out of every $2^{31}$ calls to `three()` to return the wrong result

> **Note** $2^{31} = 2147483648$, i.e. about 2.1 billion. So there is a 1 in 2.1 billion chance that `three()` returns the wrong value.

There is no particular test case that would cause 2 to be returned: `three` takes no input, and the error occurs randomly!

There are really only two ways to notice this error:
1. Read the implementation and see that it has this crazy error.
2. Do a *lot* of testing, e.g. billions and billions of calls.

While this is a contrived example, unpredictable and hard to catch errors like this do occur practice. For example, sometimes a problem in hardware can cause unpredictable behaviour in programs that are logically correct.

[[concurrent program|Concurrent programs]] can have bugs that don't appear in non-current programs. The different threads of control can interact in subtle and unexpected ways. The exact conditions under which a bug in a [[concurrent program]] occurs can often be extremely difficult to re-create, and can sometimes even seem like random errors. As you can imagine, bugs like this are hard to catch and fix. Bugs due to concurrency are often referred to in general as [[race condition]]s.

## Practice Questions
1. Name three different styles of testing, and give examples of how they work.
2. In your own words, explain the difference between [[unit testing]] and [[system testing]]. What's one of the problems with [[system testing]]?
3. In your own words, explain [[blackbox testing]] and [[whitebox testing]]. How are they similar? How do they differ?
4. Why is [[manual testing]] usually a bad idea?
5. What is [[exhaustive testing]]? Give an example of a function when you can use it, and a function when you can't.
6. How much testing should you do for a function?
7. In your own words, explain why a function might not be correct even through it passes all its tests.
8. Give an example of a function with a bug that testing would have a hard time catching. Instead of testing, how might the bug be caught?
9. What is a [[concurrent program]]? What is a [[race condition]]?
