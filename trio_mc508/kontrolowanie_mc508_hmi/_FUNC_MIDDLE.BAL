FUNCTION middle ()
    DIM emergency_sw AS INTEGER = 8
    DIM middle_x AS INTEGER = -118
    DIM middle_y AS INTEGER = -33
    DIM middle_z AS INTEGER = -30.675
    emergency(VR(emergency_sw))
    'ustaw srodek
    MOVEABS(middle_x) AXIS(0)
    WAIT IDLE AXIS(0)
    MOVEABS(middle_y) AXIS(1)
    WAIT IDLE AXIS(1)
    MOVEABS(middle_z) AXIS(2)
    WAIT IDLE AXIS(2)
ENDFUNC
