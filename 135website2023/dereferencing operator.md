---
aliases: ["indirection operator"]
---
#terminology

## Definition
In C++, `*` is the de-referencing operator and is used to *de-reference* a pointer. For example, if `p` is a pointer variable, then `*p` is the value `p` points to. 

Sometimes the term **indirection** is used when going from a pointer to the value it points to, e.g. and so `*` can be called the [[indirection operator]].

## Example
```cpp
char x = 'a';
char* px = &x;  // px stores the address of x
                // i.e. px points to x

cout << *px;    // prints a
```