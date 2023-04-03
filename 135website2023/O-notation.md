
**O-notation**, also known as **asymptotic notation**, or **order notation**, is a mathematical tool that is useful when discussing [[algorithm]] performance. It is commonly used both in the theoretical analysis of [[algorithm|algorithms]], and in practical programming for estimating running-times.

## Algorithms and Input
To analyze [[algorithm|algorithms]] mathematically, we make a number of simplifying assumptions. We assume that an [[algorithm]] $A$ takes an input of size $n$. Typically, this input is a sequence, such as an array or vector or string, with $n$ elements.  We  assume $A$ runs for a *finite* amount of time, i.e. that it eventually stops and returns a result.

For example, [[linear search]] takes $n$ elements and a target value $x$ as input, and returns the index location of an element that equals $x$; if $x$ is not in the list, -1 is returned:

1. linear_search({$a_1$, $a_2$, $\ldots$, $a_n$}, $x$)
2. $i \leftarrow 1$
3. if $a_i = x$ then return $i$
4. if $i = n$ then return $-1$
5. $i \leftarrow i + 1$
6. go to step 3

We've written this algorithm in [[pseudocode]] instead of C++ to make it more readable. The line numbers make it easy to refer to individual lines.

## Measuring Running Time
Since we are interested in how quickly [[algorithm|algorithms]] run, you might think that we would use real time --- such as seconds or microseconds --- to measure performance. We certainly judge real-world software as being fast or slow by how much time it takes.

But real time is difficult to measure for programs because different computers run at different speeds. To fairly compare two programs, we have to make sure they are run in the same conditions, i.e. on *exactly* the same computer, with *exactly* the same software, etc. We have to ensure no other software is running, e.g. if you check your email or watch a video while a program is running you might get inaccurate timings.

## Key Operations
So, to avoid these problems, computer scientists estimate an [[algorithm]]'s running time by measuring the *work* it does. And this work is estimated by *counting* how many times it executes a chosen [[key operation]]. A [[key operation]] is typically the most frequently executed instruction in an [[algorithm]]. The main advantage of this approach is that it is independent of hardware and software details, and it can even be applied to [[algorithm|algorithms]] written in [[pseudocode]] on paper.

It's very important to choose a sensible [[key operation]] that reflects the work the algorithm does. It should give us a pretty good estimate of the algorithms running time. For example, in [[linear search]] above, there are a couple of reasonable choices for the [[key operation]]:

- Item comparison using $=$.
- Item accesses, i.e. a call to $a_i$ corresponds accessing an element
  of an array or vector.
- Variable assignments using $\leftarrow$.

Traditionally, item **comparisons**, i.e. calls to $=$ or $\leq$, are the [[key operation]] for sorting and searching algorithms.

An example of a **bad** choice of [[key operation]] for linear search would be the number of times `return` is called. `return` is called exactly once, no matter how big $n$ is. This is not helpful because the running-time of linear search gets longer when $n$ is big, but the number of times `return` is called never changes.

## Algorithm Running Time
We will refer to the key instruction count in an [[algorithm]] as its **running time**. Keep in mind that even though we call this *time*, it is not actual time --- it is just a count of how many times the key instruction is executed.

Care must be taken when comparing the running times of [[algorithm|algorithms]] with different key operations. For example, comparing two strings may take longer than comparing two integers, and so 1000 string comparisons may take longer than 1000 integer comparisons. It's like comparing money: if you have $1000 Canadian and $1000 American, it's imprecise to say that you have $2000 in total.

We should also be clear if we are talking about the **best case**, **average case**, or **worst case** running time. In practice, the average case and worst case running times are usually the most useful.

## O-Notation
Getting precise instruction counts of even simple [[algorithm|algorithms]] is often difficult, and the mathematical expressions can be complicated. Simple [[key operation|key operations]], such as comparisons or additions, can be done so quickly on most computers that there is often little practical difference between [[algorithm|algorithms]] that do $5n + 1000$ or $n$ operations.

For these reasons we often describe algorithm instruction counts using *approximations*. **O-notation** (also known as **big O-notation**, **order notation**, or **asymptotic notation**) is a mathematically respectable way of approximating expressions.

Roughly, O-notation says that the **order** of a mathematical expression is its biggest term. Constants and low-order terms can be ignored. For example, we say that the expression $2n$ is in $O(n)$, and that $25n^7 -4n^3 + 20$ is in $O(n^7)$.

Intuitively, $O(n)$ is the *set* of all mathematical expressions of a single variable $n$ whose highest-order term is $n$, or lower. Similarly, $O(n^3)$ is the set of all expressions whose highest order term is $n^3$, or lower; thus $O(n)$ is a *subset* of $O(n^3)$.

The expression $45n - 80$ is in both $O(n)$ and in $O(n^3)$. We say that $O(n)$ is **tighter** than $O(n^3)$.  In practice, we usually want to know the *tightest* O-notation description for an expression since saying something like "$2n$ is $O(n^{3})$" is true but unhelpful.

It's easy to determine the high-order term of polynomials. For example, all of these expressions are in $O(n^2)$: $n^2$, $n^2+100$, $n^2-100$, $2n^2+n$, $\frac{1}{2}n^2 - 500n + 700$. If you say that a particular [[algorithm]] runs in $O(n^2)$ time, then that means the [[key operation]] count can be described by some expression from $O(n^2)$ (but we don't know which one).

Here is a more precise definition of O-notation:

> **Definition of O-notation.** [[Algorithm]] $A$ is order $f(n)$, written $O(f(n))$, if there exist fixed constants $k$ and $n_0$ such that $A$ requires no more than $kf(n)$ key operations to process an input of size $n \geq n_0$.

Using this definition, we can rigorously prove all the basic facts about O-notation. We will not go into the details of such proofs in this course, but instead focus on getting an intuition for the underlying concepts.

## O-notation Applied to Algorithms
| O-expression  | Name         | Example                   |
|---------------|--------------|---------------------------|
| $O(1)$        | constant     | $1, 10, 34, 3538, \ldots$ |
| $O(\log n)$   | logarithmic  | $8\,\log_2 n + 5$         |
| $O(n)$        | linear       | $29n+5, n-9000$           |
| $O(n \log n)$ | linearithmic | $n\,\log_3 n + 23n - 4$   |
| $O(n^2)$      | quadratic    | $7n^2 - 4n + 22$          |
| $O(n^3)$      | cubic        | $n^3 + 2n^2 + 22n + 1$    |
| $O(2^n)$      | exponential  | $3^n + n^4 - 2n^2 + 80$   |

We use the O-notation categories in the above table to describe the running
times of algorithms. For example:

- Finding the minimum value in an *unordered* vector of $n$ elements using the standard algorithm takes $n-1$ comparisons, and $n-1$ is in $O(n)$. So we say that the standard min-finding algorithm does $O(n)$ comparisons, or just that it is $O(n)$.
- Finding the minimum value in a *sorted* vector is easy: it is the first element of  the list. No matter how big $n$ is, returning the first element takes a fixed amount of work. So we say that finding the min of an $n$-element vector requires $O(1)$ work, i.e. it is a *constant  time* algorithm whose performance doesn't depend on $n$.
- [[linear search]] does $O(n)$ comparisons in the average/worst case, and so we say it is a **linear**-time [[algorithm]]. In the best case, linear search does only 1 comparison, and so in that case, it is $O(1)$, i.e. constant time.
- [[Insertion sort]] does $O(n^2)$ comparisons in the worst-case and average-case, and so it is a **quadratic**-time [[algorithm]]. In the best case (e.g. when the data is already sorted), [[insertion sort]] only does $O(n)$ comparisons, and so it is linear, i.e. $O(n)$ in that case. 
- [[Quicksort]]  does $O(n \log n)$ comparisons in the average case, but degrades to $O(n^2)$ in the worst case. The worst-case occurs very rarely, and so many programmers --- perhaps unwisely --- treat it as if it did $O(n\log n)$ comparisons in all cases.
 - Another important sorting algorithm is [[mergesort]] is also $O(n \log n)$ comparisons in *all* cases, even the worst case. However, compared to [[quicksort]], [[mergesort]] uses about twice as much memory, and is usually a little slower on average.
- [[Binary search]] does $O(\log\,n)$ comparisons in the worst-case and average-case (in the best case it does only 1 comparison). Thus it is a **logarithmic** [[algorithm]]. This is not quite as good as $O(1)$, but in practice logarithmic algorithms are often extremely fast.

  > **Note** The base of a logarithm doesn't matter when we describe it with O-notation: $\log_a x$ and $\log_b x$ differ only by a constant factor, and so they are both $O(\log n)$.

## Two or More Algorithms in a Row
Real-world programs often do multiple functions calls in a row. For example, if `f(n)` does $O(n^3)$ operations in the worst case, and `g(n)` does $O(n\log n)$ operations in its worst case, then how many operations does calling `f(n)` followed immediately by `g(n)` do in the worst case?

We can figure this out as follows. Since `f(n)` is $O(n^3)$, that means there is a polynomial with a highest-order term of $n^3$ that describes the running time of `f(n)`. Since O-notation lets us ignore constants and low-order terms, we can assume `f(n)` does $n^3$ operations. Similarly, since `g(n)` does $O(n\log n)$ comparisons, we can treat it as if it does $n \log n$ operations.

So if we run `f(n)` and then `g(n)`, that's about $n^3 + n \log n$ operations in total. Since $n^3$ is the high-order term of *that* expression, and O-notation lets us ignore constants and lower-order terms, we can say the sequence of two function calls does $O(n^3)$ [[key operation|key operations]] in total.

In general, when we run two [[algorithm|algorithms]] in a row one after the other, the total running-time equals the running time of the individual [[algorithm]] with the highest-order running time. So, for example, suppose you sort an n-element list using [[insertion sort]] and then search it using [[binary search]]. [[Insertion sort]] does $O(n^2)$ comparisons, and [[binary search]] does $O(\log n)$ comparisons, and so in total both operations together do $O(n^2)$ operations, i.e. the higher-order of the two terms.

So, overall, from the point of view of O-notation, a sequence of operations is only as fast as its slowest individual operation.

## Practice Questions
1. Besides run-time performance, what are three other kinds of questions that computer scientists may be interested in asking about an [[algorithm]]?
2. When analyzing [[algorithm|algorithms]], why do we usually write them in [[pseudocode]] instead of an actual programming language?
3. What are three reasons why it can be difficult to measure the real-time performance of an [[algorithm]]?
4. What is a [[key operation]]?
5. What is the usual [[key operation]] for searching and sorting algorithms?
6. Give an example of an [[algorithm]] whose [[key operation]] is addition.
7. What are the three main running-time cases in [[algorithm]] analysis? Which is usually the *least* important in practice?
8. Why is it often difficult to compare the running-times of [[algorithm|algorithms]] that have different [[key operation|key operations]]?
9. Write the simplest and tightest O-notation expression for each of the following:

   1. 25
   2. $n - 100$
   3. $500n + 3000$
   4. $4n^2 - 8000n - 5000$
   5. $n^2 + 1$
   6. $n^3 + n^2 + n + 1$
   7. $n^4 - 5000n^3 + 20n^2 + \log_4\,n - 143$
   8. $2^{n} + n^{10} - 25n^2$

10. For each of the following, name, or briefly describe, an [[algorithm]] that has the given performance characteristics; give a different [[algorithm]] for each question:
     1. $O(1)$ in its worst case
     2. $O(1)$ in its best case, but $O(n)$ in its worst case
     3. $O(n \log\,n)$ in the average case, but $O(n^2)$ in its worst case
     4. $O(n^2)$ in all cases (best, average, and worst)
     5. $O(n \log n)$ in its best case
     6. $O(2^n)$ in its worst case

11. Name two different sorting [[algorithm|algorithms]] that do $O(n \log\,n)$ comparisons in the average case.
12. Suppose `f(n)` has a worst-case running time of $O(n^2)$, and `g(n)` has a worst case running time of $O(500n+2000)$. What is the tightest O-expression that describes the worst-case running time of calling `f(n)` and then `f(n)`?

[[O-notation practice question solutions]].
