library IEEE;
use IEEE.std_logic_1164.all;

entity signa_vector_11 is
end entity signa_vector_11;

architecture sim of signa_vector_11 is
    --declaring 8 bit vector in vhdl
    signal signal_vector_1 : std_logic_vector(7 downto 0);
    --initializing all std_logic signals of vector to '0'
    signal signal_vector_2 : std_logic_vector(7 downto 0) := (others => '0');
    signal signal_vector_3 : std_logic_vector(7 downto 0) := (others => '1');
    --initializing vector with AA hex value
    signal signal_vector_4 : std_logic_vector(7 downto 0) := x"AA";
    signal signal_vector_5 : std_logic_vector(0 to 7) := "10101010";
    signal signal_vector_6 : std_logic_vector(7 downto 0) := "00000001";
begin
    --shift register
    process is
    begin
        wait for 10 ns;
        for i in signal_vector_6'left downto signal_vector_6'right + 1 loop
            --przesuwamy bit 1 w gore do 7, tzn przypisanie jest 7 <- 6, 6 <- 5, ...
            signal_vector_6(i) <= signal_vector_6(i - 1);
        end loop;
        signal_vector_6(signal_vector_6'right) <= signal_vector_6(signal_vector_6'left);
    end process;
end architecture sim;