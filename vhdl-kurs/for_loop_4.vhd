entity for_loop_4 is
end entity;

architecture sim of for_loop_4 is
begin
    process is
    begin
        for i in 1 to 10 loop
            report "i = " & integer'image(i);
        end loop;
        --theres need to be a wait statement on the end (in this case)
        wait;
    end process;
end architecture;