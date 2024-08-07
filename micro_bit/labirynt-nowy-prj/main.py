def on_button_pressed_b():
    basic.show_icon(IconNames.EIGTH_NOTE)
    data: List[number] = []
    error = 0
    while True:
        data = AlphaBot2.analog_read()
        error = data[0] - 20
        if AlphaBot2.infrared(Sensor.LEFT) or AlphaBot2.infrared(Sensor.RIGHT):
            AlphaBot2.motor_run(Motors.M1, 20)
            AlphaBot2.motor_run(Motors.M2, -20)
            pause(100)
            continue
        if error > 0:
            AlphaBot2.motor_run(Motors.M1, 20)
            AlphaBot2.motor_run(Motors.M2, max(20 - error, 0))
        else:
            AlphaBot2.motor_run(Motors.M1, max(20 + error, 0))
            AlphaBot2.motor_run(Motors.M2, 20)
        basic.pause(10)
input.on_button_pressed(Button.B, on_button_pressed_b)
AlphaBot2.run(Dir.STOP, 0)
basic.show_arrow(ArrowNames.EAST)