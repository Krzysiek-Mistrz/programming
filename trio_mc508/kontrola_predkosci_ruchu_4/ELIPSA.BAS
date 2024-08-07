BASE(0, 1)
UNITS = 1
SPEED = 1500
ACCEL = 15000
DECEL = ACCEL

DEFPOS(1000,0) 'zdefiniowanie punktu startowego ruchu

a = 1000 'wielka polos elipsy
b = 500 'mala polos elipsy

FOR d=0 TO 360
    x = a * COS(d * PI / 180)
    y = b * SIN(d * PI / 180)

    TABLE(1000 + d * 2, x, y)
NEXT d

adres_startowy = 1000
liczba_osi = 2
liczba_punktow = 361
opcje = 4
promien = 0
adres_wyjscia = 2000

MOVEABSSEQ(adres_startowy, liczba_osi, liczba_punktow, opcje, promien, adres_wyjscia)
