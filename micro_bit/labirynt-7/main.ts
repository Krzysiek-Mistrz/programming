let data : number[] = []
basic.forever(function on_forever() {
    //  jezeli oba ir wykryja z przodu to krec sie w kolko
    if (AlphaBot2.Infrared(Sensor.Left) || AlphaBot2.Infrared(Sensor.Right)) {
        AlphaBot2.MotorRun(Motors.M1, -30)
        AlphaBot2.MotorRun(Motors.M2, 30)
    } else if (data[1] > 60) {
        AlphaBot2.MotorRun(Motors.M2, 30)
        AlphaBot2.MotorRun(Motors.M1, 50)
    } else {
        //  jezeli wartosc czujnika left front > 20 (robot blizej sciany) to odbij w prawo zeby dalej sciany
        AlphaBot2.MotorRun(Motors.M2, 50)
        AlphaBot2.MotorRun(Motors.M1, 30)
    }
    
})
