/*
Napisz program, który wyznaczy największą wartość w jednowymiarowej tablicy pięciu liczb całkowitych.
*/

#include <stdio.h>

int main() {
    int tab[5] = {1, 2, 3, 4, 5};
    int najwiekszy = -1000;
    for(int i = 0; i < 5; i++)
        if(tab[i] > najwiekszy)
            najwiekszy = tab[i];
    printf("najwiekszy elem. tab: %d", najwiekszy);
    return 0;
}
