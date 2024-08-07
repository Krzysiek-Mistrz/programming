from RPi.GPIO import *
from time import *

setmode(BCM)
setup(18, OUT)
setup(21, IN, pull_up_down=PUD_UP)

try:
	while True:
		if input(21) == 0:
			output(18, HIGH)
		else:
			output(18, LOW)
except KeyboardInterrupt:
	print('Koniec')

cleanup()
