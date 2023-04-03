#terminology

## Definition
The idea of giving variables names that describe their type. It was used in the 1980s (and beyond) at Microsoft as a coding standard. 

The nice thing about this notation is that you know a variable's just by looking at it. However, it has a few problems. The names can be confusing and hard to remember. If a variable/function changes it's type, then the programmer must remember to change the name as well. Some variables can hold values of more than one type, e.g. in object-oriented programming an object of type `Window` is also be of type `Box` if the `Window` class inherits from the `Box` class.

Because of these sorts of problems, Hungarian notation is no longer a popular way of naming variables, and is generally discouraged.

## Example
The following variables use Hungarian notation:

```cpp
bBusy           // b means boolean
chInitial       // ch means char
dwBuff_size     // dw means double word
dbPi            // db means double
rgStudents      // rg means array (range)
fnClose         // fn means function name
```
