// scratch.cpp

//
// ❯ make scratch
// g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   scratch.cpp   -o scratch
//
// ❯ ./scratch
// Hello World!
//

#include <iostream>

using namespace std;

void summarize(const vector<int>& v) {
	for(int i = 0; i < v.size(); i++) {
		cout << "v[" << i << "] = " << v[i] << "\n";
	}
	cout << "size: " << v.size() << "\n";
}

int main() {
    cout << "Hello World!\n";
}
