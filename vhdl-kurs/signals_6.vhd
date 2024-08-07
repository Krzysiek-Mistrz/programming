entity signals_6 is
end entity;

architecture sim of signals_6 is
    signal my_signal : integer := 0;
begin
    process is
        variable my_variable : integer := 0;
    begin
        report "my variable = " & integer'image(my_variable) & "; my signal = " & integer'image(my_signal);
        my_variable := my_variable + 1;
        my_signal <= my_signal + 1;
        wait for 10 ns;
    end process;
end architecture;