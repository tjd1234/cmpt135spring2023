#terminology

## Definition
In [[whitebox testing]], code coverage is the idea of having enough test cases to make sure ever line of code in the function be testing is executed at least once.

## Example
Consider this function, which adds 1 to odd numbers and subtracts 1 from even numbers:

```cpp
int f(int n) {
	if (n % 2 == 0) {   // line 1
		return n - 1;   // line 2
	} else {    
		return n + 1;   // line 3
	}
}
```

To cover all the lines of these functions, at least two test cases are needed: an odd number and an even number. If you only tested `f` with, say, even numbers, then line 3 would never be executed (and maybe that line has a bug).
