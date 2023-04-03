#terminology

## Definition
`&` returns the address in memory of a variable. In general, we can't know ahead of time at what address a variable will be stored.

## Example
```cpp
string s = "cat";
string* p = &s;
cout << s;   // prints "cat"
cout << *p;  // prints "cat"
cout << p;   // prints address where s is stored
```
