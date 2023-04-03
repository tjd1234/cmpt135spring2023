---
aliases: Recursion
---

A function that calls itself, either directly or indirectly, is said to be **recursive**. For example, this function `a` is recursive:

```cpp
void a() {
  cout << "Hello!\n";
  a();
}
```

In *theory*, `a()` runs forever because it keeps calling itself. But, in *practice*, it *probably* stops due to an "out of memory" run-time error. In practice, every call to `a()` uses a little bit of memory to store the address of where the program should continue running from after `a()` finishes (see [[calling a function]]).

However, it is possible that `a()` could *actually* run forever if your C++ compiler uses a performance optimization trick called [[tail call elimination]]. [[tail call elimination|Tail call elimination]] can rewrite `a()` as a loop, in which case `a()` really would run forever.

The compiler we're using, g++, doesn't do [[tail call elimination]] by *default*. But if you run g++ with the `-O2` flag, it will try to. With `-O2`, `a()` may actually run forever!

> In these notes we will **not** use the `-O2` flag.

Function `b()` is a variation of `a`:

```cpp
void b(int n) {
  cout << n << ": hello!\n";
  b(n + 1);  // n + 1 here, not n
}
```

`b` prints how many times it's called. Notice that if the second line of `b` was `b(n)` instead of `b(n+1)`, then the value of `n` would never change.

Having a function run until it crashes isn't very useful. Here's a version that stops when `n` is 10 or bigger:

```cpp
void c(int n) {
  if (n >= 10) {
    // all done: do nothing
  } else {
    cout << n << ": hello!\n";
    c(n + 1);
  }
}
```

For example, calling `c(4)` prints this:

```
4: hello!
5: hello!
6: hello!
7: hello!
8: hello!
9: hello!
```

Calling `c(10)` prints nothing.

Function `c` is useful, but stopping at 10 is arbitrary. It's more useful if we pass the stopping-number as a parameter:

```cpp
void d(int n) {
  if (n <= 0) {  // n is decreasing, so check if it's 0 or lower
    // all done: do nothing
  } else {
    cout << n << ": hello!\n";
    d(n - 1);   // subtract 1 instead of add 1
  }
}
```

For example, calling `d(5)` prints this:

```
5: hello!
4: hello!
3: hello!
2: hello!
1: hello!
```

This version counts *down* from `n` to 1, where `n` is any `int`. Notice that if you call `d` with something like `d(-3)`, nothing is printed.

By negating the condition of the if-statement, we can make the function a little simpler:

```cpp
void say_hello(int n) {
  if (n > 0) {
    cout << n << ": hello!\n";
    say_hello(n - 1);
  }
}
```

Or more generally:

```cpp
void say(const string& msg, int n) {
  if (n > 0) {
    cout << n << ": " << msg << "\n";
    say(msg, n - 1);
  }
}
```

This prints `msg` exactly `n` times.

## Counting Down and Counting Up
As another example, lets write a recursive function that prints the numbers from n **down to** 1 on the screen. For example, `count_down(5)` should print this:

```
5
4
3
2
1
```

By modifying `say_hello`, we can get this function:

```cpp
// prints the numbers from n down to 1
void count_down(int n) {
  if (n > 0) {
    cout << n << "\n";
    count_down(n - 1);  // recursive call comes after printing
  }
}
```

Now consider the opposite problem: write a recursive function that prints the numbers from 1 **up to** n. For example, `count_up(5)` should print this:

```cpp
1
2
3
4
5
```

Here is a solution:

```cpp
// prints the numbers from 1 up to n
void count_up(int n) {
  if (n > 0) {
    count_up(n - 1);   // recursive calls comes before printing
    cout << n << "\n";
  }
}
```

The key difference between `count_up` and `count_down` is *when* the recursive call is made. In `count_down`, it's made *after* printing, and in `count_up` it's before. That one little change has a big impact!

> **Note** Of course, in practice, for-loops or while-loops are the best way to implement any of these functions. But our goal here is to understand recursion, and so it is best to start with simple --- if impractical --- functions.

## Recurrence Relations: Recursive Functions in Mathematics
Recursive functions are commonly used in mathematics. For example, consider the function $S(n)$ defined as follows:

$$
\begin{align}
     \textrm{base case:}\;\; S(0) &= 0 \\
\textrm{recursive case:}\;\; S(n) &= n + S(n-1) \;\;\;\; \textrm{for}\;\; n > 0
\end{align}
$$
$S(0) = 0$ is called the **base case**, and $S(n) = n + S(n - 1)$ is the **recursive case**. Any useful recursive function needs at least one base case and one recursive case.

Using these two cases --- which we'll sometimes call *rules* --- we can calculate $S(n)$ for any non-negative integer $n$.

$S(0)$ is easy: it is simply 0, as defined by the base case. $S(1)$ is a little more work:

$$
\begin{align}
S(1) &= 1 + S(0) \\
     &= 1 + 0    \\
     &= 1
\end{align}
$$
For $S(2)$, we apply the recursive rule a couple of times:

$$
\begin{align}
S(2) &= 2 + S(1)        \\
     &= 2 + (1 + S(0))  \\
     &= 2 + (1 + 0)     \\
     &= 3   
\end{align}
$$
And $S(3)$:

$$
\begin{align}
S(3) &= 3 + S(2)              \\
     &= 3 + (2 + S(1))        \\
     &= 3 + (2 + (1 + S(0)))  \\
     &= 3 + (2 + (1 + 0))     \\
     &= 6
\end{align}
$$

The pattern is: $S(n) = n + ((n-1) + ((n-2) + ... + (2 + (1 +0))))$. Since addition can be done in any order, this is the same as $S(n) = 1 + 2 + ... + n$.

We can implement $S(n)$ directly like this:

```cpp
// returns 1 + 2 + ... + n (assuming n >= 0)
int S(int n) {
  if (n == 0) {            // base case
    return 0;
  } else {
    return n + S(n - 1);   // recursive case
  }
}
```

Notice how similar this is to the mathematical definition of $S(n)$. Indeed, when writing a recursive function it can be helpful to work out the cases on paper, and then translate them into code.

The base case is *essential* in a recursive function because it determines when the recursion stops. It plays the same role as the condition in a for-loop or while-loop.

Tracing the calls and returns made by a recursive function is often useful. For example, here's the trace of the call `S(5)`:

```
S(5) entered ...
 S(4) entered ...
  S(3) entered ...
   S(2) entered ...
    S(1) entered ...
     S(0) entered ...
      ... S(0) exited
     ... S(1) exited
    ... S(2) exited
   ... S(3) exited
  ... S(4) exited
 ... S(5) exited
```

You can see here that `S` gets called exactly 6 times, and that it returns exactly 6 times. The indentation shows which calls go with which returns; notice that `S(5)` is the first to be called but the last to return.

## Fibonacci Numbers
Base cases can have multiple rules. For example, the [[Fibonacci numbers|Fibonacci sequence]] is 1, 1, 2, 3, 5, 8, 13, .... The first two numbers of the sequence are 1, and then after that each number is the sum of the two before it. More mathematically, the $n$th  [[Fibonacci numbers|Fibonacci number]] $f(n)$ can be defined with this recurrence relation:

$$
\begin{align}
f(1) &= 1 \\
f(2) &= 1 \\
f(n) &= f(n-1) + f(n-2) \;\;\;\; n > 2
\end{align}
$$
Converting this definition to C++ is not too hard:

```cpp
// Returns the nth Fibonacci number (assuming n > 0).
// Uses recursion.
int f(int n) {
  if (n == 1) {               // base case
    return 1;
  } else if (n == 2) {        // base case
    return 1; 
  } else {
    return f(n-1) + f(n-2);   // recursive case
  }
}
```

Lets try calculating $f(5)$ by hand:

$$
\begin{align}
f(5) &= f(4) + f(3)                            \\
     &= (f(3) + f(2)) + (f(2) + f(1))          \\
     &= ((f(2) + f(1)) + f(2)) + (f(2) + f(1)) \\
     &= ((1 + 1) + 1) + (1 + 1)                \\
     &= 5
\end{align}
$$
This is more work than calculating $S(5)$ because there are *two* recursive calls to $f$ in the recursive case. For large values of n, those two calls could cause 2 more calls each, i.e. 4 more calls. Then those 4 calls could cause 2 more calls each, i.e. 8 calls. For large values of n, the number of recursive calls increases exponentially, which means that `f` will take a long time to calculate for all but the smallest values of `n`.

Tracing `f` shows a more elaborate pattern of entry/exit messages:

```
 f(5) entered ... 
  f(4) entered ... 
   f(3) entered ... 
    f(2) entered ... 
    exited f(2)
    f(1) entered ... 
    exited f(1)
   exited f(3)
   f(2) entered ... 
   exited f(2)
  exited f(4)
  f(3) entered ... 
   f(2) entered ... 
   exited f(2)
   f(1) entered ... 
   exited f(1)
  exited f(3)
 exited f(5)
```

This is one of the problems with recursive functions: they can make a *lot* of
function calls which, and that eats up a lot of time and memory.

There are 9 calls to `f` here, many of them dumbly re-calculating values that have already been calculated.

A non-recursive function for computing Fibonacci numbers is *much* faster and uses *much* less memory:

```cpp
// Returns the nth Fibonacci number (assuming n > 0)
// Doesn't use recursion.
int f2(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    int a = 1;
    int b = 1;
    int c = 0;
    for (int i = 2; i < n; ++i) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
}
```

A disadvantage of `f2` is that it's harder to understand. If you were given just `f2` with no explanation of what it's about, it might take a minute or two to realize that it computes Fibonacci numbers.

> **Note** The *n*th Fibonacci number $f(n)$ can also be directly calculated 
> using the non-recursive formula $f(n) = \frac{\phi^n - \psi^n}{\sqrt{5}}$ , where $\phi = \frac{1 + \sqrt{5}}{2}$ and 
> $\psi = \frac{1 - \sqrt{5}}{2}$.

## Recursion on Vectors (or arrays)
Suppose we want to sum the numbers in a vector. We can do it recursively like this:
- **Base case**: the empty vector has sum 0, i.e. `sum({})` is 0.
- **Recursive case**: the sum of all the elements in `v` is `v[0] + sum(rest(v))`; the function `rest(v)` returns a copy of the original vector with its first element chopped off.

This definition is precise enough that we can trace examples by hand. For instance:

$$
\begin{align}
sum(\{8, 1, 4, 2\}) &= 8 + sum(\{1, 4, 2\}) \\
                   &= 8 + 1 + sum(\{4, 2\}) \\
                   &= 8 + 1 + 4 + sum(\{2\}) \\
                   &= 8 + 1 + 4 + 2 + sum(\{\}) \\
                   &= 8 + 1 + 4 + 2 + 0 \\
                   &= 15
\end{align}
$$
To implement this in C++, we *could* write the `rest` function like this

```cpp
// Returns a new vector w of n - 1 (n == v.size()) such that 
// w[0] == v[1], w[1] == v[2], ..., w[n - 2] == v[n - 1].
// In other words, it returns a copy of v with the first element 
// chopped off.
vector<int> rest(const vector<int>& v) {
   vector<int> result;
   for (int i = 1; i < v.size(); i++) {  // i starts at 1
      result.push_back(v[i]);
   }
   return result;
}
```

Now we can write `sum` as follows:

```cpp
int sum1(const vector<int>& v) {
   if (v.empty()) {  // base case
      return 0;  
   } else {          // recursive case
      return v[0] + sum1(rest(v));
   }
}
```

This works! Unfortunately, the `rest` function is *extremely inefficient*: for every call to `sum1` we end up making a new copy of almost the entire passed-in vector.

A more efficient approach is to *simulate* `rest` by re-writing `sum1` to accept *begin* and *end* parameters specifying the range of values in `v` that we want summed. Then we can efficiently access any sub-vector:

```cpp
// returns v[begin] + v[begin + 1] + ... + v[end - 1]
int sum2(const vector<int>& v, int begin, int end) {
   if (begin >= end) {
     return 0;
   } else {
     return v[begin] + sum2(v, begin + 1, end);
   }
}

// returns the sum of all the elements in v
int sum2(const vector<int>& v) {
   return sum2(v, 0, v.size());
}
```

Adding extra parameters in this way is a standard trick when writing recursive functions. Notice that we don't need to include `end` in this case. We could have just written this:

```cpp
// returns v[begin] + v[begin + 1] + ... + v[end - 1]
int sum3(const vector<int>& v, int begin) {
   if (begin >= v.size()) {
     return 0;
   } else {
     return v[begin] + sum3(v, begin + 1);
   }
}

// returns the sum of all the elements in v
int sum3(const vector<int>& v) {
   return sum3(v, 0);
}
```

Here's another example. Suppose we want a recursive function that returns `true` if all the numbers in a vector are even, and `false` otherwise:

```cpp
// Pre-condition:
//     all ints in v are >= 0
// Post-condition:
//     If v[0], v[1], ... v[n-1] are all even (n is v's size),
//     true is returned. Otherwise, false is returned.
//     If v is empty, true is returned.
bool all_even(const vector<int>& v) {
   // ...
}
```

Notice that the function is defined using a [[contract]]. This is a good way to define a function precisely, and we will often use [[contract|contracts]] to carefully specify how a function ought to work.

The recursive idea for implementing this function is the same as for the `sum` function: we check if the *first* number is even, and then recursively call `all_even` to check that the *rest* of the numbers are even. As with `sum`, we use a helper function with an extra parameter to keep track of the sub-vector of `v` that is being processed:

```cpp
// Pre-condition:
//     begin >= 0
//     all ints in v are >= 0
// Post-condition:
//     Returns true if v[begin], v[begin+1], ... v[n-1] are all even,
//     where n is the size of v; false otherwise.
bool all_even(const vector<int>& v, int begin) {
   if (begin >= v.size()) {
     return true;
   } else if (v[begin] % 2 == 0) {
     return all_even(v, begin + 1);
   } else {
     return false;
   }
}
```

The first condition of the if-statement checks if the sub-vector being processed is empty. If `begin` is equal to the size of the vector, or is greater than the size, we consider that to be an empty vector, and so return true.

The next condition checks if the first element of the sub-vector is even. Since `begin` marks the start of the vector, `v[begin]` is that start of the vector (not `v[0]`!). If the first element is indeed even, then `all_even` is called on the rest of the vector, i.e. from location `begin + 1` onward.

Finally, the else part of the if-statement occurs just when `v[begin]` is odd. In that case, we no that the entire vector cannot be all even, and so `false` is returned immediately.

For convenience, we provide a function that doesn't require a starting index:

```cpp
bool all_even(const vector<int>& v) {
   return all_even(v, 0);
}
```

Functions with fewer parameters are quite common when writing recursive functions. Checking if an *entire* vector is all even is probably the most common case, and so `all_even(v)` makes this common case easier, and less error-prone, to use.

## Why Recursion?
Many students wonder why we teach recursion. A lot of professional programmers would have a hard time pointing to examples of where they have used recursion outside of school. In practice, *iteration*, i.e. loops, are far more common than recursion. However, in *theory*, recursion is one the most important ideas in all of computer science.

Some of the benefits to learning recursion are:

- For a few kinds of algorithms, such as parsers and the (important!) sorting algorithms [[quicksort]] and [[mergesort]], recursion is the most common implementation method. Non-recursive versions of these algorithms are usually harder to understand and implement.
- There are some programming languages, such as [Haskell](http://en.wikipedia.org/wiki/Haskell_%28programming_language%29) and [Erlang](https://en.wikipedia.org/wiki/Erlang_(programming_language)), that have no loops! In such languages, you must use recursion, or functions that are based on recursion.
- It is often easier to *reason* about recursive functions than iterative ones. Recursive functions are often mathematical definitions in disguise, and so you can use mathematics to help better understand your function's correctness, performance, or memory usage.
- The source code for recursive functions is often shorter, simpler, and more elegant than non-recursive functions. This can make your programs more readable, and less likely to have bugs (bugs love to hide in hard-to-read code).
- Recursion plays a fundamental role in the theoretical study of computation. Recursive functions can be used as the foundation for *all* computation, e.g. *any* loop can be translated into a recursive function that does the same thing.

In practice, recursion is probably best thought of as one of many tools a programmer can use to solve programming problems. Use it when it makes sense, and avoid it when it doesn't.

## Extra Examples of Recursion
Here are a few more examples of using recursion:
- [[Recursive linear search]] shows how to implement [[linear search]] using recursion.
- [[binary search|Recursive binary search]] shows how to implement [[binary search]] using recursion.
- [[recursive acronym|Recursive acronyms]] are an amusing example of recursion.

## Practice Questions
Implement the following using recursion (and no loops, or library functions that do the hard part). For some questions, you may want to create a helper function with extra parameters. 

1. The product of the integers from 1 to `n`, i.e. the factorial function `n! = 1 * 2 * ... * n`, for `n >= 0`. By definition, `0! = 1`.
2. The sum of the first n squares, i.e. `1^2 + 2^2 + \ldots + n^2`, for `n >= 0`.
3. Print the numbers from n down to 1 on `cout`, one number per line. Assume 
    `n >= 1`.
5. Print the numbers from 1 up to n on `cout`, one number per line. Assume
    `n >= 1`. 
5. The sum of just the positive numbers in a vector. For example, the sum of the positive numbers in `{1, -3, -2, 6}` is 7.
6. The number of times `x` occurs in a vector. For example, in `{5, 2, 1, 5, 5}`, 5 occurs three times.
7. Print the elements of a `vector<int>`, one number per line.
8. Find the biggest number in a `vector<int>`.
9. Expand the [[recursive acronym]] YOPY = Your Own Personal YOPY some given number of times (as in the example in [[recursive acronym|recursive acronyms]]).

## Sample Solutions to Practice Questions
1. The product of the integers from 1 to `n`, i.e. the factorial function `n! = 1 * 2 * ... * n`, for`n >= 0`. By definition, `0! = 1`.

   Sample solution:
   ```cpp
   int factorial_rec(int n) {
       if (n == 0) {
           return 1;
       } else {
           return n * factorial_rec(n - 1);
       }
   }

   void factorial_rec_test() {
       cout << "Testing factorial_rec ... ";
       assert(factorial_rec(0) == 1);
       assert(factorial_rec(1) == 1);
       assert(factorial_rec(2) == 2);
       assert(factorial_rec(3) == 6);
       assert(factorial_rec(4) == 24);
       cout << "all tests passed\n";
   }
   ```
2. The sum of the first n squares, i.e. `1^2 + 2^2 + \ldots + n^2`, for `n >= 0`.

    Sample solution:
   
   ```cpp
   int square_rec(int n) {
       if (n == 0) {
           return 0;
       } else {
           return n * n + square_rec(n - 1);
       }
   }

   void square_rec_test() {
       cout << "Testing square_rec ... ";
       assert(square_rec(0) == 0);
       assert(square_rec(1) == 1);
       assert(square_rec(2) == 5);
       assert(square_rec(3) == 14);
       assert(square_rec(4) == 30);
       cout << "all tests passed\n";
   }  
   ```

3. Print the numbers from n down to 1 on `cout`, one number per line. Assume `n >= 1`.

   Sample solution:

   ```cpp
   void print_down_from(int n) {
       if (n == 1) {
           cout << 1 << "\n";
       } else {
           cout << n << "\n";
           print_down_from(n-1);
       }
   }

   void print_down_from_test() {
       cout << "Testing print_down_from ...\n";
       print_down_from(5);
       cout << "all tests passed\n";
   }
   ```

4. Print the numbers from 1 up to n on `cout`, one number per line. Assume `n >= 1`. *Hint*: Write a recursive function that takes two inputs, `n`, and also another `int` representing the current value to be printed.

   Sample solution:

   ```cpp
   void print_up_to(int start, int n) {
       if (start == n) {
           cout << start << "\n";
       } else {
           cout << start << "\n";
           print_up_to(start + 1, n);
       }
   }

   void print_up_to_test() {
       cout << "Testing print_up_to ...\n";
       print_up_to(1, 5);
       cout << "all tests passed\n";
   }
   ```

5. The sum of just the positive numbers in a vector. For example, the sum of the positive numbers in `{1, -3, -2, 6}` is 7.

   Sample solution:

   ```cpp
   int sum_pos(const vector<int>& v, int begin, int end) {
       if (begin >= end) {
           return 0;
       } else if (v[begin] > 0) {
           return v[begin] + sum_pos(v, begin + 1, end);
       } else {
           return sum_pos(v, begin + 1, end);
       }
   }

   int sum_pos(const vector<int>& v) {
       return sum_pos(v, 0, v.size());
   }

   void sum_pos_test() {
       cout << "Testing sum_pos ... ";
       vector<int> a = {2};
       vector<int> b = {-2, 1, 4, 0, -10};
       vector<int> c = {1, 2, 3};
       vector<int> d = {-1, -2, -3};
       assert(sum_pos(a) == 2);
       assert(sum_pos(b) == 5);
       assert(sum_pos(c) == 6);
       assert(sum_pos(d) == 0);
       cout << "all tests passed\n";
   }
   ```

6. The number of times `x` occurs in a vector. For example, in `{5, 2, 1,
   5, 5}`, 5 occurs three times.

   Sample solution:

   ```cpp
   int count_rec(const vector<int>& v, int x, int begin, int end) {
       if (begin >= end) {
           return 0;
       } else if (v[begin] == x) {
           return 1 + count_rec(v, x, begin + 1, end);
       } else {
           return count_rec(v, x, begin + 1, end);
       }
   }

   int count_rec(const vector<int>& v, int x) {
       return count_rec(v, x, 0, v.size());
   }

   void count_rec_test() {
       cout << "Testing count_rec ... ";
       vector<int> v = {2, 6, 6, 1, 6, 8, 2, 1};
       assert(count_rec(v, 5) == 0);
       assert(count_rec(v, 2) == 2);
       assert(count_rec(v, 6) == 3);
       assert(count_rec(v, 1) == 2);
       assert(count_rec(v, 8) == 1);
       cout << "all tests passed\n";
   }
   ```

7. Print the elements of a `vector<int>`, one number per line.

   Sample solution:

   ```cpp
   void print_vec(const vector<int>& v, int begin, int end) {
       if (begin >= end) {
           // do nothing
       } else {
           cout << v[begin] << "\n";
           print_vec(v, begin + 1, end);
       }
   }

   void print_vec(const vector<int>& v) {
       print_vec(v, 0, v.size());
   }

   void print_vec_test() {
       cout << "Testing print_vec ...\n";
       vector<int> v = {1, 2, 3, 4};
       print_vec(v);
       cout << "all tests passed\n";
   }
   ```

8. Find the biggest number in a `vector<int>`.

   Sample solution:

   ```cpp
   int max(const vector<int>& v, int begin, int end) {
       if (begin >= end) cmpt::error("empty vector has no max");
       if (end - begin == 1) {
           return v[begin];
       } else {
           return max(v[begin], max(v, begin + 1, end));
       }
   }

   int max(const vector<int>& v) {
       return max(v, 0, v.size());
   }

   void max_test() {
       cout << "Testing max ... ";
       vector<int> a = {2};
       vector<int> b = {-2, 1, 4, 0, -10};
       vector<int> c = {1, 2, 3};
       vector<int> d = {-1, -2, -3};
       assert(max(a) == 2);
       assert(max(b) == 4);
       assert(max(c) == 3);
       assert(max(d) == -1);
       cout << "all tests passed\n";
   }
   ```

9. Expand the [[recursive acronym]] YOPY = Your Own Personal YOPY some given number of times (as in the example in [[recursive acronym|recursive acronyms]]).

   Sample solution:

```cpp
const string acronym = "YOPY";
const string expansion = "Your Own Personal YOPY";
string expand_YOPY(int n) {
    if (n == 0) {
        return "";
    } else if (n == 1) {
        return expansion;
    } else { // n > 1
        string prev = expand_YOPY(n - 1);
        // replace every occurrence of "MOMS" with its expansion
        int i = prev.find(acronym);
        while (i != string::npos) {
           prev.replace(i, acronym.size(), expansion);
           // search for next acronym after the current one
           i += expansion.size(); // skip over the just-replaced
                                  // string so the acronyms within 
                                  // it are not expanded
           i = prev.find(acronym, i);
        }
        return prev;
    } // if
}

void expand_YOPY_test() {
    cout << "Testing expand_YOPY ... ";
    cout << expand_YOPY(5) << "\n";
    cout << "all tests passed\n";
}
```
