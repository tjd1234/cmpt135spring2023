#!/usr/bin/fish

./myecho_sol Once upon a time.
./myecho_sol -s Once upon a time.
./myecho_sol -r Once upon a time.
./myecho_sol -sr a b c d
./myecho_sol -rs a b c d

./myecho_sol -q Once upon a time.
./myecho_sol -qs Once upon a time.
./myecho_sol -rq Once upon a time.
./myecho_sol -sqr a b c d
./myecho_sol -qrs a b c d
./myecho_sol -q
./myecho_sol

./myecho_sol -h
./myecho_sol -qhs one two three
./myecho_sol -runtests
