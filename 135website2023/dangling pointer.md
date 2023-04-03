---
aliases: [dangling pointers]
---

#terminology

## Definition
A dangling pointer is a pointer that is pointing to memory that is no longer valid. Compare this to a [[memory leak]]. Dangling pointers can occur when, for example, two pointers are pointing to the same memory location and the memory is deleted through one of the pointers. The other pointer doesn't "know" that the memory it is pointing two has been de-allocated.

In C++, determining if a pointer is dangling can be difficult. A tool like [[valgrind]] can help catch some dangling pointers.

## Example
```cpp
int* p = new int(5);   // p points to a new int on the free store
int* q = p;            // q points to the same int as p

delete p;              // okay: value p pointed to de-allocated

//
// Problem! q is now a dangling pointer
//
```

The problem here is that after calling `delete p`, the value that `q` is pointing to is de-allocated. That means `q` is a dangling pointer and should not be used. It's up to the programmer to recognize this.
