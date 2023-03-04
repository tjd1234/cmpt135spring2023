// scratch.cpp

//
// ❯ make scratch
// g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   scratch.cpp   -o scratch
//
// ❯ ./scratch
// Hello World!
//

#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& v, int begin) {
    if (begin == v.size()) {
        return 0;
    } else {
        return v[begin] + sum(v, begin + 1);
    }
}

int sum(const vector<int>& v) {
    return sum(v, 0);
}

int main() {
    vector<int> nums = {4, 1, 7, 3};
    cout << sum(nums) << "\n"; // 15
}

