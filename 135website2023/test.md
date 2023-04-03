#terminology 

## Definition
A [[test input]] and a corresponding test output together form a *test*. In other words, a test for a function `f` can be thought of as a triple (`f`, `test_input`, `expected_output`). The test **passes**, or **succeeds**, if `f(test_input) == expected_output`. Otherwise,  if `f(test_input) != expected_output`, then we say the test has **failed**.

```cpp
if (f(test_input) == expected_result) {
    // test passed!
} else {
    // test failed
}
```

## Example
Suppose `int add(int x, int y)` is a function to be tested. Then one test for it would be `(3, 4)` (the input) and `7` (the expected output).