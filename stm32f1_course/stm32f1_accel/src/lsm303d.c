#include "lsm303d.h"

#define LSM303D_ADDR			0x3a

I2C_HandleTypeDef i2c;

void lsm_write_reg(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Write(&i2c, LSM303D_ADDR, reg, 1, &value, sizeof(value), HAL_MAX_DELAY);
}

uint8_t lsm_read_reg(uint8_t reg)
{
	uint8_t value = 0;

	HAL_I2C_Mem_Read(&i2c, LSM303D_ADDR, reg, 1, &value, sizeof(value), HAL_MAX_DELAY);

	return value;
}

int16_t lsm_read_value(uint8_t reg)
{
	int16_t value = 0;

	HAL_I2C_Mem_Read(&i2c, LSM303D_ADDR, reg | 0x80, 1, (uint8_t*)&value, sizeof(value), HAL_MAX_DELAY);

	return value;
}
