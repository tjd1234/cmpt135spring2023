#terminology

## Definition
An [[invariant]] that is true at the start of a loop body. 

## Example
At the start of each iteration in the following loop, `i` is less than 10:

```cpp
int i = 0;

while (i < 10) {
    // loop invariant: i < 10
	cout << "Hello!\n";
	i++;
}

// invariant: !(i < 10), or i >= 10
```

When the loop finishes, the loop invariant must be false, i.e. `!(i < 10)` is true, which is logically equivalent to `i >= 10` being true.
