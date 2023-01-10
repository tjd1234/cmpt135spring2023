// functions.cpp

// Example functions from the notes for understanding how function calls work.

int f(int a) {
    return a + 1;
}

int g(int a) {
    int n = a + 2;
    return 3*n;
}

int h(int a) {
    int x = f(a);
    int y = g(a);
    return x + y;
}

int main() {

}
