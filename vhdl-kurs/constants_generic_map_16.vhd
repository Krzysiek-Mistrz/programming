library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity constants_generic_map_16 is
generic(data_width : integer);
port(
    --inputs signals
    signal_1 : in unsigned(data_width - 1 downto 0);
    signal_2 : in unsigned(data_width - 1 downto 0);
    signal_3 : in unsigned(data_width - 1 downto 0);
    signal_4 : in unsigned(data_width - 1 downto 0);
    --input selector
    selector : in unsigned(1 downto 0);
    --output
    output : out unsigned(data_width - 1 downto 0)
);
end entity constants_generic_map_16;

--rtl -> register transfer level because its now a module not a tb :)
architecture rtl of constants_generic_map_16 is
begin
    --dont need stimuli for the selector in real device
    -- stimulation: process is
    -- begin
    --     wait for 10 ns;
    --     selector <= selector + 1;
    --     wait for 10 ns;
    --     selector <= selector + 1;
    --     wait for 10 ns;
    --     selector <= selector + 1;
    --     wait for 10 ns;
    --     selector <= selector + 1;
    --     wait for 10 ns;
    --     selector <= "UU";
    --     wait;
    -- end process stimulation;
    --MUX using case statement -> preffered way of implementing multiplexer :)
    process_case : process(selector) is
    begin
        case selector is
            when "00" =>
                output <= signal_1;
            when "01" =>
                output <= signal_2;
            when "10" =>
                output <= signal_3;
            when "11" =>
                output <= signal_4;
            when others =>
                output <= (others => 'X');
        end case;
    end process process_case;
end architecture rtl;