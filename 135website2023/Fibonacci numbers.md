#terminology

## Definition
An integer sequence where the first two numbers are 1, and after those each number is the sum of the two numbers immediately before it. The first few numbers in the sequence are:

1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...

The following recurrence relation defines `f(n)`, the nth Fibonacci number:

```
f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2),  n > 2
```
