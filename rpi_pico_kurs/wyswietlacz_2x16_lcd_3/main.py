from machine import Pin, ADC
from utime import sleep

# Ustawienia LCD
import lcd1602

rs = Pin(0, Pin.OUT)
en = Pin(1, Pin.OUT)
d4 = Pin(2, Pin.OUT)
d5 = Pin(3, Pin.OUT)
d6 = Pin(4, Pin.OUT)
d7 = Pin(5, Pin.OUT)

lcd = lcd1602.LCD(rs, en, d4, d5, d6, d7)

def read_temp():
    sensor_temp = ADC(4)
    conversion_factor = 3.3 / (65535)
    reading = sensor_temp.read_u16() * conversion_factor 
    temperature = 27 - (reading - 0.706)/0.001721
    formatted_temperature = "{:.2f}".format(temperature)
    string_temperature = str("Temp:" + formatted_temperature)
    print(string_temperature)
    sleep(2)
    return string_temperature

while True:
    temperature = read_temp()
        
    lcd.clear()
    lcd.set_cursor(0, 0)
    lcd.print("Temp: {}C".format(temperature))
        
    sleep(2)
