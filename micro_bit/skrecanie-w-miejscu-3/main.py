AlphaBot2.run(Dir.STOP, 0)
basic.show_arrow(ArrowNames.WEST)

def on_forever():
    basic.show_icon(IconNames.YES)
    while True:
        if AlphaBot2.ultrasonic() > 10:
            AlphaBot2.run(Dir.FORWARD, 40)
        else:
            AlphaBot2.motor_run(Motors.M1, -40)
            basic.pause(500)
basic.forever(on_forever)
