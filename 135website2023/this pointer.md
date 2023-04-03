#terminology

## Definition
`this` is a special pointer that C++ automatically adds to every class/struct. An object's `this` pointer always points to the object itself.

## Example
```cpp
class Fraction {
	int num;
	int denom;

public:
	// ...
	
	// setter method
	void set(int n, int d) {
		this->num = num;       // this pointer used to access
		this->denom = denom;   // num and denom member variables
	}	
}; // class Fraction
```