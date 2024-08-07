#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel ws2812 = Adafruit_NeoPixel(8, A0, NEO_GRB + NEO_KHZ800);

void setup() {
  ws2812.begin();
  ws2812.show();
  ws2812.setPixelColor(0, ws2812.Color(0, 255, 0));
  ws2812.show();
}

void loop() {}