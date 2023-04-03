#terminology

## Definition
A fact that is always true at a particular point in a program.

[[pre-condition|Pre-conditions]], [[post-condition|post-conditions]], and [[loop invariant|loop invariants]] are all examples of invariants

Invariants are sometimes checked using assertions, e.g. using the standard C++ `assert` macro. 

There are many possible invariant at any point in a program, and the trick is to find an invariant that is relevant and non-trivial. For example, `1 + 1 == 2` is always a true invariant anywhere in a program, but it's rarely useful.

## Example
```cpp
int a = 1;

// invariant: a == 1

int b = a + 2;

// invariant: b < a + 2


int i = 0;

while (i < a) {
    // loop invariant: i < a
	cout << "Hello!\n";
	i++;
}

// invariant: a == i + 1
```
