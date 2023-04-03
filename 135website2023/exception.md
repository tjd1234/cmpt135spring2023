#terminology

## Definition
In C++, an **exception** is an object that represents an error, or some sort
of exceptional situation.

In C++, exceptions are said to be **thrown**, or **raised**. Exceptions are *not* returned, i.e. a function that throws an exception has said to failed, and it does not return normally. The keyword `throw` is used to throw an exception.

An exception that has been thrown can be [[catch an exception|caught]] by a try/catch block.

## Example
This function throws the standard exception `std::runtime_error`:

```cpp
void error(const string& message)
{
    throw std::runtime_error(message);
    cout << "This line is never executed!\n";
}
```