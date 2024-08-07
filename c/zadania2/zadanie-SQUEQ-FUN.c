/*
Napisz funkcję, której argumentami będą liczby całkowite a, b oraz c – współczynniki równania kwadratowego. Funkcja powinna zwrócić wartość całkowitą – liczbę rozwiązań równania kwadratowego dla zadanych współczynników.
*/

#include <stdio.h>

int solutionsNum(int a, int b, int c) {
    int delta = b * b - 4 * a * c;
    if (delta > 0) 
        return 2;
    else if (delta == 0) 
        return 1;
    else return 0;
}

int main() {
    int a = 1, b = -3, c = 2;
    printf("liczba rozwiazan: %d\n", solutionsNum(a, b, c));
    return 0;
}
