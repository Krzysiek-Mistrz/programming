#ifndef MYLIB_H_
#define MYLIB_H_

#include <stdint.h>

typedef uint8_t byte;

/**
 * Zwiększ wartość wskazywaną przez argument funkcji o 1.
 *
 * @param b wskaźnik na wartość do modyfikacji
 */
extern void transform(byte* b);

/**
 * Zmienna globalna - początkowo powinna mieć wartość 1.0.
 */
extern double x;

#endif // MYLIB_H
