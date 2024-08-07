#include <stdlib.h>
#include <assert.h>
#include "mymem.h"

int *create_sequence(size_t n) {
    int *tab = malloc(n * sizeof(int));
    if (tab != NULL)
        for (size_t i = 0; i < n; ++i)
            tab[i] = (int) (i + 1);
    return tab;
}
