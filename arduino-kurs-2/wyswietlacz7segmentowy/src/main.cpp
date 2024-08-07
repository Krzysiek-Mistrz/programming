#include <Arduino.h>

#define SEG_C 2
#define SEG_E 3
#define SEG_D 4
#define SEG_B 5
#define SEG_G 6
#define SEG_A 7
#define SEG_F 8

void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  digitalWrite(SEG_A, HIGH);
  delay(800);
  digitalWrite(SEG_B, HIGH);
  delay(800);
  digitalWrite(SEG_C, HIGH);
  delay(800);
  digitalWrite(SEG_D, HIGH);
  delay(800);
  digitalWrite(SEG_E, HIGH);
  delay(800);
  digitalWrite(SEG_F, HIGH);
  delay(800);
  digitalWrite(SEG_G, HIGH);
}

void loop() {}