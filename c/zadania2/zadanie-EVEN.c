/*
Napisz program, który sprawdzi czy dana liczba (całkowita) jest liczbą parzystą i wypisze odpowiedni komunikat.
*/

#include <stdio.h>

#define PARZYSTA(x) ((x) % 2 ? "nieparzysta" : "parzysta")

int main(void) {
    int x = 2;
    printf(PARZYSTA(x));
    return 0;
}