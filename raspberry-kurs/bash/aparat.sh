#!/bin/bash

#konfiguracja pinow
gpio -g mode 21 out
gpio -g mode 12 pwm
gpio -g mode 26 up

#wlaczenie didy i poczekania na przycisk
gpio -g pwm 12 800
gpio -g wfi 26 falling

#zgaszenie diody i uruchomienie buzzera
gpio -g pwm 12 0
gpio -g write 21 0

raspistill -t 200 -n -o 'zdjecie-%d.jpg' -dt

#wyciszenie buzzera
gpio -g write 21 1
