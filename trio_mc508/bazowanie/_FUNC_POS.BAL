FUNCTION pos ()
    DIM set_pos AS INTEGER = 3 'wlacza wpisywanie do numeric
    DIM limit_switch AS INTEGER = 0
    DIM set_pos_x AS INTEGER = 4 'zapisuje wp. pozycje osi
    DIM set_pos_y AS INTEGER = 5
    DIM set_pos_z AS INTEGER = 6
    DIM emergency_sw AS INTEGER = 8 'emergency switch
    '-230, -66, -60 to bezpieczne pozycje dla poszczegolnych osi
    'zadaj pozycje x jezeli wykonano bazowanie
    IF VR(limit_switch) = 3 THEN
        IF VR(set_pos_x) > 0 THEN
            VR(set_pos_x) = -VR(set_pos_x)
            VR(set_pos_y) = -VR(set_pos_y)
            VR(set_pos_z) = -VR(set_pos_z)
        ENDIF
        IF VR(set_pos_x) > -295 AND VR(set_pos_x) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_x)) AXIS(0)
            WAIT IDLE AXIS(0)
        ENDIF
        'zadaj pozycje y
        IF VR(set_pos_y) > -80 AND VR(set_pos_y) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_y)) AXIS(1)
            WAIT IDLE AXIS(1)
        ENDIF
        'zadaj pozycje z
        IF VR(set_pos_z) > -20 AND VR(set_pos_z) < -1 THEN
            emergency(VR(emergency_sw))
            MOVEABS(VR(set_pos_z)) AXIS(2)
            WAIT IDLE AXIS(2)
        ENDIF
        VR(set_pos) = 0
    ENDIF
ENDFUNC

