This is an example of separate compilation. To build this program, run `make all`
at the command-line:

```bash
$ make all
g++ -c -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g int_vec.cpp
g++ -c -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g int_vec_test.cpp
g++ -o int_vec_test int_vec.o int_vec_test.o
```

You can also run `make clean` to remove the object files and executable:

```bash
$ make clean
rm int_vec.o
rm int_vec_test.o
rm int_vec_test
```
