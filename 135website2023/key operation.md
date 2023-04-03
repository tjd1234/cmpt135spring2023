---
aliases: key instruction, barometer instruction, key instructions, key operations
---

#terminology

## Definition
In an [[algorithm]], a key operation is a step of the [[algorithm]] that is chosen to be counted when measuring the performance of the [[algorithm]]. Typically the key operation is executed at least as many times as any other statement in the [[algorithm]].

Also called a **key instruction**, or **barometer instruction**.

## Example
Here are a few common [[algorithm|algorithms]] and their typical key operation:
- When summing a list of numbers, addition is the key operation.
- When sorting a list of numbers or strings, comparisons using `<=` is the key operation.
- For linear search, the key operation is equality, `==`.
- For binary search, depending upon the details of the algorithm, the key operation is typically `<` or `<=`.

It is possible to get different performance results if you choose different key operations. You should always try to choose the key operation to be the one that will give you the most representative results.
