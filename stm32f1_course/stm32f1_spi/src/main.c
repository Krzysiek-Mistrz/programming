#include "stm32f1xx.h"

#define MCP_IODIR		0x00
#define MCP_IPOL		0x01
#define MCP_GPINTEN		0x02
#define MCP_DEFVAL		0x03
#define MCP_INTCON		0x04
#define MCP_IOCON		0x05
#define MCP_GPPU		0x06
#define MCP_INTF		0x07
#define MCP_INTCAP		0x08
#define MCP_GPIO		0x09
#define MCP_OLAT		0x0a

SPI_HandleTypeDef spi;

void mcp_write_reg(uint8_t addr, uint8_t value)
{
	uint8_t tx_buf[] = { 0x40, addr, value };

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&spi, tx_buf, 3, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
}

int main(void)
{
	volatile int dly;

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
	 gpio.Pin = GPIO_PIN_0;						// CS
	 HAL_GPIO_Init(GPIOC, &gpio);
	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

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

	 mcp_write_reg(MCP_IODIR, ~0x01);

	 while (1) {
		 // zapal diode
		mcp_write_reg(MCP_OLAT, 0x01);

		for (dly=0;dly<150000;dly++) {}

		// zgas diode
		mcp_write_reg(MCP_OLAT, 0x00);

		for (dly=0;dly<150000;dly++) {}
	}
}
