#include <Arduino.h>
int wartoscAnalogowa = 0;
#define ADC0 A0
#define LED2 2

void setup() {
  pinMode(LED2, OUTPUT);
}

void loop() {
  wartoscAnalogowa = analogRead(ADC0);
  digitalWrite(LED2, HIGH);
  delay(wartoscAnalogowa);
  digitalWrite(LED2, LOW);
  delay(wartoscAnalogowa);
}