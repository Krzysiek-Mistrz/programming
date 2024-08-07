entity loop_3 is
end entity;

architecture sim of loop_3 is
begin
    process is
    begin
        report "hello!";
        loop
            report "kabuum!";
            wait for 10 ns;
            --wychodzi z petli
            exit;
        end loop;
        report "goodbye!";
        wait;
    end process;
end architecture;