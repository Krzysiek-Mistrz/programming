/*
Napisz program, który uzupełni tablicę typu int (o rozmiarze 10) losowymi wartościami z przedziału ⟨0,99⟩
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int myArray[10];
    for (int i = 0; i < 10; ++i) {
        myArray[i] = rand() % 100;
    }
    printf("pseudolosowe wartosci tab:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", myArray[i]);
    }
    printf("\n");
    return 0;
}
