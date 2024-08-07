#!/bin/bash
gpio -g mode 12 pwm
#zalaczenie diody
gpio -g pwm 12 0
gpio -g pwm 12 1024