#include <Arduino.h>
#include <LiquidCrystal.h>
#define SWITCH8 8
#define SWITCH9 9
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int czas = 0;

void setup() {
  pinMode(SWITCH8, INPUT_PULLUP);
  pinMode(SWITCH9, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("CZAS:");
  lcd.setCursor(0, 1);
}

void loop() {
  if(digitalRead(SWITCH8) == LOW) {
    czas = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CZAS:");
    lcd.setCursor(0, 1);
    while(digitalRead(SWITCH9) == HIGH) {
      czas += 1;
      lcd.print(czas);
      lcd.setCursor(0, 1);
      delay(1000);
    }
  }
  delay(100);
  if(digitalRead(SWITCH9) == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("KONCOWY CZAS:");
    lcd.setCursor(0, 1);
    lcd.print(czas);
  }
  delay(100);
}

/*
pomiar napiecia program
#include <Arduino.h>
#include <LiquidCrystal.h>
#define ADC0 A0
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float napiecie = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("WARTOSC U:");
  lcd.setCursor(0, 1);
}

void loop() {
  napiecie = (5.0 / 1024.0) * analogRead(ADC0);
  lcd.setCursor(0, 1);
  lcd.print(napiecie);
  delay(250);
}
*/