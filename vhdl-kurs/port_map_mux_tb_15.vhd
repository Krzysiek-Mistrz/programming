library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity port_map_mux_tb_15 is
end entity port_map_mux_tb_15;

architecture sim of port_map_mux_tb_15 is
    --inputs of multiplexer
    signal signal_1 : unsigned(7 downto 0) := x"AA";
    signal signal_2 : unsigned(7 downto 0) := x"BB";
    signal signal_3 : unsigned(7 downto 0) := x"CC";
    signal signal_4 : unsigned(7 downto 0) := x"DD";
    --selector signal of multiplexer
    signal selector : unsigned(1 downto 0) := (others => '0');
    --output signal
    signal output : unsigned(7 downto 0);
begin
    --instance of mux rtl (file: port_map_mux_15)
    mux_1 : entity work.port_map_mux_15(rtl) port map(
        selector => selector,
        signal_1 => signal_1,
        signal_2 => signal_2,
        signal_3 => signal_3,
        signal_4 => signal_4,
        output => output
    );
    --testbench process
    stimulation: process is
    begin
        wait for 10 ns;
        selector <= selector + 1;
        wait for 10 ns;
        selector <= selector + 1;
        wait for 10 ns;
        selector <= selector + 1;
        wait for 10 ns;
        selector <= selector + 1;
        wait for 10 ns;
        selector <= "UU";
        wait;
    end process stimulation;
end architecture sim;