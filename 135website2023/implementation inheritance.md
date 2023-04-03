#terminology

## Definition
Implementation inheritance occurs when a class implements a method that has an implementation, i.e. a non-virtual method.

In general, it is often a good idea to minimize implementation inheritance, or avoid it altogether. [[Interface inheritance]] is often simpler, and can result in more flexible programs.

## Example
The `to_str()` method in `Stringable` is non-abstract, and so when `Point` inherits from `Stringable` it is inheriting the implementation of `to_Str()`:

```cpp
class Stringable {
public:
  string to_str() const {return ""};
};


class Point : public Stringable {
   // ...
};
```