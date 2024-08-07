from machine import Pin
import utime

trigger = Pin(21, Pin.OUT)
echo = Pin(20, Pin.IN)

def ultra():
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(5)
    trigger.low()
    
    # Inicjalizacja zmiennych
    signaloff = 0
    signalon = 0
    
    while echo.value() == 0:
        signaloff = utime.ticks_us()
    while echo.value() == 1:
        signalon = utime.ticks_us()
    
    # Obliczenie odległości
    timepassed = signalon - signaloff
    distance = (timepassed * 0.0343) / 2
    distance = "{:.1f}".format(distance)
    print(distance + " cm")
    return str(distance)

while True:
    print(ultra())
    utime.sleep(5)