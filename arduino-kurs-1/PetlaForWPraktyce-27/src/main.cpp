#include <Arduino.h>
String liczba;

void setup() {
  Serial.begin(9600);

  /*
  miganie dioda zd dom

  pinMode(LED2, OUTPUT);
  for(int i = 0; i < 5; i++) {
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED2, LOW);
    delay(1000);
  }
  
  int licznik = 0;
  while(licznik < 5) {
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED2, LOW);
  }
  */

  /*
  program 1 odliczanie

  for(int i = 0; i < 25; i++) {
    Serial.print("Odliczanie: ");
    Serial.print(i + 1);
    Serial.println();
    delay(100);
  }
  */
}

void loop() {
  if(Serial.available() > 0) {
    liczba = Serial.readStringUntil('\n');
    for(int i = 0; i < liczba.toInt(); i++) {
      Serial.print("*");
    }
    Serial.println();
  }
  delay(1000);
}