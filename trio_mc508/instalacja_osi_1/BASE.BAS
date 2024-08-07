WDOG=ON

FOR x = 0 TO 2
    BASE(x)
    SERVO = ON
    SPEED=200 'ustawienie prędkości osi
    ACCEL=1000 'ustawienie przyśpieszenia osi
    DECEL=1000 'ustawienie opóźnienia osi
    CREEP=50 'określenie prędkości bazowania
    DATUM(3) 'wybór trybu bazowania
NEXT x

WAIT IDLE AXIS(0) 'oczekiwania, aż oś zakończy prace
WAIT IDLE AXIS(1) 'oczekiwania, aż oś zakończy prace
WAIT IDLE AXIS(2) 'oczekiwania, aż oś zakończy prace
