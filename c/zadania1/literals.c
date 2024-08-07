#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define FALSZ false

int main(void) {
    // TODO: W poniższych instrukcjach użyj poprawnych literałów tak, aby program poprawnie się kompilował  -> zrobione
    double d = 1;
    float f = 1;

    char c = 'A';    // TODO: Użyj stałej znakowej reprezentującej literę A -> zrobione
    bool b = FALSZ;     // TODO: Użyj makra odpowiadającego wartości FAŁSZ -> zrobione

    f += 1.0f;

    unsigned int ui = INT_MAX + 1U;

    printf("l = %ld\n", 3L);  // TODO: Należy wyświetlić wartość typu `long` -> zrobione

    printf("c = %c\n", c);
    printf("b = %d\n", b);

    // Poniższe instrukcje zostały dodane po to, aby kompilator nie zgłaszał
    // błędów związanych z nieużywanymi zmiennymi.
    ui += 1;
    d += 0.0;

    return EXIT_SUCCESS;
}
