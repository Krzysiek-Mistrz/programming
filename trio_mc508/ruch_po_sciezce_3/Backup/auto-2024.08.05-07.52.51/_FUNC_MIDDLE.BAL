FUNCTION middle ()
    DIM set_middle AS INTEGER = 2 'wlacza pozycjonowanie do srodka
    DIM limit_switch AS INTEGER = 0
    DIM emergency_sw AS INTEGER = 8
    'pozycje absolutne po bazowaniu
    DIM middle_x AS INTEGER = -95
    DIM middle_y AS INTEGER = -35
    DIM middle_z AS INTEGER = -5
    emergency(VR(emergency_sw))
    'ustaw srodek jezeli zbazowano
    IF VR(limit_switch) = 3 THEN
        MOVEABS(middle_x) AXIS(0)
        emergency(VR(emergency_sw))
        WAIT IDLE AXIS(0)
        MOVEABS(middle_y) AXIS(1)
        emergency(VR(emergency_sw))
        WAIT IDLE AXIS(1)
        MOVEABS(middle_z) AXIS(2)
        emergency(VR(emergency_sw))
        WAIT IDLE AXIS(2)
    ENDIF
    VR(set_middle) = 0
ENDFUNC
