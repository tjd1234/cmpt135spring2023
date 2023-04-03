#terminology

## Definition
A sequence of numbers or strings (or any value that can be ordered) arranged in a linear sequence from smallest to largest.

This is synonymous with [[ascending sorted order]]. If the items are strings, then sorted order is the same as alphabetical order. 

## Example
These sequences are all in sorted order:
- [], i.e. the empty sequence
- [5]
- [5, 6]
- [5,6,8,200]
- [5,6,6,6,8,200]
- [3,3,3,3]

Here are some sequences that are *not* in sorted order:
- [5,2,3] is *not* in sorted order
- [4,3,2,1] is *not* in sorted order
- [1,2,3,4,0] is *not* in sorted order

The following C++ function tests if a `vector<int>` is in ascending sorted order:

```cpp
// returns true if v is in ascending sorted order, and false otherwise
bool is_sorted(const vector<int>& v) {
   for(int i = 1; i < v.size(); i++) {  // note i starts at 1
      if (!(v[i-1] <= v[i])) {
        return false;
      }
   }
   return true;
}