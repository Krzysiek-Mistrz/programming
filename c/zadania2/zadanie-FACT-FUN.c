/*
Napisz funkcję zwracającą wartość silni liczby przekazanej jako argument.
*/

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int number = 5;
    printf("silnia z %d = %llu\n", number, factorial(number));
    return 0;
}
