def on_button_pressed_a():
    for index in range(4):
        AlphaBot2.run(Dir.FORWARD, 30)
        basic.pause(1000)
        AlphaBot2.motor_run(Motors.M1, -30)
        basic.pause(800)
    AlphaBot2.run(Dir.STOP, 0)
input.on_button_pressed(Button.A, on_button_pressed_a)

def on_forever():
    pass
basic.forever(on_forever)
