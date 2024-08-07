input.onButtonPressed(Button.A, function () {
    for (let index = 0; index < 4; index++) {
        AlphaBot2.Run(Dir.forward, 30)
        basic.pause(1000)
        AlphaBot2.MotorRun(Motors.M1, -30)
        basic.pause(800)
    }
    AlphaBot2.Run(Dir.stop, 0)
})
basic.forever(function () {
	
})
