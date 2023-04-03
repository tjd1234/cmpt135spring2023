Recursive acronyms are a fun example of recursion. Perhaps you've heard of the `GNU <https://www.gnu.org/>`_ project (they make g++, and much other software). GNU is an acronym that expands like this:

```
GNU = GNU's Not Unix
```

If you keep replacing GNU with its expansion you get an infinitely long string:

```
GNU = GNU's Not Unix
    = (GNU's Not Unix)'s Not Unix 
    = ((GNU's Not Unix)'s Not Unix)'s Not Unix
    = (((GNU's Not Unix)'s Not Unix)'s Not Unix)'s Not Unix 
    = ...
```

There is no base case, so it expands forever.

Here are a few more recursive acronyms:

 - YOPY = Your Own Personal YOPY
 - LAME = LAME Ain't an MP3 Encoder
 - These acronyms are *co-recursive*:
   - HURD = Hird of Unix-Replacing Daemons
   - HIRD = Hurd of Interfaces Representing Depth
 - MOMS is *doubly recursive* and so expands very quickly:
      MOMS = MOMS Offering MOMS Support
           = MOMS Offering MOMS Support Offering MOMS Offering MOMS Support 
             Support
           = MOMS Offering MOMS Support Offering MOMS Offering MOMS Support 
             Support Offering MOMS Offering MOMS Support Offering MOMS Offering 
             MOMS Support Support Support
           = ...

Here is a function that expands MOMS:

```cpp
// MOMS = MOMS Offering MOMS Support
string moms(int n) {
    if (n == 1) {
        return "moms offering moms support";
    } else {
        string sub = moms(n - 1);
        return sub + " offering " + sub + " support";
    }
}
```
