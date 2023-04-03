#terminology

## Definition
REPL stands for **read, eval, print loop**. It often has this general form:
```
loop forever:
	print "--> "              // print a prompt
	input = read_from_user()  // read
	result = evaluate(input)  // eval
	print(result)             // print
```

A REPL can be useful for interactive testing. Some programming languages, such as Python or JavaScript, provide general-purpose REPLs that can evaluate any part of the language. Such REPLS are often called **interpreters**.

## Example
This REPL tests the `trim` function:

```cpp
void repl() {
    for(;;) {  // infinite loop
        cout << "--> ";
        string s;
        getline(cin, s);
        cout << "trim(" << quote(s) << ") = "
             << quote(trim(s)) << "\n";
    }
}
```