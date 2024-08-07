library library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity concurrent_statement_13 is
end entity concurrent_statement_13;

architecture sim of concurrent_statement_13 is
    signal unsigned_signal : unsigned(5 downto 0) := (others => '0');
    signal multiplication_1 : unsigned(7 downto 0);
    signal multiplication_2 : unsigned(7 downto 0);
    signal multiplication_3 : unsigned(7 downto 0);
begin
    proc_a: process is
    begin
        unsigned_signal <= unsigned_signal + 1;
        wait for 10 ns;
    end process proc_a;

    proc_b: process is
    begin
        multiplication_1 <= unsigned_signal & "00";
    end process proc_b;

    proc_c: process(unsigned_signal) is
    begin
        multiplication_2 <= unsigned_signal & "00";
    end process proc_c;

    --concurrent statement
    multiplication_3 <= unsigned_signal & "00"
    
end architecture sim;;