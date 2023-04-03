---
aliases: [setters, setter method]
---
#terminology

## Definition
A method that assigns a value a variable in an object.

See also [[getter]].

## Example
This `Person` class has two setters:

```cpp
class Person {
	string name;
	int age;
public:
    // ...
	
	// a setter
	void set_name(const string& n) {
		name = n;
	}
	
	a stter
	void set_age(int a) {
		age = a;
		if (age <= 0) age = 1;
	}
};
```

