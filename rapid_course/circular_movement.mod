MODULE circular_movement
   CONST robtarget t1 := [[250, -75, 400], [0, -0.707, 0.707, 0], [0, 0, 0, 0], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   CONST robtarget t2 := [[250, 75, 400], [0, -0.707, 0.707, 0], [0, 0, 0, 0], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   PERS tooldata gripper := [TRUE, [[97.4, 0, 223.1], [0.924, 0, 0.383, 0]], [5, [23, 0, 75], [1, 0, 0, 0], 0, 0, 0]];

   PROC main()
      MoveC t1, t2, v1000, z10, gripper;
   ENDPROC
ENDMODULE
