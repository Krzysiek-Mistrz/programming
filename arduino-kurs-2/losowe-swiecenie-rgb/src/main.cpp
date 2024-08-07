#include <Arduino.h>

#define czerwona 3
#define zielona 5
#define niebieska 6

void setup() {
  pinMode(czerwona, OUTPUT);
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
  
  randomSeed(analogRead(A5));
}


void loop() {
  int zmiana = 0;
  int zmianaLosowa = random(255);
  
  for (zmiana = 0; zmiana < 255; zmiana++) {
    analogWrite(czerwona, zmianaLosowa);  
    analogWrite(zielona, zmiana);
    analogWrite(niebieska, 255 - zmiana);

    delay(10);
  } 

  for (zmiana = 255; zmiana > 0; zmiana--) {
    analogWrite(czerwona, zmianaLosowa);
    analogWrite(zielona, zmiana);
    analogWrite(niebieska, 255 - zmiana);
    
    delay(10);
  }
}