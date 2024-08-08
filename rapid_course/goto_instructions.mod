MODULE goto_instructions
   VAR num counter := 0;

   PROC main()
   Repeat:
      counter := counter + 1;
      TPWrite "Counter: ", counter;

      IF DI1 = TRUE THEN
         GOTO Repeat;
      ENDIF
   ENDPROC
ENDMODULE
