// sort_test.cpp

//
// Examples of how to test a sorting function.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

//
// insertion sort (taken from the web) 
//
// returns a copy of s with its characters in sorted order, e.g.
// insertion_sort("apple") returns "aelpp".
//
string insertion_sort(const string& s) {
    string result = s;
    for (int i = 1; i < result.size(); i++) {
        char c = result[i];
        // int j = i - 1;  // correct
        int j = i - 2;  // incorrect, for testing
        while (j >= 0 && result[j] > c) {
            result[j+1] = result[j];
            j--;
        }
        result[j+1] = c;
    }
    return result;
}

void if_style_testing() {
    cout << "if_style_testing ...\n";
    if (insertion_sort("") != "") {
        cout << "Test 1 failed\n";
    }
    if (insertion_sort("a") != "a") {
        cout << "Test 2 failed\n";
    }
    if (insertion_sort("aa") != "aa") {
        cout << "Test 3 failed\n";
    }
    if (insertion_sort("ab") != "ab") {
        cout << "Test 4 failed\n";
    }
    if (insertion_sort("ba") != "ab") {
        cout << "Test 5 failed\n";
    }
    if (insertion_sort("bca") != "abc") {
        cout << "Test 6 failed\n";
    }
    cout << "finished if_style_testing\n";
}

void assert_style_testing() {
    cout << "assert_style_testing ...\n";
    assert(insertion_sort("") == "");
    assert(insertion_sort("a") == "a");
    assert(insertion_sort("aa") == "aa");
    assert(insertion_sort("ab") == "ab");
    assert(insertion_sort("ba") == "ab");
    assert(insertion_sort("bca") == "abc");
    cout << "finished assert_style_testing: all tests passed\n";
}

string quote(const string& s) {
    return "\"" + s +  "\"";
}

struct Pair {
    string input;
    string expected;
};

void table_based_testing() {
    cout << "table_based_testing ...\n";

    //
    // test cases
    //
    vector<Pair> test_cases = {
        {"", ""},
        {"a", "a"},
        {"aa", "aa"},
        {"ab", "ab"},
        {"ba", "ab"},
        {"bca", "abc"},
        {"aaa", "aaa"},
        {"bbbaaaa", "aaaabbb"}
    };

    //
    // do the tests
    //
    for(Pair p : test_cases) {
        string result = insertion_sort(p.input);
        if (result != p.expected) {
            cout << "Test failed: insertion_sort(" 
                 << quote(p.input) << ")\n"
                 << "  expected: " << quote(p.expected) << "\n"
                 << "    actual: " << quote(result) << "\n ";
        }
    }

    //
    // print the results of the tests
    //
    cout << "finished table_based_testing\n";
}

// compare insertion_sort to the built-in sort
void property_style_testing() {
    cout << "property_style_testing ...\n";
    vector<string> test_strings = {
        "", "a", "aa", "ab", "ba", "acb", "aaa", "bababba",
        "one, two, three"
    };
    for(string s : test_strings) {
        string expected = s;
        sort(expected.begin(), expected.end());
        string result = insertion_sort(s);
        if (result != expected) {
            cout << "Test failed: insertion_sort(" 
                 << quote(expected) << ")\n"
                 << "  expected: "  << quote(s) << "\n"
                 << "    actual: "  << quote(result) << "\n";
        }
    }
    cout << "finished property_style_testing\n";
}

// return a random character
char rand_char() {
    const string chars = "abcdefghijklmnopqrstuvwxyz_ 0123456789";
    return chars[rand() % chars.size()];
}

// return a random string of length n
string random_string(int maxlen = 20) {
    int n = rand() % maxlen;
    string result;
    for (int i = 0; i < n; i++) {
        result += rand_char();
    }
    return result;
}

// void rand_str_test() {
//     for(int i = 0; i < 10; i++) {
//         cout << quote(random_string()) << "\n";
//     }
// }

void random_style_testing() {
    cout << "random_style_testing, 100 random test cases ...\n";
    for(int i = 0; i < 100; i++) {
        string input = random_string(5);
        string expected = input;
        sort(expected.begin(), expected.end());
        string result = insertion_sort(input);
        if (result != expected) {
            cout << "Test failed: insertion_sort(" 
                 << quote(input)   << ")\n"
                 << "  expected: " << quote(expected) << "\n"
                 << "    actual: " << quote(result) << "\n";
            return;
        }
    }
    cout << "finished random_style_testing\n";
}

int main() {
    // if_style_testing();
    // assert_style_testing();
    // table_based_testing();
    // property_style_testing();
    random_style_testing();
}
