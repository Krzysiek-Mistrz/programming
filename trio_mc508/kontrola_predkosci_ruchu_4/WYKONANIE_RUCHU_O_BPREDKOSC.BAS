FOR x = 2 TO 3
    BASE(x)
    UNITS = 6400
    SPEED = 200
    ACCEL = 10000
    DECEL = ACCEL
NEXT x
BASE(2, 3)
TABLE(1000, 0, 900)
TABLE(1002, -800, 0)
TABLE(1004, 0, -1200)
TABLE(1006, 800, 0)
TABLE(1008, 0, 300)
adres_startowy = 1000
liczba_osi = 2
liczba_punktow = 5
opcje = 0
promien = 300
MOVESEQ(adres_startowy, liczba_osi, liczba_punktow, opcje, promien)

