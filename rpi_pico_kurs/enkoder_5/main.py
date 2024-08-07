from machine import Pin
import utime

dt_pin = Pin(1, Pin.IN, Pin.PULL_UP)
clk_pin = Pin(0, Pin.IN, Pin.PULL_UP)
sw = Pin(2, Pin.IN, Pin.PULL_UP)

led = [3, 4, 5]
led_pins = []

value = 0
previous_value = 1

for x in range(0, 3):
    led_pins.append(Pin(led[x], Pin.OUT))

def rotary_changed():
    global previous_value
    global value
    if previous_value != clk_pin.value():
        if clk_pin.value() == 0:
            if dt_pin.value() == 0:
                value = (value - 1) % 3
                print("anti clockwise", value)
            else:
                value = (value + 1) % 3
                print("clockwise", value)
        previous_value = clk_pin.value()

    if sw.value() == 0:
        print("button pressed")
        utime.sleep(1)

while True:
    for i in range(0, 3):
        led_pins[i].value(0)
        rotary_changed()
        led_pins[value].value(1)
        utime.sleep(0.001)