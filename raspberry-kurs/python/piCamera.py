from picamera import PiCamera
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(0)
GPIO.setup(12, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)

dioda = GPIO.PWM(12, 50)
dioda.start(0)
GPIO.output(21, GPIO.HIGH)

kamera = PiCamera()
kamera.rotation = 180

dioda.ChangeDutyCycle(80)
GPIO.wait_for_edge(26, GPIO.FALLING)

dioda.ChangeDutyCycle(0)
GPIO.output(21, GPIO.LOW)

time.sleep(5)

kamera.capture('~/Documents/kurs-raspberry/zdj.jpg')

GPIO.output(21, GPIO.HIGH)
