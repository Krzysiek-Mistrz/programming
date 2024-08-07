from RPi.GPIO import *
from time import *

setmode(BCM)
setwarnings(0)
setup(21, OUT)

while True:
	output(21, 1)
	sleep(1)
	output(21, 0)
	sleep(1)
