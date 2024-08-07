/*
 * Zdefiniuj trzy liczby zmiennoprzecinkowe.
 * Wypisz ich sumę oraz średnią – dobierz odpowiednie specyfikatory konwersji pod
 * kątem typów użytych zmiennych. -> zrobione
 * */

#include <stdio.h>

int main() {
    float liczba1 = 3.0, liczba2 = 3.5, liczba3 = 4;
    float suma = liczba1 + liczba2 + liczba3;
    float srednia = suma / 3;
    printf("suma: %f\nsrednia: %f", suma, srednia);
    return 0;
}
