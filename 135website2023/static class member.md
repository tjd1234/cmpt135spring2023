#terminology

## Definition
A member variable or method in a class/struct that is defined to be `static`, which means it is part of the *class* instead of part of the object.

`::` notation is used to access static class members as shown in the example below.

## Example
In the following class, `initial_capacity` is declared `static`, which means there is only one copy of it shared by all `int_vec` objects:
```cpp
class int_vec {
	// ...
public:

static const initial_capacity = 10;

int_vec() 
: capacity(initial_capacity), arr(new int[capacity]), size(0)
{ }

// ...

}; // class int_vec
```

It makes sense for `initial_capacity` to be `static` since there is no need to store more than one copy of it for all objects.

To access `initial_capacity`, use `::` notation like this:

```cpp
cout << int_vec::initial_capacity; // prints 10
```

Notice that there is no need to create an `int_vec` object. That's because `initial_capacity` is part of the `int_vec` class, and the class is created at compile-time.