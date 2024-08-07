/*
Napisz funkcję, która przy pomocy wskaźników wyświetli dane znajdujące się w tablicy liczb całkowitych.
Użyj tablicy bezwymiarowej, a rozmiar określ za pomocą operatora sizeof.
Prototyp funkcji powinien wyglądać następująco:
void wyswietl(const int* poczatek, const int* koniec);
gdzie poczatek to wskaźnik na pierwszy element tablicy, a koniec – wskaźnik na obiekt tuż za ostatnim elementem tablicy.
*/

#include <stdio.h>

void wyswietl(const int* poczatek, const int* koniec) {
    for (const int* ptr = poczatek; ptr < koniec; ++ptr) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main() {
    int tablica[] = {10, 20, 30, 40, 50};
    wyswietl(tablica, tablica + sizeof(tablica) / sizeof(tablica[0]));
    return 0;
}
