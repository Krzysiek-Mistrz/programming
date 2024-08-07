/*
Napisz program, który obliczy silnię zadanej liczby naturalnej n metodą rekurencyjną.
*/

#include <stdio.h>

int factorialRec(int number) {
    if(number > 0)
        return number * factorialRec(number - 1);
    else if(number < 0) //najbardziej podstawowy security check, oczywiscie nalezaloby sprawdzic jeszcze wiele innych rzeczy
        printf("blad: podano ujemna liczbe");
    return 1;
}

int main() {
    printf("silnia liczby 5: %d", factorialRec(5));
    return 0;
}
