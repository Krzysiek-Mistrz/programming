/*
Napisz program obliczający pierwiastek kwadratowy zadanej liczby metodą babilońską (kroki 1–3). Przerwij obliczenia, gdy różnica między kolejnymi przybliżeniami jest mniejsza niż zadana wart.
*/

#include <stdio.h>
#include <math.h>

double babilonianSqrt(double S) {
    double x0 = S / 2.0;
    double xn = x0;
    double epsilon = 1e-4;
    do {
        xn = (xn + S / xn) / 2.0;
    } while (fabs(xn * xn - S) > epsilon);
    return xn;
}

int main() {
    double number = 5.25;
    double result = babilonianSqrt(number);
    printf("pierwiastek kwadratowy z %.2lf to %.6lf\n", number, result);
    return 0;
}
