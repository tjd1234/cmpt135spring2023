#terminology

## Definition
An [[invariant]] for a function that should hold *after* the function finishes executing properly (assuming its [[pre-condition]] held at the start). If a post-condition doesn't hold when the function ends, that usually means there is a bug in the function.

A pre-condition and a [[post-condition]] together form a [[contract]] between a function and the test of the program.

## Example
In the specification below, the post-condition says that the max item in `v` will be returned:

```cpp
// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns the biggest value in v.
int max(const vector<int>& v) {
    assert(v.size() > 0);   // check that the pre-condition holds
    // ...
}
```

Importantly, the post-condition is only required to hold if the [[pre-condition]] was true just before the function was called. In this example, if `max` was called with an empty vector, then it would probably crash with a run-time error.

