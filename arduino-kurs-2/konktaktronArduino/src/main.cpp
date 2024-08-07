#include <Arduino.h>

#define LED_R 9
#define LED_G 10
#define LED_B 11 
#define KONTAKTRON 0
 
void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
 
  pinMode(KONTAKTRON, INPUT_PULLUP);
  
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}
 
void loop() {
  if (digitalRead(KONTAKTRON) == LOW) {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
  } else {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
  }
}