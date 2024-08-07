#include <Arduino.h>

unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  aktualnyCzas = millis();
  if ((aktualnyCzas - zapamietanyCzas) >= 1000UL) {
    zapamietanyCzas = aktualnyCzas;
    Serial.println(aktualnyCzas);
  }
}