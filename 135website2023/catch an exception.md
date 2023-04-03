#terminology

## Definition
**Catching an exception** means to use a try/catch block to handle an exception that has been thrown.

## Example
In this code, if a `std::runtime_error` exception is thrown inside the `try` part of the block, the program will jump to the `catch` part and run the code there:

```cpp
void f1() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
        delete[] arr;  // not called if there is an exception thrown above
    } catch (std::runtime_error e) {
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
        delete[] arr;  // clean up memory
    }
    cout << "f1\n";
}
```

Not that code in the `try` block that appears on lines after the one on which the exception occurred will *not* executed.

Use `catch (...)` will catch *any* exception:

```cpp
void f2() {
    int* arr = new int[10];

    try {
        error("testing 1, 2 ,3");
        delete[] arr;  // not called if there is an exception thrown above
    } catch (...) {  
        cout << "Caught a runtime exception thrown by error: " 
             << e.what() << "\n";
        delete[] arr;  // clean up memory
    }
    cout << f2finished\n";
}
```