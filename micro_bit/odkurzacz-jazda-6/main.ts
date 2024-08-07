function rotate90Left () {
    AlphaBot2.Run(Dir.turnLeft, 40)
    basic.pause(200)
}
input.onButtonPressed(Button.A, function () {
    basic.clearScreen()
    i = 0
    while (true) {
        if (AlphaBot2.Ultrasonic() > 10) {
            AlphaBot2.Run(Dir.forward, 40)
        } else {
            rotate90Left()
        }
    }
})
function rotate90Right () {
    AlphaBot2.Run(Dir.turnRight, 40)
    basic.pause(200)
}
let i = 0
basic.showArrow(ArrowNames.West)
