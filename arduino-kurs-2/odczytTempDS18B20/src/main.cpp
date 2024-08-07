#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20PIN A5

OneWire oneWire = OneWire(DS18B20PIN);
DallasTemperature ds18b20(&oneWire);
float temp1 = 0, temp2 = 0;
float tempMax;
float tempMin;

void setup() {
  Serial.begin(9600);
  ds18b20.begin();
  ds18b20.requestTemperatures();
  tempMax = ds18b20.getTempCByIndex(0);
  tempMin = ds18b20.getTempCByIndex(0);
}

void loop() {
  ds18b20.requestTemperatures();
  temp1 = ds18b20.getTempCByIndex(0); //1 czujnik
  temp2 = ds18b20.getTempCByIndex(1); //odwolanie sie do drugiego podlaczonego czujnika
  if (temp1 > tempMax) {
    tempMax = temp1;
    Serial.println("MAX TEMP DS18B20 1: " + String(tempMax));
  }
  if (temp1 < tempMin) {
    tempMin = temp1;
    Serial.println("MIN TEMP DS18B20 1: " + String(tempMin));
  }
  Serial.println("AKTUALNA TEMP DS18B20 1: " + String(temp1));
  Serial.println("AKTUALNA TEMP DS18B20 2: " + String(temp2));

  delay(300);
}

/*********************************
 * ZAKRES PRACY : -50C : 150C
 * 4.7K ROWNOLEGLE OUTPUT, VCC
 * ADRES 1: 28 9E 73 AD F 0 0 F4
 * ADRES 2: 28 87 C1 AE F 0 0 7D
*********************************/