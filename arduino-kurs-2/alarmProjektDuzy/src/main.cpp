#include <Arduino.h>
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>

#define BUZZER 11
#define PIR 1
#define WS2812 A0

const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
char keys[ROWS][COLS] = {
  {'D', 'C', 'B', 'A'},
  {'#', '9', '6', '3'},
  {'0', '8', '5', '2'},
  {'*', '7', '4', '1'}
};
Keypad klawiatura = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel ws2812 = Adafruit_NeoPixel(8, WS2812, NEO_GRB + NEO_KHZ800);
char klawisz = 0;
volatile int stanAlarmu = 1;
char kod[4] = {'1', '2', '3', '4'};
int ileCzasuMinelo = 0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT_PULLUP);
  ws2812.begin();
  ws2812.show();
}

void loop() {
  switch (stanAlarmu) {
    case 1: //czuwanie
      ws2812.setPixelColor(0, ws2812.Color(0, 15, 0));
      ws2812.show();
      klawisz = klawiatura.getKey();
      if (klawisz == 'A') {
        delay(5000);
        stanAlarmu = 2;
      }
    break;
    case 2: //monitorowanie
      ws2812.setPixelColor(0, ws2812.Color(15, 0, 0));
      ws2812.show();
      delay(50);
      if (digitalRead(PIR) == HIGH) {
        stanAlarmu = 3;
      }
    break;
    case 3:
      for (int i = 0; i < 4; i++) {
        if (kod[i] != klawiatura.getKey()) {
          stanAlarmu = 4;
        } else {
          stanAlarmu = 1;
        }
      }
      delay(100);
      ileCzasuMinelo++;
      if (ileCzasuMinelo >= 100) {
        stanAlarmu = 4;
      }
    break;
    case 4:
      for (int i = 0; i < 8; i++) {
        ws2812.setPixelColor(i, ws2812.Color(255, 0, 0));
      }
      ws2812.show();
      tone(BUZZER, 4300);
      delay(100);
      for (int i = 0; i < 8; i++) {
        ws2812.setPixelColor(i, ws2812.Color(0, 0, 255));
      }
      ws2812.show();
      tone(BUZZER, 3500);
      delay(100);
    break;
  }
}