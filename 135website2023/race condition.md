# Race Condition
#terminology

## Definition
In a [[concurrent program]], a race condition occurs when two or more threads of control try to access the same memory and, depending upon which one access it first, different behavior can occur. Bugs caused by race conditions can appear at random (and so can be hard to re-create), and are often challenging to fix.

The term "race condition" is sometimes used as a general description of any bug that might occur in a [[concurrent program]] due to the concurrency.

## Example
Imagine a computer using two CPUs, and at the same time both CPUs want to update a record in a database. It could happen that while one CPU is in the middle of updating the record, the other CPU starts to update it as well, thus over-writing the first CPU's update.