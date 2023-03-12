// pow_count.cpp

#include "cmpt_error.h"
#include <cassert>
#include <iostream>

using namespace std;

// Pre-condition:
//    n >= 0
// Post-condition:
//    returns a to the power of n, i.e. a^n
int power_iter(int a, int n)
{
    // check pre-condition
    if (n < 0)
        cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0)
        return 1;
    if (a == 0 && n != 0)
        return 0;
    if (a != 0 && n == 0)
        return 1;
    if (a == 1)
        return 1;

    int pow = 1;
    for (int i = 0; i < n; i++)
    {
        pow *= a;
    }
    return pow;
}

// Pre-condition:
//    n >= 0
// Post-condition:
//    returns a to the power of n, i.e. a^n
int power_recur(int a, int n)
{
    // check pre-condition
    if (n < 0)
        cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0)
        return 1;
    if (a == 0 && n != 0)
        return 0;
    if (a != 0 && n == 0)
        return 1;
    if (a == 1)
        return 1;

    return a * power_recur(a, n - 1);
}

// Pre-condition:
//    n >= 0
// Post-condition:
//    returns a to the power of n, i.e. a^n
int power_recur_fast(int a, int n)
{
    // check pre-condition
    if (n < 0)
        cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0)
        return 1;
    if (a == 0 && n != 0)
        return 0;
    if (a != 0 && n == 0)
        return 1;
    if (a == 1)
        return 1;

    int half = power_recur_fast(a, n / 2);
    if (n % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return a * half * half;
    }
}

void test_power()
{
    cout << "test_power called ...\n";
    assert(power_iter(0, 0) == 1);
    assert(power_iter(3, 1) == 3);
    assert(power_iter(3, 2) == 3 * 3);
    assert(power_iter(3, 3) == 3 * 3 * 3);
    assert(power_iter(3, 4) == 3 * 3 * 3 * 3);
    assert(power_iter(3, 5) == 3 * 3 * 3 * 3 * 3);
    assert(power_iter(3, 6) == 3 * 3 * 3 * 3 * 3 * 3);

    assert(power_recur(0, 0) == 1);
    assert(power_recur(3, 1) == 3);
    assert(power_recur(3, 2) == 3 * 3);
    assert(power_recur(3, 3) == 3 * 3 * 3);
    assert(power_recur(3, 4) == 3 * 3 * 3 * 3);
    assert(power_recur(3, 5) == 3 * 3 * 3 * 3 * 3);
    assert(power_recur(3, 6) == 3 * 3 * 3 * 3 * 3 * 3);

    assert(power_recur_fast(0, 0) == 1);
    assert(power_recur_fast(3, 1) == 3);
    assert(power_recur_fast(3, 2) == 3 * 3);
    assert(power_recur_fast(3, 3) == 3 * 3 * 3);
    assert(power_recur_fast(3, 4) == 3 * 3 * 3 * 3);
    assert(power_recur_fast(3, 5) == 3 * 3 * 3 * 3 * 3);
    assert(power_recur_fast(3, 6) == 3 * 3 * 3 * 3 * 3 * 3);
    cout << "... test_power finished: all tests passed\n";
}

//
// Global variables are usually a bad idea, but here mult_count is a convenient
// way to count the number of multiplications performed by power_recur_fast.
//
int mult_count = 0;

int power_recur_fast_count(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;

    if (n % 2 == 0) {
       int half = power_recur_fast_count(a, n / 2);
       mult_count += 1;
       cout << 0;           // print 0
       return half * half;
    } else {
       int half = power_recur_fast_count(a, (n - 1) / 2);
       mult_count += 2;
       cout << 1;          // print 1
       return a * half * half;
    }
}

void power_test(int a, int n) {
    mult_count = 0;
    power_recur_fast_count(a, n);
	cout << " " << a << "^" << n << ", " 
         << mult_count << " multiplications\n";
}

void do_power_test() {
    for(int i = 0; i <= 20; ++i) {
        power_test(2, i);
    }
}

int main()
{
    // test_power();
    do_power_test();
}
