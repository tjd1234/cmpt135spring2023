#terminology

## Definition
Static memory has a fixed size (that is known at compile-time) that never
gets bigger or smaller. Global variables are stored in static memory. 

Static memory is one of the three main [[C++ memory regions]].

## Example
```cpp
int flag = 0;  // flag is a global varible, and stored in static memory

void main() {
    string s = "wave";  // s is a local variable
	cout << flag;
	cout << s;
}
```

