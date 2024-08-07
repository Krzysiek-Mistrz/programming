entity wait_until_7 is
end entity;

architecture sim of wait_until_7 is
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
        wait on count_down, count_up;
        report "count up: " & integer'image(count_up) & " count down: " & integer'image(count_down);
    end process;

    process is
    begin
        wait until count_down = count_up;
        report "counters're equal";
    end process;
end architecture;