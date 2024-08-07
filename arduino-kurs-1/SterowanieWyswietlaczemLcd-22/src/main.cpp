#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Arduino");
  lcd.setCursor(0, 1);
  lcd.print("Wyswietlacz LCD");
  //lcd.blink();
}

void loop() {
  lcd.noCursor();
  //lcd.noDisplay();
  delay(250);
  lcd.cursor();
  //lcd.display();
  delay(250);
  //usuwanie caleo tekstu: lcd.clear();
}