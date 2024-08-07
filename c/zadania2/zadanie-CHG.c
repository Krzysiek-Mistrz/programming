#include <stdlib.h>
#include <stdio.h>
 
//TODO: Tu zdefiniuj funkcję `zamien()`. -> zrobione
void zamien(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 4;
    int b = 5;
 
    zamien(&a, &b);
 
    if (a == 5 && b == 4) {
        printf("OK\n");
    } else {
        printf("Cos poszlo nie tak...\n");
    }
 
    return EXIT_SUCCESS;
}