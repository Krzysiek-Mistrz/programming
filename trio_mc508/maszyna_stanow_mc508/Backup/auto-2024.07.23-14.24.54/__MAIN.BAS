'schemat programu
'jezeli IN(0) = 1 to uruchom bazowanie osi 1 i 2 z szybkoscia velocity
'jezeli IN(1) = 1 to uruchom os 1 i os 2 z szybkoscia velocity w prawo
'jezeli IN(2) = 1 to uruchom os 1 i os 2 z szybkoscia velocity w lewo

'zmienne globalne
stan = 0
czy_bazowanie = 0


WDOG = ON


FUNCTION set_vel(velocity AS INTEGER)
    FOR x = 0 TO 2
        SPEED AXIS(x) = velocity
    NEXT x
ENDFUNC


FUNCTION bazuj(vel, acl, dec, crp, ut)
    FOR x = 0 TO 2
        UNITS AXIS(x) = ut
        SPEED AXIS(x) = vel
        CREEP AXIS(x) = crp
        ACCEL AXIS(x) = acl
        DECEL AXIS(x) = dec
    NEXT x

    WHILE IN(8) = 0 'bazowanie axis 0 wzg pojemnosciowego
        MOVE(3) AXIS(0)
    WEND

    WHILE IN(9) = 0 'bazowanie axis 1 wzg pojemnosciowego
        MOVE(3) AXIS(1)
    WEND

    czy_bazowanie = 1

ENDFUNC


FUNCTION krec(vel, dire)
    set_vel(vel)
    IF czy_bazowanie = 1 AND dire = 1 THEN
        WHILE TRUE
            MOVE(3) AXIS(0)
            MOVE(3) AXIS(1)
            IF IN(1) = 0 THEN
                GOTO label
            ENDIF
        WEND
    ENDIF
    IF czy_bazowanie = 1 AND dire = -1 THEN
        WHILE TRUE
            MOVE(-3) AXIS(0)
            MOVE(-3) AXIS(1)
            IF IN(2) = 0 THEN
                GOTO label
            ENDIF
        WEND
    ENDIF
ENDFUNC


set_vel(200)


WHILE TRUE
label:
    IF IN(0) = 1 AND IN(1) = 0 AND IN(2) = 0 THEN
        stan = 0 'bazowanie
    ELSEIF IN(0) = 0 AND IN(1) = 1 AND IN(2) = 0 THEN
        stan = 1 'os 1 i os 2 z szybkoscia velocity w prawo
    ELSEIF IN(0) = 0 AND IN(1) = 0 AND IN(2) = 1 THEN
        stan = 2 'os 1 i os 2 z szybkoscia velocity w lewo
    ELSE
        stan = 1000
    ENDIF

    SELECT_CASE stan
        CASE 0 'bazowanie
            bazuj(200, 1000, 1000, 50, 6400)
            WA(1000)

        CASE 1 'os 1 i os 2 z szybkoscia velocity w prawo
            krec(200, 1) '1 odpowiada za krec w lewo
            WA(1000)

        CASE 2 'os 1 i os 2 z szybkoscia velocity w lewo
            krec(200, -1) '-1 odpowiada za krec w lewo
            WA(1000)

        CASE ELSE 'przeciwny przypadek

    END_CASE
WEND


