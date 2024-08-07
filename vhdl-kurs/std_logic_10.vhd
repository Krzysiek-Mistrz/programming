library IEEE;
use IEEE.std_logic_1164.all;

entity std_logic_10 is
end entity std_logic_10;

architecture sim of std_logic_10 is
    signal signal_1 : std_logic := '0';
    signal signal_2 : std_logic;
    signal signal_3 : std_logic;
begin
    process is
    begin
        signal_1 <= not signal_1;
        wait for 10 ns;
    end process;
    --driver a
    process is
    begin
        signal_2 <= 'Z';
        signal_3 <= '0';
        wait;
    end process;
    --driver b will wake up every 10ns
    process(signal_1) is
    begin
        if signal_1 = '0' then
            signal_2 <= 'Z';
            signal_3 <= 'Z';
        else
            signal_2 <= '1';
            signal_3 <= '1';
        end if;
    end process;
end architecture sim;