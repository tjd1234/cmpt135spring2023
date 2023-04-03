# Iterator
#terminology

## Definition
An object that is a generalization of a pointer. For any container-like class, you could create a corresponding iterator classes that can be used to traverse its elements.

C++ iterators are used throughout the [[STL]].

## Example
If `v` is a `vector<int>`, then `v.begin()` returns an iterator to the first element of `v`, and `v.end()` returns an iterator to one past the last element. C++ iterators can be used like pointers, e.g.:

```cpp
for(auto p = v.begin(); p < v.end(); p++) {
	cout << *p << "\n";
}
```

The iterator `p` points to an element in `v`, and `*p` is the element itself.