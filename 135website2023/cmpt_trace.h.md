```cpp
// cmpt_trace.h

// By defining CMPT_TRACE_H, we avoid problems caused by including 
// this file more than once: if CMPT_TRACE_H is already defined, then 
// the code is *not* included.
#ifndef CMPT_TRACE_H
#define CMPT_TRACE_H

#include <iostream>
#include <string>

namespace cmpt {

/////////////////////////////////////////////////////////////////////
//
// Trace is a helper class that is meant to be used in functions as a 
// simple debugging aid. When you create a Trace object at the start 
// of a function, it will cause a message to be printed when the 
// function is called, and also when the function ends. For example:
//
//    int fib(int n) {
//       cmpt::Trace trace("fib(" + to_string(n) + ")");
//       if (n == 0) return 1;       // base case 1
//       if (n == 1) return 1;       // base case 2
//       return fib(n-1) + fib(n-2); // recursive case
//     }
//
// The messages are indented according to how many times the function 
// has been called, and the results can be visually striking, and 
// useful (i.e. you get an idea of stack usage and the order in which 
// functions are called).
//
/////////////////////////////////////////////////////////////////////

using namespace std;

class Trace {
private:
    string start_msg;
    string end_msg;
    int incr;           // indent increment, i.e. amount to 
                        // indent/dedent messages

    static int indent;  // indent is static, and so one copy is shared 
                        // by all Trace objects

    void print_start() const;

    void print_end() const;
public:
    static const int default_incr = 3;

    Trace(const string& start_msg, const string& end_msg, int indent_size);
    Trace(const string& start_msg, const string& end_msg);
    Trace(const string& msg, int indent_size);
    Trace(const string& msg);

    int get_incr() const;
    void set_incr(int n);

    ~Trace();
}; // class Trace

} // namespace cmpt

#endif
```