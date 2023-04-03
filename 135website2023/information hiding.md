#terminology

## Definition
In C++ classes, information hiding occurs when you make the member variables of a class private. Then these variables are *hidden* from the rest of the program. Code outside of the class may not even know these variables exist.

Information hiding is usually a good thing because it means code outside of an object needs to know fewer details. Plus, code outside of the object can't accidentally modify an object's variables in a way that makes them inconsistent.

## Example
In `int_vec`, we say that `capacity`, `arr`, and `size` are all hidden. Code outside of the `int_vec` class cannot access them, and doesn't even need to know that they exist.

```cpp
class int_vec {
private:
    int capacity; // length of underlying array
    int* arr;     // pointer to the underlying array
    int size;     // # of elements in this int_vec from user's perspective
public:
    // nothing here yet
};
```