#terminology

## Definition
Interface inheritance occurs when a class inherits an abstract method, i.e. a method without an implementation.

Compared to [[implementation inheritance]], interface inheritance can be simpler and result in more flexible designs. Some programmers prefer interface inheritance in almost all situations.

## Example
The `to_str()` method in `Stringable` is abstract, and so when `Name` inherits from `Stringable` it is inheriting just the header of `to_Str()`, and so should provide its own implementation:

```cpp
class Stringable {
public:
  string to_str() const = 0;
};


class Name : public Stringable {
	string first_name;
	string last_name;
public:
	string to_str() { return first_name + " " + last_name; }
};
```
