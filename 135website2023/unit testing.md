#terminology 

## Definition
Testing individual functions for correctness. You don't need a complete working program to do unit testing, you can test functions as you create them. Compare this to [[system testing]], where an entire program is tested.

Unit testing could be done using [[blackbox testing]] or [[whitebox testing]], or a combination of both.

## Example
```cpp
string trim(const string& s) {
    int begin = 0;
    while (begin < s.size() && s[begin] == ' ') ++begin;
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ') --end;
    return s.substr(begin, end - begin + 1);
}
```
Some units tests for `trim` are:
- `trim('')` should return `''`
- `trim('  ')` should return `''`
- `trim('abc')` should return `'abc'`
- `trim('  abc')` should return `'abc'`
- `trim('abc ')` should return `'abc'`
- `trim('  abc   ')` should return `'abc'`
- `trim('  a b  c   ')` should return `'a b  c'`