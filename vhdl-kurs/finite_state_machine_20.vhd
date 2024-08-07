library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity finite_state_machine_20 is
generic(clock_frequency : integer);
port(
    clk : in std_logic;
    negative_reset  : in std_logic;
    north_red       : out std_logic;
    north_yellow    : out std_logic;
    north_green      : out std_logic;
    west_red       : out std_logic;
    west_yellow    : out std_logic;
    west_green     : out std_logic
);
end entity finite_state_machine_20;

architecture rtl of finite_state_machine_20 is
    --enumerated type declaration
    type state_t is (NorthNext, StartNorth, North, StopNorth, WestNext, StartWest, West, StopWest);
    signal state : state_t;
    signal counter : integer range 0 to clock_frequency * 60;
begin
    process(clk) is
    begin
        if rising_edge(clk) then
            if negative_reset = '0' then
                state <= NorthNext;
                counter <= 0;
                north_red <= '1';
                north_yellow <= '0';
                north_green <= '0';
                west_red <= '1';
                west_yellow <= '0';
                west_green <= '0';
            else
                --default values
                north_red <= '0';
                north_yellow <= '0';
                north_green <= '0';
                west_red <= '0';
                west_yellow <= '0';
                west_green <= '0';
                counter <= counter + 1;
                case state is
                    --red in all directions
                    when NorthNext =>
                        north_red <= '1';
                        west_red <= '1';
                        --if 5 sec passed
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= StartNorth;
                        end if;
                    --red&yellow in north&south directions
                    when StartNorth =>
                        north_red <= '1'; 
                        north_yellow <= '1';
                        west_red <= '1';
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= North;
                        end if;
                    --green in north&south directions
                    when North => 
                        north_green <= '1';
                        west_red <= '1';
                        if counter = clock_frequency * 60 - 1 then
                            counter <= 0;
                            state <= StopNorth;
                        end if;
                    --yellow in north&south directions
                    when StopNorth =>
                        north_yellow <= '1';
                        west_red <= '1';
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= WestNext;
                        end if;
                    --red in all directions
                    when WestNext =>
                        north_red <= '1';
                        west_red <= '1';
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= StartWest;
                        end if;
                    --red&yellow in west&east directions
                    when StartWest =>
                        north_red <= '1';
                        west_red <= '1';
                        west_yellow <= '1';
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= West;
                        end if;
                    --green in west&east directions
                    when West =>
                        west_green <= '1';
                        north_red <= '1';
                        if counter = clock_frequency * 60 - 1 then
                            counter <= 0;
                            state <= StopWest;
                        end if;
                    --yellow in west&east directions
                    when StopWest =>
                        north_red <= '1';
                        west_yellow <= '1';
                        if counter = clock_frequency * 5 - 1 then
                            counter <= 0;
                            state <= NorthNext;
                        end if;
                end case;
            end if;
        end if;
    end process;
end architecture rtl;
