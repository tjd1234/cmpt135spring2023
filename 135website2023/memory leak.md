---
aliases: [memory leaks], [Memory leaks]
---

#terminology

## Definition
A memory leak is memory on the free store that has been allocated and is no longer used, but has not been de-allocated. Compare this to a [[dangling pointer]].

In a long-running program, memory leaks can add up over time and eventually use up all [[free store memory]]. If there's no [[free store memory]] left, then calling `new` will fail.

In practice, finding and fixing memory leaks can be very difficult because there the point where the program fails (i.e. a call to `new`) is not necessarily anywhere near where the missing `delete` statement ought to be.

In some languages (but not C or C++), [[garbage collection]] is used to automatically de-allocate unused memory.

## Example
Function `f` has a memory leak:

```cpp

int f(int n) {
	int* temp = 5;
	return n + *temp;
}
```

Every time `f` is called in allocates new `int` on the stack, but that `int` never gets de-allocated. When `f` ends, there is no longer a pointer to the `int` that was allocated, so there is no way to delete it (`delete` requires a pointer to the memory it de-allocates).