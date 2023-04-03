# Resource Acquisition is Initialization (RAII)
#terminology

## Definition
In C++, **Resource Acquisition is Initialization** (**RAII**) refers to the general pattern of using a class/struct to manage a resource (such as memory). The class [[constructor]] allocates the resource, and the class [[destructor]] de-allocates the resource. Thus the lifetime of the resource is tied to the lifetime of the object.

## Example
```cpp
class Printer {
public:
	// default constructor
	Printer() {
		// ... code to turn on printer ...
	}
	
	// destructor
	~Printer() {
		// ... code to turn off printer ...
	}

	// ...
};
```
