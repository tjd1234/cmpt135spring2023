This site has the lecture notes for CMPT 135, Spring 2023 at SFU Surrey. [Canvas](https://canvas.sfu.ca) is where you'll find course marks, due dates, assignment marking schemes, discussions, announcements, etc. [Assignments and some course code can be found here](https://github.com/tjd1234/cmpt135spring2023).

## Useful Links
CMPT 135 uses modern C++ in Linux/Unix, and it's best if you set up Linux on your own computer:

1. Get Linux up an running on your machine.
    - **Windows**: we recommend you use [[WSL Windows Subsystem for Linux|the Windows Subsystem for Linux (WSL)]]. 
	    - Or, [[Setting up a Linux a virtual machine|Install a VirtualBox virtual machine]]. Use this if you really can't get [[WSL Windows Subsystem for Linux|WSL]] working.
    - **Mac**: you can use the Terminal that comes with it and install the necessary software for this course (`g++`, `make`, and `valgrind`) using [the Homebrew package manager](https://brew.sh/). Macs don't directly support Linux, but instead support a version of Unix that is probably close-enough for this course. You could also try installing a virtual machine on Mac that runs Ubuntu.
2. [[Getting Your C++ Environment Up and Running|Get your C++ environment up and running]]. Note that the Linux command shell is complete programming environment with its own language. We will only use bits and pieces of it during this course. If you are curious learn more, here is a [free book about using the Linux command shell](https://www.linuxcommand.org/tlcl.php).

If you run into problems and just can't get Linux running, here are two other suggestions you can try:

- Use Linux in the CSIL lab.
- [[using Repl.it|Use Repl.it]].

**Ncurses** is a library that gives you more control over the cursor on the screen, and it might be used in some examples or assignments. Here are some instructions for [[setting up ncurses on Ubuntu Linux]].

## Lecture Notes 
**The timing of each topic is approximate, and may change a little as we go**. The examples used in some weeks may also change.

### Week 1
- Course overview
- [[C++ Review|Reviewing C++]]
- [Sample code for week 1](https://github.com/tjd1234/cmpt135spring2023/tree/main/lectures/week1) (including the [word count example](https://github.com/tjd1234/cmpt135spring2023/tree/main/lectures/week1/wordcount) and [checking long lines](https://github.com/tjd1234/cmpt135spring2023/blob/main/lectures/week1/wordcount/line_check.cpp))

### Week 2
- [[Calling a function]]
- [[Testing code]]

### Week 3
- [[Pointers and memory management]]

### Week 4
- [[Common Pointer Problems]]
- Example: [[function-oriented dynamic array]]
- [[Object-oriented programming]]

### Week 5
- [[Object-oriented programming]]
- [[Implementing a dynamic array with objects]]
- [[double_list_plus.cpp|A dynamic array with some C++-specific features]]

### Week 6
- [[Introduction to inheritance|Inheritance]]

### Week 7
- [[Separate compilation]], and [[splitting int_vec]] into a `.h` and `.cpp` file.
- [[namespaces|Namespaces]]
- [[Introduction to Exceptions|Exceptions]]

--------------------------

**Reading week (Feb 20 - 24)**: no lectures or labs

--------------------------

### Week 8
- Midterm practice
- Midterm!
- [[Recursion]]

### Week 9
- Midterm review
- [[Recursion]]

### Week 10
- [[Calculating large powers]]
- [[The max function]]
- [[linear search|Algorithms and linear search]]

### Week 11
- [[Basic sorting]]
- [[basic sorting#Binary Search|Binary search]]
- [[O-notation]]

### Week  12
- [[Easy and Hard Problems]]
- [[Using Templates]]

### Week  13
- final exam review
