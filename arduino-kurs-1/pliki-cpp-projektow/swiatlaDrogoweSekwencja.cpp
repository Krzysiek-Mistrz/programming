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
  digitalWrite(LED8, HIGH);
  digitalWrite(LED9, LOW);
  digitalWrite(LED10, LOW);
  delay(1000);
  while(digitalRead(SWITCH7) == HIGH) {}

  digitalWrite(LED8, LOW);
  digitalWrite(LED9, HIGH);
  digitalWrite(LED10, LOW);
  delay(1000);
  while(digitalRead(SWITCH7) == HIGH) {}

  digitalWrite(LED8, LOW);
  digitalWrite(LED9, LOW);
  digitalWrite(LED10, HIGH);
  delay(1000);
  while(digitalRead(SWITCH7) == HIGH) {}
  
  delay(1000);
}