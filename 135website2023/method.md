---
aliases: [methods]
---

#terminology

## Definition
A function that is defined inside a class or struct. Methods can directly access other methods and member variables of the class. Methods can also access an object's [[this pointer]].

## Example
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
