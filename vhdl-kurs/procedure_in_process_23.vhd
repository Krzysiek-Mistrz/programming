library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity procedure_in_process_23 is
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
end entity procedure_in_process_23;

architecture rtl of procedure_in_process_23 is
    --enumerated type declaration
    type state_t is (NorthNext, StartNorth, North, StopNorth, WestNext, StartWest, West, StopWest);
    signal state : state_t;
    signal counter : integer range 0 to clock_frequency * 60;
begin
    process(clk) is
        --procedure changes state after certain amount of time
        procedure change_state(to_state :  t_state; minutes : integer := 0; seconds : integer := 0) is
            variable total_seconds : integer;
            variable clock_cycles : integer;
        begin
            total_seconds := seconds + 60 * minutes;
            clock_cycles := total_seconds * clock_frequency - 1;
            if counter = clock_cycles then
                counter = 0;
                state <= to_state;
            end if;
        end procedure;
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
                        change_state(StartNorth, seconds => 5);
                    --red&yellow in north&south directions
                    when StartNorth =>
                        north_red <= '1'; 
                        north_yellow <= '1';
                        west_red <= '1';
                        change_state(North, seconds => 5);
                    --green in north&south directions
                    when North => 
                        north_green <= '1';
                        west_red <= '1';
                        change_state(StopNorth, seconds => 5);
                    --yellow in north&south directions
                    when StopNorth =>
                        north_yellow <= '1';
                        west_red <= '1';
                        change_state(WestNext, seconds => 5);
                    --red in all directions
                    when WestNext =>
                        north_red <= '1';
                        west_red <= '1';
                        change_state(StartWest, seconds => 5);
                    --red&yellow in west&east directions
                    when StartWest =>
                        north_red <= '1';
                        west_red <= '1';
                        west_yellow <= '1';
                        change_state(West, seconds => 5);
                    --green in west&east directions
                    when West =>
                        west_green <= '1';
                        north_red <= '1';
                        change_state(StopWest, seconds => 5);
                    --yellow in west&east directions
                    when StopWest =>
                        north_red <= '1';
                        west_yellow <= '1';
                        change_state(NorthNext, seconds => 5);
                        end if;
                end case;
            end if;
        end if;
    end process;
end architecture rtl;
