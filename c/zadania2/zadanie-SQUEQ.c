/*
Napisz program, który poda liczbę rozwiązań równania kwadratowego dla zadanych współczynników
Wartości współczynników podaj “na sztywno” w programie, podczas inicjalizacji zmiennych.
Nie musisz obliczać konkretnych wartości pierwiastków – o ile istnieją!
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 1;
    double b = 2;
    double c = 4;
    double delta = pow(b, 2) - 4*a*c;
    if(delta > 0)
    {
        printf("2 rozwiazania");
    } else if (delta == 0) {
        printf("1 rozwiazanie podwojne");
    } else {
        printf("0 rozwiazan");
    }
    return 0;
}
