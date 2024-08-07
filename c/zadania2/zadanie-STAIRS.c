/*
Napisz program, który dla zadanej liczby naturalnej n
 wyświetli “schody” o wysokości n
*/

#include <stdio.h>

int main(void) {
    int n = 5;
    for(int i = 1; i < (n + 1); i++) {
        for(int j = 0; j < i; j++)
            printf("$");
        printf("\n");
    }
    return 0;
}