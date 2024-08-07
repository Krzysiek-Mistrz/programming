#ifndef BITLIB_H_
#define BITLIB_H_

#include <stdint.h>

/**
 * Rozłoż 2-bajtową liczbę na jej bajt bardziej i mniej znaczący.
 *
 * @param val rozkładana liczba
 * @param byte_hi uchwyt do obiektu przechowującego bardziej znaczący bajt
 *   liczby `val`
 * @param byte_lo uchwyt do obiektu przechowującego mniej znaczący bajt liczby
 *   `val`
 */
// TODO: Uzupełnij prototyp i implementację poniższej funkcji zgodnie z jej
//   powyższą specyfikacją. Pamiętaj o zasadach const-correctness! -> ok

extern void decompose_into_bytes(uint16_t val, uint8_t* byte_hi, uint8_t* byte_lo);

/**
 * Zwróć wartość reprezentującą ostatnie dwa bity liczby.
 *
 * @param val liczba całkowita
 * @return wartość reprezentująca ostatnie dwa bity liczby `val`
 */
// TODO: Uzupełnij prototyp i implementację poniższej funkcji zgodnie z jej
//   powyższą specyfikacją. Pamiętaj o zasadach const-correctness! -> ok

extern int last_two_bits(int val);

#endif /* BITLIB_H_ */
