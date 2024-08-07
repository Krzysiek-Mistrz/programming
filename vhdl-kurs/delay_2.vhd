entity delay_2 is
end entity;

architecture sim of delay_2 is
begin
    process is
    begin
        report "kabuum!";
        wait for 10 ns;
    end process;
end architecture;