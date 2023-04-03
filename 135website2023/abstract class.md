#terminology

## Definition
A class with one, or more, [[abstract method|abstract methods]]. An abstract class cannot be implemented, and so it used as a [[base class]].

## Example
Since `get_name` is an [[abstract method]], `Nameable` is an abstract class:

```cpp
class Nameable {
public:
    // prints the object to cout
    virtual string get_name() const = 0;

    // virtual destructor
    virtual ~Nameable() { }

}; // class Nameable
```