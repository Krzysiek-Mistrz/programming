#include <Arduino.h>

void zamigajWybrana(int, int, int);

void setup() {
  zamigajWybrana(500, 20, 2);
}

void loop() {}

void zamigajWybrana(int czas, int ile, int pin) {
  pinMode(pin, OUTPUT);
  for(int i = 0; i < ile; i++) {
    digitalWrite(pin, HIGH);
    delay(czas);
    digitalWrite(pin, LOW);
    delay(czas);
  }
}