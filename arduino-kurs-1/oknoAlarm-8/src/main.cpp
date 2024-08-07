#include <Arduino.h>
#define LED10 10
#define LED11 11
#define SWITCH12 12

void setup() {
  Serial.begin(9600);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(SWITCH12, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SWITCH12) == LOW) {
    digitalWrite(LED10, HIGH);
    digitalWrite(LED11, LOW);
  }
  else {
    digitalWrite(LED11, HIGH);
    digitalWrite(LED10, LOW);
    Serial.println("===!ALARM!===");
  }
  while(digitalRead(SWITCH12) == HIGH) {
    delay(25);
  }
}
