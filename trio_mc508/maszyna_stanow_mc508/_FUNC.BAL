INCLUDE "_GLOBAL_VARIABLES"

FUNCTION set_vel(velocity AS INTEGER) AS INTEGER
    FOR x = 0 TO 2
        SPEED AXIS(x) = velocity
    NEXT x
    RETURN 0
ENDFUNC

FUNCTION set_base(vel, acl, dec, crp, ut AS INTEGER) AS INTEGER
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

    if_base = 1

    RETURN 0

ENDFUNC


FUNCTION spin(vel, dire AS INTEGER) AS INTEGER
    set_vel(vel)
    IF if_base = 1 AND dire = 1 THEN
        WHILE TRUE
            MOVE(3) AXIS(0)
            MOVE(3) AXIS(1)
            IF IN(1) = 0 THEN
                RETURN 0 'normalnie label
            ENDIF
        WEND
    ENDIF
    IF if_base = 1 AND dire = -1 THEN
        WHILE TRUE
            MOVE(-3) AXIS(0)
            MOVE(-3) AXIS(1)
            IF IN(2) = 0 THEN
                RETURN 0 'normalnie label
            ENDIF
        WEND
    ENDIF
    RETURN 1
ENDFUNC
