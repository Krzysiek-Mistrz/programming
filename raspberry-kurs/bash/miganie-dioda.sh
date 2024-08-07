#!/bin/bash

# Numer pinu GPIO, który będzie migać
GPIO_PIN=12

# Ścieżka do katalogu sysfs GPIO
GPIO_PATH="/sys/class/gpio"

# Eksportowanie pinu GPIO
echo "$GPIO_PIN" > "$GPIO_PATH/export"

# Ustawianie pinu jako wyjście
echo "out" > "$GPIO_PATH/gpio$GPIO_PIN/direction"

# Funkcja do miganie diodą
blink_led() {
    echo 1 > "$GPIO_PATH/gpio$GPIO_PIN/value"
    sleep 1
    echo 0 > "$GPIO_PATH/gpio$GPIO_PIN/value"
    sleep 1
}

# Pętla nieskończona migotania diodą
while true; do
    blink_led
done

# Po zakończeniu programu, odinstaluj pin GPIO
echo "$GPIO_PIN" > "$GPIO_PATH/unexport"
