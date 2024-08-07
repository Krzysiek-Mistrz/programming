#include <Arduino.h>
#include <LiquidCrystal.h>
#define PIN9 9
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int zmianaJasnosci = 5;
int jasnosc = 0;

void setup() {
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ZMIANA JASNOSCI");
}

void loop() {
  analogWrite(PIN9, jasnosc);
  jasnosc = jasnosc + zmianaJasnosci;
  if(jasnosc = 255 || jasnosc == 0) {
    zmianaJasnosci = 0 - zmianaJasnosci; //odpowiednia zmiana na + lub - zmianaJasnosci
  }
  delay(30);
}