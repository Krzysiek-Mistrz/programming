entity sensitivity_list_9 is
end entity sensitivity_list_9;

architecture sim of sensitivity_list_9 is
    signal count_up : integer := 0;
    signal count_down : integer := 10;
begin
    process is
    begin
        count_down <= count_down - 1;
        count_up <= count_up + 1;
        wait for 10 ns;
    end process;
    process is
    begin
        if count_up = count_down then
            report "process a: counters equal!";
        end if;
        wait on count_down, count_up;
    end process;
    process(count_down, count_up) is
    begin
        if count_down = count_up then
            report "process b: counters are equal!";
        end if;
    end process;
end architecture sim;