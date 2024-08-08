MODULE joint_move
   CONST jointtarget jt1 := [[25, 30, -10, 45, -20, 50], [9e9, 9e9, 9e9, 9e9, 9e9, 9e9]];
   PERS tooldata gripper := [TRUE, [[97.4, 0, 223.1], [0.924, 0, 0.383, 0]], [5, [23, 0, 75], [1, 0, 0, 0], 0, 0, 0]];

   PROC main()
      MoveAbsJ jt1, v1000, z100, gripper;
   ENDPROC
ENDMODULE
