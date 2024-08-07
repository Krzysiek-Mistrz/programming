#include <Arduino.h>
#define TRIGPIN3 3
#define ECHOPIN4 4
#define BUZPIN5 5

float pomiarOdleglosci();
void odleglosc(float, float);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN3, OUTPUT);
  pinMode(ECHOPIN4, INPUT);
  pinMode(BUZPIN5, OUTPUT);
}

void loop() {
  odleglosc(4, 7);
  delay(500);
}

float pomiarOdleglosci() {
  digitalWrite(TRIGPIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN3, LOW);
  float odleglosc = pulseIn(ECHOPIN4, HIGH) / 58.0;
  return odleglosc;
}

void odleglosc(float odl1, float odl2) {
  float odleglosc = pomiarOdleglosci();
  if(odleglosc > odl1 && odleglosc < odl2) {
    digitalWrite(BUZPIN5, HIGH);
  }
  else {
    digitalWrite(BUZPIN5, LOW);
  }
}