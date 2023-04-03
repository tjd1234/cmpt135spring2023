#terminology

## Definition
A [[base class]] that is [[abstract class|abstract]].

## Example
`Stringable` is an abstract case class:

```cpp
class Stringable {
public:
  virtual string to_str() const = 0;
  virtual ~Stringable() { }
};

class Student : public Stringable {
  // ...
public:
  // ...
  string to_str() const {
    return "<string representation of this object>";
  }
}
```
