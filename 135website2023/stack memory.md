---
aliases: [call stack]
---

#terminology

## Definition
Stack memory, or the call stack, is where local variables and function parameters are stored. It is structured as a [[stack data structure]].

Stack memory is *automatically* allocated and de-allocated as needed. When a
function is called, the parameters and local variables of the function are put
into stack memory, and when the function ends its parameters and variables are
automatically removed.

Stack memory is one of the three main [[C++ memory regions]].

## Example
```cpp

int g = 10;  // g is a global variable, and so stored in static memory

int f(int n) {    // variables a and n are local, and so stored in stack memory
	int a = 2;
	return n + a + g;
}

int main() {
    int b = 3;   // b is local and so stored in stack memory
	cout << 3 + f(5);
	
	double* p = new double(8.5);  // p is a local variable and so is
	                              // stored in stack memory
	
	// the value that p points is called *p and is stored in free store memory
}
```
