[[linear search]] is an algorithm that takes as input a vector `v` and a target
element `x` and returns either the index location of `x` in `v`, or -1
if `x` is not in `v`. If `x` occurs more than once, then we'll return
the location of the first `x`.

Using begin and end values, we specify the range we want to search like this:

```cpp
// Returns i such that v[i] == x and begin <= i < end; 
// otherwise returns -1 if x is not in v.
int linear_search(const vector<int>& v, int x, int begin, int end)
```

A recursive implementation of `linear_search` goes like this:

- **Base case 1**: if `v` is empty, return -1 (`x` not found)
- **Base case 2**: if `v[begin] == x`, return `begin` (`x` found at
  location `begin`)
- **Recursive case**: return the value of  `linear_search(x, v, begin + 1, end)`

Here's a C++ implementation:

```cpp
// Returns i such that v[i] == x and begin <= i < end; 
// otherwise returns -1 if x is not in v.
int linear_search(int x, const vector<int>& v, int begin, int end) {
   if (begin >= end) {          // base case 1: range is empty
     return -1;
   } else if (v[begin] == x) {  // base case 2: x is at the front of v
     return begin;
   } else {                     // recursive case
     return linear_search(x, v, begin + 1, end);  // note it's begin + 1
   }
}

int linear_search(int x, const vector<int>& v) {
   return linear_search(x, v, 0, v.size());
}
```
