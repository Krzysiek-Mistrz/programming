from machine import Pin
from utime import sleep_ms

class LCD:
    def __init__(self, rs, en, d4, d5, d6, d7):
        self.rs = rs
        self.en = en
        self.data_pins = [d4, d5, d6, d7]
        
        self.rs.init(Pin.OUT)
        self.en.init(Pin.OUT)
        for pin in self.data_pins:
            pin.init(Pin.OUT)
        
        self.init_lcd()

    def pulse_enable(self):
        self.en.value(0)
        sleep_ms(1)
        self.en.value(1)
        sleep_ms(1)
        self.en.value(0)
        sleep_ms(1)

    def send(self, data, rs_value):
        self.rs.value(rs_value)
        for i in range(4):
            self.data_pins[i].value((data >> (i + 4)) & 0x01)
        self.pulse_enable()
        for i in range(4):
            self.data_pins[i].value((data >> i) & 0x01)
        self.pulse_enable()

    def command(self, cmd):
        self.send(cmd, 0)

    def write_char(self, char):
        self.send(ord(char), 1)

    def init_lcd(self):
        sleep_ms(50)
        self.command(0x33)
        self.command(0x32)
        self.command(0x28)
        self.command(0x0C)
        self.command(0x06)
        self.command(0x01)
        sleep_ms(200)

    def clear(self):
        self.command(0x01)
        sleep_ms(2)

    def set_cursor(self, col, row):
        positions = [0x80, 0xC0]
        self.command(positions[row] + col)

    def print(self, message):
        for char in message:
            self.write_char(char)