// Napisz funkcję obliczającą dla zadanego argumentu x (będącego liczbą zmiennoprzecinkową) wartość wyrażenia 
// y=(x^3+3*x)/(x^2+6)

#include <stdio.h>

float expression(float x) {
    return (x * x * x + 3 * x) / (x * x + 6);
}

int main() {
    float x = 2.0;
    printf("wartosc: %.2f\n", expression(x));
    return 0;
}
