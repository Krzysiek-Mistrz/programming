/*
Zadeklaruj tablicę dwuwymiarową nxm. Przypisz do każdego z jej elementów odpowiednia wartosc. Oblicz sumę elementów leżących w co drugim wierszu, zaczynając od pierwszego wiersza.
*/

#include <stdio.h>

int main() {
    const int N = 3; // Liczba wierszy
    const int M = 4; // Liczba kolumn
    int A[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = i + 2 * j;    //wdg wzoru
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i += 2) {    //przesuwam sie co 2
        for (int j = 0; j < M; ++j) {
            sum += A[i][j];
        }
    }
    printf("suma elem. w co 2 wierszu: %d\n", sum);
    return 0;
}
