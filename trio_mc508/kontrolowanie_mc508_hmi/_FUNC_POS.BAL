FUNCTION pos ()
    DIM set_pos_x AS INTEGER = 4 'zapisuje wp. pozycje osi
    DIM set_pos_y AS INTEGER = 5
    DIM set_pos_z AS INTEGER = 6
    DIM emergency_sw AS INTEGER = 8 'emergency switch
    '-230, -66, -60 to bezpieczne pozycje dla poszczegolnych osi
    'zadaj pozycje x
    IF VR(set_pos_x) > -230 AND VR(set_pos_x) < -1 THEN
        emergency(VR(emergency_sw))
        MOVEABS(VR(set_pos_x)) AXIS(0)
        WAIT IDLE AXIS(0)
    ENDIF
    'zadaj pozycje y
    IF VR(set_pos_y) > -66 AND VR(set_pos_y) < -1 THEN
        emergency(VR(emergency_sw))
        MOVEABS(VR(set_pos_y)) AXIS(1)
        WAIT IDLE AXIS(1)
    ENDIF
    'zadaj pozycje z
    IF VR(set_pos_z) > -60 AND VR(set_pos_z) < -1 THEN
        emergency(VR(emergency_sw))
        MOVEABS(VR(set_pos_z)) AXIS(2)
        WAIT IDLE AXIS(2)
    ENDIF
ENDFUNC
