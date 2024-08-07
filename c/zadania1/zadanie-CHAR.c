/* Napisz program, który wyświetli znak w kodowaniu ASCII
 * odpowiadający danej liczbie całkowitej z zakresu 0–255. -> zrobione
 * */

#include <stdio.h>

int main() {
    int liczba;
    scanf("%d", &liczba);
    char znak;
    if(liczba >= 0 && liczba <= 255)
        znak = (char)liczba;
    else
        return -1;
    printf("znak: %c, odpowiada liczbie w ASCII: %d\n", znak, liczba);
    return 0;
}
