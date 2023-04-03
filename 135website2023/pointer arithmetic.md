#terminology

## Definition
Pointer arithmetic refers to adding, or subtracting, values to pointers in order to access other memory locations. For example, if `p` is a `char` pointer, then `p+100` is 100 `char`s away from the address `p` points to. Similarly, `p-25` is 25 chars away from `p` (in the opposite direction).

Pointer arithmetic is quite powerful: give just one pointer, it is possible to access practically any memory location relative to that pointer by using pointer arithmetic.

## Example
This code fragment uses pointer arithmetic to access and print the values of an array:

```cpp
int arr[] = {5, 6, 7, 8};

cout << *(arr + 0);  // prints 5
cout << *(arr + 1);  // prints 6
cout << *(arr + 2);  // prints 6
cout << *(arr + 3);  // prints 8

```

You could all access `(arr - 5)`, which is an error since C++ makes no guarantees what memory resides at that location (it could even be the memory for a completely different program).
