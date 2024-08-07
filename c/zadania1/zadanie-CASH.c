/*
 * Napisz program, który zamieni liczbę kwotę wyrażoną poprzez liczbę monet jednodolarowych
 * na kwotę w poniższych walutach:
 * euro (1 USD = 0,77 EUR)
 * złotówki (1 USD = 3,04 PLN)
 * Obliczone wartości kwot w walutach innych niż dolary mają być tak sformatowane,
 * aby liczba była wyświetlona z dwoma miejscami po przecinku, a cała liczba zajmowała
 * pole o szerokości 7 znaków.
 * */

#include <stdio.h>

int main() {
    int ileDolarow = 10;
    float ileEuro = ileDolarow * 0.77;
    float ileZlotych = ileDolarow * 3.04;
    printf("ile euro: %7.2f\nile zlotych: %7.2f", ileEuro, ileZlotych);
    return 0;
}
