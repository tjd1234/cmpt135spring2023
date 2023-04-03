#terminology

## Definition
A [[destructor]] that has been declared [[virtual method|virtual]]. This allows destructors in inheriting classes to provide their own [[destructor]] that will be correctly called when objects are deleted.

## Example
```cpp
class Printable {
public:
   // ...

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
```