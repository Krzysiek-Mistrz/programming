library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity finite_state_machine_tb_20 is
end entity finite_state_machine_tb_20;

architecture sim of finite_state_machine_tb_20 is
    --100Hz freq
    constant clock_frequency : integer := 100; 
    --1s = 1000ms
    constant clock_period : time := 1000 ms / clock_frequency;
    --clock signal
    signal clk : std_logic := '1';
    signal negative_reset : std_logic;
    --fsm vars
    signal north_red : std_logic;
    signal north_yellow : std_logic;
    signal north_green : std_logic;
    signal west_red : std_logic;
    signal west_yellow : std_logic;
    signal west_green : std_logic;
begin
    --device under tst (DUT)
    fsm : entity work.finite_state_machine_20(rtl) 
    generic map(clock_frequency => clock_frequency)
    port map(
        clk => clk,
        negative_reset => negative_reset,
        north_red => north_red,
        north_yellow => north_yellow,
        north_green => north_green,
        west_red => west_red,
        west_yellow => west_yellow,
        west_green => west_green
    );
    --process for generating clock, clock changing after half of the period (graph with period...)
    clk <= not clk after clock_period / 2;
    --tesbench sequence
    process is
    begin
        wait until rising_edge(clk);
        wait until rising_edge(clk);
        negative_reset <= '1';
        wait;
    end process;
end architecture sim;