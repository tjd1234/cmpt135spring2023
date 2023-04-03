#terminology

## Definition
In C++, a file that ends with `.h` and typically contains just declarations (not definitions) of functions and classes. Frequently used with [[Separate compilation]].

Including the same header more than once is a serious problem in C++, and so, as in the example below, the C++ processor is often used to prevent 

## Example
Here's a sample header file called `cmpt_trace.h`:

```cpp
// cmpt_trace.h

#include <iostream>
#include <string>

class Trace {
private:
    std::string start_msg;
    std::string end_msg;
    static int indent;  
	
    void print_start() const;

    void print_end() const;
	
public:
    Trace(const std::string& start_msg, const std::string& end_msg) 
    : start_msg(start_msg), end_msg(end_msg);

    Trace(const std::string& msg) 
    : start_msg(msg), end_msg(msg)
    {
        print_start();
    }

    ~Trace();
}; // class Trace

```
This contains just the declaration of `Trace`. The implementation would likely appear in a file named `Trace.cpp`.