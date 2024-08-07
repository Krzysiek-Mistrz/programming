FUNCTION bazowanie()
    'vr registers local vars
    DIM limit_switch AS INTEGER = 0 'jezeli != 0 to czujnik wlaczony
    DIM emergency_sw AS INTEGER = 8
    DIM bezpiecznik_1 AS INTEGER = 0
    DIM bezpiecznik_2 AS INTEGER = 0
    DIM bezpiecznik_3 AS INTEGER = 0
    DIM if_base AS INTEGER = 10
    IF VR(limit_switch) <> 3 THEN
        FORWARD AXIS(0) 'ox dla poprawnego reverse
        FORWARD AXIS(1) 'oy dla poprawnego forward
        FORWARD AXIS(2) 'oz dla poprawnego forward
    ENDIF
    'bazowanie
    REPEAT
        'bazowanie wzg lewgo czujnika patrzac od tylu cnc
        IF IN(0) = 0 AND bezpiecznik_1 = 0 AND VR(limit_switch) <> 3 THEN
            emergency(VR(emergency_sw))
            VR(limit_switch) = VR(limit_switch) + 1
            bezpiecznik_1 = 1
            CANCEL AXIS(0)
            MOVE(-10) AXIS(0) 'dla poprawnego 10
            WAIT IDLE AXIS(0)
        ENDIF
        'bazowanie wzg prawego czujnika patrzac od tylu cnc
        IF IN(1) = 0 AND bezpiecznik_2 = 0 AND VR(limit_switch) <> 3 THEN
            emergency(VR(emergency_sw))
            VR(limit_switch) = VR(limit_switch) + 1
            bezpiecznik_2 = 1
            CANCEL AXIS(1)
            MOVE(-10) AXIS(1) 'dla poprawnego -10
            WAIT IDLE AXIS(1)
        ENDIF
        IF IN(2) = 0 AND bezpiecznik_3 = 0 AND VR(limit_switch) <> 3 THEN
            emergency(VR(emergency_sw))
            VR(limit_switch) = VR(limit_switch) + 1
            bezpiecznik_3 = 1
            CANCEL AXIS(2)
            MOVE(-10) AXIS(2) 'dla poprawnego -10
            WAIT IDLE AXIS(2)
        ENDIF
    UNTIL VR(limit_switch) = 3
    BASE(0, 1, 2)
    DEFPOS(0, 0, 0) 'wyzeruj pozycje po bazowaniu
    RAPIDSTOP(2)
ENDFUNC
