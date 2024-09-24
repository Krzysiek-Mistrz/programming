#include "stm32f1xx.h"

TIM_HandleTypeDef tim4;

int main(void)
{
	SystemCoreClock = 8000000; // taktowanie 8Mhz
	HAL_Init();

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB, &gpio);

	tim4.Instance = TIM4;
	tim4.Init.Period = 1000 - 1;
	tim4.Init.Prescaler = 8000 - 1;
	tim4.Init.ClockDivision = 0;
	tim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim4.Init.RepetitionCounter = 0;
	tim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	HAL_TIM_PWM_Init(&tim4);

	TIM_OC_InitTypeDef oc;
	oc.OCMode = TIM_OCMODE_PWM1;
	oc.Pulse = 100;
	oc.OCPolarity = TIM_OCPOLARITY_HIGH;
	oc.OCNPolarity = TIM_OCNPOLARITY_LOW;
	oc.OCFastMode = TIM_OCFAST_ENABLE;
	oc.OCIdleState = TIM_OCIDLESTATE_SET;
	oc.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	HAL_TIM_PWM_ConfigChannel(&tim4, &oc, TIM_CHANNEL_1);

	oc.Pulse = 200;
	HAL_TIM_PWM_ConfigChannel(&tim4, &oc, TIM_CHANNEL_2);

	oc.Pulse = 500;
	HAL_TIM_PWM_ConfigChannel(&tim4, &oc, TIM_CHANNEL_3);

	oc.Pulse = 900;
	HAL_TIM_PWM_ConfigChannel(&tim4, &oc, TIM_CHANNEL_4);

	HAL_TIM_PWM_Start(&tim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&tim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&tim4, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&tim4, TIM_CHANNEL_4);


	while (1) {
	}
}
