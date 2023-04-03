#terminology

## Definition
A smart pointer is an object that acts very much like a regular "raw" pointer (such as `int*`), except it has a [[destructor]] that is guaranteed to always correctly delete memory. 

These can be extremely useful in practice, although they do require learning new ways of using pointers.

## Example
`unique_ptr<T>` is standard a smart pointer that points to an object of type `T`. It is unique in the sense that it guarantees that it is the only pointer pointing to the object, and so it is always safe to delete the object it is pointing. To ensure uniqueness, there are special rules that restrict how `unique_ptr<T>` can be used. For example, you **cannot copy** a `unique_ptr`, because then there would be more than one pointer pointing to the object.
