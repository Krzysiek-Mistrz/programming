/*
Napisz program sprawdzający w naiwny sposób (czyli: najprostszy), czy zadana przez użytkownika liczba jest liczbą pierwszą.
Wykorzystaj pętlę for i operator modulo (%).
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    int liczba = 23;
    bool czyPierwsza = 1;
    for(int i = 2; i < ((int)sqrt(liczba) + 1); i++) {
        if(liczba % i == 0)
            czyPierwsza = 0;
    }
    if(czyPierwsza)
        printf("liczba: %d, jest liczba pierwsza", liczba);
    else
        printf("liczba: %d, nie jest liczba pierwsza", liczba);
    return 0;
}