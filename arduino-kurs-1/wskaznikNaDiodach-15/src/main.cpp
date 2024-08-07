#include <Arduino.h>
#define LED2 2
#define LED3 3
#define LED4 4
#define ADC0 A0
int wartoscAnalogowa = 0;

void setup() {
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  wartoscAnalogowa = analogRead(ADC0);
  wartoscAnalogowa = map(wartoscAnalogowa, 0, 1023, 0, 5);
  if(wartoscAnalogowa == 0) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(wartoscAnalogowa == 1) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
  if(wartoscAnalogowa == 2) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  }
  if(wartoscAnalogowa == 4) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
  if(wartoscAnalogowa == 5) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
}