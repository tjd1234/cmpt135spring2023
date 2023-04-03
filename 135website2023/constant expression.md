#terminology

## Definition
In C++, a constant expression is an expression that can be evaluated at compile-time.

## Example
These are all examples of constant expressions that can be evaluated at compile-time before the program runs:

```cpp
constexpr int a = 25;
constexpr int b = a + 3;
constexpr int c = a*a + b*b;
```
