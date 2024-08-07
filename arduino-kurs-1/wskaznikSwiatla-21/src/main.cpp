#include <Arduino.h>
#include <Servo.h>
#define SERVO3 3
#define ADC0 A0
Servo serwomechanizm;
int pomiar = 0;
int pozycja = 0;
int pozycjaPoprzednia = 0;

void setup() {
  Serial.begin(9600);
  serwomechanizm.attach(SERVO3);
}

void loop() {
  pomiar = analogRead(ADC0);
  pozycja = floor((180.0 / 1024) * pomiar);
  if(pozycja <= 180 && pozycja >= 0 && abs(pozycja - pozycjaPoprzednia) > 5) {
    serwomechanizm.write(pozycja);
    pozycjaPoprzednia = pozycja;
  }
  Serial.println(pomiar);
  delay(50);
}