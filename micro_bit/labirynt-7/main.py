data: List[number] = []

def on_forever():
    # jezeli oba ir wykryja z przodu to krec sie w kolko
    if AlphaBot2.infrared(Sensor.LEFT) or AlphaBot2.infrared(Sensor.RIGHT):
        AlphaBot2.motor_run(Motors.M1, -30)
        AlphaBot2.motor_run(Motors.M2, 30)
    elif data[1] > 60:
        AlphaBot2.motor_run(Motors.M2, 30)
        AlphaBot2.motor_run(Motors.M1, 50)
    else:
        # jezeli wartosc czujnika left front > 20 (robot blizej sciany) to odbij w prawo zeby dalej sciany
        AlphaBot2.motor_run(Motors.M2, 50)
        AlphaBot2.motor_run(Motors.M1, 30)
basic.forever(on_forever)
