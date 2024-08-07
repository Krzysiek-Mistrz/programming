#!/bin/bash
#nagranie filmu o dlugosci 100ms
raspivid -n -w 1920 -h 1080 -cd MJPEG -o test.mpg -t 100
#nagranie filmu w kodeku h264
raspivid -n -w 649 -h 480 -o test2.h264
#film w zwolnionym tempie
raspivid -n -w 640 -h 480 -o test.h264 -fps 90

#utworzenie filmu poklatowego trwajacego 300000ms interwal co ile robimy = 2000ms po ustawieniu w dobrym katalogu
raspistill -t 300000 -tl 2000 -o image%04.jpg -w 1280 -h 720 -rot 180

#wygenerowanie filmu z zdjec klatkowych 10zdj/1s w tle
avconv -i image%04.jpg -r 10 -vcodec libx264 -vf scale=1280:720 timelapse.mp4 &
