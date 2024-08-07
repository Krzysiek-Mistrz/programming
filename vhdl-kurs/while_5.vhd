entity while_5 is
end entity;

architecture sim of while_5 is
begin
    process is
        variable i : integer := 0;
    begin
        while i < 10 loop
            report "i = " & integer'image(i);
            i := i + 2;
        end loop;
        wait;
    end process;
end architecture;