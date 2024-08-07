#include <Arduino.h>
#define LEDR 9
#define LEDG 10
#define LEDB 11
#define PIR 2

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop() {
  if (digitalRead(PIR) == LOW) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
  }
  else {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
  }
}