#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel ws2812 = Adafruit_NeoPixel(8, A0, NEO_GBR + NEO_KHZ800);

void setup() {
  ws2812.begin();
  ws2812.show();
  /*
  syg 1
  for (int i = 0; i < 8; i++) {
    ws2812.setPixelColor(i, ws2812.Color(0, 255, 0));
    delay(500);
    ws2812.show();
  }
  */
}

void loop() {
  /* syg2
  for (int i = 0; i < 8; i++) {
    ws2812.setPixelColor(i, ws2812.Color(0, 255, 0));
  }
  ws2812.show();
  delay(500);
  for (int j = 0; j < 8; j++) {
    ws2812.setPixelColor(j, ws2812.Color(0, 0, 255));
  }
  ws2812.show();
  delay(500);
  */

  for (int i = 0; i <8; i++) {
    if (i < 4) {
      ws2812.setPixelColor(i, ws2812.Color(255, 0, 0));
    }
    else {
      ws2812.setPixelColor(i, ws2812.Color(0, 0, 255));
    }
    ws2812.show();
    delay(200);
  }
  ws2812.clear();
}