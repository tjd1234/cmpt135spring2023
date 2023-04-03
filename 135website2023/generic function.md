---
aliases: [template function, templated function]
--- 

#terminology

## Definition
In C++ a generic function is a function that takes one, or more, types as an input. They are also called **templated functions**, in reference to the `template` keyword that is used with them

## Example
In this function, the types `InputIt` and `T` are supplied when the function is called. They can be any types that work with `find`, `==`, and `<<`:

```cpp
template<class InputIt, class T>
void test_find(InputIt first, InputIt last, const T& value) {
    if (find(first, last, value) == last) {
        cout << value << " NOT found\n";
    } else {
        cout << value << " found\n";
    }
}
```
