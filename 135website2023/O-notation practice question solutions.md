The follow are solutions to the questions at the end of [[O-notation]].

1. Besides run-time performance, what are three other kinds of questions that
   computer scientists may be interested in asking about an [[algorithm]]?

   **Answer**: memory efficiency, simplicity, generality, fault-tolerance,
   parallelizability, security, ...

2. When analyzing [[algorithm|algorithms]], why do we usually write them in [[pseudocode]] instead of an actual programming language?

   **Answer**: [[Pseudocode]] is easier for humans to read and write, and makes it
   easy to ignore unimportant details.

3. What are three reasons why it can be difficult to measure the real-time
   performance of an [[algorithm]]?

   **Answer**: computers can run at different speeds; other programs that
   happen to be running at the same time could change the running-time of a
   program; software versions and coding details can result in cause different
   performance

4. What is a [[key operation]]?

   **Answer**: A [[key operation]] is important operation for an [[algorithm]], one
   that usually runs at least as many times as any other operation.

5. What is the usual [[key operation]] for searching and sorting algorithms?

   **Answer**: usually comparisons, e.g. `==` for searching and `<=` for
   sorting

6. Give an example of an [[algorithm]] whose [[key operation]] is addition.

   **Answer**: e.g. summing an array

7. What are the three main running-time cases in [[algorithm]] analysis? Which is
   usually the *least* important?

   **Answer**: best case, average case, and worst case; best case is usually
   the least important because it usually doesn't occur very often in basic
   [[algorithm|algorithms]]

8. Why is it often difficult to compare the running-times of [[algorithm|algorithms]] that have different key operations?

   **Answer**: different key operations might take different times to execute

9. Write the simplest and tightest O-notation expression for each of the
   following:

   1. 25

      **Answer**: $O(1)$

   2. $n - 100$

      **Answer**: $O(n)$

   3. $500n + 3000$

      **Answer**: $O(n)$

   4. $4n^2 - 8000n - 5000$

      **Answer**: $O(n^2)$

   5. $n^2 + 1$

      **Answer**: $O(n^2)$

   6. $n^3 + n^2 + n + 1$

      **Answer**: $O(n^3)$

   7. $n^4 - 5000n^3 + 20n^2 + \log_4\,n - 143$

      **Answer**: $O(n^4)$

   8. $2^{n} + n^{10} - 25n^2$

      **Answer**: $O(2^n)$


10. For each of the following, name, or briefly describe, an [[algorithm]] that has the given performance characteristics; give a different [[algorithm]] for each question:

     1. $O(1)$ in its worst case;

        **Answer**: e.g. finding the min value of a sorted array

     2. $O(1)$ in its best case, but $O(n)$ in its worst case;

        **Answer**: e.g. finding the min value of an unsorted array

     3. $O(n \log\,n)$ in the average case, but $O(n^2)$ in its worst case;

         **Answer**: e.g. [[quicksort]]

     4. $O(n^2)$ in all cases (best, average, and worst);

        **Answer**: e.g. summing the elements of an n-by-n 2-dimensional table of numbers

     5. $O(n \log n)$ in its best case;

        **Answer**: e.g. [[mergesort]]

     6. $O(2^n)$ in its worst case.

        **Answer**: e.g. printing all bit-strings of length $n$

11. Name two different sorting algorithms that do $O(n \log\,n)$ comparisons in the average case.

     **Answer**: [[mergesort]] and [[quicksort]]
	 
12. Suppose `f(n)` has a worst-case running time of $O(n^2)$, and `g(n)` has a worst case running time of $O(500n+2000)$. What is the tightest O-expression that describes the worst-case running time of calling `f(n)` and then `f(n)`?

     **Answer**: $O(n^2)+O(500n+2000)=O(n^2+500n+2000)=O(n^2)$. So the best answer is $O(n^2)$.
