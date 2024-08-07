#include <Arduino.h>
#define LED2 2
#define LED3 3
#define SW4 4
#define SW5 5

void setup() {
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  if(digitalRead(SW4) == LOW || digitalRead(SW5) == LOW) {
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED3, LOW);
    delay(500);
  } else {
    digitalWrite(LED2, LOW);
    delay(500);
    digitalWrite(LED3, LOW);
    delay(500);
  }

  if(digitalRead(SW4) == LOW && digitalRead(SW5) == LOW) {
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED3, HIGH);
    delay(500);
  } else {
    digitalWrite(LED2, LOW);
    delay(500);
    digitalWrite(LED3, LOW);
    delay(500);
  }
}
