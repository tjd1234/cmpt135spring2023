// sample_questions.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

//
// pluralization
//

string pluralize(const string& s) {
    if (s == "") return "";
    int n = s.size();
    char last = s[n - 1];
    switch (last) {
        case 's': return s;
        case 'y': return s.substr(0, n - 1) + "ies";
        default : return s + "s";
    }
}

vector<string> pluralize_all(const vector<string>& v) {
    vector<string> result(v);
    for(int i = 0; i < result.size(); i++) {
        result[i] = pluralize(result[i]);
    }
    return result;
}

void pluralize_test() {
    assert(pluralize("") == "");
    assert(pluralize("birds") == "birds");
    assert(pluralize("try") == "tries");
    assert(pluralize("dog") == "dogs");

    vector<string> words   = {"", "birds", "try",   "dog"};
    vector<string> correct = {"", "birds", "tries", "dogs"};
    assert(pluralize_all(words) == correct);

    cout << "all pluralize tests passed\n";
}

//
// joining a vector<T>
//

string to_string(const string& s) { return s; }

template <typename T>
string join(const vector<T>& v, const string& sep = ", ") {
    if (v.empty()) return "";
    string result = to_string(v[0]);
    for(int i = 1; i < v.size(); i++) {
        result += sep + to_string(v[i]);
    }
    return result;
}

void join_test() {
    assert(join(vector<int>()) == "");
    assert(join(vector<int>{15}) == "15");
    assert(join(vector<int>{15, -2}) == "15, -2");
    assert(join(vector<int>{15, -2, 6}, "::") == "15::-2::6");

    assert(join(vector<string>{"one", "two", "three"}, "...")
                ==
                "one...two...three");

    cout << "all join tests passed\n";
}


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{" << join(v) << "}";
    return out;
}


//
// Is a vector<int> in ascending sorted order?
//
// An empty vector is considered to be in sorted order.
//

// loop version
bool is_sorted(const vector<int>& v) {
    int n = v.size();
    if (n < 2) return true;

    // v has at least 2 elements
    for (int i = 1; i < n; i++) { // note i starts at 1
        if (v[i-1] > v[i]) return false;
    }
    return true;
}

void is_sorted_test() {
    assert(is_sorted({}));
    assert(is_sorted({9}));
    assert(is_sorted({2, 9}));
    assert(is_sorted({2, 2}));
    assert(is_sorted({2, 9, 14}));

    assert(!is_sorted({9, 2}));
    assert(!is_sorted({20, 9, 14}));
    assert(!is_sorted({2, 9, 14, 1}));

    cout << "all is_sorted tests passed\n";
}

// recursive version
bool is_sorted_rec(const vector<int>& v, int begin) {
    int n = v.size();
    if (begin == n) return true; // check for empty sub-vector
    if (begin == n-1) return true; // check for single-int sub-vector
    
    // at this point, n >= 2
    return v[begin] <= v[begin + 1]
        && is_sorted_rec(v, begin + 1);
}

bool is_sorted_rec(const vector<int>& v) {
    return is_sorted_rec(v, 0);
}

void is_sorted_rec_test() {
    assert(is_sorted_rec({}));
    assert(is_sorted_rec({9}));
    assert(is_sorted_rec({2, 9}));
    assert(is_sorted_rec({2, 2}));
    assert(is_sorted_rec({2, 9, 14}));

    assert(!is_sorted_rec({9, 2}));
    assert(!is_sorted_rec({20, 9, 14}));
    assert(!is_sorted_rec({2, 9, 14, 1}));

    cout << "all is_sorted_rec tests passed\n";
}

//
// Does a vector<int> have any duplicate values?
//
// An empty vector is considered to not have any duplicates.
//

// This version does O(n^2) comparisons.
bool all_diff1(const vector<int>& v) {
    int n = v.size();
    if (n < 2) return true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) return false;
        }
    }
    return true;
}

void all_diff1_test() {
    assert(all_diff1({}));
    assert(all_diff1({5}));
    assert(all_diff1({5, 10}));
    assert(all_diff1({3, 2, 20}));

    assert(!all_diff1({5, 5}));
    assert(!all_diff1({10, 5, 10}));
    assert(!all_diff1({3, 2, 2, 20}));

    cout << "all all_diff1 tests passed\n";
}

//
// This version does O(n log n) comparisons for the sort, and then O(n)
// comparisons looking for adjacent ints that are the same.
//
// v is passed by value so we don't modify the order of the elements in the
// passed-in vector.
bool all_diff2(vector<int> v) {
    sort(v.begin(), v.end());

    // if v has any duplicates, then they will be adjacent to each other
    for(int i = 1; i < v.size(); i++) {  // note i starts at 1
        if (v[i-1] == v[i]) return false; // found duplicates
    }
    return true;
}

void all_diff2_test() {
    assert(all_diff2({}));
    assert(all_diff2({5}));
    assert(all_diff2({5, 10}));
    assert(all_diff2({3, 2, 20}));

    assert(!all_diff2({5, 5}));
    assert(!all_diff2({10, 5, 10}));
    assert(!all_diff2({3, 2, 2, 20}));

    cout << "all all_diff2 tests passed\n";
}

//
// Recursive linear search on a vector<int>.
//
// Return -1 if the target value is not found.
// If the there's more than one copy of the target in the
// vector, return the left-most one.
//
int linear_search(int x, const vector<int>& v, int begin) {
    if (begin >= v.size()) {
        return -1;
    } else if (v[begin] == x) {
        return begin;
    } else {
        return linear_search(x, v, begin + 1);
    }
}

int linear_search(int x, const vector<int>& v) {
    return linear_search(x, v, 0);
}

void linear_search_test() {
    assert(linear_search(3, {}    ) == -1);
    assert(linear_search(3, {3}   ) ==  0);
    assert(linear_search(3, {1}   ) == -1);
    assert(linear_search(3, {6, 4}) == -1);
    assert(linear_search(6, {6, 4}) ==  0);
    assert(linear_search(4, {6, 4}) ==  1);

    cout << "all linear_search tests passed\n";
}

//
// Returns a copy of v but with all x values removed from it.
//
vector<int> remove_all(const vector<int>& v, int x) {
    vector<int> result;
    for(int n : v) {
        if (n != x) {
            result.push_back(n);
        }
    }
    return result;
}

void check_remove_all(const vector<int>& in, int x, 
                      const vector<int>& expected) 
{
    vector<int> result = remove_all(in, x);
    if (result != expected) {
        cout << "error: remove_all(" << in << ") returned " << result 
             << ", expected " << expected << "\n";
    }
}

void remove_all_test() {
    check_remove_all({ }, 4, 
                     { });
    check_remove_all({4}, 4, 
                     { });
    check_remove_all({2}, 4, 
                     {2});
    check_remove_all({4, 4}, 4, 
                     { });
    check_remove_all({1, 4, 3}, 4, 
                     {1, 3});
    check_remove_all({3, 9, 0, 3, 2, 2, -3}, 3, 
                     {9, 0, 2, 2, -3});

    cout << "all remove_all tests passed\n"; 
}


// Returns true if c is a vowel, and false otherwise.
bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// Returns true iff s contains one, or more, vowels.
bool has_vowel(const string& s) {
    for (char c : s) {
        if (is_vowel(c)) return true;
    }
    return false;
}

// Returns a new vector<string> contain just strings with one or more vowels.
vector<string> keep_vowels(const vector<string>& v) {
    vector<string> result;
    for(string s : v) {
        if (has_vowel(s)) result.push_back(s);
    }
    return result;
}

void check_keep_vowels(const vector<string>& in,
                       const vector<string>& expected) 
{
    vector<string> result = keep_vowels(in);
    if (result != expected) {
        cout << "error: keep_vowels(" << in << ") returned " << result 
             << ", expected " << expected << "\n";
    }
}

void keep_vowels_test() {
    check_keep_vowels({"apple"}, 
                      {"apple"});
    check_keep_vowels({"hmmph!"}, 
                      {});
    check_keep_vowels({"apple", "eau"}, 
                      {"apple", "eau"});
    check_keep_vowels({"apple", "grr", "fly", "orange"}, 
                      {"apple", "orange"});
    cout << "all keep_vowels tests passed\n";
}

// Returns true if s occurs 1 or more times in v.
bool contains(const vector<string>& v, const string& s) {
    for(int i = 0; i < v.size(); i++) {
        if (s == v[i]) return true;
    }
    return false;
}

vector<string> intersection(const vector<string>& v, 
                            const vector<string>& w) 
{
    vector<string> result;
    for(int i = 0; i < v.size(); i++) {
        if (contains(w, v[i])) result.push_back(v[i]);
    }  
    return result;
}

void check_intersection(const vector<string>& v, 
                        const vector<string>& w,
                        const vector<string>& expected) 
{
    vector<string> result = intersection(v, w);
    if (result != expected) {
        cout << "error: intersection(" << v << ", " << w << ")"
             << " returned " << result 
             << ", expected " << expected << "\n";
    } 
}

void intersection_test() {
    check_intersection({}, {}, 
                       {});
    check_intersection({"a", "b", "c"}, {"A", "z", "222", " "}, 
                       {});
    check_intersection({"a", "bc", "def"}, {"def", "up", "a", "cat"}, 
                       {"a", "def"});
    check_intersection({"a", "bc", "def"}, {"def", "a", "bc"}, 
                       {"a", "bc", "def"});
    cout << "all intersection tests passed\n";
}

// Returns true if x occurs 1 or more times in v.
//
// O(n) comparisons in the worst case
template <typename T>
bool contains(const vector<T>& v, const T& x) {
    for(int i = 0; i < v.size(); i++) {
        if (x == v[i]) return true;
    }
    return false;
}

// Returns true if every element in v also occurs in w.
//
// O(n^2) comparisons in the worst case, because, in the worst-case, the loop
// runs n times, and for each of those times O(n) comparisons are done by
// contain(w, v[i]).
template <typename T>
bool contains_all(const vector<T>& v, const vector<T>& w) {
    for(int i = 0; i < v.size(); i++) {
        if (!contains(w, v[i])) return false;
    }
    return true;
}

// Returns true if v and w are the same, i.e. have the same elements but not
// necessarily in the same order.
//
// O(n^2) comparisons in the worst case because contains_all is O(n^2) and is
// called twice, so it does O(n^2) + O(n^2), which simplifies to O(n^2).
template <typename T>
bool same1(const vector<T>& v, const vector<T>& w) {
    return contains_all(v, w) && contains_all(w, v);
}

// Returns true if v and w are the same, i.e. have the same elements but not
// necessarily in the same order.
//
// O(n log n) comparisons in the worst case because std::sort does O(n log n)
// comparisons and is called twice, so it does O(n log n) + O(n log n), which
// simplifies to O(n log n). Also note that the v and w are passed by value,
// which accounts for O(n) + O(n) more time, or O(n) in total. Since O(n) is
// dominated by O(n log n) as n approaches infinity, the expression O(n) + O(n
// log n) simplifies to O(n log n).
template <typename T>
bool same2(vector<T> v, vector<T> w) {
    std::sort(v.begin(), v.end());
    std::sort(w.begin(), w.end());
    return v == w;
}

void check_same(const vector<int>& v, const vector<int>& w,
                bool expected) 
{
    bool result1 = same1(v, w);
    if (same1(v, w) != expected) {
        cout << "error: same1(" << v << ", " << w << ")"
             << " returned " << result1 
             << ", expected " << expected << "\n";
    }

    bool result2 = same2(v, w);
    if (same2(v, w) != expected) {
        cout << "error: same2(" << v << ", " << w << ")"
             << " returned " << result2
             << ", expected " << expected << "\n";
    }
}

void same_test() {
    check_same({}, {}, true);
    check_same({2}, {2}, true);
    check_same({2, 3}, {2, 3}, true);
    check_same({2, 3}, {3, 2}, true);
    check_same({1, 2, 3, 4, 5}, {2, 3, 1, 5, 4}, true);

    check_same({}, {5}, false);
    check_same({5}, {}, false);
    check_same({5}, {6}, false);
    check_same({2, 3}, {2, 3, 1}, false);
    check_same({2, 1, 3}, {2, 3}, false);
    check_same({1, 2, 4, 5}, {2, 3, 1, 5, 4}, false);
    cout << "all same tests passed\n";
}


int main() {
    pluralize_test();
    join_test();
    is_sorted_test();
    is_sorted_rec_test();
    all_diff1_test();
    all_diff2_test();
    linear_search_test();
    remove_all_test();
    keep_vowels_test();
    intersection_test();
    same_test();
}
