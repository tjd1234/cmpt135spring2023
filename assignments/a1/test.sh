#!/usr/bin/bash

./myecho Once upon a time.
./myecho -s Once upon a time.
./myecho -r Once upon a time.
./myecho -sr a b c d
./myecho -rs a b c d

./myecho -q Once upon a time.
./myecho -qs Once upon a time.
./myecho -rq Once upon a time.
./myecho -sqr a b c d
./myecho -qrs a b c d
./myecho -q
./myecho

./myecho -h
./myecho -qhs one two three
./myecho -runtests
