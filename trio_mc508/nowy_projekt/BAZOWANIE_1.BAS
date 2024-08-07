WDOG = ON

IF IN(0) = ON AND IN(1) = ON AND IN(2) = ON THEN
    FOR x=0 TO 2
        BASE(x)
        SERVO = ON
        INVERT_IN(x, 1)
        DATUM(3)
        INVERT_IN(x, 0)
    NEXT x

    WAIT IDLE AXIS(1)
    WAIT IDLE AXIS(2)
    WAIT IDLE AXIS(0)
ENDIF



