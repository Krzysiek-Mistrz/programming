from time import *
from RPi.GPIO import *

setmode(BCM)
setwarnings(0)
setup(18, OUT)
setup(21, IN, pull_up_down=PUD_UP)

output(18, LOW)
wait_for_edge(21, FALLING)
output(18, HIGH)
sleep(2)
output(18, LOW)

cleanup()
