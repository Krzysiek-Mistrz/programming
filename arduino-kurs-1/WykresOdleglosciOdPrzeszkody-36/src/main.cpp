#include <Arduino.h>
#define TRIGPIN2 2
#define ECHOPIN3 3
int pomiar = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN2, OUTPUT);
  pinMode(ECHOPIN3, INPUT);
}

/*
void loop() {
  digitalWrite(TRIGPIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN2, LOW);
  pomiar = pulseIn(ECHOPIN3, HIGH) / 58.0;
  if(pomiar > 400) {
    pomiar = 400;
  }
  Serial.println(pomiar);
  delay(100);
  //wykres pojedynczy
}
*/

void loop() {
  digitalWrite(TRIGPIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN2, LOW);
  pomiar = pulseIn(ECHOPIN3, HIGH) / 58.0;
  if(pomiar > 400) {
    pomiar = 400;
  }
  Serial.print("\t"); // Znak tabulatora
  Serial.print(pomiar + 200);
  Serial.print("\t"); // Znak tabulatora
  Serial.print(pomiar + 100);
  Serial.print("\t"); // Znak tabulatora
  Serial.print(pomiar);
  delay(100);
  //wykres wielokrotny
}