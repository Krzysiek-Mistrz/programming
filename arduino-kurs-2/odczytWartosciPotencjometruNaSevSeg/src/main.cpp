#include <SevSeg.h>
#include <Arduino.h>
#define PINPOTEN A0

SevSeg sevseg;
int potencjometr;

void setup() {
  byte ileWyswietlaczy = 2;
  byte pinyTranzystorow[] = {10, 9};
  byte pinySegmentow[] = {7, 5, 2, 4, 3, 8, 6};
  bool czyPodlaczoneRez = true;
  byte rodzajTranzystorow = N_TRANSISTORS;
  sevseg.begin(rodzajTranzystorow, ileWyswietlaczy, pinyTranzystorow, pinySegmentow, czyPodlaczoneRez);
}

void loop() {
  potencjometr = analogRead(PINPOTEN);
  potencjometr = map(potencjometr, 0, 1024, 0, 99);
  sevseg.setNumber(potencjometr, 2);
  sevseg.refreshDisplay();
}