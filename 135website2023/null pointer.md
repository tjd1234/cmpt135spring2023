#terminology

## Definition
A pointer variable with the value `nullptr`. De-referencing a null pointer is an error. 

Older versions of C++ use did not have the special value `nullptr`, and so used the value `0` instead.

## Example
```cpp
char* cp = new char('M');

cp = nullptr;  // legal, but causes a memory leak!

string* sp = nullptr;

cout << *sp;   // error: cannot de-reference a null pointer
```
