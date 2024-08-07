input.onButtonPressed(Button.A, function () {
    if (counter < 9) {
        counter += 1
    }
})
input.onButtonPressed(Button.B, function () {
    if (counter > 0) {
        counter += -1
    }
})
let counter = 0
counter = 0
basic.forever(function () {
    basic.showNumber(counter)
})
