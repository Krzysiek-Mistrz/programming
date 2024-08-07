#include <Arduino.h>
#define PIN4 4
#define PIN5 5
#define TRIG2 2
#define ECHO3 3

float zmierzOdleglosc();

void setup() {
  pinMode(PIN4, INPUT_PULLUP);
  pinMode(PIN5, OUTPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO3, INPUT);
}

void loop() {
  float pomiarHC = zmierzOdleglosc();
  if((pomiarHC > 2 && pomiarHC < 5) || digitalRead(PIN4) == LOW) {
    digitalWrite(PIN5, HIGH);
    delay(100);
  } else {
    digitalWrite(PIN5, LOW);
    delay(100);
  }
}

float zmierzOdleglosc() {
  float pomiar;
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  pomiar = pulseIn(ECHO3, HIGH) / 58.0;
  return pomiar;
}

/*
#include <Arduino.h>
#define ADC0 A0

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(ADC0));
}

void loop() {
  int losowaWartosc = random(100);
  if(losowaWartosc < 10 || losowaWartosc > 90) {
    Serial.print(losowaWartosc);
    Serial.print(" SPELNIA WARUNEK");
  }
}
*/