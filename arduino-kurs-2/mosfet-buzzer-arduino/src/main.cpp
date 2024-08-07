#include <Arduino.h>

void setup() {
  pinMode(A5, OUTPUT);
}

void loop() {
  tone(A5, 3300);
  delay(150);
  tone(A5, 2500);
  delay(150);
}