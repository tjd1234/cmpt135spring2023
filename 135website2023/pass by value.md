#terminology

## Definition
A style of passing a variable to a function where a copy of the variable's value is passed to the function.

Compare this to [[pass by reference]].

## Example
```cpp
int add1(int n) {   // n is passed by value
	n++;
	return n;
}

int main() {
	int s = -2;
	cout << add1(s) << "\n";  // prints -1
	cout << s << "\n";        // prints -2 (s is unchanged)
}
```
