#include <Arduino.h>
#define LEDR 9
#define LEDG 10
#define LEDB 11
//#define LEDSYSTEM 13
#define PIR 2

volatile int ileRazy = 0;

void przerwanie() {
  /* wersja 1
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDR, LOW);
  */
  ileRazy++;
}

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  //pinMode(LEDSYSTEM, OUTPUT);
  pinMode(PIR, INPUT);

  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, LOW);

  attachInterrupt(digitalPinToInterrupt(2), przerwanie, RISING);
}

void loop() {
  /* wersja 1
  digitalWrite(LEDSYSTEM, HIGH);
  delay(500);
  digitalWrite(LEDSYSTEM, LOW);
  delay(500);
  */
 if (ileRazy < 3) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);    
  } else if (ileRazy < 6) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);   
  } else {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }
}