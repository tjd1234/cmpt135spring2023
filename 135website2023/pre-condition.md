#terminology

## Definition
An [[invariant]] for a function that should hold *before* the function is called. If a pre-condition does not hold, then that means it was called with the wrong parameters, and so it might not work correctly. During development of a program it's often a good idea for a function to check that it's pre-conditions hold (e.g. using `assert`).

A pre-condition and a [[post-condition]] together form a [[contract]] between a function and the test of the program.

## Example
In the specification below, the pre-condition says that `v` must be non-empty:

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
