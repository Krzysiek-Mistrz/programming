INCLUDE "_GLOBAL_VARS"


WDOG = ON


FORWARD AXIS(0)
FORWARD AXIS(1)
VR(limit_switch) = 1000

WHILE TRUE
'REPEAT
    'bazowanie wzg lewgo czujnika patrzac od tylu cnc
    IF IN(0) = 1 THEN
        VR(limit_switch) = 0
        CANCEL AXIS(0)
        WA(500)
        MOVE(-10) AXIS(0)
        'bazowanie wzg prawego czujnika patrzac od tylu cnc
    ELSEIF IN(1) = 1 THEN
        VR(limit_switch) = 0
        CANCEL AXIS(0)
        WA(500)
        MOVE(10) AXIS(0)
    ELSEIF IN(2) = 1 THEN
        VR(limit_switch) = 0
        CANCEL AXIS(1)
        WA(500)
        MOVE(-10) AXIS(1)
        'ELSEIF IN(3) = 0 THEN
        '   VR(limit_switch) = 4
        '   CANCEL AXIS(1)
        '   MOVE(10)
    ELSE
        VR(limit_switch) = 1000
    ENDIF

'UNTIL VR(limit_switch) = 0 ' wykonuj tak dlugo az vr(limit_switch) nie bedzie 0
WEND

