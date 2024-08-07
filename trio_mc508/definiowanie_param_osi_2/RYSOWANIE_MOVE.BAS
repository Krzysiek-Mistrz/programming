WDOG=ON

'PREDKOSCI OSI 0
BASE(0, 1)
MERGE = ON
'SERVO = ON praca w zamknietej petli sterowania
SPEED=20 'ustawienie prędkości osi
ACCEL=1000 'ustawienie przyśpieszenia osi
DECEL=1000 'ustawienie opóźnienia osi

'BAZOWANIE
'CREEP=50 określenie prędkości bazowania
'DATUM(3) 'wybór trybu bazowania

'RUCH
MOVE(0, 12)
MOVE(3, -6)
MOVE(3, 6)
MOVE(0, -12)
