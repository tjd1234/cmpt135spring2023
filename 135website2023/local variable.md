#terminology

## Definition
A variable defined inside the body of a function. The variable can only be used within the function, and is automatically deleted when the functions ends.

Compare this to [[global variable|global variables]].

## Example
```cpp
void swap(int& a, int& b) {
	int temp = a;   // temp is a local variable
	a = b;
	b = temp;
}
```
