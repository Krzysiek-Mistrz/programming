/*
Stwórz jednowymiarową tablicę czterech wartości zmiennoprzecinkowych, zainicjalizuj ją wybranymi przez siebie wartościami, a następnie oblicz sumę jej elementów.
*/

#include <stdio.h>

int main() {
    double tab[4] = {1.0, 2.5, 3.0, 4.5};
    double suma = 0.0;
    for(int i = 0; i < 4; i++)
        suma += tab[i];
    printf("suma elementow tablicy: %lf", suma);
    return 0;
}
