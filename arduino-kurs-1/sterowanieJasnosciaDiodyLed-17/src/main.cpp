#include <Arduino.h>
#define LED3 3
//wiedzac ze kanal pwm jest 8 bitowy to 2^10 zatem zamiast int mozemy uzyc byte
//i wowczas nie bedziemy musieli uzywac if
int zmiana = 0;

void setup() {
  pinMode(LED3, OUTPUT);
}

void loop() {
  analogWrite(LED3, zmiana);
  if(zmiana < 255) {
    zmiana += 5;
  }
  else {
    zmiana = 0;
  }
  delay(50);
}

/*
void loop() {
  analogWrite(LED3, zmiana);
  if(zmiana == 255) {
    while(zmiana != 0) {
      zmiana -= 5;
      delay(50);
    }
  }
  zmiana += 5;
  delay(50);
}
*/