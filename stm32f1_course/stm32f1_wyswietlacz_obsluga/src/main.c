#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "lcd.h"
#include "bitmap.h"

int main(void)
{
	 int i;

	 SystemCoreClock = 8000000; // taktowanie 8Mhz
	 HAL_Init();

	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_SPI1_CLK_ENABLE();

	 GPIO_InitTypeDef gpio;
	 gpio.Mode = GPIO_MODE_AF_PP;
	 gpio.Pin = GPIO_PIN_5 | GPIO_PIN_7;		// SCK, MOSI
	 gpio.Pull = GPIO_NOPULL;
	 gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	 HAL_GPIO_Init(GPIOA, &gpio);

	 gpio.Mode = GPIO_MODE_AF_INPUT;
	 gpio.Pin = GPIO_PIN_6;						// MISO
	 HAL_GPIO_Init(GPIOA, &gpio);

	 gpio.Mode = GPIO_MODE_OUTPUT_PP;
	 gpio.Pin = LCD_DC|LCD_CE|LCD_RST;
	 HAL_GPIO_Init(GPIOC, &gpio);
	 HAL_GPIO_WritePin(GPIOC, LCD_CE|LCD_RST, GPIO_PIN_SET);

	 spi.Instance = SPI1;
	 spi.Init.Mode = SPI_MODE_MASTER;
	 spi.Init.NSS = SPI_NSS_SOFT;
	 spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;	// 1MHz
	 spi.Init.Direction = SPI_DIRECTION_2LINES;
	 spi.Init.CLKPhase = SPI_PHASE_1EDGE;
	 spi.Init.CLKPolarity = SPI_POLARITY_LOW;
	 spi.Init.DataSize = SPI_DATASIZE_8BIT;
	 spi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	 spi.Init.TIMode = SPI_TIMODE_DISABLE;
	 spi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	 spi.Init.CRCPolynomial = 7;
	 HAL_SPI_Init(&spi);

	 __HAL_SPI_ENABLE(&spi);

	 lcd_setup();

	 lcd_draw_bitmap(forbot_logo);
	 lcd_copy();

	 HAL_Delay(1000);

	 lcd_clear();
	 for (i = 0; i < 6; i++)
		 lcd_draw_text(i, i * 8, "Forbot !");
	 lcd_copy();

	 while (1) {
	}
}
