#!/bin/bash
raspistill -o test1.jpg
#wylanienie podgladu
raspistill -n -o test2.jpg
#zmiana opoznienia w ms robienia zdjecia
raspistill -n -o test3.jpg -t 100
#obro obrazu
raspistill -n -o test4.jpg -t 100 -rot 180
#odbicie obrazu
raspistill -n -o test.jpg -t 100 -hf -vf
#zmiana rozdzielczosci
raspistill -n -o test5.jpg -t 100 -w 640 -h 480
#zastapienie data
raspistill -n -o test%d.jpg -t 100 -dt