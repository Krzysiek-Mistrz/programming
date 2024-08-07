/*
Napisz program, który wypisze na ekran “kwadrat”, w którym:
pierwszy wiersz zawiera liczby od 1 do n
każdy kolejny wiersz zawiera liczby z poprzedniego wiersza “przekręcone” o jedną pozycję w lewo
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n = 5;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            printf("%d ", (i + j - 1) % n + 1);
        }
        printf("\n");
    }
    return 0;
}
