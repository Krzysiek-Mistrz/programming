#include <Arduino.h>

#define DIODA1_PIN 2
#define DIODA2_PIN 3
#define PIR_PIN 5

unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(DIODA1_PIN, OUTPUT);
  pinMode(DIODA2_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  aktualnyCzas = millis();
  if (digitalRead(PIR_PIN) == 1) {
    digitalWrite(DIODA1_PIN, 1);
    digitalWrite(DIODA2_PIN, 1);
    zapamietanyCzas1 = aktualnyCzas;
  }
  if (aktualnyCzas - zapamietanyCzas1 >= 10000) {
    digitalWrite(DIODA1_PIN, 0);
    digitalWrite(DIODA2_PIN, 0);
  }
}