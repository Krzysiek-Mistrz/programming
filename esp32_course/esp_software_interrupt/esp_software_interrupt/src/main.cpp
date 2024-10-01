#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t buttonSemaphore;

void buttonTask(void *pvParameters);
void ledTask(void *pvParameters);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, INPUT_PULLUP);

  buttonSemaphore = xSemaphoreCreateBinary();

  xTaskCreate(buttonTask, "ButtonTask", 2048, NULL, 1, NULL);
  xTaskCreate(ledTask, "LedTask", 2048, NULL, 1, NULL);
}

void loop() {}

void buttonTask(void *pvParameters) {
  while (1) {
    if (digitalRead(13) == LOW) {
      xSemaphoreGive(buttonSemaphore);
      vTaskDelay(200);
    }
  }
}

void ledTask(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(buttonSemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(2, HIGH);
      vTaskDelay(500);
      digitalWrite(2, LOW);
    }
  }
}
