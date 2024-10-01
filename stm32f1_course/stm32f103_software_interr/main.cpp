#include "stm32f1xx.h"
#include "cmsis_os.h"

osSemaphoreId_t buttonSemaphore;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        osSemaphoreRelease(buttonSemaphore);
    }
}

int main(void) {
    SystemCoreClock = 8000000;  // Set system clock to 8 MHz

    HAL_Init();  // Initialize the HAL Library

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef gpio;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Pin = GPIO_PIN_5;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &gpio);

    gpio.Mode = GPIO_MODE_IT_RISING;
    gpio.Pull = GPIO_NOPULL;
    gpio.Pin = GPIO_PIN_0;
    HAL_GPIO_Init(GPIOA, &gpio);

    HAL_NVIC_EnableIRQ(EXTI0_IRQn);

    osKernelInitialize();  // Initialize the RTOS kernel
    // Semaphore for signaling button press
    buttonSemaphore = osSemaphoreNew(1, 0, NULL);

    // Create tasks
    osThreadNew(StartButtonTask, NULL, NULL);  // Button task
    
    // Start scheduler
    osKernelStart();

    while (1) {}
}

void StartButtonTask(void *argument) {
    while (1) {
        if (osSemaphoreAcquire(buttonSemaphore, osWaitForever) == osOK) {
            osThreadNew(StartLedTask, NULL, NULL);
        }
    }
}

void StartLedTask(void *argument) {
    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Toggle LED on PA5
        osDelay(500);  // Delay for 500 ms
    }
}

void EXTI0_IRQHandler(void) {
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);  // Call the HAL GPIO EXTI handler
}

