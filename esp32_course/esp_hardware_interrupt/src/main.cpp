#include <Arduino.h>

volatile bool ledState = false;

void IRAM_ATTR handleInterrupt() {
  ledState = !ledState;
  digitalWrite(2, ledState);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(13), handleInterrupt, FALLING);
}

void loop() {}
