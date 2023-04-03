---
aliases: [pure virtual method]
---
#terminology

## Definition
An abstract method has no implementation. C++ uses the notation `= 0` after a method header to indicate that it's abstract. 

Also known as a pure virtual method.

A method that is not abstract is call non-abstract, or concrete.

## Example
`print()` is an abstract method, while `println()` is a non-abstract method:

```cpp
class Printable {
public:
    virtual void print() const = 0; // abstract method

    void println() const { // non-abstract method
        print();
        cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
```