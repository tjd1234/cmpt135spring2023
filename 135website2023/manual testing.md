#terminology

## Definition
Manual testing is when a human tests a piece of code "by hand", e.g. on paper. They typically run the test case and check that the result matches the expected value. Manual testing can work for small functions, but for bigger functions and programs it soon becomes very tedious and error-prone. 

Instead of manual testing, [[automated testing]] should be used whenever possible.

## Example
Suppose you are testing the function `int add(int a, int b)`. You could a the the statement `cout << add(3, 4);` to a test function, run it, and then check that `7` is printed. 