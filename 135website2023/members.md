#terminology

## Definition
The variables and [[method]]s defined in a class. 

## Example
This class has 5 members: 2 private variables, and 3 public methods.

```cpp
class Fraction {
	int num;
	int denom;

public:
    // constructor (a special kind of method)
	Fraction(int n, int d)
	: num(n), denom(d)
	{ }

	// const method (doesn't modify the object)
	double toFloat() const {
		return num / denom;
	}
	
	// setter method
	void set(int n, int d) {
		num = n;
		denom = d;
	}	
}; // class Fraction
```