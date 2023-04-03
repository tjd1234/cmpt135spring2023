
## A Problem: Sending Information Securely on the Web
When you send your login password to your bank, what stops hackers from copying it as travels across the internet? Anything you send on the web could be read or copied by many computers you know nothing about.

To protect sensitive information, like a password, you could **encrypt** it. For example, suppose `password.txt` contain password that you want to send to your bank over the web. Before sending it, you could encrypt it:

```shell
❯ cat password.txt 
swordfish

❯ ccencrypt password.txt 
Enter encryption key: honeybee
Enter encryption key: (repeat) 

❯ cat password.txt.cpt 
��[��d�d#���3�;4�g�⏎   

❯ ccdecrypt password.txt.cpt 
Enter decryption key: honey

❯ cat password.txt
swordfish
```

> If you want to try `ccencrypt`/`ccdecrypt` on your own, you can install it in Ubuntu Linux with the shell command: `sudo apt install ccrypt`

Modern encryption tools like `ccencrypt` are pretty good: the encrypted password can only practically be read if you have the encryption key (i.e. the password string `honeybee`). In other words, if you only have the encrypted file `password.txt.cpt`, it will be extremely difficult to determine that the password is `swordfish`.

So if an evil hacker gets a copy of your encrypted password, you are probably safe.

> **Careful** If you use an easy-to-guess, or very short, encryption key, then a hacker might be able to guess it. Indeed, if your key is a single English word, then it is relatively easy to guess: a hacker could try a dictionary of all English words to see if any work. 
> 
> This is why websites often insist that passwords be more than 8 characters long, and include special characters, like digits or punctuations. Such passwords are much harder to guess.

But there is a problem: how do you communicate the *encryption key* to the site you are sending it to so that they can decrypt your password? If you are sending `password.txt` to your bank, how does your bank get the encryption key `honeybee`? You have to send them the key somehow, and if you send it unencrypted then hackers could copy it. If you encrypt the key, then that encryption needs its own key: how do you send *that* key? There is no immediately obvious way around this problem.

The [RSA Cryptosystem](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) solves this problem using a clever idea called [public key cryptography](https://en.wikipedia.org/wiki/Public-key_cryptography). Basically, the *bank* makes a carefully constructed **public key** that anyone can use to encrypt a message that only the bank can decrypt it. The bank does the decryption with a **private key** that they don’t share with anyone else. To send `password.txt` to the bank, you use the banks public encryption key to encrypt the file.

We won’t go into the mathematical details of [RSA](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) other than to point out that one part the [RSA](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) algorithms requires calculating a large integer power like this: $a^{65537}$.

## Calculating Large Integer Powers Efficiently

How would you calculate $a^{65537}$ *efficiently*? How multiplications are needed?

## Some Special Cases
There are a few simple cases for calculating powers that can be handled individually:

- $a^0$ is 1 if $a \neq 0$
- $0^n$ is 0 if $n \neq 0$
- $1^n$ is 1 if $n \neq 0$
- $a^1$ is $a$ if $a \neq 0$
- $0^0 = 1$ ([although sometimes it is said to be undefined](https://en.wikipedia.org/wiki/Exponentiation#Zero_to_the_power_of_zero))

In the following discussing we will assume these special cases are all taken care of, and won't worry about them.

## The Obvious Approach (Iterative)
The "obvious" way to calculate $a^n$ is to multiple $a$ by itself $n-1$ times. Here is how to do iteratively i.e. using a loop:

```cpp
// Pre-condition: 
//    n >= 0
// Post-condition: 
//    returns a to the power of n, i.e. a^n
// Note: 
//    The bases cases can be compressed somewhat. However, we list 
//    them individually to make it easier to see that all the cases 
//    have been handled.
int power_iter(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;
    
    int pow = 1;
    for(int i = 0; i < n; i++) {
        pow *= a;
    }
    return pow;
}
```

Note the use of [[contract|contracts]] to specify what the function ought to do.

Here's the same [[algorithm]] implemented using [[recursion]]:

```cpp
int power_recur(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;
    
    return a * power_recur(a, n - 1);
}
```

While the source code is shorter than `power_iter`, it's a little less efficient since each call to `power_recur` uses some time and [[stack memory|call stack]] memory.

## A Note on Testing
One way to test these power functions is with [[property based testing]], and to test that basic properties of powers hold: 
- $a^{m+n} = a^m\cdot a^n$. So `power_iter(a, m+n) == power_iter(a, m) * power_iter(a, n)` should  be true for any non-negative `int`s `m` and `n`.
- $(a^m)^n = a^{mn}$. So `power_iter(power_iter(a, m), n) == power_iter(a, m*n)` should  be true for any non-negative `int`s `m` and `n`.

## Performance of the Obvious Approach
For both the iterative and recursive versions of the obvious approach, we can estimate its performance as follows: 

- $a^2 = a \cdot a$ does 1 multiplication
- $a^3 = a \cdot a \cdot a$ does 2 multiplications
- $a^4 = a \cdot a \cdot a \cdot a$ does 3 multiplications
- ...
- $a^n = a \cdot a \cdot \ldots a \cdot a$ does $n-1$ multiplications (for $n > 1$).

In general, the obvious approach does $n - 1$ multiplications to calculate $a^n$. The number of multiplications is *proportional* to the running time of the functions. For example, calculating $a^{2n}$ takes about twice as many multiplications as $a^n$.

## A Faster Algorithm
The obvious algorithm shows that it is possible to calculate $a^n$ using about $n$ multiplications. But can we do better? Is there an algorithm that does fewer multiplications in general?

It turns out there is. Take a look at these calculations:

$a \cdot a = a^2$
$a^2 \cdot a^2 = a^4$

Only 2 multiplications were needed to get $a^4$. That's one less than the number of multiplications done by the obvious algorithm.

It gets better. For example, $a^4 \cdot a^4 = a^8$, needs only 1 more multiplication for a total of 3 (instead of 7 for the obvious algorithm). $a^8 \cdot a^8 = a^{16}$, needs only 1 more multiplication for a total of 4 (instead of 15 for the obvious algorithm).

These examples show that **repeated squaring** can, at least sometimes, be used to calculate $a^n$ using fewer multiplications than the obvious algorithm.

By repeated squaring we can quickly calculate $a^n$ when $n$ is a power of 2, but what about other values of $n$?

It turns out we can make this trick work with any positive $n$. The idea is distinguish when $n$ is even, and when $n$ is odd. When $n$ is even, we can use the squaring trick; when it's odd, we can do one extra multiplication and then a squaring.

More precisely, when $n=2k$, to calculate $a^{2k}$, we can square $a^k$ (and recursively calculate $a^k$). When $n=2k+1$, we can't get $a^{2k+1}$ by squaring. However, we can re-arrange it like this: $a^{2k+1} = a \cdot a^{2k}$. So to calculate $a^{2k+1}$ we can square $a^k$ and multiply that by $a$.

Mathematically, we could describe this using this recurrence relation (assuming $a$ and $n$ are both non-negative integers):

$$
a^n = 
\begin{cases}
0 & \text{if $a = 0$ and $n \neq 0$} \\
1 & \text{if $n = 0$} \\
a^{n/2} \cdot a^{n/2}  & \text{if $n$ is even} \\
a \cdot a^{n/2} \cdot a^{n/2} & \text{if $n$ is odd}
\end{cases}
$$

Here's a recursive implementation in C++:

```cpp
int power_recur_fast(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;

    int half = power_recur_fast(a, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}
```

**Be careful**: the expression `n / 2` in `power_recur_fast` is **integer division**. That means it evaluates to an `int`. So `10 / 2` is 5, and `11 / 2` is also 5. `11 / 2` is 5 because C++ always chops off (**truncates**) any digits after the decimal point in the result of `n / 2`. For example:

 ```
-5 / 2 == -2
-4 / 2 == -2
-3 / 2 == -1
-2 / 2 == -1
-1 / 2 == 0
 0 / 2 == 0
 1 / 2 == 0
 2 / 2 == 1
 3 / 2 == 1
 4 / 2 == 2
 5 / 2 == 2
```

## Counting Multiplications
How much faster is this "repeated squaring" version than the obvious power algorithm? In other words, how many multiplications does `power_recur_fast` do? It is not obvious from looking at the algorithm, and so lets add some extra code to actually count how many multiplications it does:

```cpp
int mult_count = 0;

int power_recur_fast(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative"); 

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;

    if (n % 2 == 0) {
        int half = power_recur_fast(a, n / 2);
        mult_count += 1;
        return half * half;
    } else {
        int half = power_recur_fast(a, (n - 1) / 2);
        mult_count += 2;
        return a * half * half;
    }
}

void power_test(int a, int n) {
    mult_count = 0;
    power_recur_fast(a, n);
	cout << " " << a << "^" << n << ", " 
         << mult_count << " multiplications\n";
}
```

Here's some test code:

```cpp
for(int i = 0; i <= 20; ++i) {
    power_test(2, i);
}
```

And its output:

```
2^0, 0 multiplications
2^1, 2 multiplications
2^2, 3 multiplications
2^3, 4 multiplications
2^4, 4 multiplications
2^5, 5 multiplications
2^6, 5 multiplications
2^7, 6 multiplications
2^8, 5 multiplications
2^9, 6 multiplications
2^10, 6 multiplications
2^11, 7 multiplications
2^12, 6 multiplications
2^13, 7 multiplications
2^14, 7 multiplications
2^15, 8 multiplications
2^16, 6 multiplications
2^17, 7 multiplications
2^18, 7 multiplications
2^19, 8 multiplications
2^20, 7 multiplications
```

When $n$ is big, the number of multiplications being done is less then for the obvious algorithm (obviously!)

Is there a pattern to the number of multiplications? Look for a moment at the sequence of multiplications: 0, 2, 3, 4, 4, 5, 5, 6, 5, 6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, .... Notice that the numbers don't always increase --- sometimes they go down!

It turns out to be useful to print a message when each part of the if-statement is called:

```cpp
int power_recur_fast(int a, int n) {
    // check pre-condition
    if (n < 0) cmpt::error("exponent must be non-negative");

    if (a == 0 && n == 0) return 1;
    if (a == 0 && n != 0) return 0;
    if (a != 0 && n == 0) return 1;
    if (a == 1) return 1;

    if (n % 2 == 0) {
       int half = power_recur_fast(a, n / 2);
       mult_count += 1;
       cout << 1;           // print 1
       return half * half;
    } else {
       int half = power_recur_fast(a, (n - 1) / 2);
       mult_count += 2;
       cout << 2;          // print 2
       return a * half * half;
    }
}

void power_test(int a, int n) {
    mult_count = 0;
    power_recur_fast(a, n);
	cout << " " << a << "^" << n << ", " 
         << mult_count << " multiplications\n";
}
```

The output is:

```
2
21
22
211
212
221
222
2111
2112
2121
2122
2211
2212
2221
2222
21111
21112
21121
21122
21211
```

Can you see a pattern in these values?

It might be easier to see if you change 1s to 0s and 2s to 1s:

```
1
10
11
100
101
110
111
1000
1001
1010
1011
1100
1101
1110
1111
10000
10001
10010
10011
10100
```

These are the [[binary number|binary numbers]] from 1 to 20 (!). In addition to (quickly) calculating powers, we've also apparently created an algorithm that generates the [[binary number|binary numbers]].

To figure out the number of multiplications, first note that a 0 means 1 multiplication is done, and a 1 means two multiplications are done. If we knew the number of bits in the binary representation of $n$, then we could use that to estimate the number of multiplications done when `power_recur_fast` calculates  $a^n$.

A positive integer $n$ has about $\log_2 n$ bits when represented in binary. So, *at worst*, if every bit were a 1, then $2\log_2 n$ multiplications would be done. This is *much* smaller than the $n - 1$ multiplications done by the obvious algorithm.

So we can say that, *in the worst case*, the number of comparisons done by `power_recur_fast` is proportional to $\log_2 n$. This makes it fast enough in practice to calculate large exponents like those needed by the [RSA cryptosystem](http://en.wikipedia.org/wiki/65537_(number)) example at the beginning.

## Note
This is an interesting algorithm! The performance is not at all obvious at first, nor is the connection to binary numbers.

You may wonder if this is the fastest way to calculate exponents. And the answer is ... no! For *some* exponents even fewer multiplications are possible. For example, consider $2^{15}$ :

- you can get $2^{3}$ in 2 multiplications
- then square it to get $2^{6}$, 1 more multiplication
- then square it to get $2^{12}$, 1 more multiplication
- then multiply by $2^{3}`$ from the first step to get $2^{15}$, 1 more multiplication

This uses *5 multiplications* in total to calculate $2^{15}$. But the fast recursive algorithm takes 8 multiplications.

## Practice Questions
1. If you were using the obvious algorithm in a program, which implementation would you prefer to use: the iterative (loop) one, or the recursive one? Explain your answer.
2. In the *worst case*, how many multiplications with obvious algorithm and the fast algorithm do to calculate $a^{1000000}$, i.e. $a$ to the power of one million?
3. For `power_recur_fast(a, n)`, it was shown in the notes that in the worst case about $2\log_2 n$ multiplications are needed. But what about the *best* case, when the binary representation of $n$ has just one 1-bit? About how many multiplications are done? And how often does this best case occur for an $n$-bit number?
4. Using the fast power function as a starting point, write a function called `to_binary_string(int n)` that returns the binary representation of `n` as a string of `0`s and `1`s.
