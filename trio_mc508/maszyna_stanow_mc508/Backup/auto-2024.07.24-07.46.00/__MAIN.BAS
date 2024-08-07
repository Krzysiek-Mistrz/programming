'schemat programu
'jezeli IN(0) = 1 to uruchom bazowanie osi 1 i 2 z szybkoscia velocity
'jezeli IN(1) = 1 to uruchom os 1 i os 2 z szybkoscia velocity w prawo
'jezeli IN(2) = 1 to uruchom os 1 i os 2 z szybkoscia velocity w lewo


INCLUDE "_GLOBAL_VARIABLES"


WDOG = ON


WHILE TRUE
label:
    VR(sw_0) = IN(0)
    VR(sw_1) = IN(1)
    VR(sw_2) = IN(2)
    IF VR(sw_0) = 1 AND VR(sw_1) = 0 AND VR(sw_2) = 0 THEN
        VR(state) = 0 'bazowanie
    ELSEIF VR(sw_0) = 0 AND VR(sw_1) = 1 AND VR(sw_2) = 0 THEN
        VR(state) = 1 'os 1 i os 2 z szybkoscia velocity w prawo
    ELSEIF VR(sw_0) = 0 AND VR(sw_1) = 0 AND VR(sw_2) = 1 THEN
        VR(state) = 2 'os 1 i os 2 z szybkoscia velocity w lewo
    ELSE
        VR(state) = 1000
    ENDIF

    SELECT_CASE VR(state)
        CASE 0 'bazowanie
            FOR x = 0 TO 2
                UNITS AXIS(x) = 6400
                SPEED AXIS(x) = 200
                CREEP AXIS(x) = 50
                ACCEL AXIS(x) = 1000
                DECEL AXIS(x) = 1000
            NEXT x

            WHILE IN(8) = 0 'bazowanie axis 0 wzg pojemnosciowego
                MOVE(3) AXIS(0)
            WEND

            WHILE IN(9) = 0 'bazowanie axis 1 wzg pojemnosciowego
                MOVE(3) AXIS(1)
            WEND

            if_base = 1
            WA(1000)

        CASE 1 'os 1 i os 2 z szybkoscia velocity w prawo
            'spin(200, 1) 1 odpowiada za krec w lewo
            IF if_base = 1 THEN
                WHILE TRUE
                    MOVE(3) AXIS(0)
                    MOVE(3) AXIS(1)
                    VR(sw_1) = IN(1)
                    IF VR(sw_1) = 0 THEN
                        GOTO label
                    ENDIF
                WEND
            ENDIF
            WA(1000)

        CASE 2 'os 1 i os 2 z szybkoscia velocity w lewo
            'spin(200, -1) -1 odpowiada za krec w lewo
            IF if_base = 1 THEN
                WHILE TRUE
                    MOVE(-3) AXIS(0)
                    MOVE(-3) AXIS(1)
                    VR(sw_2) = IN(2)
                    IF VR(sw_2) = 0 THEN
                        GOTO label
                    ENDIF
                WEND
            ENDIF
            WA(1000)

        CASE ELSE 'przeciwny przypadek
            GOTO label

    END_CASE
WEND


