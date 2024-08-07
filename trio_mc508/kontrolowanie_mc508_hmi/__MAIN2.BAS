INCLUDE "_GLOBAL_VARS"

REVERSE AXIS(0) 'ox
FORWARD AXIS(1) 'oy
FORWARD AXIS(2) 'oz
VR(limit_switch) = 1000

'krancowka x: -0.495
'krancowka y: -0.495
'krancowka z: -61.35
start:
WHILE VR(emergency_sw) = 0 AND VR(on_off) = 1
    IF VR(base_control) = 1 THEN
        'bazowanie
        REPEAT
            'bazowanie wzg lewgo czujnika patrzac od tylu cnc
            IF IN(0) = 0 THEN
                emergency(VR(emergency_sw))
                VR(limit_switch) = 0
                CANCEL AXIS(0)
                MOVE(10) AXIS(0)
                'bazowanie wzg prawego czujnika patrzac od tylu cnc
            ELSEIF IN(1) = 0 THEN
                emergency(VR(emergency_sw))
                VR(limit_switch) = 0
                CANCEL AXIS(1)
                MOVE(-10) AXIS(1)
            ELSEIF IN(2) = 0 THEN
                emergency(VR(emergency_sw))
                VR(limit_switch) = 0
                CANCEL AXIS(2)
                MOVE(-10) AXIS(2)
            ELSE
                emergency(VR(emergency_sw))
                VR(limit_switch) = 1000
            ENDIF
        UNTIL VR(limit_switch) = 0
    ENDIF

    IF VR(set_middle) = 1 THEN
        emergency(VR(emergency_sw))
        'ustaw srodek
        MOVEABS(middle_x) AXIS(0)
        MOVEABS(middle_y) AXIS(1)
        MOVEABS(middle_z) AXIS(2)
    ENDIF

    IF VR(set_pos) = 1 THEN
        '-230, -66, -60 to bezpieczne pozycje dla poszczegolnych osi
        'zadaj pozycje x
        IF VR(set_pos_x) > -230 AND VR(set_pos_x) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_x)) AXIS(0)
        ENDIF
        'zadaj pozycje y
        IF VR(set_pos_y) > -66 AND VR(set_pos_y) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_y)) AXIS(1)
        ENDIF
        'zadaj pozycje z
        IF VR(set_pos_z) > -60 AND VR(set_pos_z) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_z)) AXIS(2)
        ENDIF
    ENDIF

    emergency(VR(emergency_sw))
    'zadaj szybkosc dla osi bez funkcji i warunkow
    SPEED AXIS(0) = VR(curr_speed)
    SPEED AXIS(1) = VR(curr_speed)
    SPEED AXIS(2) = VR(curr_speed)
WEND

IF VR(on_off) = 0 THEN
    GOTO start
ENDIF