/*
Napisz funkcję max(), posiadającą dwa parametry (a i b) będące liczbami całkowitymi. Funkcja powinna zwrócić większą spośród dwóch przekazanych jako argumenty wartości.
*/

#include <stdio.h>

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int number1 = 10, number2 = 20;
    printf("wieksza wartosc: %d\n", max(number1, number2));
    return 0;
}