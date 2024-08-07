library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity signed_uns_12 is
end entity;

architecture sim of signed_uns_12 is
    signal unsigned_counter : unsigned(7 downto 0) := (others => '0');
    signal signed_counter : signed(7 downto 0) := (others => '0');
    signal unsigned_4 : unsigned(3 downto 0) := "1000";
    signal signed_4 : signed(3 downto 0) := "1000";
    signal unsigned_8 : unsigned(7 downto 0) := (others => '0');
    signal signed_8 : signed(7 downto 0) := (others => '0');
begin
    process is
    begin
        --wraping counter
        unsigned_counter <= unsigned_counter + 1;
        signed_counter <= signed_counter + 1;
        --adding signals
        unsigned_8 <= unsigned_8 + unsigned_4;
        signed_8 <= signed_8 + signed_4;
        wait for 10 ns;
    end process;
end architecture;