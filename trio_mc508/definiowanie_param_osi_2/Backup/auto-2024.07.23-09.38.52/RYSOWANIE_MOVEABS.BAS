WDOG=ON

'PREDKOSCI OSI 0
BASE(0, 1)
'SERVO = ON praca w zamknietej petli sterowania
SPEED=200 'ustawienie prędkości osi
ACCEL=1000 'ustawienie przyśpieszenia osi
DECEL=1000 'ustawienie opóźnienia osi

'BAZOWANIE
'CREEP=50 określenie prędkości bazowania
'DATUM(3) 'wybór trybu bazowania

'RUCH
MOVEABS(0, 0) 'ruch do A
MOVE(0, 12) 'ruch a -> b
MOVE(3, 9) 'ruch a -> b
MOVE(6, 12) 'ruch c -> d
MOVE(6, 0) 'ruch d -> e
