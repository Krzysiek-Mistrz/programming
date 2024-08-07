library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity clocked_process_tb_17 is
end entity clocked_process_tb_17;

architecture sim of clocked_process_tb_17 is
    --100MHz freq
    constant clock_frequency : integer := 100e6; 
    --1s = 1000ms
    constant clock_period : time := 1000 ms / clock_frequency;
    --clock signal
    signal clk : std_logic := '1';
    --flip flop signals
    signal negative_reset : std_logic := '0';
    signal input : std_logic := '0';
    signal output : std_logic;
begin
    --device under tst (DUT)
    flip_flop : entity work.clocked_process_flip_flop_17(rtl) 
    port map(
        clk => clk,
        negative_reset => negative_reset,
        input => input,
        output => output
    );
    --process for generating clock, clock changing after half of the period (graph with period...)
    clk <= not clk after clock_period / 2;
    --tb input sequence for flip flop
    tb_input: process is
    begin
        negative_reset <= '1';
        wait for 20 ns;
        input <= '1';
        wait for 22 ns;
        input <= '0';
        wait for 6 ns;
        input <= '1';
        wait for 20 ns;
        negative_reset <= '0';
        wait;
    end process tb_input;
end architecture sim;