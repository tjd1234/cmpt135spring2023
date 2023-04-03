#terminology

## Definition
Binary search is a fast [[algorithm]] for finding a value in a list of values in [[sorted order]]. On a list with $n$ elements, binary search does, at most, $O(\log n)$ comparisons.

It works by first checking if the middle-most item of the list is equal to the target being searched for. If it is, then the [[algorithm]] is done. Otherwise, binary search is called on the left half of the list if that target is less than the middle-most item, and on the right-half of the list if the target is greater than the middle-most element.

## Example
```cpp
// Pre-condition: 
//   v[begin] to v[end - 1] is in ascending sorted order
// Post-condition: 
//   returns an index i such that v[i] == x and begin <= i < end; 
//   if x is not found, -1 is returned
int binary_search(int x, const vector<int>& v, int begin, int end) {
    while (begin < end) {
      int mid = (begin + end) / 2;
      if (v[mid] == x) {          // found x!
        return mid;
      } else if (x < v[mid]) {
        end = mid;
      } else if (x > v[mid]) {
        begin = mid + 1;
      }
    }
    return -1;                    // x not found
}

// Pre-condition:
//    v is in ascending sorted order
// Post-condition:
//    returns an index i such that v[i] == x; if x is not in
//    v, -1 is returned
int binary_search(int x, const vector<int>& v) {
   return binary_search(x, v, 0, v.size());
}
```

Here's a recursive implementation of binary search:

```cpp
// Pre-condition:
//    v[begin] <= v[begin+1] <= ... <= v[end - 1]
// Post-condition:
//    Returns index i such that v[i] == x; otherwise, returns -1
//    if x is not in v.
int binary_search(int x, const vector<int>& v, int begin, int end) {
   if (begin >= end) { // base case 1: range is empty
      return -1;
   } else {
      int mid = (begin + end) / 2;
      if (x == v[mid]) {  // base case 2: x is found
         return mid;
      } else if (x < v[mid]) { // recursive case 1: search left half
         return binary_search(x, v, begin, mid);
      } else if (x > v[mid]) { // recursive case 2: search right half
         return binary_search(x, v, mid + 1, end);
      }
   }
}

int binary_search(int x, const vector<int>& v) {
   return binary_search(x, v, 0, v.size());
}
```
