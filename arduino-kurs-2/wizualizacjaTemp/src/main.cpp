#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Adafruit_NeoPixel.h>

OneWire oneWire(A5);
DallasTemperature sensors(&oneWire);
DeviceAddress ds18b20_1 = {0x28, 0x9E, 0x73, 0xAD, 0xF, 0x0, 0x0, 0xF4};
DeviceAddress ds18b20_2 = {0x28, 0x87, 0xC1, 0xAE, 0xF, 0x0, 0x0, 0x7D};
Adafruit_NeoPixel ws2812 = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);
int tempDoWs2812;

void termometrRgb(int temp) {
  if (temp > 40) {
    temp = 40;
  }
  else if (temp < -40) {
    temp = -40;
  }
  ws2812.clear();
  if ( temp >= 0) {
    temp = map(temp, 0, 40, 1, 8);
    for (int i = 0; i < temp; i++) {
      ws2812.setPixelColor(i, ws2812.Color(255, 0, 0));
    }
  }
  else {
    temp = map(temp, -40, 0, 1, 8);
    for (int i = 8; i > temp; i--) {
      ws2812.setPixelColor(i, ws2812.Color(0, 0, 255));
    }
  }
  ws2812.show();
}

void setup() {
  Serial.begin(9600);
  sensors.begin();
  ws2812.begin();
}

void loop() {
  sensors.requestTemperatures();
  tempDoWs2812 = sensors.getTempC(ds18b20_1);
  Serial.println("AKTUALNA TEMP1: " + String(tempDoWs2812));
  termometrRgb(tempDoWs2812);
  delay(300);
}

/*********************************
 * ZAKRES PRACY : -50C : 150C
 * 4.7K ROWNOLEGLE OUTPUT, VCC
 * ADRES 1: 28 9E 73 AD F 0 0 F4
 * ADRES 2: 28 87 C1 AE F 0 0 7D
*********************************/