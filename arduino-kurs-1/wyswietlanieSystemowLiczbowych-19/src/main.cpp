#include <Arduino.h>
#define ADC0 A0
#define ADC1 A1
#define SWITCH2 2
int pomiarPotencjometr = 0;
int pomiarFotorezystor = 0;
int napieciePotencjometr = 0;
int napiecieFotorezystor = 0;
int ileWcisnieto = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH2, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SWITCH2) == LOW) {
    pomiarPotencjometr = analogRead(ADC0);
    pomiarFotorezystor = analogRead(ADC1);
    napieciePotencjometr = map(pomiarPotencjometr, 0, 1023, 0, 5);
    napiecieFotorezystor = map(pomiarFotorezystor, 0, 1023, 0, 5);
    Serial.print("napiecie potencjometr [DEC]: ");
    Serial.print(napieciePotencjometr, DEC);
    Serial.print("\t| napiecie fotorezystor [DEC]: ");
    Serial.print(napiecieFotorezystor, DEC);
    Serial.print("\n");
    ileWcisnieto += 1;
    delay(100);
    
    /*
    =poprzedni kod=
    Serial.print("\t| napiecie [BIN]: ");
    Serial.print(napiecie, BIN);
    Serial.print("\t| napiecie [OCT]: ");
    Serial.print(napiecie, OCT);
    Serial.print("\t| napiecie [HEX]: ");
    Serial.print(napiecie, HEX);
    Serial.println();
    */
    //lub Serial.print('\n');
    //delay(1000);
  }
}