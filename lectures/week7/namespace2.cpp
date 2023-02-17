// namespace2.cpp

#include <iostream>
#include <string>

// using namespace std;
using std::cout;


// from kbd_events.cpp
namespace kbd_events { 

// Returns true if c is a whitespace character, or a two-char code
// for a whitespace character.
bool is_whitespace(const std::string& c) {
    return c == " " || c == "\n" || c == "\t" || c == "\r"
        || c == "\\n" || c == "\\t" || c == "\\r";
}

} // namespace kbd_events


namespace render {
// from render.cpp

// Returns true if every character in s is a whitespace character.
bool is_whitespace(const std::string& s) {
    for(char c : s) {
        if (!(c == ' ' || c == '\n' || c == '\t' || c == '\r')) {
            return false;
        }
    }
    return true;
}
} // namespace render

using namespace render;

int main() {
    std::string test = " ";
    if (is_whitespace(test)) {
        cout << "test is whitespace\n";
    } else {
        cout << "test is not whitespace\n";
    }
}
