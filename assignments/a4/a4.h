// a4.h

///////////////////////////////////////////////////////////////////////////////
//
// Do not change this file in any way!
//
// Implement the requested functions. Put your implementations of the given
// functions into a4.cpp.
// 
///////////////////////////////////////////////////////////////////////////////

#ifndef A4_H
#define A4_H

// Don't #include any other files.
#include "cmpt_error.h"
#include "cmpt_trace.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n squares, i.e.
//    1^2 + 2^2 + 3^2 + ... + n^2. If n is 0, then 0 is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write
//    helper functions if necessary.
// Note:
//    There's a well-known non-recursive formula to calculate this function.
//    But don't use that formula here: the point of this question is to
//    practice using recursion.
int sum_of_squares(int n);

void sum_of_squares_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    n > 0
// Post-condition:
//    Returns the nth number of the sequence the sequence defined as follows.
//    The first number is 3, and every number after that is twice the number
//    before it plus 1. The first few numbers of the sequence are 3, 7, 15,
//    31, and so on.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    You don't need to worry about overflow sums that overflow int.
int strange_seq(int n);

void strange_seq_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if every character in s is either '0', '1', or '2'.
//    Otherwise, returns false.
//
//    If s is the empty string, true is returned.
//
//    For example, these are all ternary strings: "", "0", "1", "2", "2011120".
//    And these are not ternary strings: " ", "o", "x", " 2", "2011 120".
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    Ternary means base 3.
bool is_ternary(const string& s);

void is_ternary_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns true if s a valid string representation of an integer. For this
//    function a valid integer is defined to be a string of 1 or more digits
//    that, optionally, starts with a single '-'. No other characters are
//    allowed.
//
//    For example, is_int returns true for all these strings: "911", "-23", "0",
//    "000", "-007", "19346".
//
//    And it returns false for these ones: "", "-", "--", "0 ", " 911", "24e5",
//    "782 2", "+32", "3.14".
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
// Note:
//    When testing functions that return bool, make sure to some test cases
//    return true, and some return false.
bool is_int(const string& s);

void is_int_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a copy of s, but with all leading and trailing spaces removed.
//    No other characters are changed. For example, strip("  ab c  d ")
//    returns "ab c  d". If s is the empty string, or a string of all spaces,
//    then "" is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string strip(const string& s);

void strip_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the sum of just the negative numbers in v. If v is empty, 0 is
//    returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int sum_neg(const vector<int>& v);

void sum_neg_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    a.size() == b.size(), and a.size() > 0
// Post-condition:
//    Returns a vector equal to {max(a[0],b[0]), max(a[1],b[1]),
//    max(a[2],b[2]), ..., max(a[n-1],b[n-1])}, where n == a.size().
//
//    For example, max_vec({3, 4, 1}, {2, 5, 2}) returns the new vector 
//    {3, 5, 2}.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<int> max_vec(const vector<int>& a, const vector<int>& b);

void max_vec_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns the number of strings in v that are equal to s.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
int count(const vector<string>& v, const string& s);

void count_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    s.size() == t.size()
// Post-condition:
//    Returns a vector<string> where the first string is the first character
//    of s followed by the first character of t, the second string is the
//    second character of s followed by the second character of t, and so on.
//    For example, zip("abc", "xyz") returns {"ax", "by", "cz"}.
//
//    If both s and t are empty, then an empty vector<string> is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<string> zip(const string& s, const string& t);

void zip_test();

///////////////////////////////////////////////////////////////////////////////
//
// Pre-condition:
//    none
// Post-condition:
//    Returns a string consisting of all the strings in v concatenated
//    together with sep after each string (except for the last). 
//
//    For example, join({"cat", "dog", "house"}, ", ") returns "cat, dog,
//    house", join({"he", "we", "see"}, "-") returns "he-we-see", and
//    join({"he", "we", "see"}, "") returns "hewesee".
//
//    For example:
//    - join({"one"}, ", ") returns "one"
//    - join({"up", "dog"}, ", ") returns "up, dog"
//    - join({"he", "we", "see"}, "-") returns "he-we-see"
//    - join({"he", "we", "see"}, "") returns "hewesee".
//
//    If v is empty, the empty string is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
string join(const vector<string>& v, const string& sep);

void join_test();

#endif
