#include <Arduino.h>
String bokA, bokB = "";

float poleKwadrat(float);
float poleTrojkat(float, float);
float poleProstokat(float, float);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    bokA = Serial.readStringUntil('\n');
    delay(1000);
    bokB = Serial.readStringUntil('\n');
    delay(1000);
    Serial.println(poleKwadrat(bokA.toFloat()));
    Serial.println(poleTrojkat(bokA.toFloat(), bokB.toFloat()));
    Serial.println(poleProstokat(bokA.toFloat(), bokB.toFloat()));
    delay(1000);
  }
}

float poleKwadrat(float bok) {
  return bok * bok;
}

float poleTrojkat(float bokA, float bokB) {
  return 0.5 * bokA * bokB;
}

float poleProstokat(float bokA, float bokB) {
  return bokA * bokB;
}