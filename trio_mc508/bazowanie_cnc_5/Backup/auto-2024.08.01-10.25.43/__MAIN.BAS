'opis rejestrow
'0 - limit_sw
'1 - base
'2 - middle
'3 - pos
'8 - emergency
'9 - on/off

INCLUDE "_GLOBAL_VARS"

WDOG = ON

'debug purposes
'REVERSE AXIS(0) 'ox
'FORWARD AXIS(1) 'oy
'FORWARD AXIS(2) 'oz
VR(curr_speed) = 5
VR(limit_switch) = 0

'krancowka x: -0.495
'krancowka y: -0.495
'krancowka z: -61.35
start:
WHILE VR(emergency_sw) = 0 AND VR(on_off) = 1
    IF VR(base_control) = 1 THEN
        bazowanie()
        WA(1000)
    ENDIF

    IF VR(set_middle) = 1 THEN
        middle()
        WA(1000)
        'debug purposes
        'PRINT #0, "POSITION = "; MPOS AXIS(0)
        'PRINT #0, "POSITION = "; MPOS AXIS(1)
        'PRINT #0, "POSITION = "; MPOS AXIS(2)
    ENDIF

    IF VR(set_pos) = 1 THEN
        pos()
        WA(1000)
    ENDIF

    emergency(VR(emergency_sw))
    'zadaj szybkosc dla osi bez funkcji i warunkow
    SPEED AXIS(0) = VR(curr_speed)
    SPEED AXIS(1) = VR(curr_speed)
    SPEED AXIS(2) = VR(curr_speed)
WEND

IF VR(on_off) = 0 OR VR(emergency_sw) = 1 THEN
    GOTO start
ENDIF
