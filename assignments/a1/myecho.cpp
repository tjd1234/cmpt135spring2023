// myecho.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name         : <full name, exactly as it appears on your SFU id card> 
// Student ID # : <full SFU student number> 
// SFU Email    : <full SFU email address>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
//
// Notes to the Marker
// -------------------
//
// Tell us something about the assignment you're submitting, for example:
// - are there are any known bugs?
// - are there any missing features?
// - were there any parts you found particularly challenging?
// - did you use any outside sources of help (fully cite them if you did)?
// - what editor and programming tools did you use?
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>    // Do not #include any other files.
#include <vector>      //
#include <string>      // You do not need to use functions from all these
#include <algorithm>   // #includes.
#include <cassert>     //

using namespace std;


int main(int argc, char *argv[]) {
    cout << "Welcome to assignment 1! Here's what you typed:\n";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << "\n";
} // main
