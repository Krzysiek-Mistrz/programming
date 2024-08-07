from machine import Pin
import utime

segments = (8, 9, 7, 6, 5, 4, 3, 2)

patterns = [
    (0, 0, 0, 0, 0, 0, 1, 1),
    (1, 0, 0, 1, 1, 1, 1, 1),
    (0, 0, 1, 0, 0, 1, 0, 1),
    (0, 0, 0, 0, 1, 1, 0, 1),
    (0, 1, 0, 0, 1, 0, 0, 1),
    (0, 1, 0, 0, 0, 0, 0, 1),
    (0, 0, 0, 1, 1, 1, 1, 1),
    (0, 0, 0, 0, 0, 0, 0, 1),
    (0, 0, 0, 1, 1, 0, 0, 1)
]

pins = [Pin(seg, Pin.OUT) for seg in segments]
display = Pin(16, Pin.OUT, value = 1)

def display_digit(digit):
    #pattern = patterns[digit]
    for i in range(8):
        pins[i].value(1)
    display.value(0)
while True:
    for i in range(10):
        start = utime.ticks_ms()
        while utime.ticks_diff(utime.ticks_ms, start) < 1000:
            display_digit(i)