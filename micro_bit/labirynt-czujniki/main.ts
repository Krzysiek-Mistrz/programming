let data: number[] = []
basic.forever(function () {
    data = AlphaBot2.AnalogRead()
    basic.clearScreen()
    for (let i = 0; i <= 5 - 1; i++) {
        for (let j = 0; j <= data[i] / 20 - 1; j++) {
            led.plot(i, j)
        }
    }
    basic.pause(10)
})
