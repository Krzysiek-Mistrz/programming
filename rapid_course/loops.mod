MODULE loops
   VAR num repeat := 3;

   PROC main()
      WHILE repeat > 0 DO
        TPWrite "repeat count ", repeat;
        repeat := repeat - 1;
        IF repeat = 1 THEN
           BREAK;
        ENDIF
      ENDWHILE

      FOR VAR num i FROM 1 TO 10 DO
         TPWrite "For Loop Count: ", i;
      ENDFOR
   ENDPROC
ENDMODULE
