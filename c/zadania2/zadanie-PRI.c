/*
Napisz program sprawdzający, czy zadana liczba naturalna jest liczbą pierwszą – oczywiście metodą rekurencyjną, bez użycia jakichkolwiek pętli.
Przyjmij, że ani 0 ani 1 nie są liczbami pierwszymi.
*/

#include <stdio.h>
#include <stdbool.h>

bool ifPrime(int number, int divider) {
    if (divider == number) {
        return true;    //jest pierwsza
    }
    if (number % divider == 0) {
        return false;   //nie jest pier.
    }
    return ifPrime(number, divider + 1);
}

int main() {
    int number = 7;
    if(ifPrime(number, 2))  //zaczynamy od dzielnika2 oczywiscie
        printf("liczba %d, jest pierwsza", number);
    else
        printf("liczba %d, nie jest pierwsza", number);
    return 0;
}
