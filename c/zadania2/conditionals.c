#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// TODO: Najpierw zbuduj program bez flag kompilacji wychwytujących pewne błędy:
//  Zakomentuj instrukcję `add_compile_options` w pliku "SetCommonConfig.cmake".
//    (dopisz na początku wiersza znak '#')
//  Wybierz z menu CLion: File > Reload CMake Project
//  Spróbuj uruchomić program - uda się to bez problemu.
//  Teraz odkomentuj instrukcję `add_compile_options` i ponownie przeładuj projekt CMake.
//  Tym razem kompilator zgłosi szereg problemów związanych z potencjalnymi
//    problemami z instrukcjami warunkowymi (prawdopodobnie zawierającymi błędy
//    SEMANTYCZNE).
//  Zwróć uwagę, że każdorazowo CLion sygnalizuje problematyczne miejsca za pomocą:
//    - podkreślenia czerwonym wężykiem
//    - podkreślenia szarym wężykiem i wyszarzenia
//    - podświetlenia na żółto
//    - ...
//  Popraw poniższe funkcje tak, aby działały one zgodnie ze specyfikacją -> zrobione

/**
 * Zwróć wartość bezwzględną argumentu.
 * @param x liczba całkowita
 * @return wartość bezwzględna z `x`
 */
int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

/**
 * Zwróć wartość bezwzględną argumentu.
 * @param x liczba całkowita
 * @return wartość bezwzględna z `x`
 */
int my_abs2(int x) {
    if (x < 0) {
        x = -x;
        return x;
    }
    return x;
}

int main(void) {
    bool b = true;

    // TODO: Zmień poniższe wyrażenie inicjalizujące tak, aby zmienna otrzymała
    //   odpowiednio wartość odpowiadającą literze: -> zrobione
    //     - "t" gdy zmienna `b` ma wartość PRAWDA
    //     - "f" gdy zmienna `b` ma wartość FAŁSZ
    char cnd = 0;
    if(b) {
        cnd = 't';
    } else {
        cnd = 'f';
    }

    printf("%c\n\n", cnd);

    int x = 1;
    printf("my_abs(%d) = %d\n", x, my_abs(x));
    printf("my_abs2(%d) = %d\n\n", x, my_abs2(x));

    x = -1;
    printf("my_abs(%d) = %d\n", x, my_abs(x));
    printf("my_abs2(%d) = %d\n", x, my_abs2(x));

    return EXIT_SUCCESS;
}
