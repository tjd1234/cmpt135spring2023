#terminology

## Definition
A style of passing a variable to a function where the variable itself is passed to the function. Since no copy is made, this can be more efficient than [[pass by value]]. It also allows the function to modify the variable.

Pass by reference only works with variables (see the example).

## Example
```cpp
int add1(int& n) {   // n is passed by reference: note the &
	n++;
	return n;
}

int main() {
	int s = -2;
	cout << add1(s) << "\n";  // prints -1
	cout << s << "\n";        // prints -1 (s is changed)
}
```

Note that it's an error if you call `add1(5)`. Pass by reference requires a variable, and doesn't work if you give it a literal.