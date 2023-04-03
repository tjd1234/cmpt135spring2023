#terminology

## Definition
The memory of a running C++ program is divided into *three* main regions: [[static memory]], [[stack memory]], and [[free store memory]].

```
 +--------------------------------------------+
 |       |                  |                 |
 +--------------------------------------------+
  Static        Stack            Free store
  memory        memory           memory     
```

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
