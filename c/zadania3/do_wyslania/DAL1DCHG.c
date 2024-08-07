#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("podaj rozmiar tablicy: ");
    scanf("%d", &n);
    int *tablica = (int *)malloc(n * sizeof(int));
    if (tablica == NULL)
        return (-1);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        tablica[i] = rand() % 100;
    }
    int *nowa_tablica = (int *)realloc(tablica, 2 * n * sizeof(int));
    if (nowa_tablica != NULL) {
        for (int i = n; i < 2 * n; i++)
            nowa_tablica[i] = 0;
        printf("elementy powiekszonej tablicy:\n");
        for (int i = 0; i < 2 * n; i++)
            printf("%d ", nowa_tablica[i]);
        printf("\n");
        free(nowa_tablica);
    } else {
        free(tablica);
        return (-1);
    }
    return 0;
}
