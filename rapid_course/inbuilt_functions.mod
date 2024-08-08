MODULE inbuilt_functions
   VAR num angle := 30;
   VAR num result;

   PROC main()
      result := Cos(angle);
      TPWrite "Cosine of ", angle, ": ", result;

      result := Sqrt(16);
      TPWrite "Square root of 16: ", result;
   ENDPROC
ENDMODULE
