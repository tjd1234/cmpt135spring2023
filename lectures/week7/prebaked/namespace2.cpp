// namespace2.cpp

#include <iostream>
#include <string>

using std::cout;
using std::string;

namespace event {
// from kbd_events.cpp

// Returns true if c is a whitespace character, or a two-char code
// for a whitespace character.
bool is_whitespace(const string& c) {
    return c == " " || c == "\n" || c == "\t" || c == "\r"
        || c == "\\n" || c == "\\t" || c == "\\r";
}

} // namespace event

namespace render {
// from render.cpp

// Returns true if every character in s is a whitespace character.
bool is_whitespace(const string& s) {
    for(char c : s) {
        if (!(c == ' ' || c == '\n' || c == '\t' || c == '\r')) {
            return false;
        }
    }
    return true;
}

} // namespace render

using render::is_whitespace;

int main() {
    string test = " ";
    if (render::is_whitespace(test)) {
        cout << "test is whitespace\n";
    } else {
        cout << "test is not whitespace\n";
    }
}
