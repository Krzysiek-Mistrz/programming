entity conditional_statement_8 is
end entity;

architecture sim of conditional_statement_8 is
    signal count_up : integer := 0;
    signal count_down : integer := 10;
begin
    process is
    begin
        count_up <= count_up + 1;
        count_down <= count_down - 1;
        wait for 10 ns;
    end process;
    process is
    begin
        if count_up > count_down then
            report "count up counter is larger";
        elsif count_down > count_up then
            report "count down counter is larger";
        else
            report "counters're equal";
        end if;
        wait on count_down, count_up;
    end process;
end architecture;