#include <Arduino.h>
#define LM35PIN A5

float tempMax = -10;
float tempMin = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = ((analogRead(LM35PIN)*5.0)/1024.0)*100;
  if (temp > tempMax) {
    tempMax = temp;
  }
  if (temp < tempMin) {
    tempMax = temp;
  }
  Serial.println("AKTUALNA TEMP: " + String(temp) + " | TEMP MAX: " + String(tempMax) + " | TEMP MIN: " + String(tempMin));
  delay(300);
}