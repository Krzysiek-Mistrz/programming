library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity procedure_tb_19 is
end entity procedure_tb_19;

architecture sim of procedure_tb_19 is
    --10Hz freq
    constant clock_frequency : integer := 10; 
    --1s = 1000ms
    constant clock_period : time := 1000 ms / clock_frequency;
    --clock signal
    signal clk : std_logic := '1';
    --flip flop signals
    signal negative_reset : std_logic := '0';
    --signals for time
    signal seconds : integer;
    signal minutes : integer;
    signal hours : integer;
begin
    --device under tst (DUT)
    timer : entity work.procedure_19(rtl) 
    generic map(clock_frequency => clock_frequency) 
    port map(
        clk => clk,
        negative_reset => negative_reset,
        seconds => seconds,
        minutes => minutes,
        hours => hours
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