#terminology

## Definition
When a function is specified using a [[pre-condition]] and a [[post-condition]], then we can say there is a contract between the function and the rest of the program.

When the program calls the function, it is the responsibility of the program to ensure that the [[pre-condition]] holds. And if the [[pre-condition]] holds, it is the responsibility of the function to make sure that the [[post-condition]] holds after it finishes executing.

Thus, if the [[pre-condition]] for a function fails to hold, then you there is bug somewhere in the code that is calling the function. If the [[post-condition]] fails to hold, then there is a bug somewhere in the function. Thus a contract can help a programmer determine where in their program a bug might be.

## Example
Code that calls `max` is responsible for ensuring `v` is non-empty. If `v` is non-empty, then `max` is responsible for returning the max value in `v`.

```cpp
// Pre-condition:
//    v.size() > 0
// Post-condition:
//    Returns the biggest value in v.
int max(const vector<int>& v) {
    assert(v.size() > 0);   // check that the pre-condition holds
    // ...
}