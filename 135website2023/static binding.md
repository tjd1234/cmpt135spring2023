#terminology

## Definition
When the name of a function (or variable, class, etc.) is associated with its body at compile-time. This is in contrast to [[dynamic binding]], where the function is bound to  its implementation at run-time.

## Example
When this code is compiled, the function `hello` is bound to its body at compile-time:

```cpp
void hello() {          // hello is bound to its body at compile-time
    cout << "Hello!\n";
}
```
