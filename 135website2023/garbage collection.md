---
aliases: [garbage collector]
---
#terminology 

## Definition
Garbage collection refers to the process of automatically free store memory that is no longer needed. The program that does this is called a garbage collector.

Typically, a garbage collector works as a sub-process that monitors your programs memory and occasionally pauses your program in order to de-allocate unused free store memory. Some applications, such as real time systems, might not be able to use garbage collection because of these pauses.

Many modern languages, such as Python, JavaScript, Go, Java, etc., use garbage collection. In those languages, the programmer almost never needs to worry about de-allocating free store memory. Languages that use garbage collection rarely have [[memory leak|memory leaks]] or [[dangling pointer|dangling pointers]].

In contrast, C++ does **not** use garbage collection, and so requires the programmer to manually de-allocate memory. This is often more flexible and efficient than a garbage collector, but is generally more difficult to do correctly. Forgetting to de-allocate even a single value on the free store could result in a [[memory leak]].
