/*
Napisz program, który sprawdzi czy zadana liczba x spełnia nierówność:
3≤x<6
i wypisze stosowny komunikat:
“Nierownosc spelniona!” albo
“Nierownosc falszywa!”
*/

#include <stdio.h>

int main(void) {
    int x = 5;
    if(3 <= x && x < 6)
        printf("nierownosc spelniona");
    else
        printf("nierownosc nie spelniona");
    return 0;
}