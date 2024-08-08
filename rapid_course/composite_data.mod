MODULE composite_data
   VAR pos p1 := [400, 0, 200];
   VAR orient o1 := [1, 0, 0, 0];
   VAR pose target1 := [p1, o1];
   VAR confdata cd1 := [1, -1, 0, 0];
   VAR zonedata stop_path := [TRUE, 25, 40, 40, 10, 35, 5]; !stop positions
   
   PROC main()
      TPWrite "position: ", p1;
      TPWrite "orientation: ", o1;
      TPWrite "configuration: ", cd1;
      TPWrite "zone data: ", stop_path
   ENDPROC
ENDMODULE