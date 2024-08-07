library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity procedure_19 is
generic(clock_frequency : integer);
port(
    clk : in std_logic;
    -- flip flop will reset when 0
    negative_reset : in std_logic;
    seconds : inout integer;
    minutes : inout integer;
    hours : inout integer
);
end entity procedure_19;

architecture rtl of procedure_19 is
    -- signal for counting ticks
    signal ticks : integer := 0;
    -- increment signals procedure
    procedure increment_wrap(signal counter : inout integer; constant wrap_value : in integer; variable wrapped : out boolean; constant enable : in boolean) is
    begin
        if enable then
            if counter = wrap_value - 1 then
                wrapped := true;
                counter <= 0;
            else
                wrapped := false;
                counter <= counter + 1;
            end if;
        end if;
    end procedure;
begin
    process(clk) is
        variable wrap : boolean;
    begin
        if rising_edge(clk) then
            if negative_reset = '0' then
                ticks <= 0;
                seconds <= 0;
                minutes <= 0;
                hours <= 0;
            else
                -- cascade counters
                increment_wrap(ticks, clock_frequency, wrap, true);
                -- counting seconds
                increment_wrap(seconds, 60, wrap, wrap);
                -- counting minutes
                increment_wrap(minutes, 60, wrap, wrap);
                -- counting hours
                increment_wrap(hours, 24, wrap, wrap);
            end if;
        end if;
    end process;
end architecture rtl;
