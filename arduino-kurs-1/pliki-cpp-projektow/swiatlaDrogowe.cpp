#include <Arduino.h>
#define LED8 8
#define LED9 9
#define LED10 10
#define SWITCH7 7

void setup() {
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(SWITCH7, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SWITCH7) == LOW) {
    digitalWrite(LED8, HIGH);
    delay(500);
    digitalWrite(LED8, LOW);
    digitalWrite(LED9, HIGH);
    delay(500);
    digitalWrite(LED9, LOW);
    digitalWrite(LED10, HIGH);
    delay(500);
    digitalWrite(LED10, LOW);
    delay(500);
  }
}