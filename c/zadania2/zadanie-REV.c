/*
Napisz program, który odwróci kolejność elementów tablicy “w miejscu”, czyli bez deklarowania tablicy pomocniczej.
Przykład: {1, 4, 3} → {3, 4, 1}.
*/

#include <stdio.h>

int main() {
    int myArray[] = {1, 4, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    for (int i = 0; i < size / 2; ++i) {
        int temp = myArray[i];
        myArray[i] = myArray[size - 1 - i]; //pierwszy z ostatnim i do pierwszego wartosc z temp przypisywana
        myArray[size - 1 - i] = temp;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d ", myArray[i]);
    }
    return 0;
}
