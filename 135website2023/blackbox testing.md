#terminology

## Definition
Blackbox testing is when you create tests without knowing (or looking at) a function's implementation. With [[blackbox testing]], you create tests just by considering the function's *requirements*. This allows test cases to be created *before* the function is written. 

Compare this to [[whitebox testing]], where tests are created by looking at the implementation of the function.

## Example
Suppose the function `string to_upper(string s)` is meant to convert all lowercase alphabetic characters to upper case. Based on this description alone, you could write these [[test]]s:
- `to_upper('abC12z')` should return `'ABC12z'`
- `to_upper('2+5')` should return `'2+5'`
- `to_upper('')` should return `''`
