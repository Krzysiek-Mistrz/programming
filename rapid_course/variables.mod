MODULE variables
   VAR num length := 10;
   VAR string name := "robot";
   PERS num nbr := 1;
   CONST num PI := 3.1415;

   PROC main()
      TPWrite "Length: ", length;
      TPWrite "Name: ", name;
      TPWrite "Persistent Number: ", nbr;
      TPWrite "Constant PI: ", PI;
   ENDPROC
ENDMODULE
