BASE(0, 1)

UNITS = 1
SPEED = 400
ACCEL = 1000
DECEL = ACCEL

lin_force_sp = SPEED ‘ prędkosc glowna ruchu liniowego (FORCE_SPEED)
lin_end_sp = SPEED * 0.5 ‘ predkosc koncowa ruchu liniowego (ENDMOVE_SPEED)
luk_force_sp = SPEED * 0.5 ‘ predkosc glowna w ruchu po luku (FORCE_SPEED)
luk_end_sp = SPEED * 0.5 ‘ predkosc koncowa w ruchu po luku (ENDMOVE_SPEED)

TABLE(1000, 0, 900, lin_force_sp, lin_end_sp, luk_force_sp, luk_end_sp)
TABLE(1006, 800, 900, lin_force_sp, lin_end_sp, luk_force_sp, luk_end_sp)
TABLE(1012, 800, –300, lin_force_sp, lin_end_sp, luk_force_sp, luk_end_sp)
TABLE(1018, 0, –300, lin_force_sp, lin_end_sp, luk_force_sp, luk_end_sp)
TABLE(1024, 0, 0, lin_force_sp, lin_end_sp, luk_force_sp, luk_end_sp)

MERGE = ON

adres_startowy = 1000
liczba_osi = 2
liczba_punktow = 5
opcje = 1
promien = 300

MOVEABSSEQ(adres_startowy, liczba_osi, liczba_punktow, opcje, promien)

WAIT IDLE
MERGE = OFF
