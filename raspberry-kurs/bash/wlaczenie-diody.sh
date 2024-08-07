#!/bin/bash
gpio -g mode 21 out
#zalaczenie diody
gpio -g write 21 1
