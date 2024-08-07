// Napisz program, który pobiera imię i nazwisko użytkownika (używając jednego wywołania funkcji scanf()), a następnie wyświetla: w pierwszym wierszu imię i nazwisko, a w drugim liczbę liter w imieniu oraz liczbę liter w nazwisku.

#include <stdio.h>

int main() {
    char imie[50];
    char nazwisko[50];
    printf("Podaj imie i nazwisko: ");
    scanf("%49s %49s", imie, nazwisko);
    int dlugosc_imienia = 0;
    while (imie[dlugosc_imienia] != '\0') {
        dlugosc_imienia++;
    }
    int dlugosc_nazwiska = 0;
    while (nazwisko[dlugosc_nazwiska] != '\0') {
        dlugosc_nazwiska++;
    }
    printf("Imie i nazwisko: %s %s\n", imie, nazwisko);
    printf("Liczba liter w imieniu: %d\nLiczba liter w nazwisku: %d\n", dlugosc_imienia, dlugosc_nazwiska);
    return 0;
}
