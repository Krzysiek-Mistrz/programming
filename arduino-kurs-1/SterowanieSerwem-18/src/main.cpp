#include <Arduino.h>
#include <Servo.h>

Servo serwomechanizm;
int pozycja = 0;
int zmiana = 6;

void setup() {
  Serial.begin(9600);
  serwomechanizm.attach(5);
}

void loop() {
  if(pozycja <= 180 && pozycja >= 0 && Serial.available() > 0) {
    pozycja = (Serial.readStringUntil('\n')).toInt();
    serwomechanizm.write(pozycja);
  }
  delay(200);
    
  /*
  else {
    pozycja = 0;
  }
  */
  //pozycja = pozycja + zmiana;

  //za pomoca potencjometru:
  //potencjometr = analogRead(A0);
  //pozycja = map(potencjometr, 0, 1022, 0, 180);
  //serwomechanizm.write(pozycja);
}