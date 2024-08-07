def on_button_pressed_a():
    global left
    left = 0
    right = 0
    i = 0

    basic.clear_screen()
    while True:
        if AlphaBot2.infrared(Sensor.RIGHT):
            AlphaBot2.run(Dir.TURN_LEFT, 40)
            basic.pause(randint(250, 500))
        elif AlphaBot2.infrared(Sensor.LEFT):
            AlphaBot2.run(Dir.TURN_RIGHT, 40)
            basic.pause(randint(250, 500))
        else:
            if i > 1000:
                left = randint(35 ,45)
                right = randint(35, 45)
                i = 0
            i += 1    
            AlphaBot2.motor_run(Motors.M1, left)
            basic.pause(20)
            AlphaBot2.motor_run(Motors.M2, right)
input.on_button_pressed(Button.A, on_button_pressed_a)

left = 0
AlphaBot2.run(Dir.STOP, 0)
basic.show_arrow(ArrowNames.WEST)