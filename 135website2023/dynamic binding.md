#terminology

## Definition
When the name of a function (or variable, class, etc.) is associated with its body at run-time. This is in contrast to [[static binding]], where the function is bound to its implementation at compile-time.

## Example
For any code that uses the `Printable` class, the `print` method is bound at to its implementation at run-time since it has no implementation in `Printable`.

```cpp
class Printable {
public:

    virtual void print() const = 0;

    void println() const {
        print();
        cout << "\n";
    }

}; // class Printable
```