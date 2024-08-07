#ifndef MYMEM_H_
#define MYMEM_H_

#include <stddef.h>

// TODO: Dołącz bibliotekę definiującą alias `size_t` - np. <stddef.h> -> zrobione

/**
 * Zwróć adres tablicy reprezentującej ciąg liczb całkowitych: 1, 2, ..., n
 *
 * @param n maksymalny element ciągu (liczba całkowita dodatnia)
 * @return adres tablicy reprezentującej ciąg albo wskaźnik pusty, jeśli
 *   nie udało się zarezerwować bloku pamięci
 */
// TODO: Uzupełnij prototyp i implementację poniższej funkcji zgodnie z jej
//   powyższą specyfikacją.
//   UWAGA!
//   W pierwszej wersji implementacji nie sprawdzaj tego, czy malloc() zwrócił
//     pusty wskaźnik. Zamiast tego wyłącz narzędzie AddressSanitizer
//     (zob. plik main.c) i uruchom test "CreateSequence_TooLarge"
//     oraz zaobserwuj zwrócony błąd.
//   Skorzystaj z pakietu Valgrind, aby zdiagnozować problem z pamięcią:
//     W sekcji "InvalidWrite", dla pliku "mymem.c" na samym dole powinien
//     wyświetlić się komunikat:
//       "Address 0x0 is not stack'd, malloc'd or (recently) free'd".
//   Teraz dodaj sprawdzanie warunku i ponownie uruchom wspomniany test. Błąd
//     powinien zniknąć.
//   Włącz narzędzie AddressSanitizer (zob. plik main.c) i ponownie wykonaj
//     test "CreateSequence_TooLarge" - tym razem AddressSanitizer rzuci wyjątek
//     w momencie wykrycia błędnej alokacji (zwykle próba alokacji tak dużego
//     bloku pamięci wynika z błędów programisty, a nie celowego działania). -> ok
extern int *create_sequence(size_t n);

#endif /* MYMEM_H_ */
