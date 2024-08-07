import w1thermsensor
sensor = w1thermsensor.W1ThermSensor()
temp = sensor.get_temperature()
print(temp)
