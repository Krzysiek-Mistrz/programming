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
        bazowanie()
    ENDIF

    IF VR(set_middle) = 1 THEN
        middle()
    ENDIF

    IF VR(set_pos) = 1 THEN
        pos()
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