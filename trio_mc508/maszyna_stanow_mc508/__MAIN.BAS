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
                SPEED AXIS(x) = 20
                CREEP AXIS(x) = 50
                ACCEL AXIS(x) = 1000
                DECEL AXIS(x) = 1000
            NEXT x

            FORWARD AXIS(0)
            WAIT UNTIL IN(8) = 1
            CANCEL AXIS(0)

            FORWARD AXIS(1)
            WAIT UNTIL IN(9) = 1
            CANCEL AXIS(1)

            if_base = 1
            VR(state) = 1000
            WA(1000)

        CASE 1 'os 1 i os 2 z szybkoscia velocity w prawo
            'spin(200, 1) 1 odpowiada za krec w lewo
            IF if_base = 1 THEN
                FORWARD AXIS(0)
                FORWARD AXIS(1)
                WAIT UNTIL IN(1) = 0
                RAPIDSTOP
                GOTO label
            ENDIF
            VR(state) = 1000
            WA(1000)

        CASE 2 'os 1 i os 2 z szybkoscia velocity w lewo
            'spin(200, -1) -1 odpowiada za krec w lewo
            IF if_base = 1 THEN
                REVERSE AXIS(0)
                REVERSE AXIS(1)
                WAIT UNTIL IN(2) = 0
                RAPIDSTOP
                GOTO label
            ENDIF
            VR(state) = 1000
            WA(1000)

        CASE ELSE 'przeciwny przypadek
            GOTO label

    END_CASE
WEND


