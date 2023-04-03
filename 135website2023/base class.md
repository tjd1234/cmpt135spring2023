#terminology

## Definition
A class that other classes are meant to inherit from. A base class should always have a [[virtual destructor]]. Bases classes are often [[abstract class|abstract classes]].

## Example
`Printable` is abstract base class. It's abstract because ones of its methods, `print()`, is abstract.

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const = 0;

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
```
