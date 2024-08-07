#include <Arduino.h>
#define PIN10 10

void zamigajDioda(int, int, int);

void setup() {
  pinMode(PIN10, OUTPUT);
  zamigajDioda(100, 500, 5);
}

void loop() {}

void zamigajDioda(int czasWlaczenia, int czasWylaczenia, int ilosc) {
  for(int i = 0; i < ilosc; i++) {
    digitalWrite(PIN10, HIGH);
    delay(czasWlaczenia);
    digitalWrite(PIN10, LOW);
    delay(czasWylaczenia);
  }
}