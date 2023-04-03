---
aliases: [brute force testing]
---

#terminology

## Definition
Exhaustive testing is when you test **all** possible input to a function. This is sometimes possible for small functions, but it's impractical with functions that have many inputs.

Also known as **brute force testing**.

## Example
Consider this function:

```cpp
// if a and b are different, then true is returned; 
// otherwise, false is returned
bool exclusive_or(bool a, bool b);
```

There are only 4 different inputs to `exclusive_or`, and so they can easily be tested.

Typically, functions have far more input values than could ever be practically tested. For example:

```cpp
// if a and b are different, then true is returned; 
// otherwise, false is returned
int sum(const vector<int>& v);
```

Assuming an `int` is 32 bits, and that, say, `v` could have at most 2 billion elements, then there are $`32 \cdot 2 = 64`$ billion *bits* of input to `sum`, which means there are $`2^{64\, billion}`$ cases, which is an astronomical amount --- there's no way to test that many different cases!