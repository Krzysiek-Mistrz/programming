#include <Arduino.h>
#define LED8 8
#define SWITCH7 7

void setup() {
  pinMode(LED8, OUTPUT);
  pinMode(SWITCH7, INPUT_PULLUP);
}

void loop() {
  //tak dlugo jak mamy przycisk wcisniety
  while(digitalRead(SWITCH7) == LOW) {
    digitalWrite(LED8, HIGH);
    delay(500);
    digitalWrite(LED8, LOW);
    delay(500);
  }
}