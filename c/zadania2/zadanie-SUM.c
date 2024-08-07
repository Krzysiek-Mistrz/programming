/*
Napisz program sprawdzający, czy zadana liczba naturalna jest liczbą pierwszą – oczywiście metodą rekurencyjną, bez użycia jakichkolwiek pętli.
Przyjmij, że ani 0 ani 1 nie są liczbami pierwszymi.
*/

#include <stdio.h>

int digitSum(int number) {
    if (number <= 0)    //najbardziej typowy sec check
            return 0;
    else {
        return number % 10 + digitSum(number / 10);
    }
}

int main() {
    int number = 725;
    printf("suma cyfr liczby %d: %d", number, digitSum(number));
    return 0;
}
