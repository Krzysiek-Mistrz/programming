MODULE own_functions
   VAR num a := 5;
   VAR num b := 10;
   VAR num result;

   PROC main()
      result := Add(a, b);
      TPWrite "Result of Addition: ", result;
   ENDPROC

   FUNC num Add(num x, num y)
      RETURN x + y;
   ENDFUNC
ENDMODULE
