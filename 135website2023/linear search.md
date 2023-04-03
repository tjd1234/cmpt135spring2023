## Algorithms
Intuitively, an [[algorithm]] is a precise step-by-step description of a process.  For example:

- the procedure you learned in elementary school for adding numbers is an algorithm
- [selection sort](https://en.wikipedia.org/wiki/Selection_sort) is a sorting algorithm that re-arranges the elements of a vector to be in order from smallest to biggest
- [Bresenham's line-drawing algorithm](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm) draws a good-looking straight line between two pixels on a computer monitor
- many neural networks learn using an algorithm called
  [backpropagation](https://en.wikipedia.org/wiki/Backpropagation>)

A **program** can often be thought of as an *implementation of an algorithm*.

In computer science, it is often useful to first design an algorithm "on paper", and then implement it in code. By studying algorithms on paper we can often understand useful things about them, such as:

- whether or not they are correct, or for what inputs they work on
- how much work they do (i.e. how fast they are)
- how much memory they use
- how complicated they are
- how secure they are
- how much power they use (important on low-powered devices)

In what follows we will describe and algorithm and then discuss its performance in some detail.

## Linear Search
Linear search is a fundamental algorithm with many applications, and it appears in many different forms. Here we will study it from a fairly abstract point of view.

Linear search solves this problem:

> Given $v_0, v_1, \ldots, v_{n-1}$ and a target $x$, find $i$ such that $v_i = x$. If there is no such $v_i$, then return -1 (or somehow signal "not found").

You can think of $v_0, v_1, \ldots, v_{n-1}$ as being numbers, but they could also be strings, or vectors, or structures.. Any data type for which `==` is defined will work.

Here's a [[pseudocode]] description of the linear search algorithm:

- Step 1: Does $v_0 = x$? If so, stop and return 0.
- Step 2: Does $v_1 = x$? If so, stop and return 1.
- ...
- Step n: Does $v_{n-1} = x$? If so, stop and return $n-1$.
- Step n+1: Otherwise, stop and return -1.

## A Basic Implementation of Linear Search
Here is a typical implementation of linear search:

```cpp
// Pre-condition:
//    none
// Post-condition:
//    Returns the smallest i >= 0 such that v[i] == x; or, if
//    x is not anywhere in v, then -1 is returned
int linear_search1(const vector<int>& v, int x) {
    for(int i = 0; i < v.size(); i++) {
        if (x == v[i]) return i;
    }
    return -1;
}
```

Notice that this implementation of linear search always searches the vector from left to right. If you have no idea where $x$ is in $v$, then there's no reason to prefer any particular search order over another.

However, you might have some idea whereabouts in $v$ that $x$ might be. For example, suppose your looking for the `.` character in a file name. It's usually near the right-end of a file name, and so searching starting at the end and moving to the front is often faster.

## Searching in Different Orders
The [[pseudocode]] description of linear search given above is more specific than necessary: it always checks the values in order from $v_0$ to $v_{n-1}$.  Sometimes checking items in a different order might be better. For example, suppose you want to find the `.` character in a file name. The dot is usually near the right-end of a file name, and so it is usually quicker to search for it by starting at the right end and moving to the left, i.e. searching from $v_{n-1}$ down to $v_0$.

Expanding on this idea, there are a number of other ways you could do linear search that might be useful in particular situations. For example:

![[linearSearch.svg]]

However, since we know nothing about the location of $x$ in $v$, we will usually stick with plain left-to-right linear search since it's relatively simple to implement.

## Locating an Item: Another Version of Linear Search
Suppose you know for a fact that `x` is in `v`, and you want to find *where* in `v` it is. `linear_search1` can answer that question, but there is a slightly faster method:

```cpp
// Pre-condition:
//    x is in v (i.e. there exists some i such that v[i] == x)
// Post-condition:
//    returns the smallest i >= 0 such that v[i] == x
int location_of(const vector<int>& v, int x) {
    int i = 0;
    while (v[i] != x) i++;
    return i;
}
```

The [[pre-condition]] is very important here: this function only promises to work correctly if $x$ is in $v$. If $x$ is not in $v$, then it could loop forever.

`location_of` is a little faster than `linear_search1` because it does only *one* comparison, `v[i] != x`, on each iteration of the loop. In contrast, `linear_search1` does *two comparisons per iteration: `v[i] != x` and `i < v.size()`.

## A Faster General Purpose Linear Search?
Using `location_of`, we create a version of linear search that is sometimes faster that `linear_search1`. The trick is to replace the last element of $v$ with $x$,  thus guaranteeing that $x$ is in $v$. This $x$ at the end is called a **sentinel value**.

Once we know for sure that $x$ is in $v$, we can use `location_of` to find it. If the $x$ it finds is the one at the end, then we know $x$ is not equal to any of $v_0, v_1, \ldots, v_{n-1}$:

```cpp
// v is *not* const so that the end value can be 
// temporarily modified by the algorithm.
int linear_search2(vector<int> &v, int x)
{
    int n = v.size();
    if (n == 0)
        return -1;
    if (n == 1)
    {
        if (v[0] == x)
            return 0;
        else
            return -1;
    }

    // n >= 2 at this point

    // first check if x is the last element
    if (v[n - 1] == x)
        return n - 1;

    // at this point we know v[n-1] != x
    int last = v[n - 1];       // save the last element
    v[n - 1] = x;              // set the last element to x
                               
    int i = location_of(v, x); // search for x
                               
    v[n - 1] = last;           // put the last element back
    if (i == n - 1)            // check which x was found
        return -1; // x is not in v
    else
        return i; 
}
```

This is longer and more complicated, but it works! And in some cases it may be a little faster than regular linear search. However, on modern computers the improvement may be so slight that it's not worth the extra effort. But on older computers, or slower low-powered computers, it might make a more noticeable difference.

Another issue with this version is that it requires modifying the vector, and that might not always be possible.

## Linear Search on Sub-vectors
A useful way to generalize linear search is to let it search a range of sequential values:

```cpp
// linear search on the range [begin, end)
int linear_search3(const vector<int>& v, int x, int begin, int end) {
    for(int i = begin; i < end; ++i) {
        if (x == v[i]) return i;
    }
    return -1;
}
```

![[arrayBeginEnd.svg]]

In this function, `begin` is the index of the *first* element of `v` we want to search, and `end` is the index of *one past the last element* we want to search.

The range goes from `begin` to `end-1` (not `end`!). `[begin, end)` is the set of values `{v[begin], v[begin + 1], v[begin + 2], ..., v[end - 1]}`.

Thus, `linear_search3` searches the sub-range `v[begin]`, `[begin + 1]`, ... , `v[end - 1]`.

A feature of asymmetric range `[begin, end)` is that the number of elements in the range is exactly `end` - `begin`.

We can now implement regular linear search in one line:

```cpp
int linear_search3(const vector<int>& v, int x) {
    return linear_search3(v, x, 0, v.size());
}
```

This function is *not* recursive because it takes two parameters, and the `linear_search3` function it calls in its body takes 4 parameters. So they are different functions.

## Recursive Linear Search
Linear search can be implemented recursively using these three rules:

- **Base case 1**: If the list is empty, return "not found"
- **Base case 2**: If `x` is the first element of `v`, return "found"
- **Recursive case**: Otherwise, remove the first element of the list and call linear search on what remains.

```cpp
// recursive linear search on a range
int linear_search4(const vector<int>& v, int x, int begin, int end) {
    if (begin >= end) { 
        return -1; // not found
    } else if (v[begin] == x) { 
        return begin;
    } else { 
        return linear_search4(v, x, begin + 1, end);
    }
}

int linear_search4(const vector<int>& v) {
    return linear_search4(v, 0, v.size());
}
```

Performance-wise, recursive linear search is likely not as efficient as linear search implemented with a loop due to all the function calls it must do, and all the parameters it must save on the [[stack memory|call stack]]. Since this function is tail recursive, some compilers might be able to optimize-away the [[recursion]] in this case using [[tail call elimination]].

## Linear Search Performance
How fast is linear search? The speed of any program depends in on things like:

- the speed of your computer, how much memory it has, how many CPUs it has, etc.
- the quality of the code generated by your compiler, i.e. some compilers, or compiler options, produce faster/slower code than others
- the details of how you implement the code, e.g. recursive linear search is usually slower than a loop version
- the version of your operating system
- what else your computer might be doing at the same time
- etc. 

To avoid these complications, computer scientists typically measure algorithm performance by counting how many [[key operation|key operations]] it does. The number of [[key operation|key operations]] is independent of the particular software/hardware involved.

For linear search the most common [[key operation]] is  `==`. So the question "how fast is linear search?" becomes "how many times does linear search execute `==` ?".

## Counting == in Linear Search
The number of times `==` is executed depends upon `x` (the value being searched for) and the input vector:

- 0 times if the vector is empty
- 1 time if the vector's first element is `x`, or the size of the vector is 1 and `x` is not in it
- 2 times if the vector's second element is `x`, or the size of the vector is 2 and `x` is not in it
- ...
- n times if the vector's last element is `x`, or the size of the vector is n and `x` is not in it

For simplicity, we are assuming the items in the vector are unique, i.e. no duplicates.

In the **best case**, when `v` is empty, linear search does 0 comparisons. Empty vectors are probably not searched very often in practice, so this result is not very useful.

A slightly more useful best case is 1 comparison, when `x` is the first element of `v`. Assuming randomly ordered unique numbers in `v`, if `x` is in `v` then there is a $\frac{1}{n}$ chance `x` it is the first element. Thus, the best case does *not* occur very often and you shouldn't count on it.

In practice, the **worst case** is often more helpful, i.e. what is the greatest number of comparisons that linear search might do?

Keep in mind this maxim: 

> Hope for the best, but plan for the worst!

In the worst case, linear search does $n$ comparisons (where $n$ is the size of the vector). This can happen in two different ways:

- `x` is the last element of `v`
- or `x` is not in `v` at all

## Average Case Performance
The best and worst cases are extremes. Both may occur infrequently. So it is natural to ask what is the expected *average* number of comparisons done by linear search.

We can work out the answer by considering these two cases:

- **Case 1**: `x` is in `v`
- **Case 2**: `x` is not in `v`

Assuming each case occurs 50% of the time, the total number of comparisons will be the average of the two cases, e.g. $\frac{1}{2}$ (# of comparisons in case 1) + $\frac{1}{2}$ (# of comparisons in case 1).

So, how many comparisons are done in each case? For case 1, it is reasonable to estimate that about $\frac{n}{2}$ comparisons are done on average, e.g. sometimes `x` is near the beginning of the vector, sometimes it is near the end. If `v`s elements are randomly ordered, then over multiple searches these cases balance out, and we end up doing an average of about $\frac{n}{2}$ comparisons per search.

For case 2, when `x` is *not* in `v`, then `n` comparisons are always done.

So the total number of comparisons done by linear search is $\frac{1}{2}$ (# of comparisons in case 1) + $\frac{1}{2}$ (# of comparisons in case 1). This is: $\frac{1}{2}\cdot\frac{n}{2} + \frac{1}{2}n = \frac{n}{4} + \frac{2n}{4} = \frac{3n}{4}$.

Assuming random data, this expression says linear search does $\frac{3}{4}n$ comparisons on average. Experiments show that this is a pretty accurate count of the number of comparisons that linear search actually does under those conditions.

One final comment: many programmers estimate the average case for linear search to instead be the simpler expression $\frac{n}{2}$. $\frac{3}{4}n$ is a little more accurate because the worst-case of $n$ comparisons occurs in two different ways: when $x$ is the last element, and when its not in the vector at all. So $n$ comparisons occurs about twice as frequently as any other number of comparisons. In practice, especially when $n$ is big, the difference between $\frac{3}{4}n$ and $\frac{n}{2}$ often isn't hugely significant, and so $\frac{n}{2}$ is a reasonable overall answer.

## Optional: More Detailed Linear Search Average Case
Here is another, more detailed, derivation of the number of comparisons done by linear search in the average case.

First, we need to make some assumptions:

1. `v` (the vector being searched) contains $n$ unique items (no duplicates)
2. the probability that `x` is in `v` is $\frac{1}{2}$ 
3. if `x` is in `v`, then it has an equal chance of being at any location,
   i.e. the chance that `v[i] == x` is $\frac{1}{n}$

Keep in mind that these assumptions might not be true in practice! We assume they are true here to simplify the analysis.

With these assumptions in place, now we can say that the average number of comparisons is this:

- $\frac{1}{2}$ (# comparisons done when `x` is in v)  + $\frac{1}{2}$ (# comparisons done when `x` is not in v)

When `x` is not in `v`, exactly $n$ comparisons are done, and so the expression becomes:

- $\frac{1}{2}$ (# comparisons done when `x` is in v)  +  $\frac{1}{2}n$

How many comparisons are done when `x` is in `v`? Since we assumed there is a $\frac{1}{n}$ chance of `x` at being in any particular location, then:

- if `x` is at index 0, 1 comparison is done
- if `x` is at index 1, 2 comparisons are done
- if `x` is at index 2, 3 comparisons are done
- ...
- if `x` is at index i, i + 1 comparisons are done
- ...
- if `x` is at index n - 1, n comparisons are done

Thus:

- $\frac{1}{n}$ of the time 1 comparison is done
- $\frac{1}{n}$ of the time 2 comparisons are done
- $\frac{1}{n}$ of the time 3 comparisons are done
- ...
- $\frac{1}{n}$ of the time $n$ comparisons are done

The total amount of work done is the sum of each case:

$\frac{1}{n}\cdot 1 + \frac{1}{n}\cdot 2 + \ldots + \frac{1}{n}\cdot n$

This simplifies to:

$\frac{1}{n}(1 + 2 + \ldots + n)$

Since $1 + 2 + \ldots + n = \frac{n(n+1)}{2}$, the total number of comparisons done in the case when `x` is in `v` is:

$\frac{1}{n}(1 + 2 + \ldots + n)$

This simplifies to:

$\frac{1}{n}(\frac{n(n+1)}{2})$

Which further simplifies to:

$\frac{n+1}{2}$

Or:

$\frac{n}{2} + \frac{1}{2}$

Recall that the sum of all comparisons is given by this expression:

$\frac{1}{2}$ (# comparisons done when `x` is in v)  + $\frac{1}{2}n$

This now becomes:

$\frac{1}{2}\frac{n+1}{2} + \frac{1}{2}n$

Or:

$\frac{n+1}{4} + \frac{2n}{4}$

Which is:

$\frac{3n+1}{4}$

Or:

$\frac{3n}{4} + \frac{1}{4}$

So, assuming there's a 50-50 chance `x` is in `v`, and, assuming, if `x` is in `v` it has an equal chance of being at any position, then on average we would expect linear search to do $\frac{3n}{4} + \frac{1}{4}$ calls to `==`.

## Practice Questions
1. In your own words, describe what an algorithm is. What are some the properties of algorithms that are of interest to computer scientists?
2. State the [[pre-condition]] and [[post-condition]] for a general version of linear search that allows the items to be searched in any order.
3. Given an example of when searching the elements of a vector in *reverse* order might be better than searching them in forward order.
4. In your own words, explain the difference between the position-of algorithm and linear search.
5. Explain how `location_of` can be used to make an alternate version of linear search that, in some cases, is a little more efficient than the typical implementation of linear search. What are a couple of potential problems with this alternate version?
6. When estimating the performance of linear search, what is key instruction is typically used?
7. Suppose vector `v` has $n > 0$ numbers in some unknown order, and `x` is known to occur in `v` exactly once. Then:
  1. In the **best-case**, how many comparisons must linear search do to find the a target value `x`?
  2. In the **worst-case**, how many comparisons must linear search do to find the a target value `x`?
  3. If `x` is *not* in `v`, how many comparisons will linear search do?
  4. Assuming there's a 50% chance `x` is in `v`, and `x` has an equal chance of occurring at any particular position, about how many comparisons would linear search do on average to find `x`?
