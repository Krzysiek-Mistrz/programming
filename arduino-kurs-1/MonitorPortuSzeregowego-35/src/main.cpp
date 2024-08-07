#include <Arduino.h>
#define ADC0 A0
int odczytanaWartosc = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  odczytanaWartosc = analogRead(ADC0);
  Serial.println(odczytanaWartosc);
  delay(200);
}