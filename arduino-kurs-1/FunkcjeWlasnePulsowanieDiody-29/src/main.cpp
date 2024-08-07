#include <Arduino.h>
#define PIN10 10

void zamigajLed();

void setup() {
  pinMode(PIN10, OUTPUT);
}

void loop() {
  zamigajLed();
}

void zamigajLed() {
  for(int i = 0; i < 255; i++) {
    analogWrite(PIN10, i);
    delay(50);
  }
  delay(25);
  for(int i = 255; i > 0; i--) {
    analogWrite(PIN10, i);
    delay(50);
  }
  delay(25);
}