entity hello_world_1 is
end entity;

architecture sim of hello_world_1 is
begin
    process is
    begin
        report "hello world";
        wait;
    end process;
end architecture;