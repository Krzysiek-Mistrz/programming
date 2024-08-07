/*
Napisz program, w którym zainicjalizujesz trzy zmienne typu
zmiennoprzecinkowego (a, b i c) i wyświetlisz stosowny komunikat:
“Trzy dodatnie!” jeśli wszystkie liczby są dodatnie,
“Dwie dodatnie!” jeśli dokładnie dwie spośród wczytanych liczb są dodatnie, albo
“Nic :(” jeśli tylko jedna liczba jest dodatnia lub jeśli żadna z liczb nie jest dodatnia.
Skorzystaj z konstrukcji if-else if-else.
 */

#include <stdio.h>

int main() {
    double a = -1.0;
    double b = 1.0;
    double c = -3.0;
    if((a > 0) && (b > 0) && (c > 0))
        printf("trzy dodatnie");
    else if (((a > 0) && (b > 0) && (c < 0)) || ((a < 0) && (b > 0) && (c > 0)) || ((a > 0) && (b < 0) && (c > 0)))
        printf("dwie dodatnie");
    else {
        printf("nic");
    }
    return 0;
}
