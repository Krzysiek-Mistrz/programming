input.onButtonPressed(Button.A, function () {
    AlphaBot2.Run(Dir.forward, 30)
    basic.pause(1000)
    AlphaBot2.MotorRun(Motors.M1, -30)
    basic.pause(2000)
    AlphaBot2.Run(Dir.stop, 0)
})
basic.forever(function () {
	
})
