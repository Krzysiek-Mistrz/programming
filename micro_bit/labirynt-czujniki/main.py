data: List[number] = []

def on_forever():
    global data
    data = AlphaBot2.analog_read()
    basic.clear_screen()
    i = 0
    while i <= 5 - 1:
        j = 0
        while j <= data[i] / 20 - 1:
            led.plot(i, j)
            j += 1
        i += 1
    basic.pause(10)
basic.forever(on_forever)
