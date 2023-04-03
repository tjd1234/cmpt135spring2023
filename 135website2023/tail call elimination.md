---
aliases: [tail-call elimination]
---
#terminology

## Definition
Tail call elimination is an optimization that some C++ compilers might to a function. If the last thing a function does is call another function (even itself recursively), then it might be possible to replace that function call with a loop. This optimization can result in significant performance gains for some recursive functions, since it replaces all the recursive function calls with a loop.

If the last thing a recursive function does is call itself, then the function is said to be **tail recursive**.

## Example
Tail call elimination might be able to get rid of the recursive call in this function, and re-write it as a loop;
```cpp
void count_down(int n) {
  if (n > 0) {
    cout << n << "\n";
    count_down(n - 1);
  }
}
```

Be careful: sometimes functions might look recursive, but their not. For example: 

```cpp
void f(int n) {
  if (n <= 0) {
    return 1;
  } else {
  	return 1 + f(n-1);  // recursive call
  }
}
```

`f` is *not* tail recursive because the last operation it does in its recursive call is call the `+` operator. `f(n-1)` must be evaluated before calling `+`, and so a call to `f` is *not* the last thing the function does.