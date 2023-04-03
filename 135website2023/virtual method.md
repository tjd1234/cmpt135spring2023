#terminology

## Definition
A [[method]] that has been declared with the `virtual` keyword. This means that classes that inherit this method can over-ride it, i.e. replace it with their own version.

## Example
`Printable` has two virtual methods: `print()`, and its [[destructor]]. Classes that inherit from `Printable` can provide their own implementations of each.

```cpp
class Printable {
public:
    // prints the object to cout
    virtual void print() const {
		cout << "?";
	}

    // prints the object to cout followed by "\n"
    void println() const {
        print();
        cout << "\n";
    }

    // virtual destructor
    virtual ~Printable() { }

}; // class Printable
