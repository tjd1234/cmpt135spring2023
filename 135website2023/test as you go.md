#terminology 

## Definition
A combination of [[test-driven development]] and [[code first development]]. When developing a function, you interleave testing and coding. For example, you could write some code for the function, write some tests, test the function, write some more code, write some tests, etc.

To test a function `f`, test-as-you-go testing proceeds as follows:

- write a little bit of `f`
- write a few tests for this partial version `f`
- run the tests on `f`
- if any tests fail, then fix `f` (or fix the test, if it's wrong) and go to the previous step
- if `f` is not fully implemented, go to the first step
- if no tests fail, then maybe `f` is correct

This approach mixes testing and coding, and in general it is the recommended approach for this course.