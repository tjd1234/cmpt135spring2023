#terminology

## Definition
A variation of [[pass by reference]] where the variable being passed is declared `const` so that the function *cannot* modify it. This gives the performance benefit of pass by reference (i.e. no copy is made of the variable, as [[pass by value]] does) without the concern that the function might modify the variable.

## Example
```cpp
void say_hello(const string& name) {  // name is passed by constant reference
	cout << "Hello " << name << "!\n";
}

int main() {
	string who = "Elon";
	say_hello(who);
    say_hello("Sam");
}
```

Notice that, unlike regular [[pass by reference]], we can pass the string literal `"Sam"` to `say_hello`.

