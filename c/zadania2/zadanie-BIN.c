/*
Napisz program, który wypisze na ekranie reprezentację binarną zadanej liczby całkowitej dodatniej. Zadanie zrealizuj z użyciem rekurencji.
Przykład: dla liczby 15 program powinien wypisać 1111.
*/

#include <stdio.h>

// Funkcja wypisująca reprezentację binarną liczby
void printBinary(int n) {
    if (n > 0) {    //podstawowy sec check
        printBinary(n / 2); //bo od konca zapisujemy
        printf("%d", n % 2);
    }
}

int main() {
    int number = 10;
    printf("binarnie: ");
    printBinary(number);
    printf("\n");
    return 0;
}
