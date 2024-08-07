#!/bin/bash
#zczytanie pinow: gpio readall

#sterowanie buzzerem
gpio -g mode 12 out
#wylaczenie
gpio -g write 12 1
#zalaczenie
gpio -g write 12 0