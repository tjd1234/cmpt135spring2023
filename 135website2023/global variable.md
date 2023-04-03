#terminology

## Definition
A variable that is defined outside of any function, and so can be used by any code in the program.

In general, you should avoid using global variables since it can be very difficult to know what code might be changing them. It's best to make all global variables `const`. 

Compare this to [[local variable|local variables]].

## Example
```cpp
#include <iostream>
#include <string>

using namespace std;

const string name = "Deb";   // name is a (const) global variable
int age = 35;                // age is a global variable

int main() {
	cout << name << " is " << age << "\n";
}
```