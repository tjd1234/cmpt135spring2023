// parsing.cpp

#include <iostream>
#include <string>
#include <cassert>
#include "cmpt_error.h"

using namespace std;

// Takes a string of the form "a + b", where a and b are ints, 
// and returns their sum. For example, "4 + 10" returns 14.
int eval(const string& s) {
    // find the position of the '+'
    int plus_loc = s.find('+');
    if (plus_loc == string::npos) cmpt::error("eval: + not found");

    // get a and b as their own strings
    string a = s.substr(0, plus_loc);
    string b = s.substr(plus_loc + 1);

    // convert a and b to ints using the standard function stoi
    // (string to int)
    int result = stoi(a) + stoi(b);

    return result;
}

// test the eval function using asserts
void eval_test() {
    cout << "calling eval_test()...\n";
    assert(eval("3 + 10") == 13);
    assert(eval("1 + -5") == -4);
    assert(eval("  8+    3   ") == 11);
    assert(eval("-4 + -10") == -14);
    assert(eval("0 + 0") == 0);
    cout << "eval_test() passed!\n";
}

void eval_demo() {
    cout << "eval(\"3 + 10\") = " << eval("3 + 10") << endl;
    cout << "eval(\"1 + -5\") = " << eval("1 + -5") << endl;
    cout << "eval(\"  8+    3   \") = " << eval("  8+    3   ") << endl;

    // some inputs cause stoi to throw an exception ...
    cout << eval("+3");
    // cout << eval(" 2 + 39043090300473");
}

void print_safe(const string& s) {
    try {
        int result = eval(s);
        cout << "result = " << result << "\n";
    } catch (std::invalid_argument& e) {
        cout << "error: one, or both, of the operands of \"" 
             << s << "\"\n"
             << "       is not a valid int\n";
    } catch (std::out_of_range& e) {
        cout << "error: one, or both, of the operands of \"" 
             << s << "\"\n"
             << "       are outside the range of an int\n";    
    } catch (...) {
        cout << "error: an unknown error has occurred\n"
             << "       with input \"" << s << "\"\n";
    }
}

void test_safe() {
    print_safe("11  +33");
    print_safe("two + 3");
    print_safe("2 + 39043090300473");
    print_safe("cow");
}

int main() {
    eval_demo();
    // test_safe();
}
