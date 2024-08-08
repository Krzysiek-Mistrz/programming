MODULE interruptions
   VAR intnum ihandler;

   PROC main()
      CONNECT ihandler WITH iroutine;
      ISignalDI DI1, 1, ihandler;
   ENDPROC

   TRAP iroutine
      TPWrite "Interrupt Routine Executed";
   ENDTRAP
ENDMODULE
