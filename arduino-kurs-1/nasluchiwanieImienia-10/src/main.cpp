#include <Arduino.h>
String imie = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    delay(100);
    imie = Serial.readStringUntil('\n');
    delay(100);
    Serial.println("Witaj " + imie +"!");
  }
}