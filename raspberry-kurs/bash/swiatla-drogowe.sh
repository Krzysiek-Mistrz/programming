#!/bin/bash

gpioPin16=16
gpioPin20=20
gpioPin21=21
gpioPath="/sys/class/gpio"

echo "$gpioPin16" > "$gpioPath/export"
echo "$gpioPin20" > "$gpioPath/export"
echo "$gpioPin21" > "$gpioPath/export"
echo "out" > "$gpioPath/gpio$gpioPin16/direction"
echo "out" > "$gpioPath/gpio$gpioPin20/direction"
echo "out" > "$gpioPath/gpio$gpioPin21/direction"

blinkLed() {
   echo 1 > "$gpioPath/gpio$gpioPin16/value"
   echo 0 > "$gpioPath/gpio$gpioPin20/value"
   echo 0 > "$gpioPath/gpio$gpioPin21/value"
   sleep 1
   echo 0 > "$gpioPath/gpio$gpioPin16/value"
   echo 1 > "$gpioPath/gpio$gpioPin20/value"
   echo 0 > "$gpioPath/gpio$gpioPin21/value"
   sleep 1
   echo 0 > "$gpioPath/gpio$gpioPin16/value"
   echo 0 > "$gpioPath/gpio$gpioPin20/value"
   echo 1 > "$gpioPath/gpio$gpioPin21/value"
   sleep 1
}

while true; do
   blinkLed
done
