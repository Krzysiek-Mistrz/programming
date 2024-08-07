#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"

int main(void) {
    byte b = 1;
    //zwiekszamy o 1
    transform(&b);
    printf("%d", b);
    return EXIT_SUCCESS;
}
