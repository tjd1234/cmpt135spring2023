#terminology

## Definition
Pseudocode is an informal description of a program that is meant to be easy for a human to read. Pseudocode often ignores small or unimportant details, and instead focuses on the things that are most important for the human reading it.

## Example
Here's a pseudocode description of [[linear search]]:

- Does $v_0 = x$? If so, stop and return 0.
- Does $v_1 = x$? If so, stop and return 1.
- ...
- Does $v_{n-1} = x$? If so, stop and return $n-1$.
- Otherwise, stop and return -1.

Here's a pseudocode description of [[mergesort]]:

```
mergesort(v)    // v has n elements
   if v is size 0 or 1, then return  // base case
    
   half = n / 2
   left = {v[0], v[1], ..., v[half-1]}       // split v into 2 equal parts
   right = {v[half], v[half+1], ..., v[n-1]}
        
   left = mergesort(left)                    // recursively sort the 2 parts
   right = mergesort(right)
    
   v = merge(left, right)                    // combine the 2 parts
```
