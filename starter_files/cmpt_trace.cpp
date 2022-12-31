// cmpt_trace.cpp

#include "cmpt_trace.h"
#include <iostream>
#include <string>

namespace cmpt {

using namespace std;

// static variables are initialized outside their class
int Trace::indent = 0;

void Trace::print_start() const {
    cout << string(indent, ' ') << start_msg << " ...\n";
    indent += incr;
}

void Trace::print_end() const {
    indent -= incr;
    cout << string(indent, ' ') << "... " << end_msg << "\n";
}

Trace::Trace(const string& start_msg, const string& end_msg, int indent_size) 
: start_msg(start_msg), end_msg(end_msg)
{
    set_incr(indent_size);
    print_start();
}

Trace::Trace(const string& start_msg, const string& end_msg) 
: Trace{start_msg, end_msg, default_incr}
{ }

Trace::Trace(const string& msg, int indent_size) 
: Trace{msg, msg, indent_size}
{ }

Trace::Trace(const string& msg) 
: Trace{msg, msg, default_incr}
{ }

int Trace::get_incr() const { return incr; }

void Trace::set_incr(int n) {
    incr = max(0, n);
}

Trace::~Trace() {
    print_end();
}

} // namespace cmpt
