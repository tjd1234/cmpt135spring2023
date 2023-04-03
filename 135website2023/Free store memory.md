#terminology

## Definition
In a running C++ program, memory that is not the [[stack memory]] or [[static memory]] is called free store memory. 

To allocate free store memory, you must use the `new` operator. To de-allocate free store memory, you must use `delete` (for non-arrays) or `delete[]` (for arrays).

all the other memory, and in contrast to [[stack memory]] it is *not* automatically managed in C++ (although many other languages do manage it automatically). Instead, a C++ programmer must allocate memory on the free store using `new`, and de-allocate it using `delete`/`delete[]`.

Forgetting to de-allocate free-store memory can cause a [[memory leak]], a kind of bug that is notoriously hard to find and fix. If you have two or more pointers to the same free store memory, then you can also run into [[dangling pointer|dangling pointers]].

## Example
```cpp
double* p = new double(36.13); // p points to a newly allocated double
                               // on the free store

cout << *p;  // *p is the double that p points to

delete p; // use delete to de-allocate free store memory
```

