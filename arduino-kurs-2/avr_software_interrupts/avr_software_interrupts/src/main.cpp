#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t buttonSemaphore;

void buttonTask(void *pvParameters);
void ledTask(void *pvParameters);

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  buttonSemaphore = xSemaphoreCreateBinary();

  xTaskCreate(buttonTask, "ButtonTask", 128, NULL, 1, NULL);
  xTaskCreate(ledTask, "LedTask", 128, NULL, 1, NULL);
}

void loop() {}

void buttonTask(void *pvParameters) {
  while (1) {
    if (digitalRead(2) == LOW) {
      xSemaphoreGive(buttonSemaphore);
      vTaskDelay(200);
    }
  }
}

void ledTask(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(buttonSemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(13, HIGH);
      vTaskDelay(500);
      digitalWrite(13, LOW);
    }
  }
}
