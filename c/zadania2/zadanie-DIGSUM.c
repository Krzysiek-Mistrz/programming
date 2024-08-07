/*
Napisz program, który dla zadanej liczby całkowitej obliczy sumę jej cyfr.
*/

#include <stdio.h>

int main(void) {
    int n = 125;
    int dzielnik = 10;
    int sumaCyfr = 0;
    while(n) {
        sumaCyfr += n % dzielnik;
        n /= 10;
    }
    printf("suma cyfr: %d", sumaCyfr);
    return 0;
}