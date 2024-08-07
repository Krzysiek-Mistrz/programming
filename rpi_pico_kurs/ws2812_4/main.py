from neopixel import  Neopixel
import utime
import random
numpix = 8
strip = Neopixel(numpix, 0, 28, "RGB")
red = (255, 0, 0)
orange = (255, 50, 0)
yellow = (255, 100, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
indigo = (100, 0, 90)
violet = (200, 0, 100)
colors_rgb = [red, orange, yellow, green, blue, indigo, violet]
delay = 0.01
strip.brightness(42)
blank = (0, 0, 0)
while True:
    strip.show()
    for x in range(6):
        strip.set_pixel(x+1, red)
        strip.show()
        utime.sleep(delay)
        strip.set_pixel(x, red)
        strip.show()
        utime.sleep(delay)
        strip.set_pixel(x+2, red)
        strip.show()
        utime.sleep(delay)
        strip.set_pixel(x, blank)
        utime.sleep(delay)
        strip.set_pixel(x+1, blank)
        utime.sleep(delay)
        strip.set_pixel(x+2, blank)
        strip.show()