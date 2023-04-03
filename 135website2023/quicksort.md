#terminology

## Definition
Quicksort is a popular and efficient algorithm for putting the elements of a list into [[sorted order]]. On average, quicksort does $O(n \log n)$ comparisons. However, in the worst case, it does $O(n^2)$ comparisons. This worst case occurs when the data is already in [[sorted order]], or in reverse sorted order.

Quicksort works by first *partitioning* the list into two halves such that all the items on the first half of the list are less than all the items on the other half. Then it recursively sorts each half using quicksort. In practice, the partitioning can be done very quickly, and so, on average, quicksort is often fast than [[mergesort]]. 

However, [[mergesort]] is $O(n \log n)$ in the worst case. Quicksort can sometimes balloon to $O(n^2)$, which is impractically slow if $n$ is big.

One other important difference between [[quicksort]] and [[mergesort]] is that to [[mergesort]] needs an extra list of length $n$ to do its merging. Thus, to sort $n$ items, [[mergesort]] needs $2n$ space. In contrast, quicksort doesn't need any extra list, and so uses only $n$ space to sort. 

## Example
```cpp
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// returns index of the final location of pivot value
int partition(vector<int>& v, int begin, int end) {
    int p = begin;
    for (int i = begin + 1; i < end; ++i) {            
        if (v[i] <= v[p]) {
            swap(v[i], v[p + 1]);
            swap(v[p], v[p + 1]);
            ++p;
        }
    }
    return p;
}

// re-arranges the elements from v[begin] to v[end - 1] such that
// v[begin] <= v[begin + 1] <= ... <= v[end - 1]
void quicksort(vector<int>& v, int begin, int end) {
    const int n = end - begin;
    if (n <= 1) return;
    int p = partition(v, begin, end);
    quicksort(v, begin, p);
    quicksort(v, p + 1, end);
}

void quicksort(vector<int>& v) {
    quicksort(v, 0, v.size());
}
```