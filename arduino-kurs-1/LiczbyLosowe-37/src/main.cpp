#include <Arduino.h>
#define ADC0 A0
#define SW7 7
int wartoscLosowa = 0;

void setup() {
  pinMode(SW7, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(ADC0));
}

void loop() {
  if(digitalRead(SW7) == LOW) {
    wartoscLosowa = random(1, 6);
    Serial.println(wartoscLosowa);
  }
  delay(1000);
}

/*
//poprzedni program
#include <Arduino.h>
#define ADC0 A0
int wartoscLosowa = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(ADC0));
}

void loop() {
  wartoscLosowa = random(300);
  Serial.println(wartoscLosowa);
  delay(1000);
}
*/