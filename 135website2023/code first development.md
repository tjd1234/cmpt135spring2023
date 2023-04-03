#terminology 

## Definition
A kind of [[unit testing]] where the function to be tested is written first, and then, after it's written, test cases are created and run on it. While this approach can work fine for small functions, it is not so good for big or tricky functions since the testing comes too late.

Code-first testing for a function `f` proceeds as follows:
- implement `f` fully, as well as you can
- then write some tests for `f`
- run the tests on `f`
- if any tests fail, then fix `f` (or fix the test, if it's wrong) and go to the previous step
- if no tests fail, then maybe `f` is correct
