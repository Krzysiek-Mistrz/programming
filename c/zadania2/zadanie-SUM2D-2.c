/*
Zadeklaruj tablicę dwuwymiarową nxm. Przypisz do każdego z jej elementów losową wartość z przedziału 
⟨0,9⟩. Wyświetl tablicę zawierającą wylosowane elementy. Oblicz i wyświetl sumę elementów w każdym rzędzie oraz w każdej kolumnie tej tablicy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 3; // Liczba wierszy
    const int M = 4; // Liczba kolumn
    int A[N][M];
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = rand() % 10;
        }
    }
    printf("tablica zawierajaca wylosowane elementy:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; ++i) {
        int rowSum = 0;
        for (int j = 0; j < M; ++j) {
            rowSum += A[i][j];
        }
        printf("suma elem. w %d rzedzie: %d\n", i + 1, rowSum);
    }
    for (int j = 0; j < M; ++j) {
        int colSum = 0;
        for (int i = 0; i < N; ++i) {
            colSum += A[i][j];
        }
        printf("suma elem. w %d kolumnie: %d\n", j + 1, colSum);
    }
    return 0;
}
