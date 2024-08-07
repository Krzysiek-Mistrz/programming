/*
Napisz funkcję, która wyświetli napis “Dzien dobry!” otrzymaną w argumencie liczbę razy.
*/

#include <stdio.h>

void powitaj(int ile_razy) {
    for(int i = 0; i < ile_razy; i++) {
        printf("Dzien dobry! ");
    }
}

int main() {
    int ile = 10;
    powitaj(ile);
    return 0;
}
