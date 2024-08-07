/*
Napisz funkcję, która stwierdza, czy przekazana jako argument liczba całkowita jest kwadratem pewnej innej liczby całkowitej. Funkcja powinna zwrócić wartość całkowitą
*/

#include <stdio.h>
#include <math.h>

int isSquare(int number) {
    int squareRoot = sqrt(number);
    return (squareRoot * squareRoot == number);
}

int main() {
    int number = 16;
    printf("liczba: %d jest kwadratem pewnej liczby calk (1/0): %d\n", number, isSquare(number));
    return 0;
}

