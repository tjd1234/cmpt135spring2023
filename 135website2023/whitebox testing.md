---
aliases: [clear box testing, glass box testing, transparent box testing]
---

#terminology

## Definition
Whitebox testing is when you write tests that are created by taking into account the implementation details of a function. In contrast to [[blackbox testing]], you can only write whitebox tests for code that has been written.

Also known as **clearbox testing**.

## Example
Consider this function:
```cpp
string trim(const string& s) {
    int begin = 0;
    while (begin < s.size() && s[begin] == ' ') ++begin;
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ') --end;
    return s.substr(begin, end - begin + 1);
}
```

By looking at the code, you can create [[test]] cases that, for instance, make sure every part of the code is executed at least once.