MODULE linear_movement
   CONST robtarget p1 := [[0, 0, -20], [1, 0, 0, 0], [0, 0, 0, 0], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   PERS tooldata gripper := [TRUE, [[97.4, 0, 223.1], [0.924, 0, 0.383, 0]], [5, [23, 0, 75], [1, 0, 0, 0], 0, 0, 0]];

   PROC main()
      MoveL p1, v1000, z10, gripper;
   ENDPROC
ENDMODULE
