#include <Arduino.h>
#define PIN6 6
#define PIN7 7
#define PIN8 8

void setup() {
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
  pinMode(PIN8, OUTPUT);
  digitalWrite(PIN8, HIGH);
  digitalWrite(PIN7, LOW);
}

void loop() {
  //rozpedzanie
  for(int i = 0; i < 255; i++) {
    analogWrite(PIN6, i);
    delay(25);
  }
  //hamowanie
  for(int i = 255; i > 0; i--) {
    analogWrite(PIN6, i);
    delay(25);
  }
}