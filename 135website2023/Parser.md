---
aliases: [parsers, parsing]
---
#terminology

## Definition
A **parser** is a function that takes a string as input and returns some other representation of the string, usually a computer-friendly structure.  Errors that arise during parsing are often [[syntax error]]s.

## Example
`std::stoi(s)` is a simple parser that converts a string containing an `int` into the `int`. For example, `std::stoi("-425")` returns the `int` 425.

A more complex example of a parser is found in a C++ compiler. When the compiling a program the compiler first parses it by converting the text of the program into a syntax tree that is easier for the compiler to process.