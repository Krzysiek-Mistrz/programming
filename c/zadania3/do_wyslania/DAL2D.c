/*
Napisz program który alokuje dynamicznie tablicę przechowującą w wierszach następujące wyrazy:
Oto
tablica
dynamiczna.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char **tablica = (char **)malloc(3 * sizeof(char *));
    if (tablica == NULL)
        return (-1);
    for (int i = 0; i < 3; i++) {
        tablica[i] = (char *)malloc(15 * sizeof(char)); //zakladam jakas maks dlugosc
    }
    tablica[0] = "Oto";
    tablica[1] = "tablica";
    tablica[2] = "dynamiczna.";
    for (int i = 0; i < 3; i++) {
        printf("%s\n", tablica[i]);
    }
    for (int i = 0; i < 3; i++) {
        free(tablica[i]);
    }
    free(tablica);
    return EXIT_SUCCESS;
}
