#include <Arduino.h>
#define ADC A0
int odczytanaWartosc = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  odczytanaWartosc = analogRead(ADC);
  Serial.println(odczytanaWartosc);
  delay(500);
}