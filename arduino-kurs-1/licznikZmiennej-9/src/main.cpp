#include <Arduino.h>
//byte licznik = 0;
int licznik = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //int licznik = 0;
  Serial.println(licznik);
  licznik += 1;
  delay(100);
}