input.onButtonPressed(Button.A, function () {
    basic.showIcon(IconNames.Yes)
    while (true) {
        if (AlphaBot2.Ultrasonic() > 10) {
            AlphaBot2.Run(Dir.forward, 40)
        } else {
            AlphaBot2.MotorRun(Motors.M1, -40)
            basic.pause(500)
        }
    }
})
AlphaBot2.Run(Dir.stop, 0)
basic.showArrow(ArrowNames.West)
