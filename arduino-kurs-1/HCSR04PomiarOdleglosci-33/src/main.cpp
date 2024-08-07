#include <Arduino.h>
#define TRIGPIN3 3
#define ECHOPIN4 4

float pomiarOdleglosci();

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN3, OUTPUT);
  pinMode(ECHOPIN4, INPUT);
}

void loop() {
  Serial.print("ODLEGLOSC: ");
  Serial.print(pomiarOdleglosci());
  Serial.println();
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