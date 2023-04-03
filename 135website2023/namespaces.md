## Name Collisions
Xavier and Yang are working together on a large programming project. While they do talk to each other, they don't discuss every line of code they write.

One day Xavier writes this:

```cpp
// kbd_events.cpp

// Returns true if c is a whitespace character, or a two-char code
// for a whitespace character.
bool is_whitespace(const string& c) {
    return c == " " || c == "\n" || c == "\t" || c == "\r"
        || c == "\\n" || c == "\\t" || c == "\\r";
}
```

And Yang writes this:

```cpp
// render.cpp

// Returns true if every character in s is a whitespace character.
bool is_whitespace(const string& c) {
    for(char c : s) {
        if (!(c == " " || c == "\n" || c == "\t" || c == "\r")) {
            return false;
        }
    }
    return true;
}
```

There's a problem: they have written two different functions with exactly the same header. When it comes time to [[linker|link]] these programs together, there will be a name collision, which will cause the [[linker|linking]] to fail.

One way to fix this problem is to rename one, or both, of the functions, e.g. Yang's `is_whitespace` could be renamed to this:

```cpp
bool is_all_whitespace(const string& s) {
    // ...
}
```

That works, but now coordinating names becomes one of the many details that the programmers must keep in mind. 

C++ has a better solution: **namespaces**.

## Using Namespaces
A manual solution to the problem of naming that doesn't require too much communication is for Xavier and Yang to agree ahead of time to use some kind of naming convention. For example, they might agree that all Xavier's names should begin with `event_`, and all Yang's names should begin with `render_`, e.g.:

```cpp
// Xavier's names all start with event_

// Returns true if s is a whitespace character, or a two-char code
// for a whitespace character.
bool event_is_whitespace(const string& s) {
    // ...
}

// Yang's names all start with render_

// Returns true if every character in s is a whitespace character.
bool render_is_whitespace(const string& s) {
    // ...
}
```

Now there is no collision: the two different functions have different names.

In C++, a **namespace** is essentially a built-in version of this idea. A C++ namespace is a collection of names (for variables, classes, functions, etc.) that the compiler knows about.

Xavier's and Yang's can solve their naming problem by agreeing to write code inside their own namespaces. Xavier writes code inside the `event` namespace:

```cpp
namespace event {
    // kbd_events.cpp

    // Returns true iff c is a whitespace character, or a 
    // two-char code for a whitespace character.
    bool is_whitespace(const string& c) {
        return c == " " || c == "\n" || c == "\t" || c == "\r"
            || c == "\\n" || c == "\\t" || c == "\\r";
    }
} // namespace event
```

Yang writes code inside the `render` namespace:

```cpp
// render.cpp

namespace render {

    // Returns true if every character in c is a whitespace character.
    bool is_whitespace(const string& c) {
        for(char c : s) {
            if (!(c == " " || c == "\n" || c == "\t" || c == "\r")) {
                return false;
            }
        }
        return true;
    }

    // ...

} // namespace render
```

Each individual function can be called by including it's namespace, e.g.:

```cpp
if (event::is_whitespace(s)) {   // calls is_whitespace in 
                                 // event namespace
   // ...
}

if (render::is_whitespace(s)) {   // calls is_whitespace in 
                                  // render namespace
   // ...
}
```


## using Directives
While namespaces provide a solution to the problem of name collisions, using `render::` and `even::` everywhere can make the code more cluttered and harder to read. So C++ provides the `using` as a way to access names in a namespace without `::`. For example:

```cpp
using namespace event;            // provide unqualified access to all 
                                  // names in the event namespace

if (is_whitespace(s)) {           // calls is_whitespace in event
                                  // namespace
   // ...
}

if (render::is_whitespace(s)) {   // calls is_whitespace in render
                                  // namespace
   // ...
}
```

Calling just `is_whitespace` calls the version in `event`. You can still call the one in `render` by writing `render::is_whitespace`.

There could be a lot of names in the `event` namespace, and the statement `using namespace event` gives you access to all of them. Sometimes, it is better to use particular names, e.g.:

```cpp
using event::is_whitespace;          // provide unqualified access
                                     // to just the is_whitespace 
                                     // name from event

if (is_whitespace(s)) {              // calls is_whitespace in 
                                     // event namespace
   // ...
}

if (render::is_whitespace(s)) {      // calls is_whitespace in
                                     // render namespace
   // ...
}
```

Note that you *cannot* use the same name from different namespaces, e.g.:

```cpp
using event::is_whitespace;

using render::is_whitespace;  // compiler error: 
                              // is_whitespace already used
```

A rule of thumb that some programmers like to follow is to *never* use `using`. The reason is that by always including the namespace name, it ultimately makes the code clearer and easier to understand. Someone reading the code never has to wonder which function is being used.

See [[choosing good names]] for some general advice on how choose good names for variables, functions, and so on. 

## Practice Questions
1. In your own words, describe a practical programming situation where two functions might be given the same name (and the same set of parameter types).
2. In your own words, describe what a C++ namespace does, and the syntax for defining one.
3. Suppose the namespace `interface` and the namespace `database` both contain a variable of type `double` named `refresh_time`. Write a statement that prints the sum of these two variables to the screen, and assume the statement is not in either the namespaces.
4. In your own words, explain the two different ways that `using` directives can be used to access names in a namespace.
5. In your own words, list three different general rules of thumb for [[choosing good names]] for variables.