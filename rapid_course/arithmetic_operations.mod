MODULE arithmetic_operations
   VAR num a := 10;
   VAR num b := 5;
   VAR num sum;
   VAR num difference;
   VAR num product;
   VAR num quotient;

   PROC main()
      sum := a + b;
      difference := a - b;
      product := a * b;
      quotient := a / b;

      TPWrite "Sum: ", sum;
      TPWrite "Difference: ", difference;
      TPWrite "Product: ", product;
      TPWrite "Quotient: ", quotient;
   ENDPROC
ENDMODULE
