#include "stm32f1xx.h"

I2C_HandleTypeDef i2c;

int main(void)
{
	 SystemCoreClock = 8000000; // taktowanie 8Mhz
	 HAL_Init();

	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 __HAL_RCC_GPIOB_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_I2C1_CLK_ENABLE();

	 GPIO_InitTypeDef gpio;
	 gpio.Mode = GPIO_MODE_AF_OD;
	 gpio.Pin = GPIO_PIN_6 | GPIO_PIN_7;		// SCL, SDA
	 gpio.Pull = GPIO_PULLUP;
	 gpio.Speed = GPIO_SPEED_FREQ_LOW;
	 HAL_GPIO_Init(GPIOB, &gpio);

	 i2c.Instance             = I2C1;
	 i2c.Init.ClockSpeed      = 100000;
	 i2c.Init.DutyCycle       = I2C_DUTYCYCLE_2;
	 i2c.Init.OwnAddress1     = 0xff;
	 i2c.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	 i2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	 i2c.Init.OwnAddress2     = 0xff;
	 i2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	 i2c.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

	 HAL_I2C_Init(&i2c);

	 uint8_t test = 0x5a;
	 HAL_I2C_Mem_Write(&i2c, 0xa0, 0x10, 1, (uint8_t*)&test, sizeof(test), HAL_MAX_DELAY);

	 uint8_t result = 0;
	 HAL_I2C_Mem_Read(&i2c, 0xa0, 0x10, 1, (uint8_t*)&result, sizeof(result), HAL_MAX_DELAY);

	 while (1) {
	 }
}
