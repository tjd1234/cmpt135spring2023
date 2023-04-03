#terminology

## Definition
A magic number is a number (or some other non-numeric value, like a `string`) that is not explained and whose purpose is unclear.

## Example
 10 is a magic number in these two constructors:
 
```cpp
class int_vec {
	// ...
public:
    int_vec() 
    : capacity(10), arr(new int[capacity]), size(0)
    { }

    int_vec(int sz, int fill_value)
    : capacity(10), size(sz)
    {
        // ...
    }

    // ...

}; // class int_vec
```
