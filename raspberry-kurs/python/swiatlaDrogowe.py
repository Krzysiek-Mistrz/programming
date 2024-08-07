from RPi.GPIO import *
from time import *

setmode(BCM)
setwarnings(0)
setup(21, OUT)
setup(16, OUT)
setup(20, OUT)

while True:
	output(21, 1)
	output(20, 0)
	output(16, 0)
	sleep(1)
	output(21, 0)
	output(20, 1)
	output(16, 0)
	sleep(1)
	output(21, 0)
	output(20, 0)
	output(16, 1)
	sleep(1)
