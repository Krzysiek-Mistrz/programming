library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity clocked_process_flip_flop_17 is
port(
    clk : in std_logic;
    --flip flop will reset when 0
    negative_reset : in std_logic;
    input : in std_logic;
    output : out std_logic
);
end entity clocked_process_flip_flop_17;

architecture rtl of clocked_process_flip_flop_17 is
begin
    --flip flop with synchronized reset
    process(clk) is
    begin
        if rising_edge(clk) then
            if negative_reset = '0' then
                output <= '0';
            else
                output <= input;
            end if;
        end if;
    end process;
end architecture rtl;