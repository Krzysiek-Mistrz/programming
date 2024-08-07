library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity case_when_14 is
end entity case_when_14;

architecture sim of case_when_14 is
    --inputs of multiplexer
    signal signal_1 : unsigned(7 downto 0) := x"AA";
    signal signal_2 : unsigned(7 downto 0) := x"BB";
    signal signal_3 : unsigned(7 downto 0) := x"CC";
    signal signal_4 : unsigned(7 downto 0) := x"DD";
    --selector signal of multiplexer
    signal selector : unsigned(1 downto 0) := (others => '0');
    --output signal
    signal output_1 : unsigned(7 downto 0);
    signal output_2 : unsigned(7 downto 0);
begin
    --stimuli for the selector
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
    --MUX using if-then-else st
    process_if : process(selector) is
    begin
        if selector = "00" then
            output_1 <= signal_1;
        elsif selector = "01" then
            output_1 <= signal_2;
        elsif selector = "10" then
            output_1 <= signal_3;
        elsif selector = "11" then
            output_1 <= signal_4;
        else
            output_1 <= (others => 'X');
        end if;
    end process process_if;
    --MUX using case statement
    process_case : process(selector) is
    begin
        case selector is
            when "00" =>
                output_2 <= signal_1;
            when "01" =>
                output_2 <= signal_2;
            when "10" =>
                output_2 <= signal_3;
            when "11" =>
                output_2 <= signal_4;
            when others =>
                output_2 <= (others => 'X');
        end case;
    end process process_case;
end architecture sim;