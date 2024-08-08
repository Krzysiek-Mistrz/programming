MODULE acceleration_offset
   VAR speeddata speed := [100, 300, 300, 500];
   VAR num ramp := 30;
   VAR speed := 100;
   CONST robtarget t1 := [[-, 0, 20], [0.707, 0, 0, 0.707], [0, 0, 0, 0], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   const jointtarget jt1 := [[25, 30, -10, 45, -20, 50], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   PERS tooldata gripper := [TRUE, [[97.4, 0, 223.1], [0.924, 0, 0.383, 0]], [5, [23, 0, 75], [1, 0, 0, 0], 0, 0, 0]];

   PROC main()
      AccSet speed, ramp;
      MoveAbsJ jt1, speed, z10, gripper;
      MoveJ Offs(t1, 0, 0, -20), speed, z5, gripper;
      MoveL t1, v50, fine, gripper;
   ENDPROC
ENDMODULE
