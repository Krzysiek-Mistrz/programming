#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Witaj!");
}

void loop() {
  delay(1000);
  Serial.println("===Minely 2 sekundy===");
}