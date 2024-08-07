import time
import RPi.GPIO as GPIO
import w1thermsensor

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(21, GPIO.OUT)
GPIO.output(21, GPIO.HIGH)
temperaturaMax = 30.0
sensor = w1thermsensor.W1ThermSensor()

try:
    while True:
        temperatura = sensor.get_temperature()
        print(temperatura)
        if temperatura > temperaturaMax:
            GPIO.output(21, GPIO.LOW)
            print("Alarm!")
        else:
            GPIO.output(21, GPIO.HIGH)
        time.sleep(1)

except KeyboardInterrupt:
    GPIO.output(21, GPIO.HIGH)
    print('Koniec')
    GPIO.cleanup()
