/**
 * Napisz program, w którym zainicjalizujesz dwie zmienne typu
 * całkowitego (a i b) dowolnie wybranymi przez siebie wartościami,
 * a następnie sprawdzisz czy są one sobie równe i wypiszesz stosowny
 * komunikat (odpowiednio: “1” – są równe, albo “0” – nie są równe).
 */

#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;
    if(a == b) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}
