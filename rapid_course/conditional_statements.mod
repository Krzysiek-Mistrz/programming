MODULE conditional_statements
   VAR num partnum := 2;

   PROC main()
      IF partnum = 1 THEN
         Part1;
      ELSEIF partnum = 2 THEN
         Part2;
      ELSE
         TPWrite "Error";
      ENDIF
   ENDPROC

   PROC Part1()
      TPWrite "Processing Part 1";
   ENDPROC

   PROC Part2()
      TPWrite "Processing Part 2";
   ENDPROC
ENDMODULE
