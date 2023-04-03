#terminology

## Definition
Initializing a member variable directly in a class where it is defined.

## Example
In this example, when an object of `A` is created, the member variable `a` is initialized without using a constructor:

```cpp
class A {
public:
	int a = 7; // member initialization
};
```
