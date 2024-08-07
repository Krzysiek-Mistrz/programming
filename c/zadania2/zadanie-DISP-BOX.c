/*
Zadanie DISP-BOX
Napisz funkcję, która dla zadanych dwóch parametrów – liczby wierszy i liczby znaków w (każdym) wierszu – wyświetli stosowną ilość znaków $.
*/

#include <stdio.h>

void displayBox(int rows, int charsPerRow) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < charsPerRow; j++) {
            printf("$");
        }
        printf("\n");
    }
}

int main() {
    int rows, charsPerRow;
    rows = 4;
    charsPerRow = 5;
    displayBox(rows, charsPerRow);
    return 0;
}
