// moms.cpp

#include <iostream>
#include <string>

using namespace std;

// MOMS is a "recursive acronym"
// MOMS = MOMS Offering MOMS Support
string moms(int n) {
    if (n == 1) {
        return "moms offering moms support";
    } else {
        string sub = moms(n - 1);
        return sub + " offering " + sub + " support";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " n\n";
        return 1;
    }
    int n = stoi(argv[1]);
    cout << moms(n) << "\n";
}
