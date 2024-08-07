from  machine import Pin
import utime

matrix_keys = [['1', '2', '3', 'A'],
               ['4', '5', '6', 'B'],
               ['7', '8', '9', 'C'],
               ['*', '0', '#', 'D']]

guess = []
secret_pin = ['1', '2', '3', '4', '5', '6']
led = Pin("LED", Pin.OUT, Pin.PULL_UP)

#numery pinow do rows
keypad_rows = [9, 8, 7, 6]
#numery pinow do cols
keypad_columns = [5, 4, 3, 2]

col_pins = []
row_pins = []

for x in range(0, 4):
    row_pins.append(Pin(keypad_rows[x], Pin.OUT))
    row_pins[x].value(1)
    col_pins.append(Pin(keypad_columns[x], Pin.IN, Pin.PULL_DOWN))
    col_pins[x].value(0)

print("PLEASE ENTER SECRET PIN: ")

def checkPin(guess):
    if guess == secret_pin:
        print("YOU GOT THE SECRET PIN CORRECT")
        led.value(1)
        utime.sleep(3)
        led.value(0)
    else:
        print("BETTER LUCK NEXT TIME")

def scankeys():
    for row in range(0, 4):
        for col in range(4):
            row_pins[row].high()
            key = None
            if col_pins[col].value() == 1:
                print("YOU HAVE PRESSED: ", matrix_keys[row][col])
                key_press = matrix_keys[row][col]
                utime.sleep(0.3)
                guess.append(key_press)
            if len(guess) == 6:
                checkPin(guess)
                for x in range(0, 6):
                    guess.pop()
        row_pins[row].low()

while True:
    scankeys()