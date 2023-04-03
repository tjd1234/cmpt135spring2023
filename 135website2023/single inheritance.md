# Single Inheritance
#terminology

## Definition
When a class inherits from exactly one other class. This is in contrast to [[multiple inheritance]].

## Example
`Point` inherits from the class `Printable`, so this is an example of single inheritance:
```cpp
class Point : public Printable {
private:
    // ... 

public:
    // ...

    ~Point() {
        print();
        cout << " destroyed\n";
    }

    // ...
}; // class Point
```