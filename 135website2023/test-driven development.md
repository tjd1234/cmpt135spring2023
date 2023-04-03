#terminology 

## Definition
In test-driven development, or **TDD** for short, tests for a function are written *before* the function is implemented. The tests are based on the functions requirements, and so are usually [[blackbox testing|blackbox test cases]].

To test a function `f`, TDD proceeds as follows:

- write some tests for `f` *before* writing any code for `f`
- write `f` fully, as well as you can; use the tests you wrote in the previous step to help write the code
- run the tests on `f`
- if any tests fail, then fix `f` (or fix the test, if it's wrong) and go to the previous step
- if no tests fail, then maybe `f` is correct

Many programmers like TDD because writing the test cases first helps them
understand and implement `f`.
