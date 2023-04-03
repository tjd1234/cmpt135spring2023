#terminology 

## Definition
Merging is the process of combining two sorted vectors into one sorted vector, and it can be done very efficiently. 

## Example
The basic technique is as follows. Create two pointers, `a` and `b`, initialized to point to the beginning of each half like this:

```
        |
  left  |  right
1 2 4 8 | 3 5 6 7
^       | ^
|         |
a         b
```

Also, create a result vector big enough to hold both halves:

```
        |
  left  |  right
1 2 4 8 | 3 5 6 7
^       | ^
|         |
a         b

result: { }
```

To merge `left` and `right`, compare the elements that `a` and `b` point to, and append a copy of the *smaller* to the end of `result`. Then, increment the appropriate pointer to point to the next element. For example, in the above diagram 1 is less than 3, so 1 is appended to result and `a` is incremented:

```
  left  |  right
1 2 4 8 | 3 5 6 7
  ^     | ^
  |       |
  a       b

result: { 1 }
```

Next, 2 is smaller than 3, so 2 is appended to `result` and `a` is incremented:

```
  left  |  right
1 2 4 8 | 3 5 6 7
    ^   | ^
    |     |
    a     b
result: { 1, 2 }
```

Next, 3 is less than 4, so 3 is appended to `result` and `b` is incremented:

```
  left  |  right
1 2 4 8 | 3 5 6 7
    ^   |   ^
    |       |
    a       b

result: { 1, 2, 3 }
```

The merge continues in the same way until all the elements in left and right have been appended to `result`:

```
  left  |  right
1 2 4 8 | 3 5 6 7
      ^ |   ^
      |     |
      a     b

result: { 1, 2, 3, 4 }


  left  |  right
1 2 4 8 | 3 5 6 7
      ^ |     ^
      |       |
      a       b

result: { 1, 2, 3, 4, 5 }


  left  |  right
1 2 4 8 | 3 5 6 7
      ^ |       ^
      |         |
      a         b

result: { 1, 2, 3, 4, 5, 6 }


  left  |  right
1 2 4 8 | 3 5 6 7
      ^ |        ^
      |          |
      a          b

result: { 1, 2, 3, 4, 5, 6, 7 }


  left  |  right
1 2 4 8 | 3 5 6 7
       ^|        ^
       |         |
       a         b

result: { 1, 2, 3, 4, 5, 6, 7, 9 }
```

Now the entire vector is sorted.