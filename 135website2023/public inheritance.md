#terminology

## Definition
In C++, public inheritance is when a class inherits from another class using the `public` keyword. Members that were private/public in the class being inherited from stay public/private in the inheriting class.

## Example
```cpp
class int_vec : public vector<int> {  // int_vec inherits from vector<int>
	// ...
};
```
All the methods that `int_vec` inherits from `vector<int>` have the same visibility, i.e. `public` or `private`, as they had in `vector<int>`.
