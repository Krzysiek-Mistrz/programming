input.onButtonPressed(Button.A, function on_button_pressed_a() {
    
    left = 0
    let right = 0
    let i = 0
    basic.clearScreen()
    while (true) {
        if (AlphaBot2.Infrared(Sensor.Right)) {
            AlphaBot2.Run(Dir.turnLeft, 40)
            basic.pause(randint(250, 500))
        } else if (AlphaBot2.Infrared(Sensor.Left)) {
            AlphaBot2.Run(Dir.turnRight, 40)
            basic.pause(randint(250, 500))
        } else {
            if (i > 1000) {
                left = randint(35, 45)
                right = randint(35, 45)
                i = 0
            }
            
            i += 1
            AlphaBot2.MotorRun(Motors.M1, left)
            basic.pause(20)
            AlphaBot2.MotorRun(Motors.M2, right)
        }
        
    }
})
let left = 0
AlphaBot2.Run(Dir.stop, 0)
basic.showArrow(ArrowNames.West)
