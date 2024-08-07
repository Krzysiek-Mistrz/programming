#include <Arduino.h>
#define PIN6 6
#define PIN7 7
#define PIN8 8

void setup() {
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
  pinMode(PIN8, OUTPUT);
}

void loop() {
  analogWrite(PIN6, 100); //sterujemy predkoscia silnika przez ENABLE1
  digitalWrite(PIN7, HIGH); //silnik w lewo
  digitalWrite(PIN8, LOW);
  delay(300);
  analogWrite(PIN6, 255); //sterujemy predkoscia silnika przez ENABLE1
  digitalWrite(PIN7, LOW);  //silnik w prawo
  digitalWrite(PIN8, HIGH);
  delay(300);
}