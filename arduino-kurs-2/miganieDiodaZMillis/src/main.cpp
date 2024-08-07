#include <Arduino.h>

#define DIODA1_PIN 2
#define DIODA2_PIN 3
#define PRZYCISK_PIN 4

unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas1 = 0;
unsigned long zapamietanyCzas2 = 0;
bool stanDiody1 = 0;
bool stanDiody2 = 0;
unsigned long czasMigania1 = 1000, czasMigania2 =  500;

void setup() {
  Serial.begin(9600);
  pinMode(DIODA1_PIN, OUTPUT);
  pinMode(DIODA2_PIN, OUTPUT);
  pinMode(PRZYCISK_PIN, INPUT_PULLUP);
}

void loop() {
  aktualnyCzas = millis();
  if (digitalRead(PRZYCISK_PIN) == 0) {
    czasMigania1 = 2000;
    czasMigania2 = 200;
  }
  if ((aktualnyCzas - zapamietanyCzas1) >= czasMigania1) {
    zapamietanyCzas1 = aktualnyCzas;
    stanDiody1 = !stanDiody1;
    digitalWrite(DIODA1_PIN, stanDiody1);
  }
  if ((aktualnyCzas - zapamietanyCzas2) >= czasMigania2) {
    zapamietanyCzas2 = aktualnyCzas;
    stanDiody2 = !stanDiody2;
    digitalWrite(DIODA2_PIN, stanDiody2);
  }
}