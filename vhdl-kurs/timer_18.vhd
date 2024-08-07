library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity timer_18 is
generic(clock_frequency : integer);
port(
    clk : in std_logic;
    --flip flop will reset when 0
    negative_reset : in std_logic;
    seconds : inout integer;
    minutes : inout integer;
    hours : inout integer
);
end entity timer_18;

architecture rtl of timer_18 is
    -- signal for counting ticks
    signal ticks : integer;
begin
    process(clk) is
    begin
        if rising_edge(clk) then
            if negative_reset = '0' then
                ticks <= 0;
                seconds <= 0;
                minutes <= 0;
                hours <= 0;
            else
                --counting seconds
                if ticks = clock_frequency - 1 then
                    ticks <= 0;
                    --counting minutes
                    if seconds = 59 then
                        seconds <= 0;
                        --counting hours
                        if minutes = 59 then
                            minutes <= 0;
                            if hours = 23 then
                                hours <= 0;
                            else
                                hours <= hours + 1;
                            end if;
                        else
                            minutes <= minutes + 1;
                        end if;
                    else
                        seconds <= seconds + 1;
                    end if;
                else
                    ticks <= ticks + 1;
                end if;
            end if;
        end if;
    end process;
end architecture rtl;