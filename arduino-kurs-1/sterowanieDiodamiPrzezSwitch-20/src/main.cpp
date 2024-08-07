#include <Arduino.h>
#define LED2 2
#define LED3 3
char odebraneDane;

void setup() {
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    odebraneDane = Serial.read();
    switch(odebraneDane)
    {
      case 'c':
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        delay(50);
      break;
      
      case 'z':
        digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
        delay(50);
      break;

      default:
        delay(50);
      break;
    }
  }
  delay(50);
}