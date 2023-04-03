---
aliases: [initialization lists, initializer list, initializer lists]
---

#terminology

## Definition
A technique used by a constructor for initializing the variables in a class. Also called an **initializer list**.

Variables initialized on an initialization are guaranteed to have sensible values inside the body of the constructor. This can help prevent errors due to uninitialized variables.
Second, some types don't work with `=`, i.e. some types cannot be assigned. For such types, writing `a = b;` doesn't even compile. When you use an initialization list, you don't use the `=`, you instead use a [[constructor]] for that type, and all values have a [[constructor]] in C++.

## Example
```cpp
class int_vec {
private:
   int capacity;
   int* arr;
   int size;

public:
   
   // default constructor 
   int_vec() 
   : capacity(10), size(0) // initializer list
   {
     arr = new int[capacity];  // of all private
   }
   
   // ...

}; 
```