#terminology

## Definition
Property based testing tests if a function has a particular property.

## Example
Suppose that `sort(L)` returns a sorted version of list `L`, and `rev(L)` returns `L` reversed, then some properties of `sort` are:
- `sort(sort(L)) == sort(L)`, for any list `L`
- `sort(rev(L)) == sort(L)`, for any list `L`
