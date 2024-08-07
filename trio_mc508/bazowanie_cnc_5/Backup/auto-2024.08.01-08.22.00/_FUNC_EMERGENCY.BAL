FUNCTION emergency (set_emergency AS INTEGER)
    IF set_emergency = 1 THEN
        'emergency switch
        RAPIDSTOP(2)
        STOP "__MAIN"
    ENDIF
ENDFUNC
