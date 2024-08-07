/*
Wyświetl liczbę komórek pamięci między zmiennymi v1 i v2. Nie odejmuj wskaźników (gdyż w tym przypadku nie jest to dozwolone).
*/

#include <stdio.h>

int main() {
    int v1;
    size_t licznik = 0;
    int v2;
    for (const int* ptr = &v1; ptr < &v2; ++ptr) {
        ++licznik;
    }
    printf("liczba komorek pamieci: %zu", licznik);
    return 0;
}
