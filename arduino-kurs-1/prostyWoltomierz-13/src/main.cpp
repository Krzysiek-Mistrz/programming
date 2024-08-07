#include <Arduino.h>
#define ADC A0
int odczytanaWartosc = 0;
float napiecie = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  odczytanaWartosc = analogRead(ADC);
  //reprezentacja napiecia za pomoca 1024 wartosci, tzn 0=0V, 1024=10V 
  napiecie = odczytanaWartosc * (5.0/1024.0);
  Serial.println("WARTOSC NAPIECIA: " + (String)napiecie);
  delay(500);
}