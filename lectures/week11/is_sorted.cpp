// is_sorted.cpp

//
// Read from cin one word at a time. Check that the words are in sorted order.
// All words are treated as strings.
//
// Use file redirection to read, e.g.:
//
//   > ./is_sorted < words.txt 
//   The words are in sorted order.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string quote(const string &s)
{
    return "\"" + s + "\"";
}

int main()
{
    // Read one word at a time from cin. If the current word is alphabetically
    // before the previous one, then they are not in sorted order.
    string previous;
    string current;
    while (cin >> current)
    {
        if (current < previous)
        {
            cout << "The lines are NOT in sorted order:\n";
            cout << "  " << quote(previous) << " should come after " << quote(current) << "\n";
            return 0;
        }
        previous = current;
    }
    cout << "The lines ARE in sorted order.\n";
}
