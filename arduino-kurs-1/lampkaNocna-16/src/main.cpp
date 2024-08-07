#include <Arduino.h>
#define LED2 2
#define ADC0 A0
int wartoscAnalogowa = 0;
int napiecie = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
}

void loop() {
  wartoscAnalogowa = analogRead(ADC0);
  napiecie = wartoscAnalogowa * (5.0/1024.0);
  if(wartoscAnalogowa < 20) {
    digitalWrite(LED2, HIGH);
    Serial.println(napiecie);
  }
  else {
    digitalWrite(LED2, LOW);
  }
  Serial.println(wartoscAnalogowa);
  delay(50);
}

/* 
wersja z potencjometrem w roli regulatora lampy

#include <Arduino.h>
#define LED2 2
#define ADC0 A0
#define ADC1 A1
int wartoscAnalogowa = 0;
int prog = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
}

void loop() {
  wartoscAnalogowa = analogRead(ADC0);
  prog = analogRead(ADC1);
  //regulujemy prog poprzez regulacje potencjometru
  if(wartoscAnalogowa < prog) {
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED2, LOW);
  }
  Serial.println(wartoscAnalogowa);
  delay(50);
}

*/