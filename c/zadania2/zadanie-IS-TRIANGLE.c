/* 
Napisz funkcję sprawdzającą czy z trzech odcinków, których długości przekazujemy jako argumenty, da się zbudować trójkąt, i wypisującą stosowny komunikat na ekran. Aby określić, czy z danych odcinków da się zbudować trójkąt skorzystaj z nierówności trójkąta.
*/

#include <stdio.h>

int isTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int a = 3, b = 4, c = 5;
    if (isTriangle(a, b, c)) {
        printf("mozna zbudowac trojkat\n");
    } else {
        printf("nie mozna zbudowac trojkata\n");
    }
    return 0;
}
