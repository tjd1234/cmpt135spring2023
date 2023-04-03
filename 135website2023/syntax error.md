#terminology

## Definition
A **syntax error** is an error related to the grammatical, i.e. syntactic structure of program. Errors that occur during [[Parser|parsing]] are usually syntax errors.

## Examples
There are four syntax errors in this code fragment, one on each line:

```cpp
int a = 5    // syntax error: missing semi-colon
int b = ;    // syntax error: missing initial value
c int;       // syntax error: type comes before variable
int d = 3;   / syntax error: wrong comment token
```
