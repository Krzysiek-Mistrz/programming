/*
Napisz program, który sprawdzi czy dana liczba x:
spełnia jednocześnie nierówności 
2≤x<7 i x≠5
oraz wypisze stosowny komunikat.
Użyj tylko jednego wyrażenia logicznego – skorzystaj z operatorów logicznych!
*/

#include <stdio.h>

int main(void) {
    int x = 5;
    if((2 <= x && x < 7) && (x != 5))
        printf("nierownosc spelniona");
    else
        printf("nierownosc nie spelniona");
    return 0;
}