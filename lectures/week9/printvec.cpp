// printvec.cpp

#include <iostream>
#include <vector>

using namespace std;

//
// Write a function printvec(v) that uses recursion to
// print the elements of v, one per line, to cout.
// v is a vector<int>.
//

// print the elements of v[begin], v[begin+1], ... , v[n - 1]
void printvec(const vector<int>& v, int begin) {
    if (begin == v.size()) return;  // base case
    cout << v[begin] << "\n";
    printvec(v, begin + 1);
}
// void printvec(const vector<int>& v, int begin) {
//     if (begin < v.size()) {  // recursive case
//         cout << v[begin] << "\n";
//         printvec(v, begin + 1);
//     }
// }
// void printvec(const vector<int>& v, int begin) {
//     if (begin == v.size()) { // base case
//         return; // print nothing
//     } else {  // recursive case
//         cout << v[begin] << "\n";
//         printvec(v, begin + 1);
//     }
// }

// print the elements of v[0], v[1], ... , v[n - 1]
void printvec(const vector<int>& v) {
    printvec(v, 0);
}

int main()
{
    vector<int> v = {2, 1, 6, 4, 3};
    printvec(v);   // 2
                   // 1
                   // 6
                   // 4
                   // 3
}
