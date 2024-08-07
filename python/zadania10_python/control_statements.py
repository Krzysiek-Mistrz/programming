#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Instrukcje sterujące
#
# -----------------------------------------------------------------------------

def parity_str(n: int) -> str:
    return "parzysta" if n % 2 == 0 else "nieparzysta"

def plf(x: float) -> float:
    if x < 3:
        return 1
    elif x >= 10:
        return 4
    else:
        return 1.5

def factorial(n: int) -> int:
    silnia = 1
    for i in range(1, n + 1):
        silnia *= i
    return silnia

def min_pow_2(n: int) -> int:
    potega_2 = 1
    while potega_2 <= n:
        potega_2 *= 2
    return potega_2

# if __name__ == "__main__":
#     print(parity_str(100))