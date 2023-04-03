#terminology

## Definition
A loop that never stops. Typically, infinite loops are a sign of a programming bug, but for some programs, such as operating systems, infinite loops might be acceptable. 

## Example
Here are a few examples of infinite loops (there are an many others!):
```cpp
while (true) {
	cout << "hello!";
}


for(int i = 0; i % 2 == 0; i += 2) {
	cout << "goodbye!";
}
```

Sometimes code that is an infinite loop in *theory* might not be an infinite loop in practice. For example, this loop eventually stops because when `i` hits the maximum `int` value, the next value is negative:
```cpp
for(int i = 0; i > 0; i++) {          // not an infinite loop in practice
	cout << "not an infinite loop!";
}
```

Similarly, recursive functions that are infinite in theory can be finite in practice because every function call uses a bit of memory (see [[Calling a function]]):
```cpp
void f() {
	cout << "runs out of memory eventually";
	f();
}
```

In some cases, the compile *may* replace a recursive call with a loop using [[tail call elimination]]. In those cases, theoretically infinite recursive functions may end up being practically infinite as well.
