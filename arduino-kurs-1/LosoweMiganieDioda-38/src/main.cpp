#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
}
 
void loop() {
  int czasWlaczona = random(100, 1000);
  int czasWylaczona = random(50, 500);
  digitalWrite(13, HIGH);
  delay(czasWlaczona);
  digitalWrite(13, LOW);
  delay(czasWylaczona);
}