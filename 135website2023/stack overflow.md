#terminology

## Definition
A stack overflow occurs when you try to push a value onto a [[stack data structure]] that is no memory left.

It's also the name of [a popular programming question-and-answer website](https://stackoverflow.com/) that some students think teachers don't know about.

## Example
This stack contains 3 elements, and doesn't have space for any more:

```
| 8 | <-- 8 is on the top of the stack
| 2 | 
| 5 | 
|___|  bottom of the stack
```

Calling, say, push(3) is a stack overflow error since there is no space on the stack to hold another number.