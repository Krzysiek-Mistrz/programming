from RPi.GPIO import *
from time import *

setmode(BCM)
setup(18, OUT)
setup(12, OUT)
setwarnings(0)

dioda1 = PWM(18, 50)
wypelnienie1 = 0
dioda1.start(wypelnienie1)

dioda2 = PWM(12, 50)
wypelnienie2 = 0
dioda2.start(wypelnienie2)

try:
	while True:
		wypelnienie1 += 5
		if wypelnienie1 > 100:
			wypelnienie1 = 0
		dioda1.ChangeDutyCycle(wypelnienie1)
		
		wypelnienie2 += 2
		if wypelnienie2 > 100:
			wypelnienie2 = 0
		dioda2.ChangeDutyCycle(wypelnienie2)
		
		sleep(0.05)

except KeyboardInterrupt:
	print('Koniec')

dioda1.stop()
dioda2.stop()
cleanup()
