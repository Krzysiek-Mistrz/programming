// Napisz funkcję dlugosc(), o poniższym prototypie, która obliczy długość łańcucha znaków: unsigned long dlugosc(const char* str); W jej implementacji nie korzystaj z funkcji strlen()!

#include <stdio.h>
#include <stdlib.h>

unsigned long dlugosc(const char* str) {
    unsigned long len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

int main(void) {
    char str[] = "jaka mam dlugosc?";
    printf("Długość łańcucha \"%s\" wynosi %ld.\n", str, dlugosc(str));
    return EXIT_SUCCESS;
}
