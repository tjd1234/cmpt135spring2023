// int_vec.cpp

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

class int_vec : public vector<int> {
    string name;
public:
    // constructor requires a name
    int_vec(const string& s)
    : vector<int>(),  // call default constructor of vector<int>
      name(s)
    { }

    // name getter
    string get_name() const { return name; }

    int sum() const {
        return std::accumulate(begin(), end(), 0);
    }

    void sort_increasing() {
        std::sort(begin(), end());
    }

}; // class int_vec

void summarize(const vector<int>& v) {
    cout << "\n";
    cout << "Summary:\n";
	for(int i = 0; i < v.size(); i++) {
		cout << "v[" << i << "] = " << v[i] << "\n";
	}
	cout << "size: " << v.size() << "\n";
}

void fancy_summarize(const int_vec& v) {
    cout << "\n";
    cout << "Fancy Summary of " << v.get_name() << ":\n";
	cout << v.get_name() << ":\n";
	for(int n : v) cout << "   " << n << "\n";
	cout << "sum = " << v.sum() << "\n";
}

int main() {
    int_vec v("Table 1");

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);

    v.sort_increasing();
    cout << v.get_name() << ":\n";
    for(int n : v) cout << n << "\n";
    cout << "sum = " << v.sum() << "\n";

    summarize(v);
    fancy_summarize(v);
} // main
