/*
Napisz program, który dla zadanego numeru dnia tygodnia wypisze na ekran skrót jego nazwy (np. dla 1 – pn, dla 2 – wt itd.). W przypadku błędnych danych (liczba spoza zakresu) program powinien wyświetlić stosowny komunikat. Użyj instrukcji switch.
*/

#include <stdio.h>

int main() {
    short int nrDniaTygodnia = 1;
    switch(nrDniaTygodnia) {
        case 1:
            printf("pn");
            break;
        case 2:
            printf("wt");
            break;
        case 3:
            printf("sr");
            break;
        case 4:
            printf("czw");
            break;
        case 5:
            printf("pt");
            break;
        case 6:
            printf("sb");
            break;
        case 7:
            printf("nd");
            break;
        default:
            printf("blad: podano nieprawidlowy dzien tygodnia");
            return -1;
            break;
    }
    return 0;
}
