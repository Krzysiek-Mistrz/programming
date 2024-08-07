/*
Napisz funkcję palindrom() o poniższym prototypie, która rekurencyjnie (bez użycia pętli!) sprawdzi, czy dany łańcuch znaków jest palindromem:
int palindrom(const char* str);
Funkcja powinna zwrócić wartość 1, jeśli łańcuch znaków jest palindromem, a w przeciwnym przypadku powinna zwrócić wartość 0.ną.
*/

#include <stdio.h>
#include <stdlib.h>

int palindromRek(const char* str, int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return palindromRek(str, start + 1, end - 1);
}

int palindrom(const char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return palindromRek(str, 0, len - 1);
}

int main(void) {
    char str[] = "kajak";
    if (palindrom(str))
        printf("\"%s\" jest palindromem.\n", str);
    else
        printf("\"%s\" nie jest palindromem.\n", str);
    return EXIT_SUCCESS;
}
