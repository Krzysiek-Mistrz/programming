#include <Arduino.h>
#define LED8 8

void setup() {
  pinMode(LED8, OUTPUT);
}

void loop() {
  digitalWrite(LED8, HIGH);
  delay(500);
  digitalWrite(LED8, LOW);
  delay(500);
}