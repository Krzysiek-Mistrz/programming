from machine import Pin
import time

In1 = Pin(6, Pin.OUT)
In2 = Pin(7, Pin.OUT)
EN_A = Pin(8, Pin.OUT)
In3 = Pin(4, Pin.OUT)
In4 = Pin(3, Pin.OUT)
EN_B = Pin(2, Pin.OUT)
EN_A.high()
EN_B.high()

def move_forward():
    In1.high()
    In2.low()
    In3.high()
    In4.low()

while True:
    move_forward()
    print("forward")
    time.sleep(1)