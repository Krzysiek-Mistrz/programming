#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>

OneWire oneWire(A5);
DallasTemperature sensors(&oneWire);

DeviceAddress ds18b20_1 = {0x28, 0x9E, 0x73, 0xAD, 0xF, 0x0, 0x0, 0xF4};
DeviceAddress ds18b20_2 = {0x28, 0x87, 0xC1, 0xAE, 0xF, 0x0, 0x0, 0x7D};

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  Serial.println("AKTUALNA TEMP1: " + String(sensors.getTempC(ds18b20_1)) + "AKTUALNA TEMP2: " + String(sensors.getTempC(ds18b20_2)));
  delay(300);
}

/*********************************
 * ZAKRES PRACY : -50C : 150C
 * 4.7K ROWNOLEGLE OUTPUT, VCC
 * ADRES 1: 28 9E 73 AD F 0 0 F4
 * ADRES 2: 28 87 C1 AE F 0 0 7D
*********************************/