#terminology

## Definition
An approach to testing that puts puts the input and expected output for the function being tests into a table, e.g. a vector or array of structs. This makes it easy to add/remove test cases.

## Example
```cpp
struct Testcase {
    string input;
    string expected_output;
};

vector<Testcase> all_tests = {
    Testcase{"", ""},
    Testcase{" ", ""},
    Testcase{"  ", ""},
    Testcase{"a", "a"},
    Testcase{" a", "a"},
    Testcase{"a ", "a"},
    Testcase{" a ", "a"},
    Testcase{"ab", "ab"},
    Testcase{" ab", "ab"},
    Testcase{" ab ", "ab"},
    Testcase{"a b", "a b"},
    Testcase{" a b", "a b"},
    Testcase{" a b ", "a b"},
};

void do_tests() {
    for(Testcase tc : all_tests) {
        cout << "trim(\"" << tc.input << "\") ... ";
        string actual = trim(tc.input);
        if (actual == tc.expected_output) {
            cout << "passed\n";
        } else {
            cout << "failed:\n"
                 << "     expected \"" << tc.expected_output << "\"\n"
                 << "     returned \"" << actual << "\"\n";
        }
    }
}
```