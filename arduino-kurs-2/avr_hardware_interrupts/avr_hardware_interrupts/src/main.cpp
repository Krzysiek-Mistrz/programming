#include <Arduino.h>

volatile bool ledState = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(2), toggleLED, FALLING);
}

void loop() {}

void toggleLED() {
  ledState = !ledState;
  digitalWrite(13, ledState);
}
