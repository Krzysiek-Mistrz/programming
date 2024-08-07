#include <Arduino.h>
#define PIN8 8
#define PIN9 9
String odebraneDane = "";
bool led8 = 0;
bool led9 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN8, OUTPUT);
  pinMode(PIN9, OUTPUT);
}

/*
void loop() {
  if(Serial.available() > 0) {
    odebraneDane = Serial.readStringUntil('\n');
    if(odebraneDane == "zielona") {
      digitalWrite(PIN8, HIGH);
      delay(1000);
      digitalWrite(PIN8, LOW);
    }
    else if(odebraneDane == "czerwona") {
      digitalWrite(PIN9, HIGH);
      delay(1000);
      digitalWrite(PIN9, LOW);
    }
    else {
      Serial.println("===PODALES NIEPOPRAWNY KOLOR===");
    }
  }
}
*/

void loop() {
  if(Serial.available() > 0) {
    odebraneDane = Serial.readStringUntil('\n');
    if(odebraneDane == "zielona") {
      if(led8 == 0) {
        digitalWrite(PIN8, HIGH);
        led8 = 1;
      }
      else  {
        digitalWrite(PIN8, LOW);
        led8 = 0;
      }
    }
    else if(odebraneDane == "czerwona") {
      if(led9 == 0) {
        digitalWrite(PIN9, HIGH);
        led9 = 1;
      }
      else {
        digitalWrite(PIN9, LOW);
        led9 = 0;
      }
    }
    else {
      Serial.println("===PODALES NIEPOPRAWNY KOLOR===");
    }
  }
}