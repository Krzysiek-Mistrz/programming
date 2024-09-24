#include "stm32f1xx.h"

int main(void)
{
    SystemCoreClock = 8000000;

    HAL_Init();

    __HAL_RCC_GPIOC_CLK_ENABLE();

   GPIO_InitTypeDef gpio;
   gpio.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|
   GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
   gpio.Mode = GPIO_MODE_OUTPUT_PP;
   gpio.Pull = GPIO_NOPULL;
   gpio.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(GPIOC, &gpio);

    uint32_t led = 0;
   while (1) {
	   //1 jest przesuwane o led miejsc w lewo, czyli 1 -> 01, 001, ...
      HAL_GPIO_WritePin(GPIOC, 1 << led, GPIO_PIN_SET);
      HAL_Delay(150);
      HAL_GPIO_WritePin(GPIOC, 1 << led, GPIO_PIN_RESET);
      if (++led >= 10) {
         led = 0;
      }
   }
}
