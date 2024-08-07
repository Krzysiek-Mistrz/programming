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
    printf("elementy tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
    free(tablica);
    return 0;
}
