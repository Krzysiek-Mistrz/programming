#include <Arduino.h>
#define LED8 8
#define SWITCH7 7

void setup() {
  pinMode(LED8, OUTPUT);
  pinMode(SWITCH7, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SWITCH7) == LOW) {
    digitalWrite(LED8, HIGH);
    //opoznienie diody
    delay(5000);
  }
  else {
    digitalWrite(LED8, LOW);
  }
}